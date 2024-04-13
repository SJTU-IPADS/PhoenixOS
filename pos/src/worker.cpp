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
#include "pos/include/trace/base.h"
#include "pos/include/trace/tick.h"
#include "pos/include/worker.h"
#include "pos/include/client.h"
#include "pos/include/workspace.h"


#if POS_CKPT_OPT_LEVEL == 0 || POS_CKPT_OPT_LEVEL == 1

/*!
 *  \brief  worker daemon with / without SYNC checkpoint support (checkpoint optimization level 0 and 1)
 */
void POSWorker::__daemon_ckpt_sync(){
    uint64_t i, j, k, w, api_id;
    pos_retval_t launch_retval;
    POSAPIMeta_t api_meta;
    std::vector<POSClient*> clients;
    POSClient* client;
    POSAPIContext_QE *wqe;

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
                    if(unlikely(POS_SUCCESS != this->sync())){
                        POS_WARN_C("failed to synchornize the worker thread before starting checkpoint op");
                        goto ckpt_finished;
                    }

                    if(unlikely(POS_SUCCESS != this->__checkpoint_sync(wqe))){
                        POS_WARN_C("failed to do checkpointing");
                    }
                
                ckpt_finished:
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
 *  \brief  checkpoint procedure, should be implemented by each platform
 *  \note   this function will be invoked by level-1 ckpt
 *  \param  wqe     the checkpoint op
 *  \return POS_SUCCESS for successfully checkpointing
 */
pos_retval_t POSWorker::__checkpoint_sync(POSAPIContext_QE* wqe){
    uint64_t i;
    std::vector<POSHandleView_t>* handle_views;
    uint64_t nb_handles;
    POSClient *client;
    POSHandleManager<POSHandle>* hm;
    POSCheckpointSlot *ckpt_slot;
    pos_retval_t retval = POS_SUCCESS;

    typename std::map<pos_resource_typeid_t, std::set<POSHandle*>>::iterator map_iter;
    typename std::set<POSHandle*>::iterator set_iter;

    POS_CHECK_POINTER(wqe);

    wqe->nb_ckpt_handles = 0;
    wqe->ckpt_size = 0;
    wqe->ckpt_memory_consumption = 0;

    for(set_iter=wqe->checkpoint_handles.begin(); set_iter!=wqe->checkpoint_handles.end(); set_iter++){
        const POSHandle *handle = *set_iter;
        POS_CHECK_POINTER(handle);

        if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                    || handle->status == kPOS_HandleStatus_Create_Pending
                    || handle->status == kPOS_HandleStatus_Broken
        )){
            continue;
        }

        retval = handle->checkpoint_sync(
            /* version_id */ handle->latest_version,
            /* stream_id */ 0
        );
        if(unlikely(POS_SUCCESS != retval)){
            POS_WARN_C("failed to checkpoint handle");
            retval = POS_FAILED;
            goto exit;
        }

        wqe->nb_ckpt_handles += 1;
        wqe->ckpt_size += handle->state_size;
    }
    
    // make sure the checkpoint is finished
    retval = this->sync();

    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN("checkpoint unfinished: failed to synchronize");
    } else {
        // TODO: record to trace
        POS_LOG(
            "checkpoint finished: #finished_handles(%lu), size(%lu Bytes)",
            wqe->nb_ckpt_handles, wqe->ckpt_size
        );
    }
    
exit:
    return retval;
}

#elif POS_CKPT_OPT_LEVEL == 2

/*!
 *  \brief  worker daemon with ASYNC checkpoint support (checkpoint optimization level 2)
 */
