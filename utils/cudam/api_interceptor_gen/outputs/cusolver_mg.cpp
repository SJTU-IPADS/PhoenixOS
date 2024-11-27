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
#include <cusolverDn.h>
#include <cusolverMg.h>
#include <cusolverRf.h>
#include <cusolverSp.h>

#include "cudam.h"
#include "api_counter.h"

#undef cusolverMgCreate
cusolverStatus_t cusolverMgCreate(cusolverMgHandle_t * handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgCreate) (cusolverMgHandle_t *) = (cusolverStatus_t (*)(cusolverMgHandle_t *))dlsym(RTLD_NEXT, "cusolverMgCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgCreate", kApiTypeCuSolver);

    lretval = lcusolverMgCreate(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgCreate cusolverMgCreate


#undef cusolverMgDestroy
cusolverStatus_t cusolverMgDestroy(cusolverMgHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgDestroy) (cusolverMgHandle_t) = (cusolverStatus_t (*)(cusolverMgHandle_t))dlsym(RTLD_NEXT, "cusolverMgDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgDestroy", kApiTypeCuSolver);

    lretval = lcusolverMgDestroy(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgDestroy cusolverMgDestroy


#undef cusolverMgDeviceSelect
cusolverStatus_t cusolverMgDeviceSelect(cusolverMgHandle_t handle, int nbDevices, int * deviceId){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgDeviceSelect) (cusolverMgHandle_t, int, int *) = (cusolverStatus_t (*)(cusolverMgHandle_t, int, int *))dlsym(RTLD_NEXT, "cusolverMgDeviceSelect");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgDeviceSelect", kApiTypeCuSolver);

    lretval = lcusolverMgDeviceSelect(handle, nbDevices, deviceId);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgDeviceSelect cusolverMgDeviceSelect


#undef cusolverMgCreateDeviceGrid
cusolverStatus_t cusolverMgCreateDeviceGrid(cudaLibMgGrid_t * grid, int32_t numRowDevices, int32_t numColDevices, int32_t const * deviceId, cusolverMgGridMapping_t mapping){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgCreateDeviceGrid) (cudaLibMgGrid_t *, int32_t, int32_t, int32_t const *, cusolverMgGridMapping_t) = (cusolverStatus_t (*)(cudaLibMgGrid_t *, int32_t, int32_t, int32_t const *, cusolverMgGridMapping_t))dlsym(RTLD_NEXT, "cusolverMgCreateDeviceGrid");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgCreateDeviceGrid", kApiTypeCuSolver);

    lretval = lcusolverMgCreateDeviceGrid(grid, numRowDevices, numColDevices, deviceId, mapping);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgCreateDeviceGrid cusolverMgCreateDeviceGrid


#undef cusolverMgDestroyGrid
cusolverStatus_t cusolverMgDestroyGrid(cudaLibMgGrid_t grid){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgDestroyGrid) (cudaLibMgGrid_t) = (cusolverStatus_t (*)(cudaLibMgGrid_t))dlsym(RTLD_NEXT, "cusolverMgDestroyGrid");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgDestroyGrid", kApiTypeCuSolver);

    lretval = lcusolverMgDestroyGrid(grid);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgDestroyGrid cusolverMgDestroyGrid


#undef cusolverMgCreateMatrixDesc
cusolverStatus_t cusolverMgCreateMatrixDesc(cudaLibMgMatrixDesc_t * desc, int64_t numRows, int64_t numCols, int64_t rowBlockSize, int64_t colBlockSize, cudaDataType dataType, cudaLibMgGrid_t const grid){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgCreateMatrixDesc) (cudaLibMgMatrixDesc_t *, int64_t, int64_t, int64_t, int64_t, cudaDataType, cudaLibMgGrid_t const) = (cusolverStatus_t (*)(cudaLibMgMatrixDesc_t *, int64_t, int64_t, int64_t, int64_t, cudaDataType, cudaLibMgGrid_t const))dlsym(RTLD_NEXT, "cusolverMgCreateMatrixDesc");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgCreateMatrixDesc", kApiTypeCuSolver);

    lretval = lcusolverMgCreateMatrixDesc(desc, numRows, numCols, rowBlockSize, colBlockSize, dataType, grid);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgCreateMatrixDesc cusolverMgCreateMatrixDesc


#undef cusolverMgDestroyMatrixDesc
cusolverStatus_t cusolverMgDestroyMatrixDesc(cudaLibMgMatrixDesc_t desc){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgDestroyMatrixDesc) (cudaLibMgMatrixDesc_t) = (cusolverStatus_t (*)(cudaLibMgMatrixDesc_t))dlsym(RTLD_NEXT, "cusolverMgDestroyMatrixDesc");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgDestroyMatrixDesc", kApiTypeCuSolver);

    lretval = lcusolverMgDestroyMatrixDesc(desc);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgDestroyMatrixDesc cusolverMgDestroyMatrixDesc


#undef cusolverMgSyevd_bufferSize
cusolverStatus_t cusolverMgSyevd_bufferSize(cusolverMgHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int N, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, void * W, cudaDataType dataTypeW, cudaDataType computeType, int64_t * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgSyevd_bufferSize) (cusolverMgHandle_t, cusolverEigMode_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, void *, cudaDataType, cudaDataType, int64_t *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cusolverEigMode_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, void *, cudaDataType, cudaDataType, int64_t *))dlsym(RTLD_NEXT, "cusolverMgSyevd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgSyevd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverMgSyevd_bufferSize(handle, jobz, uplo, N, array_d_A, IA, JA, descrA, W, dataTypeW, computeType, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgSyevd_bufferSize cusolverMgSyevd_bufferSize


#undef cusolverMgSyevd
cusolverStatus_t cusolverMgSyevd(cusolverMgHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int N, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, void * W, cudaDataType dataTypeW, cudaDataType computeType, void * * array_d_work, int64_t lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgSyevd) (cusolverMgHandle_t, cusolverEigMode_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, void *, cudaDataType, cudaDataType, void * *, int64_t, int *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cusolverEigMode_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, void *, cudaDataType, cudaDataType, void * *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverMgSyevd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgSyevd", kApiTypeCuSolver);

    lretval = lcusolverMgSyevd(handle, jobz, uplo, N, array_d_A, IA, JA, descrA, W, dataTypeW, computeType, array_d_work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgSyevd cusolverMgSyevd


#undef cusolverMgGetrf_bufferSize
cusolverStatus_t cusolverMgGetrf_bufferSize(cusolverMgHandle_t handle, int M, int N, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, int * * array_d_IPIV, cudaDataType computeType, int64_t * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgGetrf_bufferSize) (cusolverMgHandle_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, int * *, cudaDataType, int64_t *) = (cusolverStatus_t (*)(cusolverMgHandle_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, int * *, cudaDataType, int64_t *))dlsym(RTLD_NEXT, "cusolverMgGetrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgGetrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverMgGetrf_bufferSize(handle, M, N, array_d_A, IA, JA, descrA, array_d_IPIV, computeType, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgGetrf_bufferSize cusolverMgGetrf_bufferSize


#undef cusolverMgGetrf
cusolverStatus_t cusolverMgGetrf(cusolverMgHandle_t handle, int M, int N, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, int * * array_d_IPIV, cudaDataType computeType, void * * array_d_work, int64_t lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgGetrf) (cusolverMgHandle_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, int * *, cudaDataType, void * *, int64_t, int *) = (cusolverStatus_t (*)(cusolverMgHandle_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, int * *, cudaDataType, void * *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverMgGetrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgGetrf", kApiTypeCuSolver);

    lretval = lcusolverMgGetrf(handle, M, N, array_d_A, IA, JA, descrA, array_d_IPIV, computeType, array_d_work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgGetrf cusolverMgGetrf


#undef cusolverMgGetrs_bufferSize
cusolverStatus_t cusolverMgGetrs_bufferSize(cusolverMgHandle_t handle, cublasOperation_t TRANS, int N, int NRHS, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, int * * array_d_IPIV, void * * array_d_B, int IB, int JB, cudaLibMgMatrixDesc_t descrB, cudaDataType computeType, int64_t * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgGetrs_bufferSize) (cusolverMgHandle_t, cublasOperation_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, int * *, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, int64_t *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cublasOperation_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, int * *, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, int64_t *))dlsym(RTLD_NEXT, "cusolverMgGetrs_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgGetrs_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverMgGetrs_bufferSize(handle, TRANS, N, NRHS, array_d_A, IA, JA, descrA, array_d_IPIV, array_d_B, IB, JB, descrB, computeType, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgGetrs_bufferSize cusolverMgGetrs_bufferSize


#undef cusolverMgGetrs
cusolverStatus_t cusolverMgGetrs(cusolverMgHandle_t handle, cublasOperation_t TRANS, int N, int NRHS, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, int * * array_d_IPIV, void * * array_d_B, int IB, int JB, cudaLibMgMatrixDesc_t descrB, cudaDataType computeType, void * * array_d_work, int64_t lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgGetrs) (cusolverMgHandle_t, cublasOperation_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, int * *, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, void * *, int64_t, int *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cublasOperation_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, int * *, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, void * *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverMgGetrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgGetrs", kApiTypeCuSolver);

    lretval = lcusolverMgGetrs(handle, TRANS, N, NRHS, array_d_A, IA, JA, descrA, array_d_IPIV, array_d_B, IB, JB, descrB, computeType, array_d_work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgGetrs cusolverMgGetrs


#undef cusolverMgPotrf_bufferSize
cusolverStatus_t cusolverMgPotrf_bufferSize(cusolverMgHandle_t handle, cublasFillMode_t uplo, int N, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, cudaDataType computeType, int64_t * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgPotrf_bufferSize) (cusolverMgHandle_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, int64_t *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, int64_t *))dlsym(RTLD_NEXT, "cusolverMgPotrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgPotrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverMgPotrf_bufferSize(handle, uplo, N, array_d_A, IA, JA, descrA, computeType, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgPotrf_bufferSize cusolverMgPotrf_bufferSize


#undef cusolverMgPotrf
cusolverStatus_t cusolverMgPotrf(cusolverMgHandle_t handle, cublasFillMode_t uplo, int N, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, cudaDataType computeType, void * * array_d_work, int64_t lwork, int * h_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgPotrf) (cusolverMgHandle_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, void * *, int64_t, int *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, void * *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverMgPotrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgPotrf", kApiTypeCuSolver);

    lretval = lcusolverMgPotrf(handle, uplo, N, array_d_A, IA, JA, descrA, computeType, array_d_work, lwork, h_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgPotrf cusolverMgPotrf


#undef cusolverMgPotrs_bufferSize
cusolverStatus_t cusolverMgPotrs_bufferSize(cusolverMgHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, void * * array_d_B, int IB, int JB, cudaLibMgMatrixDesc_t descrB, cudaDataType computeType, int64_t * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgPotrs_bufferSize) (cusolverMgHandle_t, cublasFillMode_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, int64_t *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cublasFillMode_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, int64_t *))dlsym(RTLD_NEXT, "cusolverMgPotrs_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgPotrs_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverMgPotrs_bufferSize(handle, uplo, n, nrhs, array_d_A, IA, JA, descrA, array_d_B, IB, JB, descrB, computeType, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgPotrs_bufferSize cusolverMgPotrs_bufferSize


#undef cusolverMgPotrs
cusolverStatus_t cusolverMgPotrs(cusolverMgHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, void * * array_d_B, int IB, int JB, cudaLibMgMatrixDesc_t descrB, cudaDataType computeType, void * * array_d_work, int64_t lwork, int * h_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgPotrs) (cusolverMgHandle_t, cublasFillMode_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, void * *, int64_t, int *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cublasFillMode_t, int, int, void * *, int, int, cudaLibMgMatrixDesc_t, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, void * *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverMgPotrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgPotrs", kApiTypeCuSolver);

    lretval = lcusolverMgPotrs(handle, uplo, n, nrhs, array_d_A, IA, JA, descrA, array_d_B, IB, JB, descrB, computeType, array_d_work, lwork, h_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgPotrs cusolverMgPotrs


#undef cusolverMgPotri_bufferSize
cusolverStatus_t cusolverMgPotri_bufferSize(cusolverMgHandle_t handle, cublasFillMode_t uplo, int N, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, cudaDataType computeType, int64_t * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgPotri_bufferSize) (cusolverMgHandle_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, int64_t *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, int64_t *))dlsym(RTLD_NEXT, "cusolverMgPotri_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgPotri_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverMgPotri_bufferSize(handle, uplo, N, array_d_A, IA, JA, descrA, computeType, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgPotri_bufferSize cusolverMgPotri_bufferSize


#undef cusolverMgPotri
cusolverStatus_t cusolverMgPotri(cusolverMgHandle_t handle, cublasFillMode_t uplo, int N, void * * array_d_A, int IA, int JA, cudaLibMgMatrixDesc_t descrA, cudaDataType computeType, void * * array_d_work, int64_t lwork, int * h_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverMgPotri) (cusolverMgHandle_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, void * *, int64_t, int *) = (cusolverStatus_t (*)(cusolverMgHandle_t, cublasFillMode_t, int, void * *, int, int, cudaLibMgMatrixDesc_t, cudaDataType, void * *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverMgPotri");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverMgPotri", kApiTypeCuSolver);

    lretval = lcusolverMgPotri(handle, uplo, N, array_d_A, IA, JA, descrA, computeType, array_d_work, lwork, h_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverMgPotri cusolverMgPotri

