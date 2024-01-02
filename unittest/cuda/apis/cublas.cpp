#include <iostream>

#include <cuda.h>
#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#include <cublas_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timestamp.h"

#include "unittest/cuda/apis/base.h"
#include "unittest/cuda/unittest.h"

pos_retval_t test_cublas_create(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cublasStatus_t cublas_result = CUBLAS_STATUS_SUCCESS;
    cublasHandle_t handle = nullptr;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTimestamp::get_tsc();
    cublas_result = cublasCreate_v2(&handle);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cublas_result != CUBLAS_STATUS_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

    POS_DEBUG("cublas handle: %p", handle);

exit:
    return retval;
}

pos_retval_t test_cublas_set_stream(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cublasStatus_t cublas_result = CUBLAS_STATUS_SUCCESS;
    uint64_t s_tick, e_tick;
    cublasHandle_t handle = nullptr;

    cublas_result = cublasCreate_v2(&handle);
    if(unlikely(cublas_result != CUBLAS_STATUS_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

    s_tick = POSUtilTimestamp::get_tsc();
    cublas_result = cublasSetStream(handle, 0);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cublas_result != CUBLAS_STATUS_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}

pos_retval_t test_cublas_set_mathmode(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cublasStatus_t cublas_result = CUBLAS_STATUS_SUCCESS;
    uint64_t s_tick, e_tick;
    cublasHandle_t handle = nullptr;

    cublas_result = cublasCreate_v2(&handle);
    if(unlikely(cublas_result != CUBLAS_STATUS_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

    s_tick = POSUtilTimestamp::get_tsc();
    cublas_result = cublasSetMathMode(handle, CUBLAS_DEFAULT_MATH);
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;

    if(unlikely(cublas_result != CUBLAS_STATUS_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}

pos_retval_t test_cublas_sgemm(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cublasStatus_t cublas_result;
    cudaError_t cuda_rt_result;
    cublasHandle_t handle;
    uint64_t s_tick, e_tick;

    int const M = 5;
    int const K = 6;
    int const N = 7;

    float *h_A, *h_B, *h_C, *true_h_C;
    float *d_A, *d_B, *d_C;
    float a=1.0f, b=0.0f;

    h_A = (float*)malloc(sizeof(float)*M*K);
    h_B = (float*)malloc(sizeof(float)*K*N);
    h_C = (float*)malloc(sizeof(float)*M*N);
    true_h_C = (float*)malloc(sizeof(float)*M*N);
    
    for (int i=0; i<M*K; i++) {
        h_A[i] = (float)(rand()%10+1);
    }
    
    for(int i=0;i<K*N; i++) {
        h_B[i] = (float)(rand()%10+1);
    }

    // calculate the correct result
    for (int m=0; m<M; m++) {
        for(int n=0; n<N; n++) {
            true_h_C[m*N+n] = 0.0f;
            for(int k=0; k<K; k++) {
                true_h_C[m*N+n] += h_A[m*K+k] * h_B[k*N+n];
            }
        }
    }

    // print h_A
    POS_DEBUG("h_A:");
    for (int m=0; m<M; m++) {
        for(int k=0; k<K; k++) {
            printf("%f ", h_A[m*K+k]);
        }
        printf("\n");
    }
    printf("\n");

    // print h_B
    POS_DEBUG("h_B:");
    for (int k=0; k<K; k++) {
        for(int n=0; n<N; n++) {
            printf("%f ", h_B[k*N+n]);
        }
        printf("\n");
    }
    printf("\n");

    // print true_h_C
    POS_DEBUG("true_h_C:");
    for (int m=0; m<M; m++) {
        for(int n=0; n<N; n++) {
            printf("%f ", true_h_C[m*N+n]);
        }
        printf("\n");
    }
    printf("\n");

    cuda_rt_result = cudaMalloc((void**)&d_A, sizeof(float)*M*K);
    if(unlikely(cuda_rt_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_result = cudaMalloc((void**)&d_B, sizeof(float)*K*N);
    if(unlikely(cuda_rt_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_result = cudaMalloc((void**)&d_C, sizeof(float)*M*N);
    if(unlikely(cuda_rt_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    cublas_result = cublasCreate(&handle);
    if(unlikely(cublas_result != CUBLAS_STATUS_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_result = cudaMemcpy(d_A, h_A, sizeof(float)*M*K, cudaMemcpyHostToDevice);
    if(unlikely(cuda_rt_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_result = cudaMemcpy(d_B, h_B, sizeof(float)*K*N, cudaMemcpyHostToDevice);
    if(unlikely(cuda_rt_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }
    
    cublas_result = cublasSetStream(handle, 0);
    if(unlikely(cublas_result != CUBLAS_STATUS_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

    cublas_result = cublasSetMathMode(handle, CUBLAS_DEFAULT_MATH);
    if(unlikely(cublas_result != CUBLAS_STATUS_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

    s_tick = POSUtilTimestamp::get_tsc();
    cublas_result = cublasSgemm(    
        handle,
        CUBLAS_OP_T,
        CUBLAS_OP_T,
        M,
        N,
        K,
        &a,
        d_A,
        K,
        d_B,
        N,
        &b,
        d_C,
        M
    );
    e_tick = POSUtilTimestamp::get_tsc();
    
    cxt->duration_ticks = e_tick - s_tick;
    
    if(unlikely(cublas_result != CUBLAS_STATUS_SUCCESS)){
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_result = cudaMemcpy(h_C, d_C, sizeof(float)*M*N, cudaMemcpyDeviceToHost);
    if(unlikely(cuda_rt_result != cudaSuccess)){
        retval = POS_FAILED;
        goto exit;
    }

    // print h_C
    POS_DEBUG("h_C:");
    for (int m=0; m<M; m++) {
        for(int n=0; n<N; n++) {
            printf("%f ", h_C[m+n*M]);
        }
        printf("\n");
    }
    printf("\n");

    // verify result
    for (int m=0; m<M; m++) {
        for(int n=0; n<N; n++) {
            if(h_C[m+n*M] != true_h_C[m*N+n]){
                retval = POS_FAILED;
                goto exit;
            }
        }
    }

exit:
    return retval;
}
