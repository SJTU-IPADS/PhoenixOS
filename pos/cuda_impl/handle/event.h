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
 *  \brief  handle for cuda event
 */
class POSHandle_CUDA_Event : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  id_             index of this handle in the handle manager list
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Event(void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, id_, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Event;
    }

    /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle_CUDA_Event(void* hm) : POSHandle(hm)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Event;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Event(size_t size_, void* hm, pos_u64id_t id_, size_t state_size_=0)
        : POSHandle(size_, hm, id_, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Event"); }

    int flags;

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t __restore() override {
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_res;
        cudaEvent_t ptr;

        cuda_rt_res = cudaEventCreateWithFlags(&ptr, this->flags);
        if(likely(cuda_rt_res == cudaSuccess)){
            this->set_server_addr((void*)(ptr));
            this->mark_status(kPOS_HandleStatus_Active);
        } else {
            retval = POS_FAILED;
            POS_WARN_C_DETAIL("failed to restore CUDA event: %d", cuda_rt_res);
        }

    exit:
        return retval;
    }

 protected:
    /*!
     *  \brief  obtain the serilization size of extra fields of specific POSHandle type
     *  \return the serilization size of extra fields of POSHandle
     */
    uint64_t __get_extra_serialize_size() override {
        return (
            /* flags */         sizeof(int)
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

        POSUtil_Serializer::write_field(&ptr, &(this->flags), sizeof(int));

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

        POSUtil_Deserializer::read_field(&(this->flags), &ptr, sizeof(int));

        return retval;
    }
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Event
 */
class POSHandleManager_CUDA_Event : public POSHandleManager<POSHandle_CUDA_Event> {
 public:
    /*!
     *  \brief  constructor
     */
    POSHandleManager_CUDA_Event() : POSHandleManager() {}
};
