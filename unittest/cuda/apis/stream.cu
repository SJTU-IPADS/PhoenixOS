#include <iostream>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timestamp.h"

#include "unittest/cuda/apis/base.h"
#include "unittest/cuda/unittest.h"

__global__ void kernel_1(const float* in_a, float* out_a, float* out_b, float* out_c, int len){
    int flat_thread_idx = blockIdx.x * blockDim.x + threadIdx.x;

    #pragma unroll
    for(int i=flat_thread_idx; i<len; i+=blockDim.x){
        out_a[i] = in_a[i];
        out_b[i] = in_a[i] * 2;
        out_c[i] = in_a[i] * 3;
    }
}

__global__ void kernel_2(const float* in_a, const float* in_b, float* out_a, int len){
    int flat_thread_idx = blockIdx.x * blockDim.x + threadIdx.x;

    #pragma unroll
    for(int i=flat_thread_idx; i<len; i+=blockDim.x){
        out_a[i] = in_a[i] + in_b[i];
    }
}

__global__ void kernel_3(const float* in_a, const float* in_b, float* in_out_a, int len){
    int flat_thread_idx = blockIdx.x * blockDim.x + threadIdx.x;

    #pragma unroll
    for(int i=flat_thread_idx; i<len; i+=blockDim.x){
        in_out_a[i] = in_a[i] + in_b[i] + in_out_a[i];
    }
}

__global__ void kernel_4(const float* in_a, float* out_a, int len){
    int flat_thread_idx = blockIdx.x * blockDim.x + threadIdx.x;

    #pragma unroll
    for(int i=flat_thread_idx; i<len; i+=blockDim.x){
        out_a[i] = in_a[i];
    }
}

pos_retval_t test_cuda_launch_kernel(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    const int kNbElement = 65536;
    float *d_buf_1 = nullptr, *d_buf_2 = nullptr, *d_buf_3 = nullptr, *d_buf_4 = nullptr;
    std::vector<float> buf_1, buf_2, buf_3, buf_4, buf_5;
    uint64_t i;
    uint64_t s_tick, e_tick;

    cudaMalloc(&d_buf_1, kNbElement*sizeof(float));
    cudaMalloc(&d_buf_2, kNbElement*sizeof(float));
    cudaMalloc(&d_buf_3, kNbElement*sizeof(float));
    cudaMalloc(&d_buf_4, kNbElement*sizeof(float));

    for (i=0; i<kNbElement; i++){
      buf_1.push_back((float)(rand()%100) * 0.1f);
    }
    buf_2.reserve(kNbElement);
    buf_3.reserve(kNbElement);
    buf_4.reserve(kNbElement);

    cudaMemcpy(d_buf_1, buf_1.data(), kNbElement*sizeof(float), cudaMemcpyHostToDevice);

    s_tick = POSUtilTimestamp::get_tsc();
    kernel_1<<<1,256>>>(d_buf_1, d_buf_2, d_buf_3, d_buf_4, kNbElement);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    cudaMemcpy(buf_2.data(), d_buf_2, kNbElement*sizeof(float), cudaMemcpyDeviceToHost);
    cudaMemcpy(buf_3.data(), d_buf_3, kNbElement*sizeof(float), cudaMemcpyDeviceToHost);
    cudaMemcpy(buf_4.data(), d_buf_4, kNbElement*sizeof(float), cudaMemcpyDeviceToHost);

    for(i=0; i<kNbElement; i++){
        if(buf_2[i] != buf_1[i]){ 
            retval = POS_FAILED_INCORRECT_OUTPUT;
            POS_WARN_DETAIL("result not correct: i(%lu), buf_2(%f), buf_1(%f)", i, buf_2[i], buf_1[i]);
            goto exit;
        }
        if(buf_3[i] != 2*buf_1[i]){ 
            retval = POS_FAILED_INCORRECT_OUTPUT;
            POS_WARN_DETAIL("result not correct: i(%lu), buf_3(%f), 2*buf_1(%f)", i, buf_3[i], 2*buf_1[i]);
            goto exit;
        }
        if(buf_4[i] != 3*buf_1[i]){ 
            retval = POS_FAILED_INCORRECT_OUTPUT;
            POS_WARN_DETAIL("result not correct: i(%lu), buf_4(%f), 3*buf_1(%f)", i, buf_4[i], 3*buf_1[i]);
            goto exit;
        }
    }

exit:
    cudaFree(d_buf_1);
    cudaFree(d_buf_2);
    cudaFree(d_buf_3);
    cudaFree(d_buf_4);

    return retval;
}

pos_retval_t test_cuda_stream_synchronize(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaError cuda_result;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTimestamp::get_tsc();
    cuda_result = cudaStreamSynchronize(0);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_result != cudaSuccess)){
        POS_WARN_DETAIL("failed: %d", cuda_result);
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}

pos_retval_t test_cuda_stream_is_capturing(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaError cuda_result;
    cudaStreamCaptureStatus status;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTimestamp::get_tsc();
    cuda_result = cudaStreamIsCapturing(0, &status);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_result != cudaSuccess)){
        POS_WARN_DETAIL("failed: %d", cuda_result);
        retval = POS_FAILED;
        goto exit;
    }

    // how to mock capture on a stream?

exit:
    return retval;
}

pos_retval_t test_cuda_event_create_with_flags(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaEvent_t event;
    cudaError cuda_result;
    uint64_t s_tick, e_tick;
    
    s_tick = POSUtilTimestamp::get_tsc();
    cuda_result = cudaEventCreateWithFlags(&event, cudaEventDefault);
    e_tick = POSUtilTimestamp::get_tsc();

    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_result != cudaSuccess)){
        POS_WARN_DETAIL("failed: %d", cuda_result);
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}

pos_retval_t test_cuda_event_record(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaEvent_t event;
    cudaError cuda_result;
    uint64_t s_tick, e_tick;

    cuda_result = cudaEventCreateWithFlags(&event, cudaEventDefault);
    if(unlikely(cuda_result != cudaSuccess)){
        POS_WARN_DETAIL("failed: %d", cuda_result);
        retval = POS_FAILED;
        goto exit;
    }

    s_tick = POSUtilTimestamp::get_tsc();
    cuda_result = cudaEventRecord(event, 0);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cuda_result != cudaSuccess)){
        POS_WARN_DETAIL("failed: %d", cuda_result);
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}


pos_retval_t test_cuda_event_destory(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cudaEvent_t event;
    cudaError cuda_result;
    uint64_t s_tick, e_tick;

    cuda_result = cudaEventCreateWithFlags(&event, cudaEventDefault);
    if(unlikely(cuda_result != cudaSuccess)){
        POS_WARN_DETAIL("failed: %d", cuda_result);
        retval = POS_FAILED;
        goto exit;
    }

    s_tick = POSUtilTimestamp::get_tsc();
    cuda_result = cudaEventDestroy(event);
    e_tick = POSUtilTimestamp::get_tsc();

    if(unlikely(cuda_result != cudaSuccess)){
        POS_WARN_DETAIL("failed: %d", cuda_result);
        retval = POS_FAILED;
        goto exit;
    }

    cxt->duration_ticks = e_tick - s_tick;

exit:
    return retval;
}
