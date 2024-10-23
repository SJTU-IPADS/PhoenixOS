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
#include <map>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/memory.h"
#include "pos/cuda_impl/proto/memory.pb.h"


std::map<int, CUdeviceptr>  POSHandleManager_CUDA_Memory::alloc_ptrs;
std::map<int, uint64_t>     POSHandleManager_CUDA_Memory::alloc_granularities;
bool                        POSHandleManager_CUDA_Memory::has_finshed_reserved;
const uint64_t              POSHandleManager_CUDA_Memory::reserved_vm_base = 0x7facd0000000;


pos_retval_t POSHandle_CUDA_Memory::__persist_async_thread(POSCheckpointSlot* ckpt_slot, std::string& ckpt_dir, uint64_t stream_id){
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;
    std::string ckpt_file_path;
    std::ofstream ckpt_file_stream;

    POS_CHECK_POINTER(ckpt_slot);
    POS_ASSERT(std::filesystem::exists(ckpt_dir));

    // form the path to the checkpoint file of this handle
    ckpt_file_path = ckpt_dir 
                    + std::string("/sf-")
                    + std::to_string(this->resource_type_id) 
                    + std::string("-")
                    + std::to_string(this->id)
                    + std::string(".bin");

    // synchronize the commit stream
    cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(stream_id));
    if(unlikely(cuda_rt_retval != cudaSuccess)){
        POS_WARN_C(
            "failed to synchronize commit stream before persist checkpoint to file system: server_addr(%p), retval(%d)",
            this->server_addr, cuda_rt_retval
        );
        retval = POS_FAILED;
        goto exit;
    }
    
    // TODO: serialize using pb

exit:
    return retval;
}
