#include <iostream>

#include <assert.h>

#include <cuda.h>
#include <cuda_runtime_api.h>

static inline void
checkRtError(cudaError_t res, const char *tok, const char *file, unsigned line)
{
    if (res != cudaSuccess) {
        std::cerr << file << ':' << line << ' ' << tok
                  << "failed (" << (unsigned)res << "): " << cudaGetErrorString(res) << std::endl;
        abort();
    }
}
#define CHECK_RT(x) checkRtError(x, #x, __FILE__, __LINE__);

#define MB(x)   ((size_t) (x) << 20)

// mock kernel execution duration
#define CLOCK_RATE 2250000  // 4060
__device__ void __sleep_us(float t) {    
    clock_t t0 = clock64();
    clock_t t1 = t0;
    while ((t1 - t0)/(double(CLOCK_RATE)/(1000.0f)) < t)
        t1 = clock64();
}


__global__ void kernel_1(const float* in_a, float* out_a, float* out_b, float* out_c, int len){ __sleep_us(50.0f); }
__global__ void kernel_2(const float* in_a, const float* in_b, const float* in_c, float* out_a, int len){ __sleep_us(200.0f); }


int main(){
    uint64_t i;
    float *mem_1, *mem_2, *mem_3, *mem_4, *mem_5, *mem_6;
    cudaDeviceProp prop;

    CHECK_RT(cudaGetDeviceProperties(&prop, 0));
    printf("device clock rate: %d\n", prop.clockRate);
    assert(prop.clockRate == CLOCK_RATE);

    CHECK_RT(cudaMalloc(&mem_1, MB(128)));
    CHECK_RT(cudaMalloc(&mem_2, MB(128)));
    CHECK_RT(cudaMalloc(&mem_3, MB(128)));
    CHECK_RT(cudaMalloc(&mem_4, MB(128)));
    CHECK_RT(cudaMalloc(&mem_5, MB(128)));
    CHECK_RT(cudaMalloc(&mem_6, MB(128)));

    for(i=0; i<64; i++){
        kernel_1<<<1,128>>>(mem_1, mem_2, mem_3, mem_4, 0);
        kernel_2<<<1,128>>>(mem_1, mem_2, mem_3, mem_4, 0);
    }
    CHECK_RT(cudaStreamSynchronize(0));

    CHECK_RT(cudaFree(mem_1));
    CHECK_RT(cudaFree(mem_2));
    CHECK_RT(cudaFree(mem_3));
    CHECK_RT(cudaFree(mem_4));
    CHECK_RT(cudaFree(mem_5));
    CHECK_RT(cudaFree(mem_6));

    return 0;
}
