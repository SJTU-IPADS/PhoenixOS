#include <iostream>
#include <vector>
#include <fstream>

#include <sys/resource.h>
#include <stdint.h>
#include <cuda_runtime_api.h>
#include <nvToolsExt.h>

#include "mb_common/ticks.h"

#define PROFILING_FILE_PATH "/root/memcpy_performance/profile.txt"


int main(){
    // initialize constants
    std::vector<uint64_t> buffer_sizes;
    constexpr uint64_t nb_buffers = 28;
    uint64_t i, s_tick, e_tick, max_buffer_size;
    double duration_us;
    void *ptr;
    std::vector<void*> mems;
    std::vector<float> host_data;
    std::ofstream output_file;

    struct rusage s_r_usage, e_r_usage;

    output_file.open(PROFILING_FILE_PATH, std::fstream::in | std::fstream::out | std::fstream::trunc);
    
    // set buffer sizes
    for(i=0; i<nb_buffers; i++){
        buffer_sizes.push_back(1<<i);
    }
    max_buffer_size = buffer_sizes[nb_buffers-1];

    // set host buffer
    host_data.reserve(max_buffer_size);
    for(i=0; i<max_buffer_size; i++){
        host_data.push_back(1.0f);
    }

    // malloc corresponding buffer
    for(i=0; i<nb_buffers; i++){
        if(cudaSuccess != cudaMalloc(&ptr, buffer_sizes[i])){
            printf("failed malloc %lu\n", i);
            exit(1);
        }
        mems.push_back(ptr);
    }

    // warmup
    cudaMemcpyAsync(host_data.data(), mems[1], buffer_sizes[1], cudaMemcpyDeviceToHost, 0);
    cudaStreamSynchronize(0);

    // measure
    for(i=0; i<nb_buffers; i++){
        if(getrusage(RUSAGE_SELF, &s_r_usage) != 0){
            printf("failed getrusage at %lu\n", i);
            exit(1);
        }

        s_tick = get_tsc();
        if(cudaSuccess != cudaMemcpyAsync(
            host_data.data(),
            mems[i],
            buffer_sizes[i],
            cudaMemcpyDeviceToHost,
            0
        )){
            printf("failed cudaMemcpyAsync at %lu\n", i);
            exit(1);
        }
        e_tick = get_tsc();

        if(getrusage(RUSAGE_SELF, &e_r_usage) != 0){
            printf("failed getrusage at %lu\n", i);
            exit(1);
        }

        duration_us = POS_TSC_RANGE_TO_USEC(e_tick, s_tick);
        printf(
            "copy duration: %lf us, size: %lu Bytes, bw: %lf Mbps, page fault: %ld (major), %ld (minor)\n",
            duration_us, buffer_sizes[i], (double)(buffer_sizes[i]) / duration_us,
            e_r_usage.ru_majflt - s_r_usage.ru_majflt,
            e_r_usage.ru_minflt - s_r_usage.ru_minflt
        );
        output_file << duration_us << "," << buffer_sizes[i] << std::endl;
    }

    for(i=0; i<nb_buffers; i++){
        cudaFree(mems[i]);
    }

    output_file.close();

    return 0;
}
