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

#undef cusolverSpCreate
cusolverStatus_t cusolverSpCreate(cusolverSpHandle_t * handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCreate) (cusolverSpHandle_t *) = (cusolverStatus_t (*)(cusolverSpHandle_t *))dlsym(RTLD_NEXT, "cusolverSpCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCreate", kApiTypeCuSolver);

    lretval = lcusolverSpCreate(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCreate cusolverSpCreate


#undef cusolverSpDestroy
cusolverStatus_t cusolverSpDestroy(cusolverSpHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDestroy) (cusolverSpHandle_t) = (cusolverStatus_t (*)(cusolverSpHandle_t))dlsym(RTLD_NEXT, "cusolverSpDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDestroy", kApiTypeCuSolver);

    lretval = lcusolverSpDestroy(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDestroy cusolverSpDestroy


#undef cusolverSpSetStream
cusolverStatus_t cusolverSpSetStream(cusolverSpHandle_t handle, cudaStream_t streamId){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpSetStream) (cusolverSpHandle_t, cudaStream_t) = (cusolverStatus_t (*)(cusolverSpHandle_t, cudaStream_t))dlsym(RTLD_NEXT, "cusolverSpSetStream");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpSetStream", kApiTypeCuSolver);

    lretval = lcusolverSpSetStream(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpSetStream cusolverSpSetStream


#undef cusolverSpGetStream
cusolverStatus_t cusolverSpGetStream(cusolverSpHandle_t handle, cudaStream_t * streamId){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpGetStream) (cusolverSpHandle_t, cudaStream_t *) = (cusolverStatus_t (*)(cusolverSpHandle_t, cudaStream_t *))dlsym(RTLD_NEXT, "cusolverSpGetStream");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpGetStream", kApiTypeCuSolver);

    lretval = lcusolverSpGetStream(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpGetStream cusolverSpGetStream


#undef cusolverSpXcsrissymHost
cusolverStatus_t cusolverSpXcsrissymHost(cusolverSpHandle_t handle, int m, int nnzA, cusparseMatDescr_t const descrA, int const * csrRowPtrA, int const * csrEndPtrA, int const * csrColIndA, int * issym){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpXcsrissymHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int const *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int const *, int *))dlsym(RTLD_NEXT, "cusolverSpXcsrissymHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpXcsrissymHost", kApiTypeCuSolver);

    lretval = lcusolverSpXcsrissymHost(handle, m, nnzA, descrA, csrRowPtrA, csrEndPtrA, csrColIndA, issym);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpXcsrissymHost cusolverSpXcsrissymHost


#undef cusolverSpScsrlsvluHost
cusolverStatus_t cusolverSpScsrlsvluHost(cusolverSpHandle_t handle, int n, int nnzA, cusparseMatDescr_t const descrA, float const * csrValA, int const * csrRowPtrA, int const * csrColIndA, float const * b, float tol, int reorder, float * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsrlsvluHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *))dlsym(RTLD_NEXT, "cusolverSpScsrlsvluHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsrlsvluHost", kApiTypeCuSolver);

    lretval = lcusolverSpScsrlsvluHost(handle, n, nnzA, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsrlsvluHost cusolverSpScsrlsvluHost


#undef cusolverSpDcsrlsvluHost
cusolverStatus_t cusolverSpDcsrlsvluHost(cusolverSpHandle_t handle, int n, int nnzA, cusparseMatDescr_t const descrA, double const * csrValA, int const * csrRowPtrA, int const * csrColIndA, double const * b, double tol, int reorder, double * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsrlsvluHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *))dlsym(RTLD_NEXT, "cusolverSpDcsrlsvluHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsrlsvluHost", kApiTypeCuSolver);

    lretval = lcusolverSpDcsrlsvluHost(handle, n, nnzA, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsrlsvluHost cusolverSpDcsrlsvluHost


#undef cusolverSpCcsrlsvluHost
cusolverStatus_t cusolverSpCcsrlsvluHost(cusolverSpHandle_t handle, int n, int nnzA, cusparseMatDescr_t const descrA, cuComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuComplex const * b, float tol, int reorder, cuComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsrlsvluHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpCcsrlsvluHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsrlsvluHost", kApiTypeCuSolver);

    lretval = lcusolverSpCcsrlsvluHost(handle, n, nnzA, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsrlsvluHost cusolverSpCcsrlsvluHost


#undef cusolverSpZcsrlsvluHost
cusolverStatus_t cusolverSpZcsrlsvluHost(cusolverSpHandle_t handle, int n, int nnzA, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuDoubleComplex const * b, double tol, int reorder, cuDoubleComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsrlsvluHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpZcsrlsvluHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsrlsvluHost", kApiTypeCuSolver);

    lretval = lcusolverSpZcsrlsvluHost(handle, n, nnzA, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsrlsvluHost cusolverSpZcsrlsvluHost


#undef cusolverSpScsrlsvqr
cusolverStatus_t cusolverSpScsrlsvqr(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrVal, int const * csrRowPtr, int const * csrColInd, float const * b, float tol, int reorder, float * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsrlsvqr) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *))dlsym(RTLD_NEXT, "cusolverSpScsrlsvqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsrlsvqr", kApiTypeCuSolver);

    lretval = lcusolverSpScsrlsvqr(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsrlsvqr cusolverSpScsrlsvqr


#undef cusolverSpDcsrlsvqr
cusolverStatus_t cusolverSpDcsrlsvqr(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrVal, int const * csrRowPtr, int const * csrColInd, double const * b, double tol, int reorder, double * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsrlsvqr) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *))dlsym(RTLD_NEXT, "cusolverSpDcsrlsvqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsrlsvqr", kApiTypeCuSolver);

    lretval = lcusolverSpDcsrlsvqr(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsrlsvqr cusolverSpDcsrlsvqr


#undef cusolverSpCcsrlsvqr
cusolverStatus_t cusolverSpCcsrlsvqr(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrVal, int const * csrRowPtr, int const * csrColInd, cuComplex const * b, float tol, int reorder, cuComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsrlsvqr) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpCcsrlsvqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsrlsvqr", kApiTypeCuSolver);

    lretval = lcusolverSpCcsrlsvqr(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsrlsvqr cusolverSpCcsrlsvqr


#undef cusolverSpZcsrlsvqr
cusolverStatus_t cusolverSpZcsrlsvqr(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrVal, int const * csrRowPtr, int const * csrColInd, cuDoubleComplex const * b, double tol, int reorder, cuDoubleComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsrlsvqr) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpZcsrlsvqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsrlsvqr", kApiTypeCuSolver);

    lretval = lcusolverSpZcsrlsvqr(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsrlsvqr cusolverSpZcsrlsvqr


#undef cusolverSpScsrlsvqrHost
cusolverStatus_t cusolverSpScsrlsvqrHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrValA, int const * csrRowPtrA, int const * csrColIndA, float const * b, float tol, int reorder, float * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsrlsvqrHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *))dlsym(RTLD_NEXT, "cusolverSpScsrlsvqrHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsrlsvqrHost", kApiTypeCuSolver);

    lretval = lcusolverSpScsrlsvqrHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsrlsvqrHost cusolverSpScsrlsvqrHost


#undef cusolverSpDcsrlsvqrHost
cusolverStatus_t cusolverSpDcsrlsvqrHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrValA, int const * csrRowPtrA, int const * csrColIndA, double const * b, double tol, int reorder, double * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsrlsvqrHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *))dlsym(RTLD_NEXT, "cusolverSpDcsrlsvqrHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsrlsvqrHost", kApiTypeCuSolver);

    lretval = lcusolverSpDcsrlsvqrHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsrlsvqrHost cusolverSpDcsrlsvqrHost


#undef cusolverSpCcsrlsvqrHost
cusolverStatus_t cusolverSpCcsrlsvqrHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuComplex const * b, float tol, int reorder, cuComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsrlsvqrHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpCcsrlsvqrHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsrlsvqrHost", kApiTypeCuSolver);

    lretval = lcusolverSpCcsrlsvqrHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsrlsvqrHost cusolverSpCcsrlsvqrHost


#undef cusolverSpZcsrlsvqrHost
cusolverStatus_t cusolverSpZcsrlsvqrHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuDoubleComplex const * b, double tol, int reorder, cuDoubleComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsrlsvqrHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpZcsrlsvqrHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsrlsvqrHost", kApiTypeCuSolver);

    lretval = lcusolverSpZcsrlsvqrHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsrlsvqrHost cusolverSpZcsrlsvqrHost


#undef cusolverSpScsrlsvcholHost
cusolverStatus_t cusolverSpScsrlsvcholHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrVal, int const * csrRowPtr, int const * csrColInd, float const * b, float tol, int reorder, float * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsrlsvcholHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *))dlsym(RTLD_NEXT, "cusolverSpScsrlsvcholHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsrlsvcholHost", kApiTypeCuSolver);

    lretval = lcusolverSpScsrlsvcholHost(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsrlsvcholHost cusolverSpScsrlsvcholHost


#undef cusolverSpDcsrlsvcholHost
cusolverStatus_t cusolverSpDcsrlsvcholHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrVal, int const * csrRowPtr, int const * csrColInd, double const * b, double tol, int reorder, double * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsrlsvcholHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *))dlsym(RTLD_NEXT, "cusolverSpDcsrlsvcholHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsrlsvcholHost", kApiTypeCuSolver);

    lretval = lcusolverSpDcsrlsvcholHost(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsrlsvcholHost cusolverSpDcsrlsvcholHost


#undef cusolverSpCcsrlsvcholHost
cusolverStatus_t cusolverSpCcsrlsvcholHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrVal, int const * csrRowPtr, int const * csrColInd, cuComplex const * b, float tol, int reorder, cuComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsrlsvcholHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpCcsrlsvcholHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsrlsvcholHost", kApiTypeCuSolver);

    lretval = lcusolverSpCcsrlsvcholHost(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsrlsvcholHost cusolverSpCcsrlsvcholHost


#undef cusolverSpZcsrlsvcholHost
cusolverStatus_t cusolverSpZcsrlsvcholHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrVal, int const * csrRowPtr, int const * csrColInd, cuDoubleComplex const * b, double tol, int reorder, cuDoubleComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsrlsvcholHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpZcsrlsvcholHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsrlsvcholHost", kApiTypeCuSolver);

    lretval = lcusolverSpZcsrlsvcholHost(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsrlsvcholHost cusolverSpZcsrlsvcholHost


#undef cusolverSpScsrlsvchol
cusolverStatus_t cusolverSpScsrlsvchol(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrVal, int const * csrRowPtr, int const * csrColInd, float const * b, float tol, int reorder, float * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsrlsvchol) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int, float *, int *))dlsym(RTLD_NEXT, "cusolverSpScsrlsvchol");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsrlsvchol", kApiTypeCuSolver);

    lretval = lcusolverSpScsrlsvchol(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsrlsvchol cusolverSpScsrlsvchol


#undef cusolverSpDcsrlsvchol
cusolverStatus_t cusolverSpDcsrlsvchol(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrVal, int const * csrRowPtr, int const * csrColInd, double const * b, double tol, int reorder, double * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsrlsvchol) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int, double *, int *))dlsym(RTLD_NEXT, "cusolverSpDcsrlsvchol");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsrlsvchol", kApiTypeCuSolver);

    lretval = lcusolverSpDcsrlsvchol(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsrlsvchol cusolverSpDcsrlsvchol


#undef cusolverSpCcsrlsvchol
cusolverStatus_t cusolverSpCcsrlsvchol(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrVal, int const * csrRowPtr, int const * csrColInd, cuComplex const * b, float tol, int reorder, cuComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsrlsvchol) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int, cuComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpCcsrlsvchol");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsrlsvchol", kApiTypeCuSolver);

    lretval = lcusolverSpCcsrlsvchol(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsrlsvchol cusolverSpCcsrlsvchol


#undef cusolverSpZcsrlsvchol
cusolverStatus_t cusolverSpZcsrlsvchol(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrVal, int const * csrRowPtr, int const * csrColInd, cuDoubleComplex const * b, double tol, int reorder, cuDoubleComplex * x, int * singularity){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsrlsvchol) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int, cuDoubleComplex *, int *))dlsym(RTLD_NEXT, "cusolverSpZcsrlsvchol");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsrlsvchol", kApiTypeCuSolver);

    lretval = lcusolverSpZcsrlsvchol(handle, m, nnz, descrA, csrVal, csrRowPtr, csrColInd, b, tol, reorder, x, singularity);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsrlsvchol cusolverSpZcsrlsvchol


