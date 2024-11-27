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


#include <iostream>
#include <vector>
#include <cuda.h>
#include <dlfcn.h>
#include <cuda_runtime.h>

#include "cudam.h"
#include "buffer_manager.h"


cudaError_t cudaDeviceReset(){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceReset) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaDeviceReset");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceReset",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceReset,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceReset();
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceSynchronize(){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSynchronize) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaDeviceSynchronize");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceSynchronize",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceSynchronize,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceSynchronize();
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceSetLimit(cudaLimit limit, size_t value){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSetLimit) (cudaLimit, size_t) = (cudaError_t (*)(cudaLimit, size_t))dlsym(RTLD_NEXT, "cudaDeviceSetLimit");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceSetLimit",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceSetLimit,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceSetLimit(limit, value);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetLimit(size_t * pValue, cudaLimit limit){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetLimit) (size_t *, cudaLimit) = (cudaError_t (*)(size_t *, cudaLimit))dlsym(RTLD_NEXT, "cudaDeviceGetLimit");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetLimit",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetLimit,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetLimit(pValue, limit);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetTexture1DLinearMaxWidth(size_t * maxWidthInElements, cudaChannelFormatDesc const * fmtDesc, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetTexture1DLinearMaxWidth) (size_t *, cudaChannelFormatDesc const *, int) = (cudaError_t (*)(size_t *, cudaChannelFormatDesc const *, int))dlsym(RTLD_NEXT, "cudaDeviceGetTexture1DLinearMaxWidth");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetTexture1DLinearMaxWidth",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetTexture1DLinearMaxWidth,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetTexture1DLinearMaxWidth(maxWidthInElements, fmtDesc, device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetCacheConfig(cudaFuncCache * pCacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetCacheConfig) (cudaFuncCache *) = (cudaError_t (*)(cudaFuncCache *))dlsym(RTLD_NEXT, "cudaDeviceGetCacheConfig");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetCacheConfig",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetCacheConfig,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetCacheConfig(pCacheConfig);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetStreamPriorityRange(int * leastPriority, int * greatestPriority){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetStreamPriorityRange) (int *, int *) = (cudaError_t (*)(int *, int *))dlsym(RTLD_NEXT, "cudaDeviceGetStreamPriorityRange");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetStreamPriorityRange",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetStreamPriorityRange,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetStreamPriorityRange(leastPriority, greatestPriority);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceSetCacheConfig(cudaFuncCache cacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSetCacheConfig) (cudaFuncCache) = (cudaError_t (*)(cudaFuncCache))dlsym(RTLD_NEXT, "cudaDeviceSetCacheConfig");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceSetCacheConfig",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceSetCacheConfig,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceSetCacheConfig(cacheConfig);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetSharedMemConfig) (cudaSharedMemConfig *) = (cudaError_t (*)(cudaSharedMemConfig *))dlsym(RTLD_NEXT, "cudaDeviceGetSharedMemConfig");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetSharedMemConfig",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetSharedMemConfig,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetSharedMemConfig(pConfig);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceSetSharedMemConfig(cudaSharedMemConfig config){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSetSharedMemConfig) (cudaSharedMemConfig) = (cudaError_t (*)(cudaSharedMemConfig))dlsym(RTLD_NEXT, "cudaDeviceSetSharedMemConfig");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceSetSharedMemConfig",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceSetSharedMemConfig,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceSetSharedMemConfig(config);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetByPCIBusId(int * device, char const * pciBusId){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetByPCIBusId) (int *, char const *) = (cudaError_t (*)(int *, char const *))dlsym(RTLD_NEXT, "cudaDeviceGetByPCIBusId");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetByPCIBusId",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetByPCIBusId,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetByPCIBusId(device, pciBusId);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetPCIBusId(char * pciBusId, int len, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetPCIBusId) (char *, int, int) = (cudaError_t (*)(char *, int, int))dlsym(RTLD_NEXT, "cudaDeviceGetPCIBusId");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetPCIBusId",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetPCIBusId,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetPCIBusId(pciBusId, len, device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaIpcGetEventHandle(cudaIpcEventHandle_t * handle, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcGetEventHandle) (cudaIpcEventHandle_t *, cudaEvent_t) = (cudaError_t (*)(cudaIpcEventHandle_t *, cudaEvent_t))dlsym(RTLD_NEXT, "cudaIpcGetEventHandle");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaIpcGetEventHandle",
        /* api_index */ CUDA_MEMORY_API_cudaIpcGetEventHandle,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaIpcGetEventHandle(handle, event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaIpcOpenEventHandle(cudaEvent_t * event, cudaIpcEventHandle_t handle){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcOpenEventHandle) (cudaEvent_t *, cudaIpcEventHandle_t) = (cudaError_t (*)(cudaEvent_t *, cudaIpcEventHandle_t))dlsym(RTLD_NEXT, "cudaIpcOpenEventHandle");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaIpcOpenEventHandle",
        /* api_index */ CUDA_MEMORY_API_cudaIpcOpenEventHandle,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaIpcOpenEventHandle(event, handle);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaIpcGetMemHandle(cudaIpcMemHandle_t * handle, void * devPtr){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcGetMemHandle) (cudaIpcMemHandle_t *, void *) = (cudaError_t (*)(cudaIpcMemHandle_t *, void *))dlsym(RTLD_NEXT, "cudaIpcGetMemHandle");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaIpcGetMemHandle",
        /* api_index */ CUDA_MEMORY_API_cudaIpcGetMemHandle,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaIpcGetMemHandle(handle, devPtr);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaIpcOpenMemHandle(void * * devPtr, cudaIpcMemHandle_t handle, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcOpenMemHandle) (void * *, cudaIpcMemHandle_t, unsigned int) = (cudaError_t (*)(void * *, cudaIpcMemHandle_t, unsigned int))dlsym(RTLD_NEXT, "cudaIpcOpenMemHandle");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaIpcOpenMemHandle",
        /* api_index */ CUDA_MEMORY_API_cudaIpcOpenMemHandle,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaIpcOpenMemHandle(devPtr, handle, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaIpcCloseMemHandle(void * devPtr){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcCloseMemHandle) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaIpcCloseMemHandle");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaIpcCloseMemHandle",
        /* api_index */ CUDA_MEMORY_API_cudaIpcCloseMemHandle,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaIpcCloseMemHandle(devPtr);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceFlushGPUDirectRDMAWrites(cudaFlushGPUDirectRDMAWritesTarget target, cudaFlushGPUDirectRDMAWritesScope scope){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceFlushGPUDirectRDMAWrites) (cudaFlushGPUDirectRDMAWritesTarget, cudaFlushGPUDirectRDMAWritesScope) = (cudaError_t (*)(cudaFlushGPUDirectRDMAWritesTarget, cudaFlushGPUDirectRDMAWritesScope))dlsym(RTLD_NEXT, "cudaDeviceFlushGPUDirectRDMAWrites");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceFlushGPUDirectRDMAWrites",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceFlushGPUDirectRDMAWrites,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceFlushGPUDirectRDMAWrites(target, scope);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaThreadExit(){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadExit) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaThreadExit");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaThreadExit",
        /* api_index */ CUDA_MEMORY_API_cudaThreadExit,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaThreadExit();
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaThreadSynchronize(){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadSynchronize) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaThreadSynchronize");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaThreadSynchronize",
        /* api_index */ CUDA_MEMORY_API_cudaThreadSynchronize,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaThreadSynchronize();
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaThreadSetLimit(cudaLimit limit, size_t value){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadSetLimit) (cudaLimit, size_t) = (cudaError_t (*)(cudaLimit, size_t))dlsym(RTLD_NEXT, "cudaThreadSetLimit");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaThreadSetLimit",
        /* api_index */ CUDA_MEMORY_API_cudaThreadSetLimit,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaThreadSetLimit(limit, value);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaThreadGetLimit(size_t * pValue, cudaLimit limit){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadGetLimit) (size_t *, cudaLimit) = (cudaError_t (*)(size_t *, cudaLimit))dlsym(RTLD_NEXT, "cudaThreadGetLimit");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaThreadGetLimit",
        /* api_index */ CUDA_MEMORY_API_cudaThreadGetLimit,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaThreadGetLimit(pValue, limit);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaThreadGetCacheConfig(cudaFuncCache * pCacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadGetCacheConfig) (cudaFuncCache *) = (cudaError_t (*)(cudaFuncCache *))dlsym(RTLD_NEXT, "cudaThreadGetCacheConfig");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaThreadGetCacheConfig",
        /* api_index */ CUDA_MEMORY_API_cudaThreadGetCacheConfig,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaThreadGetCacheConfig(pCacheConfig);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaThreadSetCacheConfig(cudaFuncCache cacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadSetCacheConfig) (cudaFuncCache) = (cudaError_t (*)(cudaFuncCache))dlsym(RTLD_NEXT, "cudaThreadSetCacheConfig");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaThreadSetCacheConfig",
        /* api_index */ CUDA_MEMORY_API_cudaThreadSetCacheConfig,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaThreadSetCacheConfig(cacheConfig);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetLastError(){
    cudaError_t lretval;
    cudaError_t (*lcudaGetLastError) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaGetLastError");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetLastError",
        /* api_index */ CUDA_MEMORY_API_cudaGetLastError,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetLastError();
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaPeekAtLastError(){
    cudaError_t lretval;
    cudaError_t (*lcudaPeekAtLastError) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaPeekAtLastError");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaPeekAtLastError",
        /* api_index */ CUDA_MEMORY_API_cudaPeekAtLastError,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaPeekAtLastError();
    
    /* NOTE: post-interception */

    return lretval;
}


char const * cudaGetErrorName(cudaError_t error){
    char const * lretval;
    char const * (*lcudaGetErrorName) (cudaError_t) = (char const * (*)(cudaError_t))dlsym(RTLD_NEXT, "cudaGetErrorName");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetErrorName",
        /* api_index */ CUDA_MEMORY_API_cudaGetErrorName,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetErrorName(error);
    
    /* NOTE: post-interception */

    return lretval;
}


char const * cudaGetErrorString(cudaError_t error){
    char const * lretval;
    char const * (*lcudaGetErrorString) (cudaError_t) = (char const * (*)(cudaError_t))dlsym(RTLD_NEXT, "cudaGetErrorString");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetErrorString",
        /* api_index */ CUDA_MEMORY_API_cudaGetErrorString,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetErrorString(error);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetDeviceCount(int * count){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDeviceCount) (int *) = (cudaError_t (*)(int *))dlsym(RTLD_NEXT, "cudaGetDeviceCount");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetDeviceCount",
        /* api_index */ CUDA_MEMORY_API_cudaGetDeviceCount,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetDeviceCount(count);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetDeviceProperties(cudaDeviceProp * prop, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDeviceProperties) (cudaDeviceProp *, int) = (cudaError_t (*)(cudaDeviceProp *, int))dlsym(RTLD_NEXT, "cudaGetDeviceProperties");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetDeviceProperties",
        /* api_index */ CUDA_MEMORY_API_cudaGetDeviceProperties,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetDeviceProperties(prop, device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetAttribute(int * value, cudaDeviceAttr attr, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetAttribute) (int *, cudaDeviceAttr, int) = (cudaError_t (*)(int *, cudaDeviceAttr, int))dlsym(RTLD_NEXT, "cudaDeviceGetAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetAttribute(value, attr, device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetDefaultMemPool(cudaMemPool_t * memPool, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetDefaultMemPool) (cudaMemPool_t *, int) = (cudaError_t (*)(cudaMemPool_t *, int))dlsym(RTLD_NEXT, "cudaDeviceGetDefaultMemPool");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetDefaultMemPool",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetDefaultMemPool,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetDefaultMemPool(memPool, device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceSetMemPool(int device, cudaMemPool_t memPool){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSetMemPool) (int, cudaMemPool_t) = (cudaError_t (*)(int, cudaMemPool_t))dlsym(RTLD_NEXT, "cudaDeviceSetMemPool");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceSetMemPool",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceSetMemPool,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceSetMemPool(device, memPool);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetMemPool(cudaMemPool_t * memPool, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetMemPool) (cudaMemPool_t *, int) = (cudaError_t (*)(cudaMemPool_t *, int))dlsym(RTLD_NEXT, "cudaDeviceGetMemPool");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetMemPool",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetMemPool,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetMemPool(memPool, device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetNvSciSyncAttributes(void * nvSciSyncAttrList, int device, int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetNvSciSyncAttributes) (void *, int, int) = (cudaError_t (*)(void *, int, int))dlsym(RTLD_NEXT, "cudaDeviceGetNvSciSyncAttributes");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetNvSciSyncAttributes",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetNvSciSyncAttributes,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetNvSciSyncAttributes(nvSciSyncAttrList, device, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetP2PAttribute(int * value, cudaDeviceP2PAttr attr, int srcDevice, int dstDevice){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetP2PAttribute) (int *, cudaDeviceP2PAttr, int, int) = (cudaError_t (*)(int *, cudaDeviceP2PAttr, int, int))dlsym(RTLD_NEXT, "cudaDeviceGetP2PAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetP2PAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetP2PAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetP2PAttribute(value, attr, srcDevice, dstDevice);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaChooseDevice(int * device, cudaDeviceProp const * prop){
    cudaError_t lretval;
    cudaError_t (*lcudaChooseDevice) (int *, cudaDeviceProp const *) = (cudaError_t (*)(int *, cudaDeviceProp const *))dlsym(RTLD_NEXT, "cudaChooseDevice");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaChooseDevice",
        /* api_index */ CUDA_MEMORY_API_cudaChooseDevice,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaChooseDevice(device, prop);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaSetDevice(int device){
    cudaError_t lretval;
    cudaError_t (*lcudaSetDevice) (int) = (cudaError_t (*)(int))dlsym(RTLD_NEXT, "cudaSetDevice");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaSetDevice",
        /* api_index */ CUDA_MEMORY_API_cudaSetDevice,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaSetDevice(device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetDevice(int * device){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDevice) (int *) = (cudaError_t (*)(int *))dlsym(RTLD_NEXT, "cudaGetDevice");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetDevice",
        /* api_index */ CUDA_MEMORY_API_cudaGetDevice,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetDevice(device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaSetValidDevices(int * device_arr, int len){
    cudaError_t lretval;
    cudaError_t (*lcudaSetValidDevices) (int *, int) = (cudaError_t (*)(int *, int))dlsym(RTLD_NEXT, "cudaSetValidDevices");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaSetValidDevices",
        /* api_index */ CUDA_MEMORY_API_cudaSetValidDevices,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaSetValidDevices(device_arr, len);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaSetDeviceFlags(unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaSetDeviceFlags) (unsigned int) = (cudaError_t (*)(unsigned int))dlsym(RTLD_NEXT, "cudaSetDeviceFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaSetDeviceFlags",
        /* api_index */ CUDA_MEMORY_API_cudaSetDeviceFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaSetDeviceFlags(flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetDeviceFlags(unsigned int * flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDeviceFlags) (unsigned int *) = (cudaError_t (*)(unsigned int *))dlsym(RTLD_NEXT, "cudaGetDeviceFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetDeviceFlags",
        /* api_index */ CUDA_MEMORY_API_cudaGetDeviceFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetDeviceFlags(flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamCreate(cudaStream_t * pStream){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamCreate) (cudaStream_t *) = (cudaError_t (*)(cudaStream_t *))dlsym(RTLD_NEXT, "cudaStreamCreate");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamCreate",
        /* api_index */ CUDA_MEMORY_API_cudaStreamCreate,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamCreate(pStream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamCreateWithFlags(cudaStream_t * pStream, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamCreateWithFlags) (cudaStream_t *, unsigned int) = (cudaError_t (*)(cudaStream_t *, unsigned int))dlsym(RTLD_NEXT, "cudaStreamCreateWithFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamCreateWithFlags",
        /* api_index */ CUDA_MEMORY_API_cudaStreamCreateWithFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamCreateWithFlags(pStream, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamCreateWithPriority(cudaStream_t * pStream, unsigned int flags, int priority){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamCreateWithPriority) (cudaStream_t *, unsigned int, int) = (cudaError_t (*)(cudaStream_t *, unsigned int, int))dlsym(RTLD_NEXT, "cudaStreamCreateWithPriority");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamCreateWithPriority",
        /* api_index */ CUDA_MEMORY_API_cudaStreamCreateWithPriority,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamCreateWithPriority(pStream, flags, priority);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamGetPriority(cudaStream_t hStream, int * priority){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetPriority) (cudaStream_t, int *) = (cudaError_t (*)(cudaStream_t, int *))dlsym(RTLD_NEXT, "cudaStreamGetPriority");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamGetPriority",
        /* api_index */ CUDA_MEMORY_API_cudaStreamGetPriority,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamGetPriority(hStream, priority);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamGetFlags(cudaStream_t hStream, unsigned int * flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetFlags) (cudaStream_t, unsigned int *) = (cudaError_t (*)(cudaStream_t, unsigned int *))dlsym(RTLD_NEXT, "cudaStreamGetFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamGetFlags",
        /* api_index */ CUDA_MEMORY_API_cudaStreamGetFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamGetFlags(hStream, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaCtxResetPersistingL2Cache(){
    cudaError_t lretval;
    cudaError_t (*lcudaCtxResetPersistingL2Cache) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaCtxResetPersistingL2Cache");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaCtxResetPersistingL2Cache",
        /* api_index */ CUDA_MEMORY_API_cudaCtxResetPersistingL2Cache,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaCtxResetPersistingL2Cache();
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamCopyAttributes(cudaStream_t dst, cudaStream_t src){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamCopyAttributes) (cudaStream_t, cudaStream_t) = (cudaError_t (*)(cudaStream_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaStreamCopyAttributes");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamCopyAttributes",
        /* api_index */ CUDA_MEMORY_API_cudaStreamCopyAttributes,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamCopyAttributes(dst, src);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamGetAttribute(cudaStream_t hStream, cudaStreamAttrID attr, cudaStreamAttrValue * value_out){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetAttribute) (cudaStream_t, cudaStreamAttrID, cudaStreamAttrValue *) = (cudaError_t (*)(cudaStream_t, cudaStreamAttrID, cudaStreamAttrValue *))dlsym(RTLD_NEXT, "cudaStreamGetAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamGetAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaStreamGetAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamGetAttribute(hStream, attr, value_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamSetAttribute(cudaStream_t hStream, cudaStreamAttrID attr, cudaStreamAttrValue const * value){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamSetAttribute) (cudaStream_t, cudaStreamAttrID, cudaStreamAttrValue const *) = (cudaError_t (*)(cudaStream_t, cudaStreamAttrID, cudaStreamAttrValue const *))dlsym(RTLD_NEXT, "cudaStreamSetAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamSetAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaStreamSetAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamSetAttribute(hStream, attr, value);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamDestroy(cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamDestroy) (cudaStream_t) = (cudaError_t (*)(cudaStream_t))dlsym(RTLD_NEXT, "cudaStreamDestroy");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamDestroy",
        /* api_index */ CUDA_MEMORY_API_cudaStreamDestroy,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamDestroy(stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamWaitEvent) (cudaStream_t, cudaEvent_t, unsigned int) = (cudaError_t (*)(cudaStream_t, cudaEvent_t, unsigned int))dlsym(RTLD_NEXT, "cudaStreamWaitEvent");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamWaitEvent",
        /* api_index */ CUDA_MEMORY_API_cudaStreamWaitEvent,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamWaitEvent(stream, event, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamAddCallback(cudaStream_t stream, cudaStreamCallback_t callback, void * userData, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamAddCallback) (cudaStream_t, cudaStreamCallback_t, void *, unsigned int) = (cudaError_t (*)(cudaStream_t, cudaStreamCallback_t, void *, unsigned int))dlsym(RTLD_NEXT, "cudaStreamAddCallback");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamAddCallback",
        /* api_index */ CUDA_MEMORY_API_cudaStreamAddCallback,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamAddCallback(stream, callback, userData, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamSynchronize(cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamSynchronize) (cudaStream_t) = (cudaError_t (*)(cudaStream_t))dlsym(RTLD_NEXT, "cudaStreamSynchronize");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamSynchronize",
        /* api_index */ CUDA_MEMORY_API_cudaStreamSynchronize,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamSynchronize(stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamQuery(cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamQuery) (cudaStream_t) = (cudaError_t (*)(cudaStream_t))dlsym(RTLD_NEXT, "cudaStreamQuery");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamQuery",
        /* api_index */ CUDA_MEMORY_API_cudaStreamQuery,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamQuery(stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamAttachMemAsync(cudaStream_t stream, void * devPtr, size_t length, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamAttachMemAsync) (cudaStream_t, void *, size_t, unsigned int) = (cudaError_t (*)(cudaStream_t, void *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaStreamAttachMemAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamAttachMemAsync",
        /* api_index */ CUDA_MEMORY_API_cudaStreamAttachMemAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamAttachMemAsync(stream, devPtr, length, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamBeginCapture(cudaStream_t stream, cudaStreamCaptureMode mode){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamBeginCapture) (cudaStream_t, cudaStreamCaptureMode) = (cudaError_t (*)(cudaStream_t, cudaStreamCaptureMode))dlsym(RTLD_NEXT, "cudaStreamBeginCapture");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamBeginCapture",
        /* api_index */ CUDA_MEMORY_API_cudaStreamBeginCapture,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamBeginCapture(stream, mode);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaThreadExchangeStreamCaptureMode(cudaStreamCaptureMode * mode){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadExchangeStreamCaptureMode) (cudaStreamCaptureMode *) = (cudaError_t (*)(cudaStreamCaptureMode *))dlsym(RTLD_NEXT, "cudaThreadExchangeStreamCaptureMode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaThreadExchangeStreamCaptureMode",
        /* api_index */ CUDA_MEMORY_API_cudaThreadExchangeStreamCaptureMode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaThreadExchangeStreamCaptureMode(mode);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamEndCapture(cudaStream_t stream, cudaGraph_t * pGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamEndCapture) (cudaStream_t, cudaGraph_t *) = (cudaError_t (*)(cudaStream_t, cudaGraph_t *))dlsym(RTLD_NEXT, "cudaStreamEndCapture");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamEndCapture",
        /* api_index */ CUDA_MEMORY_API_cudaStreamEndCapture,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamEndCapture(stream, pGraph);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamIsCapturing(cudaStream_t stream, cudaStreamCaptureStatus * pCaptureStatus){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamIsCapturing) (cudaStream_t, cudaStreamCaptureStatus *) = (cudaError_t (*)(cudaStream_t, cudaStreamCaptureStatus *))dlsym(RTLD_NEXT, "cudaStreamIsCapturing");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamIsCapturing",
        /* api_index */ CUDA_MEMORY_API_cudaStreamIsCapturing,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamIsCapturing(stream, pCaptureStatus);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamGetCaptureInfo(cudaStream_t stream, cudaStreamCaptureStatus * pCaptureStatus, long long unsigned int * pId){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetCaptureInfo) (cudaStream_t, cudaStreamCaptureStatus *, long long unsigned int *) = (cudaError_t (*)(cudaStream_t, cudaStreamCaptureStatus *, long long unsigned int *))dlsym(RTLD_NEXT, "cudaStreamGetCaptureInfo");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamGetCaptureInfo",
        /* api_index */ CUDA_MEMORY_API_cudaStreamGetCaptureInfo,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamGetCaptureInfo(stream, pCaptureStatus, pId);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamGetCaptureInfo_v2(cudaStream_t stream, cudaStreamCaptureStatus * captureStatus_out, long long unsigned int * id_out, cudaGraph_t * graph_out, cudaGraphNode_t const * * dependencies_out, size_t * numDependencies_out){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetCaptureInfo_v2) (cudaStream_t, cudaStreamCaptureStatus *, long long unsigned int *, cudaGraph_t *, cudaGraphNode_t const * *, size_t *) = (cudaError_t (*)(cudaStream_t, cudaStreamCaptureStatus *, long long unsigned int *, cudaGraph_t *, cudaGraphNode_t const * *, size_t *))dlsym(RTLD_NEXT, "cudaStreamGetCaptureInfo_v2");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamGetCaptureInfo_v2",
        /* api_index */ CUDA_MEMORY_API_cudaStreamGetCaptureInfo_v2,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamGetCaptureInfo_v2(stream, captureStatus_out, id_out, graph_out, dependencies_out, numDependencies_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaStreamUpdateCaptureDependencies(cudaStream_t stream, cudaGraphNode_t * dependencies, size_t numDependencies, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamUpdateCaptureDependencies) (cudaStream_t, cudaGraphNode_t *, size_t, unsigned int) = (cudaError_t (*)(cudaStream_t, cudaGraphNode_t *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaStreamUpdateCaptureDependencies");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaStreamUpdateCaptureDependencies",
        /* api_index */ CUDA_MEMORY_API_cudaStreamUpdateCaptureDependencies,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaStreamUpdateCaptureDependencies(stream, dependencies, numDependencies, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaEventCreate(cudaEvent_t * event){
    cudaError_t lretval;
    cudaError_t (*lcudaEventCreate) (cudaEvent_t *) = (cudaError_t (*)(cudaEvent_t *))dlsym(RTLD_NEXT, "cudaEventCreate");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaEventCreate",
        /* api_index */ CUDA_MEMORY_API_cudaEventCreate,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaEventCreate(event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaEventCreateWithFlags(cudaEvent_t * event, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaEventCreateWithFlags) (cudaEvent_t *, unsigned int) = (cudaError_t (*)(cudaEvent_t *, unsigned int))dlsym(RTLD_NEXT, "cudaEventCreateWithFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaEventCreateWithFlags",
        /* api_index */ CUDA_MEMORY_API_cudaEventCreateWithFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaEventCreateWithFlags(event, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaEventRecord) (cudaEvent_t, cudaStream_t) = (cudaError_t (*)(cudaEvent_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaEventRecord");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaEventRecord",
        /* api_index */ CUDA_MEMORY_API_cudaEventRecord,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaEventRecord(event, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaEventRecordWithFlags(cudaEvent_t event, cudaStream_t stream, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaEventRecordWithFlags) (cudaEvent_t, cudaStream_t, unsigned int) = (cudaError_t (*)(cudaEvent_t, cudaStream_t, unsigned int))dlsym(RTLD_NEXT, "cudaEventRecordWithFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaEventRecordWithFlags",
        /* api_index */ CUDA_MEMORY_API_cudaEventRecordWithFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaEventRecordWithFlags(event, stream, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaEventQuery(cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaEventQuery) (cudaEvent_t) = (cudaError_t (*)(cudaEvent_t))dlsym(RTLD_NEXT, "cudaEventQuery");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaEventQuery",
        /* api_index */ CUDA_MEMORY_API_cudaEventQuery,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaEventQuery(event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaEventSynchronize(cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaEventSynchronize) (cudaEvent_t) = (cudaError_t (*)(cudaEvent_t))dlsym(RTLD_NEXT, "cudaEventSynchronize");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaEventSynchronize",
        /* api_index */ CUDA_MEMORY_API_cudaEventSynchronize,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaEventSynchronize(event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaEventDestroy(cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaEventDestroy) (cudaEvent_t) = (cudaError_t (*)(cudaEvent_t))dlsym(RTLD_NEXT, "cudaEventDestroy");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaEventDestroy",
        /* api_index */ CUDA_MEMORY_API_cudaEventDestroy,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaEventDestroy(event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaEventElapsedTime(float * ms, cudaEvent_t start, cudaEvent_t end){
    cudaError_t lretval;
    cudaError_t (*lcudaEventElapsedTime) (float *, cudaEvent_t, cudaEvent_t) = (cudaError_t (*)(float *, cudaEvent_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaEventElapsedTime");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaEventElapsedTime",
        /* api_index */ CUDA_MEMORY_API_cudaEventElapsedTime,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaEventElapsedTime(ms, start, end);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaImportExternalMemory(cudaExternalMemory_t * extMem_out, cudaExternalMemoryHandleDesc const * memHandleDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaImportExternalMemory) (cudaExternalMemory_t *, cudaExternalMemoryHandleDesc const *) = (cudaError_t (*)(cudaExternalMemory_t *, cudaExternalMemoryHandleDesc const *))dlsym(RTLD_NEXT, "cudaImportExternalMemory");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaImportExternalMemory",
        /* api_index */ CUDA_MEMORY_API_cudaImportExternalMemory,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaImportExternalMemory(extMem_out, memHandleDesc);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaExternalMemoryGetMappedBuffer(void * * devPtr, cudaExternalMemory_t extMem, cudaExternalMemoryBufferDesc const * bufferDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaExternalMemoryGetMappedBuffer) (void * *, cudaExternalMemory_t, cudaExternalMemoryBufferDesc const *) = (cudaError_t (*)(void * *, cudaExternalMemory_t, cudaExternalMemoryBufferDesc const *))dlsym(RTLD_NEXT, "cudaExternalMemoryGetMappedBuffer");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaExternalMemoryGetMappedBuffer",
        /* api_index */ CUDA_MEMORY_API_cudaExternalMemoryGetMappedBuffer,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaExternalMemoryGetMappedBuffer(devPtr, extMem, bufferDesc);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaExternalMemoryGetMappedMipmappedArray(cudaMipmappedArray_t * mipmap, cudaExternalMemory_t extMem, cudaExternalMemoryMipmappedArrayDesc const * mipmapDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaExternalMemoryGetMappedMipmappedArray) (cudaMipmappedArray_t *, cudaExternalMemory_t, cudaExternalMemoryMipmappedArrayDesc const *) = (cudaError_t (*)(cudaMipmappedArray_t *, cudaExternalMemory_t, cudaExternalMemoryMipmappedArrayDesc const *))dlsym(RTLD_NEXT, "cudaExternalMemoryGetMappedMipmappedArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaExternalMemoryGetMappedMipmappedArray",
        /* api_index */ CUDA_MEMORY_API_cudaExternalMemoryGetMappedMipmappedArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaExternalMemoryGetMappedMipmappedArray(mipmap, extMem, mipmapDesc);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDestroyExternalMemory(cudaExternalMemory_t extMem){
    cudaError_t lretval;
    cudaError_t (*lcudaDestroyExternalMemory) (cudaExternalMemory_t) = (cudaError_t (*)(cudaExternalMemory_t))dlsym(RTLD_NEXT, "cudaDestroyExternalMemory");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDestroyExternalMemory",
        /* api_index */ CUDA_MEMORY_API_cudaDestroyExternalMemory,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDestroyExternalMemory(extMem);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaImportExternalSemaphore(cudaExternalSemaphore_t * extSem_out, cudaExternalSemaphoreHandleDesc const * semHandleDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaImportExternalSemaphore) (cudaExternalSemaphore_t *, cudaExternalSemaphoreHandleDesc const *) = (cudaError_t (*)(cudaExternalSemaphore_t *, cudaExternalSemaphoreHandleDesc const *))dlsym(RTLD_NEXT, "cudaImportExternalSemaphore");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaImportExternalSemaphore",
        /* api_index */ CUDA_MEMORY_API_cudaImportExternalSemaphore,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaImportExternalSemaphore(extSem_out, semHandleDesc);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaSignalExternalSemaphoresAsync_v2(cudaExternalSemaphore_t const * extSemArray, cudaExternalSemaphoreSignalParams const * paramsArray, unsigned int numExtSems, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaSignalExternalSemaphoresAsync_v2) (cudaExternalSemaphore_t const *, cudaExternalSemaphoreSignalParams const *, unsigned int, cudaStream_t) = (cudaError_t (*)(cudaExternalSemaphore_t const *, cudaExternalSemaphoreSignalParams const *, unsigned int, cudaStream_t))dlsym(RTLD_NEXT, "cudaSignalExternalSemaphoresAsync_v2");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaSignalExternalSemaphoresAsync_v2",
        /* api_index */ CUDA_MEMORY_API_cudaSignalExternalSemaphoresAsync_v2,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaSignalExternalSemaphoresAsync_v2(extSemArray, paramsArray, numExtSems, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaWaitExternalSemaphoresAsync_v2(cudaExternalSemaphore_t const * extSemArray, cudaExternalSemaphoreWaitParams const * paramsArray, unsigned int numExtSems, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaWaitExternalSemaphoresAsync_v2) (cudaExternalSemaphore_t const *, cudaExternalSemaphoreWaitParams const *, unsigned int, cudaStream_t) = (cudaError_t (*)(cudaExternalSemaphore_t const *, cudaExternalSemaphoreWaitParams const *, unsigned int, cudaStream_t))dlsym(RTLD_NEXT, "cudaWaitExternalSemaphoresAsync_v2");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaWaitExternalSemaphoresAsync_v2",
        /* api_index */ CUDA_MEMORY_API_cudaWaitExternalSemaphoresAsync_v2,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaWaitExternalSemaphoresAsync_v2(extSemArray, paramsArray, numExtSems, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDestroyExternalSemaphore(cudaExternalSemaphore_t extSem){
    cudaError_t lretval;
    cudaError_t (*lcudaDestroyExternalSemaphore) (cudaExternalSemaphore_t) = (cudaError_t (*)(cudaExternalSemaphore_t))dlsym(RTLD_NEXT, "cudaDestroyExternalSemaphore");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDestroyExternalSemaphore",
        /* api_index */ CUDA_MEMORY_API_cudaDestroyExternalSemaphore,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDestroyExternalSemaphore(extSem);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaLaunchKernel(void const * func, dim3 gridDim, dim3 blockDim, void * * args, size_t sharedMem, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaLaunchKernel) (void const *, dim3, dim3, void * *, size_t, cudaStream_t) = (cudaError_t (*)(void const *, dim3, dim3, void * *, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaLaunchKernel");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaLaunchKernel",
        /* api_index */ CUDA_MEMORY_API_cudaLaunchKernel,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaLaunchKernel(func, gridDim, blockDim, args, sharedMem, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaLaunchCooperativeKernel(void const * func, dim3 gridDim, dim3 blockDim, void * * args, size_t sharedMem, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaLaunchCooperativeKernel) (void const *, dim3, dim3, void * *, size_t, cudaStream_t) = (cudaError_t (*)(void const *, dim3, dim3, void * *, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaLaunchCooperativeKernel");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaLaunchCooperativeKernel",
        /* api_index */ CUDA_MEMORY_API_cudaLaunchCooperativeKernel,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaLaunchCooperativeKernel(func, gridDim, blockDim, args, sharedMem, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaLaunchCooperativeKernelMultiDevice(cudaLaunchParams * launchParamsList, unsigned int numDevices, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaLaunchCooperativeKernelMultiDevice) (cudaLaunchParams *, unsigned int, unsigned int) = (cudaError_t (*)(cudaLaunchParams *, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaLaunchCooperativeKernelMultiDevice");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaLaunchCooperativeKernelMultiDevice",
        /* api_index */ CUDA_MEMORY_API_cudaLaunchCooperativeKernelMultiDevice,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaLaunchCooperativeKernelMultiDevice(launchParamsList, numDevices, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaFuncSetCacheConfig(void const * func, cudaFuncCache cacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaFuncSetCacheConfig) (void const *, cudaFuncCache) = (cudaError_t (*)(void const *, cudaFuncCache))dlsym(RTLD_NEXT, "cudaFuncSetCacheConfig");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFuncSetCacheConfig",
        /* api_index */ CUDA_MEMORY_API_cudaFuncSetCacheConfig,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaFuncSetCacheConfig(func, cacheConfig);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaFuncSetSharedMemConfig(void const * func, cudaSharedMemConfig config){
    cudaError_t lretval;
    cudaError_t (*lcudaFuncSetSharedMemConfig) (void const *, cudaSharedMemConfig) = (cudaError_t (*)(void const *, cudaSharedMemConfig))dlsym(RTLD_NEXT, "cudaFuncSetSharedMemConfig");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFuncSetSharedMemConfig",
        /* api_index */ CUDA_MEMORY_API_cudaFuncSetSharedMemConfig,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaFuncSetSharedMemConfig(func, config);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, void const * func){
    cudaError_t lretval;
    cudaError_t (*lcudaFuncGetAttributes) (cudaFuncAttributes *, void const *) = (cudaError_t (*)(cudaFuncAttributes *, void const *))dlsym(RTLD_NEXT, "cudaFuncGetAttributes");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFuncGetAttributes",
        /* api_index */ CUDA_MEMORY_API_cudaFuncGetAttributes,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaFuncGetAttributes(attr, func);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaFuncSetAttribute(void const * func, cudaFuncAttribute attr, int value){
    cudaError_t lretval;
    cudaError_t (*lcudaFuncSetAttribute) (void const *, cudaFuncAttribute, int) = (cudaError_t (*)(void const *, cudaFuncAttribute, int))dlsym(RTLD_NEXT, "cudaFuncSetAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFuncSetAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaFuncSetAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaFuncSetAttribute(func, attr, value);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaSetDoubleForDevice(double * d){
    cudaError_t lretval;
    cudaError_t (*lcudaSetDoubleForDevice) (double *) = (cudaError_t (*)(double *))dlsym(RTLD_NEXT, "cudaSetDoubleForDevice");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaSetDoubleForDevice",
        /* api_index */ CUDA_MEMORY_API_cudaSetDoubleForDevice,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaSetDoubleForDevice(d);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaSetDoubleForHost(double * d){
    cudaError_t lretval;
    cudaError_t (*lcudaSetDoubleForHost) (double *) = (cudaError_t (*)(double *))dlsym(RTLD_NEXT, "cudaSetDoubleForHost");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaSetDoubleForHost",
        /* api_index */ CUDA_MEMORY_API_cudaSetDoubleForHost,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaSetDoubleForHost(d);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaLaunchHostFunc(cudaStream_t stream, cudaHostFn_t fn, void * userData){
    cudaError_t lretval;
    cudaError_t (*lcudaLaunchHostFunc) (cudaStream_t, cudaHostFn_t, void *) = (cudaError_t (*)(cudaStream_t, cudaHostFn_t, void *))dlsym(RTLD_NEXT, "cudaLaunchHostFunc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaLaunchHostFunc",
        /* api_index */ CUDA_MEMORY_API_cudaLaunchHostFunc,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaLaunchHostFunc(stream, fn, userData);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, void const * func, int blockSize, size_t dynamicSMemSize){
    cudaError_t lretval;
    cudaError_t (*lcudaOccupancyMaxActiveBlocksPerMultiprocessor) (int *, void const *, int, size_t) = (cudaError_t (*)(int *, void const *, int, size_t))dlsym(RTLD_NEXT, "cudaOccupancyMaxActiveBlocksPerMultiprocessor");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaOccupancyMaxActiveBlocksPerMultiprocessor",
        /* api_index */ CUDA_MEMORY_API_cudaOccupancyMaxActiveBlocksPerMultiprocessor,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaOccupancyMaxActiveBlocksPerMultiprocessor(numBlocks, func, blockSize, dynamicSMemSize);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaOccupancyAvailableDynamicSMemPerBlock(size_t * dynamicSmemSize, void const * func, int numBlocks, int blockSize){
    cudaError_t lretval;
    cudaError_t (*lcudaOccupancyAvailableDynamicSMemPerBlock) (size_t *, void const *, int, int) = (cudaError_t (*)(size_t *, void const *, int, int))dlsym(RTLD_NEXT, "cudaOccupancyAvailableDynamicSMemPerBlock");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaOccupancyAvailableDynamicSMemPerBlock",
        /* api_index */ CUDA_MEMORY_API_cudaOccupancyAvailableDynamicSMemPerBlock,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaOccupancyAvailableDynamicSMemPerBlock(dynamicSmemSize, func, numBlocks, blockSize);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, void const * func, int blockSize, size_t dynamicSMemSize, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags) (int *, void const *, int, size_t, unsigned int) = (cudaError_t (*)(int *, void const *, int, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags",
        /* api_index */ CUDA_MEMORY_API_cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, func, blockSize, dynamicSMemSize, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMallocManaged(void * * devPtr, size_t size, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocManaged) (void * *, size_t, unsigned int) = (cudaError_t (*)(void * *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaMallocManaged");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMallocManaged",
        /* api_index */ CUDA_MEMORY_API_cudaMallocManaged,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMallocManaged(devPtr, size, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMalloc(void * * devPtr, size_t size){
    cudaError_t lretval;
    cudaError_t (*lcudaMalloc) (void * *, size_t) = (cudaError_t (*)(void * *, size_t))dlsym(RTLD_NEXT, "cudaMalloc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMalloc",
        /* api_index */ CUDA_MEMORY_API_cudaMalloc,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMalloc(devPtr, size);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMallocHost(void * * ptr, size_t size){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocHost) (void * *, size_t) = (cudaError_t (*)(void * *, size_t))dlsym(RTLD_NEXT, "cudaMallocHost");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMallocHost",
        /* api_index */ CUDA_MEMORY_API_cudaMallocHost,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMallocHost(ptr, size);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMallocPitch(void * * devPtr, size_t * pitch, size_t width, size_t height){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocPitch) (void * *, size_t *, size_t, size_t) = (cudaError_t (*)(void * *, size_t *, size_t, size_t))dlsym(RTLD_NEXT, "cudaMallocPitch");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMallocPitch",
        /* api_index */ CUDA_MEMORY_API_cudaMallocPitch,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMallocPitch(devPtr, pitch, width, height);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMallocArray(cudaArray_t * array, cudaChannelFormatDesc const * desc, size_t width, size_t height, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocArray) (cudaArray_t *, cudaChannelFormatDesc const *, size_t, size_t, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaChannelFormatDesc const *, size_t, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaMallocArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMallocArray",
        /* api_index */ CUDA_MEMORY_API_cudaMallocArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMallocArray(array, desc, width, height, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaFree(void * devPtr){
    cudaError_t lretval;
    cudaError_t (*lcudaFree) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaFree");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFree",
        /* api_index */ CUDA_MEMORY_API_cudaFree,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaFree(devPtr);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaFreeHost(void * ptr){
    cudaError_t lretval;
    cudaError_t (*lcudaFreeHost) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaFreeHost");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFreeHost",
        /* api_index */ CUDA_MEMORY_API_cudaFreeHost,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaFreeHost(ptr);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaFreeArray(cudaArray_t array){
    cudaError_t lretval;
    cudaError_t (*lcudaFreeArray) (cudaArray_t) = (cudaError_t (*)(cudaArray_t))dlsym(RTLD_NEXT, "cudaFreeArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFreeArray",
        /* api_index */ CUDA_MEMORY_API_cudaFreeArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaFreeArray(array);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaFreeMipmappedArray(cudaMipmappedArray_t mipmappedArray){
    cudaError_t lretval;
    cudaError_t (*lcudaFreeMipmappedArray) (cudaMipmappedArray_t) = (cudaError_t (*)(cudaMipmappedArray_t))dlsym(RTLD_NEXT, "cudaFreeMipmappedArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFreeMipmappedArray",
        /* api_index */ CUDA_MEMORY_API_cudaFreeMipmappedArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaFreeMipmappedArray(mipmappedArray);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaHostAlloc(void * * pHost, size_t size, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaHostAlloc) (void * *, size_t, unsigned int) = (cudaError_t (*)(void * *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaHostAlloc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaHostAlloc",
        /* api_index */ CUDA_MEMORY_API_cudaHostAlloc,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaHostAlloc(pHost, size, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaHostRegister(void * ptr, size_t size, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaHostRegister) (void *, size_t, unsigned int) = (cudaError_t (*)(void *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaHostRegister");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaHostRegister",
        /* api_index */ CUDA_MEMORY_API_cudaHostRegister,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaHostRegister(ptr, size, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaHostUnregister(void * ptr){
    cudaError_t lretval;
    cudaError_t (*lcudaHostUnregister) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaHostUnregister");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaHostUnregister",
        /* api_index */ CUDA_MEMORY_API_cudaHostUnregister,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaHostUnregister(ptr);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaHostGetDevicePointer(void * * pDevice, void * pHost, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaHostGetDevicePointer) (void * *, void *, unsigned int) = (cudaError_t (*)(void * *, void *, unsigned int))dlsym(RTLD_NEXT, "cudaHostGetDevicePointer");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaHostGetDevicePointer",
        /* api_index */ CUDA_MEMORY_API_cudaHostGetDevicePointer,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaHostGetDevicePointer(pDevice, pHost, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaHostGetFlags(unsigned int * pFlags, void * pHost){
    cudaError_t lretval;
    cudaError_t (*lcudaHostGetFlags) (unsigned int *, void *) = (cudaError_t (*)(unsigned int *, void *))dlsym(RTLD_NEXT, "cudaHostGetFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaHostGetFlags",
        /* api_index */ CUDA_MEMORY_API_cudaHostGetFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaHostGetFlags(pFlags, pHost);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMalloc3D(cudaPitchedPtr * pitchedDevPtr, cudaExtent extent){
    cudaError_t lretval;
    cudaError_t (*lcudaMalloc3D) (cudaPitchedPtr *, cudaExtent) = (cudaError_t (*)(cudaPitchedPtr *, cudaExtent))dlsym(RTLD_NEXT, "cudaMalloc3D");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMalloc3D",
        /* api_index */ CUDA_MEMORY_API_cudaMalloc3D,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMalloc3D(pitchedDevPtr, extent);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMalloc3DArray(cudaArray_t * array, cudaChannelFormatDesc const * desc, cudaExtent extent, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMalloc3DArray) (cudaArray_t *, cudaChannelFormatDesc const *, cudaExtent, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaChannelFormatDesc const *, cudaExtent, unsigned int))dlsym(RTLD_NEXT, "cudaMalloc3DArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMalloc3DArray",
        /* api_index */ CUDA_MEMORY_API_cudaMalloc3DArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMalloc3DArray(array, desc, extent, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMallocMipmappedArray(cudaMipmappedArray_t * mipmappedArray, cudaChannelFormatDesc const * desc, cudaExtent extent, unsigned int numLevels, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocMipmappedArray) (cudaMipmappedArray_t *, cudaChannelFormatDesc const *, cudaExtent, unsigned int, unsigned int) = (cudaError_t (*)(cudaMipmappedArray_t *, cudaChannelFormatDesc const *, cudaExtent, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaMallocMipmappedArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMallocMipmappedArray",
        /* api_index */ CUDA_MEMORY_API_cudaMallocMipmappedArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMallocMipmappedArray(mipmappedArray, desc, extent, numLevels, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetMipmappedArrayLevel(cudaArray_t * levelArray, cudaMipmappedArray_const_t mipmappedArray, unsigned int level){
    cudaError_t lretval;
    cudaError_t (*lcudaGetMipmappedArrayLevel) (cudaArray_t *, cudaMipmappedArray_const_t, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaMipmappedArray_const_t, unsigned int))dlsym(RTLD_NEXT, "cudaGetMipmappedArrayLevel");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetMipmappedArrayLevel",
        /* api_index */ CUDA_MEMORY_API_cudaGetMipmappedArrayLevel,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetMipmappedArrayLevel(levelArray, mipmappedArray, level);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy3D(cudaMemcpy3DParms const * p){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy3D) (cudaMemcpy3DParms const *) = (cudaError_t (*)(cudaMemcpy3DParms const *))dlsym(RTLD_NEXT, "cudaMemcpy3D");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy3D",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy3D,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy3D(p);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy3DPeer(cudaMemcpy3DPeerParms const * p){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy3DPeer) (cudaMemcpy3DPeerParms const *) = (cudaError_t (*)(cudaMemcpy3DPeerParms const *))dlsym(RTLD_NEXT, "cudaMemcpy3DPeer");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy3DPeer",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy3DPeer,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy3DPeer(p);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy3DAsync(cudaMemcpy3DParms const * p, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy3DAsync) (cudaMemcpy3DParms const *, cudaStream_t) = (cudaError_t (*)(cudaMemcpy3DParms const *, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy3DAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy3DAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy3DAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy3DAsync(p, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy3DPeerAsync(cudaMemcpy3DPeerParms const * p, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy3DPeerAsync) (cudaMemcpy3DPeerParms const *, cudaStream_t) = (cudaError_t (*)(cudaMemcpy3DPeerParms const *, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy3DPeerAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy3DPeerAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy3DPeerAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy3DPeerAsync(p, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemGetInfo(size_t * free, size_t * total){
    cudaError_t lretval;
    cudaError_t (*lcudaMemGetInfo) (size_t *, size_t *) = (cudaError_t (*)(size_t *, size_t *))dlsym(RTLD_NEXT, "cudaMemGetInfo");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemGetInfo",
        /* api_index */ CUDA_MEMORY_API_cudaMemGetInfo,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemGetInfo(free, total);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaArrayGetInfo(cudaChannelFormatDesc * desc, cudaExtent * extent, unsigned int * flags, cudaArray_t array){
    cudaError_t lretval;
    cudaError_t (*lcudaArrayGetInfo) (cudaChannelFormatDesc *, cudaExtent *, unsigned int *, cudaArray_t) = (cudaError_t (*)(cudaChannelFormatDesc *, cudaExtent *, unsigned int *, cudaArray_t))dlsym(RTLD_NEXT, "cudaArrayGetInfo");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaArrayGetInfo",
        /* api_index */ CUDA_MEMORY_API_cudaArrayGetInfo,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaArrayGetInfo(desc, extent, flags, array);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaArrayGetPlane(cudaArray_t * pPlaneArray, cudaArray_t hArray, unsigned int planeIdx){
    cudaError_t lretval;
    cudaError_t (*lcudaArrayGetPlane) (cudaArray_t *, cudaArray_t, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaArray_t, unsigned int))dlsym(RTLD_NEXT, "cudaArrayGetPlane");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaArrayGetPlane",
        /* api_index */ CUDA_MEMORY_API_cudaArrayGetPlane,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaArrayGetPlane(pPlaneArray, hArray, planeIdx);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaArray_t array){
    cudaError_t lretval;
    cudaError_t (*lcudaArrayGetSparseProperties) (cudaArraySparseProperties *, cudaArray_t) = (cudaError_t (*)(cudaArraySparseProperties *, cudaArray_t))dlsym(RTLD_NEXT, "cudaArrayGetSparseProperties");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaArrayGetSparseProperties",
        /* api_index */ CUDA_MEMORY_API_cudaArrayGetSparseProperties,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaArrayGetSparseProperties(sparseProperties, array);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMipmappedArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaMipmappedArray_t mipmap){
    cudaError_t lretval;
    cudaError_t (*lcudaMipmappedArrayGetSparseProperties) (cudaArraySparseProperties *, cudaMipmappedArray_t) = (cudaError_t (*)(cudaArraySparseProperties *, cudaMipmappedArray_t))dlsym(RTLD_NEXT, "cudaMipmappedArrayGetSparseProperties");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMipmappedArrayGetSparseProperties",
        /* api_index */ CUDA_MEMORY_API_cudaMipmappedArrayGetSparseProperties,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMipmappedArrayGetSparseProperties(sparseProperties, mipmap);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy(void * dst, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy) (void *, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy(dst, src, count, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyPeer(void * dst, int dstDevice, void const * src, int srcDevice, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyPeer) (void *, int, void const *, int, size_t) = (cudaError_t (*)(void *, int, void const *, int, size_t))dlsym(RTLD_NEXT, "cudaMemcpyPeer");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyPeer",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyPeer,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyPeer(dst, dstDevice, src, srcDevice, count);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy2D(void * dst, size_t dpitch, void const * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2D) (void *, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy2D");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy2D",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy2D,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy2D(dst, dpitch, src, spitch, width, height, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy2DToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, void const * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DToArray) (cudaArray_t, size_t, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaArray_t, size_t, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy2DToArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy2DToArray",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy2DToArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy2DToArray(dst, wOffset, hOffset, src, spitch, width, height, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy2DFromArray(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DFromArray) (void *, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy2DFromArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy2DFromArray",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy2DFromArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy2DFromArray(dst, dpitch, src, wOffset, hOffset, width, height, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy2DArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DArrayToArray) (cudaArray_t, size_t, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaArray_t, size_t, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy2DArrayToArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy2DArrayToArray",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy2DArrayToArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy2DArrayToArray(dst, wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc, width, height, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyToSymbol(void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyToSymbol) (void const *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void const *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyToSymbol");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyToSymbol",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyToSymbol,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyToSymbol(symbol, src, count, offset, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyFromSymbol(void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyFromSymbol) (void *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyFromSymbol");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyFromSymbol",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyFromSymbol,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyFromSymbol(dst, symbol, count, offset, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyAsync(void * dst, void const * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyAsync) (void *, void const *, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, void const *, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyAsync(dst, src, count, kind, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyPeerAsync(void * dst, int dstDevice, void const * src, int srcDevice, size_t count, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyPeerAsync) (void *, int, void const *, int, size_t, cudaStream_t) = (cudaError_t (*)(void *, int, void const *, int, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyPeerAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyPeerAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyPeerAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyPeerAsync(dst, dstDevice, src, srcDevice, count, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy2DAsync(void * dst, size_t dpitch, void const * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DAsync) (void *, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy2DAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy2DAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy2DAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy2DAsync(dst, dpitch, src, spitch, width, height, kind, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy2DToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, void const * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DToArrayAsync) (cudaArray_t, size_t, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(cudaArray_t, size_t, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy2DToArrayAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy2DToArrayAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy2DToArrayAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy2DToArrayAsync(dst, wOffset, hOffset, src, spitch, width, height, kind, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpy2DFromArrayAsync(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DFromArrayAsync) (void *, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy2DFromArrayAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy2DFromArrayAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy2DFromArrayAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy2DFromArrayAsync(dst, dpitch, src, wOffset, hOffset, width, height, kind, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyToSymbolAsync(void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyToSymbolAsync) (void const *, void const *, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void const *, void const *, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyToSymbolAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyToSymbolAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyToSymbolAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyToSymbolAsync(symbol, src, count, offset, kind, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyFromSymbolAsync(void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyFromSymbolAsync) (void *, void const *, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, void const *, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyFromSymbolAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyFromSymbolAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyFromSymbolAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyFromSymbolAsync(dst, symbol, count, offset, kind, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemset(void * devPtr, int value, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset) (void *, int, size_t) = (cudaError_t (*)(void *, int, size_t))dlsym(RTLD_NEXT, "cudaMemset");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemset",
        /* api_index */ CUDA_MEMORY_API_cudaMemset,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemset(devPtr, value, count);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemset2D(void * devPtr, size_t pitch, int value, size_t width, size_t height){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset2D) (void *, size_t, int, size_t, size_t) = (cudaError_t (*)(void *, size_t, int, size_t, size_t))dlsym(RTLD_NEXT, "cudaMemset2D");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemset2D",
        /* api_index */ CUDA_MEMORY_API_cudaMemset2D,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemset2D(devPtr, pitch, value, width, height);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemset3D(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset3D) (cudaPitchedPtr, int, cudaExtent) = (cudaError_t (*)(cudaPitchedPtr, int, cudaExtent))dlsym(RTLD_NEXT, "cudaMemset3D");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemset3D",
        /* api_index */ CUDA_MEMORY_API_cudaMemset3D,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemset3D(pitchedDevPtr, value, extent);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemsetAsync) (void *, int, size_t, cudaStream_t) = (cudaError_t (*)(void *, int, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemsetAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemsetAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemsetAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemsetAsync(devPtr, value, count, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemset2DAsync(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset2DAsync) (void *, size_t, int, size_t, size_t, cudaStream_t) = (cudaError_t (*)(void *, size_t, int, size_t, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemset2DAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemset2DAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemset2DAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemset2DAsync(devPtr, pitch, value, width, height, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset3DAsync) (cudaPitchedPtr, int, cudaExtent, cudaStream_t) = (cudaError_t (*)(cudaPitchedPtr, int, cudaExtent, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemset3DAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemset3DAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemset3DAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemset3DAsync(pitchedDevPtr, value, extent, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetSymbolAddress(void * * devPtr, void const * symbol){
    cudaError_t lretval;
    cudaError_t (*lcudaGetSymbolAddress) (void * *, void const *) = (cudaError_t (*)(void * *, void const *))dlsym(RTLD_NEXT, "cudaGetSymbolAddress");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetSymbolAddress",
        /* api_index */ CUDA_MEMORY_API_cudaGetSymbolAddress,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetSymbolAddress(devPtr, symbol);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetSymbolSize(size_t * size, void const * symbol){
    cudaError_t lretval;
    cudaError_t (*lcudaGetSymbolSize) (size_t *, void const *) = (cudaError_t (*)(size_t *, void const *))dlsym(RTLD_NEXT, "cudaGetSymbolSize");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetSymbolSize",
        /* api_index */ CUDA_MEMORY_API_cudaGetSymbolSize,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetSymbolSize(size, symbol);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPrefetchAsync(void const * devPtr, size_t count, int dstDevice, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPrefetchAsync) (void const *, size_t, int, cudaStream_t) = (cudaError_t (*)(void const *, size_t, int, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemPrefetchAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPrefetchAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemPrefetchAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPrefetchAsync(devPtr, count, dstDevice, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemAdvise(void const * devPtr, size_t count, cudaMemoryAdvise advice, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaMemAdvise) (void const *, size_t, cudaMemoryAdvise, int) = (cudaError_t (*)(void const *, size_t, cudaMemoryAdvise, int))dlsym(RTLD_NEXT, "cudaMemAdvise");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemAdvise",
        /* api_index */ CUDA_MEMORY_API_cudaMemAdvise,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemAdvise(devPtr, count, advice, device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemRangeGetAttribute(void * data, size_t dataSize, cudaMemRangeAttribute attribute, void const * devPtr, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemRangeGetAttribute) (void *, size_t, cudaMemRangeAttribute, void const *, size_t) = (cudaError_t (*)(void *, size_t, cudaMemRangeAttribute, void const *, size_t))dlsym(RTLD_NEXT, "cudaMemRangeGetAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemRangeGetAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaMemRangeGetAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemRangeGetAttribute(data, dataSize, attribute, devPtr, count);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemRangeGetAttributes(void * * data, size_t * dataSizes, cudaMemRangeAttribute * attributes, size_t numAttributes, void const * devPtr, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemRangeGetAttributes) (void * *, size_t *, cudaMemRangeAttribute *, size_t, void const *, size_t) = (cudaError_t (*)(void * *, size_t *, cudaMemRangeAttribute *, size_t, void const *, size_t))dlsym(RTLD_NEXT, "cudaMemRangeGetAttributes");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemRangeGetAttributes",
        /* api_index */ CUDA_MEMORY_API_cudaMemRangeGetAttributes,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemRangeGetAttributes(data, dataSizes, attributes, numAttributes, devPtr, count);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyToArray) (cudaArray_t, size_t, size_t, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaArray_t, size_t, size_t, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyToArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyToArray",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyToArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyToArray(dst, wOffset, hOffset, src, count, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyFromArray(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyFromArray) (void *, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyFromArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyFromArray",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyFromArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyFromArray(dst, src, wOffset, hOffset, count, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyArrayToArray) (cudaArray_t, size_t, size_t, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaArray_t, size_t, size_t, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyArrayToArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyArrayToArray",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyArrayToArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyArrayToArray(dst, wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc, count, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, void const * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyToArrayAsync) (cudaArray_t, size_t, size_t, void const *, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(cudaArray_t, size_t, size_t, void const *, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyToArrayAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyToArrayAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyToArrayAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyToArrayAsync(dst, wOffset, hOffset, src, count, kind, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemcpyFromArrayAsync(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyFromArrayAsync) (void *, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyFromArrayAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyFromArrayAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyFromArrayAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyFromArrayAsync(dst, src, wOffset, hOffset, count, kind, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMallocAsync(void * * devPtr, size_t size, cudaStream_t hStream){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocAsync) (void * *, size_t, cudaStream_t) = (cudaError_t (*)(void * *, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMallocAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMallocAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMallocAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMallocAsync(devPtr, size, hStream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaFreeAsync(void * devPtr, cudaStream_t hStream){
    cudaError_t lretval;
    cudaError_t (*lcudaFreeAsync) (void *, cudaStream_t) = (cudaError_t (*)(void *, cudaStream_t))dlsym(RTLD_NEXT, "cudaFreeAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFreeAsync",
        /* api_index */ CUDA_MEMORY_API_cudaFreeAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaFreeAsync(devPtr, hStream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolTrimTo(cudaMemPool_t memPool, size_t minBytesToKeep){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolTrimTo) (cudaMemPool_t, size_t) = (cudaError_t (*)(cudaMemPool_t, size_t))dlsym(RTLD_NEXT, "cudaMemPoolTrimTo");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolTrimTo",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolTrimTo,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolTrimTo(memPool, minBytesToKeep);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolSetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolSetAttribute) (cudaMemPool_t, cudaMemPoolAttr, void *) = (cudaError_t (*)(cudaMemPool_t, cudaMemPoolAttr, void *))dlsym(RTLD_NEXT, "cudaMemPoolSetAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolSetAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolSetAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolSetAttribute(memPool, attr, value);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolGetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolGetAttribute) (cudaMemPool_t, cudaMemPoolAttr, void *) = (cudaError_t (*)(cudaMemPool_t, cudaMemPoolAttr, void *))dlsym(RTLD_NEXT, "cudaMemPoolGetAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolGetAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolGetAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolGetAttribute(memPool, attr, value);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolSetAccess(cudaMemPool_t memPool, cudaMemAccessDesc const * descList, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolSetAccess) (cudaMemPool_t, cudaMemAccessDesc const *, size_t) = (cudaError_t (*)(cudaMemPool_t, cudaMemAccessDesc const *, size_t))dlsym(RTLD_NEXT, "cudaMemPoolSetAccess");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolSetAccess",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolSetAccess,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolSetAccess(memPool, descList, count);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolGetAccess(cudaMemAccessFlags * flags, cudaMemPool_t memPool, cudaMemLocation * location){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolGetAccess) (cudaMemAccessFlags *, cudaMemPool_t, cudaMemLocation *) = (cudaError_t (*)(cudaMemAccessFlags *, cudaMemPool_t, cudaMemLocation *))dlsym(RTLD_NEXT, "cudaMemPoolGetAccess");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolGetAccess",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolGetAccess,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolGetAccess(flags, memPool, location);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolCreate(cudaMemPool_t * memPool, cudaMemPoolProps const * poolProps){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolCreate) (cudaMemPool_t *, cudaMemPoolProps const *) = (cudaError_t (*)(cudaMemPool_t *, cudaMemPoolProps const *))dlsym(RTLD_NEXT, "cudaMemPoolCreate");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolCreate",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolCreate,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolCreate(memPool, poolProps);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolDestroy(cudaMemPool_t memPool){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolDestroy) (cudaMemPool_t) = (cudaError_t (*)(cudaMemPool_t))dlsym(RTLD_NEXT, "cudaMemPoolDestroy");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolDestroy",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolDestroy,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolDestroy(memPool);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMallocFromPoolAsync(void * * ptr, size_t size, cudaMemPool_t memPool, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocFromPoolAsync) (void * *, size_t, cudaMemPool_t, cudaStream_t) = (cudaError_t (*)(void * *, size_t, cudaMemPool_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMallocFromPoolAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMallocFromPoolAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMallocFromPoolAsync,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMallocFromPoolAsync(ptr, size, memPool, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolExportToShareableHandle(void * shareableHandle, cudaMemPool_t memPool, cudaMemAllocationHandleType handleType, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolExportToShareableHandle) (void *, cudaMemPool_t, cudaMemAllocationHandleType, unsigned int) = (cudaError_t (*)(void *, cudaMemPool_t, cudaMemAllocationHandleType, unsigned int))dlsym(RTLD_NEXT, "cudaMemPoolExportToShareableHandle");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolExportToShareableHandle",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolExportToShareableHandle,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolExportToShareableHandle(shareableHandle, memPool, handleType, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolImportFromShareableHandle(cudaMemPool_t * memPool, void * shareableHandle, cudaMemAllocationHandleType handleType, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolImportFromShareableHandle) (cudaMemPool_t *, void *, cudaMemAllocationHandleType, unsigned int) = (cudaError_t (*)(cudaMemPool_t *, void *, cudaMemAllocationHandleType, unsigned int))dlsym(RTLD_NEXT, "cudaMemPoolImportFromShareableHandle");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolImportFromShareableHandle",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolImportFromShareableHandle,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolImportFromShareableHandle(memPool, shareableHandle, handleType, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolExportPointer(cudaMemPoolPtrExportData * exportData, void * ptr){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolExportPointer) (cudaMemPoolPtrExportData *, void *) = (cudaError_t (*)(cudaMemPoolPtrExportData *, void *))dlsym(RTLD_NEXT, "cudaMemPoolExportPointer");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolExportPointer",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolExportPointer,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolExportPointer(exportData, ptr);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMemPoolImportPointer(void * * ptr, cudaMemPool_t memPool, cudaMemPoolPtrExportData * exportData){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolImportPointer) (void * *, cudaMemPool_t, cudaMemPoolPtrExportData *) = (cudaError_t (*)(void * *, cudaMemPool_t, cudaMemPoolPtrExportData *))dlsym(RTLD_NEXT, "cudaMemPoolImportPointer");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemPoolImportPointer",
        /* api_index */ CUDA_MEMORY_API_cudaMemPoolImportPointer,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemPoolImportPointer(ptr, memPool, exportData);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaPointerGetAttributes(cudaPointerAttributes * attributes, void const * ptr){
    cudaError_t lretval;
    cudaError_t (*lcudaPointerGetAttributes) (cudaPointerAttributes *, void const *) = (cudaError_t (*)(cudaPointerAttributes *, void const *))dlsym(RTLD_NEXT, "cudaPointerGetAttributes");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaPointerGetAttributes",
        /* api_index */ CUDA_MEMORY_API_cudaPointerGetAttributes,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaPointerGetAttributes(attributes, ptr);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceCanAccessPeer(int * canAccessPeer, int device, int peerDevice){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceCanAccessPeer) (int *, int, int) = (cudaError_t (*)(int *, int, int))dlsym(RTLD_NEXT, "cudaDeviceCanAccessPeer");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceCanAccessPeer",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceCanAccessPeer,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceCanAccessPeer(canAccessPeer, device, peerDevice);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceEnablePeerAccess(int peerDevice, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceEnablePeerAccess) (int, unsigned int) = (cudaError_t (*)(int, unsigned int))dlsym(RTLD_NEXT, "cudaDeviceEnablePeerAccess");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceEnablePeerAccess",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceEnablePeerAccess,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceEnablePeerAccess(peerDevice, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceDisablePeerAccess(int peerDevice){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceDisablePeerAccess) (int) = (cudaError_t (*)(int))dlsym(RTLD_NEXT, "cudaDeviceDisablePeerAccess");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceDisablePeerAccess",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceDisablePeerAccess,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceDisablePeerAccess(peerDevice);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource_t resource){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsUnregisterResource) (cudaGraphicsResource_t) = (cudaError_t (*)(cudaGraphicsResource_t))dlsym(RTLD_NEXT, "cudaGraphicsUnregisterResource");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphicsUnregisterResource",
        /* api_index */ CUDA_MEMORY_API_cudaGraphicsUnregisterResource,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphicsUnregisterResource(resource);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t resource, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsResourceSetMapFlags) (cudaGraphicsResource_t, unsigned int) = (cudaError_t (*)(cudaGraphicsResource_t, unsigned int))dlsym(RTLD_NEXT, "cudaGraphicsResourceSetMapFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphicsResourceSetMapFlags",
        /* api_index */ CUDA_MEMORY_API_cudaGraphicsResourceSetMapFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphicsResourceSetMapFlags(resource, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphicsMapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsMapResources) (int, cudaGraphicsResource_t *, cudaStream_t) = (cudaError_t (*)(int, cudaGraphicsResource_t *, cudaStream_t))dlsym(RTLD_NEXT, "cudaGraphicsMapResources");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphicsMapResources",
        /* api_index */ CUDA_MEMORY_API_cudaGraphicsMapResources,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphicsMapResources(count, resources, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphicsUnmapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsUnmapResources) (int, cudaGraphicsResource_t *, cudaStream_t) = (cudaError_t (*)(int, cudaGraphicsResource_t *, cudaStream_t))dlsym(RTLD_NEXT, "cudaGraphicsUnmapResources");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphicsUnmapResources",
        /* api_index */ CUDA_MEMORY_API_cudaGraphicsUnmapResources,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphicsUnmapResources(count, resources, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphicsResourceGetMappedPointer(void * * devPtr, size_t * size, cudaGraphicsResource_t resource){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsResourceGetMappedPointer) (void * *, size_t *, cudaGraphicsResource_t) = (cudaError_t (*)(void * *, size_t *, cudaGraphicsResource_t))dlsym(RTLD_NEXT, "cudaGraphicsResourceGetMappedPointer");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphicsResourceGetMappedPointer",
        /* api_index */ CUDA_MEMORY_API_cudaGraphicsResourceGetMappedPointer,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphicsResourceGetMappedPointer(devPtr, size, resource);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray_t * array, cudaGraphicsResource_t resource, unsigned int arrayIndex, unsigned int mipLevel){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsSubResourceGetMappedArray) (cudaArray_t *, cudaGraphicsResource_t, unsigned int, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaGraphicsResource_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaGraphicsSubResourceGetMappedArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphicsSubResourceGetMappedArray",
        /* api_index */ CUDA_MEMORY_API_cudaGraphicsSubResourceGetMappedArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphicsSubResourceGetMappedArray(array, resource, arrayIndex, mipLevel);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphicsResourceGetMappedMipmappedArray(cudaMipmappedArray_t * mipmappedArray, cudaGraphicsResource_t resource){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsResourceGetMappedMipmappedArray) (cudaMipmappedArray_t *, cudaGraphicsResource_t) = (cudaError_t (*)(cudaMipmappedArray_t *, cudaGraphicsResource_t))dlsym(RTLD_NEXT, "cudaGraphicsResourceGetMappedMipmappedArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphicsResourceGetMappedMipmappedArray",
        /* api_index */ CUDA_MEMORY_API_cudaGraphicsResourceGetMappedMipmappedArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphicsResourceGetMappedMipmappedArray(mipmappedArray, resource);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaBindTexture(size_t * offset, textureReference const * texref, void const * devPtr, cudaChannelFormatDesc const * desc, size_t size){
    cudaError_t lretval;
    cudaError_t (*lcudaBindTexture) (size_t *, textureReference const *, void const *, cudaChannelFormatDesc const *, size_t) = (cudaError_t (*)(size_t *, textureReference const *, void const *, cudaChannelFormatDesc const *, size_t))dlsym(RTLD_NEXT, "cudaBindTexture");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaBindTexture",
        /* api_index */ CUDA_MEMORY_API_cudaBindTexture,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaBindTexture(offset, texref, devPtr, desc, size);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaBindTexture2D(size_t * offset, textureReference const * texref, void const * devPtr, cudaChannelFormatDesc const * desc, size_t width, size_t height, size_t pitch){
    cudaError_t lretval;
    cudaError_t (*lcudaBindTexture2D) (size_t *, textureReference const *, void const *, cudaChannelFormatDesc const *, size_t, size_t, size_t) = (cudaError_t (*)(size_t *, textureReference const *, void const *, cudaChannelFormatDesc const *, size_t, size_t, size_t))dlsym(RTLD_NEXT, "cudaBindTexture2D");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaBindTexture2D",
        /* api_index */ CUDA_MEMORY_API_cudaBindTexture2D,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaBindTexture2D(offset, texref, devPtr, desc, width, height, pitch);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaBindTextureToArray(textureReference const * texref, cudaArray_const_t array, cudaChannelFormatDesc const * desc){
    cudaError_t lretval;
    cudaError_t (*lcudaBindTextureToArray) (textureReference const *, cudaArray_const_t, cudaChannelFormatDesc const *) = (cudaError_t (*)(textureReference const *, cudaArray_const_t, cudaChannelFormatDesc const *))dlsym(RTLD_NEXT, "cudaBindTextureToArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaBindTextureToArray",
        /* api_index */ CUDA_MEMORY_API_cudaBindTextureToArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaBindTextureToArray(texref, array, desc);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaBindTextureToMipmappedArray(textureReference const * texref, cudaMipmappedArray_const_t mipmappedArray, cudaChannelFormatDesc const * desc){
    cudaError_t lretval;
    cudaError_t (*lcudaBindTextureToMipmappedArray) (textureReference const *, cudaMipmappedArray_const_t, cudaChannelFormatDesc const *) = (cudaError_t (*)(textureReference const *, cudaMipmappedArray_const_t, cudaChannelFormatDesc const *))dlsym(RTLD_NEXT, "cudaBindTextureToMipmappedArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaBindTextureToMipmappedArray",
        /* api_index */ CUDA_MEMORY_API_cudaBindTextureToMipmappedArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaBindTextureToMipmappedArray(texref, mipmappedArray, desc);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaUnbindTexture(textureReference const * texref){
    cudaError_t lretval;
    cudaError_t (*lcudaUnbindTexture) (textureReference const *) = (cudaError_t (*)(textureReference const *))dlsym(RTLD_NEXT, "cudaUnbindTexture");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaUnbindTexture",
        /* api_index */ CUDA_MEMORY_API_cudaUnbindTexture,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaUnbindTexture(texref);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetTextureAlignmentOffset(size_t * offset, textureReference const * texref){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureAlignmentOffset) (size_t *, textureReference const *) = (cudaError_t (*)(size_t *, textureReference const *))dlsym(RTLD_NEXT, "cudaGetTextureAlignmentOffset");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetTextureAlignmentOffset",
        /* api_index */ CUDA_MEMORY_API_cudaGetTextureAlignmentOffset,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetTextureAlignmentOffset(offset, texref);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetTextureReference(textureReference const * * texref, void const * symbol){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureReference) (textureReference const * *, void const *) = (cudaError_t (*)(textureReference const * *, void const *))dlsym(RTLD_NEXT, "cudaGetTextureReference");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetTextureReference",
        /* api_index */ CUDA_MEMORY_API_cudaGetTextureReference,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetTextureReference(texref, symbol);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaBindSurfaceToArray(surfaceReference const * surfref, cudaArray_const_t array, cudaChannelFormatDesc const * desc){
    cudaError_t lretval;
    cudaError_t (*lcudaBindSurfaceToArray) (surfaceReference const *, cudaArray_const_t, cudaChannelFormatDesc const *) = (cudaError_t (*)(surfaceReference const *, cudaArray_const_t, cudaChannelFormatDesc const *))dlsym(RTLD_NEXT, "cudaBindSurfaceToArray");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaBindSurfaceToArray",
        /* api_index */ CUDA_MEMORY_API_cudaBindSurfaceToArray,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaBindSurfaceToArray(surfref, array, desc);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetSurfaceReference(surfaceReference const * * surfref, void const * symbol){
    cudaError_t lretval;
    cudaError_t (*lcudaGetSurfaceReference) (surfaceReference const * *, void const *) = (cudaError_t (*)(surfaceReference const * *, void const *))dlsym(RTLD_NEXT, "cudaGetSurfaceReference");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetSurfaceReference",
        /* api_index */ CUDA_MEMORY_API_cudaGetSurfaceReference,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetSurfaceReference(surfref, symbol);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc * desc, cudaArray_const_t array){
    cudaError_t lretval;
    cudaError_t (*lcudaGetChannelDesc) (cudaChannelFormatDesc *, cudaArray_const_t) = (cudaError_t (*)(cudaChannelFormatDesc *, cudaArray_const_t))dlsym(RTLD_NEXT, "cudaGetChannelDesc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetChannelDesc",
        /* api_index */ CUDA_MEMORY_API_cudaGetChannelDesc,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetChannelDesc(desc, array);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w, cudaChannelFormatKind f){
    cudaChannelFormatDesc lretval;
    cudaChannelFormatDesc (*lcudaCreateChannelDesc) (int, int, int, int, cudaChannelFormatKind) = (cudaChannelFormatDesc (*)(int, int, int, int, cudaChannelFormatKind))dlsym(RTLD_NEXT, "cudaCreateChannelDesc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaCreateChannelDesc",
        /* api_index */ CUDA_MEMORY_API_cudaCreateChannelDesc,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaCreateChannelDesc(x, y, z, w, f);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaCreateTextureObject(cudaTextureObject_t * pTexObject, cudaResourceDesc const * pResDesc, cudaTextureDesc const * pTexDesc, cudaResourceViewDesc const * pResViewDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaCreateTextureObject) (cudaTextureObject_t *, cudaResourceDesc const *, cudaTextureDesc const *, cudaResourceViewDesc const *) = (cudaError_t (*)(cudaTextureObject_t *, cudaResourceDesc const *, cudaTextureDesc const *, cudaResourceViewDesc const *))dlsym(RTLD_NEXT, "cudaCreateTextureObject");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaCreateTextureObject",
        /* api_index */ CUDA_MEMORY_API_cudaCreateTextureObject,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaCreateTextureObject(pTexObject, pResDesc, pTexDesc, pResViewDesc);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDestroyTextureObject(cudaTextureObject_t texObject){
    cudaError_t lretval;
    cudaError_t (*lcudaDestroyTextureObject) (cudaTextureObject_t) = (cudaError_t (*)(cudaTextureObject_t))dlsym(RTLD_NEXT, "cudaDestroyTextureObject");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDestroyTextureObject",
        /* api_index */ CUDA_MEMORY_API_cudaDestroyTextureObject,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDestroyTextureObject(texObject);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetTextureObjectResourceDesc(cudaResourceDesc * pResDesc, cudaTextureObject_t texObject){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureObjectResourceDesc) (cudaResourceDesc *, cudaTextureObject_t) = (cudaError_t (*)(cudaResourceDesc *, cudaTextureObject_t))dlsym(RTLD_NEXT, "cudaGetTextureObjectResourceDesc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetTextureObjectResourceDesc",
        /* api_index */ CUDA_MEMORY_API_cudaGetTextureObjectResourceDesc,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetTextureObjectResourceDesc(pResDesc, texObject);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetTextureObjectTextureDesc(cudaTextureDesc * pTexDesc, cudaTextureObject_t texObject){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureObjectTextureDesc) (cudaTextureDesc *, cudaTextureObject_t) = (cudaError_t (*)(cudaTextureDesc *, cudaTextureObject_t))dlsym(RTLD_NEXT, "cudaGetTextureObjectTextureDesc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetTextureObjectTextureDesc",
        /* api_index */ CUDA_MEMORY_API_cudaGetTextureObjectTextureDesc,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetTextureObjectTextureDesc(pTexDesc, texObject);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetTextureObjectResourceViewDesc(cudaResourceViewDesc * pResViewDesc, cudaTextureObject_t texObject){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureObjectResourceViewDesc) (cudaResourceViewDesc *, cudaTextureObject_t) = (cudaError_t (*)(cudaResourceViewDesc *, cudaTextureObject_t))dlsym(RTLD_NEXT, "cudaGetTextureObjectResourceViewDesc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetTextureObjectResourceViewDesc",
        /* api_index */ CUDA_MEMORY_API_cudaGetTextureObjectResourceViewDesc,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetTextureObjectResourceViewDesc(pResViewDesc, texObject);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaCreateSurfaceObject(cudaSurfaceObject_t * pSurfObject, cudaResourceDesc const * pResDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaCreateSurfaceObject) (cudaSurfaceObject_t *, cudaResourceDesc const *) = (cudaError_t (*)(cudaSurfaceObject_t *, cudaResourceDesc const *))dlsym(RTLD_NEXT, "cudaCreateSurfaceObject");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaCreateSurfaceObject",
        /* api_index */ CUDA_MEMORY_API_cudaCreateSurfaceObject,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaCreateSurfaceObject(pSurfObject, pResDesc);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDestroySurfaceObject(cudaSurfaceObject_t surfObject){
    cudaError_t lretval;
    cudaError_t (*lcudaDestroySurfaceObject) (cudaSurfaceObject_t) = (cudaError_t (*)(cudaSurfaceObject_t))dlsym(RTLD_NEXT, "cudaDestroySurfaceObject");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDestroySurfaceObject",
        /* api_index */ CUDA_MEMORY_API_cudaDestroySurfaceObject,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDestroySurfaceObject(surfObject);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetSurfaceObjectResourceDesc(cudaResourceDesc * pResDesc, cudaSurfaceObject_t surfObject){
    cudaError_t lretval;
    cudaError_t (*lcudaGetSurfaceObjectResourceDesc) (cudaResourceDesc *, cudaSurfaceObject_t) = (cudaError_t (*)(cudaResourceDesc *, cudaSurfaceObject_t))dlsym(RTLD_NEXT, "cudaGetSurfaceObjectResourceDesc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetSurfaceObjectResourceDesc",
        /* api_index */ CUDA_MEMORY_API_cudaGetSurfaceObjectResourceDesc,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetSurfaceObjectResourceDesc(pResDesc, surfObject);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDriverGetVersion(int * driverVersion){
    cudaError_t lretval;
    cudaError_t (*lcudaDriverGetVersion) (int *) = (cudaError_t (*)(int *))dlsym(RTLD_NEXT, "cudaDriverGetVersion");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDriverGetVersion",
        /* api_index */ CUDA_MEMORY_API_cudaDriverGetVersion,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDriverGetVersion(driverVersion);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaRuntimeGetVersion(int * runtimeVersion){
    cudaError_t lretval;
    cudaError_t (*lcudaRuntimeGetVersion) (int *) = (cudaError_t (*)(int *))dlsym(RTLD_NEXT, "cudaRuntimeGetVersion");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaRuntimeGetVersion",
        /* api_index */ CUDA_MEMORY_API_cudaRuntimeGetVersion,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaRuntimeGetVersion(runtimeVersion);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphCreate(cudaGraph_t * pGraph, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphCreate) (cudaGraph_t *, unsigned int) = (cudaError_t (*)(cudaGraph_t *, unsigned int))dlsym(RTLD_NEXT, "cudaGraphCreate");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphCreate",
        /* api_index */ CUDA_MEMORY_API_cudaGraphCreate,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphCreate(pGraph, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddKernelNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaKernelNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddKernelNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaKernelNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaKernelNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphAddKernelNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddKernelNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddKernelNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddKernelNode(pGraphNode, graph, pDependencies, numDependencies, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphKernelNodeGetParams(cudaGraphNode_t node, cudaKernelNodeParams * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeGetParams) (cudaGraphNode_t, cudaKernelNodeParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaKernelNodeParams *))dlsym(RTLD_NEXT, "cudaGraphKernelNodeGetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphKernelNodeGetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphKernelNodeGetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphKernelNodeGetParams(node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphKernelNodeSetParams(cudaGraphNode_t node, cudaKernelNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeSetParams) (cudaGraphNode_t, cudaKernelNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaKernelNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphKernelNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphKernelNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphKernelNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphKernelNodeSetParams(node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphKernelNodeCopyAttributes(cudaGraphNode_t hSrc, cudaGraphNode_t hDst){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeCopyAttributes) (cudaGraphNode_t, cudaGraphNode_t) = (cudaError_t (*)(cudaGraphNode_t, cudaGraphNode_t))dlsym(RTLD_NEXT, "cudaGraphKernelNodeCopyAttributes");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphKernelNodeCopyAttributes",
        /* api_index */ CUDA_MEMORY_API_cudaGraphKernelNodeCopyAttributes,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphKernelNodeCopyAttributes(hSrc, hDst);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphKernelNodeGetAttribute(cudaGraphNode_t hNode, cudaKernelNodeAttrID attr, cudaKernelNodeAttrValue * value_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeGetAttribute) (cudaGraphNode_t, cudaKernelNodeAttrID, cudaKernelNodeAttrValue *) = (cudaError_t (*)(cudaGraphNode_t, cudaKernelNodeAttrID, cudaKernelNodeAttrValue *))dlsym(RTLD_NEXT, "cudaGraphKernelNodeGetAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphKernelNodeGetAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaGraphKernelNodeGetAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphKernelNodeGetAttribute(hNode, attr, value_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphKernelNodeSetAttribute(cudaGraphNode_t hNode, cudaKernelNodeAttrID attr, cudaKernelNodeAttrValue const * value){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeSetAttribute) (cudaGraphNode_t, cudaKernelNodeAttrID, cudaKernelNodeAttrValue const *) = (cudaError_t (*)(cudaGraphNode_t, cudaKernelNodeAttrID, cudaKernelNodeAttrValue const *))dlsym(RTLD_NEXT, "cudaGraphKernelNodeSetAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphKernelNodeSetAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaGraphKernelNodeSetAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphKernelNodeSetAttribute(hNode, attr, value);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddMemcpyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaMemcpy3DParms const * pCopyParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemcpyNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemcpy3DParms const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemcpy3DParms const *))dlsym(RTLD_NEXT, "cudaGraphAddMemcpyNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddMemcpyNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddMemcpyNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddMemcpyNode(pGraphNode, graph, pDependencies, numDependencies, pCopyParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddMemcpyNodeToSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemcpyNodeToSymbol) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void const *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void const *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphAddMemcpyNodeToSymbol");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddMemcpyNodeToSymbol",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddMemcpyNodeToSymbol,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddMemcpyNodeToSymbol(pGraphNode, graph, pDependencies, numDependencies, symbol, src, count, offset, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddMemcpyNodeFromSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemcpyNodeFromSymbol) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphAddMemcpyNodeFromSymbol");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddMemcpyNodeFromSymbol",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddMemcpyNodeFromSymbol,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddMemcpyNodeFromSymbol(pGraphNode, graph, pDependencies, numDependencies, dst, symbol, count, offset, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddMemcpyNode1D(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, void * dst, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemcpyNode1D) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphAddMemcpyNode1D");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddMemcpyNode1D",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddMemcpyNode1D,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddMemcpyNode1D(pGraphNode, graph, pDependencies, numDependencies, dst, src, count, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeGetParams(cudaGraphNode_t node, cudaMemcpy3DParms * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeGetParams) (cudaGraphNode_t, cudaMemcpy3DParms *) = (cudaError_t (*)(cudaGraphNode_t, cudaMemcpy3DParms *))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeGetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphMemcpyNodeGetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphMemcpyNodeGetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphMemcpyNodeGetParams(node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeSetParams(cudaGraphNode_t node, cudaMemcpy3DParms const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeSetParams) (cudaGraphNode_t, cudaMemcpy3DParms const *) = (cudaError_t (*)(cudaGraphNode_t, cudaMemcpy3DParms const *))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphMemcpyNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphMemcpyNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphMemcpyNodeSetParams(node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeSetParamsToSymbol(cudaGraphNode_t node, void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeSetParamsToSymbol) (cudaGraphNode_t, void const *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t, void const *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeSetParamsToSymbol");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphMemcpyNodeSetParamsToSymbol",
        /* api_index */ CUDA_MEMORY_API_cudaGraphMemcpyNodeSetParamsToSymbol,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphMemcpyNodeSetParamsToSymbol(node, symbol, src, count, offset, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeSetParamsFromSymbol(cudaGraphNode_t node, void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeSetParamsFromSymbol) (cudaGraphNode_t, void *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t, void *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeSetParamsFromSymbol");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphMemcpyNodeSetParamsFromSymbol",
        /* api_index */ CUDA_MEMORY_API_cudaGraphMemcpyNodeSetParamsFromSymbol,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphMemcpyNodeSetParamsFromSymbol(node, dst, symbol, count, offset, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeSetParams1D(cudaGraphNode_t node, void * dst, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeSetParams1D) (cudaGraphNode_t, void *, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t, void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeSetParams1D");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphMemcpyNodeSetParams1D",
        /* api_index */ CUDA_MEMORY_API_cudaGraphMemcpyNodeSetParams1D,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphMemcpyNodeSetParams1D(node, dst, src, count, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddMemsetNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaMemsetParams const * pMemsetParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemsetNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemsetParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemsetParams const *))dlsym(RTLD_NEXT, "cudaGraphAddMemsetNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddMemsetNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddMemsetNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddMemsetNode(pGraphNode, graph, pDependencies, numDependencies, pMemsetParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphMemsetNodeGetParams(cudaGraphNode_t node, cudaMemsetParams * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemsetNodeGetParams) (cudaGraphNode_t, cudaMemsetParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaMemsetParams *))dlsym(RTLD_NEXT, "cudaGraphMemsetNodeGetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphMemsetNodeGetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphMemsetNodeGetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphMemsetNodeGetParams(node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphMemsetNodeSetParams(cudaGraphNode_t node, cudaMemsetParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemsetNodeSetParams) (cudaGraphNode_t, cudaMemsetParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaMemsetParams const *))dlsym(RTLD_NEXT, "cudaGraphMemsetNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphMemsetNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphMemsetNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphMemsetNodeSetParams(node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddHostNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaHostNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddHostNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaHostNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaHostNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphAddHostNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddHostNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddHostNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddHostNode(pGraphNode, graph, pDependencies, numDependencies, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphHostNodeGetParams(cudaGraphNode_t node, cudaHostNodeParams * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphHostNodeGetParams) (cudaGraphNode_t, cudaHostNodeParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaHostNodeParams *))dlsym(RTLD_NEXT, "cudaGraphHostNodeGetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphHostNodeGetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphHostNodeGetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphHostNodeGetParams(node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphHostNodeSetParams(cudaGraphNode_t node, cudaHostNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphHostNodeSetParams) (cudaGraphNode_t, cudaHostNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaHostNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphHostNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphHostNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphHostNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphHostNodeSetParams(node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddChildGraphNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaGraph_t childGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddChildGraphNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaGraph_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphAddChildGraphNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddChildGraphNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddChildGraphNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddChildGraphNode(pGraphNode, graph, pDependencies, numDependencies, childGraph);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphChildGraphNodeGetGraph(cudaGraphNode_t node, cudaGraph_t * pGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphChildGraphNodeGetGraph) (cudaGraphNode_t, cudaGraph_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaGraph_t *))dlsym(RTLD_NEXT, "cudaGraphChildGraphNodeGetGraph");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphChildGraphNodeGetGraph",
        /* api_index */ CUDA_MEMORY_API_cudaGraphChildGraphNodeGetGraph,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphChildGraphNodeGetGraph(node, pGraph);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddEmptyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddEmptyNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t))dlsym(RTLD_NEXT, "cudaGraphAddEmptyNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddEmptyNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddEmptyNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddEmptyNode(pGraphNode, graph, pDependencies, numDependencies);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddEventRecordNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddEventRecordNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphAddEventRecordNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddEventRecordNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddEventRecordNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddEventRecordNode(pGraphNode, graph, pDependencies, numDependencies, event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphEventRecordNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphEventRecordNodeGetEvent) (cudaGraphNode_t, cudaEvent_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaEvent_t *))dlsym(RTLD_NEXT, "cudaGraphEventRecordNodeGetEvent");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphEventRecordNodeGetEvent",
        /* api_index */ CUDA_MEMORY_API_cudaGraphEventRecordNodeGetEvent,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphEventRecordNodeGetEvent(node, event_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphEventRecordNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphEventRecordNodeSetEvent) (cudaGraphNode_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphNode_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphEventRecordNodeSetEvent");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphEventRecordNodeSetEvent",
        /* api_index */ CUDA_MEMORY_API_cudaGraphEventRecordNodeSetEvent,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphEventRecordNodeSetEvent(node, event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddEventWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddEventWaitNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphAddEventWaitNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddEventWaitNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddEventWaitNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddEventWaitNode(pGraphNode, graph, pDependencies, numDependencies, event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphEventWaitNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphEventWaitNodeGetEvent) (cudaGraphNode_t, cudaEvent_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaEvent_t *))dlsym(RTLD_NEXT, "cudaGraphEventWaitNodeGetEvent");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphEventWaitNodeGetEvent",
        /* api_index */ CUDA_MEMORY_API_cudaGraphEventWaitNodeGetEvent,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphEventWaitNodeGetEvent(node, event_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphEventWaitNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphEventWaitNodeSetEvent) (cudaGraphNode_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphNode_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphEventWaitNodeSetEvent");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphEventWaitNodeSetEvent",
        /* api_index */ CUDA_MEMORY_API_cudaGraphEventWaitNodeSetEvent,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphEventWaitNodeSetEvent(node, event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddExternalSemaphoresSignalNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaExternalSemaphoreSignalNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddExternalSemaphoresSignalNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaExternalSemaphoreSignalNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaExternalSemaphoreSignalNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphAddExternalSemaphoresSignalNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddExternalSemaphoresSignalNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddExternalSemaphoresSignalNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddExternalSemaphoresSignalNode(pGraphNode, graph, pDependencies, numDependencies, nodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExternalSemaphoresSignalNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreSignalNodeParams * params_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExternalSemaphoresSignalNodeGetParams) (cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams *))dlsym(RTLD_NEXT, "cudaGraphExternalSemaphoresSignalNodeGetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExternalSemaphoresSignalNodeGetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExternalSemaphoresSignalNodeGetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExternalSemaphoresSignalNodeGetParams(hNode, params_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExternalSemaphoresSignalNodeSetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreSignalNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExternalSemaphoresSignalNodeSetParams) (cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExternalSemaphoresSignalNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExternalSemaphoresSignalNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExternalSemaphoresSignalNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExternalSemaphoresSignalNodeSetParams(hNode, nodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddExternalSemaphoresWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaExternalSemaphoreWaitNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddExternalSemaphoresWaitNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaExternalSemaphoreWaitNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaExternalSemaphoreWaitNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphAddExternalSemaphoresWaitNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddExternalSemaphoresWaitNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddExternalSemaphoresWaitNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddExternalSemaphoresWaitNode(pGraphNode, graph, pDependencies, numDependencies, nodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExternalSemaphoresWaitNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreWaitNodeParams * params_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExternalSemaphoresWaitNodeGetParams) (cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams *))dlsym(RTLD_NEXT, "cudaGraphExternalSemaphoresWaitNodeGetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExternalSemaphoresWaitNodeGetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExternalSemaphoresWaitNodeGetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExternalSemaphoresWaitNodeGetParams(hNode, params_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExternalSemaphoresWaitNodeSetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreWaitNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExternalSemaphoresWaitNodeSetParams) (cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExternalSemaphoresWaitNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExternalSemaphoresWaitNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExternalSemaphoresWaitNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExternalSemaphoresWaitNodeSetParams(hNode, nodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddMemAllocNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaMemAllocNodeParams * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemAllocNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemAllocNodeParams *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemAllocNodeParams *))dlsym(RTLD_NEXT, "cudaGraphAddMemAllocNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddMemAllocNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddMemAllocNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddMemAllocNode(pGraphNode, graph, pDependencies, numDependencies, nodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphMemAllocNodeGetParams(cudaGraphNode_t node, cudaMemAllocNodeParams * params_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemAllocNodeGetParams) (cudaGraphNode_t, cudaMemAllocNodeParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaMemAllocNodeParams *))dlsym(RTLD_NEXT, "cudaGraphMemAllocNodeGetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphMemAllocNodeGetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphMemAllocNodeGetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphMemAllocNodeGetParams(node, params_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddMemFreeNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, void * dptr){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemFreeNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *))dlsym(RTLD_NEXT, "cudaGraphAddMemFreeNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddMemFreeNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddMemFreeNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddMemFreeNode(pGraphNode, graph, pDependencies, numDependencies, dptr);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphMemFreeNodeGetParams(cudaGraphNode_t node, void * dptr_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemFreeNodeGetParams) (cudaGraphNode_t, void *) = (cudaError_t (*)(cudaGraphNode_t, void *))dlsym(RTLD_NEXT, "cudaGraphMemFreeNodeGetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphMemFreeNodeGetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphMemFreeNodeGetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphMemFreeNodeGetParams(node, dptr_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGraphMemTrim(int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGraphMemTrim) (int) = (cudaError_t (*)(int))dlsym(RTLD_NEXT, "cudaDeviceGraphMemTrim");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGraphMemTrim",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGraphMemTrim,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGraphMemTrim(device);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceGetGraphMemAttribute(int device, cudaGraphMemAttributeType attr, void * value){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetGraphMemAttribute) (int, cudaGraphMemAttributeType, void *) = (cudaError_t (*)(int, cudaGraphMemAttributeType, void *))dlsym(RTLD_NEXT, "cudaDeviceGetGraphMemAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceGetGraphMemAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceGetGraphMemAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceGetGraphMemAttribute(device, attr, value);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaDeviceSetGraphMemAttribute(int device, cudaGraphMemAttributeType attr, void * value){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSetGraphMemAttribute) (int, cudaGraphMemAttributeType, void *) = (cudaError_t (*)(int, cudaGraphMemAttributeType, void *))dlsym(RTLD_NEXT, "cudaDeviceSetGraphMemAttribute");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaDeviceSetGraphMemAttribute",
        /* api_index */ CUDA_MEMORY_API_cudaDeviceSetGraphMemAttribute,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaDeviceSetGraphMemAttribute(device, attr, value);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphClone(cudaGraph_t * pGraphClone, cudaGraph_t originalGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphClone) (cudaGraph_t *, cudaGraph_t) = (cudaError_t (*)(cudaGraph_t *, cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphClone");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphClone",
        /* api_index */ CUDA_MEMORY_API_cudaGraphClone,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphClone(pGraphClone, originalGraph);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphNodeFindInClone(cudaGraphNode_t * pNode, cudaGraphNode_t originalNode, cudaGraph_t clonedGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphNodeFindInClone) (cudaGraphNode_t *, cudaGraphNode_t, cudaGraph_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraphNode_t, cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphNodeFindInClone");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphNodeFindInClone",
        /* api_index */ CUDA_MEMORY_API_cudaGraphNodeFindInClone,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphNodeFindInClone(pNode, originalNode, clonedGraph);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphNodeGetType(cudaGraphNode_t node, cudaGraphNodeType * pType){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphNodeGetType) (cudaGraphNode_t, cudaGraphNodeType *) = (cudaError_t (*)(cudaGraphNode_t, cudaGraphNodeType *))dlsym(RTLD_NEXT, "cudaGraphNodeGetType");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphNodeGetType",
        /* api_index */ CUDA_MEMORY_API_cudaGraphNodeGetType,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphNodeGetType(node, pType);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphGetNodes(cudaGraph_t graph, cudaGraphNode_t * nodes, size_t * numNodes){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphGetNodes) (cudaGraph_t, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphGetNodes");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphGetNodes",
        /* api_index */ CUDA_MEMORY_API_cudaGraphGetNodes,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphGetNodes(graph, nodes, numNodes);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphGetRootNodes(cudaGraph_t graph, cudaGraphNode_t * pRootNodes, size_t * pNumRootNodes){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphGetRootNodes) (cudaGraph_t, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphGetRootNodes");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphGetRootNodes",
        /* api_index */ CUDA_MEMORY_API_cudaGraphGetRootNodes,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphGetRootNodes(graph, pRootNodes, pNumRootNodes);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphGetEdges(cudaGraph_t graph, cudaGraphNode_t * from, cudaGraphNode_t * to, size_t * numEdges){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphGetEdges) (cudaGraph_t, cudaGraphNode_t *, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t *, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphGetEdges");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphGetEdges",
        /* api_index */ CUDA_MEMORY_API_cudaGraphGetEdges,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphGetEdges(graph, from, to, numEdges);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphNodeGetDependencies(cudaGraphNode_t node, cudaGraphNode_t * pDependencies, size_t * pNumDependencies){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphNodeGetDependencies) (cudaGraphNode_t, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphNodeGetDependencies");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphNodeGetDependencies",
        /* api_index */ CUDA_MEMORY_API_cudaGraphNodeGetDependencies,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphNodeGetDependencies(node, pDependencies, pNumDependencies);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphNodeGetDependentNodes(cudaGraphNode_t node, cudaGraphNode_t * pDependentNodes, size_t * pNumDependentNodes){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphNodeGetDependentNodes) (cudaGraphNode_t, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphNodeGetDependentNodes");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphNodeGetDependentNodes",
        /* api_index */ CUDA_MEMORY_API_cudaGraphNodeGetDependentNodes,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphNodeGetDependentNodes(node, pDependentNodes, pNumDependentNodes);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphAddDependencies(cudaGraph_t graph, cudaGraphNode_t const * from, cudaGraphNode_t const * to, size_t numDependencies){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddDependencies) (cudaGraph_t, cudaGraphNode_t const *, cudaGraphNode_t const *, size_t) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t const *, cudaGraphNode_t const *, size_t))dlsym(RTLD_NEXT, "cudaGraphAddDependencies");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphAddDependencies",
        /* api_index */ CUDA_MEMORY_API_cudaGraphAddDependencies,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphAddDependencies(graph, from, to, numDependencies);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphRemoveDependencies(cudaGraph_t graph, cudaGraphNode_t const * from, cudaGraphNode_t const * to, size_t numDependencies){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphRemoveDependencies) (cudaGraph_t, cudaGraphNode_t const *, cudaGraphNode_t const *, size_t) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t const *, cudaGraphNode_t const *, size_t))dlsym(RTLD_NEXT, "cudaGraphRemoveDependencies");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphRemoveDependencies",
        /* api_index */ CUDA_MEMORY_API_cudaGraphRemoveDependencies,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphRemoveDependencies(graph, from, to, numDependencies);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphDestroyNode(cudaGraphNode_t node){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphDestroyNode) (cudaGraphNode_t) = (cudaError_t (*)(cudaGraphNode_t))dlsym(RTLD_NEXT, "cudaGraphDestroyNode");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphDestroyNode",
        /* api_index */ CUDA_MEMORY_API_cudaGraphDestroyNode,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphDestroyNode(node);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphInstantiate(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, cudaGraphNode_t * pErrorNode, char * pLogBuffer, size_t bufferSize){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphInstantiate) (cudaGraphExec_t *, cudaGraph_t, cudaGraphNode_t *, char *, size_t) = (cudaError_t (*)(cudaGraphExec_t *, cudaGraph_t, cudaGraphNode_t *, char *, size_t))dlsym(RTLD_NEXT, "cudaGraphInstantiate");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphInstantiate",
        /* api_index */ CUDA_MEMORY_API_cudaGraphInstantiate,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphInstantiate(pGraphExec, graph, pErrorNode, pLogBuffer, bufferSize);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphInstantiateWithFlags(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, long long unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphInstantiateWithFlags) (cudaGraphExec_t *, cudaGraph_t, long long unsigned int) = (cudaError_t (*)(cudaGraphExec_t *, cudaGraph_t, long long unsigned int))dlsym(RTLD_NEXT, "cudaGraphInstantiateWithFlags");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphInstantiateWithFlags",
        /* api_index */ CUDA_MEMORY_API_cudaGraphInstantiateWithFlags,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphInstantiateWithFlags(pGraphExec, graph, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecKernelNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaKernelNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecKernelNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaKernelNodeParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaKernelNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExecKernelNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecKernelNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecKernelNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecKernelNodeSetParams(hGraphExec, node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecMemcpyNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaMemcpy3DParms const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemcpyNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaMemcpy3DParms const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaMemcpy3DParms const *))dlsym(RTLD_NEXT, "cudaGraphExecMemcpyNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecMemcpyNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecMemcpyNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecMemcpyNodeSetParams(hGraphExec, node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecMemcpyNodeSetParamsToSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemcpyNodeSetParamsToSymbol) (cudaGraphExec_t, cudaGraphNode_t, void const *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, void const *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphExecMemcpyNodeSetParamsToSymbol");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecMemcpyNodeSetParamsToSymbol",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecMemcpyNodeSetParamsToSymbol,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecMemcpyNodeSetParamsToSymbol(hGraphExec, node, symbol, src, count, offset, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecMemcpyNodeSetParamsFromSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemcpyNodeSetParamsFromSymbol) (cudaGraphExec_t, cudaGraphNode_t, void *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, void *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphExecMemcpyNodeSetParamsFromSymbol");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecMemcpyNodeSetParamsFromSymbol",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecMemcpyNodeSetParamsFromSymbol,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecMemcpyNodeSetParamsFromSymbol(hGraphExec, node, dst, symbol, count, offset, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecMemcpyNodeSetParams1D(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemcpyNodeSetParams1D) (cudaGraphExec_t, cudaGraphNode_t, void *, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphExecMemcpyNodeSetParams1D");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecMemcpyNodeSetParams1D",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecMemcpyNodeSetParams1D,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecMemcpyNodeSetParams1D(hGraphExec, node, dst, src, count, kind);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecMemsetNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaMemsetParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemsetNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaMemsetParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaMemsetParams const *))dlsym(RTLD_NEXT, "cudaGraphExecMemsetNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecMemsetNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecMemsetNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecMemsetNodeSetParams(hGraphExec, node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecHostNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaHostNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecHostNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaHostNodeParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaHostNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExecHostNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecHostNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecHostNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecHostNodeSetParams(hGraphExec, node, pNodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecChildGraphNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaGraph_t childGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecChildGraphNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaGraph_t) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphExecChildGraphNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecChildGraphNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecChildGraphNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecChildGraphNodeSetParams(hGraphExec, node, childGraph);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecEventRecordNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecEventRecordNodeSetEvent) (cudaGraphExec_t, cudaGraphNode_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphExecEventRecordNodeSetEvent");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecEventRecordNodeSetEvent",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecEventRecordNodeSetEvent,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecEventRecordNodeSetEvent(hGraphExec, hNode, event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecEventWaitNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecEventWaitNodeSetEvent) (cudaGraphExec_t, cudaGraphNode_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphExecEventWaitNodeSetEvent");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecEventWaitNodeSetEvent",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecEventWaitNodeSetEvent,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecEventWaitNodeSetEvent(hGraphExec, hNode, event);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecExternalSemaphoresSignalNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaExternalSemaphoreSignalNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecExternalSemaphoresSignalNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExecExternalSemaphoresSignalNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecExternalSemaphoresSignalNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecExternalSemaphoresSignalNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecExternalSemaphoresSignalNodeSetParams(hGraphExec, hNode, nodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecExternalSemaphoresWaitNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaExternalSemaphoreWaitNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecExternalSemaphoresWaitNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExecExternalSemaphoresWaitNodeSetParams");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecExternalSemaphoresWaitNodeSetParams",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecExternalSemaphoresWaitNodeSetParams,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecExternalSemaphoresWaitNodeSetParams(hGraphExec, hNode, nodeParams);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecUpdate(cudaGraphExec_t hGraphExec, cudaGraph_t hGraph, cudaGraphNode_t * hErrorNode_out, cudaGraphExecUpdateResult * updateResult_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecUpdate) (cudaGraphExec_t, cudaGraph_t, cudaGraphNode_t *, cudaGraphExecUpdateResult *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraph_t, cudaGraphNode_t *, cudaGraphExecUpdateResult *))dlsym(RTLD_NEXT, "cudaGraphExecUpdate");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecUpdate",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecUpdate,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecUpdate(hGraphExec, hGraph, hErrorNode_out, updateResult_out);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphUpload(cudaGraphExec_t graphExec, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphUpload) (cudaGraphExec_t, cudaStream_t) = (cudaError_t (*)(cudaGraphExec_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaGraphUpload");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphUpload",
        /* api_index */ CUDA_MEMORY_API_cudaGraphUpload,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphUpload(graphExec, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphLaunch(cudaGraphExec_t graphExec, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphLaunch) (cudaGraphExec_t, cudaStream_t) = (cudaError_t (*)(cudaGraphExec_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaGraphLaunch");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphLaunch",
        /* api_index */ CUDA_MEMORY_API_cudaGraphLaunch,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphLaunch(graphExec, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphExecDestroy(cudaGraphExec_t graphExec){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecDestroy) (cudaGraphExec_t) = (cudaError_t (*)(cudaGraphExec_t))dlsym(RTLD_NEXT, "cudaGraphExecDestroy");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphExecDestroy",
        /* api_index */ CUDA_MEMORY_API_cudaGraphExecDestroy,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphExecDestroy(graphExec);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphDestroy(cudaGraph_t graph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphDestroy) (cudaGraph_t) = (cudaError_t (*)(cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphDestroy");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphDestroy",
        /* api_index */ CUDA_MEMORY_API_cudaGraphDestroy,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphDestroy(graph);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphDebugDotPrint(cudaGraph_t graph, char const * path, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphDebugDotPrint) (cudaGraph_t, char const *, unsigned int) = (cudaError_t (*)(cudaGraph_t, char const *, unsigned int))dlsym(RTLD_NEXT, "cudaGraphDebugDotPrint");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphDebugDotPrint",
        /* api_index */ CUDA_MEMORY_API_cudaGraphDebugDotPrint,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphDebugDotPrint(graph, path, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaUserObjectCreate(cudaUserObject_t * object_out, void * ptr, cudaHostFn_t destroy, unsigned int initialRefcount, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaUserObjectCreate) (cudaUserObject_t *, void *, cudaHostFn_t, unsigned int, unsigned int) = (cudaError_t (*)(cudaUserObject_t *, void *, cudaHostFn_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaUserObjectCreate");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaUserObjectCreate",
        /* api_index */ CUDA_MEMORY_API_cudaUserObjectCreate,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaUserObjectCreate(object_out, ptr, destroy, initialRefcount, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaUserObjectRetain(cudaUserObject_t object, unsigned int count){
    cudaError_t lretval;
    cudaError_t (*lcudaUserObjectRetain) (cudaUserObject_t, unsigned int) = (cudaError_t (*)(cudaUserObject_t, unsigned int))dlsym(RTLD_NEXT, "cudaUserObjectRetain");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaUserObjectRetain",
        /* api_index */ CUDA_MEMORY_API_cudaUserObjectRetain,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaUserObjectRetain(object, count);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaUserObjectRelease(cudaUserObject_t object, unsigned int count){
    cudaError_t lretval;
    cudaError_t (*lcudaUserObjectRelease) (cudaUserObject_t, unsigned int) = (cudaError_t (*)(cudaUserObject_t, unsigned int))dlsym(RTLD_NEXT, "cudaUserObjectRelease");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaUserObjectRelease",
        /* api_index */ CUDA_MEMORY_API_cudaUserObjectRelease,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaUserObjectRelease(object, count);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphRetainUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned int count, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphRetainUserObject) (cudaGraph_t, cudaUserObject_t, unsigned int, unsigned int) = (cudaError_t (*)(cudaGraph_t, cudaUserObject_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaGraphRetainUserObject");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphRetainUserObject",
        /* api_index */ CUDA_MEMORY_API_cudaGraphRetainUserObject,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphRetainUserObject(graph, object, count, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGraphReleaseUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned int count){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphReleaseUserObject) (cudaGraph_t, cudaUserObject_t, unsigned int) = (cudaError_t (*)(cudaGraph_t, cudaUserObject_t, unsigned int))dlsym(RTLD_NEXT, "cudaGraphReleaseUserObject");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGraphReleaseUserObject",
        /* api_index */ CUDA_MEMORY_API_cudaGraphReleaseUserObject,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGraphReleaseUserObject(graph, object, count);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetDriverEntryPoint(char const * symbol, void * * funcPtr, long long unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDriverEntryPoint) (char const *, void * *, long long unsigned int) = (cudaError_t (*)(char const *, void * *, long long unsigned int))dlsym(RTLD_NEXT, "cudaGetDriverEntryPoint");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetDriverEntryPoint",
        /* api_index */ CUDA_MEMORY_API_cudaGetDriverEntryPoint,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetDriverEntryPoint(symbol, funcPtr, flags);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetExportTable(void const * * ppExportTable, cudaUUID_t const * pExportTableId){
    cudaError_t lretval;
    cudaError_t (*lcudaGetExportTable) (void const * *, cudaUUID_t const *) = (cudaError_t (*)(void const * *, cudaUUID_t const *))dlsym(RTLD_NEXT, "cudaGetExportTable");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetExportTable",
        /* api_index */ CUDA_MEMORY_API_cudaGetExportTable,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetExportTable(ppExportTable, pExportTableId);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaGetFuncBySymbol(cudaFunction_t * functionPtr, void const * symbolPtr){
    cudaError_t lretval;
    cudaError_t (*lcudaGetFuncBySymbol) (cudaFunction_t *, void const *) = (cudaError_t (*)(cudaFunction_t *, void const *))dlsym(RTLD_NEXT, "cudaGetFuncBySymbol");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaGetFuncBySymbol",
        /* api_index */ CUDA_MEMORY_API_cudaGetFuncBySymbol,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaGetFuncBySymbol(functionPtr, symbolPtr);
    
    /* NOTE: post-interception */

    return lretval;
}


void * __builtin_memcpy(void * arg0, void const * arg1, long unsigned int arg2){
    void * lretval;
    void * (*l__builtin_memcpy) (void *, void const *, long unsigned int) = (void * (*)(void *, void const *, long unsigned int))dlsym(RTLD_NEXT, "__builtin_memcpy");

    START_MEMORY_PROFILING(
        /* api_name */ "__builtin_memcpy",
        /* api_index */ CUDA_MEMORY_API___builtin_memcpy,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = l__builtin_memcpy(arg0, arg1, arg2);
    
    /* NOTE: post-interception */

    return lretval;
}

