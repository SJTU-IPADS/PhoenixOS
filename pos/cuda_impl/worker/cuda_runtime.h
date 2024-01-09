#include <iostream>

#include "pos/include/common.h"
#include "pos/cuda_impl/worker.h"

#include <cuda_runtime_api.h>

namespace wk_functions {


/*!
 *  \related    cudaMalloc
 *  \brief      allocate a memory area
 */
namespace cuda_malloc {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_ptr memory_handle;
        size_t allocate_size;
        void *ptr;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);
        
        // execute the actual cuda_malloc
        allocate_size = pos_api_param_value(wqe, 0, size_t);
        wqe->api_cxt->return_code = cudaMalloc(&ptr, allocate_size);

        // record server address
        if(likely(cudaSuccess == wqe->api_cxt->return_code)){
            memory_handle = pos_api_handle(wqe, kPOS_ResourceTypeId_CUDA_Memory, 0);
            POS_CHECK_POINTER(memory_handle);
            
            retval = memory_handle->set_passthrough_addr(ptr, memory_handle);
            if(unlikely(POS_SUCCESS != retval)){ goto exit; }

            memory_handle->mark_status(kPOS_HandleStatus_Active);
            memcpy(wqe->api_cxt->ret_data, &(memory_handle->client_addr), sizeof(uint64_t));
        } else {
            memset(wqe->api_cxt->ret_data, 0, sizeof(uint64_t));
        }

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_malloc


/*!
 *  \related    cudaFree
 *  \brief      release a CUDA memory area
 */
namespace cuda_free {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        POSHandleView_t &memory_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 0);

        wqe->api_cxt->return_code = cudaFree(
            /* devPtr */ memory_handle_view.handle->server_addr
        );

        if(likely(cudaSuccess == wqe->api_cxt->return_code)){
            memory_handle_view.handle->mark_status(kPOS_HandleStatus_Deleted);
        }

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_free


/*!
 *  \related    cudaLaunchKernel
 *  \brief      launch a user-define computation kernel
 */
namespace cuda_launch_kernel {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Function_ptr function_handle;
        POSHandle_CUDA_Stream_ptr stream_handle;
        POSHandle_ptr memory_handle;
        uint64_t i, j, nb_involved_memory;
        void **cuda_args = nullptr;
        void *args, *args_values, *arg_addr;
        uint64_t *addr_list;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        function_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Function, POSHandle_CUDA_Function, 0);
        POS_CHECK_POINTER(function_handle.get());

        stream_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Stream, POSHandle_CUDA_Stream, 0);
        POS_CHECK_POINTER(stream_handle.get());

        // the 3rd parameter of the API call contains parameter to launch the kernel
        args = pos_api_param_addr(wqe, 3);
        POS_CHECK_POINTER(args);

        // [Cricket Adapt] skip the metadata used by cricket
        args += (sizeof(size_t) + sizeof(uint16_t) * function_handle->nb_params);

        /*!
         *  \note   the actual kernel parameter list passed to the cuLaunchKernel is 
         *          an array of pointers, so we allocate a new array here to store
         *          these pointers
         */
        if(likely(function_handle->nb_params > 0)){
            POS_CHECK_POINTER(cuda_args = malloc(function_handle->nb_params * sizeof(void*)));
        }

        for(i=0; i<function_handle->nb_params; i++){
            cuda_args[i] = args + function_handle->param_offsets[i];
            POS_CHECK_POINTER(cuda_args[i]);
        }
        typedef struct __dim3 { uint32_t x; uint32_t y; uint32_t z; } __dim3_t;

        wqe->api_cxt->return_code = cuLaunchKernel(
            /* f */ function_handle->server_addr,
            /* gridDimX */ ((__dim3_t*)pos_api_param_addr(wqe, 1))->x,
            /* gridDimY */ ((__dim3_t*)pos_api_param_addr(wqe, 1))->y,
            /* gridDimZ */ ((__dim3_t*)pos_api_param_addr(wqe, 1))->z,
            /* blockDimX */ ((__dim3_t*)pos_api_param_addr(wqe, 2))->x,
            /* blockDimY */ ((__dim3_t*)pos_api_param_addr(wqe, 2))->y,
            /* blockDimZ */ ((__dim3_t*)pos_api_param_addr(wqe, 2))->z,
            /* sharedMemBytes */ pos_api_param_value(wqe, 4, size_t),
            /* hStream */ stream_handle->server_addr,
            /* kernelParams */ cuda_args,
            /* extra */ nullptr
        );

        if(likely(cuda_args != nullptr)){ free(cuda_args); }

    exit_POS_WK_FUNC_LAUNCH_cuda_launch_kernel:
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
} // namespace cuda_launch_kernel




/*!
 *  \related    cudaMemcpy (Host to Device)
 *  \brief      copy memory buffer from host to device
 */
namespace cuda_memcpy_h2d {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        POSHandleView_t &memory_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 0);

        wqe->api_cxt->return_code = cudaMemcpy(
            /* dst */ memory_handle_view.handle->server_addr,
            /* src */ pos_api_param_addr(wqe, 1),
            /* count */ pos_api_param_size(wqe, 1),
            /* kind */ cudaMemcpyHostToDevice
        );

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_memcpy_h2d



