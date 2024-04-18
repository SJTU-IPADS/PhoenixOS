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
#include "pos/include/handle.h"
#include "pos/include/trace/base.h"
#include "pos/include/trace/tick.h"

// forward declaration
class POSClient;
class POSWorkspace;

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


#if POS_CKPT_OPT_LEVEL == 2

/*!
 *  \brief  context of the overlapped checkpoint thread
 */
typedef struct checkpoint_async_cxt {
    // flag: checkpoint thread to notify the worker thread that the previous checkpoint has done
    bool is_active;
    
    // checkpoint op context
    POSAPIContext_QE *wqe;

    // (latest) version of each handle to be checkpointed
    std::map<POSHandle*, pos_vertex_id_t> checkpoint_version_map;

    //  this flag should be raise by memcpy API worker function, to avoid slow down by
    //  overlapped checkpoint process
    bool membus_lock;

    // thread handle
    std::thread *thread;

    checkpoint_async_cxt() : is_active(false) {}
} checkpoint_async_cxt_t;

#endif // POS_CKPT_OPT_LEVEL == 2

// forward declaration
class POSClient;

/*!
 *  \brief  POS Worker
 */
class POSWorker {
 public:
    POSWorker(POSWorkspace* ws, POSClient* client)
        : _ws(ws), _client(client), _stop_flag(false)
    {
        int rc;

        // start daemon thread
        _daemon_thread = new std::thread(&POSWorker::__daemon, this);
        POS_CHECK_POINTER(_daemon_thread);
        
        #if POS_CKPT_OPT_LEVEL == 2
            _ckpt_stream_id = 0;
            _cow_stream_id = 0;
        #endif

        #if POS_CKPT_OPT_LEVEL == 2 && POS_CKPT_ENABLE_PIPELINE == 1
            _ckpt_commit_stream_id = 0;
        #endif

        #if POS_MIGRATION_OPT_LEVEL > 0
            _migration_precopy_stream_id = 0;
        #endif

        // initialize trace tick list
        POS_TRACE(true, POS_TRACE_TICK_LIST_RESET(worker));

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
    static void __restore(POSWorkspace* ws, POSAPIContext_QE* wqe);

    /*!
     *  \brief  generic complete procedure
     *  \note   should be invoked within the landing function, while exeucting success
     *  \param  ws  the global workspace
     *  \param  wqe the work QE where failure was detected
     */
    static void __done(POSWorkspace* ws, POSAPIContext_QE* wqe);

    #if POS_CKPT_OPT_LEVEL == 2
        // overlapped checkpoint context
        checkpoint_async_cxt_t async_ckpt_cxt;
    #endif
    
    #if POS_MIGRATION_OPT_LEVEL > 0
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

    #if POS_CKPT_OPT_LEVEL == 2
        // stream for overlapped memcpy while computing happens
        uint64_t _ckpt_stream_id;

        // stream for doing CoW
        uint64_t _cow_stream_id;
    #endif

    #if POS_CKPT_OPT_LEVEL == 2 && POS_CKPT_ENABLE_PIPELINE == 1
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

 private:
    /*!
     *  \brief  processing daemon of the worker
     */
    void __daemon(){
        if(unlikely(POS_SUCCESS != this->daemon_init())){
            POS_WARN_C("failed to init daemon, worker daemon exit");
            return;
        }

        #if POS_MIGRATION_OPT_LEVEL == 0
            // case: continuous checkpoint
            #if POS_CKPT_OPT_LEVEL <= 1
                this->__daemon_ckpt_sync();
            #elif POS_CKPT_OPT_LEVEL == 2
                this->__daemon_ckpt_async();
            #endif
        #else
            this->__daemon_migration_opt();
        #endif
    }

    #if POS_CKPT_OPT_LEVEL == 0 || POS_CKPT_OPT_LEVEL == 1
        /*!
         *  \brief  worker daemon with / without SYNC checkpoint support 
         *          (checkpoint optimization level 0 and 1)
         */
        void __daemon_ckpt_sync();

        /*!
         *  \brief  checkpoint procedure, should be implemented by each platform
         *  \note   this function will be invoked by level-1 ckpt
         *  \param  wqe     the checkpoint op
         *  \return POS_SUCCESS for successfully checkpointing
         */
        pos_retval_t __checkpoint_sync(POSAPIContext_QE* wqe);
    #elif POS_CKPT_OPT_LEVEL == 2
        /*!
         *  \brief  worker daemon with ASYNC checkpoint support (checkpoint optimization level 2)
         */
        void __daemon_ckpt_async();

        /*!
         *  \brief  overlapped checkpoint procedure, should be implemented by each platform
         *  \note   this thread will be raised by level-2 ckpt
         *  \note   aware of the macro POS_CKPT_ENABLE_PIPELINE
         *  \note   aware of the macro POS_CKPT_ENABLE_ORCHESTRATION
         */
        void __checkpoint_async_thread();
    #endif

    #if POS_MIGRATION_OPT_LEVEL > 0
        /*!
         *  \brief  worker daemon with optimized migration support (POS)
         */
        void __daemon_migration_opt();
    #endif

    /*!
     *  \brief  check and restore all broken handles, if there's any exists
     *  \param  wqe         the op to be checked and restored
     *  \param  api_meta    metadata of the called API
     *  \return POS_SUCCESS for successfully checking and restoring
     */
    pos_retval_t __restore_broken_handles(POSAPIContext_QE* wqe, POSAPIMeta_t& api_meta); 
};
