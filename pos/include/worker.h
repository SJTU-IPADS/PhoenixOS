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
#include "pos/include/utils/lockfree_queue.h"
#include "pos/include/api_context.h"
#include "pos/include/client.h"
#include "pos/include/trace/base.h"
#include "pos/include/trace/tick.h"

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
        : _ws(ws), _stop_flag(false)
    {
        int rc;

        // start daemon thread
        _daemon_thread = new std::thread(&POSWorker::__daemon, this);
        POS_CHECK_POINTER(_daemon_thread);
        
        #if POS_CKPT_OPT_LEVEL == 2
            _ckpt_stream_id = 0;
        #endif
        #if POS_CKPT_OPT_LEVEL == 2 && POS_CKPT_ENABLE_PIPELINE == 1
            _ckpt_commit_stream_id = 0;
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

    #if POS_CKPT_OPT_LEVEL == 2
        // stream for overlapped memcpy while computing happens
        uint64_t _ckpt_stream_id;  
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

    /*!
     *  \brief  make the specified stream synchronized
     *  \param  stream_id   index of the stream to be synced, default to be 0
     */
    virtual pos_retval_t sync(uint64_t stream_id=0){
        return POS_FAILED_NOT_IMPLEMENTED;
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

        #if POS_CKPT_OPT_LEVEL <= 1
            this->__daemon_ckpt_sync();
        #elif POS_CKPT_OPT_LEVEL == 2
            this->__daemon_ckpt_async();
        #else
            static_assert(false, "error checkpoint level");
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
         *  \param  cxt     the context of this checkpointing
         */
        void __checkpoint_async_thread(checkpoint_async_cxt_t* cxt);
    #endif

    /*!
     *  \brief  check and restore all broken handles, if there's any exists
     *  \param  wqe         the op to be checked and restored
     *  \param  api_meta    metadata of the called API
     *  \return POS_SUCCESS for successfully checking and restoring
     */
    pos_retval_t __restore_broken_handles(POSAPIContext_QE* wqe, POSAPIMeta_t& api_meta); 
};