#undef cusolverSpScsrlsqvqrHost
cusolverStatus_t cusolverSpScsrlsqvqrHost(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, float const * csrValA, int const * csrRowPtrA, int const * csrColIndA, float const * b, float tol, int * rankA, float * x, int * p, float * min_norm){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsrlsqvqrHost) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int *, float *, int *, float *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float, int *, float *, int *, float *))dlsym(RTLD_NEXT, "cusolverSpScsrlsqvqrHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsrlsqvqrHost", kApiTypeCuSolver);

    lretval = lcusolverSpScsrlsqvqrHost(handle, m, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, rankA, x, p, min_norm);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsrlsqvqrHost cusolverSpScsrlsqvqrHost


#undef cusolverSpDcsrlsqvqrHost
cusolverStatus_t cusolverSpDcsrlsqvqrHost(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, double const * csrValA, int const * csrRowPtrA, int const * csrColIndA, double const * b, double tol, int * rankA, double * x, int * p, double * min_norm){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsrlsqvqrHost) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int *, double *, int *, double *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double, int *, double *, int *, double *))dlsym(RTLD_NEXT, "cusolverSpDcsrlsqvqrHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsrlsqvqrHost", kApiTypeCuSolver);

    lretval = lcusolverSpDcsrlsqvqrHost(handle, m, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, rankA, x, p, min_norm);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsrlsqvqrHost cusolverSpDcsrlsqvqrHost


