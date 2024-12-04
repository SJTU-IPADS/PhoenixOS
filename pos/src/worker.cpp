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
#include "pos/include/utils/system.h"
#include "pos/include/api_context.h"
#include "pos/include/trace.h"


POSWorker::POSWorker(POSWorkspace* ws, POSClient* client) : _max_wqe_id(0) {
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
    pos_retval_t retval;
    if(unlikely(POS_SUCCESS != (
        retval = this->init_wk_functions()
    ))){
        POS_ERROR_C_DETAIL("failed to insert functions: retval(%u)", retval);
    }
    return retval;
}


void POSWorker::shutdown(){ 
    this->_stop_flag = true;
    if(this->_daemon_thread != nullptr){
        if(this->_daemon_thread->joinable()){
            this->_daemon_thread->join();
        }
        delete this->_daemon_thread;
        this->_daemon_thread = nullptr;
        POS_LOG_C("worker daemon thread shutdown");
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
        goto exit;
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

exit:
    return;
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

    while(!this->_stop_flag){
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
            api_meta = this->_ws->api_mgnr->api_metas[api_id];

            // check and restore broken handles
            if(unlikely(POS_SUCCESS != __restore_broken_handles(wqe, &api_meta))){
                POS_WARN_C("failed to check / restore broken handles: api_id(%lu)", api_id);
                continue;
            }

        #if POS_CONF_RUNTIME_EnableDebugCheck
            if(unlikely(this->_launch_functions.count(api_id) == 0)){
                POS_ERROR_C_DETAIL(
                    "runtime has no worker launch function for api %lu, need to implement", api_id
                );
            }
        #endif

            launch_retval = (*(this->_launch_functions[api_id]))(this->_ws, wqe);
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
            if(wqe->has_return == false){
                // we only return the QE back to frontend when it hasn't been returned before
                wqe->return_tick = POSUtilTscTimer::get_tsc();
                this->_client->template push_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(wqe);
                wqe->has_return = true;
            }

            POS_ASSERT(wqe->id >= this->_max_wqe_id);
            this->_max_wqe_id = wqe->id;
        }
    }
}


pos_retval_t POSWorker::__checkpoint_handle_sync(POSCommand_QE_t *cmd){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t nb_ckpt_handles = 0, ckpt_size = 0;
    uint64_t s_tick, e_tick;

    POS_CHECK_POINTER(cmd);

    auto __commit_and_persist_handles = [&](std::set<POSHandle*>& handle_set, bool with_state) -> pos_retval_t {
        pos_retval_t retval = POS_SUCCESS;
        typename std::set<POSHandle*>::iterator set_iter;
        
        for(set_iter=handle_set.begin(); set_iter!=handle_set.end(); set_iter++){
            POSHandle *handle = *set_iter;
            POS_CHECK_POINTER(handle);

            if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                        || handle->status == kPOS_HandleStatus_Create_Pending
                        || handle->status == kPOS_HandleStatus_Broken
            )){
                continue;
            }
            
            // commit the handle first
            retval = handle->checkpoint_commit_sync(
                /* version_id */ handle->latest_version,
                /* stream_id */ 0
            );
            if(unlikely(POS_SUCCESS != retval)){
                POS_WARN_C("failed to commit handle: hid(%lu), retval(%d)", handle->id, retval);
                retval = POS_FAILED;
                goto exit;
            }

            // persist the handle
            retval = handle->checkpoint_persist_sync(
                /* ckpt_dir */ cmd->ckpt_dir,
                /* with_state */ with_state,
                /* version_id */ handle->latest_version
            );
            if(unlikely(POS_SUCCESS != retval)){
                POS_WARN_C("failed to persist handle: hid(%lu), retval(%d)", handle->id, retval);
                retval = POS_FAILED;
                goto exit;
            }

            nb_ckpt_handles += 1;
            ckpt_size += handle->state_size;
        }

    exit:
        return retval;
    };

    s_tick = POSUtilTscTimer::get_tsc();
    // save statelful handles
    retval = __commit_and_persist_handles(cmd->stateful_handles, /* with_state */ true);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to commit and persist stateful handles");
        goto exit;
    }
    // save stateless handles
    retval = __commit_and_persist_handles(cmd->stateless_handles, /* with_state */ false);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to commit and persist stateful handles");
        goto exit;
    }
    e_tick = POSUtilTscTimer::get_tsc();

    // make sure the checkpoint is finished
    retval = this->sync();
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("commit and persist unfinished: failed to synchronize");
    } else {
        POS_LOG(
            "commit and persist finished: #finished_handles(%lu), size(%lu Bytes), duration(%lf ms)",
            nb_ckpt_handles, ckpt_size, this->_ws->tsc_timer.tick_to_ms(e_tick-s_tick)
        );
    }

