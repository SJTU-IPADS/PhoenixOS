#include <iostream>
#include <vector>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timer.h"

#include "unittest/cuda/apis/base.h"
#include "unittest/cuda/unittest.h"

const int kNbElement = 8;

pos_retval_t test_cuda_malloc(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t s_tick, e_tick;
    
    float *d_buf_1 = nullptr, *d_buf_2 = nullptr, *d_buf_3 = nullptr, *d_buf_4 = nullptr, *d_buf_5 = nullptr;
    
    s_tick = POSUtilTimestamp::get_tsc();
    cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(float));
    e_tick = POSUtilTimestamp::get_tsc();

    cxt->duration_ticks = e_tick - s_tick;

    cudaMalloc((void**)&d_buf_2, kNbElement*sizeof(float));
    cudaMalloc((void**)&d_buf_3, kNbElement*sizeof(float));
    cudaMalloc((void**)&d_buf_4, kNbElement*sizeof(float));
    cudaMalloc((void**)&d_buf_5, kNbElement*sizeof(float));

    if(d_buf_1 != nullptr && d_buf_2 != nullptr && d_buf_3 != nullptr && d_buf_4 != nullptr && d_buf_5 != nullptr){
        retval = POS_SUCCESS;
    } else {
        retval = POS_FAILED;
    }

    return retval;
}


pos_retval_t test_cuda_free(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;
    uint64_t s_tick, e_tick;
    float *d_buf_1 = nullptr;
    cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(float));

    s_tick = POSUtilTimestamp::get_tsc();    
    cuda_rt_retval = cudaFree(d_buf_1);
    e_tick = POSUtilTimestamp::get_tsc();

    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_rt_retval != cudaSuccess)){
        retval = POS_FAILED;
    }

    return retval;
}


pos_retval_t test_cuda_memcpy_h2d(test_cxt* cxt){
    uint64_t i;
    float *d_buf_1 = nullptr;
    std::vector<float> buf_1, buf_2;
    pos_retval_t retval = POS_SUCCESS;
    uint64_t s_tick, e_tick;

    cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(float)*2);
    for (i=0; i<kNbElement; i++){
        buf_1.push_back((float)(rand()%100) * 0.1f);
    }
    buf_2.reserve(kNbElement);

    s_tick = POSUtilTimestamp::get_tsc();
    cudaMemcpy(d_buf_1+kNbElement, buf_1.data(), kNbElement*sizeof(float), cudaMemcpyHostToDevice);
    e_tick = POSUtilTimestamp::get_tsc();

    cxt->duration_ticks = e_tick - s_tick;

    cudaMemcpy(buf_2.data(), d_buf_1+kNbElement, kNbElement*sizeof(float), cudaMemcpyDeviceToHost);

    POS_DEBUG("base(%p), offset(%lu), final(%p)", d_buf_1, kNbElement, d_buf_1+kNbElement);

    for (i=0; i<kNbElement; i++){
        if(buf_1[i] != buf_2[i]){
            retval = POS_FAILED;
            break;
        }
    }

    cudaFree(d_buf_1);

    return retval;
}


pos_retval_t test_cuda_memcpy_d2h(test_cxt* cxt){
    uint64_t i;
    float *d_buf_1 = nullptr;
    std::vector<float> buf_1, buf_2;
    pos_retval_t retval = POS_SUCCESS;
    uint64_t s_tick, e_tick;

    cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(float)*2);
    for (i=0; i<kNbElement; i++){
        buf_1.push_back((float)(rand()%100));
    }
    buf_2.reserve(kNbElement);

    cudaMemcpy(d_buf_1+kNbElement, buf_1.data(), kNbElement*sizeof(float), cudaMemcpyHostToDevice);

    s_tick = POSUtilTimestamp::get_tsc();
    cudaMemcpy(buf_2.data(), d_buf_1+kNbElement, kNbElement*sizeof(float), cudaMemcpyDeviceToHost);
    e_tick = POSUtilTimestamp::get_tsc();

    cxt->duration_ticks = e_tick - s_tick;

    POS_DEBUG("base(%p), offset(%lu), final(%p)", d_buf_1, kNbElement, d_buf_1+kNbElement);

    cudaFree(d_buf_1);

    return retval;
}


pos_retval_t test_cuda_memcpy_d2d(test_cxt* cxt){
    uint64_t i;
    float *d_buf_1 = nullptr, *d_buf_2 = nullptr;
    std::vector<float> buf_1, buf_2;
    pos_retval_t retval = POS_SUCCESS;
    uint64_t s_tick, e_tick;

    cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(float));
    cudaMalloc((void**)&d_buf_2, kNbElement*sizeof(float));
    for (i=0; i<kNbElement; i++){
        buf_1.push_back((float)(rand()%100) * 0.1f);
    }
    buf_2.reserve(kNbElement);

    cudaMemcpy(d_buf_1, buf_1.data(), kNbElement*sizeof(float), cudaMemcpyHostToDevice);

    s_tick = POSUtilTimestamp::get_tsc();
    cudaMemcpy(d_buf_2, d_buf_1, kNbElement*sizeof(float), cudaMemcpyDeviceToDevice);
    e_tick = POSUtilTimestamp::get_tsc();

    cxt->duration_ticks = e_tick - s_tick;

    cudaMemcpy(buf_2.data(), d_buf_2, kNbElement*sizeof(float), cudaMemcpyDeviceToHost);

    for (i=0; i<kNbElement; i++){
        if(buf_1[i] != buf_2[i]){
            retval = POS_FAILED;
            break;
        }
    }

    cudaFree(d_buf_1);
    cudaFree(d_buf_2);

    return retval;
}


