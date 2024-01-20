
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cuda_runtime.h>

#include "cudam.h"
#include "api_counter.h"


cudaError_t cudaDeviceReset(){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceReset) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaDeviceReset");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceReset", kApiTypeRuntime);

    lretval = lcudaDeviceReset();
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceSynchronize(){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSynchronize) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaDeviceSynchronize");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceSynchronize", kApiTypeRuntime);

    lretval = lcudaDeviceSynchronize();
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceSetLimit(cudaLimit limit, size_t value){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSetLimit) (cudaLimit, size_t) = (cudaError_t (*)(cudaLimit, size_t))dlsym(RTLD_NEXT, "cudaDeviceSetLimit");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceSetLimit", kApiTypeRuntime);

    lretval = lcudaDeviceSetLimit(limit, value);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetLimit(size_t * pValue, cudaLimit limit){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetLimit) (size_t *, cudaLimit) = (cudaError_t (*)(size_t *, cudaLimit))dlsym(RTLD_NEXT, "cudaDeviceGetLimit");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetLimit", kApiTypeRuntime);

    lretval = lcudaDeviceGetLimit(pValue, limit);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetTexture1DLinearMaxWidth(size_t * maxWidthInElements, cudaChannelFormatDesc const * fmtDesc, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetTexture1DLinearMaxWidth) (size_t *, cudaChannelFormatDesc const *, int) = (cudaError_t (*)(size_t *, cudaChannelFormatDesc const *, int))dlsym(RTLD_NEXT, "cudaDeviceGetTexture1DLinearMaxWidth");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetTexture1DLinearMaxWidth", kApiTypeRuntime);

    lretval = lcudaDeviceGetTexture1DLinearMaxWidth(maxWidthInElements, fmtDesc, device);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetCacheConfig(cudaFuncCache * pCacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetCacheConfig) (cudaFuncCache *) = (cudaError_t (*)(cudaFuncCache *))dlsym(RTLD_NEXT, "cudaDeviceGetCacheConfig");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetCacheConfig", kApiTypeRuntime);

    lretval = lcudaDeviceGetCacheConfig(pCacheConfig);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetStreamPriorityRange(int * leastPriority, int * greatestPriority){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetStreamPriorityRange) (int *, int *) = (cudaError_t (*)(int *, int *))dlsym(RTLD_NEXT, "cudaDeviceGetStreamPriorityRange");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetStreamPriorityRange", kApiTypeRuntime);

    lretval = lcudaDeviceGetStreamPriorityRange(leastPriority, greatestPriority);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceSetCacheConfig(cudaFuncCache cacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSetCacheConfig) (cudaFuncCache) = (cudaError_t (*)(cudaFuncCache))dlsym(RTLD_NEXT, "cudaDeviceSetCacheConfig");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceSetCacheConfig", kApiTypeRuntime);

    lretval = lcudaDeviceSetCacheConfig(cacheConfig);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetSharedMemConfig) (cudaSharedMemConfig *) = (cudaError_t (*)(cudaSharedMemConfig *))dlsym(RTLD_NEXT, "cudaDeviceGetSharedMemConfig");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetSharedMemConfig", kApiTypeRuntime);

    lretval = lcudaDeviceGetSharedMemConfig(pConfig);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceSetSharedMemConfig(cudaSharedMemConfig config){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSetSharedMemConfig) (cudaSharedMemConfig) = (cudaError_t (*)(cudaSharedMemConfig))dlsym(RTLD_NEXT, "cudaDeviceSetSharedMemConfig");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceSetSharedMemConfig", kApiTypeRuntime);

    lretval = lcudaDeviceSetSharedMemConfig(config);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetByPCIBusId(int * device, char const * pciBusId){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetByPCIBusId) (int *, char const *) = (cudaError_t (*)(int *, char const *))dlsym(RTLD_NEXT, "cudaDeviceGetByPCIBusId");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetByPCIBusId", kApiTypeRuntime);

    lretval = lcudaDeviceGetByPCIBusId(device, pciBusId);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetPCIBusId(char * pciBusId, int len, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetPCIBusId) (char *, int, int) = (cudaError_t (*)(char *, int, int))dlsym(RTLD_NEXT, "cudaDeviceGetPCIBusId");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetPCIBusId", kApiTypeRuntime);

    lretval = lcudaDeviceGetPCIBusId(pciBusId, len, device);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaIpcGetEventHandle(cudaIpcEventHandle_t * handle, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcGetEventHandle) (cudaIpcEventHandle_t *, cudaEvent_t) = (cudaError_t (*)(cudaIpcEventHandle_t *, cudaEvent_t))dlsym(RTLD_NEXT, "cudaIpcGetEventHandle");

    /* pre exeuction logics */
    ac.add_counter("cudaIpcGetEventHandle", kApiTypeRuntime);

    lretval = lcudaIpcGetEventHandle(handle, event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaIpcOpenEventHandle(cudaEvent_t * event, cudaIpcEventHandle_t handle){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcOpenEventHandle) (cudaEvent_t *, cudaIpcEventHandle_t) = (cudaError_t (*)(cudaEvent_t *, cudaIpcEventHandle_t))dlsym(RTLD_NEXT, "cudaIpcOpenEventHandle");

    /* pre exeuction logics */
    ac.add_counter("cudaIpcOpenEventHandle", kApiTypeRuntime);

    lretval = lcudaIpcOpenEventHandle(event, handle);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaIpcGetMemHandle(cudaIpcMemHandle_t * handle, void * devPtr){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcGetMemHandle) (cudaIpcMemHandle_t *, void *) = (cudaError_t (*)(cudaIpcMemHandle_t *, void *))dlsym(RTLD_NEXT, "cudaIpcGetMemHandle");

    /* pre exeuction logics */
    ac.add_counter("cudaIpcGetMemHandle", kApiTypeRuntime);

    lretval = lcudaIpcGetMemHandle(handle, devPtr);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaIpcOpenMemHandle(void * * devPtr, cudaIpcMemHandle_t handle, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcOpenMemHandle) (void * *, cudaIpcMemHandle_t, unsigned int) = (cudaError_t (*)(void * *, cudaIpcMemHandle_t, unsigned int))dlsym(RTLD_NEXT, "cudaIpcOpenMemHandle");

    /* pre exeuction logics */
    ac.add_counter("cudaIpcOpenMemHandle", kApiTypeRuntime);

    lretval = lcudaIpcOpenMemHandle(devPtr, handle, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaIpcCloseMemHandle(void * devPtr){
    cudaError_t lretval;
    cudaError_t (*lcudaIpcCloseMemHandle) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaIpcCloseMemHandle");

    /* pre exeuction logics */
    ac.add_counter("cudaIpcCloseMemHandle", kApiTypeRuntime);

    lretval = lcudaIpcCloseMemHandle(devPtr);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceFlushGPUDirectRDMAWrites(cudaFlushGPUDirectRDMAWritesTarget target, cudaFlushGPUDirectRDMAWritesScope scope){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceFlushGPUDirectRDMAWrites) (cudaFlushGPUDirectRDMAWritesTarget, cudaFlushGPUDirectRDMAWritesScope) = (cudaError_t (*)(cudaFlushGPUDirectRDMAWritesTarget, cudaFlushGPUDirectRDMAWritesScope))dlsym(RTLD_NEXT, "cudaDeviceFlushGPUDirectRDMAWrites");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceFlushGPUDirectRDMAWrites", kApiTypeRuntime);

    lretval = lcudaDeviceFlushGPUDirectRDMAWrites(target, scope);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaThreadExit(){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadExit) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaThreadExit");

    /* pre exeuction logics */
    ac.add_counter("cudaThreadExit", kApiTypeRuntime);

    lretval = lcudaThreadExit();
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaThreadSynchronize(){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadSynchronize) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaThreadSynchronize");

    /* pre exeuction logics */
    ac.add_counter("cudaThreadSynchronize", kApiTypeRuntime);

    lretval = lcudaThreadSynchronize();
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaThreadSetLimit(cudaLimit limit, size_t value){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadSetLimit) (cudaLimit, size_t) = (cudaError_t (*)(cudaLimit, size_t))dlsym(RTLD_NEXT, "cudaThreadSetLimit");

    /* pre exeuction logics */
    ac.add_counter("cudaThreadSetLimit", kApiTypeRuntime);

    lretval = lcudaThreadSetLimit(limit, value);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaThreadGetLimit(size_t * pValue, cudaLimit limit){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadGetLimit) (size_t *, cudaLimit) = (cudaError_t (*)(size_t *, cudaLimit))dlsym(RTLD_NEXT, "cudaThreadGetLimit");

    /* pre exeuction logics */
    ac.add_counter("cudaThreadGetLimit", kApiTypeRuntime);

    lretval = lcudaThreadGetLimit(pValue, limit);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaThreadGetCacheConfig(cudaFuncCache * pCacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadGetCacheConfig) (cudaFuncCache *) = (cudaError_t (*)(cudaFuncCache *))dlsym(RTLD_NEXT, "cudaThreadGetCacheConfig");

    /* pre exeuction logics */
    ac.add_counter("cudaThreadGetCacheConfig", kApiTypeRuntime);

    lretval = lcudaThreadGetCacheConfig(pCacheConfig);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaThreadSetCacheConfig(cudaFuncCache cacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadSetCacheConfig) (cudaFuncCache) = (cudaError_t (*)(cudaFuncCache))dlsym(RTLD_NEXT, "cudaThreadSetCacheConfig");

    /* pre exeuction logics */
    ac.add_counter("cudaThreadSetCacheConfig", kApiTypeRuntime);

    lretval = lcudaThreadSetCacheConfig(cacheConfig);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetLastError(){
    cudaError_t lretval;
    cudaError_t (*lcudaGetLastError) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaGetLastError");

    /* pre exeuction logics */
    ac.add_counter("cudaGetLastError", kApiTypeRuntime);

    lretval = lcudaGetLastError();
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaPeekAtLastError(){
    cudaError_t lretval;
    cudaError_t (*lcudaPeekAtLastError) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaPeekAtLastError");

    /* pre exeuction logics */
    ac.add_counter("cudaPeekAtLastError", kApiTypeRuntime);

    lretval = lcudaPeekAtLastError();
    
    /* post exeuction logics */

    return lretval;
}


char const * cudaGetErrorName(cudaError_t error){
    char const * lretval;
    char const * (*lcudaGetErrorName) (cudaError_t) = (char const * (*)(cudaError_t))dlsym(RTLD_NEXT, "cudaGetErrorName");

    /* pre exeuction logics */
    ac.add_counter("cudaGetErrorName", kApiTypeRuntime);

    lretval = lcudaGetErrorName(error);
    
    /* post exeuction logics */

    return lretval;
}


char const * cudaGetErrorString(cudaError_t error){
    char const * lretval;
    char const * (*lcudaGetErrorString) (cudaError_t) = (char const * (*)(cudaError_t))dlsym(RTLD_NEXT, "cudaGetErrorString");

    /* pre exeuction logics */
    ac.add_counter("cudaGetErrorString", kApiTypeRuntime);

    lretval = lcudaGetErrorString(error);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetDeviceCount(int * count){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDeviceCount) (int *) = (cudaError_t (*)(int *))dlsym(RTLD_NEXT, "cudaGetDeviceCount");

    /* pre exeuction logics */
    ac.add_counter("cudaGetDeviceCount", kApiTypeRuntime);

    lretval = lcudaGetDeviceCount(count);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetDeviceProperties(cudaDeviceProp * prop, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDeviceProperties) (cudaDeviceProp *, int) = (cudaError_t (*)(cudaDeviceProp *, int))dlsym(RTLD_NEXT, "cudaGetDeviceProperties");

    /* pre exeuction logics */
    ac.add_counter("cudaGetDeviceProperties", kApiTypeRuntime);

    lretval = lcudaGetDeviceProperties(prop, device);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetAttribute(int * value, cudaDeviceAttr attr, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetAttribute) (int *, cudaDeviceAttr, int) = (cudaError_t (*)(int *, cudaDeviceAttr, int))dlsym(RTLD_NEXT, "cudaDeviceGetAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetAttribute", kApiTypeRuntime);

    lretval = lcudaDeviceGetAttribute(value, attr, device);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetDefaultMemPool(cudaMemPool_t * memPool, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetDefaultMemPool) (cudaMemPool_t *, int) = (cudaError_t (*)(cudaMemPool_t *, int))dlsym(RTLD_NEXT, "cudaDeviceGetDefaultMemPool");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetDefaultMemPool", kApiTypeRuntime);

    lretval = lcudaDeviceGetDefaultMemPool(memPool, device);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceSetMemPool(int device, cudaMemPool_t memPool){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceSetMemPool) (int, cudaMemPool_t) = (cudaError_t (*)(int, cudaMemPool_t))dlsym(RTLD_NEXT, "cudaDeviceSetMemPool");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceSetMemPool", kApiTypeRuntime);

    lretval = lcudaDeviceSetMemPool(device, memPool);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetMemPool(cudaMemPool_t * memPool, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetMemPool) (cudaMemPool_t *, int) = (cudaError_t (*)(cudaMemPool_t *, int))dlsym(RTLD_NEXT, "cudaDeviceGetMemPool");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetMemPool", kApiTypeRuntime);

    lretval = lcudaDeviceGetMemPool(memPool, device);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetNvSciSyncAttributes(void * nvSciSyncAttrList, int device, int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetNvSciSyncAttributes) (void *, int, int) = (cudaError_t (*)(void *, int, int))dlsym(RTLD_NEXT, "cudaDeviceGetNvSciSyncAttributes");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetNvSciSyncAttributes", kApiTypeRuntime);

    lretval = lcudaDeviceGetNvSciSyncAttributes(nvSciSyncAttrList, device, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceGetP2PAttribute(int * value, cudaDeviceP2PAttr attr, int srcDevice, int dstDevice){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceGetP2PAttribute) (int *, cudaDeviceP2PAttr, int, int) = (cudaError_t (*)(int *, cudaDeviceP2PAttr, int, int))dlsym(RTLD_NEXT, "cudaDeviceGetP2PAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceGetP2PAttribute", kApiTypeRuntime);

    lretval = lcudaDeviceGetP2PAttribute(value, attr, srcDevice, dstDevice);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaChooseDevice(int * device, cudaDeviceProp const * prop){
    cudaError_t lretval;
    cudaError_t (*lcudaChooseDevice) (int *, cudaDeviceProp const *) = (cudaError_t (*)(int *, cudaDeviceProp const *))dlsym(RTLD_NEXT, "cudaChooseDevice");

    /* pre exeuction logics */
    ac.add_counter("cudaChooseDevice", kApiTypeRuntime);

    lretval = lcudaChooseDevice(device, prop);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaSetDevice(int device){
    cudaError_t lretval;
    cudaError_t (*lcudaSetDevice) (int) = (cudaError_t (*)(int))dlsym(RTLD_NEXT, "cudaSetDevice");

    /* pre exeuction logics */
    ac.add_counter("cudaSetDevice", kApiTypeRuntime);

    lretval = lcudaSetDevice(device);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetDevice(int * device){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDevice) (int *) = (cudaError_t (*)(int *))dlsym(RTLD_NEXT, "cudaGetDevice");

    /* pre exeuction logics */
    ac.add_counter("cudaGetDevice", kApiTypeRuntime);

    lretval = lcudaGetDevice(device);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaSetValidDevices(int * device_arr, int len){
    cudaError_t lretval;
    cudaError_t (*lcudaSetValidDevices) (int *, int) = (cudaError_t (*)(int *, int))dlsym(RTLD_NEXT, "cudaSetValidDevices");

    /* pre exeuction logics */
    ac.add_counter("cudaSetValidDevices", kApiTypeRuntime);

    lretval = lcudaSetValidDevices(device_arr, len);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaSetDeviceFlags(unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaSetDeviceFlags) (unsigned int) = (cudaError_t (*)(unsigned int))dlsym(RTLD_NEXT, "cudaSetDeviceFlags");

    /* pre exeuction logics */
    ac.add_counter("cudaSetDeviceFlags", kApiTypeRuntime);

    lretval = lcudaSetDeviceFlags(flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetDeviceFlags(unsigned int * flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDeviceFlags) (unsigned int *) = (cudaError_t (*)(unsigned int *))dlsym(RTLD_NEXT, "cudaGetDeviceFlags");

    /* pre exeuction logics */
    ac.add_counter("cudaGetDeviceFlags", kApiTypeRuntime);

    lretval = lcudaGetDeviceFlags(flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamCreate(cudaStream_t * pStream){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamCreate) (cudaStream_t *) = (cudaError_t (*)(cudaStream_t *))dlsym(RTLD_NEXT, "cudaStreamCreate");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamCreate", kApiTypeRuntime);

    lretval = lcudaStreamCreate(pStream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamCreateWithFlags(cudaStream_t * pStream, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamCreateWithFlags) (cudaStream_t *, unsigned int) = (cudaError_t (*)(cudaStream_t *, unsigned int))dlsym(RTLD_NEXT, "cudaStreamCreateWithFlags");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamCreateWithFlags", kApiTypeRuntime);

    lretval = lcudaStreamCreateWithFlags(pStream, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamCreateWithPriority(cudaStream_t * pStream, unsigned int flags, int priority){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamCreateWithPriority) (cudaStream_t *, unsigned int, int) = (cudaError_t (*)(cudaStream_t *, unsigned int, int))dlsym(RTLD_NEXT, "cudaStreamCreateWithPriority");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamCreateWithPriority", kApiTypeRuntime);

    lretval = lcudaStreamCreateWithPriority(pStream, flags, priority);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamGetPriority(cudaStream_t hStream, int * priority){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetPriority) (cudaStream_t, int *) = (cudaError_t (*)(cudaStream_t, int *))dlsym(RTLD_NEXT, "cudaStreamGetPriority");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamGetPriority", kApiTypeRuntime);

    lretval = lcudaStreamGetPriority(hStream, priority);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamGetFlags(cudaStream_t hStream, unsigned int * flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetFlags) (cudaStream_t, unsigned int *) = (cudaError_t (*)(cudaStream_t, unsigned int *))dlsym(RTLD_NEXT, "cudaStreamGetFlags");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamGetFlags", kApiTypeRuntime);

    lretval = lcudaStreamGetFlags(hStream, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaCtxResetPersistingL2Cache(){
    cudaError_t lretval;
    cudaError_t (*lcudaCtxResetPersistingL2Cache) () = (cudaError_t (*)())dlsym(RTLD_NEXT, "cudaCtxResetPersistingL2Cache");

    /* pre exeuction logics */
    ac.add_counter("cudaCtxResetPersistingL2Cache", kApiTypeRuntime);

    lretval = lcudaCtxResetPersistingL2Cache();
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamCopyAttributes(cudaStream_t dst, cudaStream_t src){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamCopyAttributes) (cudaStream_t, cudaStream_t) = (cudaError_t (*)(cudaStream_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaStreamCopyAttributes");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamCopyAttributes", kApiTypeRuntime);

    lretval = lcudaStreamCopyAttributes(dst, src);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamGetAttribute(cudaStream_t hStream, cudaStreamAttrID attr, cudaStreamAttrValue * value_out){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetAttribute) (cudaStream_t, cudaStreamAttrID, cudaStreamAttrValue *) = (cudaError_t (*)(cudaStream_t, cudaStreamAttrID, cudaStreamAttrValue *))dlsym(RTLD_NEXT, "cudaStreamGetAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamGetAttribute", kApiTypeRuntime);

    lretval = lcudaStreamGetAttribute(hStream, attr, value_out);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamSetAttribute(cudaStream_t hStream, cudaStreamAttrID attr, cudaStreamAttrValue const * value){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamSetAttribute) (cudaStream_t, cudaStreamAttrID, cudaStreamAttrValue const *) = (cudaError_t (*)(cudaStream_t, cudaStreamAttrID, cudaStreamAttrValue const *))dlsym(RTLD_NEXT, "cudaStreamSetAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamSetAttribute", kApiTypeRuntime);

    lretval = lcudaStreamSetAttribute(hStream, attr, value);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamDestroy(cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamDestroy) (cudaStream_t) = (cudaError_t (*)(cudaStream_t))dlsym(RTLD_NEXT, "cudaStreamDestroy");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamDestroy", kApiTypeRuntime);

    lretval = lcudaStreamDestroy(stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamWaitEvent) (cudaStream_t, cudaEvent_t, unsigned int) = (cudaError_t (*)(cudaStream_t, cudaEvent_t, unsigned int))dlsym(RTLD_NEXT, "cudaStreamWaitEvent");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamWaitEvent", kApiTypeRuntime);

    lretval = lcudaStreamWaitEvent(stream, event, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamAddCallback(cudaStream_t stream, cudaStreamCallback_t callback, void * userData, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamAddCallback) (cudaStream_t, cudaStreamCallback_t, void *, unsigned int) = (cudaError_t (*)(cudaStream_t, cudaStreamCallback_t, void *, unsigned int))dlsym(RTLD_NEXT, "cudaStreamAddCallback");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamAddCallback", kApiTypeRuntime);

    lretval = lcudaStreamAddCallback(stream, callback, userData, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamSynchronize(cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamSynchronize) (cudaStream_t) = (cudaError_t (*)(cudaStream_t))dlsym(RTLD_NEXT, "cudaStreamSynchronize");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamSynchronize", kApiTypeRuntime);

    lretval = lcudaStreamSynchronize(stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamQuery(cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamQuery) (cudaStream_t) = (cudaError_t (*)(cudaStream_t))dlsym(RTLD_NEXT, "cudaStreamQuery");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamQuery", kApiTypeRuntime);

    lretval = lcudaStreamQuery(stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamAttachMemAsync(cudaStream_t stream, void * devPtr, size_t length, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamAttachMemAsync) (cudaStream_t, void *, size_t, unsigned int) = (cudaError_t (*)(cudaStream_t, void *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaStreamAttachMemAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamAttachMemAsync", kApiTypeRuntime);

    lretval = lcudaStreamAttachMemAsync(stream, devPtr, length, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamBeginCapture(cudaStream_t stream, cudaStreamCaptureMode mode){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamBeginCapture) (cudaStream_t, cudaStreamCaptureMode) = (cudaError_t (*)(cudaStream_t, cudaStreamCaptureMode))dlsym(RTLD_NEXT, "cudaStreamBeginCapture");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamBeginCapture", kApiTypeRuntime);

    lretval = lcudaStreamBeginCapture(stream, mode);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaThreadExchangeStreamCaptureMode(cudaStreamCaptureMode * mode){
    cudaError_t lretval;
    cudaError_t (*lcudaThreadExchangeStreamCaptureMode) (cudaStreamCaptureMode *) = (cudaError_t (*)(cudaStreamCaptureMode *))dlsym(RTLD_NEXT, "cudaThreadExchangeStreamCaptureMode");

    /* pre exeuction logics */
    ac.add_counter("cudaThreadExchangeStreamCaptureMode", kApiTypeRuntime);

    lretval = lcudaThreadExchangeStreamCaptureMode(mode);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamEndCapture(cudaStream_t stream, cudaGraph_t * pGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamEndCapture) (cudaStream_t, cudaGraph_t *) = (cudaError_t (*)(cudaStream_t, cudaGraph_t *))dlsym(RTLD_NEXT, "cudaStreamEndCapture");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamEndCapture", kApiTypeRuntime);

    lretval = lcudaStreamEndCapture(stream, pGraph);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamIsCapturing(cudaStream_t stream, cudaStreamCaptureStatus * pCaptureStatus){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamIsCapturing) (cudaStream_t, cudaStreamCaptureStatus *) = (cudaError_t (*)(cudaStream_t, cudaStreamCaptureStatus *))dlsym(RTLD_NEXT, "cudaStreamIsCapturing");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamIsCapturing", kApiTypeRuntime);

    lretval = lcudaStreamIsCapturing(stream, pCaptureStatus);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamGetCaptureInfo(cudaStream_t stream, cudaStreamCaptureStatus * pCaptureStatus, long long unsigned int * pId){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetCaptureInfo) (cudaStream_t, cudaStreamCaptureStatus *, long long unsigned int *) = (cudaError_t (*)(cudaStream_t, cudaStreamCaptureStatus *, long long unsigned int *))dlsym(RTLD_NEXT, "cudaStreamGetCaptureInfo");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamGetCaptureInfo", kApiTypeRuntime);

    lretval = lcudaStreamGetCaptureInfo(stream, pCaptureStatus, pId);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamGetCaptureInfo_v2(cudaStream_t stream, cudaStreamCaptureStatus * captureStatus_out, long long unsigned int * id_out, cudaGraph_t * graph_out, cudaGraphNode_t const * * dependencies_out, size_t * numDependencies_out){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamGetCaptureInfo_v2) (cudaStream_t, cudaStreamCaptureStatus *, long long unsigned int *, cudaGraph_t *, cudaGraphNode_t const * *, size_t *) = (cudaError_t (*)(cudaStream_t, cudaStreamCaptureStatus *, long long unsigned int *, cudaGraph_t *, cudaGraphNode_t const * *, size_t *))dlsym(RTLD_NEXT, "cudaStreamGetCaptureInfo_v2");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamGetCaptureInfo_v2", kApiTypeRuntime);

    lretval = lcudaStreamGetCaptureInfo_v2(stream, captureStatus_out, id_out, graph_out, dependencies_out, numDependencies_out);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaStreamUpdateCaptureDependencies(cudaStream_t stream, cudaGraphNode_t * dependencies, size_t numDependencies, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaStreamUpdateCaptureDependencies) (cudaStream_t, cudaGraphNode_t *, size_t, unsigned int) = (cudaError_t (*)(cudaStream_t, cudaGraphNode_t *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaStreamUpdateCaptureDependencies");

    /* pre exeuction logics */
    ac.add_counter("cudaStreamUpdateCaptureDependencies", kApiTypeRuntime);

    lretval = lcudaStreamUpdateCaptureDependencies(stream, dependencies, numDependencies, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaEventCreate(cudaEvent_t * event){
    cudaError_t lretval;
    cudaError_t (*lcudaEventCreate) (cudaEvent_t *) = (cudaError_t (*)(cudaEvent_t *))dlsym(RTLD_NEXT, "cudaEventCreate");

    /* pre exeuction logics */
    ac.add_counter("cudaEventCreate", kApiTypeRuntime);

    lretval = lcudaEventCreate(event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaEventCreateWithFlags(cudaEvent_t * event, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaEventCreateWithFlags) (cudaEvent_t *, unsigned int) = (cudaError_t (*)(cudaEvent_t *, unsigned int))dlsym(RTLD_NEXT, "cudaEventCreateWithFlags");

    /* pre exeuction logics */
    ac.add_counter("cudaEventCreateWithFlags", kApiTypeRuntime);

    lretval = lcudaEventCreateWithFlags(event, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaEventRecord) (cudaEvent_t, cudaStream_t) = (cudaError_t (*)(cudaEvent_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaEventRecord");

    /* pre exeuction logics */
    ac.add_counter("cudaEventRecord", kApiTypeRuntime);

    lretval = lcudaEventRecord(event, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaEventRecordWithFlags(cudaEvent_t event, cudaStream_t stream, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaEventRecordWithFlags) (cudaEvent_t, cudaStream_t, unsigned int) = (cudaError_t (*)(cudaEvent_t, cudaStream_t, unsigned int))dlsym(RTLD_NEXT, "cudaEventRecordWithFlags");

    /* pre exeuction logics */
    ac.add_counter("cudaEventRecordWithFlags", kApiTypeRuntime);

    lretval = lcudaEventRecordWithFlags(event, stream, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaEventQuery(cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaEventQuery) (cudaEvent_t) = (cudaError_t (*)(cudaEvent_t))dlsym(RTLD_NEXT, "cudaEventQuery");

    /* pre exeuction logics */
    ac.add_counter("cudaEventQuery", kApiTypeRuntime);

    lretval = lcudaEventQuery(event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaEventSynchronize(cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaEventSynchronize) (cudaEvent_t) = (cudaError_t (*)(cudaEvent_t))dlsym(RTLD_NEXT, "cudaEventSynchronize");

    /* pre exeuction logics */
    ac.add_counter("cudaEventSynchronize", kApiTypeRuntime);

    lretval = lcudaEventSynchronize(event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaEventDestroy(cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaEventDestroy) (cudaEvent_t) = (cudaError_t (*)(cudaEvent_t))dlsym(RTLD_NEXT, "cudaEventDestroy");

    /* pre exeuction logics */
    ac.add_counter("cudaEventDestroy", kApiTypeRuntime);

    lretval = lcudaEventDestroy(event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaEventElapsedTime(float * ms, cudaEvent_t start, cudaEvent_t end){
    cudaError_t lretval;
    cudaError_t (*lcudaEventElapsedTime) (float *, cudaEvent_t, cudaEvent_t) = (cudaError_t (*)(float *, cudaEvent_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaEventElapsedTime");

    /* pre exeuction logics */
    ac.add_counter("cudaEventElapsedTime", kApiTypeRuntime);

    lretval = lcudaEventElapsedTime(ms, start, end);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaImportExternalMemory(cudaExternalMemory_t * extMem_out, cudaExternalMemoryHandleDesc const * memHandleDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaImportExternalMemory) (cudaExternalMemory_t *, cudaExternalMemoryHandleDesc const *) = (cudaError_t (*)(cudaExternalMemory_t *, cudaExternalMemoryHandleDesc const *))dlsym(RTLD_NEXT, "cudaImportExternalMemory");

    /* pre exeuction logics */
    ac.add_counter("cudaImportExternalMemory", kApiTypeRuntime);

    lretval = lcudaImportExternalMemory(extMem_out, memHandleDesc);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaExternalMemoryGetMappedBuffer(void * * devPtr, cudaExternalMemory_t extMem, cudaExternalMemoryBufferDesc const * bufferDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaExternalMemoryGetMappedBuffer) (void * *, cudaExternalMemory_t, cudaExternalMemoryBufferDesc const *) = (cudaError_t (*)(void * *, cudaExternalMemory_t, cudaExternalMemoryBufferDesc const *))dlsym(RTLD_NEXT, "cudaExternalMemoryGetMappedBuffer");

    /* pre exeuction logics */
    ac.add_counter("cudaExternalMemoryGetMappedBuffer", kApiTypeRuntime);

    lretval = lcudaExternalMemoryGetMappedBuffer(devPtr, extMem, bufferDesc);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaExternalMemoryGetMappedMipmappedArray(cudaMipmappedArray_t * mipmap, cudaExternalMemory_t extMem, cudaExternalMemoryMipmappedArrayDesc const * mipmapDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaExternalMemoryGetMappedMipmappedArray) (cudaMipmappedArray_t *, cudaExternalMemory_t, cudaExternalMemoryMipmappedArrayDesc const *) = (cudaError_t (*)(cudaMipmappedArray_t *, cudaExternalMemory_t, cudaExternalMemoryMipmappedArrayDesc const *))dlsym(RTLD_NEXT, "cudaExternalMemoryGetMappedMipmappedArray");

    /* pre exeuction logics */
    ac.add_counter("cudaExternalMemoryGetMappedMipmappedArray", kApiTypeRuntime);

    lretval = lcudaExternalMemoryGetMappedMipmappedArray(mipmap, extMem, mipmapDesc);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDestroyExternalMemory(cudaExternalMemory_t extMem){
    cudaError_t lretval;
    cudaError_t (*lcudaDestroyExternalMemory) (cudaExternalMemory_t) = (cudaError_t (*)(cudaExternalMemory_t))dlsym(RTLD_NEXT, "cudaDestroyExternalMemory");

    /* pre exeuction logics */
    ac.add_counter("cudaDestroyExternalMemory", kApiTypeRuntime);

    lretval = lcudaDestroyExternalMemory(extMem);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaImportExternalSemaphore(cudaExternalSemaphore_t * extSem_out, cudaExternalSemaphoreHandleDesc const * semHandleDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaImportExternalSemaphore) (cudaExternalSemaphore_t *, cudaExternalSemaphoreHandleDesc const *) = (cudaError_t (*)(cudaExternalSemaphore_t *, cudaExternalSemaphoreHandleDesc const *))dlsym(RTLD_NEXT, "cudaImportExternalSemaphore");

    /* pre exeuction logics */
    ac.add_counter("cudaImportExternalSemaphore", kApiTypeRuntime);

    lretval = lcudaImportExternalSemaphore(extSem_out, semHandleDesc);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaSignalExternalSemaphoresAsync_v2(cudaExternalSemaphore_t const * extSemArray, cudaExternalSemaphoreSignalParams const * paramsArray, unsigned int numExtSems, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaSignalExternalSemaphoresAsync_v2) (cudaExternalSemaphore_t const *, cudaExternalSemaphoreSignalParams const *, unsigned int, cudaStream_t) = (cudaError_t (*)(cudaExternalSemaphore_t const *, cudaExternalSemaphoreSignalParams const *, unsigned int, cudaStream_t))dlsym(RTLD_NEXT, "cudaSignalExternalSemaphoresAsync_v2");

    /* pre exeuction logics */
    ac.add_counter("cudaSignalExternalSemaphoresAsync_v2", kApiTypeRuntime);

    lretval = lcudaSignalExternalSemaphoresAsync_v2(extSemArray, paramsArray, numExtSems, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaWaitExternalSemaphoresAsync_v2(cudaExternalSemaphore_t const * extSemArray, cudaExternalSemaphoreWaitParams const * paramsArray, unsigned int numExtSems, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaWaitExternalSemaphoresAsync_v2) (cudaExternalSemaphore_t const *, cudaExternalSemaphoreWaitParams const *, unsigned int, cudaStream_t) = (cudaError_t (*)(cudaExternalSemaphore_t const *, cudaExternalSemaphoreWaitParams const *, unsigned int, cudaStream_t))dlsym(RTLD_NEXT, "cudaWaitExternalSemaphoresAsync_v2");

    /* pre exeuction logics */
    ac.add_counter("cudaWaitExternalSemaphoresAsync_v2", kApiTypeRuntime);

    lretval = lcudaWaitExternalSemaphoresAsync_v2(extSemArray, paramsArray, numExtSems, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDestroyExternalSemaphore(cudaExternalSemaphore_t extSem){
    cudaError_t lretval;
    cudaError_t (*lcudaDestroyExternalSemaphore) (cudaExternalSemaphore_t) = (cudaError_t (*)(cudaExternalSemaphore_t))dlsym(RTLD_NEXT, "cudaDestroyExternalSemaphore");

    /* pre exeuction logics */
    ac.add_counter("cudaDestroyExternalSemaphore", kApiTypeRuntime);

    lretval = lcudaDestroyExternalSemaphore(extSem);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaLaunchKernel(void const * func, dim3 gridDim, dim3 blockDim, void * * args, size_t sharedMem, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaLaunchKernel) (void const *, dim3, dim3, void * *, size_t, cudaStream_t) = (cudaError_t (*)(void const *, dim3, dim3, void * *, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaLaunchKernel");

    /* pre exeuction logics */
    ac.add_counter("cudaLaunchKernel", kApiTypeRuntime);

    lretval = lcudaLaunchKernel(func, gridDim, blockDim, args, sharedMem, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaLaunchCooperativeKernel(void const * func, dim3 gridDim, dim3 blockDim, void * * args, size_t sharedMem, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaLaunchCooperativeKernel) (void const *, dim3, dim3, void * *, size_t, cudaStream_t) = (cudaError_t (*)(void const *, dim3, dim3, void * *, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaLaunchCooperativeKernel");

    /* pre exeuction logics */
    ac.add_counter("cudaLaunchCooperativeKernel", kApiTypeRuntime);

    lretval = lcudaLaunchCooperativeKernel(func, gridDim, blockDim, args, sharedMem, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaLaunchCooperativeKernelMultiDevice(cudaLaunchParams * launchParamsList, unsigned int numDevices, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaLaunchCooperativeKernelMultiDevice) (cudaLaunchParams *, unsigned int, unsigned int) = (cudaError_t (*)(cudaLaunchParams *, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaLaunchCooperativeKernelMultiDevice");

    /* pre exeuction logics */
    ac.add_counter("cudaLaunchCooperativeKernelMultiDevice", kApiTypeRuntime);

    lretval = lcudaLaunchCooperativeKernelMultiDevice(launchParamsList, numDevices, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaFuncSetCacheConfig(void const * func, cudaFuncCache cacheConfig){
    cudaError_t lretval;
    cudaError_t (*lcudaFuncSetCacheConfig) (void const *, cudaFuncCache) = (cudaError_t (*)(void const *, cudaFuncCache))dlsym(RTLD_NEXT, "cudaFuncSetCacheConfig");

    /* pre exeuction logics */
    ac.add_counter("cudaFuncSetCacheConfig", kApiTypeRuntime);

    lretval = lcudaFuncSetCacheConfig(func, cacheConfig);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaFuncSetSharedMemConfig(void const * func, cudaSharedMemConfig config){
    cudaError_t lretval;
    cudaError_t (*lcudaFuncSetSharedMemConfig) (void const *, cudaSharedMemConfig) = (cudaError_t (*)(void const *, cudaSharedMemConfig))dlsym(RTLD_NEXT, "cudaFuncSetSharedMemConfig");

    /* pre exeuction logics */
    ac.add_counter("cudaFuncSetSharedMemConfig", kApiTypeRuntime);

    lretval = lcudaFuncSetSharedMemConfig(func, config);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, void const * func){
    cudaError_t lretval;
    cudaError_t (*lcudaFuncGetAttributes) (cudaFuncAttributes *, void const *) = (cudaError_t (*)(cudaFuncAttributes *, void const *))dlsym(RTLD_NEXT, "cudaFuncGetAttributes");

    /* pre exeuction logics */
    ac.add_counter("cudaFuncGetAttributes", kApiTypeRuntime);

    lretval = lcudaFuncGetAttributes(attr, func);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaFuncSetAttribute(void const * func, cudaFuncAttribute attr, int value){
    cudaError_t lretval;
    cudaError_t (*lcudaFuncSetAttribute) (void const *, cudaFuncAttribute, int) = (cudaError_t (*)(void const *, cudaFuncAttribute, int))dlsym(RTLD_NEXT, "cudaFuncSetAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaFuncSetAttribute", kApiTypeRuntime);

    lretval = lcudaFuncSetAttribute(func, attr, value);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaSetDoubleForDevice(double * d){
    cudaError_t lretval;
    cudaError_t (*lcudaSetDoubleForDevice) (double *) = (cudaError_t (*)(double *))dlsym(RTLD_NEXT, "cudaSetDoubleForDevice");

    /* pre exeuction logics */
    ac.add_counter("cudaSetDoubleForDevice", kApiTypeRuntime);

    lretval = lcudaSetDoubleForDevice(d);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaSetDoubleForHost(double * d){
    cudaError_t lretval;
    cudaError_t (*lcudaSetDoubleForHost) (double *) = (cudaError_t (*)(double *))dlsym(RTLD_NEXT, "cudaSetDoubleForHost");

    /* pre exeuction logics */
    ac.add_counter("cudaSetDoubleForHost", kApiTypeRuntime);

    lretval = lcudaSetDoubleForHost(d);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaLaunchHostFunc(cudaStream_t stream, cudaHostFn_t fn, void * userData){
    cudaError_t lretval;
    cudaError_t (*lcudaLaunchHostFunc) (cudaStream_t, cudaHostFn_t, void *) = (cudaError_t (*)(cudaStream_t, cudaHostFn_t, void *))dlsym(RTLD_NEXT, "cudaLaunchHostFunc");

    /* pre exeuction logics */
    ac.add_counter("cudaLaunchHostFunc", kApiTypeRuntime);

    lretval = lcudaLaunchHostFunc(stream, fn, userData);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, void const * func, int blockSize, size_t dynamicSMemSize){
    cudaError_t lretval;
    cudaError_t (*lcudaOccupancyMaxActiveBlocksPerMultiprocessor) (int *, void const *, int, size_t) = (cudaError_t (*)(int *, void const *, int, size_t))dlsym(RTLD_NEXT, "cudaOccupancyMaxActiveBlocksPerMultiprocessor");

    /* pre exeuction logics */
    ac.add_counter("cudaOccupancyMaxActiveBlocksPerMultiprocessor", kApiTypeRuntime);

    lretval = lcudaOccupancyMaxActiveBlocksPerMultiprocessor(numBlocks, func, blockSize, dynamicSMemSize);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaOccupancyAvailableDynamicSMemPerBlock(size_t * dynamicSmemSize, void const * func, int numBlocks, int blockSize){
    cudaError_t lretval;
    cudaError_t (*lcudaOccupancyAvailableDynamicSMemPerBlock) (size_t *, void const *, int, int) = (cudaError_t (*)(size_t *, void const *, int, int))dlsym(RTLD_NEXT, "cudaOccupancyAvailableDynamicSMemPerBlock");

    /* pre exeuction logics */
    ac.add_counter("cudaOccupancyAvailableDynamicSMemPerBlock", kApiTypeRuntime);

    lretval = lcudaOccupancyAvailableDynamicSMemPerBlock(dynamicSmemSize, func, numBlocks, blockSize);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, void const * func, int blockSize, size_t dynamicSMemSize, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags) (int *, void const *, int, size_t, unsigned int) = (cudaError_t (*)(int *, void const *, int, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");

    /* pre exeuction logics */
    ac.add_counter("cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags", kApiTypeRuntime);

    lretval = lcudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, func, blockSize, dynamicSMemSize, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMallocManaged(void * * devPtr, size_t size, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocManaged) (void * *, size_t, unsigned int) = (cudaError_t (*)(void * *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaMallocManaged");

    /* pre exeuction logics */
    ac.add_counter("cudaMallocManaged", kApiTypeRuntime);

    lretval = lcudaMallocManaged(devPtr, size, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMalloc(void * * devPtr, size_t size){
    cudaError_t lretval;
    cudaError_t (*lcudaMalloc) (void * *, size_t) = (cudaError_t (*)(void * *, size_t))dlsym(RTLD_NEXT, "cudaMalloc");

    /* pre exeuction logics */
    ac.add_counter("cudaMalloc", kApiTypeRuntime);

    lretval = lcudaMalloc(devPtr, size);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMallocHost(void * * ptr, size_t size){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocHost) (void * *, size_t) = (cudaError_t (*)(void * *, size_t))dlsym(RTLD_NEXT, "cudaMallocHost");

    /* pre exeuction logics */
    ac.add_counter("cudaMallocHost", kApiTypeRuntime);

    lretval = lcudaMallocHost(ptr, size);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMallocPitch(void * * devPtr, size_t * pitch, size_t width, size_t height){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocPitch) (void * *, size_t *, size_t, size_t) = (cudaError_t (*)(void * *, size_t *, size_t, size_t))dlsym(RTLD_NEXT, "cudaMallocPitch");

    /* pre exeuction logics */
    ac.add_counter("cudaMallocPitch", kApiTypeRuntime);

    lretval = lcudaMallocPitch(devPtr, pitch, width, height);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMallocArray(cudaArray_t * array, cudaChannelFormatDesc const * desc, size_t width, size_t height, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocArray) (cudaArray_t *, cudaChannelFormatDesc const *, size_t, size_t, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaChannelFormatDesc const *, size_t, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaMallocArray");

    /* pre exeuction logics */
    ac.add_counter("cudaMallocArray", kApiTypeRuntime);

    lretval = lcudaMallocArray(array, desc, width, height, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaFree(void * devPtr){
    cudaError_t lretval;
    cudaError_t (*lcudaFree) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaFree");

    /* pre exeuction logics */
    ac.add_counter("cudaFree", kApiTypeRuntime);

    lretval = lcudaFree(devPtr);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaFreeHost(void * ptr){
    cudaError_t lretval;
    cudaError_t (*lcudaFreeHost) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaFreeHost");

    /* pre exeuction logics */
    ac.add_counter("cudaFreeHost", kApiTypeRuntime);

    lretval = lcudaFreeHost(ptr);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaFreeArray(cudaArray_t array){
    cudaError_t lretval;
    cudaError_t (*lcudaFreeArray) (cudaArray_t) = (cudaError_t (*)(cudaArray_t))dlsym(RTLD_NEXT, "cudaFreeArray");

    /* pre exeuction logics */
    ac.add_counter("cudaFreeArray", kApiTypeRuntime);

    lretval = lcudaFreeArray(array);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaFreeMipmappedArray(cudaMipmappedArray_t mipmappedArray){
    cudaError_t lretval;
    cudaError_t (*lcudaFreeMipmappedArray) (cudaMipmappedArray_t) = (cudaError_t (*)(cudaMipmappedArray_t))dlsym(RTLD_NEXT, "cudaFreeMipmappedArray");

    /* pre exeuction logics */
    ac.add_counter("cudaFreeMipmappedArray", kApiTypeRuntime);

    lretval = lcudaFreeMipmappedArray(mipmappedArray);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaHostAlloc(void * * pHost, size_t size, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaHostAlloc) (void * *, size_t, unsigned int) = (cudaError_t (*)(void * *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaHostAlloc");

    /* pre exeuction logics */
    ac.add_counter("cudaHostAlloc", kApiTypeRuntime);

    lretval = lcudaHostAlloc(pHost, size, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaHostRegister(void * ptr, size_t size, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaHostRegister) (void *, size_t, unsigned int) = (cudaError_t (*)(void *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaHostRegister");

    /* pre exeuction logics */
    ac.add_counter("cudaHostRegister", kApiTypeRuntime);

    lretval = lcudaHostRegister(ptr, size, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaHostUnregister(void * ptr){
    cudaError_t lretval;
    cudaError_t (*lcudaHostUnregister) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaHostUnregister");

    /* pre exeuction logics */
    ac.add_counter("cudaHostUnregister", kApiTypeRuntime);

    lretval = lcudaHostUnregister(ptr);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaHostGetDevicePointer(void * * pDevice, void * pHost, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaHostGetDevicePointer) (void * *, void *, unsigned int) = (cudaError_t (*)(void * *, void *, unsigned int))dlsym(RTLD_NEXT, "cudaHostGetDevicePointer");

    /* pre exeuction logics */
    ac.add_counter("cudaHostGetDevicePointer", kApiTypeRuntime);

    lretval = lcudaHostGetDevicePointer(pDevice, pHost, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaHostGetFlags(unsigned int * pFlags, void * pHost){
    cudaError_t lretval;
    cudaError_t (*lcudaHostGetFlags) (unsigned int *, void *) = (cudaError_t (*)(unsigned int *, void *))dlsym(RTLD_NEXT, "cudaHostGetFlags");

    /* pre exeuction logics */
    ac.add_counter("cudaHostGetFlags", kApiTypeRuntime);

    lretval = lcudaHostGetFlags(pFlags, pHost);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMalloc3D(cudaPitchedPtr * pitchedDevPtr, cudaExtent extent){
    cudaError_t lretval;
    cudaError_t (*lcudaMalloc3D) (cudaPitchedPtr *, cudaExtent) = (cudaError_t (*)(cudaPitchedPtr *, cudaExtent))dlsym(RTLD_NEXT, "cudaMalloc3D");

    /* pre exeuction logics */
    ac.add_counter("cudaMalloc3D", kApiTypeRuntime);

    lretval = lcudaMalloc3D(pitchedDevPtr, extent);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMalloc3DArray(cudaArray_t * array, cudaChannelFormatDesc const * desc, cudaExtent extent, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMalloc3DArray) (cudaArray_t *, cudaChannelFormatDesc const *, cudaExtent, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaChannelFormatDesc const *, cudaExtent, unsigned int))dlsym(RTLD_NEXT, "cudaMalloc3DArray");

    /* pre exeuction logics */
    ac.add_counter("cudaMalloc3DArray", kApiTypeRuntime);

    lretval = lcudaMalloc3DArray(array, desc, extent, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMallocMipmappedArray(cudaMipmappedArray_t * mipmappedArray, cudaChannelFormatDesc const * desc, cudaExtent extent, unsigned int numLevels, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocMipmappedArray) (cudaMipmappedArray_t *, cudaChannelFormatDesc const *, cudaExtent, unsigned int, unsigned int) = (cudaError_t (*)(cudaMipmappedArray_t *, cudaChannelFormatDesc const *, cudaExtent, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaMallocMipmappedArray");

    /* pre exeuction logics */
    ac.add_counter("cudaMallocMipmappedArray", kApiTypeRuntime);

    lretval = lcudaMallocMipmappedArray(mipmappedArray, desc, extent, numLevels, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetMipmappedArrayLevel(cudaArray_t * levelArray, cudaMipmappedArray_const_t mipmappedArray, unsigned int level){
    cudaError_t lretval;
    cudaError_t (*lcudaGetMipmappedArrayLevel) (cudaArray_t *, cudaMipmappedArray_const_t, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaMipmappedArray_const_t, unsigned int))dlsym(RTLD_NEXT, "cudaGetMipmappedArrayLevel");

    /* pre exeuction logics */
    ac.add_counter("cudaGetMipmappedArrayLevel", kApiTypeRuntime);

    lretval = lcudaGetMipmappedArrayLevel(levelArray, mipmappedArray, level);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy3D(cudaMemcpy3DParms const * p){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy3D) (cudaMemcpy3DParms const *) = (cudaError_t (*)(cudaMemcpy3DParms const *))dlsym(RTLD_NEXT, "cudaMemcpy3D");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy3D", kApiTypeRuntime);

    lretval = lcudaMemcpy3D(p);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy3DPeer(cudaMemcpy3DPeerParms const * p){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy3DPeer) (cudaMemcpy3DPeerParms const *) = (cudaError_t (*)(cudaMemcpy3DPeerParms const *))dlsym(RTLD_NEXT, "cudaMemcpy3DPeer");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy3DPeer", kApiTypeRuntime);

    lretval = lcudaMemcpy3DPeer(p);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy3DAsync(cudaMemcpy3DParms const * p, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy3DAsync) (cudaMemcpy3DParms const *, cudaStream_t) = (cudaError_t (*)(cudaMemcpy3DParms const *, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy3DAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy3DAsync", kApiTypeRuntime);

    lretval = lcudaMemcpy3DAsync(p, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy3DPeerAsync(cudaMemcpy3DPeerParms const * p, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy3DPeerAsync) (cudaMemcpy3DPeerParms const *, cudaStream_t) = (cudaError_t (*)(cudaMemcpy3DPeerParms const *, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy3DPeerAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy3DPeerAsync", kApiTypeRuntime);

    lretval = lcudaMemcpy3DPeerAsync(p, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemGetInfo(size_t * free, size_t * total){
    cudaError_t lretval;
    cudaError_t (*lcudaMemGetInfo) (size_t *, size_t *) = (cudaError_t (*)(size_t *, size_t *))dlsym(RTLD_NEXT, "cudaMemGetInfo");

    /* pre exeuction logics */
    ac.add_counter("cudaMemGetInfo", kApiTypeRuntime);

    lretval = lcudaMemGetInfo(free, total);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaArrayGetInfo(cudaChannelFormatDesc * desc, cudaExtent * extent, unsigned int * flags, cudaArray_t array){
    cudaError_t lretval;
    cudaError_t (*lcudaArrayGetInfo) (cudaChannelFormatDesc *, cudaExtent *, unsigned int *, cudaArray_t) = (cudaError_t (*)(cudaChannelFormatDesc *, cudaExtent *, unsigned int *, cudaArray_t))dlsym(RTLD_NEXT, "cudaArrayGetInfo");

    /* pre exeuction logics */
    ac.add_counter("cudaArrayGetInfo", kApiTypeRuntime);

    lretval = lcudaArrayGetInfo(desc, extent, flags, array);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaArrayGetPlane(cudaArray_t * pPlaneArray, cudaArray_t hArray, unsigned int planeIdx){
    cudaError_t lretval;
    cudaError_t (*lcudaArrayGetPlane) (cudaArray_t *, cudaArray_t, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaArray_t, unsigned int))dlsym(RTLD_NEXT, "cudaArrayGetPlane");

    /* pre exeuction logics */
    ac.add_counter("cudaArrayGetPlane", kApiTypeRuntime);

    lretval = lcudaArrayGetPlane(pPlaneArray, hArray, planeIdx);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaArray_t array){
    cudaError_t lretval;
    cudaError_t (*lcudaArrayGetSparseProperties) (cudaArraySparseProperties *, cudaArray_t) = (cudaError_t (*)(cudaArraySparseProperties *, cudaArray_t))dlsym(RTLD_NEXT, "cudaArrayGetSparseProperties");

    /* pre exeuction logics */
    ac.add_counter("cudaArrayGetSparseProperties", kApiTypeRuntime);

    lretval = lcudaArrayGetSparseProperties(sparseProperties, array);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMipmappedArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaMipmappedArray_t mipmap){
    cudaError_t lretval;
    cudaError_t (*lcudaMipmappedArrayGetSparseProperties) (cudaArraySparseProperties *, cudaMipmappedArray_t) = (cudaError_t (*)(cudaArraySparseProperties *, cudaMipmappedArray_t))dlsym(RTLD_NEXT, "cudaMipmappedArrayGetSparseProperties");

    /* pre exeuction logics */
    ac.add_counter("cudaMipmappedArrayGetSparseProperties", kApiTypeRuntime);

    lretval = lcudaMipmappedArrayGetSparseProperties(sparseProperties, mipmap);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy(void * dst, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy) (void *, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy", kApiTypeRuntime);

    lretval = lcudaMemcpy(dst, src, count, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyPeer(void * dst, int dstDevice, void const * src, int srcDevice, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyPeer) (void *, int, void const *, int, size_t) = (cudaError_t (*)(void *, int, void const *, int, size_t))dlsym(RTLD_NEXT, "cudaMemcpyPeer");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyPeer", kApiTypeRuntime);

    lretval = lcudaMemcpyPeer(dst, dstDevice, src, srcDevice, count);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy2D(void * dst, size_t dpitch, void const * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2D) (void *, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy2D");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy2D", kApiTypeRuntime);

    lretval = lcudaMemcpy2D(dst, dpitch, src, spitch, width, height, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy2DToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, void const * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DToArray) (cudaArray_t, size_t, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaArray_t, size_t, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy2DToArray");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy2DToArray", kApiTypeRuntime);

    lretval = lcudaMemcpy2DToArray(dst, wOffset, hOffset, src, spitch, width, height, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy2DFromArray(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DFromArray) (void *, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy2DFromArray");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy2DFromArray", kApiTypeRuntime);

    lretval = lcudaMemcpy2DFromArray(dst, dpitch, src, wOffset, hOffset, width, height, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy2DArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DArrayToArray) (cudaArray_t, size_t, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaArray_t, size_t, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy2DArrayToArray");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy2DArrayToArray", kApiTypeRuntime);

    lretval = lcudaMemcpy2DArrayToArray(dst, wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc, width, height, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyToSymbol(void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyToSymbol) (void const *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void const *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyToSymbol");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyToSymbol", kApiTypeRuntime);

    lretval = lcudaMemcpyToSymbol(symbol, src, count, offset, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyFromSymbol(void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyFromSymbol) (void *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyFromSymbol");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyFromSymbol", kApiTypeRuntime);

    lretval = lcudaMemcpyFromSymbol(dst, symbol, count, offset, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyAsync(void * dst, void const * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyAsync) (void *, void const *, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, void const *, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyAsync", kApiTypeRuntime);

    lretval = lcudaMemcpyAsync(dst, src, count, kind, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyPeerAsync(void * dst, int dstDevice, void const * src, int srcDevice, size_t count, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyPeerAsync) (void *, int, void const *, int, size_t, cudaStream_t) = (cudaError_t (*)(void *, int, void const *, int, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyPeerAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyPeerAsync", kApiTypeRuntime);

    lretval = lcudaMemcpyPeerAsync(dst, dstDevice, src, srcDevice, count, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy2DAsync(void * dst, size_t dpitch, void const * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DAsync) (void *, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy2DAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy2DAsync", kApiTypeRuntime);

    lretval = lcudaMemcpy2DAsync(dst, dpitch, src, spitch, width, height, kind, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy2DToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, void const * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DToArrayAsync) (cudaArray_t, size_t, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(cudaArray_t, size_t, size_t, void const *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy2DToArrayAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy2DToArrayAsync", kApiTypeRuntime);

    lretval = lcudaMemcpy2DToArrayAsync(dst, wOffset, hOffset, src, spitch, width, height, kind, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpy2DFromArrayAsync(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy2DFromArrayAsync) (void *, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, size_t, cudaArray_const_t, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpy2DFromArrayAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpy2DFromArrayAsync", kApiTypeRuntime);

    lretval = lcudaMemcpy2DFromArrayAsync(dst, dpitch, src, wOffset, hOffset, width, height, kind, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyToSymbolAsync(void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyToSymbolAsync) (void const *, void const *, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void const *, void const *, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyToSymbolAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyToSymbolAsync", kApiTypeRuntime);

    lretval = lcudaMemcpyToSymbolAsync(symbol, src, count, offset, kind, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyFromSymbolAsync(void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyFromSymbolAsync) (void *, void const *, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, void const *, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyFromSymbolAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyFromSymbolAsync", kApiTypeRuntime);

    lretval = lcudaMemcpyFromSymbolAsync(dst, symbol, count, offset, kind, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemset(void * devPtr, int value, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset) (void *, int, size_t) = (cudaError_t (*)(void *, int, size_t))dlsym(RTLD_NEXT, "cudaMemset");

    /* pre exeuction logics */
    ac.add_counter("cudaMemset", kApiTypeRuntime);

    lretval = lcudaMemset(devPtr, value, count);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemset2D(void * devPtr, size_t pitch, int value, size_t width, size_t height){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset2D) (void *, size_t, int, size_t, size_t) = (cudaError_t (*)(void *, size_t, int, size_t, size_t))dlsym(RTLD_NEXT, "cudaMemset2D");

    /* pre exeuction logics */
    ac.add_counter("cudaMemset2D", kApiTypeRuntime);

    lretval = lcudaMemset2D(devPtr, pitch, value, width, height);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemset3D(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset3D) (cudaPitchedPtr, int, cudaExtent) = (cudaError_t (*)(cudaPitchedPtr, int, cudaExtent))dlsym(RTLD_NEXT, "cudaMemset3D");

    /* pre exeuction logics */
    ac.add_counter("cudaMemset3D", kApiTypeRuntime);

    lretval = lcudaMemset3D(pitchedDevPtr, value, extent);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemsetAsync) (void *, int, size_t, cudaStream_t) = (cudaError_t (*)(void *, int, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemsetAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemsetAsync", kApiTypeRuntime);

    lretval = lcudaMemsetAsync(devPtr, value, count, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemset2DAsync(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset2DAsync) (void *, size_t, int, size_t, size_t, cudaStream_t) = (cudaError_t (*)(void *, size_t, int, size_t, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemset2DAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemset2DAsync", kApiTypeRuntime);

    lretval = lcudaMemset2DAsync(devPtr, pitch, value, width, height, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemset3DAsync) (cudaPitchedPtr, int, cudaExtent, cudaStream_t) = (cudaError_t (*)(cudaPitchedPtr, int, cudaExtent, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemset3DAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemset3DAsync", kApiTypeRuntime);

    lretval = lcudaMemset3DAsync(pitchedDevPtr, value, extent, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetSymbolAddress(void * * devPtr, void const * symbol){
    cudaError_t lretval;
    cudaError_t (*lcudaGetSymbolAddress) (void * *, void const *) = (cudaError_t (*)(void * *, void const *))dlsym(RTLD_NEXT, "cudaGetSymbolAddress");

    /* pre exeuction logics */
    ac.add_counter("cudaGetSymbolAddress", kApiTypeRuntime);

    lretval = lcudaGetSymbolAddress(devPtr, symbol);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetSymbolSize(size_t * size, void const * symbol){
    cudaError_t lretval;
    cudaError_t (*lcudaGetSymbolSize) (size_t *, void const *) = (cudaError_t (*)(size_t *, void const *))dlsym(RTLD_NEXT, "cudaGetSymbolSize");

    /* pre exeuction logics */
    ac.add_counter("cudaGetSymbolSize", kApiTypeRuntime);

    lretval = lcudaGetSymbolSize(size, symbol);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPrefetchAsync(void const * devPtr, size_t count, int dstDevice, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPrefetchAsync) (void const *, size_t, int, cudaStream_t) = (cudaError_t (*)(void const *, size_t, int, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemPrefetchAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPrefetchAsync", kApiTypeRuntime);

    lretval = lcudaMemPrefetchAsync(devPtr, count, dstDevice, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemAdvise(void const * devPtr, size_t count, cudaMemoryAdvise advice, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaMemAdvise) (void const *, size_t, cudaMemoryAdvise, int) = (cudaError_t (*)(void const *, size_t, cudaMemoryAdvise, int))dlsym(RTLD_NEXT, "cudaMemAdvise");

    /* pre exeuction logics */
    ac.add_counter("cudaMemAdvise", kApiTypeRuntime);

    lretval = lcudaMemAdvise(devPtr, count, advice, device);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemRangeGetAttribute(void * data, size_t dataSize, cudaMemRangeAttribute attribute, void const * devPtr, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemRangeGetAttribute) (void *, size_t, cudaMemRangeAttribute, void const *, size_t) = (cudaError_t (*)(void *, size_t, cudaMemRangeAttribute, void const *, size_t))dlsym(RTLD_NEXT, "cudaMemRangeGetAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaMemRangeGetAttribute", kApiTypeRuntime);

    lretval = lcudaMemRangeGetAttribute(data, dataSize, attribute, devPtr, count);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemRangeGetAttributes(void * * data, size_t * dataSizes, cudaMemRangeAttribute * attributes, size_t numAttributes, void const * devPtr, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemRangeGetAttributes) (void * *, size_t *, cudaMemRangeAttribute *, size_t, void const *, size_t) = (cudaError_t (*)(void * *, size_t *, cudaMemRangeAttribute *, size_t, void const *, size_t))dlsym(RTLD_NEXT, "cudaMemRangeGetAttributes");

    /* pre exeuction logics */
    ac.add_counter("cudaMemRangeGetAttributes", kApiTypeRuntime);

    lretval = lcudaMemRangeGetAttributes(data, dataSizes, attributes, numAttributes, devPtr, count);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyToArray) (cudaArray_t, size_t, size_t, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaArray_t, size_t, size_t, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyToArray");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyToArray", kApiTypeRuntime);

    lretval = lcudaMemcpyToArray(dst, wOffset, hOffset, src, count, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyFromArray(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyFromArray) (void *, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyFromArray");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyFromArray", kApiTypeRuntime);

    lretval = lcudaMemcpyFromArray(dst, src, wOffset, hOffset, count, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyArrayToArray) (cudaArray_t, size_t, size_t, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaArray_t, size_t, size_t, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpyArrayToArray");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyArrayToArray", kApiTypeRuntime);

    lretval = lcudaMemcpyArrayToArray(dst, wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc, count, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, void const * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyToArrayAsync) (cudaArray_t, size_t, size_t, void const *, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(cudaArray_t, size_t, size_t, void const *, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyToArrayAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyToArrayAsync", kApiTypeRuntime);

    lretval = lcudaMemcpyToArrayAsync(dst, wOffset, hOffset, src, count, kind, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemcpyFromArrayAsync(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpyFromArrayAsync) (void *, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, cudaArray_const_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyFromArrayAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMemcpyFromArrayAsync", kApiTypeRuntime);

    lretval = lcudaMemcpyFromArrayAsync(dst, src, wOffset, hOffset, count, kind, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMallocAsync(void * * devPtr, size_t size, cudaStream_t hStream){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocAsync) (void * *, size_t, cudaStream_t) = (cudaError_t (*)(void * *, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMallocAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMallocAsync", kApiTypeRuntime);

    lretval = lcudaMallocAsync(devPtr, size, hStream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaFreeAsync(void * devPtr, cudaStream_t hStream){
    cudaError_t lretval;
    cudaError_t (*lcudaFreeAsync) (void *, cudaStream_t) = (cudaError_t (*)(void *, cudaStream_t))dlsym(RTLD_NEXT, "cudaFreeAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaFreeAsync", kApiTypeRuntime);

    lretval = lcudaFreeAsync(devPtr, hStream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolTrimTo(cudaMemPool_t memPool, size_t minBytesToKeep){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolTrimTo) (cudaMemPool_t, size_t) = (cudaError_t (*)(cudaMemPool_t, size_t))dlsym(RTLD_NEXT, "cudaMemPoolTrimTo");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolTrimTo", kApiTypeRuntime);

    lretval = lcudaMemPoolTrimTo(memPool, minBytesToKeep);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolSetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolSetAttribute) (cudaMemPool_t, cudaMemPoolAttr, void *) = (cudaError_t (*)(cudaMemPool_t, cudaMemPoolAttr, void *))dlsym(RTLD_NEXT, "cudaMemPoolSetAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolSetAttribute", kApiTypeRuntime);

    lretval = lcudaMemPoolSetAttribute(memPool, attr, value);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolGetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolGetAttribute) (cudaMemPool_t, cudaMemPoolAttr, void *) = (cudaError_t (*)(cudaMemPool_t, cudaMemPoolAttr, void *))dlsym(RTLD_NEXT, "cudaMemPoolGetAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolGetAttribute", kApiTypeRuntime);

    lretval = lcudaMemPoolGetAttribute(memPool, attr, value);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolSetAccess(cudaMemPool_t memPool, cudaMemAccessDesc const * descList, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolSetAccess) (cudaMemPool_t, cudaMemAccessDesc const *, size_t) = (cudaError_t (*)(cudaMemPool_t, cudaMemAccessDesc const *, size_t))dlsym(RTLD_NEXT, "cudaMemPoolSetAccess");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolSetAccess", kApiTypeRuntime);

    lretval = lcudaMemPoolSetAccess(memPool, descList, count);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolGetAccess(cudaMemAccessFlags * flags, cudaMemPool_t memPool, cudaMemLocation * location){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolGetAccess) (cudaMemAccessFlags *, cudaMemPool_t, cudaMemLocation *) = (cudaError_t (*)(cudaMemAccessFlags *, cudaMemPool_t, cudaMemLocation *))dlsym(RTLD_NEXT, "cudaMemPoolGetAccess");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolGetAccess", kApiTypeRuntime);

    lretval = lcudaMemPoolGetAccess(flags, memPool, location);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolCreate(cudaMemPool_t * memPool, cudaMemPoolProps const * poolProps){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolCreate) (cudaMemPool_t *, cudaMemPoolProps const *) = (cudaError_t (*)(cudaMemPool_t *, cudaMemPoolProps const *))dlsym(RTLD_NEXT, "cudaMemPoolCreate");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolCreate", kApiTypeRuntime);

    lretval = lcudaMemPoolCreate(memPool, poolProps);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolDestroy(cudaMemPool_t memPool){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolDestroy) (cudaMemPool_t) = (cudaError_t (*)(cudaMemPool_t))dlsym(RTLD_NEXT, "cudaMemPoolDestroy");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolDestroy", kApiTypeRuntime);

    lretval = lcudaMemPoolDestroy(memPool);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMallocFromPoolAsync(void * * ptr, size_t size, cudaMemPool_t memPool, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocFromPoolAsync) (void * *, size_t, cudaMemPool_t, cudaStream_t) = (cudaError_t (*)(void * *, size_t, cudaMemPool_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMallocFromPoolAsync");

    /* pre exeuction logics */
    ac.add_counter("cudaMallocFromPoolAsync", kApiTypeRuntime);

    lretval = lcudaMallocFromPoolAsync(ptr, size, memPool, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolExportToShareableHandle(void * shareableHandle, cudaMemPool_t memPool, cudaMemAllocationHandleType handleType, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolExportToShareableHandle) (void *, cudaMemPool_t, cudaMemAllocationHandleType, unsigned int) = (cudaError_t (*)(void *, cudaMemPool_t, cudaMemAllocationHandleType, unsigned int))dlsym(RTLD_NEXT, "cudaMemPoolExportToShareableHandle");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolExportToShareableHandle", kApiTypeRuntime);

    lretval = lcudaMemPoolExportToShareableHandle(shareableHandle, memPool, handleType, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolImportFromShareableHandle(cudaMemPool_t * memPool, void * shareableHandle, cudaMemAllocationHandleType handleType, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolImportFromShareableHandle) (cudaMemPool_t *, void *, cudaMemAllocationHandleType, unsigned int) = (cudaError_t (*)(cudaMemPool_t *, void *, cudaMemAllocationHandleType, unsigned int))dlsym(RTLD_NEXT, "cudaMemPoolImportFromShareableHandle");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolImportFromShareableHandle", kApiTypeRuntime);

    lretval = lcudaMemPoolImportFromShareableHandle(memPool, shareableHandle, handleType, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolExportPointer(cudaMemPoolPtrExportData * exportData, void * ptr){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolExportPointer) (cudaMemPoolPtrExportData *, void *) = (cudaError_t (*)(cudaMemPoolPtrExportData *, void *))dlsym(RTLD_NEXT, "cudaMemPoolExportPointer");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolExportPointer", kApiTypeRuntime);

    lretval = lcudaMemPoolExportPointer(exportData, ptr);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaMemPoolImportPointer(void * * ptr, cudaMemPool_t memPool, cudaMemPoolPtrExportData * exportData){
    cudaError_t lretval;
    cudaError_t (*lcudaMemPoolImportPointer) (void * *, cudaMemPool_t, cudaMemPoolPtrExportData *) = (cudaError_t (*)(void * *, cudaMemPool_t, cudaMemPoolPtrExportData *))dlsym(RTLD_NEXT, "cudaMemPoolImportPointer");

    /* pre exeuction logics */
    ac.add_counter("cudaMemPoolImportPointer", kApiTypeRuntime);

    lretval = lcudaMemPoolImportPointer(ptr, memPool, exportData);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaPointerGetAttributes(cudaPointerAttributes * attributes, void const * ptr){
    cudaError_t lretval;
    cudaError_t (*lcudaPointerGetAttributes) (cudaPointerAttributes *, void const *) = (cudaError_t (*)(cudaPointerAttributes *, void const *))dlsym(RTLD_NEXT, "cudaPointerGetAttributes");

    /* pre exeuction logics */
    ac.add_counter("cudaPointerGetAttributes", kApiTypeRuntime);

    lretval = lcudaPointerGetAttributes(attributes, ptr);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceCanAccessPeer(int * canAccessPeer, int device, int peerDevice){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceCanAccessPeer) (int *, int, int) = (cudaError_t (*)(int *, int, int))dlsym(RTLD_NEXT, "cudaDeviceCanAccessPeer");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceCanAccessPeer", kApiTypeRuntime);

    lretval = lcudaDeviceCanAccessPeer(canAccessPeer, device, peerDevice);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceEnablePeerAccess(int peerDevice, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceEnablePeerAccess) (int, unsigned int) = (cudaError_t (*)(int, unsigned int))dlsym(RTLD_NEXT, "cudaDeviceEnablePeerAccess");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceEnablePeerAccess", kApiTypeRuntime);

    lretval = lcudaDeviceEnablePeerAccess(peerDevice, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDeviceDisablePeerAccess(int peerDevice){
    cudaError_t lretval;
    cudaError_t (*lcudaDeviceDisablePeerAccess) (int) = (cudaError_t (*)(int))dlsym(RTLD_NEXT, "cudaDeviceDisablePeerAccess");

    /* pre exeuction logics */
    ac.add_counter("cudaDeviceDisablePeerAccess", kApiTypeRuntime);

    lretval = lcudaDeviceDisablePeerAccess(peerDevice);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource_t resource){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsUnregisterResource) (cudaGraphicsResource_t) = (cudaError_t (*)(cudaGraphicsResource_t))dlsym(RTLD_NEXT, "cudaGraphicsUnregisterResource");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphicsUnregisterResource", kApiTypeRuntime);

    lretval = lcudaGraphicsUnregisterResource(resource);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t resource, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsResourceSetMapFlags) (cudaGraphicsResource_t, unsigned int) = (cudaError_t (*)(cudaGraphicsResource_t, unsigned int))dlsym(RTLD_NEXT, "cudaGraphicsResourceSetMapFlags");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphicsResourceSetMapFlags", kApiTypeRuntime);

    lretval = lcudaGraphicsResourceSetMapFlags(resource, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphicsMapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsMapResources) (int, cudaGraphicsResource_t *, cudaStream_t) = (cudaError_t (*)(int, cudaGraphicsResource_t *, cudaStream_t))dlsym(RTLD_NEXT, "cudaGraphicsMapResources");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphicsMapResources", kApiTypeRuntime);

    lretval = lcudaGraphicsMapResources(count, resources, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphicsUnmapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsUnmapResources) (int, cudaGraphicsResource_t *, cudaStream_t) = (cudaError_t (*)(int, cudaGraphicsResource_t *, cudaStream_t))dlsym(RTLD_NEXT, "cudaGraphicsUnmapResources");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphicsUnmapResources", kApiTypeRuntime);

    lretval = lcudaGraphicsUnmapResources(count, resources, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphicsResourceGetMappedPointer(void * * devPtr, size_t * size, cudaGraphicsResource_t resource){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsResourceGetMappedPointer) (void * *, size_t *, cudaGraphicsResource_t) = (cudaError_t (*)(void * *, size_t *, cudaGraphicsResource_t))dlsym(RTLD_NEXT, "cudaGraphicsResourceGetMappedPointer");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphicsResourceGetMappedPointer", kApiTypeRuntime);

    lretval = lcudaGraphicsResourceGetMappedPointer(devPtr, size, resource);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray_t * array, cudaGraphicsResource_t resource, unsigned int arrayIndex, unsigned int mipLevel){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsSubResourceGetMappedArray) (cudaArray_t *, cudaGraphicsResource_t, unsigned int, unsigned int) = (cudaError_t (*)(cudaArray_t *, cudaGraphicsResource_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaGraphicsSubResourceGetMappedArray");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphicsSubResourceGetMappedArray", kApiTypeRuntime);

    lretval = lcudaGraphicsSubResourceGetMappedArray(array, resource, arrayIndex, mipLevel);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphicsResourceGetMappedMipmappedArray(cudaMipmappedArray_t * mipmappedArray, cudaGraphicsResource_t resource){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphicsResourceGetMappedMipmappedArray) (cudaMipmappedArray_t *, cudaGraphicsResource_t) = (cudaError_t (*)(cudaMipmappedArray_t *, cudaGraphicsResource_t))dlsym(RTLD_NEXT, "cudaGraphicsResourceGetMappedMipmappedArray");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphicsResourceGetMappedMipmappedArray", kApiTypeRuntime);

    lretval = lcudaGraphicsResourceGetMappedMipmappedArray(mipmappedArray, resource);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaBindTexture(size_t * offset, textureReference const * texref, void const * devPtr, cudaChannelFormatDesc const * desc, size_t size){
    cudaError_t lretval;
    cudaError_t (*lcudaBindTexture) (size_t *, textureReference const *, void const *, cudaChannelFormatDesc const *, size_t) = (cudaError_t (*)(size_t *, textureReference const *, void const *, cudaChannelFormatDesc const *, size_t))dlsym(RTLD_NEXT, "cudaBindTexture");

    /* pre exeuction logics */
    ac.add_counter("cudaBindTexture", kApiTypeRuntime);

    lretval = lcudaBindTexture(offset, texref, devPtr, desc, size);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaBindTexture2D(size_t * offset, textureReference const * texref, void const * devPtr, cudaChannelFormatDesc const * desc, size_t width, size_t height, size_t pitch){
    cudaError_t lretval;
    cudaError_t (*lcudaBindTexture2D) (size_t *, textureReference const *, void const *, cudaChannelFormatDesc const *, size_t, size_t, size_t) = (cudaError_t (*)(size_t *, textureReference const *, void const *, cudaChannelFormatDesc const *, size_t, size_t, size_t))dlsym(RTLD_NEXT, "cudaBindTexture2D");

    /* pre exeuction logics */
    ac.add_counter("cudaBindTexture2D", kApiTypeRuntime);

    lretval = lcudaBindTexture2D(offset, texref, devPtr, desc, width, height, pitch);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaBindTextureToArray(textureReference const * texref, cudaArray_const_t array, cudaChannelFormatDesc const * desc){
    cudaError_t lretval;
    cudaError_t (*lcudaBindTextureToArray) (textureReference const *, cudaArray_const_t, cudaChannelFormatDesc const *) = (cudaError_t (*)(textureReference const *, cudaArray_const_t, cudaChannelFormatDesc const *))dlsym(RTLD_NEXT, "cudaBindTextureToArray");

    /* pre exeuction logics */
    ac.add_counter("cudaBindTextureToArray", kApiTypeRuntime);

    lretval = lcudaBindTextureToArray(texref, array, desc);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaBindTextureToMipmappedArray(textureReference const * texref, cudaMipmappedArray_const_t mipmappedArray, cudaChannelFormatDesc const * desc){
    cudaError_t lretval;
    cudaError_t (*lcudaBindTextureToMipmappedArray) (textureReference const *, cudaMipmappedArray_const_t, cudaChannelFormatDesc const *) = (cudaError_t (*)(textureReference const *, cudaMipmappedArray_const_t, cudaChannelFormatDesc const *))dlsym(RTLD_NEXT, "cudaBindTextureToMipmappedArray");

    /* pre exeuction logics */
    ac.add_counter("cudaBindTextureToMipmappedArray", kApiTypeRuntime);

    lretval = lcudaBindTextureToMipmappedArray(texref, mipmappedArray, desc);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaUnbindTexture(textureReference const * texref){
    cudaError_t lretval;
    cudaError_t (*lcudaUnbindTexture) (textureReference const *) = (cudaError_t (*)(textureReference const *))dlsym(RTLD_NEXT, "cudaUnbindTexture");

    /* pre exeuction logics */
    ac.add_counter("cudaUnbindTexture", kApiTypeRuntime);

    lretval = lcudaUnbindTexture(texref);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetTextureAlignmentOffset(size_t * offset, textureReference const * texref){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureAlignmentOffset) (size_t *, textureReference const *) = (cudaError_t (*)(size_t *, textureReference const *))dlsym(RTLD_NEXT, "cudaGetTextureAlignmentOffset");

    /* pre exeuction logics */
    ac.add_counter("cudaGetTextureAlignmentOffset", kApiTypeRuntime);

    lretval = lcudaGetTextureAlignmentOffset(offset, texref);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetTextureReference(textureReference const * * texref, void const * symbol){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureReference) (textureReference const * *, void const *) = (cudaError_t (*)(textureReference const * *, void const *))dlsym(RTLD_NEXT, "cudaGetTextureReference");

    /* pre exeuction logics */
    ac.add_counter("cudaGetTextureReference", kApiTypeRuntime);

    lretval = lcudaGetTextureReference(texref, symbol);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaBindSurfaceToArray(surfaceReference const * surfref, cudaArray_const_t array, cudaChannelFormatDesc const * desc){
    cudaError_t lretval;
    cudaError_t (*lcudaBindSurfaceToArray) (surfaceReference const *, cudaArray_const_t, cudaChannelFormatDesc const *) = (cudaError_t (*)(surfaceReference const *, cudaArray_const_t, cudaChannelFormatDesc const *))dlsym(RTLD_NEXT, "cudaBindSurfaceToArray");

    /* pre exeuction logics */
    ac.add_counter("cudaBindSurfaceToArray", kApiTypeRuntime);

    lretval = lcudaBindSurfaceToArray(surfref, array, desc);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetSurfaceReference(surfaceReference const * * surfref, void const * symbol){
    cudaError_t lretval;
    cudaError_t (*lcudaGetSurfaceReference) (surfaceReference const * *, void const *) = (cudaError_t (*)(surfaceReference const * *, void const *))dlsym(RTLD_NEXT, "cudaGetSurfaceReference");

    /* pre exeuction logics */
    ac.add_counter("cudaGetSurfaceReference", kApiTypeRuntime);

    lretval = lcudaGetSurfaceReference(surfref, symbol);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc * desc, cudaArray_const_t array){
    cudaError_t lretval;
    cudaError_t (*lcudaGetChannelDesc) (cudaChannelFormatDesc *, cudaArray_const_t) = (cudaError_t (*)(cudaChannelFormatDesc *, cudaArray_const_t))dlsym(RTLD_NEXT, "cudaGetChannelDesc");

    /* pre exeuction logics */
    ac.add_counter("cudaGetChannelDesc", kApiTypeRuntime);

    lretval = lcudaGetChannelDesc(desc, array);
    
    /* post exeuction logics */

    return lretval;
}


cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w, cudaChannelFormatKind f){
    cudaChannelFormatDesc lretval;
    cudaChannelFormatDesc (*lcudaCreateChannelDesc) (int, int, int, int, cudaChannelFormatKind) = (cudaChannelFormatDesc (*)(int, int, int, int, cudaChannelFormatKind))dlsym(RTLD_NEXT, "cudaCreateChannelDesc");

    /* pre exeuction logics */
    ac.add_counter("cudaCreateChannelDesc", kApiTypeRuntime);

    lretval = lcudaCreateChannelDesc(x, y, z, w, f);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaCreateTextureObject(cudaTextureObject_t * pTexObject, cudaResourceDesc const * pResDesc, cudaTextureDesc const * pTexDesc, cudaResourceViewDesc const * pResViewDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaCreateTextureObject) (cudaTextureObject_t *, cudaResourceDesc const *, cudaTextureDesc const *, cudaResourceViewDesc const *) = (cudaError_t (*)(cudaTextureObject_t *, cudaResourceDesc const *, cudaTextureDesc const *, cudaResourceViewDesc const *))dlsym(RTLD_NEXT, "cudaCreateTextureObject");

    /* pre exeuction logics */
    ac.add_counter("cudaCreateTextureObject", kApiTypeRuntime);

    lretval = lcudaCreateTextureObject(pTexObject, pResDesc, pTexDesc, pResViewDesc);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDestroyTextureObject(cudaTextureObject_t texObject){
    cudaError_t lretval;
    cudaError_t (*lcudaDestroyTextureObject) (cudaTextureObject_t) = (cudaError_t (*)(cudaTextureObject_t))dlsym(RTLD_NEXT, "cudaDestroyTextureObject");

    /* pre exeuction logics */
    ac.add_counter("cudaDestroyTextureObject", kApiTypeRuntime);

    lretval = lcudaDestroyTextureObject(texObject);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetTextureObjectResourceDesc(cudaResourceDesc * pResDesc, cudaTextureObject_t texObject){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureObjectResourceDesc) (cudaResourceDesc *, cudaTextureObject_t) = (cudaError_t (*)(cudaResourceDesc *, cudaTextureObject_t))dlsym(RTLD_NEXT, "cudaGetTextureObjectResourceDesc");

    /* pre exeuction logics */
    ac.add_counter("cudaGetTextureObjectResourceDesc", kApiTypeRuntime);

    lretval = lcudaGetTextureObjectResourceDesc(pResDesc, texObject);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetTextureObjectTextureDesc(cudaTextureDesc * pTexDesc, cudaTextureObject_t texObject){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureObjectTextureDesc) (cudaTextureDesc *, cudaTextureObject_t) = (cudaError_t (*)(cudaTextureDesc *, cudaTextureObject_t))dlsym(RTLD_NEXT, "cudaGetTextureObjectTextureDesc");

    /* pre exeuction logics */
    ac.add_counter("cudaGetTextureObjectTextureDesc", kApiTypeRuntime);

    lretval = lcudaGetTextureObjectTextureDesc(pTexDesc, texObject);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetTextureObjectResourceViewDesc(cudaResourceViewDesc * pResViewDesc, cudaTextureObject_t texObject){
    cudaError_t lretval;
    cudaError_t (*lcudaGetTextureObjectResourceViewDesc) (cudaResourceViewDesc *, cudaTextureObject_t) = (cudaError_t (*)(cudaResourceViewDesc *, cudaTextureObject_t))dlsym(RTLD_NEXT, "cudaGetTextureObjectResourceViewDesc");

    /* pre exeuction logics */
    ac.add_counter("cudaGetTextureObjectResourceViewDesc", kApiTypeRuntime);

    lretval = lcudaGetTextureObjectResourceViewDesc(pResViewDesc, texObject);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaCreateSurfaceObject(cudaSurfaceObject_t * pSurfObject, cudaResourceDesc const * pResDesc){
    cudaError_t lretval;
    cudaError_t (*lcudaCreateSurfaceObject) (cudaSurfaceObject_t *, cudaResourceDesc const *) = (cudaError_t (*)(cudaSurfaceObject_t *, cudaResourceDesc const *))dlsym(RTLD_NEXT, "cudaCreateSurfaceObject");

    /* pre exeuction logics */
    ac.add_counter("cudaCreateSurfaceObject", kApiTypeRuntime);

    lretval = lcudaCreateSurfaceObject(pSurfObject, pResDesc);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDestroySurfaceObject(cudaSurfaceObject_t surfObject){
    cudaError_t lretval;
    cudaError_t (*lcudaDestroySurfaceObject) (cudaSurfaceObject_t) = (cudaError_t (*)(cudaSurfaceObject_t))dlsym(RTLD_NEXT, "cudaDestroySurfaceObject");

    /* pre exeuction logics */
    ac.add_counter("cudaDestroySurfaceObject", kApiTypeRuntime);

    lretval = lcudaDestroySurfaceObject(surfObject);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetSurfaceObjectResourceDesc(cudaResourceDesc * pResDesc, cudaSurfaceObject_t surfObject){
    cudaError_t lretval;
    cudaError_t (*lcudaGetSurfaceObjectResourceDesc) (cudaResourceDesc *, cudaSurfaceObject_t) = (cudaError_t (*)(cudaResourceDesc *, cudaSurfaceObject_t))dlsym(RTLD_NEXT, "cudaGetSurfaceObjectResourceDesc");

    /* pre exeuction logics */
    ac.add_counter("cudaGetSurfaceObjectResourceDesc", kApiTypeRuntime);

    lretval = lcudaGetSurfaceObjectResourceDesc(pResDesc, surfObject);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaDriverGetVersion(int * driverVersion){
    cudaError_t lretval;
    cudaError_t (*lcudaDriverGetVersion) (int *) = (cudaError_t (*)(int *))dlsym(RTLD_NEXT, "cudaDriverGetVersion");

    /* pre exeuction logics */
    ac.add_counter("cudaDriverGetVersion", kApiTypeRuntime);

    lretval = lcudaDriverGetVersion(driverVersion);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaRuntimeGetVersion(int * runtimeVersion){
    cudaError_t lretval;
    cudaError_t (*lcudaRuntimeGetVersion) (int *) = (cudaError_t (*)(int *))dlsym(RTLD_NEXT, "cudaRuntimeGetVersion");

    /* pre exeuction logics */
    ac.add_counter("cudaRuntimeGetVersion", kApiTypeRuntime);

    lretval = lcudaRuntimeGetVersion(runtimeVersion);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphCreate(cudaGraph_t * pGraph, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphCreate) (cudaGraph_t *, unsigned int) = (cudaError_t (*)(cudaGraph_t *, unsigned int))dlsym(RTLD_NEXT, "cudaGraphCreate");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphCreate", kApiTypeRuntime);

    lretval = lcudaGraphCreate(pGraph, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddKernelNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaKernelNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddKernelNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaKernelNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaKernelNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphAddKernelNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddKernelNode", kApiTypeRuntime);

    lretval = lcudaGraphAddKernelNode(pGraphNode, graph, pDependencies, numDependencies, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphKernelNodeGetParams(cudaGraphNode_t node, cudaKernelNodeParams * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeGetParams) (cudaGraphNode_t, cudaKernelNodeParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaKernelNodeParams *))dlsym(RTLD_NEXT, "cudaGraphKernelNodeGetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphKernelNodeGetParams", kApiTypeRuntime);

    lretval = lcudaGraphKernelNodeGetParams(node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphKernelNodeSetParams(cudaGraphNode_t node, cudaKernelNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeSetParams) (cudaGraphNode_t, cudaKernelNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaKernelNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphKernelNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphKernelNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphKernelNodeSetParams(node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphKernelNodeCopyAttributes(cudaGraphNode_t hSrc, cudaGraphNode_t hDst){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeCopyAttributes) (cudaGraphNode_t, cudaGraphNode_t) = (cudaError_t (*)(cudaGraphNode_t, cudaGraphNode_t))dlsym(RTLD_NEXT, "cudaGraphKernelNodeCopyAttributes");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphKernelNodeCopyAttributes", kApiTypeRuntime);

    lretval = lcudaGraphKernelNodeCopyAttributes(hSrc, hDst);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphKernelNodeGetAttribute(cudaGraphNode_t hNode, cudaKernelNodeAttrID attr, cudaKernelNodeAttrValue * value_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeGetAttribute) (cudaGraphNode_t, cudaKernelNodeAttrID, cudaKernelNodeAttrValue *) = (cudaError_t (*)(cudaGraphNode_t, cudaKernelNodeAttrID, cudaKernelNodeAttrValue *))dlsym(RTLD_NEXT, "cudaGraphKernelNodeGetAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphKernelNodeGetAttribute", kApiTypeRuntime);

    lretval = lcudaGraphKernelNodeGetAttribute(hNode, attr, value_out);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphKernelNodeSetAttribute(cudaGraphNode_t hNode, cudaKernelNodeAttrID attr, cudaKernelNodeAttrValue const * value){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphKernelNodeSetAttribute) (cudaGraphNode_t, cudaKernelNodeAttrID, cudaKernelNodeAttrValue const *) = (cudaError_t (*)(cudaGraphNode_t, cudaKernelNodeAttrID, cudaKernelNodeAttrValue const *))dlsym(RTLD_NEXT, "cudaGraphKernelNodeSetAttribute");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphKernelNodeSetAttribute", kApiTypeRuntime);

    lretval = lcudaGraphKernelNodeSetAttribute(hNode, attr, value);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddMemcpyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaMemcpy3DParms const * pCopyParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemcpyNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemcpy3DParms const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemcpy3DParms const *))dlsym(RTLD_NEXT, "cudaGraphAddMemcpyNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddMemcpyNode", kApiTypeRuntime);

    lretval = lcudaGraphAddMemcpyNode(pGraphNode, graph, pDependencies, numDependencies, pCopyParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddMemcpyNodeToSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemcpyNodeToSymbol) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void const *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void const *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphAddMemcpyNodeToSymbol");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddMemcpyNodeToSymbol", kApiTypeRuntime);

    lretval = lcudaGraphAddMemcpyNodeToSymbol(pGraphNode, graph, pDependencies, numDependencies, symbol, src, count, offset, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddMemcpyNodeFromSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemcpyNodeFromSymbol) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphAddMemcpyNodeFromSymbol");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddMemcpyNodeFromSymbol", kApiTypeRuntime);

    lretval = lcudaGraphAddMemcpyNodeFromSymbol(pGraphNode, graph, pDependencies, numDependencies, dst, symbol, count, offset, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddMemcpyNode1D(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, void * dst, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemcpyNode1D) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphAddMemcpyNode1D");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddMemcpyNode1D", kApiTypeRuntime);

    lretval = lcudaGraphAddMemcpyNode1D(pGraphNode, graph, pDependencies, numDependencies, dst, src, count, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeGetParams(cudaGraphNode_t node, cudaMemcpy3DParms * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeGetParams) (cudaGraphNode_t, cudaMemcpy3DParms *) = (cudaError_t (*)(cudaGraphNode_t, cudaMemcpy3DParms *))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeGetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphMemcpyNodeGetParams", kApiTypeRuntime);

    lretval = lcudaGraphMemcpyNodeGetParams(node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeSetParams(cudaGraphNode_t node, cudaMemcpy3DParms const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeSetParams) (cudaGraphNode_t, cudaMemcpy3DParms const *) = (cudaError_t (*)(cudaGraphNode_t, cudaMemcpy3DParms const *))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphMemcpyNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphMemcpyNodeSetParams(node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeSetParamsToSymbol(cudaGraphNode_t node, void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeSetParamsToSymbol) (cudaGraphNode_t, void const *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t, void const *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeSetParamsToSymbol");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphMemcpyNodeSetParamsToSymbol", kApiTypeRuntime);

    lretval = lcudaGraphMemcpyNodeSetParamsToSymbol(node, symbol, src, count, offset, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeSetParamsFromSymbol(cudaGraphNode_t node, void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeSetParamsFromSymbol) (cudaGraphNode_t, void *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t, void *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeSetParamsFromSymbol");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphMemcpyNodeSetParamsFromSymbol", kApiTypeRuntime);

    lretval = lcudaGraphMemcpyNodeSetParamsFromSymbol(node, dst, symbol, count, offset, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphMemcpyNodeSetParams1D(cudaGraphNode_t node, void * dst, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemcpyNodeSetParams1D) (cudaGraphNode_t, void *, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphNode_t, void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphMemcpyNodeSetParams1D");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphMemcpyNodeSetParams1D", kApiTypeRuntime);

    lretval = lcudaGraphMemcpyNodeSetParams1D(node, dst, src, count, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddMemsetNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaMemsetParams const * pMemsetParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddMemsetNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemsetParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaMemsetParams const *))dlsym(RTLD_NEXT, "cudaGraphAddMemsetNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddMemsetNode", kApiTypeRuntime);

    lretval = lcudaGraphAddMemsetNode(pGraphNode, graph, pDependencies, numDependencies, pMemsetParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphMemsetNodeGetParams(cudaGraphNode_t node, cudaMemsetParams * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemsetNodeGetParams) (cudaGraphNode_t, cudaMemsetParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaMemsetParams *))dlsym(RTLD_NEXT, "cudaGraphMemsetNodeGetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphMemsetNodeGetParams", kApiTypeRuntime);

    lretval = lcudaGraphMemsetNodeGetParams(node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphMemsetNodeSetParams(cudaGraphNode_t node, cudaMemsetParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphMemsetNodeSetParams) (cudaGraphNode_t, cudaMemsetParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaMemsetParams const *))dlsym(RTLD_NEXT, "cudaGraphMemsetNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphMemsetNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphMemsetNodeSetParams(node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddHostNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaHostNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddHostNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaHostNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaHostNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphAddHostNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddHostNode", kApiTypeRuntime);

    lretval = lcudaGraphAddHostNode(pGraphNode, graph, pDependencies, numDependencies, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphHostNodeGetParams(cudaGraphNode_t node, cudaHostNodeParams * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphHostNodeGetParams) (cudaGraphNode_t, cudaHostNodeParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaHostNodeParams *))dlsym(RTLD_NEXT, "cudaGraphHostNodeGetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphHostNodeGetParams", kApiTypeRuntime);

    lretval = lcudaGraphHostNodeGetParams(node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphHostNodeSetParams(cudaGraphNode_t node, cudaHostNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphHostNodeSetParams) (cudaGraphNode_t, cudaHostNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaHostNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphHostNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphHostNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphHostNodeSetParams(node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddChildGraphNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaGraph_t childGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddChildGraphNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaGraph_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphAddChildGraphNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddChildGraphNode", kApiTypeRuntime);

    lretval = lcudaGraphAddChildGraphNode(pGraphNode, graph, pDependencies, numDependencies, childGraph);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphChildGraphNodeGetGraph(cudaGraphNode_t node, cudaGraph_t * pGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphChildGraphNodeGetGraph) (cudaGraphNode_t, cudaGraph_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaGraph_t *))dlsym(RTLD_NEXT, "cudaGraphChildGraphNodeGetGraph");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphChildGraphNodeGetGraph", kApiTypeRuntime);

    lretval = lcudaGraphChildGraphNodeGetGraph(node, pGraph);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddEmptyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddEmptyNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t))dlsym(RTLD_NEXT, "cudaGraphAddEmptyNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddEmptyNode", kApiTypeRuntime);

    lretval = lcudaGraphAddEmptyNode(pGraphNode, graph, pDependencies, numDependencies);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddEventRecordNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddEventRecordNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphAddEventRecordNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddEventRecordNode", kApiTypeRuntime);

    lretval = lcudaGraphAddEventRecordNode(pGraphNode, graph, pDependencies, numDependencies, event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphEventRecordNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphEventRecordNodeGetEvent) (cudaGraphNode_t, cudaEvent_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaEvent_t *))dlsym(RTLD_NEXT, "cudaGraphEventRecordNodeGetEvent");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphEventRecordNodeGetEvent", kApiTypeRuntime);

    lretval = lcudaGraphEventRecordNodeGetEvent(node, event_out);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphEventRecordNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphEventRecordNodeSetEvent) (cudaGraphNode_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphNode_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphEventRecordNodeSetEvent");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphEventRecordNodeSetEvent", kApiTypeRuntime);

    lretval = lcudaGraphEventRecordNodeSetEvent(node, event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddEventWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddEventWaitNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphAddEventWaitNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddEventWaitNode", kApiTypeRuntime);

    lretval = lcudaGraphAddEventWaitNode(pGraphNode, graph, pDependencies, numDependencies, event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphEventWaitNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphEventWaitNodeGetEvent) (cudaGraphNode_t, cudaEvent_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaEvent_t *))dlsym(RTLD_NEXT, "cudaGraphEventWaitNodeGetEvent");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphEventWaitNodeGetEvent", kApiTypeRuntime);

    lretval = lcudaGraphEventWaitNodeGetEvent(node, event_out);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphEventWaitNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphEventWaitNodeSetEvent) (cudaGraphNode_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphNode_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphEventWaitNodeSetEvent");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphEventWaitNodeSetEvent", kApiTypeRuntime);

    lretval = lcudaGraphEventWaitNodeSetEvent(node, event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddExternalSemaphoresSignalNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaExternalSemaphoreSignalNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddExternalSemaphoresSignalNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaExternalSemaphoreSignalNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaExternalSemaphoreSignalNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphAddExternalSemaphoresSignalNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddExternalSemaphoresSignalNode", kApiTypeRuntime);

    lretval = lcudaGraphAddExternalSemaphoresSignalNode(pGraphNode, graph, pDependencies, numDependencies, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExternalSemaphoresSignalNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreSignalNodeParams * params_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExternalSemaphoresSignalNodeGetParams) (cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams *))dlsym(RTLD_NEXT, "cudaGraphExternalSemaphoresSignalNodeGetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExternalSemaphoresSignalNodeGetParams", kApiTypeRuntime);

    lretval = lcudaGraphExternalSemaphoresSignalNodeGetParams(hNode, params_out);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExternalSemaphoresSignalNodeSetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreSignalNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExternalSemaphoresSignalNodeSetParams) (cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExternalSemaphoresSignalNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExternalSemaphoresSignalNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphExternalSemaphoresSignalNodeSetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddExternalSemaphoresWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, cudaGraphNode_t const * pDependencies, size_t numDependencies, cudaExternalSemaphoreWaitNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddExternalSemaphoresWaitNode) (cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaExternalSemaphoreWaitNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraph_t, cudaGraphNode_t const *, size_t, cudaExternalSemaphoreWaitNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphAddExternalSemaphoresWaitNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddExternalSemaphoresWaitNode", kApiTypeRuntime);

    lretval = lcudaGraphAddExternalSemaphoresWaitNode(pGraphNode, graph, pDependencies, numDependencies, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExternalSemaphoresWaitNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreWaitNodeParams * params_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExternalSemaphoresWaitNodeGetParams) (cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams *) = (cudaError_t (*)(cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams *))dlsym(RTLD_NEXT, "cudaGraphExternalSemaphoresWaitNodeGetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExternalSemaphoresWaitNodeGetParams", kApiTypeRuntime);

    lretval = lcudaGraphExternalSemaphoresWaitNodeGetParams(hNode, params_out);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExternalSemaphoresWaitNodeSetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreWaitNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExternalSemaphoresWaitNodeSetParams) (cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams const *) = (cudaError_t (*)(cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExternalSemaphoresWaitNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExternalSemaphoresWaitNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphExternalSemaphoresWaitNodeSetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphClone(cudaGraph_t * pGraphClone, cudaGraph_t originalGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphClone) (cudaGraph_t *, cudaGraph_t) = (cudaError_t (*)(cudaGraph_t *, cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphClone");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphClone", kApiTypeRuntime);

    lretval = lcudaGraphClone(pGraphClone, originalGraph);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphNodeFindInClone(cudaGraphNode_t * pNode, cudaGraphNode_t originalNode, cudaGraph_t clonedGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphNodeFindInClone) (cudaGraphNode_t *, cudaGraphNode_t, cudaGraph_t) = (cudaError_t (*)(cudaGraphNode_t *, cudaGraphNode_t, cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphNodeFindInClone");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphNodeFindInClone", kApiTypeRuntime);

    lretval = lcudaGraphNodeFindInClone(pNode, originalNode, clonedGraph);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphNodeGetType(cudaGraphNode_t node, cudaGraphNodeType * pType){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphNodeGetType) (cudaGraphNode_t, cudaGraphNodeType *) = (cudaError_t (*)(cudaGraphNode_t, cudaGraphNodeType *))dlsym(RTLD_NEXT, "cudaGraphNodeGetType");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphNodeGetType", kApiTypeRuntime);

    lretval = lcudaGraphNodeGetType(node, pType);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphGetNodes(cudaGraph_t graph, cudaGraphNode_t * nodes, size_t * numNodes){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphGetNodes) (cudaGraph_t, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphGetNodes");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphGetNodes", kApiTypeRuntime);

    lretval = lcudaGraphGetNodes(graph, nodes, numNodes);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphGetRootNodes(cudaGraph_t graph, cudaGraphNode_t * pRootNodes, size_t * pNumRootNodes){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphGetRootNodes) (cudaGraph_t, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphGetRootNodes");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphGetRootNodes", kApiTypeRuntime);

    lretval = lcudaGraphGetRootNodes(graph, pRootNodes, pNumRootNodes);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphGetEdges(cudaGraph_t graph, cudaGraphNode_t * from, cudaGraphNode_t * to, size_t * numEdges){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphGetEdges) (cudaGraph_t, cudaGraphNode_t *, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t *, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphGetEdges");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphGetEdges", kApiTypeRuntime);

    lretval = lcudaGraphGetEdges(graph, from, to, numEdges);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphNodeGetDependencies(cudaGraphNode_t node, cudaGraphNode_t * pDependencies, size_t * pNumDependencies){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphNodeGetDependencies) (cudaGraphNode_t, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphNodeGetDependencies");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphNodeGetDependencies", kApiTypeRuntime);

    lretval = lcudaGraphNodeGetDependencies(node, pDependencies, pNumDependencies);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphNodeGetDependentNodes(cudaGraphNode_t node, cudaGraphNode_t * pDependentNodes, size_t * pNumDependentNodes){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphNodeGetDependentNodes) (cudaGraphNode_t, cudaGraphNode_t *, size_t *) = (cudaError_t (*)(cudaGraphNode_t, cudaGraphNode_t *, size_t *))dlsym(RTLD_NEXT, "cudaGraphNodeGetDependentNodes");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphNodeGetDependentNodes", kApiTypeRuntime);

    lretval = lcudaGraphNodeGetDependentNodes(node, pDependentNodes, pNumDependentNodes);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphAddDependencies(cudaGraph_t graph, cudaGraphNode_t const * from, cudaGraphNode_t const * to, size_t numDependencies){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphAddDependencies) (cudaGraph_t, cudaGraphNode_t const *, cudaGraphNode_t const *, size_t) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t const *, cudaGraphNode_t const *, size_t))dlsym(RTLD_NEXT, "cudaGraphAddDependencies");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphAddDependencies", kApiTypeRuntime);

    lretval = lcudaGraphAddDependencies(graph, from, to, numDependencies);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphRemoveDependencies(cudaGraph_t graph, cudaGraphNode_t const * from, cudaGraphNode_t const * to, size_t numDependencies){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphRemoveDependencies) (cudaGraph_t, cudaGraphNode_t const *, cudaGraphNode_t const *, size_t) = (cudaError_t (*)(cudaGraph_t, cudaGraphNode_t const *, cudaGraphNode_t const *, size_t))dlsym(RTLD_NEXT, "cudaGraphRemoveDependencies");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphRemoveDependencies", kApiTypeRuntime);

    lretval = lcudaGraphRemoveDependencies(graph, from, to, numDependencies);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphDestroyNode(cudaGraphNode_t node){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphDestroyNode) (cudaGraphNode_t) = (cudaError_t (*)(cudaGraphNode_t))dlsym(RTLD_NEXT, "cudaGraphDestroyNode");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphDestroyNode", kApiTypeRuntime);

    lretval = lcudaGraphDestroyNode(node);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphInstantiate(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, cudaGraphNode_t * pErrorNode, char * pLogBuffer, size_t bufferSize){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphInstantiate) (cudaGraphExec_t *, cudaGraph_t, cudaGraphNode_t *, char *, size_t) = (cudaError_t (*)(cudaGraphExec_t *, cudaGraph_t, cudaGraphNode_t *, char *, size_t))dlsym(RTLD_NEXT, "cudaGraphInstantiate");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphInstantiate", kApiTypeRuntime);

    lretval = lcudaGraphInstantiate(pGraphExec, graph, pErrorNode, pLogBuffer, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecKernelNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaKernelNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecKernelNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaKernelNodeParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaKernelNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExecKernelNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecKernelNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphExecKernelNodeSetParams(hGraphExec, node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecMemcpyNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaMemcpy3DParms const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemcpyNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaMemcpy3DParms const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaMemcpy3DParms const *))dlsym(RTLD_NEXT, "cudaGraphExecMemcpyNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecMemcpyNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphExecMemcpyNodeSetParams(hGraphExec, node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecMemcpyNodeSetParamsToSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void const * symbol, void const * src, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemcpyNodeSetParamsToSymbol) (cudaGraphExec_t, cudaGraphNode_t, void const *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, void const *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphExecMemcpyNodeSetParamsToSymbol");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecMemcpyNodeSetParamsToSymbol", kApiTypeRuntime);

    lretval = lcudaGraphExecMemcpyNodeSetParamsToSymbol(hGraphExec, node, symbol, src, count, offset, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecMemcpyNodeSetParamsFromSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, void const * symbol, size_t count, size_t offset, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemcpyNodeSetParamsFromSymbol) (cudaGraphExec_t, cudaGraphNode_t, void *, void const *, size_t, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, void *, void const *, size_t, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphExecMemcpyNodeSetParamsFromSymbol");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecMemcpyNodeSetParamsFromSymbol", kApiTypeRuntime);

    lretval = lcudaGraphExecMemcpyNodeSetParamsFromSymbol(hGraphExec, node, dst, symbol, count, offset, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecMemcpyNodeSetParams1D(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemcpyNodeSetParams1D) (cudaGraphExec_t, cudaGraphNode_t, void *, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaGraphExecMemcpyNodeSetParams1D");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecMemcpyNodeSetParams1D", kApiTypeRuntime);

    lretval = lcudaGraphExecMemcpyNodeSetParams1D(hGraphExec, node, dst, src, count, kind);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecMemsetNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaMemsetParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecMemsetNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaMemsetParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaMemsetParams const *))dlsym(RTLD_NEXT, "cudaGraphExecMemsetNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecMemsetNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphExecMemsetNodeSetParams(hGraphExec, node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecHostNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaHostNodeParams const * pNodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecHostNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaHostNodeParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaHostNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExecHostNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecHostNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphExecHostNodeSetParams(hGraphExec, node, pNodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecChildGraphNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaGraph_t childGraph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecChildGraphNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaGraph_t) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphExecChildGraphNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecChildGraphNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphExecChildGraphNodeSetParams(hGraphExec, node, childGraph);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecEventRecordNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecEventRecordNodeSetEvent) (cudaGraphExec_t, cudaGraphNode_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphExecEventRecordNodeSetEvent");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecEventRecordNodeSetEvent", kApiTypeRuntime);

    lretval = lcudaGraphExecEventRecordNodeSetEvent(hGraphExec, hNode, event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecEventWaitNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecEventWaitNodeSetEvent) (cudaGraphExec_t, cudaGraphNode_t, cudaEvent_t) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaEvent_t))dlsym(RTLD_NEXT, "cudaGraphExecEventWaitNodeSetEvent");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecEventWaitNodeSetEvent", kApiTypeRuntime);

    lretval = lcudaGraphExecEventWaitNodeSetEvent(hGraphExec, hNode, event);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecExternalSemaphoresSignalNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaExternalSemaphoreSignalNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecExternalSemaphoresSignalNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaExternalSemaphoreSignalNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExecExternalSemaphoresSignalNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecExternalSemaphoresSignalNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphExecExternalSemaphoresSignalNodeSetParams(hGraphExec, hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecExternalSemaphoresWaitNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaExternalSemaphoreWaitNodeParams const * nodeParams){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecExternalSemaphoresWaitNodeSetParams) (cudaGraphExec_t, cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams const *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraphNode_t, cudaExternalSemaphoreWaitNodeParams const *))dlsym(RTLD_NEXT, "cudaGraphExecExternalSemaphoresWaitNodeSetParams");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecExternalSemaphoresWaitNodeSetParams", kApiTypeRuntime);

    lretval = lcudaGraphExecExternalSemaphoresWaitNodeSetParams(hGraphExec, hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecUpdate(cudaGraphExec_t hGraphExec, cudaGraph_t hGraph, cudaGraphNode_t * hErrorNode_out, cudaGraphExecUpdateResult * updateResult_out){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecUpdate) (cudaGraphExec_t, cudaGraph_t, cudaGraphNode_t *, cudaGraphExecUpdateResult *) = (cudaError_t (*)(cudaGraphExec_t, cudaGraph_t, cudaGraphNode_t *, cudaGraphExecUpdateResult *))dlsym(RTLD_NEXT, "cudaGraphExecUpdate");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecUpdate", kApiTypeRuntime);

    lretval = lcudaGraphExecUpdate(hGraphExec, hGraph, hErrorNode_out, updateResult_out);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphUpload(cudaGraphExec_t graphExec, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphUpload) (cudaGraphExec_t, cudaStream_t) = (cudaError_t (*)(cudaGraphExec_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaGraphUpload");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphUpload", kApiTypeRuntime);

    lretval = lcudaGraphUpload(graphExec, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphLaunch(cudaGraphExec_t graphExec, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphLaunch) (cudaGraphExec_t, cudaStream_t) = (cudaError_t (*)(cudaGraphExec_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaGraphLaunch");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphLaunch", kApiTypeRuntime);

    lretval = lcudaGraphLaunch(graphExec, stream);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphExecDestroy(cudaGraphExec_t graphExec){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphExecDestroy) (cudaGraphExec_t) = (cudaError_t (*)(cudaGraphExec_t))dlsym(RTLD_NEXT, "cudaGraphExecDestroy");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphExecDestroy", kApiTypeRuntime);

    lretval = lcudaGraphExecDestroy(graphExec);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphDestroy(cudaGraph_t graph){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphDestroy) (cudaGraph_t) = (cudaError_t (*)(cudaGraph_t))dlsym(RTLD_NEXT, "cudaGraphDestroy");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphDestroy", kApiTypeRuntime);

    lretval = lcudaGraphDestroy(graph);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphDebugDotPrint(cudaGraph_t graph, char const * path, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphDebugDotPrint) (cudaGraph_t, char const *, unsigned int) = (cudaError_t (*)(cudaGraph_t, char const *, unsigned int))dlsym(RTLD_NEXT, "cudaGraphDebugDotPrint");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphDebugDotPrint", kApiTypeRuntime);

    lretval = lcudaGraphDebugDotPrint(graph, path, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaUserObjectCreate(cudaUserObject_t * object_out, void * ptr, cudaHostFn_t destroy, unsigned int initialRefcount, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaUserObjectCreate) (cudaUserObject_t *, void *, cudaHostFn_t, unsigned int, unsigned int) = (cudaError_t (*)(cudaUserObject_t *, void *, cudaHostFn_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaUserObjectCreate");

    /* pre exeuction logics */
    ac.add_counter("cudaUserObjectCreate", kApiTypeRuntime);

    lretval = lcudaUserObjectCreate(object_out, ptr, destroy, initialRefcount, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaUserObjectRetain(cudaUserObject_t object, unsigned int count){
    cudaError_t lretval;
    cudaError_t (*lcudaUserObjectRetain) (cudaUserObject_t, unsigned int) = (cudaError_t (*)(cudaUserObject_t, unsigned int))dlsym(RTLD_NEXT, "cudaUserObjectRetain");

    /* pre exeuction logics */
    ac.add_counter("cudaUserObjectRetain", kApiTypeRuntime);

    lretval = lcudaUserObjectRetain(object, count);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaUserObjectRelease(cudaUserObject_t object, unsigned int count){
    cudaError_t lretval;
    cudaError_t (*lcudaUserObjectRelease) (cudaUserObject_t, unsigned int) = (cudaError_t (*)(cudaUserObject_t, unsigned int))dlsym(RTLD_NEXT, "cudaUserObjectRelease");

    /* pre exeuction logics */
    ac.add_counter("cudaUserObjectRelease", kApiTypeRuntime);

    lretval = lcudaUserObjectRelease(object, count);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphRetainUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned int count, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphRetainUserObject) (cudaGraph_t, cudaUserObject_t, unsigned int, unsigned int) = (cudaError_t (*)(cudaGraph_t, cudaUserObject_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cudaGraphRetainUserObject");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphRetainUserObject", kApiTypeRuntime);

    lretval = lcudaGraphRetainUserObject(graph, object, count, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGraphReleaseUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned int count){
    cudaError_t lretval;
    cudaError_t (*lcudaGraphReleaseUserObject) (cudaGraph_t, cudaUserObject_t, unsigned int) = (cudaError_t (*)(cudaGraph_t, cudaUserObject_t, unsigned int))dlsym(RTLD_NEXT, "cudaGraphReleaseUserObject");

    /* pre exeuction logics */
    ac.add_counter("cudaGraphReleaseUserObject", kApiTypeRuntime);

    lretval = lcudaGraphReleaseUserObject(graph, object, count);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetDriverEntryPoint(char const * symbol, void * * funcPtr, long long unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaGetDriverEntryPoint) (char const *, void * *, long long unsigned int) = (cudaError_t (*)(char const *, void * *, long long unsigned int))dlsym(RTLD_NEXT, "cudaGetDriverEntryPoint");

    /* pre exeuction logics */
    ac.add_counter("cudaGetDriverEntryPoint", kApiTypeRuntime);

    lretval = lcudaGetDriverEntryPoint(symbol, funcPtr, flags);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetExportTable(void const * * ppExportTable, cudaUUID_t const * pExportTableId){
    cudaError_t lretval;
    cudaError_t (*lcudaGetExportTable) (void const * *, cudaUUID_t const *) = (cudaError_t (*)(void const * *, cudaUUID_t const *))dlsym(RTLD_NEXT, "cudaGetExportTable");

    /* pre exeuction logics */
    ac.add_counter("cudaGetExportTable", kApiTypeRuntime);

    lretval = lcudaGetExportTable(ppExportTable, pExportTableId);
    
    /* post exeuction logics */

    return lretval;
}


cudaError_t cudaGetFuncBySymbol(cudaFunction_t * functionPtr, void const * symbolPtr){
    cudaError_t lretval;
    cudaError_t (*lcudaGetFuncBySymbol) (cudaFunction_t *, void const *) = (cudaError_t (*)(cudaFunction_t *, void const *))dlsym(RTLD_NEXT, "cudaGetFuncBySymbol");

    /* pre exeuction logics */
    ac.add_counter("cudaGetFuncBySymbol", kApiTypeRuntime);

    lretval = lcudaGetFuncBySymbol(functionPtr, symbolPtr);
    
    /* post exeuction logics */

    return lretval;
}