exit:
    return retval;
}


pos_retval_t POSWorker::__process_cmd(POSCommand_QE_t *cmd){
    pos_retval_t retval = POS_SUCCESS;
    POSHandleManager<POSHandle>* hm;
    POSHandle *handle;
    uint64_t i, nb_ckpt_wqes;
    POSAPIContext_QE *wqe;
    std::vector<POSAPIContext_QE*> wqes;
    pos_u64id_t max_wqe_id = 0;
    uint64_t s_tick, e_tick;

    POS_CHECK_POINTER(cmd);

    switch (cmd->type)
    {
    /* ========== Ckpt WQ Command from parser thread ========== */
    case kPOS_Command_Parser2Worker_PreDump:
    case kPOS_Command_Parser2Worker_Dump:

        s_tick = POSUtilTscTimer::get_tsc();

        // for both pre-dump and dump, we need to first checkpoint handles
        if(unlikely(POS_SUCCESS != (retval = this->sync()))){
            POS_WARN_C("failed to synchornize the worker thread before starting checkpoint op");
            goto reply_parser;
        }
        if(unlikely(POS_SUCCESS != (retval = this->__checkpoint_handle_sync(cmd)))){
            POS_WARN_C("failed to do checkpointing of handles");
            goto reply_parser;
        }

        // pre-dump is done here
        if(cmd->type == kPOS_Command_Parser2Worker_PreDump){
            // print downtime
            e_tick = POSUtilTscTimer::get_tsc();
            POS_LOG("GPU pre-dump downtime: %lf ms", this->_ws->tsc_timer.tick_to_ms(e_tick-s_tick));

            // reply to parser thread
            goto reply_parser; 
        }

        // for dump, we need to force client to stop accepting remoting request
        POS_ASSERT(this->_client->offline_counter == 0);
        this->_client->offline_counter = 1;
        while(this->_client->offline_counter != 2 && this->_client->is_under_sync_call == false){ 
            /* wait remoting framework to confirm */ 
        }

        // for dump, we also need to save unexecuted APIs
        nb_ckpt_wqes = 0;
        while(max_wqe_id < this->_client->_api_inst_pc-1 && this->_max_wqe_id < this->_client->_api_inst_pc-1){
            // we need to make sure we drain all unexecuted APIs
            // POS_LOG("max_wqe_id: %lu, _api_inst_pc-1:%lu", max_wqe_id, this->_client->_api_inst_pc - 1);
            wqes.clear();
            // TODO: this might be buggy, consider what if there's a sync call, and simontinuously we dump the program,
            //       then the retval won't never be returned!
            this->_client->template poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(&wqes);
            for(i=0; i<wqes.size(); i++){
                POS_CHECK_POINTER(wqe = wqes[i]);
                POS_CHECK_POINTER(wqe->api_cxt);
                if(unlikely(POS_SUCCESS != (
                    retval = wqe->persist</* with_params */ true, /* type */ POSAPIContext_QE_t::ApiCxt_PersistType_Unexecuted>(cmd->ckpt_dir))
                )){
                    POS_WARN_C("failed to do checkpointing of unexecuted APIs");
                    goto reply_parser;
                }
                nb_ckpt_wqes += 1;
                max_wqe_id = (wqe->id > max_wqe_id) ? wqe->id : max_wqe_id;
            }
        }
        POS_LOG_C("finished dumping unexecuted APIs: nb_ckpt_wqes(%lu)", nb_ckpt_wqes);

        // tear down all handles inside the client
        if(unlikely(POS_SUCCESS != (retval = this->_client->tear_down_all_handles()))){
            POS_WARN_C("failed to tear down handles while dumping");
        }

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

    while(!this->_stop_flag){
        // if the client isn't ready, the queue might not exist, we can't do any queue operation
        if(this->_client->status != kPOS_ClientStatus_Active){ continue; }

        // step 1: digest cmd from parser work queue
        cmd_wqes.clear();
        this->_client->template poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_WQ>(&cmd_wqes);
        for(i=0; i<cmd_wqes.size(); i++){
            POS_CHECK_POINTER(cmd_wqe = cmd_wqes[i]);
            this->__process_cmd(cmd_wqe);
        }

        // step 2: check whether we need to run the bottom half of concurrent checkpoint
        if(unlikely(this->async_ckpt_cxt.BH_active == true) && this->_client->is_under_sync_call == false){
            tmp_retval = this->__checkpoint_BH_sync();
            continue;
        }

        // step 3: digest apicxt from parser work queue
        wqes.clear();
        this->_client->template poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(&wqes);

        for(i=0; i<wqes.size(); i++){
            POS_CHECK_POINTER(wqe = wqes[i]);

            wqe->worker_s_tick = POSUtilTscTimer::get_tsc();

            /*!
             *  \brief  if the async ckpt thread is active, we cache this wqe for potential recomputation while restoring
             */
            if(unlikely(this->async_ckpt_cxt.TH_actve == true)){
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

            if(unlikely(this->async_ckpt_cxt.TH_actve == true)){
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
                    if(this->async_ckpt_cxt.cmd->do_cow && this->async_ckpt_cxt.checkpoint_version_map.count(handle) > 0){
                        #if POS_CONF_RUNTIME_EnableTrace
                            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_cow_done_ticks_by_worker_thread);
                            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_cow_block_ticks_by_worker_thread);
                        #endif
                        tmp_retval = handle->checkpoint_add(
                            /* version_id */ this->async_ckpt_cxt.checkpoint_version_map[handle],
                            /* stream_id */ this->_cow_stream_id
                        );
                        POS_ASSERT(tmp_retval == POS_SUCCESS || tmp_retval == POS_WARN_ABANDONED || tmp_retval == POS_FAILED_ALREADY_EXIST);
                        #if POS_CONF_RUNTIME_EnableTrace
                            if(tmp_retval == POS_SUCCESS){
                                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_cow_done_ticks_by_worker_thread);
                                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_cow_done_times_by_worker_thread);
                                this->async_ckpt_cxt.metric_reducers.reduce(
                                    /* index */ checkpoint_async_cxt_t::CKPT_cow_bytes_by_worker_thread,
                                    /* value */ handle->state_size
                                );
                            } else if(tmp_retval == POS_WARN_ABANDONED){
                                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_cow_block_ticks_by_worker_thread);
                                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_cow_block_times_by_worker_thread);
                            }
                        #endif
                    }

                    // note: we also include those stateless handles here
                    if(this->async_ckpt_cxt.dirty_handles.count(handle) == 0)
                        this->async_ckpt_cxt.dirty_handle_state_size += handle->state_size;
                    this->async_ckpt_cxt.dirty_handles.insert(handle);
                }
                for(auto &out_handle_view : wqe->output_handle_views){
                    POS_CHECK_POINTER(handle = out_handle_view.handle);
                    if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                                || handle->status == kPOS_HandleStatus_Create_Pending
                                || handle->status == kPOS_HandleStatus_Broken
                    )){
                        continue;
                    }
                    if(this->async_ckpt_cxt.cmd->do_cow && this->async_ckpt_cxt.checkpoint_version_map.count(handle) > 0){
                        #if POS_CONF_RUNTIME_EnableTrace
                            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_cow_done_ticks_by_worker_thread);
                            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_cow_block_ticks_by_worker_thread);
                        #endif
                        tmp_retval = handle->checkpoint_add(
                            /* version_id */ this->async_ckpt_cxt.checkpoint_version_map[handle],
                            /* stream_id */ this->_cow_stream_id
                        );
                        POS_ASSERT(tmp_retval == POS_SUCCESS || tmp_retval == POS_WARN_ABANDONED || tmp_retval == POS_FAILED_ALREADY_EXIST);
                        #if POS_CONF_RUNTIME_EnableTrace
                            if(tmp_retval == POS_SUCCESS){
                                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_cow_done_ticks_by_worker_thread);
                                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_cow_done_times_by_worker_thread);
                                this->async_ckpt_cxt.metric_reducers.reduce(
                                    /* index */ checkpoint_async_cxt_t::CKPT_cow_bytes_by_worker_thread,
                                    /* value */ handle->state_size
                                );
                            } else if(tmp_retval == POS_WARN_ABANDONED){
                                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_cow_block_ticks_by_worker_thread);
                                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_cow_block_times_by_worker_thread);
                            }
                        #endif
                    }

                    // note: we also include those stateless handles here
                    if(this->async_ckpt_cxt.dirty_handles.count(handle) == 0)
                        this->async_ckpt_cxt.dirty_handle_state_size += handle->state_size;
                    this->async_ckpt_cxt.dirty_handles.insert(handle);
                }
            } // this->async_ckpt_cxt.TH_actve == true

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
            if(wqe->has_return == false){
                // we only return the QE back to frontend when it hasn't been returned before
                wqe->return_tick = POSUtilTscTimer::get_tsc();
                this->_client->template push_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(wqe);
                wqe->has_return = true;
            }

            if(unlikely(wqe->id < this->_max_wqe_id))
                POS_LOG("wqe->id: %lu, this->_max_wqe_id: %lu", wqe->id, this->_max_wqe_id);
            POS_ASSERT(wqe->id >= this->_max_wqe_id);
            this->_max_wqe_id = wqe->id;
        }
    }
}


