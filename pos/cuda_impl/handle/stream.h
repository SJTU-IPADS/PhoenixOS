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
 *  \brief  handle for cuda stream
 */
class POSHandle_CUDA_Stream : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Stream(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_), is_capturing(false)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Stream;
    }

    /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle_CUDA_Stream(void* hm) : POSHandle(hm)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Stream;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Stream(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_), is_capturing(false)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Stream"); }

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t __restore() override {
        cudaError_t cuda_rt_res;
        cudaStream_t stream_addr;

        if((cuda_rt_res = cudaStreamCreate(&stream_addr)) != cudaSuccess){
            POS_ERROR_C_DETAIL("cudaStreamCreate failed: %d", cuda_rt_res);
        }

        this->set_server_addr((void*)(stream_addr));
        this->mark_status(kPOS_HandleStatus_Active);

        return POS_SUCCESS;
    }

    bool is_capturing;

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
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Stream
 */
class POSHandleManager_CUDA_Stream : public POSHandleManager<POSHandle_CUDA_Stream> {
 public:
    /*!
     *  \brief  constructor
     *  \param  ctx_handle      handle of the default CUDA context to create streams
     *  \param  is_restoring    identify whether current client is under restoring
     */
    POSHandleManager_CUDA_Stream(POSHandle_CUDA_Context* ctx_handle, bool is_restoring) : POSHandleManager() {
        POSHandle_CUDA_Stream *stream_handle;
    
        /*!
         *  \note  we only create a new stream while NOT restoring
         */
        if(is_restoring == false){
            // allocate mocked stream for execute computation
            if(unlikely(POS_SUCCESS != this->allocate_mocked_resource(
                /* handle */ &stream_handle,
                /* related_handle */ std::map<uint64_t, std::vector<POSHandle*>>({
                    { kPOS_ResourceTypeId_CUDA_Context, {ctx_handle} }
                }),
                /* size */ sizeof(CUstream),
                /* expected_addr */ 0
            ))){
                POS_ERROR_C_DETAIL("failed to allocate mocked CUDA stream in the manager");
            }
            
            /*!
            *  \note   we won't use the default stream, and we will create a new non-default stream 
            *          within the worker thread, so that we can achieve overlap checkpointing
            */
            // stream_handle->set_server_addr((void*)(0));
            // stream_handle->mark_status(kPOS_HandleStatus_Active);
            
            // record in the manager
            this->_handles.push_back(stream_handle);
            this->latest_used_handle = this->_handles[0];

        #if POS_ENABLE_CONTEXT_POOL == 1
            this->preserve_pooled_handles(8);
        #endif // POS_ENABLE_CONTEXT_POOL
        }
    }

    /*!
     *  \brief  allocate new mocked CUDA stream within the manager
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
        POSHandle_CUDA_Stream** handle,
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *ctx_handle;

        POS_CHECK_POINTER(handle);

        // obtain the context to allocate buffer
    #if POS_ENABLE_DEBUG_CHECK
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
            POS_WARN_C("failed to allocate mocked CUDA stream in the manager");
            goto exit;
        }

        (*handle)->record_parent_handle(ctx_handle);

    exit:
        return retval;
    }

    /*!
     *  \brief  obtain a stream handle by given client-side address
     *  \param  client_addr the given client-side address
     *  \param  handle      the resulted handle
     *  \param  offset      pointer to store the offset of the given address from the base address
     *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
     *          POS_SUCCESS for successfully founded
     */
    pos_retval_t get_handle_by_client_addr(void* client_addr, POSHandle_CUDA_Stream** handle, uint64_t* offset=nullptr){
        // the client-side address of the default stream would be nullptr in CUDA, we do some hacking here
        if(likely(client_addr == 0)){
            *handle = this->_handles[0];
            return POS_SUCCESS;
        } else {
            return this->__get_handle_by_client_addr(client_addr, handle, offset);
        }
    }
};
