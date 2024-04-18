#pragma once

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

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
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Memory(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Memory;

    #if POS_CKPT_OPT_LEVEL > 0 || POS_MIGRATION_OPT_LEVEL > 0
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


 protected:
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
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t __commit(uint64_t version_id, uint64_t stream_id=0, bool from_cache=false, bool is_sync=false) const override { 
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
        
    exit:
        return retval;
    }

    /*!
     *  \brief  add the state of the resource behind this handle to on-device memory
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \note   the add process must be sync
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t __add(uint64_t version_id, uint64_t stream_id=0) const override {
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
    POSHandleManager_CUDA_Memory(POSHandle_CUDA_Device* device_handle, bool is_restoring) : POSHandleManager(/* passthrough */ true, /* is_stateful */ true) {
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
        if(has_finshed_reserved == true){
            goto exit;
        }
    
        // obtain the number of devices
        if(unlikely(cudaSuccess != cudaGetDeviceCount(&num_device))){
            POS_ERROR_C_DETAIL("failed to call cudaGetDeviceCount");
        }

        // we reserve virtual memory space on each device
        __reserve_device_vm_space(0);
        this->backup_base_memory = __malloc_huge_backup_memory_for_migration(1);

        // setup peer access of all devices
        for(i=0; i<num_device; i++){
            for(j=0; j<num_device; j++){
                if(unlikely(i == j)){
                    continue;
                }
                __set_peer_access(i, j);
            }
        }

        if(is_restoring == false){
            POS_CHECK_POINTER(device_handle);
            // switch back to origin default device
            if(unlikely(cudaSuccess != cudaSetDevice(device_handle->device_id))){
                POS_ERROR_DETAIL("failed to call cudaSetDevice");
            }
        }    

        has_finshed_reserved = true;

    exit:
        ;
    }

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
    #if POS_ENABLE_DEBUG_CHECK
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
