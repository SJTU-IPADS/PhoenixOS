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
template<class T_POSTransport, class T_POSClient>
using pos_worker_launch_function_t = pos_retval_t(*)(
    POSWorkspace<T_POSTransport, T_POSClient>*, POSAPIContext_QE_ptr
);

/*!
 *  \brief prototype for worker landing function for each API call
 */
template<class T_POSTransport, class T_POSClient>
using pos_worker_landing_function_t = pos_retval_t(*)(
    POSWorkspace<T_POSTransport, T_POSClient>*, POSAPIContext_QE_ptr
);

/*!
 *  \brief  macro for the definition of the worker launch functions
 */
#define POS_WK_FUNC_LAUNCH()                                \
template<class T_POSTransport, class T_POSClient>           \
pos_retval_t launch(                                        \
    POSWorkspace<T_POSTransport, T_POSClient>* ws,          \
    POSAPIContext_QE_ptr wqe                                \
)

/*!
 *  \brief  macro for the definition of the worker landing functions
 */
#define POS_WK_FUNC_LANDING()                               \
template<class T_POSTransport, class T_POSClient>           \
pos_retval_t landing(                                       \
    POSWorkspace<T_POSTransport, T_POSClient>* ws,          \
    POSAPIContext_QE_ptr wqe                                \
)

namespace wk_functions {
#define POS_WK_DECLARE_FUNCTIONS(api_name) namespace api_name { POS_WK_FUNC_LAUNCH(); POS_WK_FUNC_LANDING(); }
};  // namespace rt_functions

/*!
 *  \brief  POS Worker
 */