#undef cusolverSpCcsrlsqvqrHost
cusolverStatus_t cusolverSpCcsrlsqvqrHost(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuComplex const * b, float tol, int * rankA, cuComplex * x, int * p, float * min_norm){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsrlsqvqrHost) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int *, cuComplex *, int *, float *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, float, int *, cuComplex *, int *, float *))dlsym(RTLD_NEXT, "cusolverSpCcsrlsqvqrHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsrlsqvqrHost", kApiTypeCuSolver);

    lretval = lcusolverSpCcsrlsqvqrHost(handle, m, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, rankA, x, p, min_norm);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsrlsqvqrHost cusolverSpCcsrlsqvqrHost


#undef cusolverSpZcsrlsqvqrHost
cusolverStatus_t cusolverSpZcsrlsqvqrHost(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuDoubleComplex const * b, double tol, int * rankA, cuDoubleComplex * x, int * p, double * min_norm){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsrlsqvqrHost) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int *, cuDoubleComplex *, int *, double *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, double, int *, cuDoubleComplex *, int *, double *))dlsym(RTLD_NEXT, "cusolverSpZcsrlsqvqrHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsrlsqvqrHost", kApiTypeCuSolver);

    lretval = lcusolverSpZcsrlsqvqrHost(handle, m, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, tol, rankA, x, p, min_norm);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsrlsqvqrHost cusolverSpZcsrlsqvqrHost


