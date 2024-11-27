/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
