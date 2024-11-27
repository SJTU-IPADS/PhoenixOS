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

#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

cudaError_t cudaArrayGetInfo ( cudaChannelFormatDesc* desc, cudaExtent* extent, unsigned int* flags, cudaArray_t array );
cudaError_t cudaArrayGetMemoryRequirements ( cudaArrayMemoryRequirements* memoryRequirements, cudaArray_t array, int  device );
cudaError_t cudaArrayGetPlane ( cudaArray_t* pPlaneArray, cudaArray_t hArray, unsigned int  planeIdx );
cudaError_t cudaArrayGetSparseProperties ( cudaArraySparseProperties* sparseProperties, cudaArray_t array );
cudaError_t cudaFree ( void* devPtr );
cudaError_t cudaFreeArray ( cudaArray_t array );
cudaError_t cudaFreeHost ( void* ptr );
cudaError_t cudaFreeMipmappedArray ( cudaMipmappedArray_t mipmappedArray );
cudaError_t cudaGetMipmappedArrayLevel ( cudaArray_t* levelArray, cudaMipmappedArray_const_t mipmappedArray, unsigned int  level );
cudaError_t cudaGetSymbolAddress ( void** devPtr, const void* symbol );
cudaError_t cudaGetSymbolSize ( size_t* size, const void* symbol );
cudaError_t cudaHostAlloc ( void** pHost, size_t size, unsigned int  flags );
cudaError_t cudaHostGetDevicePointer ( void** pDevice, void* pHost, unsigned int  flags );
cudaError_t cudaHostGetFlags ( unsigned int* pFlags, void* pHost );
cudaError_t cudaHostRegister ( void* ptr, size_t size, unsigned int  flags );
cudaError_t cudaHostUnregister ( void* ptr );
cudaError_t cudaMalloc ( void** devPtr, size_t size );
cudaError_t cudaMalloc3D ( cudaPitchedPtr* pitchedDevPtr, cudaExtent extent );
cudaError_t cudaMalloc3DArray ( cudaArray_t* array, const cudaChannelFormatDesc* desc, cudaExtent extent, unsigned int  flags = 0 );
cudaError_t cudaMallocArray ( cudaArray_t* array, const cudaChannelFormatDesc* desc, size_t width, size_t height = 0, unsigned int  flags = 0 );
cudaError_t cudaMallocHost ( void** ptr, size_t size );
cudaError_t cudaMallocManaged ( void** devPtr, size_t size, unsigned int  flags = cudaMemAttachGlobal );
cudaError_t cudaMallocMipmappedArray ( cudaMipmappedArray_t* mipmappedArray, const cudaChannelFormatDesc* desc, cudaExtent extent, unsigned int  numLevels, unsigned int  flags = 0 );
cudaError_t cudaMallocPitch ( void** devPtr, size_t* pitch, size_t width, size_t height );
cudaError_t cudaMemAdvise ( const void* devPtr, size_t count, cudaMemoryAdvise advice, int  device );
cudaError_t cudaMemGetInfo ( size_t* free, size_t* total );
cudaError_t cudaMemPrefetchAsync ( const void* devPtr, size_t count, int  dstDevice, cudaStream_t stream = 0 );
cudaError_t cudaMemRangeGetAttribute ( void* data, size_t dataSize, cudaMemRangeAttribute attribute, const void* devPtr, size_t count );
cudaError_t cudaMemRangeGetAttributes ( void** data, size_t* dataSizes, cudaMemRangeAttribute ** attributes, size_t numAttributes, const void* devPtr, size_t count );
cudaError_t cudaMemcpy ( void* dst, const void* src, size_t count, cudaMemcpyKind kind );
cudaError_t cudaMemcpy2D ( void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind );
cudaError_t cudaMemcpy2DArrayToArray ( cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice );
cudaError_t cudaMemcpy2DAsync ( void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0 );
cudaError_t cudaMemcpy2DFromArray ( void* dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind );
cudaError_t cudaMemcpy2DToArray ( cudaArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind );
cudaError_t cudaMemcpy2DToArrayAsync ( cudaArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0 );
cudaError_t cudaMemcpy3D ( const cudaMemcpy3DParms* p );
cudaError_t cudaMemcpy3DAsync ( const cudaMemcpy3DParms* p, cudaStream_t stream = 0 );
cudaError_t cudaMemcpy3DPeer ( const cudaMemcpy3DPeerParms* p );
cudaError_t cudaMemcpy3DPeerAsync ( const cudaMemcpy3DPeerParms* p, cudaStream_t stream = 0 );
cudaError_t cudaMemcpyAsync ( void* dst, const void* src, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0 );
cudaError_t cudaMemcpyFromSymbol ( void* dst, const void* symbol, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyDeviceToHost );
cudaError_t cudaMemcpyFromSymbolAsync ( void* dst, const void* symbol, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0 );
cudaError_t cudaMemcpyPeer ( void* dst, int  dstDevice, const void* src, int  srcDevice, size_t count );
cudaError_t cudaMemcpyPeerAsync ( void* dst, int  dstDevice, const void* src, int  srcDevice, size_t count, cudaStream_t stream = 0 );
cudaError_t cudaMemcpyToSymbol ( const void* symbol, const void* src, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyHostToDevice );
cudaError_t cudaMemcpyToSymbolAsync ( const void* symbol, const void* src, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0 );
cudaError_t cudaMemset ( void* devPtr, int  value, size_t count );
cudaError_t cudaMemset2D ( void* devPtr, size_t pitch, int  value, size_t width, size_t height );
cudaError_t cudaMemset2DAsync ( void* devPtr, size_t pitch, int  value, size_t width, size_t height, cudaStream_t stream = 0 );
cudaError_t cudaMemset3D ( cudaPitchedPtr pitchedDevPtr, int  value, cudaExtent extent );
cudaError_t cudaMemset3DAsync ( cudaPitchedPtr pitchedDevPtr, int  value, cudaExtent extent, cudaStream_t stream = 0 );
cudaError_t cudaMemsetAsync ( void* devPtr, int  value, size_t count, cudaStream_t stream = 0 );
cudaError_t cudaMipmappedArrayGetMemoryRequirements ( cudaArrayMemoryRequirements* memoryRequirements, cudaMipmappedArray_t mipmap, int  device );
cudaError_t cudaMipmappedArrayGetSparseProperties ( cudaArraySparseProperties* sparseProperties, cudaMipmappedArray_t mipmap );
