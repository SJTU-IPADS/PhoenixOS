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
#include <vector>

#include <stdint.h>
#include <cuda_runtime_api.h>

#include "utils.cuh"
#include "memory.cuh"

using launch_func_t = void(*)();

class Kernel {
 public:
    Kernel(
        uint64_t duration_us, 
        std::vector<DeviceMemory*>& inputs,
        std::vector<DeviceMemory*>& outputs,
        launch_func_t launch_kernel_function
    ) : duration_us(duration_us), _launch_async(launch_kernel_function),
        inputs(inputs), outputs(outputs) 
    {
    }

    ~Kernel() = default;

    inline void launch_async(){ _launch_async(); }

    uint64_t duration_us;
    std::vector<DeviceMemory*> inputs; 
    std::vector<DeviceMemory*> outputs;

    inline bool is_input_memory(void* addr){
        for(auto& memory : inputs){
            if(memory->dev_ptr == addr){
                return true;
            }
        }
        return false;
    }

    inline bool is_output_memory(void* addr){
        for(auto& memory : outputs){
            if(memory->dev_ptr == addr){
                return true;
            }
        }
        return false;
    }

 private:
    launch_func_t _launch_async;
};
