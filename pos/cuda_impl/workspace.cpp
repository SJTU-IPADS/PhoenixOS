#include "pos/cuda_impl/workspace.h"


POSWorkspace_CUDA::POSWorkspace_CUDA() : POSWorkspace(){}


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
        POS_DEBUG_C("created CUDA context: device_id(%d)", i);
    }

    if(unlikely(this->_cu_contexts.size() == 0)){
        POS_WARN_C("no CUDA context was created on any device");
        retval = POS_FAILED_DRIVER;
        goto exit;
    }

exit:
    if(unlikely(retval != POS_SUCCESS)){
        for(i=0; i<this->_cu_contexts.size(); i++){
            dr_retval = cuCtxDestroy(this->_cu_contexts[i]);
            if(unlikely(dr_retval != CUDA_SUCCESS)){
                POS_WARN_C(
                    "failed to destory context on device: device_id(%d), dr_retval(%d)",
                    i, dr_retval
                );
            } else {
                POS_DEBUG_C("destoried CUDA context: device_id(%d)", i);
            }
        }
        this->_cu_contexts.clear();
    }

    return retval;
}


pos_retval_t POSWorkspace_CUDA::__deinit(){
    pos_retval_t retval = POS_SUCCESS;
    CUresult dr_retval;
    int i;

    for(i=0; i<this->_cu_contexts.size(); i++){
        POS_DEBUG("destorying cuda context on device...: device_id(%d)", i);
        dr_retval = cuCtxDestroy(this->_cu_contexts[i]);
        if(unlikely(dr_retval != CUDA_SUCCESS)){
            POS_WARN_C(
                "failed to destory context on device: device_id(%d), dr_retval(%d)",
                i, dr_retval
            );
        } else {
            POS_BACK_LINE
            POS_DEBUG_C("destoried cuda context on device: device_id(%d)", i);
        }
    }
    this->_cu_contexts.clear();

    return retval;
}


pos_retval_t POSWorkspace_CUDA::create_client(pos_create_client_param_t& param, POSClient** clnt){
    pos_retval_t retval = POS_SUCCESS;
    pos_client_cxt_CUDA_t client_cxt;
    std::string runtime_daemon_log_path;

    client_cxt.cxt_base.job_name = param.job_name;
    client_cxt.cxt_base.stateful_handle_type_idx = this->stateful_handle_type_idx;

    retval = this->ws_conf.get(POSWorkspaceConf::ConfigType::kRuntimeDaemonLogPath, runtime_daemon_log_path);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to obtain runtime daemon log path");
    } else {
        client_cxt.cxt_base.kernel_meta_path = runtime_daemon_log_path + std::string("/") 
                                                + param.job_name + std::string("_kernel_metas.txt");
    }

    // create client
    POS_CHECK_POINTER(*clnt = new POSClient_CUDA(/* ws */ this, /* id */ _current_max_uuid, /* cxt */ client_cxt));
    (*clnt)->init();
    this->_current_max_uuid += 1;
    this->_client_map[(*clnt)->id] = (*clnt);
    this->_pid_client_map[param.pid] = (*clnt);
    POS_DEBUG_C("add client: addr(%p), uuid(%lu)", (*clnt), (*clnt)->id);

    // create queue pair
    retval = this->__create_qp((*clnt)->id);

    if(retval == POS_SUCCESS){
        POS_DEBUG_C("add queue pair: uuid(%lu)", (*clnt)->id);
        (*clnt)->status = kPOS_ClientStatus_Active;
    } else {
        POS_WARN_C("failed to create queue pair: uuid(%lu)", (*clnt)->id);
    }

    return retval;
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
