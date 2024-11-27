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
#include <dlfcn.h>
#include <cudnn.h>

#include "cudam.h"
#include "api_counter.h"

#undef cudaCreateChannelDesc
cudaChannelFormatDesc cudaCreateChannelDesc(){
    cudaChannelFormatDesc lretval;
    cudaChannelFormatDesc (*lcudaCreateChannelDesc) () = (cudaChannelFormatDesc (*)())dlsym(RTLD_NEXT, "cudaCreateChannelDesc");
    
    /* pre exeuction logics */
    ac.add_counter("cudaCreateChannelDesc", kApiTypeCuDNN);

    lretval = lcudaCreateChannelDesc();
    
    /* post exeuction logics */

    return lretval;
}
#define cudaCreateChannelDesc cudaCreateChannelDesc


#undef cudnnGetVersion
size_t cudnnGetVersion(){
    size_t lretval;
    size_t (*lcudnnGetVersion) () = (size_t (*)())dlsym(RTLD_NEXT, "cudnnGetVersion");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetVersion", kApiTypeCuDNN);

    lretval = lcudnnGetVersion();
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetVersion cudnnGetVersion


#undef cudnnGetCudartVersion
size_t cudnnGetCudartVersion(){
    size_t lretval;
    size_t (*lcudnnGetCudartVersion) () = (size_t (*)())dlsym(RTLD_NEXT, "cudnnGetCudartVersion");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetCudartVersion", kApiTypeCuDNN);

    lretval = lcudnnGetCudartVersion();
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetCudartVersion cudnnGetCudartVersion


#undef cudnnGetErrorString
char const * cudnnGetErrorString(cudnnStatus_t status){
    char const * lretval;
    char const * (*lcudnnGetErrorString) (cudnnStatus_t) = (char const * (*)(cudnnStatus_t))dlsym(RTLD_NEXT, "cudnnGetErrorString");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetErrorString", kApiTypeCuDNN);

    lretval = lcudnnGetErrorString(status);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetErrorString cudnnGetErrorString


#undef cudnnQueryRuntimeError
cudnnStatus_t cudnnQueryRuntimeError(cudnnHandle_t handle, cudnnStatus_t * rstatus, cudnnErrQueryMode_t mode, cudnnRuntimeTag_t * tag){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnQueryRuntimeError) (cudnnHandle_t, cudnnStatus_t *, cudnnErrQueryMode_t, cudnnRuntimeTag_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnStatus_t *, cudnnErrQueryMode_t, cudnnRuntimeTag_t *))dlsym(RTLD_NEXT, "cudnnQueryRuntimeError");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnQueryRuntimeError", kApiTypeCuDNN);

    lretval = lcudnnQueryRuntimeError(handle, rstatus, mode, tag);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnQueryRuntimeError cudnnQueryRuntimeError


#undef cudnnGetProperty
cudnnStatus_t cudnnGetProperty(libraryPropertyType type, int * value){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetProperty) (libraryPropertyType, int *) = (cudnnStatus_t (*)(libraryPropertyType, int *))dlsym(RTLD_NEXT, "cudnnGetProperty");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetProperty", kApiTypeCuDNN);

    lretval = lcudnnGetProperty(type, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetProperty cudnnGetProperty


#undef cudnnCreate
cudnnStatus_t cudnnCreate(cudnnHandle_t * handle){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreate) (cudnnHandle_t *) = (cudnnStatus_t (*)(cudnnHandle_t *))dlsym(RTLD_NEXT, "cudnnCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreate", kApiTypeCuDNN);

    lretval = lcudnnCreate(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreate cudnnCreate


#undef cudnnDestroy
cudnnStatus_t cudnnDestroy(cudnnHandle_t handle){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroy) (cudnnHandle_t) = (cudnnStatus_t (*)(cudnnHandle_t))dlsym(RTLD_NEXT, "cudnnDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroy", kApiTypeCuDNN);

    lretval = lcudnnDestroy(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroy cudnnDestroy


#undef cudnnSetStream
cudnnStatus_t cudnnSetStream(cudnnHandle_t handle, cudaStream_t streamId){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetStream) (cudnnHandle_t, cudaStream_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudaStream_t))dlsym(RTLD_NEXT, "cudnnSetStream");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetStream", kApiTypeCuDNN);

    lretval = lcudnnSetStream(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetStream cudnnSetStream


#undef cudnnGetStream
cudnnStatus_t cudnnGetStream(cudnnHandle_t handle, cudaStream_t * streamId){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetStream) (cudnnHandle_t, cudaStream_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudaStream_t *))dlsym(RTLD_NEXT, "cudnnGetStream");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetStream", kApiTypeCuDNN);

    lretval = lcudnnGetStream(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetStream cudnnGetStream


#undef cudnnCreateTensorDescriptor
cudnnStatus_t cudnnCreateTensorDescriptor(cudnnTensorDescriptor_t * tensorDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateTensorDescriptor) (cudnnTensorDescriptor_t *) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateTensorDescriptor(tensorDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateTensorDescriptor cudnnCreateTensorDescriptor


#undef cudnnSetTensor4dDescriptor
cudnnStatus_t cudnnSetTensor4dDescriptor(cudnnTensorDescriptor_t tensorDesc, cudnnTensorFormat_t format, cudnnDataType_t dataType, int n, int c, int h, int w){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetTensor4dDescriptor) (cudnnTensorDescriptor_t, cudnnTensorFormat_t, cudnnDataType_t, int, int, int, int) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t, cudnnTensorFormat_t, cudnnDataType_t, int, int, int, int))dlsym(RTLD_NEXT, "cudnnSetTensor4dDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetTensor4dDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetTensor4dDescriptor(tensorDesc, format, dataType, n, c, h, w);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetTensor4dDescriptor cudnnSetTensor4dDescriptor


#undef cudnnSetTensor4dDescriptorEx
cudnnStatus_t cudnnSetTensor4dDescriptorEx(cudnnTensorDescriptor_t tensorDesc, cudnnDataType_t dataType, int n, int c, int h, int w, int nStride, int cStride, int hStride, int wStride){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetTensor4dDescriptorEx) (cudnnTensorDescriptor_t, cudnnDataType_t, int, int, int, int, int, int, int, int) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t, cudnnDataType_t, int, int, int, int, int, int, int, int))dlsym(RTLD_NEXT, "cudnnSetTensor4dDescriptorEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetTensor4dDescriptorEx", kApiTypeCuDNN);

    lretval = lcudnnSetTensor4dDescriptorEx(tensorDesc, dataType, n, c, h, w, nStride, cStride, hStride, wStride);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetTensor4dDescriptorEx cudnnSetTensor4dDescriptorEx


#undef cudnnGetTensor4dDescriptor
cudnnStatus_t cudnnGetTensor4dDescriptor(cudnnTensorDescriptor_t const tensorDesc, cudnnDataType_t * dataType, int * n, int * c, int * h, int * w, int * nStride, int * cStride, int * hStride, int * wStride){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetTensor4dDescriptor) (cudnnTensorDescriptor_t const, cudnnDataType_t *, int *, int *, int *, int *, int *, int *, int *, int *) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t const, cudnnDataType_t *, int *, int *, int *, int *, int *, int *, int *, int *))dlsym(RTLD_NEXT, "cudnnGetTensor4dDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetTensor4dDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetTensor4dDescriptor(tensorDesc, dataType, n, c, h, w, nStride, cStride, hStride, wStride);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetTensor4dDescriptor cudnnGetTensor4dDescriptor


#undef cudnnSetTensorNdDescriptor
cudnnStatus_t cudnnSetTensorNdDescriptor(cudnnTensorDescriptor_t tensorDesc, cudnnDataType_t dataType, int nbDims, int const * dimA, int const * strideA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetTensorNdDescriptor) (cudnnTensorDescriptor_t, cudnnDataType_t, int, int const *, int const *) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t, cudnnDataType_t, int, int const *, int const *))dlsym(RTLD_NEXT, "cudnnSetTensorNdDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetTensorNdDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetTensorNdDescriptor(tensorDesc, dataType, nbDims, dimA, strideA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetTensorNdDescriptor cudnnSetTensorNdDescriptor


#undef cudnnSetTensorNdDescriptorEx
cudnnStatus_t cudnnSetTensorNdDescriptorEx(cudnnTensorDescriptor_t tensorDesc, cudnnTensorFormat_t format, cudnnDataType_t dataType, int nbDims, int const * dimA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetTensorNdDescriptorEx) (cudnnTensorDescriptor_t, cudnnTensorFormat_t, cudnnDataType_t, int, int const *) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t, cudnnTensorFormat_t, cudnnDataType_t, int, int const *))dlsym(RTLD_NEXT, "cudnnSetTensorNdDescriptorEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetTensorNdDescriptorEx", kApiTypeCuDNN);

    lretval = lcudnnSetTensorNdDescriptorEx(tensorDesc, format, dataType, nbDims, dimA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetTensorNdDescriptorEx cudnnSetTensorNdDescriptorEx


#undef cudnnGetTensorNdDescriptor
cudnnStatus_t cudnnGetTensorNdDescriptor(cudnnTensorDescriptor_t const tensorDesc, int nbDimsRequested, cudnnDataType_t * dataType, int * nbDims, int * dimA, int * strideA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetTensorNdDescriptor) (cudnnTensorDescriptor_t const, int, cudnnDataType_t *, int *, int *, int *) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t const, int, cudnnDataType_t *, int *, int *, int *))dlsym(RTLD_NEXT, "cudnnGetTensorNdDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetTensorNdDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetTensorNdDescriptor(tensorDesc, nbDimsRequested, dataType, nbDims, dimA, strideA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetTensorNdDescriptor cudnnGetTensorNdDescriptor


#undef cudnnGetTensorSizeInBytes
cudnnStatus_t cudnnGetTensorSizeInBytes(cudnnTensorDescriptor_t const tensorDesc, size_t * size){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetTensorSizeInBytes) (cudnnTensorDescriptor_t const, size_t *) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t const, size_t *))dlsym(RTLD_NEXT, "cudnnGetTensorSizeInBytes");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetTensorSizeInBytes", kApiTypeCuDNN);

    lretval = lcudnnGetTensorSizeInBytes(tensorDesc, size);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetTensorSizeInBytes cudnnGetTensorSizeInBytes


