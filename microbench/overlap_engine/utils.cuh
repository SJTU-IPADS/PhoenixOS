#pragma once

#include <iostream>

#include <assert.h>

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

#define CHECK_POINTER(ptr) assert((ptr) != nullptr);

#define MB(x)   ((size_t) (x) << 20)

#define POS_TSC_RANGE_TO_SEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ

#define POS_TSC_RANGE_TO_MSEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ * (double)1000.0f

#define POS_TSC_RANGE_TO_USEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ * (double)1000000.0f

#define POS_TSC_TO_USEC(tick) \
    (double)(tick) / (double) POS_TSC_FREQ * (double)1000000.0f

#define POS_USEC_TO_TSC(usec) \
    (double)(usec) / (double)1000000.0f * (double) POS_TSC_FREQ

inline uint64_t get_tsc(){
    uint64_t a, d;
    __asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
    return (d << 32) | a;
}