pos_retval_t test_cuda_memcpy_h2d_async(test_cxt* cxt){
    uint64_t i;
    float *d_buf_1 = nullptr;
    std::vector<float> buf_1, buf_2;
    pos_retval_t retval = POS_SUCCESS;
    uint64_t s_tick, e_tick;

    cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(float));
    for (i=0; i<kNbElement; i++){
        buf_1.push_back((float)(rand()%100) * 0.1f);
    }
    buf_2.reserve(kNbElement);

    s_tick = POSUtilTimestamp::get_tsc();
    cudaMemcpyAsync(d_buf_1, buf_1.data(), kNbElement*sizeof(float), cudaMemcpyHostToDevice, 0);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    cudaMemcpy(buf_2.data(), d_buf_1, kNbElement*sizeof(float), cudaMemcpyDeviceToHost);

    for (i=0; i<kNbElement; i++){
        if(buf_1[i] != buf_2[i]){
            retval = POS_FAILED;
            break;
        }
    }

    cudaFree(d_buf_1);

    return retval;
}


pos_retval_t test_cuda_memcpy_d2h_async(test_cxt* cxt){
    uint64_t i;
    float *d_buf_1 = nullptr;
    std::vector<float> buf_1, buf_2;
    pos_retval_t retval = POS_SUCCESS;
    uint64_t s_tick, e_tick;

    cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(float));
    for (i=0; i<kNbElement; i++){
        buf_1.push_back((float)(rand()%100) * 0.1f);
    }
    buf_2.reserve(kNbElement);

    cudaMemcpyAsync(d_buf_1, buf_1.data(), kNbElement*sizeof(float), cudaMemcpyHostToDevice, 0);

    s_tick = POSUtilTimestamp::get_tsc();
    cudaMemcpyAsync(buf_2.data(), d_buf_1, kNbElement*sizeof(float), cudaMemcpyDeviceToHost, 0);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    for (i=0; i<kNbElement; i++){
        if(buf_1[i] != buf_2[i]){
            retval = POS_FAILED;
            break;
        }
    }

    cudaFree(d_buf_1);

    return retval;
}


pos_retval_t test_cuda_memcpy_d2d_async(test_cxt* cxt){
    uint64_t i;
    float *d_buf_1 = nullptr, *d_buf_2 = nullptr;
    std::vector<float> buf_1, buf_2;
    pos_retval_t retval = POS_SUCCESS;
    uint64_t s_tick, e_tick;

    cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(float));
    cudaMalloc((void**)&d_buf_2, kNbElement*sizeof(float));
    for (i=0; i<kNbElement; i++){
        buf_1.push_back((float)(rand()%100) * 0.1f);
    }
    buf_2.reserve(kNbElement);

    cudaMemcpyAsync(d_buf_1, buf_1.data(), kNbElement*sizeof(float), cudaMemcpyHostToDevice, 0);

    s_tick = POSUtilTimestamp::get_tsc();
    cudaMemcpyAsync(d_buf_2, d_buf_1, kNbElement*sizeof(float), cudaMemcpyDeviceToDevice, 0);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;
    
    cudaMemcpy(buf_2.data(), d_buf_2, kNbElement*sizeof(float), cudaMemcpyDeviceToHost);

    for (i=0; i<kNbElement; i++){
        if(buf_1[i] != buf_2[i]){
            retval = POS_FAILED;
            break;
        }
    }

    cudaFree(d_buf_1);
    cudaFree(d_buf_2);

    return retval;
}


pos_retval_t test_cuda_memset_async(test_cxt* cxt){
    uint64_t i;
    uint8_t *d_buf_1 = nullptr;
    std::vector<uint8_t> buf_1;
    pos_retval_t retval = POS_SUCCESS;
    uint64_t s_tick, e_tick;

    buf_1.reserve(kNbElement);

    cudaMalloc((void**)&d_buf_1, kNbElement*sizeof(uint8_t));
    for (i=0; i<kNbElement; i++){
        buf_1.push_back(0);
    }

    s_tick = POSUtilTimestamp::get_tsc();
    cudaMemsetAsync(d_buf_1, 3, kNbElement*sizeof(uint8_t), 0);
    e_tick = POSUtilTimestamp::get_tsc();

    cudaMemcpy(buf_1.data(), d_buf_1, kNbElement*sizeof(uint8_t), cudaMemcpyDeviceToHost);
    for (i=0; i<kNbElement; i++){
        if(buf_1[i] != 3){
            retval = POS_FAILED;
            break;
        }
    }

    cxt->duration_ticks = e_tick - s_tick;

    cudaFree(d_buf_1);

    return retval;
}