#undef cusolverSpScsreigvsiHost
cusolverStatus_t cusolverSpScsreigvsiHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrValA, int const * csrRowPtrA, int const * csrColIndA, float mu0, float const * x0, int maxite, float tol, float * mu, float * x){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsreigvsiHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, float const *, int, float, float *, float *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, float const *, int, float, float *, float *))dlsym(RTLD_NEXT, "cusolverSpScsreigvsiHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsreigvsiHost", kApiTypeCuSolver);

    lretval = lcusolverSpScsreigvsiHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, mu0, x0, maxite, tol, mu, x);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsreigvsiHost cusolverSpScsreigvsiHost


#undef cusolverSpDcsreigvsiHost
cusolverStatus_t cusolverSpDcsreigvsiHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrValA, int const * csrRowPtrA, int const * csrColIndA, double mu0, double const * x0, int maxite, double tol, double * mu, double * x){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsreigvsiHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double, double const *, int, double, double *, double *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double, double const *, int, double, double *, double *))dlsym(RTLD_NEXT, "cusolverSpDcsreigvsiHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsreigvsiHost", kApiTypeCuSolver);

    lretval = lcusolverSpDcsreigvsiHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, mu0, x0, maxite, tol, mu, x);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsreigvsiHost cusolverSpDcsreigvsiHost


#undef cusolverSpCcsreigvsiHost
cusolverStatus_t cusolverSpCcsreigvsiHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuComplex mu0, cuComplex const * x0, int maxite, float tol, cuComplex * mu, cuComplex * x){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsreigvsiHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex, cuComplex const *, int, float, cuComplex *, cuComplex *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex, cuComplex const *, int, float, cuComplex *, cuComplex *))dlsym(RTLD_NEXT, "cusolverSpCcsreigvsiHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsreigvsiHost", kApiTypeCuSolver);

    lretval = lcusolverSpCcsreigvsiHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, mu0, x0, maxite, tol, mu, x);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsreigvsiHost cusolverSpCcsreigvsiHost


#undef cusolverSpZcsreigvsiHost
cusolverStatus_t cusolverSpZcsreigvsiHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuDoubleComplex mu0, cuDoubleComplex const * x0, int maxite, double tol, cuDoubleComplex * mu, cuDoubleComplex * x){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsreigvsiHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex, cuDoubleComplex const *, int, double, cuDoubleComplex *, cuDoubleComplex *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex, cuDoubleComplex const *, int, double, cuDoubleComplex *, cuDoubleComplex *))dlsym(RTLD_NEXT, "cusolverSpZcsreigvsiHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsreigvsiHost", kApiTypeCuSolver);

    lretval = lcusolverSpZcsreigvsiHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, mu0, x0, maxite, tol, mu, x);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsreigvsiHost cusolverSpZcsreigvsiHost


#undef cusolverSpScsreigvsi
cusolverStatus_t cusolverSpScsreigvsi(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrValA, int const * csrRowPtrA, int const * csrColIndA, float mu0, float const * x0, int maxite, float eps, float * mu, float * x){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsreigvsi) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, float const *, int, float, float *, float *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, float const *, int, float, float *, float *))dlsym(RTLD_NEXT, "cusolverSpScsreigvsi");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsreigvsi", kApiTypeCuSolver);

    lretval = lcusolverSpScsreigvsi(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, mu0, x0, maxite, eps, mu, x);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsreigvsi cusolverSpScsreigvsi


