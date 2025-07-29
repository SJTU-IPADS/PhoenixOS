#include "test_cuda/test_cuda_common.h"


TEST_F(PhOSCudaTest, cublasSgemm_v2) {
    cudaError cuda_retval;
    cublasStatus_t cublas_retval;
    cublasHandle_t cublas_context;
    cublasHandle_t *cublas_context_ptr = &cublas_context;
    cublasOperation_t cublas_op;
    cudaStream_t stream = 0;
    int i = 0, m = 0, n = 0;
    int M = 5;
    int K = 6;
    int N = 7;
    float *h_A = nullptr, *h_B = nullptr, *h_C = nullptr, *true_h_C = nullptr;
    float *d_A = nullptr, *d_B = nullptr, *d_C = nullptr;
    float **d_A_ptr = &d_A, **d_B_ptr = &d_B, **d_C_ptr = &d_C;
    volatile float a = 1.0f, b = 0.0f;
    volatile float *a_ptr = &a, *b_ptr = &b;
    uint64_t byte_size_A = 0, byte_size_B = 0, byte_size_C = 0;
    cudaMemcpyKind kind_h2d = cudaMemcpyHostToDevice, kind_d2h = cudaMemcpyDeviceToHost;

    byte_size_A = sizeof(float)*M*K;
    byte_size_B = sizeof(float)*K*N;
    byte_size_C = sizeof(float)*M*N;

    h_A = (float*)malloc(byte_size_A);
    h_B = (float*)malloc(byte_size_B);
    h_C = (float*)malloc(byte_size_C);
    true_h_C = (float*)malloc(byte_size_C);

    // generate input
    for(i=0; i<M*K; i++) { h_A[i] = (float)(rand()%10+1); }
    for(i=0; i<K*N; i++) { h_B[i] = (float)(rand()%10+1); }

    // calculate the correct result
    for (int m=0; m<M; m++) {
        for(int n=0; n<N; n++) {
            true_h_C[m*N+n] = 0.0f;
            for(int k=0; k<K; k++) {
                true_h_C[m*N+n] += h_A[m*K+k] * h_B[k*N+n];
            }
        }
    }

    // allocate memory for computation
    cuda_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaMalloc, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &d_A_ptr, .size = sizeof(void**) },
            { .value = &byte_size_A, .size = sizeof(size_t) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_retval);

    cuda_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaMalloc, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &d_B_ptr, .size = sizeof(void**) },
            { .value = &byte_size_B, .size = sizeof(size_t) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_retval);

    cuda_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaMalloc, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &d_C_ptr, .size = sizeof(void**) },
            { .value = &byte_size_C, .size = sizeof(size_t) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_retval);

    // copy data to memory
    cuda_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaMemcpyH2D, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &(d_A), .size = sizeof(float*) },
            { .value = &(h_A), .size = sizeof(const void*) },
            { .value = &(byte_size_A), .size = sizeof(size_t) },
            { .value = &kind_h2d, .size = sizeof(cudaMemcpyKind) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_retval);

    cuda_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaMemcpyH2D, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &(d_B), .size = sizeof(float*) },
            { .value = &(h_B), .size = sizeof(const void*) },
            { .value = &(byte_size_B), .size = sizeof(size_t) },
            { .value = &kind_h2d, .size = sizeof(cudaMemcpyKind) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_retval);

    // create cuBLAS context
    cublas_retval = (cublasStatus_t)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cublasCreate_v2, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ { 
            {.value = &cublas_context_ptr, .size = sizeof(cublasHandle_t *) }
        }
    );
    EXPECT_EQ(CUBLAS_STATUS_SUCCESS, cublas_retval);

    // set cuBLAS stream
    cublas_retval = (cublasStatus_t)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cublasSetStream, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ { 
            {.value = &cublas_context, .size = sizeof(cublasHandle_t) },
            {.value = &stream, .size = sizeof(cudaStream_t) }
        }
    );
    EXPECT_EQ(CUBLAS_STATUS_SUCCESS, cublas_retval);

    // calculation
    cublas_op = CUBLAS_OP_T;
    cublas_retval = (cublasStatus_t)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cublasSgemm_v2, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ { 
            { .value = &cublas_context, .size = sizeof(cublasHandle_t) },
            { .value = &cublas_op, .size = sizeof(cublasOperation_t) },
            { .value = &cublas_op, .size = sizeof(cublasOperation_t) },
            { .value = &M, .size = sizeof(int) },
            { .value = &N, .size = sizeof(int) },
            { .value = &K, .size = sizeof(int) },
            { .value = &a_ptr, .size = sizeof(float*) },
            { .value = &d_A, .size = sizeof(float*) },
            { .value = &K, .size = sizeof(int) },
            { .value = &d_B, .size = sizeof(float*) },
            { .value = &N, .size = sizeof(int) },
            { .value = &b_ptr, .size = sizeof(float*) },
            { .value = &d_C, .size = sizeof(float*) },
            { .value = &M, .size = sizeof(int) }
        }
    );
    EXPECT_EQ(CUBLAS_STATUS_SUCCESS, cublas_retval);

    // stack pointers now point to random data
    a = 100;
    b = 100;

    // sync stream
    cuda_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaStreamSynchronize, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &stream, .size = sizeof(cudaStream_t) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_retval);

    // copy back result
    cuda_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaMemcpyD2H, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &(h_C), .size = sizeof(void*) },
            { .value = &(d_C), .size = sizeof(float*) },
            { .value = &(byte_size_C), .size = sizeof(size_t) },
            { .value = &kind_d2h, .size = sizeof(cudaMemcpyKind) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_retval);

    // verify result
    for (m=0; m<M; m++) {
        for(n=0; n<N; n++) {
            EXPECT_EQ(h_C[m+n*M], true_h_C[m*N+n]);
        }
    }
}
