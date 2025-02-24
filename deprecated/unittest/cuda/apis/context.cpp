#include <iostream>
#include <vector>


#include <string.h>
#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timer.h"

#include "unittest/cuda/apis/base.h"
#include "unittest/cuda/unittest.h"


pos_retval_t test_cu_ctx_get_current(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    CUresult cuda_result;
    CUcontext ctx;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTscTimer::get_tsc();
    cuda_result = cuCtxGetCurrent(&ctx);
    e_tick = POSUtilTscTimer::get_tsc();

    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_result != CUDA_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}


pos_retval_t test_cuda_get_last_error(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaError cuda_result;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTscTimer::get_tsc();
    cuda_result = cudaGetLastError();
    e_tick = POSUtilTscTimer::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}


pos_retval_t test_cuda_peek_at_last_error(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaError cuda_result;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTscTimer::get_tsc();
    cuda_result = cudaPeekAtLastError();
    e_tick = POSUtilTscTimer::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}


pos_retval_t test_cuda_get_error_string(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    const char* str = nullptr;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTscTimer::get_tsc();
    str = cudaGetErrorString(cudaErrorDeviceUninitialized);
    e_tick = POSUtilTscTimer::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(str == nullptr)){
        retval = POS_FAILED;
        goto exit;
    }
    
    if(unlikely(strcmp("invalid device context", str))){
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}
