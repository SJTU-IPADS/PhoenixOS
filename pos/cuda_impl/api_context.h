#pragma once

#include <iostream>
#include <vector>

#include <cuda.h>
#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#include <cublas_api.h>

#include "pos/include/common.h"
#include "pos/include/api_context.h"

#include "pos/cuda_impl/api_index.h"

enum pos_cuda_library_id_t : uint8_t {
    kPOS_CUDA_Library_Id_Runtime = 0,
    kPOS_CUDA_Library_Id_Driver,
    kPOS_CUDA_Library_Id_cuBLAS
};

/*!
 *  \brief  manager of CUDA APIs
 */
class POSApiManager_CUDA : public POSApiManager {
 public:
    POSApiManager_CUDA(){}
    ~POSApiManager_CUDA() = default;

    /*!
     *  \brief  register metadata of all API on the platform to the manager
     */
    void init() override {
        this->api_metas.insert({
            /* ========== CUDA runtime functions ========== */
            { 
                /* api_id */ CUDA_MALLOC, 
                { 
                    /* is_sync */       true, 
                    /* api_type */      kPOS_API_Type_Create_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaMalloc"
                }
            },
            { 
                /* api_id */ CUDA_FREE, 
                { 
                    /* is_sync */       true, 
                    /* api_type */      kPOS_API_Type_Delete_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaFree"
                }
            },
            {
                /* api_id */ CUDA_MEMCPY_HTOD, 
                { 
                    /* is_sync */       true, 
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaMemcpyH2D"
                }
            },
            { 
                /* api_id */ CUDA_MEMCPY_DTOH, 
                { 
                    /* is_sync */       true, 
                    /* api_type */      kPOS_API_Type_Get_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaMemcpyD2H"
                }
            },
            { 
                /* api_id */ CUDA_MEMCPY_DTOD, 
                { 
                    /* is_sync */       true, 
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaMemcpyD2D"
                }
            },
            { 
                /* api_id */ CUDA_MEMCPY_HTOD_ASYNC, 
                {
                    /* is_sync */       false, 
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaMemcpyH2DAsync"
                }
            },
            { 
                /* api_id */ CUDA_MEMCPY_DTOH_ASYNC, 
                { 
                    /*! \note           under remoting framework, this api should be sync */
                    /* is_sync */       true,   
                    /* api_type */      kPOS_API_Type_Get_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaMemcpyD2HAsync"
                }
            },
            { 
                /* api_id */ CUDA_MEMCPY_DTOD_ASYNC, 
                { 
                    /* is_sync */       false, 
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaMemcpyD2DAsync"
                }
            },
            { 
                /* api_id */ CUDA_LAUNCH_KERNEL, 
                { 
                    /* is_sync */       false, 
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaLaunchKernel"
                }
            },
            {
                /* api_id */ CUDA_SET_DEVICE, 
                { 
                    /* is_sync */       false, 
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaSetDevice"
                }
            },
            {
                /* api_id */ CUDA_GET_LAST_ERROR, 
                { 
                    /* is_sync */       false, 
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaGetLastError"
                }
            },
            { 
                /* api_id */ CUDA_GET_ERROR_STRING, 
                { 
                    /* is_sync */       true, 
                    /* api_type */      kPOS_API_Type_Get_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaGetErrorString"
                }
            },
            { 
                /* api_id */ CUDA_GET_DEVICE_COUNT, 
                { 
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Get_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaGetDeviceCount"
                }
            },
            { 
                /* api_id */ CUDA_GET_DEVICE_PROPERTIES, 
                {
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Get_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaGetDeviceProperties"
                }
            },
            { 
                /* api_id */ CUDA_GET_DEVICE, 
                {
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Get_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaGetDevice"
                }
            },
            { 
                /* api_id */ CUDA_STREAM_SYNCHRONIZE, 
                {
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Get_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaStreamSynchronize"
                }
            },
            { 
                /* api_id */ CUDA_STREAM_IS_CAPTURING, 
                {
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Get_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaStreamIsCapturing"
                }
            },
            { 
                /* api_id */ CUDA_EVENT_CREATE_WITH_FLAGS, 
                {
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Create_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaEventCreateWithFlags"
                }
            },
            {
                /* api_id */ CUDA_EVENT_DESTROY, 
                {
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Delete_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaEventDestory"
                }
            },
            { 
                /* api_id */ CUDA_EVENT_RECORD, 
                {
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Runtime,
                    /* api_name */      "cudaEventRecord"
                }
            },

            /* ========== CUDA driver functions ========== */
            { 
                /* api_id */ rpc_cuModuleLoad, 
                { 
                    /* is_sync */       true, 
                    /* api_type */      kPOS_API_Type_Create_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Driver,
                    /* api_name */      "cuModuleLoad"
                }
            },
            { 
                /* api_id */ rpc_cuModuleGetFunction, 
                { 
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Create_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Driver,
                    /* api_name */      "cuModuleGetFunction"
                }
            },
            { 
                /* api_id */ rpc_register_var, 
                { 
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Create_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Driver,
                    /* api_name */      "cuModuleGetGlobal"
                }
            },
            { 
                /* api_id */ rpc_cuDevicePrimaryCtxGetState, 
                { 
                    /* is_sync */       true,
                    /* api_type */      kPOS_API_Type_Get_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_Driver,
                    /* api_name */      "cuDevicePrimaryCtxGetState"
                }
            },

            /* ========== cuBLAS functions ========== */
            { 
                /* api_id */ rpc_cublasCreate, 
                { 
                    /* is_sync */       true, 
                    /* api_type */      kPOS_API_Type_Create_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_cuBLAS,
                    /* api_name */      "cublasCreate"
                }
            },
            { 
                /* api_id */ rpc_cublasSetStream,
                { 
                    /* is_sync */       false,
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_cuBLAS,
                    /* api_name */      "cublasSetStream"
                }
            },
            { 
                /* api_id */ rpc_cublasSetMathMode, 
                { 
                    /* is_sync */       false,
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_cuBLAS,
                    /* api_name */      "cublasSetMathMode"
                }
            },
            { 
                /* api_id */ rpc_cublasSgemm, 
                { 
                    /* is_sync */       false,
                    /* api_type */      kPOS_API_Type_Set_Resource,
                    /* library_id */    kPOS_CUDA_Library_Id_cuBLAS,
                    /* api_name */      "cublasSgemm"
                }
            },
        });
    }

