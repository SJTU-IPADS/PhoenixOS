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
#include "pos/include/trace.h"


// forward declaration
class POSClient;
class POSHandle;
class POSWorkspace;
typedef struct POSAPIMeta POSAPIMeta_t;
typedef struct POSAPIContext_QE POSAPIContext_QE_t;
typedef struct POSCommand_QE POSCommand_QE_t;


/*!
 *  \brief prototype for worker launch function for each API call
 */
using pos_worker_launch_function_t = pos_retval_t(*)(POSWorkspace*, POSAPIContext_QE_t*);


/*!
 *  \brief  macro for the definition of the worker launch functions
 */
#define POS_WK_FUNC_LAUNCH()                                        \
    pos_retval_t launch(POSWorkspace* ws, POSAPIContext_QE_t* wqe)

namespace wk_functions {
    #define POS_WK_DECLARE_FUNCTIONS(api_name) namespace api_name { POS_WK_FUNC_LAUNCH(); }
};  // namespace ps_functions


#if POS_CONF_EVAL_CkptOptLevel == 2

/*!
 *  \brief  context of the overlapped checkpoint thread
 */
typedef struct checkpoint_async_cxt {
    // flag: checkpoint thread to notify the worker thread that the previous checkpoint has done
    bool is_active;

    // checkpoint cmd
    POSCommand_QE_t *cmd;

    // (latest) version of each handle to be checkpointed
    std::map<POSHandle*, pos_u64id_t> checkpoint_version_map;

    //  this flag should be raise by memcpy API worker function, to avoid slow down by
    //  overlapped checkpoint process
    bool membus_lock;

    // thread handle
    std::thread *thread;

    checkpoint_async_cxt() : is_active(false) {}
} checkpoint_async_cxt_t;

#endif // POS_CONF_EVAL_CkptOptLevel == 2


/*!
 *  \brief  POS Worker
 */
class POSWorker {
 public:
    /*!
     *  \brief  constructor
     *  \param  ws      pointer to the global workspace that create this worker
     *  \param  client  pointer to the client which this worker thread belongs to
     */
    POSWorker(POSWorkspace* ws, POSClient* client);

    /*!
     *  \brief  deconstructor
     */
    ~POSWorker();

    /*!
     *  \brief  function insertion
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     *  \return POS_SUCCESS for successfully insertion
     */
    pos_retval_t init();

    /*!
     *  \brief  raise the shutdown signal to stop the daemon
     */
    void shutdown();

    /*!
     *  \brief  generic restore procedure
     *  \note   should be invoked within the landing function, while exeucting failed
     *  \param  ws  the global workspace
     *  \param  wqe the work QE where failure was detected
     */
    static void __restore(POSWorkspace* ws, POSAPIContext_QE_t* wqe);

    /*!
     *  \brief  generic complete procedure
     *  \note   should be invoked within the landing function, while exeucting success
     *  \param  ws  the global workspace
     *  \param  wqe the work QE where failure was detected
     */
    static void __done(POSWorkspace* ws, POSAPIContext_QE_t* wqe);

    #if POS_CONF_EVAL_CkptOptLevel == 2
        // overlapped checkpoint context
        checkpoint_async_cxt_t async_ckpt_cxt;
    #endif
    
    #if POS_CONF_EVAL_MigrOptLevel > 0
        // stream for precopy
        uint64_t _migration_precopy_stream_id;
    #endif

