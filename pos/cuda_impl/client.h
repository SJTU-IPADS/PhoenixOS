#pragma once

#include <iostream>
#include "pos/include/common.h"
#include "pos/include/workspace.h"
#include "pos/include/client.h"

#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/cublas.h"
#include "pos/cuda_impl/api_index.h"


/*!
 *  \brief  context of CUDA client
 */
typedef struct pos_client_cxt_CUDA {
    POS_CLIENT_CXT_HEAD;
} pos_client_cxt_CUDA_t;


class POSClient_CUDA : public POSClient {
 public:
    /*!
     *  \param  id  client identifier
     *  \param  cxt context to initialize this client
     */
    POSClient_CUDA(uint64_t id, pos_client_cxt_CUDA_t cxt) 
        : POSClient(id, cxt.cxt_base), _cxt_CUDA(cxt){}

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

        // TODO: it's ugly to write gconfig here
        if(pos_gconfig_server.kernel_meta_path.size() > 0){
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
     *  \brief  restore resources from checkpointed file
     *  TODO:   move this function to base class
     */
    void init_restore_resources() override {
        uint64_t i, j;
        std::ifstream file;
        uint8_t *checkpoint_bin, *bin_ptr;
        uint64_t file_size;

        pos_resource_typeid_t resource_type_id;
        uint64_t nb_handles, nb_resource_types, serialize_area_size;

        uint64_t nb_api_cxt;
        POSAPIContext_QE_t *wqe;

        POSHandleManager<POSHandle> *hm;
        POSHandleManager<POSHandle_CUDA_Memory> *hm_memory;

        auto __get_binary_file_size = [](std::ifstream& file) -> uint64_t {
            file.seekg(0, std::ios::end);
            return file.tellg();
        };

        auto __copy_binary_file_to_buffer = [](std::ifstream& file, uint64_t size, uint8_t *buffer) {
            file.seekg(0, std::ios::beg);
            file.read((char*)(buffer), size);
        };

        #define __READ_TYPED_BINARY_AND_FWD(var, type, pointer) \
                    var = (*((type*)(pointer)));                \
                    pointer += sizeof(type);

        // TODO: it's ugly to write gconfig here, try to use client context instead
        if(pos_gconfig_server.checkpoint_file_path.size() > 0){
            // open checkpoint file
            file.open(pos_gconfig_server.checkpoint_file_path.c_str(), std::ios::in|std::ios::binary);
            if(unlikely(!file.good())){
                POS_ERROR_C("failed to open checkpoint binary file from %s", pos_gconfig_server.checkpoint_file_path.c_str());
            }

            POS_LOG("restoring from binary file...");

            // obtain its size
            file_size = __get_binary_file_size(file);
            POS_ASSERT(file_size > 0);

            // allocate buffer and readin data to the buffer
            POS_CHECK_POINTER(checkpoint_bin = (uint8_t*)malloc(file_size));
            __copy_binary_file_to_buffer(file, file_size, checkpoint_bin);
            bin_ptr = checkpoint_bin;

            /* --------- step 1: read handles --------- */
            // field: # resource type
            __READ_TYPED_BINARY_AND_FWD(nb_resource_types, uint64_t, bin_ptr);

            for(i=0; i<nb_resource_types; i++){
                // field: # resource type id
                __READ_TYPED_BINARY_AND_FWD(resource_type_id, pos_resource_typeid_t, bin_ptr);

                // field: # handles under this manager 
                __READ_TYPED_BINARY_AND_FWD(nb_handles, uint64_t, bin_ptr);

                for(j=0; j<nb_handles; j++){
                    // field: size of the serialized area of this handle
                    __READ_TYPED_BINARY_AND_FWD(serialize_area_size, uint64_t, bin_ptr);

                    if(likely(serialize_area_size > 0)){
                        /*!
                         *  \note   if the resource is cuda memory, then we need to use POSHandleManager with
                         *          specific type, in order to invoke derived function of POSHandle (e.g., 
                         *          init_ckpt_bag) inside allocate_mocked_resource_from_binary
                         *  TODO:   kind of ugly here, try to extract this part as a virtual function
                         */
                        if(resource_type_id == kPOS_ResourceTypeId_CUDA_Memory){
                            POS_CHECK_POINTER(
                                hm_memory = (POSHandleManager<POSHandle_CUDA_Memory>*)(this->handle_managers[resource_type_id])
                            );
                            hm_memory->allocate_mocked_resource_from_binary(bin_ptr);
                        } else {
                            POS_CHECK_POINTER(
                                hm = (POSHandleManager<POSHandle>*)(this->handle_managers[resource_type_id])
                            );
                            hm->allocate_mocked_resource_from_binary(bin_ptr);
                        }
                        
                        bin_ptr += serialize_area_size;
                    }
                }

                POS_LOG("  => deserialized state of %lu handles for resource type %u", nb_handles, resource_type_id);
            }

            /* --------- step 2: read api context --------- */
            // field: # api context
            __READ_TYPED_BINARY_AND_FWD(nb_api_cxt, uint64_t, bin_ptr);

            for(i=0; i<nb_api_cxt; i++){
                // field: size of the serialized area of this api context
                __READ_TYPED_BINARY_AND_FWD(serialize_area_size, uint64_t, bin_ptr);
                
                POS_CHECK_POINTER(wqe = new POSAPIContext_QE_t(/* pos_client */ this));
                wqe->deserialize(bin_ptr);
                this->dag.record_op(wqe);
                
                bin_ptr += serialize_area_size;
            }

            POS_LOG("  => deserialized %lu of api contexts", nb_api_cxt);

            /* --------- step 3: read DAG --------- */
            // field: size of the serialized area of this dag topo
            __READ_TYPED_BINARY_AND_FWD(serialize_area_size, uint64_t, bin_ptr);
            this->dag.deserialize(bin_ptr);
            bin_ptr += serialize_area_size;

            POS_LOG("  => deserialized DAG");
        
            /* --------- step 4: restore handle tree --------- */
            // TODO:

            /* --------- step 5: recompute missing checkpoints --------- */
            // TODO:

            POS_LOG("restore finished");
        }

        #undef  __READ_TYPED_BINARY_AND_FWD
    }

    /*!
     *  \brief      deinit handle manager for all used resources
     *  \example    CUDA function manager should export the metadata of functions
     */
    void deinit_dump_handle_managers() override {
        this->__dump_hm_cuda_functions();
    }

    /*!
     *  \brief  dump checkpoints to file
     *  \todo   this function can be move to parent class
     */
    void deinit_dump_checkpoints() override {
        std::string file_path;
        std::ofstream output_file;

        typename std::map<pos_resource_typeid_t, void*>::iterator hm_map_iter;
        POSHandleManager<POSHandle> *hm;
        uint64_t nb_handles, nb_resource_types, i;
        POSHandle *handle;
        
        uint64_t nb_api_cxt;
        POSAPIContext_QE_t *api_cxt;

        void *serialize_area;
        uint64_t serialize_area_size;

        file_path = std::string("./") + pos_gconfig_server.job_name + std::string("_checkpoints_") + std::to_string(this->id) + std::string(".bat");
        output_file.open(file_path.c_str(), std::ios::binary);

        POS_LOG("dumping checkpoints...");

        /* ------------------ step 1: dump handles ------------------ */
        // field: # resource type
        nb_resource_types = this->handle_managers.size();
        output_file.write((const char*)(&(nb_resource_types)), sizeof(uint64_t));

        for(hm_map_iter = this->handle_managers.begin(); hm_map_iter != handle_managers.end(); hm_map_iter++){
            POS_CHECK_POINTER(hm = (POSHandleManager<POSHandle>*)(hm_map_iter->second));
            nb_handles = hm->get_nb_handles();

            // field: resource type id
            output_file.write((const char*)(&(hm_map_iter->first)), sizeof(pos_resource_typeid_t));

            // field: # handles under this manager 
            output_file.write((const char*)(&nb_handles), sizeof(uint64_t));

            for(i=0; i<nb_handles; i++){
                POS_CHECK_POINTER(handle = hm->get_handle_by_id(i));

                if(unlikely(POS_SUCCESS != handle->serialize(&serialize_area))){
                    POS_WARN_C("failed to serialize handle: client_addr(%p)", handle->client_addr);
                    continue;
                }
                POS_CHECK_POINTER(serialize_area);

                serialize_area_size = handle->get_serialize_size();

                // field: size of the serialized area of this handle
                output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));

                if(likely(serialize_area_size > 0)){
                    // field: serialized data
                    output_file.write((const char*)(serialize_area), serialize_area_size);
                }
                output_file.flush();
                free(serialize_area);
            }
        }

