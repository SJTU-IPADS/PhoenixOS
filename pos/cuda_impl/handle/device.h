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
 *  \brief  handle for cuda device
 */
class POSHandle_CUDA_Device : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Device(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Device;
    }
    
    /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle_CUDA_Device(void* hm) : POSHandle(hm)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Device;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Device(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Device"); }

    // identifier of the device
    int device_id;

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t __restore() override {
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;
        cudaDeviceProp prop;

        // invoke cudaGetDeviceProperties here to make sure the device is alright
        cuda_rt_retval = cudaGetDeviceProperties(&prop, this->device_id);
        
        if(unlikely(cuda_rt_retval == cudaSuccess)){
            this->mark_status(kPOS_HandleStatus_Active);
        } else {
            POS_WARN_C_DETAIL("failed to restore CUDA device, cudaGetDeviceProperties failed: %d, device_id(%d)", cuda_rt_retval, this->device_id);
            retval = POS_FAILED;
        } 

        return retval;
    }

 protected:
    /*!
     *  \brief  obtain the serilization size of extra fields of specific POSHandle type
     *  \return the serilization size of extra fields of POSHandle
     */
    uint64_t __get_extra_serialize_size() override {
        return (
            /* device_id */                 sizeof(int)   
        );
    }

    /*!
     *  \brief  serialize the extra state of current handle into the binary area
     *  \param  serialized_area  pointer to the binary area
     *  \return POS_SUCCESS for successfully serilization
     */
    pos_retval_t __serialize_extra(void* serialized_area) override {
        pos_retval_t retval = POS_SUCCESS;
        void *ptr = serialized_area;

        POS_CHECK_POINTER(ptr);

        POSUtil_Serializer::write_field(&ptr, &(this->device_id), sizeof(int));
 
        return retval;
    }

    /*!
     *  \brief  deserialize extra field of this handle
     *  \param  sraw_data    raw data area that store the serialized data
     *  \return POS_SUCCESS for successfully deserilization
     */
    pos_retval_t __deserialize_extra(void* raw_data) override {
        pos_retval_t retval = POS_SUCCESS;
        void *ptr = raw_data;

        POS_CHECK_POINTER(ptr);

        POSUtil_Deserializer::read_field(&(this->device_id), &ptr, sizeof(int));

        return retval;
    }
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Device
 */
class POSHandleManager_CUDA_Device : public POSHandleManager<POSHandle_CUDA_Device> {
 public:
    /*!
     *  \brief  constructor
     *  \param  ctx_handle      handle of the default CUDA context to create streams
     *  \param  is_restoring    identify whether current client is under restoring
     *  \note   insert actual #device to the device manager
     *          TBD: mock random number of devices
     */
    POSHandleManager_CUDA_Device(POSHandle_CUDA_Context* ctx_handle, bool is_restoring) : POSHandleManager() {
        int num_device, i;
        POSHandle_CUDA_Device *device_handle;

        /*!
         *  \note  we only create new devices while NOT restoring
         */
        if(is_restoring == false){
            // get number of physical devices on the machine
            if(unlikely(cudaSuccess != cudaGetDeviceCount(&num_device))){
                POS_ERROR_C_DETAIL("failed to call cudaGetDeviceCount");
            }
            if(unlikely(num_device == 0)){
                POS_ERROR_C_DETAIL("no CUDA device detected");
            }

            for(i=0; i<num_device; i++){
                if(unlikely(
                    POS_SUCCESS != this->allocate_mocked_resource(
                        &device_handle,
                        std::map<uint64_t, std::vector<POSHandle*>>({
                            { kPOS_ResourceTypeId_CUDA_Context, {ctx_handle} }
                        })
                    )
                )){
                    POS_ERROR_C_DETAIL("failed to allocate mocked CUDA device in the manager");
                }
                device_handle->device_id = i;
                device_handle->mark_status(kPOS_HandleStatus_Active);
            }

            this->latest_used_handle = this->_handles[0];
        }
    }

    /*!
     *  \brief  allocate new mocked CUDA device within the manager
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
        POSHandle_CUDA_Device** handle,
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *ctx_handle;
        POS_CHECK_POINTER(handle);

        // obtain the context to allocate device
    #if POS_CONF_RUNTIME_EnableDebugCheck
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
            POS_WARN_C("no binded context provided to created the CUDA stream");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
    #endif

        ctx_handle = related_handles[kPOS_ResourceTypeId_CUDA_Context][0];
        POS_CHECK_POINTER(ctx_handle);

        retval = this->__allocate_mocked_resource(handle, true, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA device in the manager");
            goto exit;
        }

        (*handle)->record_parent_handle(ctx_handle);

    exit:
        return retval;
    }

    /*!
     *  \brief  obtain a device handle by given client-side address
     *  \param  client_addr the given client-side address
     *  \param  handle      the resulted handle
     *  \param  offset      pointer to store the offset of the given address from the base address
     *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
     *          POS_SUCCESS for successfully founded
     */
    pos_retval_t get_handle_by_client_addr(void* client_addr, POSHandle_CUDA_Device** handle, uint64_t* offset=nullptr){
        int device_id, i;
        uint64_t device_id_u64;
        POSHandle_CUDA_Device *device_handle;

        // we cast the client address into device id here
        device_id_u64 = (uint64_t)(client_addr);
        device_id = (int)(device_id_u64);

        if(unlikely(device_id >= this->_handles.size())){
            *handle = nullptr;
            return POS_FAILED_NOT_EXIST;
        }

        device_handle = this->_handles[device_id];        
        POS_ASSERT(device_id == device_handle->device_id);

        *handle = device_handle;

        return POS_SUCCESS;
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
    pos_retval_t try_restore_from_pool(POSHandle_CUDA_Device* handle) override {
        return POS_FAILED;
    }
};
