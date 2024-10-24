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


pos_retval_t POSHandle_CUDA_Memory::__init_ckpt_bag(){ 
    this->ckpt_bag = new POSCheckpointBag(
        this->state_size,
        this->__checkpoint_allocator,
        this->__checkpoint_deallocator,
        this->__checkpoint_dev_allocator,
        this->__checkpoint_dev_deallocator
    );
    POS_CHECK_POINTER(this->ckpt_bag);
    return POS_SUCCESS;
}


pos_retval_t POSHandle_CUDA_Memory::__add(uint64_t version_id, uint64_t stream_id){
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;
    POSCheckpointSlot* ckpt_slot;

    // apply new on-device checkpoint slot
    if(unlikely(
        POS_SUCCESS != this->ckpt_bag->apply_checkpoint_slot<kPOS_CkptSlotPosition_Device>(
            /* version */ version_id,
            /* ptr */ &ckpt_slot,
            /* dynamic_state_size */ 0,
            /* force_overwrite */ true
        )
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
        POS_SUCCESS != this->ckpt_bag->apply_checkpoint_slot<kPOS_CkptSlotPosition_Host>(
            /* version */ version_id,
            /* ptr */ &ckpt_slot,
            /* dynamic_state_size */ 0,
            /* force_overwrite */ true
        )
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
            POS_SUCCESS != this->ckpt_bag->get_checkpoint_slot<kPOS_CkptSlotPosition_Device>(/* ptr */ &cow_ckpt_slot, /* version */ version_id)
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


pos_retval_t POSHandle_CUDA_Memory::__generate_protobuf_binary(google::protobuf::Message** binary, google::protobuf::Message** base_binary){
    pos_retval_t retval = POS_SUCCESS;
    pos_protobuf::Bin_POSHanlde_CUDA_Memory *cuda_memory_binary;

    POS_CHECK_POINTER(binary);
    POS_CHECK_POINTER(base_binary);

    cuda_memory_binary = new pos_protobuf::Bin_POSHanlde_CUDA_Memory();
    POS_CHECK_POINTER(cuda_memory_binary);

    *binary = reinterpret_cast<google::protobuf::Message*>(cuda_memory_binary);
    POS_CHECK_POINTER(*binary);
    *base_binary = cuda_memory_binary->mutable_base();
    POS_CHECK_POINTER(*base_binary);

    // serialize handle specific fields
    /* currently nothing */

    return retval;
}


pos_retval_t POSHandle_CUDA_Memory::__restore(){
    pos_retval_t retval = POS_SUCCESS;

    cudaError_t cuda_rt_retval;
    CUresult cuda_dv_retval;
    POSHandle_CUDA_Device *device_handle;
    
    CUmemAllocationProp prop = {};
    CUmemGenericAllocationHandle hdl;
    CUmemAccessDesc access_desc;

    void *rt_ptr;

    POS_ASSERT(this->parent_handles.size() == 1);
    POS_CHECK_POINTER(device_handle = static_cast<POSHandle_CUDA_Device*>(this->parent_handles[0]));

    if(likely(this->server_addr != 0)){
        /*!
            *  \note   case:   restore memory handle at the specified memory address
            */
        POS_ASSERT(this->client_addr == this->server_addr);

        prop.type = CU_MEM_ALLOCATION_TYPE_PINNED;
        prop.location.type = CU_MEM_LOCATION_TYPE_DEVICE;
        prop.location.id = device_handle->id;

        cuda_dv_retval = cuMemCreate(
            /* handle */ &hdl,
            /* size */ this->state_size,
            /* prop */ &prop,
            /* flags */ 0
        );
        if(unlikely(CUDA_SUCCESS != cuda_dv_retval)){
            POS_WARN_DETAIL(
                "failed to execute cuMemCreate while restoring: client_addr(%p), state_size(%lu), retval(%d)",
                this->client_addr, this->state_size, cuda_dv_retval
            );
            retval = POS_FAILED;
            goto exit;
        }

        cuda_dv_retval = cuMemMap(
            /* ptr */ (CUdeviceptr)(this->server_addr),
            /* size */ this->state_size,
            /* offset */ 0ULL,
            /* handle */ hdl,
            /* flags */ 0ULL
        );
        if(unlikely(CUDA_SUCCESS != cuda_dv_retval)){
            POS_WARN_DETAIL(
                "failed to execute cuMemMap while restoring: client_addr(%p), state_size(%lu), retval(%d)",
                this->client_addr, this->state_size, cuda_dv_retval
            );
            retval = POS_FAILED;
            goto exit;
        }

        // set access attribute of this memory
        access_desc.location = prop.location;
        access_desc.flags = CU_MEM_ACCESS_FLAGS_PROT_READWRITE;
        cuda_dv_retval = cuMemSetAccess(
            /* ptr */ (CUdeviceptr)(this->server_addr),
            /* size */ this->state_size,
            /* desc */ &access_desc,
            /* count */ 1ULL
        );
        if(unlikely(CUDA_SUCCESS != cuda_dv_retval)){
            POS_WARN_DETAIL(
                "failed to execute cuMemSetAccess while restoring: client_addr(%p), state_size(%lu), retval(%d)",
                this->client_addr, this->state_size, cuda_dv_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    } else {
        /*!
            *  \note   case:   no specified address to restore, randomly assign one
            */
        cuda_rt_retval = cudaMalloc(&rt_ptr, this->state_size);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            retval = POS_FAILED;
            POS_WARN_C_DETAIL("failed to restore CUDA memory, cudaMalloc failed: %d", cuda_rt_retval);
            goto exit;
        }

        retval = this->set_passthrough_addr(rt_ptr, this);
        if(unlikely(POS_SUCCESS != retval)){ 
            POS_WARN_DETAIL("failed to restore CUDA memory, failed to set passthrough address for the memory handle: %p", rt_ptr);
            goto exit;
        }
    }

    this->mark_status(kPOS_HandleStatus_Active);

exit:
    return retval;
}


pos_retval_t POSHandle_CUDA_Memory::__reload_state(void* data, uint64_t offset, uint64_t size, uint64_t stream_id, bool on_device){
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;

    POS_CHECK_POINTER(data);

    cuda_rt_retval = cudaMemcpyAsync(
        /* dst */ this->server_addr,
        /* src */ data,
        /* count */ size,
        /* kind */ on_device == false ? cudaMemcpyHostToDevice : cudaMemcpyDeviceToDevice,
        /* stream */ (cudaStream_t)(stream_id)
    );
    if(unlikely(cuda_rt_retval != cudaSuccess)){
        POS_WARN_DETAIL("failed to reload state of CUDA memory: server_addr(%p), retval(%d)", this->server_addr, cuda_rt_retval);
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(stream_id));
    if(unlikely(cuda_rt_retval != cudaSuccess)){
        POS_WARN_DETAIL("failed to synchronize after reloading state of CUDA memory: server_addr(%p), retval(%d)", this->server_addr, cuda_rt_retval);
        retval = POS_FAILED;
        goto exit;
    }

exit:
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
        if(unlikely(cudaSuccess != cudaSetDevice(device_handle->id))){
            POS_ERROR_DETAIL("failed to call cudaSetDevice");
        }
    }    

    this->has_finshed_reserved = true;

exit:
    ;
}


pos_retval_t POSHandleManager_CUDA_Memory::allocate_mocked_resource(
    POSHandle_CUDA_Memory** handle,
    std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
    size_t size, uint64_t expected_addr, uint64_t state_size
){
    pos_retval_t retval = POS_SUCCESS;
    POSHandle_CUDA_Device *device_handle;
    CUdeviceptr alloc_ptr;
    uint64_t aligned_alloc_size;

    POS_CHECK_POINTER(handle);

    // obtain the device to allocate buffer
#if POS_CONF_RUNTIME_EnableDebugCheck
    if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Device) == 0)){
        POS_WARN_C("no binded device provided to create the CUDA memory");
        retval = POS_FAILED_INVALID_INPUT;
        goto exit;
    }
#endif

    device_handle = (POSHandle_CUDA_Device*)(related_handles[kPOS_ResourceTypeId_CUDA_Device][0]);
    POS_ASSERT(POSHandleManager_CUDA_Memory::alloc_ptrs.count(device_handle->id) == 1);
    POS_ASSERT(POSHandleManager_CUDA_Memory::alloc_granularities.count(device_handle->id) == 1);

    // obtain the desired address based on reserved virtual memory space pointer
    alloc_ptr = POSHandleManager_CUDA_Memory::alloc_ptrs[device_handle->id];
    
    // no avaialble memory space on device
    if(unlikely((void*)(alloc_ptr) == nullptr)){
        retval = POS_FAILED_DRAIN;
        goto exit;
    }

    // forward the allocation pointer
#define ROUND_UP(size, alloc_granularity) ((size + alloc_granularity - 1) / alloc_granularity) * alloc_granularity
    aligned_alloc_size = ROUND_UP(state_size, POSHandleManager_CUDA_Memory::alloc_granularities[device_handle->id]);
    POSHandleManager_CUDA_Memory::alloc_ptrs[device_handle->id] += aligned_alloc_size;
#undef ROUND_UP

    retval = this->__allocate_mocked_resource(handle, true, size, expected_addr, aligned_alloc_size);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to allocate mocked CUDA memory in the manager");
        goto exit;
    }
    (*handle)->record_parent_handle(device_handle);

    // we directly setup the passthrough address here
    (*handle)->set_passthrough_addr((void*)(alloc_ptr), (*handle));

exit:
    return retval;
}