        POS_LOG("    => dumped checkpoints of handles");

        /* ------------------ step 2: dump api context ------------------ */
        // field: # api context
        nb_api_cxt = this->dag.get_nb_api_cxt();
        output_file.write((const char*)(&(nb_api_cxt)), sizeof(uint64_t));

        for(i=0; i<nb_api_cxt; i++){
            POS_CHECK_POINTER(api_cxt = this->dag.get_api_cxt_by_id(i));

            api_cxt->serialize(&serialize_area);
            POS_CHECK_POINTER(serialize_area);

            // field: size of the serialized area of this api context
            serialize_area_size = api_cxt->get_serialize_size();
            output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));
            
            // field: serialized data
            output_file.write((const char*)(serialize_area), serialize_area_size);
            
            output_file.flush();
            free(serialize_area);
        }

        POS_LOG("    => dumped checkpoints of api contexts");

        /* ------------------ step 3: dump dag ------------------ */
        /*!
         *  \note   actually, after dumping handle and api context, we already can construct DAG while restoring,
         *          as the api context contains information about which handles each API would operates on, we still
         *          dump the DAG here to accelerate the re-execute algorithm in restore
         */
        this->dag.serialize(&serialize_area);
        POS_CHECK_POINTER(serialize_area);

        // field: size of the serialized area of this dag topo
        serialize_area_size = this->dag.get_serialize_size();
        output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));

        // field: serialized data
        output_file.write((const char*)(serialize_area), serialize_area_size);
        
        output_file.flush();
        free(serialize_area);

        POS_LOG("    => dumped checkpoints of DAG");

        output_file.close();
        POS_LOG("finish dump checkpoints to %s", file_path.c_str());
    }

 private:
    pos_client_cxt_CUDA _cxt_CUDA;

    /*!
     *  \brief  export the metadata of functions
     */
    void __dump_hm_cuda_functions() {
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

        file_path = std::string("./") + pos_gconfig_server.job_name + std::string("_kernel_metas.txt");
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
