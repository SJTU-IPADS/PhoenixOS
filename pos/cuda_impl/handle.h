#pragma once

#include <iostream>
#include <string>

#include <stdint.h>
#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/handle.h"

#include "pos/cuda_impl/utils/fatbin.h"

/*!
 *  \brief  idx of CUDA resource types
 */
enum pos_handle_cuda_type_id_t : uint64_t {
    kPOS_ResourceTypeId_CUDA_Context = kPOS_ResourceTypeId_Num_Base_Type,
    kPOS_ResourceTypeId_CUDA_Module,
    kPOS_ResourceTypeId_CUDA_Function,
    kPOS_ResourceTypeId_CUDA_Var,
    kPOS_ResourceTypeId_CUDA_Device,
    kPOS_ResourceTypeId_CUDA_Memory,
    kPOS_ResourceTypeId_CUDA_Stream,
    kPOS_ResourceTypeId_CUDA_Event,

    /*! \note   library handle types, define in pos/cuda_impl/handle/xxx.h */
    kPOS_ResourceTypeId_cuBLAS_Context,
};

/* ==================================== Handle Definition ==================================== */

/*!
 *  \brief  handle for cuda context
 */
class POSHandle_CUDA_Context : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size            size of the resources represented by this handle
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Context(void *client_addr_, size_t size_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Context;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Context(size_t size_, size_t state_size_=0) : POSHandle(size_, state_size_){
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  restore the current handle when it becomes broken state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t restore(){
        cudaError_t cuda_rt_res;
        CUresult cuda_dv_res;
        CUcontext pctx;

        /*!
         *  \note   make sure runtime API is initialized
         *          if we don't do this and use the driver API, it might be unintialized
         */
        if((cuda_rt_res = cudaSetDevice(0)) != cudaSuccess){
            POS_ERROR_C_DETAIL("cudaSetDevice failed: %d", cuda_rt_res);
        }
        cudaDeviceSynchronize();

        // obtain current cuda context
        if((cuda_dv_res = cuCtxGetCurrent(&pctx)) != CUDA_SUCCESS){
            POS_ERROR_C_DETAIL("cuCtxGetCurrent failed: %d", cuda_dv_res);
        }
        this->set_server_addr((void*)pctx);

        // TODO: should we append to DAG here?

        this->status = kPOS_HandleStatus_Active;

        return POS_SUCCESS;
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Context"); }
};
using POSHandle_CUDA_Context_ptr = std::shared_ptr<POSHandle_CUDA_Context>;


/*!
 *  \brief  handle for cuda module
 */
class POSHandle_CUDA_Module : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size            size of the resources represented by this handle
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Module(void *client_addr_, size_t size_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Module;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Module(size_t size_, size_t state_size_=0) : POSHandle(size_, state_size_){
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Module"); }

    // function descriptors under this module
    std::vector<POSCudaFunctionDesp_ptr> function_desps;
};
using POSHandle_CUDA_Module_ptr = std::shared_ptr<POSHandle_CUDA_Module>;


/*!
 *  \brief  handle for cuda variable
 */
class POSHandle_CUDA_Var : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size            size of the resources represented by this handle
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Var(void *client_addr_, size_t size_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Var;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Var(size_t size_, size_t state_size_=0) : POSHandle(size_, state_size_){
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Var"); }

    // name of the kernel
    std::shared_ptr<char[]> name;
};
using POSHandle_CUDA_Var_ptr = std::shared_ptr<POSHandle_CUDA_Var>;


/*!
 *  \brief  handle for cuda function
 */
class POSHandle_CUDA_Function : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size            size of the resources represented by this handle
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Function(void *client_addr_, size_t size_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, state_size_) 
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Function;
    }
    
    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Function(size_t size_, size_t state_size_=0) : POSHandle(size_, state_size_){
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Function"); }

    // name of the kernel
    std::shared_ptr<char[]> name;

    // number of parameters within this function
    uint32_t nb_params;

    // offset of each parameter
    std::vector<uint32_t> param_offsets;

    // size of each parameter
    std::vector<uint32_t> param_sizes;

    // cbank parameter size (p.s., what is this?)
    uint64_t cbank_param_size;
};
using POSHandle_CUDA_Function_ptr = std::shared_ptr<POSHandle_CUDA_Function>;


/*!
 *  \brief  handle for cuda device
 */
class POSHandle_CUDA_Device : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size            size of the resources represented by this handle
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Device(void *client_addr_, size_t size_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Device;
    }
    
    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Device(size_t size_, size_t state_size_=0) : POSHandle(size_, state_size_){
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Device"); }

    // identifier of the device
    int device_id;

    protected:
};
using POSHandle_CUDA_Device_ptr = std::shared_ptr<POSHandle_CUDA_Device>;


/*!
 *  \brief  handle for cuda memory
 */
class POSHandle_CUDA_Memory : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  size    size of the resources represented by this handle
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Memory(size_t size_, size_t state_size_=0)
        : POSHandle(size_, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Memory;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Memory(void *client_addr_, size_t size_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  checkpoint the state of the resource behind this handle
     *  \note   only handle of stateful resource should implement this method
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t checkpoint(uint64_t version_id, uint64_t stream_id=0) override { 
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;
        POSCheckpointSlot_ptr ckpt_slot;

        // uint64_t s_tick = 0, e_tick = 0;
        
        // apply new checkpoint slot
        if(unlikely(
            POS_SUCCESS != this->ckpt_bag.apply_new_checkpoint(
                /* version */ version_id,
                /* ptr */ &ckpt_slot
            )
        )){
            POS_WARN_C("failed to apply checkpoint slot");
            retval = POS_FAILED;
            goto exit;
        }

        // checkpoint
        // TODO: takes long time
        // s_tick = POSUtilTimestamp::get_tsc();
        cuda_rt_retval = cudaMemcpyAsync(
            /* dst */ ckpt_slot->expose_pointer(), 
            /* src */ this->server_addr,
            /* size */ this->state_size,
            /* kind */ cudaMemcpyDeviceToHost,
            /* stream */ stream_id
        );
        // e_tick = POSUtilTimestamp::get_tsc();

        // POS_LOG("copy duration: %lf us, size: %lu Bytes", POS_TSC_RANGE_TO_USEC(e_tick, s_tick), this->state_size);

        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to checkpoint memory handle: server_addr(%p), retval(%d)",
                this->server_addr, cuda_rt_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    
    exit:
        return retval;
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Memory"); }

    protected:
};
using POSHandle_CUDA_Memory_ptr = std::shared_ptr<POSHandle_CUDA_Memory>;


/*!
 *  \brief  handle for cuda stream
 */
class POSHandle_CUDA_Stream : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size            size of the resources represented by this handle
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Stream(void *client_addr_, size_t size_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Stream;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Stream(size_t size_, size_t state_size_=0) : POSHandle(size_, state_size_){
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Stream"); }

    protected:
};
using POSHandle_CUDA_Stream_ptr = std::shared_ptr<POSHandle_CUDA_Stream>;


/*!
 *  \brief  handle for cuda event
 */
class POSHandle_CUDA_Event : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size            size of the resources represented by this handle
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Event(void *client_addr_, size_t size_, size_t state_size_=0)
        : POSHandle(client_addr_, size_, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Event;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Event(size_t size_, size_t state_size_=0) : POSHandle(size_, state_size_){
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Event"); }
};
using POSHandle_CUDA_Event_ptr = std::shared_ptr<POSHandle_CUDA_Event>;


/* ================================ End of Handle Definition ================================= */




/* ================================ Handle Manager Definition ================================ */

/*!
 *  \brief   manager for handles of POSHandle_CUDA_Context
 */
class POSHandleManager_CUDA_Context : public POSHandleManager<POSHandle_CUDA_Context> {
 public:
    /*!
     *  \brief  constructor
     */
    POSHandleManager_CUDA_Context() : POSHandleManager() {
        POSHandle_CUDA_Context_ptr ctx_handle;

        // allocate mocked context, and setup the actual context address
        if(unlikely(POS_SUCCESS != this->allocate_mocked_resource(
            /* handle */ &ctx_handle,
            /* related_handle */ std::map<uint64_t, std::vector<POSHandle_ptr>>(),
            /* size */ sizeof(CUcontext)
        ))){
            POS_ERROR_C_DETAIL("failed to allocate mocked CUDA context in the manager");
        }

        // record in the manager
        this->_handles.push_back(ctx_handle);
        this->latest_used_handle = this->_handles[0];
    }
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Stream
 */
class POSHandleManager_CUDA_Stream : public POSHandleManager<POSHandle_CUDA_Stream> {
 public:
    /*!
     *  \brief  constructor
     */
    POSHandleManager_CUDA_Stream(POSHandle_CUDA_Context_ptr ctx_handle) : POSHandleManager() {
        POSHandle_CUDA_Stream_ptr stream_handle;

        // allocate mocked stream
        if(unlikely(POS_SUCCESS != this->allocate_mocked_resource(
            /* handle */ &stream_handle,
            /* related_handle */ std::map<uint64_t, std::vector<POSHandle_ptr>>({
                { kPOS_ResourceTypeId_CUDA_Context, {ctx_handle} }
            }),
            /* size */ sizeof(CUstream),
            /* expected_addr */ 0
        ))){
            POS_ERROR_C_DETAIL("failed to allocate mocked CUDA stream in the manager");
        }
        stream_handle->set_server_addr((void*)(0));
        stream_handle->status = kPOS_HandleStatus_Active;

        // record in the manager
        this->_handles.push_back(stream_handle);
        this->latest_used_handle = this->_handles[0];
    }

    /*!
     *  \brief  allocate new mocked CUDA stream within the manager
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
        std::shared_ptr<POSHandle_CUDA_Stream>* handle,
        std::map</* type */ uint64_t, std::vector<POSHandle_ptr>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Context_ptr ctx_handle;
        POS_CHECK_POINTER(handle);

        // obtain the context to allocate buffer
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
            POS_WARN_C("no binded context provided to created the CUDA stream");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit_POSHandleManager_POSHandle_CUDA_Stream_allocate_mocked_resource;
        }
        ctx_handle = std::dynamic_pointer_cast<POSHandle_CUDA_Context>
                        (related_handles[kPOS_ResourceTypeId_CUDA_Context][0]);

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA stream in the manager");
            goto exit_POSHandleManager_POSHandle_CUDA_Stream_allocate_mocked_resource;
        }
        (*handle)->record_parent_handle(ctx_handle);

    exit_POSHandleManager_POSHandle_CUDA_Stream_allocate_mocked_resource:
        return retval;
    }

    /*!
     *  \brief  obtain a stream handle by given client-side address
     *  \param  client_addr the given client-side address
     *  \param  handle      the resulted handle
     *  \param  offset      pointer to store the offset of the given address from the base address
     *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
     *          POS_SUCCESS for successfully founded
     */
    pos_retval_t get_handle_by_client_addr(void* client_addr, std::shared_ptr<POSHandle_CUDA_Stream>* handle, uint64_t* offset=nullptr){
        // the client-side address of the default stream would be nullptr in CUDA, we do some hacking here
        if(likely(client_addr == 0)){
            *handle = this->_handles[0];
            return POS_SUCCESS;
        } else {
            return this->__get_handle_by_client_addr(client_addr, handle, offset);
        }
    }
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Stream
 */
class POSHandleManager_CUDA_Module : public POSHandleManager<POSHandle_CUDA_Module> {
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
        std::shared_ptr<POSHandle_CUDA_Module>* handle,
        std::map</* type */ uint64_t, std::vector<POSHandle_ptr>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Context_ptr context_handle;
        POS_CHECK_POINTER(handle);

        // obtain the context to allocate buffer
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
            POS_WARN_C("no binded context provided to created the CUDA module");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit_POSHandleManager_POSHandle_CUDA_Module_allocate_mocked_resource;
        }
        context_handle = std::dynamic_pointer_cast<POSHandle_CUDA_Context>
                        (related_handles[kPOS_ResourceTypeId_CUDA_Context][0]);

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA module in the manager");
            goto exit_POSHandleManager_POSHandle_CUDA_Module_allocate_mocked_resource;
        }
        (*handle)->record_parent_handle(context_handle);

    exit_POSHandleManager_POSHandle_CUDA_Module_allocate_mocked_resource:
        return retval;
    }
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Var
 */
class POSHandleManager_CUDA_Var : public POSHandleManager<POSHandle_CUDA_Var> {
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
        std::shared_ptr<POSHandle_CUDA_Var>* handle,
        std::map</* type */ uint64_t, std::vector<POSHandle_ptr>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Module_ptr module_handle;
        POS_CHECK_POINTER(handle);

        // obtain the context to allocate buffer
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Module) == 0)){
            POS_WARN_C("no binded module provided to create the CUDA var");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
        module_handle = std::dynamic_pointer_cast<POSHandle_CUDA_Module>
                        (related_handles[kPOS_ResourceTypeId_CUDA_Module][0]);

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


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Function
 */
class POSHandleManager_CUDA_Function : public POSHandleManager<POSHandle_CUDA_Function> {
 public:
    /*!
     *  \brief  allocate new mocked CUDA function within the manager
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
        std::shared_ptr<POSHandle_CUDA_Function>* handle,
        std::map</* type */ uint64_t, std::vector<POSHandle_ptr>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Module_ptr module_handle;
        POS_CHECK_POINTER(handle);

        // obtain the context to allocate buffer
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Module) == 0)){
            POS_WARN_C("no binded module provided to created the CUDA function");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit_POSHandleManager_POSHandle_CUDA_Function_allocate_mocked_resource;
        }
        module_handle = std::dynamic_pointer_cast<POSHandle_CUDA_Module>
                        (related_handles[kPOS_ResourceTypeId_CUDA_Module][0]);

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA stream in the manager");
            goto exit_POSHandleManager_POSHandle_CUDA_Function_allocate_mocked_resource;
        }
        (*handle)->record_parent_handle(module_handle);

    exit_POSHandleManager_POSHandle_CUDA_Function_allocate_mocked_resource:
        return retval;
    }
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Device
 */
