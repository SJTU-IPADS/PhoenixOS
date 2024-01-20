#include <iostream>
#include <vector>
#include <stdint.h>
#include <cuda_runtime.h>

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


int main(){

    const int kNbElement = 65536;

    float *d_buf_1 = nullptr, *d_buf_2 = nullptr, *d_buf_3 = nullptr, *d_buf_4 = nullptr, *d_buf_5 = nullptr;
    std::vector<float> buf_1, buf_2, buf_3, buf_4, buf_5;

    cudaMalloc(&d_buf_1, kNbElement*sizeof(float));
    cudaMalloc(&d_buf_2, kNbElement*sizeof(float));
    cudaMalloc(&d_buf_3, kNbElement*sizeof(float));
    cudaMalloc(&d_buf_4, kNbElement*sizeof(float));

    printf(
        "d_buf_1: %p, d_buf_2: %p, d_buf_3: %p, d_buf_4: %p\n",
        d_buf_1, d_buf_2, d_buf_3, d_buf_4
    );

    for (int i=0; i<kNbElement; i++){
      buf_3.push_back((float)(rand()%100) * 0.1f);
    }

    // step 1
    cudaMemcpy(d_buf_3, buf_3.data(), kNbElement*sizeof(float), cudaMemcpyHostToDevice);

    // step 2
    kernel_1<<<1,256>>>(d_buf_3, d_buf_1, d_buf_2, d_buf_4, kNbElement);

    // step 3
    kernel_2<<<1,256>>>(d_buf_2, d_buf_4, d_buf_3, kNbElement);

    cudaDeviceSynchronize();

    cudaMalloc(&d_buf_5, kNbElement*sizeof(float));

    // step 4
    cudaMemcpy(d_buf_5, buf_3.data(), kNbElement*sizeof(float), cudaMemcpyHostToDevice);

    // step 5
    kernel_3<<<1,256>>>(d_buf_1, d_buf_5, d_buf_3, kNbElement);

    cudaDeviceSynchronize();

    // step 6
    kernel_4<<<1,256>>>(d_buf_3, d_buf_5, kNbElement);

    cudaFree(d_buf_1);
    cudaFree(d_buf_2);
    cudaFree(d_buf_3);
    cudaFree(d_buf_4);
    cudaFree(d_buf_5);

    return 0;
}