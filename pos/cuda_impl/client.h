#pragma once

#include <iostream>
#include <set>

#include "pos/include/common.h"
#include "pos/include/workspace.h"
#include "pos/include/client.h"

#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/cublas.h"
#include "pos/cuda_impl/api_index.h"
#include "pos/cuda_impl/parser.h"
#include "pos/cuda_impl/worker.h"


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
    POSClient_CUDA(POSWorkspace *ws, uint64_t id, pos_client_cxt_CUDA_t cxt) 
        : POSClient(id, cxt.cxt_base), _cxt_CUDA(cxt)
    {
        // raise parser thread
        this->parser = new POSParser_CUDA(/* ws */ ws, /* client */ this);
        POS_CHECK_POINTER(this->parser);
        this->parser->init();

        // raise worker thread
        this->worker = new POSWorker_CUDA(/* ws */ ws, /* client */ this);
        POS_CHECK_POINTER(this->worker);
        this->worker->init();
    }

    POSClient_CUDA(){}
    ~POSClient_CUDA(){}
    
    /*!
     *  \brief  instantiate handle manager for all used CUDA resources
     *  \note   the children class should replace this method to initialize their 
     *          own needed handle managers
     */
    void init_handle_managers() override {
        pos_retval_t retval;
        POSHandleManager_CUDA_Context *ctx_mgr;
        POSHandleManager_CUDA_Module *module_mgr;
        POSHandleManager_CUDA_Device *device_mgr;

        bool is_restoring = this->_cxt.checkpoint_file_path.size() > 0;

        POS_CHECK_POINTER(ctx_mgr = new POSHandleManager_CUDA_Context(is_restoring));
        this->handle_managers[kPOS_ResourceTypeId_CUDA_Context] = ctx_mgr;

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Stream] 
            = new POSHandleManager_CUDA_Stream(ctx_mgr->latest_used_handle, is_restoring);
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Stream]);

        device_mgr = new POSHandleManager_CUDA_Device(ctx_mgr->latest_used_handle, is_restoring);
        POS_CHECK_POINTER(device_mgr);
        this->handle_managers[kPOS_ResourceTypeId_CUDA_Device] = device_mgr;

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Module] = new POSHandleManager_CUDA_Module();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Module]);

        module_mgr = new POSHandleManager_CUDA_Module();
        POS_CHECK_POINTER(module_mgr);
        this->handle_managers[kPOS_ResourceTypeId_CUDA_Module] = module_mgr;

        if(this->_cxt.kernel_meta_path.size() > 0){
            retval = module_mgr->load_cached_function_metas(this->_cxt.kernel_meta_path);
            if(likely(retval == POS_SUCCESS)){
                this->_cxt.is_load_kernel_from_cache = true;
            }
        }
        
        this->handle_managers[kPOS_ResourceTypeId_CUDA_Function] = new POSHandleManager_CUDA_Function();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Function]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Var] = new POSHandleManager_CUDA_Var();
        POS_CHECK_POINTER(this->handle_managers[kPOS_ResourceTypeId_CUDA_Var]);

        this->handle_managers[kPOS_ResourceTypeId_CUDA_Memory] 
            = new POSHandleManager_CUDA_Memory(device_mgr->latest_used_handle, is_restoring);
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

        bool is_restoring = this->_cxt.checkpoint_file_path.size() > 0;

        ctx_mgr = (POSHandleManager_CUDA_Context*)(this->handle_managers[kPOS_ResourceTypeId_CUDA_Context]);
        POS_CHECK_POINTER(ctx_mgr);
        stream_mgr = (POSHandleManager_CUDA_Stream*)(this->handle_managers[kPOS_ResourceTypeId_CUDA_Stream]);
        POS_CHECK_POINTER(stream_mgr);
        device_mgr = (POSHandleManager_CUDA_Device*)(this->handle_managers[kPOS_ResourceTypeId_CUDA_Device]);
        POS_CHECK_POINTER(device_mgr);

        /*!
         *  \note   we only inserting new handles to the DAG while NOT restoring
         *  TODO:   we have no need to record handles in the DAG, remove it
         */
        if(is_restoring == false){
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
    }

    /*!
     *  \brief      deinit handle manager for all used resources
     *  \example    CUDA function manager should export the metadata of functions
     */
    void deinit_dump_handle_managers() override {
        this->__dump_hm_cuda_functions();
    }

    #if POS_MIGRATION_OPT_LEVEL > 0

    /*! 
     *  \brief  remote malloc memories during migration
     */
    void __TMP__migration_remote_malloc(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandleManager_CUDA_Memory *hm_memory;
        POSHandle_CUDA_Memory *memory_handle;
        uint64_t i, nb_handles;

        hm_memory = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Memory, POSHandleManager_CUDA_Memory);
        POS_CHECK_POINTER(hm_memory);

        nb_handles = hm_memory->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            memory_handle = hm_memory->get_handle_by_id(i);
            POS_CHECK_POINTER(memory_handle);
            if(unlikely(POS_SUCCESS != memory_handle->remote_restore())){
                POS_WARN("failed to remotely restore memory handle: server_addr(%p)", memory_handle->server_addr);
            }
        }

        // force switch to origin device
        cudaSetDevice(0);

    exit:
        ;
    }

    /*! 
     *  \brief  precopy stateful handles to another device during migration
     */
    void __TMP__migration_precopy() override {
        POSHandleManager_CUDA_Memory *hm_memory;
        POSHandle_CUDA_Memory *memory_handle;
        uint64_t i, nb_handles;
        cudaError_t cuda_rt_retval;
        uint64_t s_tick, e_tick;
        typename std::set<POSHandle_CUDA_Memory*>::iterator memory_handle_set_iter;

        uint64_t nb_precopy_handle = 0, precopy_size = 0; 
        uint64_t nb_host_handle = 0, host_handle_size = 0;

        hm_memory = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Memory, POSHandleManager_CUDA_Memory);
        POS_CHECK_POINTER(hm_memory);

        s_tick = POSUtilTimestamp::get_tsc();
        std::set<POSHandle_CUDA_Memory*>& modified_handles = hm_memory->get_modified_handles();
        if(likely(modified_handles.size() > 0)){
            for(memory_handle_set_iter = modified_handles.begin(); memory_handle_set_iter != modified_handles.end(); memory_handle_set_iter++){
                memory_handle = *memory_handle_set_iter;
                POS_CHECK_POINTER(memory_handle);

                // skip duplicated buffers
                if(hm_memory->is_host_stateful_handle(memory_handle)){
                    this->migration_ctx.__TMP__host_handles.insert(memory_handle);
                    nb_host_handle += 1;
                    host_handle_size += memory_handle->state_size;
                    // we still copy it, and deduplicate on the CPU-side
                    // continue;
                }

                cuda_rt_retval = cudaMemcpyPeerAsync(
                    /* dst */ memory_handle->remote_server_addr,
                    /* dstDevice */ 1,
                    /* src */ memory_handle->server_addr,
                    /* srcDevice */ 0,
                    /* count */ memory_handle->state_size,
                    /* stream */ (cudaStream_t)(this->worker->_migration_precopy_stream_id)
                );
                if(unlikely(cuda_rt_retval != CUDA_SUCCESS)){
                    POS_WARN("failed to p2p copy memory: server_addr(%p), state_size(%lu)", memory_handle->server_addr, memory_handle->state_size);
                    continue;
                }
            
                cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(this->worker->_migration_precopy_stream_id));
                if(unlikely(cuda_rt_retval != CUDA_SUCCESS)){
                    POS_WARN("failed to synchronize p2p copy memory: server_addr(%p), state_size(%lu)", memory_handle->server_addr, memory_handle->state_size);
                    continue;
                }

                this->migration_ctx.precopy_handles.insert(memory_handle);
                nb_precopy_handle += 1;
                precopy_size += memory_handle->state_size;
            }
        }
        e_tick = POSUtilTimestamp::get_tsc();

        nb_handles = hm_memory->get_nb_handles();
        POS_LOG(
            "pre-copy finished: "
            "duration(%lf us), "
            "nb_precopy_handle(%lu), precopy_size(%lu Bytes), "
            "nb_host_handle(%lu), host_handle_size(%lu Bytes)"
            ,
            POS_TSC_TO_USEC(e_tick-s_tick),
            nb_precopy_handle, precopy_size,
            nb_host_handle, host_handle_size
        );

        hm_memory->clear_modified_handle();

    exit:
        ;
    }
    
    /*! 
     *  \brief  deltacopy stateful handles to another device during migration
     */
    void __TMP__migration_deltacopy() override {
        pos_retval_t retval = POS_SUCCESS;
        POSHandleManager_CUDA_Memory *hm_memory;
        typename std::set<POSHandle*>::iterator set_iter;
        POSHandle *memory_handle;
        uint64_t nb_deltacopy_handle = 0, deltacopy_size = 0;
        cudaError_t cuda_rt_retval;
        uint64_t s_tick, e_tick;

        hm_memory = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Memory, POSHandleManager_CUDA_Memory);
        POS_CHECK_POINTER(hm_memory);

        s_tick = POSUtilTimestamp::get_tsc();
        for(set_iter = this->migration_ctx.invalidated_handles.begin(); set_iter != this->migration_ctx.invalidated_handles.end(); set_iter++){
            memory_handle = *set_iter;

            // skip duplicated buffers
            if(hm_memory->is_host_stateful_handle((POSHandle_CUDA_Memory*)(memory_handle))){
                continue;
            }

            cuda_rt_retval = cudaMemcpyPeerAsync(
                /* dst */ memory_handle->remote_server_addr,
                /* dstDevice */ 1,
                /* src */ memory_handle->server_addr,
                /* srcDevice */ 0,
                /* count */ memory_handle->state_size,
                /* stream */ (cudaStream_t)(this->worker->_migration_precopy_stream_id)
            );
            if(unlikely(cuda_rt_retval != CUDA_SUCCESS)){
                POS_WARN("failed to p2p delta copy memory: server_addr(%p), state_size(%lu)", memory_handle->server_addr, memory_handle->state_size);
                continue;
            }

            cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(this->worker->_migration_precopy_stream_id));
            if(unlikely(cuda_rt_retval != CUDA_SUCCESS)){
                POS_WARN("failed to synchronize p2p delta copy memory: server_addr(%p), state_size(%lu)", memory_handle->server_addr, memory_handle->state_size);
                continue;
            }

            nb_deltacopy_handle += 1;
            deltacopy_size += memory_handle->state_size;
        }
        e_tick = POSUtilTimestamp::get_tsc();

        POS_LOG(
            "    delta-copy finished: "
            "duration(%lf us), nb_delta_handle(%lu), delta_copy_size(%lu Bytes)", 
            POS_TSC_TO_USEC(e_tick-s_tick), nb_deltacopy_handle, deltacopy_size
        );

    exit:
        ;
    }

    void __TMP__migration_tear_context(bool do_tear_module) override {
        POSHandleManager_CUDA_Context *hm_context;
        POSHandleManager_cuBLAS_Context *hm_cublas;
        POSHandleManager_CUDA_Stream *hm_stream;
        POSHandleManager_CUDA_Module *hm_module;
        POSHandleManager_CUDA_Function *hm_function;

        POSHandle_CUDA_Context *context_handle;
        POSHandle_cuBLAS_Context *cublas_handle;
        POSHandle_CUDA_Stream *stream_handle;
        POSHandle_CUDA_Module *module_handle;
        POSHandle_CUDA_Function *function_handle;

        uint64_t i, nb_handles;

        hm_context = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Context, POSHandleManager_CUDA_Context);
        POS_CHECK_POINTER(hm_context);
        hm_cublas = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_cuBLAS_Context, POSHandleManager_cuBLAS_Context);
        POS_CHECK_POINTER(hm_cublas);
        hm_stream = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Stream, POSHandleManager_CUDA_Stream);
        POS_CHECK_POINTER(hm_stream);
        hm_module = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Module, POSHandleManager_CUDA_Module);
        POS_CHECK_POINTER(hm_module);
        hm_function = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Function, POSHandleManager_CUDA_Function);
        POS_CHECK_POINTER(hm_function);

        POS_LOG("destory cublas")
        nb_handles = hm_cublas->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            cublas_handle = hm_cublas->get_handle_by_id(i);
            POS_CHECK_POINTER(cublas_handle);
            if(cublas_handle->status == kPOS_HandleStatus_Active){
                cublasDestroy_v2((cublasHandle_t)(cublas_handle->server_addr));
                cublas_handle->status = kPOS_HandleStatus_Broken;
            }
        }

        // destory streams
        POS_LOG("destory streams")
        nb_handles = hm_stream->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            stream_handle = hm_stream->get_handle_by_id(i);
            POS_CHECK_POINTER(stream_handle);
            if(stream_handle->status == kPOS_HandleStatus_Active){
                cudaStreamDestroy((cudaStream_t)(stream_handle->server_addr));
                stream_handle->status = kPOS_HandleStatus_Broken;
            }
        }

        if(do_tear_module){
            POS_LOG("modules & functions")
            nb_handles = hm_module->get_nb_handles();
            for(i=0; i<nb_handles; i++){
                module_handle = hm_module->get_handle_by_id(i);
                POS_CHECK_POINTER(module_handle);
                if(module_handle->status == kPOS_HandleStatus_Active){
                    cuModuleUnload((CUmodule)(module_handle->server_addr));
                    module_handle->status = kPOS_HandleStatus_Broken;
                }
            }

            nb_handles = hm_function->get_nb_handles();
            for(i=0; i<nb_handles; i++){
                function_handle = hm_function->get_handle_by_id(i);
                if(function_handle->status == kPOS_HandleStatus_Active){
                    function_handle->status = kPOS_HandleStatus_Broken;
                }
            }
        }
    }

    void __TMP__migration_restore_context(bool do_restore_module){
        POSHandleManager_CUDA_Context *hm_context;
        POSHandleManager_cuBLAS_Context *hm_cublas;
        POSHandleManager_CUDA_Stream *hm_stream;
        POSHandleManager_CUDA_Module *hm_module;
        POSHandleManager_CUDA_Function *hm_function;

        POSHandle_CUDA_Context *context_handle;
        POSHandle_cuBLAS_Context *cublas_handle;
        POSHandle_CUDA_Stream *stream_handle;
        POSHandle_CUDA_Module *module_handle;
        POSHandle_CUDA_Function *function_handle;

        uint64_t i, nb_handles;

        hm_context = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Context, POSHandleManager_CUDA_Context);
        POS_CHECK_POINTER(hm_context);
        hm_cublas = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_cuBLAS_Context, POSHandleManager_cuBLAS_Context);
        POS_CHECK_POINTER(hm_cublas);
        hm_stream = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Stream, POSHandleManager_CUDA_Stream);
        POS_CHECK_POINTER(hm_stream);
        hm_module = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Module, POSHandleManager_CUDA_Module);
        POS_CHECK_POINTER(hm_module);
        hm_function = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Function, POSHandleManager_CUDA_Function);
        POS_CHECK_POINTER(hm_function);

        // restore cublas
        nb_handles = hm_cublas->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            cublas_handle = hm_cublas->get_handle_by_id(i);
            cublas_handle->restore();
        }

        // restore streams
        nb_handles = hm_stream->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            stream_handle = hm_stream->get_handle_by_id(i);
            stream_handle->restore();
        }

        // restore modules & functions
        if(do_restore_module){
            nb_handles = hm_module->get_nb_handles();
            for(i=0; i<nb_handles; i++){
                module_handle = hm_module->get_handle_by_id(i);
                module_handle->restore();
            }

            nb_handles = hm_function->get_nb_handles();
            for(i=0; i<nb_handles; i++){
                function_handle = hm_function->get_handle_by_id(i);
                function_handle->restore();
            }
        }
    }

    void __TMP__migration_ondemand_reload() override {
        pos_retval_t retval = POS_SUCCESS;
        typename std::set<POSHandle*>::iterator set_iter;
        POSHandle *memory_handle;
        cudaError_t cuda_rt_retval;

        uint64_t s_tick, e_tick;
        uint64_t nb_handles = 0, reload_size = 0;

        s_tick = POSUtilTimestamp::get_tsc();
        for(
            set_iter = this->migration_ctx.__TMP__host_handles.begin();
            set_iter != this->migration_ctx.__TMP__host_handles.end(); 
            set_iter++
        ){
            memory_handle = *set_iter;
            POS_CHECK_POINTER(memory_handle);

            if(unlikely(POS_SUCCESS != memory_handle->reload_state(this->worker->_migration_precopy_stream_id))){
                POS_WARN("failed to reload state of handle within on-demand reload thread: server_addr(%p)", memory_handle->server_addr);
            } else {
                memory_handle->state_status = kPOS_HandleStatus_StateReady;
                nb_handles += 1;
                reload_size += memory_handle->state_size;
            }
        }
        e_tick = POSUtilTimestamp::get_tsc();
        POS_LOG("on-demand reload finished: %lf us, #handles(%lu), reload_size(%lu Bytes), stream_id(%p)", POS_TSC_TO_USEC(e_tick-s_tick), nb_handles, reload_size, this->worker->_migration_precopy_stream_id);
    }

    void __TMP__migration_allcopy() override {
        POSHandleManager_CUDA_Memory *hm_memory;
        uint64_t i, nb_handles;
        uint64_t s_tick, e_tick;
        uint64_t dump_size = 0;
        POSHandle_CUDA_Memory *memory_handle;

        hm_memory = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Memory, POSHandleManager_CUDA_Memory);
        POS_CHECK_POINTER(hm_memory);

        s_tick = POSUtilTimestamp::get_tsc();
        nb_handles = hm_memory->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            memory_handle = hm_memory->get_handle_by_id(i);
            if(unlikely(memory_handle->status != kPOS_HandleStatus_Active)){
                continue;
            }

            if(unlikely(POS_SUCCESS != memory_handle->checkpoint_sync(
                /* version_id */ memory_handle->latest_version, 
                /* stream_id */ 0
            ))){
                POS_WARN(
                    "failed to checkpoint handle: server_addr(%p), state_size(%lu)",
                    memory_handle->server_addr,
                    memory_handle->state_size
                );
            }
            
            dump_size += memory_handle->state_size;
        }
        e_tick = POSUtilTimestamp::get_tsc();

        POS_LOG(
            "sync dump finished: duration(%lf us), nb_handles(%lu), dump_size(%lu Bytes)",
            POS_TSC_TO_USEC(e_tick-s_tick), nb_handles, dump_size
        );
    }

    void __TMP__migration_allreload() override {
        POSHandleManager_CUDA_Memory *hm_memory;
        uint64_t i, nb_handles;
        uint64_t s_tick, e_tick;
        uint64_t reload_size = 0;
        POSHandle_CUDA_Memory *memory_handle;

        hm_memory = pos_get_client_typed_hm(this, kPOS_ResourceTypeId_CUDA_Memory, POSHandleManager_CUDA_Memory);
        POS_CHECK_POINTER(hm_memory);

        s_tick = POSUtilTimestamp::get_tsc();
        nb_handles = hm_memory->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            memory_handle = hm_memory->get_handle_by_id(i);
            if(unlikely(memory_handle->status != kPOS_HandleStatus_Active)){
                continue;
            }

            if(unlikely(POS_SUCCESS != memory_handle->reload_state(/* stream_id */ 0))){
                POS_WARN(
                    "failed to reload state of handle: server_addr(%p), state_size(%lu)",
                    memory_handle->server_addr,
                    memory_handle->state_size
                );
            }
            
            reload_size += memory_handle->state_size;
        }
        e_tick = POSUtilTimestamp::get_tsc();

        POS_LOG(
            "sync reload finished: duration(%lf us), nb_handles(%lu), reload_size(%lu Bytes)",
            POS_TSC_TO_USEC(e_tick-s_tick), nb_handles, reload_size
        );
    }

    #endif // POS_MIGRATION_OPT_LEVEL > 0

 protected:
    /*!
     *  \brief  allocate mocked resource in the handle manager according to given type
     *  \note   this function is used during restore phrase
     *  \param  type_id specified resource type index
     *  \param  bin_ptr pointer to the binary area
     *  \return POS_SUCCESS for successfully allocated
     */
    pos_retval_t __allocate_typed_resource_from_binary(pos_resource_typeid_t type_id, void* bin_ptr) override {
        pos_retval_t retval = POS_SUCCESS;
        
        if(unlikely(this->handle_managers.count(type_id) == 0)){
            POS_ERROR_C_DETAIL(
                "no handle manager with specified type registered, this is a bug: type_id(%lu)", type_id
            );
        }

        switch (type_id)
        {
        case kPOS_ResourceTypeId_CUDA_Context:
            POSHandleManager<POSHandle_CUDA_Context> *hm_context;
            POS_CHECK_POINTER(
                hm_context = (POSHandleManager<POSHandle_CUDA_Context>*)(this->handle_managers[type_id])
            );
            hm_context->allocate_mocked_resource_from_binary(bin_ptr);
            break;

        case kPOS_ResourceTypeId_CUDA_Module:
            /*!
             *  \note   if the resource is cuda module, then we need to use POSHandleManager with
             *          specific type, in order to invoke specified init_ckpt_bag for CUDA module, 
             *          as CUDA module would contains host-side checkpoint record
             */
            POSHandleManager<POSHandle_CUDA_Module> *hm_module;
            POS_CHECK_POINTER(
                hm_module = (POSHandleManager<POSHandle_CUDA_Module>*)(this->handle_managers[type_id])
            );
            hm_module->allocate_mocked_resource_from_binary(bin_ptr);
            break;

        case kPOS_ResourceTypeId_CUDA_Function:
            POSHandleManager<POSHandle_CUDA_Function> *hm_function;
            POS_CHECK_POINTER(
                hm_function = (POSHandleManager<POSHandle_CUDA_Function>*)(this->handle_managers[type_id])
            );
            hm_function->allocate_mocked_resource_from_binary(bin_ptr);
            break;

        case kPOS_ResourceTypeId_CUDA_Var:
            POSHandleManager<POSHandle_CUDA_Var> *hm_var;
            POS_CHECK_POINTER(
                hm_var = (POSHandleManager<POSHandle_CUDA_Var>*)(this->handle_managers[type_id])
            );
            hm_var->allocate_mocked_resource_from_binary(bin_ptr);
            break;

        case kPOS_ResourceTypeId_CUDA_Device:
            /*!
             *  \note   if the resource is cuda device, then we need to use POSHandleManager with
             *          specific type, as we need to setup the lastest-used handle inside the
             *          handle manager
             */
            POSHandleManager<POSHandle_CUDA_Device> *hm_device;
            POSHandle_CUDA_Device *device_handle;
            POS_CHECK_POINTER(
                hm_device = (POSHandleManager<POSHandle_CUDA_Device>*)(this->handle_managers[type_id])
            );
            POS_CHECK_POINTER(device_handle = hm_device->allocate_mocked_resource_from_binary(bin_ptr));

            if(device_handle->is_lastest_used_handle == true){
                hm_device->latest_used_handle = device_handle;
            }
            break;

        case kPOS_ResourceTypeId_CUDA_Memory:
            /*!
             *  \note   if the resource is CUDA memory, then we need to use POSHandleManager with
             *          specific type, in order to invoke specified init_ckpt_bag for CUDA memory 
             *          inside the function allocate_mocked_resource_from_binary
             */
            POSHandleManager<POSHandle_CUDA_Memory> *hm_memory;
            POS_CHECK_POINTER(
                hm_memory = (POSHandleManager<POSHandle_CUDA_Memory>*)(this->handle_managers[type_id])
            );
            hm_memory->allocate_mocked_resource_from_binary(bin_ptr);
            break;

        case kPOS_ResourceTypeId_CUDA_Stream:
            POSHandleManager<POSHandle_CUDA_Stream> *hm_stream;
            POS_CHECK_POINTER(
                hm_stream = (POSHandleManager<POSHandle_CUDA_Stream>*)(this->handle_managers[type_id])
            );
            hm_stream->allocate_mocked_resource_from_binary(bin_ptr);
            break;

        case kPOS_ResourceTypeId_CUDA_Event:
            POSHandleManager<POSHandle_CUDA_Event> *hm_event;
            POS_CHECK_POINTER(
                hm_event = (POSHandleManager<POSHandle_CUDA_Event>*)(this->handle_managers[type_id])
            );
            hm_event->allocate_mocked_resource_from_binary(bin_ptr);
            break;

        case kPOS_ResourceTypeId_cuBLAS_Context:
            POSHandleManager<POSHandle_cuBLAS_Context> *hm_cublas_cxt;
            POS_CHECK_POINTER(
                hm_cublas_cxt = (POSHandleManager<POSHandle_cuBLAS_Context>*)(this->handle_managers[type_id])
            );
            hm_cublas_cxt->allocate_mocked_resource_from_binary(bin_ptr);
            break;

        default:
            POS_ERROR_C_DETAIL(
                "no handle manager with specified type registered, this is a bug: type_id(%lu)", type_id
            );
        }

    exit:
        return retval;
    }


    /*!
     *  \brief  obtain all resource type indices of this client
     *  \return all resource type indices of this client
     */
    std::set<pos_resource_typeid_t> __get_resource_idx() override {
        return  std::set<pos_resource_typeid_t>({
            kPOS_ResourceTypeId_CUDA_Context,
            kPOS_ResourceTypeId_CUDA_Module,
            kPOS_ResourceTypeId_CUDA_Function,
            kPOS_ResourceTypeId_CUDA_Var,
            kPOS_ResourceTypeId_CUDA_Device,
            kPOS_ResourceTypeId_CUDA_Memory,
            kPOS_ResourceTypeId_CUDA_Stream,
            kPOS_ResourceTypeId_CUDA_Event,
            kPOS_ResourceTypeId_cuBLAS_Context
        });
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
        if(likely(this->_cxt.is_load_kernel_from_cache == true)){
            goto exit;
        }
        
        hm_function 
            = (POSHandleManager_CUDA_Function*)(this->handle_managers[kPOS_ResourceTypeId_CUDA_Function]);
        POS_CHECK_POINTER(hm_function);

        file_path = std::string("./") + this->_cxt.job_name + std::string("_kernel_metas.txt");
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
