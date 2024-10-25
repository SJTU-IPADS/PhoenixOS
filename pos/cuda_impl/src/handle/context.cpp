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


POSHandle_CUDA_Context::POSHandle_CUDA_Context(
    void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, size_t state_size_
)
    : POSHandle_CUDA(client_addr_, size_, hm, id_, state_size_)
{
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Context;
}


POSHandle_CUDA_Context::POSHandle_CUDA_Context(void* hm) : POSHandle_CUDA(hm){
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Context;
}


POSHandle_CUDA_Context(size_t size_, void* hm, pos_u64id_t id_, size_t state_size_)
    : POSHandle_CUDA(size_, hm, id_, state_size_)
{
    POS_ERROR_C_DETAIL("shouldn't be called");
}


pos_retval_t POSHandle_CUDA_Context::__restore(){
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_res;
    CUresult cuda_dv_res;
    CUcontext pctx;

    // TODO: this function is wrong, we need to restore on correct device
    //      find device id from parent handle

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
