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

#include <stdint.h>
#include <cuda.h>
#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#include <cublas_api.h>

#include "pos/include/common.h"
#include "pos/include/handle.h"
#include "pos/include/utils/serializer.h"

#include "pos/cuda_impl/handle.h"


/*!
 *  \brief  handle for cuBLAS context
 */
class POSHandle_cuBLAS_Context : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size      size of resource state behind this handle  
     */
    POSHandle_cuBLAS_Context(void *client_addr_, size_t size_, void* hm, uint64_t state_size=0)
        : POSHandle(client_addr_, size_, hm, state_size), lastest_used_stream(nullptr)
    {
        this->resource_type_id = kPOS_ResourceTypeId_cuBLAS_Context;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_cuBLAS_Context(size_t size_, void* hm, uint64_t state_size=0) 
        : POSHandle(size_, hm, state_size), lastest_used_stream(nullptr)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

     /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle_cuBLAS_Context(void* hm) 
        : POSHandle(hm), lastest_used_stream(nullptr)
    {
        this->resource_type_id = kPOS_ResourceTypeId_cuBLAS_Context;
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("cuBLAS Context"); }

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t __restore() override {
        pos_retval_t retval = POS_SUCCESS;
        cublasHandle_t actual_handle;
        cublasStatus_t cublas_retval;

        cublas_retval = cublasCreate_v2(&actual_handle);
        if(likely(CUBLAS_STATUS_SUCCESS == cublas_retval)){
            this->set_server_addr((void*)(actual_handle));
            this->mark_status(kPOS_HandleStatus_Active);
        } else {
            retval = POS_FAILED;
            POS_WARN_C_DETAIL("failed to restore cublas context: %d", cublas_retval);
        }

        // TODO: restore the cuBLAS context on corresponding used stream

        return retval;
    }

    POSHandle *lastest_used_stream;
    
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
     *  \param  raw_data    raw data area that store the serialized data
     *  \return POS_SUCCESS for successfully deserilization
     */
    pos_retval_t __deserialize_extra(void* raw_data) override {
        return POS_SUCCESS;
    }
};


/*!
 *  \brief   manager for handles of POSHandle_cuBLAS_Context
 */
class POSHandleManager_cuBLAS_Context : public POSHandleManager<POSHandle_cuBLAS_Context> {
 public:
    POSHandleManager_cuBLAS_Context() : POSHandleManager() {
    #if POS_CONF_EVAL_RstEnableContextPool == 1
        this->preserve_pooled_handles(8);
    #endif // POS_CONF_EVAL_RstEnableContextPool
    }

    /*!
     *  \brief  allocate new mocked cuBLAS context within the manager
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
        POSHandle_cuBLAS_Context** handle,
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *context_handle;
        POS_CHECK_POINTER(handle);

        // obtain the context to allocate buffer
    #if POS_CONF_RUNTIME_EnableDebugCheck
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
            POS_WARN_C("no binded context provided to created the CUDA module");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
    #endif

        context_handle = related_handles[kPOS_ResourceTypeId_CUDA_Context][0];

        retval = this->__allocate_mocked_resource(handle, true, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked cuBLAS context in the manager");
            goto exit;
        }
        
        (*handle)->record_parent_handle(context_handle);

    exit:
        return retval;
    }
};