class POSHandleManager_CUDA_Device : public POSHandleManager<POSHandle_CUDA_Device> {
 public:
    /*!
     *  \brief  constructor
     *  \note   insert actual #device to the device manager
     *          TBD: mock random number of devices
     */
    POSHandleManager_CUDA_Device(POSHandle_CUDA_Context_ptr ctx_handle) : POSHandleManager() {
        int num_device, i;
        POSHandle_CUDA_Device_ptr device_handle;

        // get number of physical devices on the machine
        if(unlikely(cudaSuccess != cudaGetDeviceCount(&num_device))){
            POS_ERROR_C_DETAIL("failed to call cudaGetDeviceCount");
        }
        if(unlikely(num_device == 0)){
            POS_ERROR_C_DETAIL("no CUDA device detected");
        }

        for(i=0; i<num_device; i++){
            if(unlikely(
                POS_SUCCESS != this->allocate_mocked_resource(
                    &device_handle,
                    std::map<uint64_t, std::vector<POSHandle_ptr>>({
                        { kPOS_ResourceTypeId_CUDA_Context, {ctx_handle} }
                    })
                )
            )){
                POS_ERROR_C_DETAIL("failed to allocate mocked CUDA device in the manager");
            }
            device_handle->device_id = i;
            device_handle->status = kPOS_HandleStatus_Active;
        }

        this->latest_used_handle = this->_handles[0];
    }