template<class T_POSTransport, class T_POSClient>
class POSWorker {
 public:
    POSWorker(POSWorkspace<T_POSTransport, T_POSClient>* ws) : _ws(ws), _stop_flag(false){
        int rc;
        cpu_set_t cpuset;
        CPU_ZERO(&cpuset);
        CPU_SET(2, &cpuset);    // stick to core 2

        // start daemon thread
        _daemon_thread = new std::thread(&daemon, this);
        POS_CHECK_POINTER(_daemon_thread);

        rc = pthread_setaffinity_np(_daemon_thread->native_handle(), sizeof(cpu_set_t), &cpuset);
        assert(rc == 0);

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
    static inline void __restore(POSWorkspace<T_POSTransport, T_POSClient>* ws, POSAPIContext_QE_ptr wqe){
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
    static inline void __done(POSWorkspace<T_POSTransport, T_POSClient>* ws, POSAPIContext_QE_ptr wqe){
        T_POSClient *client;
        POS_CHECK_POINTER(client = wqe->client);

        // forward the DAG pc
        client->dag.forward_pc();
    }

 protected:
    // stop flag to indicate the daemon thread to stop
    bool _stop_flag;

    // the daemon thread of the runtime
    std::thread *_daemon_thread;

    // global workspace
    POSWorkspace<T_POSTransport, T_POSClient>* _ws;

    // worker function map
    std::map<uint64_t, pos_worker_launch_function_t<T_POSTransport, T_POSClient>> _launch_functions;
    std::map<uint64_t, pos_worker_landing_function_t<T_POSTransport, T_POSClient>> _landing_functions;
    
    /*!
     *  \brief  checkpoint procedure, should be implemented by each platform
     *  \note   this function will be invoked by level-1 ckpt
     *  \param  wqe     the checkpoint op
     *  \return POS_SUCCESS for successfully checkpointing
     */
    virtual pos_retval_t checkpoint(POSAPIContext_QE_ptr wqe){ return POS_FAILED_NOT_IMPLEMENTED; }

    /*!
     *  \brief  checkpoint procedure, should be implemented by each platform
     *  \note   this function will be invoked by level-2 ckpt
     *  \param  wqe     the checkpoint op
     *  \param  handles pointer to vector that stores handles to be checkpointed
     *  \return POS_SUCCESS for successfully checkpointing
     */
    virtual pos_retval_t checkpoint_async(POSAPIContext_QE_ptr wqe, std::vector<POSHandle_ptr>* handles){ 
        return POS_FAILED_NOT_IMPLEMENTED; 
    }

    virtual pos_retval_t checkpoint_join();

    /*!
     *  \brief  generate overlap ckpt scheme
     *  \note   this function will be invoked by level-2 ckpt
     *  \param  wqe             the checkpoint op
     *  \param  nb_pending_op   number of pending ops following the ckpt op
     *  \param  ckpt_scheme     pointer to the generated checkpoint overlap scheme
     *  \return POS_SUCCESS for successfully generation
     */
    virtual pos_retval_t generate_overlap_ckpt_scheme(
        POSAPIContext_QE_ptr wqe, uint64_t nb_pending_op, pos_ckpt_overlap_scheme_t* ckpt_scheme
    ){ return POS_FAILED_NOT_IMPLEMENTED; }

 private:
    /*!
     *  \brief  processing daemon of the worker
     */
    void daemon(){
        #if POS_CKPT_OPT_LEVAL == 1
            this->__daemon_o0_o1();
        #elif POS_CKPT_OPT_LEVAL == 2
            this->__daemon_o2();
        #else // POS_CKPT_OPT_LEVAL == 0
            this->__daemon_o0_o1();
        #endif
    }

    void __daemon_o2(){
        uint64_t i, j, k, w, api_id;
        pos_retval_t launch_retval, landing_retval;

        POSAPIMeta_t api_meta;

        std::vector<T_POSClient*> clients;
        T_POSClient* client;

        std::map<pos_resource_typeid_t, std::vector<POSHandleView_t>*>::iterator iter_hvm;
        std::vector<POSHandleView_t>* handle_view_vec;

        POSHandle::pos_broken_handle_list_t broken_handle_list;
        POSHandle *broken_handle;
        uint16_t nb_layers, layer_id_keeper;
        uint64_t handle_id_keeper;

        bool during_ckpt = false, should_join_ckpt_stream = false;
        pos_ckpt_overlap_scheme_t ckpt_overlap_scheme;
        uint64_t nb_ckpt_steps, ckpt_step_id;
        uint64_t nb_pending_ops;
        std::vector<POSHandle_ptr>* overlap_scheme;
        uint64_t query_s_tick, query_e_tick;

        if(unlikely(POS_SUCCESS != daemon_init())){
            POS_WARN_C("failed to init daemon, worker daemon exit");
            return;
        }

        while(!_stop_flag){
            _ws->poll_client_dag(&clients);

            for(i=0; i<clients.size(); i++){
                // we declare the pointer here so every iteration ends the shared_ptr would be released
                POSAPIContext_QE_ptr wqe;

                POS_CHECK_POINTER(client = clients[i]);

                // keep popping next pending op until we finished all operation
                while(POS_SUCCESS == client->dag.get_next_pending_op(&wqe, &nb_pending_ops)){
                    wqe->worker_s_tick = POSUtilTimestamp::get_tsc();
                    api_id = wqe->api_cxt->api_id;

                    // this is a checkpoint op
                    if(api_id == this->_ws->checkpoint_api_id){
                    
                    /*!
                     *  \brief  macro for control the overlapping checkpoint
                     *  \param  POS_CKPT_PENDING_US     maximum time to wait for gathering following ops
                     *  \param  POS_OVERLAP_BATCH_SIZE  overlap batch size
                     *  \note   these configuration should be tuned, if the remoting/parsing performance are optimized in the future!
                     */
                    #if POS_CKPT_INTERVAL >= 1000           /* ms */
                        #define POS_CKPT_PENDING_US 5000    /* us */
                        #define POS_OVERLAP_BATCH_SIZE 20
                    #elif POS_CKPT_INTERVAL >= 100
                        #define POS_CKPT_PENDING_US 500
                        #define POS_OVERLAP_BATCH_SIZE 10  
                    #else
                        #define POS_CKPT_PENDING_US 50
                        #define POS_OVERLAP_BATCH_SIZE 5
                    #endif

                        // Resource DAG
                        // Compare: reexecute

                        // we will wait here for the next following several ops
                        // TODO: we need to prevent the following op is a ckpt op??
                        query_s_tick = POSUtilTimestamp::get_tsc();
                        while(likely(nb_pending_ops <= POS_OVERLAP_BATCH_SIZE)){
                            nb_pending_ops = client->dag.get_nb_pending_op();
                            query_e_tick = POSUtilTimestamp::get_tsc();
                            if(unlikely(POS_TSC_TO_USEC(query_e_tick - query_s_tick) >= POS_CKPT_PENDING_US)){
                                break;
                            }
                        }
                        if(likely(nb_pending_ops == 1)){
                            // POS_LOG("skip ckpt");
                            goto ckpt_op_end;
                        } else {
                            // POS_LOG(
                            //     "ckpt pending %u us, get #following_pending_ops in the DAG: %lu",
                            //     POS_CKPT_PENDING_US,
                            //     nb_pending_ops
                            // );
                        }
                        
                        // generate checkpoint scheme
                        if(unlikely(
                            POS_SUCCESS != this->generate_overlap_ckpt_scheme(wqe, nb_pending_ops, &ckpt_overlap_scheme)
                        )){
                            POS_WARN_C("failed to generate overlap checkpoint scheme");
                            goto ckpt_op_end;
                        }

                        // raise flag
                        // TODO: also, these flag should be per client!!
                        during_ckpt = true;
                        nb_ckpt_steps = nb_pending_ops;
                        ckpt_step_id = 0;
                        
                        // if there's buffers that has no budget to overlap, we need to ckpt here
                        overlap_scheme = ckpt_overlap_scheme.get_overlap_scheme_by_ckpt_step_id(ckpt_step_id);
                        POS_CHECK_POINTER(overlap_scheme);
                        // POS_LOG("ckpt op need to ckpt %lu orphan handles", overlap_scheme->size());
                        for(j=0; j<overlap_scheme->size(); j++){
                            if(unlikely(POS_SUCCESS != (*overlap_scheme)[i]->checkpoint(wqe->dag_vertex_id))){
                                POS_WARN_C_DETAIL("failed to checkpoint handle");
                            }   
                        }
                        cudaStreamSynchronize(0);

                        ckpt_step_id += 1;

                    ckpt_op_end:
                        __done(this->_ws, wqe);
                        wqe->worker_e_tick = POSUtilTimestamp::get_tsc();
                        continue;
                    }

                    api_meta = _ws->api_mgnr->api_metas[api_id];

                    /*! \note   verify whether all relyed resources are ready, if not, we need to restore their state first */
                    for(iter_hvm = wqe->handle_view_map.begin(); iter_hvm != wqe->handle_view_map.end(); iter_hvm ++){

                        handle_view_vec = iter_hvm->second;
                        
                        for(j=0; j<handle_view_vec->size(); j++){
                            broken_handle_list.reset();
                            (*handle_view_vec)[j].handle->collect_broken_handles(&broken_handle_list);

                            /*!
                             *  \todo   1. should restore based on DAG info;
                             *          2. this is a recursive procedure: obtain an op list to reexecute to restore these handles
                             *          3. we need a good checkpoint mechanism to shorten the duration here
                             */

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

                                if(unlikely(POS_SUCCESS != broken_handle->restore())){
                                    POS_ERROR_C(
                                        "failed to restore broken handle: resource_type_id(%lu), client_addr(%p), server_addr(%p), state(%u)",
                                        broken_handle->resource_type_id, broken_handle->client_addr, broken_handle->server_addr,
                                        broken_handle->status
                                    );
                                } else {
                                    POS_DEBUG_C(
                                        "restore broken handle: resource_type_id(%lu)",
                                        broken_handle->resource_type_id
                                    );
                                }
                            } // while (1)
                        } // for(j=0; j<handle_view_vec->size(); j++)
                    } // for(iter_hvm = wqe->handle_view_map.begin(); iter_hvm != wqe->handle_view_map.end(); iter_hvm ++)

                #if POS_ENABLE_DEBUG_CHECK
                    if(unlikely(_launch_functions.count(api_id) == 0)){
                        POS_ERROR_C_DETAIL(
                            "runtime has no worker launch function for api %lu, need to implement", api_id
                        );
                    }
                #endif

                    if(unlikely(during_ckpt == true)){
                        overlap_scheme = ckpt_overlap_scheme.get_overlap_scheme_by_ckpt_step_id(ckpt_step_id);
                        POS_CHECK_POINTER(overlap_scheme);

                        if(unlikely(POS_SUCCESS != this->checkpoint_async(wqe, overlap_scheme))){
                            POS_WARN("op %lu failed to checkpointed %lu handles", wqe->dag_vertex_id, overlap_scheme->size());
                        } else {
                            // POS_LOG("op %lu checkpointed %lu handles", wqe->dag_vertex_id, overlap_scheme->size());
                        }
                        
                        ckpt_step_id += 1;

                        // judge whether checkpoint is done
                        if(unlikely(ckpt_step_id == nb_ckpt_steps)){ 
                            during_ckpt = false;
                        }

                        should_join_ckpt_stream = true;
                    }

                    launch_retval = (*(_launch_functions[api_id]))(_ws, wqe);
                    if(launch_retval != POS_SUCCESS){
                        wqe->api_cxt->return_code = _ws->api_mgnr->cast_pos_retval(
                            /* pos_retval */ launch_retval, 
                            /* library_id */ api_meta.library_id
                        );

                        wqe->worker_e_tick = POSUtilTimestamp::get_tsc();

                        if(wqe->status == kPOS_API_Execute_Status_Init){
                            // we only return the QE back to frontend when it hasn't been returned before
                            wqe->status = kPOS_API_Execute_Status_Launch_Failed;
                            wqe->return_tick = POSUtilTimestamp::get_tsc();
                            _ws->template push_cq<kPOS_Queue_Position_Worker>(wqe);
                        }

                        continue;
                    }
                
                #if POS_ENABLE_DEBUG_CHECK
                    if(unlikely(_landing_functions.count(api_id) == 0)){
                        POS_ERROR_C_DETAIL(
                            "runtime has no worker landing function for api %lu, need to implement", api_id
                        );
                    }
                #endif
                
                    landing_retval = (*(_landing_functions[api_id]))(_ws, wqe);
                    wqe->api_cxt->return_code = _ws->api_mgnr->cast_pos_retval(
                        /* pos_retval */ landing_retval, 
                        /* library_id */ api_meta.library_id
                    );

                    if(unlikely(should_join_ckpt_stream)){
                        this->checkpoint_join();
                        should_join_ckpt_stream = false;
                    }

                    wqe->worker_e_tick = POSUtilTimestamp::get_tsc();
                    
                    if(wqe->status == kPOS_API_Execute_Status_Init){
                        // we only return the QE back to frontend when it hasn't been returned before
                        wqe->status = kPOS_API_Execute_Status_Launch_Failed;
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
    void __daemon_o0_o1(){
        uint64_t i, j, k, w, api_id;
        pos_retval_t launch_retval, landing_retval;

        POSAPIMeta_t api_meta;

        std::vector<T_POSClient*> clients;
        T_POSClient* client;

        std::map<pos_resource_typeid_t, std::vector<POSHandleView_t>*>::iterator iter_hvm;
        std::vector<POSHandleView_t>* handle_view_vec;

        POSHandle::pos_broken_handle_list_t broken_handle_list;
        POSHandle *broken_handle;
        uint16_t nb_layers, layer_id_keeper;
        uint64_t handle_id_keeper;
        
        if(unlikely(POS_SUCCESS != daemon_init())){
            POS_WARN_C("failed to init daemon, worker daemon exit");
            return;
        }

        while(!_stop_flag){
            _ws->poll_client_dag(&clients);

            // it's too annoy to print here :-(
            // if(clients.size() > 0){
            //     POS_DEBUG_C("polling client dags, obtain %lu pending clients", clients.size());
            // }

            for(i=0; i<clients.size(); i++){
                // we declare the pointer here so every iteration ends the shared_ptr would be released
                POSAPIContext_QE_ptr wqe;

                POS_CHECK_POINTER(client = clients[i]);

                // keep popping next pending op until we finished all operation
                while(POS_SUCCESS == client->dag.get_next_pending_op(&wqe)){
                    wqe->worker_s_tick = POSUtilTimestamp::get_tsc();
                    api_id = wqe->api_cxt->api_id;

                    // this is a checkpoint op
                    if(api_id == this->_ws->checkpoint_api_id){
                        if(unlikely(POS_SUCCESS != this->checkpoint(wqe))){
                            POS_WARN_C("failed to do checkpointing");
                        }
                        __done(this->_ws, wqe);
                        wqe->worker_e_tick = POSUtilTimestamp::get_tsc();
                        continue;
                    }

                    api_meta = _ws->api_mgnr->api_metas[api_id];

                    /*! \note   verify whether all relyed resources are ready, if not, we need to restore their state first */
                    for(iter_hvm = wqe->handle_view_map.begin(); iter_hvm != wqe->handle_view_map.end(); iter_hvm ++){

                        handle_view_vec = iter_hvm->second;
                        
                        for(j=0; j<handle_view_vec->size(); j++){
                            broken_handle_list.reset();
                            (*handle_view_vec)[j].handle->collect_broken_handles(&broken_handle_list);

                            /*!
                             *  \todo   1. should restore based on DAG info;
                             *          2. this is a recursive procedure: obtain an op list to reexecute to restore these handles
                             *          3. we need a good checkpoint mechanism to shorten the duration here
                             */

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

                                if(unlikely(POS_SUCCESS != broken_handle->restore())){
                                    POS_ERROR_C(
                                        "failed to restore broken handle: resource_type_id(%lu), client_addr(%p), server_addr(%p), state(%u)",
                                        broken_handle->resource_type_id, broken_handle->client_addr, broken_handle->server_addr,
                                        broken_handle->status
                                    );
                                } else {
                                    POS_DEBUG_C(
                                        "restore broken handle: resource_type_id(%lu)",
                                        broken_handle->resource_type_id
                                    );
                                }
                            } // while (1)
                        } // for(j=0; j<handle_view_vec->size(); j++)
                    } // for(iter_hvm = wqe->handle_view_map.begin(); iter_hvm != wqe->handle_view_map.end(); iter_hvm ++)

                #if POS_ENABLE_DEBUG_CHECK
                    if(unlikely(_launch_functions.count(api_id) == 0)){
                        POS_ERROR_C_DETAIL(
                            "runtime has no worker launch function for api %lu, need to implement", api_id
                        );
                    }
                #endif

                    launch_retval = (*(_launch_functions[api_id]))(_ws, wqe);
                    if(launch_retval != POS_SUCCESS){
                        wqe->api_cxt->return_code = _ws->api_mgnr->cast_pos_retval(
                            /* pos_retval */ launch_retval, 
                            /* library_id */ api_meta.library_id
                        );

                        wqe->worker_e_tick = POSUtilTimestamp::get_tsc();

                        if(wqe->status == kPOS_API_Execute_Status_Init){
                            // we only return the QE back to frontend when it hasn't been returned before
                            wqe->status = kPOS_API_Execute_Status_Launch_Failed;
                            wqe->return_tick = POSUtilTimestamp::get_tsc();
                            _ws->template push_cq<kPOS_Queue_Position_Worker>(wqe);
                        }

                        continue;
                    }
                
                #if POS_ENABLE_DEBUG_CHECK
                    if(unlikely(_landing_functions.count(api_id) == 0)){
                        POS_ERROR_C_DETAIL(
                            "runtime has no worker landing function for api %lu, need to implement", api_id
                        );
                    }
                #endif
                
                    landing_retval = (*(_landing_functions[api_id]))(_ws, wqe);
                    wqe->api_cxt->return_code = _ws->api_mgnr->cast_pos_retval(
                        /* pos_retval */ landing_retval, 
                        /* library_id */ api_meta.library_id
                    );

                    wqe->worker_e_tick = POSUtilTimestamp::get_tsc();
                    
                    if(wqe->status == kPOS_API_Execute_Status_Init){
                        // we only return the QE back to frontend when it hasn't been returned before
                        wqe->status = kPOS_API_Execute_Status_Launch_Failed;
                        wqe->return_tick = POSUtilTimestamp::get_tsc();
                        _ws->template push_cq<kPOS_Queue_Position_Worker>(wqe);
                    }
                }
            }
            
            clients.clear();
        }
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
