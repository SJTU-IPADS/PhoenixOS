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

#include <iostream>

#include <cuda.h>
#include <cuda_runtime_api.h>


#define ROUND_UP(size, aligned_size)    ((size + aligned_size - 1) / aligned_size) * aligned_size;


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


__global__ void test_kernel(int *output_mem, size_t mem_size){
    int i;
    int fatten_id = blockIdx.x * blockDim.x + threadIdx.x;
    
    for(i=fatten_id; i<mem_size; i+=blockDim.x){
        if(fatten_id < mem_size)
            output_mem[i] = 2;
    }
}


int main(){
    int *read_vector;

    uint64_t vector_size = 8192;

    // allocate vector for reading test
    CHECK_RT(cudaMallocManaged((void**)&read_vector, vector_size));

    // launch kernel
    test_kernel<<<1, 256>>>(read_vector, vector_size);

    // free
    CHECK_RT(cudaFree(read_vector));
}
