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
#include "pos/include/workspace.h"
#include "pos/include/handle.h"
#include "pos/include/client.h"
#include "pos/include/worker.h"
#include "pos/include/utils/lockfree_queue.h"
#include "pos/include/api_context.h"
#include "pos/include/trace.h"


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


POSWorker::~POSWorker(){ 
    this->shutdown(); 
}


pos_retval_t POSWorker::init(){
    if(unlikely(POS_SUCCESS != this->init_wk_functions())){
        POS_ERROR_C_DETAIL("failed to insert functions");
    }
}


void POSWorker::shutdown(){ 
    this->_stop_flag = true;
    if(this->_daemon_thread != nullptr){
        this->_daemon_thread->join();
        delete this->_daemon_thread;
        this->_daemon_thread = nullptr;
        POS_LOG_C("Worker daemon thread shutdown");
    }
}


void POSWorker::__restore(POSWorkspace* ws, POSAPIContext_QE* wqe){
    POS_ERROR_DETAIL(
        "execute failed, restore mechanism to be implemented: api_id(%lu), retcode(%d), pc(%lu)",
        wqe->api_cxt->api_id, wqe->api_cxt->return_code, wqe->id
    ); 
}


void POSWorker::__done(POSWorkspace* ws, POSAPIContext_QE* wqe){
    POSClient *client;
    uint64_t i;

    POS_CHECK_POINTER(wqe);
    POS_CHECK_POINTER(client = (POSClient*)(wqe->client));

    // set the latest version of all output handles
    for(i=0; i<wqe->output_handle_views.size(); i++){
        POSHandleView_t &hv = wqe->output_handle_views[i];
        hv.handle->latest_version = wqe->id;
    }

    // set the latest version of all inout handles
    for(i=0; i<wqe->inout_handle_views.size(); i++){
        POSHandleView_t &hv = wqe->inout_handle_views[i];
        hv.handle->latest_version = wqe->id;
    }
}


void POSWorker::__daemon(){
    if(unlikely(POS_SUCCESS != this->daemon_init())){
        POS_WARN_C("failed to init daemon, worker daemon exit");
        return;
    }

    #if POS_CONF_EVAL_MigrOptLevel == 0
        // case: continuous checkpoint
        #if POS_CONF_EVAL_CkptOptLevel <= 1
            this->__daemon_ckpt_sync();
        #elif POS_CONF_EVAL_CkptOptLevel == 2
            this->__daemon_ckpt_async();
        #endif
    #else
        this->__daemon_migration_opt();
    #endif
}


#if POS_CONF_EVAL_CkptOptLevel == 0 || POS_CONF_EVAL_CkptOptLevel == 1


