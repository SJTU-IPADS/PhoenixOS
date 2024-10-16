/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
#include "pos/include/trace.h"
#include "pos/include/worker.h"
#include "pos/include/client.h"
#include "pos/include/workspace.h"


POSWorker::POSWorker(POSWorkspace* ws, POSClient* client) {
    POS_CHECK_POINTER(this->_ws = ws);
    POS_CHECK_POINTER(this->_client = client);
    this->_stop_flag = false;

    // start daemon thread
    this->_daemon_thread = new std::thread(&POSWorker::__daemon, this);
    POS_CHECK_POINTER(this->_daemon_thread);
    
    #if POS_CONF_EVAL_CkptOptLevel == 2
        this->_ckpt_stream_id = 0;
        this->_cow_stream_id = 0;
    #endif

    #if POS_CONF_EVAL_CkptOptLevel == 2 && POS_CONF_EVAL_CkptEnablePipeline == 1
        this->_ckpt_commit_stream_id = 0;
    #endif

    #if POS_CONF_EVAL_MigrOptLevel > 0
        this->_migration_precopy_stream_id = 0;
    #endif

    // initialize trace tick list
    POS_TRACE_TICK_LIST_SET_TSC_TIMER(ckpt, &ws->tsc_timer);
    POS_TRACE_TICK_LIST_RESET(ckpt);

    POS_LOG_C("worker started");
}


/*!
 *  \brief  generic restore procedure
 *  \note   should be invoked within the landing function, while exeucting failed
 *  \param  ws  the global workspace
 *  \param  wqe the work QE where failure was detected
 */
void POSWorker::__restore(POSWorkspace* ws, POSAPIContext_QE* wqe){
    POS_ERROR_DETAIL(
        "execute failed, restore mechanism to be implemented: api_id(%lu), retcode(%d), pc(%lu)",
        wqe->api_cxt->api_id, wqe->api_cxt->return_code, wqe->dag_vertex_id
    ); 
}

/*!
 *  \brief  generic complete procedure
 *  \note   should be invoked within the landing function, while exeucting success
 *  \param  ws  the global workspace
 *  \param  wqe the work QE where failure was detected
 */