/*!
 *  \related    cudaMemcpy (Device to Host)
 *  \brief      copy memory buffer from device to host
 */
namespace cuda_memcpy_d2h {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        POSHandleView_t &memory_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 0);

        wqe->api_cxt->return_code = cudaMemcpy(
            /* dst */ wqe->api_cxt->ret_data,
            /* src */ (uint64_t)(memory_handle_view.handle->server_addr),
            /* count */ pos_api_param_value(wqe, 1, uint64_t),
            /* kind */ cudaMemcpyDeviceToHost
        );

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_memcpy_d2h




/*!
 *  \related    cudaMemcpy (Device to Device)
 *  \brief      copy memory buffer from device to device
 */
namespace cuda_memcpy_d2d {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        POSHandleView_t &dst_memory_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 0);
        POSHandleView_t &src_memory_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 1);

        wqe->api_cxt->return_code = cudaMemcpy(
            /* dst */ dst_memory_handle_view.handle->server_addr,
            /* src */ src_memory_handle_view.handle->server_addr,
            /* count */ pos_api_param_value(wqe, 2, uint64_t),
            /* kind */ cudaMemcpyDeviceToDevice
        );

        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_memcpy_d2d




/*!
 *  \related    cudaMemcpyAsync (Host to Device)
 *  \brief      async copy memory buffer from host to device
 */
namespace cuda_memcpy_h2d_async {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Stream_ptr stream_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        POSHandleView_t &memory_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 0);

        stream_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Stream, POSHandle_CUDA_Stream, 0);
        POS_CHECK_POINTER(stream_handle.get());

        wqe->api_cxt->return_code = cudaMemcpyAsync(
            /* dst */ memory_handle_view.handle->server_addr,
            /* src */ pos_api_param_addr(wqe, 1),
            /* count */ pos_api_param_size(wqe, 1),
            /* kind */ cudaMemcpyHostToDevice,
            /* stream */ stream_handle->server_addr
        );

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_memcpy_h2d_async




/*!
 *  \related    cudaMemcpyAsync (Device to Host)
 *  \brief      async copy memory buffer from device to host
 */
namespace cuda_memcpy_d2h_async {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Stream_ptr stream_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        POSHandleView_t &memory_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 0);

        stream_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Stream, POSHandle_CUDA_Stream, 0);
        POS_CHECK_POINTER(stream_handle.get());

        wqe->api_cxt->return_code = cudaMemcpyAsync(
            /* dst */ wqe->api_cxt->ret_data,
            /* src */ memory_handle_view.handle->server_addr,
            /* count */ pos_api_param_value(wqe, 1, uint64_t),
            /* kind */ cudaMemcpyDeviceToHost,
            /* stream */ stream_handle->server_addr
        );

        /*! \note   we must synchronize this api under remoting */
        wqe->api_cxt->return_code = cudaStreamSynchronize(stream_handle->server_addr);

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_memcpy_d2h_async




/*!
 *  \related    cudaMemcpyAsync (Device to Device)
 *  \brief      async copy memory buffer from device to device
 */
namespace cuda_memcpy_d2d_async {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Stream_ptr stream_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        POSHandleView_t &dst_memory_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 0);
        POSHandleView_t &src_memory_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Memory, 1);

        stream_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Stream, POSHandle_CUDA_Stream, 0);
        POS_CHECK_POINTER(stream_handle.get());

        wqe->api_cxt->return_code = cudaMemcpyAsync(
            /* dst */ dst_memory_handle_view.handle->server_addr,
            /* src */ src_memory_handle_view.handle->server_addr,
            /* count */ pos_api_param_value(wqe, 2, uint64_t),
            /* kind */ cudaMemcpyDeviceToDevice,
            /* stream */ stream_handle->server_addr
        );

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_memcpy_d2d_async




/*!
 *  \related    cudaSetDevice
 *  \brief      specify a CUDA device to use
 */
namespace cuda_set_device {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Device_ptr device_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        device_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Device, POSHandle_CUDA_Device, 0);
        POS_CHECK_POINTER(device_handle.get());

        wqe->api_cxt->return_code = cudaSetDevice(device_handle->device_id);

        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_set_device




/*!
 *  \related    cudaGetLastError
 *  \brief      obtain the latest error within the CUDA context
 */
namespace cuda_get_last_error {
    // parser function
    POS_WK_FUNC_LAUNCH(){
        return POS_SUCCESS;
    }

    // dag function
    POS_WK_FUNC_LANDING(){
        return POS_SUCCESS;
    }
} // namespace cuda_get_last_error




/*!
 *  \related    cudaGetErrorString
 *  \brief      obtain the error string from the CUDA context
 */
namespace cuda_get_error_string {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        const char* ret_string;
        ret_string = cudaGetErrorString(pos_api_param_value(wqe, 0, cudaError_t));

