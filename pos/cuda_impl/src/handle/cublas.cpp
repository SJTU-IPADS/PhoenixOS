#include <iostream>

#include <stdint.h>
#include <cuda.h>
#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#include <cublas_api.h>
#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/handle.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/cublas.h"
#include "pos/cuda_impl/proto/cublas.pb.h"


POSHandle_cuBLAS_Context::POSHandle_cuBLAS_Context(void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, uint64_t state_size)
    : POSHandle_CUDA(client_addr_, size_, hm, id_, state_size), lastest_used_stream(nullptr)
{
    this->resource_type_id = kPOS_ResourceTypeId_cuBLAS_Context;
}


POSHandle_cuBLAS_Context::POSHandle_cuBLAS_Context(size_t size_, void* hm, pos_u64id_t id_, uint64_t state_size) 
    : POSHandle_CUDA(size_, hm, id_, state_size), lastest_used_stream(nullptr)
{
    POS_ERROR_C_DETAIL("shouldn't be called");
}


POSHandle_cuBLAS_Context::POSHandle_cuBLAS_Context(void* hm) 
    : POSHandle_CUDA(hm), lastest_used_stream(nullptr)
{
    this->resource_type_id = kPOS_ResourceTypeId_cuBLAS_Context;
}


pos_retval_t POSHandle_cuBLAS_Context::__add(uint64_t version_id, uint64_t stream_id){
    return POS_SUCCESS;
}


pos_retval_t POSHandle_cuBLAS_Context::__commit(uint64_t version_id, uint64_t stream_id, bool from_cache, bool is_sync, std::string ckpt_dir){
    return this->__persist(nullptr, ckpt_dir, stream_id);
}


pos_retval_t POSHandle_cuBLAS_Context::__generate_protobuf_binary(google::protobuf::Message** binary, google::protobuf::Message** base_binary){
    pos_retval_t retval = POS_SUCCESS;
    pos_protobuf::Bin_POSHandle_cuBLAS_Context *cublas_context_binary;

    POS_CHECK_POINTER(binary);
    POS_CHECK_POINTER(base_binary);

    cublas_context_binary = new pos_protobuf::Bin_POSHandle_cuBLAS_Context();
    POS_CHECK_POINTER(cublas_context_binary);

    *binary = reinterpret_cast<google::protobuf::Message*>(cublas_context_binary);
    POS_CHECK_POINTER(*binary);
    *base_binary = cublas_context_binary->mutable_base();
    POS_CHECK_POINTER(*base_binary);

    // serialize handle specific fields
    /* currently nothing */

    return retval;
}


pos_retval_t POSHandle_cuBLAS_Context::__restore(){
    pos_retval_t retval = POS_SUCCESS;
    cublasHandle_t actual_handle;
    cublasStatus_t cublas_retval;
    POSHandle *stream_handle;

    POS_ASSERT(this->parent_handles.size() == 1);
    POS_CHECK_POINTER(stream_handle = this->parent_handles[0]);

    cublas_retval = cublasCreate_v2(&actual_handle);
    if(unlikely(CUBLAS_STATUS_SUCCESS != cublas_retval)){
        POS_WARN_C_DETAIL("failed to restore cublas context, failed to create: %d", cublas_retval);
        retval = POS_FAILED;
        goto exit;   
    }

    this->set_server_addr((void*)(actual_handle));
    this->mark_status(kPOS_HandleStatus_Active);

    cublas_retval = cublasSetStream(actual_handle, static_cast<cudaStream_t>(stream_handle->server_addr));
    if(unlikely(CUBLAS_STATUS_SUCCESS != cublas_retval)){
        POS_WARN_C_DETAIL("failed to restore cublas context, failed to pin to parent stream: %d", cublas_retval);
        retval = POS_FAILED;
        goto exit;   
    }

exit:
    return retval;
}


pos_retval_t POSHandleManager_cuBLAS_Context::init(std::map<uint64_t, std::vector<POSHandle*>> related_handles){
    pos_retval_t retval = POS_SUCCESS;

    /* nothing */

exit:
    return retval;
}


pos_retval_t POSHandleManager_cuBLAS_Context::allocate_mocked_resource(
    POSHandle_cuBLAS_Context** handle,
    std::map<uint64_t, std::vector<POSHandle*>> related_handles,
    size_t size,
    bool use_expected_addr,
    uint64_t expected_addr,
    uint64_t state_size
){
    pos_retval_t retval = POS_SUCCESS;
    POSHandle *stream_handle;
    POS_CHECK_POINTER(handle);

    POS_ASSERT(related_handles.count(kPOS_ResourceTypeId_CUDA_Stream) == 1);
    POS_ASSERT(related_handles[kPOS_ResourceTypeId_CUDA_Stream].size() == 1);
    POS_CHECK_POINTER(stream_handle = related_handles[kPOS_ResourceTypeId_CUDA_Stream][0]);

    retval = this->__allocate_mocked_resource(
        /* handle */ handle,
        /* size */ size,
        /* use_expected_addr */ use_expected_addr,
        /* expected_addr */ expected_addr,
        /* state_size */ state_size
    );
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to allocate mocked cuBLAS context in the manager");
        goto exit;
    }

    POS_CHECK_POINTER(*handle);
    (*handle)->record_parent_handle(stream_handle);

exit:
    return retval;
}


pos_retval_t POSHandleManager_cuBLAS_Context::preserve_pooled_handles(uint64_t amount){
    return POS_SUCCESS;
}


pos_retval_t POSHandleManager_cuBLAS_Context::try_restore_from_pool(POSHandle_cuBLAS_Context* handle){
    return POS_FAILED;
}
