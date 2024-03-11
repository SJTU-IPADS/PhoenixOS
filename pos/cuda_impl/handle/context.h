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
 *  \brief  handle for cuda context
 */
class POSHandle_CUDA_Context : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Context(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Context;
    }

    /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle_CUDA_Context(void* hm) : POSHandle(hm)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Context;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Context(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Context"); }

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t restore() override {
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_res;
        CUresult cuda_dv_res;
        CUcontext pctx;

        /*!
         *  \note   make sure runtime API is initialized
         *          if we don't do this and use the driver API, it might be unintialized
         */
        if((cuda_rt_res = cudaSetDevice(0)) != cudaSuccess){
            retval = POS_FAILED;
            POS_WARN_C_DETAIL("failed to restore CUDA context, cudaSetDevice failed: %d", cuda_rt_res);
            goto exit;
        }
        cudaDeviceSynchronize();

        // obtain current cuda context
        if((cuda_dv_res = cuCtxGetCurrent(&pctx)) != CUDA_SUCCESS){
            retval = POS_FAILED;
            POS_WARN_C_DETAIL("failed to restore CUDA context, cuCtxGetCurrent failed: %d", cuda_dv_res);
            goto exit;
        }

        this->set_server_addr((void*)pctx);
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
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Context
 */
class POSHandleManager_CUDA_Context : public POSHandleManager<POSHandle_CUDA_Context> {
 public:
    /*!
     *  \brief  constructor
     *  \param  is_restoring    identify whether current client is under restoring
     */
    POSHandleManager_CUDA_Context(bool is_restoring) : POSHandleManager() {
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
};