void POSWorker::__daemon_ckpt_async(){
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

                    POS_TRACE(true, POS_TRACE_TICK_START(worker, ckpt_drain));
                    if(unlikely(POS_SUCCESS != this->sync())){
                        POS_WARN_C("failed to synchornize the worker thread before starting checkpoint op");
                        goto ckpt_finished;
                    }
                    POS_TRACE(true, POS_TRACE_TICK_APPEND(worker, ckpt_drain));

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
                    ckpt_thread = new std::thread(&POSWorker::__checkpoint_async_thread, this, &ckpt_cxt);
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
                    *  \note   there're serval cases handle in checkpoint_add:
                    *          [1] the state hasn't been checkpoint yet, then it conducts CoW on the state
                    *          [2] the state is under checkpointing, then it blocks until the checkpoint finished
                    *          [3] the state is already checkpointed, then it directly returns
                    */
                for(auto &inout_handle_view : wqe->inout_handle_views){
                    POS_CHECK_POINTER(handle = inout_handle_view.handle);
                    if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                                || handle->status == kPOS_HandleStatus_Create_Pending
                                || handle->status == kPOS_HandleStatus_Broken
                    )){
                        continue;
                    }
                    if(ckpt_cxt.checkpoint_version_map.count(handle) > 0){
                        POS_TRACE(true, POS_TRACE_TICK_START(worker, ckpt_cow));
                        tmp_retval = handle->checkpoint_add(
                            /* version_id */ ckpt_cxt.checkpoint_version_map[handle],
                            /* stream_id */ wqe->execution_stream_id
                        );
                        POS_ASSERT(tmp_retval == POS_SUCCESS || tmp_retval == POS_WARN_ABANDONED);
                        if(tmp_retval == POS_SUCCESS){
                            POS_TRACE(true, POS_TRACE_TICK_APPEND(worker, ckpt_cow));
                        }
                    }
                }
                for(auto &out_handle_view : wqe->output_handle_views){
                    POS_CHECK_POINTER(handle = out_handle_view.handle);
                    if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                                || handle->status == kPOS_HandleStatus_Create_Pending
                                || handle->status == kPOS_HandleStatus_Broken
                    )){
                        continue;
                    }
                    if(ckpt_cxt.checkpoint_version_map.count(handle) > 0){
                        POS_TRACE(true, POS_TRACE_TICK_START(worker, ckpt_cow));
                        tmp_retval = handle->checkpoint_add(
                            /* version_id */ ckpt_cxt.checkpoint_version_map[handle],
                            /* stream_id */ wqe->execution_stream_id
                        );
                        POS_ASSERT(tmp_retval == POS_SUCCESS || tmp_retval == POS_WARN_ABANDONED);
                        if(tmp_retval == POS_SUCCESS){
                            POS_TRACE(true, POS_TRACE_TICK_APPEND(worker, ckpt_cow));
                        }
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

                // print staticstics and start new round of trace
                POS_TRACE(
                    /* cond */ true,
                    /* trace_workload */ 
                    POS_TRACE_TICK_TRY_COLLECT(worker, {
                        POS_LOG(
                            "[Worker] Checkpoint Statistics:\n"
                            "   [Drain]     Overall(%lf ms), Times(%lu), Avg.(%lf ms)\n"
                            "   [CoW]       Overall(%lf ms), Times(%lu), Avg.(%lf ms)\n"
                            "   [Add]       Overall(%lf ms), Times(%lu), Avg.(%lf ms)\n"
                            "   [Commit]    Overall(%lf ms), Times(%lu), Avg.(%lf ms)\n"
                            ,
                            POS_TRACE_TICK_GET_MS(worker, ckpt_drain),
                            POS_TRACE_TICK_GET_TIMES(worker, ckpt_drain),
                            POS_TRACE_TICK_GET_AVG_MS(worker, ckpt_drain),

                            POS_TRACE_TICK_GET_MS(worker, ckpt_cow),
                            POS_TRACE_TICK_GET_TIMES(worker, ckpt_cow),
                            POS_TRACE_TICK_GET_AVG_MS(worker, ckpt_cow),

                            POS_TRACE_TICK_GET_MS(worker, ckpt_add),
                            POS_TRACE_TICK_GET_TIMES(worker, ckpt_add),
                            POS_TRACE_TICK_GET_AVG_MS(worker, ckpt_add),

                            POS_TRACE_TICK_GET_MS(worker, ckpt_commit),
                            POS_TRACE_TICK_GET_TIMES(worker, ckpt_commit),
                            POS_TRACE_TICK_GET_AVG_MS(worker, ckpt_commit)
                        );
                        POS_TRACE_TICK_LIST_RESET(worker);
                    })
                );
            }
        }
        
        clients.clear();
    }
}

/*!
 *  \brief  overlapped checkpoint procedure, should be implemented by each platform
 *  \note   this thread will be raised by level-2 ckpt
 *  \note   aware of the macro POS_CKPT_ENABLE_PIPELINE
 *  \note   aware of the macro POS_CKPT_ENABLE_ORCHESTRATION
 *  \param  cxt     the context of this checkpointing
 */
