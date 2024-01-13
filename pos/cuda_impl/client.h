#pragma once

#include <iostream>
#include "pos/include/common.h"
#include "pos/include/workspace.h"
#include "pos/include/client.h"

#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/cublas.h"
#include "pos/cuda_impl/api_index.h"

class POSClient_CUDA : public POSClient {
 public:
    POSClient_CUDA(){}
    ~POSClient_CUDA(){};

    /*!
     *  \brief  instantiate handle manager for all used CUDA resources
     *  \note   the children class should replace this method to initialize their 
     *          own needed handle managers
     */
    void init_handle_managers() override {
        POSHandleManager_CUDA_Context* ctx_mgr;
        POS_CHECK_POINTER(ctx_mgr = new POSHandleManager_CUDA_Context());
        this->handle_managers[kPOS_ResourceTypeId_CUDA_Context] = ctx_mgr;

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Stream] = new POSHandleManager_CUDA_Stream(ctx_mgr->latest_used_handle);
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Stream]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Device] = new POSHandleManager_CUDA_Device(ctx_mgr->latest_used_handle);
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Device]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Module] = new POSHandleManager_CUDA_Module();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Module]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Function] = new POSHandleManager_CUDA_Function();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Function]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Var] = new POSHandleManager_CUDA_Var();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Var]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Memory] = new POSHandleManager_CUDA_Memory();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Memory]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Event] = new POSHandleManager_CUDA_Event();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Event]);

        this->handle_managers[kPOS_ResourceTypeId_cuBLAS_Context] = new POSHandleManager_cuBLAS_Context();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_cuBLAS_Context]);
    }

    /*!
     *  \brief  initialization of the DAG
     *  \note   insert initial handles to the DAG (e.g., default CUcontext, CUStream, etc.)
     */
    void init_dag() override {
        uint64_t i, nb_devices;
        pos_retval_t retval = POS_SUCCESS;
        POSHandleManager_CUDA_Context *ctx_mgr;
        POSHandleManager_CUDA_Stream *stream_mgr;
        POSHandleManager_CUDA_Device *device_mgr;

        ctx_mgr = (POSHandleManager_CUDA_Context*)(this->handle_managers[kPOS_ResourceTypeId_CUDA_Context]);
        POS_CHECK_POINTER(ctx_mgr);
        stream_mgr = (POSHandleManager_CUDA_Stream*)(this->handle_managers[kPOS_ResourceTypeId_CUDA_Stream]);
        POS_CHECK_POINTER(stream_mgr);
        device_mgr = (POSHandleManager_CUDA_Device*)(this->handle_managers[kPOS_ResourceTypeId_CUDA_Device]);
        POS_CHECK_POINTER(device_mgr);

        // insert the one and only initial CUDA context
        retval = this->dag.allocate_handle(ctx_mgr->latest_used_handle);
        if(unlikely(POS_SUCCESS != retval)){
            POS_ERROR_C_DETAIL("failed to allocate initial cocntext handle in the DAG");
        }

        // insert the one and only initial CUDA stream
        retval = this->dag.allocate_handle(stream_mgr->latest_used_handle);
        if(unlikely(POS_SUCCESS != retval)){
            POS_ERROR_C_DETAIL("failed to allocate initial stream_mgr handle in the DAG");
        }

        // insert all device handle
        nb_devices = device_mgr->get_nb_handles();
        for(i=0; i<nb_devices; i++){
            retval = this->dag.allocate_handle(device_mgr->get_handle_by_id(i));
            if(unlikely(POS_SUCCESS != retval)){
                POS_ERROR_C_DETAIL("failed to allocate the %lu(th) device handle in the DAG", i);
            }
        }
    }

 private:
};
