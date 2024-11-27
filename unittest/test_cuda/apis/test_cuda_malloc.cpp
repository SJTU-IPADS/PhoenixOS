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

#include "test_cuda/test_cuda_common.h"

TEST_F(PhOSCudaTest, cudaMalloc) {
    uint64_t i;

    POSWorkspace_CUDA *ws;
    POSClient_CUDA *clnt;

    cudaError cuda_retval;
    void *mem_ptr;
    std::vector<void*> mem_ptrs;
    std::vector<size_t> mem_sizes({ 16, 512, KB(1), KB(2), KB(4), KB(8) });

    for(size_t mem_size : mem_sizes){
        cuda_retval = (cudaError)this->_ws->pos_process( 
            /* api_id */ CUDA_MALLOC, 
            /* uuid */ this->_clnt->id,
            /* param_desps */ {
                { .value = &mem_size, .size = sizeof(size_t) }
            },
            /* ret_data */ &(mem_ptr),
            /* ret_data_len */ sizeof(uint64_t)
        );
        EXPECT_EQ(cudaSuccess, cuda_retval);
        mem_ptrs.push_back(mem_ptr);
    }
}
