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
#include <string>
#include <map>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <sys/resource.h>
#include <stdint.h>
#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/handle.h"
#include "pos/include/utils/serializer.h"

#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/device.h"


/*!
 *  \brief  handle for cuda memory
 */
class POSHandle_CUDA_Memory : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  id_             index of this handle in the handle manager list
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Memory(size_t size_, void* hm, pos_u64id_t id_, size_t state_size_=0)
        : POSHandle(size_, hm, id_, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Memory;

    #if POS_CONF_EVAL_CkptOptLevel > 0 || POS_CONF_EVAL_MigrOptLevel > 0
        // initialize checkpoint bag
        if(unlikely(POS_SUCCESS != this->init_ckpt_bag())){
            POS_ERROR_C_DETAIL("failed to inilialize checkpoint bag");
        }
    #endif
    }

    /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle_CUDA_Memory(void* hm) : POSHandle(hm)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Memory;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Memory(void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, id_, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  allocator of the host-side checkpoint memory
     *  \param  state_size  size of the area to store checkpoint
     */
    static void* __checkpoint_allocator(uint64_t state_size) {
        cudaError_t cuda_rt_retval;
        void *ptr;

        if(unlikely(state_size == 0)){
            POS_WARN_DETAIL("try to allocate checkpoint with state size of 0");
            return nullptr;
        }

        cuda_rt_retval = cudaMallocHost(&ptr, state_size);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_DETAIL("failed cudaMallocHost, error: %d", cuda_rt_retval);
            return nullptr;
        }

        return ptr;
    }

    /*!
     *  \brief  deallocator of the host-side checkpoint memory
     *  \param  data    pointer of the buffer to be deallocated
     */
    static void __checkpoint_deallocator(void* data){
        cudaError_t cuda_rt_retval;
        if(likely(data != nullptr)){
            cuda_rt_retval = cudaFreeHost(data);
            if(unlikely(cuda_rt_retval != cudaSuccess)){
                POS_WARN_DETAIL("failed cudaFreeHost, error: %d", cuda_rt_retval);
            }
        }
    }

    /*!
     *  \brief  allocator of the device-side checkpoint memory
     *  \param  state_size  size of the area to store checkpoint
     */
    static void* __checkpoint_dev_allocator(uint64_t state_size) {
        cudaError_t cuda_rt_retval;
        void *ptr;

        if(unlikely(state_size == 0)){
            POS_WARN_DETAIL("try to allocate checkpoint with state size of 0");
            return nullptr;
        }

        cuda_rt_retval = cudaMalloc(&ptr, state_size);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_DETAIL("failed cudaMalloc, error: %d", cuda_rt_retval);
            return nullptr;
        }

        return ptr;
    }

    /*!
     *  \brief  deallocator of the host-side checkpoint memory
     *  \param  data    pointer of the buffer to be deallocated
     */
    static void __checkpoint_dev_deallocator(void* data){
        cudaError_t cuda_rt_retval;
        if(likely(data != nullptr)){
            cuda_rt_retval = cudaFree(data);
            if(unlikely(cuda_rt_retval != cudaSuccess)){
                POS_WARN_DETAIL("failed cudaFree, error: %d", cuda_rt_retval);
            }
        }
    }

    
    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Memory"); }


    /*!
     *  \brief  restore the current handle REMOTELY when it becomes broken status
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t remote_restore() override {
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;

        this->remote_server_addr = ((POSHandleManager<POSHandle_CUDA_Memory>*)(this->_hm))->backup_base_memory;
        
    exit:
        return retval;
    }

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t __restore() override {
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
            prop.location.id = device_handle->device_id;

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

 protected:
    /*!
     *  \brief  reload state of this handle back to the device
     *  \param  data        source data to be reloaded
     *  \param  offset      offset from the base address of this handle to be reloaded
     *  \param  size        reload size
     *  \param  stream_id   stream for reloading the state
     *  \param  on_device   whether the source data is on device
     */
    pos_retval_t __reload_state(void* data, uint64_t offset, uint64_t size, uint64_t stream_id, bool on_device){
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

    /*!
     *  \brief  commit the state of the resource behind this handle
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \param  from_cow    whether to dump from on-device cow buffer
     *  \param  is_sync    whether the commit process should be sync
     *  \param  ckpt_dir    directory to store the checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t __commit(
        uint64_t version_id, uint64_t stream_id=0, bool from_cache=false, bool is_sync=false, std::string ckpt_dir=""
    ) override;

    /*!
     *  \brief  add the state of the resource behind this handle to on-device memory
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \note   the add process must be sync
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t __add(uint64_t version_id, uint64_t stream_id=0) override;

    /*!
     *  \brief  persist the checkpoint to file system
     *  \param  ckpt_slot   the checkopoint slot which stores the host-side checkpoint
     *  \param  ckpt_dir    directory to store the checkpoint
     *  \param  stream_id   index of the stream on which checkpoint is commited
     *  \return POS_SUCCESS for successfully persist
     */
    pos_retval_t __persist_async_thread(POSCheckpointSlot* ckpt_slot, std::string& ckpt_dir, uint64_t stream_id=0) override;

    /*!
     *  \brief  obtain the serilization size of extra fields of specific POSHandle type
     *  \return the serilization size of extra fields of POSHandle
     */
    uint64_t __get_extra_serialize_size() override {
        return 0;
    }

    /*!
     *  \brief  serialize the extra state of current handle into the binary area
     *  \param  serialized_area  pointer to the binary area
     *  \return POS_SUCCESS for successfully serilization
     */
    pos_retval_t __serialize_extra(void* serialized_area) override {
        return POS_SUCCESS;
    }

    /*!
     *  \brief  deserialize extra field of this handle
     *  \param  sraw_data    raw data area that store the serialized data
     *  \return POS_SUCCESS for successfully deserilization
     */
    pos_retval_t __deserialize_extra(void* raw_data) override {
        return POS_SUCCESS;
    }

    /*!
     *  \brief  initialize checkpoint bag of this handle
     *  \note   it must be implemented by different implementations of stateful 
     *          handle, as they might require different allocators and deallocators
     *  \return POS_SUCCESS for successfully initialization
     */
    pos_retval_t init_ckpt_bag() override { 
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
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Memory
 */
class POSHandleManager_CUDA_Memory : public POSHandleManager<POSHandle_CUDA_Memory> {
 public:
    /*!
     *  \brief  base virtual memory address reserved on each device
     */
    static const uint64_t reserved_vm_base;

    /*!
     *  \brief  allocation pointers on each device
     *  \note   map of device index to allocation pointer
     */
    static std::map<int, CUdeviceptr> alloc_ptrs;

    /*!
     *  \brief  allocation granularity of each device
     *  \note   map of device index to allocation granularity
     */
    static std::map<int, uint64_t> alloc_granularities;

    /*!
     *  \brief  identify whether previous cuda memroy hm has finsihed reserved virtual memory space
     *          so that current hm doesn't need to reserve again
     */
    static bool has_finshed_reserved;

    /*!
     *  \brief  constructor
     *  \note   the memory manager is a passthrough manager, which means that the client-side
     *          and server-side handle address are equal
     */
    POSHandleManager_CUDA_Memory(POSHandle_CUDA_Device* device_handle, bool is_restoring);

    /*!
     *  \brief  allocate new mocked CUDA memory within the manager
     *  \param  handle          pointer to the mocked handle of the newly allocated resource
     *  \param  related_handles all related handles for helping allocate the mocked resource
     *                          (note: these related handles might be other types)
     *  \param  size            size of the newly allocated resource
     *  \param  expected_addr   the expected mock addr to allocate the resource (optional)
     *  \param  state_size      size of resource state behind this handle  
     *  \return POS_FAILED_DRAIN for run out of virtual address space; 
     *          POS_SUCCESS for successfully allocation
     */
    pos_retval_t allocate_mocked_resource(
        POSHandle_CUDA_Memory** handle,
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
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
        POS_ASSERT(POSHandleManager_CUDA_Memory::alloc_ptrs.count(device_handle->device_id) == 1);
        POS_ASSERT(POSHandleManager_CUDA_Memory::alloc_granularities.count(device_handle->device_id) == 1);

        // obtain the desired address based on reserved virtual memory space pointer
        alloc_ptr = POSHandleManager_CUDA_Memory::alloc_ptrs[device_handle->device_id];
        
        // no avaialble memory space on device
        if(unlikely((void*)(alloc_ptr) == nullptr)){
            retval = POS_FAILED_DRAIN;
            goto exit;
        }

        // forward the allocation pointer
    #define ROUND_UP(size, alloc_granularity) ((size + alloc_granularity - 1) / alloc_granularity) * alloc_granularity
        aligned_alloc_size = ROUND_UP(state_size, POSHandleManager_CUDA_Memory::alloc_granularities[device_handle->device_id]);
        POSHandleManager_CUDA_Memory::alloc_ptrs[device_handle->device_id] += aligned_alloc_size;
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

    /*!
     *  \brief  allocate and restore handles for provision, for fast restore
     *  \param  amount  amount of handles for pooling
     *  \return POS_SUCCESS for successfully preserving
     */
    pos_retval_t preserve_pooled_handles(uint64_t amount) override {
        return POS_SUCCESS;
    }

    /*!
     *  \brief  restore handle from pool
     *  \param  handle  the handle to be restored
     *  \return POS_SUCCESS for successfully restoring
     *          POS_FAILED for failed pooled restoring, should fall back to normal path
     */
    pos_retval_t try_restore_from_pool(POSHandle_CUDA_Memory* handle) override {
        return POS_FAILED;
    }
};
