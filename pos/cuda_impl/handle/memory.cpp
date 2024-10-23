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


pos_retval_t POSHandle_CUDA_Memory::__add(uint64_t version_id, uint64_t stream_id){
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;
    POSCheckpointSlot* ckpt_slot;

    // apply new on-device checkpoint slot
    if(unlikely(
        POS_SUCCESS != this->ckpt_bag->apply_checkpoint_slot</* on_device */ true>
                                    (/* version */ version_id, /* ptr */ &ckpt_slot, /* force_overwrite */ true)
    )){
        POS_WARN_C("failed to apply checkpoint slot");
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_retval = cudaMemcpyAsync(
        /* dst */ ckpt_slot->expose_pointer(), 
        /* src */ this->server_addr,
        /* size */ this->state_size,
        /* kind */ cudaMemcpyDeviceToDevice,
        /* stream */ (cudaStream_t)(stream_id)
    );
    if(unlikely(cuda_rt_retval != cudaSuccess)){
        POS_WARN_C(
            "failed to checkpoint memory handle on device: server_addr(%p), retval(%d)",
            this->server_addr, cuda_rt_retval
        );
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(stream_id));
    if(unlikely(cuda_rt_retval != cudaSuccess)){
        POS_WARN_C(
            "failed to synchronize after checkpointing memory handle on device: server_addr(%p), retval(%d)",
            this->server_addr, cuda_rt_retval
        );
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}


pos_retval_t POSHandle_CUDA_Memory::__commit(
    uint64_t version_id, uint64_t stream_id, bool from_cache, bool is_sync, std::string ckpt_dir
){ 
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;
    POSCheckpointSlot *ckpt_slot, *cow_ckpt_slot;
    
    cudaSetDevice(0);

    // apply new host-side checkpoint slot
    if(unlikely(
        POS_SUCCESS != this->ckpt_bag->apply_checkpoint_slot</* on_device */ false>
                                    (/* version */ version_id, /* ptr */ &ckpt_slot, /* force_overwrite */ true)
    )){
        POS_WARN_C("failed to apply host-side checkpoint slot");
        retval = POS_FAILED;
        goto exit;
    }

    if(from_cache == false){
        // commit from origin buffer
        cuda_rt_retval = cudaMemcpyAsync(
            /* dst */ ckpt_slot->expose_pointer(), 
            /* src */ this->server_addr,
            /* size */ this->state_size,
            /* kind */ cudaMemcpyDeviceToHost,
            /* stream */ (cudaStream_t)(stream_id)
        );
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to checkpoint memory handle from origin buffer: server_addr(%p), retval(%d)",
                this->server_addr, cuda_rt_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    } else {
        // commit from cache buffer
        if(unlikely(
            POS_SUCCESS != this->ckpt_bag->get_checkpoint_slot</* on_device */ true>(/* ptr */ &cow_ckpt_slot, /* version */ version_id)
        )){
            POS_ERROR_C_DETAIL(
                "no cache buffer with the version founded, this is a bug: version_id(%lu), server_addr(%p)",
                version_id, this->server_addr
            );
        }
        cuda_rt_retval = cudaMemcpyAsync(
            /* dst */ ckpt_slot->expose_pointer(), 
            /* src */ cow_ckpt_slot->expose_pointer(),
            /* size */ this->state_size,
            /* kind */ cudaMemcpyDeviceToHost,
            /* stream */ (cudaStream_t)(stream_id)
        );
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to checkpoint memory handle from COW buffer: server_addr(%p), retval(%d)",
                this->server_addr, cuda_rt_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    }

    if(is_sync){
        cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(stream_id));
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to synchronize after commiting memory handle: server_addr(%p), retval(%d)",
                this->server_addr, cuda_rt_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    }

    retval = this->__persist(ckpt_slot, ckpt_dir, stream_id);

exit:
    return retval;
}


pos_retval_t POSHandle_CUDA_Memory::__persist_async_thread(POSCheckpointSlot* ckpt_slot, std::string& ckpt_dir, uint64_t stream_id){
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;
    std::string ckpt_file_path;
    std::ofstream ckpt_file_stream;
    pos_protobuf::Bin_POSHanlde_CUDA_Memory binary;
    pos_protobuf::Bin_POSHanlde *base_binary = nullptr;

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

    base_binary = binary.mutable_base();
    POS_CHECK_POINTER(base_binary);
    
    // serialize base binary
    retval = this->__serialize_protobuf_handle_base(base_binary);
    if(unlikely(retval = POS_SUCCESS)){
        POS_WARN_C(
            "failed to serialize base binry to protobuf: server_addr(%p), retval(%d)",
            this->server_addr, retval
        );
        goto exit;
    }

    // serialize other fields
    /* currently nothing */

    // write to file
    ckpt_file_stream.open(ckpt_file_path, std::ios::binary | std::ios::out);
    if(!ckpt_file_stream){
        POS_WARN_C(
            "failed to dump checkpoint to file, failed to open file: path(%s)",
            ckpt_file_path.c_str()
        );
        retval = POS_FAILED;
        goto exit;
    }
    if(!binary.SerializeToOstream(&ckpt_file_stream)){
        POS_WARN_C(
            "failed to dump checkpoint to file, protobuf failed to dump: path(%s)",
            ckpt_file_path.c_str()
        );
        retval = POS_FAILED;
        goto exit;
    }

exit:
    if(ckpt_file_stream.is_open()){ ckpt_file_stream.close(); }
    return retval;
}


POSHandleManager_CUDA_Memory::POSHandleManager_CUDA_Memory(POSHandle_CUDA_Device* device_handle, bool is_restoring)
    : POSHandleManager(/* passthrough */ true, /* is_stateful */ true)
{
    int num_device, i, j;

    /*!
     *  \brief  reserve a large portion of virtual memory space on a specified device
     *  \param  device_id   index of the device
     */
    auto __reserve_device_vm_space = [](int device_id){
        uint64_t free_portion, free, total;
        uint64_t reserved_size, alloc_granularity;
        CUmemAllocationProp prop = {};
        CUmemGenericAllocationHandle hdl;
        CUmemAccessDesc accessDesc;
        CUdeviceptr ptr;

        cudaError_t rt_retval;

        POS_ASSERT(POSHandleManager_CUDA_Memory::alloc_ptrs.count(device_id) == 0);
        POS_ASSERT(POSHandleManager_CUDA_Memory::alloc_granularities.count(device_id) == 0);

        // switch to target device
        if(unlikely(cudaSuccess != cudaSetDevice(device_id))){
            POS_ERROR_DETAIL("failed to call cudaSetDevice");
        }
        cudaDeviceSynchronize();

        // obtain avaliable device memory space
        rt_retval = cudaMemGetInfo(&free, &total);
        if(unlikely(rt_retval == cudaErrorMemoryAllocation || free < 16*1024*1024)){
            POS_LOG("no available memory space on device to reserve, skip: device_id(%d)", device_id);
            POSHandleManager_CUDA_Memory::alloc_granularities[device_id] = 0;
            POSHandleManager_CUDA_Memory::alloc_ptrs[device_id] = (CUdeviceptr)(nullptr);
            goto exit;
        }
        if(unlikely(cudaSuccess != rt_retval)){
            POS_ERROR_DETAIL("failed to call cudaMemGetInfo: retval(%d)", rt_retval);
        }

        // obtain granularity of allocation
        prop.type = CU_MEM_ALLOCATION_TYPE_PINNED;
        prop.location.type = CU_MEM_LOCATION_TYPE_DEVICE;
        prop.location.id = device_id;
        if(unlikely(
            CUDA_SUCCESS != cuMemGetAllocationGranularity(&alloc_granularity, &prop, CU_MEM_ALLOC_GRANULARITY_MINIMUM)
        )){
            POS_ERROR_DETAIL("failed to call cuMemGetAllocationGranularity");
        }
        POSHandleManager_CUDA_Memory::alloc_granularities[device_id] = alloc_granularity;

        /*!
            *  \note   we only reserved 80% of free memory, and round up the size according to allocation granularity
            */
    #define ROUND_UP(size, aligned_size) ((size + aligned_size - 1) / aligned_size) * aligned_size
        free_portion = 1.0*free;
        reserved_size = ROUND_UP(free_portion, alloc_granularity);
    #undef ROUND_UP

        if(unlikely(
            CUDA_SUCCESS != cuMemAddressReserve(&ptr, reserved_size, 0, POSHandleManager_CUDA_Memory::reserved_vm_base, 0ULL)
        )){
            POS_ERROR_DETAIL("failed to call cuMemAddressReserve");
        }
        POSHandleManager_CUDA_Memory::alloc_ptrs[device_id] = ptr;
        POS_LOG("reserved virtual memory space: device_id(%d), base(%p), size(%lu)", device_id, ptr, reserved_size);
        
    exit:
        ;
    };

    auto __set_peer_access = [](int src_device_id, int dst_device_id){
        // switch to target device
        if(unlikely(cudaSuccess != cudaSetDevice(src_device_id))){
            POS_ERROR_DETAIL("failed to call cudaSetDevice");
        }
        cudaDeviceSynchronize();
        cudaDeviceEnablePeerAccess(dst_device_id, 0);
    };

    // we mock that we have preallocated a huge b
    auto __malloc_huge_backup_memory_for_migration = [](int device_id) -> void* {
        cudaError_t cuda_rt_retval;
        void *ptr;

        // switch to target device
        if(unlikely(cudaSuccess != cudaSetDevice(device_id))){
            POS_ERROR_DETAIL("failed to call cudaSetDevice");
        }
        cudaDeviceSynchronize();

        cuda_rt_retval = cudaMalloc(&ptr, GB(12));
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN("failed to preserve %lu bytes on the backup device", GB(12));
        }
        POS_LOG("reserved backup memory space: device_id(%d), size(%lu)", device_id, GB(12));

        return ptr;
    };

    // no need to conduct reserving if previous hm has already done
    if(this->has_finshed_reserved == true){
        goto exit;
    }

    // obtain the number of devices
    if(unlikely(cudaSuccess != cudaGetDeviceCount(&num_device))){
        POS_ERROR_C_DETAIL("failed to call cudaGetDeviceCount");
    }
    if(unlikely(num_device == 0)){
        POS_ERROR_C_DETAIL("no CUDA device detected");
    }

    // we reserve virtual memory space on each device
    for(i=0; i<num_device; i++){
        __reserve_device_vm_space(i);
    }

    if(is_restoring == false){
        POS_CHECK_POINTER(device_handle);
        // switch back to origin default device
        if(unlikely(cudaSuccess != cudaSetDevice(device_handle->device_id))){
            POS_ERROR_DETAIL("failed to call cudaSetDevice");
        }
    }    

    this->has_finshed_reserved = true;

exit:
    ;
}
