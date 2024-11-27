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
#include <multimap>

#include <stdint.h>
#include <cuda_runtime_api.h>

#include "utils.cuh"
#include "memory.cuh"
#include "kernel.cuh"

class Stream {
 public:
    Stream(){
        CHECK_RT(cudaStreamCreate(&_stream));
    }

    ~Stream(){
        CHECK_RT(cudaStreamDestroy(_stream));
    }

    inline void sync(){
        CHECK_RT(cudaStreamSynchronize(_stream));
    }

 private:
    cudaStream_t _stream;
};


class OverlapEngine {
 public:
    OverlapEngine(){
        uint64_t i;
        Stream *new_stream;

        // allocate streams to the pool
        for(i=0; i<16; i++){
            CHECK_POINTER(new_stream = new Stream());
            _stream_pool.push_back(new_stream);
        }

    }

    ~OverlapEngine(){
        for(auto &stream : _stream_pool){
            CHECK_POINTER(stream);
            delete stream;
        }
    };

    // ckpt_memories: memories to be checkpointed (size)
    // kernels: kernels to be launch (duration, which memory to use)
    inline void schedule(const std::vector<DeviceMemory*>& ckpt_memories, const std::vector<Kernel*>& kernels){
        // ddl_id -> memory
        std::multimap<uint64_t, DeviceMemory*> deadline_map;

        // step 1: obtain deadline
        __get_checkpoint_deadline(ckpt_memories, kernels, deadline_map);

        // step 2: distribution (checkpoint range)


        // step 3: assign to corresponding stream
    }

 private:
    std::vector<Stream*> _stream_pool;

    inline void __get_checkpoint_deadline(
        const std::vector<DeviceMemory*>& ckpt_memories, const std::vector<Kernel*>& kernels, std::multimap<uint64_t, DeviceMemory*>& deadline_map
    ){
        uint64_t kernel_id, deadline_id;
        Kernel *kernel;

        deadline_map.clear();

        for(auto& memory : ckpt_memories){
            // if no kernel use this, we can even checkpoint this memory in the last op,
            // so the ddl should large than the last one, i.e., kernel.size()
            deadline_id = kernels.size();
            
            for(kernel_id=0; kernel_id<kernels.size(); kernel_id++){
                CHECK_POINTER(kernel = kernels[kernel_id]);
                if(kernel->is_output_memory(memory->dev_ptr)){
                    deadline_id = kernel_id;
                    break;
                }
            }

            deadline_map.insert({ deadline_id, memory });
        }
    }

    // thinking:
    // 1. if involve ckpt a specific memory will cause huge load, we should abandon it
    // 2. we can leave those memory that has rare op would output keep ckpting,
    // these memories might be immutable memory area currently

    inline void __get_distribution_scheme(
        const std::vector<DeviceMemory*>& ckpt_memories,
        const std::vector<Kernel*>& kernels,
        std::multimap<uint64_t, DeviceMemory*>& deadline_map,
        std::vector<std::pair<uint64_t, uint64_t>>& distribution_scheme
    ){
        typename std::multimap<uint64_t, DeviceMemory*>::iterator ddl_map_iter;
        uint64_t ddl_id;
        DeviceMemory *memory;
        double avg_size;

        // normalized overlap load: overlap size / kernel duration
        std::vector<double> kernel_overlap_load(kernels.size(), 0.0f);

        auto __get_normalized_overlap_load = [](const uint64_t size, const uint64_t duration_us) -> double {
            return (double)size / (double)duration_us;
        }

        // we start from the earlist memory that need to be ckpted
        for(ddl_map_iter=deadline_map.begin(); ddl_map_iter!=deadline_map.end(); ddl_map_iter++){
            ddl_id = ddl_map_iter->first();
            CHECK_POINTER(memory = ddl_map_iter->second());

            // we need to immediately, so we don't need to care about the scheme schedule later
            if(ddl_id == 0){
                
            }

            avg_size = (double)(memroy->size) / (double)(ddl_id-0);
        }
    }
};
