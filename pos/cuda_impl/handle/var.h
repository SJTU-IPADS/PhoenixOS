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
#include "pos/include/utils/serializer.h"

#include "pos/cuda_impl/handle.h"


/*!
 *  \brief  handle for cuda variable
 */
class POSHandle_CUDA_Var : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Var(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Var;
    }

    /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle_CUDA_Var(void* hm) : POSHandle(hm)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Var;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Var(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Var"); }

    // name of the kernel
    std::string name;

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t restore() override {
        pos_retval_t retval = POS_SUCCESS;
        CUresult cuda_dv_retval;
        CUdeviceptr dptr = 0;
        size_t d_size = 0;
        POSHandle *module_handle;

        POS_ASSERT(this->parent_handles.size() == 1);
        POS_CHECK_POINTER(module_handle = this->parent_handles[0]);
        POS_ASSERT(module_handle->resource_type_id = kPOS_ResourceTypeId_CUDA_Module);

        POS_ASSERT(this->name.size() > 0);

        cuda_dv_retval = cuModuleGetGlobal(
            &dptr, &d_size, (CUmodule)(module_handle->server_addr), this->name.c_str()
        );

         if(likely(CUDA_SUCCESS == cuda_dv_retval)){
            this->set_server_addr((void*)dptr);
            this->mark_status(kPOS_HandleStatus_Active);
        } else {
            retval = POS_FAILED;
            POS_WARN_C_DETAIL("failed to restore CUDA var: %d", cuda_dv_retval);
        }

        return retval;
    }

 protected:
    /*!
     *  \brief  obtain the serilization size of extra fields of specific POSHandle type
     *  \return the serilization size of extra fields of POSHandle
     */
    uint64_t __get_extra_serialize_size() override {
        return (
            /* name_size */     sizeof(uint64_t)
            /* name */          + (this->name.size() > 0 ? this->name.size() + 1 : 0)
        );
    }

    /*!
     *  \brief  serialize the extra state of current handle into the binary area
     *  \param  serialized_area  pointer to the binary area
     *  \return POS_SUCCESS for successfully serilization
     */
    pos_retval_t __serialize_extra(void* serialized_area) override {
        pos_retval_t retval = POS_SUCCESS;
        void *ptr = serialized_area;
        uint64_t tmp_size;
        char eos = '\0';

        POS_CHECK_POINTER(ptr);
        
        tmp_size = this->name.size();
        POSUtil_Serializer::write_field(&ptr, &(tmp_size), sizeof(uint64_t));
        if(tmp_size > 0){
            POSUtil_Serializer::write_field(&ptr, this->name.c_str(), tmp_size);
            POSUtil_Serializer::write_field(&ptr, &(eos), 1);
        }
        
        return retval;
    }

    /*!
     *  \brief  deserialize extra field of this handle
     *  \param  raw_data    raw data area that store the serialized data
     *  \return POS_SUCCESS for successfully deserilization
     */
    pos_retval_t __deserialize_extra(void* raw_data) override {
        pos_retval_t retval = POS_SUCCESS;
        uint64_t tmp_size;
        void *ptr = raw_data;
        char *temp_str;
        
        POS_CHECK_POINTER(ptr);

        POSUtil_Deserializer::read_field(&(tmp_size), &ptr, sizeof(uint64_t));
        if(likely(tmp_size > 0)){
            POS_CHECK_POINTER(temp_str = (char*)malloc(tmp_size+1));
            memset(temp_str, 0, tmp_size+1);
            POSUtil_Deserializer::read_field(temp_str, &ptr, tmp_size);
            this->name = std::string(static_cast<const char*>(temp_str));
            free(temp_str);
        }

        return retval;
    }
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Var
 */
class POSHandleManager_CUDA_Var : public POSHandleManager<POSHandle_CUDA_Var> {
 public:
    /*!
     *  \brief  allocate new mocked CUDA var within the manager
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
        POSHandle_CUDA_Var** handle,
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *module_handle;
        POS_CHECK_POINTER(handle);

        // obtain the context to allocate buffer
    #if POS_ENABLE_DEBUG_CHECK
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Module) == 0)){
            POS_WARN_C("no binded module provided to create the CUDA var");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
    #endif

        module_handle = related_handles[kPOS_ResourceTypeId_CUDA_Module][0];
        POS_CHECK_POINTER(module_handle);

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA stream in the manager");
            goto exit;
        }

        (*handle)->record_parent_handle(module_handle);

    exit:
        return retval;
    }
};
