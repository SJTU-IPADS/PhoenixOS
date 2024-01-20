#include <iostream>
#include <vector>
#include <cuda.h>
#include <dlfcn.h>
#include <cuda_runtime.h>

#include "cudam.h"
#include "buffer_manager.h"


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


cudaError_t cudaArrayGetMemoryRequirements(cudaArrayMemoryRequirements * memoryRequirements, cudaArray_t array, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaArrayGetMemoryRequirements) (cudaArrayMemoryRequirements *, cudaArray_t, int) = (cudaError_t (*)(cudaArrayMemoryRequirements *, cudaArray_t, int))dlsym(RTLD_NEXT, "cudaArrayGetMemoryRequirements");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaArrayGetMemoryRequirements",
        /* api_index */ CUDA_MEMORY_API_cudaArrayGetMemoryRequirements,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaArrayGetMemoryRequirements(memoryRequirements, array, device);
    
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


cudaError_t cudaFree(void * devPtr){
    cudaError_t lretval;
    cudaError_t (*lcudaFree) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaFree");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFree",
        /* api_index */ CUDA_MEMORY_API_cudaFree,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaFree(devPtr);
    
    /* NOTE: post-interception */
    if(lretval == cudaSuccess){
        bufferManager.markBufferFreed(devPtr);
    }

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


cudaError_t cudaFreeHost(void * ptr){
    cudaError_t lretval;
    cudaError_t (*lcudaFreeHost) (void *) = (cudaError_t (*)(void *))dlsym(RTLD_NEXT, "cudaFreeHost");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaFreeHost",
        /* api_index */ CUDA_MEMORY_API_cudaFreeHost,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaFreeHost(ptr);
    
    /* NOTE: post-interception */
    if(lretval == cudaSuccess){
        bufferManager.markBufferFreed(ptr);
    }

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


cudaError_t cudaHostAlloc(void * * pHost, size_t size, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaHostAlloc) (void * *, size_t, unsigned int) = (cudaError_t (*)(void * *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaHostAlloc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaHostAlloc",
        /* api_index */ CUDA_MEMORY_API_cudaHostAlloc,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaHostAlloc(pHost, size, flags);
    
    /* NOTE: post-interception */
    if(lretval == cudaSuccess){
        bufferManager.recordBuffer(
            /* ptr */ pHost, 
            /* addr */ *pHost, 
            /* size */ size, 
            /* device_id */ BUFFER_DEVICE_ID_CPU, 
            /* is_page_locked */ true, 
            /* is_unified */ false
        );
    }

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


cudaError_t cudaMalloc(void * * devPtr, size_t size){
    cudaError_t lretval;
    cudaError_t (*lcudaMalloc) (void * *, size_t) = (cudaError_t (*)(void * *, size_t))dlsym(RTLD_NEXT, "cudaMalloc");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMalloc",
        /* api_index */ CUDA_MEMORY_API_cudaMalloc,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaMalloc(devPtr, size);
    
    /* NOTE: post-interception */
    if(lretval == cudaSuccess){
        bufferManager.recordBuffer(
            /* ptr */ devPtr, 
            /* addr */ *devPtr, 
            /* size */ size, 
            /* device_id */ bufferManager.getSelectedGpuDeviceId(),
            /* is_page_locked */ false,
            /* is_unified */ false
        );
    }

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


cudaError_t cudaMallocHost(void * * ptr, size_t size){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocHost) (void * *, size_t) = (cudaError_t (*)(void * *, size_t))dlsym(RTLD_NEXT, "cudaMallocHost");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMallocHost",
        /* api_index */ CUDA_MEMORY_API_cudaMallocHost,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaMallocHost(ptr, size);
    
    /* NOTE: post-interception */
    if(lretval == cudaSuccess){
        bufferManager.recordBuffer(
            /* ptr */ ptr,
            /* addr */ *ptr,
            /* size */ size,
            /* device_id */ BUFFER_DEVICE_ID_CPU,
            /* is_page_locked */ true,
            /* is_unified */ false
        );
    }

    return lretval;
}


cudaError_t cudaMallocManaged(void * * devPtr, size_t size, unsigned int flags){
    cudaError_t lretval;
    cudaError_t (*lcudaMallocManaged) (void * *, size_t, unsigned int) = (cudaError_t (*)(void * *, size_t, unsigned int))dlsym(RTLD_NEXT, "cudaMallocManaged");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMallocManaged",
        /* api_index */ CUDA_MEMORY_API_cudaMallocManaged,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaMallocManaged(devPtr, size, flags);
    
    /* NOTE: post-interception */
    if(lretval == cudaSuccess){
        bufferManager.recordBuffer(
            /* ptr */ devPtr, 
            /* addr */ *devPtr, 
            /* size */ size, 
            /* device_id */ BUFFER_DEVICE_ID_UNIFIED,
            /* is_page_locked */ false,
            /* is_unified */ true
        );
    }

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


cudaError_t cudaMemRangeGetAttributes(void * * data, size_t * dataSizes, cudaMemRangeAttribute * * attributes, size_t numAttributes, void const * devPtr, size_t count){
    cudaError_t lretval;
    cudaError_t (*lcudaMemRangeGetAttributes) (void * *, size_t *, cudaMemRangeAttribute * *, size_t, void const *, size_t) = (cudaError_t (*)(void * *, size_t *, cudaMemRangeAttribute * *, size_t, void const *, size_t))dlsym(RTLD_NEXT, "cudaMemRangeGetAttributes");

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


cudaError_t cudaMemcpy(void * dst, void const * src, size_t count, cudaMemcpyKind kind){
    cudaError_t lretval;
    Buffer *dst_buffer, *src_buffer;
    bool found_dst_buffer = false, found_src_buffer = false;
    std::vector<Buffer*> dst_buffer_list, src_buffer_list;
    uint8_t dst_desired_pos, src_desired_pos;
    cudaError_t (*lcudaMemcpy) (void *, void const *, size_t, cudaMemcpyKind) = (cudaError_t (*)(void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpy",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpy,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpy(dst, src, count, kind);
    
    /* NOTE: post-interception */
    if(lretval == cudaSuccess){
        auto getDesiredDeviceId = [&](cudaMemcpyKind kind, bool isDst) -> int16_t {
            switch (kind)
            {
            case cudaMemcpyHostToHost:
                return BUFFER_DEVICE_ID_CPU;
            
            case cudaMemcpyHostToDevice:
                return isDst ? bufferManager.getSelectedGpuDeviceId() : BUFFER_DEVICE_ID_CPU;

            case cudaMemcpyDeviceToHost:
                return isDst ? BUFFER_DEVICE_ID_CPU : bufferManager.getSelectedGpuDeviceId();

            case cudaMemcpyDeviceToDevice:
                return bufferManager.getSelectedGpuDeviceId();

            case cudaMemcpyDefault:
                return BUFFER_DEVICE_ID_UNIFIED;

            default:
                CUDAM_WARNING("unknown cudaMemcpyKind %d", kind);
                return BUFFER_DEVICE_ID_CPU;
            }
        };

        // try to obtain previous recorded buffer
        dst_buffer_list = bufferManager.getPartialBuffersByRange(
            /* base_addr */ dst, 
            /* size */ count, 
            /* isExclusive */ false,
            /* device_id */ getDesiredDeviceId(kind, /* isDst */ true)
        );
        
        // check whether the buffer is found
        // the founded one and only buffer should totally contains the given destination range
        if(dst_buffer_list.size() == 1){
            if(dst_buffer_list[0]->isInRange(dst, count, /* isExclusive */ false)){
                found_dst_buffer = true;
            } else {
                CUDAM_WARNING_MESSAGE(
                    "the given desination buffer (%p-%p) exceeds the one and only previous-recored buffer (%p-%p), need to record a new one",
                    dst, (uint8_t*)dst+count,
                    dst_buffer_list[0]->getAddr(), ((uint8_t*)dst_buffer_list[0]->getAddr()+dst_buffer_list[0]->getSize())
                );
            }
        } else {
            CUDAM_WARNING_MESSAGE(
                "%lu previous-recorded buffer contain range %p-%p, need to record a new one",
                dst_buffer_list.size(), dst, (uint8_t*)dst + count
            );
        }

        if(!found_dst_buffer){
            if(RETVAL_SUCCESS != bufferManager.recordBuffer(
                /* ptr */ nullptr,  // we don't know the origin pointer here, don't record
                /* addr */ dst,
                /* size */ count, 
                /* device_id */ getDesiredDeviceId(kind, true), 
                /* is_page_locked */ false,     // previous-unseen buffer, shouldn't be page-locked
                /* is_unified */ false          // previous-unseen buffer, shouldn't be unified
            )){
                CUDAM_ERROR("failed to record destination buffer with address %p, after failing to find", dst);
                return lretval;
            }
            dst_buffer_list = bufferManager.getPartialBuffersByRange(
                /* base_addr */ dst,
                /* size */ count,
                /* isExclusive */ false,
                /* device_id */ getDesiredDeviceId(kind, /* isDst */ true)
            );
            assert(dst_buffer_list.size() == 1);
        }
        dst_buffer = dst_buffer_list[0];

        // try to obtain previous recorded buffer
        src_buffer_list = bufferManager.getPartialBuffersByRange(
            /* base_addr */ src,
            /* size */ count,
            /* isExclusive */ false,
            /* device_id */ getDesiredDeviceId(kind, /* isDst */ false)
        );
        
        // check whether the buffer is found
        // the founded one and only buffer should totally contains the source buffer
        if(src_buffer_list.size() == 1){
            if(src_buffer_list[0]->isInRange(src, count, /* isExclusive */ false)){
                found_src_buffer = true;
            } else {
                CUDAM_WARNING_MESSAGE(
                    "the given source buffer (%p-%p) exceeds the one and only previous-recored buffer (%p-%p), need to record a new one",
                    src, (uint8_t*)src+count,
                    src_buffer_list[0]->getAddr(), ((uint8_t*)src_buffer_list[0]->getAddr()+src_buffer_list[0]->getSize())
                );
            }
        } else {
            CUDAM_WARNING_MESSAGE(
                "%lu previous-recorded buffer contain range %p-%p, need to record a new one",
                src_buffer_list.size(), src, (uint8_t*)src + count
            );
        }

        if(!found_src_buffer){
            if(RETVAL_SUCCESS != bufferManager.recordBuffer(
                /* ptr */ nullptr,  // we don't know the origin pointer here, don't record
                /* addr */ src,
                /* size */ count,
                /* device_id */ getDesiredDeviceId(kind, false), 
                /* is_page_locked */ false,     // previous-unseen buffer, shouldn't be page-locked
                /* is_unified */ false          // previous-unseen buffer, shouldn't be unified
            )){
                CUDAM_ERROR("failed to record source buffer with address %p, after failing to find", src);
                return lretval;
            }
            src_buffer_list = bufferManager.getPartialBuffersByRange(
                /* base_addr */ src,
                /* size */ count,
                /* isExclusive */ false,
                /* device_id */ getDesiredDeviceId(kind, /* isDst */ false)
            );
            assert(src_buffer_list.size() == 1);
        }
        src_buffer = src_buffer_list[0];

        // check whether the given address ranges are totally located in the origin buffers
        if(!dst_buffer->isInRange((uint8_t*)dst+count, /* isExclusive */ false)){
            CUDAM_ERROR(
                "failed to create buffer relationship, provided dst address range (%p ~ %p) is outside of origin buffer range (%p ~ %p)",
                dst, (uint8_t*)dst+count, dst_buffer->getAddr(), (uint8_t*)(dst_buffer->getAddr())+dst_buffer->getSize()
            );
            return lretval;
        }
        if(!src_buffer->isInRange((uint8_t*)src+count, /* isExclusive */ false)){
            CUDAM_ERROR(
                "failed to create buffer relationship, provided src address range (%p ~ %p) is outside of origin buffer range (%p ~ %p)",
                src, (uint8_t*)src+count, src_buffer->getAddr(), (uint8_t*)(src_buffer->getAddr())+src_buffer->getSize()
            );
            return lretval;
        }

        // check buffer position
        auto check_pos = [&](Buffer &buffer, const void *addr, const char* desired_pos, bool condition){
            if(!condition){
                CUDAM_WARNING(
                    "buffer (%p) should be located on %s, but got %s, is this normal?",
                    addr, desired_pos, 
                    convertBufferPosToString(buffer.getDeviceId(), buffer.isPageLocked(), buffer.isUnified())
                );
            }
        };
        if(kind == cudaMemcpyHostToHost){
            check_pos(*dst_buffer, dst, "cpu", dst_buffer->getDeviceId() == BUFFER_DEVICE_ID_CPU);
            check_pos(*src_buffer, src, "cpu", src_buffer->getDeviceId() == BUFFER_DEVICE_ID_CPU);
        } else if(kind == cudaMemcpyHostToDevice){
            check_pos(*dst_buffer, dst, "gpu", dst_buffer->getDeviceId() >= 0);
            check_pos(*src_buffer, src, "cpu", src_buffer->getDeviceId() == BUFFER_DEVICE_ID_CPU);
        } else if(kind == cudaMemcpyDeviceToHost){
            check_pos(*dst_buffer, dst, "cpu", dst_buffer->getDeviceId() == BUFFER_DEVICE_ID_CPU);
            check_pos(*src_buffer, src, "gpu", src_buffer->getDeviceId() >= 0);
        } else if(kind == cudaMemcpyDeviceToDevice ){
            check_pos(*dst_buffer, dst, "gpu", dst_buffer->getDeviceId() >= 0);
            check_pos(*src_buffer, src, "gpu", src_buffer->getDeviceId() >= 0);
        } else if(kind == cudaMemcpyDefault){
            check_pos(*dst_buffer, dst, "unified", dst_buffer->getDeviceId() == BUFFER_DEVICE_ID_UNIFIED);
            check_pos(*src_buffer, src, "unified", src_buffer->getDeviceId() == BUFFER_DEVICE_ID_UNIFIED);
        }

        // record relation
        dst_buffer->addRelation(src_buffer, src, dst, count, /* isIn */ true);
        src_buffer->addRelation(dst_buffer, dst, src, count, /* isIn */ false);
    }

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


cudaError_t cudaMemcpyAsync(void * dst, void const * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream){
    cudaError_t lretval;
    Buffer *dst_buffer, *src_buffer;
    bool found_dst_buffer = false, found_src_buffer = false;
    std::vector<Buffer*> dst_buffer_list, src_buffer_list;
    uint8_t dst_desired_pos, src_desired_pos;
    cudaError_t (*lcudaMemcpyAsync) (void *, void const *, size_t, cudaMemcpyKind, cudaStream_t) = (cudaError_t (*)(void *, void const *, size_t, cudaMemcpyKind, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyAsync,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyAsync(dst, src, count, kind, stream);
    
    /* NOTE: post-interception */
    lretval = cudaStreamSynchronize(stream);
    if(lretval == cudaSuccess){
        auto getDesiredDeviceId = [&](cudaMemcpyKind kind, bool isDst) -> int16_t {
            switch (kind)
            {
            case cudaMemcpyHostToHost:
                return BUFFER_DEVICE_ID_CPU;
            
            case cudaMemcpyHostToDevice:
                return isDst ? bufferManager.getSelectedGpuDeviceId() : BUFFER_DEVICE_ID_CPU;

            case cudaMemcpyDeviceToHost:
                return isDst ? BUFFER_DEVICE_ID_CPU : bufferManager.getSelectedGpuDeviceId();

            case cudaMemcpyDeviceToDevice:
                return bufferManager.getSelectedGpuDeviceId();

            case cudaMemcpyDefault:
                return BUFFER_DEVICE_ID_UNIFIED;

            default:
                CUDAM_WARNING("unknown cudaMemcpyKind %d", kind);
                return BUFFER_DEVICE_ID_CPU;
            }
        };

        // try to obtain previous recorded buffer
        dst_buffer_list = bufferManager.getPartialBuffersByRange(
            /* base_addr */ dst, 
            /* size */ count, 
            /* isExclusive */ false,
            /* device_id */ getDesiredDeviceId(kind, /* isDst */ true)
        );
        
        // check whether the buffer is found
        // the founded one and only buffer should totally contains the given destination range
        if(dst_buffer_list.size() == 1){
            if(dst_buffer_list[0]->isInRange(dst, count, /* isExclusive */ false)){
                found_dst_buffer = true;
            } else {
                CUDAM_WARNING_MESSAGE(
                    "the given desination buffer (%p-%p) exceeds the one and only previous-recored buffer (%p-%p), need to record a new one",
                    dst, (uint8_t*)dst+count,
                    dst_buffer_list[0]->getAddr(), ((uint8_t*)dst_buffer_list[0]->getAddr()+dst_buffer_list[0]->getSize())
                );
            }
        } else {
            CUDAM_WARNING_MESSAGE(
                "%lu previous-recorded buffer contain range %p-%p, need to record a new one",
                dst_buffer_list.size(), dst, (uint8_t*)dst + count
            );
        }

        if(!found_dst_buffer){
            if(RETVAL_SUCCESS != bufferManager.recordBuffer(
                /* ptr */ nullptr,  // we don't know the origin pointer here, don't record
                /* addr */ dst,
                /* size */ count, 
                /* device_id */ getDesiredDeviceId(kind, true), 
                /* is_page_locked */ false,     // previous-unseen buffer, shouldn't be page-locked
                /* is_unified */ false          // previous-unseen buffer, shouldn't be unified
            )){
                CUDAM_ERROR("failed to record destination buffer with address %p, after failing to find", dst);
                return lretval;
            }
            dst_buffer_list = bufferManager.getPartialBuffersByRange(
                /* base_addr */ dst, 
                /* size */ count, 
                /* isExclusive */ false,
                /* device_id */ getDesiredDeviceId(kind, /* isDst */ true)
            );
            assert(dst_buffer_list.size() == 1);
        }
        dst_buffer = dst_buffer_list[0];

        // try to obtain previous recorded buffer
        src_buffer_list = bufferManager.getPartialBuffersByRange(
            /* base_addr */ src, 
            /* size */ count, 
            /* isExclusive */ false,
            /* device_id */ getDesiredDeviceId(kind, /* isDst */ false)
        );
        
        // check whether the buffer is found
        // the founded one and only buffer should totally contains the source buffer
        if(src_buffer_list.size() == 1){
            if(src_buffer_list[0]->isInRange(src, count, /* isExclusive */ false)){
                found_src_buffer = true;
            } else {
                CUDAM_WARNING_MESSAGE(
                    "the given source buffer (%p-%p) exceeds the one and only previous-recored buffer (%p-%p), need to record a new one",
                    src, (uint8_t*)src+count,
                    src_buffer_list[0]->getAddr(), ((uint8_t*)src_buffer_list[0]->getAddr()+src_buffer_list[0]->getSize())
                );
            }
        } else {
            CUDAM_WARNING_MESSAGE(
                "%lu previous-recorded buffer contain range %p-%p, need to record a new one",
                src_buffer_list.size(), src, (uint8_t*)src + count
            );
        }

        if(!found_src_buffer){
            if(RETVAL_SUCCESS != bufferManager.recordBuffer(
                /* ptr */ nullptr,  // we don't know the origin pointer here, don't record
                /* addr */ src,
                /* size */ count,
                /* device_id */ getDesiredDeviceId(kind, false), 
                /* is_page_locked */ false,     // previous-unseen buffer, shouldn't be page-locked
                /* is_unified */ false          // previous-unseen buffer, shouldn't be unified
            )){
                CUDAM_ERROR("failed to record source buffer with address %p, after failing to find", src);
                return lretval;
            }
            src_buffer_list = bufferManager.getPartialBuffersByRange(
                /* base_addr */ src, 
                /* size */ count, 
                /* isExclusive */ false,
                /* device_id */ getDesiredDeviceId(kind, /* isDst */ false)
            );
            assert(src_buffer_list.size() == 1);
        }
        src_buffer = src_buffer_list[0];

        // check whether the given address ranges are totally located in the origin buffers
        if(!dst_buffer->isInRange((uint8_t*)dst+count, /* isExclusive */ false)){
            CUDAM_ERROR(
                "failed to create buffer relationship, provided dst address range (%p ~ %p) is outside of origin buffer range (%p ~ %p)",
                dst, (uint8_t*)dst+count, dst_buffer->getAddr(), (uint8_t*)(dst_buffer->getAddr())+dst_buffer->getSize()
            );
            return lretval;
        }
        if(!src_buffer->isInRange((uint8_t*)src+count, /* isExclusive */ false)){
            CUDAM_ERROR(
                "failed to create buffer relationship, provided src address range (%p ~ %p) is outside of origin buffer range (%p ~ %p)",
                src, (uint8_t*)src+count, src_buffer->getAddr(), (uint8_t*)(src_buffer->getAddr())+src_buffer->getSize()
            );
            return lretval;
        }

        // check buffer position
        auto check_pos = [&](Buffer &buffer, const void *addr, const char* desired_pos, bool condition){
            if(!condition){
                CUDAM_WARNING(
                    "buffer (%p) should be located on %s, but got %s, is this normal?",
                    addr, desired_pos, 
                    convertBufferPosToString(buffer.getDeviceId(), buffer.isPageLocked(), buffer.isUnified())
                );
            }
        };
        if(kind == cudaMemcpyHostToHost){
            check_pos(*dst_buffer, dst, "cpu", dst_buffer->getDeviceId() == BUFFER_DEVICE_ID_CPU);
            check_pos(*src_buffer, src, "cpu", src_buffer->getDeviceId() == BUFFER_DEVICE_ID_CPU);
        } else if(kind == cudaMemcpyHostToDevice){
            check_pos(*dst_buffer, dst, "gpu", dst_buffer->getDeviceId() >= 0);
            check_pos(*src_buffer, src, "cpu", src_buffer->getDeviceId() == BUFFER_DEVICE_ID_CPU);
        } else if(kind == cudaMemcpyDeviceToHost){
            check_pos(*dst_buffer, dst, "cpu", dst_buffer->getDeviceId() == BUFFER_DEVICE_ID_CPU);
            check_pos(*src_buffer, src, "gpu", src_buffer->getDeviceId() >= 0);
        } else if(kind == cudaMemcpyDeviceToDevice ){
            check_pos(*dst_buffer, dst, "gpu", dst_buffer->getDeviceId() >= 0);
            check_pos(*src_buffer, src, "gpu", src_buffer->getDeviceId() >= 0);
        } else if(kind == cudaMemcpyDefault){
            check_pos(*dst_buffer, dst, "unified", dst_buffer->getDeviceId() == BUFFER_DEVICE_ID_UNIFIED);
            check_pos(*src_buffer, src, "unified", src_buffer->getDeviceId() == BUFFER_DEVICE_ID_UNIFIED);
        }

        // record relation
        dst_buffer->addRelation(src_buffer, src, dst, count, /* isIn */ true);
        src_buffer->addRelation(dst_buffer, dst, src, count, /* isIn */ false);
    } else {
        CUDAM_ERROR("failed to sychronize cudaMemcpyAsync, something is wrong?");
    }

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


cudaError_t cudaMemcpyPeer(void * dst, int dstDevice, void const * src, int srcDevice, size_t count){
    cudaError_t lretval;
    Buffer *dst_buffer, *src_buffer;
    bool found_dst_buffer = false, found_src_buffer = false;
    std::vector<Buffer*> dst_buffer_list, src_buffer_list;
    uint8_t dst_desired_pos, src_desired_pos;
    cudaError_t (*lcudaMemcpyPeer) (void *, int, void const *, int, size_t) = (cudaError_t (*)(void *, int, void const *, int, size_t))dlsym(RTLD_NEXT, "cudaMemcpyPeer");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyPeer",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyPeer,
        /* is_intercepted */ true
    );
    
    /* NOTE: pre-interception */

    lretval = lcudaMemcpyPeer(dst, dstDevice, src, srcDevice, count);
    
    /* NOTE: post-interception */
    if(lretval == cudaSuccess){
        // try to obtain previous recorded buffer
        dst_buffer_list = bufferManager.getPartialBuffersByRange(
            /* base_addr */ dst, 
            /* size */ count, 
            /* isExclusive */ false,
            /* device_id */ dstDevice
        );
        
        // check whether the buffer is found
        // the founded one and only buffer should totally contains the given destination range
        if(dst_buffer_list.size() == 1){
            if(dst_buffer_list[0]->isInRange(dst, count, /* isExclusive */ false)){
                found_dst_buffer = true;
            } else {
                CUDAM_WARNING_MESSAGE(
                    "the given desination buffer (%p-%p) exceeds the one and only previous-recored buffer (%p-%p), need to record a new one",
                    dst, (uint8_t*)dst+count,
                    dst_buffer_list[0]->getAddr(), ((uint8_t*)dst_buffer_list[0]->getAddr()+dst_buffer_list[0]->getSize())
                );
            }
        } else {
            CUDAM_WARNING_MESSAGE(
                "%lu previous-recorded buffer contain range %p-%p, need to record a new one",
                dst_buffer_list.size(), dst, (uint8_t*)dst + count
            );
        }

        if(!found_dst_buffer){
            if(RETVAL_SUCCESS != bufferManager.recordBuffer(
                /* ptr */ nullptr,  // we don't know the origin pointer here, don't record
                /* addr */ dst,
                /* size */ count, 
                /* device_id */ dstDevice, 
                /* is_page_locked */ false,     // previous-unseen buffer, shouldn't be page-locked
                /* is_unified */ false          // previous-unseen buffer, shouldn't be unified
            )){
                CUDAM_ERROR("failed to record destination buffer with address %p, after failing to find", dst);
                return lretval;
            }
            dst_buffer_list = bufferManager.getPartialBuffersByRange(
                /* base_addr */ dst, 
                /* size */ count, 
                /* isExclusive */ false,
                /* device_id */ dstDevice
            );
            assert(dst_buffer_list.size() == 1);
        }
        dst_buffer = dst_buffer_list[0];

        // try to obtain previous recorded buffer
        src_buffer_list = bufferManager.getPartialBuffersByRange(
            /* base_addr */ src, 
            /* size */ count, 
            /* isExclusive */ false,
            /* device_id */ srcDevice
        );
        
        // check whether the buffer is found
        // the founded one and only buffer should totally contains the source buffer
        if(src_buffer_list.size() == 1){
            if(src_buffer_list[0]->isInRange(src, count, /* isExclusive */ false)){
                found_src_buffer = true;
            } else {
                CUDAM_WARNING_MESSAGE(
                    "the given source buffer (%p-%p) exceeds the one and only previous-recored buffer (%p-%p), need to record a new one",
                    src, (uint8_t*)src+count,
                    src_buffer_list[0]->getAddr(), ((uint8_t*)src_buffer_list[0]->getAddr()+src_buffer_list[0]->getSize())
                );
            }
        } else {
            CUDAM_WARNING_MESSAGE(
                "%lu previous-recorded buffer contain range %p-%p, need to record a new one",
                src_buffer_list.size(), src, (uint8_t*)src + count
            );
        }

        if(!found_src_buffer){
            if(RETVAL_SUCCESS != bufferManager.recordBuffer(
                /* ptr */ nullptr,  // we don't know the origin pointer here, don't record
                /* addr */ src,
                /* size */ count,
                /* device_id */ srcDevice, 
                /* is_page_locked */ false,     // previous-unseen buffer, shouldn't be page-locked
                /* is_unified */ false          // previous-unseen buffer, shouldn't be unified
            )){
                CUDAM_ERROR("failed to record source buffer with address %p, after failing to find", src);
                return lretval;
            }
            src_buffer_list = bufferManager.getPartialBuffersByRange(
                /* base_addr */ src, 
                /* size */ count, 
                /* isExclusive */ false,
                /* device_id */ srcDevice
            );
            assert(src_buffer_list.size() == 1);
        }
        src_buffer = src_buffer_list[0];

        // check whether the given address ranges are totally located in the origin buffers
        if(!dst_buffer->isInRange((uint8_t*)dst+count, /* isExclusive */ false)){
            CUDAM_ERROR(
                "failed to create buffer relationship, provided dst address range (%p ~ %p) is outside of origin buffer range (%p ~ %p)",
                dst, (uint8_t*)dst+count, dst_buffer->getAddr(), (uint8_t*)(dst_buffer->getAddr())+dst_buffer->getSize()
            );
            return lretval;
        }
        if(!src_buffer->isInRange((uint8_t*)src+count, /* isExclusive */ false)){
            CUDAM_ERROR(
                "failed to create buffer relationship, provided src address range (%p ~ %p) is outside of origin buffer range (%p ~ %p)",
                src, (uint8_t*)src+count, src_buffer->getAddr(), (uint8_t*)(src_buffer->getAddr())+src_buffer->getSize()
            );
            return lretval;
        }

        // check buffer position
        if(dst_buffer->getDeviceId() != dstDevice){
            CUDAM_WARNING("given destination buffer indicates %d, but the buffer's device id is %d", dstDevice, dst_buffer->getDeviceId());
        }
        if(src_buffer->getDeviceId() != srcDevice){
            CUDAM_WARNING("given source buffer indicates %d, but the buffer's device id is %d", srcDevice, src_buffer->getDeviceId());
        }

        // record relation
        dst_buffer->addRelation(src_buffer, src, dst, count, /* isIn */ true);
        src_buffer->addRelation(dst_buffer, dst, src, count, /* isIn */ false);
    }

    return lretval;
}


cudaError_t cudaMemcpyPeerAsync(void * dst, int dstDevice, void const * src, int srcDevice, size_t count, cudaStream_t stream){
    cudaError_t lretval;
    Buffer *dst_buffer, *src_buffer;
    bool found_dst_buffer = false, found_src_buffer = false;
    std::vector<Buffer*> dst_buffer_list, src_buffer_list;
    uint8_t dst_desired_pos, src_desired_pos;
    cudaError_t (*lcudaMemcpyPeerAsync) (void *, int, void const *, int, size_t, cudaStream_t) = (cudaError_t (*)(void *, int, void const *, int, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemcpyPeerAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemcpyPeerAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemcpyPeerAsync,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemcpyPeerAsync(dst, dstDevice, src, srcDevice, count, stream);
    
    /* NOTE: post-interception */
    lretval = cudaStreamSynchronize(stream);
    if(lretval == cudaSuccess){
        // try to obtain previous recorded buffer
        dst_buffer_list = bufferManager.getPartialBuffersByRange(
            /* base_addr */ dst, 
            /* size */ count, 
            /* isExclusive */ false,
            /* device_id */ dstDevice
        );
        
        // check whether the buffer is found
        // the founded one and only buffer should totally contains the given destination range
        if(dst_buffer_list.size() == 1){
            if(dst_buffer_list[0]->isInRange(dst, count, /* isExclusive */ false)){
                found_dst_buffer = true;
            } else {
                CUDAM_WARNING_MESSAGE(
                    "the given desination buffer (%p-%p) exceeds the one and only previous-recored buffer (%p-%p), need to record a new one",
                    dst, (uint8_t*)dst+count,
                    dst_buffer_list[0]->getAddr(), ((uint8_t*)dst_buffer_list[0]->getAddr()+dst_buffer_list[0]->getSize())
                );
            }
        } else {
            CUDAM_WARNING_MESSAGE(
                "%lu previous-recorded buffer contain range %p-%p, need to record a new one",
                dst_buffer_list.size(), dst, (uint8_t*)dst + count
            );
        }

        if(!found_dst_buffer){
            if(RETVAL_SUCCESS != bufferManager.recordBuffer(
                /* ptr */ nullptr,  // we don't know the origin pointer here, don't record
                /* addr */ dst,
                /* size */ count, 
                /* device_id */ dstDevice, 
                /* is_page_locked */ false,     // previous-unseen buffer, shouldn't be page-locked
                /* is_unified */ false          // previous-unseen buffer, shouldn't be unified
            )){
                CUDAM_ERROR("failed to record destination buffer with address %p, after failing to find", dst);
                return lretval;
            }
            dst_buffer_list = bufferManager.getPartialBuffersByRange(
                /* base_addr */ dst, 
                /* size */ count, 
                /* isExclusive */ false,
                /* device_id */ dstDevice
            );
            assert(dst_buffer_list.size() == 1);
        }
        dst_buffer = dst_buffer_list[0];

        // try to obtain previous recorded buffer
        src_buffer_list = bufferManager.getPartialBuffersByRange(
            /* base_addr */ src, 
            /* size */ count, 
            /* isExclusive */ false,
            /* device_id */ srcDevice
        );
        
        // check whether the buffer is found
        // the founded one and only buffer should totally contains the source buffer
        if(src_buffer_list.size() == 1){
            if(src_buffer_list[0]->isInRange(src, count, /* isExclusive */ false)){
                found_src_buffer = true;
            } else {
                CUDAM_WARNING_MESSAGE(
                    "the given source buffer (%p-%p) exceeds the one and only previous-recored buffer (%p-%p), need to record a new one",
                    src, (uint8_t*)src+count,
                    src_buffer_list[0]->getAddr(), ((uint8_t*)src_buffer_list[0]->getAddr()+src_buffer_list[0]->getSize())
                );
            }
        } else {
            CUDAM_WARNING_MESSAGE(
                "%lu previous-recorded buffer contain range %p-%p, need to record a new one",
                src_buffer_list.size(), src, (uint8_t*)src + count
            );
        }

        if(!found_src_buffer){
            if(RETVAL_SUCCESS != bufferManager.recordBuffer(
                /* ptr */ nullptr,  // we don't know the origin pointer here, don't record
                /* addr */ src,
                /* size */ count,
                /* device_id */ srcDevice, 
                /* is_page_locked */ false,     // previous-unseen buffer, shouldn't be page-locked
                /* is_unified */ false          // previous-unseen buffer, shouldn't be unified
            )){
                CUDAM_ERROR("failed to record source buffer with address %p, after failing to find", src);
                return lretval;
            }
            src_buffer_list = bufferManager.getPartialBuffersByRange(
                /* base_addr */ src, 
                /* size */ count, 
                /* isExclusive */ false,
                /* device_id */ srcDevice
            );
            assert(src_buffer_list.size() == 1);
        }
        src_buffer = src_buffer_list[0];

        // check whether the given address ranges are totally located in the origin buffers
        if(!dst_buffer->isInRange((uint8_t*)dst+count, /* isExclusive */ false)){
            CUDAM_ERROR(
                "failed to create buffer relationship, provided dst address range (%p ~ %p) is outside of origin buffer range (%p ~ %p)",
                dst, (uint8_t*)dst+count, dst_buffer->getAddr(), (uint8_t*)(dst_buffer->getAddr())+dst_buffer->getSize()
            );
            return lretval;
        }
        if(!src_buffer->isInRange((uint8_t*)src+count, /* isExclusive */ false)){
            CUDAM_ERROR(
                "failed to create buffer relationship, provided src address range (%p ~ %p) is outside of origin buffer range (%p ~ %p)",
                src, (uint8_t*)src+count, src_buffer->getAddr(), (uint8_t*)(src_buffer->getAddr())+src_buffer->getSize()
            );
            return lretval;
        }

        // check buffer position
        if(dst_buffer->getDeviceId() != dstDevice){
            CUDAM_WARNING("given destination buffer indicates %d, but the buffer's device id is %d", dstDevice, dst_buffer->getDeviceId());
        }
        if(src_buffer->getDeviceId() != srcDevice){
            CUDAM_WARNING("given source buffer indicates %d, but the buffer's device id is %d", srcDevice, src_buffer->getDeviceId());
        }

        // record relation
        dst_buffer->addRelation(src_buffer, src, dst, count, /* isIn */ true);
        src_buffer->addRelation(dst_buffer, dst, src, count, /* isIn */ false);
    } else {
        CUDAM_ERROR("failed to sychronize cudaMemcpyPeerAsync, something is wrong?");
    }

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


cudaError_t cudaMemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream){
    cudaError_t lretval;
    cudaError_t (*lcudaMemsetAsync) (void *, int, size_t, cudaStream_t) = (cudaError_t (*)(void *, int, size_t, cudaStream_t))dlsym(RTLD_NEXT, "cudaMemsetAsync");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMemsetAsync",
        /* api_index */ CUDA_MEMORY_API_cudaMemsetAsync,
        /* is_intercepted */ true
    );

    /* NOTE: pre-interception */

    lretval = lcudaMemsetAsync(devPtr, value, count, stream);
    
    /* NOTE: post-interception */

    return lretval;
}


cudaError_t cudaMipmappedArrayGetMemoryRequirements(cudaArrayMemoryRequirements * memoryRequirements, cudaMipmappedArray_t mipmap, int device){
    cudaError_t lretval;
    cudaError_t (*lcudaMipmappedArrayGetMemoryRequirements) (cudaArrayMemoryRequirements *, cudaMipmappedArray_t, int) = (cudaError_t (*)(cudaArrayMemoryRequirements *, cudaMipmappedArray_t, int))dlsym(RTLD_NEXT, "cudaMipmappedArrayGetMemoryRequirements");

    START_MEMORY_PROFILING(
        /* api_name */ "cudaMipmappedArrayGetMemoryRequirements",
        /* api_index */ CUDA_MEMORY_API_cudaMipmappedArrayGetMemoryRequirements,
        /* is_intercepted */ false
    );

    /* NOTE: pre-interception */

    lretval = lcudaMipmappedArrayGetMemoryRequirements(memoryRequirements, mipmap, device);
    
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
