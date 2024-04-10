#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <map>

#include <sched.h>
#include <pthread.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/lockfree_queue.h"
#include "pos/include/api_context.h"

/*!
 *  \brief prototype for worker launch function for each API call
 */
using pos_worker_launch_function_t = pos_retval_t(*)(POSWorkspace*, POSAPIContext_QE*);

/*!
 *  \brief  macro for the definition of the worker launch functions
 */
#define POS_WK_FUNC_LAUNCH()                                        \
    pos_retval_t launch(POSWorkspace* ws, POSAPIContext_QE* wqe)

namespace wk_functions {
#define POS_WK_DECLARE_FUNCTIONS(api_name) namespace api_name { POS_WK_FUNC_LAUNCH(); }
};  // namespace ps_functions


typedef struct checkpoint_async_cxt {
    // flag: checkpoint thread to notify the worker thread that the previous checkpoint has done
    bool is_active;
    
    // checkpoint op context
    POSAPIContext_QE *wqe;

    // (latest) version of each handle to be checkpointed
    std::map<POSHandle*, pos_vertex_id_t> checkpoint_version_map;

    checkpoint_async_cxt() : is_active(false) {}
} checkpoint_async_cxt_t;


/*!
 *  \brief  POS Worker
 */
class POSWorker {
 public:
    POSWorker(POSWorkspace* ws)
        : _ws(ws), _stop_flag(false), worker_stream(nullptr)
    {
        int rc;

        // start daemon thread
        _daemon_thread = new std::thread(&POSWorker::daemon, this);
        POS_CHECK_POINTER(_daemon_thread);

        POS_LOG_C("worker started");
    }

    /*!
     *  \brief  deconstructor
     */
    ~POSWorker(){ shutdown(); }

    /*!
     *  \brief  function insertion
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     *  \return POS_SUCCESS for successfully insertion
     */
    pos_retval_t init(){
        if(unlikely(POS_SUCCESS != init_wk_functions())){
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
            POS_LOG_C("Worker daemon thread shutdown");
        }
    }

    /*!
     *  \brief  generic restore procedure
     *  \note   should be invoked within the landing function, while exeucting failed
     *  \param  ws  the global workspace
     *  \param  wqe the work QE where failure was detected
     */
    static inline void __restore(POSWorkspace* ws, POSAPIContext_QE* wqe){
        POS_ERROR_DETAIL(
            "execute failed, restore mechanism to be implemented: api_id(%lu), retcode(%d), pc(%lu)",
            wqe->api_cxt->api_id, wqe->api_cxt->return_code, wqe->dag_vertex_id
        ); 
        /*!
         *  \todo   1. how to identify user-handmake error and hardware error?
         *          2. mark broken handles;
         *          3. reset the _pc of the DAG to the last sync point;
         */
    }

    /*!
     *  \brief  generic complete procedure
     *  \note   should be invoked within the landing function, while exeucting success
     *  \param  ws  the global workspace
     *  \param  wqe the work QE where failure was detected
     */
    static inline void __done(POSWorkspace* ws, POSAPIContext_QE* wqe){
        POSClient *client;
        uint64_t i;

        POS_CHECK_POINTER(wqe);
        POS_CHECK_POINTER(client = (POSClient*)(wqe->client));

        // forward the DAG pc
        client->dag.forward_pc();

        // set the latest version of all output handles
        for(i=0; i<wqe->output_handle_views.size(); i++){
            POSHandleView_t &hv = wqe->output_handle_views[i];
            hv.handle->latest_version = wqe->dag_vertex_id;
        }

        // set the latest version of all inout handles
        for(i=0; i<wqe->inout_handle_views.size(); i++){
            POSHandleView_t &hv = wqe->inout_handle_views[i];
            hv.handle->latest_version = wqe->dag_vertex_id;
        }
    }

    /*!
     *  TODO: we only prepare one worker stream here, is this sufficient?
     */
    void *worker_stream;

 protected:
    // stop flag to indicate the daemon thread to stop
    bool _stop_flag;

    // the daemon thread of the runtime
    std::thread *_daemon_thread;

    // global workspace
    POSWorkspace *_ws;

    // worker function map
    std::map<uint64_t, pos_worker_launch_function_t> _launch_functions;
    
    /*!
     *  \brief  checkpoint procedure, should be implemented by each platform
     *  \note   this function will be invoked by level-1 ckpt
     *  \param  wqe     the checkpoint op
     *  \return POS_SUCCESS for successfully checkpointing
     */
    virtual pos_retval_t checkpoint_sync(POSAPIContext_QE* wqe){ return POS_FAILED_NOT_IMPLEMENTED; }
    
