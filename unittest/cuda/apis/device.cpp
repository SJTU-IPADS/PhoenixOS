#include <iostream>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timestamp.h"

#include "unittest/cuda/apis/base.h"
#include "unittest/cuda/unittest.h"

pos_retval_t test_cuda_set_device(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaError cuda_result;
    const int kNbElement = 65536;
    float *d_buf_1 = nullptr, *d_buf_2 = nullptr;
    std::vector<float> buf_1, buf_2;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTimestamp::get_tsc();
    cuda_result = cudaSetDevice(0);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    cuda_result = cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(float));
    if(unlikely(cuda_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    // cuda_result = cudaSetDevice(1);
    // if(unlikely(cuda_result != cudaSuccess)){
    //     retval = POS_FAILED;
    //     goto exit;
    // }

    // cuda_result = cudaMalloc((void**)&d_buf_2, kNbElement*sizeof(float));
    // if(unlikely(cuda_result != cudaSuccess)){
    //     retval = POS_FAILED;
    //     goto exit;
    // }

    cuda_result = cudaSetDevice(0);
    
exit:
    return retval;
}


pos_retval_t test_cuda_get_device_count(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaError cuda_result;
    int device_count = 0;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTimestamp::get_tsc();
    cuda_result = cudaGetDeviceCount(&device_count);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_result != cudaSuccess)){
        POS_WARN_DETAIL("failed");
        retval = POS_FAILED;
        goto exit;
    }

    if(device_count == 0){
        POS_WARN_DETAIL("failed");
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}

pos_retval_t test_cuda_get_device_properties(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    struct cudaDeviceProp prop;
    cudaError cuda_result;
    int device_count = 0, i;
    uint64_t s_tick, e_tick;
    
    cuda_result = cudaGetDeviceCount(&device_count);
    if(unlikely(cuda_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    cxt->duration_ticks = 0;

    for(i=0; i<device_count; i++){
        s_tick = POSUtilTimestamp::get_tsc();
        cuda_result =  cudaGetDeviceProperties(&prop, i);
        e_tick = POSUtilTimestamp::get_tsc();
    
        cxt->duration_ticks = ((double)(e_tick-s_tick) + (double)(cxt->duration_ticks)) / (double)(i+1);

        if(unlikely(cuda_result != cudaSuccess)){
            retval = POS_FAILED;
            goto exit;
        }
    }

exit:
    return retval;
}

pos_retval_t test_cuda_device_get_attribute(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaDeviceAttr attr = cudaDevAttrMaxThreadsPerBlock;
    cudaError cuda_result;
    int result;
    int device_count = 0, i;
    uint64_t s_tick, e_tick;
    
    cuda_result = cudaGetDeviceCount(&device_count);
    if(unlikely(cuda_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    cxt->duration_ticks = 0;

    for(i=0; i<device_count; i++){
        s_tick = POSUtilTimestamp::get_tsc();
        cuda_result =  cudaDeviceGetAttribute(&result, attr, i);
        e_tick = POSUtilTimestamp::get_tsc();
    
        cxt->duration_ticks = ((double)(e_tick-s_tick) + (double)(cxt->duration_ticks)) / (double)(i+1);

        if(unlikely(cuda_result != cudaSuccess)){
            retval = POS_FAILED;
            goto exit;
        }
    }

exit:
    return retval;
}

pos_retval_t test_cuda_get_device(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaError cuda_result;
    int device_count = 0, i, used_device_id;
    uint64_t s_tick, e_tick;

    cuda_result = cudaGetDeviceCount(&device_count);
    if(unlikely(cuda_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    cxt->duration_ticks = 0;

    for(i=0; i<device_count; i++){
        cuda_result = cudaSetDevice(i);
        if(unlikely(cuda_result != cudaSuccess)){
            POS_WARN_DETAIL("failed");
            retval = POS_FAILED;
            goto exit;
        }

        s_tick = POSUtilTimestamp::get_tsc();
        cuda_result = cudaGetDevice(&used_device_id);
        e_tick = POSUtilTimestamp::get_tsc();
        
        if(unlikely(cuda_result != cudaSuccess)){
            POS_WARN_DETAIL("failed");
            retval = POS_FAILED;
            goto exit;
        }

        cxt->duration_ticks = ((double)(e_tick-s_tick) + (double)(cxt->duration_ticks)) / (double)(i+1);

        if(used_device_id != i){
            POS_WARN_DETAIL("failed: used_device_id(%d), i(%d)", used_device_id, i);
            retval = POS_FAILED;
            goto exit;
        }
    }

    cuda_result = cudaSetDevice(0);
    if(unlikely(cuda_result != cudaSuccess)){
        POS_WARN_DETAIL("failed");
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}
