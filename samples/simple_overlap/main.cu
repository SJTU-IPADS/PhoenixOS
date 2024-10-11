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
#define GB(x)   ((size_t) (x) << 30)

__global__ void kernel_1(const float* in_a, float* out_a){ 
    
#define DEVICE_FREQUENCY_1_1000 1380
#define SLEEP_MS_TO_CYCLES(x)   x * DEVICE_FREQUENCY_1_1000000

    out_a[1] = in_a[0];
    out_a[2] = in_a[1];
}


int main(){
    float *mem_1, *mem_2;

    CHECK_RT(cudaMalloc(&mem_1, GB(2)));
    CHECK_RT(cudaMalloc(&mem_2, GB(4)));

    for(uint64_t i=0; i<50; i++){
        for(uint64_t j=0; j<200; j++){
            kernel_1<<<1,128>>>(mem_1, mem_1);
        }
        POSUtilTimestamp::delay_us(500);

        for(uint64_t j=0; j<200; j++){
            kernel_1<<<1,128>>>(mem_2, mem_2);
        }
        POSUtilTimestamp::delay_us(500);
    }
}
