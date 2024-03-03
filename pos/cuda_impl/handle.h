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
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Context(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Context;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Context(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
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

        this->mark_status(kPOS_HandleStatus_Active);

        return POS_SUCCESS;
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Context"); }
};


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

    // function descriptors under this module
    std::vector<POSCudaFunctionDesp*> function_desps;
};


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
    std::shared_ptr<char[]> name;
};


/*!
 *  \brief  handle for cuda function
 */
class POSHandle_CUDA_Function : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Function(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_) 
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Function;
        this->has_verified_params = false;
    }
    
    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Function(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Function"); }

    // name of the kernel
    std::shared_ptr<char[]> name;

    std::string signature;

    // number of parameters within this function
    uint32_t nb_params;

    // offset of each parameter
    std::vector<uint32_t> param_offsets;

    // size of each parameter
    std::vector<uint32_t> param_sizes;

    // index of those parameter which is a input pointer (const pointer)
    std::vector<uint32_t> input_pointer_params;

    // index of those parameter which is a output pointer (non-const pointer)
    std::vector<uint32_t> output_pointer_params;

    // index of those non-pointer parameters that may carry pointer inside their values
    std::vector<uint32_t> suspicious_params;
    bool has_verified_params;

    /*!
     *  \brief  confirmed suspicious parameters: index of the parameter -> offset from the base address
     *  \note   the structure might contains multiple pointers, so we use vector of pairs instead of 
     *          map to store these relationships
     */
    std::vector<std::pair<uint32_t,uint64_t>> confirmed_suspicious_params;

    // cbank parameter size (p.s., what is this?)
    uint64_t cbank_param_size;
};


/*!
 *  \brief  handle for cuda device
 */
class POSHandle_CUDA_Device : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Device(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Device;
    }
    
    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Device(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
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


/*!
 *  \brief  handle for cuda memory
 */
class POSHandle_CUDA_Memory : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Memory(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Memory;

        // initialize checkpoint bag
        if(unlikely(POS_SUCCESS != this->init_ckpt_bag())){
            POS_ERROR_C_DETAIL("failed to inilialize checkpoint bag");
        }
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Memory(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    static void* __checkpoint_allocator(uint64_t state_size) {
        cudaError_t cuda_rt_retval;
        void *ptr;

        if(unlikely(state_size == 0)){
            POS_WARN_DETAIL("try to allocate checkpoint with state size of 0");
            return nullptr;
        }

        cuda_rt_retval = cudaMallocHost(&ptr, state_size);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_DETAIL("failed cudaMallocHost, error: %d", cuda_rt_retval);
            return nullptr;
        }

        return ptr;
    }

    static void __checkpoint_deallocator(void* data){
        cudaError_t cuda_rt_retval;
        if(likely(data != nullptr)){
            cuda_rt_retval = cudaFreeHost(data);
            if(unlikely(cuda_rt_retval != cudaSuccess)){
                POS_WARN_DETAIL("failed cudaFreeHost, error: %d", cuda_rt_retval);
            }
        }
    }

    /*!
     *  \brief  checkpoint the state of the resource behind this handle
     *  \note   only handle of stateful resource should implement this method
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t checkpoint(uint64_t version_id, uint64_t stream_id=0) const override { 
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;
        POSCheckpointSlot* ckpt_slot;

        struct rusage s_r_usage, e_r_usage;
        uint64_t s_tick = 0, e_tick = 0;
        double duration_us = 0;
        
        // apply new checkpoint slot
        if(unlikely(
            POS_SUCCESS != this->ckpt_bag->apply_new_checkpoint(/* version */ version_id, /* ptr */ &ckpt_slot)
        )){
            POS_WARN_C("failed to apply checkpoint slot");
            retval = POS_FAILED;
            goto exit;
        }

        // checkpoint
        // TODO: takes long time
        // if(unlikely(getrusage(RUSAGE_SELF, &s_r_usage) != 0)){
        //     POS_ERROR_DETAIL("failed to call getrusage");
        // }
        // s_tick = POSUtilTimestamp::get_tsc();
        cuda_rt_retval = cudaMemcpyAsync(
            /* dst */ ckpt_slot->expose_pointer(), 
            /* src */ this->server_addr,
            /* size */ this->state_size,
            /* kind */ cudaMemcpyDeviceToHost,
            /* stream */ (cudaStream_t)(stream_id)
        );
        // e_tick = POSUtilTimestamp::get_tsc();
        // if(unlikely(getrusage(RUSAGE_SELF, &e_r_usage) != 0)){
        //     POS_ERROR_DETAIL("failed to call getrusage");
        // }

        // duration_us = POS_TSC_RANGE_TO_USEC(e_tick, s_tick);

        // POS_LOG(
        //     "copy duration: %lf us, size: %lu Bytes, bandwidth: %lf Mbps, page fault: %ld (major), %ld (minor)",
        //     duration_us,
        //     this->state_size,
        //     (double)(this->state_size) / duration_us,
        //     e_r_usage.ru_majflt - s_r_usage.ru_majflt,
        //     e_r_usage.ru_minflt - s_r_usage.ru_minflt
        // );

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
     *  \brief  invalidate the latest checkpoint due to computation / checkpoint conflict
     *          (used by async checkpoint)
     *  \return POS_SUCCESS for successfully invalidate
     *          POS_NOT_READY for no checkpoint had been record
     */
    pos_retval_t invalidate_latest_checkpoint() const override {
        return this->ckpt_bag->invalidate_latest_checkpoint();
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Memory"); }

 protected:
    /*!
     *  \brief  initialize checkpoint bag of this handle
     *  \note   it must be implemented by different implementations of stateful 
     *          handle, as they might require different allocators and deallocators
     *  \return POS_SUCCESS for successfully initialization
     */
    pos_retval_t init_ckpt_bag() override { 
        this->ckpt_bag = new POSCheckpointBag(
            this->state_size,
            this->__checkpoint_allocator,
            this->__checkpoint_deallocator
        );
        POS_CHECK_POINTER(this->ckpt_bag);
        return POS_SUCCESS;
    }
};