    /*!
     *  \brief  overlapped checkpoint procedure, should be implemented by each platform
     *  \note   this thread will be raised by level-2 ckpt
     *  \note   aware of the macro POS_CKPT_ENABLE_PIPELINE
     *  \note   aware of the macro POS_CKPT_ENABLE_ORCHESTRATION
     *  \param  cxt     the context of this checkpointing
     */
    virtual void checkpoint_async_thread(checkpoint_async_cxt_t* cxt){
        POS_CHECK_POINTER(cxt);
        POS_LOG("#checkpoint handles: %lu", cxt->wqe->checkpoint_handles.size());
        cxt->is_active = false;
    }

 private:
    /*!
     *  \brief  processing daemon of the worker
     */
    void daemon(){
        #if POS_CKPT_OPT_LEVEL <= 1
            this->__daemon_ckpt_sync();
        #elif POS_CKPT_OPT_LEVEL == 2
            this->__daemon_ckpt_async();
        #else
            static_assert(false, "error checkpoint level");
        #endif
    }

    void __daemon_ckpt_async(){
        uint64_t i, j, k, w, api_id;
        pos_retval_t launch_retval, tmp_retval;
        POSAPIMeta_t api_meta;
        std::vector<POSClient*> clients;
        POSClient *client;
        POSAPIContext_QE *wqe;

        std::thread *ckpt_thread = nullptr;
        checkpoint_async_cxt_t ckpt_cxt;
        ckpt_cxt.is_active = false;
        typename std::set<POSHandle*>::iterator handle_set_iter;
        POSHandle *handle;

        if(unlikely(POS_SUCCESS != daemon_init())){
            POS_WARN_C("failed to init daemon, worker daemon exit");
            return;
        }

        while(!_stop_flag){
            _ws->poll_client_dag(&clients);

            for(i=0; i<clients.size(); i++){
                POS_CHECK_POINTER(client = clients[i]);

                // keep popping next pending op until we finished all operation
                while(POS_SUCCESS == client->dag.get_next_pending_op(&wqe)){
                    wqe->worker_s_tick = POSUtilTimestamp::get_tsc();
                    api_id = wqe->api_cxt->api_id;

                    // this is a checkpoint op
                    if(unlikely(api_id == this->_ws->checkpoint_api_id)){
                        // if nothing to be checkpointed, we just omit
                        if(unlikely(wqe->checkpoint_handles.size() == 0)){
                            goto ckpt_finished;
                        }

                        /*!
                         *  \note   if previous checkpoint thread hasn't finished yet, we abandon this checkpoint
                         *          to avoid waiting overhead here
                         *  \note   so the actual checkpoint interval might not be accurate
                         */
                        if(ckpt_cxt.is_active == true){
                            POS_LOG("skip checkpoint due to previous one is still non-finished");
                            goto ckpt_finished;
                        }
                        // we need to wait until last checkpoint finished
                        // while(ckpt_cxt.is_active == true){}
                        
                        // start new checkpoint thread
                        ckpt_cxt.wqe = wqe;

                        // delete the handle of previous checkpoint
                        if(likely(ckpt_thread != nullptr)){
                            ckpt_thread->join();
                            delete ckpt_thread;
                        }

                        // reset checkpoint version map
                        ckpt_cxt.checkpoint_version_map.clear();
                        for(handle_set_iter = wqe->checkpoint_handles.begin(); 
                            handle_set_iter != wqe->checkpoint_handles.end(); 
                            handle_set_iter++)
                        {
                            POS_CHECK_POINTER(handle = *handle_set_iter);
                            handle->reset_preserve_counter();
                            ckpt_cxt.checkpoint_version_map[handle] = handle->latest_version;
                        }

                        // raise new checkpoint thread
                        ckpt_thread = new std::thread(&POSWorker::checkpoint_async_thread, this, &ckpt_cxt);
                        POS_CHECK_POINTER(ckpt_thread);
                        ckpt_cxt.is_active = true;

                    ckpt_finished:
                        __done(this->_ws, wqe);
                        wqe->worker_e_tick = POSUtilTimestamp::get_tsc();
                        wqe->return_tick = POSUtilTimestamp::get_tsc();
                        continue;
                    }

                    api_meta = _ws->api_mgnr->api_metas[api_id];

                    // check and restore broken handles
                    // TODO: we need to also restore the stateful handle's state here??
                    if(unlikely(POS_SUCCESS != __restore_broken_handles(wqe, api_meta))){
                        POS_WARN_C("failed to check / restore broken handles: api_id(%lu)", api_id);
                        continue;
                    }

                #if POS_ENABLE_DEBUG_CHECK
                    if(unlikely(_launch_functions.count(api_id) == 0)){
                        POS_ERROR_C_DETAIL(
                            "runtime has no worker launch function for api %lu, need to implement", api_id
                        );
                    }
                #endif

                    /*!
                     *  \brief  before launching the API, we need to preserve the state of all stateful resources for checkpointing
                     *  \note   there're serval cases handle in preserve_ckpt_state:
                     *          [1] the state hasn't been checkpoint yet, then it conducts COW on the state
                     *          [2] the state is under checkpointing, then it blocks until the checkpoint finished
                     *          [3] the state is already checkpointed, then it directly returns
                     */
                    for(auto &inout_handle_view : wqe->inout_handle_views){
                        POS_CHECK_POINTER(handle = inout_handle_view.handle);
                        if(ckpt_cxt.checkpoint_version_map.count(handle) > 0){
                            tmp_retval = handle->preserve_ckpt_state(/* version_id */ckpt_cxt.checkpoint_version_map[handle]);
                            POS_ASSERT(tmp_retval == POS_SUCCESS);
                        }
                    }
                    for(auto &out_handle_view : wqe->output_handle_views){
                        POS_CHECK_POINTER(handle = out_handle_view.handle);
                        if(ckpt_cxt.checkpoint_version_map.count(handle) > 0){
                            tmp_retval = handle->preserve_ckpt_state(/* version_id */ckpt_cxt.checkpoint_version_map[handle]);
                            POS_ASSERT(tmp_retval == POS_SUCCESS);
                        }
                    }

                    launch_retval = (*(_launch_functions[api_id]))(_ws, wqe);
                    wqe->worker_e_tick = POSUtilTimestamp::get_tsc();

                   // cast return code
                    wqe->api_cxt->return_code = _ws->api_mgnr->cast_pos_retval(
                        /* pos_retval */ launch_retval, 
                        /* library_id */ api_meta.library_id
                    );

                    // check whether the execution is success
                    if(unlikely(launch_retval != POS_SUCCESS)){
                        wqe->status = kPOS_API_Execute_Status_Launch_Failed;
                    }

                    // check whether we need to return to frontend
                    if(wqe->status == kPOS_API_Execute_Status_Init){
                        // we only return the QE back to frontend when it hasn't been returned before
                        wqe->return_tick = POSUtilTimestamp::get_tsc();
                        _ws->template push_cq<kPOS_Queue_Position_Worker>(wqe);
                    }               
                }
            }
            
            clients.clear();
        }
    }

