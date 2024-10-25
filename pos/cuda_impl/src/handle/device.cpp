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


POSHandle_CUDA_Device::POSHandle_CUDA_Device(void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, size_t state_size_)
    : POSHandle_CUDA(client_addr_, size_, hm, id_, state_size_)
{
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Device;
}


POSHandle_CUDA_Device::POSHandle_CUDA_Device(void* hm) : POSHandle_CUDA(hm)
{
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Device;
}


POSHandle_CUDA_Device::POSHandle_CUDA_Device(size_t size_, void* hm, pos_u64id_t id_, size_t state_size_)
    : POSHandle_CUDA(size_, hm, id_, state_size_)
{
    POS_ERROR_C_DETAIL("shouldn't be called");
}


pos_retval_t POSHandle_CUDA_Device::__add(uint64_t version_id, uint64_t stream_id){
    return POS_SUCCESS;
}


pos_retval_t POSHandle_CUDA_Device::__commit(uint64_t version_id, uint64_t stream_id, bool from_cache, bool is_sync, std::string ckpt_dir){
    return this->__persist(nullptr, ckpt_dir, stream_id);;
}


pos_retval_t POSHandle_CUDA_Device::__generate_protobuf_binary(google::protobuf::Message** binary, google::protobuf::Message** base_binary){
    pos_retval_t retval = POS_SUCCESS;
    pos_protobuf::Bin_POSHandle_CUDA_Device *cuda_device_binary;

    POS_CHECK_POINTER(binary);
    POS_CHECK_POINTER(base_binary);

    cuda_device_binary = new pos_protobuf::Bin_POSHandle_CUDA_Device();
    POS_CHECK_POINTER(cuda_device_binary);

    *binary = reinterpret_cast<google::protobuf::Message*>(cuda_device_binary);
    POS_CHECK_POINTER(*binary);
    *base_binary = cuda_device_binary->mutable_base();
    POS_CHECK_POINTER(*base_binary);

    // serialize handle specific fields
    /* currently nothing */

    return retval;
}


pos_retval_t POSHandle_CUDA_Device::__restore(){
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;
    cudaDeviceProp prop;

    // invoke cudaGetDeviceProperties here to make sure the device is alright
    cuda_rt_retval = cudaGetDeviceProperties(&prop, this->id);
    
    if(unlikely(cuda_rt_retval == cudaSuccess)){
        this->mark_status(kPOS_HandleStatus_Active);
    } else {
        POS_WARN_C_DETAIL("failed to restore CUDA device, cudaGetDeviceProperties failed: %d, device_id(%d)", cuda_rt_retval, this->id);
        retval = POS_FAILED;
    } 

    return retval;
}


pos_retval_t POSHandleManager_CUDA_Device::init(std::map<uint64_t, std::vector<POSHandle*>> related_handles){
    pos_retval_t retval = POS_SUCCESS;
    int num_device, i;
    cudaError_t cuda_rt_retval;

    POS_ASSERT(related_handles.size() == 0);

    // get number of physical devices on the machine
    if(unlikely(cudaSuccess != (
        cuda_rt_retval = cudaGetDeviceCount(&num_device)
    ))){
        POS_WARN_C("failed to call cudaGetDeviceCount: retval(%d)", cuda_rt_retval);
        retval = POS_FAILED_DRIVER;
        goto exit;
    }
    if(unlikely(num_device == 0)){ 
        POS_WARN_C("no cuda device, POS won't be enabled");
        retval = POS_FAILED_DRIVER;
        goto exit;
    }

    for(i=0; i<num_device; i++){
        if(unlikely(
            POS_SUCCESS != this->allocate_mocked_resource(
                &device_handle,
                std::map<uint64_t, std::vector<POSHandle*>>({})
                /* size */ 1,
                /* use_expected_addr */ true
                /* expected_addr */ reinterpret_cast<uint64_t>(i),
                /* state_size */ 0
            )
        )){
            POS_ERROR_C_DETAIL("failed to allocate mocked CUDA device in the manager");
        }
        device_handle->mark_status(kPOS_HandleStatus_Active);
    }

exit:
    return retval;
}


pos_retval_t POSHandleManager_CUDA_Device::allocate_mocked_resource(
    POSHandle_CUDA_Device** handle,
    std::map<uint64_t, std::vector<POSHandle*>> related_handles,
    size_t size = kPOS_HandleDefaultSize,
    bool use_expected_addr = false,
    uint64_t expected_addr = 0,
    uint64_t state_size = 0
){
    pos_retval_t retval = POS_SUCCESS;
    POSHandle *ctx_handle;
    POS_CHECK_POINTER(handle);

    retval = this->__allocate_mocked_resource(handle, size, use_expected_addr, expected_addr, state_size);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to allocate mocked CUDA device in the manager");
        goto exit;
    }

exit:
    return retval;
}


pos_retval_t POSHandleManager_CUDA_Device::get_handle_by_client_addr(void* client_addr, POSHandle_CUDA_Device** handle, uint64_t* offset){
    pos_retval_t retval = POS_SUCCESS;
    POSHandle_CUDA_Device *device_handle = nullptr;

    device_handle = this->get_handle_by_id((uint64_t)(client_addr));

    if(device_handle != nullptr){
        *handle = device_handle;
    } else {
        retval = POS_FAILED_NOT_EXIST;
    }

    return retval;
}


pos_retval_t POSHandleManager_CUDA_Device::preserve_pooled_handles(uint64_t amount){
    return POS_SUCCESS;
}


pos_retval_t POSHandleManager_CUDA_Device::try_restore_from_pool(POSHandle_CUDA_Device* handle){
    return POS_FAILED;
}