#undef cusolverSpDcsreigvsi
cusolverStatus_t cusolverSpDcsreigvsi(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrValA, int const * csrRowPtrA, int const * csrColIndA, double mu0, double const * x0, int maxite, double eps, double * mu, double * x){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsreigvsi) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double, double const *, int, double, double *, double *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double, double const *, int, double, double *, double *))dlsym(RTLD_NEXT, "cusolverSpDcsreigvsi");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsreigvsi", kApiTypeCuSolver);

    lretval = lcusolverSpDcsreigvsi(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, mu0, x0, maxite, eps, mu, x);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsreigvsi cusolverSpDcsreigvsi


#undef cusolverSpCcsreigvsi
cusolverStatus_t cusolverSpCcsreigvsi(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuComplex mu0, cuComplex const * x0, int maxite, float eps, cuComplex * mu, cuComplex * x){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsreigvsi) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex, cuComplex const *, int, float, cuComplex *, cuComplex *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex, cuComplex const *, int, float, cuComplex *, cuComplex *))dlsym(RTLD_NEXT, "cusolverSpCcsreigvsi");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsreigvsi", kApiTypeCuSolver);

    lretval = lcusolverSpCcsreigvsi(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, mu0, x0, maxite, eps, mu, x);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsreigvsi cusolverSpCcsreigvsi


#undef cusolverSpZcsreigvsi
cusolverStatus_t cusolverSpZcsreigvsi(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuDoubleComplex mu0, cuDoubleComplex const * x0, int maxite, double eps, cuDoubleComplex * mu, cuDoubleComplex * x){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsreigvsi) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex, cuDoubleComplex const *, int, double, cuDoubleComplex *, cuDoubleComplex *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex, cuDoubleComplex const *, int, double, cuDoubleComplex *, cuDoubleComplex *))dlsym(RTLD_NEXT, "cusolverSpZcsreigvsi");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsreigvsi", kApiTypeCuSolver);

    lretval = lcusolverSpZcsreigvsi(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, mu0, x0, maxite, eps, mu, x);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsreigvsi cusolverSpZcsreigvsi


#undef cusolverSpScsreigsHost
cusolverStatus_t cusolverSpScsreigsHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuComplex left_bottom_corner, cuComplex right_upper_corner, int * num_eigs){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsreigsHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, cuComplex, cuComplex, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, cuComplex, cuComplex, int *))dlsym(RTLD_NEXT, "cusolverSpScsreigsHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsreigsHost", kApiTypeCuSolver);

    lretval = lcusolverSpScsreigsHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, left_bottom_corner, right_upper_corner, num_eigs);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsreigsHost cusolverSpScsreigsHost


#undef cusolverSpDcsreigsHost
cusolverStatus_t cusolverSpDcsreigsHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuDoubleComplex left_bottom_corner, cuDoubleComplex right_upper_corner, int * num_eigs){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsreigsHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, cuDoubleComplex, cuDoubleComplex, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, cuDoubleComplex, cuDoubleComplex, int *))dlsym(RTLD_NEXT, "cusolverSpDcsreigsHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsreigsHost", kApiTypeCuSolver);

    lretval = lcusolverSpDcsreigsHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, left_bottom_corner, right_upper_corner, num_eigs);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsreigsHost cusolverSpDcsreigsHost


#undef cusolverSpCcsreigsHost
cusolverStatus_t cusolverSpCcsreigsHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuComplex left_bottom_corner, cuComplex right_upper_corner, int * num_eigs){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsreigsHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex, cuComplex, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex, cuComplex, int *))dlsym(RTLD_NEXT, "cusolverSpCcsreigsHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsreigsHost", kApiTypeCuSolver);

    lretval = lcusolverSpCcsreigsHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, left_bottom_corner, right_upper_corner, num_eigs);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsreigsHost cusolverSpCcsreigsHost


#undef cusolverSpZcsreigsHost
cusolverStatus_t cusolverSpZcsreigsHost(cusolverSpHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuDoubleComplex left_bottom_corner, cuDoubleComplex right_upper_corner, int * num_eigs){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsreigsHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex, cuDoubleComplex, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex, cuDoubleComplex, int *))dlsym(RTLD_NEXT, "cusolverSpZcsreigsHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsreigsHost", kApiTypeCuSolver);

    lretval = lcusolverSpZcsreigsHost(handle, m, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, left_bottom_corner, right_upper_corner, num_eigs);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsreigsHost cusolverSpZcsreigsHost


