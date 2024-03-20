#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include <sys/resource.h>
#include <stdint.h>
#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/handle.h"
#include "pos/include/utils/serializer.h"

#include "pos/cuda_impl/handle.h"


/*!
 *  \brief  handle for cuda memory
 */
class POSHandle_CUDA_Memory : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Memory(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Memory;

        // initialize checkpoint bag
        if(unlikely(POS_SUCCESS != this->init_ckpt_bag())){
            POS_ERROR_C_DETAIL("failed to inilialize checkpoint bag");
        }
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
    POSHandle_CUDA_Memory(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_)
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
     *  \brief  checkpoint the state of the resource behind this handle (sync)
     *  \note   only handle of stateful resource should implement this method
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t checkpoint_sync(uint64_t version_id, uint64_t stream_id=0) const override { 
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;
        POSCheckpointSlot* ckpt_slot;

        struct rusage s_r_usage, e_r_usage;
        uint64_t s_tick = 0, e_tick = 0;
        double duration_us = 0;
        
        // apply new checkpoint slot
        if(unlikely(
            POS_SUCCESS != this->ckpt_bag->apply_checkpoint_slot</* on_device */false>
                                        (/* version */ version_id, /* ptr */ &ckpt_slot, /* force_overwrite */ false)
        )){
            POS_WARN_C("failed to apply checkpoint slot");
            retval = POS_FAILED;
            goto exit;
        }

        // checkpoint
        cuda_rt_retval = cudaMemcpy(
            /* dst */ ckpt_slot->expose_pointer(), 
            /* src */ this->server_addr,
            /* size */ this->state_size,
            /* kind */ cudaMemcpyDeviceToHost
        );

        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to checkpoint memory handle: server_addr(%p), retval(%d)",
                this->server_addr, cuda_rt_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    
    exit:
        return retval;
    }

    /*!
     *  \brief  checkpoint the state of the resource behind this handle (async)
     *  \note   only handle of stateful resource should implement this method
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t checkpoint_async(uint64_t version_id, uint64_t stream_id=0) const override { 
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;
        POSCheckpointSlot* ckpt_slot;

        struct rusage s_r_usage, e_r_usage;
        uint64_t s_tick = 0, e_tick = 0;
        double duration_us = 0;
        
        // apply new host-side checkpoint slot
        if(unlikely(
            POS_SUCCESS != this->ckpt_bag->apply_checkpoint_slot</* on_device */ false>
                                        (/* version */ version_id, /* ptr */ &ckpt_slot, /* force_overwrite */ false)
        )){
            POS_WARN_C("failed to apply host-side checkpoint slot");
            retval = POS_FAILED;
            goto exit;
        }

        // checkpoint
        // TODO: takes long time
        // if(unlikely(getrusage(RUSAGE_SELF, &s_r_usage) != 0)){
        //     POS_ERROR_DETAIL("failed to call getrusage");
        // }
        // s_tick = POSUtilTimestamp::get_tsc();
        cuda_rt_retval = cudaMemcpyAsync(
            /* dst */ ckpt_slot->expose_pointer(), 
            /* src */ this->server_addr,
            /* size */ this->state_size,
            /* kind */ cudaMemcpyDeviceToHost,
            /* stream */ (cudaStream_t)(stream_id)
        );
        // e_tick = POSUtilTimestamp::get_tsc();
        // if(unlikely(getrusage(RUSAGE_SELF, &e_r_usage) != 0)){
        //     POS_ERROR_DETAIL("failed to call getrusage");
        // }

        // duration_us = POS_TSC_RANGE_TO_USEC(e_tick, s_tick);

        // POS_LOG(
        //     "copy duration: %lf us, size: %lu Bytes, bandwidth: %lf Mbps, page fault: %ld (major), %ld (minor)",
        //     duration_us,
        //     this->state_size,
        //     (double)(this->state_size) / duration_us,
        //     e_r_usage.ru_majflt - s_r_usage.ru_majflt,
        //     e_r_usage.ru_minflt - s_r_usage.ru_minflt
        // );

        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to checkpoint memory handle: server_addr(%p), retval(%d)",
                this->server_addr, cuda_rt_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    
    exit:
        return retval;
    }

    /*!
     *  \brief  checkpoint the state of the resource behind this handle to on-device memory (async)
     *  \note   only handle of stateful resource should implement this method
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t checkpoint_pipeline_add_async(uint64_t version_id, uint64_t stream_id=0) const override { 
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

    exit:
        return retval;
    }

    /*!
     *  \brief  commit the on-device memory to host-side checkpoint area (async)
     *  \note   only handle of stateful resource should implement this method
     *  \param  version_id  version of the checkpoint to be commit
     *  \param  stream_id   index of the stream to do this commit
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t checkpoint_pipeline_commit_async(uint64_t version_id, uint64_t stream_id=0) const override { 
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;
        POSCheckpointSlot *host_ckpt_slot, *dev_ckpt_slot;
        uint64_t ckpt_size;
        uint64_t s_tick, e_tick;

        // step 1: get device-side checkpoint slot
        if(unlikely(
            POS_SUCCESS != this->ckpt_bag->get_checkpoint_slot</* on_device */ true>
                                (/* ckpt_slot */ &dev_ckpt_slot, /* size */ ckpt_size, /* version */ version_id)
        )){
            POS_WARN_C(
                "failed to commit checkpoint due to unexist device-side checkpoint: client_addr(%p), verion(%lu)",
                this->client_addr, version_id
            );
            retval = POS_FAILED;
            goto exit;
        }

        // step 2: apply new host-side checkpoint slot
        if(unlikely(
            POS_SUCCESS != this->ckpt_bag->apply_checkpoint_slot</* on_device */ false>
                                        (/* version */ version_id, /* ptr */ &host_ckpt_slot, /* force_overwrite */ true)
        )){
            POS_WARN_C("failed to apply host-side checkpoint slot");
            retval = POS_FAILED;
            goto exit;
        }

        // step 3: memcpy from device to host
        cuda_rt_retval = cudaMemcpyAsync(
            /* dst */ host_ckpt_slot->expose_pointer(), 
            /* src */ dev_ckpt_slot->expose_pointer(),
            /* size */ this->state_size,
            /* kind */ cudaMemcpyDeviceToHost,
            /* stream */ (cudaStream_t)(stream_id)
        );
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to commit device-side checkpoint: client_addr(%p), retval(%d)",
                this->client_addr, cuda_rt_retval
            );
            retval = POS_FAILED;

            // invalidate the applied host-side checkpoint area
            if(unlikely(
                POS_SUCCESS != this->ckpt_bag->invalidate_by_version</* on_device */ false>(/* version */ version_id)
            )){
                POS_WARN_C(
                    "failed to invalidate host-side checkpoint: client_addr(%p), version(%lu)",
                    this->client_addr, version_id
                );
            }

            goto exit;
        }

        // step 4: invalidate device-side checkpoint
        if(unlikely(
            POS_SUCCESS != this->ckpt_bag->invalidate_by_version</* on_device */ true>(/* version */ version_id)
        )){
            POS_WARN_C(
                "failed to invalidate device-side checkpoint: client_addr(%p), version(%lu)",
                this->client_addr, version_id
            );
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        return retval;
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Memory"); }

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t restore() override {
        pos_retval_t retval = POS_SUCCESS;
        
        cudaError_t cuda_rt_retval;
        CUresult cuda_dv_retval;
        POSHandle_CUDA_Device *device_handle;
        
        void *rt_ptr;

        CUmemAllocationProp prop = {};
        CUmemGenericAllocationHandle hdl;
        CUmemAccessDesc accessDesc;
        CUdeviceptr ptr, req_ptr;
        size_t sz, aligned_sz;

        POS_ASSERT(this->parent_handles.size() == 1);
        POS_CHECK_POINTER(device_handle = static_cast<POSHandle_CUDA_Device*>(this->parent_handles[0]));

        if(likely(this->client_addr != 0)){
            POS_ASSERT(this->client_addr == this->server_addr);
        
            // obtain round up allocation size
            prop.type = CU_MEM_ALLOCATION_TYPE_PINNED;
            prop.location.type = CU_MEM_LOCATION_TYPE_DEVICE;
            prop.location.id = device_handle->device_id;
            cuda_dv_retval = cuMemGetAllocationGranularity(&aligned_sz, &prop, CU_MEM_ALLOC_GRANULARITY_MINIMUM);
            if(unlikely(cuda_dv_retval != CUDA_SUCCESS)){
                retval = POS_FAILED;
                POS_WARN_C_DETAIL("failed to restore CUDA memory, cuMemGetAllocationGranularity failed: %d", cuda_dv_retval);
                goto exit;
            }

        #define ROUND_UP(size, aligned_size)    ((size + aligned_size - 1) / aligned_size) * aligned_size;
            sz = ROUND_UP(this->state_size, aligned_sz);
        #undef ROUND_UP

            // allocate
            req_ptr = (CUdeviceptr)(this->client_addr);
            cuda_dv_retval = cuMemAddressReserve(&ptr, sz, 0ULL, req_ptr, 0ULL);
            if(unlikely(cuda_dv_retval != CUDA_SUCCESS)){
                retval = POS_FAILED;
                POS_WARN_C_DETAIL("failed to restore CUDA memory, cuMemAddressReserve failed: %d", cuda_dv_retval);
                goto exit;
            }
            cuda_dv_retval = cuMemCreate(&hdl, sz, &prop, 0);
            if(unlikely(cuda_dv_retval != CUDA_SUCCESS)){
                retval = POS_FAILED;
                POS_WARN_C_DETAIL("failed to restore CUDA memory, cuMemCreate failed: %d", cuda_dv_retval);
                goto exit;
            }
            cuda_dv_retval = cuMemMap(ptr, sz, 0ULL, hdl, 0ULL);
            if(unlikely(cuda_dv_retval != CUDA_SUCCESS)){
                retval = POS_FAILED;
                POS_WARN_C_DETAIL("failed to restore CUDA memory, cuMemMap failed: %d", cuda_dv_retval);
                goto exit;
            }
            accessDesc.location = prop.location;
            accessDesc.flags = CU_MEM_ACCESS_FLAGS_PROT_READWRITE;
            cuda_dv_retval = cuMemSetAccess(ptr, sz, &accessDesc, 1ULL);
            if(unlikely(cuda_dv_retval != CUDA_SUCCESS)){
                retval = POS_FAILED;
                POS_WARN_C_DETAIL("failed to restore CUDA memory, cuMemSetAccess failed: %d", cuda_dv_retval);
                goto exit;
            }

            POS_ASSERT((uint64_t)(ptr) == (uint64_t)(req_ptr));
        } else {
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
     *  \brief  constructor
     *  \note   the memory manager is a passthrough manager, which means that the client-side
     *          and server-side handle address are equal
     */
    POSHandleManager_CUDA_Memory() : POSHandleManager(/* passthrough */ true, /* is_stateful */ true) {}

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
        POSHandle *device_handle;

        POS_CHECK_POINTER(handle);

        // obtain the device to allocate buffer
    #if POS_ENABLE_DEBUG_CHECK
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Device) == 0)){
            POS_WARN_C("no binded device provided to create the CUDA memory");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
    #endif
    
        device_handle = related_handles[kPOS_ResourceTypeId_CUDA_Device][0];

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA memory in the manager");
            goto exit;
        }

        (*handle)->record_parent_handle(device_handle);

    exit:
        return retval;
    }
};
