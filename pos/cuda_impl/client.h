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
    /*!
     *  \param  id  client identifier
     *  \param  ws  pointer to the workspace related to this client
     */
    POSClient_CUDA(uint64_t id, void* ws) : POSClient(id, ws){}

    POSClient_CUDA(){}
    ~POSClient_CUDA(){};

    /*!
     *  \brief  instantiate handle manager for all used CUDA resources
     *  \note   the children class should replace this method to initialize their 
     *          own needed handle managers
     */
    void init_handle_managers() override {
        pos_retval_t retval;
        POSHandleManager_CUDA_Context *ctx_mgr;
        POSHandleManager_CUDA_Module *module_mgr;

        POS_CHECK_POINTER(ctx_mgr = new POSHandleManager_CUDA_Context());
        this->handle_managers[kPOS_ResourceTypeId_CUDA_Context] = ctx_mgr;

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Stream] = new POSHandleManager_CUDA_Stream(ctx_mgr->latest_used_handle);
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Stream]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Device] = new POSHandleManager_CUDA_Device(ctx_mgr->latest_used_handle);
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Device]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Module] = new POSHandleManager_CUDA_Module();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Module]);

        module_mgr = new POSHandleManager_CUDA_Module();
        POS_CHECK_POINTER(module_mgr);
        this->handle_managers[kPOS_ResourceTypeId_CUDA_Module] = module_mgr;
        if(likely(pos_gconfig_server.kernel_meta_path.size() > 0)){
            retval = module_mgr->load_cached_function_metas(pos_gconfig_server.kernel_meta_path);
            if(likely(retval == POS_SUCCESS)){
                pos_gconfig_server.is_load_kernel_from_cache = true;
            }
        }
        
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

    /*!
     *  \brief      deinit handle manager for all used resources
     *  \example    CUDA function manager should export the metadata of functions
     */
    void deinit_handle_managers() override {
        this->__dump_cuda_functions();
    }

 private:
    /*!
     *  \brief  export the metadata of functions
     */
    void __dump_cuda_functions() {
        uint64_t nb_functions, i;
        POSHandleManager_CUDA_Function *hm_function;
        POSHandle_CUDA_Function *function_handle;
        std::ofstream output_file;
        std::string file_path, dump_content;

        auto dump_function_metas = [](POSHandle_CUDA_Function* function_handle) -> std::string {
            std::string output_str("");
            std::string delimiter("|");
            uint64_t i;
            
            POS_CHECK_POINTER(function_handle);

            // mangled name of the kernel
            output_str += function_handle->name + std::string(delimiter);
            
            // signature of the kernel
            output_str += function_handle->signature + std::string(delimiter);

            // number of paramters
            output_str += std::to_string(function_handle->nb_params);
            output_str += std::string(delimiter);

            // parameter offsets
            for(i=0; i<function_handle->nb_params; i++){
                output_str += std::to_string(function_handle->param_offsets[i]);
                output_str += std::string(delimiter);
            }

            // parameter sizes
            for(i=0; i<function_handle->nb_params; i++){
                output_str += std::to_string(function_handle->param_sizes[i]);
                output_str += std::string(delimiter);
            }

            // input paramters
            output_str += std::to_string(function_handle->input_pointer_params.size());
            output_str += std::string(delimiter);
            for(i=0; i<function_handle->input_pointer_params.size(); i++){
                output_str += std::to_string(function_handle->input_pointer_params[i]);
                output_str += std::string(delimiter);
            }

            // output paramters
            output_str += std::to_string(function_handle->output_pointer_params.size());
            output_str += std::string(delimiter);
            for(i=0; i<function_handle->output_pointer_params.size(); i++){
                output_str += std::to_string(function_handle->output_pointer_params[i]);
                output_str += std::string(delimiter);
            }

            // inout parameters
            output_str += std::to_string(function_handle->inout_pointer_params.size());
            output_str += std::string(delimiter);
            for(i=0; i<function_handle->inout_pointer_params.size(); i++){
                output_str += std::to_string(function_handle->inout_pointer_params[i]);
                output_str += std::string(delimiter);
            }

            // suspicious paramters
            output_str += std::to_string(function_handle->suspicious_params.size());
            output_str += std::string(delimiter);
            for(i=0; i<function_handle->suspicious_params.size(); i++){
                output_str += std::to_string(function_handle->suspicious_params[i]);
                output_str += std::string(delimiter);
            }

            // has verified suspicious paramters
            if(function_handle->has_verified_params){
                output_str += std::string("1") + std::string(delimiter);

                // inout paramters
                output_str += std::to_string(function_handle->confirmed_suspicious_params.size());
                output_str += std::string(delimiter);
                for(i=0; i<function_handle->confirmed_suspicious_params.size(); i++){
                    output_str += std::to_string(function_handle->confirmed_suspicious_params[i].first);    // param_index
                    output_str += std::string(delimiter);
                    output_str += std::to_string(function_handle->confirmed_suspicious_params[i].second);   // offset
                    output_str += std::string(delimiter);
                }
            } else {
                output_str += std::string("0") + std::string(delimiter);
            }

            // cbank parameters
            output_str += std::to_string(function_handle->cbank_param_size);

            return output_str;
        };

        // if we have already save the kernels, we can skip
        if(likely(pos_gconfig_server.is_load_kernel_from_cache == true)){
            goto exit;
        }
        
        hm_function 
            = (POSHandleManager_CUDA_Function*)(this->handle_managers[kPOS_ResourceTypeId_CUDA_Function]);
        POS_CHECK_POINTER(hm_function);

        file_path = std::string("./") + pos_gconfig_server.job_name + std::string(".txt");
        output_file.open(file_path.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);

        nb_functions = hm_function->get_nb_handles();
        for(i=0; i<nb_functions; i++){
            POS_CHECK_POINTER(function_handle = hm_function->get_handle_by_id(i));
            output_file << dump_function_metas(function_handle) << std::endl;
        }

        output_file.close();
        POS_LOG("finish dump kernel metadats to %s", file_path.c_str());

    exit:
        ;
    }
};
