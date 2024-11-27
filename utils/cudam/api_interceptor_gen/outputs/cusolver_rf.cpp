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

#undef cusolverRfCreate
cusolverStatus_t cusolverRfCreate(cusolverRfHandle_t * handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfCreate) (cusolverRfHandle_t *) = (cusolverStatus_t (*)(cusolverRfHandle_t *))dlsym(RTLD_NEXT, "cusolverRfCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfCreate", kApiTypeCuSolver);

    lretval = lcusolverRfCreate(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfCreate cusolverRfCreate


#undef cusolverRfDestroy
cusolverStatus_t cusolverRfDestroy(cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfDestroy) (cusolverRfHandle_t) = (cusolverStatus_t (*)(cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfDestroy", kApiTypeCuSolver);

    lretval = lcusolverRfDestroy(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfDestroy cusolverRfDestroy


#undef cusolverRfGetMatrixFormat
cusolverStatus_t cusolverRfGetMatrixFormat(cusolverRfHandle_t handle, cusolverRfMatrixFormat_t * format, cusolverRfUnitDiagonal_t * diag){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfGetMatrixFormat) (cusolverRfHandle_t, cusolverRfMatrixFormat_t *, cusolverRfUnitDiagonal_t *) = (cusolverStatus_t (*)(cusolverRfHandle_t, cusolverRfMatrixFormat_t *, cusolverRfUnitDiagonal_t *))dlsym(RTLD_NEXT, "cusolverRfGetMatrixFormat");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfGetMatrixFormat", kApiTypeCuSolver);

    lretval = lcusolverRfGetMatrixFormat(handle, format, diag);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfGetMatrixFormat cusolverRfGetMatrixFormat


#undef cusolverRfSetMatrixFormat
cusolverStatus_t cusolverRfSetMatrixFormat(cusolverRfHandle_t handle, cusolverRfMatrixFormat_t format, cusolverRfUnitDiagonal_t diag){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfSetMatrixFormat) (cusolverRfHandle_t, cusolverRfMatrixFormat_t, cusolverRfUnitDiagonal_t) = (cusolverStatus_t (*)(cusolverRfHandle_t, cusolverRfMatrixFormat_t, cusolverRfUnitDiagonal_t))dlsym(RTLD_NEXT, "cusolverRfSetMatrixFormat");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfSetMatrixFormat", kApiTypeCuSolver);

    lretval = lcusolverRfSetMatrixFormat(handle, format, diag);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfSetMatrixFormat cusolverRfSetMatrixFormat


#undef cusolverRfSetNumericProperties
cusolverStatus_t cusolverRfSetNumericProperties(cusolverRfHandle_t handle, double zero, double boost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfSetNumericProperties) (cusolverRfHandle_t, double, double) = (cusolverStatus_t (*)(cusolverRfHandle_t, double, double))dlsym(RTLD_NEXT, "cusolverRfSetNumericProperties");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfSetNumericProperties", kApiTypeCuSolver);

    lretval = lcusolverRfSetNumericProperties(handle, zero, boost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfSetNumericProperties cusolverRfSetNumericProperties


#undef cusolverRfGetNumericProperties
cusolverStatus_t cusolverRfGetNumericProperties(cusolverRfHandle_t handle, double * zero, double * boost){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfGetNumericProperties) (cusolverRfHandle_t, double *, double *) = (cusolverStatus_t (*)(cusolverRfHandle_t, double *, double *))dlsym(RTLD_NEXT, "cusolverRfGetNumericProperties");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfGetNumericProperties", kApiTypeCuSolver);

    lretval = lcusolverRfGetNumericProperties(handle, zero, boost);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfGetNumericProperties cusolverRfGetNumericProperties


#undef cusolverRfGetNumericBoostReport
cusolverStatus_t cusolverRfGetNumericBoostReport(cusolverRfHandle_t handle, cusolverRfNumericBoostReport_t * report){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfGetNumericBoostReport) (cusolverRfHandle_t, cusolverRfNumericBoostReport_t *) = (cusolverStatus_t (*)(cusolverRfHandle_t, cusolverRfNumericBoostReport_t *))dlsym(RTLD_NEXT, "cusolverRfGetNumericBoostReport");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfGetNumericBoostReport", kApiTypeCuSolver);

    lretval = lcusolverRfGetNumericBoostReport(handle, report);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfGetNumericBoostReport cusolverRfGetNumericBoostReport


#undef cusolverRfSetAlgs
cusolverStatus_t cusolverRfSetAlgs(cusolverRfHandle_t handle, cusolverRfFactorization_t factAlg, cusolverRfTriangularSolve_t solveAlg){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfSetAlgs) (cusolverRfHandle_t, cusolverRfFactorization_t, cusolverRfTriangularSolve_t) = (cusolverStatus_t (*)(cusolverRfHandle_t, cusolverRfFactorization_t, cusolverRfTriangularSolve_t))dlsym(RTLD_NEXT, "cusolverRfSetAlgs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfSetAlgs", kApiTypeCuSolver);

    lretval = lcusolverRfSetAlgs(handle, factAlg, solveAlg);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfSetAlgs cusolverRfSetAlgs


#undef cusolverRfGetAlgs
cusolverStatus_t cusolverRfGetAlgs(cusolverRfHandle_t handle, cusolverRfFactorization_t * factAlg, cusolverRfTriangularSolve_t * solveAlg){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfGetAlgs) (cusolverRfHandle_t, cusolverRfFactorization_t *, cusolverRfTriangularSolve_t *) = (cusolverStatus_t (*)(cusolverRfHandle_t, cusolverRfFactorization_t *, cusolverRfTriangularSolve_t *))dlsym(RTLD_NEXT, "cusolverRfGetAlgs");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfGetAlgs", kApiTypeCuSolver);

    lretval = lcusolverRfGetAlgs(handle, factAlg, solveAlg);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfGetAlgs cusolverRfGetAlgs


#undef cusolverRfGetResetValuesFastMode
cusolverStatus_t cusolverRfGetResetValuesFastMode(cusolverRfHandle_t handle, cusolverRfResetValuesFastMode_t * fastMode){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfGetResetValuesFastMode) (cusolverRfHandle_t, cusolverRfResetValuesFastMode_t *) = (cusolverStatus_t (*)(cusolverRfHandle_t, cusolverRfResetValuesFastMode_t *))dlsym(RTLD_NEXT, "cusolverRfGetResetValuesFastMode");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfGetResetValuesFastMode", kApiTypeCuSolver);

    lretval = lcusolverRfGetResetValuesFastMode(handle, fastMode);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfGetResetValuesFastMode cusolverRfGetResetValuesFastMode


#undef cusolverRfSetResetValuesFastMode
cusolverStatus_t cusolverRfSetResetValuesFastMode(cusolverRfHandle_t handle, cusolverRfResetValuesFastMode_t fastMode){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfSetResetValuesFastMode) (cusolverRfHandle_t, cusolverRfResetValuesFastMode_t) = (cusolverStatus_t (*)(cusolverRfHandle_t, cusolverRfResetValuesFastMode_t))dlsym(RTLD_NEXT, "cusolverRfSetResetValuesFastMode");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfSetResetValuesFastMode", kApiTypeCuSolver);

    lretval = lcusolverRfSetResetValuesFastMode(handle, fastMode);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfSetResetValuesFastMode cusolverRfSetResetValuesFastMode


#undef cusolverRfSetupHost
cusolverStatus_t cusolverRfSetupHost(int n, int nnzA, int * h_csrRowPtrA, int * h_csrColIndA, double * h_csrValA, int nnzL, int * h_csrRowPtrL, int * h_csrColIndL, double * h_csrValL, int nnzU, int * h_csrRowPtrU, int * h_csrColIndU, double * h_csrValU, int * h_P, int * h_Q, cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfSetupHost) (int, int, int *, int *, double *, int, int *, int *, double *, int, int *, int *, double *, int *, int *, cusolverRfHandle_t) = (cusolverStatus_t (*)(int, int, int *, int *, double *, int, int *, int *, double *, int, int *, int *, double *, int *, int *, cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfSetupHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfSetupHost", kApiTypeCuSolver);

    lretval = lcusolverRfSetupHost(n, nnzA, h_csrRowPtrA, h_csrColIndA, h_csrValA, nnzL, h_csrRowPtrL, h_csrColIndL, h_csrValL, nnzU, h_csrRowPtrU, h_csrColIndU, h_csrValU, h_P, h_Q, handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfSetupHost cusolverRfSetupHost


#undef cusolverRfSetupDevice
cusolverStatus_t cusolverRfSetupDevice(int n, int nnzA, int * csrRowPtrA, int * csrColIndA, double * csrValA, int nnzL, int * csrRowPtrL, int * csrColIndL, double * csrValL, int nnzU, int * csrRowPtrU, int * csrColIndU, double * csrValU, int * P, int * Q, cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfSetupDevice) (int, int, int *, int *, double *, int, int *, int *, double *, int, int *, int *, double *, int *, int *, cusolverRfHandle_t) = (cusolverStatus_t (*)(int, int, int *, int *, double *, int, int *, int *, double *, int, int *, int *, double *, int *, int *, cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfSetupDevice");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfSetupDevice", kApiTypeCuSolver);

    lretval = lcusolverRfSetupDevice(n, nnzA, csrRowPtrA, csrColIndA, csrValA, nnzL, csrRowPtrL, csrColIndL, csrValL, nnzU, csrRowPtrU, csrColIndU, csrValU, P, Q, handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfSetupDevice cusolverRfSetupDevice


#undef cusolverRfResetValues
cusolverStatus_t cusolverRfResetValues(int n, int nnzA, int * csrRowPtrA, int * csrColIndA, double * csrValA, int * P, int * Q, cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfResetValues) (int, int, int *, int *, double *, int *, int *, cusolverRfHandle_t) = (cusolverStatus_t (*)(int, int, int *, int *, double *, int *, int *, cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfResetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfResetValues", kApiTypeCuSolver);

    lretval = lcusolverRfResetValues(n, nnzA, csrRowPtrA, csrColIndA, csrValA, P, Q, handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfResetValues cusolverRfResetValues


#undef cusolverRfAnalyze
cusolverStatus_t cusolverRfAnalyze(cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfAnalyze) (cusolverRfHandle_t) = (cusolverStatus_t (*)(cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfAnalyze");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfAnalyze", kApiTypeCuSolver);

    lretval = lcusolverRfAnalyze(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfAnalyze cusolverRfAnalyze


#undef cusolverRfRefactor
cusolverStatus_t cusolverRfRefactor(cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfRefactor) (cusolverRfHandle_t) = (cusolverStatus_t (*)(cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfRefactor");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfRefactor", kApiTypeCuSolver);

    lretval = lcusolverRfRefactor(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfRefactor cusolverRfRefactor


#undef cusolverRfAccessBundledFactorsDevice
cusolverStatus_t cusolverRfAccessBundledFactorsDevice(cusolverRfHandle_t handle, int * nnzM, int * * Mp, int * * Mi, double * * Mx){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfAccessBundledFactorsDevice) (cusolverRfHandle_t, int *, int * *, int * *, double * *) = (cusolverStatus_t (*)(cusolverRfHandle_t, int *, int * *, int * *, double * *))dlsym(RTLD_NEXT, "cusolverRfAccessBundledFactorsDevice");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfAccessBundledFactorsDevice", kApiTypeCuSolver);

    lretval = lcusolverRfAccessBundledFactorsDevice(handle, nnzM, Mp, Mi, Mx);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfAccessBundledFactorsDevice cusolverRfAccessBundledFactorsDevice


#undef cusolverRfExtractBundledFactorsHost
cusolverStatus_t cusolverRfExtractBundledFactorsHost(cusolverRfHandle_t handle, int * h_nnzM, int * * h_Mp, int * * h_Mi, double * * h_Mx){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfExtractBundledFactorsHost) (cusolverRfHandle_t, int *, int * *, int * *, double * *) = (cusolverStatus_t (*)(cusolverRfHandle_t, int *, int * *, int * *, double * *))dlsym(RTLD_NEXT, "cusolverRfExtractBundledFactorsHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfExtractBundledFactorsHost", kApiTypeCuSolver);

    lretval = lcusolverRfExtractBundledFactorsHost(handle, h_nnzM, h_Mp, h_Mi, h_Mx);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfExtractBundledFactorsHost cusolverRfExtractBundledFactorsHost


#undef cusolverRfExtractSplitFactorsHost
cusolverStatus_t cusolverRfExtractSplitFactorsHost(cusolverRfHandle_t handle, int * h_nnzL, int * * h_csrRowPtrL, int * * h_csrColIndL, double * * h_csrValL, int * h_nnzU, int * * h_csrRowPtrU, int * * h_csrColIndU, double * * h_csrValU){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfExtractSplitFactorsHost) (cusolverRfHandle_t, int *, int * *, int * *, double * *, int *, int * *, int * *, double * *) = (cusolverStatus_t (*)(cusolverRfHandle_t, int *, int * *, int * *, double * *, int *, int * *, int * *, double * *))dlsym(RTLD_NEXT, "cusolverRfExtractSplitFactorsHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfExtractSplitFactorsHost", kApiTypeCuSolver);

    lretval = lcusolverRfExtractSplitFactorsHost(handle, h_nnzL, h_csrRowPtrL, h_csrColIndL, h_csrValL, h_nnzU, h_csrRowPtrU, h_csrColIndU, h_csrValU);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfExtractSplitFactorsHost cusolverRfExtractSplitFactorsHost


#undef cusolverRfSolve
cusolverStatus_t cusolverRfSolve(cusolverRfHandle_t handle, int * P, int * Q, int nrhs, double * Temp, int ldt, double * XF, int ldxf){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfSolve) (cusolverRfHandle_t, int *, int *, int, double *, int, double *, int) = (cusolverStatus_t (*)(cusolverRfHandle_t, int *, int *, int, double *, int, double *, int))dlsym(RTLD_NEXT, "cusolverRfSolve");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfSolve", kApiTypeCuSolver);

    lretval = lcusolverRfSolve(handle, P, Q, nrhs, Temp, ldt, XF, ldxf);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfSolve cusolverRfSolve


#undef cusolverRfBatchSetupHost
cusolverStatus_t cusolverRfBatchSetupHost(int batchSize, int n, int nnzA, int * h_csrRowPtrA, int * h_csrColIndA, double * * h_csrValA_array, int nnzL, int * h_csrRowPtrL, int * h_csrColIndL, double * h_csrValL, int nnzU, int * h_csrRowPtrU, int * h_csrColIndU, double * h_csrValU, int * h_P, int * h_Q, cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfBatchSetupHost) (int, int, int, int *, int *, double * *, int, int *, int *, double *, int, int *, int *, double *, int *, int *, cusolverRfHandle_t) = (cusolverStatus_t (*)(int, int, int, int *, int *, double * *, int, int *, int *, double *, int, int *, int *, double *, int *, int *, cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfBatchSetupHost");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfBatchSetupHost", kApiTypeCuSolver);

    lretval = lcusolverRfBatchSetupHost(batchSize, n, nnzA, h_csrRowPtrA, h_csrColIndA, h_csrValA_array, nnzL, h_csrRowPtrL, h_csrColIndL, h_csrValL, nnzU, h_csrRowPtrU, h_csrColIndU, h_csrValU, h_P, h_Q, handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfBatchSetupHost cusolverRfBatchSetupHost


#undef cusolverRfBatchResetValues
cusolverStatus_t cusolverRfBatchResetValues(int batchSize, int n, int nnzA, int * csrRowPtrA, int * csrColIndA, double * * csrValA_array, int * P, int * Q, cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfBatchResetValues) (int, int, int, int *, int *, double * *, int *, int *, cusolverRfHandle_t) = (cusolverStatus_t (*)(int, int, int, int *, int *, double * *, int *, int *, cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfBatchResetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfBatchResetValues", kApiTypeCuSolver);

    lretval = lcusolverRfBatchResetValues(batchSize, n, nnzA, csrRowPtrA, csrColIndA, csrValA_array, P, Q, handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfBatchResetValues cusolverRfBatchResetValues


#undef cusolverRfBatchAnalyze
cusolverStatus_t cusolverRfBatchAnalyze(cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfBatchAnalyze) (cusolverRfHandle_t) = (cusolverStatus_t (*)(cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfBatchAnalyze");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfBatchAnalyze", kApiTypeCuSolver);

    lretval = lcusolverRfBatchAnalyze(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfBatchAnalyze cusolverRfBatchAnalyze


#undef cusolverRfBatchRefactor
cusolverStatus_t cusolverRfBatchRefactor(cusolverRfHandle_t handle){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfBatchRefactor) (cusolverRfHandle_t) = (cusolverStatus_t (*)(cusolverRfHandle_t))dlsym(RTLD_NEXT, "cusolverRfBatchRefactor");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfBatchRefactor", kApiTypeCuSolver);

    lretval = lcusolverRfBatchRefactor(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfBatchRefactor cusolverRfBatchRefactor


#undef cusolverRfBatchSolve
cusolverStatus_t cusolverRfBatchSolve(cusolverRfHandle_t handle, int * P, int * Q, int nrhs, double * Temp, int ldt, double * * XF_array, int ldxf){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfBatchSolve) (cusolverRfHandle_t, int *, int *, int, double *, int, double * *, int) = (cusolverStatus_t (*)(cusolverRfHandle_t, int *, int *, int, double *, int, double * *, int))dlsym(RTLD_NEXT, "cusolverRfBatchSolve");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfBatchSolve", kApiTypeCuSolver);

    lretval = lcusolverRfBatchSolve(handle, P, Q, nrhs, Temp, ldt, XF_array, ldxf);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfBatchSolve cusolverRfBatchSolve


#undef cusolverRfBatchZeroPivot
cusolverStatus_t cusolverRfBatchZeroPivot(cusolverRfHandle_t handle, int * position){
    cusolverStatus_t lretval;
    cusolverStatus_t (*lcusolverRfBatchZeroPivot) (cusolverRfHandle_t, int *) = (cusolverStatus_t (*)(cusolverRfHandle_t, int *))dlsym(RTLD_NEXT, "cusolverRfBatchZeroPivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusolverRfBatchZeroPivot", kApiTypeCuSolver);

    lretval = lcusolverRfBatchZeroPivot(handle, position);
    
    /* post exeuction logics */

    return lretval;
}
#define cusolverRfBatchZeroPivot cusolverRfBatchZeroPivot

