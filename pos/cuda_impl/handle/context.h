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


// forward declaration
class POSHandleManager_CUDA_Device;


/*!
 *  \brief  handle for cuda context
 */
class POSHandle_CUDA_Context final : public POSHandle_CUDA {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  id_             index of this handle in the handle manager list
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Context(void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, size_t state_size_=0);


    /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle_CUDA_Context(void* hm) : POSHandle_CUDA(hm);


    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Context(size_t size_, void* hm, pos_u64id_t id_, size_t state_size_=0);


    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Context"); }

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t __restore() override;


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
 *  \brief   manager for handles of POSHandle_CUDA_Context
 */
class POSHandleManager_CUDA_Context : public POSHandleManager<POSHandle_CUDA_Context> {
 public:
    /*!
     *  \brief  constructor
     *  \param  device_handles  all parent device handles to 
     *  \param  is_restoring    identify whether current client is under restoring
     */
    POSHandleManager_CUDA_Context(std::vector<POSHandleManager_CUDA_Device*> device_handles, bool is_restoring) : POSHandleManager() {
        POSHandle_CUDA_Context *ctx_handle;

        /*!
         *  \note  we only create a new mocked context while NOT restoring
         */
        if(is_restoring == false){
            // allocate mocked context, and setup the actual context address
            if(unlikely(POS_SUCCESS != this->allocate_mocked_resource(
                /* handle */ &ctx_handle,
                /* related_handle */ std::map<uint64_t, std::vector<POSHandle*>>(),
                /* size */ sizeof(CUcontext)
            ))){
                POS_ERROR_C_DETAIL("failed to allocate mocked CUDA context in the manager");
            }

            // record in the manager
            this->_handles.push_back(ctx_handle);
            this->latest_used_handle = this->_handles[0];
        }
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
    pos_retval_t try_restore_from_pool(POSHandle_CUDA_Context* handle) override {
        return POS_FAILED;
    }
};