void POSWorker::__done(POSWorkspace* ws, POSAPIContext_QE* wqe){
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



#if POS_CONF_EVAL_CkptOptLevel == 0 || POS_CONF_EVAL_CkptOptLevel == 1

/*!
 *  \brief  worker daemon with / without SYNC checkpoint support (checkpoint optimization level 0 and 1)
 */
void POSWorker::__daemon_ckpt_sync(){
    uint64_t i, j, k, w, api_id;
    pos_retval_t launch_retval;
    POSAPIMeta_t api_meta;
    POSAPIContext_QE *wqe;

    while(!_stop_flag){

        while(this->_client->status != kPOS_ClientStatus_Active){}

        if(POS_SUCCESS == this->_client->dag.get_next_pending_op(&wqe)){
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

        #if POS_CONF_RUNTIME_EnableDebugCheck
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

#elif POS_CONF_EVAL_CkptOptLevel == 2

/*!
 *  \brief  worker daemon with ASYNC checkpoint support (checkpoint optimization level 2)
 */
void POSWorker::__daemon_ckpt_async(){
    uint64_t i, j, k, w, api_id;
    pos_retval_t launch_retval, tmp_retval;
    POSAPIMeta_t api_meta;
    POSAPIContext_QE *wqe;

    typename std::set<POSHandle*>::iterator handle_set_iter;
    POSHandle *handle;

    while(!_stop_flag){

        while(this->_client->status != kPOS_ClientStatus_Active){}

        if(POS_SUCCESS == this->_client->dag.get_next_pending_op(&wqe)){
            wqe->worker_s_tick = POSUtilTimestamp::get_tsc();
            api_id = wqe->api_cxt->api_id;

            // this is a checkpoint op
            if(unlikely(api_id == this->_ws->checkpoint_api_id)){
                // if nothing to be checkpointed, we just omit
                if(unlikely(wqe->checkpoint_handles.size() == 0)){
                    goto ckpt_finished;
                }

                POS_TRACE_TICK_START(ckpt, ckpt_drain);
                if(unlikely(POS_SUCCESS != this->sync())){
                    POS_WARN_C("failed to synchornize the worker thread before starting checkpoint op");
                    goto ckpt_finished;
                }
                POS_TRACE_TICK_APPEND(ckpt, ckpt_drain);

                /*!
                    *  \note   if previous checkpoint thread hasn't finished yet, we abandon this checkpoint
                    *          to avoid waiting overhead here
                    *  \note   so the actual checkpoint interval might not be accurate
                    */
                if(this->async_ckpt_cxt.is_active == true){
                    POS_LOG("skip checkpoint due to previous one is still non-finished");
                    goto ckpt_finished;
                }
                
                // start new checkpoint thread
                this->async_ckpt_cxt.wqe = wqe;

                // delete the handle of previous checkpoint
                if(likely(this->async_ckpt_cxt.thread != nullptr)){
                    this->async_ckpt_cxt.thread->join();
                    delete this->async_ckpt_cxt.thread;

                    // collect the statistic of last checkpoint round
                    #if POS_CONF_RUNTIME_EnableTrace
                        POS_LOG(
                            "[Worker] Checkpoint Statistics:\n"
                            "   [Drain]     Overall(%lf ms), Times(%lu), Avg.(%lf ms)\n"
                            "   [CoW-done]  Overall(%lf ms), Times(%lu), Avg.(%lf ms), Size(%lu bytes)\n"
                            "   [CoW-wait]  Overall(%lf ms), Times(%lu), Avg.(%lf ms), Size(%lu bytes)\n"
                            "   [Add-done]  Overall(%lf ms), Times(%lu), Avg.(%lf ms), Size(%lu bytes)\n"
                            "   [Add-wait]  Overall(%lf ms), Times(%lu), Avg.(%lf ms), Size(%lu bytes)\n"
                            "   [Commit]    Overall(%lf ms), Times(%lu), Avg.(%lf ms), Size(%lu bytes)\n"
                            ,
                            POS_TRACE_TICK_GET_MS(ckpt, ckpt_drain),
                            POS_TRACE_TICK_GET_TIMES(ckpt, ckpt_drain),
                            POS_TRACE_TICK_GET_AVG_MS(ckpt, ckpt_drain),

                            POS_TRACE_TICK_GET_MS(ckpt, ckpt_cow_done),
                            POS_TRACE_TICK_GET_TIMES(ckpt, ckpt_cow_done),
                            POS_TRACE_TICK_GET_AVG_MS(ckpt, ckpt_cow_done),
                            POS_TRACE_COUNTER_GET(ckpt, ckpt_cow_done_size),

                            POS_TRACE_TICK_GET_MS(ckpt, ckpt_cow_wait),
                            POS_TRACE_TICK_GET_TIMES(ckpt, ckpt_cow_wait),
                            POS_TRACE_TICK_GET_AVG_MS(ckpt, ckpt_cow_wait),
                            POS_TRACE_COUNTER_GET(ckpt, ckpt_cow_wait_size),

                            POS_TRACE_TICK_GET_MS(ckpt, ckpt_add_done),
                            POS_TRACE_TICK_GET_TIMES(ckpt, ckpt_add_done),
                            POS_TRACE_TICK_GET_AVG_MS(ckpt, ckpt_add_done),
                            POS_TRACE_COUNTER_GET(ckpt, ckpt_add_done_size),

                            POS_TRACE_TICK_GET_MS(ckpt, ckpt_add_wait),
                            POS_TRACE_TICK_GET_TIMES(ckpt, ckpt_add_wait),
                            POS_TRACE_TICK_GET_AVG_MS(ckpt, ckpt_add_wait),
                            POS_TRACE_COUNTER_GET(ckpt, ckpt_add_wait_size),

                            POS_TRACE_TICK_GET_MS(ckpt, ckpt_commit),
                            POS_TRACE_TICK_GET_TIMES(ckpt, ckpt_commit),
                            POS_TRACE_TICK_GET_AVG_MS(ckpt, ckpt_commit),
                            POS_TRACE_COUNTER_GET(ckpt, ckpt_commit_size)
                        );
                        POS_TRACE_TICK_LIST_RESET(ckpt);
                        POS_TRACE_COUNTER_LIST_RESET(ckpt);
                    #endif
                }

                // reset checkpoint version map
                this->async_ckpt_cxt.checkpoint_version_map.clear();
                for(handle_set_iter = wqe->checkpoint_handles.begin(); 
                    handle_set_iter != wqe->checkpoint_handles.end(); 
                    handle_set_iter++)
                {
                    POS_CHECK_POINTER(handle = *handle_set_iter);
                    handle->reset_preserve_counter();
                    this->async_ckpt_cxt.checkpoint_version_map[handle] = handle->latest_version;
                }

                // raise new checkpoint thread
                this->async_ckpt_cxt.thread = new std::thread(&POSWorker::__checkpoint_async_thread, this);
                POS_CHECK_POINTER(this->async_ckpt_cxt.thread);
                this->async_ckpt_cxt.is_active = true;

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

            #if POS_CONF_RUNTIME_EnableDebugCheck
                if(unlikely(_launch_functions.count(api_id) == 0)){
                    POS_ERROR_C_DETAIL(
                        "runtime has no worker launch function for api %lu, need to implement", api_id
                    );
                }
            #endif

            if(unlikely(this->async_ckpt_cxt.is_active == true)){
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
                    if(this->async_ckpt_cxt.checkpoint_version_map.count(handle) > 0){
                        POS_TRACE_TICK_START(ckpt, ckpt_cow_done);
                        POS_TRACE_TICK_START(ckpt, ckpt_cow_wait);
                        tmp_retval = handle->checkpoint_add(
                            /* version_id */ this->async_ckpt_cxt.checkpoint_version_map[handle],
                            /* stream_id */ // wqe->execution_stream_id
                                            this->_cow_stream_id
                        );
                        POS_ASSERT(tmp_retval == POS_SUCCESS || tmp_retval == POS_WARN_ABANDONED || tmp_retval == POS_FAILED_ALREADY_EXIST);
                        if(tmp_retval == POS_SUCCESS){
                            POS_TRACE_TICK_APPEND(ckpt, ckpt_cow_done);
                            POS_TRACE_COUNTER_ADD(ckpt, ckpt_cow_done_size, handle->state_size);
                        } else if(tmp_retval == POS_WARN_ABANDONED){
                            POS_TRACE_TICK_APPEND(ckpt, ckpt_cow_wait);
                            POS_TRACE_COUNTER_ADD(ckpt, ckpt_cow_wait_size, handle->state_size);
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
                    if(this->async_ckpt_cxt.checkpoint_version_map.count(handle) > 0){
                        POS_TRACE_TICK_START(ckpt, ckpt_cow_done);
                        POS_TRACE_TICK_START(ckpt, ckpt_cow_wait);
                        tmp_retval = handle->checkpoint_add(
                            /* version_id */ this->async_ckpt_cxt.checkpoint_version_map[handle],
                            /* stream_id */ // wqe->execution_stream_id
                                            this->_cow_stream_id
                        );
                        POS_ASSERT(tmp_retval == POS_SUCCESS || tmp_retval == POS_WARN_ABANDONED || tmp_retval == POS_FAILED_ALREADY_EXIST);
                        if(tmp_retval == POS_SUCCESS){
                            POS_TRACE_TICK_APPEND(ckpt, ckpt_cow_done);
                            POS_TRACE_COUNTER_ADD(ckpt, ckpt_cow_done_size, handle->state_size);
                        } else if(tmp_retval == POS_WARN_ABANDONED){
                            POS_TRACE_TICK_APPEND(ckpt, ckpt_cow_wait);
                            POS_TRACE_COUNTER_ADD(ckpt, ckpt_cow_wait_size, handle->state_size);
                        }
                    }
                }
            } // this->async_ckpt_cxt.is_active == true
            
        
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
}

/*!
 *  \brief  overlapped checkpoint procedure, should be implemented by each platform
 *  \note   this thread will be raised by level-2 ckpt
 *  \note   aware of the macro POS_CONF_EVAL_CkptEnablePipeline
 *  \note   aware of the macro POS_CKPT_ENABLE_ORCHESTRATION
 *  \param  cxt     the context of this checkpointing
 */
void POSWorker::__checkpoint_async_thread() {
    uint64_t i;
    pos_vertex_id_t checkpoint_version;
    pos_retval_t retval = POS_SUCCESS;
    POSAPIContext_QE *wqe;
    POSHandle *handle;
    uint64_t s_tick = 0, e_tick = 0;

#if POS_CONF_EVAL_CkptEnablePipeline == 1
    std::vector<std::shared_future<pos_retval_t>> _commit_threads;
    std::shared_future<pos_retval_t> _new_commit_thread;
#endif

    typename std::map<pos_resource_typeid_t, std::set<POSHandle*>>::iterator map_iter;
    typename std::set<POSHandle*>::iterator set_iter;

    POS_CHECK_POINTER(wqe = this->async_ckpt_cxt.wqe);
    POS_ASSERT(this->_ckpt_stream_id != 0);
    #if POS_CONF_EVAL_CkptEnablePipeline == 1
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

        if(unlikely(this->async_ckpt_cxt.checkpoint_version_map.count(handle) == 0)){
            POS_WARN_C("failed to checkpoint handle, no checkpoint version provided: client_addr(%p)", handle->client_addr);
            continue;
        }

        checkpoint_version = this->async_ckpt_cxt.checkpoint_version_map[handle];

    #if POS_CONF_EVAL_CkptEnablePipeline == 1
        /*!
         *  \brief  [phrase 1]  add the state of this handle from its origin buffer
         *  \note   the adding process is sync as it might disturbed by CoW
         */
        POS_TRACE_TICK_START(ckpt, ckpt_add_done);
        POS_TRACE_TICK_START(ckpt, ckpt_add_wait);
        retval = handle->checkpoint_add(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_stream_id
        );
        POS_ASSERT(retval == POS_SUCCESS || retval == POS_WARN_ABANDONED || retval == POS_FAILED_ALREADY_EXIST);
        if(retval == POS_SUCCESS){
            POS_TRACE_TICK_APPEND(ckpt, ckpt_add_done);
            POS_TRACE_COUNTER_ADD(ckpt, ckpt_add_done_size, handle->state_size);
        } else if(retval == POS_WARN_ABANDONED){
            POS_TRACE_TICK_APPEND(ckpt, ckpt_add_wait);
            POS_TRACE_COUNTER_ADD(ckpt, ckpt_add_wait_size, handle->state_size);
        }

        /*!
         *  \brief  [phrase 2]  commit the resource state from cache
         *  \note   originally the commit process is async as it would never be disturbed by CoW, but we also need to prevent
         *          ckpt memcpy conflict with normal memcpy, so we sync the execution here to check the memcpy flag
         */
        POS_TRACE_TICK_START(ckpt, ckpt_commit);
        retval = handle->checkpoint_commit(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_commit_stream_id
        );
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN("failed to async commit the handle within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
            continue;
        }

        retval = this->sync(this->_ckpt_commit_stream_id);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN("failed to sync the commit within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
        }

        POS_TRACE_TICK_APPEND(ckpt, ckpt_commit);
        POS_TRACE_COUNTER_ADD(ckpt, ckpt_commit_size, handle->state_size);
    #else
        /*!
         *  \brief  [phrase 1]  commit the resource state from origin buffer or CoW cache
         *  \note   if the CoW is ongoing or finished, it commit from cache; otherwise it commit from origin buffer
         */
        POS_TRACE_TICK_START(ckpt, ckpt_commit);
        retval = handle->checkpoint_commit(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_stream_id
        );
        if(unlikely(retval != POS_SUCCESS && retval != POS_WARN_ABANDONED)){
            POS_WARN("failed to async commit the handle within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
            continue;
        }
        
        retval = this->sync(this->_ckpt_stream_id);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN("failed to sync the commit within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
        }

        POS_TRACE_TICK_APPEND(ckpt, ckpt_commit);
        POS_TRACE_COUNTER_ADD(ckpt, ckpt_commit_size, handle->state_size);
    #endif
    
        wqe->nb_ckpt_handles += 1;
        wqe->ckpt_size += handle->state_size;

        /*!
         *  \note   we need to avoid conflict between ckpt memcpy and normal memcpy, and we will stop once it occurs
         */
        while(this->async_ckpt_cxt.membus_lock == true){ /* block */ }
    }

    
    //  POS_TRACE_TICK_START(ckpt, ckpt_commit)
    // #if POS_CONF_EVAL_CkptEnablePipeline == 1
    //     /*!
    //      *  \note   [phrase 3]  synchronize all commits
    //      *                      this phrase is only enabled when checkpoint pipeline is enabled
    //      */
        
        
    //     // wait all commit thread to exit
    //     // for(auto &commit_thread : _commit_threads){
    //     //     if(unlikely(POS_SUCCESS != commit_thread.get())){
    //     //         POS_WARN_C("failure occured within the commit thread");
    //     //     }
    //     // }

    //     // wait all commit job to finished
    //     retval = this->sync(this->_ckpt_commit_stream_id);
    //     POS_ASSERT(retval == POS_SUCCESS);
    // #else
    //     // wait all commit job to finished
    //     retval = this->sync(this->_ckpt_stream_id);
    //     POS_ASSERT(retval == POS_SUCCESS);
    // #endif
    // POS_TRACE_TICK_APPEND_NO_COUNT(ckpt, ckpt_commit)

    POS_LOG(
        "checkpoint finished: #finished_handles(%lu), size(%lu Bytes)",
        wqe->nb_ckpt_handles, wqe->ckpt_size
    );

exit:
    this->async_ckpt_cxt.is_active = false;
}

#endif // POS_CONF_EVAL_CkptOptLevel


#if POS_CONF_EVAL_MigrOptLevel > 0
    /*!
     *  \brief  worker daemon with optimized migration support (POS)
     */
    void POSWorker::__daemon_migration_opt(){
        uint64_t i, j, k, w, api_id;
        pos_vertex_id_t latest_pc = 0;
        pos_retval_t launch_retval;
        POSAPIMeta_t api_meta;
        POSAPIContext_QE *wqe;
        pos_retval_t migration_retval;

        while(!_stop_flag){
        
            if(this->_client->status != kPOS_ClientStatus_Active){
                continue;
            }

            // check migration
            migration_retval = this->_client->migration_ctx.watch_dog(latest_pc);
            if(unlikely(migration_retval != POS_FAILED_NOT_READY)){
                switch (migration_retval)
                {
                case POS_WARN_BLOCKED:
                    // case: migration finished, worker thread blocked
                    goto loop_end;
                
                case POS_FAILED:
                    POS_WARN("migration failed!");

                default:
                    break;
                }
            }

            if(POS_SUCCESS == this->_client->dag.get_next_pending_op(&wqe)){
                wqe->worker_s_tick = POSUtilTimestamp::get_tsc();
                api_id = wqe->api_cxt->api_id;
                latest_pc = wqe->dag_vertex_id;
                api_meta = _ws->api_mgnr->api_metas[api_id];

                // check and restore broken handles
                if(unlikely(POS_SUCCESS != __restore_broken_handles(wqe, api_meta))){
                    POS_WARN_C("failed to check / restore broken handles: api_id(%lu)", api_id);
                    continue;
                }

                #if POS_CONF_RUNTIME_EnableDebugCheck
                    if(unlikely(_launch_functions.count(api_id) == 0)){
                        POS_ERROR_C_DETAIL(
                            "runtime has no worker launch function for api %lu, need to implement", api_id
                        );
                    }
                #endif

                if(unlikely(this->_client->migration_ctx.is_precopying() == true)){
                    // invalidate handles
                    for(auto &inout_handle_view : wqe->inout_handle_views){
                        this->_client->migration_ctx.invalidated_handles.insert(inout_handle_view.handle);
                    }
                    for(auto &output_handle_view : wqe->output_handle_views){
                        this->_client->migration_ctx.invalidated_handles.insert(output_handle_view.handle);
                    }
                }

                if(unlikely(this->_client->migration_ctx.is_ondemand_reloading() == true)){
                    // invalidate handles
                    for(auto &input_handle_view : wqe->input_handle_views){
                        while(input_handle_view.handle->state_status != kPOS_HandleStatus_StateReady){}
                    }
                    for(auto &output_handle_view : wqe->output_handle_views){
                        while(output_handle_view.handle->state_status != kPOS_HandleStatus_StateReady){}
                    }
                    for(auto &inout_handle_view : wqe->inout_handle_views){
                        while(inout_handle_view.handle->state_status != kPOS_HandleStatus_StateReady){}
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

        loop_end:
            ;
        } // stop_flag
    }

#endif // POS_CONF_EVAL_MigrOptLevel


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

        // step 1: restore resource allocation
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
