/*
 * Copyright 2025 The PhoenixOS Authors. All rights reserved.
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

#include <iostream>

#include "pos/include/common.h"
#include "pos/include/client.h"
#include "pos/cuda_impl/worker.h"

#include <cuda.h>
#include <cuda_runtime_api.h>

namespace wk_functions {

namespace cuda_launch_kernel {
    #define POS_CUDA_LAUNCH_KERNEL_MAX_NB_PARAMS    512

    static void* cuda_args[POS_CUDA_LAUNCH_KERNEL_MAX_NB_PARAMS] = {0};

    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Function *function_handle;
        POSHandle_CUDA_Stream *stream_handle;
        POSHandle *memory_handle;
        uint64_t i, j, nb_involved_memory;
        void *args, *args_values, *arg_addr;
        uint64_t *addr_list;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        function_handle = (POSHandle_CUDA_Function*)(pos_api_input_handle(wqe, 0));
        POS_CHECK_POINTER(function_handle);

        stream_handle = (POSHandle_CUDA_Stream*)(pos_api_input_handle(wqe, 1));
        POS_CHECK_POINTER(stream_handle);

        // the 3rd parameter of the API call contains parameter to launch the kernel
        args = pos_api_param_addr(wqe, 3);
        POS_CHECK_POINTER(args);

        for(i=0; i<function_handle->nb_params; i++){
            cuda_args[i] = args + function_handle->param_offsets[i];
            POS_CHECK_POINTER(cuda_args[i]);
        }
        typedef struct __dim3 { uint32_t x; uint32_t y; uint32_t z; } __dim3_t;

        wqe->api_cxt->return_code = cuLaunchKernel(
            /* f */ (CUfunction)(function_handle->server_addr),
            /* gridDimX */ ((__dim3_t*)pos_api_param_addr(wqe, 1))->x,
            /* gridDimY */ ((__dim3_t*)pos_api_param_addr(wqe, 1))->y,
            /* gridDimZ */ ((__dim3_t*)pos_api_param_addr(wqe, 1))->z,
            /* blockDimX */ ((__dim3_t*)pos_api_param_addr(wqe, 2))->x,
            /* blockDimY */ ((__dim3_t*)pos_api_param_addr(wqe, 2))->y,
            /* blockDimZ */ ((__dim3_t*)pos_api_param_addr(wqe, 2))->z,
            /* sharedMemBytes */ pos_api_param_value(wqe, 4, size_t),
            /* hStream */ (CUstream)(stream_handle->server_addr),
            /* kernelParams */ cuda_args,
            /* extra */ nullptr
        );
        
        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
            POSWorker::__restore(ws, wqe);
        } else {
            POSWorker::__done(ws, wqe);
        }

    exit:
        return retval;
    }


} // namespace cuda_launch_kernel

} // namespace wk_functions 