void POSWorker::__daemon_ckpt_sync(){
    uint64_t i, api_id;
    pos_retval_t launch_retval;
    POSAPIMeta_t api_meta;
    POSAPIContext_QE *wqe;
    std::vector<POSAPIContext_QE*> wqes;
    POSCommand_QE_t *cmd_wqe;
    std::vector<POSCommand_QE_t*> cmd_wqes;

    while(!_stop_flag){
        // if the client isn't ready, the queue might not exist, we can't do any queue operation
        if(this->_client->status != kPOS_ClientStatus_Active){ continue; }

        // step 1: digest cmd from parser work queue
        cmd_wqes.clear();
        this->_client->template poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_WQ>(&cmd_wqes);
        for(i=0; i<cmd_wqes.size(); i++){
            POS_CHECK_POINTER(cmd_wqe = cmd_wqes[i]);
            this->__process_cmd(cmd_wqe);
        }

        // step 2: digest apicxt from parser work queue
        wqes.clear();
        this->_client->template poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(&wqes);

        for(i=0; i<wqes.size(); i++){
            POS_CHECK_POINTER(wqe = wqes[i]);
            POS_CHECK_POINTER(wqe->api_cxt);
            
            wqe->worker_s_tick = POSUtilTscTimer::get_tsc();
            
            api_id = wqe->api_cxt->api_id;
            api_meta = _ws->api_mgnr->api_metas[api_id];

            // check and restore broken handles
            if(unlikely(POS_SUCCESS != __restore_broken_handles(wqe, &api_meta))){
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
            wqe->worker_e_tick = POSUtilTscTimer::get_tsc();

            // cast return code
            wqe->api_cxt->return_code = _ws->api_mgnr->cast_pos_retval(
                /* pos_retval */ launch_retval, 
                /* library_id */ api_meta.library_id
            );

            // check whether the execution is success
            if(unlikely(launch_retval != POS_SUCCESS)){
                wqe->status = kPOS_API_Execute_Status_Worker_Failed;
            }

            // check whether we need to return to frontend
            if(wqe->status == kPOS_API_Execute_Status_Init){
                // we only return the QE back to frontend when it hasn't been returned before
                wqe->return_tick = POSUtilTscTimer::get_tsc();
                this->_client->template push_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(wqe);
            }
        }
    }
}


pos_retval_t POSWorker::__checkpoint_handle_sync(POSCommand_QE_t *cmd){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t nb_ckpt_handles = 0, ckpt_size = 0;
    typename std::set<POSHandle*>::iterator set_iter;

    POS_CHECK_POINTER(cmd);

    // for both pre-dump and dump, we need to save pre-dump handles
    for(set_iter=cmd->predump_handles.begin(); set_iter!=cmd->predump_handles.end(); set_iter++){
        POSHandle *handle = *set_iter;
        POS_CHECK_POINTER(handle);

        if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                    || handle->status == kPOS_HandleStatus_Create_Pending
                    || handle->status == kPOS_HandleStatus_Broken
        )){
            continue;
        }

        retval = handle->checkpoint_commit_sync(
            /* version_id */ handle->latest_version,
            /* ckpt_dir */ cmd->ckpt_dir,
            /* stream_id */ 0
        );
        if(unlikely(POS_SUCCESS != retval)){
            POS_WARN_C("failed to checkpoint handle");
            retval = POS_FAILED;
            goto exit;
        }

        nb_ckpt_handles += 1;
        ckpt_size += handle->state_size;
    }

    // for dump, we also need to save dump handles
    if(cmd->type == kPOS_Command_Parser2Worker_Dump){
        for(set_iter=cmd->dump_handles.begin(); set_iter!=cmd->dump_handles.end(); set_iter++){
            POSHandle *handle = *set_iter;
            POS_CHECK_POINTER(handle);

            if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                        || handle->status == kPOS_HandleStatus_Create_Pending
                        || handle->status == kPOS_HandleStatus_Broken
            )){
                continue;
            }

            retval = handle->checkpoint_commit_sync(
                /* version_id */ handle->latest_version,
                /* ckpt_dir */ cmd->ckpt_dir,
                /* stream_id */ 0
            );
            if(unlikely(POS_SUCCESS != retval)){
                POS_WARN_C("failed to checkpoint handle");
                retval = POS_FAILED;
                goto exit;
            }

            nb_ckpt_handles += 1;
            ckpt_size += handle->state_size;
        }
    }

    // make sure the checkpoint is finished
    retval = this->sync();
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("checkpoint unfinished: failed to synchronize");
    } else {
        // TODO: record to trace
        POS_LOG(
            "checkpoint finished: #finished_handles(%lu), size(%lu Bytes)",
            nb_ckpt_handles, ckpt_size
        );
    }

exit:
    return retval;
}


pos_retval_t POSWorker::__process_cmd(POSCommand_QE_t *cmd){
    pos_retval_t retval = POS_SUCCESS;
    POSHandleManager<POSHandle>* hm;
    POSHandle *handle;
    uint64_t i;
    POSAPIContext_QE *wqe;
    std::vector<POSAPIContext_QE*> wqes;

    POS_CHECK_POINTER(cmd);

    switch (cmd->type)
    {
    /* ========== Ckpt WQ Command from parser thread ========== */
    case kPOS_Command_Parser2Worker_PreDump:
    case kPOS_Command_Parser2Worker_Dump:
        // for both pre-dump and dump, we need to first checkpoint handles
        if(unlikely(POS_SUCCESS != (retval = this->sync()))){
            POS_WARN_C("failed to synchornize the worker thread before starting checkpoint op");
            goto reply_parser;
        }
        if(unlikely(POS_SUCCESS != (retval = this->__checkpoint_handle_sync(cmd)))){
            POS_WARN_C("failed to do checkpointing");
            goto reply_parser;
        }

        if(cmd->type == kPOS_Command_Parser2Worker_PreDump){ goto reply_parser; }

        // for dump, we also need to save unexecuted APIs
        for(i=0; i<wqes.size(); i++){
            POS_CHECK_POINTER(wqe = wqes[i]);
            POS_CHECK_POINTER(wqe->api_cxt);
        }

        // for dump, we need to stop client execution
        this->_client->status = kPOS_ClientStatus_Hang;

    reply_parser:
        // reply to parser
        cmd->retval = retval;
        retval = this->_client->template push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(cmd);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to reply ckpt cmd cq to parser: retval(%u)", retval);
        }
        break;

    default:
        POS_ERROR_C_DETAIL("unknown command type %u, this is a bug", cmd->type);
    }

exit:
    return retval;
}


#elif POS_CONF_EVAL_CkptOptLevel == 2