    /*!
     *  \brief  allocate new mocked CUDA device within the manager
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
        std::shared_ptr<POSHandle_CUDA_Device>* handle,
        std::map</* type */ uint64_t, std::vector<POSHandle_ptr>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Context_ptr ctx_handle;
        POS_CHECK_POINTER(handle);

        // obtain the context to allocate device
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
            POS_WARN_C("no binded context provided to created the CUDA stream");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
        ctx_handle = std::dynamic_pointer_cast<POSHandle_CUDA_Context>
                        (related_handles[kPOS_ResourceTypeId_CUDA_Context][0]);

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA device in the manager");
            goto exit;
        }
        (*handle)->record_parent_handle(ctx_handle);

    exit:
        return retval;
    }

    /*!
     *  \brief  obtain a device handle by given client-side address
     *  \param  client_addr the given client-side address
     *  \param  handle      the resulted handle
     *  \param  offset      pointer to store the offset of the given address from the base address
     *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
     *          POS_SUCCESS for successfully founded
     */
    pos_retval_t get_handle_by_client_addr(void* client_addr, std::shared_ptr<POSHandle_CUDA_Device>* handle, uint64_t* offset=nullptr){
        int device_id, i;
        POSHandle_CUDA_Device_ptr device_handle;

        // we cast the client address into device id here
        device_id = (int)client_addr;

        if(device_id >= this->_handles.size()){
            *handle = nullptr;
            return POS_FAILED_NOT_EXIST;
        }

        device_handle = this->_handles[device_id];        
        assert(device_id == device_handle->device_id);

        *handle = device_handle;
    }
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Memory
 */
