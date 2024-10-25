#include <iostream>
#include <string>
#include <cstdlib>

#include <sys/resource.h>
#include <stdint.h>
#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/handle.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/stream.h"
#include "pos/cuda_impl/proto/stream.pb.h"


POSHandle_CUDA_Stream(void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, size_t state_size_)
    : POSHandle_CUDA(client_addr_, size_, hm, id_, state_size_)
{
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Stream;
}


POSHandle_CUDA_Stream::POSHandle_CUDA_Stream(void* hm) : POSHandle_CUDA(hm)
{
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Stream;
}


POSHandle_CUDA_Stream::POSHandle_CUDA_Stream(size_t size_, void* hm, pos_u64id_t id_, size_t state_size_=0)
    : POSHandle_CUDA(size_, hm, id_, state_size_)
{
    POS_ERROR_C_DETAIL("shouldn't be called");
}


pos_retval_t POSHandle_CUDA_Stream::__add(uint64_t version_id, uint64_t stream_id){
    return POS_SUCCESS;
}


pos_retval_t POSHandle_CUDA_Stream::__commit(
    uint64_t version_id, uint64_t stream_id, bool from_cache, bool is_sync, std::string ckpt_dir
){
    // TODO: currently we not supporting graph capture mode for stream, should be supported later
    return this->__persist(ckpt_slots[0], ckpt_dir, stream_id);
}


pos_retval_t POSHandle_CUDA_Stream::__generate_protobuf_binary(google::protobuf::Message** binary, google::protobuf::Message** base_binary){
    pos_retval_t retval = POS_SUCCESS;
    pos_protobuf::Bin_POSHandle_CUDA_Stream *cuda_stream_binary;

    POS_CHECK_POINTER(binary);
    POS_CHECK_POINTER(base_binary);

    cuda_stream_binary = new pos_protobuf::Bin_POSHandle_CUDA_Stream();
    POS_CHECK_POINTER(cuda_stream_binary);

    *binary = reinterpret_cast<google::protobuf::Message*>(cuda_stream_binary);
    POS_CHECK_POINTER(*binary);
    *base_binary = cuda_stream_binary->mutable_base();
    POS_CHECK_POINTER(*base_binary);

    // serialize handle specific fields
    /* currently nothing */

    return retval;
}


pos_retval_t POSHandle_CUDA_Stream::__restore(){
    cudaError_t cuda_rt_res;
    cudaStream_t stream_addr;

    // TODO: switch to corresponding context
    //      we can write a genertic context
    //      switch framework, but not now

    if((cuda_rt_res = cudaStreamCreate(&stream_addr)) != cudaSuccess){
        POS_WARN_C("cudaStreamCreate failed: %d", cuda_rt_res);
        retval = POS_FAILED_DRIVER;
        goto exit;
    }
    this->set_server_addr((void*)(stream_addr));
    this->mark_status(kPOS_HandleStatus_Active);

    // TODO: switch out

exit:
    return retval;
}


pos_retval_t POSHandleManager_CUDA_Stream::init(std::map<uint64_t, std::vector<POSHandle*>> related_handles){
    // allocate mocked stream for execute computation
    if(unlikely(POS_SUCCESS != this->allocate_mocked_resource(
        /* handle */ &stream_handle,
        /* related_handle */ std::map<uint64_t, std::vector<POSHandle*>>({
            { kPOS_ResourceTypeId_CUDA_Context, {ctx_handle} }
        }),
        /* size */ sizeof(CUstream),
        /* use_expected_addr */ true,
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
}
