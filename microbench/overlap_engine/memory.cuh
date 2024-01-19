#pragma once

#include <iostream>
#include <stdint.h>
#include <cuda_runtime_api.h>

#include "utils.cuh"

class DeviceMemory {
 public:
    DeviceMemory(uint64_t client_addr, uint64_t size) : dev_ptr(client_addr), size(size) {
        CHECK_RT(cudaMalloc(&dev_ptr, size));
    }

    ~DeviceMemory() {
        CHECK_RT(cudaFree(dev_ptr));
    }

    void *dev_ptr;
    uint64_t size;

 private:
    // TODO: checkpoint bag
};