void POSWorker::__checkpoint_TH_async_thread() {
    uint64_t i;
    pos_u64id_t checkpoint_version;
    pos_retval_t retval = POS_SUCCESS, dirty_retval = POS_SUCCESS;
    POSCommand_QE_t *cmd;
    POSHandle *handle;
    uint64_t s_tick = 0, e_tick = 0;
    uint64_t commit_stream_id;
    
    std::set<POSHandle*> async_commited_handles;
    typename std::set<POSHandle*>::iterator set_iter;

    // todo: we need an interface to know how many D2H engine we have,
    //      to decide whether we need this lock
    static constexpr bool TMP_enable_mem_lock = false;

    POS_CHECK_POINTER(cmd = this->async_ckpt_cxt.cmd);
    POS_ASSERT(this->_ckpt_stream_id != 0);

    #if POS_CONF_EVAL_CkptEnablePipeline == 1
        POS_ASSERT(this->_ckpt_commit_stream_id != 0);
    #endif

    for(set_iter=cmd->stateful_handles.begin(); set_iter!=cmd->stateful_handles.end(); set_iter++){
        POSHandle *handle = *set_iter;
        POS_CHECK_POINTER(handle);

        if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                    || handle->status == kPOS_HandleStatus_Create_Pending
                    || handle->status == kPOS_HandleStatus_Broken
        )){
            goto membus_lock_check;
        }

        if(unlikely(this->async_ckpt_cxt.checkpoint_version_map.count(handle) == 0)){
            POS_WARN_C("failed to checkpoint handle, no checkpoint version provided: client_addr(%p)", handle->client_addr);
            goto membus_lock_check;
        }

        checkpoint_version = this->async_ckpt_cxt.checkpoint_version_map[handle];

        // step 1: add & commit of all stateful handles
    #if POS_CONF_EVAL_CkptEnablePipeline == 1
        /*!
         *  \brief  [phrase 1]  add the state of this handle from its origin buffer
         *  \note   the adding process is sync as it might disturbed by CoW
         */
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_cow_done_ticks_by_ckpt_thread);
            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_cow_block_ticks_by_ckpt_thread);
        #endif
        retval = handle->checkpoint_add(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_stream_id
        );
        POS_ASSERT(retval == POS_SUCCESS || retval == POS_WARN_ABANDONED || retval == POS_FAILED_ALREADY_EXIST);
        #if POS_CONF_RUNTIME_EnableTrace
            if(retval == POS_SUCCESS){
                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_cow_done_ticks_by_ckpt_thread);
                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_cow_done_times_by_ckpt_thread);
                this->async_ckpt_cxt.metric_reducers.reduce(
                    /* index */ checkpoint_async_cxt_t::CKPT_cow_bytes_by_ckpt_thread,
                    /* value */ handle->state_size
                );
            } else if(retval == POS_WARN_ABANDONED){
                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_cow_block_ticks_by_ckpt_thread);
                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_cow_block_times_by_ckpt_thread);
            }
        #endif

        /*!
         *  \brief  [phrase 2]  commit the resource state from cache
         */
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_commit_ticks_by_ckpt_thread);
        #endif

        retval = handle->checkpoint_commit_async(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_commit_stream_id
        );
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN("failed to async commit the handle within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
            dirty_retval = retval;
            goto membus_lock_check;
        }
        commit_stream_id = this->_ckpt_commit_stream_id;

        if constexpr (TMP_enable_mem_lock == true){
            /*!
             *  \note   originally the commit process is async as it would never be disturbed by CoW, but we also need to prevent
             *          ckpt memcpy conflict with normal memcpy, so we sync the execution here to check the memcpy flag
             *  \todo   how many D2H engine do we have?
             */
            retval = this->sync(this->_ckpt_commit_stream_id);
            if(unlikely(retval != POS_SUCCESS)){
                POS_WARN("failed to sync the commit within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
                dirty_retval = retval;
            }
        } else {
            async_commited_handles.insert(handle);
        }

        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_reducers.reduce(
                /* index */ checkpoint_async_cxt_t::CKPT_commit_bytes_by_ckpt_thread,
                /* value */ handle->state_size
            );
            this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_commit_times_by_ckpt_thread);
            this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_commit_ticks_by_ckpt_thread);
        #endif
    #else
        /*!
         *  \brief  [phrase 1]  commit the resource state from origin buffer or CoW cache
         *  \note   if the CoW is ongoing or finished, it commit from cache; otherwise it commit from origin buffer
         */
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_commit_ticks_by_ckpt_thread);
        #endif
    
        retval = handle->checkpoint_commit_async(
            /* version_id */    checkpoint_version,
            /* stream_id */     this->_ckpt_stream_id
        );
        if(unlikely(retval != POS_SUCCESS && retval != POS_WARN_ABANDONED)){
            POS_WARN("failed to async commit the handle within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
            dirty_retval = retval;
            goto membus_lock_check;
        }
        commit_stream_id = this->_ckpt_stream_id;

        if constexpr (TMP_enable_mem_lock == true){
            // the sync would be done by persist below, we omit here
            retval = this->sync(this->_ckpt_stream_id);
            if(unlikely(retval != POS_SUCCESS)){
                POS_WARN("failed to sync the commit within ckpt thread: server_addr(%p), version_id(%lu)", handle->server_addr, checkpoint_version);
                dirty_retval = retval;
            }
        } else {
            async_commited_handles.insert(handle);
        }

        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_reducers.reduce(
                /* index */ checkpoint_async_cxt_t::CKPT_commit_bytes_by_ckpt_thread,
                /* value */ handle->state_size
            );
            this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_commit_times_by_ckpt_thread);
            this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_commit_ticks_by_ckpt_thread);
        #endif
    #endif

    membus_lock_check:
        if constexpr (TMP_enable_mem_lock == true){
            /*!
            *  \note   we need to avoid conflict between ckpt memcpy and normal memcpy, and we will stop once it occurs
            *  \todo   we only need to enable this once we only have one DMA engine on-device,
            *          we need an interface to get such information
            */
            while(this->async_ckpt_cxt.membus_lock == true && !this->_stop_flag){ /* block */ }
        }
    }

    if constexpr (TMP_enable_mem_lock == false){
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_commit_ticks_by_ckpt_thread);
        #endif
    
        #if POS_CONF_EVAL_CkptEnablePipeline == 1
            this->sync(this->_ckpt_commit_stream_id);
        #else
            this->sync(this->_ckpt_stream_id);
        #endif

        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_commit_ticks_by_ckpt_thread);
        #endif
    }

    // step 2: asynchronously persist all stateful handles
    #if POS_CONF_RUNTIME_EnableTrace
        this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::PERSIST_handle_ticks);
    #endif
    for(set_iter=async_commited_handles.begin(); set_iter!=async_commited_handles.end(); set_iter++){
        POSHandle *handle = *set_iter;
        POS_CHECK_POINTER(handle);
        
        checkpoint_version = this->async_ckpt_cxt.checkpoint_version_map[handle];

        retval = handle->checkpoint_persist_async(
            /* ckpt_dir */ cmd->ckpt_dir,
            /* with_state */ true,
            /* version_id */ checkpoint_version
        );
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN(
                "failed to async raise persist thread: hid(%lu), ckpt_dir(%s) version_id(%lu)",
                handle->id,
                cmd->ckpt_dir,
                checkpoint_version
            );
            dirty_retval = retval;
            continue;
        }
        this->async_ckpt_cxt.persist_handles.insert(handle);
    }
    #if POS_CONF_RUNTIME_EnableTrace
        this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::PERSIST_handle_ticks);
    #endif

    // if this is a pre-dump command, we return the CQE here
    if(cmd->type == kPOS_Command_Parser2Worker_PreDump){
        // mark overlap ckpt stop immediately
        this->async_ckpt_cxt.TH_actve = false;

        // make sure all async persist thread are finished
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::PERSIST_handle_ticks);
        #endif
        for(set_iter=this->async_ckpt_cxt.persist_handles.begin(); set_iter!=this->async_ckpt_cxt.persist_handles.end(); set_iter++){
            POSHandle *handle = *set_iter;
            POS_CHECK_POINTER(handle);
            if(unlikely(POS_SUCCESS != (retval = handle->sync_persist()))){
                POS_WARN_C("failed to sync async persist thread of handle: hid(%lu)", handle->id);
                dirty_retval = retval;
                continue;
            }
            #if POS_CONF_RUNTIME_EnableTrace
                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::PERSIST_handle_times);
            #endif
        }
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::PERSIST_handle_ticks);
        #endif

        cmd->retval = dirty_retval;
        retval = this->_client->template push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(cmd);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to reply ckpt cmd cq to parser: retval(%u)", retval);
        }

        // print metrics
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.print_metrics();
        #endif

        goto exit;
    }

    // raise bottom-half of dumping (e.g., dirty-copy/recomputation, dump API contexts, etc.)
    this->async_ckpt_cxt.BH_active = true;

 exit:
    ;
}


