
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cusolverDn.h>
#include <cusolverMg.h>
#include <cusolverRf.h>
#include <cusolverSp.h>

#include "cudam.h"
#include "api_counter.h"

#undef cusolverGetProperty
cusolverStatus_t cusolverGetProperty(libraryPropertyType type, int * value){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverGetProperty) (libraryPropertyType, int *) = (cusolverStatus_t (*)(libraryPropertyType, int *))dlsym(RTLD_NEXT, "cusolverGetProperty");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverGetProperty", kApiTypeCuSolver);

    lretval = lcusolverGetProperty(type, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverGetProperty cusolverGetProperty


#undef cusolverGetVersion
cusolverStatus_t cusolverGetVersion(int * version){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverGetVersion) (int *) = (cusolverStatus_t (*)(int *))dlsym(RTLD_NEXT, "cusolverGetVersion");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverGetVersion", kApiTypeCuSolver);

    lretval = lcusolverGetVersion(version);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverGetVersion cusolverGetVersion


#undef cusolverDnCreate
cusolverStatus_t cusolverDnCreate(cusolverDnHandle_t * handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCreate) (cusolverDnHandle_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t *))dlsym(RTLD_NEXT, "cusolverDnCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCreate", kApiTypeCuSolver);

    lretval = lcusolverDnCreate(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCreate cusolverDnCreate


#undef cusolverDnDestroy
cusolverStatus_t cusolverDnDestroy(cusolverDnHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDestroy) (cusolverDnHandle_t) = (cusolverStatus_t (*)(cusolverDnHandle_t))dlsym(RTLD_NEXT, "cusolverDnDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDestroy", kApiTypeCuSolver);

    lretval = lcusolverDnDestroy(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDestroy cusolverDnDestroy


#undef cusolverDnSetStream
cusolverStatus_t cusolverDnSetStream(cusolverDnHandle_t handle, cudaStream_t streamId){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSetStream) (cusolverDnHandle_t, cudaStream_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cudaStream_t))dlsym(RTLD_NEXT, "cusolverDnSetStream");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSetStream", kApiTypeCuSolver);

    lretval = lcusolverDnSetStream(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSetStream cusolverDnSetStream


#undef cusolverDnGetStream
cusolverStatus_t cusolverDnGetStream(cusolverDnHandle_t handle, cudaStream_t * streamId){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnGetStream) (cusolverDnHandle_t, cudaStream_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cudaStream_t *))dlsym(RTLD_NEXT, "cusolverDnGetStream");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnGetStream", kApiTypeCuSolver);

    lretval = lcusolverDnGetStream(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnGetStream cusolverDnGetStream


#undef cusolverDnIRSParamsCreate
cusolverStatus_t cusolverDnIRSParamsCreate(cusolverDnIRSParams_t * params_ptr){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsCreate) (cusolverDnIRSParams_t *) = (cusolverStatus_t (*)(cusolverDnIRSParams_t *))dlsym(RTLD_NEXT, "cusolverDnIRSParamsCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsCreate", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsCreate(params_ptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsCreate cusolverDnIRSParamsCreate


#undef cusolverDnIRSParamsDestroy
cusolverStatus_t cusolverDnIRSParamsDestroy(cusolverDnIRSParams_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsDestroy) (cusolverDnIRSParams_t) = (cusolverStatus_t (*)(cusolverDnIRSParams_t))dlsym(RTLD_NEXT, "cusolverDnIRSParamsDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsDestroy", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsDestroy(params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsDestroy cusolverDnIRSParamsDestroy


#undef cusolverDnIRSParamsSetRefinementSolver
cusolverStatus_t cusolverDnIRSParamsSetRefinementSolver(cusolverDnIRSParams_t params, cusolverIRSRefinement_t refinement_solver){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsSetRefinementSolver) (cusolverDnIRSParams_t, cusolverIRSRefinement_t) = (cusolverStatus_t (*)(cusolverDnIRSParams_t, cusolverIRSRefinement_t))dlsym(RTLD_NEXT, "cusolverDnIRSParamsSetRefinementSolver");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsSetRefinementSolver", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsSetRefinementSolver(params, refinement_solver);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsSetRefinementSolver cusolverDnIRSParamsSetRefinementSolver


#undef cusolverDnIRSParamsSetSolverMainPrecision
cusolverStatus_t cusolverDnIRSParamsSetSolverMainPrecision(cusolverDnIRSParams_t params, cusolverPrecType_t solver_main_precision){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsSetSolverMainPrecision) (cusolverDnIRSParams_t, cusolverPrecType_t) = (cusolverStatus_t (*)(cusolverDnIRSParams_t, cusolverPrecType_t))dlsym(RTLD_NEXT, "cusolverDnIRSParamsSetSolverMainPrecision");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsSetSolverMainPrecision", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsSetSolverMainPrecision(params, solver_main_precision);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsSetSolverMainPrecision cusolverDnIRSParamsSetSolverMainPrecision


#undef cusolverDnIRSParamsSetSolverLowestPrecision
cusolverStatus_t cusolverDnIRSParamsSetSolverLowestPrecision(cusolverDnIRSParams_t params, cusolverPrecType_t solver_lowest_precision){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsSetSolverLowestPrecision) (cusolverDnIRSParams_t, cusolverPrecType_t) = (cusolverStatus_t (*)(cusolverDnIRSParams_t, cusolverPrecType_t))dlsym(RTLD_NEXT, "cusolverDnIRSParamsSetSolverLowestPrecision");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsSetSolverLowestPrecision", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsSetSolverLowestPrecision(params, solver_lowest_precision);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsSetSolverLowestPrecision cusolverDnIRSParamsSetSolverLowestPrecision


#undef cusolverDnIRSParamsSetSolverPrecisions
cusolverStatus_t cusolverDnIRSParamsSetSolverPrecisions(cusolverDnIRSParams_t params, cusolverPrecType_t solver_main_precision, cusolverPrecType_t solver_lowest_precision){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsSetSolverPrecisions) (cusolverDnIRSParams_t, cusolverPrecType_t, cusolverPrecType_t) = (cusolverStatus_t (*)(cusolverDnIRSParams_t, cusolverPrecType_t, cusolverPrecType_t))dlsym(RTLD_NEXT, "cusolverDnIRSParamsSetSolverPrecisions");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsSetSolverPrecisions", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsSetSolverPrecisions(params, solver_main_precision, solver_lowest_precision);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsSetSolverPrecisions cusolverDnIRSParamsSetSolverPrecisions


#undef cusolverDnIRSParamsSetTol
cusolverStatus_t cusolverDnIRSParamsSetTol(cusolverDnIRSParams_t params, double val){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsSetTol) (cusolverDnIRSParams_t, double) = (cusolverStatus_t (*)(cusolverDnIRSParams_t, double))dlsym(RTLD_NEXT, "cusolverDnIRSParamsSetTol");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsSetTol", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsSetTol(params, val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsSetTol cusolverDnIRSParamsSetTol


#undef cusolverDnIRSParamsSetTolInner
cusolverStatus_t cusolverDnIRSParamsSetTolInner(cusolverDnIRSParams_t params, double val){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsSetTolInner) (cusolverDnIRSParams_t, double) = (cusolverStatus_t (*)(cusolverDnIRSParams_t, double))dlsym(RTLD_NEXT, "cusolverDnIRSParamsSetTolInner");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsSetTolInner", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsSetTolInner(params, val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsSetTolInner cusolverDnIRSParamsSetTolInner


#undef cusolverDnIRSParamsSetMaxIters
cusolverStatus_t cusolverDnIRSParamsSetMaxIters(cusolverDnIRSParams_t params, cusolver_int_t maxiters){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsSetMaxIters) (cusolverDnIRSParams_t, cusolver_int_t) = (cusolverStatus_t (*)(cusolverDnIRSParams_t, cusolver_int_t))dlsym(RTLD_NEXT, "cusolverDnIRSParamsSetMaxIters");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsSetMaxIters", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsSetMaxIters(params, maxiters);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsSetMaxIters cusolverDnIRSParamsSetMaxIters


#undef cusolverDnIRSParamsSetMaxItersInner
cusolverStatus_t cusolverDnIRSParamsSetMaxItersInner(cusolverDnIRSParams_t params, cusolver_int_t maxiters_inner){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsSetMaxItersInner) (cusolverDnIRSParams_t, cusolver_int_t) = (cusolverStatus_t (*)(cusolverDnIRSParams_t, cusolver_int_t))dlsym(RTLD_NEXT, "cusolverDnIRSParamsSetMaxItersInner");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsSetMaxItersInner", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsSetMaxItersInner(params, maxiters_inner);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsSetMaxItersInner cusolverDnIRSParamsSetMaxItersInner


#undef cusolverDnIRSParamsGetMaxIters
cusolverStatus_t cusolverDnIRSParamsGetMaxIters(cusolverDnIRSParams_t params, cusolver_int_t * maxiters){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsGetMaxIters) (cusolverDnIRSParams_t, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnIRSParams_t, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnIRSParamsGetMaxIters");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsGetMaxIters", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsGetMaxIters(params, maxiters);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsGetMaxIters cusolverDnIRSParamsGetMaxIters


#undef cusolverDnIRSParamsEnableFallback
cusolverStatus_t cusolverDnIRSParamsEnableFallback(cusolverDnIRSParams_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsEnableFallback) (cusolverDnIRSParams_t) = (cusolverStatus_t (*)(cusolverDnIRSParams_t))dlsym(RTLD_NEXT, "cusolverDnIRSParamsEnableFallback");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsEnableFallback", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsEnableFallback(params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsEnableFallback cusolverDnIRSParamsEnableFallback


#undef cusolverDnIRSParamsDisableFallback
cusolverStatus_t cusolverDnIRSParamsDisableFallback(cusolverDnIRSParams_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSParamsDisableFallback) (cusolverDnIRSParams_t) = (cusolverStatus_t (*)(cusolverDnIRSParams_t))dlsym(RTLD_NEXT, "cusolverDnIRSParamsDisableFallback");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSParamsDisableFallback", kApiTypeCuSolver);

    lretval = lcusolverDnIRSParamsDisableFallback(params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSParamsDisableFallback cusolverDnIRSParamsDisableFallback


#undef cusolverDnIRSInfosDestroy
cusolverStatus_t cusolverDnIRSInfosDestroy(cusolverDnIRSInfos_t infos){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSInfosDestroy) (cusolverDnIRSInfos_t) = (cusolverStatus_t (*)(cusolverDnIRSInfos_t))dlsym(RTLD_NEXT, "cusolverDnIRSInfosDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSInfosDestroy", kApiTypeCuSolver);

    lretval = lcusolverDnIRSInfosDestroy(infos);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSInfosDestroy cusolverDnIRSInfosDestroy


#undef cusolverDnIRSInfosCreate
cusolverStatus_t cusolverDnIRSInfosCreate(cusolverDnIRSInfos_t * infos_ptr){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSInfosCreate) (cusolverDnIRSInfos_t *) = (cusolverStatus_t (*)(cusolverDnIRSInfos_t *))dlsym(RTLD_NEXT, "cusolverDnIRSInfosCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSInfosCreate", kApiTypeCuSolver);

    lretval = lcusolverDnIRSInfosCreate(infos_ptr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSInfosCreate cusolverDnIRSInfosCreate


#undef cusolverDnIRSInfosGetNiters
cusolverStatus_t cusolverDnIRSInfosGetNiters(cusolverDnIRSInfos_t infos, cusolver_int_t * niters){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSInfosGetNiters) (cusolverDnIRSInfos_t, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnIRSInfos_t, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnIRSInfosGetNiters");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSInfosGetNiters", kApiTypeCuSolver);

    lretval = lcusolverDnIRSInfosGetNiters(infos, niters);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSInfosGetNiters cusolverDnIRSInfosGetNiters


#undef cusolverDnIRSInfosGetOuterNiters
cusolverStatus_t cusolverDnIRSInfosGetOuterNiters(cusolverDnIRSInfos_t infos, cusolver_int_t * outer_niters){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSInfosGetOuterNiters) (cusolverDnIRSInfos_t, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnIRSInfos_t, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnIRSInfosGetOuterNiters");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSInfosGetOuterNiters", kApiTypeCuSolver);

    lretval = lcusolverDnIRSInfosGetOuterNiters(infos, outer_niters);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSInfosGetOuterNiters cusolverDnIRSInfosGetOuterNiters


#undef cusolverDnIRSInfosRequestResidual
cusolverStatus_t cusolverDnIRSInfosRequestResidual(cusolverDnIRSInfos_t infos){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSInfosRequestResidual) (cusolverDnIRSInfos_t) = (cusolverStatus_t (*)(cusolverDnIRSInfos_t))dlsym(RTLD_NEXT, "cusolverDnIRSInfosRequestResidual");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSInfosRequestResidual", kApiTypeCuSolver);

    lretval = lcusolverDnIRSInfosRequestResidual(infos);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSInfosRequestResidual cusolverDnIRSInfosRequestResidual


#undef cusolverDnIRSInfosGetResidualHistory
cusolverStatus_t cusolverDnIRSInfosGetResidualHistory(cusolverDnIRSInfos_t infos, void * * residual_history){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSInfosGetResidualHistory) (cusolverDnIRSInfos_t, void * *) = (cusolverStatus_t (*)(cusolverDnIRSInfos_t, void * *))dlsym(RTLD_NEXT, "cusolverDnIRSInfosGetResidualHistory");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSInfosGetResidualHistory", kApiTypeCuSolver);

    lretval = lcusolverDnIRSInfosGetResidualHistory(infos, residual_history);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSInfosGetResidualHistory cusolverDnIRSInfosGetResidualHistory


#undef cusolverDnIRSInfosGetMaxIters
cusolverStatus_t cusolverDnIRSInfosGetMaxIters(cusolverDnIRSInfos_t infos, cusolver_int_t * maxiters){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSInfosGetMaxIters) (cusolverDnIRSInfos_t, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnIRSInfos_t, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnIRSInfosGetMaxIters");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSInfosGetMaxIters", kApiTypeCuSolver);

    lretval = lcusolverDnIRSInfosGetMaxIters(infos, maxiters);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSInfosGetMaxIters cusolverDnIRSInfosGetMaxIters


#undef cusolverDnZZgesv
cusolverStatus_t cusolverDnZZgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZZgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZZgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZZgesv", kApiTypeCuSolver);

    lretval = lcusolverDnZZgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZZgesv cusolverDnZZgesv


#undef cusolverDnZCgesv
cusolverStatus_t cusolverDnZCgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZCgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZCgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZCgesv", kApiTypeCuSolver);

    lretval = lcusolverDnZCgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZCgesv cusolverDnZCgesv


#undef cusolverDnZKgesv
cusolverStatus_t cusolverDnZKgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZKgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZKgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZKgesv", kApiTypeCuSolver);

    lretval = lcusolverDnZKgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZKgesv cusolverDnZKgesv


#undef cusolverDnZEgesv
cusolverStatus_t cusolverDnZEgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZEgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZEgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZEgesv", kApiTypeCuSolver);

    lretval = lcusolverDnZEgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZEgesv cusolverDnZEgesv


#undef cusolverDnZYgesv
cusolverStatus_t cusolverDnZYgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZYgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZYgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZYgesv", kApiTypeCuSolver);

    lretval = lcusolverDnZYgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZYgesv cusolverDnZYgesv


#undef cusolverDnCCgesv
cusolverStatus_t cusolverDnCCgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCCgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnCCgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCCgesv", kApiTypeCuSolver);

    lretval = lcusolverDnCCgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCCgesv cusolverDnCCgesv


#undef cusolverDnCEgesv
cusolverStatus_t cusolverDnCEgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCEgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnCEgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCEgesv", kApiTypeCuSolver);

    lretval = lcusolverDnCEgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCEgesv cusolverDnCEgesv


#undef cusolverDnCKgesv
cusolverStatus_t cusolverDnCKgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCKgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnCKgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCKgesv", kApiTypeCuSolver);

    lretval = lcusolverDnCKgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCKgesv cusolverDnCKgesv


#undef cusolverDnCYgesv
cusolverStatus_t cusolverDnCYgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCYgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnCYgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCYgesv", kApiTypeCuSolver);

    lretval = lcusolverDnCYgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCYgesv cusolverDnCYgesv


#undef cusolverDnDDgesv
cusolverStatus_t cusolverDnDDgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDDgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDDgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDDgesv", kApiTypeCuSolver);

    lretval = lcusolverDnDDgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDDgesv cusolverDnDDgesv


#undef cusolverDnDSgesv
cusolverStatus_t cusolverDnDSgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDSgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDSgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDSgesv", kApiTypeCuSolver);

    lretval = lcusolverDnDSgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDSgesv cusolverDnDSgesv


#undef cusolverDnDHgesv
cusolverStatus_t cusolverDnDHgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDHgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDHgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDHgesv", kApiTypeCuSolver);

    lretval = lcusolverDnDHgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDHgesv cusolverDnDHgesv


#undef cusolverDnDBgesv
cusolverStatus_t cusolverDnDBgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDBgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDBgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDBgesv", kApiTypeCuSolver);

    lretval = lcusolverDnDBgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDBgesv cusolverDnDBgesv


#undef cusolverDnDXgesv
cusolverStatus_t cusolverDnDXgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDXgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDXgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDXgesv", kApiTypeCuSolver);

    lretval = lcusolverDnDXgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDXgesv cusolverDnDXgesv


#undef cusolverDnSSgesv
cusolverStatus_t cusolverDnSSgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSSgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnSSgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSSgesv", kApiTypeCuSolver);

    lretval = lcusolverDnSSgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSSgesv cusolverDnSSgesv


#undef cusolverDnSHgesv
cusolverStatus_t cusolverDnSHgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSHgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnSHgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSHgesv", kApiTypeCuSolver);

    lretval = lcusolverDnSHgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSHgesv cusolverDnSHgesv


#undef cusolverDnSBgesv
cusolverStatus_t cusolverDnSBgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSBgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnSBgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSBgesv", kApiTypeCuSolver);

    lretval = lcusolverDnSBgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSBgesv cusolverDnSBgesv


#undef cusolverDnSXgesv
cusolverStatus_t cusolverDnSXgesv(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSXgesv) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnSXgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSXgesv", kApiTypeCuSolver);

    lretval = lcusolverDnSXgesv(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSXgesv cusolverDnSXgesv


#undef cusolverDnZZgesv_bufferSize
cusolverStatus_t cusolverDnZZgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZZgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZZgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZZgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZZgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZZgesv_bufferSize cusolverDnZZgesv_bufferSize


#undef cusolverDnZCgesv_bufferSize
cusolverStatus_t cusolverDnZCgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZCgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZCgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZCgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZCgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZCgesv_bufferSize cusolverDnZCgesv_bufferSize


#undef cusolverDnZKgesv_bufferSize
cusolverStatus_t cusolverDnZKgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZKgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZKgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZKgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZKgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZKgesv_bufferSize cusolverDnZKgesv_bufferSize


#undef cusolverDnZEgesv_bufferSize
cusolverStatus_t cusolverDnZEgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZEgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZEgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZEgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZEgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZEgesv_bufferSize cusolverDnZEgesv_bufferSize


#undef cusolverDnZYgesv_bufferSize
cusolverStatus_t cusolverDnZYgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZYgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cusolver_int_t *, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZYgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZYgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZYgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZYgesv_bufferSize cusolverDnZYgesv_bufferSize


#undef cusolverDnCCgesv_bufferSize
cusolverStatus_t cusolverDnCCgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCCgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnCCgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCCgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCCgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCCgesv_bufferSize cusolverDnCCgesv_bufferSize


#undef cusolverDnCKgesv_bufferSize
cusolverStatus_t cusolverDnCKgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCKgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnCKgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCKgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCKgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCKgesv_bufferSize cusolverDnCKgesv_bufferSize


#undef cusolverDnCEgesv_bufferSize
cusolverStatus_t cusolverDnCEgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCEgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnCEgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCEgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCEgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCEgesv_bufferSize cusolverDnCEgesv_bufferSize


#undef cusolverDnCYgesv_bufferSize
cusolverStatus_t cusolverDnCYgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCYgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cusolver_int_t *, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnCYgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCYgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCYgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCYgesv_bufferSize cusolverDnCYgesv_bufferSize


#undef cusolverDnDDgesv_bufferSize
cusolverStatus_t cusolverDnDDgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDDgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDDgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDDgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDDgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDDgesv_bufferSize cusolverDnDDgesv_bufferSize


#undef cusolverDnDSgesv_bufferSize
cusolverStatus_t cusolverDnDSgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDSgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDSgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDSgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDSgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDSgesv_bufferSize cusolverDnDSgesv_bufferSize


#undef cusolverDnDHgesv_bufferSize
cusolverStatus_t cusolverDnDHgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDHgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDHgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDHgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDHgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDHgesv_bufferSize cusolverDnDHgesv_bufferSize


#undef cusolverDnDBgesv_bufferSize
cusolverStatus_t cusolverDnDBgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDBgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDBgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDBgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDBgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDBgesv_bufferSize cusolverDnDBgesv_bufferSize


#undef cusolverDnDXgesv_bufferSize
cusolverStatus_t cusolverDnDXgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDXgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, cusolver_int_t *, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDXgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDXgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDXgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDXgesv_bufferSize cusolverDnDXgesv_bufferSize


#undef cusolverDnSSgesv_bufferSize
cusolverStatus_t cusolverDnSSgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSSgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnSSgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSSgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSSgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSSgesv_bufferSize cusolverDnSSgesv_bufferSize


#undef cusolverDnSHgesv_bufferSize
cusolverStatus_t cusolverDnSHgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSHgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnSHgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSHgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSHgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSHgesv_bufferSize cusolverDnSHgesv_bufferSize


#undef cusolverDnSBgesv_bufferSize
cusolverStatus_t cusolverDnSBgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSBgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnSBgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSBgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSBgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSBgesv_bufferSize cusolverDnSBgesv_bufferSize


#undef cusolverDnSXgesv_bufferSize
cusolverStatus_t cusolverDnSXgesv_bufferSize(cusolverDnHandle_t handle, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, cusolver_int_t * dipiv, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSXgesv_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, cusolver_int_t *, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnSXgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSXgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSXgesv_bufferSize(handle, n, nrhs, dA, ldda, dipiv, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSXgesv_bufferSize cusolverDnSXgesv_bufferSize


#undef cusolverDnZZgels
cusolverStatus_t cusolverDnZZgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZZgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZZgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZZgels", kApiTypeCuSolver);

    lretval = lcusolverDnZZgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZZgels cusolverDnZZgels


#undef cusolverDnZCgels
cusolverStatus_t cusolverDnZCgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZCgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZCgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZCgels", kApiTypeCuSolver);

    lretval = lcusolverDnZCgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZCgels cusolverDnZCgels


#undef cusolverDnZKgels
cusolverStatus_t cusolverDnZKgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZKgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZKgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZKgels", kApiTypeCuSolver);

    lretval = lcusolverDnZKgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZKgels cusolverDnZKgels


#undef cusolverDnZEgels
cusolverStatus_t cusolverDnZEgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZEgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZEgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZEgels", kApiTypeCuSolver);

    lretval = lcusolverDnZEgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZEgels cusolverDnZEgels


#undef cusolverDnZYgels
cusolverStatus_t cusolverDnZYgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZYgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnZYgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZYgels", kApiTypeCuSolver);

    lretval = lcusolverDnZYgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZYgels cusolverDnZYgels


#undef cusolverDnCCgels
cusolverStatus_t cusolverDnCCgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCCgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnCCgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCCgels", kApiTypeCuSolver);

    lretval = lcusolverDnCCgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCCgels cusolverDnCCgels


#undef cusolverDnCKgels
cusolverStatus_t cusolverDnCKgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCKgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnCKgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCKgels", kApiTypeCuSolver);

    lretval = lcusolverDnCKgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCKgels cusolverDnCKgels


#undef cusolverDnCEgels
cusolverStatus_t cusolverDnCEgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCEgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnCEgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCEgels", kApiTypeCuSolver);

    lretval = lcusolverDnCEgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCEgels cusolverDnCEgels


#undef cusolverDnCYgels
cusolverStatus_t cusolverDnCYgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCYgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnCYgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCYgels", kApiTypeCuSolver);

    lretval = lcusolverDnCYgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCYgels cusolverDnCYgels


#undef cusolverDnDDgels
cusolverStatus_t cusolverDnDDgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDDgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDDgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDDgels", kApiTypeCuSolver);

    lretval = lcusolverDnDDgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDDgels cusolverDnDDgels


#undef cusolverDnDSgels
cusolverStatus_t cusolverDnDSgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDSgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDSgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDSgels", kApiTypeCuSolver);

    lretval = lcusolverDnDSgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDSgels cusolverDnDSgels


#undef cusolverDnDHgels
cusolverStatus_t cusolverDnDHgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDHgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDHgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDHgels", kApiTypeCuSolver);

    lretval = lcusolverDnDHgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDHgels cusolverDnDHgels


#undef cusolverDnDBgels
cusolverStatus_t cusolverDnDBgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDBgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDBgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDBgels", kApiTypeCuSolver);

    lretval = lcusolverDnDBgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDBgels cusolverDnDBgels


#undef cusolverDnDXgels
cusolverStatus_t cusolverDnDXgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDXgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnDXgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDXgels", kApiTypeCuSolver);

    lretval = lcusolverDnDXgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDXgels cusolverDnDXgels


#undef cusolverDnSSgels
cusolverStatus_t cusolverDnSSgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSSgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnSSgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSSgels", kApiTypeCuSolver);

    lretval = lcusolverDnSSgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSSgels cusolverDnSSgels


#undef cusolverDnSHgels
cusolverStatus_t cusolverDnSHgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSHgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnSHgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSHgels", kApiTypeCuSolver);

    lretval = lcusolverDnSHgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSHgels cusolverDnSHgels


#undef cusolverDnSBgels
cusolverStatus_t cusolverDnSBgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSBgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnSBgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSBgels", kApiTypeCuSolver);

    lretval = lcusolverDnSBgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSBgels cusolverDnSBgels


#undef cusolverDnSXgels
cusolverStatus_t cusolverDnSXgels(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * iter, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSXgels) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnSXgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSXgels", kApiTypeCuSolver);

    lretval = lcusolverDnSXgels(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, iter, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSXgels cusolverDnSXgels


#undef cusolverDnZZgels_bufferSize
cusolverStatus_t cusolverDnZZgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZZgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZZgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZZgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZZgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZZgels_bufferSize cusolverDnZZgels_bufferSize


#undef cusolverDnZCgels_bufferSize
cusolverStatus_t cusolverDnZCgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZCgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZCgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZCgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZCgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZCgels_bufferSize cusolverDnZCgels_bufferSize


#undef cusolverDnZKgels_bufferSize
cusolverStatus_t cusolverDnZKgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZKgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZKgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZKgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZKgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZKgels_bufferSize cusolverDnZKgels_bufferSize


#undef cusolverDnZEgels_bufferSize
cusolverStatus_t cusolverDnZEgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZEgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZEgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZEgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZEgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZEgels_bufferSize cusolverDnZEgels_bufferSize


#undef cusolverDnZYgels_bufferSize
cusolverStatus_t cusolverDnZYgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuDoubleComplex * dA, cusolver_int_t ldda, cuDoubleComplex * dB, cusolver_int_t lddb, cuDoubleComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZYgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, cuDoubleComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnZYgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZYgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZYgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZYgels_bufferSize cusolverDnZYgels_bufferSize


#undef cusolverDnCCgels_bufferSize
cusolverStatus_t cusolverDnCCgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCCgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnCCgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCCgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCCgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCCgels_bufferSize cusolverDnCCgels_bufferSize


#undef cusolverDnCKgels_bufferSize
cusolverStatus_t cusolverDnCKgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCKgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnCKgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCKgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCKgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCKgels_bufferSize cusolverDnCKgels_bufferSize


#undef cusolverDnCEgels_bufferSize
cusolverStatus_t cusolverDnCEgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCEgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnCEgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCEgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCEgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCEgels_bufferSize cusolverDnCEgels_bufferSize


#undef cusolverDnCYgels_bufferSize
cusolverStatus_t cusolverDnCYgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, cuComplex * dA, cusolver_int_t ldda, cuComplex * dB, cusolver_int_t lddb, cuComplex * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCYgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, cuComplex *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnCYgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCYgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCYgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCYgels_bufferSize cusolverDnCYgels_bufferSize


#undef cusolverDnDDgels_bufferSize
cusolverStatus_t cusolverDnDDgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDDgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDDgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDDgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDDgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDDgels_bufferSize cusolverDnDDgels_bufferSize


#undef cusolverDnDSgels_bufferSize
cusolverStatus_t cusolverDnDSgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDSgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDSgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDSgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDSgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDSgels_bufferSize cusolverDnDSgels_bufferSize


#undef cusolverDnDHgels_bufferSize
cusolverStatus_t cusolverDnDHgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDHgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDHgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDHgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDHgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDHgels_bufferSize cusolverDnDHgels_bufferSize


#undef cusolverDnDBgels_bufferSize
cusolverStatus_t cusolverDnDBgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDBgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDBgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDBgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDBgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDBgels_bufferSize cusolverDnDBgels_bufferSize


#undef cusolverDnDXgels_bufferSize
cusolverStatus_t cusolverDnDXgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, double * dA, cusolver_int_t ldda, double * dB, cusolver_int_t lddb, double * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDXgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, double *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnDXgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDXgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDXgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDXgels_bufferSize cusolverDnDXgels_bufferSize


#undef cusolverDnSSgels_bufferSize
cusolverStatus_t cusolverDnSSgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSSgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnSSgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSSgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSSgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSSgels_bufferSize cusolverDnSSgels_bufferSize


#undef cusolverDnSHgels_bufferSize
cusolverStatus_t cusolverDnSHgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSHgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnSHgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSHgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSHgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSHgels_bufferSize cusolverDnSHgels_bufferSize


#undef cusolverDnSBgels_bufferSize
cusolverStatus_t cusolverDnSBgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSBgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnSBgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSBgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSBgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSBgels_bufferSize cusolverDnSBgels_bufferSize


#undef cusolverDnSXgels_bufferSize
cusolverStatus_t cusolverDnSXgels_bufferSize(cusolverDnHandle_t handle, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, float * dA, cusolver_int_t ldda, float * dB, cusolver_int_t lddb, float * dX, cusolver_int_t lddx, void * dWorkspace, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSXgels_bufferSize) (cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, float *, cusolver_int_t, void *, size_t *))dlsym(RTLD_NEXT, "cusolverDnSXgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSXgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSXgels_bufferSize(handle, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSXgels_bufferSize cusolverDnSXgels_bufferSize


#undef cusolverDnIRSXgesv
cusolverStatus_t cusolverDnIRSXgesv(cusolverDnHandle_t handle, cusolverDnIRSParams_t gesv_irs_params, cusolverDnIRSInfos_t gesv_irs_infos, cusolver_int_t n, cusolver_int_t nrhs, void * dA, cusolver_int_t ldda, void * dB, cusolver_int_t lddb, void * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * niters, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSXgesv) (cusolverDnHandle_t, cusolverDnIRSParams_t, cusolverDnIRSInfos_t, cusolver_int_t, cusolver_int_t, void *, cusolver_int_t, void *, cusolver_int_t, void *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnIRSParams_t, cusolverDnIRSInfos_t, cusolver_int_t, cusolver_int_t, void *, cusolver_int_t, void *, cusolver_int_t, void *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnIRSXgesv");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSXgesv", kApiTypeCuSolver);

    lretval = lcusolverDnIRSXgesv(handle, gesv_irs_params, gesv_irs_infos, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, niters, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSXgesv cusolverDnIRSXgesv


#undef cusolverDnIRSXgesv_bufferSize
cusolverStatus_t cusolverDnIRSXgesv_bufferSize(cusolverDnHandle_t handle, cusolverDnIRSParams_t params, cusolver_int_t n, cusolver_int_t nrhs, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSXgesv_bufferSize) (cusolverDnHandle_t, cusolverDnIRSParams_t, cusolver_int_t, cusolver_int_t, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnIRSParams_t, cusolver_int_t, cusolver_int_t, size_t *))dlsym(RTLD_NEXT, "cusolverDnIRSXgesv_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSXgesv_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnIRSXgesv_bufferSize(handle, params, n, nrhs, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSXgesv_bufferSize cusolverDnIRSXgesv_bufferSize


#undef cusolverDnIRSXgels
cusolverStatus_t cusolverDnIRSXgels(cusolverDnHandle_t handle, cusolverDnIRSParams_t gels_irs_params, cusolverDnIRSInfos_t gels_irs_infos, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, void * dA, cusolver_int_t ldda, void * dB, cusolver_int_t lddb, void * dX, cusolver_int_t lddx, void * dWorkspace, size_t lwork_bytes, cusolver_int_t * niters, cusolver_int_t * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSXgels) (cusolverDnHandle_t, cusolverDnIRSParams_t, cusolverDnIRSInfos_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, void *, cusolver_int_t, void *, cusolver_int_t, void *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnIRSParams_t, cusolverDnIRSInfos_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, void *, cusolver_int_t, void *, cusolver_int_t, void *, cusolver_int_t, void *, size_t, cusolver_int_t *, cusolver_int_t *))dlsym(RTLD_NEXT, "cusolverDnIRSXgels");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSXgels", kApiTypeCuSolver);

    lretval = lcusolverDnIRSXgels(handle, gels_irs_params, gels_irs_infos, m, n, nrhs, dA, ldda, dB, lddb, dX, lddx, dWorkspace, lwork_bytes, niters, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSXgels cusolverDnIRSXgels


#undef cusolverDnIRSXgels_bufferSize
cusolverStatus_t cusolverDnIRSXgels_bufferSize(cusolverDnHandle_t handle, cusolverDnIRSParams_t params, cusolver_int_t m, cusolver_int_t n, cusolver_int_t nrhs, size_t * lwork_bytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnIRSXgels_bufferSize) (cusolverDnHandle_t, cusolverDnIRSParams_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnIRSParams_t, cusolver_int_t, cusolver_int_t, cusolver_int_t, size_t *))dlsym(RTLD_NEXT, "cusolverDnIRSXgels_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnIRSXgels_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnIRSXgels_bufferSize(handle, params, m, n, nrhs, lwork_bytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnIRSXgels_bufferSize cusolverDnIRSXgels_bufferSize


#undef cusolverDnSpotrf_bufferSize
cusolverStatus_t cusolverDnSpotrf_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSpotrf_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSpotrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSpotrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSpotrf_bufferSize(handle, uplo, n, A, lda, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSpotrf_bufferSize cusolverDnSpotrf_bufferSize


#undef cusolverDnDpotrf_bufferSize
cusolverStatus_t cusolverDnDpotrf_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDpotrf_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDpotrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDpotrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDpotrf_bufferSize(handle, uplo, n, A, lda, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDpotrf_bufferSize cusolverDnDpotrf_bufferSize


#undef cusolverDnCpotrf_bufferSize
cusolverStatus_t cusolverDnCpotrf_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCpotrf_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCpotrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCpotrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCpotrf_bufferSize(handle, uplo, n, A, lda, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCpotrf_bufferSize cusolverDnCpotrf_bufferSize


#undef cusolverDnZpotrf_bufferSize
cusolverStatus_t cusolverDnZpotrf_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZpotrf_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZpotrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZpotrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZpotrf_bufferSize(handle, uplo, n, A, lda, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZpotrf_bufferSize cusolverDnZpotrf_bufferSize


#undef cusolverDnSpotrf
cusolverStatus_t cusolverDnSpotrf(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, float * Workspace, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSpotrf) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSpotrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSpotrf", kApiTypeCuSolver);

    lretval = lcusolverDnSpotrf(handle, uplo, n, A, lda, Workspace, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSpotrf cusolverDnSpotrf


#undef cusolverDnDpotrf
cusolverStatus_t cusolverDnDpotrf(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, double * Workspace, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDpotrf) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDpotrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDpotrf", kApiTypeCuSolver);

    lretval = lcusolverDnDpotrf(handle, uplo, n, A, lda, Workspace, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDpotrf cusolverDnDpotrf


#undef cusolverDnCpotrf
cusolverStatus_t cusolverDnCpotrf(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, cuComplex * Workspace, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCpotrf) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCpotrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCpotrf", kApiTypeCuSolver);

    lretval = lcusolverDnCpotrf(handle, uplo, n, A, lda, Workspace, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCpotrf cusolverDnCpotrf


#undef cusolverDnZpotrf
cusolverStatus_t cusolverDnZpotrf(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, cuDoubleComplex * Workspace, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZpotrf) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZpotrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZpotrf", kApiTypeCuSolver);

    lretval = lcusolverDnZpotrf(handle, uplo, n, A, lda, Workspace, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZpotrf cusolverDnZpotrf


#undef cusolverDnSpotrs
cusolverStatus_t cusolverDnSpotrs(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, float const * A, int lda, float * B, int ldb, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSpotrs) (cusolverDnHandle_t, cublasFillMode_t, int, int, float const *, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, int, float const *, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSpotrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSpotrs", kApiTypeCuSolver);

    lretval = lcusolverDnSpotrs(handle, uplo, n, nrhs, A, lda, B, ldb, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSpotrs cusolverDnSpotrs


#undef cusolverDnDpotrs
cusolverStatus_t cusolverDnDpotrs(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, double const * A, int lda, double * B, int ldb, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDpotrs) (cusolverDnHandle_t, cublasFillMode_t, int, int, double const *, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, int, double const *, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDpotrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDpotrs", kApiTypeCuSolver);

    lretval = lcusolverDnDpotrs(handle, uplo, n, nrhs, A, lda, B, ldb, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDpotrs cusolverDnDpotrs


#undef cusolverDnCpotrs
cusolverStatus_t cusolverDnCpotrs(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, cuComplex const * A, int lda, cuComplex * B, int ldb, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCpotrs) (cusolverDnHandle_t, cublasFillMode_t, int, int, cuComplex const *, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, int, cuComplex const *, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCpotrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCpotrs", kApiTypeCuSolver);

    lretval = lcusolverDnCpotrs(handle, uplo, n, nrhs, A, lda, B, ldb, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCpotrs cusolverDnCpotrs


#undef cusolverDnZpotrs
cusolverStatus_t cusolverDnZpotrs(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, cuDoubleComplex const * A, int lda, cuDoubleComplex * B, int ldb, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZpotrs) (cusolverDnHandle_t, cublasFillMode_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZpotrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZpotrs", kApiTypeCuSolver);

    lretval = lcusolverDnZpotrs(handle, uplo, n, nrhs, A, lda, B, ldb, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZpotrs cusolverDnZpotrs


#undef cusolverDnSpotrfBatched
cusolverStatus_t cusolverDnSpotrfBatched(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * * Aarray, int lda, int * infoArray, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSpotrfBatched) (cusolverDnHandle_t, cublasFillMode_t, int, float * *, int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float * *, int, int *, int))dlsym(RTLD_NEXT, "cusolverDnSpotrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSpotrfBatched", kApiTypeCuSolver);

    lretval = lcusolverDnSpotrfBatched(handle, uplo, n, Aarray, lda, infoArray, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSpotrfBatched cusolverDnSpotrfBatched


#undef cusolverDnDpotrfBatched
cusolverStatus_t cusolverDnDpotrfBatched(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * * Aarray, int lda, int * infoArray, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDpotrfBatched) (cusolverDnHandle_t, cublasFillMode_t, int, double * *, int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double * *, int, int *, int))dlsym(RTLD_NEXT, "cusolverDnDpotrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDpotrfBatched", kApiTypeCuSolver);

    lretval = lcusolverDnDpotrfBatched(handle, uplo, n, Aarray, lda, infoArray, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDpotrfBatched cusolverDnDpotrfBatched


#undef cusolverDnCpotrfBatched
cusolverStatus_t cusolverDnCpotrfBatched(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * * Aarray, int lda, int * infoArray, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCpotrfBatched) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex * *, int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex * *, int, int *, int))dlsym(RTLD_NEXT, "cusolverDnCpotrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCpotrfBatched", kApiTypeCuSolver);

    lretval = lcusolverDnCpotrfBatched(handle, uplo, n, Aarray, lda, infoArray, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCpotrfBatched cusolverDnCpotrfBatched


#undef cusolverDnZpotrfBatched
cusolverStatus_t cusolverDnZpotrfBatched(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * * Aarray, int lda, int * infoArray, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZpotrfBatched) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex * *, int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex * *, int, int *, int))dlsym(RTLD_NEXT, "cusolverDnZpotrfBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZpotrfBatched", kApiTypeCuSolver);

    lretval = lcusolverDnZpotrfBatched(handle, uplo, n, Aarray, lda, infoArray, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZpotrfBatched cusolverDnZpotrfBatched


#undef cusolverDnSpotrsBatched
cusolverStatus_t cusolverDnSpotrsBatched(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, float * * A, int lda, float * * B, int ldb, int * d_info, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSpotrsBatched) (cusolverDnHandle_t, cublasFillMode_t, int, int, float * *, int, float * *, int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, int, float * *, int, float * *, int, int *, int))dlsym(RTLD_NEXT, "cusolverDnSpotrsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSpotrsBatched", kApiTypeCuSolver);

    lretval = lcusolverDnSpotrsBatched(handle, uplo, n, nrhs, A, lda, B, ldb, d_info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSpotrsBatched cusolverDnSpotrsBatched


#undef cusolverDnDpotrsBatched
cusolverStatus_t cusolverDnDpotrsBatched(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, double * * A, int lda, double * * B, int ldb, int * d_info, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDpotrsBatched) (cusolverDnHandle_t, cublasFillMode_t, int, int, double * *, int, double * *, int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, int, double * *, int, double * *, int, int *, int))dlsym(RTLD_NEXT, "cusolverDnDpotrsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDpotrsBatched", kApiTypeCuSolver);

    lretval = lcusolverDnDpotrsBatched(handle, uplo, n, nrhs, A, lda, B, ldb, d_info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDpotrsBatched cusolverDnDpotrsBatched


#undef cusolverDnCpotrsBatched
cusolverStatus_t cusolverDnCpotrsBatched(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, cuComplex * * A, int lda, cuComplex * * B, int ldb, int * d_info, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCpotrsBatched) (cusolverDnHandle_t, cublasFillMode_t, int, int, cuComplex * *, int, cuComplex * *, int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, int, cuComplex * *, int, cuComplex * *, int, int *, int))dlsym(RTLD_NEXT, "cusolverDnCpotrsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCpotrsBatched", kApiTypeCuSolver);

    lretval = lcusolverDnCpotrsBatched(handle, uplo, n, nrhs, A, lda, B, ldb, d_info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCpotrsBatched cusolverDnCpotrsBatched


#undef cusolverDnZpotrsBatched
cusolverStatus_t cusolverDnZpotrsBatched(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, cuDoubleComplex * * A, int lda, cuDoubleComplex * * B, int ldb, int * d_info, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZpotrsBatched) (cusolverDnHandle_t, cublasFillMode_t, int, int, cuDoubleComplex * *, int, cuDoubleComplex * *, int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, int, cuDoubleComplex * *, int, cuDoubleComplex * *, int, int *, int))dlsym(RTLD_NEXT, "cusolverDnZpotrsBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZpotrsBatched", kApiTypeCuSolver);

    lretval = lcusolverDnZpotrsBatched(handle, uplo, n, nrhs, A, lda, B, ldb, d_info, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZpotrsBatched cusolverDnZpotrsBatched


#undef cusolverDnSpotri_bufferSize
cusolverStatus_t cusolverDnSpotri_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSpotri_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSpotri_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSpotri_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSpotri_bufferSize(handle, uplo, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSpotri_bufferSize cusolverDnSpotri_bufferSize


#undef cusolverDnDpotri_bufferSize
cusolverStatus_t cusolverDnDpotri_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDpotri_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDpotri_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDpotri_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDpotri_bufferSize(handle, uplo, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDpotri_bufferSize cusolverDnDpotri_bufferSize


#undef cusolverDnCpotri_bufferSize
cusolverStatus_t cusolverDnCpotri_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCpotri_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCpotri_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCpotri_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCpotri_bufferSize(handle, uplo, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCpotri_bufferSize cusolverDnCpotri_bufferSize


#undef cusolverDnZpotri_bufferSize
cusolverStatus_t cusolverDnZpotri_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZpotri_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZpotri_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZpotri_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZpotri_bufferSize(handle, uplo, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZpotri_bufferSize cusolverDnZpotri_bufferSize


#undef cusolverDnSpotri
cusolverStatus_t cusolverDnSpotri(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, float * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSpotri) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSpotri");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSpotri", kApiTypeCuSolver);

    lretval = lcusolverDnSpotri(handle, uplo, n, A, lda, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSpotri cusolverDnSpotri


#undef cusolverDnDpotri
cusolverStatus_t cusolverDnDpotri(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, double * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDpotri) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDpotri");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDpotri", kApiTypeCuSolver);

    lretval = lcusolverDnDpotri(handle, uplo, n, A, lda, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDpotri cusolverDnDpotri


#undef cusolverDnCpotri
cusolverStatus_t cusolverDnCpotri(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, cuComplex * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCpotri) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCpotri");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCpotri", kApiTypeCuSolver);

    lretval = lcusolverDnCpotri(handle, uplo, n, A, lda, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCpotri cusolverDnCpotri


#undef cusolverDnZpotri
cusolverStatus_t cusolverDnZpotri(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, cuDoubleComplex * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZpotri) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZpotri");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZpotri", kApiTypeCuSolver);

    lretval = lcusolverDnZpotri(handle, uplo, n, A, lda, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZpotri cusolverDnZpotri


#undef cusolverDnSlauum_bufferSize
cusolverStatus_t cusolverDnSlauum_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSlauum_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSlauum_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSlauum_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSlauum_bufferSize(handle, uplo, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSlauum_bufferSize cusolverDnSlauum_bufferSize


#undef cusolverDnDlauum_bufferSize
cusolverStatus_t cusolverDnDlauum_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDlauum_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDlauum_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDlauum_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDlauum_bufferSize(handle, uplo, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDlauum_bufferSize cusolverDnDlauum_bufferSize


#undef cusolverDnClauum_bufferSize
cusolverStatus_t cusolverDnClauum_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnClauum_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnClauum_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnClauum_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnClauum_bufferSize(handle, uplo, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnClauum_bufferSize cusolverDnClauum_bufferSize


#undef cusolverDnZlauum_bufferSize
cusolverStatus_t cusolverDnZlauum_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZlauum_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZlauum_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZlauum_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZlauum_bufferSize(handle, uplo, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZlauum_bufferSize cusolverDnZlauum_bufferSize


#undef cusolverDnSlauum
cusolverStatus_t cusolverDnSlauum(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, float * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSlauum) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSlauum");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSlauum", kApiTypeCuSolver);

    lretval = lcusolverDnSlauum(handle, uplo, n, A, lda, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSlauum cusolverDnSlauum


#undef cusolverDnDlauum
cusolverStatus_t cusolverDnDlauum(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, double * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDlauum) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDlauum");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDlauum", kApiTypeCuSolver);

    lretval = lcusolverDnDlauum(handle, uplo, n, A, lda, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDlauum cusolverDnDlauum


#undef cusolverDnClauum
cusolverStatus_t cusolverDnClauum(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, cuComplex * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnClauum) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnClauum");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnClauum", kApiTypeCuSolver);

    lretval = lcusolverDnClauum(handle, uplo, n, A, lda, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnClauum cusolverDnClauum


#undef cusolverDnZlauum
cusolverStatus_t cusolverDnZlauum(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, cuDoubleComplex * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZlauum) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZlauum");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZlauum", kApiTypeCuSolver);

    lretval = lcusolverDnZlauum(handle, uplo, n, A, lda, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZlauum cusolverDnZlauum


#undef cusolverDnSgetrf_bufferSize
cusolverStatus_t cusolverDnSgetrf_bufferSize(cusolverDnHandle_t handle, int m, int n, float * A, int lda, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgetrf_bufferSize) (cusolverDnHandle_t, int, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSgetrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgetrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSgetrf_bufferSize(handle, m, n, A, lda, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgetrf_bufferSize cusolverDnSgetrf_bufferSize


#undef cusolverDnDgetrf_bufferSize
cusolverStatus_t cusolverDnDgetrf_bufferSize(cusolverDnHandle_t handle, int m, int n, double * A, int lda, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgetrf_bufferSize) (cusolverDnHandle_t, int, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDgetrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgetrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDgetrf_bufferSize(handle, m, n, A, lda, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgetrf_bufferSize cusolverDnDgetrf_bufferSize


#undef cusolverDnCgetrf_bufferSize
cusolverStatus_t cusolverDnCgetrf_bufferSize(cusolverDnHandle_t handle, int m, int n, cuComplex * A, int lda, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgetrf_bufferSize) (cusolverDnHandle_t, int, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCgetrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgetrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCgetrf_bufferSize(handle, m, n, A, lda, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgetrf_bufferSize cusolverDnCgetrf_bufferSize


#undef cusolverDnZgetrf_bufferSize
cusolverStatus_t cusolverDnZgetrf_bufferSize(cusolverDnHandle_t handle, int m, int n, cuDoubleComplex * A, int lda, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgetrf_bufferSize) (cusolverDnHandle_t, int, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZgetrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgetrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZgetrf_bufferSize(handle, m, n, A, lda, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgetrf_bufferSize cusolverDnZgetrf_bufferSize


#undef cusolverDnSgetrf
cusolverStatus_t cusolverDnSgetrf(cusolverDnHandle_t handle, int m, int n, float * A, int lda, float * Workspace, int * devIpiv, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgetrf) (cusolverDnHandle_t, int, int, float *, int, float *, int *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, float *, int, float *, int *, int *))dlsym(RTLD_NEXT, "cusolverDnSgetrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgetrf", kApiTypeCuSolver);

    lretval = lcusolverDnSgetrf(handle, m, n, A, lda, Workspace, devIpiv, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgetrf cusolverDnSgetrf


#undef cusolverDnDgetrf
cusolverStatus_t cusolverDnDgetrf(cusolverDnHandle_t handle, int m, int n, double * A, int lda, double * Workspace, int * devIpiv, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgetrf) (cusolverDnHandle_t, int, int, double *, int, double *, int *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, double *, int, double *, int *, int *))dlsym(RTLD_NEXT, "cusolverDnDgetrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgetrf", kApiTypeCuSolver);

    lretval = lcusolverDnDgetrf(handle, m, n, A, lda, Workspace, devIpiv, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgetrf cusolverDnDgetrf


#undef cusolverDnCgetrf
cusolverStatus_t cusolverDnCgetrf(cusolverDnHandle_t handle, int m, int n, cuComplex * A, int lda, cuComplex * Workspace, int * devIpiv, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgetrf) (cusolverDnHandle_t, int, int, cuComplex *, int, cuComplex *, int *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuComplex *, int, cuComplex *, int *, int *))dlsym(RTLD_NEXT, "cusolverDnCgetrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgetrf", kApiTypeCuSolver);

    lretval = lcusolverDnCgetrf(handle, m, n, A, lda, Workspace, devIpiv, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgetrf cusolverDnCgetrf


#undef cusolverDnZgetrf
cusolverStatus_t cusolverDnZgetrf(cusolverDnHandle_t handle, int m, int n, cuDoubleComplex * A, int lda, cuDoubleComplex * Workspace, int * devIpiv, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgetrf) (cusolverDnHandle_t, int, int, cuDoubleComplex *, int, cuDoubleComplex *, int *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuDoubleComplex *, int, cuDoubleComplex *, int *, int *))dlsym(RTLD_NEXT, "cusolverDnZgetrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgetrf", kApiTypeCuSolver);

    lretval = lcusolverDnZgetrf(handle, m, n, A, lda, Workspace, devIpiv, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgetrf cusolverDnZgetrf


#undef cusolverDnSlaswp
cusolverStatus_t cusolverDnSlaswp(cusolverDnHandle_t handle, int n, float * A, int lda, int k1, int k2, int const * devIpiv, int incx){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSlaswp) (cusolverDnHandle_t, int, float *, int, int, int, int const *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, float *, int, int, int, int const *, int))dlsym(RTLD_NEXT, "cusolverDnSlaswp");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSlaswp", kApiTypeCuSolver);

    lretval = lcusolverDnSlaswp(handle, n, A, lda, k1, k2, devIpiv, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSlaswp cusolverDnSlaswp


#undef cusolverDnDlaswp
cusolverStatus_t cusolverDnDlaswp(cusolverDnHandle_t handle, int n, double * A, int lda, int k1, int k2, int const * devIpiv, int incx){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDlaswp) (cusolverDnHandle_t, int, double *, int, int, int, int const *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, double *, int, int, int, int const *, int))dlsym(RTLD_NEXT, "cusolverDnDlaswp");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDlaswp", kApiTypeCuSolver);

    lretval = lcusolverDnDlaswp(handle, n, A, lda, k1, k2, devIpiv, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDlaswp cusolverDnDlaswp


#undef cusolverDnClaswp
cusolverStatus_t cusolverDnClaswp(cusolverDnHandle_t handle, int n, cuComplex * A, int lda, int k1, int k2, int const * devIpiv, int incx){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnClaswp) (cusolverDnHandle_t, int, cuComplex *, int, int, int, int const *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, cuComplex *, int, int, int, int const *, int))dlsym(RTLD_NEXT, "cusolverDnClaswp");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnClaswp", kApiTypeCuSolver);

    lretval = lcusolverDnClaswp(handle, n, A, lda, k1, k2, devIpiv, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnClaswp cusolverDnClaswp


#undef cusolverDnZlaswp
cusolverStatus_t cusolverDnZlaswp(cusolverDnHandle_t handle, int n, cuDoubleComplex * A, int lda, int k1, int k2, int const * devIpiv, int incx){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZlaswp) (cusolverDnHandle_t, int, cuDoubleComplex *, int, int, int, int const *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, cuDoubleComplex *, int, int, int, int const *, int))dlsym(RTLD_NEXT, "cusolverDnZlaswp");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZlaswp", kApiTypeCuSolver);

    lretval = lcusolverDnZlaswp(handle, n, A, lda, k1, k2, devIpiv, incx);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZlaswp cusolverDnZlaswp


#undef cusolverDnSgetrs
cusolverStatus_t cusolverDnSgetrs(cusolverDnHandle_t handle, cublasOperation_t trans, int n, int nrhs, float const * A, int lda, int const * devIpiv, float * B, int ldb, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgetrs) (cusolverDnHandle_t, cublasOperation_t, int, int, float const *, int, int const *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasOperation_t, int, int, float const *, int, int const *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSgetrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgetrs", kApiTypeCuSolver);

    lretval = lcusolverDnSgetrs(handle, trans, n, nrhs, A, lda, devIpiv, B, ldb, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgetrs cusolverDnSgetrs


#undef cusolverDnDgetrs
cusolverStatus_t cusolverDnDgetrs(cusolverDnHandle_t handle, cublasOperation_t trans, int n, int nrhs, double const * A, int lda, int const * devIpiv, double * B, int ldb, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgetrs) (cusolverDnHandle_t, cublasOperation_t, int, int, double const *, int, int const *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasOperation_t, int, int, double const *, int, int const *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDgetrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgetrs", kApiTypeCuSolver);

    lretval = lcusolverDnDgetrs(handle, trans, n, nrhs, A, lda, devIpiv, B, ldb, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgetrs cusolverDnDgetrs


#undef cusolverDnCgetrs
cusolverStatus_t cusolverDnCgetrs(cusolverDnHandle_t handle, cublasOperation_t trans, int n, int nrhs, cuComplex const * A, int lda, int const * devIpiv, cuComplex * B, int ldb, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgetrs) (cusolverDnHandle_t, cublasOperation_t, int, int, cuComplex const *, int, int const *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasOperation_t, int, int, cuComplex const *, int, int const *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCgetrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgetrs", kApiTypeCuSolver);

    lretval = lcusolverDnCgetrs(handle, trans, n, nrhs, A, lda, devIpiv, B, ldb, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgetrs cusolverDnCgetrs


#undef cusolverDnZgetrs
cusolverStatus_t cusolverDnZgetrs(cusolverDnHandle_t handle, cublasOperation_t trans, int n, int nrhs, cuDoubleComplex const * A, int lda, int const * devIpiv, cuDoubleComplex * B, int ldb, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgetrs) (cusolverDnHandle_t, cublasOperation_t, int, int, cuDoubleComplex const *, int, int const *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasOperation_t, int, int, cuDoubleComplex const *, int, int const *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZgetrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgetrs", kApiTypeCuSolver);

    lretval = lcusolverDnZgetrs(handle, trans, n, nrhs, A, lda, devIpiv, B, ldb, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgetrs cusolverDnZgetrs


#undef cusolverDnSgeqrf_bufferSize
cusolverStatus_t cusolverDnSgeqrf_bufferSize(cusolverDnHandle_t handle, int m, int n, float * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgeqrf_bufferSize) (cusolverDnHandle_t, int, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSgeqrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgeqrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSgeqrf_bufferSize(handle, m, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgeqrf_bufferSize cusolverDnSgeqrf_bufferSize


#undef cusolverDnDgeqrf_bufferSize
cusolverStatus_t cusolverDnDgeqrf_bufferSize(cusolverDnHandle_t handle, int m, int n, double * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgeqrf_bufferSize) (cusolverDnHandle_t, int, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDgeqrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgeqrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDgeqrf_bufferSize(handle, m, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgeqrf_bufferSize cusolverDnDgeqrf_bufferSize


#undef cusolverDnCgeqrf_bufferSize
cusolverStatus_t cusolverDnCgeqrf_bufferSize(cusolverDnHandle_t handle, int m, int n, cuComplex * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgeqrf_bufferSize) (cusolverDnHandle_t, int, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCgeqrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgeqrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCgeqrf_bufferSize(handle, m, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgeqrf_bufferSize cusolverDnCgeqrf_bufferSize


#undef cusolverDnZgeqrf_bufferSize
cusolverStatus_t cusolverDnZgeqrf_bufferSize(cusolverDnHandle_t handle, int m, int n, cuDoubleComplex * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgeqrf_bufferSize) (cusolverDnHandle_t, int, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZgeqrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgeqrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZgeqrf_bufferSize(handle, m, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgeqrf_bufferSize cusolverDnZgeqrf_bufferSize


#undef cusolverDnSgeqrf
cusolverStatus_t cusolverDnSgeqrf(cusolverDnHandle_t handle, int m, int n, float * A, int lda, float * TAU, float * Workspace, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgeqrf) (cusolverDnHandle_t, int, int, float *, int, float *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, float *, int, float *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSgeqrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgeqrf", kApiTypeCuSolver);

    lretval = lcusolverDnSgeqrf(handle, m, n, A, lda, TAU, Workspace, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgeqrf cusolverDnSgeqrf


#undef cusolverDnDgeqrf
cusolverStatus_t cusolverDnDgeqrf(cusolverDnHandle_t handle, int m, int n, double * A, int lda, double * TAU, double * Workspace, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgeqrf) (cusolverDnHandle_t, int, int, double *, int, double *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, double *, int, double *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDgeqrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgeqrf", kApiTypeCuSolver);

    lretval = lcusolverDnDgeqrf(handle, m, n, A, lda, TAU, Workspace, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgeqrf cusolverDnDgeqrf


#undef cusolverDnCgeqrf
cusolverStatus_t cusolverDnCgeqrf(cusolverDnHandle_t handle, int m, int n, cuComplex * A, int lda, cuComplex * TAU, cuComplex * Workspace, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgeqrf) (cusolverDnHandle_t, int, int, cuComplex *, int, cuComplex *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuComplex *, int, cuComplex *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCgeqrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgeqrf", kApiTypeCuSolver);

    lretval = lcusolverDnCgeqrf(handle, m, n, A, lda, TAU, Workspace, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgeqrf cusolverDnCgeqrf


#undef cusolverDnZgeqrf
cusolverStatus_t cusolverDnZgeqrf(cusolverDnHandle_t handle, int m, int n, cuDoubleComplex * A, int lda, cuDoubleComplex * TAU, cuDoubleComplex * Workspace, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgeqrf) (cusolverDnHandle_t, int, int, cuDoubleComplex *, int, cuDoubleComplex *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuDoubleComplex *, int, cuDoubleComplex *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZgeqrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgeqrf", kApiTypeCuSolver);

    lretval = lcusolverDnZgeqrf(handle, m, n, A, lda, TAU, Workspace, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgeqrf cusolverDnZgeqrf


#undef cusolverDnSorgqr_bufferSize
cusolverStatus_t cusolverDnSorgqr_bufferSize(cusolverDnHandle_t handle, int m, int n, int k, float const * A, int lda, float const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSorgqr_bufferSize) (cusolverDnHandle_t, int, int, int, float const *, int, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int, float const *, int, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnSorgqr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSorgqr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSorgqr_bufferSize(handle, m, n, k, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSorgqr_bufferSize cusolverDnSorgqr_bufferSize


#undef cusolverDnDorgqr_bufferSize
cusolverStatus_t cusolverDnDorgqr_bufferSize(cusolverDnHandle_t handle, int m, int n, int k, double const * A, int lda, double const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDorgqr_bufferSize) (cusolverDnHandle_t, int, int, int, double const *, int, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int, double const *, int, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnDorgqr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDorgqr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDorgqr_bufferSize(handle, m, n, k, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDorgqr_bufferSize cusolverDnDorgqr_bufferSize


#undef cusolverDnCungqr_bufferSize
cusolverStatus_t cusolverDnCungqr_bufferSize(cusolverDnHandle_t handle, int m, int n, int k, cuComplex const * A, int lda, cuComplex const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCungqr_bufferSize) (cusolverDnHandle_t, int, int, int, cuComplex const *, int, cuComplex const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int, cuComplex const *, int, cuComplex const *, int *))dlsym(RTLD_NEXT, "cusolverDnCungqr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCungqr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCungqr_bufferSize(handle, m, n, k, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCungqr_bufferSize cusolverDnCungqr_bufferSize


#undef cusolverDnZungqr_bufferSize
cusolverStatus_t cusolverDnZungqr_bufferSize(cusolverDnHandle_t handle, int m, int n, int k, cuDoubleComplex const * A, int lda, cuDoubleComplex const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZungqr_bufferSize) (cusolverDnHandle_t, int, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int *))dlsym(RTLD_NEXT, "cusolverDnZungqr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZungqr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZungqr_bufferSize(handle, m, n, k, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZungqr_bufferSize cusolverDnZungqr_bufferSize


#undef cusolverDnSorgqr
cusolverStatus_t cusolverDnSorgqr(cusolverDnHandle_t handle, int m, int n, int k, float * A, int lda, float const * tau, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSorgqr) (cusolverDnHandle_t, int, int, int, float *, int, float const *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int, float *, int, float const *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSorgqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSorgqr", kApiTypeCuSolver);

    lretval = lcusolverDnSorgqr(handle, m, n, k, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSorgqr cusolverDnSorgqr


#undef cusolverDnDorgqr
cusolverStatus_t cusolverDnDorgqr(cusolverDnHandle_t handle, int m, int n, int k, double * A, int lda, double const * tau, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDorgqr) (cusolverDnHandle_t, int, int, int, double *, int, double const *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int, double *, int, double const *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDorgqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDorgqr", kApiTypeCuSolver);

    lretval = lcusolverDnDorgqr(handle, m, n, k, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDorgqr cusolverDnDorgqr


#undef cusolverDnCungqr
cusolverStatus_t cusolverDnCungqr(cusolverDnHandle_t handle, int m, int n, int k, cuComplex * A, int lda, cuComplex const * tau, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCungqr) (cusolverDnHandle_t, int, int, int, cuComplex *, int, cuComplex const *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int, cuComplex *, int, cuComplex const *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCungqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCungqr", kApiTypeCuSolver);

    lretval = lcusolverDnCungqr(handle, m, n, k, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCungqr cusolverDnCungqr


#undef cusolverDnZungqr
cusolverStatus_t cusolverDnZungqr(cusolverDnHandle_t handle, int m, int n, int k, cuDoubleComplex * A, int lda, cuDoubleComplex const * tau, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZungqr) (cusolverDnHandle_t, int, int, int, cuDoubleComplex *, int, cuDoubleComplex const *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int, cuDoubleComplex *, int, cuDoubleComplex const *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZungqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZungqr", kApiTypeCuSolver);

    lretval = lcusolverDnZungqr(handle, m, n, k, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZungqr cusolverDnZungqr


#undef cusolverDnSormqr_bufferSize
cusolverStatus_t cusolverDnSormqr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, cublasOperation_t trans, int m, int n, int k, float const * A, int lda, float const * tau, float const * C, int ldc, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSormqr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, float const *, int, float const *, float const *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, float const *, int, float const *, float const *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSormqr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSormqr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSormqr_bufferSize(handle, side, trans, m, n, k, A, lda, tau, C, ldc, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSormqr_bufferSize cusolverDnSormqr_bufferSize


#undef cusolverDnDormqr_bufferSize
cusolverStatus_t cusolverDnDormqr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, cublasOperation_t trans, int m, int n, int k, double const * A, int lda, double const * tau, double const * C, int ldc, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDormqr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, double const *, int, double const *, double const *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, double const *, int, double const *, double const *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDormqr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDormqr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDormqr_bufferSize(handle, side, trans, m, n, k, A, lda, tau, C, ldc, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDormqr_bufferSize cusolverDnDormqr_bufferSize


#undef cusolverDnCunmqr_bufferSize
cusolverStatus_t cusolverDnCunmqr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, cublasOperation_t trans, int m, int n, int k, cuComplex const * A, int lda, cuComplex const * tau, cuComplex const * C, int ldc, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCunmqr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, cuComplex const *, int, cuComplex const *, cuComplex const *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, cuComplex const *, int, cuComplex const *, cuComplex const *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCunmqr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCunmqr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCunmqr_bufferSize(handle, side, trans, m, n, k, A, lda, tau, C, ldc, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCunmqr_bufferSize cusolverDnCunmqr_bufferSize


#undef cusolverDnZunmqr_bufferSize
cusolverStatus_t cusolverDnZunmqr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, cublasOperation_t trans, int m, int n, int k, cuDoubleComplex const * A, int lda, cuDoubleComplex const * tau, cuDoubleComplex const * C, int ldc, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZunmqr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex const *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex const *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZunmqr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZunmqr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZunmqr_bufferSize(handle, side, trans, m, n, k, A, lda, tau, C, ldc, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZunmqr_bufferSize cusolverDnZunmqr_bufferSize


#undef cusolverDnSormqr
cusolverStatus_t cusolverDnSormqr(cusolverDnHandle_t handle, cublasSideMode_t side, cublasOperation_t trans, int m, int n, int k, float const * A, int lda, float const * tau, float * C, int ldc, float * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSormqr) (cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, float const *, int, float const *, float *, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, float const *, int, float const *, float *, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSormqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSormqr", kApiTypeCuSolver);

    lretval = lcusolverDnSormqr(handle, side, trans, m, n, k, A, lda, tau, C, ldc, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSormqr cusolverDnSormqr


#undef cusolverDnDormqr
cusolverStatus_t cusolverDnDormqr(cusolverDnHandle_t handle, cublasSideMode_t side, cublasOperation_t trans, int m, int n, int k, double const * A, int lda, double const * tau, double * C, int ldc, double * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDormqr) (cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, double const *, int, double const *, double *, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, double const *, int, double const *, double *, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDormqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDormqr", kApiTypeCuSolver);

    lretval = lcusolverDnDormqr(handle, side, trans, m, n, k, A, lda, tau, C, ldc, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDormqr cusolverDnDormqr


#undef cusolverDnCunmqr
cusolverStatus_t cusolverDnCunmqr(cusolverDnHandle_t handle, cublasSideMode_t side, cublasOperation_t trans, int m, int n, int k, cuComplex const * A, int lda, cuComplex const * tau, cuComplex * C, int ldc, cuComplex * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCunmqr) (cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, cuComplex const *, int, cuComplex const *, cuComplex *, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, cuComplex const *, int, cuComplex const *, cuComplex *, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCunmqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCunmqr", kApiTypeCuSolver);

    lretval = lcusolverDnCunmqr(handle, side, trans, m, n, k, A, lda, tau, C, ldc, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCunmqr cusolverDnCunmqr


#undef cusolverDnZunmqr
cusolverStatus_t cusolverDnZunmqr(cusolverDnHandle_t handle, cublasSideMode_t side, cublasOperation_t trans, int m, int n, int k, cuDoubleComplex const * A, int lda, cuDoubleComplex const * tau, cuDoubleComplex * C, int ldc, cuDoubleComplex * work, int lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZunmqr) (cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasOperation_t, int, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex *, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZunmqr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZunmqr", kApiTypeCuSolver);

    lretval = lcusolverDnZunmqr(handle, side, trans, m, n, k, A, lda, tau, C, ldc, work, lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZunmqr cusolverDnZunmqr


#undef cusolverDnSsytrf_bufferSize
cusolverStatus_t cusolverDnSsytrf_bufferSize(cusolverDnHandle_t handle, int n, float * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsytrf_bufferSize) (cusolverDnHandle_t, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSsytrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsytrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsytrf_bufferSize(handle, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsytrf_bufferSize cusolverDnSsytrf_bufferSize


#undef cusolverDnDsytrf_bufferSize
cusolverStatus_t cusolverDnDsytrf_bufferSize(cusolverDnHandle_t handle, int n, double * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsytrf_bufferSize) (cusolverDnHandle_t, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDsytrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsytrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsytrf_bufferSize(handle, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsytrf_bufferSize cusolverDnDsytrf_bufferSize


#undef cusolverDnCsytrf_bufferSize
cusolverStatus_t cusolverDnCsytrf_bufferSize(cusolverDnHandle_t handle, int n, cuComplex * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCsytrf_bufferSize) (cusolverDnHandle_t, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCsytrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCsytrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCsytrf_bufferSize(handle, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCsytrf_bufferSize cusolverDnCsytrf_bufferSize


#undef cusolverDnZsytrf_bufferSize
cusolverStatus_t cusolverDnZsytrf_bufferSize(cusolverDnHandle_t handle, int n, cuDoubleComplex * A, int lda, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZsytrf_bufferSize) (cusolverDnHandle_t, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZsytrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZsytrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZsytrf_bufferSize(handle, n, A, lda, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZsytrf_bufferSize cusolverDnZsytrf_bufferSize


#undef cusolverDnSsytrf
cusolverStatus_t cusolverDnSsytrf(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, int * ipiv, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsytrf) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSsytrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsytrf", kApiTypeCuSolver);

    lretval = lcusolverDnSsytrf(handle, uplo, n, A, lda, ipiv, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsytrf cusolverDnSsytrf


#undef cusolverDnDsytrf
cusolverStatus_t cusolverDnDsytrf(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, int * ipiv, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsytrf) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDsytrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsytrf", kApiTypeCuSolver);

    lretval = lcusolverDnDsytrf(handle, uplo, n, A, lda, ipiv, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsytrf cusolverDnDsytrf


#undef cusolverDnCsytrf
cusolverStatus_t cusolverDnCsytrf(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, int * ipiv, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCsytrf) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCsytrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCsytrf", kApiTypeCuSolver);

    lretval = lcusolverDnCsytrf(handle, uplo, n, A, lda, ipiv, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCsytrf cusolverDnCsytrf


#undef cusolverDnZsytrf
cusolverStatus_t cusolverDnZsytrf(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, int * ipiv, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZsytrf) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZsytrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZsytrf", kApiTypeCuSolver);

    lretval = lcusolverDnZsytrf(handle, uplo, n, A, lda, ipiv, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZsytrf cusolverDnZsytrf


#undef cusolverDnXsytrs_bufferSize
cusolverStatus_t cusolverDnXsytrs_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int64_t n, int64_t nrhs, cudaDataType dataTypeA, void const * A, int64_t lda, int64_t const * ipiv, cudaDataType dataTypeB, void * B, int64_t ldb, size_t * workspaceInBytesOnDevice, size_t * workspaceInBytesOnHost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsytrs_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int64_t, int64_t, cudaDataType, void const *, int64_t, int64_t const *, cudaDataType, void *, int64_t, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int64_t, int64_t, cudaDataType, void const *, int64_t, int64_t const *, cudaDataType, void *, int64_t, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverDnXsytrs_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsytrs_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnXsytrs_bufferSize(handle, uplo, n, nrhs, dataTypeA, A, lda, ipiv, dataTypeB, B, ldb, workspaceInBytesOnDevice, workspaceInBytesOnHost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsytrs_bufferSize cusolverDnXsytrs_bufferSize


#undef cusolverDnXsytrs
cusolverStatus_t cusolverDnXsytrs(cusolverDnHandle_t handle, cublasFillMode_t uplo, int64_t n, int64_t nrhs, cudaDataType dataTypeA, void const * A, int64_t lda, int64_t const * ipiv, cudaDataType dataTypeB, void * B, int64_t ldb, void * bufferOnDevice, size_t workspaceInBytesOnDevice, void * bufferOnHost, size_t workspaceInBytesOnHost, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsytrs) (cusolverDnHandle_t, cublasFillMode_t, int64_t, int64_t, cudaDataType, void const *, int64_t, int64_t const *, cudaDataType, void *, int64_t, void *, size_t, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int64_t, int64_t, cudaDataType, void const *, int64_t, int64_t const *, cudaDataType, void *, int64_t, void *, size_t, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnXsytrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsytrs", kApiTypeCuSolver);

    lretval = lcusolverDnXsytrs(handle, uplo, n, nrhs, dataTypeA, A, lda, ipiv, dataTypeB, B, ldb, bufferOnDevice, workspaceInBytesOnDevice, bufferOnHost, workspaceInBytesOnHost, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsytrs cusolverDnXsytrs


#undef cusolverDnSsytri_bufferSize
cusolverStatus_t cusolverDnSsytri_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, int const * ipiv, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsytri_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int const *, int *))dlsym(RTLD_NEXT, "cusolverDnSsytri_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsytri_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsytri_bufferSize(handle, uplo, n, A, lda, ipiv, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsytri_bufferSize cusolverDnSsytri_bufferSize


#undef cusolverDnDsytri_bufferSize
cusolverStatus_t cusolverDnDsytri_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, int const * ipiv, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsytri_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int const *, int *))dlsym(RTLD_NEXT, "cusolverDnDsytri_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsytri_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsytri_bufferSize(handle, uplo, n, A, lda, ipiv, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsytri_bufferSize cusolverDnDsytri_bufferSize


#undef cusolverDnCsytri_bufferSize
cusolverStatus_t cusolverDnCsytri_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, int const * ipiv, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCsytri_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int const *, int *))dlsym(RTLD_NEXT, "cusolverDnCsytri_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCsytri_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCsytri_bufferSize(handle, uplo, n, A, lda, ipiv, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCsytri_bufferSize cusolverDnCsytri_bufferSize


#undef cusolverDnZsytri_bufferSize
cusolverStatus_t cusolverDnZsytri_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, int const * ipiv, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZsytri_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int const *, int *))dlsym(RTLD_NEXT, "cusolverDnZsytri_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZsytri_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZsytri_bufferSize(handle, uplo, n, A, lda, ipiv, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZsytri_bufferSize cusolverDnZsytri_bufferSize


#undef cusolverDnSsytri
cusolverStatus_t cusolverDnSsytri(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, int const * ipiv, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsytri) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int const *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, int const *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSsytri");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsytri", kApiTypeCuSolver);

    lretval = lcusolverDnSsytri(handle, uplo, n, A, lda, ipiv, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsytri cusolverDnSsytri


#undef cusolverDnDsytri
cusolverStatus_t cusolverDnDsytri(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, int const * ipiv, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsytri) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int const *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, int const *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDsytri");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsytri", kApiTypeCuSolver);

    lretval = lcusolverDnDsytri(handle, uplo, n, A, lda, ipiv, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsytri cusolverDnDsytri


#undef cusolverDnCsytri
cusolverStatus_t cusolverDnCsytri(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, int const * ipiv, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCsytri) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int const *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, int const *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCsytri");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCsytri", kApiTypeCuSolver);

    lretval = lcusolverDnCsytri(handle, uplo, n, A, lda, ipiv, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCsytri cusolverDnCsytri


#undef cusolverDnZsytri
cusolverStatus_t cusolverDnZsytri(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, int const * ipiv, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZsytri) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int const *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, int const *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZsytri");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZsytri", kApiTypeCuSolver);

    lretval = lcusolverDnZsytri(handle, uplo, n, A, lda, ipiv, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZsytri cusolverDnZsytri


#undef cusolverDnSgebrd_bufferSize
cusolverStatus_t cusolverDnSgebrd_bufferSize(cusolverDnHandle_t handle, int m, int n, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgebrd_bufferSize) (cusolverDnHandle_t, int, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int *))dlsym(RTLD_NEXT, "cusolverDnSgebrd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgebrd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSgebrd_bufferSize(handle, m, n, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgebrd_bufferSize cusolverDnSgebrd_bufferSize


#undef cusolverDnDgebrd_bufferSize
cusolverStatus_t cusolverDnDgebrd_bufferSize(cusolverDnHandle_t handle, int m, int n, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgebrd_bufferSize) (cusolverDnHandle_t, int, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int *))dlsym(RTLD_NEXT, "cusolverDnDgebrd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgebrd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDgebrd_bufferSize(handle, m, n, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgebrd_bufferSize cusolverDnDgebrd_bufferSize


#undef cusolverDnCgebrd_bufferSize
cusolverStatus_t cusolverDnCgebrd_bufferSize(cusolverDnHandle_t handle, int m, int n, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgebrd_bufferSize) (cusolverDnHandle_t, int, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int *))dlsym(RTLD_NEXT, "cusolverDnCgebrd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgebrd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCgebrd_bufferSize(handle, m, n, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgebrd_bufferSize cusolverDnCgebrd_bufferSize


#undef cusolverDnZgebrd_bufferSize
cusolverStatus_t cusolverDnZgebrd_bufferSize(cusolverDnHandle_t handle, int m, int n, int * Lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgebrd_bufferSize) (cusolverDnHandle_t, int, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int *))dlsym(RTLD_NEXT, "cusolverDnZgebrd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgebrd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZgebrd_bufferSize(handle, m, n, Lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgebrd_bufferSize cusolverDnZgebrd_bufferSize


#undef cusolverDnSgebrd
cusolverStatus_t cusolverDnSgebrd(cusolverDnHandle_t handle, int m, int n, float * A, int lda, float * D, float * E, float * TAUQ, float * TAUP, float * Work, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgebrd) (cusolverDnHandle_t, int, int, float *, int, float *, float *, float *, float *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, float *, int, float *, float *, float *, float *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSgebrd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgebrd", kApiTypeCuSolver);

    lretval = lcusolverDnSgebrd(handle, m, n, A, lda, D, E, TAUQ, TAUP, Work, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgebrd cusolverDnSgebrd


#undef cusolverDnDgebrd
cusolverStatus_t cusolverDnDgebrd(cusolverDnHandle_t handle, int m, int n, double * A, int lda, double * D, double * E, double * TAUQ, double * TAUP, double * Work, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgebrd) (cusolverDnHandle_t, int, int, double *, int, double *, double *, double *, double *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, double *, int, double *, double *, double *, double *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDgebrd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgebrd", kApiTypeCuSolver);

    lretval = lcusolverDnDgebrd(handle, m, n, A, lda, D, E, TAUQ, TAUP, Work, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgebrd cusolverDnDgebrd


#undef cusolverDnCgebrd
cusolverStatus_t cusolverDnCgebrd(cusolverDnHandle_t handle, int m, int n, cuComplex * A, int lda, float * D, float * E, cuComplex * TAUQ, cuComplex * TAUP, cuComplex * Work, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgebrd) (cusolverDnHandle_t, int, int, cuComplex *, int, float *, float *, cuComplex *, cuComplex *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuComplex *, int, float *, float *, cuComplex *, cuComplex *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCgebrd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgebrd", kApiTypeCuSolver);

    lretval = lcusolverDnCgebrd(handle, m, n, A, lda, D, E, TAUQ, TAUP, Work, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgebrd cusolverDnCgebrd


#undef cusolverDnZgebrd
cusolverStatus_t cusolverDnZgebrd(cusolverDnHandle_t handle, int m, int n, cuDoubleComplex * A, int lda, double * D, double * E, cuDoubleComplex * TAUQ, cuDoubleComplex * TAUP, cuDoubleComplex * Work, int Lwork, int * devInfo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgebrd) (cusolverDnHandle_t, int, int, cuDoubleComplex *, int, double *, double *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, cuDoubleComplex *, int, double *, double *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZgebrd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgebrd", kApiTypeCuSolver);

    lretval = lcusolverDnZgebrd(handle, m, n, A, lda, D, E, TAUQ, TAUP, Work, Lwork, devInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgebrd cusolverDnZgebrd


#undef cusolverDnSorgbr_bufferSize
cusolverStatus_t cusolverDnSorgbr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, int m, int n, int k, float const * A, int lda, float const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSorgbr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, int, int, int, float const *, int, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, int, int, int, float const *, int, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnSorgbr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSorgbr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSorgbr_bufferSize(handle, side, m, n, k, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSorgbr_bufferSize cusolverDnSorgbr_bufferSize


#undef cusolverDnDorgbr_bufferSize
cusolverStatus_t cusolverDnDorgbr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, int m, int n, int k, double const * A, int lda, double const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDorgbr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, int, int, int, double const *, int, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, int, int, int, double const *, int, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnDorgbr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDorgbr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDorgbr_bufferSize(handle, side, m, n, k, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDorgbr_bufferSize cusolverDnDorgbr_bufferSize


#undef cusolverDnCungbr_bufferSize
cusolverStatus_t cusolverDnCungbr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, int m, int n, int k, cuComplex const * A, int lda, cuComplex const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCungbr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, int, int, int, cuComplex const *, int, cuComplex const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, int, int, int, cuComplex const *, int, cuComplex const *, int *))dlsym(RTLD_NEXT, "cusolverDnCungbr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCungbr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCungbr_bufferSize(handle, side, m, n, k, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCungbr_bufferSize cusolverDnCungbr_bufferSize


#undef cusolverDnZungbr_bufferSize
cusolverStatus_t cusolverDnZungbr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, int m, int n, int k, cuDoubleComplex const * A, int lda, cuDoubleComplex const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZungbr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, int, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, int, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int *))dlsym(RTLD_NEXT, "cusolverDnZungbr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZungbr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZungbr_bufferSize(handle, side, m, n, k, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZungbr_bufferSize cusolverDnZungbr_bufferSize


#undef cusolverDnSorgbr
cusolverStatus_t cusolverDnSorgbr(cusolverDnHandle_t handle, cublasSideMode_t side, int m, int n, int k, float * A, int lda, float const * tau, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSorgbr) (cusolverDnHandle_t, cublasSideMode_t, int, int, int, float *, int, float const *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, int, int, int, float *, int, float const *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSorgbr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSorgbr", kApiTypeCuSolver);

    lretval = lcusolverDnSorgbr(handle, side, m, n, k, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSorgbr cusolverDnSorgbr


#undef cusolverDnDorgbr
cusolverStatus_t cusolverDnDorgbr(cusolverDnHandle_t handle, cublasSideMode_t side, int m, int n, int k, double * A, int lda, double const * tau, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDorgbr) (cusolverDnHandle_t, cublasSideMode_t, int, int, int, double *, int, double const *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, int, int, int, double *, int, double const *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDorgbr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDorgbr", kApiTypeCuSolver);

    lretval = lcusolverDnDorgbr(handle, side, m, n, k, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDorgbr cusolverDnDorgbr


#undef cusolverDnCungbr
cusolverStatus_t cusolverDnCungbr(cusolverDnHandle_t handle, cublasSideMode_t side, int m, int n, int k, cuComplex * A, int lda, cuComplex const * tau, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCungbr) (cusolverDnHandle_t, cublasSideMode_t, int, int, int, cuComplex *, int, cuComplex const *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, int, int, int, cuComplex *, int, cuComplex const *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCungbr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCungbr", kApiTypeCuSolver);

    lretval = lcusolverDnCungbr(handle, side, m, n, k, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCungbr cusolverDnCungbr


#undef cusolverDnZungbr
cusolverStatus_t cusolverDnZungbr(cusolverDnHandle_t handle, cublasSideMode_t side, int m, int n, int k, cuDoubleComplex * A, int lda, cuDoubleComplex const * tau, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZungbr) (cusolverDnHandle_t, cublasSideMode_t, int, int, int, cuDoubleComplex *, int, cuDoubleComplex const *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, int, int, int, cuDoubleComplex *, int, cuDoubleComplex const *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZungbr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZungbr", kApiTypeCuSolver);

    lretval = lcusolverDnZungbr(handle, side, m, n, k, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZungbr cusolverDnZungbr


#undef cusolverDnSsytrd_bufferSize
cusolverStatus_t cusolverDnSsytrd_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float const * A, int lda, float const * d, float const * e, float const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsytrd_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, float const *, int, float const *, float const *, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float const *, int, float const *, float const *, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnSsytrd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsytrd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsytrd_bufferSize(handle, uplo, n, A, lda, d, e, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsytrd_bufferSize cusolverDnSsytrd_bufferSize


#undef cusolverDnDsytrd_bufferSize
cusolverStatus_t cusolverDnDsytrd_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double const * A, int lda, double const * d, double const * e, double const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsytrd_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, double const *, int, double const *, double const *, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double const *, int, double const *, double const *, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnDsytrd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsytrd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsytrd_bufferSize(handle, uplo, n, A, lda, d, e, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsytrd_bufferSize cusolverDnDsytrd_bufferSize


#undef cusolverDnChetrd_bufferSize
cusolverStatus_t cusolverDnChetrd_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, float const * d, float const * e, cuComplex const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnChetrd_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex const *, int, float const *, float const *, cuComplex const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex const *, int, float const *, float const *, cuComplex const *, int *))dlsym(RTLD_NEXT, "cusolverDnChetrd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnChetrd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnChetrd_bufferSize(handle, uplo, n, A, lda, d, e, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnChetrd_bufferSize cusolverDnChetrd_bufferSize


#undef cusolverDnZhetrd_bufferSize
cusolverStatus_t cusolverDnZhetrd_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, double const * d, double const * e, cuDoubleComplex const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZhetrd_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double const *, double const *, cuDoubleComplex const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double const *, double const *, cuDoubleComplex const *, int *))dlsym(RTLD_NEXT, "cusolverDnZhetrd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZhetrd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZhetrd_bufferSize(handle, uplo, n, A, lda, d, e, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZhetrd_bufferSize cusolverDnZhetrd_bufferSize


#undef cusolverDnSsytrd
cusolverStatus_t cusolverDnSsytrd(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, float * d, float * e, float * tau, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsytrd) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float *, float *, float *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float *, float *, float *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSsytrd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsytrd", kApiTypeCuSolver);

    lretval = lcusolverDnSsytrd(handle, uplo, n, A, lda, d, e, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsytrd cusolverDnSsytrd


#undef cusolverDnDsytrd
cusolverStatus_t cusolverDnDsytrd(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, double * d, double * e, double * tau, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsytrd) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double *, double *, double *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double *, double *, double *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDsytrd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsytrd", kApiTypeCuSolver);

    lretval = lcusolverDnDsytrd(handle, uplo, n, A, lda, d, e, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsytrd cusolverDnDsytrd


#undef cusolverDnChetrd
cusolverStatus_t cusolverDnChetrd(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, float * d, float * e, cuComplex * tau, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnChetrd) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, float *, float *, cuComplex *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, float *, float *, cuComplex *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnChetrd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnChetrd", kApiTypeCuSolver);

    lretval = lcusolverDnChetrd(handle, uplo, n, A, lda, d, e, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnChetrd cusolverDnChetrd


#undef cusolverDnZhetrd
cusolverStatus_t cusolverDnZhetrd(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, double * d, double * e, cuDoubleComplex * tau, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZhetrd) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, double *, double *, cuDoubleComplex *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, double *, double *, cuDoubleComplex *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZhetrd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZhetrd", kApiTypeCuSolver);

    lretval = lcusolverDnZhetrd(handle, uplo, n, A, lda, d, e, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZhetrd cusolverDnZhetrd


#undef cusolverDnSorgtr_bufferSize
cusolverStatus_t cusolverDnSorgtr_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float const * A, int lda, float const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSorgtr_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, float const *, int, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float const *, int, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnSorgtr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSorgtr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSorgtr_bufferSize(handle, uplo, n, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSorgtr_bufferSize cusolverDnSorgtr_bufferSize


#undef cusolverDnDorgtr_bufferSize
cusolverStatus_t cusolverDnDorgtr_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double const * A, int lda, double const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDorgtr_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, double const *, int, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double const *, int, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnDorgtr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDorgtr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDorgtr_bufferSize(handle, uplo, n, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDorgtr_bufferSize cusolverDnDorgtr_bufferSize


#undef cusolverDnCungtr_bufferSize
cusolverStatus_t cusolverDnCungtr_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, cuComplex const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCungtr_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex const *, int *))dlsym(RTLD_NEXT, "cusolverDnCungtr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCungtr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCungtr_bufferSize(handle, uplo, n, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCungtr_bufferSize cusolverDnCungtr_bufferSize


#undef cusolverDnZungtr_bufferSize
cusolverStatus_t cusolverDnZungtr_bufferSize(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, cuDoubleComplex const * tau, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZungtr_bufferSize) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int *))dlsym(RTLD_NEXT, "cusolverDnZungtr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZungtr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZungtr_bufferSize(handle, uplo, n, A, lda, tau, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZungtr_bufferSize cusolverDnZungtr_bufferSize


#undef cusolverDnSorgtr
cusolverStatus_t cusolverDnSorgtr(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, float * A, int lda, float const * tau, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSorgtr) (cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float const *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, float *, int, float const *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSorgtr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSorgtr", kApiTypeCuSolver);

    lretval = lcusolverDnSorgtr(handle, uplo, n, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSorgtr cusolverDnSorgtr


#undef cusolverDnDorgtr
cusolverStatus_t cusolverDnDorgtr(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double * A, int lda, double const * tau, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDorgtr) (cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double const *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, double *, int, double const *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDorgtr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDorgtr", kApiTypeCuSolver);

    lretval = lcusolverDnDorgtr(handle, uplo, n, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDorgtr cusolverDnDorgtr


#undef cusolverDnCungtr
cusolverStatus_t cusolverDnCungtr(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuComplex * A, int lda, cuComplex const * tau, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCungtr) (cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, cuComplex const *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuComplex *, int, cuComplex const *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCungtr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCungtr", kApiTypeCuSolver);

    lretval = lcusolverDnCungtr(handle, uplo, n, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCungtr cusolverDnCungtr


#undef cusolverDnZungtr
cusolverStatus_t cusolverDnZungtr(cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, cuDoubleComplex const * tau, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZungtr) (cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex const *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex const *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZungtr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZungtr", kApiTypeCuSolver);

    lretval = lcusolverDnZungtr(handle, uplo, n, A, lda, tau, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZungtr cusolverDnZungtr


#undef cusolverDnSormtr_bufferSize
cusolverStatus_t cusolverDnSormtr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, int m, int n, float const * A, int lda, float const * tau, float const * C, int ldc, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSormtr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, int, float const *, float const *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, float const *, int, float const *, float const *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSormtr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSormtr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSormtr_bufferSize(handle, side, uplo, trans, m, n, A, lda, tau, C, ldc, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSormtr_bufferSize cusolverDnSormtr_bufferSize


#undef cusolverDnDormtr_bufferSize
cusolverStatus_t cusolverDnDormtr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, int m, int n, double const * A, int lda, double const * tau, double const * C, int ldc, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDormtr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, int, double const *, double const *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, double const *, int, double const *, double const *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDormtr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDormtr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDormtr_bufferSize(handle, side, uplo, trans, m, n, A, lda, tau, C, ldc, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDormtr_bufferSize cusolverDnDormtr_bufferSize


#undef cusolverDnCunmtr_bufferSize
cusolverStatus_t cusolverDnCunmtr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, int m, int n, cuComplex const * A, int lda, cuComplex const * tau, cuComplex const * C, int ldc, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCunmtr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, int, cuComplex const *, cuComplex const *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex const *, int, cuComplex const *, cuComplex const *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCunmtr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCunmtr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCunmtr_bufferSize(handle, side, uplo, trans, m, n, A, lda, tau, C, ldc, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCunmtr_bufferSize cusolverDnCunmtr_bufferSize


#undef cusolverDnZunmtr_bufferSize
cusolverStatus_t cusolverDnZunmtr_bufferSize(cusolverDnHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, int m, int n, cuDoubleComplex const * A, int lda, cuDoubleComplex const * tau, cuDoubleComplex const * C, int ldc, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZunmtr_bufferSize) (cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex const *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex const *, int, cuDoubleComplex const *, cuDoubleComplex const *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZunmtr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZunmtr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZunmtr_bufferSize(handle, side, uplo, trans, m, n, A, lda, tau, C, ldc, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZunmtr_bufferSize cusolverDnZunmtr_bufferSize


#undef cusolverDnSormtr
cusolverStatus_t cusolverDnSormtr(cusolverDnHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, int m, int n, float * A, int lda, float * tau, float * C, int ldc, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSormtr) (cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, float *, int, float *, float *, int, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, float *, int, float *, float *, int, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSormtr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSormtr", kApiTypeCuSolver);

    lretval = lcusolverDnSormtr(handle, side, uplo, trans, m, n, A, lda, tau, C, ldc, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSormtr cusolverDnSormtr


#undef cusolverDnDormtr
cusolverStatus_t cusolverDnDormtr(cusolverDnHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, int m, int n, double * A, int lda, double * tau, double * C, int ldc, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDormtr) (cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, double *, int, double *, double *, int, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, double *, int, double *, double *, int, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDormtr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDormtr", kApiTypeCuSolver);

    lretval = lcusolverDnDormtr(handle, side, uplo, trans, m, n, A, lda, tau, C, ldc, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDormtr cusolverDnDormtr


#undef cusolverDnCunmtr
cusolverStatus_t cusolverDnCunmtr(cusolverDnHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, int m, int n, cuComplex * A, int lda, cuComplex * tau, cuComplex * C, int ldc, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCunmtr) (cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex *, int, cuComplex *, cuComplex *, int, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, cuComplex *, int, cuComplex *, cuComplex *, int, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCunmtr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCunmtr", kApiTypeCuSolver);

    lretval = lcusolverDnCunmtr(handle, side, uplo, trans, m, n, A, lda, tau, C, ldc, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCunmtr cusolverDnCunmtr


#undef cusolverDnZunmtr
cusolverStatus_t cusolverDnZunmtr(cusolverDnHandle_t handle, cublasSideMode_t side, cublasFillMode_t uplo, cublasOperation_t trans, int m, int n, cuDoubleComplex * A, int lda, cuDoubleComplex * tau, cuDoubleComplex * C, int ldc, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZunmtr) (cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex *, int, cuDoubleComplex *, cuDoubleComplex *, int, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cublasSideMode_t, cublasFillMode_t, cublasOperation_t, int, int, cuDoubleComplex *, int, cuDoubleComplex *, cuDoubleComplex *, int, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZunmtr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZunmtr", kApiTypeCuSolver);

    lretval = lcusolverDnZunmtr(handle, side, uplo, trans, m, n, A, lda, tau, C, ldc, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZunmtr cusolverDnZunmtr


#undef cusolverDnSgesvd_bufferSize
cusolverStatus_t cusolverDnSgesvd_bufferSize(cusolverDnHandle_t handle, int m, int n, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgesvd_bufferSize) (cusolverDnHandle_t, int, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int *))dlsym(RTLD_NEXT, "cusolverDnSgesvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgesvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSgesvd_bufferSize(handle, m, n, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgesvd_bufferSize cusolverDnSgesvd_bufferSize


#undef cusolverDnDgesvd_bufferSize
cusolverStatus_t cusolverDnDgesvd_bufferSize(cusolverDnHandle_t handle, int m, int n, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgesvd_bufferSize) (cusolverDnHandle_t, int, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int *))dlsym(RTLD_NEXT, "cusolverDnDgesvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgesvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDgesvd_bufferSize(handle, m, n, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgesvd_bufferSize cusolverDnDgesvd_bufferSize


#undef cusolverDnCgesvd_bufferSize
cusolverStatus_t cusolverDnCgesvd_bufferSize(cusolverDnHandle_t handle, int m, int n, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgesvd_bufferSize) (cusolverDnHandle_t, int, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int *))dlsym(RTLD_NEXT, "cusolverDnCgesvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgesvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCgesvd_bufferSize(handle, m, n, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgesvd_bufferSize cusolverDnCgesvd_bufferSize


#undef cusolverDnZgesvd_bufferSize
cusolverStatus_t cusolverDnZgesvd_bufferSize(cusolverDnHandle_t handle, int m, int n, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgesvd_bufferSize) (cusolverDnHandle_t, int, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, int, int, int *))dlsym(RTLD_NEXT, "cusolverDnZgesvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgesvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZgesvd_bufferSize(handle, m, n, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgesvd_bufferSize cusolverDnZgesvd_bufferSize


#undef cusolverDnSgesvd
cusolverStatus_t cusolverDnSgesvd(cusolverDnHandle_t handle, signed char jobu, signed char jobvt, int m, int n, float * A, int lda, float * S, float * U, int ldu, float * VT, int ldvt, float * work, int lwork, float * rwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgesvd) (cusolverDnHandle_t, signed char, signed char, int, int, float *, int, float *, float *, int, float *, int, float *, int, float *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, signed char, signed char, int, int, float *, int, float *, float *, int, float *, int, float *, int, float *, int *))dlsym(RTLD_NEXT, "cusolverDnSgesvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgesvd", kApiTypeCuSolver);

    lretval = lcusolverDnSgesvd(handle, jobu, jobvt, m, n, A, lda, S, U, ldu, VT, ldvt, work, lwork, rwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgesvd cusolverDnSgesvd


#undef cusolverDnDgesvd
cusolverStatus_t cusolverDnDgesvd(cusolverDnHandle_t handle, signed char jobu, signed char jobvt, int m, int n, double * A, int lda, double * S, double * U, int ldu, double * VT, int ldvt, double * work, int lwork, double * rwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgesvd) (cusolverDnHandle_t, signed char, signed char, int, int, double *, int, double *, double *, int, double *, int, double *, int, double *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, signed char, signed char, int, int, double *, int, double *, double *, int, double *, int, double *, int, double *, int *))dlsym(RTLD_NEXT, "cusolverDnDgesvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgesvd", kApiTypeCuSolver);

    lretval = lcusolverDnDgesvd(handle, jobu, jobvt, m, n, A, lda, S, U, ldu, VT, ldvt, work, lwork, rwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgesvd cusolverDnDgesvd


#undef cusolverDnCgesvd
cusolverStatus_t cusolverDnCgesvd(cusolverDnHandle_t handle, signed char jobu, signed char jobvt, int m, int n, cuComplex * A, int lda, float * S, cuComplex * U, int ldu, cuComplex * VT, int ldvt, cuComplex * work, int lwork, float * rwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgesvd) (cusolverDnHandle_t, signed char, signed char, int, int, cuComplex *, int, float *, cuComplex *, int, cuComplex *, int, cuComplex *, int, float *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, signed char, signed char, int, int, cuComplex *, int, float *, cuComplex *, int, cuComplex *, int, cuComplex *, int, float *, int *))dlsym(RTLD_NEXT, "cusolverDnCgesvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgesvd", kApiTypeCuSolver);

    lretval = lcusolverDnCgesvd(handle, jobu, jobvt, m, n, A, lda, S, U, ldu, VT, ldvt, work, lwork, rwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgesvd cusolverDnCgesvd


#undef cusolverDnZgesvd
cusolverStatus_t cusolverDnZgesvd(cusolverDnHandle_t handle, signed char jobu, signed char jobvt, int m, int n, cuDoubleComplex * A, int lda, double * S, cuDoubleComplex * U, int ldu, cuDoubleComplex * VT, int ldvt, cuDoubleComplex * work, int lwork, double * rwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgesvd) (cusolverDnHandle_t, signed char, signed char, int, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, signed char, signed char, int, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double *, int *))dlsym(RTLD_NEXT, "cusolverDnZgesvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgesvd", kApiTypeCuSolver);

    lretval = lcusolverDnZgesvd(handle, jobu, jobvt, m, n, A, lda, S, U, ldu, VT, ldvt, work, lwork, rwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgesvd cusolverDnZgesvd


#undef cusolverDnSsyevd_bufferSize
cusolverStatus_t cusolverDnSsyevd_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float const * A, int lda, float const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsyevd_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnSsyevd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsyevd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsyevd_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsyevd_bufferSize cusolverDnSsyevd_bufferSize


#undef cusolverDnDsyevd_bufferSize
cusolverStatus_t cusolverDnDsyevd_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double const * A, int lda, double const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsyevd_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnDsyevd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsyevd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsyevd_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsyevd_bufferSize cusolverDnDsyevd_bufferSize


#undef cusolverDnCheevd_bufferSize
cusolverStatus_t cusolverDnCheevd_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, float const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCheevd_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnCheevd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCheevd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCheevd_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCheevd_bufferSize cusolverDnCheevd_bufferSize


#undef cusolverDnZheevd_bufferSize
cusolverStatus_t cusolverDnZheevd_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, double const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZheevd_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnZheevd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZheevd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZheevd_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZheevd_bufferSize cusolverDnZheevd_bufferSize


#undef cusolverDnSsyevd
cusolverStatus_t cusolverDnSsyevd(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float * A, int lda, float * W, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsyevd) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSsyevd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsyevd", kApiTypeCuSolver);

    lretval = lcusolverDnSsyevd(handle, jobz, uplo, n, A, lda, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsyevd cusolverDnSsyevd


#undef cusolverDnDsyevd
cusolverStatus_t cusolverDnDsyevd(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double * A, int lda, double * W, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsyevd) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDsyevd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsyevd", kApiTypeCuSolver);

    lretval = lcusolverDnDsyevd(handle, jobz, uplo, n, A, lda, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsyevd cusolverDnDsyevd


#undef cusolverDnCheevd
cusolverStatus_t cusolverDnCheevd(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex * A, int lda, float * W, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCheevd) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, float *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, float *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCheevd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCheevd", kApiTypeCuSolver);

    lretval = lcusolverDnCheevd(handle, jobz, uplo, n, A, lda, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCheevd cusolverDnCheevd


#undef cusolverDnZheevd
cusolverStatus_t cusolverDnZheevd(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, double * W, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZheevd) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZheevd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZheevd", kApiTypeCuSolver);

    lretval = lcusolverDnZheevd(handle, jobz, uplo, n, A, lda, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZheevd cusolverDnZheevd


#undef cusolverDnSsyevdx_bufferSize
cusolverStatus_t cusolverDnSsyevdx_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, float const * A, int lda, float vl, float vu, int il, int iu, int * meig, float const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsyevdx_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, float const *, int, float, float, int, int, int *, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, float const *, int, float, float, int, int, int *, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnSsyevdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsyevdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsyevdx_bufferSize(handle, jobz, range, uplo, n, A, lda, vl, vu, il, iu, meig, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsyevdx_bufferSize cusolverDnSsyevdx_bufferSize


#undef cusolverDnDsyevdx_bufferSize
cusolverStatus_t cusolverDnDsyevdx_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, double const * A, int lda, double vl, double vu, int il, int iu, int * meig, double const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsyevdx_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, double const *, int, double, double, int, int, int *, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, double const *, int, double, double, int, int, int *, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnDsyevdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsyevdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsyevdx_bufferSize(handle, jobz, range, uplo, n, A, lda, vl, vu, il, iu, meig, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsyevdx_bufferSize cusolverDnDsyevdx_bufferSize


#undef cusolverDnCheevdx_bufferSize
cusolverStatus_t cusolverDnCheevdx_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, float vl, float vu, int il, int iu, int * meig, float const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCheevdx_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuComplex const *, int, float, float, int, int, int *, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuComplex const *, int, float, float, int, int, int *, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnCheevdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCheevdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCheevdx_bufferSize(handle, jobz, range, uplo, n, A, lda, vl, vu, il, iu, meig, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCheevdx_bufferSize cusolverDnCheevdx_bufferSize


#undef cusolverDnZheevdx_bufferSize
cusolverStatus_t cusolverDnZheevdx_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, double vl, double vu, int il, int iu, int * meig, double const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZheevdx_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double, double, int, int, int *, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double, double, int, int, int *, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnZheevdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZheevdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZheevdx_bufferSize(handle, jobz, range, uplo, n, A, lda, vl, vu, il, iu, meig, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZheevdx_bufferSize cusolverDnZheevdx_bufferSize


#undef cusolverDnSsyevdx
cusolverStatus_t cusolverDnSsyevdx(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, float * A, int lda, float vl, float vu, int il, int iu, int * meig, float * W, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsyevdx) (cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, float *, int, float, float, int, int, int *, float *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, float *, int, float, float, int, int, int *, float *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSsyevdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsyevdx", kApiTypeCuSolver);

    lretval = lcusolverDnSsyevdx(handle, jobz, range, uplo, n, A, lda, vl, vu, il, iu, meig, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsyevdx cusolverDnSsyevdx


#undef cusolverDnDsyevdx
cusolverStatus_t cusolverDnDsyevdx(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, double * A, int lda, double vl, double vu, int il, int iu, int * meig, double * W, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsyevdx) (cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, double *, int, double, double, int, int, int *, double *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, double *, int, double, double, int, int, int *, double *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDsyevdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsyevdx", kApiTypeCuSolver);

    lretval = lcusolverDnDsyevdx(handle, jobz, range, uplo, n, A, lda, vl, vu, il, iu, meig, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsyevdx cusolverDnDsyevdx


#undef cusolverDnCheevdx
cusolverStatus_t cusolverDnCheevdx(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, cuComplex * A, int lda, float vl, float vu, int il, int iu, int * meig, float * W, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCheevdx) (cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuComplex *, int, float, float, int, int, int *, float *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuComplex *, int, float, float, int, int, int *, float *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnCheevdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCheevdx", kApiTypeCuSolver);

    lretval = lcusolverDnCheevdx(handle, jobz, range, uplo, n, A, lda, vl, vu, il, iu, meig, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCheevdx cusolverDnCheevdx


#undef cusolverDnZheevdx
cusolverStatus_t cusolverDnZheevdx(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, double vl, double vu, int il, int iu, int * meig, double * W, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZheevdx) (cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuDoubleComplex *, int, double, double, int, int, int *, double *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuDoubleComplex *, int, double, double, int, int, int *, double *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZheevdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZheevdx", kApiTypeCuSolver);

    lretval = lcusolverDnZheevdx(handle, jobz, range, uplo, n, A, lda, vl, vu, il, iu, meig, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZheevdx cusolverDnZheevdx


#undef cusolverDnSsygvdx_bufferSize
cusolverStatus_t cusolverDnSsygvdx_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, float const * A, int lda, float const * B, int ldb, float vl, float vu, int il, int iu, int * meig, float const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsygvdx_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, float const *, int, float const *, int, float, float, int, int, int *, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, float const *, int, float const *, int, float, float, int, int, int *, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnSsygvdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsygvdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsygvdx_bufferSize(handle, itype, jobz, range, uplo, n, A, lda, B, ldb, vl, vu, il, iu, meig, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsygvdx_bufferSize cusolverDnSsygvdx_bufferSize


#undef cusolverDnDsygvdx_bufferSize
cusolverStatus_t cusolverDnDsygvdx_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, double const * A, int lda, double const * B, int ldb, double vl, double vu, int il, int iu, int * meig, double const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsygvdx_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, double const *, int, double const *, int, double, double, int, int, int *, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, double const *, int, double const *, int, double, double, int, int, int *, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnDsygvdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsygvdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsygvdx_bufferSize(handle, itype, jobz, range, uplo, n, A, lda, B, ldb, vl, vu, il, iu, meig, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsygvdx_bufferSize cusolverDnDsygvdx_bufferSize


#undef cusolverDnChegvdx_bufferSize
cusolverStatus_t cusolverDnChegvdx_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, cuComplex const * B, int ldb, float vl, float vu, int il, int iu, int * meig, float const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnChegvdx_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex const *, int, float, float, int, int, int *, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex const *, int, float, float, int, int, int *, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnChegvdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnChegvdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnChegvdx_bufferSize(handle, itype, jobz, range, uplo, n, A, lda, B, ldb, vl, vu, il, iu, meig, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnChegvdx_bufferSize cusolverDnChegvdx_bufferSize


#undef cusolverDnZhegvdx_bufferSize
cusolverStatus_t cusolverDnZhegvdx_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, double vl, double vu, int il, int iu, int * meig, double const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZhegvdx_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double, double, int, int, int *, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double, double, int, int, int *, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnZhegvdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZhegvdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZhegvdx_bufferSize(handle, itype, jobz, range, uplo, n, A, lda, B, ldb, vl, vu, il, iu, meig, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZhegvdx_bufferSize cusolverDnZhegvdx_bufferSize


#undef cusolverDnSsygvdx
cusolverStatus_t cusolverDnSsygvdx(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, float * A, int lda, float * B, int ldb, float vl, float vu, int il, int iu, int * meig, float * W, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsygvdx) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, float *, int, float *, int, float, float, int, int, int *, float *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, float *, int, float *, int, float, float, int, int, int *, float *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSsygvdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsygvdx", kApiTypeCuSolver);

    lretval = lcusolverDnSsygvdx(handle, itype, jobz, range, uplo, n, A, lda, B, ldb, vl, vu, il, iu, meig, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsygvdx cusolverDnSsygvdx


#undef cusolverDnDsygvdx
cusolverStatus_t cusolverDnDsygvdx(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, double * A, int lda, double * B, int ldb, double vl, double vu, int il, int iu, int * meig, double * W, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsygvdx) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, double *, int, double *, int, double, double, int, int, int *, double *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, double *, int, double *, int, double, double, int, int, int *, double *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDsygvdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsygvdx", kApiTypeCuSolver);

    lretval = lcusolverDnDsygvdx(handle, itype, jobz, range, uplo, n, A, lda, B, ldb, vl, vu, il, iu, meig, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsygvdx cusolverDnDsygvdx


#undef cusolverDnChegvdx
cusolverStatus_t cusolverDnChegvdx(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, cuComplex * A, int lda, cuComplex * B, int ldb, float vl, float vu, int il, int iu, int * meig, float * W, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnChegvdx) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, float, float, int, int, int *, float *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, float, float, int, int, int *, float *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnChegvdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnChegvdx", kApiTypeCuSolver);

    lretval = lcusolverDnChegvdx(handle, itype, jobz, range, uplo, n, A, lda, B, ldb, vl, vu, il, iu, meig, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnChegvdx cusolverDnChegvdx


#undef cusolverDnZhegvdx
cusolverStatus_t cusolverDnZhegvdx(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, cuDoubleComplex * B, int ldb, double vl, double vu, int il, int iu, int * meig, double * W, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZhegvdx) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double, double, int, int, int *, double *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double, double, int, int, int *, double *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZhegvdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZhegvdx", kApiTypeCuSolver);

    lretval = lcusolverDnZhegvdx(handle, itype, jobz, range, uplo, n, A, lda, B, ldb, vl, vu, il, iu, meig, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZhegvdx cusolverDnZhegvdx


#undef cusolverDnSsygvd_bufferSize
cusolverStatus_t cusolverDnSsygvd_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float const * A, int lda, float const * B, int ldb, float const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsygvd_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnSsygvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsygvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsygvd_bufferSize(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsygvd_bufferSize cusolverDnSsygvd_bufferSize


#undef cusolverDnDsygvd_bufferSize
cusolverStatus_t cusolverDnDsygvd_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double const * A, int lda, double const * B, int ldb, double const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsygvd_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnDsygvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsygvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsygvd_bufferSize(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsygvd_bufferSize cusolverDnDsygvd_bufferSize


#undef cusolverDnChegvd_bufferSize
cusolverStatus_t cusolverDnChegvd_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, cuComplex const * B, int ldb, float const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnChegvd_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex const *, int, float const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex const *, int, float const *, int *))dlsym(RTLD_NEXT, "cusolverDnChegvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnChegvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnChegvd_bufferSize(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnChegvd_bufferSize cusolverDnChegvd_bufferSize


#undef cusolverDnZhegvd_bufferSize
cusolverStatus_t cusolverDnZhegvd_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, double const * W, int * lwork){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZhegvd_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double const *, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double const *, int *))dlsym(RTLD_NEXT, "cusolverDnZhegvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZhegvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZhegvd_bufferSize(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, lwork);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZhegvd_bufferSize cusolverDnZhegvd_bufferSize


#undef cusolverDnSsygvd
cusolverStatus_t cusolverDnSsygvd(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float * A, int lda, float * B, int ldb, float * W, float * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsygvd) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, int, float *, float *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, int, float *, float *, int, int *))dlsym(RTLD_NEXT, "cusolverDnSsygvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsygvd", kApiTypeCuSolver);

    lretval = lcusolverDnSsygvd(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsygvd cusolverDnSsygvd


#undef cusolverDnDsygvd
cusolverStatus_t cusolverDnDsygvd(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double * A, int lda, double * B, int ldb, double * W, double * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsygvd) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, int, double *, double *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, int, double *, double *, int, int *))dlsym(RTLD_NEXT, "cusolverDnDsygvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsygvd", kApiTypeCuSolver);

    lretval = lcusolverDnDsygvd(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsygvd cusolverDnDsygvd


#undef cusolverDnChegvd
cusolverStatus_t cusolverDnChegvd(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex * A, int lda, cuComplex * B, int ldb, float * W, cuComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnChegvd) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, float *, cuComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, float *, cuComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnChegvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnChegvd", kApiTypeCuSolver);

    lretval = lcusolverDnChegvd(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnChegvd cusolverDnChegvd


#undef cusolverDnZhegvd
cusolverStatus_t cusolverDnZhegvd(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, cuDoubleComplex * B, int ldb, double * W, cuDoubleComplex * work, int lwork, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZhegvd) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *))dlsym(RTLD_NEXT, "cusolverDnZhegvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZhegvd", kApiTypeCuSolver);

    lretval = lcusolverDnZhegvd(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, work, lwork, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZhegvd cusolverDnZhegvd


#undef cusolverDnCreateSyevjInfo
cusolverStatus_t cusolverDnCreateSyevjInfo(syevjInfo_t * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCreateSyevjInfo) (syevjInfo_t *) = (cusolverStatus_t (*)(syevjInfo_t *))dlsym(RTLD_NEXT, "cusolverDnCreateSyevjInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCreateSyevjInfo", kApiTypeCuSolver);

    lretval = lcusolverDnCreateSyevjInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCreateSyevjInfo cusolverDnCreateSyevjInfo


#undef cusolverDnDestroySyevjInfo
cusolverStatus_t cusolverDnDestroySyevjInfo(syevjInfo_t info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDestroySyevjInfo) (syevjInfo_t) = (cusolverStatus_t (*)(syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnDestroySyevjInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDestroySyevjInfo", kApiTypeCuSolver);

    lretval = lcusolverDnDestroySyevjInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDestroySyevjInfo cusolverDnDestroySyevjInfo


#undef cusolverDnXsyevjSetTolerance
cusolverStatus_t cusolverDnXsyevjSetTolerance(syevjInfo_t info, double tolerance){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsyevjSetTolerance) (syevjInfo_t, double) = (cusolverStatus_t (*)(syevjInfo_t, double))dlsym(RTLD_NEXT, "cusolverDnXsyevjSetTolerance");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsyevjSetTolerance", kApiTypeCuSolver);

    lretval = lcusolverDnXsyevjSetTolerance(info, tolerance);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsyevjSetTolerance cusolverDnXsyevjSetTolerance


#undef cusolverDnXsyevjSetMaxSweeps
cusolverStatus_t cusolverDnXsyevjSetMaxSweeps(syevjInfo_t info, int max_sweeps){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsyevjSetMaxSweeps) (syevjInfo_t, int) = (cusolverStatus_t (*)(syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnXsyevjSetMaxSweeps");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsyevjSetMaxSweeps", kApiTypeCuSolver);

    lretval = lcusolverDnXsyevjSetMaxSweeps(info, max_sweeps);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsyevjSetMaxSweeps cusolverDnXsyevjSetMaxSweeps


#undef cusolverDnXsyevjSetSortEig
cusolverStatus_t cusolverDnXsyevjSetSortEig(syevjInfo_t info, int sort_eig){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsyevjSetSortEig) (syevjInfo_t, int) = (cusolverStatus_t (*)(syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnXsyevjSetSortEig");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsyevjSetSortEig", kApiTypeCuSolver);

    lretval = lcusolverDnXsyevjSetSortEig(info, sort_eig);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsyevjSetSortEig cusolverDnXsyevjSetSortEig


#undef cusolverDnXsyevjGetResidual
cusolverStatus_t cusolverDnXsyevjGetResidual(cusolverDnHandle_t handle, syevjInfo_t info, double * residual){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsyevjGetResidual) (cusolverDnHandle_t, syevjInfo_t, double *) = (cusolverStatus_t (*)(cusolverDnHandle_t, syevjInfo_t, double *))dlsym(RTLD_NEXT, "cusolverDnXsyevjGetResidual");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsyevjGetResidual", kApiTypeCuSolver);

    lretval = lcusolverDnXsyevjGetResidual(handle, info, residual);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsyevjGetResidual cusolverDnXsyevjGetResidual


#undef cusolverDnXsyevjGetSweeps
cusolverStatus_t cusolverDnXsyevjGetSweeps(cusolverDnHandle_t handle, syevjInfo_t info, int * executed_sweeps){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsyevjGetSweeps) (cusolverDnHandle_t, syevjInfo_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, syevjInfo_t, int *))dlsym(RTLD_NEXT, "cusolverDnXsyevjGetSweeps");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsyevjGetSweeps", kApiTypeCuSolver);

    lretval = lcusolverDnXsyevjGetSweeps(handle, info, executed_sweeps);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsyevjGetSweeps cusolverDnXsyevjGetSweeps


#undef cusolverDnSsyevjBatched_bufferSize
cusolverStatus_t cusolverDnSsyevjBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float const * A, int lda, float const * W, int * lwork, syevjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsyevjBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int *, syevjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int *, syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnSsyevjBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsyevjBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsyevjBatched_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsyevjBatched_bufferSize cusolverDnSsyevjBatched_bufferSize


#undef cusolverDnDsyevjBatched_bufferSize
cusolverStatus_t cusolverDnDsyevjBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double const * A, int lda, double const * W, int * lwork, syevjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsyevjBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int *, syevjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int *, syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnDsyevjBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsyevjBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsyevjBatched_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsyevjBatched_bufferSize cusolverDnDsyevjBatched_bufferSize


#undef cusolverDnCheevjBatched_bufferSize
cusolverStatus_t cusolverDnCheevjBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, float const * W, int * lwork, syevjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCheevjBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, float const *, int *, syevjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, float const *, int *, syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnCheevjBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCheevjBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCheevjBatched_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCheevjBatched_bufferSize cusolverDnCheevjBatched_bufferSize


#undef cusolverDnZheevjBatched_bufferSize
cusolverStatus_t cusolverDnZheevjBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, double const * W, int * lwork, syevjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZheevjBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double const *, int *, syevjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double const *, int *, syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnZheevjBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZheevjBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZheevjBatched_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZheevjBatched_bufferSize cusolverDnZheevjBatched_bufferSize


#undef cusolverDnSsyevjBatched
cusolverStatus_t cusolverDnSsyevjBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float * A, int lda, float * W, float * work, int lwork, int * info, syevjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsyevjBatched) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, float *, int, int *, syevjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, float *, int, int *, syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnSsyevjBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsyevjBatched", kApiTypeCuSolver);

    lretval = lcusolverDnSsyevjBatched(handle, jobz, uplo, n, A, lda, W, work, lwork, info, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsyevjBatched cusolverDnSsyevjBatched


#undef cusolverDnDsyevjBatched
cusolverStatus_t cusolverDnDsyevjBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double * A, int lda, double * W, double * work, int lwork, int * info, syevjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsyevjBatched) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, double *, int, int *, syevjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, double *, int, int *, syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnDsyevjBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsyevjBatched", kApiTypeCuSolver);

    lretval = lcusolverDnDsyevjBatched(handle, jobz, uplo, n, A, lda, W, work, lwork, info, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsyevjBatched cusolverDnDsyevjBatched


#undef cusolverDnCheevjBatched
cusolverStatus_t cusolverDnCheevjBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex * A, int lda, float * W, cuComplex * work, int lwork, int * info, syevjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCheevjBatched) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, float *, cuComplex *, int, int *, syevjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, float *, cuComplex *, int, int *, syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnCheevjBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCheevjBatched", kApiTypeCuSolver);

    lretval = lcusolverDnCheevjBatched(handle, jobz, uplo, n, A, lda, W, work, lwork, info, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCheevjBatched cusolverDnCheevjBatched


#undef cusolverDnZheevjBatched
cusolverStatus_t cusolverDnZheevjBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, double * W, cuDoubleComplex * work, int lwork, int * info, syevjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZheevjBatched) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *, syevjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *, syevjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnZheevjBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZheevjBatched", kApiTypeCuSolver);

    lretval = lcusolverDnZheevjBatched(handle, jobz, uplo, n, A, lda, W, work, lwork, info, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZheevjBatched cusolverDnZheevjBatched


#undef cusolverDnSsyevj_bufferSize
cusolverStatus_t cusolverDnSsyevj_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float const * A, int lda, float const * W, int * lwork, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsyevj_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnSsyevj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsyevj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsyevj_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsyevj_bufferSize cusolverDnSsyevj_bufferSize


#undef cusolverDnDsyevj_bufferSize
cusolverStatus_t cusolverDnDsyevj_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double const * A, int lda, double const * W, int * lwork, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsyevj_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnDsyevj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsyevj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsyevj_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsyevj_bufferSize cusolverDnDsyevj_bufferSize


#undef cusolverDnCheevj_bufferSize
cusolverStatus_t cusolverDnCheevj_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, float const * W, int * lwork, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCheevj_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, float const *, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, float const *, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnCheevj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCheevj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCheevj_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCheevj_bufferSize cusolverDnCheevj_bufferSize


#undef cusolverDnZheevj_bufferSize
cusolverStatus_t cusolverDnZheevj_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, double const * W, int * lwork, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZheevj_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double const *, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, double const *, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnZheevj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZheevj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZheevj_bufferSize(handle, jobz, uplo, n, A, lda, W, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZheevj_bufferSize cusolverDnZheevj_bufferSize


#undef cusolverDnSsyevj
cusolverStatus_t cusolverDnSsyevj(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float * A, int lda, float * W, float * work, int lwork, int * info, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsyevj) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, float *, int, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, float *, int, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnSsyevj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsyevj", kApiTypeCuSolver);

    lretval = lcusolverDnSsyevj(handle, jobz, uplo, n, A, lda, W, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsyevj cusolverDnSsyevj


#undef cusolverDnDsyevj
cusolverStatus_t cusolverDnDsyevj(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double * A, int lda, double * W, double * work, int lwork, int * info, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsyevj) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, double *, int, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, double *, int, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnDsyevj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsyevj", kApiTypeCuSolver);

    lretval = lcusolverDnDsyevj(handle, jobz, uplo, n, A, lda, W, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsyevj cusolverDnDsyevj


#undef cusolverDnCheevj
cusolverStatus_t cusolverDnCheevj(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex * A, int lda, float * W, cuComplex * work, int lwork, int * info, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCheevj) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, float *, cuComplex *, int, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, float *, cuComplex *, int, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnCheevj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCheevj", kApiTypeCuSolver);

    lretval = lcusolverDnCheevj(handle, jobz, uplo, n, A, lda, W, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCheevj cusolverDnCheevj


#undef cusolverDnZheevj
cusolverStatus_t cusolverDnZheevj(cusolverDnHandle_t handle, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, double * W, cuDoubleComplex * work, int lwork, int * info, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZheevj) (cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnZheevj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZheevj", kApiTypeCuSolver);

    lretval = lcusolverDnZheevj(handle, jobz, uplo, n, A, lda, W, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZheevj cusolverDnZheevj


#undef cusolverDnSsygvj_bufferSize
cusolverStatus_t cusolverDnSsygvj_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float const * A, int lda, float const * B, int ldb, float const * W, int * lwork, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsygvj_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int, float const *, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, float const *, int, float const *, int, float const *, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnSsygvj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsygvj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSsygvj_bufferSize(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsygvj_bufferSize cusolverDnSsygvj_bufferSize


#undef cusolverDnDsygvj_bufferSize
cusolverStatus_t cusolverDnDsygvj_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double const * A, int lda, double const * B, int ldb, double const * W, int * lwork, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsygvj_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int, double const *, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, double const *, int, double const *, int, double const *, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnDsygvj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsygvj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDsygvj_bufferSize(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsygvj_bufferSize cusolverDnDsygvj_bufferSize


#undef cusolverDnChegvj_bufferSize
cusolverStatus_t cusolverDnChegvj_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex const * A, int lda, cuComplex const * B, int ldb, float const * W, int * lwork, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnChegvj_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex const *, int, float const *, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex const *, int, cuComplex const *, int, float const *, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnChegvj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnChegvj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnChegvj_bufferSize(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnChegvj_bufferSize cusolverDnChegvj_bufferSize


#undef cusolverDnZhegvj_bufferSize
cusolverStatus_t cusolverDnZhegvj_bufferSize(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex const * A, int lda, cuDoubleComplex const * B, int ldb, double const * W, int * lwork, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZhegvj_bufferSize) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double const *, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex const *, int, cuDoubleComplex const *, int, double const *, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnZhegvj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZhegvj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZhegvj_bufferSize(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZhegvj_bufferSize cusolverDnZhegvj_bufferSize


#undef cusolverDnSsygvj
cusolverStatus_t cusolverDnSsygvj(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, float * A, int lda, float * B, int ldb, float * W, float * work, int lwork, int * info, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSsygvj) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, int, float *, float *, int, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, float *, int, float *, int, float *, float *, int, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnSsygvj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSsygvj", kApiTypeCuSolver);

    lretval = lcusolverDnSsygvj(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSsygvj cusolverDnSsygvj


#undef cusolverDnDsygvj
cusolverStatus_t cusolverDnDsygvj(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, double * A, int lda, double * B, int ldb, double * W, double * work, int lwork, int * info, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDsygvj) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, int, double *, double *, int, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, double *, int, double *, int, double *, double *, int, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnDsygvj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDsygvj", kApiTypeCuSolver);

    lretval = lcusolverDnDsygvj(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDsygvj cusolverDnDsygvj


#undef cusolverDnChegvj
cusolverStatus_t cusolverDnChegvj(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuComplex * A, int lda, cuComplex * B, int ldb, float * W, cuComplex * work, int lwork, int * info, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnChegvj) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, float *, cuComplex *, int, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuComplex *, int, cuComplex *, int, float *, cuComplex *, int, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnChegvj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnChegvj", kApiTypeCuSolver);

    lretval = lcusolverDnChegvj(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnChegvj cusolverDnChegvj


#undef cusolverDnZhegvj
cusolverStatus_t cusolverDnZhegvj(cusolverDnHandle_t handle, cusolverEigType_t itype, cusolverEigMode_t jobz, cublasFillMode_t uplo, int n, cuDoubleComplex * A, int lda, cuDoubleComplex * B, int ldb, double * W, cuDoubleComplex * work, int lwork, int * info, syevjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZhegvj) (cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *, syevjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigType_t, cusolverEigMode_t, cublasFillMode_t, int, cuDoubleComplex *, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, int *, syevjInfo_t))dlsym(RTLD_NEXT, "cusolverDnZhegvj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZhegvj", kApiTypeCuSolver);

    lretval = lcusolverDnZhegvj(handle, itype, jobz, uplo, n, A, lda, B, ldb, W, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZhegvj cusolverDnZhegvj


#undef cusolverDnCreateGesvdjInfo
cusolverStatus_t cusolverDnCreateGesvdjInfo(gesvdjInfo_t * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCreateGesvdjInfo) (gesvdjInfo_t *) = (cusolverStatus_t (*)(gesvdjInfo_t *))dlsym(RTLD_NEXT, "cusolverDnCreateGesvdjInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCreateGesvdjInfo", kApiTypeCuSolver);

    lretval = lcusolverDnCreateGesvdjInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCreateGesvdjInfo cusolverDnCreateGesvdjInfo


#undef cusolverDnDestroyGesvdjInfo
cusolverStatus_t cusolverDnDestroyGesvdjInfo(gesvdjInfo_t info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDestroyGesvdjInfo) (gesvdjInfo_t) = (cusolverStatus_t (*)(gesvdjInfo_t))dlsym(RTLD_NEXT, "cusolverDnDestroyGesvdjInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDestroyGesvdjInfo", kApiTypeCuSolver);

    lretval = lcusolverDnDestroyGesvdjInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDestroyGesvdjInfo cusolverDnDestroyGesvdjInfo


#undef cusolverDnXgesvdjSetTolerance
cusolverStatus_t cusolverDnXgesvdjSetTolerance(gesvdjInfo_t info, double tolerance){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvdjSetTolerance) (gesvdjInfo_t, double) = (cusolverStatus_t (*)(gesvdjInfo_t, double))dlsym(RTLD_NEXT, "cusolverDnXgesvdjSetTolerance");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvdjSetTolerance", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvdjSetTolerance(info, tolerance);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvdjSetTolerance cusolverDnXgesvdjSetTolerance


#undef cusolverDnXgesvdjSetMaxSweeps
cusolverStatus_t cusolverDnXgesvdjSetMaxSweeps(gesvdjInfo_t info, int max_sweeps){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvdjSetMaxSweeps) (gesvdjInfo_t, int) = (cusolverStatus_t (*)(gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnXgesvdjSetMaxSweeps");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvdjSetMaxSweeps", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvdjSetMaxSweeps(info, max_sweeps);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvdjSetMaxSweeps cusolverDnXgesvdjSetMaxSweeps


#undef cusolverDnXgesvdjSetSortEig
cusolverStatus_t cusolverDnXgesvdjSetSortEig(gesvdjInfo_t info, int sort_svd){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvdjSetSortEig) (gesvdjInfo_t, int) = (cusolverStatus_t (*)(gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnXgesvdjSetSortEig");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvdjSetSortEig", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvdjSetSortEig(info, sort_svd);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvdjSetSortEig cusolverDnXgesvdjSetSortEig


#undef cusolverDnXgesvdjGetResidual
cusolverStatus_t cusolverDnXgesvdjGetResidual(cusolverDnHandle_t handle, gesvdjInfo_t info, double * residual){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvdjGetResidual) (cusolverDnHandle_t, gesvdjInfo_t, double *) = (cusolverStatus_t (*)(cusolverDnHandle_t, gesvdjInfo_t, double *))dlsym(RTLD_NEXT, "cusolverDnXgesvdjGetResidual");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvdjGetResidual", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvdjGetResidual(handle, info, residual);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvdjGetResidual cusolverDnXgesvdjGetResidual


#undef cusolverDnXgesvdjGetSweeps
cusolverStatus_t cusolverDnXgesvdjGetSweeps(cusolverDnHandle_t handle, gesvdjInfo_t info, int * executed_sweeps){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvdjGetSweeps) (cusolverDnHandle_t, gesvdjInfo_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, gesvdjInfo_t, int *))dlsym(RTLD_NEXT, "cusolverDnXgesvdjGetSweeps");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvdjGetSweeps", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvdjGetSweeps(handle, info, executed_sweeps);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvdjGetSweeps cusolverDnXgesvdjGetSweeps


#undef cusolverDnSgesvdjBatched_bufferSize
cusolverStatus_t cusolverDnSgesvdjBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int m, int n, float const * A, int lda, float const * S, float const * U, int ldu, float const * V, int ldv, int * lwork, gesvdjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgesvdjBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, float const *, int, float const *, float const *, int, float const *, int, int *, gesvdjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, float const *, int, float const *, float const *, int, float const *, int, int *, gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnSgesvdjBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgesvdjBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSgesvdjBatched_bufferSize(handle, jobz, m, n, A, lda, S, U, ldu, V, ldv, lwork, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgesvdjBatched_bufferSize cusolverDnSgesvdjBatched_bufferSize


#undef cusolverDnDgesvdjBatched_bufferSize
cusolverStatus_t cusolverDnDgesvdjBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int m, int n, double const * A, int lda, double const * S, double const * U, int ldu, double const * V, int ldv, int * lwork, gesvdjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgesvdjBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, double const *, int, double const *, double const *, int, double const *, int, int *, gesvdjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, double const *, int, double const *, double const *, int, double const *, int, int *, gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnDgesvdjBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgesvdjBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDgesvdjBatched_bufferSize(handle, jobz, m, n, A, lda, S, U, ldu, V, ldv, lwork, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgesvdjBatched_bufferSize cusolverDnDgesvdjBatched_bufferSize


#undef cusolverDnCgesvdjBatched_bufferSize
cusolverStatus_t cusolverDnCgesvdjBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int m, int n, cuComplex const * A, int lda, float const * S, cuComplex const * U, int ldu, cuComplex const * V, int ldv, int * lwork, gesvdjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgesvdjBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, cuComplex const *, int, float const *, cuComplex const *, int, cuComplex const *, int, int *, gesvdjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, cuComplex const *, int, float const *, cuComplex const *, int, cuComplex const *, int, int *, gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnCgesvdjBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgesvdjBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCgesvdjBatched_bufferSize(handle, jobz, m, n, A, lda, S, U, ldu, V, ldv, lwork, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgesvdjBatched_bufferSize cusolverDnCgesvdjBatched_bufferSize


#undef cusolverDnZgesvdjBatched_bufferSize
cusolverStatus_t cusolverDnZgesvdjBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int m, int n, cuDoubleComplex const * A, int lda, double const * S, cuDoubleComplex const * U, int ldu, cuDoubleComplex const * V, int ldv, int * lwork, gesvdjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgesvdjBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, cuDoubleComplex const *, int, double const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, int *, gesvdjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, cuDoubleComplex const *, int, double const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, int *, gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnZgesvdjBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgesvdjBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZgesvdjBatched_bufferSize(handle, jobz, m, n, A, lda, S, U, ldu, V, ldv, lwork, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgesvdjBatched_bufferSize cusolverDnZgesvdjBatched_bufferSize


#undef cusolverDnSgesvdjBatched
cusolverStatus_t cusolverDnSgesvdjBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int m, int n, float * A, int lda, float * S, float * U, int ldu, float * V, int ldv, float * work, int lwork, int * info, gesvdjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgesvdjBatched) (cusolverDnHandle_t, cusolverEigMode_t, int, int, float *, int, float *, float *, int, float *, int, float *, int, int *, gesvdjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, float *, int, float *, float *, int, float *, int, float *, int, int *, gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnSgesvdjBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgesvdjBatched", kApiTypeCuSolver);

    lretval = lcusolverDnSgesvdjBatched(handle, jobz, m, n, A, lda, S, U, ldu, V, ldv, work, lwork, info, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgesvdjBatched cusolverDnSgesvdjBatched


#undef cusolverDnDgesvdjBatched
cusolverStatus_t cusolverDnDgesvdjBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int m, int n, double * A, int lda, double * S, double * U, int ldu, double * V, int ldv, double * work, int lwork, int * info, gesvdjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgesvdjBatched) (cusolverDnHandle_t, cusolverEigMode_t, int, int, double *, int, double *, double *, int, double *, int, double *, int, int *, gesvdjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, double *, int, double *, double *, int, double *, int, double *, int, int *, gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnDgesvdjBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgesvdjBatched", kApiTypeCuSolver);

    lretval = lcusolverDnDgesvdjBatched(handle, jobz, m, n, A, lda, S, U, ldu, V, ldv, work, lwork, info, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgesvdjBatched cusolverDnDgesvdjBatched


#undef cusolverDnCgesvdjBatched
cusolverStatus_t cusolverDnCgesvdjBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int m, int n, cuComplex * A, int lda, float * S, cuComplex * U, int ldu, cuComplex * V, int ldv, cuComplex * work, int lwork, int * info, gesvdjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgesvdjBatched) (cusolverDnHandle_t, cusolverEigMode_t, int, int, cuComplex *, int, float *, cuComplex *, int, cuComplex *, int, cuComplex *, int, int *, gesvdjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, cuComplex *, int, float *, cuComplex *, int, cuComplex *, int, cuComplex *, int, int *, gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnCgesvdjBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgesvdjBatched", kApiTypeCuSolver);

    lretval = lcusolverDnCgesvdjBatched(handle, jobz, m, n, A, lda, S, U, ldu, V, ldv, work, lwork, info, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgesvdjBatched cusolverDnCgesvdjBatched


#undef cusolverDnZgesvdjBatched
cusolverStatus_t cusolverDnZgesvdjBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int m, int n, cuDoubleComplex * A, int lda, double * S, cuDoubleComplex * U, int ldu, cuDoubleComplex * V, int ldv, cuDoubleComplex * work, int lwork, int * info, gesvdjInfo_t params, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgesvdjBatched) (cusolverDnHandle_t, cusolverEigMode_t, int, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *, gesvdjInfo_t, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *, gesvdjInfo_t, int))dlsym(RTLD_NEXT, "cusolverDnZgesvdjBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgesvdjBatched", kApiTypeCuSolver);

    lretval = lcusolverDnZgesvdjBatched(handle, jobz, m, n, A, lda, S, U, ldu, V, ldv, work, lwork, info, params, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgesvdjBatched cusolverDnZgesvdjBatched


#undef cusolverDnSgesvdj_bufferSize
cusolverStatus_t cusolverDnSgesvdj_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int econ, int m, int n, float const * A, int lda, float const * S, float const * U, int ldu, float const * V, int ldv, int * lwork, gesvdjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgesvdj_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, float const *, int, float const *, float const *, int, float const *, int, int *, gesvdjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, float const *, int, float const *, float const *, int, float const *, int, int *, gesvdjInfo_t))dlsym(RTLD_NEXT, "cusolverDnSgesvdj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgesvdj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSgesvdj_bufferSize(handle, jobz, econ, m, n, A, lda, S, U, ldu, V, ldv, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgesvdj_bufferSize cusolverDnSgesvdj_bufferSize


#undef cusolverDnDgesvdj_bufferSize
cusolverStatus_t cusolverDnDgesvdj_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int econ, int m, int n, double const * A, int lda, double const * S, double const * U, int ldu, double const * V, int ldv, int * lwork, gesvdjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgesvdj_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, double const *, int, double const *, double const *, int, double const *, int, int *, gesvdjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, double const *, int, double const *, double const *, int, double const *, int, int *, gesvdjInfo_t))dlsym(RTLD_NEXT, "cusolverDnDgesvdj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgesvdj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDgesvdj_bufferSize(handle, jobz, econ, m, n, A, lda, S, U, ldu, V, ldv, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgesvdj_bufferSize cusolverDnDgesvdj_bufferSize


#undef cusolverDnCgesvdj_bufferSize
cusolverStatus_t cusolverDnCgesvdj_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int econ, int m, int n, cuComplex const * A, int lda, float const * S, cuComplex const * U, int ldu, cuComplex const * V, int ldv, int * lwork, gesvdjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgesvdj_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuComplex const *, int, float const *, cuComplex const *, int, cuComplex const *, int, int *, gesvdjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuComplex const *, int, float const *, cuComplex const *, int, cuComplex const *, int, int *, gesvdjInfo_t))dlsym(RTLD_NEXT, "cusolverDnCgesvdj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgesvdj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCgesvdj_bufferSize(handle, jobz, econ, m, n, A, lda, S, U, ldu, V, ldv, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgesvdj_bufferSize cusolverDnCgesvdj_bufferSize


#undef cusolverDnZgesvdj_bufferSize
cusolverStatus_t cusolverDnZgesvdj_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int econ, int m, int n, cuDoubleComplex const * A, int lda, double const * S, cuDoubleComplex const * U, int ldu, cuDoubleComplex const * V, int ldv, int * lwork, gesvdjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgesvdj_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuDoubleComplex const *, int, double const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, int *, gesvdjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuDoubleComplex const *, int, double const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int, int *, gesvdjInfo_t))dlsym(RTLD_NEXT, "cusolverDnZgesvdj_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgesvdj_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZgesvdj_bufferSize(handle, jobz, econ, m, n, A, lda, S, U, ldu, V, ldv, lwork, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgesvdj_bufferSize cusolverDnZgesvdj_bufferSize


#undef cusolverDnSgesvdj
cusolverStatus_t cusolverDnSgesvdj(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int econ, int m, int n, float * A, int lda, float * S, float * U, int ldu, float * V, int ldv, float * work, int lwork, int * info, gesvdjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgesvdj) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, float *, int, float *, float *, int, float *, int, float *, int, int *, gesvdjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, float *, int, float *, float *, int, float *, int, float *, int, int *, gesvdjInfo_t))dlsym(RTLD_NEXT, "cusolverDnSgesvdj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgesvdj", kApiTypeCuSolver);

    lretval = lcusolverDnSgesvdj(handle, jobz, econ, m, n, A, lda, S, U, ldu, V, ldv, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgesvdj cusolverDnSgesvdj


#undef cusolverDnDgesvdj
cusolverStatus_t cusolverDnDgesvdj(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int econ, int m, int n, double * A, int lda, double * S, double * U, int ldu, double * V, int ldv, double * work, int lwork, int * info, gesvdjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgesvdj) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, double *, int, double *, double *, int, double *, int, double *, int, int *, gesvdjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, double *, int, double *, double *, int, double *, int, double *, int, int *, gesvdjInfo_t))dlsym(RTLD_NEXT, "cusolverDnDgesvdj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgesvdj", kApiTypeCuSolver);

    lretval = lcusolverDnDgesvdj(handle, jobz, econ, m, n, A, lda, S, U, ldu, V, ldv, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgesvdj cusolverDnDgesvdj


#undef cusolverDnCgesvdj
cusolverStatus_t cusolverDnCgesvdj(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int econ, int m, int n, cuComplex * A, int lda, float * S, cuComplex * U, int ldu, cuComplex * V, int ldv, cuComplex * work, int lwork, int * info, gesvdjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgesvdj) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuComplex *, int, float *, cuComplex *, int, cuComplex *, int, cuComplex *, int, int *, gesvdjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuComplex *, int, float *, cuComplex *, int, cuComplex *, int, cuComplex *, int, int *, gesvdjInfo_t))dlsym(RTLD_NEXT, "cusolverDnCgesvdj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgesvdj", kApiTypeCuSolver);

    lretval = lcusolverDnCgesvdj(handle, jobz, econ, m, n, A, lda, S, U, ldu, V, ldv, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgesvdj cusolverDnCgesvdj


#undef cusolverDnZgesvdj
cusolverStatus_t cusolverDnZgesvdj(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int econ, int m, int n, cuDoubleComplex * A, int lda, double * S, cuDoubleComplex * U, int ldu, cuDoubleComplex * V, int ldv, cuDoubleComplex * work, int lwork, int * info, gesvdjInfo_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgesvdj) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *, gesvdjInfo_t) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuDoubleComplex *, int, double *, cuDoubleComplex *, int, cuDoubleComplex *, int, cuDoubleComplex *, int, int *, gesvdjInfo_t))dlsym(RTLD_NEXT, "cusolverDnZgesvdj");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgesvdj", kApiTypeCuSolver);

    lretval = lcusolverDnZgesvdj(handle, jobz, econ, m, n, A, lda, S, U, ldu, V, ldv, work, lwork, info, params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgesvdj cusolverDnZgesvdj


#undef cusolverDnSgesvdaStridedBatched_bufferSize
cusolverStatus_t cusolverDnSgesvdaStridedBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int rank, int m, int n, float const * d_A, int lda, long long int strideA, float const * d_S, long long int strideS, float const * d_U, int ldu, long long int strideU, float const * d_V, int ldv, long long int strideV, int * lwork, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgesvdaStridedBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, float const *, int, long long int, float const *, long long int, float const *, int, long long int, float const *, int, long long int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, float const *, int, long long int, float const *, long long int, float const *, int, long long int, float const *, int, long long int, int *, int))dlsym(RTLD_NEXT, "cusolverDnSgesvdaStridedBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgesvdaStridedBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSgesvdaStridedBatched_bufferSize(handle, jobz, rank, m, n, d_A, lda, strideA, d_S, strideS, d_U, ldu, strideU, d_V, ldv, strideV, lwork, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgesvdaStridedBatched_bufferSize cusolverDnSgesvdaStridedBatched_bufferSize


#undef cusolverDnDgesvdaStridedBatched_bufferSize
cusolverStatus_t cusolverDnDgesvdaStridedBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int rank, int m, int n, double const * d_A, int lda, long long int strideA, double const * d_S, long long int strideS, double const * d_U, int ldu, long long int strideU, double const * d_V, int ldv, long long int strideV, int * lwork, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgesvdaStridedBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, double const *, int, long long int, double const *, long long int, double const *, int, long long int, double const *, int, long long int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, double const *, int, long long int, double const *, long long int, double const *, int, long long int, double const *, int, long long int, int *, int))dlsym(RTLD_NEXT, "cusolverDnDgesvdaStridedBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgesvdaStridedBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnDgesvdaStridedBatched_bufferSize(handle, jobz, rank, m, n, d_A, lda, strideA, d_S, strideS, d_U, ldu, strideU, d_V, ldv, strideV, lwork, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgesvdaStridedBatched_bufferSize cusolverDnDgesvdaStridedBatched_bufferSize


#undef cusolverDnCgesvdaStridedBatched_bufferSize
cusolverStatus_t cusolverDnCgesvdaStridedBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int rank, int m, int n, cuComplex const * d_A, int lda, long long int strideA, float const * d_S, long long int strideS, cuComplex const * d_U, int ldu, long long int strideU, cuComplex const * d_V, int ldv, long long int strideV, int * lwork, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgesvdaStridedBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuComplex const *, int, long long int, float const *, long long int, cuComplex const *, int, long long int, cuComplex const *, int, long long int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuComplex const *, int, long long int, float const *, long long int, cuComplex const *, int, long long int, cuComplex const *, int, long long int, int *, int))dlsym(RTLD_NEXT, "cusolverDnCgesvdaStridedBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgesvdaStridedBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnCgesvdaStridedBatched_bufferSize(handle, jobz, rank, m, n, d_A, lda, strideA, d_S, strideS, d_U, ldu, strideU, d_V, ldv, strideV, lwork, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgesvdaStridedBatched_bufferSize cusolverDnCgesvdaStridedBatched_bufferSize


#undef cusolverDnZgesvdaStridedBatched_bufferSize
cusolverStatus_t cusolverDnZgesvdaStridedBatched_bufferSize(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int rank, int m, int n, cuDoubleComplex const * d_A, int lda, long long int strideA, double const * d_S, long long int strideS, cuDoubleComplex const * d_U, int ldu, long long int strideU, cuDoubleComplex const * d_V, int ldv, long long int strideV, int * lwork, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgesvdaStridedBatched_bufferSize) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuDoubleComplex const *, int, long long int, double const *, long long int, cuDoubleComplex const *, int, long long int, cuDoubleComplex const *, int, long long int, int *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuDoubleComplex const *, int, long long int, double const *, long long int, cuDoubleComplex const *, int, long long int, cuDoubleComplex const *, int, long long int, int *, int))dlsym(RTLD_NEXT, "cusolverDnZgesvdaStridedBatched_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgesvdaStridedBatched_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnZgesvdaStridedBatched_bufferSize(handle, jobz, rank, m, n, d_A, lda, strideA, d_S, strideS, d_U, ldu, strideU, d_V, ldv, strideV, lwork, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgesvdaStridedBatched_bufferSize cusolverDnZgesvdaStridedBatched_bufferSize


#undef cusolverDnSgesvdaStridedBatched
cusolverStatus_t cusolverDnSgesvdaStridedBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int rank, int m, int n, float const * d_A, int lda, long long int strideA, float * d_S, long long int strideS, float * d_U, int ldu, long long int strideU, float * d_V, int ldv, long long int strideV, float * d_work, int lwork, int * d_info, double * h_R_nrmF, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSgesvdaStridedBatched) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, float const *, int, long long int, float *, long long int, float *, int, long long int, float *, int, long long int, float *, int, int *, double *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, float const *, int, long long int, float *, long long int, float *, int, long long int, float *, int, long long int, float *, int, int *, double *, int))dlsym(RTLD_NEXT, "cusolverDnSgesvdaStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSgesvdaStridedBatched", kApiTypeCuSolver);

    lretval = lcusolverDnSgesvdaStridedBatched(handle, jobz, rank, m, n, d_A, lda, strideA, d_S, strideS, d_U, ldu, strideU, d_V, ldv, strideV, d_work, lwork, d_info, h_R_nrmF, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSgesvdaStridedBatched cusolverDnSgesvdaStridedBatched


#undef cusolverDnDgesvdaStridedBatched
cusolverStatus_t cusolverDnDgesvdaStridedBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int rank, int m, int n, double const * d_A, int lda, long long int strideA, double * d_S, long long int strideS, double * d_U, int ldu, long long int strideU, double * d_V, int ldv, long long int strideV, double * d_work, int lwork, int * d_info, double * h_R_nrmF, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDgesvdaStridedBatched) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, double const *, int, long long int, double *, long long int, double *, int, long long int, double *, int, long long int, double *, int, int *, double *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, double const *, int, long long int, double *, long long int, double *, int, long long int, double *, int, long long int, double *, int, int *, double *, int))dlsym(RTLD_NEXT, "cusolverDnDgesvdaStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDgesvdaStridedBatched", kApiTypeCuSolver);

    lretval = lcusolverDnDgesvdaStridedBatched(handle, jobz, rank, m, n, d_A, lda, strideA, d_S, strideS, d_U, ldu, strideU, d_V, ldv, strideV, d_work, lwork, d_info, h_R_nrmF, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDgesvdaStridedBatched cusolverDnDgesvdaStridedBatched


#undef cusolverDnCgesvdaStridedBatched
cusolverStatus_t cusolverDnCgesvdaStridedBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int rank, int m, int n, cuComplex const * d_A, int lda, long long int strideA, float * d_S, long long int strideS, cuComplex * d_U, int ldu, long long int strideU, cuComplex * d_V, int ldv, long long int strideV, cuComplex * d_work, int lwork, int * d_info, double * h_R_nrmF, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCgesvdaStridedBatched) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuComplex const *, int, long long int, float *, long long int, cuComplex *, int, long long int, cuComplex *, int, long long int, cuComplex *, int, int *, double *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuComplex const *, int, long long int, float *, long long int, cuComplex *, int, long long int, cuComplex *, int, long long int, cuComplex *, int, int *, double *, int))dlsym(RTLD_NEXT, "cusolverDnCgesvdaStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCgesvdaStridedBatched", kApiTypeCuSolver);

    lretval = lcusolverDnCgesvdaStridedBatched(handle, jobz, rank, m, n, d_A, lda, strideA, d_S, strideS, d_U, ldu, strideU, d_V, ldv, strideV, d_work, lwork, d_info, h_R_nrmF, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCgesvdaStridedBatched cusolverDnCgesvdaStridedBatched


#undef cusolverDnZgesvdaStridedBatched
cusolverStatus_t cusolverDnZgesvdaStridedBatched(cusolverDnHandle_t handle, cusolverEigMode_t jobz, int rank, int m, int n, cuDoubleComplex const * d_A, int lda, long long int strideA, double * d_S, long long int strideS, cuDoubleComplex * d_U, int ldu, long long int strideU, cuDoubleComplex * d_V, int ldv, long long int strideV, cuDoubleComplex * d_work, int lwork, int * d_info, double * h_R_nrmF, int batchSize){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnZgesvdaStridedBatched) (cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuDoubleComplex const *, int, long long int, double *, long long int, cuDoubleComplex *, int, long long int, cuDoubleComplex *, int, long long int, cuDoubleComplex *, int, int *, double *, int) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverEigMode_t, int, int, int, cuDoubleComplex const *, int, long long int, double *, long long int, cuDoubleComplex *, int, long long int, cuDoubleComplex *, int, long long int, cuDoubleComplex *, int, int *, double *, int))dlsym(RTLD_NEXT, "cusolverDnZgesvdaStridedBatched");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnZgesvdaStridedBatched", kApiTypeCuSolver);

    lretval = lcusolverDnZgesvdaStridedBatched(handle, jobz, rank, m, n, d_A, lda, strideA, d_S, strideS, d_U, ldu, strideU, d_V, ldv, strideV, d_work, lwork, d_info, h_R_nrmF, batchSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnZgesvdaStridedBatched cusolverDnZgesvdaStridedBatched


#undef cusolverDnCreateParams
cusolverStatus_t cusolverDnCreateParams(cusolverDnParams_t * params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnCreateParams) (cusolverDnParams_t *) = (cusolverStatus_t (*)(cusolverDnParams_t *))dlsym(RTLD_NEXT, "cusolverDnCreateParams");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnCreateParams", kApiTypeCuSolver);

    lretval = lcusolverDnCreateParams(params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnCreateParams cusolverDnCreateParams


#undef cusolverDnDestroyParams
cusolverStatus_t cusolverDnDestroyParams(cusolverDnParams_t params){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnDestroyParams) (cusolverDnParams_t) = (cusolverStatus_t (*)(cusolverDnParams_t))dlsym(RTLD_NEXT, "cusolverDnDestroyParams");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnDestroyParams", kApiTypeCuSolver);

    lretval = lcusolverDnDestroyParams(params);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnDestroyParams cusolverDnDestroyParams


#undef cusolverDnSetAdvOptions
cusolverStatus_t cusolverDnSetAdvOptions(cusolverDnParams_t params, cusolverDnFunction_t function, cusolverAlgMode_t algo){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSetAdvOptions) (cusolverDnParams_t, cusolverDnFunction_t, cusolverAlgMode_t) = (cusolverStatus_t (*)(cusolverDnParams_t, cusolverDnFunction_t, cusolverAlgMode_t))dlsym(RTLD_NEXT, "cusolverDnSetAdvOptions");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSetAdvOptions", kApiTypeCuSolver);

    lretval = lcusolverDnSetAdvOptions(params, function, algo);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSetAdvOptions cusolverDnSetAdvOptions


#undef cusolverDnPotrf_bufferSize
cusolverStatus_t cusolverDnPotrf_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType computeType, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnPotrf_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *))dlsym(RTLD_NEXT, "cusolverDnPotrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnPotrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnPotrf_bufferSize(handle, params, uplo, n, dataTypeA, A, lda, computeType, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnPotrf_bufferSize cusolverDnPotrf_bufferSize


#undef cusolverDnPotrf
cusolverStatus_t cusolverDnPotrf(cusolverDnHandle_t handle, cusolverDnParams_t params, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType computeType, void * pBuffer, size_t workspaceInBytes, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnPotrf) (cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnPotrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnPotrf", kApiTypeCuSolver);

    lretval = lcusolverDnPotrf(handle, params, uplo, n, dataTypeA, A, lda, computeType, pBuffer, workspaceInBytes, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnPotrf cusolverDnPotrf


#undef cusolverDnPotrs
cusolverStatus_t cusolverDnPotrs(cusolverDnHandle_t handle, cusolverDnParams_t params, cublasFillMode_t uplo, int64_t n, int64_t nrhs, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeB, void * B, int64_t ldb, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnPotrs) (cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void *, int64_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverDnPotrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnPotrs", kApiTypeCuSolver);

    lretval = lcusolverDnPotrs(handle, params, uplo, n, nrhs, dataTypeA, A, lda, dataTypeB, B, ldb, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnPotrs cusolverDnPotrs


#undef cusolverDnGeqrf_bufferSize
cusolverStatus_t cusolverDnGeqrf_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, int64_t m, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeTau, void const * tau, cudaDataType computeType, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnGeqrf_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, size_t *))dlsym(RTLD_NEXT, "cusolverDnGeqrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnGeqrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnGeqrf_bufferSize(handle, params, m, n, dataTypeA, A, lda, dataTypeTau, tau, computeType, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnGeqrf_bufferSize cusolverDnGeqrf_bufferSize


#undef cusolverDnGeqrf
cusolverStatus_t cusolverDnGeqrf(cusolverDnHandle_t handle, cusolverDnParams_t params, int64_t m, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType dataTypeTau, void * tau, cudaDataType computeType, void * pBuffer, size_t workspaceInBytes, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnGeqrf) (cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnGeqrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnGeqrf", kApiTypeCuSolver);

    lretval = lcusolverDnGeqrf(handle, params, m, n, dataTypeA, A, lda, dataTypeTau, tau, computeType, pBuffer, workspaceInBytes, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnGeqrf cusolverDnGeqrf


#undef cusolverDnGetrf_bufferSize
cusolverStatus_t cusolverDnGetrf_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, int64_t m, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType computeType, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnGetrf_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *))dlsym(RTLD_NEXT, "cusolverDnGetrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnGetrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnGetrf_bufferSize(handle, params, m, n, dataTypeA, A, lda, computeType, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnGetrf_bufferSize cusolverDnGetrf_bufferSize


#undef cusolverDnGetrf
cusolverStatus_t cusolverDnGetrf(cusolverDnHandle_t handle, cusolverDnParams_t params, int64_t m, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, int64_t * ipiv, cudaDataType computeType, void * pBuffer, size_t workspaceInBytes, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnGetrf) (cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void *, int64_t, int64_t *, cudaDataType, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void *, int64_t, int64_t *, cudaDataType, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnGetrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnGetrf", kApiTypeCuSolver);

    lretval = lcusolverDnGetrf(handle, params, m, n, dataTypeA, A, lda, ipiv, computeType, pBuffer, workspaceInBytes, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnGetrf cusolverDnGetrf


#undef cusolverDnGetrs
cusolverStatus_t cusolverDnGetrs(cusolverDnHandle_t handle, cusolverDnParams_t params, cublasOperation_t trans, int64_t n, int64_t nrhs, cudaDataType dataTypeA, void const * A, int64_t lda, int64_t const * ipiv, cudaDataType dataTypeB, void * B, int64_t ldb, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnGetrs) (cusolverDnHandle_t, cusolverDnParams_t, cublasOperation_t, int64_t, int64_t, cudaDataType, void const *, int64_t, int64_t const *, cudaDataType, void *, int64_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cublasOperation_t, int64_t, int64_t, cudaDataType, void const *, int64_t, int64_t const *, cudaDataType, void *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverDnGetrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnGetrs", kApiTypeCuSolver);

    lretval = lcusolverDnGetrs(handle, params, trans, n, nrhs, dataTypeA, A, lda, ipiv, dataTypeB, B, ldb, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnGetrs cusolverDnGetrs


#undef cusolverDnSyevd_bufferSize
cusolverStatus_t cusolverDnSyevd_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeW, void const * W, cudaDataType computeType, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSyevd_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, size_t *))dlsym(RTLD_NEXT, "cusolverDnSyevd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSyevd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSyevd_bufferSize(handle, params, jobz, uplo, n, dataTypeA, A, lda, dataTypeW, W, computeType, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSyevd_bufferSize cusolverDnSyevd_bufferSize


#undef cusolverDnSyevd
cusolverStatus_t cusolverDnSyevd(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType dataTypeW, void * W, cudaDataType computeType, void * pBuffer, size_t workspaceInBytes, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSyevd) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnSyevd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSyevd", kApiTypeCuSolver);

    lretval = lcusolverDnSyevd(handle, params, jobz, uplo, n, dataTypeA, A, lda, dataTypeW, W, computeType, pBuffer, workspaceInBytes, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSyevd cusolverDnSyevd


#undef cusolverDnSyevdx_bufferSize
cusolverStatus_t cusolverDnSyevdx_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, void * vl, void * vu, int64_t il, int64_t iu, int64_t * h_meig, cudaDataType dataTypeW, void const * W, cudaDataType computeType, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSyevdx_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, void *, void *, int64_t, int64_t, int64_t *, cudaDataType, void const *, cudaDataType, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, void *, void *, int64_t, int64_t, int64_t *, cudaDataType, void const *, cudaDataType, size_t *))dlsym(RTLD_NEXT, "cusolverDnSyevdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSyevdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnSyevdx_bufferSize(handle, params, jobz, range, uplo, n, dataTypeA, A, lda, vl, vu, il, iu, h_meig, dataTypeW, W, computeType, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSyevdx_bufferSize cusolverDnSyevdx_bufferSize


#undef cusolverDnSyevdx
cusolverStatus_t cusolverDnSyevdx(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, void * vl, void * vu, int64_t il, int64_t iu, int64_t * meig64, cudaDataType dataTypeW, void * W, cudaDataType computeType, void * pBuffer, size_t workspaceInBytes, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnSyevdx) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, void *, void *, int64_t, int64_t, int64_t *, cudaDataType, void *, cudaDataType, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, void *, void *, int64_t, int64_t, int64_t *, cudaDataType, void *, cudaDataType, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnSyevdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnSyevdx", kApiTypeCuSolver);

    lretval = lcusolverDnSyevdx(handle, params, jobz, range, uplo, n, dataTypeA, A, lda, vl, vu, il, iu, meig64, dataTypeW, W, computeType, pBuffer, workspaceInBytes, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnSyevdx cusolverDnSyevdx


#undef cusolverDnGesvd_bufferSize
cusolverStatus_t cusolverDnGesvd_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, signed char jobu, signed char jobvt, int64_t m, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeS, void const * S, cudaDataType dataTypeU, void const * U, int64_t ldu, cudaDataType dataTypeVT, void const * VT, int64_t ldvt, cudaDataType computeType, size_t * workspaceInBytes){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnGesvd_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, void const *, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, void const *, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *))dlsym(RTLD_NEXT, "cusolverDnGesvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnGesvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnGesvd_bufferSize(handle, params, jobu, jobvt, m, n, dataTypeA, A, lda, dataTypeS, S, dataTypeU, U, ldu, dataTypeVT, VT, ldvt, computeType, workspaceInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnGesvd_bufferSize cusolverDnGesvd_bufferSize


#undef cusolverDnGesvd
cusolverStatus_t cusolverDnGesvd(cusolverDnHandle_t handle, cusolverDnParams_t params, signed char jobu, signed char jobvt, int64_t m, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType dataTypeS, void * S, cudaDataType dataTypeU, void * U, int64_t ldu, cudaDataType dataTypeVT, void * VT, int64_t ldvt, cudaDataType computeType, void * pBuffer, size_t workspaceInBytes, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnGesvd) (cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnGesvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnGesvd", kApiTypeCuSolver);

    lretval = lcusolverDnGesvd(handle, params, jobu, jobvt, m, n, dataTypeA, A, lda, dataTypeS, S, dataTypeU, U, ldu, dataTypeVT, VT, ldvt, computeType, pBuffer, workspaceInBytes, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnGesvd cusolverDnGesvd


#undef cusolverDnXpotrf_bufferSize
cusolverStatus_t cusolverDnXpotrf_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType computeType, size_t * workspaceInBytesOnDevice, size_t * workspaceInBytesOnHost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXpotrf_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverDnXpotrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXpotrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnXpotrf_bufferSize(handle, params, uplo, n, dataTypeA, A, lda, computeType, workspaceInBytesOnDevice, workspaceInBytesOnHost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXpotrf_bufferSize cusolverDnXpotrf_bufferSize


#undef cusolverDnXpotrf
cusolverStatus_t cusolverDnXpotrf(cusolverDnHandle_t handle, cusolverDnParams_t params, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType computeType, void * bufferOnDevice, size_t workspaceInBytesOnDevice, void * bufferOnHost, size_t workspaceInBytesOnHost, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXpotrf) (cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnXpotrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXpotrf", kApiTypeCuSolver);

    lretval = lcusolverDnXpotrf(handle, params, uplo, n, dataTypeA, A, lda, computeType, bufferOnDevice, workspaceInBytesOnDevice, bufferOnHost, workspaceInBytesOnHost, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXpotrf cusolverDnXpotrf


#undef cusolverDnXpotrs
cusolverStatus_t cusolverDnXpotrs(cusolverDnHandle_t handle, cusolverDnParams_t params, cublasFillMode_t uplo, int64_t n, int64_t nrhs, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeB, void * B, int64_t ldb, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXpotrs) (cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void *, int64_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cublasFillMode_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverDnXpotrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXpotrs", kApiTypeCuSolver);

    lretval = lcusolverDnXpotrs(handle, params, uplo, n, nrhs, dataTypeA, A, lda, dataTypeB, B, ldb, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXpotrs cusolverDnXpotrs


#undef cusolverDnXgeqrf_bufferSize
cusolverStatus_t cusolverDnXgeqrf_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, int64_t m, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeTau, void const * tau, cudaDataType computeType, size_t * workspaceInBytesOnDevice, size_t * workspaceInBytesOnHost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgeqrf_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverDnXgeqrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgeqrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnXgeqrf_bufferSize(handle, params, m, n, dataTypeA, A, lda, dataTypeTau, tau, computeType, workspaceInBytesOnDevice, workspaceInBytesOnHost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgeqrf_bufferSize cusolverDnXgeqrf_bufferSize


#undef cusolverDnXgeqrf
cusolverStatus_t cusolverDnXgeqrf(cusolverDnHandle_t handle, cusolverDnParams_t params, int64_t m, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType dataTypeTau, void * tau, cudaDataType computeType, void * bufferOnDevice, size_t workspaceInBytesOnDevice, void * bufferOnHost, size_t workspaceInBytesOnHost, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgeqrf) (cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, size_t, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, size_t, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnXgeqrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgeqrf", kApiTypeCuSolver);

    lretval = lcusolverDnXgeqrf(handle, params, m, n, dataTypeA, A, lda, dataTypeTau, tau, computeType, bufferOnDevice, workspaceInBytesOnDevice, bufferOnHost, workspaceInBytesOnHost, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgeqrf cusolverDnXgeqrf


#undef cusolverDnXgetrf_bufferSize
cusolverStatus_t cusolverDnXgetrf_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, int64_t m, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType computeType, size_t * workspaceInBytesOnDevice, size_t * workspaceInBytesOnHost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgetrf_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverDnXgetrf_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgetrf_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnXgetrf_bufferSize(handle, params, m, n, dataTypeA, A, lda, computeType, workspaceInBytesOnDevice, workspaceInBytesOnHost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgetrf_bufferSize cusolverDnXgetrf_bufferSize


#undef cusolverDnXgetrf
cusolverStatus_t cusolverDnXgetrf(cusolverDnHandle_t handle, cusolverDnParams_t params, int64_t m, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, int64_t * ipiv, cudaDataType computeType, void * bufferOnDevice, size_t workspaceInBytesOnDevice, void * bufferOnHost, size_t workspaceInBytesOnHost, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgetrf) (cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void *, int64_t, int64_t *, cudaDataType, void *, size_t, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, int64_t, int64_t, cudaDataType, void *, int64_t, int64_t *, cudaDataType, void *, size_t, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnXgetrf");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgetrf", kApiTypeCuSolver);

    lretval = lcusolverDnXgetrf(handle, params, m, n, dataTypeA, A, lda, ipiv, computeType, bufferOnDevice, workspaceInBytesOnDevice, bufferOnHost, workspaceInBytesOnHost, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgetrf cusolverDnXgetrf


#undef cusolverDnXgetrs
cusolverStatus_t cusolverDnXgetrs(cusolverDnHandle_t handle, cusolverDnParams_t params, cublasOperation_t trans, int64_t n, int64_t nrhs, cudaDataType dataTypeA, void const * A, int64_t lda, int64_t const * ipiv, cudaDataType dataTypeB, void * B, int64_t ldb, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgetrs) (cusolverDnHandle_t, cusolverDnParams_t, cublasOperation_t, int64_t, int64_t, cudaDataType, void const *, int64_t, int64_t const *, cudaDataType, void *, int64_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cublasOperation_t, int64_t, int64_t, cudaDataType, void const *, int64_t, int64_t const *, cudaDataType, void *, int64_t, int *))dlsym(RTLD_NEXT, "cusolverDnXgetrs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgetrs", kApiTypeCuSolver);

    lretval = lcusolverDnXgetrs(handle, params, trans, n, nrhs, dataTypeA, A, lda, ipiv, dataTypeB, B, ldb, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgetrs cusolverDnXgetrs


#undef cusolverDnXsyevd_bufferSize
cusolverStatus_t cusolverDnXsyevd_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeW, void const * W, cudaDataType computeType, size_t * workspaceInBytesOnDevice, size_t * workspaceInBytesOnHost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsyevd_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverDnXsyevd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsyevd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnXsyevd_bufferSize(handle, params, jobz, uplo, n, dataTypeA, A, lda, dataTypeW, W, computeType, workspaceInBytesOnDevice, workspaceInBytesOnHost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsyevd_bufferSize cusolverDnXsyevd_bufferSize


#undef cusolverDnXsyevd
cusolverStatus_t cusolverDnXsyevd(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType dataTypeW, void * W, cudaDataType computeType, void * bufferOnDevice, size_t workspaceInBytesOnDevice, void * bufferOnHost, size_t workspaceInBytesOnHost, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsyevd) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, size_t, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, size_t, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnXsyevd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsyevd", kApiTypeCuSolver);

    lretval = lcusolverDnXsyevd(handle, params, jobz, uplo, n, dataTypeA, A, lda, dataTypeW, W, computeType, bufferOnDevice, workspaceInBytesOnDevice, bufferOnHost, workspaceInBytesOnHost, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsyevd cusolverDnXsyevd


#undef cusolverDnXsyevdx_bufferSize
cusolverStatus_t cusolverDnXsyevdx_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, void * vl, void * vu, int64_t il, int64_t iu, int64_t * h_meig, cudaDataType dataTypeW, void const * W, cudaDataType computeType, size_t * workspaceInBytesOnDevice, size_t * workspaceInBytesOnHost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsyevdx_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, void *, void *, int64_t, int64_t, int64_t *, cudaDataType, void const *, cudaDataType, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int64_t, cudaDataType, void const *, int64_t, void *, void *, int64_t, int64_t, int64_t *, cudaDataType, void const *, cudaDataType, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverDnXsyevdx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsyevdx_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnXsyevdx_bufferSize(handle, params, jobz, range, uplo, n, dataTypeA, A, lda, vl, vu, il, iu, h_meig, dataTypeW, W, computeType, workspaceInBytesOnDevice, workspaceInBytesOnHost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsyevdx_bufferSize cusolverDnXsyevdx_bufferSize


#undef cusolverDnXsyevdx
cusolverStatus_t cusolverDnXsyevdx(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, cusolverEigRange_t range, cublasFillMode_t uplo, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, void * vl, void * vu, int64_t il, int64_t iu, int64_t * meig64, cudaDataType dataTypeW, void * W, cudaDataType computeType, void * bufferOnDevice, size_t workspaceInBytesOnDevice, void * bufferOnHost, size_t workspaceInBytesOnHost, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXsyevdx) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, void *, void *, int64_t, int64_t, int64_t *, cudaDataType, void *, cudaDataType, void *, size_t, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, cusolverEigRange_t, cublasFillMode_t, int64_t, cudaDataType, void *, int64_t, void *, void *, int64_t, int64_t, int64_t *, cudaDataType, void *, cudaDataType, void *, size_t, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnXsyevdx");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXsyevdx", kApiTypeCuSolver);

    lretval = lcusolverDnXsyevdx(handle, params, jobz, range, uplo, n, dataTypeA, A, lda, vl, vu, il, iu, meig64, dataTypeW, W, computeType, bufferOnDevice, workspaceInBytesOnDevice, bufferOnHost, workspaceInBytesOnHost, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXsyevdx cusolverDnXsyevdx


#undef cusolverDnXgesvd_bufferSize
cusolverStatus_t cusolverDnXgesvd_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, signed char jobu, signed char jobvt, int64_t m, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeS, void const * S, cudaDataType dataTypeU, void const * U, int64_t ldu, cudaDataType dataTypeVT, void const * VT, int64_t ldvt, cudaDataType computeType, size_t * workspaceInBytesOnDevice, size_t * workspaceInBytesOnHost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvd_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, void const *, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, void const *, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverDnXgesvd_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvd_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvd_bufferSize(handle, params, jobu, jobvt, m, n, dataTypeA, A, lda, dataTypeS, S, dataTypeU, U, ldu, dataTypeVT, VT, ldvt, computeType, workspaceInBytesOnDevice, workspaceInBytesOnHost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvd_bufferSize cusolverDnXgesvd_bufferSize


#undef cusolverDnXgesvd
cusolverStatus_t cusolverDnXgesvd(cusolverDnHandle_t handle, cusolverDnParams_t params, signed char jobu, signed char jobvt, int64_t m, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType dataTypeS, void * S, cudaDataType dataTypeU, void * U, int64_t ldu, cudaDataType dataTypeVT, void * VT, int64_t ldvt, cudaDataType computeType, void * bufferOnDevice, size_t workspaceInBytesOnDevice, void * bufferOnHost, size_t workspaceInBytesOnHost, int * info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvd) (cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnXgesvd");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvd", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvd(handle, params, jobu, jobvt, m, n, dataTypeA, A, lda, dataTypeS, S, dataTypeU, U, ldu, dataTypeVT, VT, ldvt, computeType, bufferOnDevice, workspaceInBytesOnDevice, bufferOnHost, workspaceInBytesOnHost, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvd cusolverDnXgesvd


#undef cusolverDnXgesvdp_bufferSize
cusolverStatus_t cusolverDnXgesvdp_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, int econ, int64_t m, int64_t n, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeS, void const * S, cudaDataType dataTypeU, void const * U, int64_t ldu, cudaDataType dataTypeV, void const * V, int64_t ldv, cudaDataType computeType, size_t * workspaceInBytesOnDevice, size_t * workspaceInBytesOnHost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvdp_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, int, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, void const *, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, int, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, void const *, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverDnXgesvdp_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvdp_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvdp_bufferSize(handle, params, jobz, econ, m, n, dataTypeA, A, lda, dataTypeS, S, dataTypeU, U, ldu, dataTypeV, V, ldv, computeType, workspaceInBytesOnDevice, workspaceInBytesOnHost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvdp_bufferSize cusolverDnXgesvdp_bufferSize


#undef cusolverDnXgesvdp
cusolverStatus_t cusolverDnXgesvdp(cusolverDnHandle_t handle, cusolverDnParams_t params, cusolverEigMode_t jobz, int econ, int64_t m, int64_t n, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType dataTypeS, void * S, cudaDataType dataTypeU, void * U, int64_t ldu, cudaDataType dataTypeV, void * V, int64_t ldv, cudaDataType computeType, void * bufferOnDevice, size_t workspaceInBytesOnDevice, void * bufferOnHost, size_t workspaceInBytesOnHost, int * d_info, double * h_err_sigma){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvdp) (cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, int, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, void *, size_t, int *, double *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, cusolverEigMode_t, int, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, void *, size_t, int *, double *))dlsym(RTLD_NEXT, "cusolverDnXgesvdp");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvdp", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvdp(handle, params, jobz, econ, m, n, dataTypeA, A, lda, dataTypeS, S, dataTypeU, U, ldu, dataTypeV, V, ldv, computeType, bufferOnDevice, workspaceInBytesOnDevice, bufferOnHost, workspaceInBytesOnHost, d_info, h_err_sigma);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvdp cusolverDnXgesvdp


#undef cusolverDnXgesvdr_bufferSize
cusolverStatus_t cusolverDnXgesvdr_bufferSize(cusolverDnHandle_t handle, cusolverDnParams_t params, signed char jobu, signed char jobv, int64_t m, int64_t n, int64_t k, int64_t p, int64_t niters, cudaDataType dataTypeA, void const * A, int64_t lda, cudaDataType dataTypeSrand, void const * Srand, cudaDataType dataTypeUrand, void const * Urand, int64_t ldUrand, cudaDataType dataTypeVrand, void const * Vrand, int64_t ldVrand, cudaDataType computeType, size_t * workspaceInBytesOnDevice, size_t * workspaceInBytesOnHost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvdr_bufferSize) (cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, int64_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, void const *, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, int64_t, int64_t, int64_t, cudaDataType, void const *, int64_t, cudaDataType, void const *, cudaDataType, void const *, int64_t, cudaDataType, void const *, int64_t, cudaDataType, size_t *, size_t *))dlsym(RTLD_NEXT, "cusolverDnXgesvdr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvdr_bufferSize", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvdr_bufferSize(handle, params, jobu, jobv, m, n, k, p, niters, dataTypeA, A, lda, dataTypeSrand, Srand, dataTypeUrand, Urand, ldUrand, dataTypeVrand, Vrand, ldVrand, computeType, workspaceInBytesOnDevice, workspaceInBytesOnHost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvdr_bufferSize cusolverDnXgesvdr_bufferSize


#undef cusolverDnXgesvdr
cusolverStatus_t cusolverDnXgesvdr(cusolverDnHandle_t handle, cusolverDnParams_t params, signed char jobu, signed char jobv, int64_t m, int64_t n, int64_t k, int64_t p, int64_t niters, cudaDataType dataTypeA, void * A, int64_t lda, cudaDataType dataTypeSrand, void * Srand, cudaDataType dataTypeUrand, void * Urand, int64_t ldUrand, cudaDataType dataTypeVrand, void * Vrand, int64_t ldVrand, cudaDataType computeType, void * bufferOnDevice, size_t workspaceInBytesOnDevice, void * bufferOnHost, size_t workspaceInBytesOnHost, int * d_info){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverDnXgesvdr) (cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, int64_t, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, void *, size_t, int *) = (cusolverStatus_t (*)(cusolverDnHandle_t, cusolverDnParams_t, signed char, signed char, int64_t, int64_t, int64_t, int64_t, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, cudaDataType, void *, int64_t, cudaDataType, void *, int64_t, cudaDataType, void *, size_t, void *, size_t, int *))dlsym(RTLD_NEXT, "cusolverDnXgesvdr");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverDnXgesvdr", kApiTypeCuSolver);

    lretval = lcusolverDnXgesvdr(handle, params, jobu, jobv, m, n, k, p, niters, dataTypeA, A, lda, dataTypeSrand, Srand, dataTypeUrand, Urand, ldUrand, dataTypeVrand, Vrand, ldVrand, computeType, bufferOnDevice, workspaceInBytesOnDevice, bufferOnHost, workspaceInBytesOnHost, d_info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverDnXgesvdr cusolverDnXgesvdr

