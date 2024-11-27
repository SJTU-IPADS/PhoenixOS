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
#include <cublas_v2.h>

#include "cudam.h"
#include "api_counter.h"


#undef cublasCreate_v2
cublasStatus_t cublasCreate_v2(cublasHandle_t * handle){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCreate_v2) (cublasHandle_t *) = (cublasStatus_t (*)(cublasHandle_t *))dlsym(RTLD_NEXT, "cublasCreate_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCreate_v2", kApiTypeCublasV2);

    lretval = lcublasCreate_v2(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCreate_v2 cublasCreate_v2


#undef cublasDestroy_v2
cublasStatus_t cublasDestroy_v2(cublasHandle_t handle){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDestroy_v2) (cublasHandle_t) = (cublasStatus_t (*)(cublasHandle_t))dlsym(RTLD_NEXT, "cublasDestroy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDestroy_v2", kApiTypeCublasV2);

    lretval = lcublasDestroy_v2(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDestroy_v2 cublasDestroy_v2


#undef cublasGetVersion_v2
cublasStatus_t cublasGetVersion_v2(cublasHandle_t handle, int * version){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetVersion_v2) (cublasHandle_t, int *) = (cublasStatus_t (*)(cublasHandle_t, int *))dlsym(RTLD_NEXT, "cublasGetVersion_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetVersion_v2", kApiTypeCublasV2);

    lretval = lcublasGetVersion_v2(handle, version);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetVersion_v2 cublasGetVersion_v2


#undef cublasGetProperty
cublasStatus_t cublasGetProperty(libraryPropertyType type, int * value){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetProperty) (libraryPropertyType, int *) = (cublasStatus_t (*)(libraryPropertyType, int *))dlsym(RTLD_NEXT, "cublasGetProperty");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetProperty", kApiTypeCublasV2);

    lretval = lcublasGetProperty(type, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetProperty cublasGetProperty


#undef cublasGetCudartVersion
size_t cublasGetCudartVersion(){
    size_t lretval;
    size_t (*lcublasGetCudartVersion) () = (size_t (*)())dlsym(RTLD_NEXT, "cublasGetCudartVersion");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetCudartVersion", kApiTypeCublasV2);

    lretval = lcublasGetCudartVersion();
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetCudartVersion cublasGetCudartVersion


#undef cublasSetWorkspace_v2
cublasStatus_t cublasSetWorkspace_v2(cublasHandle_t handle, void * workspace, size_t workspaceSizeInBytes){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetWorkspace_v2) (cublasHandle_t, void *, size_t) = (cublasStatus_t (*)(cublasHandle_t, void *, size_t))dlsym(RTLD_NEXT, "cublasSetWorkspace_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetWorkspace_v2", kApiTypeCublasV2);

    lretval = lcublasSetWorkspace_v2(handle, workspace, workspaceSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetWorkspace_v2 cublasSetWorkspace_v2


#undef cublasSetStream_v2
cublasStatus_t cublasSetStream_v2(cublasHandle_t handle, cudaStream_t streamId){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetStream_v2) (cublasHandle_t, cudaStream_t) = (cublasStatus_t (*)(cublasHandle_t, cudaStream_t))dlsym(RTLD_NEXT, "cublasSetStream_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetStream_v2", kApiTypeCublasV2);

    lretval = lcublasSetStream_v2(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetStream_v2 cublasSetStream_v2


#undef cublasGetStream_v2
cublasStatus_t cublasGetStream_v2(cublasHandle_t handle, cudaStream_t * streamId){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetStream_v2) (cublasHandle_t, cudaStream_t *) = (cublasStatus_t (*)(cublasHandle_t, cudaStream_t *))dlsym(RTLD_NEXT, "cublasGetStream_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetStream_v2", kApiTypeCublasV2);

    lretval = lcublasGetStream_v2(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetStream_v2 cublasGetStream_v2


#undef cublasGetPointerMode_v2
cublasStatus_t cublasGetPointerMode_v2(cublasHandle_t handle, cublasPointerMode_t * mode){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetPointerMode_v2) (cublasHandle_t, cublasPointerMode_t *) = (cublasStatus_t (*)(cublasHandle_t, cublasPointerMode_t *))dlsym(RTLD_NEXT, "cublasGetPointerMode_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetPointerMode_v2", kApiTypeCublasV2);

    lretval = lcublasGetPointerMode_v2(handle, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetPointerMode_v2 cublasGetPointerMode_v2


#undef cublasSetPointerMode_v2
cublasStatus_t cublasSetPointerMode_v2(cublasHandle_t handle, cublasPointerMode_t mode){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetPointerMode_v2) (cublasHandle_t, cublasPointerMode_t) = (cublasStatus_t (*)(cublasHandle_t, cublasPointerMode_t))dlsym(RTLD_NEXT, "cublasSetPointerMode_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetPointerMode_v2", kApiTypeCublasV2);

    lretval = lcublasSetPointerMode_v2(handle, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetPointerMode_v2 cublasSetPointerMode_v2


#undef cublasGetAtomicsMode
cublasStatus_t cublasGetAtomicsMode(cublasHandle_t handle, cublasAtomicsMode_t * mode){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetAtomicsMode) (cublasHandle_t, cublasAtomicsMode_t *) = (cublasStatus_t (*)(cublasHandle_t, cublasAtomicsMode_t *))dlsym(RTLD_NEXT, "cublasGetAtomicsMode");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetAtomicsMode", kApiTypeCublasV2);

    lretval = lcublasGetAtomicsMode(handle, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetAtomicsMode cublasGetAtomicsMode


#undef cublasSetAtomicsMode
cublasStatus_t cublasSetAtomicsMode(cublasHandle_t handle, cublasAtomicsMode_t mode){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetAtomicsMode) (cublasHandle_t, cublasAtomicsMode_t) = (cublasStatus_t (*)(cublasHandle_t, cublasAtomicsMode_t))dlsym(RTLD_NEXT, "cublasSetAtomicsMode");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetAtomicsMode", kApiTypeCublasV2);

    lretval = lcublasSetAtomicsMode(handle, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetAtomicsMode cublasSetAtomicsMode


#undef cublasGetMathMode
cublasStatus_t cublasGetMathMode(cublasHandle_t handle, cublasMath_t * mode){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetMathMode) (cublasHandle_t, cublasMath_t *) = (cublasStatus_t (*)(cublasHandle_t, cublasMath_t *))dlsym(RTLD_NEXT, "cublasGetMathMode");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetMathMode", kApiTypeCublasV2);

    lretval = lcublasGetMathMode(handle, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetMathMode cublasGetMathMode


#undef cublasSetMathMode
cublasStatus_t cublasSetMathMode(cublasHandle_t handle, cublasMath_t mode){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetMathMode) (cublasHandle_t, cublasMath_t) = (cublasStatus_t (*)(cublasHandle_t, cublasMath_t))dlsym(RTLD_NEXT, "cublasSetMathMode");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetMathMode", kApiTypeCublasV2);

    lretval = lcublasSetMathMode(handle, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetMathMode cublasSetMathMode


#undef cublasGetSmCountTarget
cublasStatus_t cublasGetSmCountTarget(cublasHandle_t handle, int * smCountTarget){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetSmCountTarget) (cublasHandle_t, int *) = (cublasStatus_t (*)(cublasHandle_t, int *))dlsym(RTLD_NEXT, "cublasGetSmCountTarget");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetSmCountTarget", kApiTypeCublasV2);

    lretval = lcublasGetSmCountTarget(handle, smCountTarget);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetSmCountTarget cublasGetSmCountTarget


#undef cublasSetSmCountTarget
cublasStatus_t cublasSetSmCountTarget(cublasHandle_t handle, int smCountTarget){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetSmCountTarget) (cublasHandle_t, int) = (cublasStatus_t (*)(cublasHandle_t, int))dlsym(RTLD_NEXT, "cublasSetSmCountTarget");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetSmCountTarget", kApiTypeCublasV2);

    lretval = lcublasSetSmCountTarget(handle, smCountTarget);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetSmCountTarget cublasSetSmCountTarget


#undef cublasLoggerConfigure
cublasStatus_t cublasLoggerConfigure(int logIsOn, int logToStdOut, int logToStdErr, char const * logFileName){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasLoggerConfigure) (int, int, int, char const *) = (cublasStatus_t (*)(int, int, int, char const *))dlsym(RTLD_NEXT, "cublasLoggerConfigure");
    
    /* pre exeuction logics */
    ac.add_counter("cublasLoggerConfigure", kApiTypeCublasV2);

    lretval = lcublasLoggerConfigure(logIsOn, logToStdOut, logToStdErr, logFileName);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasLoggerConfigure cublasLoggerConfigure


#undef cublasSetLoggerCallback
cublasStatus_t cublasSetLoggerCallback(cublasLogCallback userCallback){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetLoggerCallback) (cublasLogCallback) = (cublasStatus_t (*)(cublasLogCallback))dlsym(RTLD_NEXT, "cublasSetLoggerCallback");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetLoggerCallback", kApiTypeCublasV2);

    lretval = lcublasSetLoggerCallback(userCallback);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetLoggerCallback cublasSetLoggerCallback


#undef cublasGetLoggerCallback
cublasStatus_t cublasGetLoggerCallback(cublasLogCallback * userCallback){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetLoggerCallback) (cublasLogCallback *) = (cublasStatus_t (*)(cublasLogCallback *))dlsym(RTLD_NEXT, "cublasGetLoggerCallback");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetLoggerCallback", kApiTypeCublasV2);

    lretval = lcublasGetLoggerCallback(userCallback);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetLoggerCallback cublasGetLoggerCallback


#undef cublasSetVector
cublasStatus_t cublasSetVector(int n, int elemSize, void const * x, int incx, void * devicePtr, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetVector) (int, int, void const *, int, void *, int) = (cublasStatus_t (*)(int, int, void const *, int, void *, int))dlsym(RTLD_NEXT, "cublasSetVector");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetVector", kApiTypeCublasV2);

    lretval = lcublasSetVector(n, elemSize, x, incx, devicePtr, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetVector cublasSetVector


#undef cublasGetVector
cublasStatus_t cublasGetVector(int n, int elemSize, void const * x, int incx, void * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetVector) (int, int, void const *, int, void *, int) = (cublasStatus_t (*)(int, int, void const *, int, void *, int))dlsym(RTLD_NEXT, "cublasGetVector");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetVector", kApiTypeCublasV2);

    lretval = lcublasGetVector(n, elemSize, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetVector cublasGetVector


#undef cublasSetMatrix
cublasStatus_t cublasSetMatrix(int rows, int cols, int elemSize, void const * A, int lda, void * B, int ldb){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetMatrix) (int, int, int, void const *, int, void *, int) = (cublasStatus_t (*)(int, int, int, void const *, int, void *, int))dlsym(RTLD_NEXT, "cublasSetMatrix");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetMatrix", kApiTypeCublasV2);

    lretval = lcublasSetMatrix(rows, cols, elemSize, A, lda, B, ldb);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetMatrix cublasSetMatrix


#undef cublasGetMatrix
cublasStatus_t cublasGetMatrix(int rows, int cols, int elemSize, void const * A, int lda, void * B, int ldb){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetMatrix) (int, int, int, void const *, int, void *, int) = (cublasStatus_t (*)(int, int, int, void const *, int, void *, int))dlsym(RTLD_NEXT, "cublasGetMatrix");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetMatrix", kApiTypeCublasV2);

    lretval = lcublasGetMatrix(rows, cols, elemSize, A, lda, B, ldb);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetMatrix cublasGetMatrix


#undef cublasSetVectorAsync
cublasStatus_t cublasSetVectorAsync(int n, int elemSize, void const * hostPtr, int incx, void * devicePtr, int incy, cudaStream_t stream){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetVectorAsync) (int, int, void const *, int, void *, int, cudaStream_t) = (cublasStatus_t (*)(int, int, void const *, int, void *, int, cudaStream_t))dlsym(RTLD_NEXT, "cublasSetVectorAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetVectorAsync", kApiTypeCublasV2);

    lretval = lcublasSetVectorAsync(n, elemSize, hostPtr, incx, devicePtr, incy, stream);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetVectorAsync cublasSetVectorAsync


#undef cublasGetVectorAsync
cublasStatus_t cublasGetVectorAsync(int n, int elemSize, void const * devicePtr, int incx, void * hostPtr, int incy, cudaStream_t stream){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetVectorAsync) (int, int, void const *, int, void *, int, cudaStream_t) = (cublasStatus_t (*)(int, int, void const *, int, void *, int, cudaStream_t))dlsym(RTLD_NEXT, "cublasGetVectorAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetVectorAsync", kApiTypeCublasV2);

    lretval = lcublasGetVectorAsync(n, elemSize, devicePtr, incx, hostPtr, incy, stream);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetVectorAsync cublasGetVectorAsync


#undef cublasSetMatrixAsync
cublasStatus_t cublasSetMatrixAsync(int rows, int cols, int elemSize, void const * A, int lda, void * B, int ldb, cudaStream_t stream){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSetMatrixAsync) (int, int, int, void const *, int, void *, int, cudaStream_t) = (cublasStatus_t (*)(int, int, int, void const *, int, void *, int, cudaStream_t))dlsym(RTLD_NEXT, "cublasSetMatrixAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSetMatrixAsync", kApiTypeCublasV2);

    lretval = lcublasSetMatrixAsync(rows, cols, elemSize, A, lda, B, ldb, stream);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSetMatrixAsync cublasSetMatrixAsync


#undef cublasGetMatrixAsync
cublasStatus_t cublasGetMatrixAsync(int rows, int cols, int elemSize, void const * A, int lda, void * B, int ldb, cudaStream_t stream){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGetMatrixAsync) (int, int, int, void const *, int, void *, int, cudaStream_t) = (cublasStatus_t (*)(int, int, int, void const *, int, void *, int, cudaStream_t))dlsym(RTLD_NEXT, "cublasGetMatrixAsync");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGetMatrixAsync", kApiTypeCublasV2);

    lretval = lcublasGetMatrixAsync(rows, cols, elemSize, A, lda, B, ldb, stream);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGetMatrixAsync cublasGetMatrixAsync


void cublasXerbla(char const * srName, int info){
    void (*lcublasXerbla) (char const *, int) = (void (*)(char const *, int))dlsym(RTLD_NEXT, "cublasXerbla");

    /* pre exeuction logics */
    ac.add_counter("cublasXerbla", kApiTypeCublasV2);

    /* post exeuction logics */

    lcublasXerbla(srName, info);
}


#undef cublasNrm2Ex
cublasStatus_t cublasNrm2Ex(cublasHandle_t handle, int n, void const * x, cudaDataType xType, int incx, void * result, cudaDataType resultType, cudaDataType executionType){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasNrm2Ex) (cublasHandle_t, int, void const *, cudaDataType, int, void *, cudaDataType, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, int, void const *, cudaDataType, int, void *, cudaDataType, cudaDataType))dlsym(RTLD_NEXT, "cublasNrm2Ex");
    
    /* pre exeuction logics */
    ac.add_counter("cublasNrm2Ex", kApiTypeCublasV2);

    lretval = lcublasNrm2Ex(handle, n, x, xType, incx, result, resultType, executionType);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasNrm2Ex cublasNrm2Ex


#undef cublasSnrm2_v2
cublasStatus_t cublasSnrm2_v2(cublasHandle_t handle, int n, float const * x, int incx, float * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSnrm2_v2) (cublasHandle_t, int, float const *, int, float *) = (cublasStatus_t (*)(cublasHandle_t, int, float const *, int, float *))dlsym(RTLD_NEXT, "cublasSnrm2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSnrm2_v2", kApiTypeCublasV2);

    lretval = lcublasSnrm2_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSnrm2_v2 cublasSnrm2_v2


#undef cublasDnrm2_v2
cublasStatus_t cublasDnrm2_v2(cublasHandle_t handle, int n, double const * x, int incx, double * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDnrm2_v2) (cublasHandle_t, int, double const *, int, double *) = (cublasStatus_t (*)(cublasHandle_t, int, double const *, int, double *))dlsym(RTLD_NEXT, "cublasDnrm2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDnrm2_v2", kApiTypeCublasV2);

    lretval = lcublasDnrm2_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDnrm2_v2 cublasDnrm2_v2


#undef cublasScnrm2_v2
cublasStatus_t cublasScnrm2_v2(cublasHandle_t handle, int n, cuComplex const * x, int incx, float * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasScnrm2_v2) (cublasHandle_t, int, cuComplex const *, int, float *) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const *, int, float *))dlsym(RTLD_NEXT, "cublasScnrm2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasScnrm2_v2", kApiTypeCublasV2);

    lretval = lcublasScnrm2_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasScnrm2_v2 cublasScnrm2_v2


#undef cublasDznrm2_v2
cublasStatus_t cublasDznrm2_v2(cublasHandle_t handle, int n, cuDoubleComplex const * x, int incx, double * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDznrm2_v2) (cublasHandle_t, int, cuDoubleComplex const *, int, double *) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const *, int, double *))dlsym(RTLD_NEXT, "cublasDznrm2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDznrm2_v2", kApiTypeCublasV2);

    lretval = lcublasDznrm2_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDznrm2_v2 cublasDznrm2_v2


#undef cublasDotEx
cublasStatus_t cublasDotEx(cublasHandle_t handle, int n, void const * x, cudaDataType xType, int incx, void const * y, cudaDataType yType, int incy, void * result, cudaDataType resultType, cudaDataType executionType){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDotEx) (cublasHandle_t, int, void const *, cudaDataType, int, void const *, cudaDataType, int, void *, cudaDataType, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, int, void const *, cudaDataType, int, void const *, cudaDataType, int, void *, cudaDataType, cudaDataType))dlsym(RTLD_NEXT, "cublasDotEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDotEx", kApiTypeCublasV2);

    lretval = lcublasDotEx(handle, n, x, xType, incx, y, yType, incy, result, resultType, executionType);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDotEx cublasDotEx


#undef cublasDotcEx
cublasStatus_t cublasDotcEx(cublasHandle_t handle, int n, void const * x, cudaDataType xType, int incx, void const * y, cudaDataType yType, int incy, void * result, cudaDataType resultType, cudaDataType executionType){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDotcEx) (cublasHandle_t, int, void const *, cudaDataType, int, void const *, cudaDataType, int, void *, cudaDataType, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, int, void const *, cudaDataType, int, void const *, cudaDataType, int, void *, cudaDataType, cudaDataType))dlsym(RTLD_NEXT, "cublasDotcEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDotcEx", kApiTypeCublasV2);

    lretval = lcublasDotcEx(handle, n, x, xType, incx, y, yType, incy, result, resultType, executionType);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDotcEx cublasDotcEx


#undef cublasSdot_v2
cublasStatus_t cublasSdot_v2(cublasHandle_t handle, int n, float const * x, int incx, float const * y, int incy, float * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSdot_v2) (cublasHandle_t, int, float const *, int, float const *, int, float *) = (cublasStatus_t (*)(cublasHandle_t, int, float const *, int, float const *, int, float *))dlsym(RTLD_NEXT, "cublasSdot_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSdot_v2", kApiTypeCublasV2);

    lretval = lcublasSdot_v2(handle, n, x, incx, y, incy, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSdot_v2 cublasSdot_v2


#undef cublasDdot_v2
cublasStatus_t cublasDdot_v2(cublasHandle_t handle, int n, double const * x, int incx, double const * y, int incy, double * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDdot_v2) (cublasHandle_t, int, double const *, int, double const *, int, double *) = (cublasStatus_t (*)(cublasHandle_t, int, double const *, int, double const *, int, double *))dlsym(RTLD_NEXT, "cublasDdot_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDdot_v2", kApiTypeCublasV2);

    lretval = lcublasDdot_v2(handle, n, x, incx, y, incy, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDdot_v2 cublasDdot_v2


#undef cublasCdotu_v2
cublasStatus_t cublasCdotu_v2(cublasHandle_t handle, int n, cuComplex const * x, int incx, cuComplex const * y, int incy, cuComplex * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCdotu_v2) (cublasHandle_t, int, cuComplex const *, int, cuComplex const *, int, cuComplex *) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const *, int, cuComplex const *, int, cuComplex *))dlsym(RTLD_NEXT, "cublasCdotu_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCdotu_v2", kApiTypeCublasV2);

    lretval = lcublasCdotu_v2(handle, n, x, incx, y, incy, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCdotu_v2 cublasCdotu_v2


#undef cublasCdotc_v2
cublasStatus_t cublasCdotc_v2(cublasHandle_t handle, int n, cuComplex const * x, int incx, cuComplex const * y, int incy, cuComplex * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCdotc_v2) (cublasHandle_t, int, cuComplex const *, int, cuComplex const *, int, cuComplex *) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const *, int, cuComplex const *, int, cuComplex *))dlsym(RTLD_NEXT, "cublasCdotc_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCdotc_v2", kApiTypeCublasV2);

    lretval = lcublasCdotc_v2(handle, n, x, incx, y, incy, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCdotc_v2 cublasCdotc_v2


#undef cublasZdotu_v2
cublasStatus_t cublasZdotu_v2(cublasHandle_t handle, int n, cuDoubleComplex const * x, int incx, cuDoubleComplex const * y, int incy, cuDoubleComplex * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZdotu_v2) (cublasHandle_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *))dlsym(RTLD_NEXT, "cublasZdotu_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZdotu_v2", kApiTypeCublasV2);

    lretval = lcublasZdotu_v2(handle, n, x, incx, y, incy, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZdotu_v2 cublasZdotu_v2


#undef cublasZdotc_v2
cublasStatus_t cublasZdotc_v2(cublasHandle_t handle, int n, cuDoubleComplex const * x, int incx, cuDoubleComplex const * y, int incy, cuDoubleComplex * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZdotc_v2) (cublasHandle_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *))dlsym(RTLD_NEXT, "cublasZdotc_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZdotc_v2", kApiTypeCublasV2);

    lretval = lcublasZdotc_v2(handle, n, x, incx, y, incy, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZdotc_v2 cublasZdotc_v2


#undef cublasScalEx
cublasStatus_t cublasScalEx(cublasHandle_t handle, int n, void const * alpha, cudaDataType alphaType, void * x, cudaDataType xType, int incx, cudaDataType executionType){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasScalEx) (cublasHandle_t, int, void const *, cudaDataType, void *, cudaDataType, int, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, int, void const *, cudaDataType, void *, cudaDataType, int, cudaDataType))dlsym(RTLD_NEXT, "cublasScalEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasScalEx", kApiTypeCublasV2);

    lretval = lcublasScalEx(handle, n, alpha, alphaType, x, xType, incx, executionType);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasScalEx cublasScalEx


#undef cublasSscal_v2
cublasStatus_t cublasSscal_v2(cublasHandle_t handle, int n, float const * alpha, float * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSscal_v2) (cublasHandle_t, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSscal_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSscal_v2", kApiTypeCublasV2);

    lretval = lcublasSscal_v2(handle, n, alpha, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSscal_v2 cublasSscal_v2


#undef cublasDscal_v2
cublasStatus_t cublasDscal_v2(cublasHandle_t handle, int n, double const * alpha, double * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDscal_v2) (cublasHandle_t, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDscal_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDscal_v2", kApiTypeCublasV2);

    lretval = lcublasDscal_v2(handle, n, alpha, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDscal_v2 cublasDscal_v2


#undef cublasCscal_v2
cublasStatus_t cublasCscal_v2(cublasHandle_t handle, int n, cuComplex const * alpha, cuComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCscal_v2) (cublasHandle_t, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCscal_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCscal_v2", kApiTypeCublasV2);

    lretval = lcublasCscal_v2(handle, n, alpha, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCscal_v2 cublasCscal_v2


#undef cublasCsscal_v2
cublasStatus_t cublasCsscal_v2(cublasHandle_t handle, int n, float const * alpha, cuComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsscal_v2) (cublasHandle_t, int, float const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, float const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCsscal_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsscal_v2", kApiTypeCublasV2);

    lretval = lcublasCsscal_v2(handle, n, alpha, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsscal_v2 cublasCsscal_v2


#undef cublasZscal_v2
cublasStatus_t cublasZscal_v2(cublasHandle_t handle, int n, cuDoubleComplex const * alpha, cuDoubleComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZscal_v2) (cublasHandle_t, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZscal_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZscal_v2", kApiTypeCublasV2);

    lretval = lcublasZscal_v2(handle, n, alpha, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZscal_v2 cublasZscal_v2


#undef cublasZdscal_v2
cublasStatus_t cublasZdscal_v2(cublasHandle_t handle, int n, double const * alpha, cuDoubleComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZdscal_v2) (cublasHandle_t, int, double const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, double const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZdscal_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZdscal_v2", kApiTypeCublasV2);

    lretval = lcublasZdscal_v2(handle, n, alpha, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZdscal_v2 cublasZdscal_v2


#undef cublasAxpyEx
cublasStatus_t cublasAxpyEx(cublasHandle_t handle, int n, void const * alpha, cudaDataType alphaType, void const * x, cudaDataType xType, int incx, void * y, cudaDataType yType, int incy, cudaDataType executiontype){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasAxpyEx) (cublasHandle_t, int, void const *, cudaDataType, void const *, cudaDataType, int, void *, cudaDataType, int, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, int, void const *, cudaDataType, void const *, cudaDataType, int, void *, cudaDataType, int, cudaDataType))dlsym(RTLD_NEXT, "cublasAxpyEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasAxpyEx", kApiTypeCublasV2);

    lretval = lcublasAxpyEx(handle, n, alpha, alphaType, x, xType, incx, y, yType, incy, executiontype);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasAxpyEx cublasAxpyEx


#undef cublasSaxpy_v2
cublasStatus_t cublasSaxpy_v2(cublasHandle_t handle, int n, float const * alpha, float const * x, int incx, float * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSaxpy_v2) (cublasHandle_t, int, float const *, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, int, float const *, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasSaxpy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSaxpy_v2", kApiTypeCublasV2);

    lretval = lcublasSaxpy_v2(handle, n, alpha, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSaxpy_v2 cublasSaxpy_v2


#undef cublasDaxpy_v2
cublasStatus_t cublasDaxpy_v2(cublasHandle_t handle, int n, double const * alpha, double const * x, int incx, double * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDaxpy_v2) (cublasHandle_t, int, double const *, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, int, double const *, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDaxpy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDaxpy_v2", kApiTypeCublasV2);

    lretval = lcublasDaxpy_v2(handle, n, alpha, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDaxpy_v2 cublasDaxpy_v2


#undef cublasCaxpy_v2
cublasStatus_t cublasCaxpy_v2(cublasHandle_t handle, int n, cuComplex const * alpha, cuComplex const * x, int incx, cuComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCaxpy_v2) (cublasHandle_t, int, cuComplex const *, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const *, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCaxpy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCaxpy_v2", kApiTypeCublasV2);

    lretval = lcublasCaxpy_v2(handle, n, alpha, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCaxpy_v2 cublasCaxpy_v2


#undef cublasZaxpy_v2
cublasStatus_t cublasZaxpy_v2(cublasHandle_t handle, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * x, int incx, cuDoubleComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZaxpy_v2) (cublasHandle_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZaxpy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZaxpy_v2", kApiTypeCublasV2);

    lretval = lcublasZaxpy_v2(handle, n, alpha, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZaxpy_v2 cublasZaxpy_v2


#undef cublasCopyEx
cublasStatus_t cublasCopyEx(cublasHandle_t handle, int n, void const * x, cudaDataType xType, int incx, void * y, cudaDataType yType, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCopyEx) (cublasHandle_t, int, void const *, cudaDataType, int, void *, cudaDataType, int) = (cublasStatus_t (*)(cublasHandle_t, int, void const *, cudaDataType, int, void *, cudaDataType, int))dlsym(RTLD_NEXT, "cublasCopyEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCopyEx", kApiTypeCublasV2);

    lretval = lcublasCopyEx(handle, n, x, xType, incx, y, yType, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCopyEx cublasCopyEx


#undef cublasScopy_v2
cublasStatus_t cublasScopy_v2(cublasHandle_t handle, int n, float const * x, int incx, float * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasScopy_v2) (cublasHandle_t, int, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, int, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasScopy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasScopy_v2", kApiTypeCublasV2);

    lretval = lcublasScopy_v2(handle, n, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasScopy_v2 cublasScopy_v2


#undef cublasDcopy_v2
cublasStatus_t cublasDcopy_v2(cublasHandle_t handle, int n, double const * x, int incx, double * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDcopy_v2) (cublasHandle_t, int, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, int, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDcopy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDcopy_v2", kApiTypeCublasV2);

    lretval = lcublasDcopy_v2(handle, n, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDcopy_v2 cublasDcopy_v2


#undef cublasCcopy_v2
cublasStatus_t cublasCcopy_v2(cublasHandle_t handle, int n, cuComplex const * x, int incx, cuComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCcopy_v2) (cublasHandle_t, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCcopy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCcopy_v2", kApiTypeCublasV2);

    lretval = lcublasCcopy_v2(handle, n, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCcopy_v2 cublasCcopy_v2


#undef cublasZcopy_v2
cublasStatus_t cublasZcopy_v2(cublasHandle_t handle, int n, cuDoubleComplex const * x, int incx, cuDoubleComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZcopy_v2) (cublasHandle_t, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZcopy_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZcopy_v2", kApiTypeCublasV2);

    lretval = lcublasZcopy_v2(handle, n, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZcopy_v2 cublasZcopy_v2


#undef cublasSswap_v2
cublasStatus_t cublasSswap_v2(cublasHandle_t handle, int n, float * x, int incx, float * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSswap_v2) (cublasHandle_t, int, float *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, int, float *, int, float *, int))dlsym(RTLD_NEXT, "cublasSswap_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSswap_v2", kApiTypeCublasV2);

    lretval = lcublasSswap_v2(handle, n, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSswap_v2 cublasSswap_v2


#undef cublasDswap_v2
cublasStatus_t cublasDswap_v2(cublasHandle_t handle, int n, double * x, int incx, double * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDswap_v2) (cublasHandle_t, int, double *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, int, double *, int, double *, int))dlsym(RTLD_NEXT, "cublasDswap_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDswap_v2", kApiTypeCublasV2);

    lretval = lcublasDswap_v2(handle, n, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDswap_v2 cublasDswap_v2


#undef cublasCswap_v2
cublasStatus_t cublasCswap_v2(cublasHandle_t handle, int n, cuComplex * x, int incx, cuComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCswap_v2) (cublasHandle_t, int, cuComplex *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCswap_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCswap_v2", kApiTypeCublasV2);

    lretval = lcublasCswap_v2(handle, n, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCswap_v2 cublasCswap_v2


#undef cublasZswap_v2
cublasStatus_t cublasZswap_v2(cublasHandle_t handle, int n, cuDoubleComplex * x, int incx, cuDoubleComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZswap_v2) (cublasHandle_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZswap_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZswap_v2", kApiTypeCublasV2);

    lretval = lcublasZswap_v2(handle, n, x, incx, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZswap_v2 cublasZswap_v2


#undef cublasSwapEx
cublasStatus_t cublasSwapEx(cublasHandle_t handle, int n, void * x, cudaDataType xType, int incx, void * y, cudaDataType yType, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSwapEx) (cublasHandle_t, int, void *, cudaDataType, int, void *, cudaDataType, int) = (cublasStatus_t (*)(cublasHandle_t, int, void *, cudaDataType, int, void *, cudaDataType, int))dlsym(RTLD_NEXT, "cublasSwapEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSwapEx", kApiTypeCublasV2);

    lretval = lcublasSwapEx(handle, n, x, xType, incx, y, yType, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSwapEx cublasSwapEx


#undef cublasIsamax_v2
cublasStatus_t cublasIsamax_v2(cublasHandle_t handle, int n, float const * x, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIsamax_v2) (cublasHandle_t, int, float const *, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, float const *, int, int *))dlsym(RTLD_NEXT, "cublasIsamax_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIsamax_v2", kApiTypeCublasV2);

    lretval = lcublasIsamax_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIsamax_v2 cublasIsamax_v2


#undef cublasIdamax_v2
cublasStatus_t cublasIdamax_v2(cublasHandle_t handle, int n, double const * x, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIdamax_v2) (cublasHandle_t, int, double const *, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, double const *, int, int *))dlsym(RTLD_NEXT, "cublasIdamax_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIdamax_v2", kApiTypeCublasV2);

    lretval = lcublasIdamax_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIdamax_v2 cublasIdamax_v2


#undef cublasIcamax_v2
cublasStatus_t cublasIcamax_v2(cublasHandle_t handle, int n, cuComplex const * x, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIcamax_v2) (cublasHandle_t, int, cuComplex const *, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const *, int, int *))dlsym(RTLD_NEXT, "cublasIcamax_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIcamax_v2", kApiTypeCublasV2);

    lretval = lcublasIcamax_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIcamax_v2 cublasIcamax_v2


#undef cublasIzamax_v2
cublasStatus_t cublasIzamax_v2(cublasHandle_t handle, int n, cuDoubleComplex const * x, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIzamax_v2) (cublasHandle_t, int, cuDoubleComplex const *, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const *, int, int *))dlsym(RTLD_NEXT, "cublasIzamax_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIzamax_v2", kApiTypeCublasV2);

    lretval = lcublasIzamax_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIzamax_v2 cublasIzamax_v2


#undef cublasIamaxEx
cublasStatus_t cublasIamaxEx(cublasHandle_t handle, int n, void const * x, cudaDataType xType, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIamaxEx) (cublasHandle_t, int, void const *, cudaDataType, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, void const *, cudaDataType, int, int *))dlsym(RTLD_NEXT, "cublasIamaxEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIamaxEx", kApiTypeCublasV2);

    lretval = lcublasIamaxEx(handle, n, x, xType, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIamaxEx cublasIamaxEx


#undef cublasIsamin_v2
cublasStatus_t cublasIsamin_v2(cublasHandle_t handle, int n, float const * x, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIsamin_v2) (cublasHandle_t, int, float const *, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, float const *, int, int *))dlsym(RTLD_NEXT, "cublasIsamin_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIsamin_v2", kApiTypeCublasV2);

    lretval = lcublasIsamin_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIsamin_v2 cublasIsamin_v2


#undef cublasIdamin_v2
cublasStatus_t cublasIdamin_v2(cublasHandle_t handle, int n, double const * x, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIdamin_v2) (cublasHandle_t, int, double const *, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, double const *, int, int *))dlsym(RTLD_NEXT, "cublasIdamin_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIdamin_v2", kApiTypeCublasV2);

    lretval = lcublasIdamin_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIdamin_v2 cublasIdamin_v2


#undef cublasIcamin_v2
cublasStatus_t cublasIcamin_v2(cublasHandle_t handle, int n, cuComplex const * x, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIcamin_v2) (cublasHandle_t, int, cuComplex const *, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const *, int, int *))dlsym(RTLD_NEXT, "cublasIcamin_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIcamin_v2", kApiTypeCublasV2);

    lretval = lcublasIcamin_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIcamin_v2 cublasIcamin_v2


#undef cublasIzamin_v2
cublasStatus_t cublasIzamin_v2(cublasHandle_t handle, int n, cuDoubleComplex const * x, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIzamin_v2) (cublasHandle_t, int, cuDoubleComplex const *, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const *, int, int *))dlsym(RTLD_NEXT, "cublasIzamin_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIzamin_v2", kApiTypeCublasV2);

    lretval = lcublasIzamin_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIzamin_v2 cublasIzamin_v2


#undef cublasIaminEx
cublasStatus_t cublasIaminEx(cublasHandle_t handle, int n, void const * x, cudaDataType xType, int incx, int * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasIaminEx) (cublasHandle_t, int, void const *, cudaDataType, int, int *) = (cublasStatus_t (*)(cublasHandle_t, int, void const *, cudaDataType, int, int *))dlsym(RTLD_NEXT, "cublasIaminEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasIaminEx", kApiTypeCublasV2);

    lretval = lcublasIaminEx(handle, n, x, xType, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasIaminEx cublasIaminEx


#undef cublasAsumEx
cublasStatus_t cublasAsumEx(cublasHandle_t handle, int n, void const * x, cudaDataType xType, int incx, void * result, cudaDataType resultType, cudaDataType executiontype){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasAsumEx) (cublasHandle_t, int, void const *, cudaDataType, int, void *, cudaDataType, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, int, void const *, cudaDataType, int, void *, cudaDataType, cudaDataType))dlsym(RTLD_NEXT, "cublasAsumEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasAsumEx", kApiTypeCublasV2);

    lretval = lcublasAsumEx(handle, n, x, xType, incx, result, resultType, executiontype);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasAsumEx cublasAsumEx


#undef cublasSasum_v2
cublasStatus_t cublasSasum_v2(cublasHandle_t handle, int n, float const * x, int incx, float * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSasum_v2) (cublasHandle_t, int, float const *, int, float *) = (cublasStatus_t (*)(cublasHandle_t, int, float const *, int, float *))dlsym(RTLD_NEXT, "cublasSasum_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSasum_v2", kApiTypeCublasV2);

    lretval = lcublasSasum_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSasum_v2 cublasSasum_v2


#undef cublasDasum_v2
cublasStatus_t cublasDasum_v2(cublasHandle_t handle, int n, double const * x, int incx, double * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDasum_v2) (cublasHandle_t, int, double const *, int, double *) = (cublasStatus_t (*)(cublasHandle_t, int, double const *, int, double *))dlsym(RTLD_NEXT, "cublasDasum_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDasum_v2", kApiTypeCublasV2);

    lretval = lcublasDasum_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDasum_v2 cublasDasum_v2


#undef cublasScasum_v2
cublasStatus_t cublasScasum_v2(cublasHandle_t handle, int n, cuComplex const * x, int incx, float * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasScasum_v2) (cublasHandle_t, int, cuComplex const *, int, float *) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const *, int, float *))dlsym(RTLD_NEXT, "cublasScasum_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasScasum_v2", kApiTypeCublasV2);

    lretval = lcublasScasum_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasScasum_v2 cublasScasum_v2


#undef cublasDzasum_v2
cublasStatus_t cublasDzasum_v2(cublasHandle_t handle, int n, cuDoubleComplex const * x, int incx, double * result){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDzasum_v2) (cublasHandle_t, int, cuDoubleComplex const *, int, double *) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const *, int, double *))dlsym(RTLD_NEXT, "cublasDzasum_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDzasum_v2", kApiTypeCublasV2);

    lretval = lcublasDzasum_v2(handle, n, x, incx, result);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDzasum_v2 cublasDzasum_v2


#undef cublasSrot_v2
cublasStatus_t cublasSrot_v2(cublasHandle_t handle, int n, float * x, int incx, float * y, int incy, float const * c, float const * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSrot_v2) (cublasHandle_t, int, float *, int, float *, int, float const *, float const *) = (cublasStatus_t (*)(cublasHandle_t, int, float *, int, float *, int, float const *, float const *))dlsym(RTLD_NEXT, "cublasSrot_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSrot_v2", kApiTypeCublasV2);

    lretval = lcublasSrot_v2(handle, n, x, incx, y, incy, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSrot_v2 cublasSrot_v2


#undef cublasDrot_v2
cublasStatus_t cublasDrot_v2(cublasHandle_t handle, int n, double * x, int incx, double * y, int incy, double const * c, double const * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDrot_v2) (cublasHandle_t, int, double *, int, double *, int, double const *, double const *) = (cublasStatus_t (*)(cublasHandle_t, int, double *, int, double *, int, double const *, double const *))dlsym(RTLD_NEXT, "cublasDrot_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDrot_v2", kApiTypeCublasV2);

    lretval = lcublasDrot_v2(handle, n, x, incx, y, incy, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDrot_v2 cublasDrot_v2


#undef cublasCrot_v2
cublasStatus_t cublasCrot_v2(cublasHandle_t handle, int n, cuComplex * x, int incx, cuComplex * y, int incy, float const * c, cuComplex const * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCrot_v2) (cublasHandle_t, int, cuComplex *, int, cuComplex *, int, float const *, cuComplex const *) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex *, int, cuComplex *, int, float const *, cuComplex const *))dlsym(RTLD_NEXT, "cublasCrot_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCrot_v2", kApiTypeCublasV2);

    lretval = lcublasCrot_v2(handle, n, x, incx, y, incy, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCrot_v2 cublasCrot_v2


#undef cublasCsrot_v2
cublasStatus_t cublasCsrot_v2(cublasHandle_t handle, int n, cuComplex * x, int incx, cuComplex * y, int incy, float const * c, float const * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsrot_v2) (cublasHandle_t, int, cuComplex *, int, cuComplex *, int, float const *, float const *) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex *, int, cuComplex *, int, float const *, float const *))dlsym(RTLD_NEXT, "cublasCsrot_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsrot_v2", kApiTypeCublasV2);

    lretval = lcublasCsrot_v2(handle, n, x, incx, y, incy, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsrot_v2 cublasCsrot_v2


#undef cublasZrot_v2
cublasStatus_t cublasZrot_v2(cublasHandle_t handle, int n, cuDoubleComplex * x, int incx, cuDoubleComplex * y, int incy, double const * c, cuDoubleComplex const * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZrot_v2) (cublasHandle_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double const *, cuDoubleComplex const *) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double const *, cuDoubleComplex const *))dlsym(RTLD_NEXT, "cublasZrot_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZrot_v2", kApiTypeCublasV2);

    lretval = lcublasZrot_v2(handle, n, x, incx, y, incy, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZrot_v2 cublasZrot_v2


#undef cublasZdrot_v2
cublasStatus_t cublasZdrot_v2(cublasHandle_t handle, int n, cuDoubleComplex * x, int incx, cuDoubleComplex * y, int incy, double const * c, double const * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZdrot_v2) (cublasHandle_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double const *, double const *) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double const *, double const *))dlsym(RTLD_NEXT, "cublasZdrot_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZdrot_v2", kApiTypeCublasV2);

    lretval = lcublasZdrot_v2(handle, n, x, incx, y, incy, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZdrot_v2 cublasZdrot_v2


#undef cublasRotEx
cublasStatus_t cublasRotEx(cublasHandle_t handle, int n, void * x, cudaDataType xType, int incx, void * y, cudaDataType yType, int incy, void const * c, void const * s, cudaDataType csType, cudaDataType executiontype){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasRotEx) (cublasHandle_t, int, void *, cudaDataType, int, void *, cudaDataType, int, void const *, void const *, cudaDataType, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, int, void *, cudaDataType, int, void *, cudaDataType, int, void const *, void const *, cudaDataType, cudaDataType))dlsym(RTLD_NEXT, "cublasRotEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasRotEx", kApiTypeCublasV2);

    lretval = lcublasRotEx(handle, n, x, xType, incx, y, yType, incy, c, s, csType, executiontype);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasRotEx cublasRotEx


#undef cublasSrotg_v2
cublasStatus_t cublasSrotg_v2(cublasHandle_t handle, float * a, float * b, float * c, float * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSrotg_v2) (cublasHandle_t, float *, float *, float *, float *) = (cublasStatus_t (*)(cublasHandle_t, float *, float *, float *, float *))dlsym(RTLD_NEXT, "cublasSrotg_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSrotg_v2", kApiTypeCublasV2);

    lretval = lcublasSrotg_v2(handle, a, b, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSrotg_v2 cublasSrotg_v2


#undef cublasDrotg_v2
cublasStatus_t cublasDrotg_v2(cublasHandle_t handle, double * a, double * b, double * c, double * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDrotg_v2) (cublasHandle_t, double *, double *, double *, double *) = (cublasStatus_t (*)(cublasHandle_t, double *, double *, double *, double *))dlsym(RTLD_NEXT, "cublasDrotg_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDrotg_v2", kApiTypeCublasV2);

    lretval = lcublasDrotg_v2(handle, a, b, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDrotg_v2 cublasDrotg_v2


#undef cublasCrotg_v2
cublasStatus_t cublasCrotg_v2(cublasHandle_t handle, cuComplex * a, cuComplex * b, float * c, cuComplex * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCrotg_v2) (cublasHandle_t, cuComplex *, cuComplex *, float *, cuComplex *) = (cublasStatus_t (*)(cublasHandle_t, cuComplex *, cuComplex *, float *, cuComplex *))dlsym(RTLD_NEXT, "cublasCrotg_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCrotg_v2", kApiTypeCublasV2);

    lretval = lcublasCrotg_v2(handle, a, b, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCrotg_v2 cublasCrotg_v2


#undef cublasZrotg_v2
cublasStatus_t cublasZrotg_v2(cublasHandle_t handle, cuDoubleComplex * a, cuDoubleComplex * b, double * c, cuDoubleComplex * s){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZrotg_v2) (cublasHandle_t, cuDoubleComplex *, cuDoubleComplex *, double *, cuDoubleComplex *) = (cublasStatus_t (*)(cublasHandle_t, cuDoubleComplex *, cuDoubleComplex *, double *, cuDoubleComplex *))dlsym(RTLD_NEXT, "cublasZrotg_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZrotg_v2", kApiTypeCublasV2);

    lretval = lcublasZrotg_v2(handle, a, b, c, s);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZrotg_v2 cublasZrotg_v2


#undef cublasRotgEx
cublasStatus_t cublasRotgEx(cublasHandle_t handle, void * a, void * b, cudaDataType abType, void * c, void * s, cudaDataType csType, cudaDataType executiontype){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasRotgEx) (cublasHandle_t, void *, void *, cudaDataType, void *, void *, cudaDataType, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, void *, void *, cudaDataType, void *, void *, cudaDataType, cudaDataType))dlsym(RTLD_NEXT, "cublasRotgEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasRotgEx", kApiTypeCublasV2);

    lretval = lcublasRotgEx(handle, a, b, abType, c, s, csType, executiontype);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasRotgEx cublasRotgEx


#undef cublasSrotm_v2
cublasStatus_t cublasSrotm_v2(cublasHandle_t handle, int n, float * x, int incx, float * y, int incy, float const * param){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSrotm_v2) (cublasHandle_t, int, float *, int, float *, int, float const *) = (cublasStatus_t (*)(cublasHandle_t, int, float *, int, float *, int, float const *))dlsym(RTLD_NEXT, "cublasSrotm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSrotm_v2", kApiTypeCublasV2);

    lretval = lcublasSrotm_v2(handle, n, x, incx, y, incy, param);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSrotm_v2 cublasSrotm_v2


#undef cublasDrotm_v2
cublasStatus_t cublasDrotm_v2(cublasHandle_t handle, int n, double * x, int incx, double * y, int incy, double const * param){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDrotm_v2) (cublasHandle_t, int, double *, int, double *, int, double const *) = (cublasStatus_t (*)(cublasHandle_t, int, double *, int, double *, int, double const *))dlsym(RTLD_NEXT, "cublasDrotm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDrotm_v2", kApiTypeCublasV2);

    lretval = lcublasDrotm_v2(handle, n, x, incx, y, incy, param);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDrotm_v2 cublasDrotm_v2


#undef cublasRotmEx
cublasStatus_t cublasRotmEx(cublasHandle_t handle, int n, void * x, cudaDataType xType, int incx, void * y, cudaDataType yType, int incy, void const * param, cudaDataType paramType, cudaDataType executiontype){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasRotmEx) (cublasHandle_t, int, void *, cudaDataType, int, void *, cudaDataType, int, void const *, cudaDataType, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, int, void *, cudaDataType, int, void *, cudaDataType, int, void const *, cudaDataType, cudaDataType))dlsym(RTLD_NEXT, "cublasRotmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasRotmEx", kApiTypeCublasV2);

    lretval = lcublasRotmEx(handle, n, x, xType, incx, y, yType, incy, param, paramType, executiontype);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasRotmEx cublasRotmEx


#undef cublasSrotmg_v2
cublasStatus_t cublasSrotmg_v2(cublasHandle_t handle, float * d1, float * d2, float * x1, float const * y1, float * param){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSrotmg_v2) (cublasHandle_t, float *, float *, float *, float const *, float *) = (cublasStatus_t (*)(cublasHandle_t, float *, float *, float *, float const *, float *))dlsym(RTLD_NEXT, "cublasSrotmg_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSrotmg_v2", kApiTypeCublasV2);

    lretval = lcublasSrotmg_v2(handle, d1, d2, x1, y1, param);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSrotmg_v2 cublasSrotmg_v2


#undef cublasDrotmg_v2
cublasStatus_t cublasDrotmg_v2(cublasHandle_t handle, double * d1, double * d2, double * x1, double const * y1, double * param){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDrotmg_v2) (cublasHandle_t, double *, double *, double *, double const *, double *) = (cublasStatus_t (*)(cublasHandle_t, double *, double *, double *, double const *, double *))dlsym(RTLD_NEXT, "cublasDrotmg_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDrotmg_v2", kApiTypeCublasV2);

    lretval = lcublasDrotmg_v2(handle, d1, d2, x1, y1, param);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDrotmg_v2 cublasDrotmg_v2


#undef cublasRotmgEx
cublasStatus_t cublasRotmgEx(cublasHandle_t handle, void * d1, cudaDataType d1Type, void * d2, cudaDataType d2Type, void * x1, cudaDataType x1Type, void const * y1, cudaDataType y1Type, void * param, cudaDataType paramType, cudaDataType executiontype){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasRotmgEx) (cublasHandle_t, void *, cudaDataType, void *, cudaDataType, void *, cudaDataType, void const *, cudaDataType, void *, cudaDataType, cudaDataType) = (cublasStatus_t (*)(cublasHandle_t, void *, cudaDataType, void *, cudaDataType, void *, cudaDataType, void const *, cudaDataType, void *, cudaDataType, cudaDataType))dlsym(RTLD_NEXT, "cublasRotmgEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasRotmgEx", kApiTypeCublasV2);

    lretval = lcublasRotmgEx(handle, d1, d1Type, d2, d2Type, x1, x1Type, y1, y1Type, param, paramType, executiontype);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasRotmgEx cublasRotmgEx


#undef cublasSgemv_v2
cublasStatus_t cublasSgemv_v2(cublasHandle_t handle, cublasOperation_t trans, int m, int n, float const * alpha, float const * A, int lda, float const * x, int incx, float const * beta, float * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgemv_v2) (cublasHandle_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSgemv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgemv_v2", kApiTypeCublasV2);

    lretval = lcublasSgemv_v2(handle, trans, m, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgemv_v2 cublasSgemv_v2


#undef cublasDgemv_v2
cublasStatus_t cublasDgemv_v2(cublasHandle_t handle, cublasOperation_t trans, int m, int n, double const * alpha, double const * A, int lda, double const * x, int incx, double const * beta, double * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgemv_v2) (cublasHandle_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDgemv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgemv_v2", kApiTypeCublasV2);

    lretval = lcublasDgemv_v2(handle, trans, m, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgemv_v2 cublasDgemv_v2


#undef cublasCgemv_v2
cublasStatus_t cublasCgemv_v2(cublasHandle_t handle, cublasOperation_t trans, int m, int n, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * x, int incx, cuComplex const * beta, cuComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgemv_v2) (cublasHandle_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCgemv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgemv_v2", kApiTypeCublasV2);

    lretval = lcublasCgemv_v2(handle, trans, m, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgemv_v2 cublasCgemv_v2


#undef cublasZgemv_v2
cublasStatus_t cublasZgemv_v2(cublasHandle_t handle, cublasOperation_t trans, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * x, int incx, cuDoubleComplex const * beta, cuDoubleComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgemv_v2) (cublasHandle_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZgemv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgemv_v2", kApiTypeCublasV2);

    lretval = lcublasZgemv_v2(handle, trans, m, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgemv_v2 cublasZgemv_v2


#undef cublasSgbmv_v2
cublasStatus_t cublasSgbmv_v2(cublasHandle_t handle, cublasOperation_t trans, int m, int n, int kl, int ku, float const * alpha, float const * A, int lda, float const * x, int incx, float const * beta, float * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgbmv_v2) (cublasHandle_t, cublasOperation_t, int, int, int, int, float const *, float const *, int, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, int, int, float const *, float const *, int, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSgbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgbmv_v2", kApiTypeCublasV2);

    lretval = lcublasSgbmv_v2(handle, trans, m, n, kl, ku, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgbmv_v2 cublasSgbmv_v2


#undef cublasDgbmv_v2
cublasStatus_t cublasDgbmv_v2(cublasHandle_t handle, cublasOperation_t trans, int m, int n, int kl, int ku, double const * alpha, double const * A, int lda, double const * x, int incx, double const * beta, double * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgbmv_v2) (cublasHandle_t, cublasOperation_t, int, int, int, int, double const *, double const *, int, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, int, int, double const *, double const *, int, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDgbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgbmv_v2", kApiTypeCublasV2);

    lretval = lcublasDgbmv_v2(handle, trans, m, n, kl, ku, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgbmv_v2 cublasDgbmv_v2


#undef cublasCgbmv_v2
cublasStatus_t cublasCgbmv_v2(cublasHandle_t handle, cublasOperation_t trans, int m, int n, int kl, int ku, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * x, int incx, cuComplex const * beta, cuComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgbmv_v2) (cublasHandle_t, cublasOperation_t, int, int, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCgbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgbmv_v2", kApiTypeCublasV2);

    lretval = lcublasCgbmv_v2(handle, trans, m, n, kl, ku, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgbmv_v2 cublasCgbmv_v2


#undef cublasZgbmv_v2
cublasStatus_t cublasZgbmv_v2(cublasHandle_t handle, cublasOperation_t trans, int m, int n, int kl, int ku, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * x, int incx, cuDoubleComplex const * beta, cuDoubleComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgbmv_v2) (cublasHandle_t, cublasOperation_t, int, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZgbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgbmv_v2", kApiTypeCublasV2);

    lretval = lcublasZgbmv_v2(handle, trans, m, n, kl, ku, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgbmv_v2 cublasZgbmv_v2


#undef cublasStrmv_v2
cublasStatus_t cublasStrmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, float const * A, int lda, float * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStrmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasStrmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStrmv_v2", kApiTypeCublasV2);

    lretval = lcublasStrmv_v2(handle, uplo, trans, diag, n, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStrmv_v2 cublasStrmv_v2


#undef cublasDtrmv_v2
cublasStatus_t cublasDtrmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, double const * A, int lda, double * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtrmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDtrmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtrmv_v2", kApiTypeCublasV2);

    lretval = lcublasDtrmv_v2(handle, uplo, trans, diag, n, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtrmv_v2 cublasDtrmv_v2


#undef cublasCtrmv_v2
cublasStatus_t cublasCtrmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, cuComplex const * A, int lda, cuComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtrmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCtrmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtrmv_v2", kApiTypeCublasV2);

    lretval = lcublasCtrmv_v2(handle, uplo, trans, diag, n, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtrmv_v2 cublasCtrmv_v2


#undef cublasZtrmv_v2
cublasStatus_t cublasZtrmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, cuDoubleComplex const * A, int lda, cuDoubleComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtrmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZtrmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtrmv_v2", kApiTypeCublasV2);

    lretval = lcublasZtrmv_v2(handle, uplo, trans, diag, n, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtrmv_v2 cublasZtrmv_v2


#undef cublasStbmv_v2
cublasStatus_t cublasStbmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, int k, float const * A, int lda, float * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStbmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasStbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStbmv_v2", kApiTypeCublasV2);

    lretval = lcublasStbmv_v2(handle, uplo, trans, diag, n, k, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStbmv_v2 cublasStbmv_v2


#undef cublasDtbmv_v2
cublasStatus_t cublasDtbmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, int k, double const * A, int lda, double * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtbmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDtbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtbmv_v2", kApiTypeCublasV2);

    lretval = lcublasDtbmv_v2(handle, uplo, trans, diag, n, k, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtbmv_v2 cublasDtbmv_v2


#undef cublasCtbmv_v2
cublasStatus_t cublasCtbmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, int k, cuComplex const * A, int lda, cuComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtbmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCtbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtbmv_v2", kApiTypeCublasV2);

    lretval = lcublasCtbmv_v2(handle, uplo, trans, diag, n, k, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtbmv_v2 cublasCtbmv_v2


#undef cublasZtbmv_v2
cublasStatus_t cublasZtbmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, int k, cuDoubleComplex const * A, int lda, cuDoubleComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtbmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZtbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtbmv_v2", kApiTypeCublasV2);

    lretval = lcublasZtbmv_v2(handle, uplo, trans, diag, n, k, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtbmv_v2 cublasZtbmv_v2


#undef cublasStpmv_v2
cublasStatus_t cublasStpmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, float const * AP, float * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStpmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasStpmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStpmv_v2", kApiTypeCublasV2);

    lretval = lcublasStpmv_v2(handle, uplo, trans, diag, n, AP, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStpmv_v2 cublasStpmv_v2


#undef cublasDtpmv_v2
cublasStatus_t cublasDtpmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, double const * AP, double * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtpmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDtpmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtpmv_v2", kApiTypeCublasV2);

    lretval = lcublasDtpmv_v2(handle, uplo, trans, diag, n, AP, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtpmv_v2 cublasDtpmv_v2


#undef cublasCtpmv_v2
cublasStatus_t cublasCtpmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, cuComplex const * AP, cuComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtpmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCtpmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtpmv_v2", kApiTypeCublasV2);

    lretval = lcublasCtpmv_v2(handle, uplo, trans, diag, n, AP, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtpmv_v2 cublasCtpmv_v2


#undef cublasZtpmv_v2
cublasStatus_t cublasZtpmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, cuDoubleComplex const * AP, cuDoubleComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtpmv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZtpmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtpmv_v2", kApiTypeCublasV2);

    lretval = lcublasZtpmv_v2(handle, uplo, trans, diag, n, AP, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtpmv_v2 cublasZtpmv_v2


#undef cublasStrsv_v2
cublasStatus_t cublasStrsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, float const * A, int lda, float * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStrsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasStrsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStrsv_v2", kApiTypeCublasV2);

    lretval = lcublasStrsv_v2(handle, uplo, trans, diag, n, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStrsv_v2 cublasStrsv_v2


#undef cublasDtrsv_v2
cublasStatus_t cublasDtrsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, double const * A, int lda, double * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtrsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDtrsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtrsv_v2", kApiTypeCublasV2);

    lretval = lcublasDtrsv_v2(handle, uplo, trans, diag, n, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtrsv_v2 cublasDtrsv_v2


#undef cublasCtrsv_v2
cublasStatus_t cublasCtrsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, cuComplex const * A, int lda, cuComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtrsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCtrsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtrsv_v2", kApiTypeCublasV2);

    lretval = lcublasCtrsv_v2(handle, uplo, trans, diag, n, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtrsv_v2 cublasCtrsv_v2


#undef cublasZtrsv_v2
cublasStatus_t cublasZtrsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, cuDoubleComplex const * A, int lda, cuDoubleComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtrsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZtrsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtrsv_v2", kApiTypeCublasV2);

    lretval = lcublasZtrsv_v2(handle, uplo, trans, diag, n, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtrsv_v2 cublasZtrsv_v2


#undef cublasStpsv_v2
cublasStatus_t cublasStpsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, float const * AP, float * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStpsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasStpsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStpsv_v2", kApiTypeCublasV2);

    lretval = lcublasStpsv_v2(handle, uplo, trans, diag, n, AP, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStpsv_v2 cublasStpsv_v2


#undef cublasDtpsv_v2
cublasStatus_t cublasDtpsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, double const * AP, double * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtpsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDtpsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtpsv_v2", kApiTypeCublasV2);

    lretval = lcublasDtpsv_v2(handle, uplo, trans, diag, n, AP, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtpsv_v2 cublasDtpsv_v2


#undef cublasCtpsv_v2
cublasStatus_t cublasCtpsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, cuComplex const * AP, cuComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtpsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCtpsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtpsv_v2", kApiTypeCublasV2);

    lretval = lcublasCtpsv_v2(handle, uplo, trans, diag, n, AP, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtpsv_v2 cublasCtpsv_v2


#undef cublasZtpsv_v2
cublasStatus_t cublasZtpsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, cuDoubleComplex const * AP, cuDoubleComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtpsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZtpsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtpsv_v2", kApiTypeCublasV2);

    lretval = lcublasZtpsv_v2(handle, uplo, trans, diag, n, AP, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtpsv_v2 cublasZtpsv_v2


#undef cublasStbsv_v2
cublasStatus_t cublasStbsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, int k, float const * A, int lda, float * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStbsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasStbsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStbsv_v2", kApiTypeCublasV2);

    lretval = lcublasStbsv_v2(handle, uplo, trans, diag, n, k, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStbsv_v2 cublasStbsv_v2


#undef cublasDtbsv_v2
cublasStatus_t cublasDtbsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, int k, double const * A, int lda, double * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtbsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDtbsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtbsv_v2", kApiTypeCublasV2);

    lretval = lcublasDtbsv_v2(handle, uplo, trans, diag, n, k, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtbsv_v2 cublasDtbsv_v2


#undef cublasCtbsv_v2
cublasStatus_t cublasCtbsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, int k, cuComplex const * A, int lda, cuComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtbsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCtbsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtbsv_v2", kApiTypeCublasV2);

    lretval = lcublasCtbsv_v2(handle, uplo, trans, diag, n, k, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtbsv_v2 cublasCtbsv_v2


#undef cublasZtbsv_v2
cublasStatus_t cublasZtbsv_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int n, int k, cuDoubleComplex const * A, int lda, cuDoubleComplex * x, int incx){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtbsv_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZtbsv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtbsv_v2", kApiTypeCublasV2);

    lretval = lcublasZtbsv_v2(handle, uplo, trans, diag, n, k, A, lda, x, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtbsv_v2 cublasZtbsv_v2


#undef cublasSsymv_v2
cublasStatus_t cublasSsymv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * alpha, float const * A, int lda, float const * x, int incx, float const * beta, float * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSsymv_v2) (cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSsymv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSsymv_v2", kApiTypeCublasV2);

    lretval = lcublasSsymv_v2(handle, uplo, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSsymv_v2 cublasSsymv_v2


#undef cublasDsymv_v2
cublasStatus_t cublasDsymv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * alpha, double const * A, int lda, double const * x, int incx, double const * beta, double * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDsymv_v2) (cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDsymv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDsymv_v2", kApiTypeCublasV2);

    lretval = lcublasDsymv_v2(handle, uplo, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDsymv_v2 cublasDsymv_v2


#undef cublasCsymv_v2
cublasStatus_t cublasCsymv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * x, int incx, cuComplex const * beta, cuComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsymv_v2) (cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCsymv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsymv_v2", kApiTypeCublasV2);

    lretval = lcublasCsymv_v2(handle, uplo, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsymv_v2 cublasCsymv_v2


#undef cublasZsymv_v2
cublasStatus_t cublasZsymv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * x, int incx, cuDoubleComplex const * beta, cuDoubleComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZsymv_v2) (cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZsymv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZsymv_v2", kApiTypeCublasV2);

    lretval = lcublasZsymv_v2(handle, uplo, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZsymv_v2 cublasZsymv_v2


#undef cublasChemv_v2
cublasStatus_t cublasChemv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * x, int incx, cuComplex const * beta, cuComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasChemv_v2) (cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasChemv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasChemv_v2", kApiTypeCublasV2);

    lretval = lcublasChemv_v2(handle, uplo, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasChemv_v2 cublasChemv_v2


#undef cublasZhemv_v2
cublasStatus_t cublasZhemv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * x, int incx, cuDoubleComplex const * beta, cuDoubleComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZhemv_v2) (cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZhemv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZhemv_v2", kApiTypeCublasV2);

    lretval = lcublasZhemv_v2(handle, uplo, n, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZhemv_v2 cublasZhemv_v2


#undef cublasSsbmv_v2
cublasStatus_t cublasSsbmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, int k, float const * alpha, float const * A, int lda, float const * x, int incx, float const * beta, float * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSsbmv_v2) (cublasHandle_t, cublasFillMode_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSsbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSsbmv_v2", kApiTypeCublasV2);

    lretval = lcublasSsbmv_v2(handle, uplo, n, k, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSsbmv_v2 cublasSsbmv_v2


#undef cublasDsbmv_v2
cublasStatus_t cublasDsbmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, int k, double const * alpha, double const * A, int lda, double const * x, int incx, double const * beta, double * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDsbmv_v2) (cublasHandle_t, cublasFillMode_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDsbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDsbmv_v2", kApiTypeCublasV2);

    lretval = lcublasDsbmv_v2(handle, uplo, n, k, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDsbmv_v2 cublasDsbmv_v2


#undef cublasChbmv_v2
cublasStatus_t cublasChbmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * x, int incx, cuComplex const * beta, cuComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasChbmv_v2) (cublasHandle_t, cublasFillMode_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasChbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasChbmv_v2", kApiTypeCublasV2);

    lretval = lcublasChbmv_v2(handle, uplo, n, k, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasChbmv_v2 cublasChbmv_v2


#undef cublasZhbmv_v2
cublasStatus_t cublasZhbmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * x, int incx, cuDoubleComplex const * beta, cuDoubleComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZhbmv_v2) (cublasHandle_t, cublasFillMode_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZhbmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZhbmv_v2", kApiTypeCublasV2);

    lretval = lcublasZhbmv_v2(handle, uplo, n, k, alpha, A, lda, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZhbmv_v2 cublasZhbmv_v2


#undef cublasSspmv_v2
cublasStatus_t cublasSspmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * alpha, float const * AP, float const * x, int incx, float const * beta, float * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSspmv_v2) (cublasHandle_t, cublasFillMode_t, int, float const *, float const *, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, float const *, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSspmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSspmv_v2", kApiTypeCublasV2);

    lretval = lcublasSspmv_v2(handle, uplo, n, alpha, AP, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSspmv_v2 cublasSspmv_v2


#undef cublasDspmv_v2
cublasStatus_t cublasDspmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * alpha, double const * AP, double const * x, int incx, double const * beta, double * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDspmv_v2) (cublasHandle_t, cublasFillMode_t, int, double const *, double const *, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, double const *, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDspmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDspmv_v2", kApiTypeCublasV2);

    lretval = lcublasDspmv_v2(handle, uplo, n, alpha, AP, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDspmv_v2 cublasDspmv_v2


#undef cublasChpmv_v2
cublasStatus_t cublasChpmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * alpha, cuComplex const * AP, cuComplex const * x, int incx, cuComplex const * beta, cuComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasChpmv_v2) (cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasChpmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasChpmv_v2", kApiTypeCublasV2);

    lretval = lcublasChpmv_v2(handle, uplo, n, alpha, AP, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasChpmv_v2 cublasChpmv_v2


#undef cublasZhpmv_v2
cublasStatus_t cublasZhpmv_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * AP, cuDoubleComplex const * x, int incx, cuDoubleComplex const * beta, cuDoubleComplex * y, int incy){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZhpmv_v2) (cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZhpmv_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZhpmv_v2", kApiTypeCublasV2);

    lretval = lcublasZhpmv_v2(handle, uplo, n, alpha, AP, x, incx, beta, y, incy);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZhpmv_v2 cublasZhpmv_v2


#undef cublasSger_v2
cublasStatus_t cublasSger_v2(cublasHandle_t handle, int m, int n, float const * alpha, float const * x, int incx, float const * y, int incy, float * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSger_v2) (cublasHandle_t, int, int, float const *, float const *, int, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, float const *, float const *, int, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasSger_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSger_v2", kApiTypeCublasV2);

    lretval = lcublasSger_v2(handle, m, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSger_v2 cublasSger_v2


#undef cublasDger_v2
cublasStatus_t cublasDger_v2(cublasHandle_t handle, int m, int n, double const * alpha, double const * x, int incx, double const * y, int incy, double * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDger_v2) (cublasHandle_t, int, int, double const *, double const *, int, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, double const *, double const *, int, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDger_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDger_v2", kApiTypeCublasV2);

    lretval = lcublasDger_v2(handle, m, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDger_v2 cublasDger_v2


#undef cublasCgeru_v2
cublasStatus_t cublasCgeru_v2(cublasHandle_t handle, int m, int n, cuComplex const * alpha, cuComplex const * x, int incx, cuComplex const * y, int incy, cuComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgeru_v2) (cublasHandle_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCgeru_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgeru_v2", kApiTypeCublasV2);

    lretval = lcublasCgeru_v2(handle, m, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgeru_v2 cublasCgeru_v2


#undef cublasCgerc_v2
cublasStatus_t cublasCgerc_v2(cublasHandle_t handle, int m, int n, cuComplex const * alpha, cuComplex const * x, int incx, cuComplex const * y, int incy, cuComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgerc_v2) (cublasHandle_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCgerc_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgerc_v2", kApiTypeCublasV2);

    lretval = lcublasCgerc_v2(handle, m, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgerc_v2 cublasCgerc_v2


#undef cublasZgeru_v2
cublasStatus_t cublasZgeru_v2(cublasHandle_t handle, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * x, int incx, cuDoubleComplex const * y, int incy, cuDoubleComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgeru_v2) (cublasHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZgeru_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgeru_v2", kApiTypeCublasV2);

    lretval = lcublasZgeru_v2(handle, m, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgeru_v2 cublasZgeru_v2


#undef cublasZgerc_v2
cublasStatus_t cublasZgerc_v2(cublasHandle_t handle, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * x, int incx, cuDoubleComplex const * y, int incy, cuDoubleComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgerc_v2) (cublasHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZgerc_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgerc_v2", kApiTypeCublasV2);

    lretval = lcublasZgerc_v2(handle, m, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgerc_v2 cublasZgerc_v2


#undef cublasSsyr_v2
cublasStatus_t cublasSsyr_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * alpha, float const * x, int incx, float * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSsyr_v2) (cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasSsyr_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSsyr_v2", kApiTypeCublasV2);

    lretval = lcublasSsyr_v2(handle, uplo, n, alpha, x, incx, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSsyr_v2 cublasSsyr_v2


#undef cublasDsyr_v2
cublasStatus_t cublasDsyr_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * alpha, double const * x, int incx, double * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDsyr_v2) (cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDsyr_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDsyr_v2", kApiTypeCublasV2);

    lretval = lcublasDsyr_v2(handle, uplo, n, alpha, x, incx, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDsyr_v2 cublasDsyr_v2


#undef cublasCsyr_v2
cublasStatus_t cublasCsyr_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * alpha, cuComplex const * x, int incx, cuComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsyr_v2) (cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCsyr_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsyr_v2", kApiTypeCublasV2);

    lretval = lcublasCsyr_v2(handle, uplo, n, alpha, x, incx, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsyr_v2 cublasCsyr_v2


#undef cublasZsyr_v2
cublasStatus_t cublasZsyr_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * x, int incx, cuDoubleComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZsyr_v2) (cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZsyr_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZsyr_v2", kApiTypeCublasV2);

    lretval = lcublasZsyr_v2(handle, uplo, n, alpha, x, incx, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZsyr_v2 cublasZsyr_v2


#undef cublasCher_v2
cublasStatus_t cublasCher_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * alpha, cuComplex const * x, int incx, cuComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCher_v2) (cublasHandle_t, cublasFillMode_t, int, float const *, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCher_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCher_v2", kApiTypeCublasV2);

    lretval = lcublasCher_v2(handle, uplo, n, alpha, x, incx, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCher_v2 cublasCher_v2


#undef cublasZher_v2
cublasStatus_t cublasZher_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * alpha, cuDoubleComplex const * x, int incx, cuDoubleComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZher_v2) (cublasHandle_t, cublasFillMode_t, int, double const *, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZher_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZher_v2", kApiTypeCublasV2);

    lretval = lcublasZher_v2(handle, uplo, n, alpha, x, incx, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZher_v2 cublasZher_v2


#undef cublasSspr_v2
cublasStatus_t cublasSspr_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * alpha, float const * x, int incx, float * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSspr_v2) (cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float *))dlsym(RTLD_NEXT, "cublasSspr_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSspr_v2", kApiTypeCublasV2);

    lretval = lcublasSspr_v2(handle, uplo, n, alpha, x, incx, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSspr_v2 cublasSspr_v2


#undef cublasDspr_v2
cublasStatus_t cublasDspr_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * alpha, double const * x, int incx, double * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDspr_v2) (cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double *))dlsym(RTLD_NEXT, "cublasDspr_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDspr_v2", kApiTypeCublasV2);

    lretval = lcublasDspr_v2(handle, uplo, n, alpha, x, incx, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDspr_v2 cublasDspr_v2


#undef cublasChpr_v2
cublasStatus_t cublasChpr_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * alpha, cuComplex const * x, int incx, cuComplex * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasChpr_v2) (cublasHandle_t, cublasFillMode_t, int, float const *, cuComplex const *, int, cuComplex *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, cuComplex const *, int, cuComplex *))dlsym(RTLD_NEXT, "cublasChpr_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasChpr_v2", kApiTypeCublasV2);

    lretval = lcublasChpr_v2(handle, uplo, n, alpha, x, incx, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasChpr_v2 cublasChpr_v2


#undef cublasZhpr_v2
cublasStatus_t cublasZhpr_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * alpha, cuDoubleComplex const * x, int incx, cuDoubleComplex * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZhpr_v2) (cublasHandle_t, cublasFillMode_t, int, double const *, cuDoubleComplex const *, int, cuDoubleComplex *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, cuDoubleComplex const *, int, cuDoubleComplex *))dlsym(RTLD_NEXT, "cublasZhpr_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZhpr_v2", kApiTypeCublasV2);

    lretval = lcublasZhpr_v2(handle, uplo, n, alpha, x, incx, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZhpr_v2 cublasZhpr_v2


#undef cublasSsyr2_v2
cublasStatus_t cublasSsyr2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * alpha, float const * x, int incx, float const * y, int incy, float * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSsyr2_v2) (cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasSsyr2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSsyr2_v2", kApiTypeCublasV2);

    lretval = lcublasSsyr2_v2(handle, uplo, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSsyr2_v2 cublasSsyr2_v2


#undef cublasDsyr2_v2
cublasStatus_t cublasDsyr2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * alpha, double const * x, int incx, double const * y, int incy, double * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDsyr2_v2) (cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDsyr2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDsyr2_v2", kApiTypeCublasV2);

    lretval = lcublasDsyr2_v2(handle, uplo, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDsyr2_v2 cublasDsyr2_v2


#undef cublasCsyr2_v2
cublasStatus_t cublasCsyr2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * alpha, cuComplex const * x, int incx, cuComplex const * y, int incy, cuComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsyr2_v2) (cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCsyr2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsyr2_v2", kApiTypeCublasV2);

    lretval = lcublasCsyr2_v2(handle, uplo, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsyr2_v2 cublasCsyr2_v2


#undef cublasZsyr2_v2
cublasStatus_t cublasZsyr2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * x, int incx, cuDoubleComplex const * y, int incy, cuDoubleComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZsyr2_v2) (cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZsyr2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZsyr2_v2", kApiTypeCublasV2);

    lretval = lcublasZsyr2_v2(handle, uplo, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZsyr2_v2 cublasZsyr2_v2


#undef cublasCher2_v2
cublasStatus_t cublasCher2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * alpha, cuComplex const * x, int incx, cuComplex const * y, int incy, cuComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCher2_v2) (cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCher2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCher2_v2", kApiTypeCublasV2);

    lretval = lcublasCher2_v2(handle, uplo, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCher2_v2 cublasCher2_v2


#undef cublasZher2_v2
cublasStatus_t cublasZher2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * x, int incx, cuDoubleComplex const * y, int incy, cuDoubleComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZher2_v2) (cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZher2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZher2_v2", kApiTypeCublasV2);

    lretval = lcublasZher2_v2(handle, uplo, n, alpha, x, incx, y, incy, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZher2_v2 cublasZher2_v2


#undef cublasSspr2_v2
cublasStatus_t cublasSspr2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * alpha, float const * x, int incx, float const * y, int incy, float * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSspr2_v2) (cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float const *, int, float *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, float const *, int, float const *, int, float *))dlsym(RTLD_NEXT, "cublasSspr2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSspr2_v2", kApiTypeCublasV2);

    lretval = lcublasSspr2_v2(handle, uplo, n, alpha, x, incx, y, incy, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSspr2_v2 cublasSspr2_v2


#undef cublasDspr2_v2
cublasStatus_t cublasDspr2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * alpha, double const * x, int incx, double const * y, int incy, double * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDspr2_v2) (cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double const *, int, double *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, double const *, int, double const *, int, double *))dlsym(RTLD_NEXT, "cublasDspr2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDspr2_v2", kApiTypeCublasV2);

    lretval = lcublasDspr2_v2(handle, uplo, n, alpha, x, incx, y, incy, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDspr2_v2 cublasDspr2_v2


#undef cublasChpr2_v2
cublasStatus_t cublasChpr2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * alpha, cuComplex const * x, int incx, cuComplex const * y, int incy, cuComplex * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasChpr2_v2) (cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *))dlsym(RTLD_NEXT, "cublasChpr2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasChpr2_v2", kApiTypeCublasV2);

    lretval = lcublasChpr2_v2(handle, uplo, n, alpha, x, incx, y, incy, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasChpr2_v2 cublasChpr2_v2


#undef cublasZhpr2_v2
cublasStatus_t cublasZhpr2_v2(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * x, int incx, cuDoubleComplex const * y, int incy, cuDoubleComplex * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZhpr2_v2) (cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *))dlsym(RTLD_NEXT, "cublasZhpr2_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZhpr2_v2", kApiTypeCublasV2);

    lretval = lcublasZhpr2_v2(handle, uplo, n, alpha, x, incx, y, incy, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZhpr2_v2 cublasZhpr2_v2


#undef cublasSgemm_v2
cublasStatus_t cublasSgemm_v2(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, float const * alpha, float const * A, int lda, float const * B, int ldb, float const * beta, float * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgemm_v2) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, float const *, float const *, int, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, float const *, float const *, int, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSgemm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgemm_v2", kApiTypeCublasV2);

    lretval = lcublasSgemm_v2(handle, transa, transb, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgemm_v2 cublasSgemm_v2


#undef cublasDgemm_v2
cublasStatus_t cublasDgemm_v2(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, double const * alpha, double const * A, int lda, double const * B, int ldb, double const * beta, double * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgemm_v2) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, double const *, double const *, int, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, double const *, double const *, int, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDgemm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgemm_v2", kApiTypeCublasV2);

    lretval = lcublasDgemm_v2(handle, transa, transb, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgemm_v2 cublasDgemm_v2


#undef cublasCgemm_v2
cublasStatus_t cublasCgemm_v2(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * B, int ldb, cuComplex const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgemm_v2) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCgemm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgemm_v2", kApiTypeCublasV2);

    lretval = lcublasCgemm_v2(handle, transa, transb, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgemm_v2 cublasCgemm_v2


#undef cublasCgemm3m
cublasStatus_t cublasCgemm3m(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * B, int ldb, cuComplex const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgemm3m) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCgemm3m");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgemm3m", kApiTypeCublasV2);

    lretval = lcublasCgemm3m(handle, transa, transb, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgemm3m cublasCgemm3m


#undef cublasCgemm3mEx
cublasStatus_t cublasCgemm3mEx(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuComplex const * alpha, void const * A, cudaDataType Atype, int lda, void const * B, cudaDataType Btype, int ldb, cuComplex const * beta, void * C, cudaDataType Ctype, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgemm3mEx) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, void const *, cudaDataType, int, void const *, cudaDataType, int, cuComplex const *, void *, cudaDataType, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, void const *, cudaDataType, int, void const *, cudaDataType, int, cuComplex const *, void *, cudaDataType, int))dlsym(RTLD_NEXT, "cublasCgemm3mEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgemm3mEx", kApiTypeCublasV2);

    lretval = lcublasCgemm3mEx(handle, transa, transb, m, n, k, alpha, A, Atype, lda, B, Btype, ldb, beta, C, Ctype, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgemm3mEx cublasCgemm3mEx


#undef cublasZgemm_v2
cublasStatus_t cublasZgemm_v2(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgemm_v2) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZgemm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgemm_v2", kApiTypeCublasV2);

    lretval = lcublasZgemm_v2(handle, transa, transb, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgemm_v2 cublasZgemm_v2


#undef cublasZgemm3m
cublasStatus_t cublasZgemm3m(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgemm3m) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZgemm3m");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgemm3m", kApiTypeCublasV2);

    lretval = lcublasZgemm3m(handle, transa, transb, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgemm3m cublasZgemm3m


#undef cublasHgemm
cublasStatus_t cublasHgemm(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, __half const * alpha, __half const * A, int lda, __half const * B, int ldb, __half const * beta, __half * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasHgemm) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, __half const *, __half const *, int, __half const *, int, __half const *, __half *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, __half const *, __half const *, int, __half const *, int, __half const *, __half *, int))dlsym(RTLD_NEXT, "cublasHgemm");
    
    /* pre exeuction logics */
    ac.add_counter("cublasHgemm", kApiTypeCublasV2);

    lretval = lcublasHgemm(handle, transa, transb, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasHgemm cublasHgemm


#undef cublasSgemmEx
cublasStatus_t cublasSgemmEx(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, float const * alpha, void const * A, cudaDataType Atype, int lda, void const * B, cudaDataType Btype, int ldb, float const * beta, void * C, cudaDataType Ctype, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgemmEx) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, float const *, void const *, cudaDataType, int, void const *, cudaDataType, int, float const *, void *, cudaDataType, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, float const *, void const *, cudaDataType, int, void const *, cudaDataType, int, float const *, void *, cudaDataType, int))dlsym(RTLD_NEXT, "cublasSgemmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgemmEx", kApiTypeCublasV2);

    lretval = lcublasSgemmEx(handle, transa, transb, m, n, k, alpha, A, Atype, lda, B, Btype, ldb, beta, C, Ctype, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgemmEx cublasSgemmEx


#undef cublasGemmEx
cublasStatus_t cublasGemmEx(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, void const * alpha, void const * A, cudaDataType Atype, int lda, void const * B, cudaDataType Btype, int ldb, void const * beta, void * C, cudaDataType Ctype, int ldc, cublasComputeType_t computeType, cublasGemmAlgo_t algo){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGemmEx) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, void const *, void const *, cudaDataType, int, void const *, cudaDataType, int, void const *, void *, cudaDataType, int, cublasComputeType_t, cublasGemmAlgo_t) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, void const *, void const *, cudaDataType, int, void const *, cudaDataType, int, void const *, void *, cudaDataType, int, cublasComputeType_t, cublasGemmAlgo_t))dlsym(RTLD_NEXT, "cublasGemmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGemmEx", kApiTypeCublasV2);

    lretval = lcublasGemmEx(handle, transa, transb, m, n, k, alpha, A, Atype, lda, B, Btype, ldb, beta, C, Ctype, ldc, computeType, algo);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGemmEx cublasGemmEx


#undef cublasCgemmEx
cublasStatus_t cublasCgemmEx(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuComplex const * alpha, void const * A, cudaDataType Atype, int lda, void const * B, cudaDataType Btype, int ldb, cuComplex const * beta, void * C, cudaDataType Ctype, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgemmEx) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, void const *, cudaDataType, int, void const *, cudaDataType, int, cuComplex const *, void *, cudaDataType, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, void const *, cudaDataType, int, void const *, cudaDataType, int, cuComplex const *, void *, cudaDataType, int))dlsym(RTLD_NEXT, "cublasCgemmEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgemmEx", kApiTypeCublasV2);

    lretval = lcublasCgemmEx(handle, transa, transb, m, n, k, alpha, A, Atype, lda, B, Btype, ldb, beta, C, Ctype, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgemmEx cublasCgemmEx


#undef cublasUint8gemmBias
cublasStatus_t cublasUint8gemmBias(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, cublasOperation_t transc, int m, int n, int k, unsigned char const * A, int A_bias, int lda, unsigned char const * B, int B_bias, int ldb, unsigned char * C, int C_bias, int ldc, int C_mult, int C_shift){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasUint8gemmBias) (cublasHandle_t, cublasOperation_t, cublasOperation_t, cublasOperation_t, int, int, int, unsigned char const *, int, int, unsigned char const *, int, int, unsigned char *, int, int, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, cublasOperation_t, int, int, int, unsigned char const *, int, int, unsigned char const *, int, int, unsigned char *, int, int, int, int))dlsym(RTLD_NEXT, "cublasUint8gemmBias");
    
    /* pre exeuction logics */
    ac.add_counter("cublasUint8gemmBias", kApiTypeCublasV2);

    lretval = lcublasUint8gemmBias(handle, transa, transb, transc, m, n, k, A, A_bias, lda, B, B_bias, ldb, C, C_bias, ldc, C_mult, C_shift);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasUint8gemmBias cublasUint8gemmBias


#undef cublasSsyrk_v2
cublasStatus_t cublasSsyrk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, float const * alpha, float const * A, int lda, float const * beta, float * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSsyrk_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSsyrk_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSsyrk_v2", kApiTypeCublasV2);

    lretval = lcublasSsyrk_v2(handle, uplo, trans, n, k, alpha, A, lda, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSsyrk_v2 cublasSsyrk_v2


#undef cublasDsyrk_v2
cublasStatus_t cublasDsyrk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, double const * alpha, double const * A, int lda, double const * beta, double * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDsyrk_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDsyrk_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDsyrk_v2", kApiTypeCublasV2);

    lretval = lcublasDsyrk_v2(handle, uplo, trans, n, k, alpha, A, lda, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDsyrk_v2 cublasDsyrk_v2


#undef cublasCsyrk_v2
cublasStatus_t cublasCsyrk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsyrk_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCsyrk_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsyrk_v2", kApiTypeCublasV2);

    lretval = lcublasCsyrk_v2(handle, uplo, trans, n, k, alpha, A, lda, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsyrk_v2 cublasCsyrk_v2


#undef cublasZsyrk_v2
cublasStatus_t cublasZsyrk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZsyrk_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZsyrk_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZsyrk_v2", kApiTypeCublasV2);

    lretval = lcublasZsyrk_v2(handle, uplo, trans, n, k, alpha, A, lda, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZsyrk_v2 cublasZsyrk_v2


#undef cublasCsyrkEx
cublasStatus_t cublasCsyrkEx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuComplex const * alpha, void const * A, cudaDataType Atype, int lda, cuComplex const * beta, void * C, cudaDataType Ctype, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsyrkEx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, void const *, cudaDataType, int, cuComplex const *, void *, cudaDataType, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, void const *, cudaDataType, int, cuComplex const *, void *, cudaDataType, int))dlsym(RTLD_NEXT, "cublasCsyrkEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsyrkEx", kApiTypeCublasV2);

    lretval = lcublasCsyrkEx(handle, uplo, trans, n, k, alpha, A, Atype, lda, beta, C, Ctype, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsyrkEx cublasCsyrkEx


#undef cublasCsyrk3mEx
cublasStatus_t cublasCsyrk3mEx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuComplex const * alpha, void const * A, cudaDataType Atype, int lda, cuComplex const * beta, void * C, cudaDataType Ctype, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsyrk3mEx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, void const *, cudaDataType, int, cuComplex const *, void *, cudaDataType, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, void const *, cudaDataType, int, cuComplex const *, void *, cudaDataType, int))dlsym(RTLD_NEXT, "cublasCsyrk3mEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsyrk3mEx", kApiTypeCublasV2);

    lretval = lcublasCsyrk3mEx(handle, uplo, trans, n, k, alpha, A, Atype, lda, beta, C, Ctype, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsyrk3mEx cublasCsyrk3mEx


#undef cublasCherk_v2
cublasStatus_t cublasCherk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, float const * alpha, cuComplex const * A, int lda, float const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCherk_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, cuComplex const *, int, float const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, cuComplex const *, int, float const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCherk_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCherk_v2", kApiTypeCublasV2);

    lretval = lcublasCherk_v2(handle, uplo, trans, n, k, alpha, A, lda, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCherk_v2 cublasCherk_v2


#undef cublasZherk_v2
cublasStatus_t cublasZherk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, double const * alpha, cuDoubleComplex const * A, int lda, double const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZherk_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, cuDoubleComplex const *, int, double const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, cuDoubleComplex const *, int, double const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZherk_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZherk_v2", kApiTypeCublasV2);

    lretval = lcublasZherk_v2(handle, uplo, trans, n, k, alpha, A, lda, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZherk_v2 cublasZherk_v2


#undef cublasCherkEx
cublasStatus_t cublasCherkEx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, float const * alpha, void const * A, cudaDataType Atype, int lda, float const * beta, void * C, cudaDataType Ctype, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCherkEx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, void const *, cudaDataType, int, float const *, void *, cudaDataType, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, void const *, cudaDataType, int, float const *, void *, cudaDataType, int))dlsym(RTLD_NEXT, "cublasCherkEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCherkEx", kApiTypeCublasV2);

    lretval = lcublasCherkEx(handle, uplo, trans, n, k, alpha, A, Atype, lda, beta, C, Ctype, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCherkEx cublasCherkEx


#undef cublasCherk3mEx
cublasStatus_t cublasCherk3mEx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, float const * alpha, void const * A, cudaDataType Atype, int lda, float const * beta, void * C, cudaDataType Ctype, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCherk3mEx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, void const *, cudaDataType, int, float const *, void *, cudaDataType, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, void const *, cudaDataType, int, float const *, void *, cudaDataType, int))dlsym(RTLD_NEXT, "cublasCherk3mEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCherk3mEx", kApiTypeCublasV2);

    lretval = lcublasCherk3mEx(handle, uplo, trans, n, k, alpha, A, Atype, lda, beta, C, Ctype, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCherk3mEx cublasCherk3mEx


#undef cublasSsyr2k_v2
cublasStatus_t cublasSsyr2k_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, float const * alpha, float const * A, int lda, float const * B, int ldb, float const * beta, float * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSsyr2k_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSsyr2k_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSsyr2k_v2", kApiTypeCublasV2);

    lretval = lcublasSsyr2k_v2(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSsyr2k_v2 cublasSsyr2k_v2


#undef cublasDsyr2k_v2
cublasStatus_t cublasDsyr2k_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, double const * alpha, double const * A, int lda, double const * B, int ldb, double const * beta, double * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDsyr2k_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDsyr2k_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDsyr2k_v2", kApiTypeCublasV2);

    lretval = lcublasDsyr2k_v2(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDsyr2k_v2 cublasDsyr2k_v2


#undef cublasCsyr2k_v2
cublasStatus_t cublasCsyr2k_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * B, int ldb, cuComplex const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsyr2k_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCsyr2k_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsyr2k_v2", kApiTypeCublasV2);

    lretval = lcublasCsyr2k_v2(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsyr2k_v2 cublasCsyr2k_v2


#undef cublasZsyr2k_v2
cublasStatus_t cublasZsyr2k_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZsyr2k_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZsyr2k_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZsyr2k_v2", kApiTypeCublasV2);

    lretval = lcublasZsyr2k_v2(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZsyr2k_v2 cublasZsyr2k_v2


#undef cublasCher2k_v2
cublasStatus_t cublasCher2k_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * B, int ldb, float const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCher2k_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, float const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, float const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCher2k_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCher2k_v2", kApiTypeCublasV2);

    lretval = lcublasCher2k_v2(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCher2k_v2 cublasCher2k_v2


#undef cublasZher2k_v2
cublasStatus_t cublasZher2k_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, double const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZher2k_v2) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZher2k_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZher2k_v2", kApiTypeCublasV2);

    lretval = lcublasZher2k_v2(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZher2k_v2 cublasZher2k_v2


#undef cublasSsyrkx
cublasStatus_t cublasSsyrkx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, float const * alpha, float const * A, int lda, float const * B, int ldb, float const * beta, float * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSsyrkx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSsyrkx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSsyrkx", kApiTypeCublasV2);

    lretval = lcublasSsyrkx(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSsyrkx cublasSsyrkx


#undef cublasDsyrkx
cublasStatus_t cublasDsyrkx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, double const * alpha, double const * A, int lda, double const * B, int ldb, double const * beta, double * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDsyrkx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDsyrkx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDsyrkx", kApiTypeCublasV2);

    lretval = lcublasDsyrkx(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDsyrkx cublasDsyrkx


#undef cublasCsyrkx
cublasStatus_t cublasCsyrkx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * B, int ldb, cuComplex const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsyrkx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCsyrkx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsyrkx", kApiTypeCublasV2);

    lretval = lcublasCsyrkx(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsyrkx cublasCsyrkx


#undef cublasZsyrkx
cublasStatus_t cublasZsyrkx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZsyrkx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZsyrkx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZsyrkx", kApiTypeCublasV2);

    lretval = lcublasZsyrkx(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZsyrkx cublasZsyrkx


#undef cublasCherkx
cublasStatus_t cublasCherkx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * B, int ldb, float const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCherkx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, float const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, float const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCherkx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCherkx", kApiTypeCublasV2);

    lretval = lcublasCherkx(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCherkx cublasCherkx


#undef cublasZherkx
cublasStatus_t cublasZherkx(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, double const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZherkx) (cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZherkx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZherkx", kApiTypeCublasV2);

    lretval = lcublasZherkx(handle, uplo, trans, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZherkx cublasZherkx


#undef cublasSsymm_v2
cublasStatus_t cublasSsymm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, int m, int n, float const * alpha, float const * A, int lda, float const * B, int ldb, float const * beta, float * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSsymm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, float const *, float const *, int, float const *, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasSsymm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSsymm_v2", kApiTypeCublasV2);

    lretval = lcublasSsymm_v2(handle, side, uplo, m, n, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSsymm_v2 cublasSsymm_v2


#undef cublasDsymm_v2
cublasStatus_t cublasDsymm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, int m, int n, double const * alpha, double const * A, int lda, double const * B, int ldb, double const * beta, double * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDsymm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, double const *, double const *, int, double const *, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDsymm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDsymm_v2", kApiTypeCublasV2);

    lretval = lcublasDsymm_v2(handle, side, uplo, m, n, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDsymm_v2 cublasDsymm_v2


#undef cublasCsymm_v2
cublasStatus_t cublasCsymm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, int m, int n, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * B, int ldb, cuComplex const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCsymm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCsymm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCsymm_v2", kApiTypeCublasV2);

    lretval = lcublasCsymm_v2(handle, side, uplo, m, n, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCsymm_v2 cublasCsymm_v2


#undef cublasZsymm_v2
cublasStatus_t cublasZsymm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZsymm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZsymm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZsymm_v2", kApiTypeCublasV2);

    lretval = lcublasZsymm_v2(handle, side, uplo, m, n, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZsymm_v2 cublasZsymm_v2


#undef cublasChemm_v2
cublasStatus_t cublasChemm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, int m, int n, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * B, int ldb, cuComplex const * beta, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasChemm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasChemm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasChemm_v2", kApiTypeCublasV2);

    lretval = lcublasChemm_v2(handle, side, uplo, m, n, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasChemm_v2 cublasChemm_v2


#undef cublasZhemm_v2
cublasStatus_t cublasZhemm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZhemm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZhemm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZhemm_v2", kApiTypeCublasV2);

    lretval = lcublasZhemm_v2(handle, side, uplo, m, n, alpha, A, lda, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZhemm_v2 cublasZhemm_v2


#undef cublasStrsm_v2
cublasStatus_t cublasStrsm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, float const * alpha, float const * A, int lda, float * B, int ldb){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStrsm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasStrsm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStrsm_v2", kApiTypeCublasV2);

    lretval = lcublasStrsm_v2(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStrsm_v2 cublasStrsm_v2


#undef cublasDtrsm_v2
cublasStatus_t cublasDtrsm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, double const * alpha, double const * A, int lda, double * B, int ldb){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtrsm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDtrsm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtrsm_v2", kApiTypeCublasV2);

    lretval = lcublasDtrsm_v2(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtrsm_v2 cublasDtrsm_v2


#undef cublasCtrsm_v2
cublasStatus_t cublasCtrsm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex * B, int ldb){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtrsm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCtrsm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtrsm_v2", kApiTypeCublasV2);

    lretval = lcublasCtrsm_v2(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtrsm_v2 cublasCtrsm_v2


#undef cublasZtrsm_v2
cublasStatus_t cublasZtrsm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex * B, int ldb){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtrsm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZtrsm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtrsm_v2", kApiTypeCublasV2);

    lretval = lcublasZtrsm_v2(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtrsm_v2 cublasZtrsm_v2


#undef cublasStrmm_v2
cublasStatus_t cublasStrmm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, float const * alpha, float const * A, int lda, float const * B, int ldb, float * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStrmm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, float const *, int, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, float const *, int, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasStrmm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStrmm_v2", kApiTypeCublasV2);

    lretval = lcublasStrmm_v2(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStrmm_v2 cublasStrmm_v2


#undef cublasDtrmm_v2
cublasStatus_t cublasDtrmm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, double const * alpha, double const * A, int lda, double const * B, int ldb, double * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtrmm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, double const *, int, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, double const *, int, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDtrmm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtrmm_v2", kApiTypeCublasV2);

    lretval = lcublasDtrmm_v2(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtrmm_v2 cublasDtrmm_v2


#undef cublasCtrmm_v2
cublasStatus_t cublasCtrmm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * B, int ldb, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtrmm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCtrmm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtrmm_v2", kApiTypeCublasV2);

    lretval = lcublasCtrmm_v2(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtrmm_v2 cublasCtrmm_v2


#undef cublasZtrmm_v2
cublasStatus_t cublasZtrmm_v2(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtrmm_v2) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZtrmm_v2");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtrmm_v2", kApiTypeCublasV2);

    lretval = lcublasZtrmm_v2(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtrmm_v2 cublasZtrmm_v2


#undef cublasHgemmBatched
cublasStatus_t cublasHgemmBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, __half const * alpha, __half const * const * Aarray, int lda, __half const * const * Barray, int ldb, __half const * beta, __half * const * Carray, int ldc, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasHgemmBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, __half const *, __half const * const *, int, __half const * const *, int, __half const *, __half * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, __half const *, __half const * const *, int, __half const * const *, int, __half const *, __half * const *, int, int))dlsym(RTLD_NEXT, "cublasHgemmBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasHgemmBatched", kApiTypeCublasV2);

    lretval = lcublasHgemmBatched(handle, transa, transb, m, n, k, alpha, Aarray, lda, Barray, ldb, beta, Carray, ldc, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasHgemmBatched cublasHgemmBatched


#undef cublasSgemmBatched
cublasStatus_t cublasSgemmBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, float const * alpha, float const * const * Aarray, int lda, float const * const * Barray, int ldb, float const * beta, float * const * Carray, int ldc, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgemmBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, float const *, float const * const *, int, float const * const *, int, float const *, float * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, float const *, float const * const *, int, float const * const *, int, float const *, float * const *, int, int))dlsym(RTLD_NEXT, "cublasSgemmBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgemmBatched", kApiTypeCublasV2);

    lretval = lcublasSgemmBatched(handle, transa, transb, m, n, k, alpha, Aarray, lda, Barray, ldb, beta, Carray, ldc, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgemmBatched cublasSgemmBatched


#undef cublasDgemmBatched
cublasStatus_t cublasDgemmBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, double const * alpha, double const * const * Aarray, int lda, double const * const * Barray, int ldb, double const * beta, double * const * Carray, int ldc, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgemmBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, double const *, double const * const *, int, double const * const *, int, double const *, double * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, double const *, double const * const *, int, double const * const *, int, double const *, double * const *, int, int))dlsym(RTLD_NEXT, "cublasDgemmBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgemmBatched", kApiTypeCublasV2);

    lretval = lcublasDgemmBatched(handle, transa, transb, m, n, k, alpha, Aarray, lda, Barray, ldb, beta, Carray, ldc, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgemmBatched cublasDgemmBatched


#undef cublasCgemmBatched
cublasStatus_t cublasCgemmBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuComplex const * alpha, cuComplex const * const * Aarray, int lda, cuComplex const * const * Barray, int ldb, cuComplex const * beta, cuComplex * const * Carray, int ldc, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgemmBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const * const *, int, cuComplex const * const *, int, cuComplex const *, cuComplex * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const * const *, int, cuComplex const * const *, int, cuComplex const *, cuComplex * const *, int, int))dlsym(RTLD_NEXT, "cublasCgemmBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgemmBatched", kApiTypeCublasV2);

    lretval = lcublasCgemmBatched(handle, transa, transb, m, n, k, alpha, Aarray, lda, Barray, ldb, beta, Carray, ldc, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgemmBatched cublasCgemmBatched


#undef cublasCgemm3mBatched
cublasStatus_t cublasCgemm3mBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuComplex const * alpha, cuComplex const * const * Aarray, int lda, cuComplex const * const * Barray, int ldb, cuComplex const * beta, cuComplex * const * Carray, int ldc, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgemm3mBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const * const *, int, cuComplex const * const *, int, cuComplex const *, cuComplex * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const * const *, int, cuComplex const * const *, int, cuComplex const *, cuComplex * const *, int, int))dlsym(RTLD_NEXT, "cublasCgemm3mBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgemm3mBatched", kApiTypeCublasV2);

    lretval = lcublasCgemm3mBatched(handle, transa, transb, m, n, k, alpha, Aarray, lda, Barray, ldb, beta, Carray, ldc, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgemm3mBatched cublasCgemm3mBatched


#undef cublasZgemmBatched
cublasStatus_t cublasZgemmBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * const * Aarray, int lda, cuDoubleComplex const * const * Barray, int ldb, cuDoubleComplex const * beta, cuDoubleComplex * const * Carray, int ldc, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgemmBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, cuDoubleComplex const * const *, int, cuDoubleComplex const * const *, int, cuDoubleComplex const *, cuDoubleComplex * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, cuDoubleComplex const * const *, int, cuDoubleComplex const * const *, int, cuDoubleComplex const *, cuDoubleComplex * const *, int, int))dlsym(RTLD_NEXT, "cublasZgemmBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgemmBatched", kApiTypeCublasV2);

    lretval = lcublasZgemmBatched(handle, transa, transb, m, n, k, alpha, Aarray, lda, Barray, ldb, beta, Carray, ldc, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgemmBatched cublasZgemmBatched


#undef cublasGemmBatchedEx
cublasStatus_t cublasGemmBatchedEx(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, void const * alpha, void const * const * Aarray, cudaDataType Atype, int lda, void const * const * Barray, cudaDataType Btype, int ldb, void const * beta, void * const * Carray, cudaDataType Ctype, int ldc, int batchCount, cublasComputeType_t computeType, cublasGemmAlgo_t algo){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGemmBatchedEx) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, void const *, void const * const *, cudaDataType, int, void const * const *, cudaDataType, int, void const *, void * const *, cudaDataType, int, int, cublasComputeType_t, cublasGemmAlgo_t) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, void const *, void const * const *, cudaDataType, int, void const * const *, cudaDataType, int, void const *, void * const *, cudaDataType, int, int, cublasComputeType_t, cublasGemmAlgo_t))dlsym(RTLD_NEXT, "cublasGemmBatchedEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGemmBatchedEx", kApiTypeCublasV2);

    lretval = lcublasGemmBatchedEx(handle, transa, transb, m, n, k, alpha, Aarray, Atype, lda, Barray, Btype, ldb, beta, Carray, Ctype, ldc, batchCount, computeType, algo);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGemmBatchedEx cublasGemmBatchedEx


#undef cublasGemmStridedBatchedEx
cublasStatus_t cublasGemmStridedBatchedEx(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, void const * alpha, void const * A, cudaDataType Atype, int lda, long long int strideA, void const * B, cudaDataType Btype, int ldb, long long int strideB, void const * beta, void * C, cudaDataType Ctype, int ldc, long long int strideC, int batchCount, cublasComputeType_t computeType, cublasGemmAlgo_t algo){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasGemmStridedBatchedEx) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, void const *, void const *, cudaDataType, int, long long int, void const *, cudaDataType, int, long long int, void const *, void *, cudaDataType, int, long long int, int, cublasComputeType_t, cublasGemmAlgo_t) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, void const *, void const *, cudaDataType, int, long long int, void const *, cudaDataType, int, long long int, void const *, void *, cudaDataType, int, long long int, int, cublasComputeType_t, cublasGemmAlgo_t))dlsym(RTLD_NEXT, "cublasGemmStridedBatchedEx");
    
    /* pre exeuction logics */
    ac.add_counter("cublasGemmStridedBatchedEx", kApiTypeCublasV2);

    lretval = lcublasGemmStridedBatchedEx(handle, transa, transb, m, n, k, alpha, A, Atype, lda, strideA, B, Btype, ldb, strideB, beta, C, Ctype, ldc, strideC, batchCount, computeType, algo);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasGemmStridedBatchedEx cublasGemmStridedBatchedEx


#undef cublasSgemmStridedBatched
cublasStatus_t cublasSgemmStridedBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, float const * alpha, float const * A, int lda, long long int strideA, float const * B, int ldb, long long int strideB, float const * beta, float * C, int ldc, long long int strideC, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgemmStridedBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, float const *, float const *, int, long long int, float const *, int, long long int, float const *, float *, int, long long int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, float const *, float const *, int, long long int, float const *, int, long long int, float const *, float *, int, long long int, int))dlsym(RTLD_NEXT, "cublasSgemmStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgemmStridedBatched", kApiTypeCublasV2);

    lretval = lcublasSgemmStridedBatched(handle, transa, transb, m, n, k, alpha, A, lda, strideA, B, ldb, strideB, beta, C, ldc, strideC, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgemmStridedBatched cublasSgemmStridedBatched


#undef cublasDgemmStridedBatched
cublasStatus_t cublasDgemmStridedBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, double const * alpha, double const * A, int lda, long long int strideA, double const * B, int ldb, long long int strideB, double const * beta, double * C, int ldc, long long int strideC, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgemmStridedBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, double const *, double const *, int, long long int, double const *, int, long long int, double const *, double *, int, long long int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, double const *, double const *, int, long long int, double const *, int, long long int, double const *, double *, int, long long int, int))dlsym(RTLD_NEXT, "cublasDgemmStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgemmStridedBatched", kApiTypeCublasV2);

    lretval = lcublasDgemmStridedBatched(handle, transa, transb, m, n, k, alpha, A, lda, strideA, B, ldb, strideB, beta, C, ldc, strideC, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgemmStridedBatched cublasDgemmStridedBatched


#undef cublasCgemmStridedBatched
cublasStatus_t cublasCgemmStridedBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, long long int strideA, cuComplex const * B, int ldb, long long int strideB, cuComplex const * beta, cuComplex * C, int ldc, long long int strideC, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgemmStridedBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const *, int, long long int, cuComplex const *, int, long long int, cuComplex const *, cuComplex *, int, long long int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const *, int, long long int, cuComplex const *, int, long long int, cuComplex const *, cuComplex *, int, long long int, int))dlsym(RTLD_NEXT, "cublasCgemmStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgemmStridedBatched", kApiTypeCublasV2);

    lretval = lcublasCgemmStridedBatched(handle, transa, transb, m, n, k, alpha, A, lda, strideA, B, ldb, strideB, beta, C, ldc, strideC, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgemmStridedBatched cublasCgemmStridedBatched


#undef cublasCgemm3mStridedBatched
cublasStatus_t cublasCgemm3mStridedBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuComplex const * alpha, cuComplex const * A, int lda, long long int strideA, cuComplex const * B, int ldb, long long int strideB, cuComplex const * beta, cuComplex * C, int ldc, long long int strideC, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgemm3mStridedBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const *, int, long long int, cuComplex const *, int, long long int, cuComplex const *, cuComplex *, int, long long int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuComplex const *, cuComplex const *, int, long long int, cuComplex const *, int, long long int, cuComplex const *, cuComplex *, int, long long int, int))dlsym(RTLD_NEXT, "cublasCgemm3mStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgemm3mStridedBatched", kApiTypeCublasV2);

    lretval = lcublasCgemm3mStridedBatched(handle, transa, transb, m, n, k, alpha, A, lda, strideA, B, ldb, strideB, beta, C, ldc, strideC, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgemm3mStridedBatched cublasCgemm3mStridedBatched


#undef cublasZgemmStridedBatched
cublasStatus_t cublasZgemmStridedBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, long long int strideA, cuDoubleComplex const * B, int ldb, long long int strideB, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc, long long int strideC, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgemmStridedBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, long long int, cuDoubleComplex const *, int, long long int, cuDoubleComplex const *, cuDoubleComplex *, int, long long int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, long long int, cuDoubleComplex const *, int, long long int, cuDoubleComplex const *, cuDoubleComplex *, int, long long int, int))dlsym(RTLD_NEXT, "cublasZgemmStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgemmStridedBatched", kApiTypeCublasV2);

    lretval = lcublasZgemmStridedBatched(handle, transa, transb, m, n, k, alpha, A, lda, strideA, B, ldb, strideB, beta, C, ldc, strideC, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgemmStridedBatched cublasZgemmStridedBatched


#undef cublasHgemmStridedBatched
cublasStatus_t cublasHgemmStridedBatched(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, __half const * alpha, __half const * A, int lda, long long int strideA, __half const * B, int ldb, long long int strideB, __half const * beta, __half * C, int ldc, long long int strideC, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasHgemmStridedBatched) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, __half const *, __half const *, int, long long int, __half const *, int, long long int, __half const *, __half *, int, long long int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, int, __half const *, __half const *, int, long long int, __half const *, int, long long int, __half const *, __half *, int, long long int, int))dlsym(RTLD_NEXT, "cublasHgemmStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasHgemmStridedBatched", kApiTypeCublasV2);

    lretval = lcublasHgemmStridedBatched(handle, transa, transb, m, n, k, alpha, A, lda, strideA, B, ldb, strideB, beta, C, ldc, strideC, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasHgemmStridedBatched cublasHgemmStridedBatched


#undef cublasSgeam
cublasStatus_t cublasSgeam(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, float const * alpha, float const * A, int lda, float const * beta, float const * B, int ldb, float * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgeam) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, float const *, float const *, int, float const *, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasSgeam");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgeam", kApiTypeCublasV2);

    lretval = lcublasSgeam(handle, transa, transb, m, n, alpha, A, lda, beta, B, ldb, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgeam cublasSgeam


#undef cublasDgeam
cublasStatus_t cublasDgeam(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, double const * alpha, double const * A, int lda, double const * beta, double const * B, int ldb, double * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgeam) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, double const *, double const *, int, double const *, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDgeam");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgeam", kApiTypeCublasV2);

    lretval = lcublasDgeam(handle, transa, transb, m, n, alpha, A, lda, beta, B, ldb, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgeam cublasDgeam


#undef cublasCgeam
cublasStatus_t cublasCgeam(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * beta, cuComplex const * B, int ldb, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgeam) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCgeam");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgeam", kApiTypeCublasV2);

    lretval = lcublasCgeam(handle, transa, transb, m, n, alpha, A, lda, beta, B, ldb, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgeam cublasCgeam


#undef cublasZgeam
cublasStatus_t cublasZgeam(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * beta, cuDoubleComplex const * B, int ldb, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgeam) (cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, cublasOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZgeam");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgeam", kApiTypeCublasV2);

    lretval = lcublasZgeam(handle, transa, transb, m, n, alpha, A, lda, beta, B, ldb, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgeam cublasZgeam


#undef cublasSgetrfBatched
cublasStatus_t cublasSgetrfBatched(cublasHandle_t handle, int n, float * const * A, int lda, int * P, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgetrfBatched) (cublasHandle_t, int, float * const *, int, int *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, float * const *, int, int *, int *, int))dlsym(RTLD_NEXT, "cublasSgetrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgetrfBatched", kApiTypeCublasV2);

    lretval = lcublasSgetrfBatched(handle, n, A, lda, P, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgetrfBatched cublasSgetrfBatched


#undef cublasDgetrfBatched
cublasStatus_t cublasDgetrfBatched(cublasHandle_t handle, int n, double * const * A, int lda, int * P, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgetrfBatched) (cublasHandle_t, int, double * const *, int, int *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, double * const *, int, int *, int *, int))dlsym(RTLD_NEXT, "cublasDgetrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgetrfBatched", kApiTypeCublasV2);

    lretval = lcublasDgetrfBatched(handle, n, A, lda, P, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgetrfBatched cublasDgetrfBatched


#undef cublasCgetrfBatched
cublasStatus_t cublasCgetrfBatched(cublasHandle_t handle, int n, cuComplex * const * A, int lda, int * P, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgetrfBatched) (cublasHandle_t, int, cuComplex * const *, int, int *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex * const *, int, int *, int *, int))dlsym(RTLD_NEXT, "cublasCgetrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgetrfBatched", kApiTypeCublasV2);

    lretval = lcublasCgetrfBatched(handle, n, A, lda, P, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgetrfBatched cublasCgetrfBatched


#undef cublasZgetrfBatched
cublasStatus_t cublasZgetrfBatched(cublasHandle_t handle, int n, cuDoubleComplex * const * A, int lda, int * P, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgetrfBatched) (cublasHandle_t, int, cuDoubleComplex * const *, int, int *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex * const *, int, int *, int *, int))dlsym(RTLD_NEXT, "cublasZgetrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgetrfBatched", kApiTypeCublasV2);

    lretval = lcublasZgetrfBatched(handle, n, A, lda, P, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgetrfBatched cublasZgetrfBatched


#undef cublasSgetriBatched
cublasStatus_t cublasSgetriBatched(cublasHandle_t handle, int n, float const * const * A, int lda, int const * P, float * const * C, int ldc, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgetriBatched) (cublasHandle_t, int, float const * const *, int, int const *, float * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, float const * const *, int, int const *, float * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasSgetriBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgetriBatched", kApiTypeCublasV2);

    lretval = lcublasSgetriBatched(handle, n, A, lda, P, C, ldc, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgetriBatched cublasSgetriBatched


#undef cublasDgetriBatched
cublasStatus_t cublasDgetriBatched(cublasHandle_t handle, int n, double const * const * A, int lda, int const * P, double * const * C, int ldc, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgetriBatched) (cublasHandle_t, int, double const * const *, int, int const *, double * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, double const * const *, int, int const *, double * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasDgetriBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgetriBatched", kApiTypeCublasV2);

    lretval = lcublasDgetriBatched(handle, n, A, lda, P, C, ldc, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgetriBatched cublasDgetriBatched


#undef cublasCgetriBatched
cublasStatus_t cublasCgetriBatched(cublasHandle_t handle, int n, cuComplex const * const * A, int lda, int const * P, cuComplex * const * C, int ldc, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgetriBatched) (cublasHandle_t, int, cuComplex const * const *, int, int const *, cuComplex * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const * const *, int, int const *, cuComplex * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasCgetriBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgetriBatched", kApiTypeCublasV2);

    lretval = lcublasCgetriBatched(handle, n, A, lda, P, C, ldc, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgetriBatched cublasCgetriBatched


#undef cublasZgetriBatched
cublasStatus_t cublasZgetriBatched(cublasHandle_t handle, int n, cuDoubleComplex const * const * A, int lda, int const * P, cuDoubleComplex * const * C, int ldc, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgetriBatched) (cublasHandle_t, int, cuDoubleComplex const * const *, int, int const *, cuDoubleComplex * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const * const *, int, int const *, cuDoubleComplex * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasZgetriBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgetriBatched", kApiTypeCublasV2);

    lretval = lcublasZgetriBatched(handle, n, A, lda, P, C, ldc, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgetriBatched cublasZgetriBatched


#undef cublasSgetrsBatched
cublasStatus_t cublasSgetrsBatched(cublasHandle_t handle, cublasOperation_t trans, int n, int nrhs, float const * const * Aarray, int lda, int const * devIpiv, float * const * Barray, int ldb, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgetrsBatched) (cublasHandle_t, cublasOperation_t, int, int, float const * const *, int, int const *, float * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, float const * const *, int, int const *, float * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasSgetrsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgetrsBatched", kApiTypeCublasV2);

    lretval = lcublasSgetrsBatched(handle, trans, n, nrhs, Aarray, lda, devIpiv, Barray, ldb, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgetrsBatched cublasSgetrsBatched


#undef cublasDgetrsBatched
cublasStatus_t cublasDgetrsBatched(cublasHandle_t handle, cublasOperation_t trans, int n, int nrhs, double const * const * Aarray, int lda, int const * devIpiv, double * const * Barray, int ldb, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgetrsBatched) (cublasHandle_t, cublasOperation_t, int, int, double const * const *, int, int const *, double * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, double const * const *, int, int const *, double * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasDgetrsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgetrsBatched", kApiTypeCublasV2);

    lretval = lcublasDgetrsBatched(handle, trans, n, nrhs, Aarray, lda, devIpiv, Barray, ldb, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgetrsBatched cublasDgetrsBatched


#undef cublasCgetrsBatched
cublasStatus_t cublasCgetrsBatched(cublasHandle_t handle, cublasOperation_t trans, int n, int nrhs, cuComplex const * const * Aarray, int lda, int const * devIpiv, cuComplex * const * Barray, int ldb, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgetrsBatched) (cublasHandle_t, cublasOperation_t, int, int, cuComplex const * const *, int, int const *, cuComplex * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, cuComplex const * const *, int, int const *, cuComplex * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasCgetrsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgetrsBatched", kApiTypeCublasV2);

    lretval = lcublasCgetrsBatched(handle, trans, n, nrhs, Aarray, lda, devIpiv, Barray, ldb, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgetrsBatched cublasCgetrsBatched


#undef cublasZgetrsBatched
cublasStatus_t cublasZgetrsBatched(cublasHandle_t handle, cublasOperation_t trans, int n, int nrhs, cuDoubleComplex const * const * Aarray, int lda, int const * devIpiv, cuDoubleComplex * const * Barray, int ldb, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgetrsBatched) (cublasHandle_t, cublasOperation_t, int, int, cuDoubleComplex const * const *, int, int const *, cuDoubleComplex * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, cuDoubleComplex const * const *, int, int const *, cuDoubleComplex * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasZgetrsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgetrsBatched", kApiTypeCublasV2);

    lretval = lcublasZgetrsBatched(handle, trans, n, nrhs, Aarray, lda, devIpiv, Barray, ldb, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgetrsBatched cublasZgetrsBatched


#undef cublasStrsmBatched
cublasStatus_t cublasStrsmBatched(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, float const * alpha, float const * const * A, int lda, float * const * B, int ldb, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStrsmBatched) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, float const * const *, int, float * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, float const *, float const * const *, int, float * const *, int, int))dlsym(RTLD_NEXT, "cublasStrsmBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStrsmBatched", kApiTypeCublasV2);

    lretval = lcublasStrsmBatched(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStrsmBatched cublasStrsmBatched


#undef cublasDtrsmBatched
cublasStatus_t cublasDtrsmBatched(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, double const * alpha, double const * const * A, int lda, double * const * B, int ldb, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtrsmBatched) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, double const * const *, int, double * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, double const *, double const * const *, int, double * const *, int, int))dlsym(RTLD_NEXT, "cublasDtrsmBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtrsmBatched", kApiTypeCublasV2);

    lretval = lcublasDtrsmBatched(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtrsmBatched cublasDtrsmBatched


#undef cublasCtrsmBatched
cublasStatus_t cublasCtrsmBatched(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, cuComplex const * alpha, cuComplex const * const * A, int lda, cuComplex * const * B, int ldb, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtrsmBatched) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, cuComplex const * const *, int, cuComplex * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuComplex const *, cuComplex const * const *, int, cuComplex * const *, int, int))dlsym(RTLD_NEXT, "cublasCtrsmBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtrsmBatched", kApiTypeCublasV2);

    lretval = lcublasCtrsmBatched(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtrsmBatched cublasCtrsmBatched


#undef cublasZtrsmBatched
cublasStatus_t cublasZtrsmBatched(cublasHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, cublasDiagType_t diag, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * const * A, int lda, cuDoubleComplex * const * B, int ldb, int batchCount){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtrsmBatched) (cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, cuDoubleComplex const * const *, int, cuDoubleComplex * const *, int, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, cublasDiagType_t, int, int, cuDoubleComplex const *, cuDoubleComplex const * const *, int, cuDoubleComplex * const *, int, int))dlsym(RTLD_NEXT, "cublasZtrsmBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtrsmBatched", kApiTypeCublasV2);

    lretval = lcublasZtrsmBatched(handle, side, uplo, trans, diag, m, n, alpha, A, lda, B, ldb, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtrsmBatched cublasZtrsmBatched


#undef cublasSmatinvBatched
cublasStatus_t cublasSmatinvBatched(cublasHandle_t handle, int n, float const * const * A, int lda, float * const * Ainv, int lda_inv, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSmatinvBatched) (cublasHandle_t, int, float const * const *, int, float * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, float const * const *, int, float * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasSmatinvBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSmatinvBatched", kApiTypeCublasV2);

    lretval = lcublasSmatinvBatched(handle, n, A, lda, Ainv, lda_inv, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSmatinvBatched cublasSmatinvBatched


#undef cublasDmatinvBatched
cublasStatus_t cublasDmatinvBatched(cublasHandle_t handle, int n, double const * const * A, int lda, double * const * Ainv, int lda_inv, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDmatinvBatched) (cublasHandle_t, int, double const * const *, int, double * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, double const * const *, int, double * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasDmatinvBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDmatinvBatched", kApiTypeCublasV2);

    lretval = lcublasDmatinvBatched(handle, n, A, lda, Ainv, lda_inv, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDmatinvBatched cublasDmatinvBatched


#undef cublasCmatinvBatched
cublasStatus_t cublasCmatinvBatched(cublasHandle_t handle, int n, cuComplex const * const * A, int lda, cuComplex * const * Ainv, int lda_inv, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCmatinvBatched) (cublasHandle_t, int, cuComplex const * const *, int, cuComplex * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuComplex const * const *, int, cuComplex * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasCmatinvBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCmatinvBatched", kApiTypeCublasV2);

    lretval = lcublasCmatinvBatched(handle, n, A, lda, Ainv, lda_inv, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCmatinvBatched cublasCmatinvBatched


#undef cublasZmatinvBatched
cublasStatus_t cublasZmatinvBatched(cublasHandle_t handle, int n, cuDoubleComplex const * const * A, int lda, cuDoubleComplex * const * Ainv, int lda_inv, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZmatinvBatched) (cublasHandle_t, int, cuDoubleComplex const * const *, int, cuDoubleComplex * const *, int, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, cuDoubleComplex const * const *, int, cuDoubleComplex * const *, int, int *, int))dlsym(RTLD_NEXT, "cublasZmatinvBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZmatinvBatched", kApiTypeCublasV2);

    lretval = lcublasZmatinvBatched(handle, n, A, lda, Ainv, lda_inv, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZmatinvBatched cublasZmatinvBatched


#undef cublasSgeqrfBatched
cublasStatus_t cublasSgeqrfBatched(cublasHandle_t handle, int m, int n, float * const * Aarray, int lda, float * const * TauArray, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgeqrfBatched) (cublasHandle_t, int, int, float * const *, int, float * const *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, float * const *, int, float * const *, int *, int))dlsym(RTLD_NEXT, "cublasSgeqrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgeqrfBatched", kApiTypeCublasV2);

    lretval = lcublasSgeqrfBatched(handle, m, n, Aarray, lda, TauArray, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgeqrfBatched cublasSgeqrfBatched


#undef cublasDgeqrfBatched
cublasStatus_t cublasDgeqrfBatched(cublasHandle_t handle, int m, int n, double * const * Aarray, int lda, double * const * TauArray, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgeqrfBatched) (cublasHandle_t, int, int, double * const *, int, double * const *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, double * const *, int, double * const *, int *, int))dlsym(RTLD_NEXT, "cublasDgeqrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgeqrfBatched", kApiTypeCublasV2);

    lretval = lcublasDgeqrfBatched(handle, m, n, Aarray, lda, TauArray, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgeqrfBatched cublasDgeqrfBatched


#undef cublasCgeqrfBatched
cublasStatus_t cublasCgeqrfBatched(cublasHandle_t handle, int m, int n, cuComplex * const * Aarray, int lda, cuComplex * const * TauArray, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgeqrfBatched) (cublasHandle_t, int, int, cuComplex * const *, int, cuComplex * const *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, cuComplex * const *, int, cuComplex * const *, int *, int))dlsym(RTLD_NEXT, "cublasCgeqrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgeqrfBatched", kApiTypeCublasV2);

    lretval = lcublasCgeqrfBatched(handle, m, n, Aarray, lda, TauArray, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgeqrfBatched cublasCgeqrfBatched


#undef cublasZgeqrfBatched
cublasStatus_t cublasZgeqrfBatched(cublasHandle_t handle, int m, int n, cuDoubleComplex * const * Aarray, int lda, cuDoubleComplex * const * TauArray, int * info, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgeqrfBatched) (cublasHandle_t, int, int, cuDoubleComplex * const *, int, cuDoubleComplex * const *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, int, int, cuDoubleComplex * const *, int, cuDoubleComplex * const *, int *, int))dlsym(RTLD_NEXT, "cublasZgeqrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgeqrfBatched", kApiTypeCublasV2);

    lretval = lcublasZgeqrfBatched(handle, m, n, Aarray, lda, TauArray, info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgeqrfBatched cublasZgeqrfBatched


#undef cublasSgelsBatched
cublasStatus_t cublasSgelsBatched(cublasHandle_t handle, cublasOperation_t trans, int m, int n, int nrhs, float * const * Aarray, int lda, float * const * Carray, int ldc, int * info, int * devInfoArray, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSgelsBatched) (cublasHandle_t, cublasOperation_t, int, int, int, float * const *, int, float * const *, int, int *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, int, float * const *, int, float * const *, int, int *, int *, int))dlsym(RTLD_NEXT, "cublasSgelsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSgelsBatched", kApiTypeCublasV2);

    lretval = lcublasSgelsBatched(handle, trans, m, n, nrhs, Aarray, lda, Carray, ldc, info, devInfoArray, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSgelsBatched cublasSgelsBatched


#undef cublasDgelsBatched
cublasStatus_t cublasDgelsBatched(cublasHandle_t handle, cublasOperation_t trans, int m, int n, int nrhs, double * const * Aarray, int lda, double * const * Carray, int ldc, int * info, int * devInfoArray, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDgelsBatched) (cublasHandle_t, cublasOperation_t, int, int, int, double * const *, int, double * const *, int, int *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, int, double * const *, int, double * const *, int, int *, int *, int))dlsym(RTLD_NEXT, "cublasDgelsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDgelsBatched", kApiTypeCublasV2);

    lretval = lcublasDgelsBatched(handle, trans, m, n, nrhs, Aarray, lda, Carray, ldc, info, devInfoArray, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDgelsBatched cublasDgelsBatched


#undef cublasCgelsBatched
cublasStatus_t cublasCgelsBatched(cublasHandle_t handle, cublasOperation_t trans, int m, int n, int nrhs, cuComplex * const * Aarray, int lda, cuComplex * const * Carray, int ldc, int * info, int * devInfoArray, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCgelsBatched) (cublasHandle_t, cublasOperation_t, int, int, int, cuComplex * const *, int, cuComplex * const *, int, int *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, int, cuComplex * const *, int, cuComplex * const *, int, int *, int *, int))dlsym(RTLD_NEXT, "cublasCgelsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCgelsBatched", kApiTypeCublasV2);

    lretval = lcublasCgelsBatched(handle, trans, m, n, nrhs, Aarray, lda, Carray, ldc, info, devInfoArray, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCgelsBatched cublasCgelsBatched


#undef cublasZgelsBatched
cublasStatus_t cublasZgelsBatched(cublasHandle_t handle, cublasOperation_t trans, int m, int n, int nrhs, cuDoubleComplex * const * Aarray, int lda, cuDoubleComplex * const * Carray, int ldc, int * info, int * devInfoArray, int batchSize){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZgelsBatched) (cublasHandle_t, cublasOperation_t, int, int, int, cuDoubleComplex * const *, int, cuDoubleComplex * const *, int, int *, int *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasOperation_t, int, int, int, cuDoubleComplex * const *, int, cuDoubleComplex * const *, int, int *, int *, int))dlsym(RTLD_NEXT, "cublasZgelsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZgelsBatched", kApiTypeCublasV2);

    lretval = lcublasZgelsBatched(handle, trans, m, n, nrhs, Aarray, lda, Carray, ldc, info, devInfoArray, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZgelsBatched cublasZgelsBatched


#undef cublasSdgmm
cublasStatus_t cublasSdgmm(cublasHandle_t handle, cublasSideMode_t mode, int m, int n, float const * A, int lda, float const * x, int incx, float * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasSdgmm) (cublasHandle_t, cublasSideMode_t, int, int, float const *, int, float const *, int, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, int, int, float const *, int, float const *, int, float *, int))dlsym(RTLD_NEXT, "cublasSdgmm");
    
    /* pre exeuction logics */
    ac.add_counter("cublasSdgmm", kApiTypeCublasV2);

    lretval = lcublasSdgmm(handle, mode, m, n, A, lda, x, incx, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasSdgmm cublasSdgmm


#undef cublasDdgmm
cublasStatus_t cublasDdgmm(cublasHandle_t handle, cublasSideMode_t mode, int m, int n, double const * A, int lda, double const * x, int incx, double * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDdgmm) (cublasHandle_t, cublasSideMode_t, int, int, double const *, int, double const *, int, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, int, int, double const *, int, double const *, int, double *, int))dlsym(RTLD_NEXT, "cublasDdgmm");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDdgmm", kApiTypeCublasV2);

    lretval = lcublasDdgmm(handle, mode, m, n, A, lda, x, incx, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDdgmm cublasDdgmm


#undef cublasCdgmm
cublasStatus_t cublasCdgmm(cublasHandle_t handle, cublasSideMode_t mode, int m, int n, cuComplex const * A, int lda, cuComplex const * x, int incx, cuComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCdgmm) (cublasHandle_t, cublasSideMode_t, int, int, cuComplex const *, int, cuComplex const *, int, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, int, int, cuComplex const *, int, cuComplex const *, int, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCdgmm");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCdgmm", kApiTypeCublasV2);

    lretval = lcublasCdgmm(handle, mode, m, n, A, lda, x, incx, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCdgmm cublasCdgmm


#undef cublasZdgmm
cublasStatus_t cublasZdgmm(cublasHandle_t handle, cublasSideMode_t mode, int m, int n, cuDoubleComplex const * A, int lda, cuDoubleComplex const * x, int incx, cuDoubleComplex * C, int ldc){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZdgmm) (cublasHandle_t, cublasSideMode_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasSideMode_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZdgmm");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZdgmm", kApiTypeCublasV2);

    lretval = lcublasZdgmm(handle, mode, m, n, A, lda, x, incx, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZdgmm cublasZdgmm


#undef cublasStpttr
cublasStatus_t cublasStpttr(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * AP, float * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStpttr) (cublasHandle_t, cublasFillMode_t, int, float const *, float *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, float *, int))dlsym(RTLD_NEXT, "cublasStpttr");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStpttr", kApiTypeCublasV2);

    lretval = lcublasStpttr(handle, uplo, n, AP, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStpttr cublasStpttr


#undef cublasDtpttr
cublasStatus_t cublasDtpttr(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * AP, double * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtpttr) (cublasHandle_t, cublasFillMode_t, int, double const *, double *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, double *, int))dlsym(RTLD_NEXT, "cublasDtpttr");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtpttr", kApiTypeCublasV2);

    lretval = lcublasDtpttr(handle, uplo, n, AP, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtpttr cublasDtpttr


#undef cublasCtpttr
cublasStatus_t cublasCtpttr(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * AP, cuComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtpttr) (cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cublasCtpttr");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtpttr", kApiTypeCublasV2);

    lretval = lcublasCtpttr(handle, uplo, n, AP, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtpttr cublasCtpttr


#undef cublasZtpttr
cublasStatus_t cublasZtpttr(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * AP, cuDoubleComplex * A, int lda){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtpttr) (cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex *, int) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cublasZtpttr");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtpttr", kApiTypeCublasV2);

    lretval = lcublasZtpttr(handle, uplo, n, AP, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtpttr cublasZtpttr


#undef cublasStrttp
cublasStatus_t cublasStrttp(cublasHandle_t handle, cublasFillMode_t uplo, int n, float const * A, int lda, float * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasStrttp) (cublasHandle_t, cublasFillMode_t, int, float const *, int, float *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, float const *, int, float *))dlsym(RTLD_NEXT, "cublasStrttp");
    
    /* pre exeuction logics */
    ac.add_counter("cublasStrttp", kApiTypeCublasV2);

    lretval = lcublasStrttp(handle, uplo, n, A, lda, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasStrttp cublasStrttp


#undef cublasDtrttp
cublasStatus_t cublasDtrttp(cublasHandle_t handle, cublasFillMode_t uplo, int n, double const * A, int lda, double * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasDtrttp) (cublasHandle_t, cublasFillMode_t, int, double const *, int, double *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, double const *, int, double *))dlsym(RTLD_NEXT, "cublasDtrttp");
    
    /* pre exeuction logics */
    ac.add_counter("cublasDtrttp", kApiTypeCublasV2);

    lretval = lcublasDtrttp(handle, uplo, n, A, lda, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasDtrttp cublasDtrttp


#undef cublasCtrttp
cublasStatus_t cublasCtrttp(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, cuComplex * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasCtrttp) (cublasHandle_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex *))dlsym(RTLD_NEXT, "cublasCtrttp");
    
    /* pre exeuction logics */
    ac.add_counter("cublasCtrttp", kApiTypeCublasV2);

    lretval = lcublasCtrttp(handle, uplo, n, A, lda, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasCtrttp cublasCtrttp


#undef cublasZtrttp
cublasStatus_t cublasZtrttp(cublasHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, cuDoubleComplex * AP){
    cublasStatus_t lretval;
    cublasStatus_t (*lcublasZtrttp) (cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex *) = (cublasStatus_t (*)(cublasHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex *))dlsym(RTLD_NEXT, "cublasZtrttp");
    
    /* pre exeuction logics */
    ac.add_counter("cublasZtrttp", kApiTypeCublasV2);

    lretval = lcublasZtrttp(handle, uplo, n, A, lda, AP);
    
    /* post exeuction logics */

    return lretval;
}
#define cublasZtrttp cublasZtrttp

