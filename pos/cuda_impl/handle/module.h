/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
#include "pos/include/checkpoint.h"
#include "pos/include/api_context.h"
#include "pos/include/utils/serializer.h"

#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/utils/fatbin.h"


/*!
 *  \brief  handle for cuda module
 */
class POSHandle_CUDA_Module : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Module(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Module;

        // initialize checkpoint bag
    #if POS_CONF_EVAL_CkptOptLevel > 0 || POS_CONF_EVAL_MigrOptLevel > 0
        if(unlikely(POS_SUCCESS != this->init_ckpt_bag())){
            POS_ERROR_C_DETAIL("failed to inilialize checkpoint bag");
        }
    #endif
    }

    /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle_CUDA_Module(void* hm) : POSHandle(hm)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Module;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Module(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Module"); }

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t __restore() override {
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

    // function descriptors under this module
    std::vector<POSCudaFunctionDesp*> function_desps;

    // pacthed binary, only PTX included
    std::vector<uint8_t> patched_binary;

    // shadow module for the patched kernel binary
    void *patched_server_addr;
    
 protected:
    /*!
     *  \brief  reload state of this handle back to the device
     *  \param  data        source data to be reloaded
     *  \param  offset      offset from the base address of this handle to be reloaded
     *  \param  size        reload size
     *  \param  stream_id   stream for reloading the state
     *  \param  on_device   whether the source data is on device
     */
    pos_retval_t __reload_state(void* data, uint64_t offset, uint64_t size, uint64_t stream_id, bool on_device) override {
        pos_retval_t retval = POS_SUCCESS;

        /*!
         *  \note   the state is restoring in restore function, so we do nothing here
         */

    exit:
        return retval;
    }

    /*!
     *  \brief  obtain the serilization size of extra fields of specific POSHandle type
     *  \return the serilization size of extra fields of POSHandle
     */
    uint64_t __get_extra_serialize_size() override {
        return 0;
    }

    /*!
     *  \brief  serialize the extra state of current handle into the binary area
     *  \param  serialized_area  pointer to the binary area
     *  \return POS_SUCCESS for successfully serilization
     */
    pos_retval_t __serialize_extra(void* serialized_area) override {
        return POS_SUCCESS;
    }

    /*!
     *  \brief  deserialize extra field of this handle
     *  \param  sraw_data    raw data area that store the serialized data
     *  \return POS_SUCCESS for successfully deserilization
     */
    pos_retval_t __deserialize_extra(void* raw_data) override {
        return POS_SUCCESS;
    }

    /*!
     *  \brief  initialize checkpoint bag of this handle
     *  \note   it must be implemented by different implementations of stateful 
     *          handle, as they might require different allocators and deallocators
     *  \return POS_SUCCESS for successfully initialization
     */
    pos_retval_t init_ckpt_bag() override { 
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
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Stream
 */
class POSHandleManager_CUDA_Module : public POSHandleManager<POSHandle_CUDA_Module> {
 public:
    std::map<std::string, POSCudaFunctionDesp_t*> cached_function_desps;

    pos_retval_t load_cached_function_metas(std::string &file_path){
        pos_retval_t retval = POS_SUCCESS;
        uint64_t i;
        std::string line, stream;
        POSCudaFunctionDesp_t *new_desp;
        char delimiter = '|';

        auto generate_desp_from_meta = [](std::vector<std::string>& metas) -> POSCudaFunctionDesp_t* {
            uint64_t i;
            std::vector<uint32_t> param_offsets;
            std::vector<uint32_t> param_sizes;
            std::vector<uint32_t> input_pointer_params;
            std::vector<uint32_t> output_pointer_params;
            std::vector<uint32_t> inout_pointer_params;
            std::vector<uint32_t> suspicious_params;
            std::vector<std::pair<uint32_t,uint64_t>> confirmed_suspicious_params;
            bool confirmed;
            uint64_t nb_input_pointer_params, nb_output_pointer_params, nb_inout_pointer_params, 
                    nb_suspicious_params, nb_confirmed_suspicious_params, has_verified_params;
            uint64_t ptr;

            POSCudaFunctionDesp_t *new_desp = new POSCudaFunctionDesp_t();
            POS_CHECK_POINTER(new_desp);

            ptr = 0;
            
            // mangled name of the kernel
            new_desp->name = metas[ptr];
            ptr++;

            // signature of the kernel
            new_desp->signature = metas[ptr];
            ptr++;

            // number of paramters
            new_desp->nb_params = std::stoul(metas[ptr]);
            ptr++;

            // parameter offsets
            for(i=0; i<new_desp->nb_params; i++){
                param_offsets.push_back(std::stoul(metas[ptr+i]));   
            }
            ptr += new_desp->nb_params;
            new_desp->param_offsets = param_offsets;

            // parameter sizes
            for(i=0; i<new_desp->nb_params; i++){
                param_sizes.push_back(std::stoul(metas[ptr+i]));
            }
            ptr += new_desp->nb_params;
            new_desp->param_sizes = param_sizes;

            // input paramters
            nb_input_pointer_params = std::stoul(metas[ptr]);
            ptr++;
            for(i=0; i<nb_input_pointer_params; i++){
                input_pointer_params.push_back(std::stoul(metas[ptr+i]));
            }
            ptr += nb_input_pointer_params;
            new_desp->input_pointer_params = input_pointer_params;

            // output paramters
            nb_output_pointer_params = std::stoul(metas[ptr]);
            ptr++;
            for(i=0; i<nb_output_pointer_params; i++){
                output_pointer_params.push_back(std::stoul(metas[ptr+i]));
            }
            ptr += nb_output_pointer_params;
            new_desp->output_pointer_params = output_pointer_params;

            // inout paramters
            nb_inout_pointer_params = std::stoul(metas[ptr]);
            ptr++;
            for(i=0; i<nb_inout_pointer_params; i++){
                inout_pointer_params.push_back(std::stoul(metas[ptr+i]));
            }
            ptr += nb_inout_pointer_params;
            new_desp->inout_pointer_params = inout_pointer_params;

            // suspicious paramters
            nb_suspicious_params = std::stoul(metas[ptr]);
            ptr++;
            for(i=0; i<nb_suspicious_params; i++){
                suspicious_params.push_back(std::stoul(metas[ptr+i]));
            }
            ptr += nb_suspicious_params;
            new_desp->suspicious_params = suspicious_params;

            // has verified suspicious paramters
            has_verified_params = std::stoul(metas[ptr]);
            ptr++;
            new_desp->has_verified_params = has_verified_params;

            if(has_verified_params == 1){
                // index of those parameter which is a structure (contains pointers)
                nb_confirmed_suspicious_params = std::stoul(metas[ptr]);
                ptr++;
                for(i=0; i<nb_confirmed_suspicious_params; i++){
                    confirmed_suspicious_params.push_back({
                        /* param_index */ std::stoul(metas[ptr+2*i]), /* offset */ std::stoul(metas[ptr+2*i+1])
                    });
                }
                ptr += nb_confirmed_suspicious_params;
                new_desp->confirmed_suspicious_params = confirmed_suspicious_params;
            }

            // cbank parameter size (p.s., what is this?)
            new_desp->cbank_param_size = std::stoul(metas[ptr].c_str());

            return new_desp;
        };

        std::ifstream file(file_path.c_str(), std::ios::in);
        if(likely(file.is_open())){
            POS_LOG("parsing cached kernel metas from file %s...", file_path.c_str());
            i = 0;
            while (std::getline(file, line)) {
                // split by ","
                std::stringstream ss(line);
                std::string segment;
                std::vector<std::string> metas;
                while (std::getline(ss, segment, delimiter)) { metas.push_back(segment); }

                // parse
                new_desp = generate_desp_from_meta(metas);
                cached_function_desps.insert(
                    std::pair<std::string, POSCudaFunctionDesp_t*>(new_desp->name, new_desp)
                );

                i++;
            }

            POS_LOG("parsed %lu of cached kernel metas from file %s", i, file_path.c_str());
            file.close();
        } else {
            retval = POS_FAILED_NOT_EXIST;
            POS_WARN("failed to load kernel meta file %s, fall back to slow path", file_path.c_str());
        }

    exit:
        return retval;
    }
    
    /*!
     *  \brief  allocate new mocked CUDA module within the manager
     *  \param  handle          pointer to the mocked handle of the newly allocated resource
     *  \param  related_handles all related handles for helping allocate the mocked resource
     *                          (note: these related handles might be other types)
     *  \param  size            size of the newly allocated resource
     *  \param  expected_addr   the expected mock addr to allocate the resource (optional)
     *  \param  state_size      size of resource state behind this handle  
     *  \return POS_FAILED_DRAIN for run out of virtual address space; 
     *          POS_SUCCESS for successfully allocation
     */
    pos_retval_t allocate_mocked_resource(
        POSHandle_CUDA_Module** handle,
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *context_handle;

        POS_CHECK_POINTER(handle);

    #if POS_CONF_RUNTIME_EnableDebugCheck
        // obtain the context to allocate buffer
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
            POS_WARN_C("no binded context provided to created the CUDA module");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
    #endif

        context_handle = related_handles[kPOS_ResourceTypeId_CUDA_Context][0];
        POS_CHECK_POINTER(context_handle);

        retval = this->__allocate_mocked_resource(handle, true, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA module in the manager");
            goto exit;
        }

        (*handle)->record_parent_handle(context_handle);

    exit:
        return retval;
    }

    /*!
     *  \brief  allocate and restore handles for provision, for fast restore
     *  \param  amount  amount of handles for pooling
     *  \return POS_SUCCESS for successfully preserving
     */
    pos_retval_t preserve_pooled_handles(uint64_t amount) override {
        return POS_SUCCESS;
    }

    /*!
     *  \brief  restore handle from pool
     *  \param  handle  the handle to be restored
     *  \return POS_SUCCESS for successfully restoring
     *          POS_FAILED for failed pooled restoring, should fall back to normal path
     */
    pos_retval_t try_restore_from_pool(POSHandle_CUDA_Module* handle) override {
        return POS_FAILED;
    }
};
