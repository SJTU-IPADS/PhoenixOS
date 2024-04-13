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

namespace ps_functions {
#define POS_PS_DECLARE_FUNCTIONS(api_name) namespace api_name { POS_RT_FUNC_PARSER(); }
};  // namespace ps_functions

/*!
 *  \brief  POS Parser
 */
class POSParser {
 public:
    POSParser(POSWorkspace* ws) : _ws(ws), _stop_flag(false) {   
        int rc;

        this->checkpoint_interval_tick = ((double)POS_CKPT_INTERVAL / 1000.f) * (double)(POS_TSC_FREQ);

        // start daemon thread
        _daemon_thread = new std::thread(&POSParser::__daemon, this);
        POS_CHECK_POINTER(_daemon_thread);

        POS_LOG_C("parser started");
    };

    /*!
     *  \brief  deconstructor
     */
    ~POSParser(){ shutdown(); }
    
    /*!
     *  \brief  function insertion
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     *  \return POS_SUCCESS for successfully insertion
     */
    pos_retval_t init(){
        if(unlikely(POS_SUCCESS != init_ps_functions())){
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

    /*!
     *  \brief  insertion of parse and dag functions
     *  \return POS_SUCCESS for succefully insertion
     */
    virtual pos_retval_t init_ps_functions(){ return POS_FAILED_NOT_IMPLEMENTED; }

    /*!
     *  \brief      initialization of the runtime daemon thread
     *  \example    for CUDA, one need to call API e.g. cudaSetDevice first to setup the context for a thread
     */
    virtual pos_retval_t daemon_init(){ return POS_SUCCESS; }

 private:
    /*!
     *  \brief  processing daemon of the parser
     */
    void __daemon();

    /*!
     *  \brief  insert checkpoint op to the DAG based on certain conditions
     *  \note   aware of the macro POS_CKPT_ENABLE_INCREMENTAL
     *  \param  wqe the exact WQ element before inserting checkpoint op
     *  \return POS_SUCCESS for successfully checkpoint insertion
     */
    pos_retval_t __checkpoint_insertion(POSAPIContext_QE* wqe);

    /*!
     *  \brief  naive implementation of checkpoint insertion procedure
     *  \note   this implementation naively insert a checkpoint op to the dag, 
     *          without any optimization hint
     *  \param  wqe the exact WQ element before inserting checkpoint op
     *  \return POS_SUCCESS for successfully checkpoint insertion
     */
    pos_retval_t __checkpoint_insertion_naive(POSAPIContext_QE* wqe);

    /*!
     *  \brief  level-1/2 optimization of checkpoint insertion procedure
     *  \note   this implementation give hints of those memory handles that
     *          been modified (INOUT/OUT) since last checkpoint
     *  \param  wqe the exact WQ element before inserting checkpoint op
     *  \return POS_SUCCESS for successfully checkpoint insertion
     */
    pos_retval_t __checkpoint_insertion_incremental(POSAPIContext_QE* wqe);
};
