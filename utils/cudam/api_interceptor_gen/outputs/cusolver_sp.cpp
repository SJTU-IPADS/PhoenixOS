
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cusolverDn.h>
#include <cusolverMg.h>
#include <cusolverRf.h>
#include <cusolverSp.h>

#include "cudam.h"
#include "api_counter.h"

#undef cusparseCreate
cusparseStatus_t cusparseCreate(cusparseHandle_t * handle){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreate) (cusparseHandle_t *) = (cusparseStatus_t (*)(cusparseHandle_t *))dlsym(RTLD_NEXT, "cusparseCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreate", kApiTypeCuSolver);

    lretval = lcusparseCreate(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreate cusparseCreate


#undef cusparseDestroy
cusparseStatus_t cusparseDestroy(cusparseHandle_t handle){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroy) (cusparseHandle_t) = (cusparseStatus_t (*)(cusparseHandle_t))dlsym(RTLD_NEXT, "cusparseDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroy", kApiTypeCuSolver);

    lretval = lcusparseDestroy(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroy cusparseDestroy


#undef cusparseGetVersion
cusparseStatus_t cusparseGetVersion(cusparseHandle_t handle, int * version){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseGetVersion) (cusparseHandle_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int *))dlsym(RTLD_NEXT, "cusparseGetVersion");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetVersion", kApiTypeCuSolver);

    lretval = lcusparseGetVersion(handle, version);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetVersion cusparseGetVersion


#undef cusparseGetProperty
cusparseStatus_t cusparseGetProperty(libraryPropertyType type, int * value){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseGetProperty) (libraryPropertyType, int *) = (cusparseStatus_t (*)(libraryPropertyType, int *))dlsym(RTLD_NEXT, "cusparseGetProperty");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetProperty", kApiTypeCuSolver);

    lretval = lcusparseGetProperty(type, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetProperty cusparseGetProperty


#undef cusparseGetErrorName
char const * cusparseGetErrorName(cusparseStatus_t status){
    char const * lretval;
    char const * (*lcusparseGetErrorName) (cusparseStatus_t) = (char const * (*)(cusparseStatus_t))dlsym(RTLD_NEXT, "cusparseGetErrorName");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetErrorName", kApiTypeCuSolver);

    lretval = lcusparseGetErrorName(status);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetErrorName cusparseGetErrorName


#undef cusparseGetErrorString
char const * cusparseGetErrorString(cusparseStatus_t status){
    char const * lretval;
    char const * (*lcusparseGetErrorString) (cusparseStatus_t) = (char const * (*)(cusparseStatus_t))dlsym(RTLD_NEXT, "cusparseGetErrorString");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetErrorString", kApiTypeCuSolver);

    lretval = lcusparseGetErrorString(status);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetErrorString cusparseGetErrorString


#undef cusparseSetStream
cusparseStatus_t cusparseSetStream(cusparseHandle_t handle, cudaStream_t streamId){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSetStream) (cusparseHandle_t, cudaStream_t) = (cusparseStatus_t (*)(cusparseHandle_t, cudaStream_t))dlsym(RTLD_NEXT, "cusparseSetStream");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSetStream", kApiTypeCuSolver);

    lretval = lcusparseSetStream(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSetStream cusparseSetStream


#undef cusparseGetStream
cusparseStatus_t cusparseGetStream(cusparseHandle_t handle, cudaStream_t * streamId){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseGetStream) (cusparseHandle_t, cudaStream_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cudaStream_t *))dlsym(RTLD_NEXT, "cusparseGetStream");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetStream", kApiTypeCuSolver);

    lretval = lcusparseGetStream(handle, streamId);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetStream cusparseGetStream


#undef cusparseGetPointerMode
cusparseStatus_t cusparseGetPointerMode(cusparseHandle_t handle, cusparsePointerMode_t * mode){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseGetPointerMode) (cusparseHandle_t, cusparsePointerMode_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparsePointerMode_t *))dlsym(RTLD_NEXT, "cusparseGetPointerMode");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetPointerMode", kApiTypeCuSolver);

    lretval = lcusparseGetPointerMode(handle, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetPointerMode cusparseGetPointerMode


#undef cusparseSetPointerMode
cusparseStatus_t cusparseSetPointerMode(cusparseHandle_t handle, cusparsePointerMode_t mode){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSetPointerMode) (cusparseHandle_t, cusparsePointerMode_t) = (cusparseStatus_t (*)(cusparseHandle_t, cusparsePointerMode_t))dlsym(RTLD_NEXT, "cusparseSetPointerMode");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSetPointerMode", kApiTypeCuSolver);

    lretval = lcusparseSetPointerMode(handle, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSetPointerMode cusparseSetPointerMode


#undef cusparseCreateMatDescr
cusparseStatus_t cusparseCreateMatDescr(cusparseMatDescr_t * descrA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateMatDescr) (cusparseMatDescr_t *) = (cusparseStatus_t (*)(cusparseMatDescr_t *))dlsym(RTLD_NEXT, "cusparseCreateMatDescr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateMatDescr", kApiTypeCuSolver);

    lretval = lcusparseCreateMatDescr(descrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateMatDescr cusparseCreateMatDescr


#undef cusparseDestroyMatDescr
cusparseStatus_t cusparseDestroyMatDescr(cusparseMatDescr_t descrA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyMatDescr) (cusparseMatDescr_t) = (cusparseStatus_t (*)(cusparseMatDescr_t))dlsym(RTLD_NEXT, "cusparseDestroyMatDescr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyMatDescr", kApiTypeCuSolver);

    lretval = lcusparseDestroyMatDescr(descrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyMatDescr cusparseDestroyMatDescr


#undef cusparseCopyMatDescr
cusparseStatus_t cusparseCopyMatDescr(cusparseMatDescr_t dest, cusparseMatDescr_t const src){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCopyMatDescr) (cusparseMatDescr_t, cusparseMatDescr_t const) = (cusparseStatus_t (*)(cusparseMatDescr_t, cusparseMatDescr_t const))dlsym(RTLD_NEXT, "cusparseCopyMatDescr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCopyMatDescr", kApiTypeCuSolver);

    lretval = lcusparseCopyMatDescr(dest, src);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCopyMatDescr cusparseCopyMatDescr


#undef cusparseSetMatType
cusparseStatus_t cusparseSetMatType(cusparseMatDescr_t descrA, cusparseMatrixType_t type){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSetMatType) (cusparseMatDescr_t, cusparseMatrixType_t) = (cusparseStatus_t (*)(cusparseMatDescr_t, cusparseMatrixType_t))dlsym(RTLD_NEXT, "cusparseSetMatType");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSetMatType", kApiTypeCuSolver);

    lretval = lcusparseSetMatType(descrA, type);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSetMatType cusparseSetMatType


#undef cusparseGetMatType
cusparseMatrixType_t cusparseGetMatType(cusparseMatDescr_t const descrA){
    cusparseMatrixType_t lretval;
    cusparseMatrixType_t (*lcusparseGetMatType) (cusparseMatDescr_t const) = (cusparseMatrixType_t (*)(cusparseMatDescr_t const))dlsym(RTLD_NEXT, "cusparseGetMatType");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetMatType", kApiTypeCuSolver);

    lretval = lcusparseGetMatType(descrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetMatType cusparseGetMatType


#undef cusparseSetMatFillMode
cusparseStatus_t cusparseSetMatFillMode(cusparseMatDescr_t descrA, cusparseFillMode_t fillMode){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSetMatFillMode) (cusparseMatDescr_t, cusparseFillMode_t) = (cusparseStatus_t (*)(cusparseMatDescr_t, cusparseFillMode_t))dlsym(RTLD_NEXT, "cusparseSetMatFillMode");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSetMatFillMode", kApiTypeCuSolver);

    lretval = lcusparseSetMatFillMode(descrA, fillMode);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSetMatFillMode cusparseSetMatFillMode


#undef cusparseGetMatFillMode
cusparseFillMode_t cusparseGetMatFillMode(cusparseMatDescr_t const descrA){
    cusparseFillMode_t lretval;
    cusparseFillMode_t (*lcusparseGetMatFillMode) (cusparseMatDescr_t const) = (cusparseFillMode_t (*)(cusparseMatDescr_t const))dlsym(RTLD_NEXT, "cusparseGetMatFillMode");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetMatFillMode", kApiTypeCuSolver);

    lretval = lcusparseGetMatFillMode(descrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetMatFillMode cusparseGetMatFillMode


#undef cusparseSetMatDiagType
cusparseStatus_t cusparseSetMatDiagType(cusparseMatDescr_t descrA, cusparseDiagType_t diagType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSetMatDiagType) (cusparseMatDescr_t, cusparseDiagType_t) = (cusparseStatus_t (*)(cusparseMatDescr_t, cusparseDiagType_t))dlsym(RTLD_NEXT, "cusparseSetMatDiagType");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSetMatDiagType", kApiTypeCuSolver);

    lretval = lcusparseSetMatDiagType(descrA, diagType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSetMatDiagType cusparseSetMatDiagType


#undef cusparseGetMatDiagType
cusparseDiagType_t cusparseGetMatDiagType(cusparseMatDescr_t const descrA){
    cusparseDiagType_t lretval;
    cusparseDiagType_t (*lcusparseGetMatDiagType) (cusparseMatDescr_t const) = (cusparseDiagType_t (*)(cusparseMatDescr_t const))dlsym(RTLD_NEXT, "cusparseGetMatDiagType");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetMatDiagType", kApiTypeCuSolver);

    lretval = lcusparseGetMatDiagType(descrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetMatDiagType cusparseGetMatDiagType


#undef cusparseSetMatIndexBase
cusparseStatus_t cusparseSetMatIndexBase(cusparseMatDescr_t descrA, cusparseIndexBase_t base){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSetMatIndexBase) (cusparseMatDescr_t, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseMatDescr_t, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseSetMatIndexBase");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSetMatIndexBase", kApiTypeCuSolver);

    lretval = lcusparseSetMatIndexBase(descrA, base);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSetMatIndexBase cusparseSetMatIndexBase


#undef cusparseGetMatIndexBase
cusparseIndexBase_t cusparseGetMatIndexBase(cusparseMatDescr_t const descrA){
    cusparseIndexBase_t lretval;
    cusparseIndexBase_t (*lcusparseGetMatIndexBase) (cusparseMatDescr_t const) = (cusparseIndexBase_t (*)(cusparseMatDescr_t const))dlsym(RTLD_NEXT, "cusparseGetMatIndexBase");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetMatIndexBase", kApiTypeCuSolver);

    lretval = lcusparseGetMatIndexBase(descrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetMatIndexBase cusparseGetMatIndexBase


#undef cusparseCreateCsrsv2Info
cusparseStatus_t cusparseCreateCsrsv2Info(csrsv2Info_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCsrsv2Info) (csrsv2Info_t *) = (cusparseStatus_t (*)(csrsv2Info_t *))dlsym(RTLD_NEXT, "cusparseCreateCsrsv2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCsrsv2Info", kApiTypeCuSolver);

    lretval = lcusparseCreateCsrsv2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCsrsv2Info cusparseCreateCsrsv2Info


#undef cusparseDestroyCsrsv2Info
cusparseStatus_t cusparseDestroyCsrsv2Info(csrsv2Info_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyCsrsv2Info) (csrsv2Info_t) = (cusparseStatus_t (*)(csrsv2Info_t))dlsym(RTLD_NEXT, "cusparseDestroyCsrsv2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyCsrsv2Info", kApiTypeCuSolver);

    lretval = lcusparseDestroyCsrsv2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyCsrsv2Info cusparseDestroyCsrsv2Info


#undef cusparseCreateCsric02Info
cusparseStatus_t cusparseCreateCsric02Info(csric02Info_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCsric02Info) (csric02Info_t *) = (cusparseStatus_t (*)(csric02Info_t *))dlsym(RTLD_NEXT, "cusparseCreateCsric02Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCsric02Info", kApiTypeCuSolver);

    lretval = lcusparseCreateCsric02Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCsric02Info cusparseCreateCsric02Info


#undef cusparseDestroyCsric02Info
cusparseStatus_t cusparseDestroyCsric02Info(csric02Info_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyCsric02Info) (csric02Info_t) = (cusparseStatus_t (*)(csric02Info_t))dlsym(RTLD_NEXT, "cusparseDestroyCsric02Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyCsric02Info", kApiTypeCuSolver);

    lretval = lcusparseDestroyCsric02Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyCsric02Info cusparseDestroyCsric02Info


#undef cusparseCreateBsric02Info
cusparseStatus_t cusparseCreateBsric02Info(bsric02Info_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateBsric02Info) (bsric02Info_t *) = (cusparseStatus_t (*)(bsric02Info_t *))dlsym(RTLD_NEXT, "cusparseCreateBsric02Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateBsric02Info", kApiTypeCuSolver);

    lretval = lcusparseCreateBsric02Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateBsric02Info cusparseCreateBsric02Info


#undef cusparseDestroyBsric02Info
cusparseStatus_t cusparseDestroyBsric02Info(bsric02Info_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyBsric02Info) (bsric02Info_t) = (cusparseStatus_t (*)(bsric02Info_t))dlsym(RTLD_NEXT, "cusparseDestroyBsric02Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyBsric02Info", kApiTypeCuSolver);

    lretval = lcusparseDestroyBsric02Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyBsric02Info cusparseDestroyBsric02Info


#undef cusparseCreateCsrilu02Info
cusparseStatus_t cusparseCreateCsrilu02Info(csrilu02Info_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCsrilu02Info) (csrilu02Info_t *) = (cusparseStatus_t (*)(csrilu02Info_t *))dlsym(RTLD_NEXT, "cusparseCreateCsrilu02Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCsrilu02Info", kApiTypeCuSolver);

    lretval = lcusparseCreateCsrilu02Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCsrilu02Info cusparseCreateCsrilu02Info


#undef cusparseDestroyCsrilu02Info
cusparseStatus_t cusparseDestroyCsrilu02Info(csrilu02Info_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyCsrilu02Info) (csrilu02Info_t) = (cusparseStatus_t (*)(csrilu02Info_t))dlsym(RTLD_NEXT, "cusparseDestroyCsrilu02Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyCsrilu02Info", kApiTypeCuSolver);

    lretval = lcusparseDestroyCsrilu02Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyCsrilu02Info cusparseDestroyCsrilu02Info


#undef cusparseCreateBsrilu02Info
cusparseStatus_t cusparseCreateBsrilu02Info(bsrilu02Info_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateBsrilu02Info) (bsrilu02Info_t *) = (cusparseStatus_t (*)(bsrilu02Info_t *))dlsym(RTLD_NEXT, "cusparseCreateBsrilu02Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateBsrilu02Info", kApiTypeCuSolver);

    lretval = lcusparseCreateBsrilu02Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateBsrilu02Info cusparseCreateBsrilu02Info


#undef cusparseDestroyBsrilu02Info
cusparseStatus_t cusparseDestroyBsrilu02Info(bsrilu02Info_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyBsrilu02Info) (bsrilu02Info_t) = (cusparseStatus_t (*)(bsrilu02Info_t))dlsym(RTLD_NEXT, "cusparseDestroyBsrilu02Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyBsrilu02Info", kApiTypeCuSolver);

    lretval = lcusparseDestroyBsrilu02Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyBsrilu02Info cusparseDestroyBsrilu02Info


#undef cusparseCreateBsrsv2Info
cusparseStatus_t cusparseCreateBsrsv2Info(bsrsv2Info_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateBsrsv2Info) (bsrsv2Info_t *) = (cusparseStatus_t (*)(bsrsv2Info_t *))dlsym(RTLD_NEXT, "cusparseCreateBsrsv2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateBsrsv2Info", kApiTypeCuSolver);

    lretval = lcusparseCreateBsrsv2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateBsrsv2Info cusparseCreateBsrsv2Info


#undef cusparseDestroyBsrsv2Info
cusparseStatus_t cusparseDestroyBsrsv2Info(bsrsv2Info_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyBsrsv2Info) (bsrsv2Info_t) = (cusparseStatus_t (*)(bsrsv2Info_t))dlsym(RTLD_NEXT, "cusparseDestroyBsrsv2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyBsrsv2Info", kApiTypeCuSolver);

    lretval = lcusparseDestroyBsrsv2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyBsrsv2Info cusparseDestroyBsrsv2Info


#undef cusparseCreateBsrsm2Info
cusparseStatus_t cusparseCreateBsrsm2Info(bsrsm2Info_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateBsrsm2Info) (bsrsm2Info_t *) = (cusparseStatus_t (*)(bsrsm2Info_t *))dlsym(RTLD_NEXT, "cusparseCreateBsrsm2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateBsrsm2Info", kApiTypeCuSolver);

    lretval = lcusparseCreateBsrsm2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateBsrsm2Info cusparseCreateBsrsm2Info


#undef cusparseDestroyBsrsm2Info
cusparseStatus_t cusparseDestroyBsrsm2Info(bsrsm2Info_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyBsrsm2Info) (bsrsm2Info_t) = (cusparseStatus_t (*)(bsrsm2Info_t))dlsym(RTLD_NEXT, "cusparseDestroyBsrsm2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyBsrsm2Info", kApiTypeCuSolver);

    lretval = lcusparseDestroyBsrsm2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyBsrsm2Info cusparseDestroyBsrsm2Info


#undef cusparseCreateCsru2csrInfo
cusparseStatus_t cusparseCreateCsru2csrInfo(csru2csrInfo_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCsru2csrInfo) (csru2csrInfo_t *) = (cusparseStatus_t (*)(csru2csrInfo_t *))dlsym(RTLD_NEXT, "cusparseCreateCsru2csrInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCsru2csrInfo", kApiTypeCuSolver);

    lretval = lcusparseCreateCsru2csrInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCsru2csrInfo cusparseCreateCsru2csrInfo


#undef cusparseDestroyCsru2csrInfo
cusparseStatus_t cusparseDestroyCsru2csrInfo(csru2csrInfo_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyCsru2csrInfo) (csru2csrInfo_t) = (cusparseStatus_t (*)(csru2csrInfo_t))dlsym(RTLD_NEXT, "cusparseDestroyCsru2csrInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyCsru2csrInfo", kApiTypeCuSolver);

    lretval = lcusparseDestroyCsru2csrInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyCsru2csrInfo cusparseDestroyCsru2csrInfo


#undef cusparseCreateColorInfo
cusparseStatus_t cusparseCreateColorInfo(cusparseColorInfo_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateColorInfo) (cusparseColorInfo_t *) = (cusparseStatus_t (*)(cusparseColorInfo_t *))dlsym(RTLD_NEXT, "cusparseCreateColorInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateColorInfo", kApiTypeCuSolver);

    lretval = lcusparseCreateColorInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateColorInfo cusparseCreateColorInfo


#undef cusparseDestroyColorInfo
cusparseStatus_t cusparseDestroyColorInfo(cusparseColorInfo_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyColorInfo) (cusparseColorInfo_t) = (cusparseStatus_t (*)(cusparseColorInfo_t))dlsym(RTLD_NEXT, "cusparseDestroyColorInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyColorInfo", kApiTypeCuSolver);

    lretval = lcusparseDestroyColorInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyColorInfo cusparseDestroyColorInfo


#undef cusparseSetColorAlgs
cusparseStatus_t cusparseSetColorAlgs(cusparseColorInfo_t info, cusparseColorAlg_t alg){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSetColorAlgs) (cusparseColorInfo_t, cusparseColorAlg_t) = (cusparseStatus_t (*)(cusparseColorInfo_t, cusparseColorAlg_t))dlsym(RTLD_NEXT, "cusparseSetColorAlgs");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSetColorAlgs", kApiTypeCuSolver);

    lretval = lcusparseSetColorAlgs(info, alg);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSetColorAlgs cusparseSetColorAlgs


#undef cusparseGetColorAlgs
cusparseStatus_t cusparseGetColorAlgs(cusparseColorInfo_t info, cusparseColorAlg_t * alg){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseGetColorAlgs) (cusparseColorInfo_t, cusparseColorAlg_t *) = (cusparseStatus_t (*)(cusparseColorInfo_t, cusparseColorAlg_t *))dlsym(RTLD_NEXT, "cusparseGetColorAlgs");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGetColorAlgs", kApiTypeCuSolver);

    lretval = lcusparseGetColorAlgs(info, alg);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGetColorAlgs cusparseGetColorAlgs


#undef cusparseCreatePruneInfo
cusparseStatus_t cusparseCreatePruneInfo(pruneInfo_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreatePruneInfo) (pruneInfo_t *) = (cusparseStatus_t (*)(pruneInfo_t *))dlsym(RTLD_NEXT, "cusparseCreatePruneInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreatePruneInfo", kApiTypeCuSolver);

    lretval = lcusparseCreatePruneInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreatePruneInfo cusparseCreatePruneInfo


#undef cusparseDestroyPruneInfo
cusparseStatus_t cusparseDestroyPruneInfo(pruneInfo_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyPruneInfo) (pruneInfo_t) = (cusparseStatus_t (*)(pruneInfo_t))dlsym(RTLD_NEXT, "cusparseDestroyPruneInfo");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyPruneInfo", kApiTypeCuSolver);

    lretval = lcusparseDestroyPruneInfo(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyPruneInfo cusparseDestroyPruneInfo


#undef cusparseSaxpyi
cusparseStatus_t cusparseSaxpyi(cusparseHandle_t handle, int nnz, float const * alpha, float const * xVal, int const * xInd, float * y, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSaxpyi) (cusparseHandle_t, int, float const *, float const *, int const *, float *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, float const *, float const *, int const *, float *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseSaxpyi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSaxpyi", kApiTypeCuSolver);

    lretval = lcusparseSaxpyi(handle, nnz, alpha, xVal, xInd, y, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSaxpyi cusparseSaxpyi


#undef cusparseDaxpyi
cusparseStatus_t cusparseDaxpyi(cusparseHandle_t handle, int nnz, double const * alpha, double const * xVal, int const * xInd, double * y, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDaxpyi) (cusparseHandle_t, int, double const *, double const *, int const *, double *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, double const *, double const *, int const *, double *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseDaxpyi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDaxpyi", kApiTypeCuSolver);

    lretval = lcusparseDaxpyi(handle, nnz, alpha, xVal, xInd, y, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDaxpyi cusparseDaxpyi


#undef cusparseCaxpyi
cusparseStatus_t cusparseCaxpyi(cusparseHandle_t handle, int nnz, cuComplex const * alpha, cuComplex const * xVal, int const * xInd, cuComplex * y, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCaxpyi) (cusparseHandle_t, int, cuComplex const *, cuComplex const *, int const *, cuComplex *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuComplex const *, cuComplex const *, int const *, cuComplex *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseCaxpyi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCaxpyi", kApiTypeCuSolver);

    lretval = lcusparseCaxpyi(handle, nnz, alpha, xVal, xInd, y, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCaxpyi cusparseCaxpyi


#undef cusparseZaxpyi
cusparseStatus_t cusparseZaxpyi(cusparseHandle_t handle, int nnz, cuDoubleComplex const * alpha, cuDoubleComplex const * xVal, int const * xInd, cuDoubleComplex * y, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZaxpyi) (cusparseHandle_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int const *, cuDoubleComplex *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuDoubleComplex const *, cuDoubleComplex const *, int const *, cuDoubleComplex *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseZaxpyi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZaxpyi", kApiTypeCuSolver);

    lretval = lcusparseZaxpyi(handle, nnz, alpha, xVal, xInd, y, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZaxpyi cusparseZaxpyi


#undef cusparseSgthr
cusparseStatus_t cusparseSgthr(cusparseHandle_t handle, int nnz, float const * y, float * xVal, int const * xInd, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgthr) (cusparseHandle_t, int, float const *, float *, int const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, float const *, float *, int const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseSgthr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgthr", kApiTypeCuSolver);

    lretval = lcusparseSgthr(handle, nnz, y, xVal, xInd, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgthr cusparseSgthr


#undef cusparseDgthr
cusparseStatus_t cusparseDgthr(cusparseHandle_t handle, int nnz, double const * y, double * xVal, int const * xInd, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgthr) (cusparseHandle_t, int, double const *, double *, int const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, double const *, double *, int const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseDgthr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgthr", kApiTypeCuSolver);

    lretval = lcusparseDgthr(handle, nnz, y, xVal, xInd, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgthr cusparseDgthr


#undef cusparseCgthr
cusparseStatus_t cusparseCgthr(cusparseHandle_t handle, int nnz, cuComplex const * y, cuComplex * xVal, int const * xInd, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgthr) (cusparseHandle_t, int, cuComplex const *, cuComplex *, int const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuComplex const *, cuComplex *, int const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseCgthr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgthr", kApiTypeCuSolver);

    lretval = lcusparseCgthr(handle, nnz, y, xVal, xInd, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgthr cusparseCgthr


#undef cusparseZgthr
cusparseStatus_t cusparseZgthr(cusparseHandle_t handle, int nnz, cuDoubleComplex const * y, cuDoubleComplex * xVal, int const * xInd, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgthr) (cusparseHandle_t, int, cuDoubleComplex const *, cuDoubleComplex *, int const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuDoubleComplex const *, cuDoubleComplex *, int const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseZgthr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgthr", kApiTypeCuSolver);

    lretval = lcusparseZgthr(handle, nnz, y, xVal, xInd, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgthr cusparseZgthr


#undef cusparseSgthrz
cusparseStatus_t cusparseSgthrz(cusparseHandle_t handle, int nnz, float * y, float * xVal, int const * xInd, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgthrz) (cusparseHandle_t, int, float *, float *, int const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, float *, float *, int const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseSgthrz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgthrz", kApiTypeCuSolver);

    lretval = lcusparseSgthrz(handle, nnz, y, xVal, xInd, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgthrz cusparseSgthrz


#undef cusparseDgthrz
cusparseStatus_t cusparseDgthrz(cusparseHandle_t handle, int nnz, double * y, double * xVal, int const * xInd, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgthrz) (cusparseHandle_t, int, double *, double *, int const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, double *, double *, int const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseDgthrz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgthrz", kApiTypeCuSolver);

    lretval = lcusparseDgthrz(handle, nnz, y, xVal, xInd, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgthrz cusparseDgthrz


#undef cusparseCgthrz
cusparseStatus_t cusparseCgthrz(cusparseHandle_t handle, int nnz, cuComplex * y, cuComplex * xVal, int const * xInd, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgthrz) (cusparseHandle_t, int, cuComplex *, cuComplex *, int const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuComplex *, cuComplex *, int const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseCgthrz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgthrz", kApiTypeCuSolver);

    lretval = lcusparseCgthrz(handle, nnz, y, xVal, xInd, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgthrz cusparseCgthrz


#undef cusparseZgthrz
cusparseStatus_t cusparseZgthrz(cusparseHandle_t handle, int nnz, cuDoubleComplex * y, cuDoubleComplex * xVal, int const * xInd, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgthrz) (cusparseHandle_t, int, cuDoubleComplex *, cuDoubleComplex *, int const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuDoubleComplex *, cuDoubleComplex *, int const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseZgthrz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgthrz", kApiTypeCuSolver);

    lretval = lcusparseZgthrz(handle, nnz, y, xVal, xInd, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgthrz cusparseZgthrz


#undef cusparseSsctr
cusparseStatus_t cusparseSsctr(cusparseHandle_t handle, int nnz, float const * xVal, int const * xInd, float * y, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSsctr) (cusparseHandle_t, int, float const *, int const *, float *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, float const *, int const *, float *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseSsctr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSsctr", kApiTypeCuSolver);

    lretval = lcusparseSsctr(handle, nnz, xVal, xInd, y, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSsctr cusparseSsctr


#undef cusparseDsctr
cusparseStatus_t cusparseDsctr(cusparseHandle_t handle, int nnz, double const * xVal, int const * xInd, double * y, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDsctr) (cusparseHandle_t, int, double const *, int const *, double *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, double const *, int const *, double *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseDsctr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDsctr", kApiTypeCuSolver);

    lretval = lcusparseDsctr(handle, nnz, xVal, xInd, y, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDsctr cusparseDsctr


#undef cusparseCsctr
cusparseStatus_t cusparseCsctr(cusparseHandle_t handle, int nnz, cuComplex const * xVal, int const * xInd, cuComplex * y, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCsctr) (cusparseHandle_t, int, cuComplex const *, int const *, cuComplex *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuComplex const *, int const *, cuComplex *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseCsctr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCsctr", kApiTypeCuSolver);

    lretval = lcusparseCsctr(handle, nnz, xVal, xInd, y, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCsctr cusparseCsctr


#undef cusparseZsctr
cusparseStatus_t cusparseZsctr(cusparseHandle_t handle, int nnz, cuDoubleComplex const * xVal, int const * xInd, cuDoubleComplex * y, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZsctr) (cusparseHandle_t, int, cuDoubleComplex const *, int const *, cuDoubleComplex *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuDoubleComplex const *, int const *, cuDoubleComplex *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseZsctr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZsctr", kApiTypeCuSolver);

    lretval = lcusparseZsctr(handle, nnz, xVal, xInd, y, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZsctr cusparseZsctr


#undef cusparseSroti
cusparseStatus_t cusparseSroti(cusparseHandle_t handle, int nnz, float * xVal, int const * xInd, float * y, float const * c, float const * s, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSroti) (cusparseHandle_t, int, float *, int const *, float *, float const *, float const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, float *, int const *, float *, float const *, float const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseSroti");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSroti", kApiTypeCuSolver);

    lretval = lcusparseSroti(handle, nnz, xVal, xInd, y, c, s, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSroti cusparseSroti


#undef cusparseDroti
cusparseStatus_t cusparseDroti(cusparseHandle_t handle, int nnz, double * xVal, int const * xInd, double * y, double const * c, double const * s, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDroti) (cusparseHandle_t, int, double *, int const *, double *, double const *, double const *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int, double *, int const *, double *, double const *, double const *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseDroti");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDroti", kApiTypeCuSolver);

    lretval = lcusparseDroti(handle, nnz, xVal, xInd, y, c, s, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDroti cusparseDroti


#undef cusparseSgemvi
cusparseStatus_t cusparseSgemvi(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, float const * alpha, float const * A, int lda, int nnz, float const * xVal, int const * xInd, float const * beta, float * y, cusparseIndexBase_t idxBase, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgemvi) (cusparseHandle_t, cusparseOperation_t, int, int, float const *, float const *, int, int, float const *, int const *, float const *, float *, cusparseIndexBase_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, float const *, float const *, int, int, float const *, int const *, float const *, float *, cusparseIndexBase_t, void *))dlsym(RTLD_NEXT, "cusparseSgemvi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgemvi", kApiTypeCuSolver);

    lretval = lcusparseSgemvi(handle, transA, m, n, alpha, A, lda, nnz, xVal, xInd, beta, y, idxBase, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgemvi cusparseSgemvi


#undef cusparseSgemvi_bufferSize
cusparseStatus_t cusparseSgemvi_bufferSize(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, int nnz, int * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgemvi_bufferSize) (cusparseHandle_t, cusparseOperation_t, int, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, int, int *))dlsym(RTLD_NEXT, "cusparseSgemvi_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgemvi_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSgemvi_bufferSize(handle, transA, m, n, nnz, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgemvi_bufferSize cusparseSgemvi_bufferSize


#undef cusparseDgemvi
cusparseStatus_t cusparseDgemvi(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, double const * alpha, double const * A, int lda, int nnz, double const * xVal, int const * xInd, double const * beta, double * y, cusparseIndexBase_t idxBase, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgemvi) (cusparseHandle_t, cusparseOperation_t, int, int, double const *, double const *, int, int, double const *, int const *, double const *, double *, cusparseIndexBase_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, double const *, double const *, int, int, double const *, int const *, double const *, double *, cusparseIndexBase_t, void *))dlsym(RTLD_NEXT, "cusparseDgemvi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgemvi", kApiTypeCuSolver);

    lretval = lcusparseDgemvi(handle, transA, m, n, alpha, A, lda, nnz, xVal, xInd, beta, y, idxBase, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgemvi cusparseDgemvi


#undef cusparseDgemvi_bufferSize
cusparseStatus_t cusparseDgemvi_bufferSize(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, int nnz, int * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgemvi_bufferSize) (cusparseHandle_t, cusparseOperation_t, int, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, int, int *))dlsym(RTLD_NEXT, "cusparseDgemvi_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgemvi_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDgemvi_bufferSize(handle, transA, m, n, nnz, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgemvi_bufferSize cusparseDgemvi_bufferSize


#undef cusparseCgemvi
cusparseStatus_t cusparseCgemvi(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, cuComplex const * alpha, cuComplex const * A, int lda, int nnz, cuComplex const * xVal, int const * xInd, cuComplex const * beta, cuComplex * y, cusparseIndexBase_t idxBase, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgemvi) (cusparseHandle_t, cusparseOperation_t, int, int, cuComplex const *, cuComplex const *, int, int, cuComplex const *, int const *, cuComplex const *, cuComplex *, cusparseIndexBase_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cuComplex const *, cuComplex const *, int, int, cuComplex const *, int const *, cuComplex const *, cuComplex *, cusparseIndexBase_t, void *))dlsym(RTLD_NEXT, "cusparseCgemvi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgemvi", kApiTypeCuSolver);

    lretval = lcusparseCgemvi(handle, transA, m, n, alpha, A, lda, nnz, xVal, xInd, beta, y, idxBase, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgemvi cusparseCgemvi


#undef cusparseCgemvi_bufferSize
cusparseStatus_t cusparseCgemvi_bufferSize(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, int nnz, int * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgemvi_bufferSize) (cusparseHandle_t, cusparseOperation_t, int, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, int, int *))dlsym(RTLD_NEXT, "cusparseCgemvi_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgemvi_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCgemvi_bufferSize(handle, transA, m, n, nnz, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgemvi_bufferSize cusparseCgemvi_bufferSize


#undef cusparseZgemvi
cusparseStatus_t cusparseZgemvi(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, int nnz, cuDoubleComplex const * xVal, int const * xInd, cuDoubleComplex const * beta, cuDoubleComplex * y, cusparseIndexBase_t idxBase, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgemvi) (cusparseHandle_t, cusparseOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, int, cuDoubleComplex const *, int const *, cuDoubleComplex const *, cuDoubleComplex *, cusparseIndexBase_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, int, cuDoubleComplex const *, int const *, cuDoubleComplex const *, cuDoubleComplex *, cusparseIndexBase_t, void *))dlsym(RTLD_NEXT, "cusparseZgemvi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgemvi", kApiTypeCuSolver);

    lretval = lcusparseZgemvi(handle, transA, m, n, alpha, A, lda, nnz, xVal, xInd, beta, y, idxBase, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgemvi cusparseZgemvi


#undef cusparseZgemvi_bufferSize
cusparseStatus_t cusparseZgemvi_bufferSize(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, int nnz, int * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgemvi_bufferSize) (cusparseHandle_t, cusparseOperation_t, int, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, int, int *))dlsym(RTLD_NEXT, "cusparseZgemvi_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgemvi_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZgemvi_bufferSize(handle, transA, m, n, nnz, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgemvi_bufferSize cusparseZgemvi_bufferSize


#undef cusparseCsrmvEx_bufferSize
cusparseStatus_t cusparseCsrmvEx_bufferSize(cusparseHandle_t handle, cusparseAlgMode_t alg, cusparseOperation_t transA, int m, int n, int nnz, void const * alpha, cudaDataType alphatype, cusparseMatDescr_t const descrA, void const * csrValA, cudaDataType csrValAtype, int const * csrRowPtrA, int const * csrColIndA, void const * x, cudaDataType xtype, void const * beta, cudaDataType betatype, void * y, cudaDataType ytype, cudaDataType executiontype, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCsrmvEx_bufferSize) (cusparseHandle_t, cusparseAlgMode_t, cusparseOperation_t, int, int, int, void const *, cudaDataType, cusparseMatDescr_t const, void const *, cudaDataType, int const *, int const *, void const *, cudaDataType, void const *, cudaDataType, void *, cudaDataType, cudaDataType, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseAlgMode_t, cusparseOperation_t, int, int, int, void const *, cudaDataType, cusparseMatDescr_t const, void const *, cudaDataType, int const *, int const *, void const *, cudaDataType, void const *, cudaDataType, void *, cudaDataType, cudaDataType, size_t *))dlsym(RTLD_NEXT, "cusparseCsrmvEx_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCsrmvEx_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCsrmvEx_bufferSize(handle, alg, transA, m, n, nnz, alpha, alphatype, descrA, csrValA, csrValAtype, csrRowPtrA, csrColIndA, x, xtype, beta, betatype, y, ytype, executiontype, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCsrmvEx_bufferSize cusparseCsrmvEx_bufferSize


#undef cusparseCsrmvEx
cusparseStatus_t cusparseCsrmvEx(cusparseHandle_t handle, cusparseAlgMode_t alg, cusparseOperation_t transA, int m, int n, int nnz, void const * alpha, cudaDataType alphatype, cusparseMatDescr_t const descrA, void const * csrValA, cudaDataType csrValAtype, int const * csrRowPtrA, int const * csrColIndA, void const * x, cudaDataType xtype, void const * beta, cudaDataType betatype, void * y, cudaDataType ytype, cudaDataType executiontype, void * buffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCsrmvEx) (cusparseHandle_t, cusparseAlgMode_t, cusparseOperation_t, int, int, int, void const *, cudaDataType, cusparseMatDescr_t const, void const *, cudaDataType, int const *, int const *, void const *, cudaDataType, void const *, cudaDataType, void *, cudaDataType, cudaDataType, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseAlgMode_t, cusparseOperation_t, int, int, int, void const *, cudaDataType, cusparseMatDescr_t const, void const *, cudaDataType, int const *, int const *, void const *, cudaDataType, void const *, cudaDataType, void *, cudaDataType, cudaDataType, void *))dlsym(RTLD_NEXT, "cusparseCsrmvEx");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCsrmvEx", kApiTypeCuSolver);

    lretval = lcusparseCsrmvEx(handle, alg, transA, m, n, nnz, alpha, alphatype, descrA, csrValA, csrValAtype, csrRowPtrA, csrColIndA, x, xtype, beta, betatype, y, ytype, executiontype, buffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCsrmvEx cusparseCsrmvEx


#undef cusparseSbsrmv
cusparseStatus_t cusparseSbsrmv(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nb, int nnzb, float const * alpha, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, float const * x, float const * beta, float * y){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrmv) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int, float const *, float const *, float *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int, float const *, float const *, float *))dlsym(RTLD_NEXT, "cusparseSbsrmv");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrmv", kApiTypeCuSolver);

    lretval = lcusparseSbsrmv(handle, dirA, transA, mb, nb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, x, beta, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrmv cusparseSbsrmv


#undef cusparseDbsrmv
cusparseStatus_t cusparseDbsrmv(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nb, int nnzb, double const * alpha, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, double const * x, double const * beta, double * y){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrmv) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int, double const *, double const *, double *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int, double const *, double const *, double *))dlsym(RTLD_NEXT, "cusparseDbsrmv");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrmv", kApiTypeCuSolver);

    lretval = lcusparseDbsrmv(handle, dirA, transA, mb, nb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, x, beta, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrmv cusparseDbsrmv


#undef cusparseCbsrmv
cusparseStatus_t cusparseCbsrmv(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nb, int nnzb, cuComplex const * alpha, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, cuComplex const * x, cuComplex const * beta, cuComplex * y){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrmv) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, cuComplex const *, cuComplex const *, cuComplex *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, cuComplex const *, cuComplex const *, cuComplex *))dlsym(RTLD_NEXT, "cusparseCbsrmv");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrmv", kApiTypeCuSolver);

    lretval = lcusparseCbsrmv(handle, dirA, transA, mb, nb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, x, beta, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrmv cusparseCbsrmv


#undef cusparseZbsrmv
cusparseStatus_t cusparseZbsrmv(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nb, int nnzb, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, cuDoubleComplex const * x, cuDoubleComplex const * beta, cuDoubleComplex * y){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrmv) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *))dlsym(RTLD_NEXT, "cusparseZbsrmv");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrmv", kApiTypeCuSolver);

    lretval = lcusparseZbsrmv(handle, dirA, transA, mb, nb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, x, beta, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrmv cusparseZbsrmv


#undef cusparseSbsrxmv
cusparseStatus_t cusparseSbsrxmv(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int sizeOfMask, int mb, int nb, int nnzb, float const * alpha, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedMaskPtrA, int const * bsrSortedRowPtrA, int const * bsrSortedEndPtrA, int const * bsrSortedColIndA, int blockDim, float const * x, float const * beta, float * y){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrxmv) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int const *, int const *, int, float const *, float const *, float *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int const *, int const *, int, float const *, float const *, float *))dlsym(RTLD_NEXT, "cusparseSbsrxmv");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrxmv", kApiTypeCuSolver);

    lretval = lcusparseSbsrxmv(handle, dirA, transA, sizeOfMask, mb, nb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedMaskPtrA, bsrSortedRowPtrA, bsrSortedEndPtrA, bsrSortedColIndA, blockDim, x, beta, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrxmv cusparseSbsrxmv


#undef cusparseDbsrxmv
cusparseStatus_t cusparseDbsrxmv(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int sizeOfMask, int mb, int nb, int nnzb, double const * alpha, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedMaskPtrA, int const * bsrSortedRowPtrA, int const * bsrSortedEndPtrA, int const * bsrSortedColIndA, int blockDim, double const * x, double const * beta, double * y){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrxmv) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int const *, int const *, int, double const *, double const *, double *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int const *, int const *, int, double const *, double const *, double *))dlsym(RTLD_NEXT, "cusparseDbsrxmv");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrxmv", kApiTypeCuSolver);

    lretval = lcusparseDbsrxmv(handle, dirA, transA, sizeOfMask, mb, nb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedMaskPtrA, bsrSortedRowPtrA, bsrSortedEndPtrA, bsrSortedColIndA, blockDim, x, beta, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrxmv cusparseDbsrxmv


#undef cusparseCbsrxmv
cusparseStatus_t cusparseCbsrxmv(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int sizeOfMask, int mb, int nb, int nnzb, cuComplex const * alpha, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedMaskPtrA, int const * bsrSortedRowPtrA, int const * bsrSortedEndPtrA, int const * bsrSortedColIndA, int blockDim, cuComplex const * x, cuComplex const * beta, cuComplex * y){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrxmv) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int const *, int const *, int, cuComplex const *, cuComplex const *, cuComplex *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int const *, int const *, int, cuComplex const *, cuComplex const *, cuComplex *))dlsym(RTLD_NEXT, "cusparseCbsrxmv");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrxmv", kApiTypeCuSolver);

    lretval = lcusparseCbsrxmv(handle, dirA, transA, sizeOfMask, mb, nb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedMaskPtrA, bsrSortedRowPtrA, bsrSortedEndPtrA, bsrSortedColIndA, blockDim, x, beta, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrxmv cusparseCbsrxmv


#undef cusparseZbsrxmv
cusparseStatus_t cusparseZbsrxmv(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int sizeOfMask, int mb, int nb, int nnzb, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedMaskPtrA, int const * bsrSortedRowPtrA, int const * bsrSortedEndPtrA, int const * bsrSortedColIndA, int blockDim, cuDoubleComplex const * x, cuDoubleComplex const * beta, cuDoubleComplex * y){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrxmv) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int const *, int const *, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int const *, int const *, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *))dlsym(RTLD_NEXT, "cusparseZbsrxmv");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrxmv", kApiTypeCuSolver);

    lretval = lcusparseZbsrxmv(handle, dirA, transA, sizeOfMask, mb, nb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedMaskPtrA, bsrSortedRowPtrA, bsrSortedEndPtrA, bsrSortedColIndA, blockDim, x, beta, y);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrxmv cusparseZbsrxmv


#undef cusparseXcsrsv2_zeroPivot
cusparseStatus_t cusparseXcsrsv2_zeroPivot(cusparseHandle_t handle, csrsv2Info_t info, int * position){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsrsv2_zeroPivot) (cusparseHandle_t, csrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, csrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseXcsrsv2_zeroPivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsrsv2_zeroPivot", kApiTypeCuSolver);

    lretval = lcusparseXcsrsv2_zeroPivot(handle, info, position);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsrsv2_zeroPivot cusparseXcsrsv2_zeroPivot


#undef cusparseScsrsv2_bufferSize
cusparseStatus_t cusparseScsrsv2_bufferSize(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, float * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrsv2_bufferSize) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseScsrsv2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrsv2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseScsrsv2_bufferSize(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrsv2_bufferSize cusparseScsrsv2_bufferSize


#undef cusparseDcsrsv2_bufferSize
cusparseStatus_t cusparseDcsrsv2_bufferSize(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, double * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrsv2_bufferSize) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseDcsrsv2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrsv2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDcsrsv2_bufferSize(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrsv2_bufferSize cusparseDcsrsv2_bufferSize


#undef cusparseCcsrsv2_bufferSize
cusparseStatus_t cusparseCcsrsv2_bufferSize(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrsv2_bufferSize) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseCcsrsv2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrsv2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCcsrsv2_bufferSize(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrsv2_bufferSize cusparseCcsrsv2_bufferSize


#undef cusparseZcsrsv2_bufferSize
cusparseStatus_t cusparseZcsrsv2_bufferSize(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrsv2_bufferSize) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseZcsrsv2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrsv2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZcsrsv2_bufferSize(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrsv2_bufferSize cusparseZcsrsv2_bufferSize


#undef cusparseScsrsv2_bufferSizeExt
cusparseStatus_t cusparseScsrsv2_bufferSizeExt(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, float * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrsv2_bufferSizeExt) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrsv2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrsv2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseScsrsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseScsrsv2_bufferSizeExt(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrsv2_bufferSizeExt cusparseScsrsv2_bufferSizeExt


#undef cusparseDcsrsv2_bufferSizeExt
cusparseStatus_t cusparseDcsrsv2_bufferSizeExt(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, double * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrsv2_bufferSizeExt) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrsv2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrsv2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseDcsrsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDcsrsv2_bufferSizeExt(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrsv2_bufferSizeExt cusparseDcsrsv2_bufferSizeExt


#undef cusparseCcsrsv2_bufferSizeExt
cusparseStatus_t cusparseCcsrsv2_bufferSizeExt(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrsv2_bufferSizeExt) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrsv2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrsv2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseCcsrsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCcsrsv2_bufferSizeExt(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrsv2_bufferSizeExt cusparseCcsrsv2_bufferSizeExt


#undef cusparseZcsrsv2_bufferSizeExt
cusparseStatus_t cusparseZcsrsv2_bufferSizeExt(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrsv2_bufferSizeExt) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrsv2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrsv2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseZcsrsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZcsrsv2_bufferSizeExt(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrsv2_bufferSizeExt cusparseZcsrsv2_bufferSizeExt


#undef cusparseScsrsv2_analysis
cusparseStatus_t cusparseScsrsv2_analysis(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrsv2_analysis) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, csrsv2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, csrsv2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseScsrsv2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrsv2_analysis", kApiTypeCuSolver);

    lretval = lcusparseScsrsv2_analysis(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrsv2_analysis cusparseScsrsv2_analysis


#undef cusparseDcsrsv2_analysis
cusparseStatus_t cusparseDcsrsv2_analysis(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrsv2_analysis) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, csrsv2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, csrsv2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDcsrsv2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrsv2_analysis", kApiTypeCuSolver);

    lretval = lcusparseDcsrsv2_analysis(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrsv2_analysis cusparseDcsrsv2_analysis


#undef cusparseCcsrsv2_analysis
cusparseStatus_t cusparseCcsrsv2_analysis(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrsv2_analysis) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, csrsv2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, csrsv2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCcsrsv2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrsv2_analysis", kApiTypeCuSolver);

    lretval = lcusparseCcsrsv2_analysis(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrsv2_analysis cusparseCcsrsv2_analysis


#undef cusparseZcsrsv2_analysis
cusparseStatus_t cusparseZcsrsv2_analysis(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrsv2_analysis) (cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, csrsv2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, csrsv2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZcsrsv2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrsv2_analysis", kApiTypeCuSolver);

    lretval = lcusparseZcsrsv2_analysis(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrsv2_analysis cusparseZcsrsv2_analysis


#undef cusparseScsrsv2_solve
cusparseStatus_t cusparseScsrsv2_solve(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, float const * alpha, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, float const * f, float * x, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrsv2_solve) (cusparseHandle_t, cusparseOperation_t, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, csrsv2Info_t, float const *, float *, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, csrsv2Info_t, float const *, float *, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseScsrsv2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrsv2_solve", kApiTypeCuSolver);

    lretval = lcusparseScsrsv2_solve(handle, transA, m, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, f, x, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrsv2_solve cusparseScsrsv2_solve


#undef cusparseDcsrsv2_solve
cusparseStatus_t cusparseDcsrsv2_solve(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, double const * alpha, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, double const * f, double * x, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrsv2_solve) (cusparseHandle_t, cusparseOperation_t, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, csrsv2Info_t, double const *, double *, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, csrsv2Info_t, double const *, double *, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDcsrsv2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrsv2_solve", kApiTypeCuSolver);

    lretval = lcusparseDcsrsv2_solve(handle, transA, m, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, f, x, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrsv2_solve cusparseDcsrsv2_solve


#undef cusparseCcsrsv2_solve
cusparseStatus_t cusparseCcsrsv2_solve(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cuComplex const * alpha, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, cuComplex const * f, cuComplex * x, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrsv2_solve) (cusparseHandle_t, cusparseOperation_t, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, csrsv2Info_t, cuComplex const *, cuComplex *, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, csrsv2Info_t, cuComplex const *, cuComplex *, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCcsrsv2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrsv2_solve", kApiTypeCuSolver);

    lretval = lcusparseCcsrsv2_solve(handle, transA, m, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, f, x, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrsv2_solve cusparseCcsrsv2_solve


#undef cusparseZcsrsv2_solve
cusparseStatus_t cusparseZcsrsv2_solve(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrsv2Info_t info, cuDoubleComplex const * f, cuDoubleComplex * x, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrsv2_solve) (cusparseHandle_t, cusparseOperation_t, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, csrsv2Info_t, cuDoubleComplex const *, cuDoubleComplex *, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, csrsv2Info_t, cuDoubleComplex const *, cuDoubleComplex *, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZcsrsv2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrsv2_solve", kApiTypeCuSolver);

    lretval = lcusparseZcsrsv2_solve(handle, transA, m, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, f, x, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrsv2_solve cusparseZcsrsv2_solve


#undef cusparseXbsrsv2_zeroPivot
cusparseStatus_t cusparseXbsrsv2_zeroPivot(cusparseHandle_t handle, bsrsv2Info_t info, int * position){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXbsrsv2_zeroPivot) (cusparseHandle_t, bsrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, bsrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseXbsrsv2_zeroPivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXbsrsv2_zeroPivot", kApiTypeCuSolver);

    lretval = lcusparseXbsrsv2_zeroPivot(handle, info, position);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXbsrsv2_zeroPivot cusparseXbsrsv2_zeroPivot


#undef cusparseSbsrsv2_bufferSize
cusparseStatus_t cusparseSbsrsv2_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrsv2_bufferSize) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseSbsrsv2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrsv2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSbsrsv2_bufferSize(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrsv2_bufferSize cusparseSbsrsv2_bufferSize


#undef cusparseDbsrsv2_bufferSize
cusparseStatus_t cusparseDbsrsv2_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrsv2_bufferSize) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseDbsrsv2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrsv2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDbsrsv2_bufferSize(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrsv2_bufferSize cusparseDbsrsv2_bufferSize


#undef cusparseCbsrsv2_bufferSize
cusparseStatus_t cusparseCbsrsv2_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrsv2_bufferSize) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseCbsrsv2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrsv2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCbsrsv2_bufferSize(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrsv2_bufferSize cusparseCbsrsv2_bufferSize


#undef cusparseZbsrsv2_bufferSize
cusparseStatus_t cusparseZbsrsv2_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrsv2_bufferSize) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrsv2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrsv2Info_t, int *))dlsym(RTLD_NEXT, "cusparseZbsrsv2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrsv2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZbsrsv2_bufferSize(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrsv2_bufferSize cusparseZbsrsv2_bufferSize


#undef cusparseSbsrsv2_bufferSizeExt
cusparseStatus_t cusparseSbsrsv2_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockSize, bsrsv2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrsv2_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrsv2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrsv2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseSbsrsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSbsrsv2_bufferSizeExt(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrsv2_bufferSizeExt cusparseSbsrsv2_bufferSizeExt


#undef cusparseDbsrsv2_bufferSizeExt
cusparseStatus_t cusparseDbsrsv2_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockSize, bsrsv2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrsv2_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrsv2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrsv2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseDbsrsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDbsrsv2_bufferSizeExt(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrsv2_bufferSizeExt cusparseDbsrsv2_bufferSizeExt


#undef cusparseCbsrsv2_bufferSizeExt
cusparseStatus_t cusparseCbsrsv2_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockSize, bsrsv2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrsv2_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrsv2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrsv2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseCbsrsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCbsrsv2_bufferSizeExt(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrsv2_bufferSizeExt cusparseCbsrsv2_bufferSizeExt


#undef cusparseZbsrsv2_bufferSizeExt
cusparseStatus_t cusparseZbsrsv2_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockSize, bsrsv2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrsv2_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrsv2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrsv2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseZbsrsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZbsrsv2_bufferSizeExt(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrsv2_bufferSizeExt cusparseZbsrsv2_bufferSizeExt


#undef cusparseSbsrsv2_analysis
cusparseStatus_t cusparseSbsrsv2_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrsv2_analysis) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsrsv2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsrsv2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseSbsrsv2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrsv2_analysis", kApiTypeCuSolver);

    lretval = lcusparseSbsrsv2_analysis(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrsv2_analysis cusparseSbsrsv2_analysis


#undef cusparseDbsrsv2_analysis
cusparseStatus_t cusparseDbsrsv2_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrsv2_analysis) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsrsv2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsrsv2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDbsrsv2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrsv2_analysis", kApiTypeCuSolver);

    lretval = lcusparseDbsrsv2_analysis(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrsv2_analysis cusparseDbsrsv2_analysis


#undef cusparseCbsrsv2_analysis
cusparseStatus_t cusparseCbsrsv2_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrsv2_analysis) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsrsv2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsrsv2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCbsrsv2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrsv2_analysis", kApiTypeCuSolver);

    lretval = lcusparseCbsrsv2_analysis(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrsv2_analysis cusparseCbsrsv2_analysis


#undef cusparseZbsrsv2_analysis
cusparseStatus_t cusparseZbsrsv2_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrsv2_analysis) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsrsv2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsrsv2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZbsrsv2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrsv2_analysis", kApiTypeCuSolver);

    lretval = lcusparseZbsrsv2_analysis(handle, dirA, transA, mb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrsv2_analysis cusparseZbsrsv2_analysis


#undef cusparseSbsrsv2_solve
cusparseStatus_t cusparseSbsrsv2_solve(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, float const * alpha, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, float const * f, float * x, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrsv2_solve) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsrsv2Info_t, float const *, float *, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsrsv2Info_t, float const *, float *, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseSbsrsv2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrsv2_solve", kApiTypeCuSolver);

    lretval = lcusparseSbsrsv2_solve(handle, dirA, transA, mb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, f, x, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrsv2_solve cusparseSbsrsv2_solve


#undef cusparseDbsrsv2_solve
cusparseStatus_t cusparseDbsrsv2_solve(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, double const * alpha, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, double const * f, double * x, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrsv2_solve) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsrsv2Info_t, double const *, double *, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsrsv2Info_t, double const *, double *, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDbsrsv2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrsv2_solve", kApiTypeCuSolver);

    lretval = lcusparseDbsrsv2_solve(handle, dirA, transA, mb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, f, x, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrsv2_solve cusparseDbsrsv2_solve


#undef cusparseCbsrsv2_solve
cusparseStatus_t cusparseCbsrsv2_solve(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cuComplex const * alpha, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, cuComplex const * f, cuComplex * x, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrsv2_solve) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsrsv2Info_t, cuComplex const *, cuComplex *, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsrsv2Info_t, cuComplex const *, cuComplex *, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCbsrsv2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrsv2_solve", kApiTypeCuSolver);

    lretval = lcusparseCbsrsv2_solve(handle, dirA, transA, mb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, f, x, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrsv2_solve cusparseCbsrsv2_solve


#undef cusparseZbsrsv2_solve
cusparseStatus_t cusparseZbsrsv2_solve(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, int mb, int nnzb, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, bsrsv2Info_t info, cuDoubleComplex const * f, cuDoubleComplex * x, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrsv2_solve) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsrsv2Info_t, cuDoubleComplex const *, cuDoubleComplex *, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsrsv2Info_t, cuDoubleComplex const *, cuDoubleComplex *, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZbsrsv2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrsv2_solve", kApiTypeCuSolver);

    lretval = lcusparseZbsrsv2_solve(handle, dirA, transA, mb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, info, f, x, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrsv2_solve cusparseZbsrsv2_solve


#undef cusparseSbsrmm
cusparseStatus_t cusparseSbsrmm(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transB, int mb, int n, int kb, int nnzb, float const * alpha, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int const blockSize, float const * B, int const ldb, float const * beta, float * C, int ldc){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrmm) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int const, float const *, int const, float const *, float *, int) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int const, float const *, int const, float const *, float *, int))dlsym(RTLD_NEXT, "cusparseSbsrmm");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrmm", kApiTypeCuSolver);

    lretval = lcusparseSbsrmm(handle, dirA, transA, transB, mb, n, kb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockSize, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrmm cusparseSbsrmm


#undef cusparseDbsrmm
cusparseStatus_t cusparseDbsrmm(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transB, int mb, int n, int kb, int nnzb, double const * alpha, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int const blockSize, double const * B, int const ldb, double const * beta, double * C, int ldc){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrmm) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int const, double const *, int const, double const *, double *, int) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int const, double const *, int const, double const *, double *, int))dlsym(RTLD_NEXT, "cusparseDbsrmm");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrmm", kApiTypeCuSolver);

    lretval = lcusparseDbsrmm(handle, dirA, transA, transB, mb, n, kb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockSize, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrmm cusparseDbsrmm


#undef cusparseCbsrmm
cusparseStatus_t cusparseCbsrmm(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transB, int mb, int n, int kb, int nnzb, cuComplex const * alpha, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int const blockSize, cuComplex const * B, int const ldb, cuComplex const * beta, cuComplex * C, int ldc){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrmm) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int const, cuComplex const *, int const, cuComplex const *, cuComplex *, int) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int const, cuComplex const *, int const, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cusparseCbsrmm");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrmm", kApiTypeCuSolver);

    lretval = lcusparseCbsrmm(handle, dirA, transA, transB, mb, n, kb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockSize, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrmm cusparseCbsrmm


#undef cusparseZbsrmm
cusparseStatus_t cusparseZbsrmm(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transB, int mb, int n, int kb, int nnzb, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int const blockSize, cuDoubleComplex const * B, int const ldb, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrmm) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int const, cuDoubleComplex const *, int const, cuDoubleComplex const *, cuDoubleComplex *, int) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int const, cuDoubleComplex const *, int const, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cusparseZbsrmm");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrmm", kApiTypeCuSolver);

    lretval = lcusparseZbsrmm(handle, dirA, transA, transB, mb, n, kb, nnzb, alpha, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockSize, B, ldb, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrmm cusparseZbsrmm


#undef cusparseSgemmi
cusparseStatus_t cusparseSgemmi(cusparseHandle_t handle, int m, int n, int k, int nnz, float const * alpha, float const * A, int lda, float const * cscValB, int const * cscColPtrB, int const * cscRowIndB, float const * beta, float * C, int ldc){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgemmi) (cusparseHandle_t, int, int, int, int, float const *, float const *, int, float const *, int const *, int const *, float const *, float *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, int, float const *, float const *, int, float const *, int const *, int const *, float const *, float *, int))dlsym(RTLD_NEXT, "cusparseSgemmi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgemmi", kApiTypeCuSolver);

    lretval = lcusparseSgemmi(handle, m, n, k, nnz, alpha, A, lda, cscValB, cscColPtrB, cscRowIndB, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgemmi cusparseSgemmi


#undef cusparseDgemmi
cusparseStatus_t cusparseDgemmi(cusparseHandle_t handle, int m, int n, int k, int nnz, double const * alpha, double const * A, int lda, double const * cscValB, int const * cscColPtrB, int const * cscRowIndB, double const * beta, double * C, int ldc){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgemmi) (cusparseHandle_t, int, int, int, int, double const *, double const *, int, double const *, int const *, int const *, double const *, double *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, int, double const *, double const *, int, double const *, int const *, int const *, double const *, double *, int))dlsym(RTLD_NEXT, "cusparseDgemmi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgemmi", kApiTypeCuSolver);

    lretval = lcusparseDgemmi(handle, m, n, k, nnz, alpha, A, lda, cscValB, cscColPtrB, cscRowIndB, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgemmi cusparseDgemmi


#undef cusparseCgemmi
cusparseStatus_t cusparseCgemmi(cusparseHandle_t handle, int m, int n, int k, int nnz, cuComplex const * alpha, cuComplex const * A, int lda, cuComplex const * cscValB, int const * cscColPtrB, int const * cscRowIndB, cuComplex const * beta, cuComplex * C, int ldc){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgemmi) (cusparseHandle_t, int, int, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int const *, int const *, cuComplex const *, cuComplex *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, int, cuComplex const *, cuComplex const *, int, cuComplex const *, int const *, int const *, cuComplex const *, cuComplex *, int))dlsym(RTLD_NEXT, "cusparseCgemmi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgemmi", kApiTypeCuSolver);

    lretval = lcusparseCgemmi(handle, m, n, k, nnz, alpha, A, lda, cscValB, cscColPtrB, cscRowIndB, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgemmi cusparseCgemmi


#undef cusparseZgemmi
cusparseStatus_t cusparseZgemmi(cusparseHandle_t handle, int m, int n, int k, int nnz, cuDoubleComplex const * alpha, cuDoubleComplex const * A, int lda, cuDoubleComplex const * cscValB, int const * cscColPtrB, int const * cscRowIndB, cuDoubleComplex const * beta, cuDoubleComplex * C, int ldc){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgemmi) (cusparseHandle_t, int, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cuDoubleComplex *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, int, cuDoubleComplex const *, cuDoubleComplex const *, int, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cusparseZgemmi");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgemmi", kApiTypeCuSolver);

    lretval = lcusparseZgemmi(handle, m, n, k, nnz, alpha, A, lda, cscValB, cscColPtrB, cscRowIndB, beta, C, ldc);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgemmi cusparseZgemmi


#undef cusparseCreateCsrsm2Info
cusparseStatus_t cusparseCreateCsrsm2Info(csrsm2Info_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCsrsm2Info) (csrsm2Info_t *) = (cusparseStatus_t (*)(csrsm2Info_t *))dlsym(RTLD_NEXT, "cusparseCreateCsrsm2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCsrsm2Info", kApiTypeCuSolver);

    lretval = lcusparseCreateCsrsm2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCsrsm2Info cusparseCreateCsrsm2Info


#undef cusparseDestroyCsrsm2Info
cusparseStatus_t cusparseDestroyCsrsm2Info(csrsm2Info_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyCsrsm2Info) (csrsm2Info_t) = (cusparseStatus_t (*)(csrsm2Info_t))dlsym(RTLD_NEXT, "cusparseDestroyCsrsm2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyCsrsm2Info", kApiTypeCuSolver);

    lretval = lcusparseDestroyCsrsm2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyCsrsm2Info cusparseDestroyCsrsm2Info


#undef cusparseXcsrsm2_zeroPivot
cusparseStatus_t cusparseXcsrsm2_zeroPivot(cusparseHandle_t handle, csrsm2Info_t info, int * position){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsrsm2_zeroPivot) (cusparseHandle_t, csrsm2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, csrsm2Info_t, int *))dlsym(RTLD_NEXT, "cusparseXcsrsm2_zeroPivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsrsm2_zeroPivot", kApiTypeCuSolver);

    lretval = lcusparseXcsrsm2_zeroPivot(handle, info, position);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsrsm2_zeroPivot cusparseXcsrsm2_zeroPivot


#undef cusparseScsrsm2_bufferSizeExt
cusparseStatus_t cusparseScsrsm2_bufferSizeExt(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, float const * alpha, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float const * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrsm2_bufferSizeExt) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, int, csrsm2Info_t, cusparseSolvePolicy_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, int, csrsm2Info_t, cusparseSolvePolicy_t, size_t *))dlsym(RTLD_NEXT, "cusparseScsrsm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrsm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseScsrsm2_bufferSizeExt(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrsm2_bufferSizeExt cusparseScsrsm2_bufferSizeExt


#undef cusparseDcsrsm2_bufferSizeExt
cusparseStatus_t cusparseDcsrsm2_bufferSizeExt(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, double const * alpha, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double const * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrsm2_bufferSizeExt) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, int, csrsm2Info_t, cusparseSolvePolicy_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, int, csrsm2Info_t, cusparseSolvePolicy_t, size_t *))dlsym(RTLD_NEXT, "cusparseDcsrsm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrsm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDcsrsm2_bufferSizeExt(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrsm2_bufferSizeExt cusparseDcsrsm2_bufferSizeExt


#undef cusparseCcsrsm2_bufferSizeExt
cusparseStatus_t cusparseCcsrsm2_bufferSizeExt(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, cuComplex const * alpha, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuComplex const * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrsm2_bufferSizeExt) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, int, csrsm2Info_t, cusparseSolvePolicy_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, int, csrsm2Info_t, cusparseSolvePolicy_t, size_t *))dlsym(RTLD_NEXT, "cusparseCcsrsm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrsm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCcsrsm2_bufferSizeExt(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrsm2_bufferSizeExt cusparseCcsrsm2_bufferSizeExt


#undef cusparseZcsrsm2_bufferSizeExt
cusparseStatus_t cusparseZcsrsm2_bufferSizeExt(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuDoubleComplex const * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrsm2_bufferSizeExt) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, int, csrsm2Info_t, cusparseSolvePolicy_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, int, csrsm2Info_t, cusparseSolvePolicy_t, size_t *))dlsym(RTLD_NEXT, "cusparseZcsrsm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrsm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZcsrsm2_bufferSizeExt(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrsm2_bufferSizeExt cusparseZcsrsm2_bufferSizeExt


#undef cusparseScsrsm2_analysis
cusparseStatus_t cusparseScsrsm2_analysis(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, float const * alpha, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float const * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrsm2_analysis) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseScsrsm2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrsm2_analysis", kApiTypeCuSolver);

    lretval = lcusparseScsrsm2_analysis(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrsm2_analysis cusparseScsrsm2_analysis


#undef cusparseDcsrsm2_analysis
cusparseStatus_t cusparseDcsrsm2_analysis(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, double const * alpha, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double const * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrsm2_analysis) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDcsrsm2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrsm2_analysis", kApiTypeCuSolver);

    lretval = lcusparseDcsrsm2_analysis(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrsm2_analysis cusparseDcsrsm2_analysis


#undef cusparseCcsrsm2_analysis
cusparseStatus_t cusparseCcsrsm2_analysis(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, cuComplex const * alpha, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuComplex const * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrsm2_analysis) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex const *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCcsrsm2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrsm2_analysis", kApiTypeCuSolver);

    lretval = lcusparseCcsrsm2_analysis(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrsm2_analysis cusparseCcsrsm2_analysis


#undef cusparseZcsrsm2_analysis
cusparseStatus_t cusparseZcsrsm2_analysis(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuDoubleComplex const * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrsm2_analysis) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZcsrsm2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrsm2_analysis", kApiTypeCuSolver);

    lretval = lcusparseZcsrsm2_analysis(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrsm2_analysis cusparseZcsrsm2_analysis


#undef cusparseScsrsm2_solve
cusparseStatus_t cusparseScsrsm2_solve(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, float const * alpha, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrsm2_solve) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, float *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, float *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseScsrsm2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrsm2_solve", kApiTypeCuSolver);

    lretval = lcusparseScsrsm2_solve(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrsm2_solve cusparseScsrsm2_solve


#undef cusparseDcsrsm2_solve
cusparseStatus_t cusparseDcsrsm2_solve(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, double const * alpha, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrsm2_solve) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, double *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, double *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDcsrsm2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrsm2_solve", kApiTypeCuSolver);

    lretval = lcusparseDcsrsm2_solve(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrsm2_solve cusparseDcsrsm2_solve


#undef cusparseCcsrsm2_solve
cusparseStatus_t cusparseCcsrsm2_solve(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, cuComplex const * alpha, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuComplex * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrsm2_solve) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCcsrsm2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrsm2_solve", kApiTypeCuSolver);

    lretval = lcusparseCcsrsm2_solve(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrsm2_solve cusparseCcsrsm2_solve


#undef cusparseZcsrsm2_solve
cusparseStatus_t cusparseZcsrsm2_solve(cusparseHandle_t handle, int algo, cusparseOperation_t transA, cusparseOperation_t transB, int m, int nrhs, int nnz, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuDoubleComplex * B, int ldb, csrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrsm2_solve) (cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseOperation_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex *, int, csrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZcsrsm2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrsm2_solve", kApiTypeCuSolver);

    lretval = lcusparseZcsrsm2_solve(handle, algo, transA, transB, m, nrhs, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, B, ldb, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrsm2_solve cusparseZcsrsm2_solve


#undef cusparseXbsrsm2_zeroPivot
cusparseStatus_t cusparseXbsrsm2_zeroPivot(cusparseHandle_t handle, bsrsm2Info_t info, int * position){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXbsrsm2_zeroPivot) (cusparseHandle_t, bsrsm2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, bsrsm2Info_t, int *))dlsym(RTLD_NEXT, "cusparseXbsrsm2_zeroPivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXbsrsm2_zeroPivot", kApiTypeCuSolver);

    lretval = lcusparseXbsrsm2_zeroPivot(handle, info, position);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXbsrsm2_zeroPivot cusparseXbsrsm2_zeroPivot


#undef cusparseSbsrsm2_bufferSize
cusparseStatus_t cusparseSbsrsm2_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrsm2_bufferSize) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrsm2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrsm2Info_t, int *))dlsym(RTLD_NEXT, "cusparseSbsrsm2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrsm2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSbsrsm2_bufferSize(handle, dirA, transA, transXY, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrsm2_bufferSize cusparseSbsrsm2_bufferSize


#undef cusparseDbsrsm2_bufferSize
cusparseStatus_t cusparseDbsrsm2_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrsm2_bufferSize) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrsm2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrsm2Info_t, int *))dlsym(RTLD_NEXT, "cusparseDbsrsm2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrsm2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDbsrsm2_bufferSize(handle, dirA, transA, transXY, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrsm2_bufferSize cusparseDbsrsm2_bufferSize


#undef cusparseCbsrsm2_bufferSize
cusparseStatus_t cusparseCbsrsm2_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrsm2_bufferSize) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrsm2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrsm2Info_t, int *))dlsym(RTLD_NEXT, "cusparseCbsrsm2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrsm2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCbsrsm2_bufferSize(handle, dirA, transA, transXY, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrsm2_bufferSize cusparseCbsrsm2_bufferSize


#undef cusparseZbsrsm2_bufferSize
cusparseStatus_t cusparseZbsrsm2_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrsm2_bufferSize) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrsm2Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrsm2Info_t, int *))dlsym(RTLD_NEXT, "cusparseZbsrsm2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrsm2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZbsrsm2_bufferSize(handle, dirA, transA, transXY, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrsm2_bufferSize cusparseZbsrsm2_bufferSize


#undef cusparseSbsrsm2_bufferSizeExt
cusparseStatus_t cusparseSbsrsm2_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transB, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrsm2_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrsm2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrsm2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseSbsrsm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrsm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSbsrsm2_bufferSizeExt(handle, dirA, transA, transB, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrsm2_bufferSizeExt cusparseSbsrsm2_bufferSizeExt


#undef cusparseDbsrsm2_bufferSizeExt
cusparseStatus_t cusparseDbsrsm2_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transB, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrsm2_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrsm2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrsm2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseDbsrsm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrsm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDbsrsm2_bufferSizeExt(handle, dirA, transA, transB, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrsm2_bufferSizeExt cusparseDbsrsm2_bufferSizeExt


#undef cusparseCbsrsm2_bufferSizeExt
cusparseStatus_t cusparseCbsrsm2_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transB, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrsm2_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrsm2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrsm2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseCbsrsm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrsm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCbsrsm2_bufferSizeExt(handle, dirA, transA, transB, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrsm2_bufferSizeExt cusparseCbsrsm2_bufferSizeExt


#undef cusparseZbsrsm2_bufferSizeExt
cusparseStatus_t cusparseZbsrsm2_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transB, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrsm2_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrsm2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrsm2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseZbsrsm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrsm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZbsrsm2_bufferSizeExt(handle, dirA, transA, transB, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrsm2_bufferSizeExt cusparseZbsrsm2_bufferSizeExt


#undef cusparseSbsrsm2_analysis
cusparseStatus_t cusparseSbsrsm2_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, float const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrsm2_analysis) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseSbsrsm2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrsm2_analysis", kApiTypeCuSolver);

    lretval = lcusparseSbsrsm2_analysis(handle, dirA, transA, transXY, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrsm2_analysis cusparseSbsrsm2_analysis


#undef cusparseDbsrsm2_analysis
cusparseStatus_t cusparseDbsrsm2_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, double const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrsm2_analysis) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDbsrsm2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrsm2_analysis", kApiTypeCuSolver);

    lretval = lcusparseDbsrsm2_analysis(handle, dirA, transA, transXY, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrsm2_analysis cusparseDbsrsm2_analysis


#undef cusparseCbsrsm2_analysis
cusparseStatus_t cusparseCbsrsm2_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrsm2_analysis) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCbsrsm2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrsm2_analysis", kApiTypeCuSolver);

    lretval = lcusparseCbsrsm2_analysis(handle, dirA, transA, transXY, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrsm2_analysis cusparseCbsrsm2_analysis


#undef cusparseZbsrsm2_analysis
cusparseStatus_t cusparseZbsrsm2_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrsm2_analysis) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsrsm2Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsrsm2Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZbsrsm2_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrsm2_analysis", kApiTypeCuSolver);

    lretval = lcusparseZbsrsm2_analysis(handle, dirA, transA, transXY, mb, n, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrsm2_analysis cusparseZbsrsm2_analysis


#undef cusparseSbsrsm2_solve
cusparseStatus_t cusparseSbsrsm2_solve(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, float const * alpha, cusparseMatDescr_t const descrA, float const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, float const * B, int ldb, float * X, int ldx, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrsm2_solve) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsrsm2Info_t, float const *, int, float *, int, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsrsm2Info_t, float const *, int, float *, int, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseSbsrsm2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrsm2_solve", kApiTypeCuSolver);

    lretval = lcusparseSbsrsm2_solve(handle, dirA, transA, transXY, mb, n, nnzb, alpha, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, B, ldb, X, ldx, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrsm2_solve cusparseSbsrsm2_solve


#undef cusparseDbsrsm2_solve
cusparseStatus_t cusparseDbsrsm2_solve(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, double const * alpha, cusparseMatDescr_t const descrA, double const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, double const * B, int ldb, double * X, int ldx, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrsm2_solve) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsrsm2Info_t, double const *, int, double *, int, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsrsm2Info_t, double const *, int, double *, int, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDbsrsm2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrsm2_solve", kApiTypeCuSolver);

    lretval = lcusparseDbsrsm2_solve(handle, dirA, transA, transXY, mb, n, nnzb, alpha, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, B, ldb, X, ldx, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrsm2_solve cusparseDbsrsm2_solve


#undef cusparseCbsrsm2_solve
cusparseStatus_t cusparseCbsrsm2_solve(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cuComplex const * alpha, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, cuComplex const * B, int ldb, cuComplex * X, int ldx, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrsm2_solve) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsrsm2Info_t, cuComplex const *, int, cuComplex *, int, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsrsm2Info_t, cuComplex const *, int, cuComplex *, int, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCbsrsm2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrsm2_solve", kApiTypeCuSolver);

    lretval = lcusparseCbsrsm2_solve(handle, dirA, transA, transXY, mb, n, nnzb, alpha, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, B, ldb, X, ldx, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrsm2_solve cusparseCbsrsm2_solve


#undef cusparseZbsrsm2_solve
cusparseStatus_t cusparseZbsrsm2_solve(cusparseHandle_t handle, cusparseDirection_t dirA, cusparseOperation_t transA, cusparseOperation_t transXY, int mb, int n, int nnzb, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrsm2Info_t info, cuDoubleComplex const * B, int ldb, cuDoubleComplex * X, int ldx, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrsm2_solve) (cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsrsm2Info_t, cuDoubleComplex const *, int, cuDoubleComplex *, int, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, cusparseOperation_t, cusparseOperation_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsrsm2Info_t, cuDoubleComplex const *, int, cuDoubleComplex *, int, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZbsrsm2_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrsm2_solve", kApiTypeCuSolver);

    lretval = lcusparseZbsrsm2_solve(handle, dirA, transA, transXY, mb, n, nnzb, alpha, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, B, ldb, X, ldx, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrsm2_solve cusparseZbsrsm2_solve


#undef cusparseScsrilu02_numericBoost
cusparseStatus_t cusparseScsrilu02_numericBoost(cusparseHandle_t handle, csrilu02Info_t info, int enable_boost, double * tol, float * boost_val){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrilu02_numericBoost) (cusparseHandle_t, csrilu02Info_t, int, double *, float *) = (cusparseStatus_t (*)(cusparseHandle_t, csrilu02Info_t, int, double *, float *))dlsym(RTLD_NEXT, "cusparseScsrilu02_numericBoost");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrilu02_numericBoost", kApiTypeCuSolver);

    lretval = lcusparseScsrilu02_numericBoost(handle, info, enable_boost, tol, boost_val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrilu02_numericBoost cusparseScsrilu02_numericBoost


#undef cusparseDcsrilu02_numericBoost
cusparseStatus_t cusparseDcsrilu02_numericBoost(cusparseHandle_t handle, csrilu02Info_t info, int enable_boost, double * tol, double * boost_val){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrilu02_numericBoost) (cusparseHandle_t, csrilu02Info_t, int, double *, double *) = (cusparseStatus_t (*)(cusparseHandle_t, csrilu02Info_t, int, double *, double *))dlsym(RTLD_NEXT, "cusparseDcsrilu02_numericBoost");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrilu02_numericBoost", kApiTypeCuSolver);

    lretval = lcusparseDcsrilu02_numericBoost(handle, info, enable_boost, tol, boost_val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrilu02_numericBoost cusparseDcsrilu02_numericBoost


#undef cusparseCcsrilu02_numericBoost
cusparseStatus_t cusparseCcsrilu02_numericBoost(cusparseHandle_t handle, csrilu02Info_t info, int enable_boost, double * tol, cuComplex * boost_val){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrilu02_numericBoost) (cusparseHandle_t, csrilu02Info_t, int, double *, cuComplex *) = (cusparseStatus_t (*)(cusparseHandle_t, csrilu02Info_t, int, double *, cuComplex *))dlsym(RTLD_NEXT, "cusparseCcsrilu02_numericBoost");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrilu02_numericBoost", kApiTypeCuSolver);

    lretval = lcusparseCcsrilu02_numericBoost(handle, info, enable_boost, tol, boost_val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrilu02_numericBoost cusparseCcsrilu02_numericBoost


#undef cusparseZcsrilu02_numericBoost
cusparseStatus_t cusparseZcsrilu02_numericBoost(cusparseHandle_t handle, csrilu02Info_t info, int enable_boost, double * tol, cuDoubleComplex * boost_val){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrilu02_numericBoost) (cusparseHandle_t, csrilu02Info_t, int, double *, cuDoubleComplex *) = (cusparseStatus_t (*)(cusparseHandle_t, csrilu02Info_t, int, double *, cuDoubleComplex *))dlsym(RTLD_NEXT, "cusparseZcsrilu02_numericBoost");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrilu02_numericBoost", kApiTypeCuSolver);

    lretval = lcusparseZcsrilu02_numericBoost(handle, info, enable_boost, tol, boost_val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrilu02_numericBoost cusparseZcsrilu02_numericBoost


#undef cusparseXcsrilu02_zeroPivot
cusparseStatus_t cusparseXcsrilu02_zeroPivot(cusparseHandle_t handle, csrilu02Info_t info, int * position){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsrilu02_zeroPivot) (cusparseHandle_t, csrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, csrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseXcsrilu02_zeroPivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsrilu02_zeroPivot", kApiTypeCuSolver);

    lretval = lcusparseXcsrilu02_zeroPivot(handle, info, position);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsrilu02_zeroPivot cusparseXcsrilu02_zeroPivot


#undef cusparseScsrilu02_bufferSize
cusparseStatus_t cusparseScsrilu02_bufferSize(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrilu02_bufferSize) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseScsrilu02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrilu02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseScsrilu02_bufferSize(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrilu02_bufferSize cusparseScsrilu02_bufferSize


#undef cusparseDcsrilu02_bufferSize
cusparseStatus_t cusparseDcsrilu02_bufferSize(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrilu02_bufferSize) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseDcsrilu02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrilu02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDcsrilu02_bufferSize(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrilu02_bufferSize cusparseDcsrilu02_bufferSize


#undef cusparseCcsrilu02_bufferSize
cusparseStatus_t cusparseCcsrilu02_bufferSize(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrilu02_bufferSize) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseCcsrilu02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrilu02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCcsrilu02_bufferSize(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrilu02_bufferSize cusparseCcsrilu02_bufferSize


#undef cusparseZcsrilu02_bufferSize
cusparseStatus_t cusparseZcsrilu02_bufferSize(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrilu02_bufferSize) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseZcsrilu02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrilu02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZcsrilu02_bufferSize(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrilu02_bufferSize cusparseZcsrilu02_bufferSize


#undef cusparseScsrilu02_bufferSizeExt
cusparseStatus_t cusparseScsrilu02_bufferSizeExt(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float * csrSortedVal, int const * csrSortedRowPtr, int const * csrSortedColInd, csrilu02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrilu02_bufferSizeExt) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrilu02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrilu02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseScsrilu02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrilu02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseScsrilu02_bufferSizeExt(handle, m, nnz, descrA, csrSortedVal, csrSortedRowPtr, csrSortedColInd, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrilu02_bufferSizeExt cusparseScsrilu02_bufferSizeExt


#undef cusparseDcsrilu02_bufferSizeExt
cusparseStatus_t cusparseDcsrilu02_bufferSizeExt(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double * csrSortedVal, int const * csrSortedRowPtr, int const * csrSortedColInd, csrilu02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrilu02_bufferSizeExt) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrilu02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrilu02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseDcsrilu02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrilu02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDcsrilu02_bufferSizeExt(handle, m, nnz, descrA, csrSortedVal, csrSortedRowPtr, csrSortedColInd, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrilu02_bufferSizeExt cusparseDcsrilu02_bufferSizeExt


#undef cusparseCcsrilu02_bufferSizeExt
cusparseStatus_t cusparseCcsrilu02_bufferSizeExt(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrSortedVal, int const * csrSortedRowPtr, int const * csrSortedColInd, csrilu02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrilu02_bufferSizeExt) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrilu02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrilu02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseCcsrilu02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrilu02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCcsrilu02_bufferSizeExt(handle, m, nnz, descrA, csrSortedVal, csrSortedRowPtr, csrSortedColInd, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrilu02_bufferSizeExt cusparseCcsrilu02_bufferSizeExt


#undef cusparseZcsrilu02_bufferSizeExt
cusparseStatus_t cusparseZcsrilu02_bufferSizeExt(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrSortedVal, int const * csrSortedRowPtr, int const * csrSortedColInd, csrilu02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrilu02_bufferSizeExt) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrilu02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrilu02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseZcsrilu02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrilu02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZcsrilu02_bufferSizeExt(handle, m, nnz, descrA, csrSortedVal, csrSortedRowPtr, csrSortedColInd, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrilu02_bufferSizeExt cusparseZcsrilu02_bufferSizeExt


#undef cusparseScsrilu02_analysis
cusparseStatus_t cusparseScsrilu02_analysis(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrilu02_analysis) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseScsrilu02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrilu02_analysis", kApiTypeCuSolver);

    lretval = lcusparseScsrilu02_analysis(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrilu02_analysis cusparseScsrilu02_analysis


#undef cusparseDcsrilu02_analysis
cusparseStatus_t cusparseDcsrilu02_analysis(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrilu02_analysis) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDcsrilu02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrilu02_analysis", kApiTypeCuSolver);

    lretval = lcusparseDcsrilu02_analysis(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrilu02_analysis cusparseDcsrilu02_analysis


#undef cusparseCcsrilu02_analysis
cusparseStatus_t cusparseCcsrilu02_analysis(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrilu02_analysis) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCcsrilu02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrilu02_analysis", kApiTypeCuSolver);

    lretval = lcusparseCcsrilu02_analysis(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrilu02_analysis cusparseCcsrilu02_analysis


#undef cusparseZcsrilu02_analysis
cusparseStatus_t cusparseZcsrilu02_analysis(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrilu02_analysis) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZcsrilu02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrilu02_analysis", kApiTypeCuSolver);

    lretval = lcusparseZcsrilu02_analysis(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrilu02_analysis cusparseZcsrilu02_analysis


#undef cusparseScsrilu02
cusparseStatus_t cusparseScsrilu02(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float * csrSortedValA_valM, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrilu02) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseScsrilu02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrilu02", kApiTypeCuSolver);

    lretval = lcusparseScsrilu02(handle, m, nnz, descrA, csrSortedValA_valM, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrilu02 cusparseScsrilu02


#undef cusparseDcsrilu02
cusparseStatus_t cusparseDcsrilu02(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double * csrSortedValA_valM, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrilu02) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDcsrilu02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrilu02", kApiTypeCuSolver);

    lretval = lcusparseDcsrilu02(handle, m, nnz, descrA, csrSortedValA_valM, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrilu02 cusparseDcsrilu02


#undef cusparseCcsrilu02
cusparseStatus_t cusparseCcsrilu02(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrSortedValA_valM, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrilu02) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCcsrilu02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrilu02", kApiTypeCuSolver);

    lretval = lcusparseCcsrilu02(handle, m, nnz, descrA, csrSortedValA_valM, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrilu02 cusparseCcsrilu02


#undef cusparseZcsrilu02
cusparseStatus_t cusparseZcsrilu02(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrSortedValA_valM, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrilu02) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZcsrilu02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrilu02", kApiTypeCuSolver);

    lretval = lcusparseZcsrilu02(handle, m, nnz, descrA, csrSortedValA_valM, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrilu02 cusparseZcsrilu02


#undef cusparseSbsrilu02_numericBoost
cusparseStatus_t cusparseSbsrilu02_numericBoost(cusparseHandle_t handle, bsrilu02Info_t info, int enable_boost, double * tol, float * boost_val){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrilu02_numericBoost) (cusparseHandle_t, bsrilu02Info_t, int, double *, float *) = (cusparseStatus_t (*)(cusparseHandle_t, bsrilu02Info_t, int, double *, float *))dlsym(RTLD_NEXT, "cusparseSbsrilu02_numericBoost");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrilu02_numericBoost", kApiTypeCuSolver);

    lretval = lcusparseSbsrilu02_numericBoost(handle, info, enable_boost, tol, boost_val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrilu02_numericBoost cusparseSbsrilu02_numericBoost


#undef cusparseDbsrilu02_numericBoost
cusparseStatus_t cusparseDbsrilu02_numericBoost(cusparseHandle_t handle, bsrilu02Info_t info, int enable_boost, double * tol, double * boost_val){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrilu02_numericBoost) (cusparseHandle_t, bsrilu02Info_t, int, double *, double *) = (cusparseStatus_t (*)(cusparseHandle_t, bsrilu02Info_t, int, double *, double *))dlsym(RTLD_NEXT, "cusparseDbsrilu02_numericBoost");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrilu02_numericBoost", kApiTypeCuSolver);

    lretval = lcusparseDbsrilu02_numericBoost(handle, info, enable_boost, tol, boost_val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrilu02_numericBoost cusparseDbsrilu02_numericBoost


#undef cusparseCbsrilu02_numericBoost
cusparseStatus_t cusparseCbsrilu02_numericBoost(cusparseHandle_t handle, bsrilu02Info_t info, int enable_boost, double * tol, cuComplex * boost_val){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrilu02_numericBoost) (cusparseHandle_t, bsrilu02Info_t, int, double *, cuComplex *) = (cusparseStatus_t (*)(cusparseHandle_t, bsrilu02Info_t, int, double *, cuComplex *))dlsym(RTLD_NEXT, "cusparseCbsrilu02_numericBoost");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrilu02_numericBoost", kApiTypeCuSolver);

    lretval = lcusparseCbsrilu02_numericBoost(handle, info, enable_boost, tol, boost_val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrilu02_numericBoost cusparseCbsrilu02_numericBoost


#undef cusparseZbsrilu02_numericBoost
cusparseStatus_t cusparseZbsrilu02_numericBoost(cusparseHandle_t handle, bsrilu02Info_t info, int enable_boost, double * tol, cuDoubleComplex * boost_val){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrilu02_numericBoost) (cusparseHandle_t, bsrilu02Info_t, int, double *, cuDoubleComplex *) = (cusparseStatus_t (*)(cusparseHandle_t, bsrilu02Info_t, int, double *, cuDoubleComplex *))dlsym(RTLD_NEXT, "cusparseZbsrilu02_numericBoost");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrilu02_numericBoost", kApiTypeCuSolver);

    lretval = lcusparseZbsrilu02_numericBoost(handle, info, enable_boost, tol, boost_val);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrilu02_numericBoost cusparseZbsrilu02_numericBoost


#undef cusparseXbsrilu02_zeroPivot
cusparseStatus_t cusparseXbsrilu02_zeroPivot(cusparseHandle_t handle, bsrilu02Info_t info, int * position){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXbsrilu02_zeroPivot) (cusparseHandle_t, bsrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, bsrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseXbsrilu02_zeroPivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXbsrilu02_zeroPivot", kApiTypeCuSolver);

    lretval = lcusparseXbsrilu02_zeroPivot(handle, info, position);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXbsrilu02_zeroPivot cusparseXbsrilu02_zeroPivot


#undef cusparseSbsrilu02_bufferSize
cusparseStatus_t cusparseSbsrilu02_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrilu02_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseSbsrilu02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrilu02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSbsrilu02_bufferSize(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrilu02_bufferSize cusparseSbsrilu02_bufferSize


#undef cusparseDbsrilu02_bufferSize
cusparseStatus_t cusparseDbsrilu02_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrilu02_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseDbsrilu02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrilu02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDbsrilu02_bufferSize(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrilu02_bufferSize cusparseDbsrilu02_bufferSize


#undef cusparseCbsrilu02_bufferSize
cusparseStatus_t cusparseCbsrilu02_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrilu02_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseCbsrilu02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrilu02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCbsrilu02_bufferSize(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrilu02_bufferSize cusparseCbsrilu02_bufferSize


#undef cusparseZbsrilu02_bufferSize
cusparseStatus_t cusparseZbsrilu02_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrilu02_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrilu02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrilu02Info_t, int *))dlsym(RTLD_NEXT, "cusparseZbsrilu02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrilu02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZbsrilu02_bufferSize(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrilu02_bufferSize cusparseZbsrilu02_bufferSize


#undef cusparseSbsrilu02_bufferSizeExt
cusparseStatus_t cusparseSbsrilu02_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrilu02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrilu02_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrilu02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrilu02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseSbsrilu02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrilu02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSbsrilu02_bufferSizeExt(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrilu02_bufferSizeExt cusparseSbsrilu02_bufferSizeExt


#undef cusparseDbsrilu02_bufferSizeExt
cusparseStatus_t cusparseDbsrilu02_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrilu02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrilu02_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrilu02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrilu02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseDbsrilu02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrilu02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDbsrilu02_bufferSizeExt(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrilu02_bufferSizeExt cusparseDbsrilu02_bufferSizeExt


#undef cusparseCbsrilu02_bufferSizeExt
cusparseStatus_t cusparseCbsrilu02_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrilu02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrilu02_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrilu02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrilu02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseCbsrilu02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrilu02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCbsrilu02_bufferSizeExt(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrilu02_bufferSizeExt cusparseCbsrilu02_bufferSizeExt


#undef cusparseZbsrilu02_bufferSizeExt
cusparseStatus_t cusparseZbsrilu02_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsrilu02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrilu02_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrilu02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrilu02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseZbsrilu02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrilu02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZbsrilu02_bufferSizeExt(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrilu02_bufferSizeExt cusparseZbsrilu02_bufferSizeExt


#undef cusparseSbsrilu02_analysis
cusparseStatus_t cusparseSbsrilu02_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrilu02_analysis) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseSbsrilu02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrilu02_analysis", kApiTypeCuSolver);

    lretval = lcusparseSbsrilu02_analysis(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrilu02_analysis cusparseSbsrilu02_analysis


#undef cusparseDbsrilu02_analysis
cusparseStatus_t cusparseDbsrilu02_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrilu02_analysis) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDbsrilu02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrilu02_analysis", kApiTypeCuSolver);

    lretval = lcusparseDbsrilu02_analysis(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrilu02_analysis cusparseDbsrilu02_analysis


#undef cusparseCbsrilu02_analysis
cusparseStatus_t cusparseCbsrilu02_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrilu02_analysis) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCbsrilu02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrilu02_analysis", kApiTypeCuSolver);

    lretval = lcusparseCbsrilu02_analysis(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrilu02_analysis cusparseCbsrilu02_analysis


#undef cusparseZbsrilu02_analysis
cusparseStatus_t cusparseZbsrilu02_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrilu02_analysis) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZbsrilu02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrilu02_analysis", kApiTypeCuSolver);

    lretval = lcusparseZbsrilu02_analysis(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrilu02_analysis cusparseZbsrilu02_analysis


#undef cusparseSbsrilu02
cusparseStatus_t cusparseSbsrilu02(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsrilu02) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseSbsrilu02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsrilu02", kApiTypeCuSolver);

    lretval = lcusparseSbsrilu02(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsrilu02 cusparseSbsrilu02


#undef cusparseDbsrilu02
cusparseStatus_t cusparseDbsrilu02(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsrilu02) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDbsrilu02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsrilu02", kApiTypeCuSolver);

    lretval = lcusparseDbsrilu02(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsrilu02 cusparseDbsrilu02


#undef cusparseCbsrilu02
cusparseStatus_t cusparseCbsrilu02(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsrilu02) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCbsrilu02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsrilu02", kApiTypeCuSolver);

    lretval = lcusparseCbsrilu02(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsrilu02 cusparseCbsrilu02


#undef cusparseZbsrilu02
cusparseStatus_t cusparseZbsrilu02(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsrilu02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsrilu02) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsrilu02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZbsrilu02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsrilu02", kApiTypeCuSolver);

    lretval = lcusparseZbsrilu02(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsrilu02 cusparseZbsrilu02


#undef cusparseXcsric02_zeroPivot
cusparseStatus_t cusparseXcsric02_zeroPivot(cusparseHandle_t handle, csric02Info_t info, int * position){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsric02_zeroPivot) (cusparseHandle_t, csric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, csric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseXcsric02_zeroPivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsric02_zeroPivot", kApiTypeCuSolver);

    lretval = lcusparseXcsric02_zeroPivot(handle, info, position);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsric02_zeroPivot cusparseXcsric02_zeroPivot


#undef cusparseScsric02_bufferSize
cusparseStatus_t cusparseScsric02_bufferSize(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsric02_bufferSize) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseScsric02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsric02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseScsric02_bufferSize(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsric02_bufferSize cusparseScsric02_bufferSize


#undef cusparseDcsric02_bufferSize
cusparseStatus_t cusparseDcsric02_bufferSize(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsric02_bufferSize) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseDcsric02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsric02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDcsric02_bufferSize(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsric02_bufferSize cusparseDcsric02_bufferSize


#undef cusparseCcsric02_bufferSize
cusparseStatus_t cusparseCcsric02_bufferSize(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsric02_bufferSize) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseCcsric02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsric02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCcsric02_bufferSize(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsric02_bufferSize cusparseCcsric02_bufferSize


#undef cusparseZcsric02_bufferSize
cusparseStatus_t cusparseZcsric02_bufferSize(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsric02_bufferSize) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseZcsric02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsric02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZcsric02_bufferSize(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsric02_bufferSize cusparseZcsric02_bufferSize


#undef cusparseScsric02_bufferSizeExt
cusparseStatus_t cusparseScsric02_bufferSizeExt(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float * csrSortedVal, int const * csrSortedRowPtr, int const * csrSortedColInd, csric02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsric02_bufferSizeExt) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csric02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csric02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseScsric02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsric02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseScsric02_bufferSizeExt(handle, m, nnz, descrA, csrSortedVal, csrSortedRowPtr, csrSortedColInd, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsric02_bufferSizeExt cusparseScsric02_bufferSizeExt


#undef cusparseDcsric02_bufferSizeExt
cusparseStatus_t cusparseDcsric02_bufferSizeExt(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double * csrSortedVal, int const * csrSortedRowPtr, int const * csrSortedColInd, csric02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsric02_bufferSizeExt) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csric02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csric02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseDcsric02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsric02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDcsric02_bufferSizeExt(handle, m, nnz, descrA, csrSortedVal, csrSortedRowPtr, csrSortedColInd, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsric02_bufferSizeExt cusparseDcsric02_bufferSizeExt


#undef cusparseCcsric02_bufferSizeExt
cusparseStatus_t cusparseCcsric02_bufferSizeExt(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrSortedVal, int const * csrSortedRowPtr, int const * csrSortedColInd, csric02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsric02_bufferSizeExt) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csric02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csric02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseCcsric02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsric02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCcsric02_bufferSizeExt(handle, m, nnz, descrA, csrSortedVal, csrSortedRowPtr, csrSortedColInd, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsric02_bufferSizeExt cusparseCcsric02_bufferSizeExt


#undef cusparseZcsric02_bufferSizeExt
cusparseStatus_t cusparseZcsric02_bufferSizeExt(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrSortedVal, int const * csrSortedRowPtr, int const * csrSortedColInd, csric02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsric02_bufferSizeExt) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csric02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csric02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseZcsric02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsric02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZcsric02_bufferSizeExt(handle, m, nnz, descrA, csrSortedVal, csrSortedRowPtr, csrSortedColInd, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsric02_bufferSizeExt cusparseZcsric02_bufferSizeExt


#undef cusparseScsric02_analysis
cusparseStatus_t cusparseScsric02_analysis(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsric02_analysis) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseScsric02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsric02_analysis", kApiTypeCuSolver);

    lretval = lcusparseScsric02_analysis(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsric02_analysis cusparseScsric02_analysis


#undef cusparseDcsric02_analysis
cusparseStatus_t cusparseDcsric02_analysis(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsric02_analysis) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDcsric02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsric02_analysis", kApiTypeCuSolver);

    lretval = lcusparseDcsric02_analysis(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsric02_analysis cusparseDcsric02_analysis


#undef cusparseCcsric02_analysis
cusparseStatus_t cusparseCcsric02_analysis(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsric02_analysis) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCcsric02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsric02_analysis", kApiTypeCuSolver);

    lretval = lcusparseCcsric02_analysis(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsric02_analysis cusparseCcsric02_analysis


#undef cusparseZcsric02_analysis
cusparseStatus_t cusparseZcsric02_analysis(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsric02_analysis) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZcsric02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsric02_analysis", kApiTypeCuSolver);

    lretval = lcusparseZcsric02_analysis(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsric02_analysis cusparseZcsric02_analysis


#undef cusparseScsric02
cusparseStatus_t cusparseScsric02(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float * csrSortedValA_valM, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsric02) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseScsric02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsric02", kApiTypeCuSolver);

    lretval = lcusparseScsric02(handle, m, nnz, descrA, csrSortedValA_valM, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsric02 cusparseScsric02


#undef cusparseDcsric02
cusparseStatus_t cusparseDcsric02(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double * csrSortedValA_valM, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsric02) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDcsric02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsric02", kApiTypeCuSolver);

    lretval = lcusparseDcsric02(handle, m, nnz, descrA, csrSortedValA_valM, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsric02 cusparseDcsric02


#undef cusparseCcsric02
cusparseStatus_t cusparseCcsric02(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrSortedValA_valM, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsric02) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCcsric02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsric02", kApiTypeCuSolver);

    lretval = lcusparseCcsric02(handle, m, nnz, descrA, csrSortedValA_valM, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsric02 cusparseCcsric02


#undef cusparseZcsric02
cusparseStatus_t cusparseZcsric02(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrSortedValA_valM, int const * csrSortedRowPtrA, int const * csrSortedColIndA, csric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsric02) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, csric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZcsric02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsric02", kApiTypeCuSolver);

    lretval = lcusparseZcsric02(handle, m, nnz, descrA, csrSortedValA_valM, csrSortedRowPtrA, csrSortedColIndA, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsric02 cusparseZcsric02


#undef cusparseXbsric02_zeroPivot
cusparseStatus_t cusparseXbsric02_zeroPivot(cusparseHandle_t handle, bsric02Info_t info, int * position){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXbsric02_zeroPivot) (cusparseHandle_t, bsric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, bsric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseXbsric02_zeroPivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXbsric02_zeroPivot", kApiTypeCuSolver);

    lretval = lcusparseXbsric02_zeroPivot(handle, info, position);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXbsric02_zeroPivot cusparseXbsric02_zeroPivot


#undef cusparseSbsric02_bufferSize
cusparseStatus_t cusparseSbsric02_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsric02_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseSbsric02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsric02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSbsric02_bufferSize(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsric02_bufferSize cusparseSbsric02_bufferSize


#undef cusparseDbsric02_bufferSize
cusparseStatus_t cusparseDbsric02_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsric02_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseDbsric02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsric02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDbsric02_bufferSize(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsric02_bufferSize cusparseDbsric02_bufferSize


#undef cusparseCbsric02_bufferSize
cusparseStatus_t cusparseCbsric02_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsric02_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseCbsric02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsric02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCbsric02_bufferSize(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsric02_bufferSize cusparseCbsric02_bufferSize


#undef cusparseZbsric02_bufferSize
cusparseStatus_t cusparseZbsric02_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsric02_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsric02Info_t, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsric02Info_t, int *))dlsym(RTLD_NEXT, "cusparseZbsric02_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsric02_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZbsric02_bufferSize(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsric02_bufferSize cusparseZbsric02_bufferSize


#undef cusparseSbsric02_bufferSizeExt
cusparseStatus_t cusparseSbsric02_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsric02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsric02_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsric02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsric02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseSbsric02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsric02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSbsric02_bufferSizeExt(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsric02_bufferSizeExt cusparseSbsric02_bufferSizeExt


#undef cusparseDbsric02_bufferSizeExt
cusparseStatus_t cusparseDbsric02_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsric02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsric02_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsric02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsric02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseDbsric02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsric02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDbsric02_bufferSizeExt(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsric02_bufferSizeExt cusparseDbsric02_bufferSizeExt


#undef cusparseCbsric02_bufferSizeExt
cusparseStatus_t cusparseCbsric02_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsric02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsric02_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsric02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsric02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseCbsric02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsric02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCbsric02_bufferSizeExt(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsric02_bufferSizeExt cusparseCbsric02_bufferSizeExt


#undef cusparseZbsric02_bufferSizeExt
cusparseStatus_t cusparseZbsric02_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockSize, bsric02Info_t info, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsric02_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsric02Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsric02Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseZbsric02_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsric02_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZbsric02_bufferSizeExt(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockSize, info, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsric02_bufferSizeExt cusparseZbsric02_bufferSizeExt


#undef cusparseSbsric02_analysis
cusparseStatus_t cusparseSbsric02_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, float const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, cusparseSolvePolicy_t policy, void * pInputBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsric02_analysis) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseSbsric02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsric02_analysis", kApiTypeCuSolver);

    lretval = lcusparseSbsric02_analysis(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pInputBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsric02_analysis cusparseSbsric02_analysis


#undef cusparseDbsric02_analysis
cusparseStatus_t cusparseDbsric02_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, double const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, cusparseSolvePolicy_t policy, void * pInputBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsric02_analysis) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDbsric02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsric02_analysis", kApiTypeCuSolver);

    lretval = lcusparseDbsric02_analysis(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pInputBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsric02_analysis cusparseDbsric02_analysis


#undef cusparseCbsric02_analysis
cusparseStatus_t cusparseCbsric02_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, cusparseSolvePolicy_t policy, void * pInputBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsric02_analysis) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCbsric02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsric02_analysis", kApiTypeCuSolver);

    lretval = lcusparseCbsric02_analysis(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pInputBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsric02_analysis cusparseCbsric02_analysis


#undef cusparseZbsric02_analysis
cusparseStatus_t cusparseZbsric02_analysis(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, cusparseSolvePolicy_t policy, void * pInputBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsric02_analysis) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZbsric02_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsric02_analysis", kApiTypeCuSolver);

    lretval = lcusparseZbsric02_analysis(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pInputBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsric02_analysis cusparseZbsric02_analysis


#undef cusparseSbsric02
cusparseStatus_t cusparseSbsric02(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, float * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsric02) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseSbsric02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsric02", kApiTypeCuSolver);

    lretval = lcusparseSbsric02(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsric02 cusparseSbsric02


#undef cusparseDbsric02
cusparseStatus_t cusparseDbsric02(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, double * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsric02) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseDbsric02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsric02", kApiTypeCuSolver);

    lretval = lcusparseDbsric02(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsric02 cusparseDbsric02


#undef cusparseCbsric02
cusparseStatus_t cusparseCbsric02(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsric02) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseCbsric02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsric02", kApiTypeCuSolver);

    lretval = lcusparseCbsric02(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsric02 cusparseCbsric02


#undef cusparseZbsric02
cusparseStatus_t cusparseZbsric02(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int blockDim, bsric02Info_t info, cusparseSolvePolicy_t policy, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsric02) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int const *, int, bsric02Info_t, cusparseSolvePolicy_t, void *))dlsym(RTLD_NEXT, "cusparseZbsric02");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsric02", kApiTypeCuSolver);

    lretval = lcusparseZbsric02(handle, dirA, mb, nnzb, descrA, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, blockDim, info, policy, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsric02 cusparseZbsric02


#undef cusparseSgtsv2_bufferSizeExt
cusparseStatus_t cusparseSgtsv2_bufferSizeExt(cusparseHandle_t handle, int m, int n, float const * dl, float const * d, float const * du, float const * B, int ldb, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgtsv2_bufferSizeExt) (cusparseHandle_t, int, int, float const *, float const *, float const *, float const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, float const *, float const *, float const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseSgtsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgtsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSgtsv2_bufferSizeExt(handle, m, n, dl, d, du, B, ldb, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgtsv2_bufferSizeExt cusparseSgtsv2_bufferSizeExt


#undef cusparseDgtsv2_bufferSizeExt
cusparseStatus_t cusparseDgtsv2_bufferSizeExt(cusparseHandle_t handle, int m, int n, double const * dl, double const * d, double const * du, double const * B, int ldb, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgtsv2_bufferSizeExt) (cusparseHandle_t, int, int, double const *, double const *, double const *, double const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, double const *, double const *, double const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseDgtsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgtsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDgtsv2_bufferSizeExt(handle, m, n, dl, d, du, B, ldb, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgtsv2_bufferSizeExt cusparseDgtsv2_bufferSizeExt


#undef cusparseCgtsv2_bufferSizeExt
cusparseStatus_t cusparseCgtsv2_bufferSizeExt(cusparseHandle_t handle, int m, int n, cuComplex const * dl, cuComplex const * d, cuComplex const * du, cuComplex const * B, int ldb, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgtsv2_bufferSizeExt) (cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseCgtsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgtsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCgtsv2_bufferSizeExt(handle, m, n, dl, d, du, B, ldb, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgtsv2_bufferSizeExt cusparseCgtsv2_bufferSizeExt


#undef cusparseZgtsv2_bufferSizeExt
cusparseStatus_t cusparseZgtsv2_bufferSizeExt(cusparseHandle_t handle, int m, int n, cuDoubleComplex const * dl, cuDoubleComplex const * d, cuDoubleComplex const * du, cuDoubleComplex const * B, int ldb, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgtsv2_bufferSizeExt) (cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseZgtsv2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgtsv2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZgtsv2_bufferSizeExt(handle, m, n, dl, d, du, B, ldb, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgtsv2_bufferSizeExt cusparseZgtsv2_bufferSizeExt


#undef cusparseSgtsv2
cusparseStatus_t cusparseSgtsv2(cusparseHandle_t handle, int m, int n, float const * dl, float const * d, float const * du, float * B, int ldb, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgtsv2) (cusparseHandle_t, int, int, float const *, float const *, float const *, float *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, float const *, float const *, float *, int, void *))dlsym(RTLD_NEXT, "cusparseSgtsv2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgtsv2", kApiTypeCuSolver);

    lretval = lcusparseSgtsv2(handle, m, n, dl, d, du, B, ldb, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgtsv2 cusparseSgtsv2


#undef cusparseDgtsv2
cusparseStatus_t cusparseDgtsv2(cusparseHandle_t handle, int m, int n, double const * dl, double const * d, double const * du, double * B, int ldb, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgtsv2) (cusparseHandle_t, int, int, double const *, double const *, double const *, double *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, double const *, double const *, double *, int, void *))dlsym(RTLD_NEXT, "cusparseDgtsv2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgtsv2", kApiTypeCuSolver);

    lretval = lcusparseDgtsv2(handle, m, n, dl, d, du, B, ldb, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgtsv2 cusparseDgtsv2


#undef cusparseCgtsv2
cusparseStatus_t cusparseCgtsv2(cusparseHandle_t handle, int m, int n, cuComplex const * dl, cuComplex const * d, cuComplex const * du, cuComplex * B, int ldb, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgtsv2) (cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex *, int, void *))dlsym(RTLD_NEXT, "cusparseCgtsv2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgtsv2", kApiTypeCuSolver);

    lretval = lcusparseCgtsv2(handle, m, n, dl, d, du, B, ldb, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgtsv2 cusparseCgtsv2


#undef cusparseZgtsv2
cusparseStatus_t cusparseZgtsv2(cusparseHandle_t handle, int m, int n, cuDoubleComplex const * dl, cuDoubleComplex const * d, cuDoubleComplex const * du, cuDoubleComplex * B, int ldb, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgtsv2) (cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *, int, void *))dlsym(RTLD_NEXT, "cusparseZgtsv2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgtsv2", kApiTypeCuSolver);

    lretval = lcusparseZgtsv2(handle, m, n, dl, d, du, B, ldb, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgtsv2 cusparseZgtsv2


#undef cusparseSgtsv2_nopivot_bufferSizeExt
cusparseStatus_t cusparseSgtsv2_nopivot_bufferSizeExt(cusparseHandle_t handle, int m, int n, float const * dl, float const * d, float const * du, float const * B, int ldb, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgtsv2_nopivot_bufferSizeExt) (cusparseHandle_t, int, int, float const *, float const *, float const *, float const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, float const *, float const *, float const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseSgtsv2_nopivot_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgtsv2_nopivot_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSgtsv2_nopivot_bufferSizeExt(handle, m, n, dl, d, du, B, ldb, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgtsv2_nopivot_bufferSizeExt cusparseSgtsv2_nopivot_bufferSizeExt


#undef cusparseDgtsv2_nopivot_bufferSizeExt
cusparseStatus_t cusparseDgtsv2_nopivot_bufferSizeExt(cusparseHandle_t handle, int m, int n, double const * dl, double const * d, double const * du, double const * B, int ldb, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgtsv2_nopivot_bufferSizeExt) (cusparseHandle_t, int, int, double const *, double const *, double const *, double const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, double const *, double const *, double const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseDgtsv2_nopivot_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgtsv2_nopivot_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDgtsv2_nopivot_bufferSizeExt(handle, m, n, dl, d, du, B, ldb, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgtsv2_nopivot_bufferSizeExt cusparseDgtsv2_nopivot_bufferSizeExt


#undef cusparseCgtsv2_nopivot_bufferSizeExt
cusparseStatus_t cusparseCgtsv2_nopivot_bufferSizeExt(cusparseHandle_t handle, int m, int n, cuComplex const * dl, cuComplex const * d, cuComplex const * du, cuComplex const * B, int ldb, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgtsv2_nopivot_bufferSizeExt) (cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseCgtsv2_nopivot_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgtsv2_nopivot_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCgtsv2_nopivot_bufferSizeExt(handle, m, n, dl, d, du, B, ldb, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgtsv2_nopivot_bufferSizeExt cusparseCgtsv2_nopivot_bufferSizeExt


#undef cusparseZgtsv2_nopivot_bufferSizeExt
cusparseStatus_t cusparseZgtsv2_nopivot_bufferSizeExt(cusparseHandle_t handle, int m, int n, cuDoubleComplex const * dl, cuDoubleComplex const * d, cuDoubleComplex const * du, cuDoubleComplex const * B, int ldb, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgtsv2_nopivot_bufferSizeExt) (cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseZgtsv2_nopivot_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgtsv2_nopivot_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZgtsv2_nopivot_bufferSizeExt(handle, m, n, dl, d, du, B, ldb, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgtsv2_nopivot_bufferSizeExt cusparseZgtsv2_nopivot_bufferSizeExt


#undef cusparseSgtsv2_nopivot
cusparseStatus_t cusparseSgtsv2_nopivot(cusparseHandle_t handle, int m, int n, float const * dl, float const * d, float const * du, float * B, int ldb, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgtsv2_nopivot) (cusparseHandle_t, int, int, float const *, float const *, float const *, float *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, float const *, float const *, float *, int, void *))dlsym(RTLD_NEXT, "cusparseSgtsv2_nopivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgtsv2_nopivot", kApiTypeCuSolver);

    lretval = lcusparseSgtsv2_nopivot(handle, m, n, dl, d, du, B, ldb, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgtsv2_nopivot cusparseSgtsv2_nopivot


#undef cusparseDgtsv2_nopivot
cusparseStatus_t cusparseDgtsv2_nopivot(cusparseHandle_t handle, int m, int n, double const * dl, double const * d, double const * du, double * B, int ldb, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgtsv2_nopivot) (cusparseHandle_t, int, int, double const *, double const *, double const *, double *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, double const *, double const *, double *, int, void *))dlsym(RTLD_NEXT, "cusparseDgtsv2_nopivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgtsv2_nopivot", kApiTypeCuSolver);

    lretval = lcusparseDgtsv2_nopivot(handle, m, n, dl, d, du, B, ldb, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgtsv2_nopivot cusparseDgtsv2_nopivot


#undef cusparseCgtsv2_nopivot
cusparseStatus_t cusparseCgtsv2_nopivot(cusparseHandle_t handle, int m, int n, cuComplex const * dl, cuComplex const * d, cuComplex const * du, cuComplex * B, int ldb, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgtsv2_nopivot) (cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex *, int, void *))dlsym(RTLD_NEXT, "cusparseCgtsv2_nopivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgtsv2_nopivot", kApiTypeCuSolver);

    lretval = lcusparseCgtsv2_nopivot(handle, m, n, dl, d, du, B, ldb, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgtsv2_nopivot cusparseCgtsv2_nopivot


#undef cusparseZgtsv2_nopivot
cusparseStatus_t cusparseZgtsv2_nopivot(cusparseHandle_t handle, int m, int n, cuDoubleComplex const * dl, cuDoubleComplex const * d, cuDoubleComplex const * du, cuDoubleComplex * B, int ldb, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgtsv2_nopivot) (cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *, int, void *))dlsym(RTLD_NEXT, "cusparseZgtsv2_nopivot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgtsv2_nopivot", kApiTypeCuSolver);

    lretval = lcusparseZgtsv2_nopivot(handle, m, n, dl, d, du, B, ldb, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgtsv2_nopivot cusparseZgtsv2_nopivot


#undef cusparseSgtsv2StridedBatch_bufferSizeExt
cusparseStatus_t cusparseSgtsv2StridedBatch_bufferSizeExt(cusparseHandle_t handle, int m, float const * dl, float const * d, float const * du, float const * x, int batchCount, int batchStride, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgtsv2StridedBatch_bufferSizeExt) (cusparseHandle_t, int, float const *, float const *, float const *, float const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, float const *, float const *, float const *, float const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseSgtsv2StridedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgtsv2StridedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSgtsv2StridedBatch_bufferSizeExt(handle, m, dl, d, du, x, batchCount, batchStride, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgtsv2StridedBatch_bufferSizeExt cusparseSgtsv2StridedBatch_bufferSizeExt


#undef cusparseDgtsv2StridedBatch_bufferSizeExt
cusparseStatus_t cusparseDgtsv2StridedBatch_bufferSizeExt(cusparseHandle_t handle, int m, double const * dl, double const * d, double const * du, double const * x, int batchCount, int batchStride, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgtsv2StridedBatch_bufferSizeExt) (cusparseHandle_t, int, double const *, double const *, double const *, double const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, double const *, double const *, double const *, double const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseDgtsv2StridedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgtsv2StridedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDgtsv2StridedBatch_bufferSizeExt(handle, m, dl, d, du, x, batchCount, batchStride, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgtsv2StridedBatch_bufferSizeExt cusparseDgtsv2StridedBatch_bufferSizeExt


#undef cusparseCgtsv2StridedBatch_bufferSizeExt
cusparseStatus_t cusparseCgtsv2StridedBatch_bufferSizeExt(cusparseHandle_t handle, int m, cuComplex const * dl, cuComplex const * d, cuComplex const * du, cuComplex const * x, int batchCount, int batchStride, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgtsv2StridedBatch_bufferSizeExt) (cusparseHandle_t, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseCgtsv2StridedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgtsv2StridedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCgtsv2StridedBatch_bufferSizeExt(handle, m, dl, d, du, x, batchCount, batchStride, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgtsv2StridedBatch_bufferSizeExt cusparseCgtsv2StridedBatch_bufferSizeExt


#undef cusparseZgtsv2StridedBatch_bufferSizeExt
cusparseStatus_t cusparseZgtsv2StridedBatch_bufferSizeExt(cusparseHandle_t handle, int m, cuDoubleComplex const * dl, cuDoubleComplex const * d, cuDoubleComplex const * du, cuDoubleComplex const * x, int batchCount, int batchStride, size_t * bufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgtsv2StridedBatch_bufferSizeExt) (cusparseHandle_t, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseZgtsv2StridedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgtsv2StridedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZgtsv2StridedBatch_bufferSizeExt(handle, m, dl, d, du, x, batchCount, batchStride, bufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgtsv2StridedBatch_bufferSizeExt cusparseZgtsv2StridedBatch_bufferSizeExt


#undef cusparseSgtsv2StridedBatch
cusparseStatus_t cusparseSgtsv2StridedBatch(cusparseHandle_t handle, int m, float const * dl, float const * d, float const * du, float * x, int batchCount, int batchStride, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgtsv2StridedBatch) (cusparseHandle_t, int, float const *, float const *, float const *, float *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, float const *, float const *, float const *, float *, int, int, void *))dlsym(RTLD_NEXT, "cusparseSgtsv2StridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgtsv2StridedBatch", kApiTypeCuSolver);

    lretval = lcusparseSgtsv2StridedBatch(handle, m, dl, d, du, x, batchCount, batchStride, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgtsv2StridedBatch cusparseSgtsv2StridedBatch


#undef cusparseDgtsv2StridedBatch
cusparseStatus_t cusparseDgtsv2StridedBatch(cusparseHandle_t handle, int m, double const * dl, double const * d, double const * du, double * x, int batchCount, int batchStride, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgtsv2StridedBatch) (cusparseHandle_t, int, double const *, double const *, double const *, double *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, double const *, double const *, double const *, double *, int, int, void *))dlsym(RTLD_NEXT, "cusparseDgtsv2StridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgtsv2StridedBatch", kApiTypeCuSolver);

    lretval = lcusparseDgtsv2StridedBatch(handle, m, dl, d, du, x, batchCount, batchStride, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgtsv2StridedBatch cusparseDgtsv2StridedBatch


#undef cusparseCgtsv2StridedBatch
cusparseStatus_t cusparseCgtsv2StridedBatch(cusparseHandle_t handle, int m, cuComplex const * dl, cuComplex const * d, cuComplex const * du, cuComplex * x, int batchCount, int batchStride, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgtsv2StridedBatch) (cusparseHandle_t, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex *, int, int, void *))dlsym(RTLD_NEXT, "cusparseCgtsv2StridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgtsv2StridedBatch", kApiTypeCuSolver);

    lretval = lcusparseCgtsv2StridedBatch(handle, m, dl, d, du, x, batchCount, batchStride, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgtsv2StridedBatch cusparseCgtsv2StridedBatch


#undef cusparseZgtsv2StridedBatch
cusparseStatus_t cusparseZgtsv2StridedBatch(cusparseHandle_t handle, int m, cuDoubleComplex const * dl, cuDoubleComplex const * d, cuDoubleComplex const * du, cuDoubleComplex * x, int batchCount, int batchStride, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgtsv2StridedBatch) (cusparseHandle_t, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex *, int, int, void *))dlsym(RTLD_NEXT, "cusparseZgtsv2StridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgtsv2StridedBatch", kApiTypeCuSolver);

    lretval = lcusparseZgtsv2StridedBatch(handle, m, dl, d, du, x, batchCount, batchStride, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgtsv2StridedBatch cusparseZgtsv2StridedBatch


#undef cusparseSgtsvInterleavedBatch_bufferSizeExt
cusparseStatus_t cusparseSgtsvInterleavedBatch_bufferSizeExt(cusparseHandle_t handle, int algo, int m, float const * dl, float const * d, float const * du, float const * x, int batchCount, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgtsvInterleavedBatch_bufferSizeExt) (cusparseHandle_t, int, int, float const *, float const *, float const *, float const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, float const *, float const *, float const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseSgtsvInterleavedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgtsvInterleavedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSgtsvInterleavedBatch_bufferSizeExt(handle, algo, m, dl, d, du, x, batchCount, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgtsvInterleavedBatch_bufferSizeExt cusparseSgtsvInterleavedBatch_bufferSizeExt


#undef cusparseDgtsvInterleavedBatch_bufferSizeExt
cusparseStatus_t cusparseDgtsvInterleavedBatch_bufferSizeExt(cusparseHandle_t handle, int algo, int m, double const * dl, double const * d, double const * du, double const * x, int batchCount, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgtsvInterleavedBatch_bufferSizeExt) (cusparseHandle_t, int, int, double const *, double const *, double const *, double const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, double const *, double const *, double const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseDgtsvInterleavedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgtsvInterleavedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDgtsvInterleavedBatch_bufferSizeExt(handle, algo, m, dl, d, du, x, batchCount, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgtsvInterleavedBatch_bufferSizeExt cusparseDgtsvInterleavedBatch_bufferSizeExt


#undef cusparseCgtsvInterleavedBatch_bufferSizeExt
cusparseStatus_t cusparseCgtsvInterleavedBatch_bufferSizeExt(cusparseHandle_t handle, int algo, int m, cuComplex const * dl, cuComplex const * d, cuComplex const * du, cuComplex const * x, int batchCount, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgtsvInterleavedBatch_bufferSizeExt) (cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseCgtsvInterleavedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgtsvInterleavedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCgtsvInterleavedBatch_bufferSizeExt(handle, algo, m, dl, d, du, x, batchCount, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgtsvInterleavedBatch_bufferSizeExt cusparseCgtsvInterleavedBatch_bufferSizeExt


#undef cusparseZgtsvInterleavedBatch_bufferSizeExt
cusparseStatus_t cusparseZgtsvInterleavedBatch_bufferSizeExt(cusparseHandle_t handle, int algo, int m, cuDoubleComplex const * dl, cuDoubleComplex const * d, cuDoubleComplex const * du, cuDoubleComplex const * x, int batchCount, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgtsvInterleavedBatch_bufferSizeExt) (cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseZgtsvInterleavedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgtsvInterleavedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZgtsvInterleavedBatch_bufferSizeExt(handle, algo, m, dl, d, du, x, batchCount, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgtsvInterleavedBatch_bufferSizeExt cusparseZgtsvInterleavedBatch_bufferSizeExt


#undef cusparseSgtsvInterleavedBatch
cusparseStatus_t cusparseSgtsvInterleavedBatch(cusparseHandle_t handle, int algo, int m, float * dl, float * d, float * du, float * x, int batchCount, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgtsvInterleavedBatch) (cusparseHandle_t, int, int, float *, float *, float *, float *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float *, float *, float *, float *, int, void *))dlsym(RTLD_NEXT, "cusparseSgtsvInterleavedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgtsvInterleavedBatch", kApiTypeCuSolver);

    lretval = lcusparseSgtsvInterleavedBatch(handle, algo, m, dl, d, du, x, batchCount, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgtsvInterleavedBatch cusparseSgtsvInterleavedBatch


#undef cusparseDgtsvInterleavedBatch
cusparseStatus_t cusparseDgtsvInterleavedBatch(cusparseHandle_t handle, int algo, int m, double * dl, double * d, double * du, double * x, int batchCount, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgtsvInterleavedBatch) (cusparseHandle_t, int, int, double *, double *, double *, double *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double *, double *, double *, double *, int, void *))dlsym(RTLD_NEXT, "cusparseDgtsvInterleavedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgtsvInterleavedBatch", kApiTypeCuSolver);

    lretval = lcusparseDgtsvInterleavedBatch(handle, algo, m, dl, d, du, x, batchCount, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgtsvInterleavedBatch cusparseDgtsvInterleavedBatch


#undef cusparseCgtsvInterleavedBatch
cusparseStatus_t cusparseCgtsvInterleavedBatch(cusparseHandle_t handle, int algo, int m, cuComplex * dl, cuComplex * d, cuComplex * du, cuComplex * x, int batchCount, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgtsvInterleavedBatch) (cusparseHandle_t, int, int, cuComplex *, cuComplex *, cuComplex *, cuComplex *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex *, cuComplex *, cuComplex *, cuComplex *, int, void *))dlsym(RTLD_NEXT, "cusparseCgtsvInterleavedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgtsvInterleavedBatch", kApiTypeCuSolver);

    lretval = lcusparseCgtsvInterleavedBatch(handle, algo, m, dl, d, du, x, batchCount, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgtsvInterleavedBatch cusparseCgtsvInterleavedBatch


#undef cusparseZgtsvInterleavedBatch
cusparseStatus_t cusparseZgtsvInterleavedBatch(cusparseHandle_t handle, int algo, int m, cuDoubleComplex * dl, cuDoubleComplex * d, cuDoubleComplex * du, cuDoubleComplex * x, int batchCount, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgtsvInterleavedBatch) (cusparseHandle_t, int, int, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, int, void *))dlsym(RTLD_NEXT, "cusparseZgtsvInterleavedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgtsvInterleavedBatch", kApiTypeCuSolver);

    lretval = lcusparseZgtsvInterleavedBatch(handle, algo, m, dl, d, du, x, batchCount, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgtsvInterleavedBatch cusparseZgtsvInterleavedBatch


#undef cusparseSgpsvInterleavedBatch_bufferSizeExt
cusparseStatus_t cusparseSgpsvInterleavedBatch_bufferSizeExt(cusparseHandle_t handle, int algo, int m, float const * ds, float const * dl, float const * d, float const * du, float const * dw, float const * x, int batchCount, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgpsvInterleavedBatch_bufferSizeExt) (cusparseHandle_t, int, int, float const *, float const *, float const *, float const *, float const *, float const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, float const *, float const *, float const *, float const *, float const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseSgpsvInterleavedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgpsvInterleavedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSgpsvInterleavedBatch_bufferSizeExt(handle, algo, m, ds, dl, d, du, dw, x, batchCount, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgpsvInterleavedBatch_bufferSizeExt cusparseSgpsvInterleavedBatch_bufferSizeExt


#undef cusparseDgpsvInterleavedBatch_bufferSizeExt
cusparseStatus_t cusparseDgpsvInterleavedBatch_bufferSizeExt(cusparseHandle_t handle, int algo, int m, double const * ds, double const * dl, double const * d, double const * du, double const * dw, double const * x, int batchCount, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgpsvInterleavedBatch_bufferSizeExt) (cusparseHandle_t, int, int, double const *, double const *, double const *, double const *, double const *, double const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, double const *, double const *, double const *, double const *, double const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseDgpsvInterleavedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgpsvInterleavedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDgpsvInterleavedBatch_bufferSizeExt(handle, algo, m, ds, dl, d, du, dw, x, batchCount, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgpsvInterleavedBatch_bufferSizeExt cusparseDgpsvInterleavedBatch_bufferSizeExt


#undef cusparseCgpsvInterleavedBatch_bufferSizeExt
cusparseStatus_t cusparseCgpsvInterleavedBatch_bufferSizeExt(cusparseHandle_t handle, int algo, int m, cuComplex const * ds, cuComplex const * dl, cuComplex const * d, cuComplex const * du, cuComplex const * dw, cuComplex const * x, int batchCount, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgpsvInterleavedBatch_bufferSizeExt) (cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, cuComplex const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseCgpsvInterleavedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgpsvInterleavedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCgpsvInterleavedBatch_bufferSizeExt(handle, algo, m, ds, dl, d, du, dw, x, batchCount, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgpsvInterleavedBatch_bufferSizeExt cusparseCgpsvInterleavedBatch_bufferSizeExt


#undef cusparseZgpsvInterleavedBatch_bufferSizeExt
cusparseStatus_t cusparseZgpsvInterleavedBatch_bufferSizeExt(cusparseHandle_t handle, int algo, int m, cuDoubleComplex const * ds, cuDoubleComplex const * dl, cuDoubleComplex const * d, cuDoubleComplex const * du, cuDoubleComplex const * dw, cuDoubleComplex const * x, int batchCount, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgpsvInterleavedBatch_bufferSizeExt) (cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, cuDoubleComplex const *, int, size_t *))dlsym(RTLD_NEXT, "cusparseZgpsvInterleavedBatch_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgpsvInterleavedBatch_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZgpsvInterleavedBatch_bufferSizeExt(handle, algo, m, ds, dl, d, du, dw, x, batchCount, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgpsvInterleavedBatch_bufferSizeExt cusparseZgpsvInterleavedBatch_bufferSizeExt


#undef cusparseSgpsvInterleavedBatch
cusparseStatus_t cusparseSgpsvInterleavedBatch(cusparseHandle_t handle, int algo, int m, float * ds, float * dl, float * d, float * du, float * dw, float * x, int batchCount, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgpsvInterleavedBatch) (cusparseHandle_t, int, int, float *, float *, float *, float *, float *, float *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float *, float *, float *, float *, float *, float *, int, void *))dlsym(RTLD_NEXT, "cusparseSgpsvInterleavedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgpsvInterleavedBatch", kApiTypeCuSolver);

    lretval = lcusparseSgpsvInterleavedBatch(handle, algo, m, ds, dl, d, du, dw, x, batchCount, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgpsvInterleavedBatch cusparseSgpsvInterleavedBatch


#undef cusparseDgpsvInterleavedBatch
cusparseStatus_t cusparseDgpsvInterleavedBatch(cusparseHandle_t handle, int algo, int m, double * ds, double * dl, double * d, double * du, double * dw, double * x, int batchCount, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgpsvInterleavedBatch) (cusparseHandle_t, int, int, double *, double *, double *, double *, double *, double *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double *, double *, double *, double *, double *, double *, int, void *))dlsym(RTLD_NEXT, "cusparseDgpsvInterleavedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgpsvInterleavedBatch", kApiTypeCuSolver);

    lretval = lcusparseDgpsvInterleavedBatch(handle, algo, m, ds, dl, d, du, dw, x, batchCount, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgpsvInterleavedBatch cusparseDgpsvInterleavedBatch


#undef cusparseCgpsvInterleavedBatch
cusparseStatus_t cusparseCgpsvInterleavedBatch(cusparseHandle_t handle, int algo, int m, cuComplex * ds, cuComplex * dl, cuComplex * d, cuComplex * du, cuComplex * dw, cuComplex * x, int batchCount, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgpsvInterleavedBatch) (cusparseHandle_t, int, int, cuComplex *, cuComplex *, cuComplex *, cuComplex *, cuComplex *, cuComplex *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex *, cuComplex *, cuComplex *, cuComplex *, cuComplex *, cuComplex *, int, void *))dlsym(RTLD_NEXT, "cusparseCgpsvInterleavedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgpsvInterleavedBatch", kApiTypeCuSolver);

    lretval = lcusparseCgpsvInterleavedBatch(handle, algo, m, ds, dl, d, du, dw, x, batchCount, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgpsvInterleavedBatch cusparseCgpsvInterleavedBatch


#undef cusparseZgpsvInterleavedBatch
cusparseStatus_t cusparseZgpsvInterleavedBatch(cusparseHandle_t handle, int algo, int m, cuDoubleComplex * ds, cuDoubleComplex * dl, cuDoubleComplex * d, cuDoubleComplex * du, cuDoubleComplex * dw, cuDoubleComplex * x, int batchCount, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgpsvInterleavedBatch) (cusparseHandle_t, int, int, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, cuDoubleComplex *, int, void *))dlsym(RTLD_NEXT, "cusparseZgpsvInterleavedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgpsvInterleavedBatch", kApiTypeCuSolver);

    lretval = lcusparseZgpsvInterleavedBatch(handle, algo, m, ds, dl, d, du, dw, x, batchCount, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgpsvInterleavedBatch cusparseZgpsvInterleavedBatch


#undef cusparseCreateCsrgemm2Info
cusparseStatus_t cusparseCreateCsrgemm2Info(csrgemm2Info_t * info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCsrgemm2Info) (csrgemm2Info_t *) = (cusparseStatus_t (*)(csrgemm2Info_t *))dlsym(RTLD_NEXT, "cusparseCreateCsrgemm2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCsrgemm2Info", kApiTypeCuSolver);

    lretval = lcusparseCreateCsrgemm2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCsrgemm2Info cusparseCreateCsrgemm2Info


#undef cusparseDestroyCsrgemm2Info
cusparseStatus_t cusparseDestroyCsrgemm2Info(csrgemm2Info_t info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyCsrgemm2Info) (csrgemm2Info_t) = (cusparseStatus_t (*)(csrgemm2Info_t))dlsym(RTLD_NEXT, "cusparseDestroyCsrgemm2Info");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyCsrgemm2Info", kApiTypeCuSolver);

    lretval = lcusparseDestroyCsrgemm2Info(info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyCsrgemm2Info cusparseDestroyCsrgemm2Info


#undef cusparseScsrgemm2_bufferSizeExt
cusparseStatus_t cusparseScsrgemm2_bufferSizeExt(cusparseHandle_t handle, int m, int n, int k, float const * alpha, cusparseMatDescr_t const descrA, int nnzA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, float const * beta, cusparseMatDescr_t const descrD, int nnzD, int const * csrSortedRowPtrD, int const * csrSortedColIndD, csrgemm2Info_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrgemm2_bufferSizeExt) (cusparseHandle_t, int, int, int, float const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, float const *, cusparseMatDescr_t const, int, int const *, int const *, csrgemm2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, float const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, float const *, cusparseMatDescr_t const, int, int const *, int const *, csrgemm2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseScsrgemm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrgemm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseScsrgemm2_bufferSizeExt(handle, m, n, k, alpha, descrA, nnzA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedRowPtrB, csrSortedColIndB, beta, descrD, nnzD, csrSortedRowPtrD, csrSortedColIndD, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrgemm2_bufferSizeExt cusparseScsrgemm2_bufferSizeExt


#undef cusparseDcsrgemm2_bufferSizeExt
cusparseStatus_t cusparseDcsrgemm2_bufferSizeExt(cusparseHandle_t handle, int m, int n, int k, double const * alpha, cusparseMatDescr_t const descrA, int nnzA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, double const * beta, cusparseMatDescr_t const descrD, int nnzD, int const * csrSortedRowPtrD, int const * csrSortedColIndD, csrgemm2Info_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrgemm2_bufferSizeExt) (cusparseHandle_t, int, int, int, double const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, double const *, cusparseMatDescr_t const, int, int const *, int const *, csrgemm2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, double const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, double const *, cusparseMatDescr_t const, int, int const *, int const *, csrgemm2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseDcsrgemm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrgemm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDcsrgemm2_bufferSizeExt(handle, m, n, k, alpha, descrA, nnzA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedRowPtrB, csrSortedColIndB, beta, descrD, nnzD, csrSortedRowPtrD, csrSortedColIndD, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrgemm2_bufferSizeExt cusparseDcsrgemm2_bufferSizeExt


#undef cusparseCcsrgemm2_bufferSizeExt
cusparseStatus_t cusparseCcsrgemm2_bufferSizeExt(cusparseHandle_t handle, int m, int n, int k, cuComplex const * alpha, cusparseMatDescr_t const descrA, int nnzA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cuComplex const * beta, cusparseMatDescr_t const descrD, int nnzD, int const * csrSortedRowPtrD, int const * csrSortedColIndD, csrgemm2Info_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrgemm2_bufferSizeExt) (cusparseHandle_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cuComplex const *, cusparseMatDescr_t const, int, int const *, int const *, csrgemm2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cuComplex const *, cusparseMatDescr_t const, int, int const *, int const *, csrgemm2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseCcsrgemm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrgemm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCcsrgemm2_bufferSizeExt(handle, m, n, k, alpha, descrA, nnzA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedRowPtrB, csrSortedColIndB, beta, descrD, nnzD, csrSortedRowPtrD, csrSortedColIndD, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrgemm2_bufferSizeExt cusparseCcsrgemm2_bufferSizeExt


#undef cusparseZcsrgemm2_bufferSizeExt
cusparseStatus_t cusparseZcsrgemm2_bufferSizeExt(cusparseHandle_t handle, int m, int n, int k, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, int nnzA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cuDoubleComplex const * beta, cusparseMatDescr_t const descrD, int nnzD, int const * csrSortedRowPtrD, int const * csrSortedColIndD, csrgemm2Info_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrgemm2_bufferSizeExt) (cusparseHandle_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cuDoubleComplex const *, cusparseMatDescr_t const, int, int const *, int const *, csrgemm2Info_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cuDoubleComplex const *, cusparseMatDescr_t const, int, int const *, int const *, csrgemm2Info_t, size_t *))dlsym(RTLD_NEXT, "cusparseZcsrgemm2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrgemm2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZcsrgemm2_bufferSizeExt(handle, m, n, k, alpha, descrA, nnzA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedRowPtrB, csrSortedColIndB, beta, descrD, nnzD, csrSortedRowPtrD, csrSortedColIndD, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrgemm2_bufferSizeExt cusparseZcsrgemm2_bufferSizeExt


#undef cusparseXcsrgemm2Nnz
cusparseStatus_t cusparseXcsrgemm2Nnz(cusparseHandle_t handle, int m, int n, int k, cusparseMatDescr_t const descrA, int nnzA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrD, int nnzD, int const * csrSortedRowPtrD, int const * csrSortedColIndD, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * nnzTotalDevHostPtr, csrgemm2Info_t const info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsrgemm2Nnz) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int *, int *, csrgemm2Info_t const, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int *, int *, csrgemm2Info_t const, void *))dlsym(RTLD_NEXT, "cusparseXcsrgemm2Nnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsrgemm2Nnz", kApiTypeCuSolver);

    lretval = lcusparseXcsrgemm2Nnz(handle, m, n, k, descrA, nnzA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedRowPtrB, csrSortedColIndB, descrD, nnzD, csrSortedRowPtrD, csrSortedColIndD, descrC, csrSortedRowPtrC, nnzTotalDevHostPtr, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsrgemm2Nnz cusparseXcsrgemm2Nnz


#undef cusparseScsrgemm2
cusparseStatus_t cusparseScsrgemm2(cusparseHandle_t handle, int m, int n, int k, float const * alpha, cusparseMatDescr_t const descrA, int nnzA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, float const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, float const * beta, cusparseMatDescr_t const descrD, int nnzD, float const * csrSortedValD, int const * csrSortedRowPtrD, int const * csrSortedColIndD, cusparseMatDescr_t const descrC, float * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, csrgemm2Info_t const info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrgemm2) (cusparseHandle_t, int, int, int, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, cusparseMatDescr_t const, float *, int const *, int *, csrgemm2Info_t const, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, cusparseMatDescr_t const, float *, int const *, int *, csrgemm2Info_t const, void *))dlsym(RTLD_NEXT, "cusparseScsrgemm2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrgemm2", kApiTypeCuSolver);

    lretval = lcusparseScsrgemm2(handle, m, n, k, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, beta, descrD, nnzD, csrSortedValD, csrSortedRowPtrD, csrSortedColIndD, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrgemm2 cusparseScsrgemm2


#undef cusparseDcsrgemm2
cusparseStatus_t cusparseDcsrgemm2(cusparseHandle_t handle, int m, int n, int k, double const * alpha, cusparseMatDescr_t const descrA, int nnzA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, double const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, double const * beta, cusparseMatDescr_t const descrD, int nnzD, double const * csrSortedValD, int const * csrSortedRowPtrD, int const * csrSortedColIndD, cusparseMatDescr_t const descrC, double * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, csrgemm2Info_t const info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrgemm2) (cusparseHandle_t, int, int, int, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, cusparseMatDescr_t const, double *, int const *, int *, csrgemm2Info_t const, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, cusparseMatDescr_t const, double *, int const *, int *, csrgemm2Info_t const, void *))dlsym(RTLD_NEXT, "cusparseDcsrgemm2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrgemm2", kApiTypeCuSolver);

    lretval = lcusparseDcsrgemm2(handle, m, n, k, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, beta, descrD, nnzD, csrSortedValD, csrSortedRowPtrD, csrSortedColIndD, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrgemm2 cusparseDcsrgemm2


#undef cusparseCcsrgemm2
cusparseStatus_t cusparseCcsrgemm2(cusparseHandle_t handle, int m, int n, int k, cuComplex const * alpha, cusparseMatDescr_t const descrA, int nnzA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, cuComplex const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cuComplex const * beta, cusparseMatDescr_t const descrD, int nnzD, cuComplex const * csrSortedValD, int const * csrSortedRowPtrD, int const * csrSortedColIndD, cusparseMatDescr_t const descrC, cuComplex * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, csrgemm2Info_t const info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrgemm2) (cusparseHandle_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, cuComplex *, int const *, int *, csrgemm2Info_t const, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, cuComplex *, int const *, int *, csrgemm2Info_t const, void *))dlsym(RTLD_NEXT, "cusparseCcsrgemm2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrgemm2", kApiTypeCuSolver);

    lretval = lcusparseCcsrgemm2(handle, m, n, k, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, beta, descrD, nnzD, csrSortedValD, csrSortedRowPtrD, csrSortedColIndD, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrgemm2 cusparseCcsrgemm2


#undef cusparseZcsrgemm2
cusparseStatus_t cusparseZcsrgemm2(cusparseHandle_t handle, int m, int n, int k, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, int nnzA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, cuDoubleComplex const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cuDoubleComplex const * beta, cusparseMatDescr_t const descrD, int nnzD, cuDoubleComplex const * csrSortedValD, int const * csrSortedRowPtrD, int const * csrSortedColIndD, cusparseMatDescr_t const descrC, cuDoubleComplex * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, csrgemm2Info_t const info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrgemm2) (cusparseHandle_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int *, csrgemm2Info_t const, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int *, csrgemm2Info_t const, void *))dlsym(RTLD_NEXT, "cusparseZcsrgemm2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrgemm2", kApiTypeCuSolver);

    lretval = lcusparseZcsrgemm2(handle, m, n, k, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, beta, descrD, nnzD, csrSortedValD, csrSortedRowPtrD, csrSortedColIndD, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrgemm2 cusparseZcsrgemm2


#undef cusparseScsrgeam2_bufferSizeExt
cusparseStatus_t cusparseScsrgeam2_bufferSizeExt(cusparseHandle_t handle, int m, int n, float const * alpha, cusparseMatDescr_t const descrA, int nnzA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float const * beta, cusparseMatDescr_t const descrB, int nnzB, float const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrC, float const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrgeam2_bufferSizeExt) (cusparseHandle_t, int, int, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, cusparseMatDescr_t const, float const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, cusparseMatDescr_t const, float const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseScsrgeam2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrgeam2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseScsrgeam2_bufferSizeExt(handle, m, n, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, beta, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrgeam2_bufferSizeExt cusparseScsrgeam2_bufferSizeExt


#undef cusparseDcsrgeam2_bufferSizeExt
cusparseStatus_t cusparseDcsrgeam2_bufferSizeExt(cusparseHandle_t handle, int m, int n, double const * alpha, cusparseMatDescr_t const descrA, int nnzA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double const * beta, cusparseMatDescr_t const descrB, int nnzB, double const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrC, double const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrgeam2_bufferSizeExt) (cusparseHandle_t, int, int, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, cusparseMatDescr_t const, double const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, cusparseMatDescr_t const, double const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseDcsrgeam2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrgeam2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDcsrgeam2_bufferSizeExt(handle, m, n, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, beta, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrgeam2_bufferSizeExt cusparseDcsrgeam2_bufferSizeExt


#undef cusparseCcsrgeam2_bufferSizeExt
cusparseStatus_t cusparseCcsrgeam2_bufferSizeExt(cusparseHandle_t handle, int m, int n, cuComplex const * alpha, cusparseMatDescr_t const descrA, int nnzA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuComplex const * beta, cusparseMatDescr_t const descrB, int nnzB, cuComplex const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrC, cuComplex const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrgeam2_bufferSizeExt) (cusparseHandle_t, int, int, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseCcsrgeam2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrgeam2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCcsrgeam2_bufferSizeExt(handle, m, n, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, beta, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrgeam2_bufferSizeExt cusparseCcsrgeam2_bufferSizeExt


#undef cusparseZcsrgeam2_bufferSizeExt
cusparseStatus_t cusparseZcsrgeam2_bufferSizeExt(cusparseHandle_t handle, int m, int n, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, int nnzA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuDoubleComplex const * beta, cusparseMatDescr_t const descrB, int nnzB, cuDoubleComplex const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrC, cuDoubleComplex const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrgeam2_bufferSizeExt) (cusparseHandle_t, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseZcsrgeam2_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrgeam2_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZcsrgeam2_bufferSizeExt(handle, m, n, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, beta, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrgeam2_bufferSizeExt cusparseZcsrgeam2_bufferSizeExt


#undef cusparseXcsrgeam2Nnz
cusparseStatus_t cusparseXcsrgeam2Nnz(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, int nnzA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrB, int nnzB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * nnzTotalDevHostPtr, void * workspace){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsrgeam2Nnz) (cusparseHandle_t, int, int, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int, int const *, int const *, cusparseMatDescr_t const, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseXcsrgeam2Nnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsrgeam2Nnz", kApiTypeCuSolver);

    lretval = lcusparseXcsrgeam2Nnz(handle, m, n, descrA, nnzA, csrSortedRowPtrA, csrSortedColIndA, descrB, nnzB, csrSortedRowPtrB, csrSortedColIndB, descrC, csrSortedRowPtrC, nnzTotalDevHostPtr, workspace);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsrgeam2Nnz cusparseXcsrgeam2Nnz


#undef cusparseScsrgeam2
cusparseStatus_t cusparseScsrgeam2(cusparseHandle_t handle, int m, int n, float const * alpha, cusparseMatDescr_t const descrA, int nnzA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float const * beta, cusparseMatDescr_t const descrB, int nnzB, float const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrC, float * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrgeam2) (cusparseHandle_t, int, int, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, cusparseMatDescr_t const, float *, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, int, float const *, int const *, int const *, cusparseMatDescr_t const, float *, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseScsrgeam2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrgeam2", kApiTypeCuSolver);

    lretval = lcusparseScsrgeam2(handle, m, n, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, beta, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrgeam2 cusparseScsrgeam2


#undef cusparseDcsrgeam2
cusparseStatus_t cusparseDcsrgeam2(cusparseHandle_t handle, int m, int n, double const * alpha, cusparseMatDescr_t const descrA, int nnzA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double const * beta, cusparseMatDescr_t const descrB, int nnzB, double const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrC, double * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrgeam2) (cusparseHandle_t, int, int, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, cusparseMatDescr_t const, double *, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, int, double const *, int const *, int const *, cusparseMatDescr_t const, double *, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseDcsrgeam2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrgeam2", kApiTypeCuSolver);

    lretval = lcusparseDcsrgeam2(handle, m, n, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, beta, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrgeam2 cusparseDcsrgeam2


#undef cusparseCcsrgeam2
cusparseStatus_t cusparseCcsrgeam2(cusparseHandle_t handle, int m, int n, cuComplex const * alpha, cusparseMatDescr_t const descrA, int nnzA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuComplex const * beta, cusparseMatDescr_t const descrB, int nnzB, cuComplex const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrC, cuComplex * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrgeam2) (cusparseHandle_t, int, int, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, cuComplex *, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cuComplex const *, cusparseMatDescr_t const, int, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, cuComplex *, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseCcsrgeam2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrgeam2", kApiTypeCuSolver);

    lretval = lcusparseCcsrgeam2(handle, m, n, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, beta, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrgeam2 cusparseCcsrgeam2


#undef cusparseZcsrgeam2
cusparseStatus_t cusparseZcsrgeam2(cusparseHandle_t handle, int m, int n, cuDoubleComplex const * alpha, cusparseMatDescr_t const descrA, int nnzA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuDoubleComplex const * beta, cusparseMatDescr_t const descrB, int nnzB, cuDoubleComplex const * csrSortedValB, int const * csrSortedRowPtrB, int const * csrSortedColIndB, cusparseMatDescr_t const descrC, cuDoubleComplex * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrgeam2) (cusparseHandle_t, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex const *, cusparseMatDescr_t const, int, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseZcsrgeam2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrgeam2", kApiTypeCuSolver);

    lretval = lcusparseZcsrgeam2(handle, m, n, alpha, descrA, nnzA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, beta, descrB, nnzB, csrSortedValB, csrSortedRowPtrB, csrSortedColIndB, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrgeam2 cusparseZcsrgeam2


#undef cusparseScsrcolor
cusparseStatus_t cusparseScsrcolor(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float const * fractionToColor, int * ncolors, int * coloring, int * reordering, cusparseColorInfo_t const info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsrcolor) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, int *, int *, int *, cusparseColorInfo_t const) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, int *, int *, int *, cusparseColorInfo_t const))dlsym(RTLD_NEXT, "cusparseScsrcolor");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsrcolor", kApiTypeCuSolver);

    lretval = lcusparseScsrcolor(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, fractionToColor, ncolors, coloring, reordering, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsrcolor cusparseScsrcolor


#undef cusparseDcsrcolor
cusparseStatus_t cusparseDcsrcolor(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double const * fractionToColor, int * ncolors, int * coloring, int * reordering, cusparseColorInfo_t const info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsrcolor) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, int *, int *, int *, cusparseColorInfo_t const) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, int *, int *, int *, cusparseColorInfo_t const))dlsym(RTLD_NEXT, "cusparseDcsrcolor");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsrcolor", kApiTypeCuSolver);

    lretval = lcusparseDcsrcolor(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, fractionToColor, ncolors, coloring, reordering, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsrcolor cusparseDcsrcolor


#undef cusparseCcsrcolor
cusparseStatus_t cusparseCcsrcolor(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float const * fractionToColor, int * ncolors, int * coloring, int * reordering, cusparseColorInfo_t const info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsrcolor) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, float const *, int *, int *, int *, cusparseColorInfo_t const) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, float const *, int *, int *, int *, cusparseColorInfo_t const))dlsym(RTLD_NEXT, "cusparseCcsrcolor");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsrcolor", kApiTypeCuSolver);

    lretval = lcusparseCcsrcolor(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, fractionToColor, ncolors, coloring, reordering, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsrcolor cusparseCcsrcolor


#undef cusparseZcsrcolor
cusparseStatus_t cusparseZcsrcolor(cusparseHandle_t handle, int m, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double const * fractionToColor, int * ncolors, int * coloring, int * reordering, cusparseColorInfo_t const info){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsrcolor) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, double const *, int *, int *, int *, cusparseColorInfo_t const) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, double const *, int *, int *, int *, cusparseColorInfo_t const))dlsym(RTLD_NEXT, "cusparseZcsrcolor");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsrcolor", kApiTypeCuSolver);

    lretval = lcusparseZcsrcolor(handle, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, fractionToColor, ncolors, coloring, reordering, info);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsrcolor cusparseZcsrcolor


#undef cusparseSnnz
cusparseStatus_t cusparseSnnz(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, float const * A, int lda, int * nnzPerRowCol, int * nnzTotalDevHostPtr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSnnz) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int, int *, int *))dlsym(RTLD_NEXT, "cusparseSnnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSnnz", kApiTypeCuSolver);

    lretval = lcusparseSnnz(handle, dirA, m, n, descrA, A, lda, nnzPerRowCol, nnzTotalDevHostPtr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSnnz cusparseSnnz


#undef cusparseDnnz
cusparseStatus_t cusparseDnnz(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, double const * A, int lda, int * nnzPerRowCol, int * nnzTotalDevHostPtr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnnz) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int, int *, int *))dlsym(RTLD_NEXT, "cusparseDnnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnnz", kApiTypeCuSolver);

    lretval = lcusparseDnnz(handle, dirA, m, n, descrA, A, lda, nnzPerRowCol, nnzTotalDevHostPtr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnnz cusparseDnnz


#undef cusparseCnnz
cusparseStatus_t cusparseCnnz(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * A, int lda, int * nnzPerRowCol, int * nnzTotalDevHostPtr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCnnz) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int, int *, int *))dlsym(RTLD_NEXT, "cusparseCnnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCnnz", kApiTypeCuSolver);

    lretval = lcusparseCnnz(handle, dirA, m, n, descrA, A, lda, nnzPerRowCol, nnzTotalDevHostPtr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCnnz cusparseCnnz


#undef cusparseZnnz
cusparseStatus_t cusparseZnnz(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * A, int lda, int * nnzPerRowCol, int * nnzTotalDevHostPtr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZnnz) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int, int *, int *))dlsym(RTLD_NEXT, "cusparseZnnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZnnz", kApiTypeCuSolver);

    lretval = lcusparseZnnz(handle, dirA, m, n, descrA, A, lda, nnzPerRowCol, nnzTotalDevHostPtr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZnnz cusparseZnnz


#undef cusparseSnnz_compress
cusparseStatus_t cusparseSnnz_compress(cusparseHandle_t handle, int m, cusparseMatDescr_t const descr, float const * csrSortedValA, int const * csrSortedRowPtrA, int * nnzPerRow, int * nnzC, float tol){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSnnz_compress) (cusparseHandle_t, int, cusparseMatDescr_t const, float const *, int const *, int *, int *, float) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseMatDescr_t const, float const *, int const *, int *, int *, float))dlsym(RTLD_NEXT, "cusparseSnnz_compress");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSnnz_compress", kApiTypeCuSolver);

    lretval = lcusparseSnnz_compress(handle, m, descr, csrSortedValA, csrSortedRowPtrA, nnzPerRow, nnzC, tol);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSnnz_compress cusparseSnnz_compress


#undef cusparseDnnz_compress
cusparseStatus_t cusparseDnnz_compress(cusparseHandle_t handle, int m, cusparseMatDescr_t const descr, double const * csrSortedValA, int const * csrSortedRowPtrA, int * nnzPerRow, int * nnzC, double tol){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnnz_compress) (cusparseHandle_t, int, cusparseMatDescr_t const, double const *, int const *, int *, int *, double) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseMatDescr_t const, double const *, int const *, int *, int *, double))dlsym(RTLD_NEXT, "cusparseDnnz_compress");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnnz_compress", kApiTypeCuSolver);

    lretval = lcusparseDnnz_compress(handle, m, descr, csrSortedValA, csrSortedRowPtrA, nnzPerRow, nnzC, tol);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnnz_compress cusparseDnnz_compress


#undef cusparseCnnz_compress
cusparseStatus_t cusparseCnnz_compress(cusparseHandle_t handle, int m, cusparseMatDescr_t const descr, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int * nnzPerRow, int * nnzC, cuComplex tol){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCnnz_compress) (cusparseHandle_t, int, cusparseMatDescr_t const, cuComplex const *, int const *, int *, int *, cuComplex) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseMatDescr_t const, cuComplex const *, int const *, int *, int *, cuComplex))dlsym(RTLD_NEXT, "cusparseCnnz_compress");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCnnz_compress", kApiTypeCuSolver);

    lretval = lcusparseCnnz_compress(handle, m, descr, csrSortedValA, csrSortedRowPtrA, nnzPerRow, nnzC, tol);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCnnz_compress cusparseCnnz_compress


#undef cusparseZnnz_compress
cusparseStatus_t cusparseZnnz_compress(cusparseHandle_t handle, int m, cusparseMatDescr_t const descr, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int * nnzPerRow, int * nnzC, cuDoubleComplex tol){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZnnz_compress) (cusparseHandle_t, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int *, int *, cuDoubleComplex) = (cusparseStatus_t (*)(cusparseHandle_t, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int *, int *, cuDoubleComplex))dlsym(RTLD_NEXT, "cusparseZnnz_compress");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZnnz_compress", kApiTypeCuSolver);

    lretval = lcusparseZnnz_compress(handle, m, descr, csrSortedValA, csrSortedRowPtrA, nnzPerRow, nnzC, tol);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZnnz_compress cusparseZnnz_compress


#undef cusparseScsr2csr_compress
cusparseStatus_t cusparseScsr2csr_compress(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedColIndA, int const * csrSortedRowPtrA, int nnzA, int const * nnzPerRow, float * csrSortedValC, int * csrSortedColIndC, int * csrSortedRowPtrC, float tol){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsr2csr_compress) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int const *, float *, int *, int *, float) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int const *, float *, int *, int *, float))dlsym(RTLD_NEXT, "cusparseScsr2csr_compress");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsr2csr_compress", kApiTypeCuSolver);

    lretval = lcusparseScsr2csr_compress(handle, m, n, descrA, csrSortedValA, csrSortedColIndA, csrSortedRowPtrA, nnzA, nnzPerRow, csrSortedValC, csrSortedColIndC, csrSortedRowPtrC, tol);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsr2csr_compress cusparseScsr2csr_compress


#undef cusparseDcsr2csr_compress
cusparseStatus_t cusparseDcsr2csr_compress(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedColIndA, int const * csrSortedRowPtrA, int nnzA, int const * nnzPerRow, double * csrSortedValC, int * csrSortedColIndC, int * csrSortedRowPtrC, double tol){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsr2csr_compress) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int const *, double *, int *, int *, double) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int const *, double *, int *, int *, double))dlsym(RTLD_NEXT, "cusparseDcsr2csr_compress");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsr2csr_compress", kApiTypeCuSolver);

    lretval = lcusparseDcsr2csr_compress(handle, m, n, descrA, csrSortedValA, csrSortedColIndA, csrSortedRowPtrA, nnzA, nnzPerRow, csrSortedValC, csrSortedColIndC, csrSortedRowPtrC, tol);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsr2csr_compress cusparseDcsr2csr_compress


#undef cusparseCcsr2csr_compress
cusparseStatus_t cusparseCcsr2csr_compress(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedColIndA, int const * csrSortedRowPtrA, int nnzA, int const * nnzPerRow, cuComplex * csrSortedValC, int * csrSortedColIndC, int * csrSortedRowPtrC, cuComplex tol){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsr2csr_compress) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int const *, cuComplex *, int *, int *, cuComplex) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int const *, cuComplex *, int *, int *, cuComplex))dlsym(RTLD_NEXT, "cusparseCcsr2csr_compress");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsr2csr_compress", kApiTypeCuSolver);

    lretval = lcusparseCcsr2csr_compress(handle, m, n, descrA, csrSortedValA, csrSortedColIndA, csrSortedRowPtrA, nnzA, nnzPerRow, csrSortedValC, csrSortedColIndC, csrSortedRowPtrC, tol);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsr2csr_compress cusparseCcsr2csr_compress


#undef cusparseZcsr2csr_compress
cusparseStatus_t cusparseZcsr2csr_compress(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedColIndA, int const * csrSortedRowPtrA, int nnzA, int const * nnzPerRow, cuDoubleComplex * csrSortedValC, int * csrSortedColIndC, int * csrSortedRowPtrC, cuDoubleComplex tol){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsr2csr_compress) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int const *, cuDoubleComplex *, int *, int *, cuDoubleComplex) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int const *, cuDoubleComplex *, int *, int *, cuDoubleComplex))dlsym(RTLD_NEXT, "cusparseZcsr2csr_compress");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsr2csr_compress", kApiTypeCuSolver);

    lretval = lcusparseZcsr2csr_compress(handle, m, n, descrA, csrSortedValA, csrSortedColIndA, csrSortedRowPtrA, nnzA, nnzPerRow, csrSortedValC, csrSortedColIndC, csrSortedRowPtrC, tol);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsr2csr_compress cusparseZcsr2csr_compress


#undef cusparseSdense2csr
cusparseStatus_t cusparseSdense2csr(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, float const * A, int lda, int const * nnzPerRow, float * csrSortedValA, int * csrSortedRowPtrA, int * csrSortedColIndA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSdense2csr) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int, int const *, float *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int, int const *, float *, int *, int *))dlsym(RTLD_NEXT, "cusparseSdense2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSdense2csr", kApiTypeCuSolver);

    lretval = lcusparseSdense2csr(handle, m, n, descrA, A, lda, nnzPerRow, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSdense2csr cusparseSdense2csr


#undef cusparseDdense2csr
cusparseStatus_t cusparseDdense2csr(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, double const * A, int lda, int const * nnzPerRow, double * csrSortedValA, int * csrSortedRowPtrA, int * csrSortedColIndA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDdense2csr) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int, int const *, double *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int, int const *, double *, int *, int *))dlsym(RTLD_NEXT, "cusparseDdense2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDdense2csr", kApiTypeCuSolver);

    lretval = lcusparseDdense2csr(handle, m, n, descrA, A, lda, nnzPerRow, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDdense2csr cusparseDdense2csr


#undef cusparseCdense2csr
cusparseStatus_t cusparseCdense2csr(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * A, int lda, int const * nnzPerRow, cuComplex * csrSortedValA, int * csrSortedRowPtrA, int * csrSortedColIndA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCdense2csr) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int, int const *, cuComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int, int const *, cuComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseCdense2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCdense2csr", kApiTypeCuSolver);

    lretval = lcusparseCdense2csr(handle, m, n, descrA, A, lda, nnzPerRow, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCdense2csr cusparseCdense2csr


#undef cusparseZdense2csr
cusparseStatus_t cusparseZdense2csr(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * A, int lda, int const * nnzPerRow, cuDoubleComplex * csrSortedValA, int * csrSortedRowPtrA, int * csrSortedColIndA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZdense2csr) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int, int const *, cuDoubleComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int, int const *, cuDoubleComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseZdense2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZdense2csr", kApiTypeCuSolver);

    lretval = lcusparseZdense2csr(handle, m, n, descrA, A, lda, nnzPerRow, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZdense2csr cusparseZdense2csr


#undef cusparseScsr2dense
cusparseStatus_t cusparseScsr2dense(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float * A, int lda){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsr2dense) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float *, int))dlsym(RTLD_NEXT, "cusparseScsr2dense");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsr2dense", kApiTypeCuSolver);

    lretval = lcusparseScsr2dense(handle, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsr2dense cusparseScsr2dense


#undef cusparseDcsr2dense
cusparseStatus_t cusparseDcsr2dense(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double * A, int lda){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsr2dense) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double *, int))dlsym(RTLD_NEXT, "cusparseDcsr2dense");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsr2dense", kApiTypeCuSolver);

    lretval = lcusparseDcsr2dense(handle, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsr2dense cusparseDcsr2dense


#undef cusparseCcsr2dense
cusparseStatus_t cusparseCcsr2dense(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuComplex * A, int lda){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsr2dense) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex *, int))dlsym(RTLD_NEXT, "cusparseCcsr2dense");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsr2dense", kApiTypeCuSolver);

    lretval = lcusparseCcsr2dense(handle, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsr2dense cusparseCcsr2dense


#undef cusparseZcsr2dense
cusparseStatus_t cusparseZcsr2dense(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cuDoubleComplex * A, int lda){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsr2dense) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cusparseZcsr2dense");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsr2dense", kApiTypeCuSolver);

    lretval = lcusparseZcsr2dense(handle, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsr2dense cusparseZcsr2dense


#undef cusparseSdense2csc
cusparseStatus_t cusparseSdense2csc(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, float const * A, int lda, int const * nnzPerCol, float * cscSortedValA, int * cscSortedRowIndA, int * cscSortedColPtrA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSdense2csc) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int, int const *, float *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int, int const *, float *, int *, int *))dlsym(RTLD_NEXT, "cusparseSdense2csc");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSdense2csc", kApiTypeCuSolver);

    lretval = lcusparseSdense2csc(handle, m, n, descrA, A, lda, nnzPerCol, cscSortedValA, cscSortedRowIndA, cscSortedColPtrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSdense2csc cusparseSdense2csc


#undef cusparseDdense2csc
cusparseStatus_t cusparseDdense2csc(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, double const * A, int lda, int const * nnzPerCol, double * cscSortedValA, int * cscSortedRowIndA, int * cscSortedColPtrA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDdense2csc) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int, int const *, double *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int, int const *, double *, int *, int *))dlsym(RTLD_NEXT, "cusparseDdense2csc");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDdense2csc", kApiTypeCuSolver);

    lretval = lcusparseDdense2csc(handle, m, n, descrA, A, lda, nnzPerCol, cscSortedValA, cscSortedRowIndA, cscSortedColPtrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDdense2csc cusparseDdense2csc


#undef cusparseCdense2csc
cusparseStatus_t cusparseCdense2csc(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * A, int lda, int const * nnzPerCol, cuComplex * cscSortedValA, int * cscSortedRowIndA, int * cscSortedColPtrA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCdense2csc) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int, int const *, cuComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int, int const *, cuComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseCdense2csc");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCdense2csc", kApiTypeCuSolver);

    lretval = lcusparseCdense2csc(handle, m, n, descrA, A, lda, nnzPerCol, cscSortedValA, cscSortedRowIndA, cscSortedColPtrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCdense2csc cusparseCdense2csc


#undef cusparseZdense2csc
cusparseStatus_t cusparseZdense2csc(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * A, int lda, int const * nnzPerCol, cuDoubleComplex * cscSortedValA, int * cscSortedRowIndA, int * cscSortedColPtrA){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZdense2csc) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int, int const *, cuDoubleComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int, int const *, cuDoubleComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseZdense2csc");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZdense2csc", kApiTypeCuSolver);

    lretval = lcusparseZdense2csc(handle, m, n, descrA, A, lda, nnzPerCol, cscSortedValA, cscSortedRowIndA, cscSortedColPtrA);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZdense2csc cusparseZdense2csc


#undef cusparseScsc2dense
cusparseStatus_t cusparseScsc2dense(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, float const * cscSortedValA, int const * cscSortedRowIndA, int const * cscSortedColPtrA, float * A, int lda){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsc2dense) (cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float *, int))dlsym(RTLD_NEXT, "cusparseScsc2dense");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsc2dense", kApiTypeCuSolver);

    lretval = lcusparseScsc2dense(handle, m, n, descrA, cscSortedValA, cscSortedRowIndA, cscSortedColPtrA, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsc2dense cusparseScsc2dense


#undef cusparseDcsc2dense
cusparseStatus_t cusparseDcsc2dense(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, double const * cscSortedValA, int const * cscSortedRowIndA, int const * cscSortedColPtrA, double * A, int lda){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsc2dense) (cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double *, int))dlsym(RTLD_NEXT, "cusparseDcsc2dense");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsc2dense", kApiTypeCuSolver);

    lretval = lcusparseDcsc2dense(handle, m, n, descrA, cscSortedValA, cscSortedRowIndA, cscSortedColPtrA, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsc2dense cusparseDcsc2dense


#undef cusparseCcsc2dense
cusparseStatus_t cusparseCcsc2dense(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * cscSortedValA, int const * cscSortedRowIndA, int const * cscSortedColPtrA, cuComplex * A, int lda){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsc2dense) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cuComplex *, int))dlsym(RTLD_NEXT, "cusparseCcsc2dense");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsc2dense", kApiTypeCuSolver);

    lretval = lcusparseCcsc2dense(handle, m, n, descrA, cscSortedValA, cscSortedRowIndA, cscSortedColPtrA, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsc2dense cusparseCcsc2dense


#undef cusparseZcsc2dense
cusparseStatus_t cusparseZcsc2dense(cusparseHandle_t handle, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * cscSortedValA, int const * cscSortedRowIndA, int const * cscSortedColPtrA, cuDoubleComplex * A, int lda){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsc2dense) (cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex *, int) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cuDoubleComplex *, int))dlsym(RTLD_NEXT, "cusparseZcsc2dense");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsc2dense", kApiTypeCuSolver);

    lretval = lcusparseZcsc2dense(handle, m, n, descrA, cscSortedValA, cscSortedRowIndA, cscSortedColPtrA, A, lda);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsc2dense cusparseZcsc2dense


#undef cusparseXcoo2csr
cusparseStatus_t cusparseXcoo2csr(cusparseHandle_t handle, int const * cooRowInd, int nnz, int m, int * csrSortedRowPtr, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcoo2csr) (cusparseHandle_t, int const *, int, int, int *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int const *, int, int, int *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseXcoo2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcoo2csr", kApiTypeCuSolver);

    lretval = lcusparseXcoo2csr(handle, cooRowInd, nnz, m, csrSortedRowPtr, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcoo2csr cusparseXcoo2csr


#undef cusparseXcsr2coo
cusparseStatus_t cusparseXcsr2coo(cusparseHandle_t handle, int const * csrSortedRowPtr, int nnz, int m, int * cooRowInd, cusparseIndexBase_t idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsr2coo) (cusparseHandle_t, int const *, int, int, int *, cusparseIndexBase_t) = (cusparseStatus_t (*)(cusparseHandle_t, int const *, int, int, int *, cusparseIndexBase_t))dlsym(RTLD_NEXT, "cusparseXcsr2coo");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsr2coo", kApiTypeCuSolver);

    lretval = lcusparseXcsr2coo(handle, csrSortedRowPtr, nnz, m, cooRowInd, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsr2coo cusparseXcsr2coo


#undef cusparseXcsr2bsrNnz
cusparseStatus_t cusparseXcsr2bsrNnz(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int blockDim, cusparseMatDescr_t const descrC, int * bsrSortedRowPtrC, int * nnzTotalDevHostPtr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsr2bsrNnz) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, int const *, int const *, int, cusparseMatDescr_t const, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, int const *, int const *, int, cusparseMatDescr_t const, int *, int *))dlsym(RTLD_NEXT, "cusparseXcsr2bsrNnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsr2bsrNnz", kApiTypeCuSolver);

    lretval = lcusparseXcsr2bsrNnz(handle, dirA, m, n, descrA, csrSortedRowPtrA, csrSortedColIndA, blockDim, descrC, bsrSortedRowPtrC, nnzTotalDevHostPtr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsr2bsrNnz cusparseXcsr2bsrNnz


#undef cusparseScsr2bsr
cusparseStatus_t cusparseScsr2bsr(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int blockDim, cusparseMatDescr_t const descrC, float * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsr2bsr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, cusparseMatDescr_t const, float *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, cusparseMatDescr_t const, float *, int *, int *))dlsym(RTLD_NEXT, "cusparseScsr2bsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsr2bsr", kApiTypeCuSolver);

    lretval = lcusparseScsr2bsr(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, blockDim, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsr2bsr cusparseScsr2bsr


#undef cusparseDcsr2bsr
cusparseStatus_t cusparseDcsr2bsr(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int blockDim, cusparseMatDescr_t const descrC, double * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsr2bsr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, cusparseMatDescr_t const, double *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, cusparseMatDescr_t const, double *, int *, int *))dlsym(RTLD_NEXT, "cusparseDcsr2bsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsr2bsr", kApiTypeCuSolver);

    lretval = lcusparseDcsr2bsr(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, blockDim, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsr2bsr cusparseDcsr2bsr


#undef cusparseCcsr2bsr
cusparseStatus_t cusparseCcsr2bsr(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int blockDim, cusparseMatDescr_t const descrC, cuComplex * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsr2bsr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, cusparseMatDescr_t const, cuComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, cusparseMatDescr_t const, cuComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseCcsr2bsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsr2bsr", kApiTypeCuSolver);

    lretval = lcusparseCcsr2bsr(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, blockDim, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsr2bsr cusparseCcsr2bsr


#undef cusparseZcsr2bsr
cusparseStatus_t cusparseZcsr2bsr(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int blockDim, cusparseMatDescr_t const descrC, cuDoubleComplex * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsr2bsr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseZcsr2bsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsr2bsr", kApiTypeCuSolver);

    lretval = lcusparseZcsr2bsr(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, blockDim, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsr2bsr cusparseZcsr2bsr


#undef cusparseSbsr2csr
cusparseStatus_t cusparseSbsr2csr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, cusparseMatDescr_t const descrC, float * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSbsr2csr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, cusparseMatDescr_t const, float *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, cusparseMatDescr_t const, float *, int *, int *))dlsym(RTLD_NEXT, "cusparseSbsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSbsr2csr", kApiTypeCuSolver);

    lretval = lcusparseSbsr2csr(handle, dirA, mb, nb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSbsr2csr cusparseSbsr2csr


#undef cusparseDbsr2csr
cusparseStatus_t cusparseDbsr2csr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, cusparseMatDescr_t const descrC, double * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDbsr2csr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, cusparseMatDescr_t const, double *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, cusparseMatDescr_t const, double *, int *, int *))dlsym(RTLD_NEXT, "cusparseDbsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDbsr2csr", kApiTypeCuSolver);

    lretval = lcusparseDbsr2csr(handle, dirA, mb, nb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDbsr2csr cusparseDbsr2csr


#undef cusparseCbsr2csr
cusparseStatus_t cusparseCbsr2csr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, cusparseMatDescr_t const descrC, cuComplex * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCbsr2csr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, cusparseMatDescr_t const, cuComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, cusparseMatDescr_t const, cuComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseCbsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCbsr2csr", kApiTypeCuSolver);

    lretval = lcusparseCbsr2csr(handle, dirA, mb, nb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCbsr2csr cusparseCbsr2csr


#undef cusparseZbsr2csr
cusparseStatus_t cusparseZbsr2csr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int blockDim, cusparseMatDescr_t const descrC, cuDoubleComplex * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZbsr2csr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseZbsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZbsr2csr", kApiTypeCuSolver);

    lretval = lcusparseZbsr2csr(handle, dirA, mb, nb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, blockDim, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZbsr2csr cusparseZbsr2csr


#undef cusparseSgebsr2gebsc_bufferSize
cusparseStatus_t cusparseSgebsr2gebsc_bufferSize(cusparseHandle_t handle, int mb, int nb, int nnzb, float const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgebsr2gebsc_bufferSize) (cusparseHandle_t, int, int, int, float const *, int const *, int const *, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, float const *, int const *, int const *, int, int, int *))dlsym(RTLD_NEXT, "cusparseSgebsr2gebsc_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgebsr2gebsc_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSgebsr2gebsc_bufferSize(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgebsr2gebsc_bufferSize cusparseSgebsr2gebsc_bufferSize


#undef cusparseDgebsr2gebsc_bufferSize
cusparseStatus_t cusparseDgebsr2gebsc_bufferSize(cusparseHandle_t handle, int mb, int nb, int nnzb, double const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgebsr2gebsc_bufferSize) (cusparseHandle_t, int, int, int, double const *, int const *, int const *, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, double const *, int const *, int const *, int, int, int *))dlsym(RTLD_NEXT, "cusparseDgebsr2gebsc_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgebsr2gebsc_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDgebsr2gebsc_bufferSize(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgebsr2gebsc_bufferSize cusparseDgebsr2gebsc_bufferSize


#undef cusparseCgebsr2gebsc_bufferSize
cusparseStatus_t cusparseCgebsr2gebsc_bufferSize(cusparseHandle_t handle, int mb, int nb, int nnzb, cuComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgebsr2gebsc_bufferSize) (cusparseHandle_t, int, int, int, cuComplex const *, int const *, int const *, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuComplex const *, int const *, int const *, int, int, int *))dlsym(RTLD_NEXT, "cusparseCgebsr2gebsc_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgebsr2gebsc_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCgebsr2gebsc_bufferSize(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgebsr2gebsc_bufferSize cusparseCgebsr2gebsc_bufferSize


#undef cusparseZgebsr2gebsc_bufferSize
cusparseStatus_t cusparseZgebsr2gebsc_bufferSize(cusparseHandle_t handle, int mb, int nb, int nnzb, cuDoubleComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgebsr2gebsc_bufferSize) (cusparseHandle_t, int, int, int, cuDoubleComplex const *, int const *, int const *, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuDoubleComplex const *, int const *, int const *, int, int, int *))dlsym(RTLD_NEXT, "cusparseZgebsr2gebsc_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgebsr2gebsc_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZgebsr2gebsc_bufferSize(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgebsr2gebsc_bufferSize cusparseZgebsr2gebsc_bufferSize


#undef cusparseSgebsr2gebsc_bufferSizeExt
cusparseStatus_t cusparseSgebsr2gebsc_bufferSizeExt(cusparseHandle_t handle, int mb, int nb, int nnzb, float const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgebsr2gebsc_bufferSizeExt) (cusparseHandle_t, int, int, int, float const *, int const *, int const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, float const *, int const *, int const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseSgebsr2gebsc_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgebsr2gebsc_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSgebsr2gebsc_bufferSizeExt(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgebsr2gebsc_bufferSizeExt cusparseSgebsr2gebsc_bufferSizeExt


#undef cusparseDgebsr2gebsc_bufferSizeExt
cusparseStatus_t cusparseDgebsr2gebsc_bufferSizeExt(cusparseHandle_t handle, int mb, int nb, int nnzb, double const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgebsr2gebsc_bufferSizeExt) (cusparseHandle_t, int, int, int, double const *, int const *, int const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, double const *, int const *, int const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseDgebsr2gebsc_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgebsr2gebsc_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDgebsr2gebsc_bufferSizeExt(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgebsr2gebsc_bufferSizeExt cusparseDgebsr2gebsc_bufferSizeExt


#undef cusparseCgebsr2gebsc_bufferSizeExt
cusparseStatus_t cusparseCgebsr2gebsc_bufferSizeExt(cusparseHandle_t handle, int mb, int nb, int nnzb, cuComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgebsr2gebsc_bufferSizeExt) (cusparseHandle_t, int, int, int, cuComplex const *, int const *, int const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuComplex const *, int const *, int const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseCgebsr2gebsc_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgebsr2gebsc_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCgebsr2gebsc_bufferSizeExt(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgebsr2gebsc_bufferSizeExt cusparseCgebsr2gebsc_bufferSizeExt


#undef cusparseZgebsr2gebsc_bufferSizeExt
cusparseStatus_t cusparseZgebsr2gebsc_bufferSizeExt(cusparseHandle_t handle, int mb, int nb, int nnzb, cuDoubleComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgebsr2gebsc_bufferSizeExt) (cusparseHandle_t, int, int, int, cuDoubleComplex const *, int const *, int const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuDoubleComplex const *, int const *, int const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseZgebsr2gebsc_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgebsr2gebsc_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZgebsr2gebsc_bufferSizeExt(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgebsr2gebsc_bufferSizeExt cusparseZgebsr2gebsc_bufferSizeExt


#undef cusparseSgebsr2gebsc
cusparseStatus_t cusparseSgebsr2gebsc(cusparseHandle_t handle, int mb, int nb, int nnzb, float const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, float * bscVal, int * bscRowInd, int * bscColPtr, cusparseAction_t copyValues, cusparseIndexBase_t idxBase, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgebsr2gebsc) (cusparseHandle_t, int, int, int, float const *, int const *, int const *, int, int, float *, int *, int *, cusparseAction_t, cusparseIndexBase_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, float const *, int const *, int const *, int, int, float *, int *, int *, cusparseAction_t, cusparseIndexBase_t, void *))dlsym(RTLD_NEXT, "cusparseSgebsr2gebsc");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgebsr2gebsc", kApiTypeCuSolver);

    lretval = lcusparseSgebsr2gebsc(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, bscVal, bscRowInd, bscColPtr, copyValues, idxBase, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgebsr2gebsc cusparseSgebsr2gebsc


#undef cusparseDgebsr2gebsc
cusparseStatus_t cusparseDgebsr2gebsc(cusparseHandle_t handle, int mb, int nb, int nnzb, double const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, double * bscVal, int * bscRowInd, int * bscColPtr, cusparseAction_t copyValues, cusparseIndexBase_t idxBase, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgebsr2gebsc) (cusparseHandle_t, int, int, int, double const *, int const *, int const *, int, int, double *, int *, int *, cusparseAction_t, cusparseIndexBase_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, double const *, int const *, int const *, int, int, double *, int *, int *, cusparseAction_t, cusparseIndexBase_t, void *))dlsym(RTLD_NEXT, "cusparseDgebsr2gebsc");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgebsr2gebsc", kApiTypeCuSolver);

    lretval = lcusparseDgebsr2gebsc(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, bscVal, bscRowInd, bscColPtr, copyValues, idxBase, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgebsr2gebsc cusparseDgebsr2gebsc


#undef cusparseCgebsr2gebsc
cusparseStatus_t cusparseCgebsr2gebsc(cusparseHandle_t handle, int mb, int nb, int nnzb, cuComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, cuComplex * bscVal, int * bscRowInd, int * bscColPtr, cusparseAction_t copyValues, cusparseIndexBase_t idxBase, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgebsr2gebsc) (cusparseHandle_t, int, int, int, cuComplex const *, int const *, int const *, int, int, cuComplex *, int *, int *, cusparseAction_t, cusparseIndexBase_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuComplex const *, int const *, int const *, int, int, cuComplex *, int *, int *, cusparseAction_t, cusparseIndexBase_t, void *))dlsym(RTLD_NEXT, "cusparseCgebsr2gebsc");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgebsr2gebsc", kApiTypeCuSolver);

    lretval = lcusparseCgebsr2gebsc(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, bscVal, bscRowInd, bscColPtr, copyValues, idxBase, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgebsr2gebsc cusparseCgebsr2gebsc


#undef cusparseZgebsr2gebsc
cusparseStatus_t cusparseZgebsr2gebsc(cusparseHandle_t handle, int mb, int nb, int nnzb, cuDoubleComplex const * bsrSortedVal, int const * bsrSortedRowPtr, int const * bsrSortedColInd, int rowBlockDim, int colBlockDim, cuDoubleComplex * bscVal, int * bscRowInd, int * bscColPtr, cusparseAction_t copyValues, cusparseIndexBase_t idxBase, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgebsr2gebsc) (cusparseHandle_t, int, int, int, cuDoubleComplex const *, int const *, int const *, int, int, cuDoubleComplex *, int *, int *, cusparseAction_t, cusparseIndexBase_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuDoubleComplex const *, int const *, int const *, int, int, cuDoubleComplex *, int *, int *, cusparseAction_t, cusparseIndexBase_t, void *))dlsym(RTLD_NEXT, "cusparseZgebsr2gebsc");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgebsr2gebsc", kApiTypeCuSolver);

    lretval = lcusparseZgebsr2gebsc(handle, mb, nb, nnzb, bsrSortedVal, bsrSortedRowPtr, bsrSortedColInd, rowBlockDim, colBlockDim, bscVal, bscRowInd, bscColPtr, copyValues, idxBase, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgebsr2gebsc cusparseZgebsr2gebsc


#undef cusparseXgebsr2csr
cusparseStatus_t cusparseXgebsr2csr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, cusparseMatDescr_t const descrA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDim, int colBlockDim, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * csrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXgebsr2csr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, int const *, int const *, int, int, cusparseMatDescr_t const, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, int const *, int const *, int, int, cusparseMatDescr_t const, int *, int *))dlsym(RTLD_NEXT, "cusparseXgebsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXgebsr2csr", kApiTypeCuSolver);

    lretval = lcusparseXgebsr2csr(handle, dirA, mb, nb, descrA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDim, colBlockDim, descrC, csrSortedRowPtrC, csrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXgebsr2csr cusparseXgebsr2csr


#undef cusparseSgebsr2csr
cusparseStatus_t cusparseSgebsr2csr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDim, int colBlockDim, cusparseMatDescr_t const descrC, float * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgebsr2csr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, cusparseMatDescr_t const, float *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, cusparseMatDescr_t const, float *, int *, int *))dlsym(RTLD_NEXT, "cusparseSgebsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgebsr2csr", kApiTypeCuSolver);

    lretval = lcusparseSgebsr2csr(handle, dirA, mb, nb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDim, colBlockDim, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgebsr2csr cusparseSgebsr2csr


#undef cusparseDgebsr2csr
cusparseStatus_t cusparseDgebsr2csr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDim, int colBlockDim, cusparseMatDescr_t const descrC, double * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgebsr2csr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, cusparseMatDescr_t const, double *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, cusparseMatDescr_t const, double *, int *, int *))dlsym(RTLD_NEXT, "cusparseDgebsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgebsr2csr", kApiTypeCuSolver);

    lretval = lcusparseDgebsr2csr(handle, dirA, mb, nb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDim, colBlockDim, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgebsr2csr cusparseDgebsr2csr


#undef cusparseCgebsr2csr
cusparseStatus_t cusparseCgebsr2csr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDim, int colBlockDim, cusparseMatDescr_t const descrC, cuComplex * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgebsr2csr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, cusparseMatDescr_t const, cuComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, cusparseMatDescr_t const, cuComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseCgebsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgebsr2csr", kApiTypeCuSolver);

    lretval = lcusparseCgebsr2csr(handle, dirA, mb, nb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDim, colBlockDim, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgebsr2csr cusparseCgebsr2csr


#undef cusparseZgebsr2csr
cusparseStatus_t cusparseZgebsr2csr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDim, int colBlockDim, cusparseMatDescr_t const descrC, cuDoubleComplex * csrSortedValC, int * csrSortedRowPtrC, int * csrSortedColIndC){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgebsr2csr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *))dlsym(RTLD_NEXT, "cusparseZgebsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgebsr2csr", kApiTypeCuSolver);

    lretval = lcusparseZgebsr2csr(handle, dirA, mb, nb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDim, colBlockDim, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgebsr2csr cusparseZgebsr2csr


#undef cusparseScsr2gebsr_bufferSize
cusparseStatus_t cusparseScsr2gebsr_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int rowBlockDim, int colBlockDim, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsr2gebsr_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, int *))dlsym(RTLD_NEXT, "cusparseScsr2gebsr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsr2gebsr_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseScsr2gebsr_bufferSize(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, rowBlockDim, colBlockDim, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsr2gebsr_bufferSize cusparseScsr2gebsr_bufferSize


#undef cusparseDcsr2gebsr_bufferSize
cusparseStatus_t cusparseDcsr2gebsr_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int rowBlockDim, int colBlockDim, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsr2gebsr_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, int *))dlsym(RTLD_NEXT, "cusparseDcsr2gebsr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsr2gebsr_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDcsr2gebsr_bufferSize(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, rowBlockDim, colBlockDim, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsr2gebsr_bufferSize cusparseDcsr2gebsr_bufferSize


#undef cusparseCcsr2gebsr_bufferSize
cusparseStatus_t cusparseCcsr2gebsr_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int rowBlockDim, int colBlockDim, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsr2gebsr_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, int *))dlsym(RTLD_NEXT, "cusparseCcsr2gebsr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsr2gebsr_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCcsr2gebsr_bufferSize(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, rowBlockDim, colBlockDim, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsr2gebsr_bufferSize cusparseCcsr2gebsr_bufferSize


#undef cusparseZcsr2gebsr_bufferSize
cusparseStatus_t cusparseZcsr2gebsr_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int rowBlockDim, int colBlockDim, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsr2gebsr_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, int *))dlsym(RTLD_NEXT, "cusparseZcsr2gebsr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsr2gebsr_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZcsr2gebsr_bufferSize(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, rowBlockDim, colBlockDim, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsr2gebsr_bufferSize cusparseZcsr2gebsr_bufferSize


#undef cusparseScsr2gebsr_bufferSizeExt
cusparseStatus_t cusparseScsr2gebsr_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int rowBlockDim, int colBlockDim, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsr2gebsr_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseScsr2gebsr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsr2gebsr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseScsr2gebsr_bufferSizeExt(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, rowBlockDim, colBlockDim, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsr2gebsr_bufferSizeExt cusparseScsr2gebsr_bufferSizeExt


#undef cusparseDcsr2gebsr_bufferSizeExt
cusparseStatus_t cusparseDcsr2gebsr_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int rowBlockDim, int colBlockDim, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsr2gebsr_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseDcsr2gebsr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsr2gebsr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDcsr2gebsr_bufferSizeExt(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, rowBlockDim, colBlockDim, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsr2gebsr_bufferSizeExt cusparseDcsr2gebsr_bufferSizeExt


#undef cusparseCcsr2gebsr_bufferSizeExt
cusparseStatus_t cusparseCcsr2gebsr_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int rowBlockDim, int colBlockDim, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsr2gebsr_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseCcsr2gebsr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsr2gebsr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCcsr2gebsr_bufferSizeExt(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, rowBlockDim, colBlockDim, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsr2gebsr_bufferSizeExt cusparseCcsr2gebsr_bufferSizeExt


#undef cusparseZcsr2gebsr_bufferSizeExt
cusparseStatus_t cusparseZcsr2gebsr_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, int rowBlockDim, int colBlockDim, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsr2gebsr_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseZcsr2gebsr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsr2gebsr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZcsr2gebsr_bufferSizeExt(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, rowBlockDim, colBlockDim, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsr2gebsr_bufferSizeExt cusparseZcsr2gebsr_bufferSizeExt


#undef cusparseXcsr2gebsrNnz
cusparseStatus_t cusparseXcsr2gebsrNnz(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrC, int * bsrSortedRowPtrC, int rowBlockDim, int colBlockDim, int * nnzTotalDevHostPtr, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsr2gebsrNnz) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, int const *, int const *, cusparseMatDescr_t const, int *, int, int, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, int const *, int const *, cusparseMatDescr_t const, int *, int, int, int *, void *))dlsym(RTLD_NEXT, "cusparseXcsr2gebsrNnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsr2gebsrNnz", kApiTypeCuSolver);

    lretval = lcusparseXcsr2gebsrNnz(handle, dirA, m, n, descrA, csrSortedRowPtrA, csrSortedColIndA, descrC, bsrSortedRowPtrC, rowBlockDim, colBlockDim, nnzTotalDevHostPtr, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsr2gebsrNnz cusparseXcsr2gebsrNnz


#undef cusparseScsr2gebsr
cusparseStatus_t cusparseScsr2gebsr(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrC, float * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC, int rowBlockDim, int colBlockDim, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsr2gebsr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, cusparseMatDescr_t const, float *, int *, int *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, cusparseMatDescr_t const, float *, int *, int *, int, int, void *))dlsym(RTLD_NEXT, "cusparseScsr2gebsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsr2gebsr", kApiTypeCuSolver);

    lretval = lcusparseScsr2gebsr(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC, rowBlockDim, colBlockDim, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsr2gebsr cusparseScsr2gebsr


#undef cusparseDcsr2gebsr
cusparseStatus_t cusparseDcsr2gebsr(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrC, double * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC, int rowBlockDim, int colBlockDim, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsr2gebsr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, cusparseMatDescr_t const, double *, int *, int *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, cusparseMatDescr_t const, double *, int *, int *, int, int, void *))dlsym(RTLD_NEXT, "cusparseDcsr2gebsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsr2gebsr", kApiTypeCuSolver);

    lretval = lcusparseDcsr2gebsr(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC, rowBlockDim, colBlockDim, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsr2gebsr cusparseDcsr2gebsr


#undef cusparseCcsr2gebsr
cusparseStatus_t cusparseCcsr2gebsr(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrC, cuComplex * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC, int rowBlockDim, int colBlockDim, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsr2gebsr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, cuComplex *, int *, int *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, cusparseMatDescr_t const, cuComplex *, int *, int *, int, int, void *))dlsym(RTLD_NEXT, "cusparseCcsr2gebsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsr2gebsr", kApiTypeCuSolver);

    lretval = lcusparseCcsr2gebsr(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC, rowBlockDim, colBlockDim, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsr2gebsr cusparseCcsr2gebsr


#undef cusparseZcsr2gebsr
cusparseStatus_t cusparseZcsr2gebsr(cusparseHandle_t handle, cusparseDirection_t dirA, int m, int n, cusparseMatDescr_t const descrA, cuDoubleComplex const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, cusparseMatDescr_t const descrC, cuDoubleComplex * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC, int rowBlockDim, int colBlockDim, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsr2gebsr) (cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *, int, int, void *))dlsym(RTLD_NEXT, "cusparseZcsr2gebsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsr2gebsr", kApiTypeCuSolver);

    lretval = lcusparseZcsr2gebsr(handle, dirA, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC, rowBlockDim, colBlockDim, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsr2gebsr cusparseZcsr2gebsr


#undef cusparseSgebsr2gebsr_bufferSize
cusparseStatus_t cusparseSgebsr2gebsr_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, int rowBlockDimC, int colBlockDimC, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgebsr2gebsr_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, int, int, int *))dlsym(RTLD_NEXT, "cusparseSgebsr2gebsr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgebsr2gebsr_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSgebsr2gebsr_bufferSize(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, rowBlockDimC, colBlockDimC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgebsr2gebsr_bufferSize cusparseSgebsr2gebsr_bufferSize


#undef cusparseDgebsr2gebsr_bufferSize
cusparseStatus_t cusparseDgebsr2gebsr_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, int rowBlockDimC, int colBlockDimC, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgebsr2gebsr_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, int, int, int *))dlsym(RTLD_NEXT, "cusparseDgebsr2gebsr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgebsr2gebsr_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDgebsr2gebsr_bufferSize(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, rowBlockDimC, colBlockDimC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgebsr2gebsr_bufferSize cusparseDgebsr2gebsr_bufferSize


#undef cusparseCgebsr2gebsr_bufferSize
cusparseStatus_t cusparseCgebsr2gebsr_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, int rowBlockDimC, int colBlockDimC, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgebsr2gebsr_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, int, int, int *))dlsym(RTLD_NEXT, "cusparseCgebsr2gebsr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgebsr2gebsr_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCgebsr2gebsr_bufferSize(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, rowBlockDimC, colBlockDimC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgebsr2gebsr_bufferSize cusparseCgebsr2gebsr_bufferSize


#undef cusparseZgebsr2gebsr_bufferSize
cusparseStatus_t cusparseZgebsr2gebsr_bufferSize(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, int rowBlockDimC, int colBlockDimC, int * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgebsr2gebsr_bufferSize) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, int, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, int, int, int *))dlsym(RTLD_NEXT, "cusparseZgebsr2gebsr_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgebsr2gebsr_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseZgebsr2gebsr_bufferSize(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, rowBlockDimC, colBlockDimC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgebsr2gebsr_bufferSize cusparseZgebsr2gebsr_bufferSize


#undef cusparseSgebsr2gebsr_bufferSizeExt
cusparseStatus_t cusparseSgebsr2gebsr_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, int rowBlockDimC, int colBlockDimC, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgebsr2gebsr_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseSgebsr2gebsr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgebsr2gebsr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSgebsr2gebsr_bufferSizeExt(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, rowBlockDimC, colBlockDimC, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgebsr2gebsr_bufferSizeExt cusparseSgebsr2gebsr_bufferSizeExt


#undef cusparseDgebsr2gebsr_bufferSizeExt
cusparseStatus_t cusparseDgebsr2gebsr_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, int rowBlockDimC, int colBlockDimC, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgebsr2gebsr_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseDgebsr2gebsr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgebsr2gebsr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDgebsr2gebsr_bufferSizeExt(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, rowBlockDimC, colBlockDimC, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgebsr2gebsr_bufferSizeExt cusparseDgebsr2gebsr_bufferSizeExt


#undef cusparseCgebsr2gebsr_bufferSizeExt
cusparseStatus_t cusparseCgebsr2gebsr_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, int rowBlockDimC, int colBlockDimC, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgebsr2gebsr_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseCgebsr2gebsr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgebsr2gebsr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCgebsr2gebsr_bufferSizeExt(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, rowBlockDimC, colBlockDimC, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgebsr2gebsr_bufferSizeExt cusparseCgebsr2gebsr_bufferSizeExt


#undef cusparseZgebsr2gebsr_bufferSizeExt
cusparseStatus_t cusparseZgebsr2gebsr_bufferSizeExt(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, int rowBlockDimC, int colBlockDimC, size_t * pBufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgebsr2gebsr_bufferSizeExt) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, int, int, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, int, int, size_t *))dlsym(RTLD_NEXT, "cusparseZgebsr2gebsr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgebsr2gebsr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZgebsr2gebsr_bufferSizeExt(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, rowBlockDimC, colBlockDimC, pBufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgebsr2gebsr_bufferSizeExt cusparseZgebsr2gebsr_bufferSizeExt


#undef cusparseXgebsr2gebsrNnz
cusparseStatus_t cusparseXgebsr2gebsrNnz(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, cusparseMatDescr_t const descrC, int * bsrSortedRowPtrC, int rowBlockDimC, int colBlockDimC, int * nnzTotalDevHostPtr, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXgebsr2gebsrNnz) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, int const *, int const *, int, int, cusparseMatDescr_t const, int *, int, int, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, int const *, int const *, int, int, cusparseMatDescr_t const, int *, int, int, int *, void *))dlsym(RTLD_NEXT, "cusparseXgebsr2gebsrNnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXgebsr2gebsrNnz", kApiTypeCuSolver);

    lretval = lcusparseXgebsr2gebsrNnz(handle, dirA, mb, nb, nnzb, descrA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, descrC, bsrSortedRowPtrC, rowBlockDimC, colBlockDimC, nnzTotalDevHostPtr, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXgebsr2gebsrNnz cusparseXgebsr2gebsrNnz


#undef cusparseSgebsr2gebsr
cusparseStatus_t cusparseSgebsr2gebsr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, float const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, cusparseMatDescr_t const descrC, float * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC, int rowBlockDimC, int colBlockDimC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSgebsr2gebsr) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, cusparseMatDescr_t const, float *, int *, int *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, int, int, cusparseMatDescr_t const, float *, int *, int *, int, int, void *))dlsym(RTLD_NEXT, "cusparseSgebsr2gebsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSgebsr2gebsr", kApiTypeCuSolver);

    lretval = lcusparseSgebsr2gebsr(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC, rowBlockDimC, colBlockDimC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSgebsr2gebsr cusparseSgebsr2gebsr


#undef cusparseDgebsr2gebsr
cusparseStatus_t cusparseDgebsr2gebsr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, double const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, cusparseMatDescr_t const descrC, double * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC, int rowBlockDimC, int colBlockDimC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDgebsr2gebsr) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, cusparseMatDescr_t const, double *, int *, int *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, int, int, cusparseMatDescr_t const, double *, int *, int *, int, int, void *))dlsym(RTLD_NEXT, "cusparseDgebsr2gebsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDgebsr2gebsr", kApiTypeCuSolver);

    lretval = lcusparseDgebsr2gebsr(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC, rowBlockDimC, colBlockDimC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDgebsr2gebsr cusparseDgebsr2gebsr


#undef cusparseCgebsr2gebsr
cusparseStatus_t cusparseCgebsr2gebsr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, cuComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, cusparseMatDescr_t const descrC, cuComplex * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC, int rowBlockDimC, int colBlockDimC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCgebsr2gebsr) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, cusparseMatDescr_t const, cuComplex *, int *, int *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuComplex const *, int const *, int const *, int, int, cusparseMatDescr_t const, cuComplex *, int *, int *, int, int, void *))dlsym(RTLD_NEXT, "cusparseCgebsr2gebsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCgebsr2gebsr", kApiTypeCuSolver);

    lretval = lcusparseCgebsr2gebsr(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC, rowBlockDimC, colBlockDimC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCgebsr2gebsr cusparseCgebsr2gebsr


#undef cusparseZgebsr2gebsr
cusparseStatus_t cusparseZgebsr2gebsr(cusparseHandle_t handle, cusparseDirection_t dirA, int mb, int nb, int nnzb, cusparseMatDescr_t const descrA, cuDoubleComplex const * bsrSortedValA, int const * bsrSortedRowPtrA, int const * bsrSortedColIndA, int rowBlockDimA, int colBlockDimA, cusparseMatDescr_t const descrC, cuDoubleComplex * bsrSortedValC, int * bsrSortedRowPtrC, int * bsrSortedColIndC, int rowBlockDimC, int colBlockDimC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZgebsr2gebsr) (cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *, int, int, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDirection_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex const *, int const *, int const *, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int *, int *, int, int, void *))dlsym(RTLD_NEXT, "cusparseZgebsr2gebsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZgebsr2gebsr", kApiTypeCuSolver);

    lretval = lcusparseZgebsr2gebsr(handle, dirA, mb, nb, nnzb, descrA, bsrSortedValA, bsrSortedRowPtrA, bsrSortedColIndA, rowBlockDimA, colBlockDimA, descrC, bsrSortedValC, bsrSortedRowPtrC, bsrSortedColIndC, rowBlockDimC, colBlockDimC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZgebsr2gebsr cusparseZgebsr2gebsr


#undef cusparseCreateIdentityPermutation
cusparseStatus_t cusparseCreateIdentityPermutation(cusparseHandle_t handle, int n, int * p){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateIdentityPermutation) (cusparseHandle_t, int, int *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int *))dlsym(RTLD_NEXT, "cusparseCreateIdentityPermutation");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateIdentityPermutation", kApiTypeCuSolver);

    lretval = lcusparseCreateIdentityPermutation(handle, n, p);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateIdentityPermutation cusparseCreateIdentityPermutation


#undef cusparseXcoosort_bufferSizeExt
cusparseStatus_t cusparseXcoosort_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnz, int const * cooRowsA, int const * cooColsA, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcoosort_bufferSizeExt) (cusparseHandle_t, int, int, int, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseXcoosort_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcoosort_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseXcoosort_bufferSizeExt(handle, m, n, nnz, cooRowsA, cooColsA, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcoosort_bufferSizeExt cusparseXcoosort_bufferSizeExt


#undef cusparseXcoosortByRow
cusparseStatus_t cusparseXcoosortByRow(cusparseHandle_t handle, int m, int n, int nnz, int * cooRowsA, int * cooColsA, int * P, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcoosortByRow) (cusparseHandle_t, int, int, int, int *, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, int *, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseXcoosortByRow");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcoosortByRow", kApiTypeCuSolver);

    lretval = lcusparseXcoosortByRow(handle, m, n, nnz, cooRowsA, cooColsA, P, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcoosortByRow cusparseXcoosortByRow


#undef cusparseXcoosortByColumn
cusparseStatus_t cusparseXcoosortByColumn(cusparseHandle_t handle, int m, int n, int nnz, int * cooRowsA, int * cooColsA, int * P, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcoosortByColumn) (cusparseHandle_t, int, int, int, int *, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, int *, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseXcoosortByColumn");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcoosortByColumn", kApiTypeCuSolver);

    lretval = lcusparseXcoosortByColumn(handle, m, n, nnz, cooRowsA, cooColsA, P, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcoosortByColumn cusparseXcoosortByColumn


#undef cusparseXcsrsort_bufferSizeExt
cusparseStatus_t cusparseXcsrsort_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnz, int const * csrRowPtrA, int const * csrColIndA, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsrsort_bufferSizeExt) (cusparseHandle_t, int, int, int, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseXcsrsort_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsrsort_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseXcsrsort_bufferSizeExt(handle, m, n, nnz, csrRowPtrA, csrColIndA, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsrsort_bufferSizeExt cusparseXcsrsort_bufferSizeExt


#undef cusparseXcsrsort
cusparseStatus_t cusparseXcsrsort(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, int const * csrRowPtrA, int * csrColIndA, int * P, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcsrsort) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, int const *, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, int const *, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseXcsrsort");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcsrsort", kApiTypeCuSolver);

    lretval = lcusparseXcsrsort(handle, m, n, nnz, descrA, csrRowPtrA, csrColIndA, P, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcsrsort cusparseXcsrsort


#undef cusparseXcscsort_bufferSizeExt
cusparseStatus_t cusparseXcscsort_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnz, int const * cscColPtrA, int const * cscRowIndA, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcscsort_bufferSizeExt) (cusparseHandle_t, int, int, int, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseXcscsort_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcscsort_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseXcscsort_bufferSizeExt(handle, m, n, nnz, cscColPtrA, cscRowIndA, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcscsort_bufferSizeExt cusparseXcscsort_bufferSizeExt


#undef cusparseXcscsort
cusparseStatus_t cusparseXcscsort(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, int const * cscColPtrA, int * cscRowIndA, int * P, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseXcscsort) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, int const *, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, int const *, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseXcscsort");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseXcscsort", kApiTypeCuSolver);

    lretval = lcusparseXcscsort(handle, m, n, nnz, descrA, cscColPtrA, cscRowIndA, P, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseXcscsort cusparseXcscsort


#undef cusparseScsru2csr_bufferSizeExt
cusparseStatus_t cusparseScsru2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnz, float * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsru2csr_bufferSizeExt) (cusparseHandle_t, int, int, int, float *, int const *, int *, csru2csrInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, float *, int const *, int *, csru2csrInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseScsru2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsru2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseScsru2csr_bufferSizeExt(handle, m, n, nnz, csrVal, csrRowPtr, csrColInd, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsru2csr_bufferSizeExt cusparseScsru2csr_bufferSizeExt


#undef cusparseDcsru2csr_bufferSizeExt
cusparseStatus_t cusparseDcsru2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnz, double * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsru2csr_bufferSizeExt) (cusparseHandle_t, int, int, int, double *, int const *, int *, csru2csrInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, double *, int const *, int *, csru2csrInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseDcsru2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsru2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDcsru2csr_bufferSizeExt(handle, m, n, nnz, csrVal, csrRowPtr, csrColInd, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsru2csr_bufferSizeExt cusparseDcsru2csr_bufferSizeExt


#undef cusparseCcsru2csr_bufferSizeExt
cusparseStatus_t cusparseCcsru2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnz, cuComplex * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsru2csr_bufferSizeExt) (cusparseHandle_t, int, int, int, cuComplex *, int const *, int *, csru2csrInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuComplex *, int const *, int *, csru2csrInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseCcsru2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsru2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseCcsru2csr_bufferSizeExt(handle, m, n, nnz, csrVal, csrRowPtr, csrColInd, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsru2csr_bufferSizeExt cusparseCcsru2csr_bufferSizeExt


#undef cusparseZcsru2csr_bufferSizeExt
cusparseStatus_t cusparseZcsru2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnz, cuDoubleComplex * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsru2csr_bufferSizeExt) (cusparseHandle_t, int, int, int, cuDoubleComplex *, int const *, int *, csru2csrInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cuDoubleComplex *, int const *, int *, csru2csrInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseZcsru2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsru2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseZcsru2csr_bufferSizeExt(handle, m, n, nnz, csrVal, csrRowPtr, csrColInd, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsru2csr_bufferSizeExt cusparseZcsru2csr_bufferSizeExt


#undef cusparseScsru2csr
cusparseStatus_t cusparseScsru2csr(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, float * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsru2csr) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float *, int const *, int *, csru2csrInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float *, int const *, int *, csru2csrInfo_t, void *))dlsym(RTLD_NEXT, "cusparseScsru2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsru2csr", kApiTypeCuSolver);

    lretval = lcusparseScsru2csr(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsru2csr cusparseScsru2csr


#undef cusparseDcsru2csr
cusparseStatus_t cusparseDcsru2csr(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, double * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsru2csr) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double *, int const *, int *, csru2csrInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double *, int const *, int *, csru2csrInfo_t, void *))dlsym(RTLD_NEXT, "cusparseDcsru2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsru2csr", kApiTypeCuSolver);

    lretval = lcusparseDcsru2csr(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsru2csr cusparseDcsru2csr


#undef cusparseCcsru2csr
cusparseStatus_t cusparseCcsru2csr(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsru2csr) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int *, csru2csrInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int *, csru2csrInfo_t, void *))dlsym(RTLD_NEXT, "cusparseCcsru2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsru2csr", kApiTypeCuSolver);

    lretval = lcusparseCcsru2csr(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsru2csr cusparseCcsru2csr


#undef cusparseZcsru2csr
cusparseStatus_t cusparseZcsru2csr(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsru2csr) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int *, csru2csrInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int *, csru2csrInfo_t, void *))dlsym(RTLD_NEXT, "cusparseZcsru2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsru2csr", kApiTypeCuSolver);

    lretval = lcusparseZcsru2csr(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsru2csr cusparseZcsru2csr


#undef cusparseScsr2csru
cusparseStatus_t cusparseScsr2csru(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, float * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScsr2csru) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float *, int const *, int *, csru2csrInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float *, int const *, int *, csru2csrInfo_t, void *))dlsym(RTLD_NEXT, "cusparseScsr2csru");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScsr2csru", kApiTypeCuSolver);

    lretval = lcusparseScsr2csru(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScsr2csru cusparseScsr2csru


#undef cusparseDcsr2csru
cusparseStatus_t cusparseDcsr2csru(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, double * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDcsr2csru) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double *, int const *, int *, csru2csrInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double *, int const *, int *, csru2csrInfo_t, void *))dlsym(RTLD_NEXT, "cusparseDcsr2csru");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDcsr2csru", kApiTypeCuSolver);

    lretval = lcusparseDcsr2csru(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDcsr2csru cusparseDcsr2csru


#undef cusparseCcsr2csru
cusparseStatus_t cusparseCcsr2csru(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuComplex * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCcsr2csru) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int *, csru2csrInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, cuComplex *, int const *, int *, csru2csrInfo_t, void *))dlsym(RTLD_NEXT, "cusparseCcsr2csru");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCcsr2csru", kApiTypeCuSolver);

    lretval = lcusparseCcsr2csru(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCcsr2csru cusparseCcsr2csru


#undef cusparseZcsr2csru
cusparseStatus_t cusparseZcsr2csru(cusparseHandle_t handle, int m, int n, int nnz, cusparseMatDescr_t const descrA, cuDoubleComplex * csrVal, int const * csrRowPtr, int * csrColInd, csru2csrInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseZcsr2csru) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int *, csru2csrInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, cuDoubleComplex *, int const *, int *, csru2csrInfo_t, void *))dlsym(RTLD_NEXT, "cusparseZcsr2csru");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseZcsr2csru", kApiTypeCuSolver);

    lretval = lcusparseZcsr2csru(handle, m, n, nnz, descrA, csrVal, csrRowPtr, csrColInd, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseZcsr2csru cusparseZcsr2csru


#undef cusparseHpruneDense2csr_bufferSizeExt
cusparseStatus_t cusparseHpruneDense2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, __half const * A, int lda, __half const * threshold, cusparseMatDescr_t const descrC, __half const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneDense2csr_bufferSizeExt) (cusparseHandle_t, int, int, __half const *, int, __half const *, cusparseMatDescr_t const, __half const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, __half const *, int, __half const *, cusparseMatDescr_t const, __half const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseHpruneDense2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneDense2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseHpruneDense2csr_bufferSizeExt(handle, m, n, A, lda, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneDense2csr_bufferSizeExt cusparseHpruneDense2csr_bufferSizeExt


#undef cusparseSpruneDense2csr_bufferSizeExt
cusparseStatus_t cusparseSpruneDense2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, float const * A, int lda, float const * threshold, cusparseMatDescr_t const descrC, float const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneDense2csr_bufferSizeExt) (cusparseHandle_t, int, int, float const *, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, int, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseSpruneDense2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneDense2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSpruneDense2csr_bufferSizeExt(handle, m, n, A, lda, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneDense2csr_bufferSizeExt cusparseSpruneDense2csr_bufferSizeExt


#undef cusparseDpruneDense2csr_bufferSizeExt
cusparseStatus_t cusparseDpruneDense2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, double const * A, int lda, double const * threshold, cusparseMatDescr_t const descrC, double const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneDense2csr_bufferSizeExt) (cusparseHandle_t, int, int, double const *, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, int, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseDpruneDense2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneDense2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDpruneDense2csr_bufferSizeExt(handle, m, n, A, lda, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneDense2csr_bufferSizeExt cusparseDpruneDense2csr_bufferSizeExt


#undef cusparseHpruneDense2csrNnz
cusparseStatus_t cusparseHpruneDense2csrNnz(cusparseHandle_t handle, int m, int n, __half const * A, int lda, __half const * threshold, cusparseMatDescr_t const descrC, int * csrRowPtrC, int * nnzTotalDevHostPtr, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneDense2csrNnz) (cusparseHandle_t, int, int, __half const *, int, __half const *, cusparseMatDescr_t const, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, __half const *, int, __half const *, cusparseMatDescr_t const, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseHpruneDense2csrNnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneDense2csrNnz", kApiTypeCuSolver);

    lretval = lcusparseHpruneDense2csrNnz(handle, m, n, A, lda, threshold, descrC, csrRowPtrC, nnzTotalDevHostPtr, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneDense2csrNnz cusparseHpruneDense2csrNnz


#undef cusparseSpruneDense2csrNnz
cusparseStatus_t cusparseSpruneDense2csrNnz(cusparseHandle_t handle, int m, int n, float const * A, int lda, float const * threshold, cusparseMatDescr_t const descrC, int * csrRowPtrC, int * nnzTotalDevHostPtr, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneDense2csrNnz) (cusparseHandle_t, int, int, float const *, int, float const *, cusparseMatDescr_t const, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, int, float const *, cusparseMatDescr_t const, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseSpruneDense2csrNnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneDense2csrNnz", kApiTypeCuSolver);

    lretval = lcusparseSpruneDense2csrNnz(handle, m, n, A, lda, threshold, descrC, csrRowPtrC, nnzTotalDevHostPtr, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneDense2csrNnz cusparseSpruneDense2csrNnz


#undef cusparseDpruneDense2csrNnz
cusparseStatus_t cusparseDpruneDense2csrNnz(cusparseHandle_t handle, int m, int n, double const * A, int lda, double const * threshold, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * nnzTotalDevHostPtr, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneDense2csrNnz) (cusparseHandle_t, int, int, double const *, int, double const *, cusparseMatDescr_t const, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, int, double const *, cusparseMatDescr_t const, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseDpruneDense2csrNnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneDense2csrNnz", kApiTypeCuSolver);

    lretval = lcusparseDpruneDense2csrNnz(handle, m, n, A, lda, threshold, descrC, csrSortedRowPtrC, nnzTotalDevHostPtr, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneDense2csrNnz cusparseDpruneDense2csrNnz


#undef cusparseHpruneDense2csr
cusparseStatus_t cusparseHpruneDense2csr(cusparseHandle_t handle, int m, int n, __half const * A, int lda, __half const * threshold, cusparseMatDescr_t const descrC, __half * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneDense2csr) (cusparseHandle_t, int, int, __half const *, int, __half const *, cusparseMatDescr_t const, __half *, int const *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, __half const *, int, __half const *, cusparseMatDescr_t const, __half *, int const *, int *, void *))dlsym(RTLD_NEXT, "cusparseHpruneDense2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneDense2csr", kApiTypeCuSolver);

    lretval = lcusparseHpruneDense2csr(handle, m, n, A, lda, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneDense2csr cusparseHpruneDense2csr


#undef cusparseSpruneDense2csr
cusparseStatus_t cusparseSpruneDense2csr(cusparseHandle_t handle, int m, int n, float const * A, int lda, float const * threshold, cusparseMatDescr_t const descrC, float * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneDense2csr) (cusparseHandle_t, int, int, float const *, int, float const *, cusparseMatDescr_t const, float *, int const *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, int, float const *, cusparseMatDescr_t const, float *, int const *, int *, void *))dlsym(RTLD_NEXT, "cusparseSpruneDense2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneDense2csr", kApiTypeCuSolver);

    lretval = lcusparseSpruneDense2csr(handle, m, n, A, lda, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneDense2csr cusparseSpruneDense2csr


#undef cusparseDpruneDense2csr
cusparseStatus_t cusparseDpruneDense2csr(cusparseHandle_t handle, int m, int n, double const * A, int lda, double const * threshold, cusparseMatDescr_t const descrC, double * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneDense2csr) (cusparseHandle_t, int, int, double const *, int, double const *, cusparseMatDescr_t const, double *, int const *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, int, double const *, cusparseMatDescr_t const, double *, int const *, int *, void *))dlsym(RTLD_NEXT, "cusparseDpruneDense2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneDense2csr", kApiTypeCuSolver);

    lretval = lcusparseDpruneDense2csr(handle, m, n, A, lda, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneDense2csr cusparseDpruneDense2csr


#undef cusparseHpruneCsr2csr_bufferSizeExt
cusparseStatus_t cusparseHpruneCsr2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, __half const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, __half const * threshold, cusparseMatDescr_t const descrC, __half const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneCsr2csr_bufferSizeExt) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, __half const *, cusparseMatDescr_t const, __half const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, __half const *, cusparseMatDescr_t const, __half const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseHpruneCsr2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneCsr2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseHpruneCsr2csr_bufferSizeExt(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneCsr2csr_bufferSizeExt cusparseHpruneCsr2csr_bufferSizeExt


#undef cusparseSpruneCsr2csr_bufferSizeExt
cusparseStatus_t cusparseSpruneCsr2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float const * threshold, cusparseMatDescr_t const descrC, float const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneCsr2csr_bufferSizeExt) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, float const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseSpruneCsr2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneCsr2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSpruneCsr2csr_bufferSizeExt(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneCsr2csr_bufferSizeExt cusparseSpruneCsr2csr_bufferSizeExt


#undef cusparseDpruneCsr2csr_bufferSizeExt
cusparseStatus_t cusparseDpruneCsr2csr_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double const * threshold, cusparseMatDescr_t const descrC, double const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneCsr2csr_bufferSizeExt) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, double const *, int const *, int const *, size_t *))dlsym(RTLD_NEXT, "cusparseDpruneCsr2csr_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneCsr2csr_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDpruneCsr2csr_bufferSizeExt(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneCsr2csr_bufferSizeExt cusparseDpruneCsr2csr_bufferSizeExt


#undef cusparseHpruneCsr2csrNnz
cusparseStatus_t cusparseHpruneCsr2csrNnz(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, __half const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, __half const * threshold, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * nnzTotalDevHostPtr, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneCsr2csrNnz) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, __half const *, cusparseMatDescr_t const, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, __half const *, cusparseMatDescr_t const, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseHpruneCsr2csrNnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneCsr2csrNnz", kApiTypeCuSolver);

    lretval = lcusparseHpruneCsr2csrNnz(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, threshold, descrC, csrSortedRowPtrC, nnzTotalDevHostPtr, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneCsr2csrNnz cusparseHpruneCsr2csrNnz


#undef cusparseSpruneCsr2csrNnz
cusparseStatus_t cusparseSpruneCsr2csrNnz(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float const * threshold, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * nnzTotalDevHostPtr, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneCsr2csrNnz) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseSpruneCsr2csrNnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneCsr2csrNnz", kApiTypeCuSolver);

    lretval = lcusparseSpruneCsr2csrNnz(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, threshold, descrC, csrSortedRowPtrC, nnzTotalDevHostPtr, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneCsr2csrNnz cusparseSpruneCsr2csrNnz


#undef cusparseDpruneCsr2csrNnz
cusparseStatus_t cusparseDpruneCsr2csrNnz(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double const * threshold, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * nnzTotalDevHostPtr, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneCsr2csrNnz) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, int *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, int *, int *, void *))dlsym(RTLD_NEXT, "cusparseDpruneCsr2csrNnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneCsr2csrNnz", kApiTypeCuSolver);

    lretval = lcusparseDpruneCsr2csrNnz(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, threshold, descrC, csrSortedRowPtrC, nnzTotalDevHostPtr, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneCsr2csrNnz cusparseDpruneCsr2csrNnz


#undef cusparseHpruneCsr2csr
cusparseStatus_t cusparseHpruneCsr2csr(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, __half const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, __half const * threshold, cusparseMatDescr_t const descrC, __half * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneCsr2csr) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, __half const *, cusparseMatDescr_t const, __half *, int const *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, __half const *, cusparseMatDescr_t const, __half *, int const *, int *, void *))dlsym(RTLD_NEXT, "cusparseHpruneCsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneCsr2csr", kApiTypeCuSolver);

    lretval = lcusparseHpruneCsr2csr(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneCsr2csr cusparseHpruneCsr2csr


#undef cusparseSpruneCsr2csr
cusparseStatus_t cusparseSpruneCsr2csr(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float const * threshold, cusparseMatDescr_t const descrC, float * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneCsr2csr) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, float *, int const *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float const *, cusparseMatDescr_t const, float *, int const *, int *, void *))dlsym(RTLD_NEXT, "cusparseSpruneCsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneCsr2csr", kApiTypeCuSolver);

    lretval = lcusparseSpruneCsr2csr(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneCsr2csr cusparseSpruneCsr2csr


#undef cusparseDpruneCsr2csr
cusparseStatus_t cusparseDpruneCsr2csr(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, double const * threshold, cusparseMatDescr_t const descrC, double * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneCsr2csr) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, double *, int const *, int *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, double const *, cusparseMatDescr_t const, double *, int const *, int *, void *))dlsym(RTLD_NEXT, "cusparseDpruneCsr2csr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneCsr2csr", kApiTypeCuSolver);

    lretval = lcusparseDpruneCsr2csr(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, threshold, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneCsr2csr cusparseDpruneCsr2csr


#undef cusparseHpruneDense2csrByPercentage_bufferSizeExt
cusparseStatus_t cusparseHpruneDense2csrByPercentage_bufferSizeExt(cusparseHandle_t handle, int m, int n, __half const * A, int lda, float percentage, cusparseMatDescr_t const descrC, __half const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, pruneInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneDense2csrByPercentage_bufferSizeExt) (cusparseHandle_t, int, int, __half const *, int, float, cusparseMatDescr_t const, __half const *, int const *, int const *, pruneInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, __half const *, int, float, cusparseMatDescr_t const, __half const *, int const *, int const *, pruneInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseHpruneDense2csrByPercentage_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneDense2csrByPercentage_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseHpruneDense2csrByPercentage_bufferSizeExt(handle, m, n, A, lda, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneDense2csrByPercentage_bufferSizeExt cusparseHpruneDense2csrByPercentage_bufferSizeExt


#undef cusparseSpruneDense2csrByPercentage_bufferSizeExt
cusparseStatus_t cusparseSpruneDense2csrByPercentage_bufferSizeExt(cusparseHandle_t handle, int m, int n, float const * A, int lda, float percentage, cusparseMatDescr_t const descrC, float const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, pruneInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneDense2csrByPercentage_bufferSizeExt) (cusparseHandle_t, int, int, float const *, int, float, cusparseMatDescr_t const, float const *, int const *, int const *, pruneInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, int, float, cusparseMatDescr_t const, float const *, int const *, int const *, pruneInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseSpruneDense2csrByPercentage_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneDense2csrByPercentage_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSpruneDense2csrByPercentage_bufferSizeExt(handle, m, n, A, lda, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneDense2csrByPercentage_bufferSizeExt cusparseSpruneDense2csrByPercentage_bufferSizeExt


#undef cusparseDpruneDense2csrByPercentage_bufferSizeExt
cusparseStatus_t cusparseDpruneDense2csrByPercentage_bufferSizeExt(cusparseHandle_t handle, int m, int n, double const * A, int lda, float percentage, cusparseMatDescr_t const descrC, double const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, pruneInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneDense2csrByPercentage_bufferSizeExt) (cusparseHandle_t, int, int, double const *, int, float, cusparseMatDescr_t const, double const *, int const *, int const *, pruneInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, int, float, cusparseMatDescr_t const, double const *, int const *, int const *, pruneInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseDpruneDense2csrByPercentage_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneDense2csrByPercentage_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDpruneDense2csrByPercentage_bufferSizeExt(handle, m, n, A, lda, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneDense2csrByPercentage_bufferSizeExt cusparseDpruneDense2csrByPercentage_bufferSizeExt


#undef cusparseHpruneDense2csrNnzByPercentage
cusparseStatus_t cusparseHpruneDense2csrNnzByPercentage(cusparseHandle_t handle, int m, int n, __half const * A, int lda, float percentage, cusparseMatDescr_t const descrC, int * csrRowPtrC, int * nnzTotalDevHostPtr, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneDense2csrNnzByPercentage) (cusparseHandle_t, int, int, __half const *, int, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, __half const *, int, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseHpruneDense2csrNnzByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneDense2csrNnzByPercentage", kApiTypeCuSolver);

    lretval = lcusparseHpruneDense2csrNnzByPercentage(handle, m, n, A, lda, percentage, descrC, csrRowPtrC, nnzTotalDevHostPtr, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneDense2csrNnzByPercentage cusparseHpruneDense2csrNnzByPercentage


#undef cusparseSpruneDense2csrNnzByPercentage
cusparseStatus_t cusparseSpruneDense2csrNnzByPercentage(cusparseHandle_t handle, int m, int n, float const * A, int lda, float percentage, cusparseMatDescr_t const descrC, int * csrRowPtrC, int * nnzTotalDevHostPtr, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneDense2csrNnzByPercentage) (cusparseHandle_t, int, int, float const *, int, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, int, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseSpruneDense2csrNnzByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneDense2csrNnzByPercentage", kApiTypeCuSolver);

    lretval = lcusparseSpruneDense2csrNnzByPercentage(handle, m, n, A, lda, percentage, descrC, csrRowPtrC, nnzTotalDevHostPtr, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneDense2csrNnzByPercentage cusparseSpruneDense2csrNnzByPercentage


#undef cusparseDpruneDense2csrNnzByPercentage
cusparseStatus_t cusparseDpruneDense2csrNnzByPercentage(cusparseHandle_t handle, int m, int n, double const * A, int lda, float percentage, cusparseMatDescr_t const descrC, int * csrRowPtrC, int * nnzTotalDevHostPtr, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneDense2csrNnzByPercentage) (cusparseHandle_t, int, int, double const *, int, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, int, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseDpruneDense2csrNnzByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneDense2csrNnzByPercentage", kApiTypeCuSolver);

    lretval = lcusparseDpruneDense2csrNnzByPercentage(handle, m, n, A, lda, percentage, descrC, csrRowPtrC, nnzTotalDevHostPtr, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneDense2csrNnzByPercentage cusparseDpruneDense2csrNnzByPercentage


#undef cusparseHpruneDense2csrByPercentage
cusparseStatus_t cusparseHpruneDense2csrByPercentage(cusparseHandle_t handle, int m, int n, __half const * A, int lda, float percentage, cusparseMatDescr_t const descrC, __half * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneDense2csrByPercentage) (cusparseHandle_t, int, int, __half const *, int, float, cusparseMatDescr_t const, __half *, int const *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, __half const *, int, float, cusparseMatDescr_t const, __half *, int const *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseHpruneDense2csrByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneDense2csrByPercentage", kApiTypeCuSolver);

    lretval = lcusparseHpruneDense2csrByPercentage(handle, m, n, A, lda, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneDense2csrByPercentage cusparseHpruneDense2csrByPercentage


#undef cusparseSpruneDense2csrByPercentage
cusparseStatus_t cusparseSpruneDense2csrByPercentage(cusparseHandle_t handle, int m, int n, float const * A, int lda, float percentage, cusparseMatDescr_t const descrC, float * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneDense2csrByPercentage) (cusparseHandle_t, int, int, float const *, int, float, cusparseMatDescr_t const, float *, int const *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, float const *, int, float, cusparseMatDescr_t const, float *, int const *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseSpruneDense2csrByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneDense2csrByPercentage", kApiTypeCuSolver);

    lretval = lcusparseSpruneDense2csrByPercentage(handle, m, n, A, lda, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneDense2csrByPercentage cusparseSpruneDense2csrByPercentage


#undef cusparseDpruneDense2csrByPercentage
cusparseStatus_t cusparseDpruneDense2csrByPercentage(cusparseHandle_t handle, int m, int n, double const * A, int lda, float percentage, cusparseMatDescr_t const descrC, double * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneDense2csrByPercentage) (cusparseHandle_t, int, int, double const *, int, float, cusparseMatDescr_t const, double *, int const *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, double const *, int, float, cusparseMatDescr_t const, double *, int const *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseDpruneDense2csrByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneDense2csrByPercentage", kApiTypeCuSolver);

    lretval = lcusparseDpruneDense2csrByPercentage(handle, m, n, A, lda, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneDense2csrByPercentage cusparseDpruneDense2csrByPercentage


#undef cusparseHpruneCsr2csrByPercentage_bufferSizeExt
cusparseStatus_t cusparseHpruneCsr2csrByPercentage_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, __half const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float percentage, cusparseMatDescr_t const descrC, __half const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, pruneInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneCsr2csrByPercentage_bufferSizeExt) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, float, cusparseMatDescr_t const, __half const *, int const *, int const *, pruneInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, float, cusparseMatDescr_t const, __half const *, int const *, int const *, pruneInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseHpruneCsr2csrByPercentage_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneCsr2csrByPercentage_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseHpruneCsr2csrByPercentage_bufferSizeExt(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneCsr2csrByPercentage_bufferSizeExt cusparseHpruneCsr2csrByPercentage_bufferSizeExt


#undef cusparseSpruneCsr2csrByPercentage_bufferSizeExt
cusparseStatus_t cusparseSpruneCsr2csrByPercentage_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float percentage, cusparseMatDescr_t const descrC, float const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, pruneInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneCsr2csrByPercentage_bufferSizeExt) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, cusparseMatDescr_t const, float const *, int const *, int const *, pruneInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, cusparseMatDescr_t const, float const *, int const *, int const *, pruneInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseSpruneCsr2csrByPercentage_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneCsr2csrByPercentage_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseSpruneCsr2csrByPercentage_bufferSizeExt(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneCsr2csrByPercentage_bufferSizeExt cusparseSpruneCsr2csrByPercentage_bufferSizeExt


#undef cusparseDpruneCsr2csrByPercentage_bufferSizeExt
cusparseStatus_t cusparseDpruneCsr2csrByPercentage_bufferSizeExt(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float percentage, cusparseMatDescr_t const descrC, double const * csrSortedValC, int const * csrSortedRowPtrC, int const * csrSortedColIndC, pruneInfo_t info, size_t * pBufferSizeInBytes){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneCsr2csrByPercentage_bufferSizeExt) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, float, cusparseMatDescr_t const, double const *, int const *, int const *, pruneInfo_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, float, cusparseMatDescr_t const, double const *, int const *, int const *, pruneInfo_t, size_t *))dlsym(RTLD_NEXT, "cusparseDpruneCsr2csrByPercentage_bufferSizeExt");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneCsr2csrByPercentage_bufferSizeExt", kApiTypeCuSolver);

    lretval = lcusparseDpruneCsr2csrByPercentage_bufferSizeExt(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBufferSizeInBytes);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneCsr2csrByPercentage_bufferSizeExt cusparseDpruneCsr2csrByPercentage_bufferSizeExt


#undef cusparseHpruneCsr2csrNnzByPercentage
cusparseStatus_t cusparseHpruneCsr2csrNnzByPercentage(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, __half const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float percentage, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * nnzTotalDevHostPtr, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneCsr2csrNnzByPercentage) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseHpruneCsr2csrNnzByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneCsr2csrNnzByPercentage", kApiTypeCuSolver);

    lretval = lcusparseHpruneCsr2csrNnzByPercentage(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, percentage, descrC, csrSortedRowPtrC, nnzTotalDevHostPtr, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneCsr2csrNnzByPercentage cusparseHpruneCsr2csrNnzByPercentage


#undef cusparseSpruneCsr2csrNnzByPercentage
cusparseStatus_t cusparseSpruneCsr2csrNnzByPercentage(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float percentage, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * nnzTotalDevHostPtr, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneCsr2csrNnzByPercentage) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseSpruneCsr2csrNnzByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneCsr2csrNnzByPercentage", kApiTypeCuSolver);

    lretval = lcusparseSpruneCsr2csrNnzByPercentage(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, percentage, descrC, csrSortedRowPtrC, nnzTotalDevHostPtr, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneCsr2csrNnzByPercentage cusparseSpruneCsr2csrNnzByPercentage


#undef cusparseDpruneCsr2csrNnzByPercentage
cusparseStatus_t cusparseDpruneCsr2csrNnzByPercentage(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float percentage, cusparseMatDescr_t const descrC, int * csrSortedRowPtrC, int * nnzTotalDevHostPtr, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneCsr2csrNnzByPercentage) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, float, cusparseMatDescr_t const, int *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseDpruneCsr2csrNnzByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneCsr2csrNnzByPercentage", kApiTypeCuSolver);

    lretval = lcusparseDpruneCsr2csrNnzByPercentage(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, percentage, descrC, csrSortedRowPtrC, nnzTotalDevHostPtr, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneCsr2csrNnzByPercentage cusparseDpruneCsr2csrNnzByPercentage


#undef cusparseHpruneCsr2csrByPercentage
cusparseStatus_t cusparseHpruneCsr2csrByPercentage(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, __half const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float percentage, cusparseMatDescr_t const descrC, __half * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseHpruneCsr2csrByPercentage) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, float, cusparseMatDescr_t const, __half *, int const *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, __half const *, int const *, int const *, float, cusparseMatDescr_t const, __half *, int const *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseHpruneCsr2csrByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseHpruneCsr2csrByPercentage", kApiTypeCuSolver);

    lretval = lcusparseHpruneCsr2csrByPercentage(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseHpruneCsr2csrByPercentage cusparseHpruneCsr2csrByPercentage


#undef cusparseSpruneCsr2csrByPercentage
cusparseStatus_t cusparseSpruneCsr2csrByPercentage(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, float const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float percentage, cusparseMatDescr_t const descrC, float * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpruneCsr2csrByPercentage) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, cusparseMatDescr_t const, float *, int const *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, float const *, int const *, int const *, float, cusparseMatDescr_t const, float *, int const *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseSpruneCsr2csrByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpruneCsr2csrByPercentage", kApiTypeCuSolver);

    lretval = lcusparseSpruneCsr2csrByPercentage(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpruneCsr2csrByPercentage cusparseSpruneCsr2csrByPercentage


#undef cusparseDpruneCsr2csrByPercentage
cusparseStatus_t cusparseDpruneCsr2csrByPercentage(cusparseHandle_t handle, int m, int n, int nnzA, cusparseMatDescr_t const descrA, double const * csrSortedValA, int const * csrSortedRowPtrA, int const * csrSortedColIndA, float percentage, cusparseMatDescr_t const descrC, double * csrSortedValC, int const * csrSortedRowPtrC, int * csrSortedColIndC, pruneInfo_t info, void * pBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDpruneCsr2csrByPercentage) (cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, float, cusparseMatDescr_t const, double *, int const *, int *, pruneInfo_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, cusparseMatDescr_t const, double const *, int const *, int const *, float, cusparseMatDescr_t const, double *, int const *, int *, pruneInfo_t, void *))dlsym(RTLD_NEXT, "cusparseDpruneCsr2csrByPercentage");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDpruneCsr2csrByPercentage", kApiTypeCuSolver);

    lretval = lcusparseDpruneCsr2csrByPercentage(handle, m, n, nnzA, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, percentage, descrC, csrSortedValC, csrSortedRowPtrC, csrSortedColIndC, info, pBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDpruneCsr2csrByPercentage cusparseDpruneCsr2csrByPercentage


#undef cusparseCsr2cscEx2
cusparseStatus_t cusparseCsr2cscEx2(cusparseHandle_t handle, int m, int n, int nnz, void const * csrVal, int const * csrRowPtr, int const * csrColInd, void * cscVal, int * cscColPtr, int * cscRowInd, cudaDataType valType, cusparseAction_t copyValues, cusparseIndexBase_t idxBase, cusparseCsr2CscAlg_t alg, void * buffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCsr2cscEx2) (cusparseHandle_t, int, int, int, void const *, int const *, int const *, void *, int *, int *, cudaDataType, cusparseAction_t, cusparseIndexBase_t, cusparseCsr2CscAlg_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, void const *, int const *, int const *, void *, int *, int *, cudaDataType, cusparseAction_t, cusparseIndexBase_t, cusparseCsr2CscAlg_t, void *))dlsym(RTLD_NEXT, "cusparseCsr2cscEx2");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCsr2cscEx2", kApiTypeCuSolver);

    lretval = lcusparseCsr2cscEx2(handle, m, n, nnz, csrVal, csrRowPtr, csrColInd, cscVal, cscColPtr, cscRowInd, valType, copyValues, idxBase, alg, buffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCsr2cscEx2 cusparseCsr2cscEx2


#undef cusparseCsr2cscEx2_bufferSize
cusparseStatus_t cusparseCsr2cscEx2_bufferSize(cusparseHandle_t handle, int m, int n, int nnz, void const * csrVal, int const * csrRowPtr, int const * csrColInd, void * cscVal, int * cscColPtr, int * cscRowInd, cudaDataType valType, cusparseAction_t copyValues, cusparseIndexBase_t idxBase, cusparseCsr2CscAlg_t alg, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCsr2cscEx2_bufferSize) (cusparseHandle_t, int, int, int, void const *, int const *, int const *, void *, int *, int *, cudaDataType, cusparseAction_t, cusparseIndexBase_t, cusparseCsr2CscAlg_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, int, int, int, void const *, int const *, int const *, void *, int *, int *, cudaDataType, cusparseAction_t, cusparseIndexBase_t, cusparseCsr2CscAlg_t, size_t *))dlsym(RTLD_NEXT, "cusparseCsr2cscEx2_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCsr2cscEx2_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseCsr2cscEx2_bufferSize(handle, m, n, nnz, csrVal, csrRowPtr, csrColInd, cscVal, cscColPtr, cscRowInd, valType, copyValues, idxBase, alg, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCsr2cscEx2_bufferSize cusparseCsr2cscEx2_bufferSize


#undef cusparseCreateSpVec
cusparseStatus_t cusparseCreateSpVec(cusparseSpVecDescr_t * spVecDescr, int64_t size, int64_t nnz, void * indices, void * values, cusparseIndexType_t idxType, cusparseIndexBase_t idxBase, cudaDataType valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateSpVec) (cusparseSpVecDescr_t *, int64_t, int64_t, void *, void *, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType) = (cusparseStatus_t (*)(cusparseSpVecDescr_t *, int64_t, int64_t, void *, void *, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType))dlsym(RTLD_NEXT, "cusparseCreateSpVec");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateSpVec", kApiTypeCuSolver);

    lretval = lcusparseCreateSpVec(spVecDescr, size, nnz, indices, values, idxType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateSpVec cusparseCreateSpVec


#undef cusparseDestroySpVec
cusparseStatus_t cusparseDestroySpVec(cusparseSpVecDescr_t spVecDescr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroySpVec) (cusparseSpVecDescr_t) = (cusparseStatus_t (*)(cusparseSpVecDescr_t))dlsym(RTLD_NEXT, "cusparseDestroySpVec");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroySpVec", kApiTypeCuSolver);

    lretval = lcusparseDestroySpVec(spVecDescr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroySpVec cusparseDestroySpVec


#undef cusparseSpVecGet
cusparseStatus_t cusparseSpVecGet(cusparseSpVecDescr_t spVecDescr, int64_t * size, int64_t * nnz, void * * indices, void * * values, cusparseIndexType_t * idxType, cusparseIndexBase_t * idxBase, cudaDataType * valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpVecGet) (cusparseSpVecDescr_t, int64_t *, int64_t *, void * *, void * *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *) = (cusparseStatus_t (*)(cusparseSpVecDescr_t, int64_t *, int64_t *, void * *, void * *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *))dlsym(RTLD_NEXT, "cusparseSpVecGet");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpVecGet", kApiTypeCuSolver);

    lretval = lcusparseSpVecGet(spVecDescr, size, nnz, indices, values, idxType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpVecGet cusparseSpVecGet


#undef cusparseSpVecGetIndexBase
cusparseStatus_t cusparseSpVecGetIndexBase(cusparseSpVecDescr_t spVecDescr, cusparseIndexBase_t * idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpVecGetIndexBase) (cusparseSpVecDescr_t, cusparseIndexBase_t *) = (cusparseStatus_t (*)(cusparseSpVecDescr_t, cusparseIndexBase_t *))dlsym(RTLD_NEXT, "cusparseSpVecGetIndexBase");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpVecGetIndexBase", kApiTypeCuSolver);

    lretval = lcusparseSpVecGetIndexBase(spVecDescr, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpVecGetIndexBase cusparseSpVecGetIndexBase


#undef cusparseSpVecGetValues
cusparseStatus_t cusparseSpVecGetValues(cusparseSpVecDescr_t spVecDescr, void * * values){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpVecGetValues) (cusparseSpVecDescr_t, void * *) = (cusparseStatus_t (*)(cusparseSpVecDescr_t, void * *))dlsym(RTLD_NEXT, "cusparseSpVecGetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpVecGetValues", kApiTypeCuSolver);

    lretval = lcusparseSpVecGetValues(spVecDescr, values);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpVecGetValues cusparseSpVecGetValues


#undef cusparseSpVecSetValues
cusparseStatus_t cusparseSpVecSetValues(cusparseSpVecDescr_t spVecDescr, void * values){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpVecSetValues) (cusparseSpVecDescr_t, void *) = (cusparseStatus_t (*)(cusparseSpVecDescr_t, void *))dlsym(RTLD_NEXT, "cusparseSpVecSetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpVecSetValues", kApiTypeCuSolver);

    lretval = lcusparseSpVecSetValues(spVecDescr, values);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpVecSetValues cusparseSpVecSetValues


#undef cusparseCreateDnVec
cusparseStatus_t cusparseCreateDnVec(cusparseDnVecDescr_t * dnVecDescr, int64_t size, void * values, cudaDataType valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateDnVec) (cusparseDnVecDescr_t *, int64_t, void *, cudaDataType) = (cusparseStatus_t (*)(cusparseDnVecDescr_t *, int64_t, void *, cudaDataType))dlsym(RTLD_NEXT, "cusparseCreateDnVec");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateDnVec", kApiTypeCuSolver);

    lretval = lcusparseCreateDnVec(dnVecDescr, size, values, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateDnVec cusparseCreateDnVec


#undef cusparseDestroyDnVec
cusparseStatus_t cusparseDestroyDnVec(cusparseDnVecDescr_t dnVecDescr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyDnVec) (cusparseDnVecDescr_t) = (cusparseStatus_t (*)(cusparseDnVecDescr_t))dlsym(RTLD_NEXT, "cusparseDestroyDnVec");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyDnVec", kApiTypeCuSolver);

    lretval = lcusparseDestroyDnVec(dnVecDescr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyDnVec cusparseDestroyDnVec


#undef cusparseDnVecGet
cusparseStatus_t cusparseDnVecGet(cusparseDnVecDescr_t dnVecDescr, int64_t * size, void * * values, cudaDataType * valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnVecGet) (cusparseDnVecDescr_t, int64_t *, void * *, cudaDataType *) = (cusparseStatus_t (*)(cusparseDnVecDescr_t, int64_t *, void * *, cudaDataType *))dlsym(RTLD_NEXT, "cusparseDnVecGet");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnVecGet", kApiTypeCuSolver);

    lretval = lcusparseDnVecGet(dnVecDescr, size, values, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnVecGet cusparseDnVecGet


#undef cusparseDnVecGetValues
cusparseStatus_t cusparseDnVecGetValues(cusparseDnVecDescr_t dnVecDescr, void * * values){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnVecGetValues) (cusparseDnVecDescr_t, void * *) = (cusparseStatus_t (*)(cusparseDnVecDescr_t, void * *))dlsym(RTLD_NEXT, "cusparseDnVecGetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnVecGetValues", kApiTypeCuSolver);

    lretval = lcusparseDnVecGetValues(dnVecDescr, values);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnVecGetValues cusparseDnVecGetValues


#undef cusparseDnVecSetValues
cusparseStatus_t cusparseDnVecSetValues(cusparseDnVecDescr_t dnVecDescr, void * values){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnVecSetValues) (cusparseDnVecDescr_t, void *) = (cusparseStatus_t (*)(cusparseDnVecDescr_t, void *))dlsym(RTLD_NEXT, "cusparseDnVecSetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnVecSetValues", kApiTypeCuSolver);

    lretval = lcusparseDnVecSetValues(dnVecDescr, values);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnVecSetValues cusparseDnVecSetValues


#undef cusparseDestroySpMat
cusparseStatus_t cusparseDestroySpMat(cusparseSpMatDescr_t spMatDescr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroySpMat) (cusparseSpMatDescr_t) = (cusparseStatus_t (*)(cusparseSpMatDescr_t))dlsym(RTLD_NEXT, "cusparseDestroySpMat");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroySpMat", kApiTypeCuSolver);

    lretval = lcusparseDestroySpMat(spMatDescr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroySpMat cusparseDestroySpMat


#undef cusparseSpMatGetFormat
cusparseStatus_t cusparseSpMatGetFormat(cusparseSpMatDescr_t spMatDescr, cusparseFormat_t * format){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMatGetFormat) (cusparseSpMatDescr_t, cusparseFormat_t *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, cusparseFormat_t *))dlsym(RTLD_NEXT, "cusparseSpMatGetFormat");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMatGetFormat", kApiTypeCuSolver);

    lretval = lcusparseSpMatGetFormat(spMatDescr, format);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMatGetFormat cusparseSpMatGetFormat


#undef cusparseSpMatGetIndexBase
cusparseStatus_t cusparseSpMatGetIndexBase(cusparseSpMatDescr_t spMatDescr, cusparseIndexBase_t * idxBase){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMatGetIndexBase) (cusparseSpMatDescr_t, cusparseIndexBase_t *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, cusparseIndexBase_t *))dlsym(RTLD_NEXT, "cusparseSpMatGetIndexBase");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMatGetIndexBase", kApiTypeCuSolver);

    lretval = lcusparseSpMatGetIndexBase(spMatDescr, idxBase);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMatGetIndexBase cusparseSpMatGetIndexBase


#undef cusparseSpMatGetValues
cusparseStatus_t cusparseSpMatGetValues(cusparseSpMatDescr_t spMatDescr, void * * values){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMatGetValues) (cusparseSpMatDescr_t, void * *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, void * *))dlsym(RTLD_NEXT, "cusparseSpMatGetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMatGetValues", kApiTypeCuSolver);

    lretval = lcusparseSpMatGetValues(spMatDescr, values);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMatGetValues cusparseSpMatGetValues


#undef cusparseSpMatSetValues
cusparseStatus_t cusparseSpMatSetValues(cusparseSpMatDescr_t spMatDescr, void * values){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMatSetValues) (cusparseSpMatDescr_t, void *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, void *))dlsym(RTLD_NEXT, "cusparseSpMatSetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMatSetValues", kApiTypeCuSolver);

    lretval = lcusparseSpMatSetValues(spMatDescr, values);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMatSetValues cusparseSpMatSetValues


#undef cusparseSpMatGetSize
cusparseStatus_t cusparseSpMatGetSize(cusparseSpMatDescr_t spMatDescr, int64_t * rows, int64_t * cols, int64_t * nnz){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMatGetSize) (cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *))dlsym(RTLD_NEXT, "cusparseSpMatGetSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMatGetSize", kApiTypeCuSolver);

    lretval = lcusparseSpMatGetSize(spMatDescr, rows, cols, nnz);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMatGetSize cusparseSpMatGetSize


#undef cusparseSpMatSetStridedBatch
cusparseStatus_t cusparseSpMatSetStridedBatch(cusparseSpMatDescr_t spMatDescr, int batchCount){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMatSetStridedBatch) (cusparseSpMatDescr_t, int) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, int))dlsym(RTLD_NEXT, "cusparseSpMatSetStridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMatSetStridedBatch", kApiTypeCuSolver);

    lretval = lcusparseSpMatSetStridedBatch(spMatDescr, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMatSetStridedBatch cusparseSpMatSetStridedBatch


#undef cusparseSpMatGetStridedBatch
cusparseStatus_t cusparseSpMatGetStridedBatch(cusparseSpMatDescr_t spMatDescr, int * batchCount){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMatGetStridedBatch) (cusparseSpMatDescr_t, int *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, int *))dlsym(RTLD_NEXT, "cusparseSpMatGetStridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMatGetStridedBatch", kApiTypeCuSolver);

    lretval = lcusparseSpMatGetStridedBatch(spMatDescr, batchCount);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMatGetStridedBatch cusparseSpMatGetStridedBatch


#undef cusparseCooSetStridedBatch
cusparseStatus_t cusparseCooSetStridedBatch(cusparseSpMatDescr_t spMatDescr, int batchCount, int64_t batchStride){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCooSetStridedBatch) (cusparseSpMatDescr_t, int, int64_t) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, int, int64_t))dlsym(RTLD_NEXT, "cusparseCooSetStridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCooSetStridedBatch", kApiTypeCuSolver);

    lretval = lcusparseCooSetStridedBatch(spMatDescr, batchCount, batchStride);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCooSetStridedBatch cusparseCooSetStridedBatch


#undef cusparseCsrSetStridedBatch
cusparseStatus_t cusparseCsrSetStridedBatch(cusparseSpMatDescr_t spMatDescr, int batchCount, int64_t offsetsBatchStride, int64_t columnsValuesBatchStride){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCsrSetStridedBatch) (cusparseSpMatDescr_t, int, int64_t, int64_t) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, int, int64_t, int64_t))dlsym(RTLD_NEXT, "cusparseCsrSetStridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCsrSetStridedBatch", kApiTypeCuSolver);

    lretval = lcusparseCsrSetStridedBatch(spMatDescr, batchCount, offsetsBatchStride, columnsValuesBatchStride);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCsrSetStridedBatch cusparseCsrSetStridedBatch


#undef cusparseSpMatGetAttribute
cusparseStatus_t cusparseSpMatGetAttribute(cusparseSpMatDescr_t spMatDescr, cusparseSpMatAttribute_t attribute, void * data, size_t dataSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMatGetAttribute) (cusparseSpMatDescr_t, cusparseSpMatAttribute_t, void *, size_t) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, cusparseSpMatAttribute_t, void *, size_t))dlsym(RTLD_NEXT, "cusparseSpMatGetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMatGetAttribute", kApiTypeCuSolver);

    lretval = lcusparseSpMatGetAttribute(spMatDescr, attribute, data, dataSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMatGetAttribute cusparseSpMatGetAttribute


#undef cusparseSpMatSetAttribute
cusparseStatus_t cusparseSpMatSetAttribute(cusparseSpMatDescr_t spMatDescr, cusparseSpMatAttribute_t attribute, void * data, size_t dataSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMatSetAttribute) (cusparseSpMatDescr_t, cusparseSpMatAttribute_t, void *, size_t) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, cusparseSpMatAttribute_t, void *, size_t))dlsym(RTLD_NEXT, "cusparseSpMatSetAttribute");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMatSetAttribute", kApiTypeCuSolver);

    lretval = lcusparseSpMatSetAttribute(spMatDescr, attribute, data, dataSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMatSetAttribute cusparseSpMatSetAttribute


#undef cusparseCreateCsr
cusparseStatus_t cusparseCreateCsr(cusparseSpMatDescr_t * spMatDescr, int64_t rows, int64_t cols, int64_t nnz, void * csrRowOffsets, void * csrColInd, void * csrValues, cusparseIndexType_t csrRowOffsetsType, cusparseIndexType_t csrColIndType, cusparseIndexBase_t idxBase, cudaDataType valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCsr) (cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, void *, void *, void *, cusparseIndexType_t, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType) = (cusparseStatus_t (*)(cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, void *, void *, void *, cusparseIndexType_t, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType))dlsym(RTLD_NEXT, "cusparseCreateCsr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCsr", kApiTypeCuSolver);

    lretval = lcusparseCreateCsr(spMatDescr, rows, cols, nnz, csrRowOffsets, csrColInd, csrValues, csrRowOffsetsType, csrColIndType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCsr cusparseCreateCsr


#undef cusparseCreateCsc
cusparseStatus_t cusparseCreateCsc(cusparseSpMatDescr_t * spMatDescr, int64_t rows, int64_t cols, int64_t nnz, void * cscColOffsets, void * cscRowInd, void * cscValues, cusparseIndexType_t cscColOffsetsType, cusparseIndexType_t cscRowIndType, cusparseIndexBase_t idxBase, cudaDataType valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCsc) (cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, void *, void *, void *, cusparseIndexType_t, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType) = (cusparseStatus_t (*)(cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, void *, void *, void *, cusparseIndexType_t, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType))dlsym(RTLD_NEXT, "cusparseCreateCsc");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCsc", kApiTypeCuSolver);

    lretval = lcusparseCreateCsc(spMatDescr, rows, cols, nnz, cscColOffsets, cscRowInd, cscValues, cscColOffsetsType, cscRowIndType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCsc cusparseCreateCsc


#undef cusparseCsrGet
cusparseStatus_t cusparseCsrGet(cusparseSpMatDescr_t spMatDescr, int64_t * rows, int64_t * cols, int64_t * nnz, void * * csrRowOffsets, void * * csrColInd, void * * csrValues, cusparseIndexType_t * csrRowOffsetsType, cusparseIndexType_t * csrColIndType, cusparseIndexBase_t * idxBase, cudaDataType * valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCsrGet) (cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *, void * *, void * *, void * *, cusparseIndexType_t *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *, void * *, void * *, void * *, cusparseIndexType_t *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *))dlsym(RTLD_NEXT, "cusparseCsrGet");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCsrGet", kApiTypeCuSolver);

    lretval = lcusparseCsrGet(spMatDescr, rows, cols, nnz, csrRowOffsets, csrColInd, csrValues, csrRowOffsetsType, csrColIndType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCsrGet cusparseCsrGet


#undef cusparseCsrSetPointers
cusparseStatus_t cusparseCsrSetPointers(cusparseSpMatDescr_t spMatDescr, void * csrRowOffsets, void * csrColInd, void * csrValues){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCsrSetPointers) (cusparseSpMatDescr_t, void *, void *, void *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, void *, void *, void *))dlsym(RTLD_NEXT, "cusparseCsrSetPointers");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCsrSetPointers", kApiTypeCuSolver);

    lretval = lcusparseCsrSetPointers(spMatDescr, csrRowOffsets, csrColInd, csrValues);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCsrSetPointers cusparseCsrSetPointers


#undef cusparseCscSetPointers
cusparseStatus_t cusparseCscSetPointers(cusparseSpMatDescr_t spMatDescr, void * cscColOffsets, void * cscRowInd, void * cscValues){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCscSetPointers) (cusparseSpMatDescr_t, void *, void *, void *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, void *, void *, void *))dlsym(RTLD_NEXT, "cusparseCscSetPointers");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCscSetPointers", kApiTypeCuSolver);

    lretval = lcusparseCscSetPointers(spMatDescr, cscColOffsets, cscRowInd, cscValues);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCscSetPointers cusparseCscSetPointers


#undef cusparseCreateCoo
cusparseStatus_t cusparseCreateCoo(cusparseSpMatDescr_t * spMatDescr, int64_t rows, int64_t cols, int64_t nnz, void * cooRowInd, void * cooColInd, void * cooValues, cusparseIndexType_t cooIdxType, cusparseIndexBase_t idxBase, cudaDataType valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCoo) (cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, void *, void *, void *, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType) = (cusparseStatus_t (*)(cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, void *, void *, void *, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType))dlsym(RTLD_NEXT, "cusparseCreateCoo");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCoo", kApiTypeCuSolver);

    lretval = lcusparseCreateCoo(spMatDescr, rows, cols, nnz, cooRowInd, cooColInd, cooValues, cooIdxType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCoo cusparseCreateCoo


#undef cusparseCreateCooAoS
cusparseStatus_t cusparseCreateCooAoS(cusparseSpMatDescr_t * spMatDescr, int64_t rows, int64_t cols, int64_t nnz, void * cooInd, void * cooValues, cusparseIndexType_t cooIdxType, cusparseIndexBase_t idxBase, cudaDataType valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateCooAoS) (cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, void *, void *, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType) = (cusparseStatus_t (*)(cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, void *, void *, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType))dlsym(RTLD_NEXT, "cusparseCreateCooAoS");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateCooAoS", kApiTypeCuSolver);

    lretval = lcusparseCreateCooAoS(spMatDescr, rows, cols, nnz, cooInd, cooValues, cooIdxType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateCooAoS cusparseCreateCooAoS


#undef cusparseCooGet
cusparseStatus_t cusparseCooGet(cusparseSpMatDescr_t spMatDescr, int64_t * rows, int64_t * cols, int64_t * nnz, void * * cooRowInd, void * * cooColInd, void * * cooValues, cusparseIndexType_t * idxType, cusparseIndexBase_t * idxBase, cudaDataType * valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCooGet) (cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *, void * *, void * *, void * *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *, void * *, void * *, void * *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *))dlsym(RTLD_NEXT, "cusparseCooGet");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCooGet", kApiTypeCuSolver);

    lretval = lcusparseCooGet(spMatDescr, rows, cols, nnz, cooRowInd, cooColInd, cooValues, idxType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCooGet cusparseCooGet


#undef cusparseCooAoSGet
cusparseStatus_t cusparseCooAoSGet(cusparseSpMatDescr_t spMatDescr, int64_t * rows, int64_t * cols, int64_t * nnz, void * * cooInd, void * * cooValues, cusparseIndexType_t * idxType, cusparseIndexBase_t * idxBase, cudaDataType * valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCooAoSGet) (cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *, void * *, void * *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *, void * *, void * *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *))dlsym(RTLD_NEXT, "cusparseCooAoSGet");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCooAoSGet", kApiTypeCuSolver);

    lretval = lcusparseCooAoSGet(spMatDescr, rows, cols, nnz, cooInd, cooValues, idxType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCooAoSGet cusparseCooAoSGet


#undef cusparseCooSetPointers
cusparseStatus_t cusparseCooSetPointers(cusparseSpMatDescr_t spMatDescr, void * cooRows, void * cooColumns, void * cooValues){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCooSetPointers) (cusparseSpMatDescr_t, void *, void *, void *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, void *, void *, void *))dlsym(RTLD_NEXT, "cusparseCooSetPointers");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCooSetPointers", kApiTypeCuSolver);

    lretval = lcusparseCooSetPointers(spMatDescr, cooRows, cooColumns, cooValues);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCooSetPointers cusparseCooSetPointers


#undef cusparseCreateBlockedEll
cusparseStatus_t cusparseCreateBlockedEll(cusparseSpMatDescr_t * spMatDescr, int64_t rows, int64_t cols, int64_t ellBlockSize, int64_t ellCols, void * ellColInd, void * ellValue, cusparseIndexType_t ellIdxType, cusparseIndexBase_t idxBase, cudaDataType valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateBlockedEll) (cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, int64_t, void *, void *, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType) = (cusparseStatus_t (*)(cusparseSpMatDescr_t *, int64_t, int64_t, int64_t, int64_t, void *, void *, cusparseIndexType_t, cusparseIndexBase_t, cudaDataType))dlsym(RTLD_NEXT, "cusparseCreateBlockedEll");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateBlockedEll", kApiTypeCuSolver);

    lretval = lcusparseCreateBlockedEll(spMatDescr, rows, cols, ellBlockSize, ellCols, ellColInd, ellValue, ellIdxType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateBlockedEll cusparseCreateBlockedEll


#undef cusparseBlockedEllGet
cusparseStatus_t cusparseBlockedEllGet(cusparseSpMatDescr_t spMatDescr, int64_t * rows, int64_t * cols, int64_t * ellBlockSize, int64_t * ellCols, void * * ellColInd, void * * ellValue, cusparseIndexType_t * ellIdxType, cusparseIndexBase_t * idxBase, cudaDataType * valueType){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseBlockedEllGet) (cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *, int64_t *, void * *, void * *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *) = (cusparseStatus_t (*)(cusparseSpMatDescr_t, int64_t *, int64_t *, int64_t *, int64_t *, void * *, void * *, cusparseIndexType_t *, cusparseIndexBase_t *, cudaDataType *))dlsym(RTLD_NEXT, "cusparseBlockedEllGet");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseBlockedEllGet", kApiTypeCuSolver);

    lretval = lcusparseBlockedEllGet(spMatDescr, rows, cols, ellBlockSize, ellCols, ellColInd, ellValue, ellIdxType, idxBase, valueType);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseBlockedEllGet cusparseBlockedEllGet


#undef cusparseCreateDnMat
cusparseStatus_t cusparseCreateDnMat(cusparseDnMatDescr_t * dnMatDescr, int64_t rows, int64_t cols, int64_t ld, void * values, cudaDataType valueType, cusparseOrder_t order){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseCreateDnMat) (cusparseDnMatDescr_t *, int64_t, int64_t, int64_t, void *, cudaDataType, cusparseOrder_t) = (cusparseStatus_t (*)(cusparseDnMatDescr_t *, int64_t, int64_t, int64_t, void *, cudaDataType, cusparseOrder_t))dlsym(RTLD_NEXT, "cusparseCreateDnMat");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseCreateDnMat", kApiTypeCuSolver);

    lretval = lcusparseCreateDnMat(dnMatDescr, rows, cols, ld, values, valueType, order);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseCreateDnMat cusparseCreateDnMat


#undef cusparseDestroyDnMat
cusparseStatus_t cusparseDestroyDnMat(cusparseDnMatDescr_t dnMatDescr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDestroyDnMat) (cusparseDnMatDescr_t) = (cusparseStatus_t (*)(cusparseDnMatDescr_t))dlsym(RTLD_NEXT, "cusparseDestroyDnMat");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDestroyDnMat", kApiTypeCuSolver);

    lretval = lcusparseDestroyDnMat(dnMatDescr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDestroyDnMat cusparseDestroyDnMat


#undef cusparseDnMatGet
cusparseStatus_t cusparseDnMatGet(cusparseDnMatDescr_t dnMatDescr, int64_t * rows, int64_t * cols, int64_t * ld, void * * values, cudaDataType * type, cusparseOrder_t * order){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnMatGet) (cusparseDnMatDescr_t, int64_t *, int64_t *, int64_t *, void * *, cudaDataType *, cusparseOrder_t *) = (cusparseStatus_t (*)(cusparseDnMatDescr_t, int64_t *, int64_t *, int64_t *, void * *, cudaDataType *, cusparseOrder_t *))dlsym(RTLD_NEXT, "cusparseDnMatGet");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnMatGet", kApiTypeCuSolver);

    lretval = lcusparseDnMatGet(dnMatDescr, rows, cols, ld, values, type, order);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnMatGet cusparseDnMatGet


#undef cusparseDnMatGetValues
cusparseStatus_t cusparseDnMatGetValues(cusparseDnMatDescr_t dnMatDescr, void * * values){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnMatGetValues) (cusparseDnMatDescr_t, void * *) = (cusparseStatus_t (*)(cusparseDnMatDescr_t, void * *))dlsym(RTLD_NEXT, "cusparseDnMatGetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnMatGetValues", kApiTypeCuSolver);

    lretval = lcusparseDnMatGetValues(dnMatDescr, values);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnMatGetValues cusparseDnMatGetValues


#undef cusparseDnMatSetValues
cusparseStatus_t cusparseDnMatSetValues(cusparseDnMatDescr_t dnMatDescr, void * values){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnMatSetValues) (cusparseDnMatDescr_t, void *) = (cusparseStatus_t (*)(cusparseDnMatDescr_t, void *))dlsym(RTLD_NEXT, "cusparseDnMatSetValues");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnMatSetValues", kApiTypeCuSolver);

    lretval = lcusparseDnMatSetValues(dnMatDescr, values);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnMatSetValues cusparseDnMatSetValues


#undef cusparseDnMatSetStridedBatch
cusparseStatus_t cusparseDnMatSetStridedBatch(cusparseDnMatDescr_t dnMatDescr, int batchCount, int64_t batchStride){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnMatSetStridedBatch) (cusparseDnMatDescr_t, int, int64_t) = (cusparseStatus_t (*)(cusparseDnMatDescr_t, int, int64_t))dlsym(RTLD_NEXT, "cusparseDnMatSetStridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnMatSetStridedBatch", kApiTypeCuSolver);

    lretval = lcusparseDnMatSetStridedBatch(dnMatDescr, batchCount, batchStride);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnMatSetStridedBatch cusparseDnMatSetStridedBatch


#undef cusparseDnMatGetStridedBatch
cusparseStatus_t cusparseDnMatGetStridedBatch(cusparseDnMatDescr_t dnMatDescr, int * batchCount, int64_t * batchStride){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDnMatGetStridedBatch) (cusparseDnMatDescr_t, int *, int64_t *) = (cusparseStatus_t (*)(cusparseDnMatDescr_t, int *, int64_t *))dlsym(RTLD_NEXT, "cusparseDnMatGetStridedBatch");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDnMatGetStridedBatch", kApiTypeCuSolver);

    lretval = lcusparseDnMatGetStridedBatch(dnMatDescr, batchCount, batchStride);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDnMatGetStridedBatch cusparseDnMatGetStridedBatch


#undef cusparseAxpby
cusparseStatus_t cusparseAxpby(cusparseHandle_t handle, void const * alpha, cusparseSpVecDescr_t vecX, void const * beta, cusparseDnVecDescr_t vecY){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseAxpby) (cusparseHandle_t, void const *, cusparseSpVecDescr_t, void const *, cusparseDnVecDescr_t) = (cusparseStatus_t (*)(cusparseHandle_t, void const *, cusparseSpVecDescr_t, void const *, cusparseDnVecDescr_t))dlsym(RTLD_NEXT, "cusparseAxpby");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseAxpby", kApiTypeCuSolver);

    lretval = lcusparseAxpby(handle, alpha, vecX, beta, vecY);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseAxpby cusparseAxpby


#undef cusparseGather
cusparseStatus_t cusparseGather(cusparseHandle_t handle, cusparseDnVecDescr_t vecY, cusparseSpVecDescr_t vecX){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseGather) (cusparseHandle_t, cusparseDnVecDescr_t, cusparseSpVecDescr_t) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDnVecDescr_t, cusparseSpVecDescr_t))dlsym(RTLD_NEXT, "cusparseGather");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseGather", kApiTypeCuSolver);

    lretval = lcusparseGather(handle, vecY, vecX);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseGather cusparseGather


#undef cusparseScatter
cusparseStatus_t cusparseScatter(cusparseHandle_t handle, cusparseSpVecDescr_t vecX, cusparseDnVecDescr_t vecY){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseScatter) (cusparseHandle_t, cusparseSpVecDescr_t, cusparseDnVecDescr_t) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseSpVecDescr_t, cusparseDnVecDescr_t))dlsym(RTLD_NEXT, "cusparseScatter");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseScatter", kApiTypeCuSolver);

    lretval = lcusparseScatter(handle, vecX, vecY);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseScatter cusparseScatter


#undef cusparseRot
cusparseStatus_t cusparseRot(cusparseHandle_t handle, void const * c_coeff, void const * s_coeff, cusparseSpVecDescr_t vecX, cusparseDnVecDescr_t vecY){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseRot) (cusparseHandle_t, void const *, void const *, cusparseSpVecDescr_t, cusparseDnVecDescr_t) = (cusparseStatus_t (*)(cusparseHandle_t, void const *, void const *, cusparseSpVecDescr_t, cusparseDnVecDescr_t))dlsym(RTLD_NEXT, "cusparseRot");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseRot", kApiTypeCuSolver);

    lretval = lcusparseRot(handle, c_coeff, s_coeff, vecX, vecY);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseRot cusparseRot


#undef cusparseSpVV_bufferSize
cusparseStatus_t cusparseSpVV_bufferSize(cusparseHandle_t handle, cusparseOperation_t opX, cusparseSpVecDescr_t vecX, cusparseDnVecDescr_t vecY, void const * result, cudaDataType computeType, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpVV_bufferSize) (cusparseHandle_t, cusparseOperation_t, cusparseSpVecDescr_t, cusparseDnVecDescr_t, void const *, cudaDataType, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseSpVecDescr_t, cusparseDnVecDescr_t, void const *, cudaDataType, size_t *))dlsym(RTLD_NEXT, "cusparseSpVV_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpVV_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSpVV_bufferSize(handle, opX, vecX, vecY, result, computeType, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpVV_bufferSize cusparseSpVV_bufferSize


#undef cusparseSpVV
cusparseStatus_t cusparseSpVV(cusparseHandle_t handle, cusparseOperation_t opX, cusparseSpVecDescr_t vecX, cusparseDnVecDescr_t vecY, void * result, cudaDataType computeType, void * externalBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpVV) (cusparseHandle_t, cusparseOperation_t, cusparseSpVecDescr_t, cusparseDnVecDescr_t, void *, cudaDataType, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseSpVecDescr_t, cusparseDnVecDescr_t, void *, cudaDataType, void *))dlsym(RTLD_NEXT, "cusparseSpVV");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpVV", kApiTypeCuSolver);

    lretval = lcusparseSpVV(handle, opX, vecX, vecY, result, computeType, externalBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpVV cusparseSpVV


#undef cusparseSparseToDense_bufferSize
cusparseStatus_t cusparseSparseToDense_bufferSize(cusparseHandle_t handle, cusparseSpMatDescr_t matA, cusparseDnMatDescr_t matB, cusparseSparseToDenseAlg_t alg, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSparseToDense_bufferSize) (cusparseHandle_t, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseSparseToDenseAlg_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseSparseToDenseAlg_t, size_t *))dlsym(RTLD_NEXT, "cusparseSparseToDense_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSparseToDense_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSparseToDense_bufferSize(handle, matA, matB, alg, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSparseToDense_bufferSize cusparseSparseToDense_bufferSize


#undef cusparseSparseToDense
cusparseStatus_t cusparseSparseToDense(cusparseHandle_t handle, cusparseSpMatDescr_t matA, cusparseDnMatDescr_t matB, cusparseSparseToDenseAlg_t alg, void * buffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSparseToDense) (cusparseHandle_t, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseSparseToDenseAlg_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseSparseToDenseAlg_t, void *))dlsym(RTLD_NEXT, "cusparseSparseToDense");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSparseToDense", kApiTypeCuSolver);

    lretval = lcusparseSparseToDense(handle, matA, matB, alg, buffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSparseToDense cusparseSparseToDense


#undef cusparseDenseToSparse_bufferSize
cusparseStatus_t cusparseDenseToSparse_bufferSize(cusparseHandle_t handle, cusparseDnMatDescr_t matA, cusparseSpMatDescr_t matB, cusparseDenseToSparseAlg_t alg, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDenseToSparse_bufferSize) (cusparseHandle_t, cusparseDnMatDescr_t, cusparseSpMatDescr_t, cusparseDenseToSparseAlg_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDnMatDescr_t, cusparseSpMatDescr_t, cusparseDenseToSparseAlg_t, size_t *))dlsym(RTLD_NEXT, "cusparseDenseToSparse_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDenseToSparse_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseDenseToSparse_bufferSize(handle, matA, matB, alg, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDenseToSparse_bufferSize cusparseDenseToSparse_bufferSize


#undef cusparseDenseToSparse_analysis
cusparseStatus_t cusparseDenseToSparse_analysis(cusparseHandle_t handle, cusparseDnMatDescr_t matA, cusparseSpMatDescr_t matB, cusparseDenseToSparseAlg_t alg, void * buffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDenseToSparse_analysis) (cusparseHandle_t, cusparseDnMatDescr_t, cusparseSpMatDescr_t, cusparseDenseToSparseAlg_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDnMatDescr_t, cusparseSpMatDescr_t, cusparseDenseToSparseAlg_t, void *))dlsym(RTLD_NEXT, "cusparseDenseToSparse_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDenseToSparse_analysis", kApiTypeCuSolver);

    lretval = lcusparseDenseToSparse_analysis(handle, matA, matB, alg, buffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDenseToSparse_analysis cusparseDenseToSparse_analysis


#undef cusparseDenseToSparse_convert
cusparseStatus_t cusparseDenseToSparse_convert(cusparseHandle_t handle, cusparseDnMatDescr_t matA, cusparseSpMatDescr_t matB, cusparseDenseToSparseAlg_t alg, void * buffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseDenseToSparse_convert) (cusparseHandle_t, cusparseDnMatDescr_t, cusparseSpMatDescr_t, cusparseDenseToSparseAlg_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseDnMatDescr_t, cusparseSpMatDescr_t, cusparseDenseToSparseAlg_t, void *))dlsym(RTLD_NEXT, "cusparseDenseToSparse_convert");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseDenseToSparse_convert", kApiTypeCuSolver);

    lretval = lcusparseDenseToSparse_convert(handle, matA, matB, alg, buffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseDenseToSparse_convert cusparseDenseToSparse_convert


#undef cusparseSpMV
cusparseStatus_t cusparseSpMV(cusparseHandle_t handle, cusparseOperation_t opA, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnVecDescr_t vecX, void const * beta, cusparseDnVecDescr_t vecY, cudaDataType computeType, cusparseSpMVAlg_t alg, void * externalBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMV) (cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, void const *, cusparseDnVecDescr_t, cudaDataType, cusparseSpMVAlg_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, void const *, cusparseDnVecDescr_t, cudaDataType, cusparseSpMVAlg_t, void *))dlsym(RTLD_NEXT, "cusparseSpMV");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMV", kApiTypeCuSolver);

    lretval = lcusparseSpMV(handle, opA, alpha, matA, vecX, beta, vecY, computeType, alg, externalBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMV cusparseSpMV


#undef cusparseSpMV_bufferSize
cusparseStatus_t cusparseSpMV_bufferSize(cusparseHandle_t handle, cusparseOperation_t opA, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnVecDescr_t vecX, void const * beta, cusparseDnVecDescr_t vecY, cudaDataType computeType, cusparseSpMVAlg_t alg, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMV_bufferSize) (cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, void const *, cusparseDnVecDescr_t, cudaDataType, cusparseSpMVAlg_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, void const *, cusparseDnVecDescr_t, cudaDataType, cusparseSpMVAlg_t, size_t *))dlsym(RTLD_NEXT, "cusparseSpMV_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMV_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSpMV_bufferSize(handle, opA, alpha, matA, vecX, beta, vecY, computeType, alg, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMV_bufferSize cusparseSpMV_bufferSize


#undef cusparseSpSV_createDescr
cusparseStatus_t cusparseSpSV_createDescr(cusparseSpSVDescr_t * descr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSV_createDescr) (cusparseSpSVDescr_t *) = (cusparseStatus_t (*)(cusparseSpSVDescr_t *))dlsym(RTLD_NEXT, "cusparseSpSV_createDescr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSV_createDescr", kApiTypeCuSolver);

    lretval = lcusparseSpSV_createDescr(descr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSV_createDescr cusparseSpSV_createDescr


#undef cusparseSpSV_destroyDescr
cusparseStatus_t cusparseSpSV_destroyDescr(cusparseSpSVDescr_t descr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSV_destroyDescr) (cusparseSpSVDescr_t) = (cusparseStatus_t (*)(cusparseSpSVDescr_t))dlsym(RTLD_NEXT, "cusparseSpSV_destroyDescr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSV_destroyDescr", kApiTypeCuSolver);

    lretval = lcusparseSpSV_destroyDescr(descr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSV_destroyDescr cusparseSpSV_destroyDescr


#undef cusparseSpSV_bufferSize
cusparseStatus_t cusparseSpSV_bufferSize(cusparseHandle_t handle, cusparseOperation_t opA, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnVecDescr_t vecX, cusparseDnVecDescr_t vecY, cudaDataType computeType, cusparseSpSVAlg_t alg, cusparseSpSVDescr_t spsvDescr, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSV_bufferSize) (cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, cusparseDnVecDescr_t, cudaDataType, cusparseSpSVAlg_t, cusparseSpSVDescr_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, cusparseDnVecDescr_t, cudaDataType, cusparseSpSVAlg_t, cusparseSpSVDescr_t, size_t *))dlsym(RTLD_NEXT, "cusparseSpSV_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSV_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSpSV_bufferSize(handle, opA, alpha, matA, vecX, vecY, computeType, alg, spsvDescr, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSV_bufferSize cusparseSpSV_bufferSize


#undef cusparseSpSV_analysis
cusparseStatus_t cusparseSpSV_analysis(cusparseHandle_t handle, cusparseOperation_t opA, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnVecDescr_t vecX, cusparseDnVecDescr_t vecY, cudaDataType computeType, cusparseSpSVAlg_t alg, cusparseSpSVDescr_t spsvDescr, void * externalBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSV_analysis) (cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, cusparseDnVecDescr_t, cudaDataType, cusparseSpSVAlg_t, cusparseSpSVDescr_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, cusparseDnVecDescr_t, cudaDataType, cusparseSpSVAlg_t, cusparseSpSVDescr_t, void *))dlsym(RTLD_NEXT, "cusparseSpSV_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSV_analysis", kApiTypeCuSolver);

    lretval = lcusparseSpSV_analysis(handle, opA, alpha, matA, vecX, vecY, computeType, alg, spsvDescr, externalBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSV_analysis cusparseSpSV_analysis


#undef cusparseSpSV_solve
cusparseStatus_t cusparseSpSV_solve(cusparseHandle_t handle, cusparseOperation_t opA, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnVecDescr_t vecX, cusparseDnVecDescr_t vecY, cudaDataType computeType, cusparseSpSVAlg_t alg, cusparseSpSVDescr_t spsvDescr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSV_solve) (cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, cusparseDnVecDescr_t, cudaDataType, cusparseSpSVAlg_t, cusparseSpSVDescr_t) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnVecDescr_t, cusparseDnVecDescr_t, cudaDataType, cusparseSpSVAlg_t, cusparseSpSVDescr_t))dlsym(RTLD_NEXT, "cusparseSpSV_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSV_solve", kApiTypeCuSolver);

    lretval = lcusparseSpSV_solve(handle, opA, alpha, matA, vecX, vecY, computeType, alg, spsvDescr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSV_solve cusparseSpSV_solve


#undef cusparseSpSM_createDescr
cusparseStatus_t cusparseSpSM_createDescr(cusparseSpSMDescr_t * descr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSM_createDescr) (cusparseSpSMDescr_t *) = (cusparseStatus_t (*)(cusparseSpSMDescr_t *))dlsym(RTLD_NEXT, "cusparseSpSM_createDescr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSM_createDescr", kApiTypeCuSolver);

    lretval = lcusparseSpSM_createDescr(descr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSM_createDescr cusparseSpSM_createDescr


#undef cusparseSpSM_destroyDescr
cusparseStatus_t cusparseSpSM_destroyDescr(cusparseSpSMDescr_t descr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSM_destroyDescr) (cusparseSpSMDescr_t) = (cusparseStatus_t (*)(cusparseSpSMDescr_t))dlsym(RTLD_NEXT, "cusparseSpSM_destroyDescr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSM_destroyDescr", kApiTypeCuSolver);

    lretval = lcusparseSpSM_destroyDescr(descr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSM_destroyDescr cusparseSpSM_destroyDescr


#undef cusparseSpSM_bufferSize
cusparseStatus_t cusparseSpSM_bufferSize(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnMatDescr_t matB, cusparseDnMatDescr_t matC, cudaDataType computeType, cusparseSpSMAlg_t alg, cusparseSpSMDescr_t spsmDescr, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSM_bufferSize) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseDnMatDescr_t, cudaDataType, cusparseSpSMAlg_t, cusparseSpSMDescr_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseDnMatDescr_t, cudaDataType, cusparseSpSMAlg_t, cusparseSpSMDescr_t, size_t *))dlsym(RTLD_NEXT, "cusparseSpSM_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSM_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSpSM_bufferSize(handle, opA, opB, alpha, matA, matB, matC, computeType, alg, spsmDescr, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSM_bufferSize cusparseSpSM_bufferSize


#undef cusparseSpSM_analysis
cusparseStatus_t cusparseSpSM_analysis(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnMatDescr_t matB, cusparseDnMatDescr_t matC, cudaDataType computeType, cusparseSpSMAlg_t alg, cusparseSpSMDescr_t spsmDescr, void * externalBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSM_analysis) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseDnMatDescr_t, cudaDataType, cusparseSpSMAlg_t, cusparseSpSMDescr_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseDnMatDescr_t, cudaDataType, cusparseSpSMAlg_t, cusparseSpSMDescr_t, void *))dlsym(RTLD_NEXT, "cusparseSpSM_analysis");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSM_analysis", kApiTypeCuSolver);

    lretval = lcusparseSpSM_analysis(handle, opA, opB, alpha, matA, matB, matC, computeType, alg, spsmDescr, externalBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSM_analysis cusparseSpSM_analysis


#undef cusparseSpSM_solve
cusparseStatus_t cusparseSpSM_solve(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnMatDescr_t matB, cusparseDnMatDescr_t matC, cudaDataType computeType, cusparseSpSMAlg_t alg, cusparseSpSMDescr_t spsmDescr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpSM_solve) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseDnMatDescr_t, cudaDataType, cusparseSpSMAlg_t, cusparseSpSMDescr_t) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, cusparseDnMatDescr_t, cudaDataType, cusparseSpSMAlg_t, cusparseSpSMDescr_t))dlsym(RTLD_NEXT, "cusparseSpSM_solve");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpSM_solve", kApiTypeCuSolver);

    lretval = lcusparseSpSM_solve(handle, opA, opB, alpha, matA, matB, matC, computeType, alg, spsmDescr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpSM_solve cusparseSpSM_solve


#undef cusparseSpMM_bufferSize
cusparseStatus_t cusparseSpMM_bufferSize(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnMatDescr_t matB, void const * beta, cusparseDnMatDescr_t matC, cudaDataType computeType, cusparseSpMMAlg_t alg, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMM_bufferSize) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseDnMatDescr_t, cudaDataType, cusparseSpMMAlg_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseDnMatDescr_t, cudaDataType, cusparseSpMMAlg_t, size_t *))dlsym(RTLD_NEXT, "cusparseSpMM_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMM_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSpMM_bufferSize(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMM_bufferSize cusparseSpMM_bufferSize


#undef cusparseSpMM_preprocess
cusparseStatus_t cusparseSpMM_preprocess(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnMatDescr_t matB, void const * beta, cusparseDnMatDescr_t matC, cudaDataType computeType, cusparseSpMMAlg_t alg, void * externalBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMM_preprocess) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseDnMatDescr_t, cudaDataType, cusparseSpMMAlg_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseDnMatDescr_t, cudaDataType, cusparseSpMMAlg_t, void *))dlsym(RTLD_NEXT, "cusparseSpMM_preprocess");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMM_preprocess", kApiTypeCuSolver);

    lretval = lcusparseSpMM_preprocess(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, externalBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMM_preprocess cusparseSpMM_preprocess


#undef cusparseSpMM
cusparseStatus_t cusparseSpMM(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseDnMatDescr_t matB, void const * beta, cusparseDnMatDescr_t matC, cudaDataType computeType, cusparseSpMMAlg_t alg, void * externalBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpMM) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseDnMatDescr_t, cudaDataType, cusparseSpMMAlg_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseDnMatDescr_t, cudaDataType, cusparseSpMMAlg_t, void *))dlsym(RTLD_NEXT, "cusparseSpMM");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpMM", kApiTypeCuSolver);

    lretval = lcusparseSpMM(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, externalBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpMM cusparseSpMM


#undef cusparseSpGEMM_createDescr
cusparseStatus_t cusparseSpGEMM_createDescr(cusparseSpGEMMDescr_t * descr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpGEMM_createDescr) (cusparseSpGEMMDescr_t *) = (cusparseStatus_t (*)(cusparseSpGEMMDescr_t *))dlsym(RTLD_NEXT, "cusparseSpGEMM_createDescr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpGEMM_createDescr", kApiTypeCuSolver);

    lretval = lcusparseSpGEMM_createDescr(descr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpGEMM_createDescr cusparseSpGEMM_createDescr


#undef cusparseSpGEMM_destroyDescr
cusparseStatus_t cusparseSpGEMM_destroyDescr(cusparseSpGEMMDescr_t descr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpGEMM_destroyDescr) (cusparseSpGEMMDescr_t) = (cusparseStatus_t (*)(cusparseSpGEMMDescr_t))dlsym(RTLD_NEXT, "cusparseSpGEMM_destroyDescr");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpGEMM_destroyDescr", kApiTypeCuSolver);

    lretval = lcusparseSpGEMM_destroyDescr(descr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpGEMM_destroyDescr cusparseSpGEMM_destroyDescr


#undef cusparseSpGEMM_workEstimation
cusparseStatus_t cusparseSpGEMM_workEstimation(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseSpMatDescr_t matB, void const * beta, cusparseSpMatDescr_t matC, cudaDataType computeType, cusparseSpGEMMAlg_t alg, cusparseSpGEMMDescr_t spgemmDescr, size_t * bufferSize1, void * externalBuffer1){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpGEMM_workEstimation) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseSpMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseSpMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *))dlsym(RTLD_NEXT, "cusparseSpGEMM_workEstimation");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpGEMM_workEstimation", kApiTypeCuSolver);

    lretval = lcusparseSpGEMM_workEstimation(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, spgemmDescr, bufferSize1, externalBuffer1);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpGEMM_workEstimation cusparseSpGEMM_workEstimation


#undef cusparseSpGEMM_compute
cusparseStatus_t cusparseSpGEMM_compute(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseSpMatDescr_t matB, void const * beta, cusparseSpMatDescr_t matC, cudaDataType computeType, cusparseSpGEMMAlg_t alg, cusparseSpGEMMDescr_t spgemmDescr, size_t * bufferSize2, void * externalBuffer2){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpGEMM_compute) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseSpMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseSpMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *))dlsym(RTLD_NEXT, "cusparseSpGEMM_compute");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpGEMM_compute", kApiTypeCuSolver);

    lretval = lcusparseSpGEMM_compute(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, spgemmDescr, bufferSize2, externalBuffer2);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpGEMM_compute cusparseSpGEMM_compute


#undef cusparseSpGEMM_copy
cusparseStatus_t cusparseSpGEMM_copy(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseSpMatDescr_t matB, void const * beta, cusparseSpMatDescr_t matC, cudaDataType computeType, cusparseSpGEMMAlg_t alg, cusparseSpGEMMDescr_t spgemmDescr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpGEMM_copy) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseSpMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseSpMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t))dlsym(RTLD_NEXT, "cusparseSpGEMM_copy");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpGEMM_copy", kApiTypeCuSolver);

    lretval = lcusparseSpGEMM_copy(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, spgemmDescr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpGEMM_copy cusparseSpGEMM_copy


#undef cusparseSpGEMMreuse_workEstimation
cusparseStatus_t cusparseSpGEMMreuse_workEstimation(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, cusparseSpMatDescr_t matA, cusparseSpMatDescr_t matB, cusparseSpMatDescr_t matC, cusparseSpGEMMAlg_t alg, cusparseSpGEMMDescr_t spgemmDescr, size_t * bufferSize1, void * externalBuffer1){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpGEMMreuse_workEstimation) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *))dlsym(RTLD_NEXT, "cusparseSpGEMMreuse_workEstimation");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpGEMMreuse_workEstimation", kApiTypeCuSolver);

    lretval = lcusparseSpGEMMreuse_workEstimation(handle, opA, opB, matA, matB, matC, alg, spgemmDescr, bufferSize1, externalBuffer1);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpGEMMreuse_workEstimation cusparseSpGEMMreuse_workEstimation


#undef cusparseSpGEMMreuse_nnz
cusparseStatus_t cusparseSpGEMMreuse_nnz(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, cusparseSpMatDescr_t matA, cusparseSpMatDescr_t matB, cusparseSpMatDescr_t matC, cusparseSpGEMMAlg_t alg, cusparseSpGEMMDescr_t spgemmDescr, size_t * bufferSize2, void * externalBuffer2, size_t * bufferSize3, void * externalBuffer3, size_t * bufferSize4, void * externalBuffer4){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpGEMMreuse_nnz) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *, size_t *, void *, size_t *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *, size_t *, void *, size_t *, void *))dlsym(RTLD_NEXT, "cusparseSpGEMMreuse_nnz");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpGEMMreuse_nnz", kApiTypeCuSolver);

    lretval = lcusparseSpGEMMreuse_nnz(handle, opA, opB, matA, matB, matC, alg, spgemmDescr, bufferSize2, externalBuffer2, bufferSize3, externalBuffer3, bufferSize4, externalBuffer4);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpGEMMreuse_nnz cusparseSpGEMMreuse_nnz


#undef cusparseSpGEMMreuse_copy
cusparseStatus_t cusparseSpGEMMreuse_copy(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, cusparseSpMatDescr_t matA, cusparseSpMatDescr_t matB, cusparseSpMatDescr_t matC, cusparseSpGEMMAlg_t alg, cusparseSpGEMMDescr_t spgemmDescr, size_t * bufferSize5, void * externalBuffer5){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpGEMMreuse_copy) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpMatDescr_t, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t, size_t *, void *))dlsym(RTLD_NEXT, "cusparseSpGEMMreuse_copy");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpGEMMreuse_copy", kApiTypeCuSolver);

    lretval = lcusparseSpGEMMreuse_copy(handle, opA, opB, matA, matB, matC, alg, spgemmDescr, bufferSize5, externalBuffer5);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpGEMMreuse_copy cusparseSpGEMMreuse_copy


#undef cusparseSpGEMMreuse_compute
cusparseStatus_t cusparseSpGEMMreuse_compute(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseSpMatDescr_t matA, cusparseSpMatDescr_t matB, void const * beta, cusparseSpMatDescr_t matC, cudaDataType computeType, cusparseSpGEMMAlg_t alg, cusparseSpGEMMDescr_t spgemmDescr){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSpGEMMreuse_compute) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseSpMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseSpMatDescr_t, cusparseSpMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSpGEMMAlg_t, cusparseSpGEMMDescr_t))dlsym(RTLD_NEXT, "cusparseSpGEMMreuse_compute");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSpGEMMreuse_compute", kApiTypeCuSolver);

    lretval = lcusparseSpGEMMreuse_compute(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, spgemmDescr);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSpGEMMreuse_compute cusparseSpGEMMreuse_compute


#undef cusparseConstrainedGeMM
cusparseStatus_t cusparseConstrainedGeMM(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseDnMatDescr_t matA, cusparseDnMatDescr_t matB, void const * beta, cusparseSpMatDescr_t matC, cudaDataType computeType, void * externalBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseConstrainedGeMM) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, void *))dlsym(RTLD_NEXT, "cusparseConstrainedGeMM");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseConstrainedGeMM", kApiTypeCuSolver);

    lretval = lcusparseConstrainedGeMM(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, externalBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseConstrainedGeMM cusparseConstrainedGeMM


#undef cusparseConstrainedGeMM_bufferSize
cusparseStatus_t cusparseConstrainedGeMM_bufferSize(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseDnMatDescr_t matA, cusparseDnMatDescr_t matB, void const * beta, cusparseSpMatDescr_t matC, cudaDataType computeType, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseConstrainedGeMM_bufferSize) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, size_t *))dlsym(RTLD_NEXT, "cusparseConstrainedGeMM_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseConstrainedGeMM_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseConstrainedGeMM_bufferSize(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseConstrainedGeMM_bufferSize cusparseConstrainedGeMM_bufferSize


#undef cusparseSDDMM_bufferSize
cusparseStatus_t cusparseSDDMM_bufferSize(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseDnMatDescr_t matA, cusparseDnMatDescr_t matB, void const * beta, cusparseSpMatDescr_t matC, cudaDataType computeType, cusparseSDDMMAlg_t alg, size_t * bufferSize){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSDDMM_bufferSize) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSDDMMAlg_t, size_t *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSDDMMAlg_t, size_t *))dlsym(RTLD_NEXT, "cusparseSDDMM_bufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSDDMM_bufferSize", kApiTypeCuSolver);

    lretval = lcusparseSDDMM_bufferSize(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSDDMM_bufferSize cusparseSDDMM_bufferSize


#undef cusparseSDDMM_preprocess
cusparseStatus_t cusparseSDDMM_preprocess(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseDnMatDescr_t matA, cusparseDnMatDescr_t matB, void const * beta, cusparseSpMatDescr_t matC, cudaDataType computeType, cusparseSDDMMAlg_t alg, void * externalBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSDDMM_preprocess) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSDDMMAlg_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSDDMMAlg_t, void *))dlsym(RTLD_NEXT, "cusparseSDDMM_preprocess");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSDDMM_preprocess", kApiTypeCuSolver);

    lretval = lcusparseSDDMM_preprocess(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, externalBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSDDMM_preprocess cusparseSDDMM_preprocess


#undef cusparseSDDMM
cusparseStatus_t cusparseSDDMM(cusparseHandle_t handle, cusparseOperation_t opA, cusparseOperation_t opB, void const * alpha, cusparseDnMatDescr_t matA, cusparseDnMatDescr_t matB, void const * beta, cusparseSpMatDescr_t matC, cudaDataType computeType, cusparseSDDMMAlg_t alg, void * externalBuffer){
    cusparseStatus_t lretval;
    cusparseStatus_t (*lcusparseSDDMM) (cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSDDMMAlg_t, void *) = (cusparseStatus_t (*)(cusparseHandle_t, cusparseOperation_t, cusparseOperation_t, void const *, cusparseDnMatDescr_t, cusparseDnMatDescr_t, void const *, cusparseSpMatDescr_t, cudaDataType, cusparseSDDMMAlg_t, void *))dlsym(RTLD_NEXT, "cusparseSDDMM");
    
    /* pre exeuction logics */
    ac.add_counter("cusparseSDDMM", kApiTypeCuSolver);

    lretval = lcusparseSDDMM(handle, opA, opB, alpha, matA, matB, beta, matC, computeType, alg, externalBuffer);
    
    /* post exeuction logics */

    return lretval;
}
#define cusparseSDDMM cusparseSDDMM


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