/*!
 *  \brief  handle for cuda stream
 */
class POSHandle_CUDA_Stream : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Stream(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_), is_capturing(false)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Stream;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Stream(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_), is_capturing(false)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Stream"); }

    bool is_capturing;
};


/*!
 *  \brief  handle for cuda event
 */
class POSHandle_CUDA_Event : public POSHandle {
 public:
    /*!
     *  \brief  constructor
     *  \param  client_addr     the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     */
    POSHandle_CUDA_Event(void *client_addr_, size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(client_addr_, size_, hm, state_size_)
    {
        this->resource_type_id = kPOS_ResourceTypeId_CUDA_Event;
    }

    /*!
     *  \note   never called, just for passing compilation
     */
    POSHandle_CUDA_Event(size_t size_, void* hm, size_t state_size_=0)
        : POSHandle(size_, hm, state_size_)
    {
        POS_ERROR_C_DETAIL("shouldn't be called");
    }

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    std::string get_resource_name(){ return std::string("CUDA Event"); }
};


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
        POSHandle_CUDA_Context *ctx_handle;

        // allocate mocked context, and setup the actual context address
        if(unlikely(POS_SUCCESS != this->allocate_mocked_resource(
            /* handle */ &ctx_handle,
            /* related_handle */ std::map<uint64_t, std::vector<POSHandle*>>(),
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
    POSHandleManager_CUDA_Stream(POSHandle_CUDA_Context* ctx_handle) : POSHandleManager() {
        POSHandle_CUDA_Stream *stream_handle;

        // allocate mocked stream
        if(unlikely(POS_SUCCESS != this->allocate_mocked_resource(
            /* handle */ &stream_handle,
            /* related_handle */ std::map<uint64_t, std::vector<POSHandle*>>({
                { kPOS_ResourceTypeId_CUDA_Context, {ctx_handle} }
            }),
            /* size */ sizeof(CUstream),
            /* expected_addr */ 0
        ))){
            POS_ERROR_C_DETAIL("failed to allocate mocked CUDA stream in the manager");
        }
        stream_handle->set_server_addr((void*)(0));
        stream_handle->mark_status(kPOS_HandleStatus_Active);

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
        POSHandle_CUDA_Stream** handle,
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *ctx_handle;

        POS_CHECK_POINTER(handle);

        // obtain the context to allocate buffer
    #if POS_ENABLE_DEBUG_CHECK
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
            POS_WARN_C("no binded context provided to created the CUDA stream");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
    #endif

        ctx_handle = related_handles[kPOS_ResourceTypeId_CUDA_Context][0];
        POS_CHECK_POINTER(ctx_handle);

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA stream in the manager");
            goto exit;
        }

        (*handle)->record_parent_handle(ctx_handle);

    exit:
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
    pos_retval_t get_handle_by_client_addr(void* client_addr, POSHandle_CUDA_Stream** handle, uint64_t* offset=nullptr){
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
 public:
    std::map<std::string, POSCudaFunctionDesp_t*> cached_function_desps;

    pos_retval_t load_cached_function_metas(std::string &file_path){
        pos_retval_t retval = POS_SUCCESS;
        uint64_t i;
        std::string line, stream;
        POSCudaFunctionDesp_t *new_desp;

        auto generate_desp_from_meta = [](std::vector<std::string>& metas) -> POSCudaFunctionDesp_t* {
            uint64_t i;
            std::vector<uint32_t> param_offsets;
            std::vector<uint32_t> param_sizes;
            std::vector<uint32_t> input_pointer_params;
            std::vector<uint32_t> output_pointer_params;
            std::vector<uint32_t> suspicious_params;
            std::vector<std::pair<uint32_t,uint64_t>> confirmed_suspicious_params;
            bool confirmed;
            uint64_t nb_input_pointer_params, nb_output_pointer_params, nb_suspicious_params, nb_inout_params, has_verified_params;
            uint64_t ptr;

            POSCudaFunctionDesp_t *new_desp = new POSCudaFunctionDesp_t();
            POS_CHECK_POINTER(new_desp);

            ptr = 0;

            // mangled name of the kernel
            new_desp->set_name(metas[ptr].c_str());
            ptr++;

            // number of paramters
            new_desp->nb_params = std::stoul(metas[ptr]);
            ptr++;

            // offset of each parameter
            for(i=0; i<new_desp->nb_params; i++){
                param_offsets.push_back(std::stoul(metas[ptr+i]));   
            }
            ptr += new_desp->nb_params;
            new_desp->param_offsets = param_offsets;

            // size of each parameter
            for(i=0; i<new_desp->nb_params; i++){
                param_sizes.push_back(std::stoul(metas[ptr+i]));
            }
            ptr += new_desp->nb_params;
            new_desp->param_sizes = param_sizes;

            // index of those parameter which is a input pointer (const pointer)
            nb_input_pointer_params = std::stoul(metas[ptr]);
            ptr++;
            for(i=0; i<nb_input_pointer_params; i++){
                input_pointer_params.push_back(std::stoul(metas[ptr+i]));
            }
            ptr += nb_input_pointer_params;
            new_desp->input_pointer_params = input_pointer_params;

            // index of those parameter which is a output pointer (non-const pointer)
            nb_output_pointer_params = std::stoul(metas[ptr]);
            ptr++;
            for(i=0; i<nb_output_pointer_params; i++){
                output_pointer_params.push_back(std::stoul(metas[ptr+i]));
            }
            ptr += nb_output_pointer_params;
            new_desp->output_pointer_params = output_pointer_params;

            // index of those parameter which is a output pointer (non-const pointer)
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
                nb_inout_params = std::stoul(metas[ptr]);
                ptr++;
                for(i=0; i<nb_inout_params; i++){
                    confirmed_suspicious_params.push_back({
                        /* param_index */ std::stoul(metas[ptr+2*i]), /* offset */ std::stoul(metas[ptr+2*i+1])
                    });
                }
                ptr += nb_inout_params;
                new_desp->confirmed_suspicious_params = confirmed_suspicious_params;
            }

            // cbank parameter size (p.s., what is this?)
            new_desp->cbank_param_size = std::stoul(metas[ptr].c_str());

            return new_desp;
        };

        std::ifstream file(file_path.c_str(), std::ios::in);
        if(likely(file.is_open())){
            POS_LOG("parsing cached kernel metas from file %s...", i, file_path.c_str());
            i = 0;
            while (std::getline(file, line)) {
                // split by ","
                std::stringstream ss(line);
                std::string segment;
                std::vector<std::string> metas;
                while (std::getline(ss, segment, ',')) { metas.push_back(segment); }

                // parse
                new_desp = generate_desp_from_meta(metas);
                cached_function_desps[std::string(new_desp->name.get())] = new_desp;

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

    #if POS_ENABLE_DEBUG_CHECK
        // obtain the context to allocate buffer
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
            POS_WARN_C("no binded context provided to created the CUDA module");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
    #endif

        context_handle = related_handles[kPOS_ResourceTypeId_CUDA_Context][0];
        POS_CHECK_POINTER(context_handle);

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA module in the manager");
            goto exit;
        }

        (*handle)->record_parent_handle(context_handle);

    exit:
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
        POSHandle_CUDA_Function** handle,
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
            POS_WARN_C("no binded module provided to created the CUDA function");
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
    POSHandleManager_CUDA_Device(POSHandle_CUDA_Context* ctx_handle) : POSHandleManager() {
        int num_device, i;
        POSHandle_CUDA_Device *device_handle;

        // get number of physical devices on the machine
        // TODO: we shouldn't call this function here?
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
                    std::map<uint64_t, std::vector<POSHandle*>>({
                        { kPOS_ResourceTypeId_CUDA_Context, {ctx_handle} }
                    })
                )
            )){
                POS_ERROR_C_DETAIL("failed to allocate mocked CUDA device in the manager");
            }
            device_handle->device_id = i;
            device_handle->mark_status(kPOS_HandleStatus_Active);
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
        POSHandle_CUDA_Device** handle,
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *ctx_handle;
        POS_CHECK_POINTER(handle);

        // obtain the context to allocate device
    #if POS_ENABLE_DEBUG_CHECK
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
            POS_WARN_C("no binded context provided to created the CUDA stream");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
    #endif

        ctx_handle = related_handles[kPOS_ResourceTypeId_CUDA_Context][0];
        POS_CHECK_POINTER(ctx_handle);

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
    pos_retval_t get_handle_by_client_addr(void* client_addr, POSHandle_CUDA_Device** handle, uint64_t* offset=nullptr){
        int device_id, i;
        uint64_t device_id_u64;
        POSHandle_CUDA_Device *device_handle;

        // we cast the client address into device id here
        device_id_u64 = (uint64_t)(client_addr);
        device_id = (int)(device_id_u64);

        if(unlikely(device_id >= this->_handles.size())){
            *handle = nullptr;
            return POS_FAILED_NOT_EXIST;
        }

        device_handle = this->_handles[device_id];        
        POS_ASSERT(device_id == device_handle->device_id);

        *handle = device_handle;

        return POS_SUCCESS;
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
        POSHandle_CUDA_Memory** handle,
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size=kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    ) override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *device_handle;

        POS_CHECK_POINTER(handle);

        // obtain the device to allocate buffer
    #if POS_ENABLE_DEBUG_CHECK
        if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Device) == 0)){
            POS_WARN_C("no binded device provided to create the CUDA memory");
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
    #endif
    
        device_handle = related_handles[kPOS_ResourceTypeId_CUDA_Device][0];

        retval = this->__allocate_mocked_resource(handle, size, expected_addr, state_size);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to allocate mocked CUDA memory in the manager");
            goto exit;
        }

        (*handle)->record_parent_handle(device_handle);

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