#undef cudnnDestroyTensorDescriptor
cudnnStatus_t cudnnDestroyTensorDescriptor(cudnnTensorDescriptor_t tensorDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyTensorDescriptor) (cudnnTensorDescriptor_t) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyTensorDescriptor(tensorDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyTensorDescriptor cudnnDestroyTensorDescriptor


#undef cudnnInitTransformDest
cudnnStatus_t cudnnInitTransformDest(cudnnTensorTransformDescriptor_t const transformDesc, cudnnTensorDescriptor_t const srcDesc, cudnnTensorDescriptor_t destDesc, size_t * destSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnInitTransformDest) (cudnnTensorTransformDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t, size_t *) = (cudnnStatus_t (*)(cudnnTensorTransformDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t, size_t *))dlsym(RTLD_NEXT, "cudnnInitTransformDest");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnInitTransformDest", kApiTypeCuDNN);

    lretval = lcudnnInitTransformDest(transformDesc, srcDesc, destDesc, destSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnInitTransformDest cudnnInitTransformDest


#undef cudnnCreateTensorTransformDescriptor
cudnnStatus_t cudnnCreateTensorTransformDescriptor(cudnnTensorTransformDescriptor_t * transformDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateTensorTransformDescriptor) (cudnnTensorTransformDescriptor_t *) = (cudnnStatus_t (*)(cudnnTensorTransformDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateTensorTransformDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateTensorTransformDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateTensorTransformDescriptor(transformDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateTensorTransformDescriptor cudnnCreateTensorTransformDescriptor


#undef cudnnSetTensorTransformDescriptor
cudnnStatus_t cudnnSetTensorTransformDescriptor(cudnnTensorTransformDescriptor_t transformDesc, uint32_t const nbDims, cudnnTensorFormat_t const destFormat, int32_t const * padBeforeA, int32_t const * padAfterA, uint32_t const * foldA, cudnnFoldingDirection_t const direction){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetTensorTransformDescriptor) (cudnnTensorTransformDescriptor_t, uint32_t const, cudnnTensorFormat_t const, int32_t const *, int32_t const *, uint32_t const *, cudnnFoldingDirection_t const) = (cudnnStatus_t (*)(cudnnTensorTransformDescriptor_t, uint32_t const, cudnnTensorFormat_t const, int32_t const *, int32_t const *, uint32_t const *, cudnnFoldingDirection_t const))dlsym(RTLD_NEXT, "cudnnSetTensorTransformDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetTensorTransformDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetTensorTransformDescriptor(transformDesc, nbDims, destFormat, padBeforeA, padAfterA, foldA, direction);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetTensorTransformDescriptor cudnnSetTensorTransformDescriptor


#undef cudnnGetTensorTransformDescriptor
cudnnStatus_t cudnnGetTensorTransformDescriptor(cudnnTensorTransformDescriptor_t transformDesc, uint32_t nbDimsRequested, cudnnTensorFormat_t * destFormat, int32_t * padBeforeA, int32_t * padAfterA, uint32_t * foldA, cudnnFoldingDirection_t * direction){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetTensorTransformDescriptor) (cudnnTensorTransformDescriptor_t, uint32_t, cudnnTensorFormat_t *, int32_t *, int32_t *, uint32_t *, cudnnFoldingDirection_t *) = (cudnnStatus_t (*)(cudnnTensorTransformDescriptor_t, uint32_t, cudnnTensorFormat_t *, int32_t *, int32_t *, uint32_t *, cudnnFoldingDirection_t *))dlsym(RTLD_NEXT, "cudnnGetTensorTransformDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetTensorTransformDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetTensorTransformDescriptor(transformDesc, nbDimsRequested, destFormat, padBeforeA, padAfterA, foldA, direction);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetTensorTransformDescriptor cudnnGetTensorTransformDescriptor


#undef cudnnDestroyTensorTransformDescriptor
cudnnStatus_t cudnnDestroyTensorTransformDescriptor(cudnnTensorTransformDescriptor_t transformDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyTensorTransformDescriptor) (cudnnTensorTransformDescriptor_t) = (cudnnStatus_t (*)(cudnnTensorTransformDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyTensorTransformDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyTensorTransformDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyTensorTransformDescriptor(transformDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyTensorTransformDescriptor cudnnDestroyTensorTransformDescriptor


#undef cudnnTransformTensor
cudnnStatus_t cudnnTransformTensor(cudnnHandle_t handle, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, void const * beta, cudnnTensorDescriptor_t const yDesc, void * y){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnTransformTensor) (cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnTransformTensor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnTransformTensor", kApiTypeCuDNN);

    lretval = lcudnnTransformTensor(handle, alpha, xDesc, x, beta, yDesc, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnTransformTensor cudnnTransformTensor


#undef cudnnTransformTensorEx
cudnnStatus_t cudnnTransformTensorEx(cudnnHandle_t handle, cudnnTensorTransformDescriptor_t const transDesc, void const * alpha, cudnnTensorDescriptor_t const srcDesc, void const * srcData, void const * beta, cudnnTensorDescriptor_t const destDesc, void * destData){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnTransformTensorEx) (cudnnHandle_t, cudnnTensorTransformDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorTransformDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnTransformTensorEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnTransformTensorEx", kApiTypeCuDNN);

    lretval = lcudnnTransformTensorEx(handle, transDesc, alpha, srcDesc, srcData, beta, destDesc, destData);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnTransformTensorEx cudnnTransformTensorEx


#undef cudnnAddTensor
cudnnStatus_t cudnnAddTensor(cudnnHandle_t handle, void const * alpha, cudnnTensorDescriptor_t const aDesc, void const * A, void const * beta, cudnnTensorDescriptor_t const cDesc, void * C){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnAddTensor) (cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnAddTensor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnAddTensor", kApiTypeCuDNN);

    lretval = lcudnnAddTensor(handle, alpha, aDesc, A, beta, cDesc, C);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnAddTensor cudnnAddTensor


#undef cudnnCreateOpTensorDescriptor
cudnnStatus_t cudnnCreateOpTensorDescriptor(cudnnOpTensorDescriptor_t * opTensorDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateOpTensorDescriptor) (cudnnOpTensorDescriptor_t *) = (cudnnStatus_t (*)(cudnnOpTensorDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateOpTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateOpTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateOpTensorDescriptor(opTensorDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateOpTensorDescriptor cudnnCreateOpTensorDescriptor


#undef cudnnSetOpTensorDescriptor
cudnnStatus_t cudnnSetOpTensorDescriptor(cudnnOpTensorDescriptor_t opTensorDesc, cudnnOpTensorOp_t opTensorOp, cudnnDataType_t opTensorCompType, cudnnNanPropagation_t opTensorNanOpt){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetOpTensorDescriptor) (cudnnOpTensorDescriptor_t, cudnnOpTensorOp_t, cudnnDataType_t, cudnnNanPropagation_t) = (cudnnStatus_t (*)(cudnnOpTensorDescriptor_t, cudnnOpTensorOp_t, cudnnDataType_t, cudnnNanPropagation_t))dlsym(RTLD_NEXT, "cudnnSetOpTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetOpTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetOpTensorDescriptor(opTensorDesc, opTensorOp, opTensorCompType, opTensorNanOpt);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetOpTensorDescriptor cudnnSetOpTensorDescriptor


#undef cudnnGetOpTensorDescriptor
cudnnStatus_t cudnnGetOpTensorDescriptor(cudnnOpTensorDescriptor_t const opTensorDesc, cudnnOpTensorOp_t * opTensorOp, cudnnDataType_t * opTensorCompType, cudnnNanPropagation_t * opTensorNanOpt){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetOpTensorDescriptor) (cudnnOpTensorDescriptor_t const, cudnnOpTensorOp_t *, cudnnDataType_t *, cudnnNanPropagation_t *) = (cudnnStatus_t (*)(cudnnOpTensorDescriptor_t const, cudnnOpTensorOp_t *, cudnnDataType_t *, cudnnNanPropagation_t *))dlsym(RTLD_NEXT, "cudnnGetOpTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetOpTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetOpTensorDescriptor(opTensorDesc, opTensorOp, opTensorCompType, opTensorNanOpt);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetOpTensorDescriptor cudnnGetOpTensorDescriptor


#undef cudnnDestroyOpTensorDescriptor
cudnnStatus_t cudnnDestroyOpTensorDescriptor(cudnnOpTensorDescriptor_t opTensorDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyOpTensorDescriptor) (cudnnOpTensorDescriptor_t) = (cudnnStatus_t (*)(cudnnOpTensorDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyOpTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyOpTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyOpTensorDescriptor(opTensorDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyOpTensorDescriptor cudnnDestroyOpTensorDescriptor


#undef cudnnOpTensor
cudnnStatus_t cudnnOpTensor(cudnnHandle_t handle, cudnnOpTensorDescriptor_t const opTensorDesc, void const * alpha1, cudnnTensorDescriptor_t const aDesc, void const * A, void const * alpha2, cudnnTensorDescriptor_t const bDesc, void const * B, void const * beta, cudnnTensorDescriptor_t const cDesc, void * C){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnOpTensor) (cudnnHandle_t, cudnnOpTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnOpTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnOpTensor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnOpTensor", kApiTypeCuDNN);

    lretval = lcudnnOpTensor(handle, opTensorDesc, alpha1, aDesc, A, alpha2, bDesc, B, beta, cDesc, C);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnOpTensor cudnnOpTensor


#undef cudnnCreateReduceTensorDescriptor
cudnnStatus_t cudnnCreateReduceTensorDescriptor(cudnnReduceTensorDescriptor_t * reduceTensorDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateReduceTensorDescriptor) (cudnnReduceTensorDescriptor_t *) = (cudnnStatus_t (*)(cudnnReduceTensorDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateReduceTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateReduceTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateReduceTensorDescriptor(reduceTensorDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateReduceTensorDescriptor cudnnCreateReduceTensorDescriptor


#undef cudnnSetReduceTensorDescriptor
cudnnStatus_t cudnnSetReduceTensorDescriptor(cudnnReduceTensorDescriptor_t reduceTensorDesc, cudnnReduceTensorOp_t reduceTensorOp, cudnnDataType_t reduceTensorCompType, cudnnNanPropagation_t reduceTensorNanOpt, cudnnReduceTensorIndices_t reduceTensorIndices, cudnnIndicesType_t reduceTensorIndicesType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetReduceTensorDescriptor) (cudnnReduceTensorDescriptor_t, cudnnReduceTensorOp_t, cudnnDataType_t, cudnnNanPropagation_t, cudnnReduceTensorIndices_t, cudnnIndicesType_t) = (cudnnStatus_t (*)(cudnnReduceTensorDescriptor_t, cudnnReduceTensorOp_t, cudnnDataType_t, cudnnNanPropagation_t, cudnnReduceTensorIndices_t, cudnnIndicesType_t))dlsym(RTLD_NEXT, "cudnnSetReduceTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetReduceTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetReduceTensorDescriptor(reduceTensorDesc, reduceTensorOp, reduceTensorCompType, reduceTensorNanOpt, reduceTensorIndices, reduceTensorIndicesType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetReduceTensorDescriptor cudnnSetReduceTensorDescriptor


#undef cudnnGetReduceTensorDescriptor
cudnnStatus_t cudnnGetReduceTensorDescriptor(cudnnReduceTensorDescriptor_t const reduceTensorDesc, cudnnReduceTensorOp_t * reduceTensorOp, cudnnDataType_t * reduceTensorCompType, cudnnNanPropagation_t * reduceTensorNanOpt, cudnnReduceTensorIndices_t * reduceTensorIndices, cudnnIndicesType_t * reduceTensorIndicesType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetReduceTensorDescriptor) (cudnnReduceTensorDescriptor_t const, cudnnReduceTensorOp_t *, cudnnDataType_t *, cudnnNanPropagation_t *, cudnnReduceTensorIndices_t *, cudnnIndicesType_t *) = (cudnnStatus_t (*)(cudnnReduceTensorDescriptor_t const, cudnnReduceTensorOp_t *, cudnnDataType_t *, cudnnNanPropagation_t *, cudnnReduceTensorIndices_t *, cudnnIndicesType_t *))dlsym(RTLD_NEXT, "cudnnGetReduceTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetReduceTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetReduceTensorDescriptor(reduceTensorDesc, reduceTensorOp, reduceTensorCompType, reduceTensorNanOpt, reduceTensorIndices, reduceTensorIndicesType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetReduceTensorDescriptor cudnnGetReduceTensorDescriptor


#undef cudnnDestroyReduceTensorDescriptor
cudnnStatus_t cudnnDestroyReduceTensorDescriptor(cudnnReduceTensorDescriptor_t reduceTensorDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyReduceTensorDescriptor) (cudnnReduceTensorDescriptor_t) = (cudnnStatus_t (*)(cudnnReduceTensorDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyReduceTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyReduceTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyReduceTensorDescriptor(reduceTensorDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyReduceTensorDescriptor cudnnDestroyReduceTensorDescriptor


#undef cudnnGetReductionIndicesSize
cudnnStatus_t cudnnGetReductionIndicesSize(cudnnHandle_t handle, cudnnReduceTensorDescriptor_t const reduceTensorDesc, cudnnTensorDescriptor_t const aDesc, cudnnTensorDescriptor_t const cDesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetReductionIndicesSize) (cudnnHandle_t, cudnnReduceTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnReduceTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, size_t *))dlsym(RTLD_NEXT, "cudnnGetReductionIndicesSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetReductionIndicesSize", kApiTypeCuDNN);

    lretval = lcudnnGetReductionIndicesSize(handle, reduceTensorDesc, aDesc, cDesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetReductionIndicesSize cudnnGetReductionIndicesSize


#undef cudnnGetReductionWorkspaceSize
cudnnStatus_t cudnnGetReductionWorkspaceSize(cudnnHandle_t handle, cudnnReduceTensorDescriptor_t const reduceTensorDesc, cudnnTensorDescriptor_t const aDesc, cudnnTensorDescriptor_t const cDesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetReductionWorkspaceSize) (cudnnHandle_t, cudnnReduceTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnReduceTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, size_t *))dlsym(RTLD_NEXT, "cudnnGetReductionWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetReductionWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetReductionWorkspaceSize(handle, reduceTensorDesc, aDesc, cDesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetReductionWorkspaceSize cudnnGetReductionWorkspaceSize


#undef cudnnReduceTensor
cudnnStatus_t cudnnReduceTensor(cudnnHandle_t handle, cudnnReduceTensorDescriptor_t const reduceTensorDesc, void * indices, size_t indicesSizeInBytes, void * workspace, size_t workspaceSizeInBytes, void const * alpha, cudnnTensorDescriptor_t const aDesc, void const * A, void const * beta, cudnnTensorDescriptor_t const cDesc, void * C){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnReduceTensor) (cudnnHandle_t, cudnnReduceTensorDescriptor_t const, void *, size_t, void *, size_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnReduceTensorDescriptor_t const, void *, size_t, void *, size_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnReduceTensor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnReduceTensor", kApiTypeCuDNN);

    lretval = lcudnnReduceTensor(handle, reduceTensorDesc, indices, indicesSizeInBytes, workspace, workspaceSizeInBytes, alpha, aDesc, A, beta, cDesc, C);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnReduceTensor cudnnReduceTensor


#undef cudnnSetTensor
cudnnStatus_t cudnnSetTensor(cudnnHandle_t handle, cudnnTensorDescriptor_t const yDesc, void * y, void const * valuePtr){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetTensor) (cudnnHandle_t, cudnnTensorDescriptor_t const, void *, void const *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, void *, void const *))dlsym(RTLD_NEXT, "cudnnSetTensor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetTensor", kApiTypeCuDNN);

    lretval = lcudnnSetTensor(handle, yDesc, y, valuePtr);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetTensor cudnnSetTensor


#undef cudnnScaleTensor
cudnnStatus_t cudnnScaleTensor(cudnnHandle_t handle, cudnnTensorDescriptor_t const yDesc, void * y, void const * alpha){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnScaleTensor) (cudnnHandle_t, cudnnTensorDescriptor_t const, void *, void const *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, void *, void const *))dlsym(RTLD_NEXT, "cudnnScaleTensor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnScaleTensor", kApiTypeCuDNN);

    lretval = lcudnnScaleTensor(handle, yDesc, y, alpha);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnScaleTensor cudnnScaleTensor


#undef cudnnCreateFilterDescriptor
cudnnStatus_t cudnnCreateFilterDescriptor(cudnnFilterDescriptor_t * filterDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateFilterDescriptor) (cudnnFilterDescriptor_t *) = (cudnnStatus_t (*)(cudnnFilterDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateFilterDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateFilterDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateFilterDescriptor(filterDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateFilterDescriptor cudnnCreateFilterDescriptor


#undef cudnnSetFilter4dDescriptor
cudnnStatus_t cudnnSetFilter4dDescriptor(cudnnFilterDescriptor_t filterDesc, cudnnDataType_t dataType, cudnnTensorFormat_t format, int k, int c, int h, int w){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetFilter4dDescriptor) (cudnnFilterDescriptor_t, cudnnDataType_t, cudnnTensorFormat_t, int, int, int, int) = (cudnnStatus_t (*)(cudnnFilterDescriptor_t, cudnnDataType_t, cudnnTensorFormat_t, int, int, int, int))dlsym(RTLD_NEXT, "cudnnSetFilter4dDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetFilter4dDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetFilter4dDescriptor(filterDesc, dataType, format, k, c, h, w);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetFilter4dDescriptor cudnnSetFilter4dDescriptor


#undef cudnnGetFilter4dDescriptor
cudnnStatus_t cudnnGetFilter4dDescriptor(cudnnFilterDescriptor_t const filterDesc, cudnnDataType_t * dataType, cudnnTensorFormat_t * format, int * k, int * c, int * h, int * w){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetFilter4dDescriptor) (cudnnFilterDescriptor_t const, cudnnDataType_t *, cudnnTensorFormat_t *, int *, int *, int *, int *) = (cudnnStatus_t (*)(cudnnFilterDescriptor_t const, cudnnDataType_t *, cudnnTensorFormat_t *, int *, int *, int *, int *))dlsym(RTLD_NEXT, "cudnnGetFilter4dDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetFilter4dDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetFilter4dDescriptor(filterDesc, dataType, format, k, c, h, w);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetFilter4dDescriptor cudnnGetFilter4dDescriptor


#undef cudnnSetFilterNdDescriptor
cudnnStatus_t cudnnSetFilterNdDescriptor(cudnnFilterDescriptor_t filterDesc, cudnnDataType_t dataType, cudnnTensorFormat_t format, int nbDims, int const * filterDimA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetFilterNdDescriptor) (cudnnFilterDescriptor_t, cudnnDataType_t, cudnnTensorFormat_t, int, int const *) = (cudnnStatus_t (*)(cudnnFilterDescriptor_t, cudnnDataType_t, cudnnTensorFormat_t, int, int const *))dlsym(RTLD_NEXT, "cudnnSetFilterNdDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetFilterNdDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetFilterNdDescriptor(filterDesc, dataType, format, nbDims, filterDimA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetFilterNdDescriptor cudnnSetFilterNdDescriptor


#undef cudnnGetFilterNdDescriptor
cudnnStatus_t cudnnGetFilterNdDescriptor(cudnnFilterDescriptor_t const filterDesc, int nbDimsRequested, cudnnDataType_t * dataType, cudnnTensorFormat_t * format, int * nbDims, int * filterDimA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetFilterNdDescriptor) (cudnnFilterDescriptor_t const, int, cudnnDataType_t *, cudnnTensorFormat_t *, int *, int *) = (cudnnStatus_t (*)(cudnnFilterDescriptor_t const, int, cudnnDataType_t *, cudnnTensorFormat_t *, int *, int *))dlsym(RTLD_NEXT, "cudnnGetFilterNdDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetFilterNdDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetFilterNdDescriptor(filterDesc, nbDimsRequested, dataType, format, nbDims, filterDimA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetFilterNdDescriptor cudnnGetFilterNdDescriptor


#undef cudnnGetFilterSizeInBytes
cudnnStatus_t cudnnGetFilterSizeInBytes(cudnnFilterDescriptor_t const filterDesc, size_t * size){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetFilterSizeInBytes) (cudnnFilterDescriptor_t const, size_t *) = (cudnnStatus_t (*)(cudnnFilterDescriptor_t const, size_t *))dlsym(RTLD_NEXT, "cudnnGetFilterSizeInBytes");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetFilterSizeInBytes", kApiTypeCuDNN);

    lretval = lcudnnGetFilterSizeInBytes(filterDesc, size);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetFilterSizeInBytes cudnnGetFilterSizeInBytes


#undef cudnnTransformFilter
cudnnStatus_t cudnnTransformFilter(cudnnHandle_t handle, cudnnTensorTransformDescriptor_t const transDesc, void const * alpha, cudnnFilterDescriptor_t const srcDesc, void const * srcData, void const * beta, cudnnFilterDescriptor_t const destDesc, void * destData){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnTransformFilter) (cudnnHandle_t, cudnnTensorTransformDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, void const *, cudnnFilterDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorTransformDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, void const *, cudnnFilterDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnTransformFilter");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnTransformFilter", kApiTypeCuDNN);

    lretval = lcudnnTransformFilter(handle, transDesc, alpha, srcDesc, srcData, beta, destDesc, destData);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnTransformFilter cudnnTransformFilter


#undef cudnnDestroyFilterDescriptor
cudnnStatus_t cudnnDestroyFilterDescriptor(cudnnFilterDescriptor_t filterDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyFilterDescriptor) (cudnnFilterDescriptor_t) = (cudnnStatus_t (*)(cudnnFilterDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyFilterDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyFilterDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyFilterDescriptor(filterDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyFilterDescriptor cudnnDestroyFilterDescriptor


#undef cudnnSoftmaxForward
cudnnStatus_t cudnnSoftmaxForward(cudnnHandle_t handle, cudnnSoftmaxAlgorithm_t algo, cudnnSoftmaxMode_t mode, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, void const * beta, cudnnTensorDescriptor_t const yDesc, void * y){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSoftmaxForward) (cudnnHandle_t, cudnnSoftmaxAlgorithm_t, cudnnSoftmaxMode_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnSoftmaxAlgorithm_t, cudnnSoftmaxMode_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnSoftmaxForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSoftmaxForward", kApiTypeCuDNN);

    lretval = lcudnnSoftmaxForward(handle, algo, mode, alpha, xDesc, x, beta, yDesc, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSoftmaxForward cudnnSoftmaxForward


#undef cudnnCreatePoolingDescriptor
cudnnStatus_t cudnnCreatePoolingDescriptor(cudnnPoolingDescriptor_t * poolingDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreatePoolingDescriptor) (cudnnPoolingDescriptor_t *) = (cudnnStatus_t (*)(cudnnPoolingDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreatePoolingDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreatePoolingDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreatePoolingDescriptor(poolingDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreatePoolingDescriptor cudnnCreatePoolingDescriptor


#undef cudnnSetPooling2dDescriptor
cudnnStatus_t cudnnSetPooling2dDescriptor(cudnnPoolingDescriptor_t poolingDesc, cudnnPoolingMode_t mode, cudnnNanPropagation_t maxpoolingNanOpt, int windowHeight, int windowWidth, int verticalPadding, int horizontalPadding, int verticalStride, int horizontalStride){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetPooling2dDescriptor) (cudnnPoolingDescriptor_t, cudnnPoolingMode_t, cudnnNanPropagation_t, int, int, int, int, int, int) = (cudnnStatus_t (*)(cudnnPoolingDescriptor_t, cudnnPoolingMode_t, cudnnNanPropagation_t, int, int, int, int, int, int))dlsym(RTLD_NEXT, "cudnnSetPooling2dDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetPooling2dDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetPooling2dDescriptor(poolingDesc, mode, maxpoolingNanOpt, windowHeight, windowWidth, verticalPadding, horizontalPadding, verticalStride, horizontalStride);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetPooling2dDescriptor cudnnSetPooling2dDescriptor


#undef cudnnGetPooling2dDescriptor
cudnnStatus_t cudnnGetPooling2dDescriptor(cudnnPoolingDescriptor_t const poolingDesc, cudnnPoolingMode_t * mode, cudnnNanPropagation_t * maxpoolingNanOpt, int * windowHeight, int * windowWidth, int * verticalPadding, int * horizontalPadding, int * verticalStride, int * horizontalStride){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetPooling2dDescriptor) (cudnnPoolingDescriptor_t const, cudnnPoolingMode_t *, cudnnNanPropagation_t *, int *, int *, int *, int *, int *, int *) = (cudnnStatus_t (*)(cudnnPoolingDescriptor_t const, cudnnPoolingMode_t *, cudnnNanPropagation_t *, int *, int *, int *, int *, int *, int *))dlsym(RTLD_NEXT, "cudnnGetPooling2dDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetPooling2dDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetPooling2dDescriptor(poolingDesc, mode, maxpoolingNanOpt, windowHeight, windowWidth, verticalPadding, horizontalPadding, verticalStride, horizontalStride);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetPooling2dDescriptor cudnnGetPooling2dDescriptor


#undef cudnnSetPoolingNdDescriptor
cudnnStatus_t cudnnSetPoolingNdDescriptor(cudnnPoolingDescriptor_t poolingDesc, cudnnPoolingMode_t const mode, cudnnNanPropagation_t const maxpoolingNanOpt, int nbDims, int const * windowDimA, int const * paddingA, int const * strideA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetPoolingNdDescriptor) (cudnnPoolingDescriptor_t, cudnnPoolingMode_t const, cudnnNanPropagation_t const, int, int const *, int const *, int const *) = (cudnnStatus_t (*)(cudnnPoolingDescriptor_t, cudnnPoolingMode_t const, cudnnNanPropagation_t const, int, int const *, int const *, int const *))dlsym(RTLD_NEXT, "cudnnSetPoolingNdDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetPoolingNdDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetPoolingNdDescriptor(poolingDesc, mode, maxpoolingNanOpt, nbDims, windowDimA, paddingA, strideA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetPoolingNdDescriptor cudnnSetPoolingNdDescriptor


#undef cudnnGetPoolingNdDescriptor
cudnnStatus_t cudnnGetPoolingNdDescriptor(cudnnPoolingDescriptor_t const poolingDesc, int nbDimsRequested, cudnnPoolingMode_t * mode, cudnnNanPropagation_t * maxpoolingNanOpt, int * nbDims, int * windowDimA, int * paddingA, int * strideA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetPoolingNdDescriptor) (cudnnPoolingDescriptor_t const, int, cudnnPoolingMode_t *, cudnnNanPropagation_t *, int *, int *, int *, int *) = (cudnnStatus_t (*)(cudnnPoolingDescriptor_t const, int, cudnnPoolingMode_t *, cudnnNanPropagation_t *, int *, int *, int *, int *))dlsym(RTLD_NEXT, "cudnnGetPoolingNdDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetPoolingNdDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetPoolingNdDescriptor(poolingDesc, nbDimsRequested, mode, maxpoolingNanOpt, nbDims, windowDimA, paddingA, strideA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetPoolingNdDescriptor cudnnGetPoolingNdDescriptor


#undef cudnnGetPoolingNdForwardOutputDim
cudnnStatus_t cudnnGetPoolingNdForwardOutputDim(cudnnPoolingDescriptor_t const poolingDesc, cudnnTensorDescriptor_t const inputTensorDesc, int nbDims, int * outputTensorDimA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetPoolingNdForwardOutputDim) (cudnnPoolingDescriptor_t const, cudnnTensorDescriptor_t const, int, int *) = (cudnnStatus_t (*)(cudnnPoolingDescriptor_t const, cudnnTensorDescriptor_t const, int, int *))dlsym(RTLD_NEXT, "cudnnGetPoolingNdForwardOutputDim");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetPoolingNdForwardOutputDim", kApiTypeCuDNN);

    lretval = lcudnnGetPoolingNdForwardOutputDim(poolingDesc, inputTensorDesc, nbDims, outputTensorDimA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetPoolingNdForwardOutputDim cudnnGetPoolingNdForwardOutputDim


#undef cudnnGetPooling2dForwardOutputDim
cudnnStatus_t cudnnGetPooling2dForwardOutputDim(cudnnPoolingDescriptor_t const poolingDesc, cudnnTensorDescriptor_t const inputTensorDesc, int * n, int * c, int * h, int * w){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetPooling2dForwardOutputDim) (cudnnPoolingDescriptor_t const, cudnnTensorDescriptor_t const, int *, int *, int *, int *) = (cudnnStatus_t (*)(cudnnPoolingDescriptor_t const, cudnnTensorDescriptor_t const, int *, int *, int *, int *))dlsym(RTLD_NEXT, "cudnnGetPooling2dForwardOutputDim");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetPooling2dForwardOutputDim", kApiTypeCuDNN);

    lretval = lcudnnGetPooling2dForwardOutputDim(poolingDesc, inputTensorDesc, n, c, h, w);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetPooling2dForwardOutputDim cudnnGetPooling2dForwardOutputDim


#undef cudnnDestroyPoolingDescriptor
cudnnStatus_t cudnnDestroyPoolingDescriptor(cudnnPoolingDescriptor_t poolingDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyPoolingDescriptor) (cudnnPoolingDescriptor_t) = (cudnnStatus_t (*)(cudnnPoolingDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyPoolingDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyPoolingDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyPoolingDescriptor(poolingDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyPoolingDescriptor cudnnDestroyPoolingDescriptor


#undef cudnnPoolingForward
cudnnStatus_t cudnnPoolingForward(cudnnHandle_t handle, cudnnPoolingDescriptor_t const poolingDesc, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, void const * beta, cudnnTensorDescriptor_t const yDesc, void * y){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnPoolingForward) (cudnnHandle_t, cudnnPoolingDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnPoolingDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnPoolingForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnPoolingForward", kApiTypeCuDNN);

    lretval = lcudnnPoolingForward(handle, poolingDesc, alpha, xDesc, x, beta, yDesc, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnPoolingForward cudnnPoolingForward


#undef cudnnCreateActivationDescriptor
cudnnStatus_t cudnnCreateActivationDescriptor(cudnnActivationDescriptor_t * activationDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateActivationDescriptor) (cudnnActivationDescriptor_t *) = (cudnnStatus_t (*)(cudnnActivationDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateActivationDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateActivationDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateActivationDescriptor(activationDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateActivationDescriptor cudnnCreateActivationDescriptor


#undef cudnnSetActivationDescriptor
cudnnStatus_t cudnnSetActivationDescriptor(cudnnActivationDescriptor_t activationDesc, cudnnActivationMode_t mode, cudnnNanPropagation_t reluNanOpt, double coef){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetActivationDescriptor) (cudnnActivationDescriptor_t, cudnnActivationMode_t, cudnnNanPropagation_t, double) = (cudnnStatus_t (*)(cudnnActivationDescriptor_t, cudnnActivationMode_t, cudnnNanPropagation_t, double))dlsym(RTLD_NEXT, "cudnnSetActivationDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetActivationDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetActivationDescriptor(activationDesc, mode, reluNanOpt, coef);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetActivationDescriptor cudnnSetActivationDescriptor


#undef cudnnGetActivationDescriptor
cudnnStatus_t cudnnGetActivationDescriptor(cudnnActivationDescriptor_t const activationDesc, cudnnActivationMode_t * mode, cudnnNanPropagation_t * reluNanOpt, double * coef){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetActivationDescriptor) (cudnnActivationDescriptor_t const, cudnnActivationMode_t *, cudnnNanPropagation_t *, double *) = (cudnnStatus_t (*)(cudnnActivationDescriptor_t const, cudnnActivationMode_t *, cudnnNanPropagation_t *, double *))dlsym(RTLD_NEXT, "cudnnGetActivationDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetActivationDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetActivationDescriptor(activationDesc, mode, reluNanOpt, coef);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetActivationDescriptor cudnnGetActivationDescriptor


#undef cudnnSetActivationDescriptorSwishBeta
cudnnStatus_t cudnnSetActivationDescriptorSwishBeta(cudnnActivationDescriptor_t activationDesc, double swish_beta){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetActivationDescriptorSwishBeta) (cudnnActivationDescriptor_t, double) = (cudnnStatus_t (*)(cudnnActivationDescriptor_t, double))dlsym(RTLD_NEXT, "cudnnSetActivationDescriptorSwishBeta");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetActivationDescriptorSwishBeta", kApiTypeCuDNN);

    lretval = lcudnnSetActivationDescriptorSwishBeta(activationDesc, swish_beta);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetActivationDescriptorSwishBeta cudnnSetActivationDescriptorSwishBeta


#undef cudnnGetActivationDescriptorSwishBeta
cudnnStatus_t cudnnGetActivationDescriptorSwishBeta(cudnnActivationDescriptor_t activationDesc, double * swish_beta){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetActivationDescriptorSwishBeta) (cudnnActivationDescriptor_t, double *) = (cudnnStatus_t (*)(cudnnActivationDescriptor_t, double *))dlsym(RTLD_NEXT, "cudnnGetActivationDescriptorSwishBeta");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetActivationDescriptorSwishBeta", kApiTypeCuDNN);

    lretval = lcudnnGetActivationDescriptorSwishBeta(activationDesc, swish_beta);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetActivationDescriptorSwishBeta cudnnGetActivationDescriptorSwishBeta


#undef cudnnDestroyActivationDescriptor
cudnnStatus_t cudnnDestroyActivationDescriptor(cudnnActivationDescriptor_t activationDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyActivationDescriptor) (cudnnActivationDescriptor_t) = (cudnnStatus_t (*)(cudnnActivationDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyActivationDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyActivationDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyActivationDescriptor(activationDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyActivationDescriptor cudnnDestroyActivationDescriptor


#undef cudnnActivationForward
cudnnStatus_t cudnnActivationForward(cudnnHandle_t handle, cudnnActivationDescriptor_t activationDesc, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, void const * beta, cudnnTensorDescriptor_t const yDesc, void * y){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnActivationForward) (cudnnHandle_t, cudnnActivationDescriptor_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnActivationDescriptor_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnActivationForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnActivationForward", kApiTypeCuDNN);

    lretval = lcudnnActivationForward(handle, activationDesc, alpha, xDesc, x, beta, yDesc, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnActivationForward cudnnActivationForward


#undef cudnnCreateLRNDescriptor
cudnnStatus_t cudnnCreateLRNDescriptor(cudnnLRNDescriptor_t * normDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateLRNDescriptor) (cudnnLRNDescriptor_t *) = (cudnnStatus_t (*)(cudnnLRNDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateLRNDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateLRNDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateLRNDescriptor(normDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateLRNDescriptor cudnnCreateLRNDescriptor


#undef cudnnSetLRNDescriptor
cudnnStatus_t cudnnSetLRNDescriptor(cudnnLRNDescriptor_t normDesc, unsigned int lrnN, double lrnAlpha, double lrnBeta, double lrnK){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetLRNDescriptor) (cudnnLRNDescriptor_t, unsigned int, double, double, double) = (cudnnStatus_t (*)(cudnnLRNDescriptor_t, unsigned int, double, double, double))dlsym(RTLD_NEXT, "cudnnSetLRNDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetLRNDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetLRNDescriptor(normDesc, lrnN, lrnAlpha, lrnBeta, lrnK);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetLRNDescriptor cudnnSetLRNDescriptor


#undef cudnnGetLRNDescriptor
cudnnStatus_t cudnnGetLRNDescriptor(cudnnLRNDescriptor_t normDesc, unsigned int * lrnN, double * lrnAlpha, double * lrnBeta, double * lrnK){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetLRNDescriptor) (cudnnLRNDescriptor_t, unsigned int *, double *, double *, double *) = (cudnnStatus_t (*)(cudnnLRNDescriptor_t, unsigned int *, double *, double *, double *))dlsym(RTLD_NEXT, "cudnnGetLRNDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetLRNDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetLRNDescriptor(normDesc, lrnN, lrnAlpha, lrnBeta, lrnK);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetLRNDescriptor cudnnGetLRNDescriptor


#undef cudnnDestroyLRNDescriptor
cudnnStatus_t cudnnDestroyLRNDescriptor(cudnnLRNDescriptor_t lrnDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyLRNDescriptor) (cudnnLRNDescriptor_t) = (cudnnStatus_t (*)(cudnnLRNDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyLRNDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyLRNDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyLRNDescriptor(lrnDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyLRNDescriptor cudnnDestroyLRNDescriptor


#undef cudnnLRNCrossChannelForward
cudnnStatus_t cudnnLRNCrossChannelForward(cudnnHandle_t handle, cudnnLRNDescriptor_t normDesc, cudnnLRNMode_t lrnMode, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, void const * beta, cudnnTensorDescriptor_t const yDesc, void * y){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnLRNCrossChannelForward) (cudnnHandle_t, cudnnLRNDescriptor_t, cudnnLRNMode_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnLRNDescriptor_t, cudnnLRNMode_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnLRNCrossChannelForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnLRNCrossChannelForward", kApiTypeCuDNN);

    lretval = lcudnnLRNCrossChannelForward(handle, normDesc, lrnMode, alpha, xDesc, x, beta, yDesc, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnLRNCrossChannelForward cudnnLRNCrossChannelForward


#undef cudnnDivisiveNormalizationForward
cudnnStatus_t cudnnDivisiveNormalizationForward(cudnnHandle_t handle, cudnnLRNDescriptor_t normDesc, cudnnDivNormMode_t mode, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, void const * means, void * temp, void * temp2, void const * beta, cudnnTensorDescriptor_t const yDesc, void * y){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDivisiveNormalizationForward) (cudnnHandle_t, cudnnLRNDescriptor_t, cudnnDivNormMode_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, void *, void *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnLRNDescriptor_t, cudnnDivNormMode_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, void *, void *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnDivisiveNormalizationForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDivisiveNormalizationForward", kApiTypeCuDNN);

    lretval = lcudnnDivisiveNormalizationForward(handle, normDesc, mode, alpha, xDesc, x, means, temp, temp2, beta, yDesc, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDivisiveNormalizationForward cudnnDivisiveNormalizationForward


#undef cudnnDeriveBNTensorDescriptor
cudnnStatus_t cudnnDeriveBNTensorDescriptor(cudnnTensorDescriptor_t derivedBnDesc, cudnnTensorDescriptor_t const xDesc, cudnnBatchNormMode_t mode){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDeriveBNTensorDescriptor) (cudnnTensorDescriptor_t, cudnnTensorDescriptor_t const, cudnnBatchNormMode_t) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t, cudnnTensorDescriptor_t const, cudnnBatchNormMode_t))dlsym(RTLD_NEXT, "cudnnDeriveBNTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDeriveBNTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDeriveBNTensorDescriptor(derivedBnDesc, xDesc, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDeriveBNTensorDescriptor cudnnDeriveBNTensorDescriptor


#undef cudnnBatchNormalizationForwardInference
cudnnStatus_t cudnnBatchNormalizationForwardInference(cudnnHandle_t handle, cudnnBatchNormMode_t mode, void const * alpha, void const * beta, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnTensorDescriptor_t const yDesc, void * y, cudnnTensorDescriptor_t const bnScaleBiasMeanVarDesc, void const * bnScale, void const * bnBias, void const * estimatedMean, void const * estimatedVariance, double epsilon){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBatchNormalizationForwardInference) (cudnnHandle_t, cudnnBatchNormMode_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, void const *, void const *, double) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnBatchNormMode_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, void const *, void const *, double))dlsym(RTLD_NEXT, "cudnnBatchNormalizationForwardInference");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBatchNormalizationForwardInference", kApiTypeCuDNN);

    lretval = lcudnnBatchNormalizationForwardInference(handle, mode, alpha, beta, xDesc, x, yDesc, y, bnScaleBiasMeanVarDesc, bnScale, bnBias, estimatedMean, estimatedVariance, epsilon);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBatchNormalizationForwardInference cudnnBatchNormalizationForwardInference


#undef cudnnDeriveNormTensorDescriptor
cudnnStatus_t cudnnDeriveNormTensorDescriptor(cudnnTensorDescriptor_t derivedNormScaleBiasDesc, cudnnTensorDescriptor_t derivedNormMeanVarDesc, cudnnTensorDescriptor_t const xDesc, cudnnNormMode_t mode, int groupCnt){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDeriveNormTensorDescriptor) (cudnnTensorDescriptor_t, cudnnTensorDescriptor_t, cudnnTensorDescriptor_t const, cudnnNormMode_t, int) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t, cudnnTensorDescriptor_t, cudnnTensorDescriptor_t const, cudnnNormMode_t, int))dlsym(RTLD_NEXT, "cudnnDeriveNormTensorDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDeriveNormTensorDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDeriveNormTensorDescriptor(derivedNormScaleBiasDesc, derivedNormMeanVarDesc, xDesc, mode, groupCnt);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDeriveNormTensorDescriptor cudnnDeriveNormTensorDescriptor


#undef cudnnNormalizationForwardInference
cudnnStatus_t cudnnNormalizationForwardInference(cudnnHandle_t handle, cudnnNormMode_t mode, cudnnNormOps_t normOps, cudnnNormAlgo_t algo, void const * alpha, void const * beta, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnTensorDescriptor_t const normScaleBiasDesc, void const * normScale, void const * normBias, cudnnTensorDescriptor_t const normMeanVarDesc, void const * estimatedMean, void const * estimatedVariance, cudnnTensorDescriptor_t const zDesc, void const * z, cudnnActivationDescriptor_t activationDesc, cudnnTensorDescriptor_t const yDesc, void * y, double epsilon, int groupCnt){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnNormalizationForwardInference) (cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnActivationDescriptor_t, cudnnTensorDescriptor_t const, void *, double, int) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnActivationDescriptor_t, cudnnTensorDescriptor_t const, void *, double, int))dlsym(RTLD_NEXT, "cudnnNormalizationForwardInference");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnNormalizationForwardInference", kApiTypeCuDNN);

    lretval = lcudnnNormalizationForwardInference(handle, mode, normOps, algo, alpha, beta, xDesc, x, normScaleBiasDesc, normScale, normBias, normMeanVarDesc, estimatedMean, estimatedVariance, zDesc, z, activationDesc, yDesc, y, epsilon, groupCnt);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnNormalizationForwardInference cudnnNormalizationForwardInference


#undef cudnnCreateSpatialTransformerDescriptor
cudnnStatus_t cudnnCreateSpatialTransformerDescriptor(cudnnSpatialTransformerDescriptor_t * stDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateSpatialTransformerDescriptor) (cudnnSpatialTransformerDescriptor_t *) = (cudnnStatus_t (*)(cudnnSpatialTransformerDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateSpatialTransformerDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateSpatialTransformerDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateSpatialTransformerDescriptor(stDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateSpatialTransformerDescriptor cudnnCreateSpatialTransformerDescriptor


#undef cudnnSetSpatialTransformerNdDescriptor
cudnnStatus_t cudnnSetSpatialTransformerNdDescriptor(cudnnSpatialTransformerDescriptor_t stDesc, cudnnSamplerType_t samplerType, cudnnDataType_t dataType, int const nbDims, int const * dimA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetSpatialTransformerNdDescriptor) (cudnnSpatialTransformerDescriptor_t, cudnnSamplerType_t, cudnnDataType_t, int const, int const *) = (cudnnStatus_t (*)(cudnnSpatialTransformerDescriptor_t, cudnnSamplerType_t, cudnnDataType_t, int const, int const *))dlsym(RTLD_NEXT, "cudnnSetSpatialTransformerNdDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetSpatialTransformerNdDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetSpatialTransformerNdDescriptor(stDesc, samplerType, dataType, nbDims, dimA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetSpatialTransformerNdDescriptor cudnnSetSpatialTransformerNdDescriptor


#undef cudnnDestroySpatialTransformerDescriptor
cudnnStatus_t cudnnDestroySpatialTransformerDescriptor(cudnnSpatialTransformerDescriptor_t stDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroySpatialTransformerDescriptor) (cudnnSpatialTransformerDescriptor_t) = (cudnnStatus_t (*)(cudnnSpatialTransformerDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroySpatialTransformerDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroySpatialTransformerDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroySpatialTransformerDescriptor(stDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroySpatialTransformerDescriptor cudnnDestroySpatialTransformerDescriptor


#undef cudnnSpatialTfGridGeneratorForward
cudnnStatus_t cudnnSpatialTfGridGeneratorForward(cudnnHandle_t handle, cudnnSpatialTransformerDescriptor_t const stDesc, void const * theta, void * grid){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSpatialTfGridGeneratorForward) (cudnnHandle_t, cudnnSpatialTransformerDescriptor_t const, void const *, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnSpatialTransformerDescriptor_t const, void const *, void *))dlsym(RTLD_NEXT, "cudnnSpatialTfGridGeneratorForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSpatialTfGridGeneratorForward", kApiTypeCuDNN);

    lretval = lcudnnSpatialTfGridGeneratorForward(handle, stDesc, theta, grid);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSpatialTfGridGeneratorForward cudnnSpatialTfGridGeneratorForward


#undef cudnnSpatialTfSamplerForward
cudnnStatus_t cudnnSpatialTfSamplerForward(cudnnHandle_t handle, cudnnSpatialTransformerDescriptor_t stDesc, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, void const * grid, void const * beta, cudnnTensorDescriptor_t yDesc, void * y){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSpatialTfSamplerForward) (cudnnHandle_t, cudnnSpatialTransformerDescriptor_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, void const *, cudnnTensorDescriptor_t, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnSpatialTransformerDescriptor_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, void const *, cudnnTensorDescriptor_t, void *))dlsym(RTLD_NEXT, "cudnnSpatialTfSamplerForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSpatialTfSamplerForward", kApiTypeCuDNN);

    lretval = lcudnnSpatialTfSamplerForward(handle, stDesc, alpha, xDesc, x, grid, beta, yDesc, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSpatialTfSamplerForward cudnnSpatialTfSamplerForward


#undef cudnnCreateDropoutDescriptor
cudnnStatus_t cudnnCreateDropoutDescriptor(cudnnDropoutDescriptor_t * dropoutDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateDropoutDescriptor) (cudnnDropoutDescriptor_t *) = (cudnnStatus_t (*)(cudnnDropoutDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateDropoutDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateDropoutDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateDropoutDescriptor(dropoutDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateDropoutDescriptor cudnnCreateDropoutDescriptor


#undef cudnnDestroyDropoutDescriptor
cudnnStatus_t cudnnDestroyDropoutDescriptor(cudnnDropoutDescriptor_t dropoutDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyDropoutDescriptor) (cudnnDropoutDescriptor_t) = (cudnnStatus_t (*)(cudnnDropoutDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyDropoutDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyDropoutDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyDropoutDescriptor(dropoutDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyDropoutDescriptor cudnnDestroyDropoutDescriptor


#undef cudnnDropoutGetStatesSize
cudnnStatus_t cudnnDropoutGetStatesSize(cudnnHandle_t handle, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDropoutGetStatesSize) (cudnnHandle_t, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, size_t *))dlsym(RTLD_NEXT, "cudnnDropoutGetStatesSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDropoutGetStatesSize", kApiTypeCuDNN);

    lretval = lcudnnDropoutGetStatesSize(handle, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDropoutGetStatesSize cudnnDropoutGetStatesSize


#undef cudnnDropoutGetReserveSpaceSize
cudnnStatus_t cudnnDropoutGetReserveSpaceSize(cudnnTensorDescriptor_t xdesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDropoutGetReserveSpaceSize) (cudnnTensorDescriptor_t, size_t *) = (cudnnStatus_t (*)(cudnnTensorDescriptor_t, size_t *))dlsym(RTLD_NEXT, "cudnnDropoutGetReserveSpaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDropoutGetReserveSpaceSize", kApiTypeCuDNN);

    lretval = lcudnnDropoutGetReserveSpaceSize(xdesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDropoutGetReserveSpaceSize cudnnDropoutGetReserveSpaceSize


#undef cudnnSetDropoutDescriptor
cudnnStatus_t cudnnSetDropoutDescriptor(cudnnDropoutDescriptor_t dropoutDesc, cudnnHandle_t handle, float dropout, void * states, size_t stateSizeInBytes, long long unsigned int seed){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetDropoutDescriptor) (cudnnDropoutDescriptor_t, cudnnHandle_t, float, void *, size_t, long long unsigned int) = (cudnnStatus_t (*)(cudnnDropoutDescriptor_t, cudnnHandle_t, float, void *, size_t, long long unsigned int))dlsym(RTLD_NEXT, "cudnnSetDropoutDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetDropoutDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetDropoutDescriptor(dropoutDesc, handle, dropout, states, stateSizeInBytes, seed);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetDropoutDescriptor cudnnSetDropoutDescriptor


#undef cudnnRestoreDropoutDescriptor
cudnnStatus_t cudnnRestoreDropoutDescriptor(cudnnDropoutDescriptor_t dropoutDesc, cudnnHandle_t handle, float dropout, void * states, size_t stateSizeInBytes, long long unsigned int seed){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRestoreDropoutDescriptor) (cudnnDropoutDescriptor_t, cudnnHandle_t, float, void *, size_t, long long unsigned int) = (cudnnStatus_t (*)(cudnnDropoutDescriptor_t, cudnnHandle_t, float, void *, size_t, long long unsigned int))dlsym(RTLD_NEXT, "cudnnRestoreDropoutDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRestoreDropoutDescriptor", kApiTypeCuDNN);

    lretval = lcudnnRestoreDropoutDescriptor(dropoutDesc, handle, dropout, states, stateSizeInBytes, seed);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRestoreDropoutDescriptor cudnnRestoreDropoutDescriptor


#undef cudnnGetDropoutDescriptor
cudnnStatus_t cudnnGetDropoutDescriptor(cudnnDropoutDescriptor_t dropoutDesc, cudnnHandle_t handle, float * dropout, void * * states, long long unsigned int * seed){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetDropoutDescriptor) (cudnnDropoutDescriptor_t, cudnnHandle_t, float *, void * *, long long unsigned int *) = (cudnnStatus_t (*)(cudnnDropoutDescriptor_t, cudnnHandle_t, float *, void * *, long long unsigned int *))dlsym(RTLD_NEXT, "cudnnGetDropoutDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetDropoutDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetDropoutDescriptor(dropoutDesc, handle, dropout, states, seed);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetDropoutDescriptor cudnnGetDropoutDescriptor


#undef cudnnDropoutForward
cudnnStatus_t cudnnDropoutForward(cudnnHandle_t handle, cudnnDropoutDescriptor_t const dropoutDesc, cudnnTensorDescriptor_t const xdesc, void const * x, cudnnTensorDescriptor_t const ydesc, void * y, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDropoutForward) (cudnnHandle_t, cudnnDropoutDescriptor_t const, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnDropoutDescriptor_t const, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, void *, size_t))dlsym(RTLD_NEXT, "cudnnDropoutForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDropoutForward", kApiTypeCuDNN);

    lretval = lcudnnDropoutForward(handle, dropoutDesc, xdesc, x, ydesc, y, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDropoutForward cudnnDropoutForward


#undef cudnnCreateAlgorithmDescriptor
cudnnStatus_t cudnnCreateAlgorithmDescriptor(cudnnAlgorithmDescriptor_t * algoDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateAlgorithmDescriptor) (cudnnAlgorithmDescriptor_t *) = (cudnnStatus_t (*)(cudnnAlgorithmDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateAlgorithmDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateAlgorithmDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateAlgorithmDescriptor(algoDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateAlgorithmDescriptor cudnnCreateAlgorithmDescriptor


#undef cudnnSetAlgorithmDescriptor
cudnnStatus_t cudnnSetAlgorithmDescriptor(cudnnAlgorithmDescriptor_t algoDesc, cudnnAlgorithm_t algorithm){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetAlgorithmDescriptor) (cudnnAlgorithmDescriptor_t, cudnnAlgorithm_t) = (cudnnStatus_t (*)(cudnnAlgorithmDescriptor_t, cudnnAlgorithm_t))dlsym(RTLD_NEXT, "cudnnSetAlgorithmDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetAlgorithmDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetAlgorithmDescriptor(algoDesc, algorithm);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetAlgorithmDescriptor cudnnSetAlgorithmDescriptor


#undef cudnnGetAlgorithmDescriptor
cudnnStatus_t cudnnGetAlgorithmDescriptor(cudnnAlgorithmDescriptor_t const algoDesc, cudnnAlgorithm_t * algorithm){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetAlgorithmDescriptor) (cudnnAlgorithmDescriptor_t const, cudnnAlgorithm_t *) = (cudnnStatus_t (*)(cudnnAlgorithmDescriptor_t const, cudnnAlgorithm_t *))dlsym(RTLD_NEXT, "cudnnGetAlgorithmDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetAlgorithmDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetAlgorithmDescriptor(algoDesc, algorithm);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetAlgorithmDescriptor cudnnGetAlgorithmDescriptor


#undef cudnnCopyAlgorithmDescriptor
cudnnStatus_t cudnnCopyAlgorithmDescriptor(cudnnAlgorithmDescriptor_t const src, cudnnAlgorithmDescriptor_t dest){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCopyAlgorithmDescriptor) (cudnnAlgorithmDescriptor_t const, cudnnAlgorithmDescriptor_t) = (cudnnStatus_t (*)(cudnnAlgorithmDescriptor_t const, cudnnAlgorithmDescriptor_t))dlsym(RTLD_NEXT, "cudnnCopyAlgorithmDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCopyAlgorithmDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCopyAlgorithmDescriptor(src, dest);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCopyAlgorithmDescriptor cudnnCopyAlgorithmDescriptor


#undef cudnnDestroyAlgorithmDescriptor
cudnnStatus_t cudnnDestroyAlgorithmDescriptor(cudnnAlgorithmDescriptor_t algoDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyAlgorithmDescriptor) (cudnnAlgorithmDescriptor_t) = (cudnnStatus_t (*)(cudnnAlgorithmDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyAlgorithmDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyAlgorithmDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyAlgorithmDescriptor(algoDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyAlgorithmDescriptor cudnnDestroyAlgorithmDescriptor


#undef cudnnCreateAlgorithmPerformance
cudnnStatus_t cudnnCreateAlgorithmPerformance(cudnnAlgorithmPerformance_t * algoPerf, int numberToCreate){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateAlgorithmPerformance) (cudnnAlgorithmPerformance_t *, int) = (cudnnStatus_t (*)(cudnnAlgorithmPerformance_t *, int))dlsym(RTLD_NEXT, "cudnnCreateAlgorithmPerformance");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateAlgorithmPerformance", kApiTypeCuDNN);

    lretval = lcudnnCreateAlgorithmPerformance(algoPerf, numberToCreate);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateAlgorithmPerformance cudnnCreateAlgorithmPerformance


#undef cudnnSetAlgorithmPerformance
cudnnStatus_t cudnnSetAlgorithmPerformance(cudnnAlgorithmPerformance_t algoPerf, cudnnAlgorithmDescriptor_t algoDesc, cudnnStatus_t status, float time, size_t memory){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetAlgorithmPerformance) (cudnnAlgorithmPerformance_t, cudnnAlgorithmDescriptor_t, cudnnStatus_t, float, size_t) = (cudnnStatus_t (*)(cudnnAlgorithmPerformance_t, cudnnAlgorithmDescriptor_t, cudnnStatus_t, float, size_t))dlsym(RTLD_NEXT, "cudnnSetAlgorithmPerformance");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetAlgorithmPerformance", kApiTypeCuDNN);

    lretval = lcudnnSetAlgorithmPerformance(algoPerf, algoDesc, status, time, memory);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetAlgorithmPerformance cudnnSetAlgorithmPerformance


#undef cudnnGetAlgorithmPerformance
cudnnStatus_t cudnnGetAlgorithmPerformance(cudnnAlgorithmPerformance_t const algoPerf, cudnnAlgorithmDescriptor_t * algoDesc, cudnnStatus_t * status, float * time, size_t * memory){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetAlgorithmPerformance) (cudnnAlgorithmPerformance_t const, cudnnAlgorithmDescriptor_t *, cudnnStatus_t *, float *, size_t *) = (cudnnStatus_t (*)(cudnnAlgorithmPerformance_t const, cudnnAlgorithmDescriptor_t *, cudnnStatus_t *, float *, size_t *))dlsym(RTLD_NEXT, "cudnnGetAlgorithmPerformance");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetAlgorithmPerformance", kApiTypeCuDNN);

    lretval = lcudnnGetAlgorithmPerformance(algoPerf, algoDesc, status, time, memory);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetAlgorithmPerformance cudnnGetAlgorithmPerformance


#undef cudnnDestroyAlgorithmPerformance
cudnnStatus_t cudnnDestroyAlgorithmPerformance(cudnnAlgorithmPerformance_t * algoPerf, int numberToDestroy){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyAlgorithmPerformance) (cudnnAlgorithmPerformance_t *, int) = (cudnnStatus_t (*)(cudnnAlgorithmPerformance_t *, int))dlsym(RTLD_NEXT, "cudnnDestroyAlgorithmPerformance");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyAlgorithmPerformance", kApiTypeCuDNN);

    lretval = lcudnnDestroyAlgorithmPerformance(algoPerf, numberToDestroy);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyAlgorithmPerformance cudnnDestroyAlgorithmPerformance


#undef cudnnGetAlgorithmSpaceSize
cudnnStatus_t cudnnGetAlgorithmSpaceSize(cudnnHandle_t handle, cudnnAlgorithmDescriptor_t algoDesc, size_t * algoSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetAlgorithmSpaceSize) (cudnnHandle_t, cudnnAlgorithmDescriptor_t, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnAlgorithmDescriptor_t, size_t *))dlsym(RTLD_NEXT, "cudnnGetAlgorithmSpaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetAlgorithmSpaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetAlgorithmSpaceSize(handle, algoDesc, algoSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetAlgorithmSpaceSize cudnnGetAlgorithmSpaceSize


#undef cudnnSaveAlgorithm
cudnnStatus_t cudnnSaveAlgorithm(cudnnHandle_t handle, cudnnAlgorithmDescriptor_t algoDesc, void * algoSpace, size_t algoSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSaveAlgorithm) (cudnnHandle_t, cudnnAlgorithmDescriptor_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnAlgorithmDescriptor_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnSaveAlgorithm");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSaveAlgorithm", kApiTypeCuDNN);

    lretval = lcudnnSaveAlgorithm(handle, algoDesc, algoSpace, algoSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSaveAlgorithm cudnnSaveAlgorithm


#undef cudnnRestoreAlgorithm
cudnnStatus_t cudnnRestoreAlgorithm(cudnnHandle_t handle, void * algoSpace, size_t algoSpaceSizeInBytes, cudnnAlgorithmDescriptor_t algoDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRestoreAlgorithm) (cudnnHandle_t, void *, size_t, cudnnAlgorithmDescriptor_t) = (cudnnStatus_t (*)(cudnnHandle_t, void *, size_t, cudnnAlgorithmDescriptor_t))dlsym(RTLD_NEXT, "cudnnRestoreAlgorithm");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRestoreAlgorithm", kApiTypeCuDNN);

    lretval = lcudnnRestoreAlgorithm(handle, algoSpace, algoSpaceSizeInBytes, algoDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRestoreAlgorithm cudnnRestoreAlgorithm


#undef cudnnSetCallback
cudnnStatus_t cudnnSetCallback(unsigned int mask, void * udata, cudnnCallback_t fptr){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetCallback) (unsigned int, void *, cudnnCallback_t) = (cudnnStatus_t (*)(unsigned int, void *, cudnnCallback_t))dlsym(RTLD_NEXT, "cudnnSetCallback");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetCallback", kApiTypeCuDNN);

    lretval = lcudnnSetCallback(mask, udata, fptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetCallback cudnnSetCallback


#undef cudnnGetCallback
cudnnStatus_t cudnnGetCallback(unsigned int * mask, void * * udata, cudnnCallback_t * fptr){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetCallback) (unsigned int *, void * *, cudnnCallback_t *) = (cudnnStatus_t (*)(unsigned int *, void * *, cudnnCallback_t *))dlsym(RTLD_NEXT, "cudnnGetCallback");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetCallback", kApiTypeCuDNN);

    lretval = lcudnnGetCallback(mask, udata, fptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetCallback cudnnGetCallback


#undef cudnnOpsInferVersionCheck
cudnnStatus_t cudnnOpsInferVersionCheck(){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnOpsInferVersionCheck) () = (cudnnStatus_t (*)())dlsym(RTLD_NEXT, "cudnnOpsInferVersionCheck");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnOpsInferVersionCheck", kApiTypeCuDNN);

    lretval = lcudnnOpsInferVersionCheck();
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnOpsInferVersionCheck cudnnOpsInferVersionCheck


#undef cudnnSoftmaxBackward
cudnnStatus_t cudnnSoftmaxBackward(cudnnHandle_t handle, cudnnSoftmaxAlgorithm_t algo, cudnnSoftmaxMode_t mode, void const * alpha, cudnnTensorDescriptor_t const yDesc, void const * y, cudnnTensorDescriptor_t const dyDesc, void const * dy, void const * beta, cudnnTensorDescriptor_t const dxDesc, void * dx){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSoftmaxBackward) (cudnnHandle_t, cudnnSoftmaxAlgorithm_t, cudnnSoftmaxMode_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnSoftmaxAlgorithm_t, cudnnSoftmaxMode_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnSoftmaxBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSoftmaxBackward", kApiTypeCuDNN);

    lretval = lcudnnSoftmaxBackward(handle, algo, mode, alpha, yDesc, y, dyDesc, dy, beta, dxDesc, dx);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSoftmaxBackward cudnnSoftmaxBackward


#undef cudnnPoolingBackward
cudnnStatus_t cudnnPoolingBackward(cudnnHandle_t handle, cudnnPoolingDescriptor_t const poolingDesc, void const * alpha, cudnnTensorDescriptor_t const yDesc, void const * y, cudnnTensorDescriptor_t const dyDesc, void const * dy, cudnnTensorDescriptor_t const xDesc, void const * x, void const * beta, cudnnTensorDescriptor_t const dxDesc, void * dx){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnPoolingBackward) (cudnnHandle_t, cudnnPoolingDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnPoolingDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnPoolingBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnPoolingBackward", kApiTypeCuDNN);

    lretval = lcudnnPoolingBackward(handle, poolingDesc, alpha, yDesc, y, dyDesc, dy, xDesc, x, beta, dxDesc, dx);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnPoolingBackward cudnnPoolingBackward


#undef cudnnActivationBackward
cudnnStatus_t cudnnActivationBackward(cudnnHandle_t handle, cudnnActivationDescriptor_t activationDesc, void const * alpha, cudnnTensorDescriptor_t const yDesc, void const * y, cudnnTensorDescriptor_t const dyDesc, void const * dy, cudnnTensorDescriptor_t const xDesc, void const * x, void const * beta, cudnnTensorDescriptor_t const dxDesc, void * dx){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnActivationBackward) (cudnnHandle_t, cudnnActivationDescriptor_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnActivationDescriptor_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnActivationBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnActivationBackward", kApiTypeCuDNN);

    lretval = lcudnnActivationBackward(handle, activationDesc, alpha, yDesc, y, dyDesc, dy, xDesc, x, beta, dxDesc, dx);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnActivationBackward cudnnActivationBackward


#undef cudnnLRNCrossChannelBackward
cudnnStatus_t cudnnLRNCrossChannelBackward(cudnnHandle_t handle, cudnnLRNDescriptor_t normDesc, cudnnLRNMode_t lrnMode, void const * alpha, cudnnTensorDescriptor_t const yDesc, void const * y, cudnnTensorDescriptor_t const dyDesc, void const * dy, cudnnTensorDescriptor_t const xDesc, void const * x, void const * beta, cudnnTensorDescriptor_t const dxDesc, void * dx){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnLRNCrossChannelBackward) (cudnnHandle_t, cudnnLRNDescriptor_t, cudnnLRNMode_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnLRNDescriptor_t, cudnnLRNMode_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnLRNCrossChannelBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnLRNCrossChannelBackward", kApiTypeCuDNN);

    lretval = lcudnnLRNCrossChannelBackward(handle, normDesc, lrnMode, alpha, yDesc, y, dyDesc, dy, xDesc, x, beta, dxDesc, dx);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnLRNCrossChannelBackward cudnnLRNCrossChannelBackward


#undef cudnnDivisiveNormalizationBackward
cudnnStatus_t cudnnDivisiveNormalizationBackward(cudnnHandle_t handle, cudnnLRNDescriptor_t normDesc, cudnnDivNormMode_t mode, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, void const * means, void const * dy, void * temp, void * temp2, void const * beta, cudnnTensorDescriptor_t const dXdMeansDesc, void * dx, void * dMeans){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDivisiveNormalizationBackward) (cudnnHandle_t, cudnnLRNDescriptor_t, cudnnDivNormMode_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, void const *, void *, void *, void const *, cudnnTensorDescriptor_t const, void *, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnLRNDescriptor_t, cudnnDivNormMode_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, void const *, void *, void *, void const *, cudnnTensorDescriptor_t const, void *, void *))dlsym(RTLD_NEXT, "cudnnDivisiveNormalizationBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDivisiveNormalizationBackward", kApiTypeCuDNN);

    lretval = lcudnnDivisiveNormalizationBackward(handle, normDesc, mode, alpha, xDesc, x, means, dy, temp, temp2, beta, dXdMeansDesc, dx, dMeans);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDivisiveNormalizationBackward cudnnDivisiveNormalizationBackward


#undef cudnnGetBatchNormalizationForwardTrainingExWorkspaceSize
cudnnStatus_t cudnnGetBatchNormalizationForwardTrainingExWorkspaceSize(cudnnHandle_t handle, cudnnBatchNormMode_t mode, cudnnBatchNormOps_t bnOps, cudnnTensorDescriptor_t const xDesc, cudnnTensorDescriptor_t const zDesc, cudnnTensorDescriptor_t const yDesc, cudnnTensorDescriptor_t const bnScaleBiasMeanVarDesc, cudnnActivationDescriptor_t const activationDesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetBatchNormalizationForwardTrainingExWorkspaceSize) (cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnActivationDescriptor_t const, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnActivationDescriptor_t const, size_t *))dlsym(RTLD_NEXT, "cudnnGetBatchNormalizationForwardTrainingExWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetBatchNormalizationForwardTrainingExWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetBatchNormalizationForwardTrainingExWorkspaceSize(handle, mode, bnOps, xDesc, zDesc, yDesc, bnScaleBiasMeanVarDesc, activationDesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetBatchNormalizationForwardTrainingExWorkspaceSize cudnnGetBatchNormalizationForwardTrainingExWorkspaceSize


#undef cudnnGetBatchNormalizationBackwardExWorkspaceSize
cudnnStatus_t cudnnGetBatchNormalizationBackwardExWorkspaceSize(cudnnHandle_t handle, cudnnBatchNormMode_t mode, cudnnBatchNormOps_t bnOps, cudnnTensorDescriptor_t const xDesc, cudnnTensorDescriptor_t const yDesc, cudnnTensorDescriptor_t const dyDesc, cudnnTensorDescriptor_t const dzDesc, cudnnTensorDescriptor_t const dxDesc, cudnnTensorDescriptor_t const dBnScaleBiasDesc, cudnnActivationDescriptor_t const activationDesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetBatchNormalizationBackwardExWorkspaceSize) (cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnActivationDescriptor_t const, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnActivationDescriptor_t const, size_t *))dlsym(RTLD_NEXT, "cudnnGetBatchNormalizationBackwardExWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetBatchNormalizationBackwardExWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetBatchNormalizationBackwardExWorkspaceSize(handle, mode, bnOps, xDesc, yDesc, dyDesc, dzDesc, dxDesc, dBnScaleBiasDesc, activationDesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetBatchNormalizationBackwardExWorkspaceSize cudnnGetBatchNormalizationBackwardExWorkspaceSize


#undef cudnnGetBatchNormalizationTrainingExReserveSpaceSize
cudnnStatus_t cudnnGetBatchNormalizationTrainingExReserveSpaceSize(cudnnHandle_t handle, cudnnBatchNormMode_t mode, cudnnBatchNormOps_t bnOps, cudnnActivationDescriptor_t const activationDesc, cudnnTensorDescriptor_t const xDesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetBatchNormalizationTrainingExReserveSpaceSize) (cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, size_t *))dlsym(RTLD_NEXT, "cudnnGetBatchNormalizationTrainingExReserveSpaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetBatchNormalizationTrainingExReserveSpaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetBatchNormalizationTrainingExReserveSpaceSize(handle, mode, bnOps, activationDesc, xDesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetBatchNormalizationTrainingExReserveSpaceSize cudnnGetBatchNormalizationTrainingExReserveSpaceSize


#undef cudnnBatchNormalizationForwardTraining
cudnnStatus_t cudnnBatchNormalizationForwardTraining(cudnnHandle_t handle, cudnnBatchNormMode_t mode, void const * alpha, void const * beta, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnTensorDescriptor_t const yDesc, void * y, cudnnTensorDescriptor_t const bnScaleBiasMeanVarDesc, void const * bnScale, void const * bnBias, double exponentialAverageFactor, void * resultRunningMean, void * resultRunningVariance, double epsilon, void * resultSaveMean, void * resultSaveInvVariance){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBatchNormalizationForwardTraining) (cudnnHandle_t, cudnnBatchNormMode_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, double, void *, void *, double, void *, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnBatchNormMode_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, double, void *, void *, double, void *, void *))dlsym(RTLD_NEXT, "cudnnBatchNormalizationForwardTraining");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBatchNormalizationForwardTraining", kApiTypeCuDNN);

    lretval = lcudnnBatchNormalizationForwardTraining(handle, mode, alpha, beta, xDesc, x, yDesc, y, bnScaleBiasMeanVarDesc, bnScale, bnBias, exponentialAverageFactor, resultRunningMean, resultRunningVariance, epsilon, resultSaveMean, resultSaveInvVariance);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBatchNormalizationForwardTraining cudnnBatchNormalizationForwardTraining


#undef cudnnBatchNormalizationForwardTrainingEx
cudnnStatus_t cudnnBatchNormalizationForwardTrainingEx(cudnnHandle_t handle, cudnnBatchNormMode_t mode, cudnnBatchNormOps_t bnOps, void const * alpha, void const * beta, cudnnTensorDescriptor_t const xDesc, void const * xData, cudnnTensorDescriptor_t const zDesc, void const * zData, cudnnTensorDescriptor_t const yDesc, void * yData, cudnnTensorDescriptor_t const bnScaleBiasMeanVarDesc, void const * bnScale, void const * bnBias, double exponentialAverageFactor, void * resultRunningMean, void * resultRunningVariance, double epsilon, void * resultSaveMean, void * resultSaveInvVariance, cudnnActivationDescriptor_t activationDesc, void * workspace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBatchNormalizationForwardTrainingEx) (cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, double, void *, void *, double, void *, void *, cudnnActivationDescriptor_t, void *, size_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, double, void *, void *, double, void *, void *, cudnnActivationDescriptor_t, void *, size_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnBatchNormalizationForwardTrainingEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBatchNormalizationForwardTrainingEx", kApiTypeCuDNN);

    lretval = lcudnnBatchNormalizationForwardTrainingEx(handle, mode, bnOps, alpha, beta, xDesc, xData, zDesc, zData, yDesc, yData, bnScaleBiasMeanVarDesc, bnScale, bnBias, exponentialAverageFactor, resultRunningMean, resultRunningVariance, epsilon, resultSaveMean, resultSaveInvVariance, activationDesc, workspace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBatchNormalizationForwardTrainingEx cudnnBatchNormalizationForwardTrainingEx


#undef cudnnBatchNormalizationBackward
cudnnStatus_t cudnnBatchNormalizationBackward(cudnnHandle_t handle, cudnnBatchNormMode_t mode, void const * alphaDataDiff, void const * betaDataDiff, void const * alphaParamDiff, void const * betaParamDiff, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnTensorDescriptor_t const dyDesc, void const * dy, cudnnTensorDescriptor_t const dxDesc, void * dx, cudnnTensorDescriptor_t const dBnScaleBiasDesc, void const * bnScale, void * dBnScaleResult, void * dBnBiasResult, double epsilon, void const * savedMean, void const * savedInvVariance){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBatchNormalizationBackward) (cudnnHandle_t, cudnnBatchNormMode_t, void const *, void const *, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void *, void *, double, void const *, void const *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnBatchNormMode_t, void const *, void const *, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void *, void *, double, void const *, void const *))dlsym(RTLD_NEXT, "cudnnBatchNormalizationBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBatchNormalizationBackward", kApiTypeCuDNN);

    lretval = lcudnnBatchNormalizationBackward(handle, mode, alphaDataDiff, betaDataDiff, alphaParamDiff, betaParamDiff, xDesc, x, dyDesc, dy, dxDesc, dx, dBnScaleBiasDesc, bnScale, dBnScaleResult, dBnBiasResult, epsilon, savedMean, savedInvVariance);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBatchNormalizationBackward cudnnBatchNormalizationBackward


#undef cudnnBatchNormalizationBackwardEx
cudnnStatus_t cudnnBatchNormalizationBackwardEx(cudnnHandle_t handle, cudnnBatchNormMode_t mode, cudnnBatchNormOps_t bnOps, void const * alphaDataDiff, void const * betaDataDiff, void const * alphaParamDiff, void const * betaParamDiff, cudnnTensorDescriptor_t const xDesc, void const * xData, cudnnTensorDescriptor_t const yDesc, void const * yData, cudnnTensorDescriptor_t const dyDesc, void const * dyData, cudnnTensorDescriptor_t const dzDesc, void * dzData, cudnnTensorDescriptor_t const dxDesc, void * dxData, cudnnTensorDescriptor_t const dBnScaleBiasDesc, void const * bnScaleData, void const * bnBiasData, void * dBnScaleData, void * dBnBiasData, double epsilon, void const * savedMean, void const * savedInvVariance, cudnnActivationDescriptor_t activationDesc, void * workSpace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBatchNormalizationBackwardEx) (cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, void const *, void const *, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, void *, void *, double, void const *, void const *, cudnnActivationDescriptor_t, void *, size_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnBatchNormMode_t, cudnnBatchNormOps_t, void const *, void const *, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, void *, void *, double, void const *, void const *, cudnnActivationDescriptor_t, void *, size_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnBatchNormalizationBackwardEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBatchNormalizationBackwardEx", kApiTypeCuDNN);

    lretval = lcudnnBatchNormalizationBackwardEx(handle, mode, bnOps, alphaDataDiff, betaDataDiff, alphaParamDiff, betaParamDiff, xDesc, xData, yDesc, yData, dyDesc, dyData, dzDesc, dzData, dxDesc, dxData, dBnScaleBiasDesc, bnScaleData, bnBiasData, dBnScaleData, dBnBiasData, epsilon, savedMean, savedInvVariance, activationDesc, workSpace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBatchNormalizationBackwardEx cudnnBatchNormalizationBackwardEx


#undef cudnnGetNormalizationForwardTrainingWorkspaceSize
cudnnStatus_t cudnnGetNormalizationForwardTrainingWorkspaceSize(cudnnHandle_t handle, cudnnNormMode_t mode, cudnnNormOps_t normOps, cudnnNormAlgo_t algo, cudnnTensorDescriptor_t const xDesc, cudnnTensorDescriptor_t const zDesc, cudnnTensorDescriptor_t const yDesc, cudnnTensorDescriptor_t const normScaleBiasDesc, cudnnActivationDescriptor_t const activationDesc, cudnnTensorDescriptor_t const normMeanVarDesc, size_t * sizeInBytes, int groupCnt){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetNormalizationForwardTrainingWorkspaceSize) (cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, size_t *, int) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, size_t *, int))dlsym(RTLD_NEXT, "cudnnGetNormalizationForwardTrainingWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetNormalizationForwardTrainingWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetNormalizationForwardTrainingWorkspaceSize(handle, mode, normOps, algo, xDesc, zDesc, yDesc, normScaleBiasDesc, activationDesc, normMeanVarDesc, sizeInBytes, groupCnt);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetNormalizationForwardTrainingWorkspaceSize cudnnGetNormalizationForwardTrainingWorkspaceSize


#undef cudnnGetNormalizationBackwardWorkspaceSize
cudnnStatus_t cudnnGetNormalizationBackwardWorkspaceSize(cudnnHandle_t handle, cudnnNormMode_t mode, cudnnNormOps_t normOps, cudnnNormAlgo_t algo, cudnnTensorDescriptor_t const xDesc, cudnnTensorDescriptor_t const yDesc, cudnnTensorDescriptor_t const dyDesc, cudnnTensorDescriptor_t const dzDesc, cudnnTensorDescriptor_t const dxDesc, cudnnTensorDescriptor_t const dNormScaleBiasDesc, cudnnActivationDescriptor_t const activationDesc, cudnnTensorDescriptor_t const normMeanVarDesc, size_t * sizeInBytes, int groupCnt){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetNormalizationBackwardWorkspaceSize) (cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, size_t *, int) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, size_t *, int))dlsym(RTLD_NEXT, "cudnnGetNormalizationBackwardWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetNormalizationBackwardWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetNormalizationBackwardWorkspaceSize(handle, mode, normOps, algo, xDesc, yDesc, dyDesc, dzDesc, dxDesc, dNormScaleBiasDesc, activationDesc, normMeanVarDesc, sizeInBytes, groupCnt);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetNormalizationBackwardWorkspaceSize cudnnGetNormalizationBackwardWorkspaceSize


#undef cudnnGetNormalizationTrainingReserveSpaceSize
cudnnStatus_t cudnnGetNormalizationTrainingReserveSpaceSize(cudnnHandle_t handle, cudnnNormMode_t mode, cudnnNormOps_t normOps, cudnnNormAlgo_t algo, cudnnActivationDescriptor_t const activationDesc, cudnnTensorDescriptor_t const xDesc, size_t * sizeInBytes, int groupCnt){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetNormalizationTrainingReserveSpaceSize) (cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, size_t *, int) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, size_t *, int))dlsym(RTLD_NEXT, "cudnnGetNormalizationTrainingReserveSpaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetNormalizationTrainingReserveSpaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetNormalizationTrainingReserveSpaceSize(handle, mode, normOps, algo, activationDesc, xDesc, sizeInBytes, groupCnt);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetNormalizationTrainingReserveSpaceSize cudnnGetNormalizationTrainingReserveSpaceSize


#undef cudnnNormalizationForwardTraining
cudnnStatus_t cudnnNormalizationForwardTraining(cudnnHandle_t handle, cudnnNormMode_t mode, cudnnNormOps_t normOps, cudnnNormAlgo_t algo, void const * alpha, void const * beta, cudnnTensorDescriptor_t const xDesc, void const * xData, cudnnTensorDescriptor_t const normScaleBiasDesc, void const * normScale, void const * normBias, double exponentialAverageFactor, cudnnTensorDescriptor_t const normMeanVarDesc, void * resultRunningMean, void * resultRunningVariance, double epsilon, void * resultSaveMean, void * resultSaveInvVariance, cudnnActivationDescriptor_t activationDesc, cudnnTensorDescriptor_t const zDesc, void const * zData, cudnnTensorDescriptor_t const yDesc, void * yData, void * workspace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes, int groupCnt){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnNormalizationForwardTraining) (cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, double, cudnnTensorDescriptor_t const, void *, void *, double, void *, void *, cudnnActivationDescriptor_t, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, void *, size_t, void *, size_t, int) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, void const *, double, cudnnTensorDescriptor_t const, void *, void *, double, void *, void *, cudnnActivationDescriptor_t, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, void *, size_t, void *, size_t, int))dlsym(RTLD_NEXT, "cudnnNormalizationForwardTraining");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnNormalizationForwardTraining", kApiTypeCuDNN);

    lretval = lcudnnNormalizationForwardTraining(handle, mode, normOps, algo, alpha, beta, xDesc, xData, normScaleBiasDesc, normScale, normBias, exponentialAverageFactor, normMeanVarDesc, resultRunningMean, resultRunningVariance, epsilon, resultSaveMean, resultSaveInvVariance, activationDesc, zDesc, zData, yDesc, yData, workspace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes, groupCnt);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnNormalizationForwardTraining cudnnNormalizationForwardTraining


#undef cudnnNormalizationBackward
cudnnStatus_t cudnnNormalizationBackward(cudnnHandle_t handle, cudnnNormMode_t mode, cudnnNormOps_t normOps, cudnnNormAlgo_t algo, void const * alphaDataDiff, void const * betaDataDiff, void const * alphaParamDiff, void const * betaParamDiff, cudnnTensorDescriptor_t const xDesc, void const * xData, cudnnTensorDescriptor_t const yDesc, void const * yData, cudnnTensorDescriptor_t const dyDesc, void const * dyData, cudnnTensorDescriptor_t const dzDesc, void * dzData, cudnnTensorDescriptor_t const dxDesc, void * dxData, cudnnTensorDescriptor_t const dNormScaleBiasDesc, void const * normScaleData, void const * normBiasData, void * dNormScaleData, void * dNormBiasData, double epsilon, cudnnTensorDescriptor_t const normMeanVarDesc, void const * savedMean, void const * savedInvVariance, cudnnActivationDescriptor_t activationDesc, void * workSpace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes, int groupCnt){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnNormalizationBackward) (cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, void const *, void const *, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, void *, void *, double, cudnnTensorDescriptor_t const, void const *, void const *, cudnnActivationDescriptor_t, void *, size_t, void *, size_t, int) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnNormMode_t, cudnnNormOps_t, cudnnNormAlgo_t, void const *, void const *, void const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void const *, void const *, void *, void *, double, cudnnTensorDescriptor_t const, void const *, void const *, cudnnActivationDescriptor_t, void *, size_t, void *, size_t, int))dlsym(RTLD_NEXT, "cudnnNormalizationBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnNormalizationBackward", kApiTypeCuDNN);

    lretval = lcudnnNormalizationBackward(handle, mode, normOps, algo, alphaDataDiff, betaDataDiff, alphaParamDiff, betaParamDiff, xDesc, xData, yDesc, yData, dyDesc, dyData, dzDesc, dzData, dxDesc, dxData, dNormScaleBiasDesc, normScaleData, normBiasData, dNormScaleData, dNormBiasData, epsilon, normMeanVarDesc, savedMean, savedInvVariance, activationDesc, workSpace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes, groupCnt);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnNormalizationBackward cudnnNormalizationBackward


#undef cudnnSpatialTfGridGeneratorBackward
cudnnStatus_t cudnnSpatialTfGridGeneratorBackward(cudnnHandle_t handle, cudnnSpatialTransformerDescriptor_t const stDesc, void const * dgrid, void * dtheta){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSpatialTfGridGeneratorBackward) (cudnnHandle_t, cudnnSpatialTransformerDescriptor_t const, void const *, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnSpatialTransformerDescriptor_t const, void const *, void *))dlsym(RTLD_NEXT, "cudnnSpatialTfGridGeneratorBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSpatialTfGridGeneratorBackward", kApiTypeCuDNN);

    lretval = lcudnnSpatialTfGridGeneratorBackward(handle, stDesc, dgrid, dtheta);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSpatialTfGridGeneratorBackward cudnnSpatialTfGridGeneratorBackward


#undef cudnnSpatialTfSamplerBackward
cudnnStatus_t cudnnSpatialTfSamplerBackward(cudnnHandle_t handle, cudnnSpatialTransformerDescriptor_t stDesc, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, void const * beta, cudnnTensorDescriptor_t const dxDesc, void * dx, void const * alphaDgrid, cudnnTensorDescriptor_t const dyDesc, void const * dy, void const * grid, void const * betaDgrid, void * dgrid){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSpatialTfSamplerBackward) (cudnnHandle_t, cudnnSpatialTransformerDescriptor_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *, void const *, cudnnTensorDescriptor_t const, void const *, void const *, void const *, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnSpatialTransformerDescriptor_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *, void const *, cudnnTensorDescriptor_t const, void const *, void const *, void const *, void *))dlsym(RTLD_NEXT, "cudnnSpatialTfSamplerBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSpatialTfSamplerBackward", kApiTypeCuDNN);

    lretval = lcudnnSpatialTfSamplerBackward(handle, stDesc, alpha, xDesc, x, beta, dxDesc, dx, alphaDgrid, dyDesc, dy, grid, betaDgrid, dgrid);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSpatialTfSamplerBackward cudnnSpatialTfSamplerBackward


#undef cudnnDropoutBackward
cudnnStatus_t cudnnDropoutBackward(cudnnHandle_t handle, cudnnDropoutDescriptor_t const dropoutDesc, cudnnTensorDescriptor_t const dydesc, void const * dy, cudnnTensorDescriptor_t const dxdesc, void * dx, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDropoutBackward) (cudnnHandle_t, cudnnDropoutDescriptor_t const, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnDropoutDescriptor_t const, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void *, void *, size_t))dlsym(RTLD_NEXT, "cudnnDropoutBackward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDropoutBackward", kApiTypeCuDNN);

    lretval = lcudnnDropoutBackward(handle, dropoutDesc, dydesc, dy, dxdesc, dx, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDropoutBackward cudnnDropoutBackward


#undef cudnnOpsTrainVersionCheck
cudnnStatus_t cudnnOpsTrainVersionCheck(){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnOpsTrainVersionCheck) () = (cudnnStatus_t (*)())dlsym(RTLD_NEXT, "cudnnOpsTrainVersionCheck");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnOpsTrainVersionCheck", kApiTypeCuDNN);

    lretval = lcudnnOpsTrainVersionCheck();
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnOpsTrainVersionCheck cudnnOpsTrainVersionCheck


#undef cudnnCreateRNNDescriptor
cudnnStatus_t cudnnCreateRNNDescriptor(cudnnRNNDescriptor_t * rnnDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateRNNDescriptor) (cudnnRNNDescriptor_t *) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateRNNDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateRNNDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateRNNDescriptor(rnnDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateRNNDescriptor cudnnCreateRNNDescriptor


#undef cudnnDestroyRNNDescriptor
cudnnStatus_t cudnnDestroyRNNDescriptor(cudnnRNNDescriptor_t rnnDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyRNNDescriptor) (cudnnRNNDescriptor_t) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyRNNDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyRNNDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyRNNDescriptor(rnnDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyRNNDescriptor cudnnDestroyRNNDescriptor


#undef cudnnSetRNNDescriptor_v8
cudnnStatus_t cudnnSetRNNDescriptor_v8(cudnnRNNDescriptor_t rnnDesc, cudnnRNNAlgo_t algo, cudnnRNNMode_t cellMode, cudnnRNNBiasMode_t biasMode, cudnnDirectionMode_t dirMode, cudnnRNNInputMode_t inputMode, cudnnDataType_t dataType, cudnnDataType_t mathPrec, cudnnMathType_t mathType, int32_t inputSize, int32_t hiddenSize, int32_t projSize, int32_t numLayers, cudnnDropoutDescriptor_t dropoutDesc, uint32_t auxFlags){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetRNNDescriptor_v8) (cudnnRNNDescriptor_t, cudnnRNNAlgo_t, cudnnRNNMode_t, cudnnRNNBiasMode_t, cudnnDirectionMode_t, cudnnRNNInputMode_t, cudnnDataType_t, cudnnDataType_t, cudnnMathType_t, int32_t, int32_t, int32_t, int32_t, cudnnDropoutDescriptor_t, uint32_t) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, cudnnRNNAlgo_t, cudnnRNNMode_t, cudnnRNNBiasMode_t, cudnnDirectionMode_t, cudnnRNNInputMode_t, cudnnDataType_t, cudnnDataType_t, cudnnMathType_t, int32_t, int32_t, int32_t, int32_t, cudnnDropoutDescriptor_t, uint32_t))dlsym(RTLD_NEXT, "cudnnSetRNNDescriptor_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetRNNDescriptor_v8", kApiTypeCuDNN);

    lretval = lcudnnSetRNNDescriptor_v8(rnnDesc, algo, cellMode, biasMode, dirMode, inputMode, dataType, mathPrec, mathType, inputSize, hiddenSize, projSize, numLayers, dropoutDesc, auxFlags);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetRNNDescriptor_v8 cudnnSetRNNDescriptor_v8


#undef cudnnGetRNNDescriptor_v8
cudnnStatus_t cudnnGetRNNDescriptor_v8(cudnnRNNDescriptor_t rnnDesc, cudnnRNNAlgo_t * algo, cudnnRNNMode_t * cellMode, cudnnRNNBiasMode_t * biasMode, cudnnDirectionMode_t * dirMode, cudnnRNNInputMode_t * inputMode, cudnnDataType_t * dataType, cudnnDataType_t * mathPrec, cudnnMathType_t * mathType, int32_t * inputSize, int32_t * hiddenSize, int32_t * projSize, int32_t * numLayers, cudnnDropoutDescriptor_t * dropoutDesc, uint32_t * auxFlags){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNDescriptor_v8) (cudnnRNNDescriptor_t, cudnnRNNAlgo_t *, cudnnRNNMode_t *, cudnnRNNBiasMode_t *, cudnnDirectionMode_t *, cudnnRNNInputMode_t *, cudnnDataType_t *, cudnnDataType_t *, cudnnMathType_t *, int32_t *, int32_t *, int32_t *, int32_t *, cudnnDropoutDescriptor_t *, uint32_t *) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, cudnnRNNAlgo_t *, cudnnRNNMode_t *, cudnnRNNBiasMode_t *, cudnnDirectionMode_t *, cudnnRNNInputMode_t *, cudnnDataType_t *, cudnnDataType_t *, cudnnMathType_t *, int32_t *, int32_t *, int32_t *, int32_t *, cudnnDropoutDescriptor_t *, uint32_t *))dlsym(RTLD_NEXT, "cudnnGetRNNDescriptor_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNDescriptor_v8", kApiTypeCuDNN);

    lretval = lcudnnGetRNNDescriptor_v8(rnnDesc, algo, cellMode, biasMode, dirMode, inputMode, dataType, mathPrec, mathType, inputSize, hiddenSize, projSize, numLayers, dropoutDesc, auxFlags);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNDescriptor_v8 cudnnGetRNNDescriptor_v8


#undef cudnnSetRNNDescriptor_v6
cudnnStatus_t cudnnSetRNNDescriptor_v6(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, int const hiddenSize, int const numLayers, cudnnDropoutDescriptor_t dropoutDesc, cudnnRNNInputMode_t inputMode, cudnnDirectionMode_t direction, cudnnRNNMode_t cellMode, cudnnRNNAlgo_t algo, cudnnDataType_t mathPrec){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetRNNDescriptor_v6) (cudnnHandle_t, cudnnRNNDescriptor_t, int const, int const, cudnnDropoutDescriptor_t, cudnnRNNInputMode_t, cudnnDirectionMode_t, cudnnRNNMode_t, cudnnRNNAlgo_t, cudnnDataType_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, int const, int const, cudnnDropoutDescriptor_t, cudnnRNNInputMode_t, cudnnDirectionMode_t, cudnnRNNMode_t, cudnnRNNAlgo_t, cudnnDataType_t))dlsym(RTLD_NEXT, "cudnnSetRNNDescriptor_v6");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetRNNDescriptor_v6", kApiTypeCuDNN);

    lretval = lcudnnSetRNNDescriptor_v6(handle, rnnDesc, hiddenSize, numLayers, dropoutDesc, inputMode, direction, cellMode, algo, mathPrec);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetRNNDescriptor_v6 cudnnSetRNNDescriptor_v6


#undef cudnnGetRNNDescriptor_v6
cudnnStatus_t cudnnGetRNNDescriptor_v6(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, int * hiddenSize, int * numLayers, cudnnDropoutDescriptor_t * dropoutDesc, cudnnRNNInputMode_t * inputMode, cudnnDirectionMode_t * direction, cudnnRNNMode_t * cellMode, cudnnRNNAlgo_t * algo, cudnnDataType_t * mathPrec){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNDescriptor_v6) (cudnnHandle_t, cudnnRNNDescriptor_t, int *, int *, cudnnDropoutDescriptor_t *, cudnnRNNInputMode_t *, cudnnDirectionMode_t *, cudnnRNNMode_t *, cudnnRNNAlgo_t *, cudnnDataType_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, int *, int *, cudnnDropoutDescriptor_t *, cudnnRNNInputMode_t *, cudnnDirectionMode_t *, cudnnRNNMode_t *, cudnnRNNAlgo_t *, cudnnDataType_t *))dlsym(RTLD_NEXT, "cudnnGetRNNDescriptor_v6");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNDescriptor_v6", kApiTypeCuDNN);

    lretval = lcudnnGetRNNDescriptor_v6(handle, rnnDesc, hiddenSize, numLayers, dropoutDesc, inputMode, direction, cellMode, algo, mathPrec);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNDescriptor_v6 cudnnGetRNNDescriptor_v6


#undef cudnnSetRNNMatrixMathType
cudnnStatus_t cudnnSetRNNMatrixMathType(cudnnRNNDescriptor_t rnnDesc, cudnnMathType_t mType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetRNNMatrixMathType) (cudnnRNNDescriptor_t, cudnnMathType_t) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, cudnnMathType_t))dlsym(RTLD_NEXT, "cudnnSetRNNMatrixMathType");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetRNNMatrixMathType", kApiTypeCuDNN);

    lretval = lcudnnSetRNNMatrixMathType(rnnDesc, mType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetRNNMatrixMathType cudnnSetRNNMatrixMathType


#undef cudnnGetRNNMatrixMathType
cudnnStatus_t cudnnGetRNNMatrixMathType(cudnnRNNDescriptor_t rnnDesc, cudnnMathType_t * mType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNMatrixMathType) (cudnnRNNDescriptor_t, cudnnMathType_t *) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, cudnnMathType_t *))dlsym(RTLD_NEXT, "cudnnGetRNNMatrixMathType");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNMatrixMathType", kApiTypeCuDNN);

    lretval = lcudnnGetRNNMatrixMathType(rnnDesc, mType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNMatrixMathType cudnnGetRNNMatrixMathType


#undef cudnnSetRNNBiasMode
cudnnStatus_t cudnnSetRNNBiasMode(cudnnRNNDescriptor_t rnnDesc, cudnnRNNBiasMode_t biasMode){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetRNNBiasMode) (cudnnRNNDescriptor_t, cudnnRNNBiasMode_t) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, cudnnRNNBiasMode_t))dlsym(RTLD_NEXT, "cudnnSetRNNBiasMode");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetRNNBiasMode", kApiTypeCuDNN);

    lretval = lcudnnSetRNNBiasMode(rnnDesc, biasMode);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetRNNBiasMode cudnnSetRNNBiasMode


#undef cudnnGetRNNBiasMode
cudnnStatus_t cudnnGetRNNBiasMode(cudnnRNNDescriptor_t rnnDesc, cudnnRNNBiasMode_t * biasMode){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNBiasMode) (cudnnRNNDescriptor_t, cudnnRNNBiasMode_t *) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, cudnnRNNBiasMode_t *))dlsym(RTLD_NEXT, "cudnnGetRNNBiasMode");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNBiasMode", kApiTypeCuDNN);

    lretval = lcudnnGetRNNBiasMode(rnnDesc, biasMode);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNBiasMode cudnnGetRNNBiasMode


#undef cudnnRNNSetClip_v8
cudnnStatus_t cudnnRNNSetClip_v8(cudnnRNNDescriptor_t rnnDesc, cudnnRNNClipMode_t clipMode, cudnnNanPropagation_t clipNanOpt, double lclip, double rclip){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNSetClip_v8) (cudnnRNNDescriptor_t, cudnnRNNClipMode_t, cudnnNanPropagation_t, double, double) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, cudnnRNNClipMode_t, cudnnNanPropagation_t, double, double))dlsym(RTLD_NEXT, "cudnnRNNSetClip_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNSetClip_v8", kApiTypeCuDNN);

    lretval = lcudnnRNNSetClip_v8(rnnDesc, clipMode, clipNanOpt, lclip, rclip);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNSetClip_v8 cudnnRNNSetClip_v8


#undef cudnnRNNGetClip_v8
cudnnStatus_t cudnnRNNGetClip_v8(cudnnRNNDescriptor_t rnnDesc, cudnnRNNClipMode_t * clipMode, cudnnNanPropagation_t * clipNanOpt, double * lclip, double * rclip){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNGetClip_v8) (cudnnRNNDescriptor_t, cudnnRNNClipMode_t *, cudnnNanPropagation_t *, double *, double *) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, cudnnRNNClipMode_t *, cudnnNanPropagation_t *, double *, double *))dlsym(RTLD_NEXT, "cudnnRNNGetClip_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNGetClip_v8", kApiTypeCuDNN);

    lretval = lcudnnRNNGetClip_v8(rnnDesc, clipMode, clipNanOpt, lclip, rclip);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNGetClip_v8 cudnnRNNGetClip_v8


#undef cudnnRNNSetClip
cudnnStatus_t cudnnRNNSetClip(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, cudnnRNNClipMode_t clipMode, cudnnNanPropagation_t clipNanOpt, double lclip, double rclip){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNSetClip) (cudnnHandle_t, cudnnRNNDescriptor_t, cudnnRNNClipMode_t, cudnnNanPropagation_t, double, double) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, cudnnRNNClipMode_t, cudnnNanPropagation_t, double, double))dlsym(RTLD_NEXT, "cudnnRNNSetClip");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNSetClip", kApiTypeCuDNN);

    lretval = lcudnnRNNSetClip(handle, rnnDesc, clipMode, clipNanOpt, lclip, rclip);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNSetClip cudnnRNNSetClip


#undef cudnnRNNGetClip
cudnnStatus_t cudnnRNNGetClip(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, cudnnRNNClipMode_t * clipMode, cudnnNanPropagation_t * clipNanOpt, double * lclip, double * rclip){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNGetClip) (cudnnHandle_t, cudnnRNNDescriptor_t, cudnnRNNClipMode_t *, cudnnNanPropagation_t *, double *, double *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, cudnnRNNClipMode_t *, cudnnNanPropagation_t *, double *, double *))dlsym(RTLD_NEXT, "cudnnRNNGetClip");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNGetClip", kApiTypeCuDNN);

    lretval = lcudnnRNNGetClip(handle, rnnDesc, clipMode, clipNanOpt, lclip, rclip);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNGetClip cudnnRNNGetClip


#undef cudnnSetRNNProjectionLayers
cudnnStatus_t cudnnSetRNNProjectionLayers(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, int const recProjSize, int const outProjSize){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetRNNProjectionLayers) (cudnnHandle_t, cudnnRNNDescriptor_t, int const, int const) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, int const, int const))dlsym(RTLD_NEXT, "cudnnSetRNNProjectionLayers");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetRNNProjectionLayers", kApiTypeCuDNN);

    lretval = lcudnnSetRNNProjectionLayers(handle, rnnDesc, recProjSize, outProjSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetRNNProjectionLayers cudnnSetRNNProjectionLayers


#undef cudnnGetRNNProjectionLayers
cudnnStatus_t cudnnGetRNNProjectionLayers(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int * recProjSize, int * outProjSize){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNProjectionLayers) (cudnnHandle_t, cudnnRNNDescriptor_t const, int *, int *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int *, int *))dlsym(RTLD_NEXT, "cudnnGetRNNProjectionLayers");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNProjectionLayers", kApiTypeCuDNN);

    lretval = lcudnnGetRNNProjectionLayers(handle, rnnDesc, recProjSize, outProjSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNProjectionLayers cudnnGetRNNProjectionLayers


#undef cudnnCreatePersistentRNNPlan
cudnnStatus_t cudnnCreatePersistentRNNPlan(cudnnRNNDescriptor_t rnnDesc, int const minibatch, cudnnDataType_t const dataType, cudnnPersistentRNNPlan_t * plan){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreatePersistentRNNPlan) (cudnnRNNDescriptor_t, int const, cudnnDataType_t const, cudnnPersistentRNNPlan_t *) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, int const, cudnnDataType_t const, cudnnPersistentRNNPlan_t *))dlsym(RTLD_NEXT, "cudnnCreatePersistentRNNPlan");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreatePersistentRNNPlan", kApiTypeCuDNN);

    lretval = lcudnnCreatePersistentRNNPlan(rnnDesc, minibatch, dataType, plan);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreatePersistentRNNPlan cudnnCreatePersistentRNNPlan


#undef cudnnDestroyPersistentRNNPlan
cudnnStatus_t cudnnDestroyPersistentRNNPlan(cudnnPersistentRNNPlan_t plan){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyPersistentRNNPlan) (cudnnPersistentRNNPlan_t) = (cudnnStatus_t (*)(cudnnPersistentRNNPlan_t))dlsym(RTLD_NEXT, "cudnnDestroyPersistentRNNPlan");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyPersistentRNNPlan", kApiTypeCuDNN);

    lretval = lcudnnDestroyPersistentRNNPlan(plan);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyPersistentRNNPlan cudnnDestroyPersistentRNNPlan


#undef cudnnSetPersistentRNNPlan
cudnnStatus_t cudnnSetPersistentRNNPlan(cudnnRNNDescriptor_t rnnDesc, cudnnPersistentRNNPlan_t plan){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetPersistentRNNPlan) (cudnnRNNDescriptor_t, cudnnPersistentRNNPlan_t) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, cudnnPersistentRNNPlan_t))dlsym(RTLD_NEXT, "cudnnSetPersistentRNNPlan");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetPersistentRNNPlan", kApiTypeCuDNN);

    lretval = lcudnnSetPersistentRNNPlan(rnnDesc, plan);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetPersistentRNNPlan cudnnSetPersistentRNNPlan


#undef cudnnBuildRNNDynamic
cudnnStatus_t cudnnBuildRNNDynamic(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, int miniBatch){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBuildRNNDynamic) (cudnnHandle_t, cudnnRNNDescriptor_t, int) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, int))dlsym(RTLD_NEXT, "cudnnBuildRNNDynamic");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBuildRNNDynamic", kApiTypeCuDNN);

    lretval = lcudnnBuildRNNDynamic(handle, rnnDesc, miniBatch);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBuildRNNDynamic cudnnBuildRNNDynamic


#undef cudnnGetRNNWorkspaceSize
cudnnStatus_t cudnnGetRNNWorkspaceSize(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * xDesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNWorkspaceSize) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, size_t *))dlsym(RTLD_NEXT, "cudnnGetRNNWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetRNNWorkspaceSize(handle, rnnDesc, seqLength, xDesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNWorkspaceSize cudnnGetRNNWorkspaceSize


#undef cudnnGetRNNTrainingReserveSize
cudnnStatus_t cudnnGetRNNTrainingReserveSize(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * xDesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNTrainingReserveSize) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, size_t *))dlsym(RTLD_NEXT, "cudnnGetRNNTrainingReserveSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNTrainingReserveSize", kApiTypeCuDNN);

    lretval = lcudnnGetRNNTrainingReserveSize(handle, rnnDesc, seqLength, xDesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNTrainingReserveSize cudnnGetRNNTrainingReserveSize


#undef cudnnGetRNNTempSpaceSizes
cudnnStatus_t cudnnGetRNNTempSpaceSizes(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, cudnnForwardMode_t fMode, cudnnRNNDataDescriptor_t xDesc, size_t * workSpaceSize, size_t * reserveSpaceSize){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNTempSpaceSizes) (cudnnHandle_t, cudnnRNNDescriptor_t, cudnnForwardMode_t, cudnnRNNDataDescriptor_t, size_t *, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, cudnnForwardMode_t, cudnnRNNDataDescriptor_t, size_t *, size_t *))dlsym(RTLD_NEXT, "cudnnGetRNNTempSpaceSizes");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNTempSpaceSizes", kApiTypeCuDNN);

    lretval = lcudnnGetRNNTempSpaceSizes(handle, rnnDesc, fMode, xDesc, workSpaceSize, reserveSpaceSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNTempSpaceSizes cudnnGetRNNTempSpaceSizes


#undef cudnnGetRNNParamsSize
cudnnStatus_t cudnnGetRNNParamsSize(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, cudnnTensorDescriptor_t const xDesc, size_t * sizeInBytes, cudnnDataType_t dataType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNParamsSize) (cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnTensorDescriptor_t const, size_t *, cudnnDataType_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnTensorDescriptor_t const, size_t *, cudnnDataType_t))dlsym(RTLD_NEXT, "cudnnGetRNNParamsSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNParamsSize", kApiTypeCuDNN);

    lretval = lcudnnGetRNNParamsSize(handle, rnnDesc, xDesc, sizeInBytes, dataType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNParamsSize cudnnGetRNNParamsSize


#undef cudnnGetRNNWeightSpaceSize
cudnnStatus_t cudnnGetRNNWeightSpaceSize(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, size_t * weightSpaceSize){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNWeightSpaceSize) (cudnnHandle_t, cudnnRNNDescriptor_t, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, size_t *))dlsym(RTLD_NEXT, "cudnnGetRNNWeightSpaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNWeightSpaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetRNNWeightSpaceSize(handle, rnnDesc, weightSpaceSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNWeightSpaceSize cudnnGetRNNWeightSpaceSize


#undef cudnnGetRNNLinLayerMatrixParams
cudnnStatus_t cudnnGetRNNLinLayerMatrixParams(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const pseudoLayer, cudnnTensorDescriptor_t const xDesc, cudnnFilterDescriptor_t const wDesc, void const * w, int const linLayerID, cudnnFilterDescriptor_t linLayerMatDesc, void * * linLayerMat){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNLinLayerMatrixParams) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, void const *, int const, cudnnFilterDescriptor_t, void * *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, void const *, int const, cudnnFilterDescriptor_t, void * *))dlsym(RTLD_NEXT, "cudnnGetRNNLinLayerMatrixParams");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNLinLayerMatrixParams", kApiTypeCuDNN);

    lretval = lcudnnGetRNNLinLayerMatrixParams(handle, rnnDesc, pseudoLayer, xDesc, wDesc, w, linLayerID, linLayerMatDesc, linLayerMat);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNLinLayerMatrixParams cudnnGetRNNLinLayerMatrixParams


#undef cudnnGetRNNLinLayerBiasParams
cudnnStatus_t cudnnGetRNNLinLayerBiasParams(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const pseudoLayer, cudnnTensorDescriptor_t const xDesc, cudnnFilterDescriptor_t const wDesc, void const * w, int const linLayerID, cudnnFilterDescriptor_t linLayerBiasDesc, void * * linLayerBias){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNLinLayerBiasParams) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, void const *, int const, cudnnFilterDescriptor_t, void * *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, void const *, int const, cudnnFilterDescriptor_t, void * *))dlsym(RTLD_NEXT, "cudnnGetRNNLinLayerBiasParams");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNLinLayerBiasParams", kApiTypeCuDNN);

    lretval = lcudnnGetRNNLinLayerBiasParams(handle, rnnDesc, pseudoLayer, xDesc, wDesc, w, linLayerID, linLayerBiasDesc, linLayerBias);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNLinLayerBiasParams cudnnGetRNNLinLayerBiasParams


#undef cudnnGetRNNWeightParams
cudnnStatus_t cudnnGetRNNWeightParams(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, int32_t pseudoLayer, size_t weightSpaceSize, void const * weightSpace, int32_t linLayerID, cudnnTensorDescriptor_t mDesc, void * * mAddr, cudnnTensorDescriptor_t bDesc, void * * bAddr){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNWeightParams) (cudnnHandle_t, cudnnRNNDescriptor_t, int32_t, size_t, void const *, int32_t, cudnnTensorDescriptor_t, void * *, cudnnTensorDescriptor_t, void * *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, int32_t, size_t, void const *, int32_t, cudnnTensorDescriptor_t, void * *, cudnnTensorDescriptor_t, void * *))dlsym(RTLD_NEXT, "cudnnGetRNNWeightParams");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNWeightParams", kApiTypeCuDNN);

    lretval = lcudnnGetRNNWeightParams(handle, rnnDesc, pseudoLayer, weightSpaceSize, weightSpace, linLayerID, mDesc, mAddr, bDesc, bAddr);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNWeightParams cudnnGetRNNWeightParams


#undef cudnnRNNForwardInference
cudnnStatus_t cudnnRNNForwardInference(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * xDesc, void const * x, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const cxDesc, void const * cx, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnTensorDescriptor_t const * yDesc, void * y, cudnnTensorDescriptor_t const hyDesc, void * hy, cudnnTensorDescriptor_t const cyDesc, void * cy, void * workSpace, size_t workSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNForwardInference) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, void *, size_t))dlsym(RTLD_NEXT, "cudnnRNNForwardInference");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNForwardInference", kApiTypeCuDNN);

    lretval = lcudnnRNNForwardInference(handle, rnnDesc, seqLength, xDesc, x, hxDesc, hx, cxDesc, cx, wDesc, w, yDesc, y, hyDesc, hy, cyDesc, cy, workSpace, workSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNForwardInference cudnnRNNForwardInference


#undef cudnnSetRNNPaddingMode
cudnnStatus_t cudnnSetRNNPaddingMode(cudnnRNNDescriptor_t rnnDesc, unsigned int paddingMode){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetRNNPaddingMode) (cudnnRNNDescriptor_t, unsigned int) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, unsigned int))dlsym(RTLD_NEXT, "cudnnSetRNNPaddingMode");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetRNNPaddingMode", kApiTypeCuDNN);

    lretval = lcudnnSetRNNPaddingMode(rnnDesc, paddingMode);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetRNNPaddingMode cudnnSetRNNPaddingMode


#undef cudnnGetRNNPaddingMode
cudnnStatus_t cudnnGetRNNPaddingMode(cudnnRNNDescriptor_t rnnDesc, unsigned int * paddingMode){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNPaddingMode) (cudnnRNNDescriptor_t, unsigned int *) = (cudnnStatus_t (*)(cudnnRNNDescriptor_t, unsigned int *))dlsym(RTLD_NEXT, "cudnnGetRNNPaddingMode");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNPaddingMode", kApiTypeCuDNN);

    lretval = lcudnnGetRNNPaddingMode(rnnDesc, paddingMode);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNPaddingMode cudnnGetRNNPaddingMode


#undef cudnnCreateRNNDataDescriptor
cudnnStatus_t cudnnCreateRNNDataDescriptor(cudnnRNNDataDescriptor_t * rnnDataDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateRNNDataDescriptor) (cudnnRNNDataDescriptor_t *) = (cudnnStatus_t (*)(cudnnRNNDataDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateRNNDataDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateRNNDataDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateRNNDataDescriptor(rnnDataDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateRNNDataDescriptor cudnnCreateRNNDataDescriptor


#undef cudnnDestroyRNNDataDescriptor
cudnnStatus_t cudnnDestroyRNNDataDescriptor(cudnnRNNDataDescriptor_t rnnDataDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyRNNDataDescriptor) (cudnnRNNDataDescriptor_t) = (cudnnStatus_t (*)(cudnnRNNDataDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyRNNDataDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyRNNDataDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyRNNDataDescriptor(rnnDataDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyRNNDataDescriptor cudnnDestroyRNNDataDescriptor


#undef cudnnSetRNNDataDescriptor
cudnnStatus_t cudnnSetRNNDataDescriptor(cudnnRNNDataDescriptor_t rnnDataDesc, cudnnDataType_t dataType, cudnnRNNDataLayout_t layout, int maxSeqLength, int batchSize, int vectorSize, int const * seqLengthArray, void * paddingFill){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetRNNDataDescriptor) (cudnnRNNDataDescriptor_t, cudnnDataType_t, cudnnRNNDataLayout_t, int, int, int, int const *, void *) = (cudnnStatus_t (*)(cudnnRNNDataDescriptor_t, cudnnDataType_t, cudnnRNNDataLayout_t, int, int, int, int const *, void *))dlsym(RTLD_NEXT, "cudnnSetRNNDataDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetRNNDataDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetRNNDataDescriptor(rnnDataDesc, dataType, layout, maxSeqLength, batchSize, vectorSize, seqLengthArray, paddingFill);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetRNNDataDescriptor cudnnSetRNNDataDescriptor


#undef cudnnGetRNNDataDescriptor
cudnnStatus_t cudnnGetRNNDataDescriptor(cudnnRNNDataDescriptor_t rnnDataDesc, cudnnDataType_t * dataType, cudnnRNNDataLayout_t * layout, int * maxSeqLength, int * batchSize, int * vectorSize, int arrayLengthRequested, int * seqLengthArray, void * paddingFill){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNDataDescriptor) (cudnnRNNDataDescriptor_t, cudnnDataType_t *, cudnnRNNDataLayout_t *, int *, int *, int *, int, int *, void *) = (cudnnStatus_t (*)(cudnnRNNDataDescriptor_t, cudnnDataType_t *, cudnnRNNDataLayout_t *, int *, int *, int *, int, int *, void *))dlsym(RTLD_NEXT, "cudnnGetRNNDataDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNDataDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetRNNDataDescriptor(rnnDataDesc, dataType, layout, maxSeqLength, batchSize, vectorSize, arrayLengthRequested, seqLengthArray, paddingFill);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNDataDescriptor cudnnGetRNNDataDescriptor


#undef cudnnRNNForwardInferenceEx
cudnnStatus_t cudnnRNNForwardInferenceEx(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, cudnnRNNDataDescriptor_t const xDesc, void const * x, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const cxDesc, void const * cx, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnRNNDataDescriptor_t const yDesc, void * y, cudnnTensorDescriptor_t const hyDesc, void * hy, cudnnTensorDescriptor_t const cyDesc, void * cy, cudnnRNNDataDescriptor_t const kDesc, void const * keys, cudnnRNNDataDescriptor_t const cDesc, void * cAttn, cudnnRNNDataDescriptor_t const iDesc, void * iAttn, cudnnRNNDataDescriptor_t const qDesc, void * queries, void * workSpace, size_t workSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNForwardInferenceEx) (cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnRNNDataDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnRNNDataDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, void *, size_t))dlsym(RTLD_NEXT, "cudnnRNNForwardInferenceEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNForwardInferenceEx", kApiTypeCuDNN);

    lretval = lcudnnRNNForwardInferenceEx(handle, rnnDesc, xDesc, x, hxDesc, hx, cxDesc, cx, wDesc, w, yDesc, y, hyDesc, hy, cyDesc, cy, kDesc, keys, cDesc, cAttn, iDesc, iAttn, qDesc, queries, workSpace, workSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNForwardInferenceEx cudnnRNNForwardInferenceEx


#undef cudnnRNNForward
cudnnStatus_t cudnnRNNForward(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, cudnnForwardMode_t fwdMode, int32_t const * devSeqLengths, cudnnRNNDataDescriptor_t xDesc, void const * x, cudnnRNNDataDescriptor_t yDesc, void * y, cudnnTensorDescriptor_t hDesc, void const * hx, void * hy, cudnnTensorDescriptor_t cDesc, void const * cx, void * cy, size_t weightSpaceSize, void const * weightSpace, size_t workSpaceSize, void * workSpace, size_t reserveSpaceSize, void * reserveSpace){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNForward) (cudnnHandle_t, cudnnRNNDescriptor_t, cudnnForwardMode_t, int32_t const *, cudnnRNNDataDescriptor_t, void const *, cudnnRNNDataDescriptor_t, void *, cudnnTensorDescriptor_t, void const *, void *, cudnnTensorDescriptor_t, void const *, void *, size_t, void const *, size_t, void *, size_t, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, cudnnForwardMode_t, int32_t const *, cudnnRNNDataDescriptor_t, void const *, cudnnRNNDataDescriptor_t, void *, cudnnTensorDescriptor_t, void const *, void *, cudnnTensorDescriptor_t, void const *, void *, size_t, void const *, size_t, void *, size_t, void *))dlsym(RTLD_NEXT, "cudnnRNNForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNForward", kApiTypeCuDNN);

    lretval = lcudnnRNNForward(handle, rnnDesc, fwdMode, devSeqLengths, xDesc, x, yDesc, y, hDesc, hx, hy, cDesc, cx, cy, weightSpaceSize, weightSpace, workSpaceSize, workSpace, reserveSpaceSize, reserveSpace);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNForward cudnnRNNForward


#undef cudnnSetRNNAlgorithmDescriptor
cudnnStatus_t cudnnSetRNNAlgorithmDescriptor(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, cudnnAlgorithmDescriptor_t algoDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetRNNAlgorithmDescriptor) (cudnnHandle_t, cudnnRNNDescriptor_t, cudnnAlgorithmDescriptor_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, cudnnAlgorithmDescriptor_t))dlsym(RTLD_NEXT, "cudnnSetRNNAlgorithmDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetRNNAlgorithmDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetRNNAlgorithmDescriptor(handle, rnnDesc, algoDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetRNNAlgorithmDescriptor cudnnSetRNNAlgorithmDescriptor


#undef cudnnGetRNNForwardInferenceAlgorithmMaxCount
cudnnStatus_t cudnnGetRNNForwardInferenceAlgorithmMaxCount(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int * count){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNForwardInferenceAlgorithmMaxCount) (cudnnHandle_t, cudnnRNNDescriptor_t const, int *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int *))dlsym(RTLD_NEXT, "cudnnGetRNNForwardInferenceAlgorithmMaxCount");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNForwardInferenceAlgorithmMaxCount", kApiTypeCuDNN);

    lretval = lcudnnGetRNNForwardInferenceAlgorithmMaxCount(handle, rnnDesc, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNForwardInferenceAlgorithmMaxCount cudnnGetRNNForwardInferenceAlgorithmMaxCount


#undef cudnnFindRNNForwardInferenceAlgorithmEx
cudnnStatus_t cudnnFindRNNForwardInferenceAlgorithmEx(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * xDesc, void const * x, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const cxDesc, void const * cx, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnTensorDescriptor_t const * yDesc, void * y, cudnnTensorDescriptor_t const hyDesc, void * hy, cudnnTensorDescriptor_t const cyDesc, void * cy, float const findIntensity, int const requestedAlgoCount, int * returnedAlgoCount, cudnnAlgorithmPerformance_t * perfResults, void * workspace, size_t workSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindRNNForwardInferenceAlgorithmEx) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, float const, int const, int *, cudnnAlgorithmPerformance_t *, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, float const, int const, int *, cudnnAlgorithmPerformance_t *, void *, size_t))dlsym(RTLD_NEXT, "cudnnFindRNNForwardInferenceAlgorithmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindRNNForwardInferenceAlgorithmEx", kApiTypeCuDNN);

    lretval = lcudnnFindRNNForwardInferenceAlgorithmEx(handle, rnnDesc, seqLength, xDesc, x, hxDesc, hx, cxDesc, cx, wDesc, w, yDesc, y, hyDesc, hy, cyDesc, cy, findIntensity, requestedAlgoCount, returnedAlgoCount, perfResults, workspace, workSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindRNNForwardInferenceAlgorithmEx cudnnFindRNNForwardInferenceAlgorithmEx


#undef cudnnCreateSeqDataDescriptor
cudnnStatus_t cudnnCreateSeqDataDescriptor(cudnnSeqDataDescriptor_t * seqDataDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateSeqDataDescriptor) (cudnnSeqDataDescriptor_t *) = (cudnnStatus_t (*)(cudnnSeqDataDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateSeqDataDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateSeqDataDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateSeqDataDescriptor(seqDataDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateSeqDataDescriptor cudnnCreateSeqDataDescriptor


#undef cudnnDestroySeqDataDescriptor
cudnnStatus_t cudnnDestroySeqDataDescriptor(cudnnSeqDataDescriptor_t seqDataDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroySeqDataDescriptor) (cudnnSeqDataDescriptor_t) = (cudnnStatus_t (*)(cudnnSeqDataDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroySeqDataDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroySeqDataDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroySeqDataDescriptor(seqDataDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroySeqDataDescriptor cudnnDestroySeqDataDescriptor


#undef cudnnSetSeqDataDescriptor
cudnnStatus_t cudnnSetSeqDataDescriptor(cudnnSeqDataDescriptor_t seqDataDesc, cudnnDataType_t dataType, int nbDims, int const * dimA, cudnnSeqDataAxis_t const * axes, size_t seqLengthArraySize, int const * seqLengthArray, void * paddingFill){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetSeqDataDescriptor) (cudnnSeqDataDescriptor_t, cudnnDataType_t, int, int const *, cudnnSeqDataAxis_t const *, size_t, int const *, void *) = (cudnnStatus_t (*)(cudnnSeqDataDescriptor_t, cudnnDataType_t, int, int const *, cudnnSeqDataAxis_t const *, size_t, int const *, void *))dlsym(RTLD_NEXT, "cudnnSetSeqDataDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetSeqDataDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetSeqDataDescriptor(seqDataDesc, dataType, nbDims, dimA, axes, seqLengthArraySize, seqLengthArray, paddingFill);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetSeqDataDescriptor cudnnSetSeqDataDescriptor


#undef cudnnGetSeqDataDescriptor
cudnnStatus_t cudnnGetSeqDataDescriptor(cudnnSeqDataDescriptor_t const seqDataDesc, cudnnDataType_t * dataType, int * nbDims, int nbDimsRequested, int * dimA, cudnnSeqDataAxis_t * axes, size_t * seqLengthArraySize, size_t seqLengthSizeRequested, int * seqLengthArray, void * paddingFill){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetSeqDataDescriptor) (cudnnSeqDataDescriptor_t const, cudnnDataType_t *, int *, int, int *, cudnnSeqDataAxis_t *, size_t *, size_t, int *, void *) = (cudnnStatus_t (*)(cudnnSeqDataDescriptor_t const, cudnnDataType_t *, int *, int, int *, cudnnSeqDataAxis_t *, size_t *, size_t, int *, void *))dlsym(RTLD_NEXT, "cudnnGetSeqDataDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetSeqDataDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetSeqDataDescriptor(seqDataDesc, dataType, nbDims, nbDimsRequested, dimA, axes, seqLengthArraySize, seqLengthSizeRequested, seqLengthArray, paddingFill);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetSeqDataDescriptor cudnnGetSeqDataDescriptor


#undef cudnnCreateAttnDescriptor
cudnnStatus_t cudnnCreateAttnDescriptor(cudnnAttnDescriptor_t * attnDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateAttnDescriptor) (cudnnAttnDescriptor_t *) = (cudnnStatus_t (*)(cudnnAttnDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateAttnDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateAttnDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateAttnDescriptor(attnDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateAttnDescriptor cudnnCreateAttnDescriptor


#undef cudnnDestroyAttnDescriptor
cudnnStatus_t cudnnDestroyAttnDescriptor(cudnnAttnDescriptor_t attnDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyAttnDescriptor) (cudnnAttnDescriptor_t) = (cudnnStatus_t (*)(cudnnAttnDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyAttnDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyAttnDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyAttnDescriptor(attnDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyAttnDescriptor cudnnDestroyAttnDescriptor


#undef cudnnSetAttnDescriptor
cudnnStatus_t cudnnSetAttnDescriptor(cudnnAttnDescriptor_t attnDesc, unsigned int attnMode, int nHeads, double smScaler, cudnnDataType_t dataType, cudnnDataType_t computePrec, cudnnMathType_t mathType, cudnnDropoutDescriptor_t attnDropoutDesc, cudnnDropoutDescriptor_t postDropoutDesc, int qSize, int kSize, int vSize, int qProjSize, int kProjSize, int vProjSize, int oProjSize, int qoMaxSeqLength, int kvMaxSeqLength, int maxBatchSize, int maxBeamSize){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetAttnDescriptor) (cudnnAttnDescriptor_t, unsigned int, int, double, cudnnDataType_t, cudnnDataType_t, cudnnMathType_t, cudnnDropoutDescriptor_t, cudnnDropoutDescriptor_t, int, int, int, int, int, int, int, int, int, int, int) = (cudnnStatus_t (*)(cudnnAttnDescriptor_t, unsigned int, int, double, cudnnDataType_t, cudnnDataType_t, cudnnMathType_t, cudnnDropoutDescriptor_t, cudnnDropoutDescriptor_t, int, int, int, int, int, int, int, int, int, int, int))dlsym(RTLD_NEXT, "cudnnSetAttnDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetAttnDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetAttnDescriptor(attnDesc, attnMode, nHeads, smScaler, dataType, computePrec, mathType, attnDropoutDesc, postDropoutDesc, qSize, kSize, vSize, qProjSize, kProjSize, vProjSize, oProjSize, qoMaxSeqLength, kvMaxSeqLength, maxBatchSize, maxBeamSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetAttnDescriptor cudnnSetAttnDescriptor


#undef cudnnGetAttnDescriptor
cudnnStatus_t cudnnGetAttnDescriptor(cudnnAttnDescriptor_t attnDesc, unsigned int * attnMode, int * nHeads, double * smScaler, cudnnDataType_t * dataType, cudnnDataType_t * computePrec, cudnnMathType_t * mathType, cudnnDropoutDescriptor_t * attnDropoutDesc, cudnnDropoutDescriptor_t * postDropoutDesc, int * qSize, int * kSize, int * vSize, int * qProjSize, int * kProjSize, int * vProjSize, int * oProjSize, int * qoMaxSeqLength, int * kvMaxSeqLength, int * maxBatchSize, int * maxBeamSize){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetAttnDescriptor) (cudnnAttnDescriptor_t, unsigned int *, int *, double *, cudnnDataType_t *, cudnnDataType_t *, cudnnMathType_t *, cudnnDropoutDescriptor_t *, cudnnDropoutDescriptor_t *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *) = (cudnnStatus_t (*)(cudnnAttnDescriptor_t, unsigned int *, int *, double *, cudnnDataType_t *, cudnnDataType_t *, cudnnMathType_t *, cudnnDropoutDescriptor_t *, cudnnDropoutDescriptor_t *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *))dlsym(RTLD_NEXT, "cudnnGetAttnDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetAttnDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetAttnDescriptor(attnDesc, attnMode, nHeads, smScaler, dataType, computePrec, mathType, attnDropoutDesc, postDropoutDesc, qSize, kSize, vSize, qProjSize, kProjSize, vProjSize, oProjSize, qoMaxSeqLength, kvMaxSeqLength, maxBatchSize, maxBeamSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetAttnDescriptor cudnnGetAttnDescriptor


#undef cudnnGetMultiHeadAttnBuffers
cudnnStatus_t cudnnGetMultiHeadAttnBuffers(cudnnHandle_t handle, cudnnAttnDescriptor_t const attnDesc, size_t * weightSizeInBytes, size_t * workSpaceSizeInBytes, size_t * reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetMultiHeadAttnBuffers) (cudnnHandle_t, cudnnAttnDescriptor_t const, size_t *, size_t *, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnAttnDescriptor_t const, size_t *, size_t *, size_t *))dlsym(RTLD_NEXT, "cudnnGetMultiHeadAttnBuffers");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetMultiHeadAttnBuffers", kApiTypeCuDNN);

    lretval = lcudnnGetMultiHeadAttnBuffers(handle, attnDesc, weightSizeInBytes, workSpaceSizeInBytes, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetMultiHeadAttnBuffers cudnnGetMultiHeadAttnBuffers


#undef cudnnGetMultiHeadAttnWeights
cudnnStatus_t cudnnGetMultiHeadAttnWeights(cudnnHandle_t handle, cudnnAttnDescriptor_t const attnDesc, cudnnMultiHeadAttnWeightKind_t wKind, size_t weightSizeInBytes, void const * weights, cudnnTensorDescriptor_t wDesc, void * * wAddr){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetMultiHeadAttnWeights) (cudnnHandle_t, cudnnAttnDescriptor_t const, cudnnMultiHeadAttnWeightKind_t, size_t, void const *, cudnnTensorDescriptor_t, void * *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnAttnDescriptor_t const, cudnnMultiHeadAttnWeightKind_t, size_t, void const *, cudnnTensorDescriptor_t, void * *))dlsym(RTLD_NEXT, "cudnnGetMultiHeadAttnWeights");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetMultiHeadAttnWeights", kApiTypeCuDNN);

    lretval = lcudnnGetMultiHeadAttnWeights(handle, attnDesc, wKind, weightSizeInBytes, weights, wDesc, wAddr);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetMultiHeadAttnWeights cudnnGetMultiHeadAttnWeights


#undef cudnnMultiHeadAttnForward
cudnnStatus_t cudnnMultiHeadAttnForward(cudnnHandle_t handle, cudnnAttnDescriptor_t const attnDesc, int currIdx, int const * loWinIdx, int const * hiWinIdx, int const * devSeqLengthsQO, int const * devSeqLengthsKV, cudnnSeqDataDescriptor_t const qDesc, void const * queries, void const * residuals, cudnnSeqDataDescriptor_t const kDesc, void const * keys, cudnnSeqDataDescriptor_t const vDesc, void const * values, cudnnSeqDataDescriptor_t const oDesc, void * out, size_t weightSizeInBytes, void const * weights, size_t workSpaceSizeInBytes, void * workSpace, size_t reserveSpaceSizeInBytes, void * reserveSpace){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnMultiHeadAttnForward) (cudnnHandle_t, cudnnAttnDescriptor_t const, int, int const *, int const *, int const *, int const *, cudnnSeqDataDescriptor_t const, void const *, void const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void *, size_t, void const *, size_t, void *, size_t, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnAttnDescriptor_t const, int, int const *, int const *, int const *, int const *, cudnnSeqDataDescriptor_t const, void const *, void const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void *, size_t, void const *, size_t, void *, size_t, void *))dlsym(RTLD_NEXT, "cudnnMultiHeadAttnForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnMultiHeadAttnForward", kApiTypeCuDNN);

    lretval = lcudnnMultiHeadAttnForward(handle, attnDesc, currIdx, loWinIdx, hiWinIdx, devSeqLengthsQO, devSeqLengthsKV, qDesc, queries, residuals, kDesc, keys, vDesc, values, oDesc, out, weightSizeInBytes, weights, workSpaceSizeInBytes, workSpace, reserveSpaceSizeInBytes, reserveSpace);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnMultiHeadAttnForward cudnnMultiHeadAttnForward


#undef cudnnAdvInferVersionCheck
cudnnStatus_t cudnnAdvInferVersionCheck(){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnAdvInferVersionCheck) () = (cudnnStatus_t (*)())dlsym(RTLD_NEXT, "cudnnAdvInferVersionCheck");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnAdvInferVersionCheck", kApiTypeCuDNN);

    lretval = lcudnnAdvInferVersionCheck();
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnAdvInferVersionCheck cudnnAdvInferVersionCheck


#undef cudnnRNNForwardTraining
cudnnStatus_t cudnnRNNForwardTraining(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * xDesc, void const * x, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const cxDesc, void const * cx, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnTensorDescriptor_t const * yDesc, void * y, cudnnTensorDescriptor_t const hyDesc, void * hy, cudnnTensorDescriptor_t const cyDesc, void * cy, void * workSpace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNForwardTraining) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, void *, size_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, void *, size_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnRNNForwardTraining");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNForwardTraining", kApiTypeCuDNN);

    lretval = lcudnnRNNForwardTraining(handle, rnnDesc, seqLength, xDesc, x, hxDesc, hx, cxDesc, cx, wDesc, w, yDesc, y, hyDesc, hy, cyDesc, cy, workSpace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNForwardTraining cudnnRNNForwardTraining


#undef cudnnRNNBackwardData
cudnnStatus_t cudnnRNNBackwardData(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * yDesc, void const * y, cudnnTensorDescriptor_t const * dyDesc, void const * dy, cudnnTensorDescriptor_t const dhyDesc, void const * dhy, cudnnTensorDescriptor_t const dcyDesc, void const * dcy, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const cxDesc, void const * cx, cudnnTensorDescriptor_t const * dxDesc, void * dx, cudnnTensorDescriptor_t const dhxDesc, void * dhx, cudnnTensorDescriptor_t const dcxDesc, void * dcx, void * workSpace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNBackwardData) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, void *, size_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, void *, size_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnRNNBackwardData");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNBackwardData", kApiTypeCuDNN);

    lretval = lcudnnRNNBackwardData(handle, rnnDesc, seqLength, yDesc, y, dyDesc, dy, dhyDesc, dhy, dcyDesc, dcy, wDesc, w, hxDesc, hx, cxDesc, cx, dxDesc, dx, dhxDesc, dhx, dcxDesc, dcx, workSpace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNBackwardData cudnnRNNBackwardData


#undef cudnnRNNBackwardData_v8
cudnnStatus_t cudnnRNNBackwardData_v8(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, int32_t const * devSeqLengths, cudnnRNNDataDescriptor_t yDesc, void const * y, void const * dy, cudnnRNNDataDescriptor_t xDesc, void * dx, cudnnTensorDescriptor_t hDesc, void const * hx, void const * dhy, void * dhx, cudnnTensorDescriptor_t cDesc, void const * cx, void const * dcy, void * dcx, size_t weightSpaceSize, void const * weightSpace, size_t workSpaceSize, void * workSpace, size_t reserveSpaceSize, void * reserveSpace){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNBackwardData_v8) (cudnnHandle_t, cudnnRNNDescriptor_t, int32_t const *, cudnnRNNDataDescriptor_t, void const *, void const *, cudnnRNNDataDescriptor_t, void *, cudnnTensorDescriptor_t, void const *, void const *, void *, cudnnTensorDescriptor_t, void const *, void const *, void *, size_t, void const *, size_t, void *, size_t, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, int32_t const *, cudnnRNNDataDescriptor_t, void const *, void const *, cudnnRNNDataDescriptor_t, void *, cudnnTensorDescriptor_t, void const *, void const *, void *, cudnnTensorDescriptor_t, void const *, void const *, void *, size_t, void const *, size_t, void *, size_t, void *))dlsym(RTLD_NEXT, "cudnnRNNBackwardData_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNBackwardData_v8", kApiTypeCuDNN);

    lretval = lcudnnRNNBackwardData_v8(handle, rnnDesc, devSeqLengths, yDesc, y, dy, xDesc, dx, hDesc, hx, dhy, dhx, cDesc, cx, dcy, dcx, weightSpaceSize, weightSpace, workSpaceSize, workSpace, reserveSpaceSize, reserveSpace);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNBackwardData_v8 cudnnRNNBackwardData_v8


#undef cudnnRNNBackwardWeights
cudnnStatus_t cudnnRNNBackwardWeights(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * xDesc, void const * x, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const * yDesc, void const * y, void const * workSpace, size_t workSpaceSizeInBytes, cudnnFilterDescriptor_t const dwDesc, void * dw, void const * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNBackwardWeights) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void const *, void const *, size_t, cudnnFilterDescriptor_t const, void *, void const *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void const *, void const *, size_t, cudnnFilterDescriptor_t const, void *, void const *, size_t))dlsym(RTLD_NEXT, "cudnnRNNBackwardWeights");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNBackwardWeights", kApiTypeCuDNN);

    lretval = lcudnnRNNBackwardWeights(handle, rnnDesc, seqLength, xDesc, x, hxDesc, hx, yDesc, y, workSpace, workSpaceSizeInBytes, dwDesc, dw, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNBackwardWeights cudnnRNNBackwardWeights


#undef cudnnRNNBackwardWeights_v8
cudnnStatus_t cudnnRNNBackwardWeights_v8(cudnnHandle_t handle, cudnnRNNDescriptor_t rnnDesc, cudnnWgradMode_t addGrad, int32_t const * devSeqLengths, cudnnRNNDataDescriptor_t xDesc, void const * x, cudnnTensorDescriptor_t hDesc, void const * hx, cudnnRNNDataDescriptor_t yDesc, void const * y, size_t weightSpaceSize, void * dweightSpace, size_t workSpaceSize, void * workSpace, size_t reserveSpaceSize, void * reserveSpace){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNBackwardWeights_v8) (cudnnHandle_t, cudnnRNNDescriptor_t, cudnnWgradMode_t, int32_t const *, cudnnRNNDataDescriptor_t, void const *, cudnnTensorDescriptor_t, void const *, cudnnRNNDataDescriptor_t, void const *, size_t, void *, size_t, void *, size_t, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t, cudnnWgradMode_t, int32_t const *, cudnnRNNDataDescriptor_t, void const *, cudnnTensorDescriptor_t, void const *, cudnnRNNDataDescriptor_t, void const *, size_t, void *, size_t, void *, size_t, void *))dlsym(RTLD_NEXT, "cudnnRNNBackwardWeights_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNBackwardWeights_v8", kApiTypeCuDNN);

    lretval = lcudnnRNNBackwardWeights_v8(handle, rnnDesc, addGrad, devSeqLengths, xDesc, x, hDesc, hx, yDesc, y, weightSpaceSize, dweightSpace, workSpaceSize, workSpace, reserveSpaceSize, reserveSpace);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNBackwardWeights_v8 cudnnRNNBackwardWeights_v8


#undef cudnnRNNForwardTrainingEx
cudnnStatus_t cudnnRNNForwardTrainingEx(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, cudnnRNNDataDescriptor_t const xDesc, void const * x, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const cxDesc, void const * cx, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnRNNDataDescriptor_t const yDesc, void * y, cudnnTensorDescriptor_t const hyDesc, void * hy, cudnnTensorDescriptor_t const cyDesc, void * cy, cudnnRNNDataDescriptor_t const kDesc, void const * keys, cudnnRNNDataDescriptor_t const cDesc, void * cAttn, cudnnRNNDataDescriptor_t const iDesc, void * iAttn, cudnnRNNDataDescriptor_t const qDesc, void * queries, void * workSpace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNForwardTrainingEx) (cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnRNNDataDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, void *, size_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnRNNDataDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, void *, size_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnRNNForwardTrainingEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNForwardTrainingEx", kApiTypeCuDNN);

    lretval = lcudnnRNNForwardTrainingEx(handle, rnnDesc, xDesc, x, hxDesc, hx, cxDesc, cx, wDesc, w, yDesc, y, hyDesc, hy, cyDesc, cy, kDesc, keys, cDesc, cAttn, iDesc, iAttn, qDesc, queries, workSpace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNForwardTrainingEx cudnnRNNForwardTrainingEx


#undef cudnnRNNBackwardDataEx
cudnnStatus_t cudnnRNNBackwardDataEx(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, cudnnRNNDataDescriptor_t const yDesc, void const * y, cudnnRNNDataDescriptor_t const dyDesc, void const * dy, cudnnRNNDataDescriptor_t const dcDesc, void const * dcAttn, cudnnTensorDescriptor_t const dhyDesc, void const * dhy, cudnnTensorDescriptor_t const dcyDesc, void const * dcy, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const cxDesc, void const * cx, cudnnRNNDataDescriptor_t const dxDesc, void * dx, cudnnTensorDescriptor_t const dhxDesc, void * dhx, cudnnTensorDescriptor_t const dcxDesc, void * dcx, cudnnRNNDataDescriptor_t const dkDesc, void * dkeys, void * workSpace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNBackwardDataEx) (cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnRNNDataDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, void *, size_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnRNNDataDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, cudnnRNNDataDescriptor_t const, void *, void *, size_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnRNNBackwardDataEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNBackwardDataEx", kApiTypeCuDNN);

    lretval = lcudnnRNNBackwardDataEx(handle, rnnDesc, yDesc, y, dyDesc, dy, dcDesc, dcAttn, dhyDesc, dhy, dcyDesc, dcy, wDesc, w, hxDesc, hx, cxDesc, cx, dxDesc, dx, dhxDesc, dhx, dcxDesc, dcx, dkDesc, dkeys, workSpace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNBackwardDataEx cudnnRNNBackwardDataEx


#undef cudnnRNNBackwardWeightsEx
cudnnStatus_t cudnnRNNBackwardWeightsEx(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, cudnnRNNDataDescriptor_t const xDesc, void const * x, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnRNNDataDescriptor_t const yDesc, void const * y, void * workSpace, size_t workSpaceSizeInBytes, cudnnFilterDescriptor_t const dwDesc, void * dw, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnRNNBackwardWeightsEx) (cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnRNNDataDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void const *, void *, size_t, cudnnFilterDescriptor_t const, void *, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, cudnnRNNDataDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnRNNDataDescriptor_t const, void const *, void *, size_t, cudnnFilterDescriptor_t const, void *, void *, size_t))dlsym(RTLD_NEXT, "cudnnRNNBackwardWeightsEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnRNNBackwardWeightsEx", kApiTypeCuDNN);

    lretval = lcudnnRNNBackwardWeightsEx(handle, rnnDesc, xDesc, x, hxDesc, hx, yDesc, y, workSpace, workSpaceSizeInBytes, dwDesc, dw, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnRNNBackwardWeightsEx cudnnRNNBackwardWeightsEx


#undef cudnnGetRNNForwardTrainingAlgorithmMaxCount
cudnnStatus_t cudnnGetRNNForwardTrainingAlgorithmMaxCount(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int * count){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNForwardTrainingAlgorithmMaxCount) (cudnnHandle_t, cudnnRNNDescriptor_t const, int *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int *))dlsym(RTLD_NEXT, "cudnnGetRNNForwardTrainingAlgorithmMaxCount");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNForwardTrainingAlgorithmMaxCount", kApiTypeCuDNN);

    lretval = lcudnnGetRNNForwardTrainingAlgorithmMaxCount(handle, rnnDesc, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNForwardTrainingAlgorithmMaxCount cudnnGetRNNForwardTrainingAlgorithmMaxCount


#undef cudnnFindRNNForwardTrainingAlgorithmEx
cudnnStatus_t cudnnFindRNNForwardTrainingAlgorithmEx(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * xDesc, void const * x, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const cxDesc, void const * cx, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnTensorDescriptor_t const * yDesc, void * y, cudnnTensorDescriptor_t const hyDesc, void * hy, cudnnTensorDescriptor_t const cyDesc, void * cy, float const findIntensity, int const requestedAlgoCount, int * returnedAlgoCount, cudnnAlgorithmPerformance_t * perfResults, void * workspace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindRNNForwardTrainingAlgorithmEx) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, float const, int const, int *, cudnnAlgorithmPerformance_t *, void *, size_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, float const, int const, int *, cudnnAlgorithmPerformance_t *, void *, size_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnFindRNNForwardTrainingAlgorithmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindRNNForwardTrainingAlgorithmEx", kApiTypeCuDNN);

    lretval = lcudnnFindRNNForwardTrainingAlgorithmEx(handle, rnnDesc, seqLength, xDesc, x, hxDesc, hx, cxDesc, cx, wDesc, w, yDesc, y, hyDesc, hy, cyDesc, cy, findIntensity, requestedAlgoCount, returnedAlgoCount, perfResults, workspace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindRNNForwardTrainingAlgorithmEx cudnnFindRNNForwardTrainingAlgorithmEx


#undef cudnnGetRNNBackwardDataAlgorithmMaxCount
cudnnStatus_t cudnnGetRNNBackwardDataAlgorithmMaxCount(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int * count){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNBackwardDataAlgorithmMaxCount) (cudnnHandle_t, cudnnRNNDescriptor_t const, int *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int *))dlsym(RTLD_NEXT, "cudnnGetRNNBackwardDataAlgorithmMaxCount");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNBackwardDataAlgorithmMaxCount", kApiTypeCuDNN);

    lretval = lcudnnGetRNNBackwardDataAlgorithmMaxCount(handle, rnnDesc, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNBackwardDataAlgorithmMaxCount cudnnGetRNNBackwardDataAlgorithmMaxCount


#undef cudnnFindRNNBackwardDataAlgorithmEx
cudnnStatus_t cudnnFindRNNBackwardDataAlgorithmEx(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * yDesc, void const * y, cudnnTensorDescriptor_t const * dyDesc, void const * dy, cudnnTensorDescriptor_t const dhyDesc, void const * dhy, cudnnTensorDescriptor_t const dcyDesc, void const * dcy, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const cxDesc, void const * cx, cudnnTensorDescriptor_t const * dxDesc, void * dx, cudnnTensorDescriptor_t const dhxDesc, void * dhx, cudnnTensorDescriptor_t const dcxDesc, void * dcx, float const findIntensity, int const requestedAlgoCount, int * returnedAlgoCount, cudnnAlgorithmPerformance_t * perfResults, void * workspace, size_t workSpaceSizeInBytes, void * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindRNNBackwardDataAlgorithmEx) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, float const, int const, int *, cudnnAlgorithmPerformance_t *, void *, size_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void *, cudnnTensorDescriptor_t const, void *, cudnnTensorDescriptor_t const, void *, float const, int const, int *, cudnnAlgorithmPerformance_t *, void *, size_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnFindRNNBackwardDataAlgorithmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindRNNBackwardDataAlgorithmEx", kApiTypeCuDNN);

    lretval = lcudnnFindRNNBackwardDataAlgorithmEx(handle, rnnDesc, seqLength, yDesc, y, dyDesc, dy, dhyDesc, dhy, dcyDesc, dcy, wDesc, w, hxDesc, hx, cxDesc, cx, dxDesc, dx, dhxDesc, dhx, dcxDesc, dcx, findIntensity, requestedAlgoCount, returnedAlgoCount, perfResults, workspace, workSpaceSizeInBytes, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindRNNBackwardDataAlgorithmEx cudnnFindRNNBackwardDataAlgorithmEx


#undef cudnnGetRNNBackwardWeightsAlgorithmMaxCount
cudnnStatus_t cudnnGetRNNBackwardWeightsAlgorithmMaxCount(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int * count){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetRNNBackwardWeightsAlgorithmMaxCount) (cudnnHandle_t, cudnnRNNDescriptor_t const, int *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int *))dlsym(RTLD_NEXT, "cudnnGetRNNBackwardWeightsAlgorithmMaxCount");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetRNNBackwardWeightsAlgorithmMaxCount", kApiTypeCuDNN);

    lretval = lcudnnGetRNNBackwardWeightsAlgorithmMaxCount(handle, rnnDesc, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetRNNBackwardWeightsAlgorithmMaxCount cudnnGetRNNBackwardWeightsAlgorithmMaxCount


#undef cudnnFindRNNBackwardWeightsAlgorithmEx
cudnnStatus_t cudnnFindRNNBackwardWeightsAlgorithmEx(cudnnHandle_t handle, cudnnRNNDescriptor_t const rnnDesc, int const seqLength, cudnnTensorDescriptor_t const * xDesc, void const * x, cudnnTensorDescriptor_t const hxDesc, void const * hx, cudnnTensorDescriptor_t const * yDesc, void const * y, float const findIntensity, int const requestedAlgoCount, int * returnedAlgoCount, cudnnAlgorithmPerformance_t * perfResults, void const * workspace, size_t workSpaceSizeInBytes, cudnnFilterDescriptor_t const dwDesc, void * dw, void const * reserveSpace, size_t reserveSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindRNNBackwardWeightsAlgorithmEx) (cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void const *, float const, int const, int *, cudnnAlgorithmPerformance_t *, void const *, size_t, cudnnFilterDescriptor_t const, void *, void const *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnRNNDescriptor_t const, int const, cudnnTensorDescriptor_t const *, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const *, void const *, float const, int const, int *, cudnnAlgorithmPerformance_t *, void const *, size_t, cudnnFilterDescriptor_t const, void *, void const *, size_t))dlsym(RTLD_NEXT, "cudnnFindRNNBackwardWeightsAlgorithmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindRNNBackwardWeightsAlgorithmEx", kApiTypeCuDNN);

    lretval = lcudnnFindRNNBackwardWeightsAlgorithmEx(handle, rnnDesc, seqLength, xDesc, x, hxDesc, hx, yDesc, y, findIntensity, requestedAlgoCount, returnedAlgoCount, perfResults, workspace, workSpaceSizeInBytes, dwDesc, dw, reserveSpace, reserveSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindRNNBackwardWeightsAlgorithmEx cudnnFindRNNBackwardWeightsAlgorithmEx


#undef cudnnMultiHeadAttnBackwardData
cudnnStatus_t cudnnMultiHeadAttnBackwardData(cudnnHandle_t handle, cudnnAttnDescriptor_t const attnDesc, int const * loWinIdx, int const * hiWinIdx, int const * devSeqLengthsDQDO, int const * devSeqLengthsDKDV, cudnnSeqDataDescriptor_t const doDesc, void const * dout, cudnnSeqDataDescriptor_t const dqDesc, void * dqueries, void const * queries, cudnnSeqDataDescriptor_t const dkDesc, void * dkeys, void const * keys, cudnnSeqDataDescriptor_t const dvDesc, void * dvalues, void const * values, size_t weightSizeInBytes, void const * weights, size_t workSpaceSizeInBytes, void * workSpace, size_t reserveSpaceSizeInBytes, void * reserveSpace){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnMultiHeadAttnBackwardData) (cudnnHandle_t, cudnnAttnDescriptor_t const, int const *, int const *, int const *, int const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void *, void const *, cudnnSeqDataDescriptor_t const, void *, void const *, cudnnSeqDataDescriptor_t const, void *, void const *, size_t, void const *, size_t, void *, size_t, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnAttnDescriptor_t const, int const *, int const *, int const *, int const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void *, void const *, cudnnSeqDataDescriptor_t const, void *, void const *, cudnnSeqDataDescriptor_t const, void *, void const *, size_t, void const *, size_t, void *, size_t, void *))dlsym(RTLD_NEXT, "cudnnMultiHeadAttnBackwardData");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnMultiHeadAttnBackwardData", kApiTypeCuDNN);

    lretval = lcudnnMultiHeadAttnBackwardData(handle, attnDesc, loWinIdx, hiWinIdx, devSeqLengthsDQDO, devSeqLengthsDKDV, doDesc, dout, dqDesc, dqueries, queries, dkDesc, dkeys, keys, dvDesc, dvalues, values, weightSizeInBytes, weights, workSpaceSizeInBytes, workSpace, reserveSpaceSizeInBytes, reserveSpace);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnMultiHeadAttnBackwardData cudnnMultiHeadAttnBackwardData


#undef cudnnMultiHeadAttnBackwardWeights
cudnnStatus_t cudnnMultiHeadAttnBackwardWeights(cudnnHandle_t handle, cudnnAttnDescriptor_t const attnDesc, cudnnWgradMode_t addGrad, cudnnSeqDataDescriptor_t const qDesc, void const * queries, cudnnSeqDataDescriptor_t const kDesc, void const * keys, cudnnSeqDataDescriptor_t const vDesc, void const * values, cudnnSeqDataDescriptor_t const doDesc, void const * dout, size_t weightSizeInBytes, void const * weights, void * dweights, size_t workSpaceSizeInBytes, void * workSpace, size_t reserveSpaceSizeInBytes, void * reserveSpace){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnMultiHeadAttnBackwardWeights) (cudnnHandle_t, cudnnAttnDescriptor_t const, cudnnWgradMode_t, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void const *, size_t, void const *, void *, size_t, void *, size_t, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnAttnDescriptor_t const, cudnnWgradMode_t, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void const *, cudnnSeqDataDescriptor_t const, void const *, size_t, void const *, void *, size_t, void *, size_t, void *))dlsym(RTLD_NEXT, "cudnnMultiHeadAttnBackwardWeights");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnMultiHeadAttnBackwardWeights", kApiTypeCuDNN);

    lretval = lcudnnMultiHeadAttnBackwardWeights(handle, attnDesc, addGrad, qDesc, queries, kDesc, keys, vDesc, values, doDesc, dout, weightSizeInBytes, weights, dweights, workSpaceSizeInBytes, workSpace, reserveSpaceSizeInBytes, reserveSpace);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnMultiHeadAttnBackwardWeights cudnnMultiHeadAttnBackwardWeights


#undef cudnnCreateCTCLossDescriptor
cudnnStatus_t cudnnCreateCTCLossDescriptor(cudnnCTCLossDescriptor_t * ctcLossDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateCTCLossDescriptor) (cudnnCTCLossDescriptor_t *) = (cudnnStatus_t (*)(cudnnCTCLossDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateCTCLossDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateCTCLossDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateCTCLossDescriptor(ctcLossDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateCTCLossDescriptor cudnnCreateCTCLossDescriptor


#undef cudnnSetCTCLossDescriptor
cudnnStatus_t cudnnSetCTCLossDescriptor(cudnnCTCLossDescriptor_t ctcLossDesc, cudnnDataType_t compType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetCTCLossDescriptor) (cudnnCTCLossDescriptor_t, cudnnDataType_t) = (cudnnStatus_t (*)(cudnnCTCLossDescriptor_t, cudnnDataType_t))dlsym(RTLD_NEXT, "cudnnSetCTCLossDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetCTCLossDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetCTCLossDescriptor(ctcLossDesc, compType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetCTCLossDescriptor cudnnSetCTCLossDescriptor


#undef cudnnSetCTCLossDescriptorEx
cudnnStatus_t cudnnSetCTCLossDescriptorEx(cudnnCTCLossDescriptor_t ctcLossDesc, cudnnDataType_t compType, cudnnLossNormalizationMode_t normMode, cudnnNanPropagation_t gradMode){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetCTCLossDescriptorEx) (cudnnCTCLossDescriptor_t, cudnnDataType_t, cudnnLossNormalizationMode_t, cudnnNanPropagation_t) = (cudnnStatus_t (*)(cudnnCTCLossDescriptor_t, cudnnDataType_t, cudnnLossNormalizationMode_t, cudnnNanPropagation_t))dlsym(RTLD_NEXT, "cudnnSetCTCLossDescriptorEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetCTCLossDescriptorEx", kApiTypeCuDNN);

    lretval = lcudnnSetCTCLossDescriptorEx(ctcLossDesc, compType, normMode, gradMode);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetCTCLossDescriptorEx cudnnSetCTCLossDescriptorEx


#undef cudnnSetCTCLossDescriptor_v8
cudnnStatus_t cudnnSetCTCLossDescriptor_v8(cudnnCTCLossDescriptor_t ctcLossDesc, cudnnDataType_t compType, cudnnLossNormalizationMode_t normMode, cudnnNanPropagation_t gradMode, int maxLabelLength){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetCTCLossDescriptor_v8) (cudnnCTCLossDescriptor_t, cudnnDataType_t, cudnnLossNormalizationMode_t, cudnnNanPropagation_t, int) = (cudnnStatus_t (*)(cudnnCTCLossDescriptor_t, cudnnDataType_t, cudnnLossNormalizationMode_t, cudnnNanPropagation_t, int))dlsym(RTLD_NEXT, "cudnnSetCTCLossDescriptor_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetCTCLossDescriptor_v8", kApiTypeCuDNN);

    lretval = lcudnnSetCTCLossDescriptor_v8(ctcLossDesc, compType, normMode, gradMode, maxLabelLength);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetCTCLossDescriptor_v8 cudnnSetCTCLossDescriptor_v8


#undef cudnnGetCTCLossDescriptor
cudnnStatus_t cudnnGetCTCLossDescriptor(cudnnCTCLossDescriptor_t ctcLossDesc, cudnnDataType_t * compType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetCTCLossDescriptor) (cudnnCTCLossDescriptor_t, cudnnDataType_t *) = (cudnnStatus_t (*)(cudnnCTCLossDescriptor_t, cudnnDataType_t *))dlsym(RTLD_NEXT, "cudnnGetCTCLossDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetCTCLossDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetCTCLossDescriptor(ctcLossDesc, compType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetCTCLossDescriptor cudnnGetCTCLossDescriptor


#undef cudnnGetCTCLossDescriptorEx
cudnnStatus_t cudnnGetCTCLossDescriptorEx(cudnnCTCLossDescriptor_t ctcLossDesc, cudnnDataType_t * compType, cudnnLossNormalizationMode_t * normMode, cudnnNanPropagation_t * gradMode){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetCTCLossDescriptorEx) (cudnnCTCLossDescriptor_t, cudnnDataType_t *, cudnnLossNormalizationMode_t *, cudnnNanPropagation_t *) = (cudnnStatus_t (*)(cudnnCTCLossDescriptor_t, cudnnDataType_t *, cudnnLossNormalizationMode_t *, cudnnNanPropagation_t *))dlsym(RTLD_NEXT, "cudnnGetCTCLossDescriptorEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetCTCLossDescriptorEx", kApiTypeCuDNN);

    lretval = lcudnnGetCTCLossDescriptorEx(ctcLossDesc, compType, normMode, gradMode);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetCTCLossDescriptorEx cudnnGetCTCLossDescriptorEx


#undef cudnnGetCTCLossDescriptor_v8
cudnnStatus_t cudnnGetCTCLossDescriptor_v8(cudnnCTCLossDescriptor_t ctcLossDesc, cudnnDataType_t * compType, cudnnLossNormalizationMode_t * normMode, cudnnNanPropagation_t * gradMode, int * maxLabelLength){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetCTCLossDescriptor_v8) (cudnnCTCLossDescriptor_t, cudnnDataType_t *, cudnnLossNormalizationMode_t *, cudnnNanPropagation_t *, int *) = (cudnnStatus_t (*)(cudnnCTCLossDescriptor_t, cudnnDataType_t *, cudnnLossNormalizationMode_t *, cudnnNanPropagation_t *, int *))dlsym(RTLD_NEXT, "cudnnGetCTCLossDescriptor_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetCTCLossDescriptor_v8", kApiTypeCuDNN);

    lretval = lcudnnGetCTCLossDescriptor_v8(ctcLossDesc, compType, normMode, gradMode, maxLabelLength);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetCTCLossDescriptor_v8 cudnnGetCTCLossDescriptor_v8


#undef cudnnDestroyCTCLossDescriptor
cudnnStatus_t cudnnDestroyCTCLossDescriptor(cudnnCTCLossDescriptor_t ctcLossDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyCTCLossDescriptor) (cudnnCTCLossDescriptor_t) = (cudnnStatus_t (*)(cudnnCTCLossDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyCTCLossDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyCTCLossDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyCTCLossDescriptor(ctcLossDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyCTCLossDescriptor cudnnDestroyCTCLossDescriptor


#undef cudnnCTCLoss
cudnnStatus_t cudnnCTCLoss(cudnnHandle_t handle, cudnnTensorDescriptor_t const probsDesc, void const * probs, int const * hostLabels, int const * hostLabelLengths, int const * hostInputLengths, void * costs, cudnnTensorDescriptor_t const gradientsDesc, void * gradients, cudnnCTCLossAlgo_t algo, cudnnCTCLossDescriptor_t ctcLossDesc, void * workspace, size_t workSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCTCLoss) (cudnnHandle_t, cudnnTensorDescriptor_t const, void const *, int const *, int const *, int const *, void *, cudnnTensorDescriptor_t const, void *, cudnnCTCLossAlgo_t, cudnnCTCLossDescriptor_t, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, void const *, int const *, int const *, int const *, void *, cudnnTensorDescriptor_t const, void *, cudnnCTCLossAlgo_t, cudnnCTCLossDescriptor_t, void *, size_t))dlsym(RTLD_NEXT, "cudnnCTCLoss");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCTCLoss", kApiTypeCuDNN);

    lretval = lcudnnCTCLoss(handle, probsDesc, probs, hostLabels, hostLabelLengths, hostInputLengths, costs, gradientsDesc, gradients, algo, ctcLossDesc, workspace, workSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCTCLoss cudnnCTCLoss


#undef cudnnCTCLoss_v8
cudnnStatus_t cudnnCTCLoss_v8(cudnnHandle_t handle, cudnnCTCLossAlgo_t algo, cudnnCTCLossDescriptor_t ctcLossDesc, cudnnTensorDescriptor_t const probsDesc, void const * probs, int const * labels, int const * labelLengths, int const * inputLengths, void * costs, cudnnTensorDescriptor_t const gradientsDesc, void * gradients, size_t workSpaceSizeInBytes, void * workspace){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCTCLoss_v8) (cudnnHandle_t, cudnnCTCLossAlgo_t, cudnnCTCLossDescriptor_t, cudnnTensorDescriptor_t const, void const *, int const *, int const *, int const *, void *, cudnnTensorDescriptor_t const, void *, size_t, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnCTCLossAlgo_t, cudnnCTCLossDescriptor_t, cudnnTensorDescriptor_t const, void const *, int const *, int const *, int const *, void *, cudnnTensorDescriptor_t const, void *, size_t, void *))dlsym(RTLD_NEXT, "cudnnCTCLoss_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCTCLoss_v8", kApiTypeCuDNN);

    lretval = lcudnnCTCLoss_v8(handle, algo, ctcLossDesc, probsDesc, probs, labels, labelLengths, inputLengths, costs, gradientsDesc, gradients, workSpaceSizeInBytes, workspace);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCTCLoss_v8 cudnnCTCLoss_v8


#undef cudnnGetCTCLossWorkspaceSize
cudnnStatus_t cudnnGetCTCLossWorkspaceSize(cudnnHandle_t handle, cudnnTensorDescriptor_t const probsDesc, cudnnTensorDescriptor_t const gradientsDesc, int const * labels, int const * labelLengths, int const * inputLengths, cudnnCTCLossAlgo_t algo, cudnnCTCLossDescriptor_t ctcLossDesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetCTCLossWorkspaceSize) (cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, int const *, int const *, int const *, cudnnCTCLossAlgo_t, cudnnCTCLossDescriptor_t, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, int const *, int const *, int const *, cudnnCTCLossAlgo_t, cudnnCTCLossDescriptor_t, size_t *))dlsym(RTLD_NEXT, "cudnnGetCTCLossWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetCTCLossWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetCTCLossWorkspaceSize(handle, probsDesc, gradientsDesc, labels, labelLengths, inputLengths, algo, ctcLossDesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetCTCLossWorkspaceSize cudnnGetCTCLossWorkspaceSize


#undef cudnnGetCTCLossWorkspaceSize_v8
cudnnStatus_t cudnnGetCTCLossWorkspaceSize_v8(cudnnHandle_t handle, cudnnCTCLossAlgo_t algo, cudnnCTCLossDescriptor_t ctcLossDesc, cudnnTensorDescriptor_t const probsDesc, cudnnTensorDescriptor_t const gradientsDesc, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetCTCLossWorkspaceSize_v8) (cudnnHandle_t, cudnnCTCLossAlgo_t, cudnnCTCLossDescriptor_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnCTCLossAlgo_t, cudnnCTCLossDescriptor_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, size_t *))dlsym(RTLD_NEXT, "cudnnGetCTCLossWorkspaceSize_v8");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetCTCLossWorkspaceSize_v8", kApiTypeCuDNN);

    lretval = lcudnnGetCTCLossWorkspaceSize_v8(handle, algo, ctcLossDesc, probsDesc, gradientsDesc, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetCTCLossWorkspaceSize_v8 cudnnGetCTCLossWorkspaceSize_v8


#undef cudnnAdvTrainVersionCheck
cudnnStatus_t cudnnAdvTrainVersionCheck(){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnAdvTrainVersionCheck) () = (cudnnStatus_t (*)())dlsym(RTLD_NEXT, "cudnnAdvTrainVersionCheck");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnAdvTrainVersionCheck", kApiTypeCuDNN);

    lretval = lcudnnAdvTrainVersionCheck();
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnAdvTrainVersionCheck cudnnAdvTrainVersionCheck


#undef cudnnCreateConvolutionDescriptor
cudnnStatus_t cudnnCreateConvolutionDescriptor(cudnnConvolutionDescriptor_t * convDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateConvolutionDescriptor) (cudnnConvolutionDescriptor_t *) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t *))dlsym(RTLD_NEXT, "cudnnCreateConvolutionDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateConvolutionDescriptor", kApiTypeCuDNN);

    lretval = lcudnnCreateConvolutionDescriptor(convDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateConvolutionDescriptor cudnnCreateConvolutionDescriptor


#undef cudnnDestroyConvolutionDescriptor
cudnnStatus_t cudnnDestroyConvolutionDescriptor(cudnnConvolutionDescriptor_t convDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyConvolutionDescriptor) (cudnnConvolutionDescriptor_t) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t))dlsym(RTLD_NEXT, "cudnnDestroyConvolutionDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyConvolutionDescriptor", kApiTypeCuDNN);

    lretval = lcudnnDestroyConvolutionDescriptor(convDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyConvolutionDescriptor cudnnDestroyConvolutionDescriptor


#undef cudnnSetConvolutionMathType
cudnnStatus_t cudnnSetConvolutionMathType(cudnnConvolutionDescriptor_t convDesc, cudnnMathType_t mathType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetConvolutionMathType) (cudnnConvolutionDescriptor_t, cudnnMathType_t) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t, cudnnMathType_t))dlsym(RTLD_NEXT, "cudnnSetConvolutionMathType");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetConvolutionMathType", kApiTypeCuDNN);

    lretval = lcudnnSetConvolutionMathType(convDesc, mathType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetConvolutionMathType cudnnSetConvolutionMathType


#undef cudnnGetConvolutionMathType
cudnnStatus_t cudnnGetConvolutionMathType(cudnnConvolutionDescriptor_t convDesc, cudnnMathType_t * mathType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionMathType) (cudnnConvolutionDescriptor_t, cudnnMathType_t *) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t, cudnnMathType_t *))dlsym(RTLD_NEXT, "cudnnGetConvolutionMathType");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionMathType", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionMathType(convDesc, mathType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionMathType cudnnGetConvolutionMathType


#undef cudnnSetConvolutionGroupCount
cudnnStatus_t cudnnSetConvolutionGroupCount(cudnnConvolutionDescriptor_t convDesc, int groupCount){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetConvolutionGroupCount) (cudnnConvolutionDescriptor_t, int) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t, int))dlsym(RTLD_NEXT, "cudnnSetConvolutionGroupCount");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetConvolutionGroupCount", kApiTypeCuDNN);

    lretval = lcudnnSetConvolutionGroupCount(convDesc, groupCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetConvolutionGroupCount cudnnSetConvolutionGroupCount


#undef cudnnGetConvolutionGroupCount
cudnnStatus_t cudnnGetConvolutionGroupCount(cudnnConvolutionDescriptor_t convDesc, int * groupCount){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionGroupCount) (cudnnConvolutionDescriptor_t, int *) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t, int *))dlsym(RTLD_NEXT, "cudnnGetConvolutionGroupCount");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionGroupCount", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionGroupCount(convDesc, groupCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionGroupCount cudnnGetConvolutionGroupCount


#undef cudnnSetConvolutionReorderType
cudnnStatus_t cudnnSetConvolutionReorderType(cudnnConvolutionDescriptor_t convDesc, cudnnReorderType_t reorderType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetConvolutionReorderType) (cudnnConvolutionDescriptor_t, cudnnReorderType_t) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t, cudnnReorderType_t))dlsym(RTLD_NEXT, "cudnnSetConvolutionReorderType");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetConvolutionReorderType", kApiTypeCuDNN);

    lretval = lcudnnSetConvolutionReorderType(convDesc, reorderType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetConvolutionReorderType cudnnSetConvolutionReorderType


#undef cudnnGetConvolutionReorderType
cudnnStatus_t cudnnGetConvolutionReorderType(cudnnConvolutionDescriptor_t convDesc, cudnnReorderType_t * reorderType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionReorderType) (cudnnConvolutionDescriptor_t, cudnnReorderType_t *) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t, cudnnReorderType_t *))dlsym(RTLD_NEXT, "cudnnGetConvolutionReorderType");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionReorderType", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionReorderType(convDesc, reorderType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionReorderType cudnnGetConvolutionReorderType


#undef cudnnSetConvolution2dDescriptor
cudnnStatus_t cudnnSetConvolution2dDescriptor(cudnnConvolutionDescriptor_t convDesc, int pad_h, int pad_w, int u, int v, int dilation_h, int dilation_w, cudnnConvolutionMode_t mode, cudnnDataType_t computeType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetConvolution2dDescriptor) (cudnnConvolutionDescriptor_t, int, int, int, int, int, int, cudnnConvolutionMode_t, cudnnDataType_t) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t, int, int, int, int, int, int, cudnnConvolutionMode_t, cudnnDataType_t))dlsym(RTLD_NEXT, "cudnnSetConvolution2dDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetConvolution2dDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetConvolution2dDescriptor(convDesc, pad_h, pad_w, u, v, dilation_h, dilation_w, mode, computeType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetConvolution2dDescriptor cudnnSetConvolution2dDescriptor


#undef cudnnGetConvolution2dDescriptor
cudnnStatus_t cudnnGetConvolution2dDescriptor(cudnnConvolutionDescriptor_t const convDesc, int * pad_h, int * pad_w, int * u, int * v, int * dilation_h, int * dilation_w, cudnnConvolutionMode_t * mode, cudnnDataType_t * computeType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolution2dDescriptor) (cudnnConvolutionDescriptor_t const, int *, int *, int *, int *, int *, int *, cudnnConvolutionMode_t *, cudnnDataType_t *) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t const, int *, int *, int *, int *, int *, int *, cudnnConvolutionMode_t *, cudnnDataType_t *))dlsym(RTLD_NEXT, "cudnnGetConvolution2dDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolution2dDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetConvolution2dDescriptor(convDesc, pad_h, pad_w, u, v, dilation_h, dilation_w, mode, computeType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolution2dDescriptor cudnnGetConvolution2dDescriptor


#undef cudnnSetConvolutionNdDescriptor
cudnnStatus_t cudnnSetConvolutionNdDescriptor(cudnnConvolutionDescriptor_t convDesc, int arrayLength, int const * padA, int const * filterStrideA, int const * dilationA, cudnnConvolutionMode_t mode, cudnnDataType_t computeType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetConvolutionNdDescriptor) (cudnnConvolutionDescriptor_t, int, int const *, int const *, int const *, cudnnConvolutionMode_t, cudnnDataType_t) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t, int, int const *, int const *, int const *, cudnnConvolutionMode_t, cudnnDataType_t))dlsym(RTLD_NEXT, "cudnnSetConvolutionNdDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetConvolutionNdDescriptor", kApiTypeCuDNN);

    lretval = lcudnnSetConvolutionNdDescriptor(convDesc, arrayLength, padA, filterStrideA, dilationA, mode, computeType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetConvolutionNdDescriptor cudnnSetConvolutionNdDescriptor


#undef cudnnGetConvolutionNdDescriptor
cudnnStatus_t cudnnGetConvolutionNdDescriptor(cudnnConvolutionDescriptor_t const convDesc, int arrayLengthRequested, int * arrayLength, int * padA, int * strideA, int * dilationA, cudnnConvolutionMode_t * mode, cudnnDataType_t * computeType){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionNdDescriptor) (cudnnConvolutionDescriptor_t const, int, int *, int *, int *, int *, cudnnConvolutionMode_t *, cudnnDataType_t *) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t const, int, int *, int *, int *, int *, cudnnConvolutionMode_t *, cudnnDataType_t *))dlsym(RTLD_NEXT, "cudnnGetConvolutionNdDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionNdDescriptor", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionNdDescriptor(convDesc, arrayLengthRequested, arrayLength, padA, strideA, dilationA, mode, computeType);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionNdDescriptor cudnnGetConvolutionNdDescriptor


#undef cudnnGetConvolution2dForwardOutputDim
cudnnStatus_t cudnnGetConvolution2dForwardOutputDim(cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const inputTensorDesc, cudnnFilterDescriptor_t const filterDesc, int * n, int * c, int * h, int * w){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolution2dForwardOutputDim) (cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, int *, int *, int *, int *) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, int *, int *, int *, int *))dlsym(RTLD_NEXT, "cudnnGetConvolution2dForwardOutputDim");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolution2dForwardOutputDim", kApiTypeCuDNN);

    lretval = lcudnnGetConvolution2dForwardOutputDim(convDesc, inputTensorDesc, filterDesc, n, c, h, w);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolution2dForwardOutputDim cudnnGetConvolution2dForwardOutputDim


#undef cudnnGetConvolutionNdForwardOutputDim
cudnnStatus_t cudnnGetConvolutionNdForwardOutputDim(cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const inputTensorDesc, cudnnFilterDescriptor_t const filterDesc, int nbDims, int * tensorOuputDimA){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionNdForwardOutputDim) (cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, int, int *) = (cudnnStatus_t (*)(cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, int, int *))dlsym(RTLD_NEXT, "cudnnGetConvolutionNdForwardOutputDim");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionNdForwardOutputDim", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionNdForwardOutputDim(convDesc, inputTensorDesc, filterDesc, nbDims, tensorOuputDimA);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionNdForwardOutputDim cudnnGetConvolutionNdForwardOutputDim


#undef cudnnGetConvolutionForwardAlgorithmMaxCount
cudnnStatus_t cudnnGetConvolutionForwardAlgorithmMaxCount(cudnnHandle_t handle, int * count){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionForwardAlgorithmMaxCount) (cudnnHandle_t, int *) = (cudnnStatus_t (*)(cudnnHandle_t, int *))dlsym(RTLD_NEXT, "cudnnGetConvolutionForwardAlgorithmMaxCount");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionForwardAlgorithmMaxCount", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionForwardAlgorithmMaxCount(handle, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionForwardAlgorithmMaxCount cudnnGetConvolutionForwardAlgorithmMaxCount


#undef cudnnGetConvolutionForwardAlgorithm_v7
cudnnStatus_t cudnnGetConvolutionForwardAlgorithm_v7(cudnnHandle_t handle, cudnnTensorDescriptor_t const srcDesc, cudnnFilterDescriptor_t const filterDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const destDesc, int const requestedAlgoCount, int * returnedAlgoCount, cudnnConvolutionFwdAlgoPerf_t * perfResults){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionForwardAlgorithm_v7) (cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, int const, int *, cudnnConvolutionFwdAlgoPerf_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, int const, int *, cudnnConvolutionFwdAlgoPerf_t *))dlsym(RTLD_NEXT, "cudnnGetConvolutionForwardAlgorithm_v7");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionForwardAlgorithm_v7", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionForwardAlgorithm_v7(handle, srcDesc, filterDesc, convDesc, destDesc, requestedAlgoCount, returnedAlgoCount, perfResults);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionForwardAlgorithm_v7 cudnnGetConvolutionForwardAlgorithm_v7


#undef cudnnFindConvolutionForwardAlgorithm
cudnnStatus_t cudnnFindConvolutionForwardAlgorithm(cudnnHandle_t handle, cudnnTensorDescriptor_t const xDesc, cudnnFilterDescriptor_t const wDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const yDesc, int const requestedAlgoCount, int * returnedAlgoCount, cudnnConvolutionFwdAlgoPerf_t * perfResults){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindConvolutionForwardAlgorithm) (cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, int const, int *, cudnnConvolutionFwdAlgoPerf_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, int const, int *, cudnnConvolutionFwdAlgoPerf_t *))dlsym(RTLD_NEXT, "cudnnFindConvolutionForwardAlgorithm");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindConvolutionForwardAlgorithm", kApiTypeCuDNN);

    lretval = lcudnnFindConvolutionForwardAlgorithm(handle, xDesc, wDesc, convDesc, yDesc, requestedAlgoCount, returnedAlgoCount, perfResults);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindConvolutionForwardAlgorithm cudnnFindConvolutionForwardAlgorithm


#undef cudnnFindConvolutionForwardAlgorithmEx
cudnnStatus_t cudnnFindConvolutionForwardAlgorithmEx(cudnnHandle_t handle, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const yDesc, void * y, int const requestedAlgoCount, int * returnedAlgoCount, cudnnConvolutionFwdAlgoPerf_t * perfResults, void * workSpace, size_t workSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindConvolutionForwardAlgorithmEx) (cudnnHandle_t, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, void *, int const, int *, cudnnConvolutionFwdAlgoPerf_t *, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, void *, int const, int *, cudnnConvolutionFwdAlgoPerf_t *, void *, size_t))dlsym(RTLD_NEXT, "cudnnFindConvolutionForwardAlgorithmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindConvolutionForwardAlgorithmEx", kApiTypeCuDNN);

    lretval = lcudnnFindConvolutionForwardAlgorithmEx(handle, xDesc, x, wDesc, w, convDesc, yDesc, y, requestedAlgoCount, returnedAlgoCount, perfResults, workSpace, workSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindConvolutionForwardAlgorithmEx cudnnFindConvolutionForwardAlgorithmEx


#undef cudnnIm2Col
cudnnStatus_t cudnnIm2Col(cudnnHandle_t handle, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnFilterDescriptor_t const wDesc, cudnnConvolutionDescriptor_t const convDesc, void * colBuffer){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnIm2Col) (cudnnHandle_t, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, cudnnConvolutionDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, cudnnConvolutionDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnIm2Col");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnIm2Col", kApiTypeCuDNN);

    lretval = lcudnnIm2Col(handle, xDesc, x, wDesc, convDesc, colBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnIm2Col cudnnIm2Col


#undef cudnnReorderFilterAndBias
cudnnStatus_t cudnnReorderFilterAndBias(cudnnHandle_t handle, cudnnFilterDescriptor_t const filterDesc, cudnnReorderType_t reorderType, void const * filterData, void * reorderedFilterData, int reorderBias, void const * biasData, void * reorderedBiasData){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnReorderFilterAndBias) (cudnnHandle_t, cudnnFilterDescriptor_t const, cudnnReorderType_t, void const *, void *, int, void const *, void *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnFilterDescriptor_t const, cudnnReorderType_t, void const *, void *, int, void const *, void *))dlsym(RTLD_NEXT, "cudnnReorderFilterAndBias");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnReorderFilterAndBias", kApiTypeCuDNN);

    lretval = lcudnnReorderFilterAndBias(handle, filterDesc, reorderType, filterData, reorderedFilterData, reorderBias, biasData, reorderedBiasData);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnReorderFilterAndBias cudnnReorderFilterAndBias


#undef cudnnGetConvolutionForwardWorkspaceSize
cudnnStatus_t cudnnGetConvolutionForwardWorkspaceSize(cudnnHandle_t handle, cudnnTensorDescriptor_t const xDesc, cudnnFilterDescriptor_t const wDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const yDesc, cudnnConvolutionFwdAlgo_t algo, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionForwardWorkspaceSize) (cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionFwdAlgo_t, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnFilterDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionFwdAlgo_t, size_t *))dlsym(RTLD_NEXT, "cudnnGetConvolutionForwardWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionForwardWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionForwardWorkspaceSize(handle, xDesc, wDesc, convDesc, yDesc, algo, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionForwardWorkspaceSize cudnnGetConvolutionForwardWorkspaceSize


#undef cudnnConvolutionForward
cudnnStatus_t cudnnConvolutionForward(cudnnHandle_t handle, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnConvolutionDescriptor_t const convDesc, cudnnConvolutionFwdAlgo_t algo, void * workSpace, size_t workSpaceSizeInBytes, void const * beta, cudnnTensorDescriptor_t const yDesc, void * y){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnConvolutionForward) (cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnConvolutionFwdAlgo_t, void *, size_t, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnConvolutionFwdAlgo_t, void *, size_t, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnConvolutionForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnConvolutionForward", kApiTypeCuDNN);

    lretval = lcudnnConvolutionForward(handle, alpha, xDesc, x, wDesc, w, convDesc, algo, workSpace, workSpaceSizeInBytes, beta, yDesc, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnConvolutionForward cudnnConvolutionForward


#undef cudnnConvolutionBiasActivationForward
cudnnStatus_t cudnnConvolutionBiasActivationForward(cudnnHandle_t handle, void const * alpha1, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnConvolutionDescriptor_t const convDesc, cudnnConvolutionFwdAlgo_t algo, void * workSpace, size_t workSpaceSizeInBytes, void const * alpha2, cudnnTensorDescriptor_t const zDesc, void const * z, cudnnTensorDescriptor_t const biasDesc, void const * bias, cudnnActivationDescriptor_t const activationDesc, cudnnTensorDescriptor_t const yDesc, void * y){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnConvolutionBiasActivationForward) (cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnConvolutionFwdAlgo_t, void *, size_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnFilterDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnConvolutionFwdAlgo_t, void *, size_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnActivationDescriptor_t const, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnConvolutionBiasActivationForward");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnConvolutionBiasActivationForward", kApiTypeCuDNN);

    lretval = lcudnnConvolutionBiasActivationForward(handle, alpha1, xDesc, x, wDesc, w, convDesc, algo, workSpace, workSpaceSizeInBytes, alpha2, zDesc, z, biasDesc, bias, activationDesc, yDesc, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnConvolutionBiasActivationForward cudnnConvolutionBiasActivationForward


#undef cudnnGetConvolutionBackwardDataAlgorithmMaxCount
cudnnStatus_t cudnnGetConvolutionBackwardDataAlgorithmMaxCount(cudnnHandle_t handle, int * count){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionBackwardDataAlgorithmMaxCount) (cudnnHandle_t, int *) = (cudnnStatus_t (*)(cudnnHandle_t, int *))dlsym(RTLD_NEXT, "cudnnGetConvolutionBackwardDataAlgorithmMaxCount");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionBackwardDataAlgorithmMaxCount", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionBackwardDataAlgorithmMaxCount(handle, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionBackwardDataAlgorithmMaxCount cudnnGetConvolutionBackwardDataAlgorithmMaxCount


#undef cudnnFindConvolutionBackwardDataAlgorithm
cudnnStatus_t cudnnFindConvolutionBackwardDataAlgorithm(cudnnHandle_t handle, cudnnFilterDescriptor_t const wDesc, cudnnTensorDescriptor_t const dyDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const dxDesc, int const requestedAlgoCount, int * returnedAlgoCount, cudnnConvolutionBwdDataAlgoPerf_t * perfResults){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindConvolutionBackwardDataAlgorithm) (cudnnHandle_t, cudnnFilterDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, int const, int *, cudnnConvolutionBwdDataAlgoPerf_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnFilterDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, int const, int *, cudnnConvolutionBwdDataAlgoPerf_t *))dlsym(RTLD_NEXT, "cudnnFindConvolutionBackwardDataAlgorithm");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindConvolutionBackwardDataAlgorithm", kApiTypeCuDNN);

    lretval = lcudnnFindConvolutionBackwardDataAlgorithm(handle, wDesc, dyDesc, convDesc, dxDesc, requestedAlgoCount, returnedAlgoCount, perfResults);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindConvolutionBackwardDataAlgorithm cudnnFindConvolutionBackwardDataAlgorithm


#undef cudnnFindConvolutionBackwardDataAlgorithmEx
cudnnStatus_t cudnnFindConvolutionBackwardDataAlgorithmEx(cudnnHandle_t handle, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnTensorDescriptor_t const dyDesc, void const * dy, cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const dxDesc, void * dx, int const requestedAlgoCount, int * returnedAlgoCount, cudnnConvolutionBwdDataAlgoPerf_t * perfResults, void * workSpace, size_t workSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindConvolutionBackwardDataAlgorithmEx) (cudnnHandle_t, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, void *, int const, int *, cudnnConvolutionBwdDataAlgoPerf_t *, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, void *, int const, int *, cudnnConvolutionBwdDataAlgoPerf_t *, void *, size_t))dlsym(RTLD_NEXT, "cudnnFindConvolutionBackwardDataAlgorithmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindConvolutionBackwardDataAlgorithmEx", kApiTypeCuDNN);

    lretval = lcudnnFindConvolutionBackwardDataAlgorithmEx(handle, wDesc, w, dyDesc, dy, convDesc, dxDesc, dx, requestedAlgoCount, returnedAlgoCount, perfResults, workSpace, workSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindConvolutionBackwardDataAlgorithmEx cudnnFindConvolutionBackwardDataAlgorithmEx


#undef cudnnGetConvolutionBackwardDataAlgorithm_v7
cudnnStatus_t cudnnGetConvolutionBackwardDataAlgorithm_v7(cudnnHandle_t handle, cudnnFilterDescriptor_t const filterDesc, cudnnTensorDescriptor_t const diffDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const gradDesc, int const requestedAlgoCount, int * returnedAlgoCount, cudnnConvolutionBwdDataAlgoPerf_t * perfResults){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionBackwardDataAlgorithm_v7) (cudnnHandle_t, cudnnFilterDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, int const, int *, cudnnConvolutionBwdDataAlgoPerf_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnFilterDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, int const, int *, cudnnConvolutionBwdDataAlgoPerf_t *))dlsym(RTLD_NEXT, "cudnnGetConvolutionBackwardDataAlgorithm_v7");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionBackwardDataAlgorithm_v7", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionBackwardDataAlgorithm_v7(handle, filterDesc, diffDesc, convDesc, gradDesc, requestedAlgoCount, returnedAlgoCount, perfResults);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionBackwardDataAlgorithm_v7 cudnnGetConvolutionBackwardDataAlgorithm_v7


#undef cudnnGetConvolutionBackwardDataWorkspaceSize
cudnnStatus_t cudnnGetConvolutionBackwardDataWorkspaceSize(cudnnHandle_t handle, cudnnFilterDescriptor_t const wDesc, cudnnTensorDescriptor_t const dyDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const dxDesc, cudnnConvolutionBwdDataAlgo_t algo, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionBackwardDataWorkspaceSize) (cudnnHandle_t, cudnnFilterDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionBwdDataAlgo_t, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnFilterDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionBwdDataAlgo_t, size_t *))dlsym(RTLD_NEXT, "cudnnGetConvolutionBackwardDataWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionBackwardDataWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionBackwardDataWorkspaceSize(handle, wDesc, dyDesc, convDesc, dxDesc, algo, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionBackwardDataWorkspaceSize cudnnGetConvolutionBackwardDataWorkspaceSize


#undef cudnnConvolutionBackwardData
cudnnStatus_t cudnnConvolutionBackwardData(cudnnHandle_t handle, void const * alpha, cudnnFilterDescriptor_t const wDesc, void const * w, cudnnTensorDescriptor_t const dyDesc, void const * dy, cudnnConvolutionDescriptor_t const convDesc, cudnnConvolutionBwdDataAlgo_t algo, void * workSpace, size_t workSpaceSizeInBytes, void const * beta, cudnnTensorDescriptor_t const dxDesc, void * dx){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnConvolutionBackwardData) (cudnnHandle_t, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnConvolutionBwdDataAlgo_t, void *, size_t, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, void const *, cudnnFilterDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnConvolutionBwdDataAlgo_t, void *, size_t, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnConvolutionBackwardData");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnConvolutionBackwardData", kApiTypeCuDNN);

    lretval = lcudnnConvolutionBackwardData(handle, alpha, wDesc, w, dyDesc, dy, convDesc, algo, workSpace, workSpaceSizeInBytes, beta, dxDesc, dx);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnConvolutionBackwardData cudnnConvolutionBackwardData


#undef cudnnGetFoldedConvBackwardDataDescriptors
cudnnStatus_t cudnnGetFoldedConvBackwardDataDescriptors(cudnnHandle_t const handle, cudnnFilterDescriptor_t const filterDesc, cudnnTensorDescriptor_t const diffDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnTensorDescriptor_t const gradDesc, cudnnTensorFormat_t const transformFormat, cudnnFilterDescriptor_t foldedFilterDesc, cudnnTensorDescriptor_t paddedDiffDesc, cudnnConvolutionDescriptor_t foldedConvDesc, cudnnTensorDescriptor_t foldedGradDesc, cudnnTensorTransformDescriptor_t filterFoldTransDesc, cudnnTensorTransformDescriptor_t diffPadTransDesc, cudnnTensorTransformDescriptor_t gradFoldTransDesc, cudnnTensorTransformDescriptor_t gradUnfoldTransDesc){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetFoldedConvBackwardDataDescriptors) (cudnnHandle_t const, cudnnFilterDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorFormat_t const, cudnnFilterDescriptor_t, cudnnTensorDescriptor_t, cudnnConvolutionDescriptor_t, cudnnTensorDescriptor_t, cudnnTensorTransformDescriptor_t, cudnnTensorTransformDescriptor_t, cudnnTensorTransformDescriptor_t, cudnnTensorTransformDescriptor_t) = (cudnnStatus_t (*)(cudnnHandle_t const, cudnnFilterDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnTensorDescriptor_t const, cudnnTensorFormat_t const, cudnnFilterDescriptor_t, cudnnTensorDescriptor_t, cudnnConvolutionDescriptor_t, cudnnTensorDescriptor_t, cudnnTensorTransformDescriptor_t, cudnnTensorTransformDescriptor_t, cudnnTensorTransformDescriptor_t, cudnnTensorTransformDescriptor_t))dlsym(RTLD_NEXT, "cudnnGetFoldedConvBackwardDataDescriptors");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetFoldedConvBackwardDataDescriptors", kApiTypeCuDNN);

    lretval = lcudnnGetFoldedConvBackwardDataDescriptors(handle, filterDesc, diffDesc, convDesc, gradDesc, transformFormat, foldedFilterDesc, paddedDiffDesc, foldedConvDesc, foldedGradDesc, filterFoldTransDesc, diffPadTransDesc, gradFoldTransDesc, gradUnfoldTransDesc);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetFoldedConvBackwardDataDescriptors cudnnGetFoldedConvBackwardDataDescriptors


#undef cudnnCnnInferVersionCheck
cudnnStatus_t cudnnCnnInferVersionCheck(){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCnnInferVersionCheck) () = (cudnnStatus_t (*)())dlsym(RTLD_NEXT, "cudnnCnnInferVersionCheck");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCnnInferVersionCheck", kApiTypeCuDNN);

    lretval = lcudnnCnnInferVersionCheck();
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCnnInferVersionCheck cudnnCnnInferVersionCheck


#undef cudnnGetConvolutionBackwardFilterAlgorithmMaxCount
cudnnStatus_t cudnnGetConvolutionBackwardFilterAlgorithmMaxCount(cudnnHandle_t handle, int * count){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionBackwardFilterAlgorithmMaxCount) (cudnnHandle_t, int *) = (cudnnStatus_t (*)(cudnnHandle_t, int *))dlsym(RTLD_NEXT, "cudnnGetConvolutionBackwardFilterAlgorithmMaxCount");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionBackwardFilterAlgorithmMaxCount", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionBackwardFilterAlgorithmMaxCount(handle, count);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionBackwardFilterAlgorithmMaxCount cudnnGetConvolutionBackwardFilterAlgorithmMaxCount


#undef cudnnFindConvolutionBackwardFilterAlgorithm
cudnnStatus_t cudnnFindConvolutionBackwardFilterAlgorithm(cudnnHandle_t handle, cudnnTensorDescriptor_t const xDesc, cudnnTensorDescriptor_t const dyDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnFilterDescriptor_t const dwDesc, int const requestedAlgoCount, int * returnedAlgoCount, cudnnConvolutionBwdFilterAlgoPerf_t * perfResults){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindConvolutionBackwardFilterAlgorithm) (cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnFilterDescriptor_t const, int const, int *, cudnnConvolutionBwdFilterAlgoPerf_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnFilterDescriptor_t const, int const, int *, cudnnConvolutionBwdFilterAlgoPerf_t *))dlsym(RTLD_NEXT, "cudnnFindConvolutionBackwardFilterAlgorithm");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindConvolutionBackwardFilterAlgorithm", kApiTypeCuDNN);

    lretval = lcudnnFindConvolutionBackwardFilterAlgorithm(handle, xDesc, dyDesc, convDesc, dwDesc, requestedAlgoCount, returnedAlgoCount, perfResults);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindConvolutionBackwardFilterAlgorithm cudnnFindConvolutionBackwardFilterAlgorithm


#undef cudnnFindConvolutionBackwardFilterAlgorithmEx
cudnnStatus_t cudnnFindConvolutionBackwardFilterAlgorithmEx(cudnnHandle_t handle, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnTensorDescriptor_t const dyDesc, void const * y, cudnnConvolutionDescriptor_t const convDesc, cudnnFilterDescriptor_t const dwDesc, void * dw, int const requestedAlgoCount, int * returnedAlgoCount, cudnnConvolutionBwdFilterAlgoPerf_t * perfResults, void * workSpace, size_t workSpaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFindConvolutionBackwardFilterAlgorithmEx) (cudnnHandle_t, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnFilterDescriptor_t const, void *, int const, int *, cudnnConvolutionBwdFilterAlgoPerf_t *, void *, size_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnFilterDescriptor_t const, void *, int const, int *, cudnnConvolutionBwdFilterAlgoPerf_t *, void *, size_t))dlsym(RTLD_NEXT, "cudnnFindConvolutionBackwardFilterAlgorithmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFindConvolutionBackwardFilterAlgorithmEx", kApiTypeCuDNN);

    lretval = lcudnnFindConvolutionBackwardFilterAlgorithmEx(handle, xDesc, x, dyDesc, y, convDesc, dwDesc, dw, requestedAlgoCount, returnedAlgoCount, perfResults, workSpace, workSpaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFindConvolutionBackwardFilterAlgorithmEx cudnnFindConvolutionBackwardFilterAlgorithmEx


#undef cudnnGetConvolutionBackwardFilterAlgorithm_v7
cudnnStatus_t cudnnGetConvolutionBackwardFilterAlgorithm_v7(cudnnHandle_t handle, cudnnTensorDescriptor_t const srcDesc, cudnnTensorDescriptor_t const diffDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnFilterDescriptor_t const gradDesc, int const requestedAlgoCount, int * returnedAlgoCount, cudnnConvolutionBwdFilterAlgoPerf_t * perfResults){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionBackwardFilterAlgorithm_v7) (cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnFilterDescriptor_t const, int const, int *, cudnnConvolutionBwdFilterAlgoPerf_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnFilterDescriptor_t const, int const, int *, cudnnConvolutionBwdFilterAlgoPerf_t *))dlsym(RTLD_NEXT, "cudnnGetConvolutionBackwardFilterAlgorithm_v7");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionBackwardFilterAlgorithm_v7", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionBackwardFilterAlgorithm_v7(handle, srcDesc, diffDesc, convDesc, gradDesc, requestedAlgoCount, returnedAlgoCount, perfResults);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionBackwardFilterAlgorithm_v7 cudnnGetConvolutionBackwardFilterAlgorithm_v7


#undef cudnnGetConvolutionBackwardFilterWorkspaceSize
cudnnStatus_t cudnnGetConvolutionBackwardFilterWorkspaceSize(cudnnHandle_t handle, cudnnTensorDescriptor_t const xDesc, cudnnTensorDescriptor_t const dyDesc, cudnnConvolutionDescriptor_t const convDesc, cudnnFilterDescriptor_t const gradDesc, cudnnConvolutionBwdFilterAlgo_t algo, size_t * sizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetConvolutionBackwardFilterWorkspaceSize) (cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnFilterDescriptor_t const, cudnnConvolutionBwdFilterAlgo_t, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnTensorDescriptor_t const, cudnnTensorDescriptor_t const, cudnnConvolutionDescriptor_t const, cudnnFilterDescriptor_t const, cudnnConvolutionBwdFilterAlgo_t, size_t *))dlsym(RTLD_NEXT, "cudnnGetConvolutionBackwardFilterWorkspaceSize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetConvolutionBackwardFilterWorkspaceSize", kApiTypeCuDNN);

    lretval = lcudnnGetConvolutionBackwardFilterWorkspaceSize(handle, xDesc, dyDesc, convDesc, gradDesc, algo, sizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetConvolutionBackwardFilterWorkspaceSize cudnnGetConvolutionBackwardFilterWorkspaceSize


#undef cudnnConvolutionBackwardFilter
cudnnStatus_t cudnnConvolutionBackwardFilter(cudnnHandle_t handle, void const * alpha, cudnnTensorDescriptor_t const xDesc, void const * x, cudnnTensorDescriptor_t const dyDesc, void const * dy, cudnnConvolutionDescriptor_t const convDesc, cudnnConvolutionBwdFilterAlgo_t algo, void * workSpace, size_t workSpaceSizeInBytes, void const * beta, cudnnFilterDescriptor_t const dwDesc, void * dw){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnConvolutionBackwardFilter) (cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnConvolutionBwdFilterAlgo_t, void *, size_t, void const *, cudnnFilterDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, cudnnTensorDescriptor_t const, void const *, cudnnConvolutionDescriptor_t const, cudnnConvolutionBwdFilterAlgo_t, void *, size_t, void const *, cudnnFilterDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnConvolutionBackwardFilter");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnConvolutionBackwardFilter", kApiTypeCuDNN);

    lretval = lcudnnConvolutionBackwardFilter(handle, alpha, xDesc, x, dyDesc, dy, convDesc, algo, workSpace, workSpaceSizeInBytes, beta, dwDesc, dw);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnConvolutionBackwardFilter cudnnConvolutionBackwardFilter


#undef cudnnConvolutionBackwardBias
cudnnStatus_t cudnnConvolutionBackwardBias(cudnnHandle_t handle, void const * alpha, cudnnTensorDescriptor_t const dyDesc, void const * dy, void const * beta, cudnnTensorDescriptor_t const dbDesc, void * db){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnConvolutionBackwardBias) (cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *) = (cudnnStatus_t (*)(cudnnHandle_t, void const *, cudnnTensorDescriptor_t const, void const *, void const *, cudnnTensorDescriptor_t const, void *))dlsym(RTLD_NEXT, "cudnnConvolutionBackwardBias");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnConvolutionBackwardBias", kApiTypeCuDNN);

    lretval = lcudnnConvolutionBackwardBias(handle, alpha, dyDesc, dy, beta, dbDesc, db);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnConvolutionBackwardBias cudnnConvolutionBackwardBias


#undef cudnnCreateFusedOpsConstParamPack
cudnnStatus_t cudnnCreateFusedOpsConstParamPack(cudnnFusedOpsConstParamPack_t * constPack, cudnnFusedOps_t ops){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateFusedOpsConstParamPack) (cudnnFusedOpsConstParamPack_t *, cudnnFusedOps_t) = (cudnnStatus_t (*)(cudnnFusedOpsConstParamPack_t *, cudnnFusedOps_t))dlsym(RTLD_NEXT, "cudnnCreateFusedOpsConstParamPack");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateFusedOpsConstParamPack", kApiTypeCuDNN);

    lretval = lcudnnCreateFusedOpsConstParamPack(constPack, ops);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateFusedOpsConstParamPack cudnnCreateFusedOpsConstParamPack


#undef cudnnDestroyFusedOpsConstParamPack
cudnnStatus_t cudnnDestroyFusedOpsConstParamPack(cudnnFusedOpsConstParamPack_t constPack){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyFusedOpsConstParamPack) (cudnnFusedOpsConstParamPack_t) = (cudnnStatus_t (*)(cudnnFusedOpsConstParamPack_t))dlsym(RTLD_NEXT, "cudnnDestroyFusedOpsConstParamPack");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyFusedOpsConstParamPack", kApiTypeCuDNN);

    lretval = lcudnnDestroyFusedOpsConstParamPack(constPack);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyFusedOpsConstParamPack cudnnDestroyFusedOpsConstParamPack


#undef cudnnSetFusedOpsConstParamPackAttribute
cudnnStatus_t cudnnSetFusedOpsConstParamPackAttribute(cudnnFusedOpsConstParamPack_t constPack, cudnnFusedOpsConstParamLabel_t paramLabel, void const * param){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetFusedOpsConstParamPackAttribute) (cudnnFusedOpsConstParamPack_t, cudnnFusedOpsConstParamLabel_t, void const *) = (cudnnStatus_t (*)(cudnnFusedOpsConstParamPack_t, cudnnFusedOpsConstParamLabel_t, void const *))dlsym(RTLD_NEXT, "cudnnSetFusedOpsConstParamPackAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetFusedOpsConstParamPackAttribute", kApiTypeCuDNN);

    lretval = lcudnnSetFusedOpsConstParamPackAttribute(constPack, paramLabel, param);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetFusedOpsConstParamPackAttribute cudnnSetFusedOpsConstParamPackAttribute


#undef cudnnGetFusedOpsConstParamPackAttribute
cudnnStatus_t cudnnGetFusedOpsConstParamPackAttribute(cudnnFusedOpsConstParamPack_t const constPack, cudnnFusedOpsConstParamLabel_t paramLabel, void * param, int * isNULL){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetFusedOpsConstParamPackAttribute) (cudnnFusedOpsConstParamPack_t const, cudnnFusedOpsConstParamLabel_t, void *, int *) = (cudnnStatus_t (*)(cudnnFusedOpsConstParamPack_t const, cudnnFusedOpsConstParamLabel_t, void *, int *))dlsym(RTLD_NEXT, "cudnnGetFusedOpsConstParamPackAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetFusedOpsConstParamPackAttribute", kApiTypeCuDNN);

    lretval = lcudnnGetFusedOpsConstParamPackAttribute(constPack, paramLabel, param, isNULL);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetFusedOpsConstParamPackAttribute cudnnGetFusedOpsConstParamPackAttribute


#undef cudnnCreateFusedOpsVariantParamPack
cudnnStatus_t cudnnCreateFusedOpsVariantParamPack(cudnnFusedOpsVariantParamPack_t * varPack, cudnnFusedOps_t ops){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateFusedOpsVariantParamPack) (cudnnFusedOpsVariantParamPack_t *, cudnnFusedOps_t) = (cudnnStatus_t (*)(cudnnFusedOpsVariantParamPack_t *, cudnnFusedOps_t))dlsym(RTLD_NEXT, "cudnnCreateFusedOpsVariantParamPack");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateFusedOpsVariantParamPack", kApiTypeCuDNN);

    lretval = lcudnnCreateFusedOpsVariantParamPack(varPack, ops);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateFusedOpsVariantParamPack cudnnCreateFusedOpsVariantParamPack


#undef cudnnDestroyFusedOpsVariantParamPack
cudnnStatus_t cudnnDestroyFusedOpsVariantParamPack(cudnnFusedOpsVariantParamPack_t varPack){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyFusedOpsVariantParamPack) (cudnnFusedOpsVariantParamPack_t) = (cudnnStatus_t (*)(cudnnFusedOpsVariantParamPack_t))dlsym(RTLD_NEXT, "cudnnDestroyFusedOpsVariantParamPack");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyFusedOpsVariantParamPack", kApiTypeCuDNN);

    lretval = lcudnnDestroyFusedOpsVariantParamPack(varPack);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyFusedOpsVariantParamPack cudnnDestroyFusedOpsVariantParamPack


#undef cudnnSetFusedOpsVariantParamPackAttribute
cudnnStatus_t cudnnSetFusedOpsVariantParamPackAttribute(cudnnFusedOpsVariantParamPack_t varPack, cudnnFusedOpsVariantParamLabel_t paramLabel, void * ptr){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnSetFusedOpsVariantParamPackAttribute) (cudnnFusedOpsVariantParamPack_t, cudnnFusedOpsVariantParamLabel_t, void *) = (cudnnStatus_t (*)(cudnnFusedOpsVariantParamPack_t, cudnnFusedOpsVariantParamLabel_t, void *))dlsym(RTLD_NEXT, "cudnnSetFusedOpsVariantParamPackAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnSetFusedOpsVariantParamPackAttribute", kApiTypeCuDNN);

    lretval = lcudnnSetFusedOpsVariantParamPackAttribute(varPack, paramLabel, ptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnSetFusedOpsVariantParamPackAttribute cudnnSetFusedOpsVariantParamPackAttribute


#undef cudnnGetFusedOpsVariantParamPackAttribute
cudnnStatus_t cudnnGetFusedOpsVariantParamPackAttribute(cudnnFusedOpsVariantParamPack_t const varPack, cudnnFusedOpsVariantParamLabel_t paramLabel, void * ptr){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnGetFusedOpsVariantParamPackAttribute) (cudnnFusedOpsVariantParamPack_t const, cudnnFusedOpsVariantParamLabel_t, void *) = (cudnnStatus_t (*)(cudnnFusedOpsVariantParamPack_t const, cudnnFusedOpsVariantParamLabel_t, void *))dlsym(RTLD_NEXT, "cudnnGetFusedOpsVariantParamPackAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnGetFusedOpsVariantParamPackAttribute", kApiTypeCuDNN);

    lretval = lcudnnGetFusedOpsVariantParamPackAttribute(varPack, paramLabel, ptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnGetFusedOpsVariantParamPackAttribute cudnnGetFusedOpsVariantParamPackAttribute


#undef cudnnCreateFusedOpsPlan
cudnnStatus_t cudnnCreateFusedOpsPlan(cudnnFusedOpsPlan_t * plan, cudnnFusedOps_t ops){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCreateFusedOpsPlan) (cudnnFusedOpsPlan_t *, cudnnFusedOps_t) = (cudnnStatus_t (*)(cudnnFusedOpsPlan_t *, cudnnFusedOps_t))dlsym(RTLD_NEXT, "cudnnCreateFusedOpsPlan");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCreateFusedOpsPlan", kApiTypeCuDNN);

    lretval = lcudnnCreateFusedOpsPlan(plan, ops);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCreateFusedOpsPlan cudnnCreateFusedOpsPlan


#undef cudnnDestroyFusedOpsPlan
cudnnStatus_t cudnnDestroyFusedOpsPlan(cudnnFusedOpsPlan_t plan){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnDestroyFusedOpsPlan) (cudnnFusedOpsPlan_t) = (cudnnStatus_t (*)(cudnnFusedOpsPlan_t))dlsym(RTLD_NEXT, "cudnnDestroyFusedOpsPlan");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnDestroyFusedOpsPlan", kApiTypeCuDNN);

    lretval = lcudnnDestroyFusedOpsPlan(plan);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnDestroyFusedOpsPlan cudnnDestroyFusedOpsPlan


#undef cudnnMakeFusedOpsPlan
cudnnStatus_t cudnnMakeFusedOpsPlan(cudnnHandle_t handle, cudnnFusedOpsPlan_t plan, cudnnFusedOpsConstParamPack_t const constPack, size_t * workspaceSizeInBytes){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnMakeFusedOpsPlan) (cudnnHandle_t, cudnnFusedOpsPlan_t, cudnnFusedOpsConstParamPack_t const, size_t *) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnFusedOpsPlan_t, cudnnFusedOpsConstParamPack_t const, size_t *))dlsym(RTLD_NEXT, "cudnnMakeFusedOpsPlan");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnMakeFusedOpsPlan", kApiTypeCuDNN);

    lretval = lcudnnMakeFusedOpsPlan(handle, plan, constPack, workspaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnMakeFusedOpsPlan cudnnMakeFusedOpsPlan


#undef cudnnFusedOpsExecute
cudnnStatus_t cudnnFusedOpsExecute(cudnnHandle_t handle, cudnnFusedOpsPlan_t const plan, cudnnFusedOpsVariantParamPack_t varPack){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnFusedOpsExecute) (cudnnHandle_t, cudnnFusedOpsPlan_t const, cudnnFusedOpsVariantParamPack_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnFusedOpsPlan_t const, cudnnFusedOpsVariantParamPack_t))dlsym(RTLD_NEXT, "cudnnFusedOpsExecute");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnFusedOpsExecute", kApiTypeCuDNN);

    lretval = lcudnnFusedOpsExecute(handle, plan, varPack);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnFusedOpsExecute cudnnFusedOpsExecute


#undef cudnnCnnTrainVersionCheck
cudnnStatus_t cudnnCnnTrainVersionCheck(){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnCnnTrainVersionCheck) () = (cudnnStatus_t (*)())dlsym(RTLD_NEXT, "cudnnCnnTrainVersionCheck");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnCnnTrainVersionCheck", kApiTypeCuDNN);

    lretval = lcudnnCnnTrainVersionCheck();
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnCnnTrainVersionCheck cudnnCnnTrainVersionCheck


#undef cudnnBackendCreateDescriptor
cudnnStatus_t cudnnBackendCreateDescriptor(cudnnBackendDescriptorType_t descriptorType, cudnnBackendDescriptor_t * descriptor){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBackendCreateDescriptor) (cudnnBackendDescriptorType_t, cudnnBackendDescriptor_t *) = (cudnnStatus_t (*)(cudnnBackendDescriptorType_t, cudnnBackendDescriptor_t *))dlsym(RTLD_NEXT, "cudnnBackendCreateDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBackendCreateDescriptor", kApiTypeCuDNN);

    lretval = lcudnnBackendCreateDescriptor(descriptorType, descriptor);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBackendCreateDescriptor cudnnBackendCreateDescriptor


#undef cudnnBackendDestroyDescriptor
cudnnStatus_t cudnnBackendDestroyDescriptor(cudnnBackendDescriptor_t descriptor){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBackendDestroyDescriptor) (cudnnBackendDescriptor_t) = (cudnnStatus_t (*)(cudnnBackendDescriptor_t))dlsym(RTLD_NEXT, "cudnnBackendDestroyDescriptor");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBackendDestroyDescriptor", kApiTypeCuDNN);

    lretval = lcudnnBackendDestroyDescriptor(descriptor);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBackendDestroyDescriptor cudnnBackendDestroyDescriptor


#undef cudnnBackendInitialize
cudnnStatus_t cudnnBackendInitialize(cudnnBackendDescriptor_t descriptor){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBackendInitialize) (cudnnBackendDescriptor_t) = (cudnnStatus_t (*)(cudnnBackendDescriptor_t))dlsym(RTLD_NEXT, "cudnnBackendInitialize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBackendInitialize", kApiTypeCuDNN);

    lretval = lcudnnBackendInitialize(descriptor);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBackendInitialize cudnnBackendInitialize


#undef cudnnBackendFinalize
cudnnStatus_t cudnnBackendFinalize(cudnnBackendDescriptor_t descriptor){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBackendFinalize) (cudnnBackendDescriptor_t) = (cudnnStatus_t (*)(cudnnBackendDescriptor_t))dlsym(RTLD_NEXT, "cudnnBackendFinalize");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBackendFinalize", kApiTypeCuDNN);

    lretval = lcudnnBackendFinalize(descriptor);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBackendFinalize cudnnBackendFinalize


#undef cudnnBackendSetAttribute
cudnnStatus_t cudnnBackendSetAttribute(cudnnBackendDescriptor_t descriptor, cudnnBackendAttributeName_t attributeName, cudnnBackendAttributeType_t attributeType, int64_t elementCount, void const * arrayOfElements){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBackendSetAttribute) (cudnnBackendDescriptor_t, cudnnBackendAttributeName_t, cudnnBackendAttributeType_t, int64_t, void const *) = (cudnnStatus_t (*)(cudnnBackendDescriptor_t, cudnnBackendAttributeName_t, cudnnBackendAttributeType_t, int64_t, void const *))dlsym(RTLD_NEXT, "cudnnBackendSetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBackendSetAttribute", kApiTypeCuDNN);

    lretval = lcudnnBackendSetAttribute(descriptor, attributeName, attributeType, elementCount, arrayOfElements);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBackendSetAttribute cudnnBackendSetAttribute


#undef cudnnBackendGetAttribute
cudnnStatus_t cudnnBackendGetAttribute(cudnnBackendDescriptor_t const descriptor, cudnnBackendAttributeName_t attributeName, cudnnBackendAttributeType_t attributeType, int64_t requestedElementCount, int64_t * elementCount, void * arrayOfElements){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBackendGetAttribute) (cudnnBackendDescriptor_t const, cudnnBackendAttributeName_t, cudnnBackendAttributeType_t, int64_t, int64_t *, void *) = (cudnnStatus_t (*)(cudnnBackendDescriptor_t const, cudnnBackendAttributeName_t, cudnnBackendAttributeType_t, int64_t, int64_t *, void *))dlsym(RTLD_NEXT, "cudnnBackendGetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBackendGetAttribute", kApiTypeCuDNN);

    lretval = lcudnnBackendGetAttribute(descriptor, attributeName, attributeType, requestedElementCount, elementCount, arrayOfElements);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBackendGetAttribute cudnnBackendGetAttribute


#undef cudnnBackendExecute
cudnnStatus_t cudnnBackendExecute(cudnnHandle_t handle, cudnnBackendDescriptor_t executionPlan, cudnnBackendDescriptor_t variantPack){
    cudnnStatus_t lretval;
    cudnnStatus_t (*lcudnnBackendExecute) (cudnnHandle_t, cudnnBackendDescriptor_t, cudnnBackendDescriptor_t) = (cudnnStatus_t (*)(cudnnHandle_t, cudnnBackendDescriptor_t, cudnnBackendDescriptor_t))dlsym(RTLD_NEXT, "cudnnBackendExecute");
    
    /* pre exeuction logics */
    ac.add_counter("cudnnBackendExecute", kApiTypeCuDNN);

    lretval = lcudnnBackendExecute(handle, executionPlan, variantPack);
    
    /* post exeuction logics */

    return lretval;
}
#define cudnnBackendExecute cudnnBackendExecute

