#include <iostream>
#include <vector>

#include <stdint.h>


#include "pos/include/common.h"
#include "pos/include/api_context.h"

#include "pos/cuda_impl/api_index.h"

/*!
 *  \brief  all POS-hijacked should be record here, used for debug checking
 */
static const std::vector<uint64_t> __pos_hijacked_apis({
    /* CUDA Runtime */
    CUDA_MALLOC,
    CUDA_FREE,
    CUDA_LAUNCH_KERNEL,
    CUDA_MEMCPY_HTOD,
    CUDA_MEMCPY_DTOH,
    CUDA_MEMCPY_DTOD,
    CUDA_MEMCPY_HTOD_ASYNC,
    CUDA_MEMCPY_DTOH_ASYNC,
    CUDA_MEMCPY_DTOD_ASYNC,
    CUDA_SET_DEVICE,
    CUDA_GET_LAST_ERROR,
    CUDA_GET_ERROR_STRING,
    CUDA_GET_DEVICE_COUNT,
    CUDA_GET_DEVICE_PROPERTIES,
    CUDA_GET_DEVICE,
    CUDA_STREAM_SYNCHRONIZE,
    CUDA_STREAM_IS_CAPTURING,
    CUDA_EVENT_CREATE_WITH_FLAGS,
    CUDA_EVENT_DESTROY,
    CUDA_EVENT_RECORD,

    /* CUDA Driver */
    rpc_cuModuleLoad,
    rpc_cuModuleGetFunction,
    rpc_register_var,
    rpc_cuDevicePrimaryCtxGetState,
    
    /* cuBLAS */
    rpc_cublasCreate,
    rpc_cublasSetStream,
    rpc_cublasSetMathMode,
    rpc_cublasSgemm,

    /* no need to hijack */
    rpc_printmessage,
    rpc_elf_load,
    rpc_register_function,
    rpc_elf_unload,
    rpc_deinit
});

bool pos_is_hijacked(uint64_t api_id){
    uint64_t i=0;
    for(i=0; i<__pos_hijacked_apis.size(); i++){
        if(unlikely(__pos_hijacked_apis[i] == api_id)){
            return true;
        }
    }
    return false;
}