void POSWorker::__checkpoint_async_thread(checkpoint_async_cxt_t* cxt) {
    uint64_t i;
    pos_vertex_id_t checkpoint_version;
    pos_retval_t retval = POS_SUCCESS;
    POSAPIContext_QE *wqe;
    POSHandle *handle;
    uint64_t s_tick = 0, e_tick = 0;

#if POS_CKPT_ENABLE_PIPELINE == 1
    std::vector<std::shared_future<pos_retval_t>> _commit_threads;
    std::shared_future<pos_retval_t> _new_commit_thread;
#endif

    typename std::map<pos_resource_typeid_t, std::set<POSHandle*>>::iterator map_iter;
    typename std::set<POSHandle*>::iterator set_iter;

    POS_CHECK_POINTER(cxt);
    POS_CHECK_POINTER(wqe = cxt->wqe);
    POS_ASSERT(this->_ckpt_stream_id != 0);
    #if POS_CKPT_ENABLE_PIPELINE == 1
        POS_ASSERT(this->_ckpt_commit_stream_id != 0);
    #endif

    wqe->nb_ckpt_handles = 0;
    wqe->ckpt_size = 0;
    wqe->nb_abandon_handles = 0;
    wqe->abandon_ckpt_size = 0;
    wqe->ckpt_memory_consumption = 0;
    
    for(set_iter=wqe->checkpoint_handles.begin(); set_iter!=wqe->checkpoint_handles.end(); set_iter++){
        POSHandle *handle = *set_iter;
        POS_CHECK_POINTER(handle);
        
        if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                    || handle->status == kPOS_HandleStatus_Create_Pending
                    || handle->status == kPOS_HandleStatus_Broken
        )){
            continue;
        }

        if(unlikely(cxt->checkpoint_version_map.count(handle) == 0)){
            POS_WARN_C("failed to checkpoint handle, no checkpoint version provided: client_addr(%p)", handle->client_addr);
            continue;
        }

        checkpoint_version = cxt->checkpoint_version_map[handle];

    #if POS_CKPT_ENABLE_PIPELINE == 1
        /*!
         *  \brief  [phrase 1]  add the state of this handle from its origin buffer
         *  \note   the adding process is sync as it might disturbed by CoW
         */
        POS_TRACE(
            /* cond */ unlikely(set_iter == wqe->checkpoint_handles.begin()),
            /* trace_workload */ POS_TRACE_TICK_START(worker, ckpt_add)
        );
        retval = handle->checkpoint_add(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_stream_id
        );
        POS_ASSERT(retval == POS_SUCCESS || retval == POS_WARN_ABANDONED);
        POS_TRACE(
            /* cond */ unlikely(std::next(set_iter) == wqe->checkpoint_handles.end()),
            /* trace_workload */ POS_TRACE_TICK_APPEND_NO_COUNT(worker, ckpt_add)
        );

        /*!
         *  \brief  [phrase 2]  commit the resource state from cache
         *  \note   the commit process is async as it would never be disturbed by CoW
         */
        POS_TRACE(
            /* cond */ unlikely(set_iter == wqe->checkpoint_handles.begin()),
            /* trace_workload */ POS_TRACE_TICK_START(worker, ckpt_commit)
        );
        retval = handle->checkpoint_commit(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_commit_stream_id
        );
        POS_TRACE(
            /* cond */ unlikely(std::next(set_iter) == wqe->checkpoint_handles.end()),
            /* trace_workload */ POS_TRACE_TICK_APPEND_NO_COUNT(worker, ckpt_commit)
        );
    #else
        /*!
         *  \brief  [phrase 1]  commit the resource state from origin buffer or CoW cache
         *  \note   if the CoW is ongoing or finished, it commit from cache; otherwise it commit from origin buffer
         */
        POS_TRACE(
            /* cond */ unlikely(set_iter == wqe->checkpoint_handles.begin()),
            /* trace_workload */ POS_TRACE_TICK_START(worker, ckpt_commit)
        );
        retval = handle->checkpoint_commit(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_stream_id
        );
        POS_ASSERT(retval == POS_SUCCESS || retval == POS_WARN_ABANDONED);
        POS_TRACE(
            /* cond */ unlikely(std::next(set_iter) == wqe->checkpoint_handles.end()),
            /* trace_workload */ POS_TRACE_TICK_APPEND_NO_COUNT(worker, ckpt_commit)
        );
    #endif
    
        wqe->nb_ckpt_handles += 1;
        wqe->ckpt_size += handle->state_size;   
    }

    
    POS_TRACE(
        /* cond */ true,
        /* trace_workload */ POS_TRACE_TICK_START(worker, ckpt_commit)
    );
    #if POS_CKPT_ENABLE_PIPELINE == 1
        /*!
         *  \note   [phrase 3]  synchronize all commits
         *                      this phrase is only enabled when checkpoint pipeline is enabled
         */
        
        
        // wait all commit thread to exit
        // for(auto &commit_thread : _commit_threads){
        //     if(unlikely(POS_SUCCESS != commit_thread.get())){
        //         POS_WARN_C("failure occured within the commit thread");
        //     }
        // }

        // wait all commit job to finished
        retval = this->sync(this->_ckpt_commit_stream_id);
        POS_ASSERT(retval == POS_SUCCESS);

        // we add one count to ckpt_add process
        POS_TRACE(true, POS_TRACE_TICK_ADD_COUNT(worker, ckpt_add));
    #else
        // wait all commit job to finished
        retval = this->sync(this->_ckpt_stream_id);
        POS_ASSERT(retval == POS_SUCCESS);
    #endif
    POS_TRACE(
        /* cond */ true,
        /* trace_workload */ POS_TRACE_TICK_APPEND(worker, ckpt_commit)
    );

    POS_LOG(
        "checkpoint finished: #finished_handles(%lu), size(%lu Bytes)",
        wqe->nb_ckpt_handles, wqe->ckpt_size
    );

exit:
    cxt->is_active = false;
}

#endif // POS_CKPT_OPT_LEVEL


/*!
 *  \brief  check and restore all broken handles, if there's any exists
 *  \param  wqe         the op to be checked and restored
 *  \param  api_meta    metadata of the called API
 *  \return POS_SUCCESS for successfully checking and restoring
 */
pos_retval_t POSWorker::__restore_broken_handles(POSAPIContext_QE* wqe, POSAPIMeta_t& api_meta){
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