pos_retval_t POSWorker::__checkpoint_BH_sync() {
    pos_retval_t retval = POS_SUCCESS;
    POSHandle *handle;
    pos_u64id_t max_wqe_id = 0;
    uint64_t nb_ckpt_handles = 0;
    uint64_t i, nb_ckpt_wqes;
    uint64_t nb_ckpt_dirty_handles = 0, dirty_ckpt_size = 0;
    typename std::set<POSHandle*>::iterator set_iter;
    POSAPIContext_QE *wqe;
    std::vector<POSAPIContext_QE*> wqes;
    POSCommand_QE_t *cmd;
    uint64_t s_tick, e_tick;
    bool do_dirty_copy = false;

    POS_CHECK_POINTER(cmd = this->async_ckpt_cxt.cmd);

    // mark top-half as disabled here to avoid missed dirty handles
    this->async_ckpt_cxt.TH_actve = false;

    // step 0, for dump, we need to force client to stop accepting remoting request
    POS_ASSERT(this->_client->offline_counter == 0);
    if(this->_client->offline_counter == 0){
        // case: first stop attempt
        this->_client->offline_counter = 1;
        while(this->_client->offline_counter != 2){ 
            /* wait remoting framework to confirm */
            if(this->_client->is_under_sync_call == true){
                // if the RPC thread is currently encounter a sync call
                // we should finish it before we doing the dump
                retval = POS_WARN_ABANDONED;
                goto exit;
            }
        }
    } else if(this->_client->offline_counter == 1){
        // case: subsequent stop attempt, the remoting framework haven't confirmed yet
        while(this->_client->offline_counter != 2){
            /* wait remoting framework to confirm */
            POS_ASSERT(this->_client->is_under_sync_call == false);
        }
    } else if(this->_client->offline_counter == 2){
        // case: subsequent stop attempt, the remoting frameowork has replied, we're free to go for dump
    } else {
        POS_ERROR_C_DETAIL("unexpected value obtained");
    }


    // step 1: synchronize the worker thread
    #if POS_CONF_RUNTIME_EnableTrace
        this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::COMMON_sync);
    #endif
    if(unlikely(POS_SUCCESS != (retval = this->sync()))){
        POS_WARN_C("failed to synchornize the worker thread before starting checkpoint op");
        goto sync_persist;
    }
    #if POS_CONF_RUNTIME_EnableTrace
        this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::COMMON_sync);
    #endif

    // step 2: dump stateless handles
    #if POS_CONF_RUNTIME_EnableTrace
        this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::PERSIST_handle_ticks);
    #endif
    for(set_iter=cmd->stateless_handles.begin(); set_iter!=cmd->stateless_handles.end(); set_iter++){
        handle = *set_iter;
        POS_CHECK_POINTER(handle);

        if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                    || handle->status == kPOS_HandleStatus_Create_Pending
                    || handle->status == kPOS_HandleStatus_Broken
        )){
            continue;
        }

        // asynchronously persist all stateless handles
        retval = handle->checkpoint_persist_async(
            /* ckpt_dir */ cmd->ckpt_dir,
            /* with_state */ false,
            /* version_id */ 0
        );
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN(
                "failed to async raise persist thread: hid(%lu), ckpt_dir(%s) version_id(%lu)", handle->id, cmd->ckpt_dir
            );
            goto sync_persist;
        }
        this->async_ckpt_cxt.persist_handles.insert(handle);
        nb_ckpt_handles += 1;
    }
    #if POS_CONF_RUNTIME_EnableTrace
        this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::PERSIST_handle_ticks);
    #endif
    POS_LOG("#stateless handles(%lu)", nb_ckpt_handles);

    // step 3: decide either dump recomputation APIs (only if CoW is enabled) or do dirty copy
    if(cmd->do_cow == true){
        if(this->async_ckpt_cxt.dirty_handle_state_size >= GB(4)){
            // case: too many dirty copies, we dump recomputation APIs
            do_dirty_copy = false;
            POS_LOG(
                "[Dirty Behaviour] potential dirty copies too large, dumping recomputation APIs: dirty-copies(%s)",
                POSUtilSystem::format_byte_number(this->async_ckpt_cxt.dirty_handle_state_size).c_str()
            );
        } else {
            // case: not too many dirty copies, conduct dirty copy
            do_dirty_copy = true;
            POS_LOG(
                "[Dirty Behaviour] potential dirty copies is acceptable, do dirty copy: dirty-copies(%s)",
                POSUtilSystem::format_byte_number(this->async_ckpt_cxt.dirty_handle_state_size).c_str()
            );
        }
    } else {
        do_dirty_copy = true;
        POS_LOG(
            "[Dirty Behaviour] no CoW enabled, do dirty copy: dirty-copies(%s)",
            POSUtilSystem::format_byte_number(this->async_ckpt_cxt.dirty_handle_state_size).c_str()
        );
    }

    if(do_dirty_copy){ // do dirty copy
        for(set_iter=this->async_ckpt_cxt.dirty_handles.begin(); set_iter!=this->async_ckpt_cxt.dirty_handles.end(); set_iter++){
            handle = *set_iter;
            POS_CHECK_POINTER(handle);

            if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                        || handle->status == kPOS_HandleStatus_Create_Pending
                        || handle->status == kPOS_HandleStatus_Broken
            )){
                continue;
            }

            // step 1: commit the state
            #if POS_CONF_RUNTIME_EnableTrace
                this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::CKPT_dirty_commit_ticks);
            #endif
            retval = handle->checkpoint_commit_sync(
                /* version_id */ handle->latest_version,
                /* stream_id */ 0
            );
            if(unlikely(POS_SUCCESS != retval)){
                POS_WARN_C("failed to commit handle");
                retval = POS_FAILED;
                goto sync_persist;
            }
            #if POS_CONF_RUNTIME_EnableTrace
                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::CKPT_dirty_commit_ticks);
                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_dirty_commit_times);
                this->async_ckpt_cxt.metric_reducers.reduce(
                    /* index*/ checkpoint_async_cxt_t::CKPT_dirty_commit_bytes,
                    /* value */ handle->state_size
                );
            #endif

            // step 2: asynchronously persist
            #if POS_CONF_RUNTIME_EnableTrace
                this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::PERSIST_handle_ticks);
            #endif
            retval = handle->checkpoint_persist_async(
                /* ckpt_dir */ cmd->ckpt_dir,
                /* with_state */ true,
                /* version_id */ handle->latest_version
            );
            if(unlikely(retval != POS_SUCCESS)){
                POS_WARN(
                    "failed to async raise persist thread: hid(%lu), ckpt_dir(%s) version_id(%lu)", handle->id, cmd->ckpt_dir
                );
                goto sync_persist;
            }
            #if POS_CONF_RUNTIME_EnableTrace
                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::PERSIST_handle_ticks);
            #endif
            this->async_ckpt_cxt.persist_handles.insert(handle); // actually this is redundant

            nb_ckpt_dirty_handles += 1;
            dirty_ckpt_size += handle->state_size;
        }
    } else { // do recomputation
        wqes.clear();
        this->_client->template poll_q<kPOS_QueueDirection_WorkerLocal, kPOS_QueueType_ApiCxt_CkptDag_WQ>(&wqes);
        for(i=0; i<wqes.size(); i++){
            POS_CHECK_POINTER(wqe = wqes[i]);
            POS_CHECK_POINTER(wqe->api_cxt);

            #if POS_CONF_RUNTIME_EnableTrace
                this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::PERSIST_wqe_ticks);
            #endif
            if(unlikely(POS_SUCCESS != (
                retval = wqe->persist</* with_params */ true, /* type */ POSAPIContext_QE_t::ApiCxt_PersistType_Recomputation>(cmd->ckpt_dir)
            ))){
                POS_WARN_C("failed to do checkpointing of recomputation APIs");
                goto sync_persist;
            }
            #if POS_CONF_RUNTIME_EnableTrace
                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::PERSIST_wqe_ticks);
                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_nb_recomputation_apis);
            #endif
        }
        POS_LOG_C("finished dumping recomputation APIs: nb_ckpt_wqes(%lu)", nb_ckpt_wqes);
    }

    // step 5: for dump, we also need to save unexecuted APIs
    while(max_wqe_id < this->_client->_api_inst_pc-1 && this->_max_wqe_id < this->_client->_api_inst_pc-1){
        // we need to make sure we drain all unexecuted APIs
        wqes.clear();
        this->_client->template poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(&wqes);
        for(i=0; i<wqes.size(); i++){
            POS_CHECK_POINTER(wqe = wqes[i]);
            POS_CHECK_POINTER(wqe->api_cxt);
            
            #if POS_CONF_RUNTIME_EnableTrace
                this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::PERSIST_wqe_ticks);
            #endif
            if(unlikely(POS_SUCCESS != (
                retval = wqe->persist</* with_params */ true, /* type */ POSAPIContext_QE_t::ApiCxt_PersistType_Unexecuted>(cmd->ckpt_dir))
            )){
                POS_WARN_C("failed to do checkpointing of unexecuted APIs");
                goto sync_persist;
            }
            #if POS_CONF_RUNTIME_EnableTrace
                this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::PERSIST_wqe_ticks);
                this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::CKPT_nb_unexecuted_apis);
            #endif

            max_wqe_id = (wqe->id > max_wqe_id) ? wqe->id : max_wqe_id;
        }
    }
 
 sync_persist:
    // step 6: make sure all async persist thread are finished
    #if POS_CONF_RUNTIME_EnableTrace
        this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::PERSIST_handle_ticks);
    #endif
    for(set_iter=this->async_ckpt_cxt.persist_handles.begin(); set_iter!=this->async_ckpt_cxt.persist_handles.end(); set_iter++){
        POSHandle *handle = *set_iter;
        POS_CHECK_POINTER(handle);
        if(unlikely(POS_SUCCESS != (retval = handle->sync_persist()))){
            POS_WARN_C("failed to sync async persist thread of handle: hid(%lu)", handle->id);
            goto reply_parser;
        }
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_counters.add_counter(checkpoint_async_cxt_t::PERSIST_handle_times);
        #endif
    }
    #if POS_CONF_RUNTIME_EnableTrace
        this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::PERSIST_handle_ticks);
    #endif

    // step 7: tear down all handles inside the client
    if(unlikely(POS_SUCCESS != (retval = this->_client->tear_down_all_handles()))){
        POS_WARN_C("failed to tear down handles while dumping");
    }

    // mark bottom-half disabled
    this->async_ckpt_cxt.BH_active = false;

    // print metrics
    #if POS_CONF_RUNTIME_EnableTrace
        this->async_ckpt_cxt.print_metrics();
    #endif

 reply_parser:
    cmd->retval = retval;
    retval = this->_client->template push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(cmd);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to reply ckpt cmd cq to parser: retval(%u)", retval);
    }

 exit:
    return retval;
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
        /*!
         *  \note   if previous checkpoint thread hasn't finished yet, we abandon this checkpoint
         *          to avoid waiting overhead here
         */
        if(this->async_ckpt_cxt.TH_actve == true){
            POS_WARN_C("skip checkpoint due to previous one is still non-finished");
            cmd->retval = POS_FAILED_ALREADY_EXIST;
            retval = this->_client->template push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(cmd);
            if(unlikely(retval != POS_SUCCESS)){
                POS_WARN_C("failed to reply ckpt cmd cq to parser: retval(%u)", retval);
            }
            goto exit;
        }

        this->async_ckpt_cxt.cmd = cmd;
        this->async_ckpt_cxt.dirty_handles.clear();
        this->async_ckpt_cxt.dirty_handle_state_size = 0;
        this->async_ckpt_cxt.persist_handles.clear();

        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_counters.reset_counters();
            this->async_ckpt_cxt.metric_reducers.reset_reducers();
            this->async_ckpt_cxt.metric_tickers.reset_tickers();
        #endif

        // deallocate the thread handle of previous checkpoint
        if(likely(this->async_ckpt_cxt.thread != nullptr)){
            if(this->async_ckpt_cxt.thread->joinable())
                this->async_ckpt_cxt.thread->join();
            delete this->async_ckpt_cxt.thread;
        }

        // clear the ckpt dag queue
        this->_client->clear_q<kPOS_QueueDirection_WorkerLocal, kPOS_QueueType_ApiCxt_CkptDag_WQ>();

        // reset checkpoint version map
        this->async_ckpt_cxt.checkpoint_version_map.clear();
        for(handle_set_iter = cmd->stateful_handles.begin(); 
            handle_set_iter != cmd->stateful_handles.end(); 
            handle_set_iter++)
        {
            POS_CHECK_POINTER(handle = *handle_set_iter);
            handle->reset_preserve_counter();
            this->async_ckpt_cxt.checkpoint_version_map[handle] = handle->latest_version;
        }

        // drain the device
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_tickers.start(checkpoint_async_cxt_t::COMMON_sync);
        #endif
        if(unlikely(POS_SUCCESS != (retval = this->sync()))){
            POS_TRACE_TICK_APPEND(ckpt, ckpt_drain);
            POS_WARN_C("failed to synchornize the worker thread before starting checkpoint op");
            goto exit;
        }
        #if POS_CONF_RUNTIME_EnableTrace
            this->async_ckpt_cxt.metric_tickers.end(checkpoint_async_cxt_t::COMMON_sync);
        #endif

        // raise new checkpoint thread
        this->async_ckpt_cxt.thread = new std::thread(&POSWorker::__checkpoint_TH_async_thread, this);
        POS_CHECK_POINTER(this->async_ckpt_cxt.thread);
        this->async_ckpt_cxt.TH_actve = true;

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

                // restore handle
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

                // restore handle state (on-demand restore)
                // TODO: prefetching opt.
                if(broken_handle->state_size > 0 && broken_handle->state_status == kPOS_HandleStatus_StateMiss){
                    if(unlikely(POS_SUCCESS != broken_handle->reload_state(/* stream_id */ 0))){
                        POS_ERROR_C(
                            "failed to restore state of broken handle: "
                            "resource_type(%s), client_addr(%p), server_addr(%p), status(%u), state_size(%lu)"
                            ,
                            broken_handle->get_resource_name().c_str(),
                            broken_handle->client_addr,
                            broken_handle->server_addr,
                            broken_handle->status,
                            broken_handle->state_size
                        );
                    }
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
