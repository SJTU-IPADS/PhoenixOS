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

#include "cudam.h"
#include "api_counter.h"


#undef cuGetErrorString
CUresult cuGetErrorString(CUresult error, char const * * pStr){
    CUresult lretval;
    CUresult (*lcuGetErrorString) (CUresult, char const * *) = (CUresult (*)(CUresult, char const * *))dlsym(RTLD_NEXT, "cuGetErrorString");
    
    /* pre exeuction logics */
    ac.add_counter("cuGetErrorString", kApiTypeDriver);

    lretval = lcuGetErrorString(error, pStr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGetErrorString cuGetErrorString


#undef cuGetErrorName
CUresult cuGetErrorName(CUresult error, char const * * pStr){
    CUresult lretval;
    CUresult (*lcuGetErrorName) (CUresult, char const * *) = (CUresult (*)(CUresult, char const * *))dlsym(RTLD_NEXT, "cuGetErrorName");
    
    /* pre exeuction logics */
    ac.add_counter("cuGetErrorName", kApiTypeDriver);

    lretval = lcuGetErrorName(error, pStr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGetErrorName cuGetErrorName


#undef cuInit
CUresult cuInit(unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuInit) (unsigned int) = (CUresult (*)(unsigned int))dlsym(RTLD_NEXT, "cuInit");
    
    /* pre exeuction logics */
    ac.add_counter("cuInit", kApiTypeDriver);

    lretval = lcuInit(Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuInit cuInit


#undef cuDriverGetVersion
CUresult cuDriverGetVersion(int * driverVersion){
    CUresult lretval;
    CUresult (*lcuDriverGetVersion) (int *) = (CUresult (*)(int *))dlsym(RTLD_NEXT, "cuDriverGetVersion");
    
    /* pre exeuction logics */
    ac.add_counter("cuDriverGetVersion", kApiTypeDriver);

    lretval = lcuDriverGetVersion(driverVersion);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDriverGetVersion cuDriverGetVersion


#undef cuDeviceGet
CUresult cuDeviceGet(CUdevice * device, int ordinal){
    CUresult lretval;
    CUresult (*lcuDeviceGet) (CUdevice *, int) = (CUresult (*)(CUdevice *, int))dlsym(RTLD_NEXT, "cuDeviceGet");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGet", kApiTypeDriver);

    lretval = lcuDeviceGet(device, ordinal);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGet cuDeviceGet


#undef cuDeviceGetCount
CUresult cuDeviceGetCount(int * count){
    CUresult lretval;
    CUresult (*lcuDeviceGetCount) (int *) = (CUresult (*)(int *))dlsym(RTLD_NEXT, "cuDeviceGetCount");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetCount", kApiTypeDriver);

    lretval = lcuDeviceGetCount(count);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetCount cuDeviceGetCount


#undef cuDeviceGetName
CUresult cuDeviceGetName(char * name, int len, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceGetName) (char *, int, CUdevice) = (CUresult (*)(char *, int, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetName");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetName", kApiTypeDriver);

    lretval = lcuDeviceGetName(name, len, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetName cuDeviceGetName


#undef cuDeviceGetUuid
CUresult cuDeviceGetUuid(CUuuid * uuid, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceGetUuid) (CUuuid *, CUdevice) = (CUresult (*)(CUuuid *, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetUuid");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetUuid", kApiTypeDriver);

    lretval = lcuDeviceGetUuid(uuid, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetUuid cuDeviceGetUuid


#undef cuDeviceGetLuid
CUresult cuDeviceGetLuid(char * luid, unsigned int * deviceNodeMask, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceGetLuid) (char *, unsigned int *, CUdevice) = (CUresult (*)(char *, unsigned int *, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetLuid");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetLuid", kApiTypeDriver);

    lretval = lcuDeviceGetLuid(luid, deviceNodeMask, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetLuid cuDeviceGetLuid


#undef cuDeviceTotalMem_v2
CUresult cuDeviceTotalMem_v2(size_t * bytes, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceTotalMem_v2) (size_t *, CUdevice) = (CUresult (*)(size_t *, CUdevice))dlsym(RTLD_NEXT, "cuDeviceTotalMem_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceTotalMem_v2", kApiTypeDriver);

    lretval = lcuDeviceTotalMem_v2(bytes, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceTotalMem_v2 cuDeviceTotalMem_v2


#undef cuDeviceGetTexture1DLinearMaxWidth
CUresult cuDeviceGetTexture1DLinearMaxWidth(size_t * maxWidthInElements, CUarray_format format, unsigned int numChannels, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceGetTexture1DLinearMaxWidth) (size_t *, CUarray_format, unsigned int, CUdevice) = (CUresult (*)(size_t *, CUarray_format, unsigned int, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetTexture1DLinearMaxWidth");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetTexture1DLinearMaxWidth", kApiTypeDriver);

    lretval = lcuDeviceGetTexture1DLinearMaxWidth(maxWidthInElements, format, numChannels, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetTexture1DLinearMaxWidth cuDeviceGetTexture1DLinearMaxWidth


#undef cuDeviceGetAttribute
CUresult cuDeviceGetAttribute(int * pi, CUdevice_attribute attrib, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceGetAttribute) (int *, CUdevice_attribute, CUdevice) = (CUresult (*)(int *, CUdevice_attribute, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetAttribute", kApiTypeDriver);

    lretval = lcuDeviceGetAttribute(pi, attrib, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetAttribute cuDeviceGetAttribute


#undef cuDeviceGetNvSciSyncAttributes
CUresult cuDeviceGetNvSciSyncAttributes(void * nvSciSyncAttrList, CUdevice dev, int flags){
    CUresult lretval;
    CUresult (*lcuDeviceGetNvSciSyncAttributes) (void *, CUdevice, int) = (CUresult (*)(void *, CUdevice, int))dlsym(RTLD_NEXT, "cuDeviceGetNvSciSyncAttributes");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetNvSciSyncAttributes", kApiTypeDriver);

    lretval = lcuDeviceGetNvSciSyncAttributes(nvSciSyncAttrList, dev, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetNvSciSyncAttributes cuDeviceGetNvSciSyncAttributes


#undef cuDeviceSetMemPool
CUresult cuDeviceSetMemPool(CUdevice dev, CUmemoryPool pool){
    CUresult lretval;
    CUresult (*lcuDeviceSetMemPool) (CUdevice, CUmemoryPool) = (CUresult (*)(CUdevice, CUmemoryPool))dlsym(RTLD_NEXT, "cuDeviceSetMemPool");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceSetMemPool", kApiTypeDriver);

    lretval = lcuDeviceSetMemPool(dev, pool);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceSetMemPool cuDeviceSetMemPool


#undef cuDeviceGetMemPool
CUresult cuDeviceGetMemPool(CUmemoryPool * pool, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceGetMemPool) (CUmemoryPool *, CUdevice) = (CUresult (*)(CUmemoryPool *, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetMemPool");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetMemPool", kApiTypeDriver);

    lretval = lcuDeviceGetMemPool(pool, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetMemPool cuDeviceGetMemPool


#undef cuDeviceGetDefaultMemPool
CUresult cuDeviceGetDefaultMemPool(CUmemoryPool * pool_out, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceGetDefaultMemPool) (CUmemoryPool *, CUdevice) = (CUresult (*)(CUmemoryPool *, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetDefaultMemPool");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetDefaultMemPool", kApiTypeDriver);

    lretval = lcuDeviceGetDefaultMemPool(pool_out, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetDefaultMemPool cuDeviceGetDefaultMemPool


#undef cuDeviceGetProperties
CUresult cuDeviceGetProperties(CUdevprop * prop, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceGetProperties) (CUdevprop *, CUdevice) = (CUresult (*)(CUdevprop *, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetProperties");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetProperties", kApiTypeDriver);

    lretval = lcuDeviceGetProperties(prop, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetProperties cuDeviceGetProperties


#undef cuDeviceComputeCapability
CUresult cuDeviceComputeCapability(int * major, int * minor, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceComputeCapability) (int *, int *, CUdevice) = (CUresult (*)(int *, int *, CUdevice))dlsym(RTLD_NEXT, "cuDeviceComputeCapability");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceComputeCapability", kApiTypeDriver);

    lretval = lcuDeviceComputeCapability(major, minor, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceComputeCapability cuDeviceComputeCapability


#undef cuDevicePrimaryCtxRetain
CUresult cuDevicePrimaryCtxRetain(CUcontext * pctx, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDevicePrimaryCtxRetain) (CUcontext *, CUdevice) = (CUresult (*)(CUcontext *, CUdevice))dlsym(RTLD_NEXT, "cuDevicePrimaryCtxRetain");
    
    /* pre exeuction logics */
    ac.add_counter("cuDevicePrimaryCtxRetain", kApiTypeDriver);

    lretval = lcuDevicePrimaryCtxRetain(pctx, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDevicePrimaryCtxRetain cuDevicePrimaryCtxRetain


#undef cuDevicePrimaryCtxRelease_v2
CUresult cuDevicePrimaryCtxRelease_v2(CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDevicePrimaryCtxRelease_v2) (CUdevice) = (CUresult (*)(CUdevice))dlsym(RTLD_NEXT, "cuDevicePrimaryCtxRelease_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuDevicePrimaryCtxRelease_v2", kApiTypeDriver);

    lretval = lcuDevicePrimaryCtxRelease_v2(dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDevicePrimaryCtxRelease_v2 cuDevicePrimaryCtxRelease_v2


#undef cuDevicePrimaryCtxSetFlags_v2
CUresult cuDevicePrimaryCtxSetFlags_v2(CUdevice dev, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuDevicePrimaryCtxSetFlags_v2) (CUdevice, unsigned int) = (CUresult (*)(CUdevice, unsigned int))dlsym(RTLD_NEXT, "cuDevicePrimaryCtxSetFlags_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuDevicePrimaryCtxSetFlags_v2", kApiTypeDriver);

    lretval = lcuDevicePrimaryCtxSetFlags_v2(dev, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDevicePrimaryCtxSetFlags_v2 cuDevicePrimaryCtxSetFlags_v2


#undef cuDevicePrimaryCtxGetState
CUresult cuDevicePrimaryCtxGetState(CUdevice dev, unsigned int * flags, int * active){
    CUresult lretval;
    CUresult (*lcuDevicePrimaryCtxGetState) (CUdevice, unsigned int *, int *) = (CUresult (*)(CUdevice, unsigned int *, int *))dlsym(RTLD_NEXT, "cuDevicePrimaryCtxGetState");
    
    /* pre exeuction logics */
    ac.add_counter("cuDevicePrimaryCtxGetState", kApiTypeDriver);

    lretval = lcuDevicePrimaryCtxGetState(dev, flags, active);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDevicePrimaryCtxGetState cuDevicePrimaryCtxGetState


#undef cuDevicePrimaryCtxReset_v2
CUresult cuDevicePrimaryCtxReset_v2(CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDevicePrimaryCtxReset_v2) (CUdevice) = (CUresult (*)(CUdevice))dlsym(RTLD_NEXT, "cuDevicePrimaryCtxReset_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuDevicePrimaryCtxReset_v2", kApiTypeDriver);

    lretval = lcuDevicePrimaryCtxReset_v2(dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDevicePrimaryCtxReset_v2 cuDevicePrimaryCtxReset_v2


#undef cuCtxCreate_v2
CUresult cuCtxCreate_v2(CUcontext * pctx, unsigned int flags, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuCtxCreate_v2) (CUcontext *, unsigned int, CUdevice) = (CUresult (*)(CUcontext *, unsigned int, CUdevice))dlsym(RTLD_NEXT, "cuCtxCreate_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxCreate_v2", kApiTypeDriver);

    lretval = lcuCtxCreate_v2(pctx, flags, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxCreate_v2 cuCtxCreate_v2


#undef cuCtxDestroy_v2
CUresult cuCtxDestroy_v2(CUcontext ctx){
    CUresult lretval;
    CUresult (*lcuCtxDestroy_v2) (CUcontext) = (CUresult (*)(CUcontext))dlsym(RTLD_NEXT, "cuCtxDestroy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxDestroy_v2", kApiTypeDriver);

    lretval = lcuCtxDestroy_v2(ctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxDestroy_v2 cuCtxDestroy_v2


#undef cuCtxPushCurrent_v2
CUresult cuCtxPushCurrent_v2(CUcontext ctx){
    CUresult lretval;
    CUresult (*lcuCtxPushCurrent_v2) (CUcontext) = (CUresult (*)(CUcontext))dlsym(RTLD_NEXT, "cuCtxPushCurrent_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxPushCurrent_v2", kApiTypeDriver);

    lretval = lcuCtxPushCurrent_v2(ctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxPushCurrent_v2 cuCtxPushCurrent_v2


#undef cuCtxPopCurrent_v2
CUresult cuCtxPopCurrent_v2(CUcontext * pctx){
    CUresult lretval;
    CUresult (*lcuCtxPopCurrent_v2) (CUcontext *) = (CUresult (*)(CUcontext *))dlsym(RTLD_NEXT, "cuCtxPopCurrent_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxPopCurrent_v2", kApiTypeDriver);

    lretval = lcuCtxPopCurrent_v2(pctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxPopCurrent_v2 cuCtxPopCurrent_v2


#undef cuCtxSetCurrent
CUresult cuCtxSetCurrent(CUcontext ctx){
    CUresult lretval;
    CUresult (*lcuCtxSetCurrent) (CUcontext) = (CUresult (*)(CUcontext))dlsym(RTLD_NEXT, "cuCtxSetCurrent");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxSetCurrent", kApiTypeDriver);

    lretval = lcuCtxSetCurrent(ctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxSetCurrent cuCtxSetCurrent


#undef cuCtxGetCurrent
CUresult cuCtxGetCurrent(CUcontext * pctx){
    CUresult lretval;
    CUresult (*lcuCtxGetCurrent) (CUcontext *) = (CUresult (*)(CUcontext *))dlsym(RTLD_NEXT, "cuCtxGetCurrent");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxGetCurrent", kApiTypeDriver);

    lretval = lcuCtxGetCurrent(pctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxGetCurrent cuCtxGetCurrent


#undef cuCtxGetDevice
CUresult cuCtxGetDevice(CUdevice * device){
    CUresult lretval;
    CUresult (*lcuCtxGetDevice) (CUdevice *) = (CUresult (*)(CUdevice *))dlsym(RTLD_NEXT, "cuCtxGetDevice");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxGetDevice", kApiTypeDriver);

    lretval = lcuCtxGetDevice(device);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxGetDevice cuCtxGetDevice


#undef cuCtxGetFlags
CUresult cuCtxGetFlags(unsigned int * flags){
    CUresult lretval;
    CUresult (*lcuCtxGetFlags) (unsigned int *) = (CUresult (*)(unsigned int *))dlsym(RTLD_NEXT, "cuCtxGetFlags");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxGetFlags", kApiTypeDriver);

    lretval = lcuCtxGetFlags(flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxGetFlags cuCtxGetFlags


#undef cuCtxSynchronize
CUresult cuCtxSynchronize(){
    CUresult lretval;
    CUresult (*lcuCtxSynchronize) () = (CUresult (*)())dlsym(RTLD_NEXT, "cuCtxSynchronize");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxSynchronize", kApiTypeDriver);

    lretval = lcuCtxSynchronize();
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxSynchronize cuCtxSynchronize


#undef cuCtxSetLimit
CUresult cuCtxSetLimit(CUlimit limit, size_t value){
    CUresult lretval;
    CUresult (*lcuCtxSetLimit) (CUlimit, size_t) = (CUresult (*)(CUlimit, size_t))dlsym(RTLD_NEXT, "cuCtxSetLimit");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxSetLimit", kApiTypeDriver);

    lretval = lcuCtxSetLimit(limit, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxSetLimit cuCtxSetLimit


#undef cuCtxGetLimit
CUresult cuCtxGetLimit(size_t * pvalue, CUlimit limit){
    CUresult lretval;
    CUresult (*lcuCtxGetLimit) (size_t *, CUlimit) = (CUresult (*)(size_t *, CUlimit))dlsym(RTLD_NEXT, "cuCtxGetLimit");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxGetLimit", kApiTypeDriver);

    lretval = lcuCtxGetLimit(pvalue, limit);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxGetLimit cuCtxGetLimit


#undef cuCtxGetCacheConfig
CUresult cuCtxGetCacheConfig(CUfunc_cache * pconfig){
    CUresult lretval;
    CUresult (*lcuCtxGetCacheConfig) (CUfunc_cache *) = (CUresult (*)(CUfunc_cache *))dlsym(RTLD_NEXT, "cuCtxGetCacheConfig");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxGetCacheConfig", kApiTypeDriver);

    lretval = lcuCtxGetCacheConfig(pconfig);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxGetCacheConfig cuCtxGetCacheConfig


#undef cuCtxSetCacheConfig
CUresult cuCtxSetCacheConfig(CUfunc_cache config){
    CUresult lretval;
    CUresult (*lcuCtxSetCacheConfig) (CUfunc_cache) = (CUresult (*)(CUfunc_cache))dlsym(RTLD_NEXT, "cuCtxSetCacheConfig");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxSetCacheConfig", kApiTypeDriver);

    lretval = lcuCtxSetCacheConfig(config);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxSetCacheConfig cuCtxSetCacheConfig


#undef cuCtxGetSharedMemConfig
CUresult cuCtxGetSharedMemConfig(CUsharedconfig * pConfig){
    CUresult lretval;
    CUresult (*lcuCtxGetSharedMemConfig) (CUsharedconfig *) = (CUresult (*)(CUsharedconfig *))dlsym(RTLD_NEXT, "cuCtxGetSharedMemConfig");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxGetSharedMemConfig", kApiTypeDriver);

    lretval = lcuCtxGetSharedMemConfig(pConfig);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxGetSharedMemConfig cuCtxGetSharedMemConfig


#undef cuCtxSetSharedMemConfig
CUresult cuCtxSetSharedMemConfig(CUsharedconfig config){
    CUresult lretval;
    CUresult (*lcuCtxSetSharedMemConfig) (CUsharedconfig) = (CUresult (*)(CUsharedconfig))dlsym(RTLD_NEXT, "cuCtxSetSharedMemConfig");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxSetSharedMemConfig", kApiTypeDriver);

    lretval = lcuCtxSetSharedMemConfig(config);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxSetSharedMemConfig cuCtxSetSharedMemConfig


#undef cuCtxGetApiVersion
CUresult cuCtxGetApiVersion(CUcontext ctx, unsigned int * version){
    CUresult lretval;
    CUresult (*lcuCtxGetApiVersion) (CUcontext, unsigned int *) = (CUresult (*)(CUcontext, unsigned int *))dlsym(RTLD_NEXT, "cuCtxGetApiVersion");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxGetApiVersion", kApiTypeDriver);

    lretval = lcuCtxGetApiVersion(ctx, version);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxGetApiVersion cuCtxGetApiVersion


#undef cuCtxGetStreamPriorityRange
CUresult cuCtxGetStreamPriorityRange(int * leastPriority, int * greatestPriority){
    CUresult lretval;
    CUresult (*lcuCtxGetStreamPriorityRange) (int *, int *) = (CUresult (*)(int *, int *))dlsym(RTLD_NEXT, "cuCtxGetStreamPriorityRange");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxGetStreamPriorityRange", kApiTypeDriver);

    lretval = lcuCtxGetStreamPriorityRange(leastPriority, greatestPriority);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxGetStreamPriorityRange cuCtxGetStreamPriorityRange


#undef cuCtxResetPersistingL2Cache
CUresult cuCtxResetPersistingL2Cache(){
    CUresult lretval;
    CUresult (*lcuCtxResetPersistingL2Cache) () = (CUresult (*)())dlsym(RTLD_NEXT, "cuCtxResetPersistingL2Cache");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxResetPersistingL2Cache", kApiTypeDriver);

    lretval = lcuCtxResetPersistingL2Cache();
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxResetPersistingL2Cache cuCtxResetPersistingL2Cache


#undef cuCtxAttach
CUresult cuCtxAttach(CUcontext * pctx, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuCtxAttach) (CUcontext *, unsigned int) = (CUresult (*)(CUcontext *, unsigned int))dlsym(RTLD_NEXT, "cuCtxAttach");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxAttach", kApiTypeDriver);

    lretval = lcuCtxAttach(pctx, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxAttach cuCtxAttach


#undef cuCtxDetach
CUresult cuCtxDetach(CUcontext ctx){
    CUresult lretval;
    CUresult (*lcuCtxDetach) (CUcontext) = (CUresult (*)(CUcontext))dlsym(RTLD_NEXT, "cuCtxDetach");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxDetach", kApiTypeDriver);

    lretval = lcuCtxDetach(ctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxDetach cuCtxDetach


#undef cuModuleLoad
CUresult cuModuleLoad(CUmodule * module, char const * fname){
    CUresult lretval;
    CUresult (*lcuModuleLoad) (CUmodule *, char const *) = (CUresult (*)(CUmodule *, char const *))dlsym(RTLD_NEXT, "cuModuleLoad");
    
    /* pre exeuction logics */
    ac.add_counter("cuModuleLoad", kApiTypeDriver);

    lretval = lcuModuleLoad(module, fname);
    
    /* post exeuction logics */

    return lretval;
}
#define cuModuleLoad cuModuleLoad


#undef cuModuleLoadData
CUresult cuModuleLoadData(CUmodule * module, void const * image){
    CUresult lretval;
    CUresult (*lcuModuleLoadData) (CUmodule *, void const *) = (CUresult (*)(CUmodule *, void const *))dlsym(RTLD_NEXT, "cuModuleLoadData");
    
    /* pre exeuction logics */
    ac.add_counter("cuModuleLoadData", kApiTypeDriver);

    lretval = lcuModuleLoadData(module, image);
    
    /* post exeuction logics */

    return lretval;
}
#define cuModuleLoadData cuModuleLoadData


#undef cuModuleLoadDataEx
CUresult cuModuleLoadDataEx(CUmodule * module, void const * image, unsigned int numOptions, CUjit_option * options, void * * optionValues){
    CUresult lretval;
    CUresult (*lcuModuleLoadDataEx) (CUmodule *, void const *, unsigned int, CUjit_option *, void * *) = (CUresult (*)(CUmodule *, void const *, unsigned int, CUjit_option *, void * *))dlsym(RTLD_NEXT, "cuModuleLoadDataEx");
    
    /* pre exeuction logics */
    ac.add_counter("cuModuleLoadDataEx", kApiTypeDriver);

    lretval = lcuModuleLoadDataEx(module, image, numOptions, options, optionValues);
    
    /* post exeuction logics */

    return lretval;
}
#define cuModuleLoadDataEx cuModuleLoadDataEx


#undef cuModuleLoadFatBinary
CUresult cuModuleLoadFatBinary(CUmodule * module, void const * fatCubin){
    CUresult lretval;
    CUresult (*lcuModuleLoadFatBinary) (CUmodule *, void const *) = (CUresult (*)(CUmodule *, void const *))dlsym(RTLD_NEXT, "cuModuleLoadFatBinary");
    
    /* pre exeuction logics */
    ac.add_counter("cuModuleLoadFatBinary", kApiTypeDriver);

    lretval = lcuModuleLoadFatBinary(module, fatCubin);
    
    /* post exeuction logics */

    return lretval;
}
#define cuModuleLoadFatBinary cuModuleLoadFatBinary


#undef cuModuleUnload
CUresult cuModuleUnload(CUmodule hmod){
    CUresult lretval;
    CUresult (*lcuModuleUnload) (CUmodule) = (CUresult (*)(CUmodule))dlsym(RTLD_NEXT, "cuModuleUnload");
    
    /* pre exeuction logics */
    ac.add_counter("cuModuleUnload", kApiTypeDriver);

    lretval = lcuModuleUnload(hmod);
    
    /* post exeuction logics */

    return lretval;
}
#define cuModuleUnload cuModuleUnload


#undef cuModuleGetFunction
CUresult cuModuleGetFunction(CUfunction * hfunc, CUmodule hmod, char const * name){
    CUresult lretval;
    CUresult (*lcuModuleGetFunction) (CUfunction *, CUmodule, char const *) = (CUresult (*)(CUfunction *, CUmodule, char const *))dlsym(RTLD_NEXT, "cuModuleGetFunction");
    
    /* pre exeuction logics */
    ac.add_counter("cuModuleGetFunction", kApiTypeDriver);

    lretval = lcuModuleGetFunction(hfunc, hmod, name);
    
    /* post exeuction logics */

    return lretval;
}
#define cuModuleGetFunction cuModuleGetFunction


#undef cuModuleGetGlobal_v2
CUresult cuModuleGetGlobal_v2(CUdeviceptr * dptr, size_t * bytes, CUmodule hmod, char const * name){
    CUresult lretval;
    CUresult (*lcuModuleGetGlobal_v2) (CUdeviceptr *, size_t *, CUmodule, char const *) = (CUresult (*)(CUdeviceptr *, size_t *, CUmodule, char const *))dlsym(RTLD_NEXT, "cuModuleGetGlobal_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuModuleGetGlobal_v2", kApiTypeDriver);

    lretval = lcuModuleGetGlobal_v2(dptr, bytes, hmod, name);
    
    /* post exeuction logics */

    return lretval;
}
#define cuModuleGetGlobal_v2 cuModuleGetGlobal_v2


#undef cuModuleGetTexRef
CUresult cuModuleGetTexRef(CUtexref * pTexRef, CUmodule hmod, char const * name){
    CUresult lretval;
    CUresult (*lcuModuleGetTexRef) (CUtexref *, CUmodule, char const *) = (CUresult (*)(CUtexref *, CUmodule, char const *))dlsym(RTLD_NEXT, "cuModuleGetTexRef");
    
    /* pre exeuction logics */
    ac.add_counter("cuModuleGetTexRef", kApiTypeDriver);

    lretval = lcuModuleGetTexRef(pTexRef, hmod, name);
    
    /* post exeuction logics */

    return lretval;
}
#define cuModuleGetTexRef cuModuleGetTexRef


#undef cuModuleGetSurfRef
CUresult cuModuleGetSurfRef(CUsurfref * pSurfRef, CUmodule hmod, char const * name){
    CUresult lretval;
    CUresult (*lcuModuleGetSurfRef) (CUsurfref *, CUmodule, char const *) = (CUresult (*)(CUsurfref *, CUmodule, char const *))dlsym(RTLD_NEXT, "cuModuleGetSurfRef");
    
    /* pre exeuction logics */
    ac.add_counter("cuModuleGetSurfRef", kApiTypeDriver);

    lretval = lcuModuleGetSurfRef(pSurfRef, hmod, name);
    
    /* post exeuction logics */

    return lretval;
}
#define cuModuleGetSurfRef cuModuleGetSurfRef


#undef cuLinkCreate_v2
CUresult cuLinkCreate_v2(unsigned int numOptions, CUjit_option * options, void * * optionValues, CUlinkState * stateOut){
    CUresult lretval;
    CUresult (*lcuLinkCreate_v2) (unsigned int, CUjit_option *, void * *, CUlinkState *) = (CUresult (*)(unsigned int, CUjit_option *, void * *, CUlinkState *))dlsym(RTLD_NEXT, "cuLinkCreate_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuLinkCreate_v2", kApiTypeDriver);

    lretval = lcuLinkCreate_v2(numOptions, options, optionValues, stateOut);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLinkCreate_v2 cuLinkCreate_v2


#undef cuLinkAddData_v2
CUresult cuLinkAddData_v2(CUlinkState state, CUjitInputType type, void * data, size_t size, char const * name, unsigned int numOptions, CUjit_option * options, void * * optionValues){
    CUresult lretval;
    CUresult (*lcuLinkAddData_v2) (CUlinkState, CUjitInputType, void *, size_t, char const *, unsigned int, CUjit_option *, void * *) = (CUresult (*)(CUlinkState, CUjitInputType, void *, size_t, char const *, unsigned int, CUjit_option *, void * *))dlsym(RTLD_NEXT, "cuLinkAddData_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuLinkAddData_v2", kApiTypeDriver);

    lretval = lcuLinkAddData_v2(state, type, data, size, name, numOptions, options, optionValues);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLinkAddData_v2 cuLinkAddData_v2


#undef cuLinkAddFile_v2
CUresult cuLinkAddFile_v2(CUlinkState state, CUjitInputType type, char const * path, unsigned int numOptions, CUjit_option * options, void * * optionValues){
    CUresult lretval;
    CUresult (*lcuLinkAddFile_v2) (CUlinkState, CUjitInputType, char const *, unsigned int, CUjit_option *, void * *) = (CUresult (*)(CUlinkState, CUjitInputType, char const *, unsigned int, CUjit_option *, void * *))dlsym(RTLD_NEXT, "cuLinkAddFile_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuLinkAddFile_v2", kApiTypeDriver);

    lretval = lcuLinkAddFile_v2(state, type, path, numOptions, options, optionValues);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLinkAddFile_v2 cuLinkAddFile_v2


#undef cuLinkComplete
CUresult cuLinkComplete(CUlinkState state, void * * cubinOut, size_t * sizeOut){
    CUresult lretval;
    CUresult (*lcuLinkComplete) (CUlinkState, void * *, size_t *) = (CUresult (*)(CUlinkState, void * *, size_t *))dlsym(RTLD_NEXT, "cuLinkComplete");
    
    /* pre exeuction logics */
    ac.add_counter("cuLinkComplete", kApiTypeDriver);

    lretval = lcuLinkComplete(state, cubinOut, sizeOut);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLinkComplete cuLinkComplete


#undef cuLinkDestroy
CUresult cuLinkDestroy(CUlinkState state){
    CUresult lretval;
    CUresult (*lcuLinkDestroy) (CUlinkState) = (CUresult (*)(CUlinkState))dlsym(RTLD_NEXT, "cuLinkDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cuLinkDestroy", kApiTypeDriver);

    lretval = lcuLinkDestroy(state);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLinkDestroy cuLinkDestroy


#undef cuMemGetInfo_v2
CUresult cuMemGetInfo_v2(size_t * free, size_t * total){
    CUresult lretval;
    CUresult (*lcuMemGetInfo_v2) (size_t *, size_t *) = (CUresult (*)(size_t *, size_t *))dlsym(RTLD_NEXT, "cuMemGetInfo_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemGetInfo_v2", kApiTypeDriver);

    lretval = lcuMemGetInfo_v2(free, total);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemGetInfo_v2 cuMemGetInfo_v2


#undef cuMemAlloc_v2
CUresult cuMemAlloc_v2(CUdeviceptr * dptr, size_t bytesize){
    CUresult lretval;
    CUresult (*lcuMemAlloc_v2) (CUdeviceptr *, size_t) = (CUresult (*)(CUdeviceptr *, size_t))dlsym(RTLD_NEXT, "cuMemAlloc_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemAlloc_v2", kApiTypeDriver);

    lretval = lcuMemAlloc_v2(dptr, bytesize);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemAlloc_v2 cuMemAlloc_v2


#undef cuMemAllocPitch_v2
CUresult cuMemAllocPitch_v2(CUdeviceptr * dptr, size_t * pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes){
    CUresult lretval;
    CUresult (*lcuMemAllocPitch_v2) (CUdeviceptr *, size_t *, size_t, size_t, unsigned int) = (CUresult (*)(CUdeviceptr *, size_t *, size_t, size_t, unsigned int))dlsym(RTLD_NEXT, "cuMemAllocPitch_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemAllocPitch_v2", kApiTypeDriver);

    lretval = lcuMemAllocPitch_v2(dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemAllocPitch_v2 cuMemAllocPitch_v2


#undef cuMemFree_v2
CUresult cuMemFree_v2(CUdeviceptr dptr){
    CUresult lretval;
    CUresult (*lcuMemFree_v2) (CUdeviceptr) = (CUresult (*)(CUdeviceptr))dlsym(RTLD_NEXT, "cuMemFree_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemFree_v2", kApiTypeDriver);

    lretval = lcuMemFree_v2(dptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemFree_v2 cuMemFree_v2


#undef cuMemGetAddressRange_v2
CUresult cuMemGetAddressRange_v2(CUdeviceptr * pbase, size_t * psize, CUdeviceptr dptr){
    CUresult lretval;
    CUresult (*lcuMemGetAddressRange_v2) (CUdeviceptr *, size_t *, CUdeviceptr) = (CUresult (*)(CUdeviceptr *, size_t *, CUdeviceptr))dlsym(RTLD_NEXT, "cuMemGetAddressRange_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemGetAddressRange_v2", kApiTypeDriver);

    lretval = lcuMemGetAddressRange_v2(pbase, psize, dptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemGetAddressRange_v2 cuMemGetAddressRange_v2


#undef cuMemAllocHost_v2
CUresult cuMemAllocHost_v2(void * * pp, size_t bytesize){
    CUresult lretval;
    CUresult (*lcuMemAllocHost_v2) (void * *, size_t) = (CUresult (*)(void * *, size_t))dlsym(RTLD_NEXT, "cuMemAllocHost_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemAllocHost_v2", kApiTypeDriver);

    lretval = lcuMemAllocHost_v2(pp, bytesize);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemAllocHost_v2 cuMemAllocHost_v2


#undef cuMemFreeHost
CUresult cuMemFreeHost(void * p){
    CUresult lretval;
    CUresult (*lcuMemFreeHost) (void *) = (CUresult (*)(void *))dlsym(RTLD_NEXT, "cuMemFreeHost");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemFreeHost", kApiTypeDriver);

    lretval = lcuMemFreeHost(p);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemFreeHost cuMemFreeHost


#undef cuMemHostAlloc
CUresult cuMemHostAlloc(void * * pp, size_t bytesize, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuMemHostAlloc) (void * *, size_t, unsigned int) = (CUresult (*)(void * *, size_t, unsigned int))dlsym(RTLD_NEXT, "cuMemHostAlloc");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemHostAlloc", kApiTypeDriver);

    lretval = lcuMemHostAlloc(pp, bytesize, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemHostAlloc cuMemHostAlloc


#undef cuMemHostGetDevicePointer_v2
CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr * pdptr, void * p, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuMemHostGetDevicePointer_v2) (CUdeviceptr *, void *, unsigned int) = (CUresult (*)(CUdeviceptr *, void *, unsigned int))dlsym(RTLD_NEXT, "cuMemHostGetDevicePointer_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemHostGetDevicePointer_v2", kApiTypeDriver);

    lretval = lcuMemHostGetDevicePointer_v2(pdptr, p, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemHostGetDevicePointer_v2 cuMemHostGetDevicePointer_v2


#undef cuMemHostGetFlags
CUresult cuMemHostGetFlags(unsigned int * pFlags, void * p){
    CUresult lretval;
    CUresult (*lcuMemHostGetFlags) (unsigned int *, void *) = (CUresult (*)(unsigned int *, void *))dlsym(RTLD_NEXT, "cuMemHostGetFlags");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemHostGetFlags", kApiTypeDriver);

    lretval = lcuMemHostGetFlags(pFlags, p);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemHostGetFlags cuMemHostGetFlags


#undef cuMemAllocManaged
CUresult cuMemAllocManaged(CUdeviceptr * dptr, size_t bytesize, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuMemAllocManaged) (CUdeviceptr *, size_t, unsigned int) = (CUresult (*)(CUdeviceptr *, size_t, unsigned int))dlsym(RTLD_NEXT, "cuMemAllocManaged");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemAllocManaged", kApiTypeDriver);

    lretval = lcuMemAllocManaged(dptr, bytesize, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemAllocManaged cuMemAllocManaged


#undef cuDeviceGetByPCIBusId
CUresult cuDeviceGetByPCIBusId(CUdevice * dev, char const * pciBusId){
    CUresult lretval;
    CUresult (*lcuDeviceGetByPCIBusId) (CUdevice *, char const *) = (CUresult (*)(CUdevice *, char const *))dlsym(RTLD_NEXT, "cuDeviceGetByPCIBusId");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetByPCIBusId", kApiTypeDriver);

    lretval = lcuDeviceGetByPCIBusId(dev, pciBusId);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetByPCIBusId cuDeviceGetByPCIBusId


#undef cuDeviceGetPCIBusId
CUresult cuDeviceGetPCIBusId(char * pciBusId, int len, CUdevice dev){
    CUresult lretval;
    CUresult (*lcuDeviceGetPCIBusId) (char *, int, CUdevice) = (CUresult (*)(char *, int, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetPCIBusId");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetPCIBusId", kApiTypeDriver);

    lretval = lcuDeviceGetPCIBusId(pciBusId, len, dev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetPCIBusId cuDeviceGetPCIBusId


#undef cuIpcGetEventHandle
CUresult cuIpcGetEventHandle(CUipcEventHandle * pHandle, CUevent event){
    CUresult lretval;
    CUresult (*lcuIpcGetEventHandle) (CUipcEventHandle *, CUevent) = (CUresult (*)(CUipcEventHandle *, CUevent))dlsym(RTLD_NEXT, "cuIpcGetEventHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuIpcGetEventHandle", kApiTypeDriver);

    lretval = lcuIpcGetEventHandle(pHandle, event);
    
    /* post exeuction logics */

    return lretval;
}
#define cuIpcGetEventHandle cuIpcGetEventHandle


#undef cuIpcOpenEventHandle
CUresult cuIpcOpenEventHandle(CUevent * phEvent, CUipcEventHandle handle){
    CUresult lretval;
    CUresult (*lcuIpcOpenEventHandle) (CUevent *, CUipcEventHandle) = (CUresult (*)(CUevent *, CUipcEventHandle))dlsym(RTLD_NEXT, "cuIpcOpenEventHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuIpcOpenEventHandle", kApiTypeDriver);

    lretval = lcuIpcOpenEventHandle(phEvent, handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cuIpcOpenEventHandle cuIpcOpenEventHandle


#undef cuIpcGetMemHandle
CUresult cuIpcGetMemHandle(CUipcMemHandle * pHandle, CUdeviceptr dptr){
    CUresult lretval;
    CUresult (*lcuIpcGetMemHandle) (CUipcMemHandle *, CUdeviceptr) = (CUresult (*)(CUipcMemHandle *, CUdeviceptr))dlsym(RTLD_NEXT, "cuIpcGetMemHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuIpcGetMemHandle", kApiTypeDriver);

    lretval = lcuIpcGetMemHandle(pHandle, dptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuIpcGetMemHandle cuIpcGetMemHandle


#undef cuIpcOpenMemHandle_v2
CUresult cuIpcOpenMemHandle_v2(CUdeviceptr * pdptr, CUipcMemHandle handle, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuIpcOpenMemHandle_v2) (CUdeviceptr *, CUipcMemHandle, unsigned int) = (CUresult (*)(CUdeviceptr *, CUipcMemHandle, unsigned int))dlsym(RTLD_NEXT, "cuIpcOpenMemHandle_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuIpcOpenMemHandle_v2", kApiTypeDriver);

    lretval = lcuIpcOpenMemHandle_v2(pdptr, handle, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuIpcOpenMemHandle_v2 cuIpcOpenMemHandle_v2


#undef cuIpcCloseMemHandle
CUresult cuIpcCloseMemHandle(CUdeviceptr dptr){
    CUresult lretval;
    CUresult (*lcuIpcCloseMemHandle) (CUdeviceptr) = (CUresult (*)(CUdeviceptr))dlsym(RTLD_NEXT, "cuIpcCloseMemHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuIpcCloseMemHandle", kApiTypeDriver);

    lretval = lcuIpcCloseMemHandle(dptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuIpcCloseMemHandle cuIpcCloseMemHandle


#undef cuMemHostRegister_v2
CUresult cuMemHostRegister_v2(void * p, size_t bytesize, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuMemHostRegister_v2) (void *, size_t, unsigned int) = (CUresult (*)(void *, size_t, unsigned int))dlsym(RTLD_NEXT, "cuMemHostRegister_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemHostRegister_v2", kApiTypeDriver);

    lretval = lcuMemHostRegister_v2(p, bytesize, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemHostRegister_v2 cuMemHostRegister_v2


#undef cuMemHostUnregister
CUresult cuMemHostUnregister(void * p){
    CUresult lretval;
    CUresult (*lcuMemHostUnregister) (void *) = (CUresult (*)(void *))dlsym(RTLD_NEXT, "cuMemHostUnregister");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemHostUnregister", kApiTypeDriver);

    lretval = lcuMemHostUnregister(p);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemHostUnregister cuMemHostUnregister


#undef cuMemcpy
CUresult cuMemcpy(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpy) (CUdeviceptr, CUdeviceptr, size_t) = (CUresult (*)(CUdeviceptr, CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuMemcpy");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpy", kApiTypeDriver);

    lretval = lcuMemcpy(dst, src, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpy cuMemcpy


#undef cuMemcpyPeer
CUresult cuMemcpyPeer(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpyPeer) (CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t) = (CUresult (*)(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t))dlsym(RTLD_NEXT, "cuMemcpyPeer");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyPeer", kApiTypeDriver);

    lretval = lcuMemcpyPeer(dstDevice, dstContext, srcDevice, srcContext, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyPeer cuMemcpyPeer


#undef cuMemcpyHtoD_v2
CUresult cuMemcpyHtoD_v2(CUdeviceptr dstDevice, void const * srcHost, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpyHtoD_v2) (CUdeviceptr, void const *, size_t) = (CUresult (*)(CUdeviceptr, void const *, size_t))dlsym(RTLD_NEXT, "cuMemcpyHtoD_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyHtoD_v2", kApiTypeDriver);

    lretval = lcuMemcpyHtoD_v2(dstDevice, srcHost, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyHtoD_v2 cuMemcpyHtoD_v2


#undef cuMemcpyDtoH_v2
CUresult cuMemcpyDtoH_v2(void * dstHost, CUdeviceptr srcDevice, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpyDtoH_v2) (void *, CUdeviceptr, size_t) = (CUresult (*)(void *, CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuMemcpyDtoH_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyDtoH_v2", kApiTypeDriver);

    lretval = lcuMemcpyDtoH_v2(dstHost, srcDevice, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyDtoH_v2 cuMemcpyDtoH_v2


#undef cuMemcpyDtoD_v2
CUresult cuMemcpyDtoD_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpyDtoD_v2) (CUdeviceptr, CUdeviceptr, size_t) = (CUresult (*)(CUdeviceptr, CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuMemcpyDtoD_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyDtoD_v2", kApiTypeDriver);

    lretval = lcuMemcpyDtoD_v2(dstDevice, srcDevice, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyDtoD_v2 cuMemcpyDtoD_v2


#undef cuMemcpyDtoA_v2
CUresult cuMemcpyDtoA_v2(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpyDtoA_v2) (CUarray, size_t, CUdeviceptr, size_t) = (CUresult (*)(CUarray, size_t, CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuMemcpyDtoA_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyDtoA_v2", kApiTypeDriver);

    lretval = lcuMemcpyDtoA_v2(dstArray, dstOffset, srcDevice, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyDtoA_v2 cuMemcpyDtoA_v2


#undef cuMemcpyAtoD_v2
CUresult cuMemcpyAtoD_v2(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpyAtoD_v2) (CUdeviceptr, CUarray, size_t, size_t) = (CUresult (*)(CUdeviceptr, CUarray, size_t, size_t))dlsym(RTLD_NEXT, "cuMemcpyAtoD_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyAtoD_v2", kApiTypeDriver);

    lretval = lcuMemcpyAtoD_v2(dstDevice, srcArray, srcOffset, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyAtoD_v2 cuMemcpyAtoD_v2


#undef cuMemcpyHtoA_v2
CUresult cuMemcpyHtoA_v2(CUarray dstArray, size_t dstOffset, void const * srcHost, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpyHtoA_v2) (CUarray, size_t, void const *, size_t) = (CUresult (*)(CUarray, size_t, void const *, size_t))dlsym(RTLD_NEXT, "cuMemcpyHtoA_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyHtoA_v2", kApiTypeDriver);

    lretval = lcuMemcpyHtoA_v2(dstArray, dstOffset, srcHost, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyHtoA_v2 cuMemcpyHtoA_v2


#undef cuMemcpyAtoH_v2
CUresult cuMemcpyAtoH_v2(void * dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpyAtoH_v2) (void *, CUarray, size_t, size_t) = (CUresult (*)(void *, CUarray, size_t, size_t))dlsym(RTLD_NEXT, "cuMemcpyAtoH_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyAtoH_v2", kApiTypeDriver);

    lretval = lcuMemcpyAtoH_v2(dstHost, srcArray, srcOffset, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyAtoH_v2 cuMemcpyAtoH_v2


#undef cuMemcpyAtoA_v2
CUresult cuMemcpyAtoA_v2(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount){
    CUresult lretval;
    CUresult (*lcuMemcpyAtoA_v2) (CUarray, size_t, CUarray, size_t, size_t) = (CUresult (*)(CUarray, size_t, CUarray, size_t, size_t))dlsym(RTLD_NEXT, "cuMemcpyAtoA_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyAtoA_v2", kApiTypeDriver);

    lretval = lcuMemcpyAtoA_v2(dstArray, dstOffset, srcArray, srcOffset, ByteCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyAtoA_v2 cuMemcpyAtoA_v2


#undef cuMemcpy2D_v2
CUresult cuMemcpy2D_v2(CUDA_MEMCPY2D const * pCopy){
    CUresult lretval;
    CUresult (*lcuMemcpy2D_v2) (CUDA_MEMCPY2D const *) = (CUresult (*)(CUDA_MEMCPY2D const *))dlsym(RTLD_NEXT, "cuMemcpy2D_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpy2D_v2", kApiTypeDriver);

    lretval = lcuMemcpy2D_v2(pCopy);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpy2D_v2 cuMemcpy2D_v2


#undef cuMemcpy2DUnaligned_v2
CUresult cuMemcpy2DUnaligned_v2(CUDA_MEMCPY2D const * pCopy){
    CUresult lretval;
    CUresult (*lcuMemcpy2DUnaligned_v2) (CUDA_MEMCPY2D const *) = (CUresult (*)(CUDA_MEMCPY2D const *))dlsym(RTLD_NEXT, "cuMemcpy2DUnaligned_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpy2DUnaligned_v2", kApiTypeDriver);

    lretval = lcuMemcpy2DUnaligned_v2(pCopy);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpy2DUnaligned_v2 cuMemcpy2DUnaligned_v2


#undef cuMemcpy3D_v2
CUresult cuMemcpy3D_v2(CUDA_MEMCPY3D const * pCopy){
    CUresult lretval;
    CUresult (*lcuMemcpy3D_v2) (CUDA_MEMCPY3D const *) = (CUresult (*)(CUDA_MEMCPY3D const *))dlsym(RTLD_NEXT, "cuMemcpy3D_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpy3D_v2", kApiTypeDriver);

    lretval = lcuMemcpy3D_v2(pCopy);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpy3D_v2 cuMemcpy3D_v2


#undef cuMemcpy3DPeer
CUresult cuMemcpy3DPeer(CUDA_MEMCPY3D_PEER const * pCopy){
    CUresult lretval;
    CUresult (*lcuMemcpy3DPeer) (CUDA_MEMCPY3D_PEER const *) = (CUresult (*)(CUDA_MEMCPY3D_PEER const *))dlsym(RTLD_NEXT, "cuMemcpy3DPeer");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpy3DPeer", kApiTypeDriver);

    lretval = lcuMemcpy3DPeer(pCopy);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpy3DPeer cuMemcpy3DPeer


#undef cuMemcpyAsync
CUresult cuMemcpyAsync(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpyAsync) (CUdeviceptr, CUdeviceptr, size_t, CUstream) = (CUresult (*)(CUdeviceptr, CUdeviceptr, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemcpyAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyAsync", kApiTypeDriver);

    lretval = lcuMemcpyAsync(dst, src, ByteCount, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyAsync cuMemcpyAsync


#undef cuMemcpyPeerAsync
CUresult cuMemcpyPeerAsync(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpyPeerAsync) (CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t, CUstream) = (CUresult (*)(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemcpyPeerAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyPeerAsync", kApiTypeDriver);

    lretval = lcuMemcpyPeerAsync(dstDevice, dstContext, srcDevice, srcContext, ByteCount, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyPeerAsync cuMemcpyPeerAsync


#undef cuMemcpyHtoDAsync_v2
CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr dstDevice, void const * srcHost, size_t ByteCount, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpyHtoDAsync_v2) (CUdeviceptr, void const *, size_t, CUstream) = (CUresult (*)(CUdeviceptr, void const *, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemcpyHtoDAsync_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyHtoDAsync_v2", kApiTypeDriver);

    lretval = lcuMemcpyHtoDAsync_v2(dstDevice, srcHost, ByteCount, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyHtoDAsync_v2 cuMemcpyHtoDAsync_v2


#undef cuMemcpyDtoHAsync_v2
CUresult cuMemcpyDtoHAsync_v2(void * dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpyDtoHAsync_v2) (void *, CUdeviceptr, size_t, CUstream) = (CUresult (*)(void *, CUdeviceptr, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemcpyDtoHAsync_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyDtoHAsync_v2", kApiTypeDriver);

    lretval = lcuMemcpyDtoHAsync_v2(dstHost, srcDevice, ByteCount, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyDtoHAsync_v2 cuMemcpyDtoHAsync_v2


#undef cuMemcpyDtoDAsync_v2
CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpyDtoDAsync_v2) (CUdeviceptr, CUdeviceptr, size_t, CUstream) = (CUresult (*)(CUdeviceptr, CUdeviceptr, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemcpyDtoDAsync_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyDtoDAsync_v2", kApiTypeDriver);

    lretval = lcuMemcpyDtoDAsync_v2(dstDevice, srcDevice, ByteCount, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyDtoDAsync_v2 cuMemcpyDtoDAsync_v2


#undef cuMemcpyHtoAAsync_v2
CUresult cuMemcpyHtoAAsync_v2(CUarray dstArray, size_t dstOffset, void const * srcHost, size_t ByteCount, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpyHtoAAsync_v2) (CUarray, size_t, void const *, size_t, CUstream) = (CUresult (*)(CUarray, size_t, void const *, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemcpyHtoAAsync_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyHtoAAsync_v2", kApiTypeDriver);

    lretval = lcuMemcpyHtoAAsync_v2(dstArray, dstOffset, srcHost, ByteCount, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyHtoAAsync_v2 cuMemcpyHtoAAsync_v2


#undef cuMemcpyAtoHAsync_v2
CUresult cuMemcpyAtoHAsync_v2(void * dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpyAtoHAsync_v2) (void *, CUarray, size_t, size_t, CUstream) = (CUresult (*)(void *, CUarray, size_t, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemcpyAtoHAsync_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpyAtoHAsync_v2", kApiTypeDriver);

    lretval = lcuMemcpyAtoHAsync_v2(dstHost, srcArray, srcOffset, ByteCount, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpyAtoHAsync_v2 cuMemcpyAtoHAsync_v2


#undef cuMemcpy2DAsync_v2
CUresult cuMemcpy2DAsync_v2(CUDA_MEMCPY2D const * pCopy, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpy2DAsync_v2) (CUDA_MEMCPY2D const *, CUstream) = (CUresult (*)(CUDA_MEMCPY2D const *, CUstream))dlsym(RTLD_NEXT, "cuMemcpy2DAsync_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpy2DAsync_v2", kApiTypeDriver);

    lretval = lcuMemcpy2DAsync_v2(pCopy, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpy2DAsync_v2 cuMemcpy2DAsync_v2


#undef cuMemcpy3DAsync_v2
CUresult cuMemcpy3DAsync_v2(CUDA_MEMCPY3D const * pCopy, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpy3DAsync_v2) (CUDA_MEMCPY3D const *, CUstream) = (CUresult (*)(CUDA_MEMCPY3D const *, CUstream))dlsym(RTLD_NEXT, "cuMemcpy3DAsync_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpy3DAsync_v2", kApiTypeDriver);

    lretval = lcuMemcpy3DAsync_v2(pCopy, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpy3DAsync_v2 cuMemcpy3DAsync_v2


#undef cuMemcpy3DPeerAsync
CUresult cuMemcpy3DPeerAsync(CUDA_MEMCPY3D_PEER const * pCopy, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemcpy3DPeerAsync) (CUDA_MEMCPY3D_PEER const *, CUstream) = (CUresult (*)(CUDA_MEMCPY3D_PEER const *, CUstream))dlsym(RTLD_NEXT, "cuMemcpy3DPeerAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemcpy3DPeerAsync", kApiTypeDriver);

    lretval = lcuMemcpy3DPeerAsync(pCopy, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemcpy3DPeerAsync cuMemcpy3DPeerAsync


#undef cuMemsetD8_v2
CUresult cuMemsetD8_v2(CUdeviceptr dstDevice, unsigned char uc, size_t N){
    CUresult lretval;
    CUresult (*lcuMemsetD8_v2) (CUdeviceptr, unsigned char, size_t) = (CUresult (*)(CUdeviceptr, unsigned char, size_t))dlsym(RTLD_NEXT, "cuMemsetD8_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD8_v2", kApiTypeDriver);

    lretval = lcuMemsetD8_v2(dstDevice, uc, N);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD8_v2 cuMemsetD8_v2


#undef cuMemsetD16_v2
CUresult cuMemsetD16_v2(CUdeviceptr dstDevice, short unsigned int us, size_t N){
    CUresult lretval;
    CUresult (*lcuMemsetD16_v2) (CUdeviceptr, short unsigned int, size_t) = (CUresult (*)(CUdeviceptr, short unsigned int, size_t))dlsym(RTLD_NEXT, "cuMemsetD16_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD16_v2", kApiTypeDriver);

    lretval = lcuMemsetD16_v2(dstDevice, us, N);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD16_v2 cuMemsetD16_v2


#undef cuMemsetD32_v2
CUresult cuMemsetD32_v2(CUdeviceptr dstDevice, unsigned int ui, size_t N){
    CUresult lretval;
    CUresult (*lcuMemsetD32_v2) (CUdeviceptr, unsigned int, size_t) = (CUresult (*)(CUdeviceptr, unsigned int, size_t))dlsym(RTLD_NEXT, "cuMemsetD32_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD32_v2", kApiTypeDriver);

    lretval = lcuMemsetD32_v2(dstDevice, ui, N);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD32_v2 cuMemsetD32_v2


#undef cuMemsetD2D8_v2
CUresult cuMemsetD2D8_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height){
    CUresult lretval;
    CUresult (*lcuMemsetD2D8_v2) (CUdeviceptr, size_t, unsigned char, size_t, size_t) = (CUresult (*)(CUdeviceptr, size_t, unsigned char, size_t, size_t))dlsym(RTLD_NEXT, "cuMemsetD2D8_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD2D8_v2", kApiTypeDriver);

    lretval = lcuMemsetD2D8_v2(dstDevice, dstPitch, uc, Width, Height);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD2D8_v2 cuMemsetD2D8_v2


#undef cuMemsetD2D16_v2
CUresult cuMemsetD2D16_v2(CUdeviceptr dstDevice, size_t dstPitch, short unsigned int us, size_t Width, size_t Height){
    CUresult lretval;
    CUresult (*lcuMemsetD2D16_v2) (CUdeviceptr, size_t, short unsigned int, size_t, size_t) = (CUresult (*)(CUdeviceptr, size_t, short unsigned int, size_t, size_t))dlsym(RTLD_NEXT, "cuMemsetD2D16_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD2D16_v2", kApiTypeDriver);

    lretval = lcuMemsetD2D16_v2(dstDevice, dstPitch, us, Width, Height);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD2D16_v2 cuMemsetD2D16_v2


#undef cuMemsetD2D32_v2
CUresult cuMemsetD2D32_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height){
    CUresult lretval;
    CUresult (*lcuMemsetD2D32_v2) (CUdeviceptr, size_t, unsigned int, size_t, size_t) = (CUresult (*)(CUdeviceptr, size_t, unsigned int, size_t, size_t))dlsym(RTLD_NEXT, "cuMemsetD2D32_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD2D32_v2", kApiTypeDriver);

    lretval = lcuMemsetD2D32_v2(dstDevice, dstPitch, ui, Width, Height);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD2D32_v2 cuMemsetD2D32_v2


#undef cuMemsetD8Async
CUresult cuMemsetD8Async(CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemsetD8Async) (CUdeviceptr, unsigned char, size_t, CUstream) = (CUresult (*)(CUdeviceptr, unsigned char, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemsetD8Async");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD8Async", kApiTypeDriver);

    lretval = lcuMemsetD8Async(dstDevice, uc, N, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD8Async cuMemsetD8Async


#undef cuMemsetD16Async
CUresult cuMemsetD16Async(CUdeviceptr dstDevice, short unsigned int us, size_t N, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemsetD16Async) (CUdeviceptr, short unsigned int, size_t, CUstream) = (CUresult (*)(CUdeviceptr, short unsigned int, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemsetD16Async");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD16Async", kApiTypeDriver);

    lretval = lcuMemsetD16Async(dstDevice, us, N, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD16Async cuMemsetD16Async


#undef cuMemsetD32Async
CUresult cuMemsetD32Async(CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemsetD32Async) (CUdeviceptr, unsigned int, size_t, CUstream) = (CUresult (*)(CUdeviceptr, unsigned int, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemsetD32Async");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD32Async", kApiTypeDriver);

    lretval = lcuMemsetD32Async(dstDevice, ui, N, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD32Async cuMemsetD32Async


#undef cuMemsetD2D8Async
CUresult cuMemsetD2D8Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemsetD2D8Async) (CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream) = (CUresult (*)(CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemsetD2D8Async");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD2D8Async", kApiTypeDriver);

    lretval = lcuMemsetD2D8Async(dstDevice, dstPitch, uc, Width, Height, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD2D8Async cuMemsetD2D8Async


#undef cuMemsetD2D16Async
CUresult cuMemsetD2D16Async(CUdeviceptr dstDevice, size_t dstPitch, short unsigned int us, size_t Width, size_t Height, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemsetD2D16Async) (CUdeviceptr, size_t, short unsigned int, size_t, size_t, CUstream) = (CUresult (*)(CUdeviceptr, size_t, short unsigned int, size_t, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemsetD2D16Async");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD2D16Async", kApiTypeDriver);

    lretval = lcuMemsetD2D16Async(dstDevice, dstPitch, us, Width, Height, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD2D16Async cuMemsetD2D16Async


#undef cuMemsetD2D32Async
CUresult cuMemsetD2D32Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemsetD2D32Async) (CUdeviceptr, size_t, unsigned int, size_t, size_t, CUstream) = (CUresult (*)(CUdeviceptr, size_t, unsigned int, size_t, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemsetD2D32Async");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemsetD2D32Async", kApiTypeDriver);

    lretval = lcuMemsetD2D32Async(dstDevice, dstPitch, ui, Width, Height, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemsetD2D32Async cuMemsetD2D32Async


#undef cuArrayCreate_v2
CUresult cuArrayCreate_v2(CUarray * pHandle, CUDA_ARRAY_DESCRIPTOR const * pAllocateArray){
    CUresult lretval;
    CUresult (*lcuArrayCreate_v2) (CUarray *, CUDA_ARRAY_DESCRIPTOR const *) = (CUresult (*)(CUarray *, CUDA_ARRAY_DESCRIPTOR const *))dlsym(RTLD_NEXT, "cuArrayCreate_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuArrayCreate_v2", kApiTypeDriver);

    lretval = lcuArrayCreate_v2(pHandle, pAllocateArray);
    
    /* post exeuction logics */

    return lretval;
}
#define cuArrayCreate_v2 cuArrayCreate_v2


#undef cuArrayGetDescriptor_v2
CUresult cuArrayGetDescriptor_v2(CUDA_ARRAY_DESCRIPTOR * pArrayDescriptor, CUarray hArray){
    CUresult lretval;
    CUresult (*lcuArrayGetDescriptor_v2) (CUDA_ARRAY_DESCRIPTOR *, CUarray) = (CUresult (*)(CUDA_ARRAY_DESCRIPTOR *, CUarray))dlsym(RTLD_NEXT, "cuArrayGetDescriptor_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuArrayGetDescriptor_v2", kApiTypeDriver);

    lretval = lcuArrayGetDescriptor_v2(pArrayDescriptor, hArray);
    
    /* post exeuction logics */

    return lretval;
}
#define cuArrayGetDescriptor_v2 cuArrayGetDescriptor_v2


#undef cuArrayGetSparseProperties
CUresult cuArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES * sparseProperties, CUarray array){
    CUresult lretval;
    CUresult (*lcuArrayGetSparseProperties) (CUDA_ARRAY_SPARSE_PROPERTIES *, CUarray) = (CUresult (*)(CUDA_ARRAY_SPARSE_PROPERTIES *, CUarray))dlsym(RTLD_NEXT, "cuArrayGetSparseProperties");
    
    /* pre exeuction logics */
    ac.add_counter("cuArrayGetSparseProperties", kApiTypeDriver);

    lretval = lcuArrayGetSparseProperties(sparseProperties, array);
    
    /* post exeuction logics */

    return lretval;
}
#define cuArrayGetSparseProperties cuArrayGetSparseProperties


#undef cuMipmappedArrayGetSparseProperties
CUresult cuMipmappedArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES * sparseProperties, CUmipmappedArray mipmap){
    CUresult lretval;
    CUresult (*lcuMipmappedArrayGetSparseProperties) (CUDA_ARRAY_SPARSE_PROPERTIES *, CUmipmappedArray) = (CUresult (*)(CUDA_ARRAY_SPARSE_PROPERTIES *, CUmipmappedArray))dlsym(RTLD_NEXT, "cuMipmappedArrayGetSparseProperties");
    
    /* pre exeuction logics */
    ac.add_counter("cuMipmappedArrayGetSparseProperties", kApiTypeDriver);

    lretval = lcuMipmappedArrayGetSparseProperties(sparseProperties, mipmap);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMipmappedArrayGetSparseProperties cuMipmappedArrayGetSparseProperties


#undef cuArrayGetPlane
CUresult cuArrayGetPlane(CUarray * pPlaneArray, CUarray hArray, unsigned int planeIdx){
    CUresult lretval;
    CUresult (*lcuArrayGetPlane) (CUarray *, CUarray, unsigned int) = (CUresult (*)(CUarray *, CUarray, unsigned int))dlsym(RTLD_NEXT, "cuArrayGetPlane");
    
    /* pre exeuction logics */
    ac.add_counter("cuArrayGetPlane", kApiTypeDriver);

    lretval = lcuArrayGetPlane(pPlaneArray, hArray, planeIdx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuArrayGetPlane cuArrayGetPlane


#undef cuArrayDestroy
CUresult cuArrayDestroy(CUarray hArray){
    CUresult lretval;
    CUresult (*lcuArrayDestroy) (CUarray) = (CUresult (*)(CUarray))dlsym(RTLD_NEXT, "cuArrayDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cuArrayDestroy", kApiTypeDriver);

    lretval = lcuArrayDestroy(hArray);
    
    /* post exeuction logics */

    return lretval;
}
#define cuArrayDestroy cuArrayDestroy


#undef cuArray3DCreate_v2
CUresult cuArray3DCreate_v2(CUarray * pHandle, CUDA_ARRAY3D_DESCRIPTOR const * pAllocateArray){
    CUresult lretval;
    CUresult (*lcuArray3DCreate_v2) (CUarray *, CUDA_ARRAY3D_DESCRIPTOR const *) = (CUresult (*)(CUarray *, CUDA_ARRAY3D_DESCRIPTOR const *))dlsym(RTLD_NEXT, "cuArray3DCreate_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuArray3DCreate_v2", kApiTypeDriver);

    lretval = lcuArray3DCreate_v2(pHandle, pAllocateArray);
    
    /* post exeuction logics */

    return lretval;
}
#define cuArray3DCreate_v2 cuArray3DCreate_v2


#undef cuArray3DGetDescriptor_v2
CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR * pArrayDescriptor, CUarray hArray){
    CUresult lretval;
    CUresult (*lcuArray3DGetDescriptor_v2) (CUDA_ARRAY3D_DESCRIPTOR *, CUarray) = (CUresult (*)(CUDA_ARRAY3D_DESCRIPTOR *, CUarray))dlsym(RTLD_NEXT, "cuArray3DGetDescriptor_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuArray3DGetDescriptor_v2", kApiTypeDriver);

    lretval = lcuArray3DGetDescriptor_v2(pArrayDescriptor, hArray);
    
    /* post exeuction logics */

    return lretval;
}
#define cuArray3DGetDescriptor_v2 cuArray3DGetDescriptor_v2


#undef cuMipmappedArrayCreate
CUresult cuMipmappedArrayCreate(CUmipmappedArray * pHandle, CUDA_ARRAY3D_DESCRIPTOR const * pMipmappedArrayDesc, unsigned int numMipmapLevels){
    CUresult lretval;
    CUresult (*lcuMipmappedArrayCreate) (CUmipmappedArray *, CUDA_ARRAY3D_DESCRIPTOR const *, unsigned int) = (CUresult (*)(CUmipmappedArray *, CUDA_ARRAY3D_DESCRIPTOR const *, unsigned int))dlsym(RTLD_NEXT, "cuMipmappedArrayCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuMipmappedArrayCreate", kApiTypeDriver);

    lretval = lcuMipmappedArrayCreate(pHandle, pMipmappedArrayDesc, numMipmapLevels);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMipmappedArrayCreate cuMipmappedArrayCreate


#undef cuMipmappedArrayGetLevel
CUresult cuMipmappedArrayGetLevel(CUarray * pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int level){
    CUresult lretval;
    CUresult (*lcuMipmappedArrayGetLevel) (CUarray *, CUmipmappedArray, unsigned int) = (CUresult (*)(CUarray *, CUmipmappedArray, unsigned int))dlsym(RTLD_NEXT, "cuMipmappedArrayGetLevel");
    
    /* pre exeuction logics */
    ac.add_counter("cuMipmappedArrayGetLevel", kApiTypeDriver);

    lretval = lcuMipmappedArrayGetLevel(pLevelArray, hMipmappedArray, level);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMipmappedArrayGetLevel cuMipmappedArrayGetLevel


#undef cuMipmappedArrayDestroy
CUresult cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray){
    CUresult lretval;
    CUresult (*lcuMipmappedArrayDestroy) (CUmipmappedArray) = (CUresult (*)(CUmipmappedArray))dlsym(RTLD_NEXT, "cuMipmappedArrayDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cuMipmappedArrayDestroy", kApiTypeDriver);

    lretval = lcuMipmappedArrayDestroy(hMipmappedArray);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMipmappedArrayDestroy cuMipmappedArrayDestroy


#undef cuMemAddressReserve
CUresult cuMemAddressReserve(CUdeviceptr * ptr, size_t size, size_t alignment, CUdeviceptr addr, long long unsigned int flags){
    CUresult lretval;
    CUresult (*lcuMemAddressReserve) (CUdeviceptr *, size_t, size_t, CUdeviceptr, long long unsigned int) = (CUresult (*)(CUdeviceptr *, size_t, size_t, CUdeviceptr, long long unsigned int))dlsym(RTLD_NEXT, "cuMemAddressReserve");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemAddressReserve", kApiTypeDriver);

    lretval = lcuMemAddressReserve(ptr, size, alignment, addr, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemAddressReserve cuMemAddressReserve


#undef cuMemAddressFree
CUresult cuMemAddressFree(CUdeviceptr ptr, size_t size){
    CUresult lretval;
    CUresult (*lcuMemAddressFree) (CUdeviceptr, size_t) = (CUresult (*)(CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuMemAddressFree");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemAddressFree", kApiTypeDriver);

    lretval = lcuMemAddressFree(ptr, size);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemAddressFree cuMemAddressFree


#undef cuMemCreate
CUresult cuMemCreate(CUmemGenericAllocationHandle * handle, size_t size, CUmemAllocationProp const * prop, long long unsigned int flags){
    CUresult lretval;
    CUresult (*lcuMemCreate) (CUmemGenericAllocationHandle *, size_t, CUmemAllocationProp const *, long long unsigned int) = (CUresult (*)(CUmemGenericAllocationHandle *, size_t, CUmemAllocationProp const *, long long unsigned int))dlsym(RTLD_NEXT, "cuMemCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemCreate", kApiTypeDriver);

    lretval = lcuMemCreate(handle, size, prop, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemCreate cuMemCreate


#undef cuMemRelease
CUresult cuMemRelease(CUmemGenericAllocationHandle handle){
    CUresult lretval;
    CUresult (*lcuMemRelease) (CUmemGenericAllocationHandle) = (CUresult (*)(CUmemGenericAllocationHandle))dlsym(RTLD_NEXT, "cuMemRelease");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemRelease", kApiTypeDriver);

    lretval = lcuMemRelease(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemRelease cuMemRelease


#undef cuMemMap
CUresult cuMemMap(CUdeviceptr ptr, size_t size, size_t offset, CUmemGenericAllocationHandle handle, long long unsigned int flags){
    CUresult lretval;
    CUresult (*lcuMemMap) (CUdeviceptr, size_t, size_t, CUmemGenericAllocationHandle, long long unsigned int) = (CUresult (*)(CUdeviceptr, size_t, size_t, CUmemGenericAllocationHandle, long long unsigned int))dlsym(RTLD_NEXT, "cuMemMap");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemMap", kApiTypeDriver);

    lretval = lcuMemMap(ptr, size, offset, handle, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemMap cuMemMap


#undef cuMemMapArrayAsync
CUresult cuMemMapArrayAsync(CUarrayMapInfo * mapInfoList, unsigned int count, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemMapArrayAsync) (CUarrayMapInfo *, unsigned int, CUstream) = (CUresult (*)(CUarrayMapInfo *, unsigned int, CUstream))dlsym(RTLD_NEXT, "cuMemMapArrayAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemMapArrayAsync", kApiTypeDriver);

    lretval = lcuMemMapArrayAsync(mapInfoList, count, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemMapArrayAsync cuMemMapArrayAsync


#undef cuMemUnmap
CUresult cuMemUnmap(CUdeviceptr ptr, size_t size){
    CUresult lretval;
    CUresult (*lcuMemUnmap) (CUdeviceptr, size_t) = (CUresult (*)(CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuMemUnmap");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemUnmap", kApiTypeDriver);

    lretval = lcuMemUnmap(ptr, size);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemUnmap cuMemUnmap


#undef cuMemSetAccess
CUresult cuMemSetAccess(CUdeviceptr ptr, size_t size, CUmemAccessDesc const * desc, size_t count){
    CUresult lretval;
    CUresult (*lcuMemSetAccess) (CUdeviceptr, size_t, CUmemAccessDesc const *, size_t) = (CUresult (*)(CUdeviceptr, size_t, CUmemAccessDesc const *, size_t))dlsym(RTLD_NEXT, "cuMemSetAccess");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemSetAccess", kApiTypeDriver);

    lretval = lcuMemSetAccess(ptr, size, desc, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemSetAccess cuMemSetAccess


#undef cuMemGetAccess
CUresult cuMemGetAccess(long long unsigned int * flags, CUmemLocation const * location, CUdeviceptr ptr){
    CUresult lretval;
    CUresult (*lcuMemGetAccess) (long long unsigned int *, CUmemLocation const *, CUdeviceptr) = (CUresult (*)(long long unsigned int *, CUmemLocation const *, CUdeviceptr))dlsym(RTLD_NEXT, "cuMemGetAccess");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemGetAccess", kApiTypeDriver);

    lretval = lcuMemGetAccess(flags, location, ptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemGetAccess cuMemGetAccess


#undef cuMemExportToShareableHandle
CUresult cuMemExportToShareableHandle(void * shareableHandle, CUmemGenericAllocationHandle handle, CUmemAllocationHandleType handleType, long long unsigned int flags){
    CUresult lretval;
    CUresult (*lcuMemExportToShareableHandle) (void *, CUmemGenericAllocationHandle, CUmemAllocationHandleType, long long unsigned int) = (CUresult (*)(void *, CUmemGenericAllocationHandle, CUmemAllocationHandleType, long long unsigned int))dlsym(RTLD_NEXT, "cuMemExportToShareableHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemExportToShareableHandle", kApiTypeDriver);

    lretval = lcuMemExportToShareableHandle(shareableHandle, handle, handleType, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemExportToShareableHandle cuMemExportToShareableHandle


#undef cuMemImportFromShareableHandle
CUresult cuMemImportFromShareableHandle(CUmemGenericAllocationHandle * handle, void * osHandle, CUmemAllocationHandleType shHandleType){
    CUresult lretval;
    CUresult (*lcuMemImportFromShareableHandle) (CUmemGenericAllocationHandle *, void *, CUmemAllocationHandleType) = (CUresult (*)(CUmemGenericAllocationHandle *, void *, CUmemAllocationHandleType))dlsym(RTLD_NEXT, "cuMemImportFromShareableHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemImportFromShareableHandle", kApiTypeDriver);

    lretval = lcuMemImportFromShareableHandle(handle, osHandle, shHandleType);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemImportFromShareableHandle cuMemImportFromShareableHandle


#undef cuMemGetAllocationGranularity
CUresult cuMemGetAllocationGranularity(size_t * granularity, CUmemAllocationProp const * prop, CUmemAllocationGranularity_flags option){
    CUresult lretval;
    CUresult (*lcuMemGetAllocationGranularity) (size_t *, CUmemAllocationProp const *, CUmemAllocationGranularity_flags) = (CUresult (*)(size_t *, CUmemAllocationProp const *, CUmemAllocationGranularity_flags))dlsym(RTLD_NEXT, "cuMemGetAllocationGranularity");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemGetAllocationGranularity", kApiTypeDriver);

    lretval = lcuMemGetAllocationGranularity(granularity, prop, option);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemGetAllocationGranularity cuMemGetAllocationGranularity


#undef cuMemGetAllocationPropertiesFromHandle
CUresult cuMemGetAllocationPropertiesFromHandle(CUmemAllocationProp * prop, CUmemGenericAllocationHandle handle){
    CUresult lretval;
    CUresult (*lcuMemGetAllocationPropertiesFromHandle) (CUmemAllocationProp *, CUmemGenericAllocationHandle) = (CUresult (*)(CUmemAllocationProp *, CUmemGenericAllocationHandle))dlsym(RTLD_NEXT, "cuMemGetAllocationPropertiesFromHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemGetAllocationPropertiesFromHandle", kApiTypeDriver);

    lretval = lcuMemGetAllocationPropertiesFromHandle(prop, handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemGetAllocationPropertiesFromHandle cuMemGetAllocationPropertiesFromHandle


#undef cuMemRetainAllocationHandle
CUresult cuMemRetainAllocationHandle(CUmemGenericAllocationHandle * handle, void * addr){
    CUresult lretval;
    CUresult (*lcuMemRetainAllocationHandle) (CUmemGenericAllocationHandle *, void *) = (CUresult (*)(CUmemGenericAllocationHandle *, void *))dlsym(RTLD_NEXT, "cuMemRetainAllocationHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemRetainAllocationHandle", kApiTypeDriver);

    lretval = lcuMemRetainAllocationHandle(handle, addr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemRetainAllocationHandle cuMemRetainAllocationHandle


#undef cuMemFreeAsync
CUresult cuMemFreeAsync(CUdeviceptr dptr, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemFreeAsync) (CUdeviceptr, CUstream) = (CUresult (*)(CUdeviceptr, CUstream))dlsym(RTLD_NEXT, "cuMemFreeAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemFreeAsync", kApiTypeDriver);

    lretval = lcuMemFreeAsync(dptr, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemFreeAsync cuMemFreeAsync


#undef cuMemAllocAsync
CUresult cuMemAllocAsync(CUdeviceptr * dptr, size_t bytesize, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemAllocAsync) (CUdeviceptr *, size_t, CUstream) = (CUresult (*)(CUdeviceptr *, size_t, CUstream))dlsym(RTLD_NEXT, "cuMemAllocAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemAllocAsync", kApiTypeDriver);

    lretval = lcuMemAllocAsync(dptr, bytesize, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemAllocAsync cuMemAllocAsync


#undef cuMemPoolTrimTo
CUresult cuMemPoolTrimTo(CUmemoryPool pool, size_t minBytesToKeep){
    CUresult lretval;
    CUresult (*lcuMemPoolTrimTo) (CUmemoryPool, size_t) = (CUresult (*)(CUmemoryPool, size_t))dlsym(RTLD_NEXT, "cuMemPoolTrimTo");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolTrimTo", kApiTypeDriver);

    lretval = lcuMemPoolTrimTo(pool, minBytesToKeep);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolTrimTo cuMemPoolTrimTo


#undef cuMemPoolSetAttribute
CUresult cuMemPoolSetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void * value){
    CUresult lretval;
    CUresult (*lcuMemPoolSetAttribute) (CUmemoryPool, CUmemPool_attribute, void *) = (CUresult (*)(CUmemoryPool, CUmemPool_attribute, void *))dlsym(RTLD_NEXT, "cuMemPoolSetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolSetAttribute", kApiTypeDriver);

    lretval = lcuMemPoolSetAttribute(pool, attr, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolSetAttribute cuMemPoolSetAttribute


#undef cuMemPoolGetAttribute
CUresult cuMemPoolGetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void * value){
    CUresult lretval;
    CUresult (*lcuMemPoolGetAttribute) (CUmemoryPool, CUmemPool_attribute, void *) = (CUresult (*)(CUmemoryPool, CUmemPool_attribute, void *))dlsym(RTLD_NEXT, "cuMemPoolGetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolGetAttribute", kApiTypeDriver);

    lretval = lcuMemPoolGetAttribute(pool, attr, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolGetAttribute cuMemPoolGetAttribute


#undef cuMemPoolSetAccess
CUresult cuMemPoolSetAccess(CUmemoryPool pool, CUmemAccessDesc const * map, size_t count){
    CUresult lretval;
    CUresult (*lcuMemPoolSetAccess) (CUmemoryPool, CUmemAccessDesc const *, size_t) = (CUresult (*)(CUmemoryPool, CUmemAccessDesc const *, size_t))dlsym(RTLD_NEXT, "cuMemPoolSetAccess");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolSetAccess", kApiTypeDriver);

    lretval = lcuMemPoolSetAccess(pool, map, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolSetAccess cuMemPoolSetAccess


#undef cuMemPoolGetAccess
CUresult cuMemPoolGetAccess(CUmemAccess_flags * flags, CUmemoryPool memPool, CUmemLocation * location){
    CUresult lretval;
    CUresult (*lcuMemPoolGetAccess) (CUmemAccess_flags *, CUmemoryPool, CUmemLocation *) = (CUresult (*)(CUmemAccess_flags *, CUmemoryPool, CUmemLocation *))dlsym(RTLD_NEXT, "cuMemPoolGetAccess");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolGetAccess", kApiTypeDriver);

    lretval = lcuMemPoolGetAccess(flags, memPool, location);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolGetAccess cuMemPoolGetAccess


#undef cuMemPoolCreate
CUresult cuMemPoolCreate(CUmemoryPool * pool, CUmemPoolProps const * poolProps){
    CUresult lretval;
    CUresult (*lcuMemPoolCreate) (CUmemoryPool *, CUmemPoolProps const *) = (CUresult (*)(CUmemoryPool *, CUmemPoolProps const *))dlsym(RTLD_NEXT, "cuMemPoolCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolCreate", kApiTypeDriver);

    lretval = lcuMemPoolCreate(pool, poolProps);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolCreate cuMemPoolCreate


#undef cuMemPoolDestroy
CUresult cuMemPoolDestroy(CUmemoryPool pool){
    CUresult lretval;
    CUresult (*lcuMemPoolDestroy) (CUmemoryPool) = (CUresult (*)(CUmemoryPool))dlsym(RTLD_NEXT, "cuMemPoolDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolDestroy", kApiTypeDriver);

    lretval = lcuMemPoolDestroy(pool);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolDestroy cuMemPoolDestroy


#undef cuMemAllocFromPoolAsync
CUresult cuMemAllocFromPoolAsync(CUdeviceptr * dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemAllocFromPoolAsync) (CUdeviceptr *, size_t, CUmemoryPool, CUstream) = (CUresult (*)(CUdeviceptr *, size_t, CUmemoryPool, CUstream))dlsym(RTLD_NEXT, "cuMemAllocFromPoolAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemAllocFromPoolAsync", kApiTypeDriver);

    lretval = lcuMemAllocFromPoolAsync(dptr, bytesize, pool, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemAllocFromPoolAsync cuMemAllocFromPoolAsync


#undef cuMemPoolExportToShareableHandle
CUresult cuMemPoolExportToShareableHandle(void * handle_out, CUmemoryPool pool, CUmemAllocationHandleType handleType, long long unsigned int flags){
    CUresult lretval;
    CUresult (*lcuMemPoolExportToShareableHandle) (void *, CUmemoryPool, CUmemAllocationHandleType, long long unsigned int) = (CUresult (*)(void *, CUmemoryPool, CUmemAllocationHandleType, long long unsigned int))dlsym(RTLD_NEXT, "cuMemPoolExportToShareableHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolExportToShareableHandle", kApiTypeDriver);

    lretval = lcuMemPoolExportToShareableHandle(handle_out, pool, handleType, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolExportToShareableHandle cuMemPoolExportToShareableHandle


#undef cuMemPoolImportFromShareableHandle
CUresult cuMemPoolImportFromShareableHandle(CUmemoryPool * pool_out, void * handle, CUmemAllocationHandleType handleType, long long unsigned int flags){
    CUresult lretval;
    CUresult (*lcuMemPoolImportFromShareableHandle) (CUmemoryPool *, void *, CUmemAllocationHandleType, long long unsigned int) = (CUresult (*)(CUmemoryPool *, void *, CUmemAllocationHandleType, long long unsigned int))dlsym(RTLD_NEXT, "cuMemPoolImportFromShareableHandle");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolImportFromShareableHandle", kApiTypeDriver);

    lretval = lcuMemPoolImportFromShareableHandle(pool_out, handle, handleType, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolImportFromShareableHandle cuMemPoolImportFromShareableHandle


#undef cuMemPoolExportPointer
CUresult cuMemPoolExportPointer(CUmemPoolPtrExportData * shareData_out, CUdeviceptr ptr){
    CUresult lretval;
    CUresult (*lcuMemPoolExportPointer) (CUmemPoolPtrExportData *, CUdeviceptr) = (CUresult (*)(CUmemPoolPtrExportData *, CUdeviceptr))dlsym(RTLD_NEXT, "cuMemPoolExportPointer");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolExportPointer", kApiTypeDriver);

    lretval = lcuMemPoolExportPointer(shareData_out, ptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolExportPointer cuMemPoolExportPointer


#undef cuMemPoolImportPointer
CUresult cuMemPoolImportPointer(CUdeviceptr * ptr_out, CUmemoryPool pool, CUmemPoolPtrExportData * shareData){
    CUresult lretval;
    CUresult (*lcuMemPoolImportPointer) (CUdeviceptr *, CUmemoryPool, CUmemPoolPtrExportData *) = (CUresult (*)(CUdeviceptr *, CUmemoryPool, CUmemPoolPtrExportData *))dlsym(RTLD_NEXT, "cuMemPoolImportPointer");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPoolImportPointer", kApiTypeDriver);

    lretval = lcuMemPoolImportPointer(ptr_out, pool, shareData);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPoolImportPointer cuMemPoolImportPointer


#undef cuPointerGetAttribute
CUresult cuPointerGetAttribute(void * data, CUpointer_attribute attribute, CUdeviceptr ptr){
    CUresult lretval;
    CUresult (*lcuPointerGetAttribute) (void *, CUpointer_attribute, CUdeviceptr) = (CUresult (*)(void *, CUpointer_attribute, CUdeviceptr))dlsym(RTLD_NEXT, "cuPointerGetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuPointerGetAttribute", kApiTypeDriver);

    lretval = lcuPointerGetAttribute(data, attribute, ptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuPointerGetAttribute cuPointerGetAttribute


#undef cuMemPrefetchAsync
CUresult cuMemPrefetchAsync(CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuMemPrefetchAsync) (CUdeviceptr, size_t, CUdevice, CUstream) = (CUresult (*)(CUdeviceptr, size_t, CUdevice, CUstream))dlsym(RTLD_NEXT, "cuMemPrefetchAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemPrefetchAsync", kApiTypeDriver);

    lretval = lcuMemPrefetchAsync(devPtr, count, dstDevice, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemPrefetchAsync cuMemPrefetchAsync


#undef cuMemAdvise
CUresult cuMemAdvise(CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device){
    CUresult lretval;
    CUresult (*lcuMemAdvise) (CUdeviceptr, size_t, CUmem_advise, CUdevice) = (CUresult (*)(CUdeviceptr, size_t, CUmem_advise, CUdevice))dlsym(RTLD_NEXT, "cuMemAdvise");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemAdvise", kApiTypeDriver);

    lretval = lcuMemAdvise(devPtr, count, advice, device);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemAdvise cuMemAdvise


#undef cuMemRangeGetAttribute
CUresult cuMemRangeGetAttribute(void * data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count){
    CUresult lretval;
    CUresult (*lcuMemRangeGetAttribute) (void *, size_t, CUmem_range_attribute, CUdeviceptr, size_t) = (CUresult (*)(void *, size_t, CUmem_range_attribute, CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuMemRangeGetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemRangeGetAttribute", kApiTypeDriver);

    lretval = lcuMemRangeGetAttribute(data, dataSize, attribute, devPtr, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemRangeGetAttribute cuMemRangeGetAttribute


#undef cuMemRangeGetAttributes
CUresult cuMemRangeGetAttributes(void * * data, size_t * dataSizes, CUmem_range_attribute * attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count){
    CUresult lretval;
    CUresult (*lcuMemRangeGetAttributes) (void * *, size_t *, CUmem_range_attribute *, size_t, CUdeviceptr, size_t) = (CUresult (*)(void * *, size_t *, CUmem_range_attribute *, size_t, CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuMemRangeGetAttributes");
    
    /* pre exeuction logics */
    ac.add_counter("cuMemRangeGetAttributes", kApiTypeDriver);

    lretval = lcuMemRangeGetAttributes(data, dataSizes, attributes, numAttributes, devPtr, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cuMemRangeGetAttributes cuMemRangeGetAttributes


#undef cuPointerSetAttribute
CUresult cuPointerSetAttribute(void const * value, CUpointer_attribute attribute, CUdeviceptr ptr){
    CUresult lretval;
    CUresult (*lcuPointerSetAttribute) (void const *, CUpointer_attribute, CUdeviceptr) = (CUresult (*)(void const *, CUpointer_attribute, CUdeviceptr))dlsym(RTLD_NEXT, "cuPointerSetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuPointerSetAttribute", kApiTypeDriver);

    lretval = lcuPointerSetAttribute(value, attribute, ptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuPointerSetAttribute cuPointerSetAttribute


#undef cuPointerGetAttributes
CUresult cuPointerGetAttributes(unsigned int numAttributes, CUpointer_attribute * attributes, void * * data, CUdeviceptr ptr){
    CUresult lretval;
    CUresult (*lcuPointerGetAttributes) (unsigned int, CUpointer_attribute *, void * *, CUdeviceptr) = (CUresult (*)(unsigned int, CUpointer_attribute *, void * *, CUdeviceptr))dlsym(RTLD_NEXT, "cuPointerGetAttributes");
    
    /* pre exeuction logics */
    ac.add_counter("cuPointerGetAttributes", kApiTypeDriver);

    lretval = lcuPointerGetAttributes(numAttributes, attributes, data, ptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cuPointerGetAttributes cuPointerGetAttributes


#undef cuStreamCreate
CUresult cuStreamCreate(CUstream * phStream, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuStreamCreate) (CUstream *, unsigned int) = (CUresult (*)(CUstream *, unsigned int))dlsym(RTLD_NEXT, "cuStreamCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamCreate", kApiTypeDriver);

    lretval = lcuStreamCreate(phStream, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamCreate cuStreamCreate


#undef cuStreamCreateWithPriority
CUresult cuStreamCreateWithPriority(CUstream * phStream, unsigned int flags, int priority){
    CUresult lretval;
    CUresult (*lcuStreamCreateWithPriority) (CUstream *, unsigned int, int) = (CUresult (*)(CUstream *, unsigned int, int))dlsym(RTLD_NEXT, "cuStreamCreateWithPriority");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamCreateWithPriority", kApiTypeDriver);

    lretval = lcuStreamCreateWithPriority(phStream, flags, priority);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamCreateWithPriority cuStreamCreateWithPriority


#undef cuStreamGetPriority
CUresult cuStreamGetPriority(CUstream hStream, int * priority){
    CUresult lretval;
    CUresult (*lcuStreamGetPriority) (CUstream, int *) = (CUresult (*)(CUstream, int *))dlsym(RTLD_NEXT, "cuStreamGetPriority");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamGetPriority", kApiTypeDriver);

    lretval = lcuStreamGetPriority(hStream, priority);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamGetPriority cuStreamGetPriority


#undef cuStreamGetFlags
CUresult cuStreamGetFlags(CUstream hStream, unsigned int * flags){
    CUresult lretval;
    CUresult (*lcuStreamGetFlags) (CUstream, unsigned int *) = (CUresult (*)(CUstream, unsigned int *))dlsym(RTLD_NEXT, "cuStreamGetFlags");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamGetFlags", kApiTypeDriver);

    lretval = lcuStreamGetFlags(hStream, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamGetFlags cuStreamGetFlags


#undef cuStreamGetCtx
CUresult cuStreamGetCtx(CUstream hStream, CUcontext * pctx){
    CUresult lretval;
    CUresult (*lcuStreamGetCtx) (CUstream, CUcontext *) = (CUresult (*)(CUstream, CUcontext *))dlsym(RTLD_NEXT, "cuStreamGetCtx");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamGetCtx", kApiTypeDriver);

    lretval = lcuStreamGetCtx(hStream, pctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamGetCtx cuStreamGetCtx


#undef cuStreamWaitEvent
CUresult cuStreamWaitEvent(CUstream hStream, CUevent hEvent, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuStreamWaitEvent) (CUstream, CUevent, unsigned int) = (CUresult (*)(CUstream, CUevent, unsigned int))dlsym(RTLD_NEXT, "cuStreamWaitEvent");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamWaitEvent", kApiTypeDriver);

    lretval = lcuStreamWaitEvent(hStream, hEvent, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamWaitEvent cuStreamWaitEvent


#undef cuStreamAddCallback
CUresult cuStreamAddCallback(CUstream hStream, CUstreamCallback callback, void * userData, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuStreamAddCallback) (CUstream, CUstreamCallback, void *, unsigned int) = (CUresult (*)(CUstream, CUstreamCallback, void *, unsigned int))dlsym(RTLD_NEXT, "cuStreamAddCallback");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamAddCallback", kApiTypeDriver);

    lretval = lcuStreamAddCallback(hStream, callback, userData, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamAddCallback cuStreamAddCallback


#undef cuStreamBeginCapture_v2
CUresult cuStreamBeginCapture_v2(CUstream hStream, CUstreamCaptureMode mode){
    CUresult lretval;
    CUresult (*lcuStreamBeginCapture_v2) (CUstream, CUstreamCaptureMode) = (CUresult (*)(CUstream, CUstreamCaptureMode))dlsym(RTLD_NEXT, "cuStreamBeginCapture_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamBeginCapture_v2", kApiTypeDriver);

    lretval = lcuStreamBeginCapture_v2(hStream, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamBeginCapture_v2 cuStreamBeginCapture_v2


#undef cuThreadExchangeStreamCaptureMode
CUresult cuThreadExchangeStreamCaptureMode(CUstreamCaptureMode * mode){
    CUresult lretval;
    CUresult (*lcuThreadExchangeStreamCaptureMode) (CUstreamCaptureMode *) = (CUresult (*)(CUstreamCaptureMode *))dlsym(RTLD_NEXT, "cuThreadExchangeStreamCaptureMode");
    
    /* pre exeuction logics */
    ac.add_counter("cuThreadExchangeStreamCaptureMode", kApiTypeDriver);

    lretval = lcuThreadExchangeStreamCaptureMode(mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cuThreadExchangeStreamCaptureMode cuThreadExchangeStreamCaptureMode


#undef cuStreamEndCapture
CUresult cuStreamEndCapture(CUstream hStream, CUgraph * phGraph){
    CUresult lretval;
    CUresult (*lcuStreamEndCapture) (CUstream, CUgraph *) = (CUresult (*)(CUstream, CUgraph *))dlsym(RTLD_NEXT, "cuStreamEndCapture");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamEndCapture", kApiTypeDriver);

    lretval = lcuStreamEndCapture(hStream, phGraph);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamEndCapture cuStreamEndCapture


#undef cuStreamIsCapturing
CUresult cuStreamIsCapturing(CUstream hStream, CUstreamCaptureStatus * captureStatus){
    CUresult lretval;
    CUresult (*lcuStreamIsCapturing) (CUstream, CUstreamCaptureStatus *) = (CUresult (*)(CUstream, CUstreamCaptureStatus *))dlsym(RTLD_NEXT, "cuStreamIsCapturing");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamIsCapturing", kApiTypeDriver);

    lretval = lcuStreamIsCapturing(hStream, captureStatus);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamIsCapturing cuStreamIsCapturing


#undef cuStreamGetCaptureInfo
CUresult cuStreamGetCaptureInfo(CUstream hStream, CUstreamCaptureStatus * captureStatus_out, cuuint64_t * id_out){
    CUresult lretval;
    CUresult (*lcuStreamGetCaptureInfo) (CUstream, CUstreamCaptureStatus *, cuuint64_t *) = (CUresult (*)(CUstream, CUstreamCaptureStatus *, cuuint64_t *))dlsym(RTLD_NEXT, "cuStreamGetCaptureInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamGetCaptureInfo", kApiTypeDriver);

    lretval = lcuStreamGetCaptureInfo(hStream, captureStatus_out, id_out);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamGetCaptureInfo cuStreamGetCaptureInfo


#undef cuStreamGetCaptureInfo_v2
CUresult cuStreamGetCaptureInfo_v2(CUstream hStream, CUstreamCaptureStatus * captureStatus_out, cuuint64_t * id_out, CUgraph * graph_out, CUgraphNode const * * dependencies_out, size_t * numDependencies_out){
    CUresult lretval;
    CUresult (*lcuStreamGetCaptureInfo_v2) (CUstream, CUstreamCaptureStatus *, cuuint64_t *, CUgraph *, CUgraphNode const * *, size_t *) = (CUresult (*)(CUstream, CUstreamCaptureStatus *, cuuint64_t *, CUgraph *, CUgraphNode const * *, size_t *))dlsym(RTLD_NEXT, "cuStreamGetCaptureInfo_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamGetCaptureInfo_v2", kApiTypeDriver);

    lretval = lcuStreamGetCaptureInfo_v2(hStream, captureStatus_out, id_out, graph_out, dependencies_out, numDependencies_out);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamGetCaptureInfo_v2 cuStreamGetCaptureInfo_v2


#undef cuStreamUpdateCaptureDependencies
CUresult cuStreamUpdateCaptureDependencies(CUstream hStream, CUgraphNode * dependencies, size_t numDependencies, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuStreamUpdateCaptureDependencies) (CUstream, CUgraphNode *, size_t, unsigned int) = (CUresult (*)(CUstream, CUgraphNode *, size_t, unsigned int))dlsym(RTLD_NEXT, "cuStreamUpdateCaptureDependencies");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamUpdateCaptureDependencies", kApiTypeDriver);

    lretval = lcuStreamUpdateCaptureDependencies(hStream, dependencies, numDependencies, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamUpdateCaptureDependencies cuStreamUpdateCaptureDependencies


#undef cuStreamAttachMemAsync
CUresult cuStreamAttachMemAsync(CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuStreamAttachMemAsync) (CUstream, CUdeviceptr, size_t, unsigned int) = (CUresult (*)(CUstream, CUdeviceptr, size_t, unsigned int))dlsym(RTLD_NEXT, "cuStreamAttachMemAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamAttachMemAsync", kApiTypeDriver);

    lretval = lcuStreamAttachMemAsync(hStream, dptr, length, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamAttachMemAsync cuStreamAttachMemAsync


#undef cuStreamQuery
CUresult cuStreamQuery(CUstream hStream){
    CUresult lretval;
    CUresult (*lcuStreamQuery) (CUstream) = (CUresult (*)(CUstream))dlsym(RTLD_NEXT, "cuStreamQuery");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamQuery", kApiTypeDriver);

    lretval = lcuStreamQuery(hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamQuery cuStreamQuery


#undef cuStreamSynchronize
CUresult cuStreamSynchronize(CUstream hStream){
    CUresult lretval;
    CUresult (*lcuStreamSynchronize) (CUstream) = (CUresult (*)(CUstream))dlsym(RTLD_NEXT, "cuStreamSynchronize");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamSynchronize", kApiTypeDriver);

    lretval = lcuStreamSynchronize(hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamSynchronize cuStreamSynchronize


#undef cuStreamDestroy_v2
CUresult cuStreamDestroy_v2(CUstream hStream){
    CUresult lretval;
    CUresult (*lcuStreamDestroy_v2) (CUstream) = (CUresult (*)(CUstream))dlsym(RTLD_NEXT, "cuStreamDestroy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamDestroy_v2", kApiTypeDriver);

    lretval = lcuStreamDestroy_v2(hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamDestroy_v2 cuStreamDestroy_v2


#undef cuStreamCopyAttributes
CUresult cuStreamCopyAttributes(CUstream dst, CUstream src){
    CUresult lretval;
    CUresult (*lcuStreamCopyAttributes) (CUstream, CUstream) = (CUresult (*)(CUstream, CUstream))dlsym(RTLD_NEXT, "cuStreamCopyAttributes");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamCopyAttributes", kApiTypeDriver);

    lretval = lcuStreamCopyAttributes(dst, src);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamCopyAttributes cuStreamCopyAttributes


#undef cuStreamGetAttribute
CUresult cuStreamGetAttribute(CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue * value_out){
    CUresult lretval;
    CUresult (*lcuStreamGetAttribute) (CUstream, CUstreamAttrID, CUstreamAttrValue *) = (CUresult (*)(CUstream, CUstreamAttrID, CUstreamAttrValue *))dlsym(RTLD_NEXT, "cuStreamGetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamGetAttribute", kApiTypeDriver);

    lretval = lcuStreamGetAttribute(hStream, attr, value_out);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamGetAttribute cuStreamGetAttribute


#undef cuStreamSetAttribute
CUresult cuStreamSetAttribute(CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue const * value){
    CUresult lretval;
    CUresult (*lcuStreamSetAttribute) (CUstream, CUstreamAttrID, CUstreamAttrValue const *) = (CUresult (*)(CUstream, CUstreamAttrID, CUstreamAttrValue const *))dlsym(RTLD_NEXT, "cuStreamSetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamSetAttribute", kApiTypeDriver);

    lretval = lcuStreamSetAttribute(hStream, attr, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamSetAttribute cuStreamSetAttribute


#undef cuEventCreate
CUresult cuEventCreate(CUevent * phEvent, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuEventCreate) (CUevent *, unsigned int) = (CUresult (*)(CUevent *, unsigned int))dlsym(RTLD_NEXT, "cuEventCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuEventCreate", kApiTypeDriver);

    lretval = lcuEventCreate(phEvent, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuEventCreate cuEventCreate


#undef cuEventRecord
CUresult cuEventRecord(CUevent hEvent, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuEventRecord) (CUevent, CUstream) = (CUresult (*)(CUevent, CUstream))dlsym(RTLD_NEXT, "cuEventRecord");
    
    /* pre exeuction logics */
    ac.add_counter("cuEventRecord", kApiTypeDriver);

    lretval = lcuEventRecord(hEvent, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuEventRecord cuEventRecord


#undef cuEventRecordWithFlags
CUresult cuEventRecordWithFlags(CUevent hEvent, CUstream hStream, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuEventRecordWithFlags) (CUevent, CUstream, unsigned int) = (CUresult (*)(CUevent, CUstream, unsigned int))dlsym(RTLD_NEXT, "cuEventRecordWithFlags");
    
    /* pre exeuction logics */
    ac.add_counter("cuEventRecordWithFlags", kApiTypeDriver);

    lretval = lcuEventRecordWithFlags(hEvent, hStream, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuEventRecordWithFlags cuEventRecordWithFlags


#undef cuEventQuery
CUresult cuEventQuery(CUevent hEvent){
    CUresult lretval;
    CUresult (*lcuEventQuery) (CUevent) = (CUresult (*)(CUevent))dlsym(RTLD_NEXT, "cuEventQuery");
    
    /* pre exeuction logics */
    ac.add_counter("cuEventQuery", kApiTypeDriver);

    lretval = lcuEventQuery(hEvent);
    
    /* post exeuction logics */

    return lretval;
}
#define cuEventQuery cuEventQuery


#undef cuEventSynchronize
CUresult cuEventSynchronize(CUevent hEvent){
    CUresult lretval;
    CUresult (*lcuEventSynchronize) (CUevent) = (CUresult (*)(CUevent))dlsym(RTLD_NEXT, "cuEventSynchronize");
    
    /* pre exeuction logics */
    ac.add_counter("cuEventSynchronize", kApiTypeDriver);

    lretval = lcuEventSynchronize(hEvent);
    
    /* post exeuction logics */

    return lretval;
}
#define cuEventSynchronize cuEventSynchronize


#undef cuEventDestroy_v2
CUresult cuEventDestroy_v2(CUevent hEvent){
    CUresult lretval;
    CUresult (*lcuEventDestroy_v2) (CUevent) = (CUresult (*)(CUevent))dlsym(RTLD_NEXT, "cuEventDestroy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuEventDestroy_v2", kApiTypeDriver);

    lretval = lcuEventDestroy_v2(hEvent);
    
    /* post exeuction logics */

    return lretval;
}
#define cuEventDestroy_v2 cuEventDestroy_v2


#undef cuEventElapsedTime
CUresult cuEventElapsedTime(float * pMilliseconds, CUevent hStart, CUevent hEnd){
    CUresult lretval;
    CUresult (*lcuEventElapsedTime) (float *, CUevent, CUevent) = (CUresult (*)(float *, CUevent, CUevent))dlsym(RTLD_NEXT, "cuEventElapsedTime");
    
    /* pre exeuction logics */
    ac.add_counter("cuEventElapsedTime", kApiTypeDriver);

    lretval = lcuEventElapsedTime(pMilliseconds, hStart, hEnd);
    
    /* post exeuction logics */

    return lretval;
}
#define cuEventElapsedTime cuEventElapsedTime


#undef cuImportExternalMemory
CUresult cuImportExternalMemory(CUexternalMemory * extMem_out, CUDA_EXTERNAL_MEMORY_HANDLE_DESC const * memHandleDesc){
    CUresult lretval;
    CUresult (*lcuImportExternalMemory) (CUexternalMemory *, CUDA_EXTERNAL_MEMORY_HANDLE_DESC const *) = (CUresult (*)(CUexternalMemory *, CUDA_EXTERNAL_MEMORY_HANDLE_DESC const *))dlsym(RTLD_NEXT, "cuImportExternalMemory");
    
    /* pre exeuction logics */
    ac.add_counter("cuImportExternalMemory", kApiTypeDriver);

    lretval = lcuImportExternalMemory(extMem_out, memHandleDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cuImportExternalMemory cuImportExternalMemory


#undef cuExternalMemoryGetMappedBuffer
CUresult cuExternalMemoryGetMappedBuffer(CUdeviceptr * devPtr, CUexternalMemory extMem, CUDA_EXTERNAL_MEMORY_BUFFER_DESC const * bufferDesc){
    CUresult lretval;
    CUresult (*lcuExternalMemoryGetMappedBuffer) (CUdeviceptr *, CUexternalMemory, CUDA_EXTERNAL_MEMORY_BUFFER_DESC const *) = (CUresult (*)(CUdeviceptr *, CUexternalMemory, CUDA_EXTERNAL_MEMORY_BUFFER_DESC const *))dlsym(RTLD_NEXT, "cuExternalMemoryGetMappedBuffer");
    
    /* pre exeuction logics */
    ac.add_counter("cuExternalMemoryGetMappedBuffer", kApiTypeDriver);

    lretval = lcuExternalMemoryGetMappedBuffer(devPtr, extMem, bufferDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cuExternalMemoryGetMappedBuffer cuExternalMemoryGetMappedBuffer


#undef cuExternalMemoryGetMappedMipmappedArray
CUresult cuExternalMemoryGetMappedMipmappedArray(CUmipmappedArray * mipmap, CUexternalMemory extMem, CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC const * mipmapDesc){
    CUresult lretval;
    CUresult (*lcuExternalMemoryGetMappedMipmappedArray) (CUmipmappedArray *, CUexternalMemory, CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC const *) = (CUresult (*)(CUmipmappedArray *, CUexternalMemory, CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC const *))dlsym(RTLD_NEXT, "cuExternalMemoryGetMappedMipmappedArray");
    
    /* pre exeuction logics */
    ac.add_counter("cuExternalMemoryGetMappedMipmappedArray", kApiTypeDriver);

    lretval = lcuExternalMemoryGetMappedMipmappedArray(mipmap, extMem, mipmapDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cuExternalMemoryGetMappedMipmappedArray cuExternalMemoryGetMappedMipmappedArray


#undef cuDestroyExternalMemory
CUresult cuDestroyExternalMemory(CUexternalMemory extMem){
    CUresult lretval;
    CUresult (*lcuDestroyExternalMemory) (CUexternalMemory) = (CUresult (*)(CUexternalMemory))dlsym(RTLD_NEXT, "cuDestroyExternalMemory");
    
    /* pre exeuction logics */
    ac.add_counter("cuDestroyExternalMemory", kApiTypeDriver);

    lretval = lcuDestroyExternalMemory(extMem);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDestroyExternalMemory cuDestroyExternalMemory


#undef cuImportExternalSemaphore
CUresult cuImportExternalSemaphore(CUexternalSemaphore * extSem_out, CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC const * semHandleDesc){
    CUresult lretval;
    CUresult (*lcuImportExternalSemaphore) (CUexternalSemaphore *, CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC const *) = (CUresult (*)(CUexternalSemaphore *, CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC const *))dlsym(RTLD_NEXT, "cuImportExternalSemaphore");
    
    /* pre exeuction logics */
    ac.add_counter("cuImportExternalSemaphore", kApiTypeDriver);

    lretval = lcuImportExternalSemaphore(extSem_out, semHandleDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cuImportExternalSemaphore cuImportExternalSemaphore


#undef cuSignalExternalSemaphoresAsync
CUresult cuSignalExternalSemaphoresAsync(CUexternalSemaphore const * extSemArray, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS const * paramsArray, unsigned int numExtSems, CUstream stream){
    CUresult lretval;
    CUresult (*lcuSignalExternalSemaphoresAsync) (CUexternalSemaphore const *, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS const *, unsigned int, CUstream) = (CUresult (*)(CUexternalSemaphore const *, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS const *, unsigned int, CUstream))dlsym(RTLD_NEXT, "cuSignalExternalSemaphoresAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuSignalExternalSemaphoresAsync", kApiTypeDriver);

    lretval = lcuSignalExternalSemaphoresAsync(extSemArray, paramsArray, numExtSems, stream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuSignalExternalSemaphoresAsync cuSignalExternalSemaphoresAsync


#undef cuWaitExternalSemaphoresAsync
CUresult cuWaitExternalSemaphoresAsync(CUexternalSemaphore const * extSemArray, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS const * paramsArray, unsigned int numExtSems, CUstream stream){
    CUresult lretval;
    CUresult (*lcuWaitExternalSemaphoresAsync) (CUexternalSemaphore const *, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS const *, unsigned int, CUstream) = (CUresult (*)(CUexternalSemaphore const *, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS const *, unsigned int, CUstream))dlsym(RTLD_NEXT, "cuWaitExternalSemaphoresAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuWaitExternalSemaphoresAsync", kApiTypeDriver);

    lretval = lcuWaitExternalSemaphoresAsync(extSemArray, paramsArray, numExtSems, stream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuWaitExternalSemaphoresAsync cuWaitExternalSemaphoresAsync


#undef cuDestroyExternalSemaphore
CUresult cuDestroyExternalSemaphore(CUexternalSemaphore extSem){
    CUresult lretval;
    CUresult (*lcuDestroyExternalSemaphore) (CUexternalSemaphore) = (CUresult (*)(CUexternalSemaphore))dlsym(RTLD_NEXT, "cuDestroyExternalSemaphore");
    
    /* pre exeuction logics */
    ac.add_counter("cuDestroyExternalSemaphore", kApiTypeDriver);

    lretval = lcuDestroyExternalSemaphore(extSem);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDestroyExternalSemaphore cuDestroyExternalSemaphore


#undef cuStreamWaitValue32
CUresult cuStreamWaitValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuStreamWaitValue32) (CUstream, CUdeviceptr, cuuint32_t, unsigned int) = (CUresult (*)(CUstream, CUdeviceptr, cuuint32_t, unsigned int))dlsym(RTLD_NEXT, "cuStreamWaitValue32");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamWaitValue32", kApiTypeDriver);

    lretval = lcuStreamWaitValue32(stream, addr, value, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamWaitValue32 cuStreamWaitValue32


#undef cuStreamWaitValue64
CUresult cuStreamWaitValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuStreamWaitValue64) (CUstream, CUdeviceptr, cuuint64_t, unsigned int) = (CUresult (*)(CUstream, CUdeviceptr, cuuint64_t, unsigned int))dlsym(RTLD_NEXT, "cuStreamWaitValue64");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamWaitValue64", kApiTypeDriver);

    lretval = lcuStreamWaitValue64(stream, addr, value, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamWaitValue64 cuStreamWaitValue64


#undef cuStreamWriteValue32
CUresult cuStreamWriteValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuStreamWriteValue32) (CUstream, CUdeviceptr, cuuint32_t, unsigned int) = (CUresult (*)(CUstream, CUdeviceptr, cuuint32_t, unsigned int))dlsym(RTLD_NEXT, "cuStreamWriteValue32");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamWriteValue32", kApiTypeDriver);

    lretval = lcuStreamWriteValue32(stream, addr, value, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamWriteValue32 cuStreamWriteValue32


#undef cuStreamWriteValue64
CUresult cuStreamWriteValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuStreamWriteValue64) (CUstream, CUdeviceptr, cuuint64_t, unsigned int) = (CUresult (*)(CUstream, CUdeviceptr, cuuint64_t, unsigned int))dlsym(RTLD_NEXT, "cuStreamWriteValue64");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamWriteValue64", kApiTypeDriver);

    lretval = lcuStreamWriteValue64(stream, addr, value, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamWriteValue64 cuStreamWriteValue64


#undef cuStreamBatchMemOp
CUresult cuStreamBatchMemOp(CUstream stream, unsigned int count, CUstreamBatchMemOpParams * paramArray, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuStreamBatchMemOp) (CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int) = (CUresult (*)(CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int))dlsym(RTLD_NEXT, "cuStreamBatchMemOp");
    
    /* pre exeuction logics */
    ac.add_counter("cuStreamBatchMemOp", kApiTypeDriver);

    lretval = lcuStreamBatchMemOp(stream, count, paramArray, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuStreamBatchMemOp cuStreamBatchMemOp


#undef cuFuncGetAttribute
CUresult cuFuncGetAttribute(int * pi, CUfunction_attribute attrib, CUfunction hfunc){
    CUresult lretval;
    CUresult (*lcuFuncGetAttribute) (int *, CUfunction_attribute, CUfunction) = (CUresult (*)(int *, CUfunction_attribute, CUfunction))dlsym(RTLD_NEXT, "cuFuncGetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuFuncGetAttribute", kApiTypeDriver);

    lretval = lcuFuncGetAttribute(pi, attrib, hfunc);
    
    /* post exeuction logics */

    return lretval;
}
#define cuFuncGetAttribute cuFuncGetAttribute


#undef cuFuncSetAttribute
CUresult cuFuncSetAttribute(CUfunction hfunc, CUfunction_attribute attrib, int value){
    CUresult lretval;
    CUresult (*lcuFuncSetAttribute) (CUfunction, CUfunction_attribute, int) = (CUresult (*)(CUfunction, CUfunction_attribute, int))dlsym(RTLD_NEXT, "cuFuncSetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuFuncSetAttribute", kApiTypeDriver);

    lretval = lcuFuncSetAttribute(hfunc, attrib, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cuFuncSetAttribute cuFuncSetAttribute


#undef cuFuncSetCacheConfig
CUresult cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config){
    CUresult lretval;
    CUresult (*lcuFuncSetCacheConfig) (CUfunction, CUfunc_cache) = (CUresult (*)(CUfunction, CUfunc_cache))dlsym(RTLD_NEXT, "cuFuncSetCacheConfig");
    
    /* pre exeuction logics */
    ac.add_counter("cuFuncSetCacheConfig", kApiTypeDriver);

    lretval = lcuFuncSetCacheConfig(hfunc, config);
    
    /* post exeuction logics */

    return lretval;
}
#define cuFuncSetCacheConfig cuFuncSetCacheConfig


#undef cuFuncSetSharedMemConfig
CUresult cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config){
    CUresult lretval;
    CUresult (*lcuFuncSetSharedMemConfig) (CUfunction, CUsharedconfig) = (CUresult (*)(CUfunction, CUsharedconfig))dlsym(RTLD_NEXT, "cuFuncSetSharedMemConfig");
    
    /* pre exeuction logics */
    ac.add_counter("cuFuncSetSharedMemConfig", kApiTypeDriver);

    lretval = lcuFuncSetSharedMemConfig(hfunc, config);
    
    /* post exeuction logics */

    return lretval;
}
#define cuFuncSetSharedMemConfig cuFuncSetSharedMemConfig


#undef cuFuncGetModule
CUresult cuFuncGetModule(CUmodule * hmod, CUfunction hfunc){
    CUresult lretval;
    CUresult (*lcuFuncGetModule) (CUmodule *, CUfunction) = (CUresult (*)(CUmodule *, CUfunction))dlsym(RTLD_NEXT, "cuFuncGetModule");
    
    /* pre exeuction logics */
    ac.add_counter("cuFuncGetModule", kApiTypeDriver);

    lretval = lcuFuncGetModule(hmod, hfunc);
    
    /* post exeuction logics */

    return lretval;
}
#define cuFuncGetModule cuFuncGetModule


#undef cuLaunchKernel
CUresult cuLaunchKernel(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void * * kernelParams, void * * extra){
    CUresult lretval;
    CUresult (*lcuLaunchKernel) (CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void * *, void * *) = (CUresult (*)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void * *, void * *))dlsym(RTLD_NEXT, "cuLaunchKernel");
    
    /* pre exeuction logics */
    ac.add_counter("cuLaunchKernel", kApiTypeDriver);

    lretval = lcuLaunchKernel(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams, extra);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLaunchKernel cuLaunchKernel


#undef cuLaunchCooperativeKernel
CUresult cuLaunchCooperativeKernel(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void * * kernelParams){
    CUresult lretval;
    CUresult (*lcuLaunchCooperativeKernel) (CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void * *) = (CUresult (*)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void * *))dlsym(RTLD_NEXT, "cuLaunchCooperativeKernel");
    
    /* pre exeuction logics */
    ac.add_counter("cuLaunchCooperativeKernel", kApiTypeDriver);

    lretval = lcuLaunchCooperativeKernel(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLaunchCooperativeKernel cuLaunchCooperativeKernel


#undef cuLaunchCooperativeKernelMultiDevice
CUresult cuLaunchCooperativeKernelMultiDevice(CUDA_LAUNCH_PARAMS * launchParamsList, unsigned int numDevices, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuLaunchCooperativeKernelMultiDevice) (CUDA_LAUNCH_PARAMS *, unsigned int, unsigned int) = (CUresult (*)(CUDA_LAUNCH_PARAMS *, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cuLaunchCooperativeKernelMultiDevice");
    
    /* pre exeuction logics */
    ac.add_counter("cuLaunchCooperativeKernelMultiDevice", kApiTypeDriver);

    lretval = lcuLaunchCooperativeKernelMultiDevice(launchParamsList, numDevices, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLaunchCooperativeKernelMultiDevice cuLaunchCooperativeKernelMultiDevice


#undef cuLaunchHostFunc
CUresult cuLaunchHostFunc(CUstream hStream, CUhostFn fn, void * userData){
    CUresult lretval;
    CUresult (*lcuLaunchHostFunc) (CUstream, CUhostFn, void *) = (CUresult (*)(CUstream, CUhostFn, void *))dlsym(RTLD_NEXT, "cuLaunchHostFunc");
    
    /* pre exeuction logics */
    ac.add_counter("cuLaunchHostFunc", kApiTypeDriver);

    lretval = lcuLaunchHostFunc(hStream, fn, userData);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLaunchHostFunc cuLaunchHostFunc


#undef cuFuncSetBlockShape
CUresult cuFuncSetBlockShape(CUfunction hfunc, int x, int y, int z){
    CUresult lretval;
    CUresult (*lcuFuncSetBlockShape) (CUfunction, int, int, int) = (CUresult (*)(CUfunction, int, int, int))dlsym(RTLD_NEXT, "cuFuncSetBlockShape");
    
    /* pre exeuction logics */
    ac.add_counter("cuFuncSetBlockShape", kApiTypeDriver);

    lretval = lcuFuncSetBlockShape(hfunc, x, y, z);
    
    /* post exeuction logics */

    return lretval;
}
#define cuFuncSetBlockShape cuFuncSetBlockShape


#undef cuFuncSetSharedSize
CUresult cuFuncSetSharedSize(CUfunction hfunc, unsigned int bytes){
    CUresult lretval;
    CUresult (*lcuFuncSetSharedSize) (CUfunction, unsigned int) = (CUresult (*)(CUfunction, unsigned int))dlsym(RTLD_NEXT, "cuFuncSetSharedSize");
    
    /* pre exeuction logics */
    ac.add_counter("cuFuncSetSharedSize", kApiTypeDriver);

    lretval = lcuFuncSetSharedSize(hfunc, bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cuFuncSetSharedSize cuFuncSetSharedSize


#undef cuParamSetSize
CUresult cuParamSetSize(CUfunction hfunc, unsigned int numbytes){
    CUresult lretval;
    CUresult (*lcuParamSetSize) (CUfunction, unsigned int) = (CUresult (*)(CUfunction, unsigned int))dlsym(RTLD_NEXT, "cuParamSetSize");
    
    /* pre exeuction logics */
    ac.add_counter("cuParamSetSize", kApiTypeDriver);

    lretval = lcuParamSetSize(hfunc, numbytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cuParamSetSize cuParamSetSize


#undef cuParamSeti
CUresult cuParamSeti(CUfunction hfunc, int offset, unsigned int value){
    CUresult lretval;
    CUresult (*lcuParamSeti) (CUfunction, int, unsigned int) = (CUresult (*)(CUfunction, int, unsigned int))dlsym(RTLD_NEXT, "cuParamSeti");
    
    /* pre exeuction logics */
    ac.add_counter("cuParamSeti", kApiTypeDriver);

    lretval = lcuParamSeti(hfunc, offset, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cuParamSeti cuParamSeti


#undef cuParamSetf
CUresult cuParamSetf(CUfunction hfunc, int offset, float value){
    CUresult lretval;
    CUresult (*lcuParamSetf) (CUfunction, int, float) = (CUresult (*)(CUfunction, int, float))dlsym(RTLD_NEXT, "cuParamSetf");
    
    /* pre exeuction logics */
    ac.add_counter("cuParamSetf", kApiTypeDriver);

    lretval = lcuParamSetf(hfunc, offset, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cuParamSetf cuParamSetf


#undef cuParamSetv
CUresult cuParamSetv(CUfunction hfunc, int offset, void * ptr, unsigned int numbytes){
    CUresult lretval;
    CUresult (*lcuParamSetv) (CUfunction, int, void *, unsigned int) = (CUresult (*)(CUfunction, int, void *, unsigned int))dlsym(RTLD_NEXT, "cuParamSetv");
    
    /* pre exeuction logics */
    ac.add_counter("cuParamSetv", kApiTypeDriver);

    lretval = lcuParamSetv(hfunc, offset, ptr, numbytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cuParamSetv cuParamSetv


#undef cuLaunch
CUresult cuLaunch(CUfunction f){
    CUresult lretval;
    CUresult (*lcuLaunch) (CUfunction) = (CUresult (*)(CUfunction))dlsym(RTLD_NEXT, "cuLaunch");
    
    /* pre exeuction logics */
    ac.add_counter("cuLaunch", kApiTypeDriver);

    lretval = lcuLaunch(f);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLaunch cuLaunch


#undef cuLaunchGrid
CUresult cuLaunchGrid(CUfunction f, int grid_width, int grid_height){
    CUresult lretval;
    CUresult (*lcuLaunchGrid) (CUfunction, int, int) = (CUresult (*)(CUfunction, int, int))dlsym(RTLD_NEXT, "cuLaunchGrid");
    
    /* pre exeuction logics */
    ac.add_counter("cuLaunchGrid", kApiTypeDriver);

    lretval = lcuLaunchGrid(f, grid_width, grid_height);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLaunchGrid cuLaunchGrid


#undef cuLaunchGridAsync
CUresult cuLaunchGridAsync(CUfunction f, int grid_width, int grid_height, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuLaunchGridAsync) (CUfunction, int, int, CUstream) = (CUresult (*)(CUfunction, int, int, CUstream))dlsym(RTLD_NEXT, "cuLaunchGridAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cuLaunchGridAsync", kApiTypeDriver);

    lretval = lcuLaunchGridAsync(f, grid_width, grid_height, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuLaunchGridAsync cuLaunchGridAsync


#undef cuParamSetTexRef
CUresult cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuParamSetTexRef) (CUfunction, int, CUtexref) = (CUresult (*)(CUfunction, int, CUtexref))dlsym(RTLD_NEXT, "cuParamSetTexRef");
    
    /* pre exeuction logics */
    ac.add_counter("cuParamSetTexRef", kApiTypeDriver);

    lretval = lcuParamSetTexRef(hfunc, texunit, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuParamSetTexRef cuParamSetTexRef


#undef cuGraphCreate
CUresult cuGraphCreate(CUgraph * phGraph, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuGraphCreate) (CUgraph *, unsigned int) = (CUresult (*)(CUgraph *, unsigned int))dlsym(RTLD_NEXT, "cuGraphCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphCreate", kApiTypeDriver);

    lretval = lcuGraphCreate(phGraph, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphCreate cuGraphCreate


#undef cuGraphAddKernelNode
CUresult cuGraphAddKernelNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies, CUDA_KERNEL_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphAddKernelNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_KERNEL_NODE_PARAMS const *) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_KERNEL_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphAddKernelNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddKernelNode", kApiTypeDriver);

    lretval = lcuGraphAddKernelNode(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddKernelNode cuGraphAddKernelNode


#undef cuGraphKernelNodeGetParams
CUresult cuGraphKernelNodeGetParams(CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphKernelNodeGetParams) (CUgraphNode, CUDA_KERNEL_NODE_PARAMS *) = (CUresult (*)(CUgraphNode, CUDA_KERNEL_NODE_PARAMS *))dlsym(RTLD_NEXT, "cuGraphKernelNodeGetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphKernelNodeGetParams", kApiTypeDriver);

    lretval = lcuGraphKernelNodeGetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphKernelNodeGetParams cuGraphKernelNodeGetParams


#undef cuGraphKernelNodeSetParams
CUresult cuGraphKernelNodeSetParams(CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphKernelNodeSetParams) (CUgraphNode, CUDA_KERNEL_NODE_PARAMS const *) = (CUresult (*)(CUgraphNode, CUDA_KERNEL_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphKernelNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphKernelNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphKernelNodeSetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphKernelNodeSetParams cuGraphKernelNodeSetParams


#undef cuGraphAddMemcpyNode
CUresult cuGraphAddMemcpyNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies, CUDA_MEMCPY3D const * copyParams, CUcontext ctx){
    CUresult lretval;
    CUresult (*lcuGraphAddMemcpyNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_MEMCPY3D const *, CUcontext) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_MEMCPY3D const *, CUcontext))dlsym(RTLD_NEXT, "cuGraphAddMemcpyNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddMemcpyNode", kApiTypeDriver);

    lretval = lcuGraphAddMemcpyNode(phGraphNode, hGraph, dependencies, numDependencies, copyParams, ctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddMemcpyNode cuGraphAddMemcpyNode


#undef cuGraphMemcpyNodeGetParams
CUresult cuGraphMemcpyNodeGetParams(CUgraphNode hNode, CUDA_MEMCPY3D * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphMemcpyNodeGetParams) (CUgraphNode, CUDA_MEMCPY3D *) = (CUresult (*)(CUgraphNode, CUDA_MEMCPY3D *))dlsym(RTLD_NEXT, "cuGraphMemcpyNodeGetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphMemcpyNodeGetParams", kApiTypeDriver);

    lretval = lcuGraphMemcpyNodeGetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphMemcpyNodeGetParams cuGraphMemcpyNodeGetParams


#undef cuGraphMemcpyNodeSetParams
CUresult cuGraphMemcpyNodeSetParams(CUgraphNode hNode, CUDA_MEMCPY3D const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphMemcpyNodeSetParams) (CUgraphNode, CUDA_MEMCPY3D const *) = (CUresult (*)(CUgraphNode, CUDA_MEMCPY3D const *))dlsym(RTLD_NEXT, "cuGraphMemcpyNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphMemcpyNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphMemcpyNodeSetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphMemcpyNodeSetParams cuGraphMemcpyNodeSetParams


#undef cuGraphAddMemsetNode
CUresult cuGraphAddMemsetNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies, CUDA_MEMSET_NODE_PARAMS const * memsetParams, CUcontext ctx){
    CUresult lretval;
    CUresult (*lcuGraphAddMemsetNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_MEMSET_NODE_PARAMS const *, CUcontext) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_MEMSET_NODE_PARAMS const *, CUcontext))dlsym(RTLD_NEXT, "cuGraphAddMemsetNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddMemsetNode", kApiTypeDriver);

    lretval = lcuGraphAddMemsetNode(phGraphNode, hGraph, dependencies, numDependencies, memsetParams, ctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddMemsetNode cuGraphAddMemsetNode


#undef cuGraphMemsetNodeGetParams
CUresult cuGraphMemsetNodeGetParams(CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphMemsetNodeGetParams) (CUgraphNode, CUDA_MEMSET_NODE_PARAMS *) = (CUresult (*)(CUgraphNode, CUDA_MEMSET_NODE_PARAMS *))dlsym(RTLD_NEXT, "cuGraphMemsetNodeGetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphMemsetNodeGetParams", kApiTypeDriver);

    lretval = lcuGraphMemsetNodeGetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphMemsetNodeGetParams cuGraphMemsetNodeGetParams


#undef cuGraphMemsetNodeSetParams
CUresult cuGraphMemsetNodeSetParams(CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphMemsetNodeSetParams) (CUgraphNode, CUDA_MEMSET_NODE_PARAMS const *) = (CUresult (*)(CUgraphNode, CUDA_MEMSET_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphMemsetNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphMemsetNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphMemsetNodeSetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphMemsetNodeSetParams cuGraphMemsetNodeSetParams


#undef cuGraphAddHostNode
CUresult cuGraphAddHostNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies, CUDA_HOST_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphAddHostNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_HOST_NODE_PARAMS const *) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_HOST_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphAddHostNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddHostNode", kApiTypeDriver);

    lretval = lcuGraphAddHostNode(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddHostNode cuGraphAddHostNode


#undef cuGraphHostNodeGetParams
CUresult cuGraphHostNodeGetParams(CUgraphNode hNode, CUDA_HOST_NODE_PARAMS * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphHostNodeGetParams) (CUgraphNode, CUDA_HOST_NODE_PARAMS *) = (CUresult (*)(CUgraphNode, CUDA_HOST_NODE_PARAMS *))dlsym(RTLD_NEXT, "cuGraphHostNodeGetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphHostNodeGetParams", kApiTypeDriver);

    lretval = lcuGraphHostNodeGetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphHostNodeGetParams cuGraphHostNodeGetParams


#undef cuGraphHostNodeSetParams
CUresult cuGraphHostNodeSetParams(CUgraphNode hNode, CUDA_HOST_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphHostNodeSetParams) (CUgraphNode, CUDA_HOST_NODE_PARAMS const *) = (CUresult (*)(CUgraphNode, CUDA_HOST_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphHostNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphHostNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphHostNodeSetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphHostNodeSetParams cuGraphHostNodeSetParams


#undef cuGraphAddChildGraphNode
CUresult cuGraphAddChildGraphNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies, CUgraph childGraph){
    CUresult lretval;
    CUresult (*lcuGraphAddChildGraphNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUgraph) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUgraph))dlsym(RTLD_NEXT, "cuGraphAddChildGraphNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddChildGraphNode", kApiTypeDriver);

    lretval = lcuGraphAddChildGraphNode(phGraphNode, hGraph, dependencies, numDependencies, childGraph);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddChildGraphNode cuGraphAddChildGraphNode


#undef cuGraphChildGraphNodeGetGraph
CUresult cuGraphChildGraphNodeGetGraph(CUgraphNode hNode, CUgraph * phGraph){
    CUresult lretval;
    CUresult (*lcuGraphChildGraphNodeGetGraph) (CUgraphNode, CUgraph *) = (CUresult (*)(CUgraphNode, CUgraph *))dlsym(RTLD_NEXT, "cuGraphChildGraphNodeGetGraph");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphChildGraphNodeGetGraph", kApiTypeDriver);

    lretval = lcuGraphChildGraphNodeGetGraph(hNode, phGraph);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphChildGraphNodeGetGraph cuGraphChildGraphNodeGetGraph


#undef cuGraphAddEmptyNode
CUresult cuGraphAddEmptyNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies){
    CUresult lretval;
    CUresult (*lcuGraphAddEmptyNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t))dlsym(RTLD_NEXT, "cuGraphAddEmptyNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddEmptyNode", kApiTypeDriver);

    lretval = lcuGraphAddEmptyNode(phGraphNode, hGraph, dependencies, numDependencies);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddEmptyNode cuGraphAddEmptyNode


#undef cuGraphAddEventRecordNode
CUresult cuGraphAddEventRecordNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies, CUevent event){
    CUresult lretval;
    CUresult (*lcuGraphAddEventRecordNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUevent) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUevent))dlsym(RTLD_NEXT, "cuGraphAddEventRecordNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddEventRecordNode", kApiTypeDriver);

    lretval = lcuGraphAddEventRecordNode(phGraphNode, hGraph, dependencies, numDependencies, event);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddEventRecordNode cuGraphAddEventRecordNode


#undef cuGraphEventRecordNodeGetEvent
CUresult cuGraphEventRecordNodeGetEvent(CUgraphNode hNode, CUevent * event_out){
    CUresult lretval;
    CUresult (*lcuGraphEventRecordNodeGetEvent) (CUgraphNode, CUevent *) = (CUresult (*)(CUgraphNode, CUevent *))dlsym(RTLD_NEXT, "cuGraphEventRecordNodeGetEvent");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphEventRecordNodeGetEvent", kApiTypeDriver);

    lretval = lcuGraphEventRecordNodeGetEvent(hNode, event_out);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphEventRecordNodeGetEvent cuGraphEventRecordNodeGetEvent


#undef cuGraphEventRecordNodeSetEvent
CUresult cuGraphEventRecordNodeSetEvent(CUgraphNode hNode, CUevent event){
    CUresult lretval;
    CUresult (*lcuGraphEventRecordNodeSetEvent) (CUgraphNode, CUevent) = (CUresult (*)(CUgraphNode, CUevent))dlsym(RTLD_NEXT, "cuGraphEventRecordNodeSetEvent");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphEventRecordNodeSetEvent", kApiTypeDriver);

    lretval = lcuGraphEventRecordNodeSetEvent(hNode, event);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphEventRecordNodeSetEvent cuGraphEventRecordNodeSetEvent


#undef cuGraphAddEventWaitNode
CUresult cuGraphAddEventWaitNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies, CUevent event){
    CUresult lretval;
    CUresult (*lcuGraphAddEventWaitNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUevent) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUevent))dlsym(RTLD_NEXT, "cuGraphAddEventWaitNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddEventWaitNode", kApiTypeDriver);

    lretval = lcuGraphAddEventWaitNode(phGraphNode, hGraph, dependencies, numDependencies, event);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddEventWaitNode cuGraphAddEventWaitNode


#undef cuGraphEventWaitNodeGetEvent
CUresult cuGraphEventWaitNodeGetEvent(CUgraphNode hNode, CUevent * event_out){
    CUresult lretval;
    CUresult (*lcuGraphEventWaitNodeGetEvent) (CUgraphNode, CUevent *) = (CUresult (*)(CUgraphNode, CUevent *))dlsym(RTLD_NEXT, "cuGraphEventWaitNodeGetEvent");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphEventWaitNodeGetEvent", kApiTypeDriver);

    lretval = lcuGraphEventWaitNodeGetEvent(hNode, event_out);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphEventWaitNodeGetEvent cuGraphEventWaitNodeGetEvent


#undef cuGraphEventWaitNodeSetEvent
CUresult cuGraphEventWaitNodeSetEvent(CUgraphNode hNode, CUevent event){
    CUresult lretval;
    CUresult (*lcuGraphEventWaitNodeSetEvent) (CUgraphNode, CUevent) = (CUresult (*)(CUgraphNode, CUevent))dlsym(RTLD_NEXT, "cuGraphEventWaitNodeSetEvent");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphEventWaitNodeSetEvent", kApiTypeDriver);

    lretval = lcuGraphEventWaitNodeSetEvent(hNode, event);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphEventWaitNodeSetEvent cuGraphEventWaitNodeSetEvent


#undef cuGraphAddExternalSemaphoresSignalNode
CUresult cuGraphAddExternalSemaphoresSignalNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphAddExternalSemaphoresSignalNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS const *) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphAddExternalSemaphoresSignalNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddExternalSemaphoresSignalNode", kApiTypeDriver);

    lretval = lcuGraphAddExternalSemaphoresSignalNode(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddExternalSemaphoresSignalNode cuGraphAddExternalSemaphoresSignalNode


#undef cuGraphExternalSemaphoresSignalNodeGetParams
CUresult cuGraphExternalSemaphoresSignalNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * params_out){
    CUresult lretval;
    CUresult (*lcuGraphExternalSemaphoresSignalNodeGetParams) (CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *) = (CUresult (*)(CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *))dlsym(RTLD_NEXT, "cuGraphExternalSemaphoresSignalNodeGetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExternalSemaphoresSignalNodeGetParams", kApiTypeDriver);

    lretval = lcuGraphExternalSemaphoresSignalNodeGetParams(hNode, params_out);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExternalSemaphoresSignalNodeGetParams cuGraphExternalSemaphoresSignalNodeGetParams


#undef cuGraphExternalSemaphoresSignalNodeSetParams
CUresult cuGraphExternalSemaphoresSignalNodeSetParams(CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphExternalSemaphoresSignalNodeSetParams) (CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS const *) = (CUresult (*)(CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphExternalSemaphoresSignalNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExternalSemaphoresSignalNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphExternalSemaphoresSignalNodeSetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExternalSemaphoresSignalNodeSetParams cuGraphExternalSemaphoresSignalNodeSetParams


#undef cuGraphAddExternalSemaphoresWaitNode
CUresult cuGraphAddExternalSemaphoresWaitNode(CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode const * dependencies, size_t numDependencies, CUDA_EXT_SEM_WAIT_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphAddExternalSemaphoresWaitNode) (CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_EXT_SEM_WAIT_NODE_PARAMS const *) = (CUresult (*)(CUgraphNode *, CUgraph, CUgraphNode const *, size_t, CUDA_EXT_SEM_WAIT_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphAddExternalSemaphoresWaitNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddExternalSemaphoresWaitNode", kApiTypeDriver);

    lretval = lcuGraphAddExternalSemaphoresWaitNode(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddExternalSemaphoresWaitNode cuGraphAddExternalSemaphoresWaitNode


#undef cuGraphExternalSemaphoresWaitNodeGetParams
CUresult cuGraphExternalSemaphoresWaitNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS * params_out){
    CUresult lretval;
    CUresult (*lcuGraphExternalSemaphoresWaitNodeGetParams) (CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *) = (CUresult (*)(CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *))dlsym(RTLD_NEXT, "cuGraphExternalSemaphoresWaitNodeGetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExternalSemaphoresWaitNodeGetParams", kApiTypeDriver);

    lretval = lcuGraphExternalSemaphoresWaitNodeGetParams(hNode, params_out);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExternalSemaphoresWaitNodeGetParams cuGraphExternalSemaphoresWaitNodeGetParams


#undef cuGraphExternalSemaphoresWaitNodeSetParams
CUresult cuGraphExternalSemaphoresWaitNodeSetParams(CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphExternalSemaphoresWaitNodeSetParams) (CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS const *) = (CUresult (*)(CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphExternalSemaphoresWaitNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExternalSemaphoresWaitNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphExternalSemaphoresWaitNodeSetParams(hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExternalSemaphoresWaitNodeSetParams cuGraphExternalSemaphoresWaitNodeSetParams


#undef cuGraphClone
CUresult cuGraphClone(CUgraph * phGraphClone, CUgraph originalGraph){
    CUresult lretval;
    CUresult (*lcuGraphClone) (CUgraph *, CUgraph) = (CUresult (*)(CUgraph *, CUgraph))dlsym(RTLD_NEXT, "cuGraphClone");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphClone", kApiTypeDriver);

    lretval = lcuGraphClone(phGraphClone, originalGraph);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphClone cuGraphClone


#undef cuGraphNodeFindInClone
CUresult cuGraphNodeFindInClone(CUgraphNode * phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph){
    CUresult lretval;
    CUresult (*lcuGraphNodeFindInClone) (CUgraphNode *, CUgraphNode, CUgraph) = (CUresult (*)(CUgraphNode *, CUgraphNode, CUgraph))dlsym(RTLD_NEXT, "cuGraphNodeFindInClone");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphNodeFindInClone", kApiTypeDriver);

    lretval = lcuGraphNodeFindInClone(phNode, hOriginalNode, hClonedGraph);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphNodeFindInClone cuGraphNodeFindInClone


#undef cuGraphNodeGetType
CUresult cuGraphNodeGetType(CUgraphNode hNode, CUgraphNodeType * type){
    CUresult lretval;
    CUresult (*lcuGraphNodeGetType) (CUgraphNode, CUgraphNodeType *) = (CUresult (*)(CUgraphNode, CUgraphNodeType *))dlsym(RTLD_NEXT, "cuGraphNodeGetType");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphNodeGetType", kApiTypeDriver);

    lretval = lcuGraphNodeGetType(hNode, type);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphNodeGetType cuGraphNodeGetType


#undef cuGraphGetNodes
CUresult cuGraphGetNodes(CUgraph hGraph, CUgraphNode * nodes, size_t * numNodes){
    CUresult lretval;
    CUresult (*lcuGraphGetNodes) (CUgraph, CUgraphNode *, size_t *) = (CUresult (*)(CUgraph, CUgraphNode *, size_t *))dlsym(RTLD_NEXT, "cuGraphGetNodes");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphGetNodes", kApiTypeDriver);

    lretval = lcuGraphGetNodes(hGraph, nodes, numNodes);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphGetNodes cuGraphGetNodes


#undef cuGraphGetRootNodes
CUresult cuGraphGetRootNodes(CUgraph hGraph, CUgraphNode * rootNodes, size_t * numRootNodes){
    CUresult lretval;
    CUresult (*lcuGraphGetRootNodes) (CUgraph, CUgraphNode *, size_t *) = (CUresult (*)(CUgraph, CUgraphNode *, size_t *))dlsym(RTLD_NEXT, "cuGraphGetRootNodes");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphGetRootNodes", kApiTypeDriver);

    lretval = lcuGraphGetRootNodes(hGraph, rootNodes, numRootNodes);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphGetRootNodes cuGraphGetRootNodes


#undef cuGraphGetEdges
CUresult cuGraphGetEdges(CUgraph hGraph, CUgraphNode * from, CUgraphNode * to, size_t * numEdges){
    CUresult lretval;
    CUresult (*lcuGraphGetEdges) (CUgraph, CUgraphNode *, CUgraphNode *, size_t *) = (CUresult (*)(CUgraph, CUgraphNode *, CUgraphNode *, size_t *))dlsym(RTLD_NEXT, "cuGraphGetEdges");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphGetEdges", kApiTypeDriver);

    lretval = lcuGraphGetEdges(hGraph, from, to, numEdges);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphGetEdges cuGraphGetEdges


#undef cuGraphNodeGetDependencies
CUresult cuGraphNodeGetDependencies(CUgraphNode hNode, CUgraphNode * dependencies, size_t * numDependencies){
    CUresult lretval;
    CUresult (*lcuGraphNodeGetDependencies) (CUgraphNode, CUgraphNode *, size_t *) = (CUresult (*)(CUgraphNode, CUgraphNode *, size_t *))dlsym(RTLD_NEXT, "cuGraphNodeGetDependencies");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphNodeGetDependencies", kApiTypeDriver);

    lretval = lcuGraphNodeGetDependencies(hNode, dependencies, numDependencies);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphNodeGetDependencies cuGraphNodeGetDependencies


#undef cuGraphNodeGetDependentNodes
CUresult cuGraphNodeGetDependentNodes(CUgraphNode hNode, CUgraphNode * dependentNodes, size_t * numDependentNodes){
    CUresult lretval;
    CUresult (*lcuGraphNodeGetDependentNodes) (CUgraphNode, CUgraphNode *, size_t *) = (CUresult (*)(CUgraphNode, CUgraphNode *, size_t *))dlsym(RTLD_NEXT, "cuGraphNodeGetDependentNodes");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphNodeGetDependentNodes", kApiTypeDriver);

    lretval = lcuGraphNodeGetDependentNodes(hNode, dependentNodes, numDependentNodes);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphNodeGetDependentNodes cuGraphNodeGetDependentNodes


#undef cuGraphAddDependencies
CUresult cuGraphAddDependencies(CUgraph hGraph, CUgraphNode const * from, CUgraphNode const * to, size_t numDependencies){
    CUresult lretval;
    CUresult (*lcuGraphAddDependencies) (CUgraph, CUgraphNode const *, CUgraphNode const *, size_t) = (CUresult (*)(CUgraph, CUgraphNode const *, CUgraphNode const *, size_t))dlsym(RTLD_NEXT, "cuGraphAddDependencies");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphAddDependencies", kApiTypeDriver);

    lretval = lcuGraphAddDependencies(hGraph, from, to, numDependencies);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphAddDependencies cuGraphAddDependencies


#undef cuGraphRemoveDependencies
CUresult cuGraphRemoveDependencies(CUgraph hGraph, CUgraphNode const * from, CUgraphNode const * to, size_t numDependencies){
    CUresult lretval;
    CUresult (*lcuGraphRemoveDependencies) (CUgraph, CUgraphNode const *, CUgraphNode const *, size_t) = (CUresult (*)(CUgraph, CUgraphNode const *, CUgraphNode const *, size_t))dlsym(RTLD_NEXT, "cuGraphRemoveDependencies");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphRemoveDependencies", kApiTypeDriver);

    lretval = lcuGraphRemoveDependencies(hGraph, from, to, numDependencies);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphRemoveDependencies cuGraphRemoveDependencies


#undef cuGraphDestroyNode
CUresult cuGraphDestroyNode(CUgraphNode hNode){
    CUresult lretval;
    CUresult (*lcuGraphDestroyNode) (CUgraphNode) = (CUresult (*)(CUgraphNode))dlsym(RTLD_NEXT, "cuGraphDestroyNode");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphDestroyNode", kApiTypeDriver);

    lretval = lcuGraphDestroyNode(hNode);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphDestroyNode cuGraphDestroyNode


#undef cuGraphInstantiate_v2
CUresult cuGraphInstantiate_v2(CUgraphExec * phGraphExec, CUgraph hGraph, CUgraphNode * phErrorNode, char * logBuffer, size_t bufferSize){
    CUresult lretval;
    CUresult (*lcuGraphInstantiate_v2) (CUgraphExec *, CUgraph, CUgraphNode *, char *, size_t) = (CUresult (*)(CUgraphExec *, CUgraph, CUgraphNode *, char *, size_t))dlsym(RTLD_NEXT, "cuGraphInstantiate_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphInstantiate_v2", kApiTypeDriver);

    lretval = lcuGraphInstantiate_v2(phGraphExec, hGraph, phErrorNode, logBuffer, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphInstantiate_v2 cuGraphInstantiate_v2


#undef cuGraphExecKernelNodeSetParams
CUresult cuGraphExecKernelNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphExecKernelNodeSetParams) (CUgraphExec, CUgraphNode, CUDA_KERNEL_NODE_PARAMS const *) = (CUresult (*)(CUgraphExec, CUgraphNode, CUDA_KERNEL_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphExecKernelNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecKernelNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphExecKernelNodeSetParams(hGraphExec, hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecKernelNodeSetParams cuGraphExecKernelNodeSetParams


#undef cuGraphExecMemcpyNodeSetParams
CUresult cuGraphExecMemcpyNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_MEMCPY3D const * copyParams, CUcontext ctx){
    CUresult lretval;
    CUresult (*lcuGraphExecMemcpyNodeSetParams) (CUgraphExec, CUgraphNode, CUDA_MEMCPY3D const *, CUcontext) = (CUresult (*)(CUgraphExec, CUgraphNode, CUDA_MEMCPY3D const *, CUcontext))dlsym(RTLD_NEXT, "cuGraphExecMemcpyNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecMemcpyNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphExecMemcpyNodeSetParams(hGraphExec, hNode, copyParams, ctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecMemcpyNodeSetParams cuGraphExecMemcpyNodeSetParams


#undef cuGraphExecMemsetNodeSetParams
CUresult cuGraphExecMemsetNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS const * memsetParams, CUcontext ctx){
    CUresult lretval;
    CUresult (*lcuGraphExecMemsetNodeSetParams) (CUgraphExec, CUgraphNode, CUDA_MEMSET_NODE_PARAMS const *, CUcontext) = (CUresult (*)(CUgraphExec, CUgraphNode, CUDA_MEMSET_NODE_PARAMS const *, CUcontext))dlsym(RTLD_NEXT, "cuGraphExecMemsetNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecMemsetNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphExecMemsetNodeSetParams(hGraphExec, hNode, memsetParams, ctx);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecMemsetNodeSetParams cuGraphExecMemsetNodeSetParams


#undef cuGraphExecHostNodeSetParams
CUresult cuGraphExecHostNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_HOST_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphExecHostNodeSetParams) (CUgraphExec, CUgraphNode, CUDA_HOST_NODE_PARAMS const *) = (CUresult (*)(CUgraphExec, CUgraphNode, CUDA_HOST_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphExecHostNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecHostNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphExecHostNodeSetParams(hGraphExec, hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecHostNodeSetParams cuGraphExecHostNodeSetParams


#undef cuGraphExecChildGraphNodeSetParams
CUresult cuGraphExecChildGraphNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUgraph childGraph){
    CUresult lretval;
    CUresult (*lcuGraphExecChildGraphNodeSetParams) (CUgraphExec, CUgraphNode, CUgraph) = (CUresult (*)(CUgraphExec, CUgraphNode, CUgraph))dlsym(RTLD_NEXT, "cuGraphExecChildGraphNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecChildGraphNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphExecChildGraphNodeSetParams(hGraphExec, hNode, childGraph);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecChildGraphNodeSetParams cuGraphExecChildGraphNodeSetParams


#undef cuGraphExecEventRecordNodeSetEvent
CUresult cuGraphExecEventRecordNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event){
    CUresult lretval;
    CUresult (*lcuGraphExecEventRecordNodeSetEvent) (CUgraphExec, CUgraphNode, CUevent) = (CUresult (*)(CUgraphExec, CUgraphNode, CUevent))dlsym(RTLD_NEXT, "cuGraphExecEventRecordNodeSetEvent");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecEventRecordNodeSetEvent", kApiTypeDriver);

    lretval = lcuGraphExecEventRecordNodeSetEvent(hGraphExec, hNode, event);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecEventRecordNodeSetEvent cuGraphExecEventRecordNodeSetEvent


#undef cuGraphExecEventWaitNodeSetEvent
CUresult cuGraphExecEventWaitNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event){
    CUresult lretval;
    CUresult (*lcuGraphExecEventWaitNodeSetEvent) (CUgraphExec, CUgraphNode, CUevent) = (CUresult (*)(CUgraphExec, CUgraphNode, CUevent))dlsym(RTLD_NEXT, "cuGraphExecEventWaitNodeSetEvent");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecEventWaitNodeSetEvent", kApiTypeDriver);

    lretval = lcuGraphExecEventWaitNodeSetEvent(hGraphExec, hNode, event);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecEventWaitNodeSetEvent cuGraphExecEventWaitNodeSetEvent


#undef cuGraphExecExternalSemaphoresSignalNodeSetParams
CUresult cuGraphExecExternalSemaphoresSignalNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphExecExternalSemaphoresSignalNodeSetParams) (CUgraphExec, CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS const *) = (CUresult (*)(CUgraphExec, CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphExecExternalSemaphoresSignalNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecExternalSemaphoresSignalNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphExecExternalSemaphoresSignalNodeSetParams(hGraphExec, hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecExternalSemaphoresSignalNodeSetParams cuGraphExecExternalSemaphoresSignalNodeSetParams


#undef cuGraphExecExternalSemaphoresWaitNodeSetParams
CUresult cuGraphExecExternalSemaphoresWaitNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS const * nodeParams){
    CUresult lretval;
    CUresult (*lcuGraphExecExternalSemaphoresWaitNodeSetParams) (CUgraphExec, CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS const *) = (CUresult (*)(CUgraphExec, CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS const *))dlsym(RTLD_NEXT, "cuGraphExecExternalSemaphoresWaitNodeSetParams");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecExternalSemaphoresWaitNodeSetParams", kApiTypeDriver);

    lretval = lcuGraphExecExternalSemaphoresWaitNodeSetParams(hGraphExec, hNode, nodeParams);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecExternalSemaphoresWaitNodeSetParams cuGraphExecExternalSemaphoresWaitNodeSetParams


#undef cuGraphUpload
CUresult cuGraphUpload(CUgraphExec hGraphExec, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuGraphUpload) (CUgraphExec, CUstream) = (CUresult (*)(CUgraphExec, CUstream))dlsym(RTLD_NEXT, "cuGraphUpload");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphUpload", kApiTypeDriver);

    lretval = lcuGraphUpload(hGraphExec, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphUpload cuGraphUpload


#undef cuGraphLaunch
CUresult cuGraphLaunch(CUgraphExec hGraphExec, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuGraphLaunch) (CUgraphExec, CUstream) = (CUresult (*)(CUgraphExec, CUstream))dlsym(RTLD_NEXT, "cuGraphLaunch");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphLaunch", kApiTypeDriver);

    lretval = lcuGraphLaunch(hGraphExec, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphLaunch cuGraphLaunch


#undef cuGraphExecDestroy
CUresult cuGraphExecDestroy(CUgraphExec hGraphExec){
    CUresult lretval;
    CUresult (*lcuGraphExecDestroy) (CUgraphExec) = (CUresult (*)(CUgraphExec))dlsym(RTLD_NEXT, "cuGraphExecDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecDestroy", kApiTypeDriver);

    lretval = lcuGraphExecDestroy(hGraphExec);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecDestroy cuGraphExecDestroy


#undef cuGraphDestroy
CUresult cuGraphDestroy(CUgraph hGraph){
    CUresult lretval;
    CUresult (*lcuGraphDestroy) (CUgraph) = (CUresult (*)(CUgraph))dlsym(RTLD_NEXT, "cuGraphDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphDestroy", kApiTypeDriver);

    lretval = lcuGraphDestroy(hGraph);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphDestroy cuGraphDestroy


#undef cuGraphExecUpdate
CUresult cuGraphExecUpdate(CUgraphExec hGraphExec, CUgraph hGraph, CUgraphNode * hErrorNode_out, CUgraphExecUpdateResult * updateResult_out){
    CUresult lretval;
    CUresult (*lcuGraphExecUpdate) (CUgraphExec, CUgraph, CUgraphNode *, CUgraphExecUpdateResult *) = (CUresult (*)(CUgraphExec, CUgraph, CUgraphNode *, CUgraphExecUpdateResult *))dlsym(RTLD_NEXT, "cuGraphExecUpdate");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphExecUpdate", kApiTypeDriver);

    lretval = lcuGraphExecUpdate(hGraphExec, hGraph, hErrorNode_out, updateResult_out);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphExecUpdate cuGraphExecUpdate


#undef cuGraphKernelNodeCopyAttributes
CUresult cuGraphKernelNodeCopyAttributes(CUgraphNode dst, CUgraphNode src){
    CUresult lretval;
    CUresult (*lcuGraphKernelNodeCopyAttributes) (CUgraphNode, CUgraphNode) = (CUresult (*)(CUgraphNode, CUgraphNode))dlsym(RTLD_NEXT, "cuGraphKernelNodeCopyAttributes");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphKernelNodeCopyAttributes", kApiTypeDriver);

    lretval = lcuGraphKernelNodeCopyAttributes(dst, src);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphKernelNodeCopyAttributes cuGraphKernelNodeCopyAttributes


#undef cuGraphKernelNodeGetAttribute
CUresult cuGraphKernelNodeGetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue * value_out){
    CUresult lretval;
    CUresult (*lcuGraphKernelNodeGetAttribute) (CUgraphNode, CUkernelNodeAttrID, CUkernelNodeAttrValue *) = (CUresult (*)(CUgraphNode, CUkernelNodeAttrID, CUkernelNodeAttrValue *))dlsym(RTLD_NEXT, "cuGraphKernelNodeGetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphKernelNodeGetAttribute", kApiTypeDriver);

    lretval = lcuGraphKernelNodeGetAttribute(hNode, attr, value_out);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphKernelNodeGetAttribute cuGraphKernelNodeGetAttribute


#undef cuGraphKernelNodeSetAttribute
CUresult cuGraphKernelNodeSetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue const * value){
    CUresult lretval;
    CUresult (*lcuGraphKernelNodeSetAttribute) (CUgraphNode, CUkernelNodeAttrID, CUkernelNodeAttrValue const *) = (CUresult (*)(CUgraphNode, CUkernelNodeAttrID, CUkernelNodeAttrValue const *))dlsym(RTLD_NEXT, "cuGraphKernelNodeSetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphKernelNodeSetAttribute", kApiTypeDriver);

    lretval = lcuGraphKernelNodeSetAttribute(hNode, attr, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphKernelNodeSetAttribute cuGraphKernelNodeSetAttribute


#undef cuGraphDebugDotPrint
CUresult cuGraphDebugDotPrint(CUgraph hGraph, char const * path, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuGraphDebugDotPrint) (CUgraph, char const *, unsigned int) = (CUresult (*)(CUgraph, char const *, unsigned int))dlsym(RTLD_NEXT, "cuGraphDebugDotPrint");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphDebugDotPrint", kApiTypeDriver);

    lretval = lcuGraphDebugDotPrint(hGraph, path, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphDebugDotPrint cuGraphDebugDotPrint


#undef cuUserObjectCreate
CUresult cuUserObjectCreate(CUuserObject * object_out, void * ptr, CUhostFn destroy, unsigned int initialRefcount, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuUserObjectCreate) (CUuserObject *, void *, CUhostFn, unsigned int, unsigned int) = (CUresult (*)(CUuserObject *, void *, CUhostFn, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cuUserObjectCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuUserObjectCreate", kApiTypeDriver);

    lretval = lcuUserObjectCreate(object_out, ptr, destroy, initialRefcount, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuUserObjectCreate cuUserObjectCreate


#undef cuUserObjectRetain
CUresult cuUserObjectRetain(CUuserObject object, unsigned int count){
    CUresult lretval;
    CUresult (*lcuUserObjectRetain) (CUuserObject, unsigned int) = (CUresult (*)(CUuserObject, unsigned int))dlsym(RTLD_NEXT, "cuUserObjectRetain");
    
    /* pre exeuction logics */
    ac.add_counter("cuUserObjectRetain", kApiTypeDriver);

    lretval = lcuUserObjectRetain(object, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cuUserObjectRetain cuUserObjectRetain


#undef cuUserObjectRelease
CUresult cuUserObjectRelease(CUuserObject object, unsigned int count){
    CUresult lretval;
    CUresult (*lcuUserObjectRelease) (CUuserObject, unsigned int) = (CUresult (*)(CUuserObject, unsigned int))dlsym(RTLD_NEXT, "cuUserObjectRelease");
    
    /* pre exeuction logics */
    ac.add_counter("cuUserObjectRelease", kApiTypeDriver);

    lretval = lcuUserObjectRelease(object, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cuUserObjectRelease cuUserObjectRelease


#undef cuGraphRetainUserObject
CUresult cuGraphRetainUserObject(CUgraph graph, CUuserObject object, unsigned int count, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuGraphRetainUserObject) (CUgraph, CUuserObject, unsigned int, unsigned int) = (CUresult (*)(CUgraph, CUuserObject, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cuGraphRetainUserObject");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphRetainUserObject", kApiTypeDriver);

    lretval = lcuGraphRetainUserObject(graph, object, count, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphRetainUserObject cuGraphRetainUserObject


#undef cuGraphReleaseUserObject
CUresult cuGraphReleaseUserObject(CUgraph graph, CUuserObject object, unsigned int count){
    CUresult lretval;
    CUresult (*lcuGraphReleaseUserObject) (CUgraph, CUuserObject, unsigned int) = (CUresult (*)(CUgraph, CUuserObject, unsigned int))dlsym(RTLD_NEXT, "cuGraphReleaseUserObject");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphReleaseUserObject", kApiTypeDriver);

    lretval = lcuGraphReleaseUserObject(graph, object, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphReleaseUserObject cuGraphReleaseUserObject


#undef cuOccupancyMaxActiveBlocksPerMultiprocessor
CUresult cuOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize){
    CUresult lretval;
    CUresult (*lcuOccupancyMaxActiveBlocksPerMultiprocessor) (int *, CUfunction, int, size_t) = (CUresult (*)(int *, CUfunction, int, size_t))dlsym(RTLD_NEXT, "cuOccupancyMaxActiveBlocksPerMultiprocessor");
    
    /* pre exeuction logics */
    ac.add_counter("cuOccupancyMaxActiveBlocksPerMultiprocessor", kApiTypeDriver);

    lretval = lcuOccupancyMaxActiveBlocksPerMultiprocessor(numBlocks, func, blockSize, dynamicSMemSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cuOccupancyMaxActiveBlocksPerMultiprocessor cuOccupancyMaxActiveBlocksPerMultiprocessor


#undef cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags
CUresult cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags) (int *, CUfunction, int, size_t, unsigned int) = (CUresult (*)(int *, CUfunction, int, size_t, unsigned int))dlsym(RTLD_NEXT, "cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");
    
    /* pre exeuction logics */
    ac.add_counter("cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags", kApiTypeDriver);

    lretval = lcuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, func, blockSize, dynamicSMemSize, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags


#undef cuOccupancyMaxPotentialBlockSize
CUresult cuOccupancyMaxPotentialBlockSize(int * minGridSize, int * blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit){
    CUresult lretval;
    CUresult (*lcuOccupancyMaxPotentialBlockSize) (int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int) = (CUresult (*)(int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int))dlsym(RTLD_NEXT, "cuOccupancyMaxPotentialBlockSize");
    
    /* pre exeuction logics */
    ac.add_counter("cuOccupancyMaxPotentialBlockSize", kApiTypeDriver);

    lretval = lcuOccupancyMaxPotentialBlockSize(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit);
    
    /* post exeuction logics */

    return lretval;
}
#define cuOccupancyMaxPotentialBlockSize cuOccupancyMaxPotentialBlockSize


#undef cuOccupancyMaxPotentialBlockSizeWithFlags
CUresult cuOccupancyMaxPotentialBlockSizeWithFlags(int * minGridSize, int * blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuOccupancyMaxPotentialBlockSizeWithFlags) (int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int, unsigned int) = (CUresult (*)(int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int, unsigned int))dlsym(RTLD_NEXT, "cuOccupancyMaxPotentialBlockSizeWithFlags");
    
    /* pre exeuction logics */
    ac.add_counter("cuOccupancyMaxPotentialBlockSizeWithFlags", kApiTypeDriver);

    lretval = lcuOccupancyMaxPotentialBlockSizeWithFlags(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuOccupancyMaxPotentialBlockSizeWithFlags cuOccupancyMaxPotentialBlockSizeWithFlags


#undef cuOccupancyAvailableDynamicSMemPerBlock
CUresult cuOccupancyAvailableDynamicSMemPerBlock(size_t * dynamicSmemSize, CUfunction func, int numBlocks, int blockSize){
    CUresult lretval;
    CUresult (*lcuOccupancyAvailableDynamicSMemPerBlock) (size_t *, CUfunction, int, int) = (CUresult (*)(size_t *, CUfunction, int, int))dlsym(RTLD_NEXT, "cuOccupancyAvailableDynamicSMemPerBlock");
    
    /* pre exeuction logics */
    ac.add_counter("cuOccupancyAvailableDynamicSMemPerBlock", kApiTypeDriver);

    lretval = lcuOccupancyAvailableDynamicSMemPerBlock(dynamicSmemSize, func, numBlocks, blockSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cuOccupancyAvailableDynamicSMemPerBlock cuOccupancyAvailableDynamicSMemPerBlock


#undef cuTexRefSetArray
CUresult cuTexRefSetArray(CUtexref hTexRef, CUarray hArray, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuTexRefSetArray) (CUtexref, CUarray, unsigned int) = (CUresult (*)(CUtexref, CUarray, unsigned int))dlsym(RTLD_NEXT, "cuTexRefSetArray");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetArray", kApiTypeDriver);

    lretval = lcuTexRefSetArray(hTexRef, hArray, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetArray cuTexRefSetArray


#undef cuTexRefSetMipmappedArray
CUresult cuTexRefSetMipmappedArray(CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuTexRefSetMipmappedArray) (CUtexref, CUmipmappedArray, unsigned int) = (CUresult (*)(CUtexref, CUmipmappedArray, unsigned int))dlsym(RTLD_NEXT, "cuTexRefSetMipmappedArray");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetMipmappedArray", kApiTypeDriver);

    lretval = lcuTexRefSetMipmappedArray(hTexRef, hMipmappedArray, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetMipmappedArray cuTexRefSetMipmappedArray


#undef cuTexRefSetAddress_v2
CUresult cuTexRefSetAddress_v2(size_t * ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes){
    CUresult lretval;
    CUresult (*lcuTexRefSetAddress_v2) (size_t *, CUtexref, CUdeviceptr, size_t) = (CUresult (*)(size_t *, CUtexref, CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuTexRefSetAddress_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetAddress_v2", kApiTypeDriver);

    lretval = lcuTexRefSetAddress_v2(ByteOffset, hTexRef, dptr, bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetAddress_v2 cuTexRefSetAddress_v2


#undef cuTexRefSetAddress2D_v3
CUresult cuTexRefSetAddress2D_v3(CUtexref hTexRef, CUDA_ARRAY_DESCRIPTOR const * desc, CUdeviceptr dptr, size_t Pitch){
    CUresult lretval;
    CUresult (*lcuTexRefSetAddress2D_v3) (CUtexref, CUDA_ARRAY_DESCRIPTOR const *, CUdeviceptr, size_t) = (CUresult (*)(CUtexref, CUDA_ARRAY_DESCRIPTOR const *, CUdeviceptr, size_t))dlsym(RTLD_NEXT, "cuTexRefSetAddress2D_v3");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetAddress2D_v3", kApiTypeDriver);

    lretval = lcuTexRefSetAddress2D_v3(hTexRef, desc, dptr, Pitch);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetAddress2D_v3 cuTexRefSetAddress2D_v3


#undef cuTexRefSetFormat
CUresult cuTexRefSetFormat(CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents){
    CUresult lretval;
    CUresult (*lcuTexRefSetFormat) (CUtexref, CUarray_format, int) = (CUresult (*)(CUtexref, CUarray_format, int))dlsym(RTLD_NEXT, "cuTexRefSetFormat");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetFormat", kApiTypeDriver);

    lretval = lcuTexRefSetFormat(hTexRef, fmt, NumPackedComponents);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetFormat cuTexRefSetFormat


#undef cuTexRefSetAddressMode
CUresult cuTexRefSetAddressMode(CUtexref hTexRef, int dim, CUaddress_mode am){
    CUresult lretval;
    CUresult (*lcuTexRefSetAddressMode) (CUtexref, int, CUaddress_mode) = (CUresult (*)(CUtexref, int, CUaddress_mode))dlsym(RTLD_NEXT, "cuTexRefSetAddressMode");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetAddressMode", kApiTypeDriver);

    lretval = lcuTexRefSetAddressMode(hTexRef, dim, am);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetAddressMode cuTexRefSetAddressMode


#undef cuTexRefSetFilterMode
CUresult cuTexRefSetFilterMode(CUtexref hTexRef, CUfilter_mode fm){
    CUresult lretval;
    CUresult (*lcuTexRefSetFilterMode) (CUtexref, CUfilter_mode) = (CUresult (*)(CUtexref, CUfilter_mode))dlsym(RTLD_NEXT, "cuTexRefSetFilterMode");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetFilterMode", kApiTypeDriver);

    lretval = lcuTexRefSetFilterMode(hTexRef, fm);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetFilterMode cuTexRefSetFilterMode


#undef cuTexRefSetMipmapFilterMode
CUresult cuTexRefSetMipmapFilterMode(CUtexref hTexRef, CUfilter_mode fm){
    CUresult lretval;
    CUresult (*lcuTexRefSetMipmapFilterMode) (CUtexref, CUfilter_mode) = (CUresult (*)(CUtexref, CUfilter_mode))dlsym(RTLD_NEXT, "cuTexRefSetMipmapFilterMode");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetMipmapFilterMode", kApiTypeDriver);

    lretval = lcuTexRefSetMipmapFilterMode(hTexRef, fm);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetMipmapFilterMode cuTexRefSetMipmapFilterMode


#undef cuTexRefSetMipmapLevelBias
CUresult cuTexRefSetMipmapLevelBias(CUtexref hTexRef, float bias){
    CUresult lretval;
    CUresult (*lcuTexRefSetMipmapLevelBias) (CUtexref, float) = (CUresult (*)(CUtexref, float))dlsym(RTLD_NEXT, "cuTexRefSetMipmapLevelBias");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetMipmapLevelBias", kApiTypeDriver);

    lretval = lcuTexRefSetMipmapLevelBias(hTexRef, bias);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetMipmapLevelBias cuTexRefSetMipmapLevelBias


#undef cuTexRefSetMipmapLevelClamp
CUresult cuTexRefSetMipmapLevelClamp(CUtexref hTexRef, float minMipmapLevelClamp, float maxMipmapLevelClamp){
    CUresult lretval;
    CUresult (*lcuTexRefSetMipmapLevelClamp) (CUtexref, float, float) = (CUresult (*)(CUtexref, float, float))dlsym(RTLD_NEXT, "cuTexRefSetMipmapLevelClamp");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetMipmapLevelClamp", kApiTypeDriver);

    lretval = lcuTexRefSetMipmapLevelClamp(hTexRef, minMipmapLevelClamp, maxMipmapLevelClamp);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetMipmapLevelClamp cuTexRefSetMipmapLevelClamp


#undef cuTexRefSetMaxAnisotropy
CUresult cuTexRefSetMaxAnisotropy(CUtexref hTexRef, unsigned int maxAniso){
    CUresult lretval;
    CUresult (*lcuTexRefSetMaxAnisotropy) (CUtexref, unsigned int) = (CUresult (*)(CUtexref, unsigned int))dlsym(RTLD_NEXT, "cuTexRefSetMaxAnisotropy");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetMaxAnisotropy", kApiTypeDriver);

    lretval = lcuTexRefSetMaxAnisotropy(hTexRef, maxAniso);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetMaxAnisotropy cuTexRefSetMaxAnisotropy


#undef cuTexRefSetBorderColor
CUresult cuTexRefSetBorderColor(CUtexref hTexRef, float * pBorderColor){
    CUresult lretval;
    CUresult (*lcuTexRefSetBorderColor) (CUtexref, float *) = (CUresult (*)(CUtexref, float *))dlsym(RTLD_NEXT, "cuTexRefSetBorderColor");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetBorderColor", kApiTypeDriver);

    lretval = lcuTexRefSetBorderColor(hTexRef, pBorderColor);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetBorderColor cuTexRefSetBorderColor


#undef cuTexRefSetFlags
CUresult cuTexRefSetFlags(CUtexref hTexRef, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuTexRefSetFlags) (CUtexref, unsigned int) = (CUresult (*)(CUtexref, unsigned int))dlsym(RTLD_NEXT, "cuTexRefSetFlags");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefSetFlags", kApiTypeDriver);

    lretval = lcuTexRefSetFlags(hTexRef, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefSetFlags cuTexRefSetFlags


#undef cuTexRefGetAddress_v2
CUresult cuTexRefGetAddress_v2(CUdeviceptr * pdptr, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetAddress_v2) (CUdeviceptr *, CUtexref) = (CUresult (*)(CUdeviceptr *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetAddress_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetAddress_v2", kApiTypeDriver);

    lretval = lcuTexRefGetAddress_v2(pdptr, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetAddress_v2 cuTexRefGetAddress_v2


#undef cuTexRefGetArray
CUresult cuTexRefGetArray(CUarray * phArray, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetArray) (CUarray *, CUtexref) = (CUresult (*)(CUarray *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetArray");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetArray", kApiTypeDriver);

    lretval = lcuTexRefGetArray(phArray, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetArray cuTexRefGetArray


#undef cuTexRefGetMipmappedArray
CUresult cuTexRefGetMipmappedArray(CUmipmappedArray * phMipmappedArray, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetMipmappedArray) (CUmipmappedArray *, CUtexref) = (CUresult (*)(CUmipmappedArray *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetMipmappedArray");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetMipmappedArray", kApiTypeDriver);

    lretval = lcuTexRefGetMipmappedArray(phMipmappedArray, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetMipmappedArray cuTexRefGetMipmappedArray


#undef cuTexRefGetAddressMode
CUresult cuTexRefGetAddressMode(CUaddress_mode * pam, CUtexref hTexRef, int dim){
    CUresult lretval;
    CUresult (*lcuTexRefGetAddressMode) (CUaddress_mode *, CUtexref, int) = (CUresult (*)(CUaddress_mode *, CUtexref, int))dlsym(RTLD_NEXT, "cuTexRefGetAddressMode");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetAddressMode", kApiTypeDriver);

    lretval = lcuTexRefGetAddressMode(pam, hTexRef, dim);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetAddressMode cuTexRefGetAddressMode


#undef cuTexRefGetFilterMode
CUresult cuTexRefGetFilterMode(CUfilter_mode * pfm, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetFilterMode) (CUfilter_mode *, CUtexref) = (CUresult (*)(CUfilter_mode *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetFilterMode");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetFilterMode", kApiTypeDriver);

    lretval = lcuTexRefGetFilterMode(pfm, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetFilterMode cuTexRefGetFilterMode


#undef cuTexRefGetFormat
CUresult cuTexRefGetFormat(CUarray_format * pFormat, int * pNumChannels, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetFormat) (CUarray_format *, int *, CUtexref) = (CUresult (*)(CUarray_format *, int *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetFormat");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetFormat", kApiTypeDriver);

    lretval = lcuTexRefGetFormat(pFormat, pNumChannels, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetFormat cuTexRefGetFormat


#undef cuTexRefGetMipmapFilterMode
CUresult cuTexRefGetMipmapFilterMode(CUfilter_mode * pfm, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetMipmapFilterMode) (CUfilter_mode *, CUtexref) = (CUresult (*)(CUfilter_mode *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetMipmapFilterMode");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetMipmapFilterMode", kApiTypeDriver);

    lretval = lcuTexRefGetMipmapFilterMode(pfm, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetMipmapFilterMode cuTexRefGetMipmapFilterMode


#undef cuTexRefGetMipmapLevelBias
CUresult cuTexRefGetMipmapLevelBias(float * pbias, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetMipmapLevelBias) (float *, CUtexref) = (CUresult (*)(float *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetMipmapLevelBias");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetMipmapLevelBias", kApiTypeDriver);

    lretval = lcuTexRefGetMipmapLevelBias(pbias, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetMipmapLevelBias cuTexRefGetMipmapLevelBias


#undef cuTexRefGetMipmapLevelClamp
CUresult cuTexRefGetMipmapLevelClamp(float * pminMipmapLevelClamp, float * pmaxMipmapLevelClamp, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetMipmapLevelClamp) (float *, float *, CUtexref) = (CUresult (*)(float *, float *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetMipmapLevelClamp");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetMipmapLevelClamp", kApiTypeDriver);

    lretval = lcuTexRefGetMipmapLevelClamp(pminMipmapLevelClamp, pmaxMipmapLevelClamp, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetMipmapLevelClamp cuTexRefGetMipmapLevelClamp


#undef cuTexRefGetMaxAnisotropy
CUresult cuTexRefGetMaxAnisotropy(int * pmaxAniso, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetMaxAnisotropy) (int *, CUtexref) = (CUresult (*)(int *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetMaxAnisotropy");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetMaxAnisotropy", kApiTypeDriver);

    lretval = lcuTexRefGetMaxAnisotropy(pmaxAniso, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetMaxAnisotropy cuTexRefGetMaxAnisotropy


#undef cuTexRefGetBorderColor
CUresult cuTexRefGetBorderColor(float * pBorderColor, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetBorderColor) (float *, CUtexref) = (CUresult (*)(float *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetBorderColor");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetBorderColor", kApiTypeDriver);

    lretval = lcuTexRefGetBorderColor(pBorderColor, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetBorderColor cuTexRefGetBorderColor


#undef cuTexRefGetFlags
CUresult cuTexRefGetFlags(unsigned int * pFlags, CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefGetFlags) (unsigned int *, CUtexref) = (CUresult (*)(unsigned int *, CUtexref))dlsym(RTLD_NEXT, "cuTexRefGetFlags");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefGetFlags", kApiTypeDriver);

    lretval = lcuTexRefGetFlags(pFlags, hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefGetFlags cuTexRefGetFlags


#undef cuTexRefCreate
CUresult cuTexRefCreate(CUtexref * pTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefCreate) (CUtexref *) = (CUresult (*)(CUtexref *))dlsym(RTLD_NEXT, "cuTexRefCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefCreate", kApiTypeDriver);

    lretval = lcuTexRefCreate(pTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefCreate cuTexRefCreate


#undef cuTexRefDestroy
CUresult cuTexRefDestroy(CUtexref hTexRef){
    CUresult lretval;
    CUresult (*lcuTexRefDestroy) (CUtexref) = (CUresult (*)(CUtexref))dlsym(RTLD_NEXT, "cuTexRefDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexRefDestroy", kApiTypeDriver);

    lretval = lcuTexRefDestroy(hTexRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexRefDestroy cuTexRefDestroy


#undef cuSurfRefSetArray
CUresult cuSurfRefSetArray(CUsurfref hSurfRef, CUarray hArray, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuSurfRefSetArray) (CUsurfref, CUarray, unsigned int) = (CUresult (*)(CUsurfref, CUarray, unsigned int))dlsym(RTLD_NEXT, "cuSurfRefSetArray");
    
    /* pre exeuction logics */
    ac.add_counter("cuSurfRefSetArray", kApiTypeDriver);

    lretval = lcuSurfRefSetArray(hSurfRef, hArray, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuSurfRefSetArray cuSurfRefSetArray


#undef cuSurfRefGetArray
CUresult cuSurfRefGetArray(CUarray * phArray, CUsurfref hSurfRef){
    CUresult lretval;
    CUresult (*lcuSurfRefGetArray) (CUarray *, CUsurfref) = (CUresult (*)(CUarray *, CUsurfref))dlsym(RTLD_NEXT, "cuSurfRefGetArray");
    
    /* pre exeuction logics */
    ac.add_counter("cuSurfRefGetArray", kApiTypeDriver);

    lretval = lcuSurfRefGetArray(phArray, hSurfRef);
    
    /* post exeuction logics */

    return lretval;
}
#define cuSurfRefGetArray cuSurfRefGetArray


#undef cuTexObjectCreate
CUresult cuTexObjectCreate(CUtexObject * pTexObject, CUDA_RESOURCE_DESC const * pResDesc, CUDA_TEXTURE_DESC const * pTexDesc, CUDA_RESOURCE_VIEW_DESC const * pResViewDesc){
    CUresult lretval;
    CUresult (*lcuTexObjectCreate) (CUtexObject *, CUDA_RESOURCE_DESC const *, CUDA_TEXTURE_DESC const *, CUDA_RESOURCE_VIEW_DESC const *) = (CUresult (*)(CUtexObject *, CUDA_RESOURCE_DESC const *, CUDA_TEXTURE_DESC const *, CUDA_RESOURCE_VIEW_DESC const *))dlsym(RTLD_NEXT, "cuTexObjectCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexObjectCreate", kApiTypeDriver);

    lretval = lcuTexObjectCreate(pTexObject, pResDesc, pTexDesc, pResViewDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexObjectCreate cuTexObjectCreate


#undef cuTexObjectDestroy
CUresult cuTexObjectDestroy(CUtexObject texObject){
    CUresult lretval;
    CUresult (*lcuTexObjectDestroy) (CUtexObject) = (CUresult (*)(CUtexObject))dlsym(RTLD_NEXT, "cuTexObjectDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexObjectDestroy", kApiTypeDriver);

    lretval = lcuTexObjectDestroy(texObject);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexObjectDestroy cuTexObjectDestroy


#undef cuTexObjectGetResourceDesc
CUresult cuTexObjectGetResourceDesc(CUDA_RESOURCE_DESC * pResDesc, CUtexObject texObject){
    CUresult lretval;
    CUresult (*lcuTexObjectGetResourceDesc) (CUDA_RESOURCE_DESC *, CUtexObject) = (CUresult (*)(CUDA_RESOURCE_DESC *, CUtexObject))dlsym(RTLD_NEXT, "cuTexObjectGetResourceDesc");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexObjectGetResourceDesc", kApiTypeDriver);

    lretval = lcuTexObjectGetResourceDesc(pResDesc, texObject);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexObjectGetResourceDesc cuTexObjectGetResourceDesc


#undef cuTexObjectGetTextureDesc
CUresult cuTexObjectGetTextureDesc(CUDA_TEXTURE_DESC * pTexDesc, CUtexObject texObject){
    CUresult lretval;
    CUresult (*lcuTexObjectGetTextureDesc) (CUDA_TEXTURE_DESC *, CUtexObject) = (CUresult (*)(CUDA_TEXTURE_DESC *, CUtexObject))dlsym(RTLD_NEXT, "cuTexObjectGetTextureDesc");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexObjectGetTextureDesc", kApiTypeDriver);

    lretval = lcuTexObjectGetTextureDesc(pTexDesc, texObject);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexObjectGetTextureDesc cuTexObjectGetTextureDesc


#undef cuTexObjectGetResourceViewDesc
CUresult cuTexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC * pResViewDesc, CUtexObject texObject){
    CUresult lretval;
    CUresult (*lcuTexObjectGetResourceViewDesc) (CUDA_RESOURCE_VIEW_DESC *, CUtexObject) = (CUresult (*)(CUDA_RESOURCE_VIEW_DESC *, CUtexObject))dlsym(RTLD_NEXT, "cuTexObjectGetResourceViewDesc");
    
    /* pre exeuction logics */
    ac.add_counter("cuTexObjectGetResourceViewDesc", kApiTypeDriver);

    lretval = lcuTexObjectGetResourceViewDesc(pResViewDesc, texObject);
    
    /* post exeuction logics */

    return lretval;
}
#define cuTexObjectGetResourceViewDesc cuTexObjectGetResourceViewDesc


#undef cuSurfObjectCreate
CUresult cuSurfObjectCreate(CUsurfObject * pSurfObject, CUDA_RESOURCE_DESC const * pResDesc){
    CUresult lretval;
    CUresult (*lcuSurfObjectCreate) (CUsurfObject *, CUDA_RESOURCE_DESC const *) = (CUresult (*)(CUsurfObject *, CUDA_RESOURCE_DESC const *))dlsym(RTLD_NEXT, "cuSurfObjectCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cuSurfObjectCreate", kApiTypeDriver);

    lretval = lcuSurfObjectCreate(pSurfObject, pResDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cuSurfObjectCreate cuSurfObjectCreate


#undef cuSurfObjectDestroy
CUresult cuSurfObjectDestroy(CUsurfObject surfObject){
    CUresult lretval;
    CUresult (*lcuSurfObjectDestroy) (CUsurfObject) = (CUresult (*)(CUsurfObject))dlsym(RTLD_NEXT, "cuSurfObjectDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cuSurfObjectDestroy", kApiTypeDriver);

    lretval = lcuSurfObjectDestroy(surfObject);
    
    /* post exeuction logics */

    return lretval;
}
#define cuSurfObjectDestroy cuSurfObjectDestroy


#undef cuSurfObjectGetResourceDesc
CUresult cuSurfObjectGetResourceDesc(CUDA_RESOURCE_DESC * pResDesc, CUsurfObject surfObject){
    CUresult lretval;
    CUresult (*lcuSurfObjectGetResourceDesc) (CUDA_RESOURCE_DESC *, CUsurfObject) = (CUresult (*)(CUDA_RESOURCE_DESC *, CUsurfObject))dlsym(RTLD_NEXT, "cuSurfObjectGetResourceDesc");
    
    /* pre exeuction logics */
    ac.add_counter("cuSurfObjectGetResourceDesc", kApiTypeDriver);

    lretval = lcuSurfObjectGetResourceDesc(pResDesc, surfObject);
    
    /* post exeuction logics */

    return lretval;
}
#define cuSurfObjectGetResourceDesc cuSurfObjectGetResourceDesc


#undef cuDeviceCanAccessPeer
CUresult cuDeviceCanAccessPeer(int * canAccessPeer, CUdevice dev, CUdevice peerDev){
    CUresult lretval;
    CUresult (*lcuDeviceCanAccessPeer) (int *, CUdevice, CUdevice) = (CUresult (*)(int *, CUdevice, CUdevice))dlsym(RTLD_NEXT, "cuDeviceCanAccessPeer");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceCanAccessPeer", kApiTypeDriver);

    lretval = lcuDeviceCanAccessPeer(canAccessPeer, dev, peerDev);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceCanAccessPeer cuDeviceCanAccessPeer


#undef cuCtxEnablePeerAccess
CUresult cuCtxEnablePeerAccess(CUcontext peerContext, unsigned int Flags){
    CUresult lretval;
    CUresult (*lcuCtxEnablePeerAccess) (CUcontext, unsigned int) = (CUresult (*)(CUcontext, unsigned int))dlsym(RTLD_NEXT, "cuCtxEnablePeerAccess");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxEnablePeerAccess", kApiTypeDriver);

    lretval = lcuCtxEnablePeerAccess(peerContext, Flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxEnablePeerAccess cuCtxEnablePeerAccess


#undef cuCtxDisablePeerAccess
CUresult cuCtxDisablePeerAccess(CUcontext peerContext){
    CUresult lretval;
    CUresult (*lcuCtxDisablePeerAccess) (CUcontext) = (CUresult (*)(CUcontext))dlsym(RTLD_NEXT, "cuCtxDisablePeerAccess");
    
    /* pre exeuction logics */
    ac.add_counter("cuCtxDisablePeerAccess", kApiTypeDriver);

    lretval = lcuCtxDisablePeerAccess(peerContext);
    
    /* post exeuction logics */

    return lretval;
}
#define cuCtxDisablePeerAccess cuCtxDisablePeerAccess


#undef cuDeviceGetP2PAttribute
CUresult cuDeviceGetP2PAttribute(int * value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice){
    CUresult lretval;
    CUresult (*lcuDeviceGetP2PAttribute) (int *, CUdevice_P2PAttribute, CUdevice, CUdevice) = (CUresult (*)(int *, CUdevice_P2PAttribute, CUdevice, CUdevice))dlsym(RTLD_NEXT, "cuDeviceGetP2PAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cuDeviceGetP2PAttribute", kApiTypeDriver);

    lretval = lcuDeviceGetP2PAttribute(value, attrib, srcDevice, dstDevice);
    
    /* post exeuction logics */

    return lretval;
}
#define cuDeviceGetP2PAttribute cuDeviceGetP2PAttribute


#undef cuGraphicsUnregisterResource
CUresult cuGraphicsUnregisterResource(CUgraphicsResource resource){
    CUresult lretval;
    CUresult (*lcuGraphicsUnregisterResource) (CUgraphicsResource) = (CUresult (*)(CUgraphicsResource))dlsym(RTLD_NEXT, "cuGraphicsUnregisterResource");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphicsUnregisterResource", kApiTypeDriver);

    lretval = lcuGraphicsUnregisterResource(resource);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphicsUnregisterResource cuGraphicsUnregisterResource


#undef cuGraphicsSubResourceGetMappedArray
CUresult cuGraphicsSubResourceGetMappedArray(CUarray * pArray, CUgraphicsResource resource, unsigned int arrayIndex, unsigned int mipLevel){
    CUresult lretval;
    CUresult (*lcuGraphicsSubResourceGetMappedArray) (CUarray *, CUgraphicsResource, unsigned int, unsigned int) = (CUresult (*)(CUarray *, CUgraphicsResource, unsigned int, unsigned int))dlsym(RTLD_NEXT, "cuGraphicsSubResourceGetMappedArray");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphicsSubResourceGetMappedArray", kApiTypeDriver);

    lretval = lcuGraphicsSubResourceGetMappedArray(pArray, resource, arrayIndex, mipLevel);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphicsSubResourceGetMappedArray cuGraphicsSubResourceGetMappedArray


#undef cuGraphicsResourceGetMappedMipmappedArray
CUresult cuGraphicsResourceGetMappedMipmappedArray(CUmipmappedArray * pMipmappedArray, CUgraphicsResource resource){
    CUresult lretval;
    CUresult (*lcuGraphicsResourceGetMappedMipmappedArray) (CUmipmappedArray *, CUgraphicsResource) = (CUresult (*)(CUmipmappedArray *, CUgraphicsResource))dlsym(RTLD_NEXT, "cuGraphicsResourceGetMappedMipmappedArray");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphicsResourceGetMappedMipmappedArray", kApiTypeDriver);

    lretval = lcuGraphicsResourceGetMappedMipmappedArray(pMipmappedArray, resource);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphicsResourceGetMappedMipmappedArray cuGraphicsResourceGetMappedMipmappedArray


#undef cuGraphicsResourceGetMappedPointer_v2
CUresult cuGraphicsResourceGetMappedPointer_v2(CUdeviceptr * pDevPtr, size_t * pSize, CUgraphicsResource resource){
    CUresult lretval;
    CUresult (*lcuGraphicsResourceGetMappedPointer_v2) (CUdeviceptr *, size_t *, CUgraphicsResource) = (CUresult (*)(CUdeviceptr *, size_t *, CUgraphicsResource))dlsym(RTLD_NEXT, "cuGraphicsResourceGetMappedPointer_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphicsResourceGetMappedPointer_v2", kApiTypeDriver);

    lretval = lcuGraphicsResourceGetMappedPointer_v2(pDevPtr, pSize, resource);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphicsResourceGetMappedPointer_v2 cuGraphicsResourceGetMappedPointer_v2


#undef cuGraphicsResourceSetMapFlags_v2
CUresult cuGraphicsResourceSetMapFlags_v2(CUgraphicsResource resource, unsigned int flags){
    CUresult lretval;
    CUresult (*lcuGraphicsResourceSetMapFlags_v2) (CUgraphicsResource, unsigned int) = (CUresult (*)(CUgraphicsResource, unsigned int))dlsym(RTLD_NEXT, "cuGraphicsResourceSetMapFlags_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphicsResourceSetMapFlags_v2", kApiTypeDriver);

    lretval = lcuGraphicsResourceSetMapFlags_v2(resource, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphicsResourceSetMapFlags_v2 cuGraphicsResourceSetMapFlags_v2


#undef cuGraphicsMapResources
CUresult cuGraphicsMapResources(unsigned int count, CUgraphicsResource * resources, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuGraphicsMapResources) (unsigned int, CUgraphicsResource *, CUstream) = (CUresult (*)(unsigned int, CUgraphicsResource *, CUstream))dlsym(RTLD_NEXT, "cuGraphicsMapResources");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphicsMapResources", kApiTypeDriver);

    lretval = lcuGraphicsMapResources(count, resources, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphicsMapResources cuGraphicsMapResources


#undef cuGraphicsUnmapResources
CUresult cuGraphicsUnmapResources(unsigned int count, CUgraphicsResource * resources, CUstream hStream){
    CUresult lretval;
    CUresult (*lcuGraphicsUnmapResources) (unsigned int, CUgraphicsResource *, CUstream) = (CUresult (*)(unsigned int, CUgraphicsResource *, CUstream))dlsym(RTLD_NEXT, "cuGraphicsUnmapResources");
    
    /* pre exeuction logics */
    ac.add_counter("cuGraphicsUnmapResources", kApiTypeDriver);

    lretval = lcuGraphicsUnmapResources(count, resources, hStream);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGraphicsUnmapResources cuGraphicsUnmapResources


#undef cuGetProcAddress
CUresult cuGetProcAddress(char const * symbol, void * * pfn, int cudaVersion, cuuint64_t flags){
    CUresult lretval;
    CUresult (*lcuGetProcAddress) (char const *, void * *, int, cuuint64_t) = (CUresult (*)(char const *, void * *, int, cuuint64_t))dlsym(RTLD_NEXT, "cuGetProcAddress");
    
    /* pre exeuction logics */
    ac.add_counter("cuGetProcAddress", kApiTypeDriver);

    lretval = lcuGetProcAddress(symbol, pfn, cudaVersion, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGetProcAddress cuGetProcAddress


#undef cuGetExportTable
CUresult cuGetExportTable(void const * * ppExportTable, CUuuid const * pExportTableId){
    CUresult lretval;
    CUresult (*lcuGetExportTable) (void const * *, CUuuid const *) = (CUresult (*)(void const * *, CUuuid const *))dlsym(RTLD_NEXT, "cuGetExportTable");
    
    /* pre exeuction logics */
    ac.add_counter("cuGetExportTable", kApiTypeDriver);

    lretval = lcuGetExportTable(ppExportTable, pExportTableId);
    
    /* post exeuction logics */

    return lretval;
}
#define cuGetExportTable cuGetExportTable


#undef cuFlushGPUDirectRDMAWrites
CUresult cuFlushGPUDirectRDMAWrites(CUflushGPUDirectRDMAWritesTarget target, CUflushGPUDirectRDMAWritesScope scope){
    CUresult lretval;
    CUresult (*lcuFlushGPUDirectRDMAWrites) (CUflushGPUDirectRDMAWritesTarget, CUflushGPUDirectRDMAWritesScope) = (CUresult (*)(CUflushGPUDirectRDMAWritesTarget, CUflushGPUDirectRDMAWritesScope))dlsym(RTLD_NEXT, "cuFlushGPUDirectRDMAWrites");
    
    /* pre exeuction logics */
    ac.add_counter("cuFlushGPUDirectRDMAWrites", kApiTypeDriver);

    lretval = lcuFlushGPUDirectRDMAWrites(target, scope);
    
    /* post exeuction logics */

    return lretval;
}
#define cuFlushGPUDirectRDMAWrites cuFlushGPUDirectRDMAWrites

