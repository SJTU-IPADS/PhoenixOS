#include <iostream>
#include <map>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/module.h"
#include "pos/cuda_impl/proto/module.pb.h"


POSHandle_CUDA_Module::POSHandle_CUDA_Module(void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, size_t state_size_)
    : POSHandle_CUDA(client_addr_, size_, hm, id_, state_size_)
{
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Module;

    // initialize checkpoint bag
    #if POS_CONF_EVAL_CkptOptLevel > 0 || POS_CONF_EVAL_MigrOptLevel > 0
        if(unlikely(POS_SUCCESS != this->__init_ckpt_bag())){
            POS_ERROR_C_DETAIL("failed to inilialize checkpoint bag");
        }
    #endif
}


POSHandle_CUDA_Module::POSHandle_CUDA_Module(void* hm) : POSHandle_CUDA(hm)
{
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Module;
}


POSHandle_CUDA_Module::POSHandle_CUDA_Module(size_t size_, void* hm, pos_u64id_t id_, size_t state_size_)
    : POSHandle_CUDA(size_, hm, id_, state_size_)
{
    POS_ERROR_C_DETAIL("shouldn't be called");
}


pos_retval_t POSHandle_CUDA_Module::__init_ckpt_bag(){ 
    this->ckpt_bag = new POSCheckpointBag(
        /* 0 */ state_size,
        /* allocator */ nullptr,
        /* deallocator */ nullptr,
        /* dev_allocator */ nullptr,
        /* dev_deallocator */ nullptr
    );
    POS_CHECK_POINTER(this->ckpt_bag);
    return POS_SUCCESS;
}


pos_retval_t POSHandle_CUDA_Module::__add(uint64_t version_id, uint64_t stream_id){
    return POS_SUCCESS;
}


pos_retval_t POSHandle_CUDA_Module::__commit(
    uint64_t version_id, uint64_t stream_id, bool from_cache, bool is_sync, std::string ckpt_dir
){
    pos_retval_t retval = POS_SUCCESS;
    std::vector<POSCheckpointSlot*> ckpt_slots;

    if(unlikely(POS_SUCCESS != (
        retval = this->ckpt_bag->get_all_scheckpoint_slots<kPOS_CkptSlotPosition_Host, kPOS_CkptStateType_Host>(ckpt_slots)
    ))){
        POS_WARN_C("failed to obtain host-side checkpoint slot that stores host-side state");
        goto exit;
    }
    POS_ASSERT(ckpt_slots.size() == 1);

    retval = this->__persist(ckpt_slots[0], ckpt_dir, stream_id);

exit:
    return retval;
}


pos_retval_t POSHandle_CUDA_Module::__generate_protobuf_binary(google::protobuf::Message** binary, google::protobuf::Message** base_binary){
    pos_retval_t retval = POS_SUCCESS;
    pos_protobuf::Bin_POSHandle_CUDA_Module *cuda_module_binary;

    POS_CHECK_POINTER(binary);
    POS_CHECK_POINTER(base_binary);

    cuda_module_binary = new pos_protobuf::Bin_POSHandle_CUDA_Module();
    POS_CHECK_POINTER(cuda_module_binary);

    *binary = reinterpret_cast<google::protobuf::Message*>(cuda_module_binary);
    POS_CHECK_POINTER(*binary);
    *base_binary = cuda_module_binary->mutable_base();
    POS_CHECK_POINTER(*base_binary);

    // serialize handle specific fields
    /* currently nothing */

    return retval;
}


pos_retval_t POSHandle_CUDA_Module::__restore(){
    pos_retval_t retval = POS_SUCCESS;
    CUresult cuda_dv_retval;
    std::vector<pos_host_ckpt_t> host_ckpts;
    POSAPIContext_QE_t *wqe;
    CUmodule module = NULL;

    // the module content comes from the host-side checkpoint
    POS_CHECK_POINTER(this->ckpt_bag);
    host_ckpts = this->ckpt_bag->get_host_checkpoint_records();
    POS_ASSERT(host_ckpts.size() == 1);

    POS_CHECK_POINTER(wqe = host_ckpts[0].wqe);

    cuda_dv_retval = cuModuleLoadData(
        /* module */ &module,
        /* image */  pos_api_param_addr(wqe, host_ckpts[0].param_index)
    );

    if(likely(CUDA_SUCCESS == cuda_dv_retval)){
        this->set_server_addr((void*)module);
        this->mark_status(kPOS_HandleStatus_Active);
    } else {
        POS_WARN_C_DETAIL("failed to restore CUDA module, cuModuleLoadData failed: %d", cuda_dv_retval);
        retval = POS_FAILED;
    }

    return retval;
}


pos_retval_t POSHandle_CUDA_Module::__reload_state(
    void* data, uint64_t offset, uint64_t size, uint64_t stream_id, bool on_device
){
    pos_retval_t retval = POS_SUCCESS;

    /*!
     *  \note   the state is restoring in restore function, so we do nothing here
     */

exit:
    return retval;
}
