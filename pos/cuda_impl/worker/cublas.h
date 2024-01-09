#include <iostream>

#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#include <cublas_api.h>

#include "pos/include/common.h"
#include "pos/cuda_impl/worker.h"


namespace wk_functions {


/*!
 *  \related    cuBlasCreate
 *  \brief      create a cuBlas context
 */
namespace cublas_create {
    // parser function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_ptr cublas_context_handle;
        cublasHandle_t actual_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);
        
        // execute the actual cublasCreate
        wqe->api_cxt->return_code = cublasCreate_v2(&actual_handle);

        // record server address
        if(likely(CUBLAS_STATUS_SUCCESS == wqe->api_cxt->return_code)){
            cublas_context_handle = pos_api_handle(wqe, kPOS_ResourceTypeId_cuBLAS_Context, 0);
            POS_CHECK_POINTER(cublas_context_handle);
            cublas_context_handle->set_server_addr((void*)actual_handle);
            cublas_context_handle->mark_status(kPOS_HandleStatus_Active);
        }

    exit:
        return retval;
    }

    // dag function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cublas_create




/*!
 *  \related    cuBlasSetStream
 *  \brief      todo
 */
namespace cublas_set_stream {
    // parser function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Stream_ptr stream_handle;
        POSHandle_cuBLAS_Context_ptr cublas_context_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        stream_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Stream, POSHandle_CUDA_Stream, 0);
        POS_CHECK_POINTER(stream_handle.get());

        cublas_context_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_cuBLAS_Context, POSHandle_cuBLAS_Context, 0);
        POS_CHECK_POINTER(cublas_context_handle.get());

        wqe->api_cxt->return_code = cublasSetStream(
            cublas_context_handle->server_addr,
            stream_handle->server_addr
        );

    exit:
        return retval;
    }

    // dag function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cublas_set_stream




/*!
 *  \related    cuBlasSetMathMode
 *  \brief      todo
 */
namespace cublas_set_math_mode {
    // parser function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_cuBLAS_Context_ptr cublas_context_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        cublas_context_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_cuBLAS_Context, POSHandle_cuBLAS_Context, 0);
        POS_CHECK_POINTER(cublas_context_handle.get());

        wqe->api_cxt->return_code = cublasSetMathMode(
            cublas_context_handle->server_addr,
            pos_api_param_value(wqe, 1, cublasMath_t)
        );

    exit:
        return retval;
    }

    // dag function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cublas_set_math_mode




/*!
 *  \related    cuBlasSGemm
 *  \brief      todo
 */
namespace cublas_sgemm {
    // parser function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_cuBLAS_Context_ptr cublas_context_handle;
        POSHandle_CUDA_Memory_ptr memory_handle_A, memory_handle_B, memory_handle_C;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        cublas_context_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_cuBLAS_Context, POSHandle_cuBLAS_Context, 0);
        POS_CHECK_POINTER(cublas_context_handle.get());

        POSHandleView_t &memory_A_hv = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 0);
        POS_CHECK_POINTER(memory_A_hv.handle.get());
        POSHandleView_t &memory_B_hv = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 1);
        POS_CHECK_POINTER(memory_B_hv.handle.get());
        POSHandleView_t &memory_C_hv = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 2);
        POS_CHECK_POINTER(memory_C_hv.handle.get());

        wqe->api_cxt->return_code = cublasSgemm(
            /* handle */ (cublasHandle_t)(cublas_context_handle->server_addr),
            /* transa */ pos_api_param_value(wqe, 1, cublasOperation_t),
            /* transb */ pos_api_param_value(wqe, 2, cublasOperation_t),
            /* m */ pos_api_param_value(wqe, 3, int),
            /* n */ pos_api_param_value(wqe, 4, int),
            /* k */ pos_api_param_value(wqe, 5, int),
            /* alpha */ (float*)pos_api_param_addr(wqe, 6),
            /* A */ (float*)(memory_A_hv.handle->server_addr),
            /* lda */ pos_api_param_value(wqe, 8, int),
            /* B */ (float*)(memory_B_hv.handle->server_addr),
            /* ldb */ pos_api_param_value(wqe, 10, int),
            /* beta */ (float*)pos_api_param_addr(wqe, 11),
            /* C */ (float*)(memory_C_hv.handle->server_addr),
            /* ldc */ pos_api_param_value(wqe, 13, int)
        );

    exit:
        return retval;
    }

    // dag function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(CUBLAS_STATUS_SUCCESS != wqe->api_cxt->return_code)){
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }
        
        return retval;
    }
} // namespace cublas_sgemm


} // namespace wk_functions
