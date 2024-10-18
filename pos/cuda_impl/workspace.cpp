#include "pos/cuda_impl/workspace.h"


POSWorkspace_CUDA::POSWorkspace_CUDA(int argc, char *argv[]) : POSWorkspace(argc, argv){
    this->checkpoint_api_id = 6666;
}


pos_retval_t POSWorkspace_CUDA::__init(){
    pos_retval_t retval = POS_SUCCESS;
    CUresult dr_retval;
    CUdevice cu_device;
    CUcontext cu_context;
    int device_count, i;

    // create the api manager
    this->api_mgnr = new POSApiManager_CUDA();
    POS_CHECK_POINTER(this->api_mgnr);
    this->api_mgnr->init();

    // mark all stateful resources
    this->stateful_handle_type_idx.push_back({
        kPOS_ResourceTypeId_CUDA_Memory
    });

    dr_retval = cuInit(0);
    if(unlikely(dr_retval != CUDA_SUCCESS)){
        POS_ERROR_C_DETAIL("failed to initialize CUDA driver: dr_retval(%d)", dr_retval);
    }

    dr_retval = cuDeviceGetCount(&device_count);
    if (unlikely(dr_retval != CUDA_SUCCESS)) {
        POS_ERROR_C_DETAIL("failed to obtain number of CUDA devices: dr_retval(%d)", dr_retval);
    }
    if(unlikely(device_count <= 0)){
        POS_ERROR_C_DETAIL("no CUDA device detected on current machines");
    }

    // create one CUDA context on each device
    for(i=0; i<device_count; i++){
        // obtain handles on each device
        dr_retval = cuDeviceGet(&cu_device, i);
        if (unlikely(dr_retval != CUDA_SUCCESS)){
            POS_WARN_C("failed to obtain device handle of device %d, skipped: dr_retval(%d)", i, dr_retval);
            continue;
        }

        // create context
        dr_retval = cuCtxCreate(&cu_context, 0, cu_device);
        if (unlikely(dr_retval != CUDA_SUCCESS)) {
            POS_WARN_C("failed to create context on device %d, skipped: dr_retval(%d)", i, dr_retval);
            continue;
        }

        if(unlikely(i == 0)){
            // set the first device context as default context
            dr_retval = cuCtxSetCurrent(cu_context);
            if (dr_retval != CUDA_SUCCESS) {
                POS_WARN_C("failed to set context on device %d as current: dr_retval(%d)", i, dr_retval);
                retval = POS_FAILED_DRIVER;
                goto exit;
            }
        }
        this->_cu_contexts.push_back(cu_context);
    }

    if(unlikely(this->_cu_contexts.size() == 0)){
        POS_WARN_C("no CUDA context was created on any device");
        retval = POS_FAILED_DRIVER;
        goto exit;
    }

exit:
    if(unlikely(retval != POS_SUCCESS)){
        for(i=0; i<this->_cu_contexts.size(); i++){
            cuCtxDestroy(this->_cu_contexts[i]);
            this->_cu_contexts.erase(this->_cu_contexts.begin()+i);
        }
    }

    return retval;
}


pos_retval_t POSWorkspace_CUDA::__deinit(){
    pos_retval_t retval = POS_SUCCESS;
    int i;

    for(i=0; i<this->_cu_contexts.size(); i++){
        cuCtxDestroy(this->_cu_contexts[i]);
        this->_cu_contexts.erase(this->_cu_contexts.begin()+i);
    }

    return retval;
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