        if(likely(strlen(ret_string) > 0)){
            memcpy(wqe->api_cxt->ret_data, ret_string, strlen(ret_string)+1);
        }

        wqe->api_cxt->return_code = cudaSuccess;

        return POS_SUCCESS;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_get_error_string




/*!
 *  \related    cudaGetDeviceCount
 *  \brief      obtain the number of devices
 */
namespace cuda_get_device_count {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        return POS_SUCCESS;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        return POS_SUCCESS;
    }
} // namespace cuda_get_device_count




/*!
 *  \related    cudaGetDeviceProperties
 *  \brief      obtain the properties of specified device
 */
namespace cuda_get_device_properties {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Device_ptr device_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        device_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Device, POSHandle_CUDA_Device, 0);
        POS_CHECK_POINTER(device_handle.get());

        wqe->api_cxt->return_code = cudaGetDeviceProperties(
            (struct cudaDeviceProp*)wqe->api_cxt->ret_data, 
            device_handle->device_id
        );

        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_get_device_properties




/*!
 *  \related    cudaGetDevice
 *  \brief      obtain the handle of specified device
 */
namespace cuda_get_device {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        return POS_SUCCESS;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        return POS_SUCCESS;
    }
} // namespace cuda_get_device




/*!
 *  \related    cudaStreamSynchronize
 *  \brief      sync a specified stream
 */
namespace cuda_stream_synchronize {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Stream_ptr stream_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        stream_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Stream, POSHandle_CUDA_Stream, 0);
        POS_CHECK_POINTER(stream_handle.get());

        wqe->api_cxt->return_code = cudaStreamSynchronize(stream_handle->server_addr);

        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_stream_synchronize




/*!
 *  \related    cudaStreamIsCapturing
 *  \brief      obtain the stream's capturing state
 */
namespace cuda_stream_is_capturing {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_CUDA_Stream_ptr stream_handle;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        stream_handle = pos_api_typed_handle(wqe, kPOS_ResourceTypeId_CUDA_Stream, POSHandle_CUDA_Stream, 0);
        POS_CHECK_POINTER(stream_handle.get());

        wqe->api_cxt->return_code = cudaStreamIsCapturing(
            /* stream */ stream_handle->server_addr,
            /* pCaptureStatus */ (cudaStreamCaptureStatus*) wqe->api_cxt->ret_data
        );

        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_stream_is_capturing



/*!
 *  \related    cuda_event_create_with_flags
 *  \brief      create a new event with flags
 */
namespace cuda_event_create_with_flags {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_ptr event_handle;
        int flags;
        cudaEvent_t ptr;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);
        
        // execute the actual cudaEventCreateWithFlags
        flags = pos_api_param_value(wqe, 0, int);
        wqe->api_cxt->return_code = cudaEventCreateWithFlags(&ptr, flags);

        // record server address
        if(likely(cudaSuccess == wqe->api_cxt->return_code)){
            event_handle = pos_api_handle(wqe, kPOS_ResourceTypeId_CUDA_Event, 0);
            POS_CHECK_POINTER(event_handle);
            event_handle->set_server_addr(ptr);
            event_handle->mark_status(kPOS_HandleStatus_Active);
        }

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_event_create_with_flags




/*!
 *  \related    cuda_event_destory
 *  \brief      destory a CUDA event
 */
namespace cuda_event_destory {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        POSHandleView_t &event_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Event, 0);

        wqe->api_cxt->return_code = cudaEventDestroy(
            /* event */ event_handle_view.handle->server_addr
        );

        if(likely(cudaSuccess == wqe->api_cxt->return_code)){
            event_handle_view.handle->mark_status(kPOS_HandleStatus_Deleted);
        }

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_event_destory




/*!
 *  \related    cuda_event_record
 *  \brief      record a CUDA event
 */
namespace cuda_event_record {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        pos_retval_t retval = POS_SUCCESS;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        POSHandleView_t &event_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Event, 0);
        POS_CHECK_POINTER(event_handle_view.handle.get());
        POSHandleView_t &stream_handle_view = pos_api_handle_view(wqe, kPOS_ResourceTypeId_CUDA_Stream, 0);
        POS_CHECK_POINTER(stream_handle_view.handle.get());

        wqe->api_cxt->return_code = cudaEventRecord(
            /* event */ event_handle_view.handle->server_addr,
            /* stream */ stream_handle_view.handle->server_addr
        );

    exit:
        return retval;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        pos_retval_t retval = POS_SUCCESS;
        
        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(wqe);

        if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){ 
            POSWorker<T_POSTransport, T_POSClient>::__restore(ws, wqe);
        } else {
            POSWorker<T_POSTransport, T_POSClient>::__done(ws, wqe);
        }

        return retval;
    }
} // namespace cuda_event_record




/*!
 *  \related    template_cuda
 *  \brief      template_cuda
 */
namespace template_cuda {
    // launch function
    POS_WK_FUNC_LAUNCH(){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    // landing function
    POS_WK_FUNC_LANDING(){
        return POS_FAILED_NOT_IMPLEMENTED;
    }
} // namespace template_cuda




} // namespace wk_functions 
