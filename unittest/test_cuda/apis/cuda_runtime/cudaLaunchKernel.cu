#include"test_cuda/test_cuda_common.h"

__global__ void vectorAddKernel(const float* A, const float* B, float* C, int N) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < N) {
        C[i] = A[i] + B[i];
    }
}

TEST_F(PhOSCudaTest, cudaLaunchKernel) {
    const int N = 256;
    const size_t size = N * sizeof(float);

    float *A, *B, *C;
    cudaMalloc(&A, size);
    cudaMalloc(&B, size);
    cudaMalloc(&C, size);

    std::vector<float> h_A(N, 1.0f);
    std::vector<float> h_B(N, 2.0f);
    std::vector<float> h_C(N, 0.0f);

    cudaMemcpy(A, h_A.data(), size, cudaMemcpyHostToDevice);
    cudaMemcpy(B, h_B.data(), size, cudaMemcpyHostToDevice);

    void *args[] = { &A, &B, &C, (void*)&N };
    dim3 gridDim((N + 255) / 256);
    dim3 blockDim(256);

    cudaError cuda_retval = (cudaError)this->_ws->pos_process(
        /* api_id */ PosApiIndex_cudaLaunchKernel,
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = (void*)&vectorAddKernel, .size = sizeof(void*) },
            { .value = &gridDim, .size = sizeof(dim3) },
            { .value = &blockDim, .size = sizeof(dim3) },
            { .value = &args, .size = sizeof(void**) }, 
            { .value = nullptr, .size = 0 }, // shared memory
            { .value = nullptr, .size = 0 } // stream
        }
    );

    EXPECT_EQ(cudaSuccess, cuda_retval);

    cudaMemcpy(h_C.data(), C, size, cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; ++i) {
        EXPECT_FLOAT_EQ(h_C[i], 3.0f);
    }

    cudaFree(A);
    cudaFree(B);
    cudaFree(C);
}
