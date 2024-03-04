#include <iostream>

#include "pos/include/common.h"
#include "pos/cuda_impl/worker.h"

#include <cuda.h>
#include <cuda_runtime_api.h>

char* __cu_demangle(const char *id, char *output_buffer, size_t *length, int *status);

namespace wk_functions {

/*!
 *  \related    cuModuleLoadData
 *  \brief      load CUmodule down to the driver, which contains PTX/SASS binary
 */
namespace cu_module_load_data {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *module_handle;
        uint8_t *fatbin_binary;
        CUresult res;
        CUmodule module = NULL;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        module_handle = pos_api_create_handle(wqe, 0);
        POS_CHECK_POINTER(module_handle);

        fatbin_binary = module_handle->host_value_map[wqe->dag_vertex_id].first;

        wqe->api_cxt->return_code = cuModuleLoadData(&module, fatbin_binary);

        // record server address
        if(likely(CUDA_SUCCESS == wqe->api_cxt->return_code)){
            module_handle->set_server_addr((void*)module);
            module_handle->mark_status(kPOS_HandleStatus_Active);
        }

        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
            POSWorker::__restore(ws, wqe);
        } else {
            POSWorker::__done(ws, wqe);
        }

    exit:
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
        POSHandle *module_handle;
        POSHandle_CUDA_Function *function_handle;
        CUfunction function = NULL;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);
    
        function_handle = (POSHandle_CUDA_Function*)(pos_api_create_handle(wqe, 0));
        POS_CHECK_POINTER(function_handle);

        POS_ASSERT(function_handle->parent_handles.size() > 0);
        module_handle = function_handle->parent_handles[0];

        wqe->api_cxt->return_code = cuModuleGetFunction(
            &function, (CUmodule)(module_handle->server_addr), function_handle->name.c_str()
        );

        // record server address
        if(likely(CUDA_SUCCESS == wqe->api_cxt->return_code)){
            function_handle->set_server_addr((void*)function);
            function_handle->mark_status(kPOS_HandleStatus_Active);
        }

        // TODO: skip checking
        // if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
        //     POSWorker::__restore(ws, wqe);
        // } else {
        //     POSWorker::__done(ws, wqe);
        // }
        POSWorker::__done(ws, wqe);

    exit:
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
        POSHandle *module_handle;
        POSHandle_CUDA_Var *var_handle;
        CUfunction function = NULL;

        CUdeviceptr dptr = 0;
        size_t d_size = 0;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        var_handle = (POSHandle_CUDA_Var*)(pos_api_create_handle(wqe, 0));
        POS_CHECK_POINTER(var_handle);

        POS_ASSERT(var_handle->parent_handles.size() > 0);
        module_handle = var_handle->parent_handles[0];

        wqe->api_cxt->return_code = cuModuleGetGlobal(
            &dptr, &d_size, (CUmodule)(module_handle->server_addr), var_handle->name.get()
        );

        // record server address
        if(likely(CUDA_SUCCESS == wqe->api_cxt->return_code)){
            var_handle->set_server_addr((void*)dptr);
            var_handle->mark_status(kPOS_HandleStatus_Active);
        }

        // we temp hide the error from this api
        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){
            wqe->api_cxt->return_code = CUDA_SUCCESS;
        }

        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
            POSWorker::__restore(ws, wqe);
        } else {
            POSWorker::__done(ws, wqe);
        }

    exit:
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
        POSHandle_CUDA_Device *device_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        device_handle = (POSHandle_CUDA_Device*)(pos_api_input_handle(wqe, 0));
        POS_CHECK_POINTER(device_handle);

        wqe->api_cxt->return_code = cuDevicePrimaryCtxGetState(
            device_handle->device_id,
            (unsigned int*)(wqe->api_cxt->ret_data),
            (int*)(wqe->api_cxt->ret_data + sizeof(unsigned int))
        );

        if(unlikely(CUDA_SUCCESS != wqe->api_cxt->return_code)){ 
            POSWorker::__restore(ws, wqe);
        } else {
            POSWorker::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cu_device_primary_ctx_get_state


} // namespace wk_functions 