void POSWorker::__daemon_ckpt_async(){
    uint64_t i, api_id;
    pos_retval_t launch_retval, tmp_retval;
    POSAPIMeta_t api_meta;
    POSAPIContext_QE *wqe;
    std::vector<POSAPIContext_QE*> wqes;
    POSCommand_QE_t *cmd_wqe;
    std::vector<POSCommand_QE_t*> cmd_wqes;
    POSHandle *handle;

    while(!_stop_flag){
        // if the client isn't ready, the queue might not exist, we can't do any queue operation
        if(this->_client->status != kPOS_ClientStatus_Active){ continue; }

        // step 1: digest cmd from parser work queue
        cmd_wqes.clear();
        this->_client->poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_WQ>(&cmd_wqes);
        for(i=0; i<cmd_wqes.size(); i++){
            POS_CHECK_POINTER(cmd_wqe = cmd_wqes[i]);
            this->__process_cmd(cmd_wqe);
        }

        // step 2: digest apicxt from parser work queue
        wqes.clear();
        this->_client->template poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(&wqes);

        for(i=0; i<wqes.size(); i++){
            POS_CHECK_POINTER(wqe = wqes[i]);

            wqe->worker_s_tick = POSUtilTscTimer::get_tsc();
            
            /*!
             *  \brief  if the async ckpt thread is active, we cache this wqe for potential recomputation while restoring
             */
            if(unlikely(this->async_ckpt_cxt.is_active == true)){
                this->_client->template push_q<kPOS_QueueDirection_WorkerLocal, kPOS_QueueType_ApiCxt_CkptDag_WQ>(wqe);
            }

            POS_CHECK_POINTER(wqe->api_cxt);
            api_id = wqe->api_cxt->api_id;
            api_meta = this->_ws->api_mgnr->api_metas[api_id];

            // check and restore broken handles
            if(unlikely(POS_SUCCESS != __restore_broken_handles(wqe, &api_meta))){
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
                            /* stream_id */ this->_cow_stream_id
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
                            /* stream_id */ this->_cow_stream_id
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
            wqe->worker_e_tick = POSUtilTscTimer::get_tsc();

            // cast return code
            wqe->api_cxt->return_code = _ws->api_mgnr->cast_pos_retval(
                /* pos_retval */ launch_retval, 
                /* library_id */ api_meta.library_id
            );

            // check whether the execution is success
            if(unlikely(launch_retval != POS_SUCCESS)){
                wqe->status = kPOS_API_Execute_Status_Worker_Failed;
            }

            // check whether we need to return to frontend
            if(wqe->status == kPOS_API_Execute_Status_Init){
                // we only return the QE back to frontend when it hasn't been returned before
                wqe->return_tick = POSUtilTscTimer::get_tsc();
                this->_client->template push_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(wqe);
            }
        }
    }
}


void POSWorker::__checkpoint_async_thread() {
    uint64_t i;
    pos_u64id_t checkpoint_version;
    pos_retval_t retval = POS_SUCCESS, dirty_retval = POS_SUCCESS;
    POSCommand_QE_t *cmd;
    POSHandle *handle;
    uint64_t s_tick = 0, e_tick = 0;

#if POS_CONF_EVAL_CkptEnablePipeline == 1
    std::vector<std::shared_future<pos_retval_t>> _commit_threads;
    std::shared_future<pos_retval_t> _new_commit_thread;
#endif

    typename std::map<pos_resource_typeid_t, std::set<POSHandle*>>::iterator map_iter;
    typename std::set<POSHandle*>::iterator set_iter;

    POS_CHECK_POINTER(cmd = this->async_ckpt_cxt.cmd);
    POS_ASSERT(this->_ckpt_stream_id != 0);

#if POS_CONF_EVAL_CkptEnablePipeline == 1
    POS_ASSERT(this->_ckpt_commit_stream_id != 0);
#endif

    for(set_iter=cmd->checkpoint_handles.begin(); set_iter!=cmd->checkpoint_handles.end(); set_iter++){
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
        retval = handle->checkpoint_commit_async(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_commit_stream_id
        );
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN("failed to async commit the handle within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
            dirty_retval = retval;
            continue;
        }

        retval = this->sync(this->_ckpt_commit_stream_id);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN("failed to sync the commit within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
            dirty_retval = retval;
        }

        POS_TRACE_TICK_APPEND(ckpt, ckpt_commit);
        POS_TRACE_COUNTER_ADD(ckpt, ckpt_commit_size, handle->state_size);
    #else
        /*!
         *  \brief  [phrase 1]  commit the resource state from origin buffer or CoW cache
         *  \note   if the CoW is ongoing or finished, it commit from cache; otherwise it commit from origin buffer
         */
        POS_TRACE_TICK_START(ckpt, ckpt_commit);
        retval = handle->checkpoint_commit_async(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_stream_id
        );
        if(unlikely(retval != POS_SUCCESS && retval != POS_WARN_ABANDONED)){
            POS_WARN("failed to async commit the handle within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
            dirty_retval = retval;
            continue;
        }
        
        retval = this->sync(this->_ckpt_stream_id);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN("failed to sync the commit within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
            dirty_retval = retval;
        }

        POS_TRACE_TICK_APPEND(ckpt, ckpt_commit);
        POS_TRACE_COUNTER_ADD(ckpt, ckpt_commit_size, handle->state_size);
    #endif

        /*!
         *  \note   we need to avoid conflict between ckpt memcpy and normal memcpy, and we will stop once it occurs
         */
        while(this->async_ckpt_cxt.membus_lock == true){ /* block */ }
    }

    // mark overlap ckpt stop immediately
    this->async_ckpt_cxt.is_active = false;

    // collect the statistic of of this checkpoint round
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

 pre_dump_done:
    // if this is a pre-dump command, we return the CQE here
    if(cmd->type == kPOS_Command_Parser2Worker_PreDump){
        cmd->retval = dirty_retval;
        retval = this->_client->template push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(cmd);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to reply ckpt cmd cq to parser: retval(%u)", retval);
        }
        goto exit;
    }

 dump_done:
    // TODO: should we do the dirty copy here??
    POS_ASSERT(cmd->type == kPOS_Command_Parser2Worker_Dump);
    cmd->retval = dirty_retval;
    retval = this->_client->template push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(cmd);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to reply ckpt cmd cq to parser: retval(%u)", retval);
    }

 exit:
    ;
}