class POSHandleManager_CUDA_Memory : public POSHandleManager<POSHandle_CUDA_Memory> {
 public:
    /*!
     *  \brief  constructor
     *  \note   the memory manager is a passthrough manager, which means that the client-side
     *          and server-side handle address are equal
     */
    POSHandleManager_CUDA_Memory() : POSHandleManager(/* passthrough */ true) {}

    /*!
     *  \brief  allocate new mocked CUDA memory within the manager
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
        std::shared_ptr<POSHandle_CUDA_Memory>* handle,
        std::map</* type */ uint64_t, std::vector<POSHandle_ptr>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Device_ptr device;
        POS_CHECK_POINTER(handle);

        // obtain the device to allocate buffer
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Device) == 0)){
            POS_WARN_C("no binded device provided to create the CUDA memory");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
        device = std::dynamic_pointer_cast<POSHandle_CUDA_Device>(related_handles[kPOS_ResourceTypeId_CUDA_Device][0]);

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA memory in the manager");
            goto exit;
        }
        (*handle)->record_parent_handle(device);

    exit:
        return retval;
    }
};


/*!
 *  \brief   manager for handles of POSHandle_CUDA_Event
 */
class POSHandleManager_CUDA_Event : public POSHandleManager<POSHandle_CUDA_Event> {
 public:
    /*!
     *  \brief  constructor
     */
    POSHandleManager_CUDA_Event() : POSHandleManager() {}
};


/* ============================= End of Handle Manager Definition ============================ */
