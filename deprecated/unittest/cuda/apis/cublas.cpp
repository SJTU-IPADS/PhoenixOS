#include <iostream>

#include <cuda.h>
#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#include <cublas_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timer.h"

#include "unittest/cuda/apis/base.h"
#include "unittest/cuda/unittest.h"

pos_retval_t test_cublas_create(test_cxt* cxt){
    pos_retval_t retval = POS_SUCCESS;
    cublasStatus_t cublas_result = CUBLAS_STATUS_SUCCESS;
    cublasHandle_t handle = nullptr;
    uint64_t s_tick, e_tick;

    s_tick = POSUtilTscTimer::get_tsc();
    cublas_result = cublasCreate_v2(&handle);
    e_tick = POSUtilTscTimer::get_tsc();
    
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

    s_tick = POSUtilTscTimer::get_tsc();
    cublas_result = cublasSetStream(handle, 0);
    e_tick = POSUtilTscTimer::get_tsc();
    
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

    s_tick = POSUtilTscTimer::get_tsc();
    cublas_result = cublasSetMathMode(handle, CUBLAS_DEFAULT_MATH);
    e_tick = POSUtilTscTimer::get_tsc();
    
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

    s_tick = POSUtilTscTimer::get_tsc();
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
    e_tick = POSUtilTscTimer::get_tsc();
    
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


// TODO: this test has issue
pos_retval_t test_cublas_sgemm_stride_batched(test_cxt* cxt){
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
    long long int stride = 1;

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
    auto __calculate_correct_result = [](
        bool transB, bool transA,
        int CCols, int CRows, int AColsBRows,
        const float* alpha,
        float* B, int ColsB, int SizeB,
        float* A, int ColsA, int SizeA,
        const float* beta,
        float* C, int ColsC, int SizeC,
        int batchCount
    ){
        for (int b = batchCount; b--;){
            for (int m = CCols; m--;)
                for (int n = CRows; n--;)
                {
                    float sum = 0;
                    for (int k = AColsBRows; k--;)
                        sum += (transA ? A[k * ColsA + n] : A[n * ColsA + k]) * (transB ? B[m * ColsB + k] : B[k * ColsB + m]);
                    C[n * ColsC + m] = *alpha * sum + *beta * C[n * ColsC + m];
                }
            A += SizeA;
            B += SizeB;
            C += SizeC;
        }
    };  
    __calculate_correct_result(false, false, N, M, K, &a, h_B, N, N * K, h_A, M, M * K, &b, true_h_C, N, N * M, 1);

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

    s_tick = POSUtilTscTimer::get_tsc();
    cublas_result = cublasSgemmStridedBatched(
        handle, 
        CUBLAS_OP_N, CUBLAS_OP_N, 
        N, M, K, 
        &a,
        d_B, N, N * M, 
        d_A, K, K * M,
        &b, 
        d_C, N, N * M,
        1
    );

    e_tick = POSUtilTscTimer::get_tsc();
    
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
