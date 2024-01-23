#include <iostream>

#include <assert.h>
#include <unistd.h>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timestamp.h"

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
template<unsigned us>
__device__ void __sleep_us() {    
    __nanosleep(us*1000);
}

__global__ void kernel_1(const float* in_a, float* out_a, float* out_b, float* out_c, int len){ 
    __sleep_us<5>();
}
__global__ void kernel_2(const float* in_a, const float* in_b, const float* in_c, float* out_a, int len){
   __sleep_us<10>();
}
__global__ void kernel_3(const float* in_a, float* out_a, int len){ 
    __sleep_us<15>();
}
__global__ void kernel_4(const float* in_a, const float* in_b, float* out_a, int len){ 
    __sleep_us<15>();
}

int main(){
    uint64_t i, j;
    float *mem_1, *mem_2, *mem_3, *mem_4, *mem_5, *mem_6;

    uint64_t s_tick, e_tick;

    // cudaDeviceProp prop;

    // CHECK_RT(cudaGetDeviceProperties(&prop, 0));
    // printf("device clock rate: %d\n", prop.clockRate);
    // assert(prop.clockRate == CLOCK_RATE);

    CHECK_RT(cudaMalloc(&mem_1, MB(16)));
    CHECK_RT(cudaMalloc(&mem_2, MB(64)));
    CHECK_RT(cudaMalloc(&mem_3, MB(32)));
    CHECK_RT(cudaMalloc(&mem_4, MB(128)));
    CHECK_RT(cudaMalloc(&mem_5, MB(8)));
    CHECK_RT(cudaMalloc(&mem_6, MB(2)));

    s_tick = POSUtilTimestamp::get_tsc();

    for(i=0; i<8; i++){
        for(j=0; j<512; j++){
            kernel_1<<<1,128>>>(mem_1, mem_2, mem_3, mem_4, 0);
            kernel_2<<<1,128>>>(mem_2, mem_4, mem_1, mem_3, 0);
            kernel_3<<<1,128>>>(mem_4, mem_3, 0);
            kernel_4<<<1,128>>>(mem_3, mem_5, mem_6, 0);
            kernel_3<<<1,128>>>(mem_6, mem_4, 0);
            kernel_1<<<1,128>>>(mem_2, mem_4, mem_6, mem_1, 0);
        }
        CHECK_RT(cudaStreamSynchronize(0));
        usleep(1000);
    }

    e_tick = POSUtilTimestamp::get_tsc();

    POS_LOG("E2E Latency: %lf us", POS_TSC_TO_USEC(e_tick-s_tick));

    CHECK_RT(cudaFree(mem_1));
    CHECK_RT(cudaFree(mem_2));
    CHECK_RT(cudaFree(mem_3));
    CHECK_RT(cudaFree(mem_4));
    CHECK_RT(cudaFree(mem_5));
    CHECK_RT(cudaFree(mem_6));

    return 0;
}