    /*!
     *  \brief  translate POS retval to corresponding retval on the CUDA platform
     *  \param  pos_retval the POS retval to be translated
     *  \param  library_id  id of the destination library (e.g., cuda rt, driver, cublas)
     */
    int cast_pos_retval(pos_retval_t pos_retval, uint8_t library_id) override {
        switch (pos_retval)
        {
        case POS_SUCCESS:
            if (library_id == kPOS_CUDA_Library_Id_Runtime){
                return cudaSuccess;
            } else if (library_id == kPOS_CUDA_Library_Id_Driver){
                return CUDA_SUCCESS;
            } else if (library_id == kPOS_CUDA_Library_Id_cuBLAS){
                return CUBLAS_STATUS_SUCCESS;
            }
        case POS_FAILED_DRAIN:
            if (library_id == kPOS_CUDA_Library_Id_Runtime){
                return cudaErrorMemoryAllocation;
            } else if (library_id == kPOS_CUDA_Library_Id_Driver){
                return CUDA_ERROR_OUT_OF_MEMORY;
            } else if (library_id == kPOS_CUDA_Library_Id_cuBLAS){
                return CUBLAS_STATUS_ALLOC_FAILED;
            }
        default:
            if (library_id == kPOS_CUDA_Library_Id_Runtime){
                return cudaErrorUnknown;
            } else if (library_id == kPOS_CUDA_Library_Id_Driver){
                return CUDA_ERROR_UNKNOWN;
            } else if (library_id == kPOS_CUDA_Library_Id_cuBLAS){
                return CUBLAS_STATUS_INTERNAL_ERROR;
            }
        }
    }
};

bool pos_is_hijacked(uint64_t api_id);
