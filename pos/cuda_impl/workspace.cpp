#include "pos/cuda_impl/workspace.h"


POSWorkspace_CUDA::POSWorkspace_CUDA(int argc, char *argv[]) 
    : POSWorkspace(argc, argv)
{
    this->checkpoint_api_id = 6666;
}


pos_retval_t POSWorkspace_CUDA::init(){
    // create the api manager
    this->api_mgnr = new POSApiManager_CUDA();
    POS_CHECK_POINTER(this->api_mgnr);
    this->api_mgnr->init();

    // mark all stateful resources
    this->stateful_handle_type_idx.push_back({
        kPOS_ResourceTypeId_CUDA_Memory
    });

    // create CUDA context


    return POS_SUCCESS;
}


pos_retval_t POSWorkspace_CUDA::create_client(POSClient** clnt, pos_client_uuid_t* uuid){
    pos_client_cxt_CUDA_t client_cxt;
    client_cxt.cxt_base = this->_template_client_cxt;
    client_cxt.cxt_base.checkpoint_api_id = this->checkpoint_api_id;
    client_cxt.cxt_base.stateful_handle_type_idx = this->stateful_handle_type_idx;

    POS_CHECK_POINTER(*clnt = new POSClient_CUDA(/* ws */ this, /* id */ _current_max_uuid, /* cxt */ client_cxt));
    (*clnt)->init();
    
    *uuid = _current_max_uuid;
    _current_max_uuid += 1;
    _client_map[*uuid] = (*clnt);

    POS_DEBUG_C("add client: addr(%p), uuid(%lu)", (*clnt), *uuid);
    return POS_SUCCESS;
}


pos_retval_t POSWorkspace_CUDA::preserve_resource(pos_resource_typeid_t rid, void *data){
    pos_retval_t retval = POS_SUCCESS;

    switch (rid)
    {
    case kPOS_ResourceTypeId_CUDA_Context:
        // no need to preserve context
        goto exit;
    
    case kPOS_ResourceTypeId_CUDA_Module:
        goto exit;

    default:
        retval = POS_FAILED_NOT_IMPLEMENTED;
        goto exit;
    }

exit:
    return retval;
}


pos_retval_t POSWorkspace_CUDA::__create_cuda_contexts(){
    pos_retval_t retval = POS_SUCCESS;

exit:
    return retval;
}


pos_retval_t POSWorkspace_CUDA::__destory_cuda_contexts(){
    pos_retval_t retval = POS_SUCCESS;

exit:
    return retval;
}