#undef cusolverSpXcsrsymrcmHost
cusolverStatus_t cusolverSpXcsrsymrcmHost(cusolverSpHandle_t handle, int n, int nnzA, cusparseMatDescr_t const descrA, int const * csrRowPtrA, int const * csrColIndA, int * p){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpXcsrsymrcmHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int *))dlsym(RTLD_NEXT, "cusolverSpXcsrsymrcmHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpXcsrsymrcmHost", kApiTypeCuSolver);

    lretval = lcusolverSpXcsrsymrcmHost(handle, n, nnzA, descrA, csrRowPtrA, csrColIndA, p);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpXcsrsymrcmHost cusolverSpXcsrsymrcmHost


#undef cusolverSpXcsrsymmdqHost
cusolverStatus_t cusolverSpXcsrsymmdqHost(cusolverSpHandle_t handle, int n, int nnzA, cusparseMatDescr_t const descrA, int const * csrRowPtrA, int const * csrColIndA, int * p){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpXcsrsymmdqHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int *))dlsym(RTLD_NEXT, "cusolverSpXcsrsymmdqHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpXcsrsymmdqHost", kApiTypeCuSolver);

    lretval = lcusolverSpXcsrsymmdqHost(handle, n, nnzA, descrA, csrRowPtrA, csrColIndA, p);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpXcsrsymmdqHost cusolverSpXcsrsymmdqHost


#undef cusolverSpXcsrsymamdHost
cusolverStatus_t cusolverSpXcsrsymamdHost(cusolverSpHandle_t handle, int n, int nnzA, cusparseMatDescr_t const descrA, int const * csrRowPtrA, int const * csrColIndA, int * p){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpXcsrsymamdHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int *))dlsym(RTLD_NEXT, "cusolverSpXcsrsymamdHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpXcsrsymamdHost", kApiTypeCuSolver);

    lretval = lcusolverSpXcsrsymamdHost(handle, n, nnzA, descrA, csrRowPtrA, csrColIndA, p);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpXcsrsymamdHost cusolverSpXcsrsymamdHost


#undef cusolverSpXcsrmetisndHost
cusolverStatus_t cusolverSpXcsrmetisndHost(cusolverSpHandle_t handle, int n, int nnzA, cusparseMatDescr_t const descrA, int const * csrRowPtrA, int const * csrColIndA, int64_t const * options, int * p){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpXcsrmetisndHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int64_t const *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, int const *, int const *, int64_t const *, int *))dlsym(RTLD_NEXT, "cusolverSpXcsrmetisndHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpXcsrmetisndHost", kApiTypeCuSolver);

    lretval = lcusolverSpXcsrmetisndHost(handle, n, nnzA, descrA, csrRowPtrA, csrColIndA, options, p);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpXcsrmetisndHost cusolverSpXcsrmetisndHost


#undef cusolverSpScsrzfdHost
cusolverStatus_t cusolverSpScsrzfdHost(cusolverSpHandle_t handle, int n, int nnz, cusparseMatDescr_t const descrA, float const * csrValA, int const * csrRowPtrA, int const * csrColIndA, int * P, int * numnz){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsrzfdHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int *, int *))dlsym(RTLD_NEXT, "cusolverSpScsrzfdHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsrzfdHost", kApiTypeCuSolver);

    lretval = lcusolverSpScsrzfdHost(handle, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, P, numnz);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsrzfdHost cusolverSpScsrzfdHost


#undef cusolverSpDcsrzfdHost
cusolverStatus_t cusolverSpDcsrzfdHost(cusolverSpHandle_t handle, int n, int nnz, cusparseMatDescr_t const descrA, double const * csrValA, int const * csrRowPtrA, int const * csrColIndA, int * P, int * numnz){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsrzfdHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int *, int *))dlsym(RTLD_NEXT, "cusolverSpDcsrzfdHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsrzfdHost", kApiTypeCuSolver);

    lretval = lcusolverSpDcsrzfdHost(handle, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, P, numnz);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsrzfdHost cusolverSpDcsrzfdHost


#undef cusolverSpCcsrzfdHost
cusolverStatus_t cusolverSpCcsrzfdHost(cusolverSpHandle_t handle, int n, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, int * P, int * numnz){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsrzfdHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int *, int *))dlsym(RTLD_NEXT, "cusolverSpCcsrzfdHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsrzfdHost", kApiTypeCuSolver);

    lretval = lcusolverSpCcsrzfdHost(handle, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, P, numnz);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsrzfdHost cusolverSpCcsrzfdHost


#undef cusolverSpZcsrzfdHost
cusolverStatus_t cusolverSpZcsrzfdHost(cusolverSpHandle_t handle, int n, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, int * P, int * numnz){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsrzfdHost) (cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int *, int *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int *, int *))dlsym(RTLD_NEXT, "cusolverSpZcsrzfdHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsrzfdHost", kApiTypeCuSolver);

    lretval = lcusolverSpZcsrzfdHost(handle, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, P, numnz);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsrzfdHost cusolverSpZcsrzfdHost


