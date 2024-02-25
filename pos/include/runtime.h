#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <map>

#include <sched.h>
#include <pthread.h>

#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/lockfree_queue.h"
#include "pos/include/api_context.h"
#include "pos/include/workspace.h"


/*!
 *  \brief prototype for parser function for each API call
 */
using pos_runtime_parser_function_t = pos_retval_t(*)(POSWorkspace*, POSAPIContext_QE*);

/*!
 *  \brief  macro for the definition of the runtime parser functions
 */
#define POS_RT_FUNC_PARSER()                                    \
    pos_retval_t parse(POSWorkspace* ws, POSAPIContext_QE* wqe)

namespace rt_functions {
#define POS_RT_DECLARE_FUNCTIONS(api_name) namespace api_name { POS_RT_FUNC_PARSER(); }
};  // namespace rt_functions

/*!
 *  \brief  POS Runtime
 *  \note   1. Parser:      parsing each API call, translate virtual handles to physicall handles;
 *          2. DAG:         maintainance of launch flow for checkpoint/restore and scheduling;
 */
class POSRuntime {
 public:
    POSRuntime(POSWorkspace* ws) : _ws(ws), _stop_flag(false) {   
        int rc;

        this->checkpoint_interval_tick = ((double)POS_CKPT_INTERVAL / 1000.f) * (double)(POS_TSC_FREQ);

        // start daemon thread
        _daemon_thread = new std::thread(&POSRuntime::daemon, this);
        POS_CHECK_POINTER(_daemon_thread);

        POS_LOG_C(
            "runtime started: ckpt_interval(%lu ms, %lu ticks), ckpt_opt_level(%d)",
            POS_CKPT_INTERVAL,
            this->checkpoint_interval_tick,
            POS_CKPT_OPT_LEVAL
        );
    };

    /*!
     *  \brief  deconstructor
     */
    ~POSRuntime(){ shutdown(); }
    
    /*!
     *  \brief  function insertion
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     *  \return POS_SUCCESS for successfully insertion
     */
    pos_retval_t init(){
        if(unlikely(POS_SUCCESS != init_rt_functions())){
            POS_ERROR_C_DETAIL("failed to insert functions");
        }
    }

    /*!
     *  \brief  raise the shutdown signal to stop the daemon
     */
    inline void shutdown(){ 
        _stop_flag = true;
        if(_daemon_thread != nullptr){
            _daemon_thread->join();
            delete _daemon_thread;
            _daemon_thread = nullptr;
            POS_LOG_C("Runtime daemon thread shutdown");
        }
    }

 protected:
    // stop flag to indicate the daemon thread to stop
    bool _stop_flag;

    // the daemon thread of the runtime
    std::thread *_daemon_thread;

    // global workspace
    POSWorkspace *_ws;

    // parser function map
    std::map<uint64_t, pos_runtime_parser_function_t> _parser_functions;
    
    // intervals between two checkpoint ops
    uint64_t checkpoint_interval_tick;