    /*!
     *  \brief  make the specified stream synchronized
     *  \param  stream_id   index of the stream to be synced, default to be 0
     */
    virtual pos_retval_t sync(uint64_t stream_id=0){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

 protected:
    // stop flag to indicate the daemon thread to stop
    bool _stop_flag;

    // the daemon thread of the runtime
    std::thread *_daemon_thread;

    // global workspace
    POSWorkspace *_ws;

    // corresonding client
    POSClient *_client;

    // worker function map
    std::map<uint64_t, pos_worker_launch_function_t> _launch_functions;

    #if POS_CONF_EVAL_CkptOptLevel == 2
        // stream for overlapped memcpy while computing happens
        uint64_t _ckpt_stream_id;

        // stream for doing CoW
        uint64_t _cow_stream_id;
    #endif

    #if POS_CONF_EVAL_CkptOptLevel == 2 && POS_CONF_EVAL_CkptEnablePipeline == 1
        // stream for commiting checkpoint from device
        uint64_t _ckpt_commit_stream_id;
    #endif

    
    /*!
     *  \brief  insertion of worker functions
     *  \return POS_SUCCESS for succefully insertion
     */
    virtual pos_retval_t init_wk_functions(){ 
        return POS_FAILED_NOT_IMPLEMENTED; 
    }

    /*!
     *  \brief      initialization of the worker daemon thread
     *  \example    for CUDA, one need to call API e.g. cudaSetDevice first to setup the context for a thread
     */
    virtual pos_retval_t daemon_init(){
        return POS_SUCCESS; 
    }

    /*!
     *  \brief  profiling metrics for worker
     */
    #if POS_CONF_RUNTIME_EnableTrace
        /* ========== tick traces ========== */
        // tick metrics for checkpoint process
        POS_TRACE_TICK_LIST_DEF(
            /* list_name */ ckpt,
            /* tick_list */
                ckpt_drain,
                ckpt_cow_done,       
                ckpt_cow_wait,
                ckpt_add_done,
                ckpt_add_wait,
                ckpt_commit
        );
        POS_TRACE_TICK_LIST_DECLARE(ckpt);

        /* ========== counter traces ========== */
        // counter metrics for checkpoint process
        POS_TRACE_COUNTER_LIST_DEF(
            /* list_name */ ckpt,
            /* counters */
                ckpt_drain,
                ckpt_cow_done_size,       
                ckpt_cow_wait_size,
                ckpt_add_done_size,
                ckpt_add_wait_size,
                ckpt_commit_size
        );
        POS_TRACE_COUNTER_LIST_DECLARE(ckpt);
    #endif

 private:
    /*!
     *  \brief  processing daemon of the worker
     */
    void __daemon();

    #if POS_CONF_EVAL_CkptOptLevel == 0 || POS_CONF_EVAL_CkptOptLevel == 1
        /*!
         *  \brief  worker daemon with / without SYNC checkpoint support 
         *          (checkpoint optimization level 0 and 1)
         */
        void __daemon_ckpt_sync();

        /*!
         *  \brief  checkpoint procedure, should be implemented by each platform
         *  \note   this function will be invoked by level-1 ckpt
         *  \param  cmd     the checkpoint command
         *  \return POS_SUCCESS for successfully checkpointing
         */
        pos_retval_t __checkpoint_handle_sync(POSCommand_QE_t *cmd);
    #elif POS_CONF_EVAL_CkptOptLevel == 2
        /*!
         *  \brief  worker daemon with ASYNC checkpoint support (checkpoint optimization level 2)
         */
        void __daemon_ckpt_async();

        /*!
         *  \brief  overlapped checkpoint procedure, should be implemented by each platform
         *  \note   this thread will be raised by level-2 ckpt
         *  \note   aware of the macro POS_CONF_EVAL_CkptEnablePipeline
         *  \note   aware of the macro POS_CKPT_ENABLE_ORCHESTRATION
         */
        void __checkpoint_async_thread();
    #endif

    #if POS_CONF_EVAL_MigrOptLevel > 0
        /*!
         *  \brief  worker daemon with optimized migration support (POS)
         */
        void __daemon_migration_opt();
    #endif

    /*!
     *  \brief  process command received in the worker daemon
     *  \param  cmd the received command
     *  \return POS_SUCCESS for successfully process the command
     */
    pos_retval_t __process_cmd(POSCommand_QE_t *cmd);

    /*!
     *  \brief  check and restore all broken handles, if there's any exists
     *  \param  wqe         the op to be checked and restored
     *  \param  api_meta    metadata of the called API
     *  \return POS_SUCCESS for successfully checking and restoring
     */
    pos_retval_t __restore_broken_handles(POSAPIContext_QE_t* wqe, POSAPIMeta_t *api_meta); 

    // maximum index of processed wqe index
    uint64_t _max_wqe_id;
};
