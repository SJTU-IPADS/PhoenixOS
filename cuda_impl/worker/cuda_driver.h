#include <iostream>

#include "pos/common.h"
#include "pos/cuda_impl/worker.h"

#include <cuda_runtime_api.h>

namespace wk_functions {


/*!
 *  \related    cuModuleLoadData
 *  \brief      load CUmodule down to the driver, which contains PTX/SASS binary
 */
namespace cu_module_load_data {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_ptr module_handle;
        POSMem_ptr fatbin_binary;
        CUresult res;
        CUmodule module = NULL;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        module_handle = pos_api_handle(wqe, kPOS_ResourceTypeId_CUDA_Module, 0);
        POS_CHECK_POINTER(module_handle);

        fatbin_binary = module_handle->host_value_map[wqe->dag_vertex_id].first;

        wqe->api_cxt->return_code = cuModuleLoadData(&module, fatbin_binary.get());

        // record server address
        if(likely(CUDA_SUCCESS == wqe->api_cxt->return_code)){
            module_handle = pos_api_handle(wqe, kPOS_ResourceTypeId_CUDA_Module, 0);
            POS_CHECK_POINTER(module_handle);
            module_handle->set_server_addr((void*)module);
            module_handle->state = kPOS_HandleState_Active;
        }
    
    exit_POS_WK_FUNC_LAUNCH_cu_module_load_data:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cu_module_load_data




/*!
 *  \related    cuModuleGetFunction 
 *  \brief      obtain kernel host pointer by given kernel name from specified CUmodule
 */
namespace cu_module_get_function {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_ptr module_handle;
        POSHandle_CUDA_Function_ptr function_handle;
        CUfunction function = NULL;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);
    
        function_handle = std::dynamic_pointer_cast<POSHandle_CUDA_Function>(
            pos_api_handle(wqe, kPOS_ResourceTypeId_CUDA_Function, 0)
        );
        POS_CHECK_POINTER(function_handle);

        if(unlikely(function_handle->parent_handles.size() == 0)){
            POS_WARN(
                "launch(cu_module_get_function): no parent module of the function recorded: device_name(%s)",
                function_handle->name.get()
            );
            retval = POS_FAILED_INVALID_INPUT;
            goto exit_POS_WK_FUNC_LAUNCH_cu_module_get_function;
        }
        module_handle = function_handle->parent_handles[0];

        wqe->api_cxt->return_code = cuModuleGetFunction(&function, module_handle->server_addr, function_handle->name.get());

        // record server address
        if(likely(CUDA_SUCCESS == wqe->api_cxt->return_code)){
            function_handle->set_server_addr((void*)function);
            function_handle->state = kPOS_HandleState_Active;
        }

    exit_POS_WK_FUNC_LAUNCH_cu_module_get_function:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        // TODO: skip checking
        // if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
        //     POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        // } else {
        //     POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        // }

        POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);

        return retval;
    }
} // namespace cu_module_get_function


/*!
 *  \related    cuModuleGetGlobal
 *  \brief      obtain the host-side pointer of a global CUDA symbol
 */
namespace cu_module_get_global {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_ptr module_handle;
        POSHandle_CUDA_Var_ptr var_handle;
        CUfunction function = NULL;

        CUdeviceptr dptr = 0;
        size_t d_size = 0;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        var_handle = std::dynamic_pointer_cast<POSHandle_CUDA_Var>(
            pos_api_handle(wqe, kPOS_ResourceTypeId_CUDA_Var, 0)
        );
        POS_CHECK_POINTER(var_handle);

        if(unlikely(var_handle->parent_handles.size() == 0)){
            POS_WARN(
                "launch(cu_module_get_global): no parent module of the var recorded: device_name(%s)",
                var_handle->name.get()
            );
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
        module_handle = var_handle->parent_handles[0];

        wqe->api_cxt->return_code = cuModuleGetGlobal(&dptr, &d_size, module_handle->server_addr, var_handle->name.get());

        // record server address
        if(likely(CUDA_SUCCESS == wqe->api_cxt->return_code)){
            var_handle->set_server_addr((void*)dptr);
            var_handle->state = kPOS_HandleState_Active;
        }

        // we temp hide the error from this api
        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){
            wqe->api_cxt->return_code = CUDA_SUCCESS;
        }

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cu_module_get_global




/*!
 *  \related    cuDevicePrimaryCtxGetState
 *  \brief      obtain the state of the primary context
 */
namespace cu_device_primary_ctx_get_state {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Device_ptr device_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        device_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Device, POSHandle_CUDA_Device, 0);
        POS_CHECK_POINTER(device_handle.get());

        wqe->api_cxt->return_code = cuDevicePrimaryCtxGetState(
            device_handle->device_id,
            (unsigned int*)(wqe->api_cxt->ret_data),
            (int*)(wqe->api_cxt->ret_data + sizeof(unsigned int))
        );

        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cu_device_primary_ctx_get_state


} // namespace wk_functions 