 private:
    /*!
     *  \brief  processing daemon of the runtime
     */
    void daemon(){
        uint64_t i, api_id;
        pos_retval_t parser_retval, dag_retval;
        POSAPIMeta_t api_meta;
        std::vector<POSAPIContext_QE*> wqes;
        POSAPIContext_QE* wqe;
        uint64_t last_ckpt_tick = 0, current_tick;

        if(unlikely(POS_SUCCESS != daemon_init())){
            POS_WARN_C("failed to init daemon, worker daemon exit");
            return;
        }
        
        while(!_stop_flag){
            _ws->poll_runtime_wq(&wqes);

        #if POS_ENABLE_DEBUG_CHECK
            if(wqes.size() > 0){
                POS_DEBUG_C("polling runtime work queues, obtain %lu elements", wqes.size());
            }
        #endif

            for(i=0; i<wqes.size(); i++){
                POS_CHECK_POINTER(wqe = wqes[i]);

                api_id = wqe->api_cxt->api_id;
                api_meta = _ws->api_mgnr->api_metas[api_id];

            #if POS_ENABLE_DEBUG_CHECK
                if(unlikely(_parser_functions.count(api_id) == 0)){
                    POS_ERROR_C_DETAIL(
                        "runtime has no parser function for api %lu, need to implement", api_id
                    );
                }
            #endif

                /*!
                 *  \brief  ================== phrase 1 - parse API semantics ==================
                 */
                wqe->runtime_s_tick = POSUtilTimestamp::get_tsc();
                parser_retval = (*(_parser_functions[api_id]))(_ws, wqe);
                wqe->runtime_e_tick = POSUtilTimestamp::get_tsc();

                // set the return code
                wqe->api_cxt->return_code = _ws->api_mgnr->cast_pos_retval(
                    /* pos_retval */ parser_retval, 
                    /* library_id */ api_meta.library_id
                );

                if(unlikely(POS_SUCCESS != parser_retval)){
                    POS_WARN_C(
                        "failed to execute parser function: client_id(%lu), api_id(%lu)",
                        wqe->client_id, api_id
                    );
                    wqe->status = kPOS_API_Execute_Status_Parse_Failed;
                    wqe->return_tick = POSUtilTimestamp::get_tsc();                    
                    _ws->template push_cq<kPOS_Queue_Position_Runtime>(wqe);

                    goto checkpoint_entrance;
                }
                

                /*!
                 *  \note       for api in type of Delete_Resource, one can directly send
                 *              response to the client right after operating on mocked resources
                 *  \warning    we can't apply this rule for Create_Resource, consider the memory situation, which is passthrough addressed
                 */
                if(unlikely(api_meta.api_type == kPOS_API_Type_Delete_Resource)){
                    POS_DEBUG_C("api(%lu) is type of Delete_Resource, set as \"Return_After_Parse\"", api_id);
                    wqe->status = kPOS_API_Execute_Status_Return_After_Parse;
                }

                /*!
                 *  \note       for sync api that mark as kPOS_API_Execute_Status_Return_After_Parse,
                 *              we directly return the result back to the frontend side
                 */
                if(wqe->status == kPOS_API_Execute_Status_Return_After_Parse){
                    wqe->return_tick = POSUtilTimestamp::get_tsc();
                    _ws->template push_cq<kPOS_Queue_Position_Runtime>(wqe);
                }

            checkpoint_entrance:
                /*!
                 *  \brief  ================== phrase 2 - checkpoint insertion ==================
                 */
                // TODO: this checkpoint tick should be modified as per-client
                current_tick = POSUtilTimestamp::get_tsc();
                if(unlikely(
                    current_tick - last_ckpt_tick >= this->checkpoint_interval_tick
                )){
                    last_ckpt_tick = current_tick;
                    if(unlikely(POS_SUCCESS != this->checkpoint_insertion(wqe))){
                        POS_WARN_C("failed to insert checkpointing op");
                    }
                }
            }

            wqes.clear();
        }
    }

    /*!
     *  \brief  insertion of parse and dag functions
     *  \return POS_SUCCESS for succefully insertion
     */
    virtual pos_retval_t init_rt_functions(){ return POS_FAILED_NOT_IMPLEMENTED; }

    /*!
     *  \brief      initialization of the runtime daemon thread
     *  \example    for CUDA, one need to call API e.g. cudaSetDevice first to setup the context for a thread
     */
    virtual pos_retval_t daemon_init(){ return POS_SUCCESS; }

    /*!
     *  \brief  insert checkpoint op to the DAG based on certain conditions
     *  \param  wqe the exact WQ element before inserting checkpoint op
     *  \return POS_SUCCESS for successfully checkpoint insertion
     */
    virtual pos_retval_t checkpoint_insertion(POSAPIContext_QE* wqe){ return POS_FAILED_NOT_IMPLEMENTED; }
};
