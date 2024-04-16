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

typedef struct mock_dev_ptr_struct {
    int nothing_1;
    int nothing_2;
    bool nothing_3;
    void *dev_ptr_1;
    void *dev_ptr_2;
    bool nothing_4;
    int nothing_5;
} mock_dev_ptr_struct_t;

__global__ void kernel_with_struct_input(const float* in_a, float* out_a, mock_dev_ptr_struct_t mock_struct_input, int len){ 
    ((float*)(mock_struct_input.dev_ptr_1))[0] = in_a[0];
}

int main(){
    float *mem_1, *mem_2, *mem_3, *mem_4, *mem_5, *mem_6;
    mock_dev_ptr_struct_t struct_input;
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

    struct_input.dev_ptr_1 = mem_1;
    struct_input.dev_ptr_2 = mem_2;
    
    POS_LOG("mem_1: %p, mem_2: %p", mem_1, mem_2);

    POS_LOG("sizeof mock_dev_ptr_struct_t: %lu bytes", sizeof(mock_dev_ptr_struct));

    s_tick = POSUtilTimestamp::get_tsc();

    kernel_with_struct_input<<<1,128>>>(mem_1, mem_2, struct_input, 0);
    kernel_with_struct_input<<<1,128>>>(mem_1, mem_2, struct_input, 0);
    
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