    /*!
     *  \brief  processing daemon of the worker (under checkpoint optimization level 0 and 1)
     *  \note   under this worker, checkpoint ops are executed using the same stream (thread) with other
     *          normal operators
     */
    void __daemon_ckpt_sync(){
        uint64_t i, j, k, w, api_id;
        pos_retval_t launch_retval;
        POSAPIMeta_t api_meta;
        std::vector<POSClient*> clients;
        POSClient* client;
        POSAPIContext_QE *wqe;

        if(unlikely(POS_SUCCESS != daemon_init())){
            POS_WARN_C("failed to init daemon, worker daemon exit");
            return;
        }

        while(!_stop_flag){
            _ws->poll_client_dag(&clients);

            for(i=0; i<clients.size(); i++){
                POS_CHECK_POINTER(client = clients[i]);

                // keep popping next pending op until we finished all operation
                while(POS_SUCCESS == client->dag.get_next_pending_op(&wqe)){
                    wqe->worker_s_tick = POSUtilTimestamp::get_tsc();
                    api_id = wqe->api_cxt->api_id;

                    // this is a checkpoint op
                    if(unlikely(api_id == this->_ws->checkpoint_api_id)){
                        if(unlikely(POS_SUCCESS != this->checkpoint_sync(wqe))){
                            POS_WARN_C("failed to do checkpointing");
                        }
                        __done(this->_ws, wqe);
                        wqe->worker_e_tick = POSUtilTimestamp::get_tsc();
                        wqe->return_tick = POSUtilTimestamp::get_tsc();
                        continue;
                    }

                    api_meta = _ws->api_mgnr->api_metas[api_id];

                    // check and restore broken handles
                    if(unlikely(POS_SUCCESS != __restore_broken_handles(wqe, api_meta))){
                        POS_WARN_C("failed to check / restore broken handles: api_id(%lu)", api_id);
                        continue;
                    }

                #if POS_ENABLE_DEBUG_CHECK
                    if(unlikely(_launch_functions.count(api_id) == 0)){
                        POS_ERROR_C_DETAIL(
                            "runtime has no worker launch function for api %lu, need to implement", api_id
                        );
                    }
                #endif

                    launch_retval = (*(_launch_functions[api_id]))(_ws, wqe);
                    wqe->worker_e_tick = POSUtilTimestamp::get_tsc();

                   // cast return code
                    wqe->api_cxt->return_code = _ws->api_mgnr->cast_pos_retval(
                        /* pos_retval */ launch_retval, 
                        /* library_id */ api_meta.library_id
                    );

                    // check whether the execution is success
                    if(unlikely(launch_retval != POS_SUCCESS)){
                        wqe->status = kPOS_API_Execute_Status_Launch_Failed;
                    }

                    // check whether we need to return to frontend
                    if(wqe->status == kPOS_API_Execute_Status_Init){
                        // we only return the QE back to frontend when it hasn't been returned before
                        wqe->return_tick = POSUtilTimestamp::get_tsc();
                        _ws->template push_cq<kPOS_Queue_Position_Worker>(wqe);
                    }               
                }
            }
            
            clients.clear();
        }
    }
    