#undef cusolverSpXcsrperm_bufferSizeHost
cusolverStatus_t cusolverSpXcsrperm_bufferSizeHost(cusolverSpHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, int const * csrRowPtrA, int const * csrColIndA, int const * p, int const * q, size_t * bufferSizeInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpXcsrperm_bufferSizeHost) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, int const *, int const *, int const *, int const *, size_t *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, int const *, int const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusolverSpXcsrperm_bufferSizeHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpXcsrperm_bufferSizeHost", kApiTypeCuSolver);

    lretval = lcusolverSpXcsrperm_bufferSizeHost(handle, m, n, nnzA, descrA, csrRowPtrA, csrColIndA, p, q, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpXcsrperm_bufferSizeHost cusolverSpXcsrperm_bufferSizeHost


#undef cusolverSpXcsrpermHost
cusolverStatus_t cusolverSpXcsrpermHost(cusolverSpHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, int * csrRowPtrA, int * csrColIndA, int const * p, int const * q, int * map, void * pBuffer){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpXcsrpermHost) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, int *, int *, int const *, int const *, int *, void *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, int *, int *, int const *, int const *, int *, void *))dlsym(RTLD_NEXT, "cusolverSpXcsrpermHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpXcsrpermHost", kApiTypeCuSolver);

    lretval = lcusolverSpXcsrpermHost(handle, m, n, nnzA, descrA, csrRowPtrA, csrColIndA, p, q, map, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpXcsrpermHost cusolverSpXcsrpermHost


#undef cusolverSpCreateCsrqrInfo
cusolverStatus_t cusolverSpCreateCsrqrInfo(csrqrInfo_t * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCreateCsrqrInfo) (csrqrInfo_t *) = (cusolverStatus_t (*)(csrqrInfo_t *))dlsym(RTLD_NEXT, "cusolverSpCreateCsrqrInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCreateCsrqrInfo", kApiTypeCuSolver);

    lretval = lcusolverSpCreateCsrqrInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCreateCsrqrInfo cusolverSpCreateCsrqrInfo


#undef cusolverSpDestroyCsrqrInfo
cusolverStatus_t cusolverSpDestroyCsrqrInfo(csrqrInfo_t info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDestroyCsrqrInfo) (csrqrInfo_t) = (cusolverStatus_t (*)(csrqrInfo_t))dlsym(RTLD_NEXT, "cusolverSpDestroyCsrqrInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDestroyCsrqrInfo", kApiTypeCuSolver);

    lretval = lcusolverSpDestroyCsrqrInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDestroyCsrqrInfo cusolverSpDestroyCsrqrInfo


#undef cusolverSpXcsrqrAnalysisBatched
cusolverStatus_t cusolverSpXcsrqrAnalysisBatched(cusolverSpHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, int const * csrRowPtrA, int const * csrColIndA, csrqrInfo_t info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpXcsrqrAnalysisBatched) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, int const *, int const *, csrqrInfo_t) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, int const *, int const *, csrqrInfo_t))dlsym(RTLD_NEXT, "cusolverSpXcsrqrAnalysisBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpXcsrqrAnalysisBatched", kApiTypeCuSolver);

    lretval = lcusolverSpXcsrqrAnalysisBatched(handle, m, n, nnzA, descrA, csrRowPtrA, csrColIndA, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpXcsrqrAnalysisBatched cusolverSpXcsrqrAnalysisBatched


#undef cusolverSpScsrqrBufferInfoBatched
cusolverStatus_t cusolverSpScsrqrBufferInfoBatched(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, float const * csrVal, int const * csrRowPtr, int const * csrColInd, int batchSize, csrqrInfo_t info, size_t * internalDataInBytes, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsrqrBufferInfoBatched) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, csrqrInfo_t, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, csrqrInfo_t, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverSpScsrqrBufferInfoBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsrqrBufferInfoBatched", kApiTypeCuSolver);

    lretval = lcusolverSpScsrqrBufferInfoBatched(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, batchSize, info, internalDataInBytes, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsrqrBufferInfoBatched cusolverSpScsrqrBufferInfoBatched


#undef cusolverSpDcsrqrBufferInfoBatched
cusolverStatus_t cusolverSpDcsrqrBufferInfoBatched(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, double const * csrVal, int const * csrRowPtr, int const * csrColInd, int batchSize, csrqrInfo_t info, size_t * internalDataInBytes, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsrqrBufferInfoBatched) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, csrqrInfo_t, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, csrqrInfo_t, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverSpDcsrqrBufferInfoBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsrqrBufferInfoBatched", kApiTypeCuSolver);

    lretval = lcusolverSpDcsrqrBufferInfoBatched(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, batchSize, info, internalDataInBytes, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsrqrBufferInfoBatched cusolverSpDcsrqrBufferInfoBatched


#undef cusolverSpCcsrqrBufferInfoBatched
cusolverStatus_t cusolverSpCcsrqrBufferInfoBatched(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrVal, int const * csrRowPtr, int const * csrColInd, int batchSize, csrqrInfo_t info, size_t * internalDataInBytes, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsrqrBufferInfoBatched) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, csrqrInfo_t, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, csrqrInfo_t, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverSpCcsrqrBufferInfoBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsrqrBufferInfoBatched", kApiTypeCuSolver);

    lretval = lcusolverSpCcsrqrBufferInfoBatched(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, batchSize, info, internalDataInBytes, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsrqrBufferInfoBatched cusolverSpCcsrqrBufferInfoBatched


#undef cusolverSpZcsrqrBufferInfoBatched
cusolverStatus_t cusolverSpZcsrqrBufferInfoBatched(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrVal, int const * csrRowPtr, int const * csrColInd, int batchSize, csrqrInfo_t info, size_t * internalDataInBytes, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsrqrBufferInfoBatched) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, csrqrInfo_t, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, csrqrInfo_t, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverSpZcsrqrBufferInfoBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsrqrBufferInfoBatched", kApiTypeCuSolver);

    lretval = lcusolverSpZcsrqrBufferInfoBatched(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, batchSize, info, internalDataInBytes, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsrqrBufferInfoBatched cusolverSpZcsrqrBufferInfoBatched


#undef cusolverSpScsrqrsvBatched
cusolverStatus_t cusolverSpScsrqrsvBatched(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, float const * csrValA, int const * csrRowPtrA, int const * csrColIndA, float const * b, float * x, int batchSize, csrqrInfo_t info, void * pBuffer){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpScsrqrsvBatched) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float *, int, csrqrInfo_t, void *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, float *, int, csrqrInfo_t, void *))dlsym(RTLD_NEXT, "cusolverSpScsrqrsvBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpScsrqrsvBatched", kApiTypeCuSolver);

    lretval = lcusolverSpScsrqrsvBatched(handle, m, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, x, batchSize, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpScsrqrsvBatched cusolverSpScsrqrsvBatched


#undef cusolverSpDcsrqrsvBatched
cusolverStatus_t cusolverSpDcsrqrsvBatched(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, double const * csrValA, int const * csrRowPtrA, int const * csrColIndA, double const * b, double * x, int batchSize, csrqrInfo_t info, void * pBuffer){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpDcsrqrsvBatched) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double *, int, csrqrInfo_t, void *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, double *, int, csrqrInfo_t, void *))dlsym(RTLD_NEXT, "cusolverSpDcsrqrsvBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpDcsrqrsvBatched", kApiTypeCuSolver);

    lretval = lcusolverSpDcsrqrsvBatched(handle, m, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, x, batchSize, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpDcsrqrsvBatched cusolverSpDcsrqrsvBatched


#undef cusolverSpCcsrqrsvBatched
cusolverStatus_t cusolverSpCcsrqrsvBatched(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuComplex const * b, cuComplex * x, int batchSize, csrqrInfo_t info, void * pBuffer){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpCcsrqrsvBatched) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, cuComplex *, int, csrqrInfo_t, void *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, cuComplex *, int, csrqrInfo_t, void *))dlsym(RTLD_NEXT, "cusolverSpCcsrqrsvBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpCcsrqrsvBatched", kApiTypeCuSolver);

    lretval = lcusolverSpCcsrqrsvBatched(handle, m, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, x, batchSize, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpCcsrqrsvBatched cusolverSpCcsrqrsvBatched


#undef cusolverSpZcsrqrsvBatched
cusolverStatus_t cusolverSpZcsrqrsvBatched(cusolverSpHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrValA, int const * csrRowPtrA, int const * csrColIndA, cuDoubleComplex const * b, cuDoubleComplex * x, int batchSize, csrqrInfo_t info, void * pBuffer){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverSpZcsrqrsvBatched) (cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cuDoubleComplex *, int, csrqrInfo_t, void *) = (cusolverStatus_t (*)(cusolverSpHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cuDoubleComplex *, int, csrqrInfo_t, void *))dlsym(RTLD_NEXT, "cusolverSpZcsrqrsvBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverSpZcsrqrsvBatched", kApiTypeCuSolver);

    lretval = lcusolverSpZcsrqrsvBatched(handle, m, n, nnz, descrA, csrValA, csrRowPtrA, csrColIndA, b, x, batchSize, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverSpZcsrqrsvBatched cusolverSpZcsrqrsvBatched

