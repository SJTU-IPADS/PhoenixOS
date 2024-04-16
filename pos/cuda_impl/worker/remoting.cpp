#include <iostream>

#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#include <cublas_api.h>

#include "pos/include/common.h"
#include "pos/cuda_impl/worker.h"


namespace wk_functions {

/*!
 *  \related    [Cricket Adapt] rpc_dinit
 *  \brief      disconnect of RPC connection
 */
namespace remoting_deinit {
    // execution function
    POS_WK_FUNC_LAUNCH(){
        POSWorker::__done(ws, wqe);
    exit:
        return POS_SUCCESS;
    }
} // namespace remoting_deinit

} // namespace wk_functions