    /*!
     *  \brief  check and restore all broken handles, if there's any exists
     *  \param  wqe         the op to be checked and restored
     *  \param  api_meta    metadata of the called API
     *  \return POS_SUCCESS for successfully checking and restoring
     */
    pos_retval_t __restore_broken_handles(POSAPIContext_QE* wqe, POSAPIMeta_t& api_meta){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(wqe);

        auto __restore_broken_hendles_per_direction = [&](std::vector<POSHandleView_t>& handle_view_vec){
            uint64_t i;
            POSHandle::pos_broken_handle_list_t broken_handle_list;
            POSHandle *broken_handle;
            uint16_t nb_layers, layer_id_keeper;
            uint64_t handle_id_keeper;

            for(i=0; i<handle_view_vec.size(); i++){
                broken_handle_list.reset();
                handle_view_vec[i].handle->collect_broken_handles(&broken_handle_list);

                nb_layers = broken_handle_list.get_nb_layers();
                if(likely(nb_layers == 0)){
                    continue;
                }

                layer_id_keeper = nb_layers - 1;
                handle_id_keeper = 0;

                while(1){
                    broken_handle = broken_handle_list.reverse_get_handle(layer_id_keeper, handle_id_keeper);
                    if(unlikely(broken_handle == nullptr)){
                        break;
                    }

                    /*!
                     *  \note   we don't need to restore the bottom handle while haven't create them yet
                     */
                    if(unlikely(api_meta.api_type == kPOS_API_Type_Create_Resource && layer_id_keeper == 0)){
                        if(likely(broken_handle->status == kPOS_HandleStatus_Create_Pending)){
                            continue;
                        }
                    }
                    
                    // restore locally
                    if(unlikely(POS_SUCCESS != broken_handle->restore())){
                        POS_ERROR_C(
                            "failed to restore broken handle: resource_type(%s), client_addr(%p), server_addr(%p), state(%u)",
                            broken_handle->get_resource_name().c_str(), broken_handle->client_addr, broken_handle->server_addr,
                            broken_handle->status
                        );
                    } else {
                        POS_DEBUG_C(
                            "restore broken handle: resource_type_id(%lu)",
                            broken_handle->resource_type_id
                        );
                    }
                } // while (1)

            } // foreach handle_view_vec
        };

        __restore_broken_hendles_per_direction(wqe->input_handle_views);
        __restore_broken_hendles_per_direction(wqe->output_handle_views);
        __restore_broken_hendles_per_direction(wqe->inout_handle_views);
        __restore_broken_hendles_per_direction(wqe->create_handle_views);
        __restore_broken_hendles_per_direction(wqe->delete_handle_views);

    exit:
        return retval;
    }

    /*!
     *  \brief  insertion of worker functions
     *  \return POS_SUCCESS for succefully insertion
     */
    virtual pos_retval_t init_wk_functions(){ return POS_FAILED_NOT_IMPLEMENTED; }

    /*!
     *  \brief      initialization of the worker daemon thread
     *  \example    for CUDA, one need to call API e.g. cudaSetDevice first to setup the context for a thread
     */
    virtual pos_retval_t daemon_init(){ return POS_SUCCESS; }
};