pos_retval_t POSWorker::__process_cmd(POSCommand_QE_t *cmd){
    pos_retval_t retval = POS_SUCCESS;
    POSHandleManager<POSHandle>* hm;
    POSHandle *handle;
    uint64_t i;
    typename std::set<POSHandle*>::iterator handle_set_iter;

    POS_CHECK_POINTER(cmd);

    switch (cmd->type)
    {
    /* ========== Ckpt WQ Command from parser thread ========== */
    case kPOS_Command_Parser2Worker_PreDump:
    case kPOS_Command_Parser2Worker_Dump:
        // if nothing to be checkpointed, we just omit
        if(unlikely(cmd->checkpoint_handles.size() == 0)){
            cmd->retval = POS_SUCCESS;
            retval = this->_client->template push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(cmd);
            if(unlikely(retval != POS_SUCCESS)){
                POS_WARN_C("failed to reply ckpt cmd cq to parser: retval(%u)", retval);
            }
            goto exit;
        }

        /*!
         *  \note   if previous checkpoint thread hasn't finished yet, we abandon this checkpoint
         *          to avoid waiting overhead here
         */
        if(this->async_ckpt_cxt.is_active == true){
            POS_WARN_C("skip checkpoint due to previous one is still non-finished");
            cmd->retval = POS_FAILED_ALREADY_EXIST;
            retval = this->_client->template push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(cmd);
            if(unlikely(retval != POS_SUCCESS)){
                POS_WARN_C("failed to reply ckpt cmd cq to parser: retval(%u)", retval);
            }
            goto exit;
        }

        // drain the device
        POS_TRACE_TICK_START(ckpt, ckpt_drain);
        if(unlikely(
            POS_SUCCESS != (retval = this->sync())
        )){
            POS_TRACE_TICK_APPEND(ckpt, ckpt_drain);
            POS_WARN_C("failed to synchornize the worker thread before starting checkpoint op");
            goto exit;
        }
        POS_TRACE_TICK_APPEND(ckpt, ckpt_drain);

        this->async_ckpt_cxt.cmd = cmd;

        // deallocate the thread handle of previous checkpoint
        if(likely(this->async_ckpt_cxt.thread != nullptr)){
            this->async_ckpt_cxt.thread->join();
            delete this->async_ckpt_cxt.thread;
        }

        // clear the ckpt dag queue
        this->_client->clear_q<kPOS_QueueDirection_WorkerLocal, kPOS_QueueType_ApiCxt_CkptDag_WQ>();

        // reset checkpoint version map
        this->async_ckpt_cxt.checkpoint_version_map.clear();
        for(handle_set_iter = cmd->checkpoint_handles.begin(); 
            handle_set_iter != cmd->checkpoint_handles.end(); 
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
        
        break;

    default:
        POS_ERROR_C_DETAIL("unknown command type %u, this is a bug", cmd->type);
    }

exit:
    return retval;
}


#endif // POS_CONF_EVAL_CkptOptLevel


pos_retval_t POSWorker::__restore_broken_handles(POSAPIContext_QE* wqe, POSAPIMeta_t* api_meta){
    pos_retval_t retval = POS_SUCCESS;
    
    POS_CHECK_POINTER(wqe);
    POS_CHECK_POINTER(api_meta);

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
                if(unlikely(api_meta->api_type == kPOS_API_Type_Create_Resource && layer_id_keeper == 0)){
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
