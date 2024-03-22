
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cufft.h>
#include <cufftw.h>

#include "cudam.h"
#include "api_counter.h"

#undef cufftPlan1d
cufftResult cufftPlan1d(cufftHandle * plan, int nx, cufftType type, int batch){
    cufftResult lretval;
    cufftResult (*lcufftPlan1d) (cufftHandle *, int, cufftType, int) = (cufftResult (*)(cufftHandle *, int, cufftType, int))dlsym(RTLD_NEXT, "cufftPlan1d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftPlan1d", kApiTypeCuFFT);

    lretval = lcufftPlan1d(plan, nx, type, batch);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftPlan1d cufftPlan1d


#undef cufftPlan2d
cufftResult cufftPlan2d(cufftHandle * plan, int nx, int ny, cufftType type){
    cufftResult lretval;
    cufftResult (*lcufftPlan2d) (cufftHandle *, int, int, cufftType) = (cufftResult (*)(cufftHandle *, int, int, cufftType))dlsym(RTLD_NEXT, "cufftPlan2d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftPlan2d", kApiTypeCuFFT);

    lretval = lcufftPlan2d(plan, nx, ny, type);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftPlan2d cufftPlan2d


#undef cufftPlan3d
cufftResult cufftPlan3d(cufftHandle * plan, int nx, int ny, int nz, cufftType type){
    cufftResult lretval;
    cufftResult (*lcufftPlan3d) (cufftHandle *, int, int, int, cufftType) = (cufftResult (*)(cufftHandle *, int, int, int, cufftType))dlsym(RTLD_NEXT, "cufftPlan3d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftPlan3d", kApiTypeCuFFT);

    lretval = lcufftPlan3d(plan, nx, ny, nz, type);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftPlan3d cufftPlan3d


#undef cufftPlanMany
cufftResult cufftPlanMany(cufftHandle * plan, int rank, int * n, int * inembed, int istride, int idist, int * onembed, int ostride, int odist, cufftType type, int batch){
    cufftResult lretval;
    cufftResult (*lcufftPlanMany) (cufftHandle *, int, int *, int *, int, int, int *, int, int, cufftType, int) = (cufftResult (*)(cufftHandle *, int, int *, int *, int, int, int *, int, int, cufftType, int))dlsym(RTLD_NEXT, "cufftPlanMany");
    
    /* pre exeuction logics */
    ac.add_counter("cufftPlanMany", kApiTypeCuFFT);

    lretval = lcufftPlanMany(plan, rank, n, inembed, istride, idist, onembed, ostride, odist, type, batch);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftPlanMany cufftPlanMany


#undef cufftMakePlan1d
cufftResult cufftMakePlan1d(cufftHandle plan, int nx, cufftType type, int batch, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftMakePlan1d) (cufftHandle, int, cufftType, int, size_t *) = (cufftResult (*)(cufftHandle, int, cufftType, int, size_t *))dlsym(RTLD_NEXT, "cufftMakePlan1d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftMakePlan1d", kApiTypeCuFFT);

    lretval = lcufftMakePlan1d(plan, nx, type, batch, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftMakePlan1d cufftMakePlan1d


#undef cufftMakePlan2d
cufftResult cufftMakePlan2d(cufftHandle plan, int nx, int ny, cufftType type, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftMakePlan2d) (cufftHandle, int, int, cufftType, size_t *) = (cufftResult (*)(cufftHandle, int, int, cufftType, size_t *))dlsym(RTLD_NEXT, "cufftMakePlan2d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftMakePlan2d", kApiTypeCuFFT);

    lretval = lcufftMakePlan2d(plan, nx, ny, type, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftMakePlan2d cufftMakePlan2d


#undef cufftMakePlan3d
cufftResult cufftMakePlan3d(cufftHandle plan, int nx, int ny, int nz, cufftType type, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftMakePlan3d) (cufftHandle, int, int, int, cufftType, size_t *) = (cufftResult (*)(cufftHandle, int, int, int, cufftType, size_t *))dlsym(RTLD_NEXT, "cufftMakePlan3d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftMakePlan3d", kApiTypeCuFFT);

    lretval = lcufftMakePlan3d(plan, nx, ny, nz, type, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftMakePlan3d cufftMakePlan3d


#undef cufftMakePlanMany
cufftResult cufftMakePlanMany(cufftHandle plan, int rank, int * n, int * inembed, int istride, int idist, int * onembed, int ostride, int odist, cufftType type, int batch, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftMakePlanMany) (cufftHandle, int, int *, int *, int, int, int *, int, int, cufftType, int, size_t *) = (cufftResult (*)(cufftHandle, int, int *, int *, int, int, int *, int, int, cufftType, int, size_t *))dlsym(RTLD_NEXT, "cufftMakePlanMany");
    
    /* pre exeuction logics */
    ac.add_counter("cufftMakePlanMany", kApiTypeCuFFT);

    lretval = lcufftMakePlanMany(plan, rank, n, inembed, istride, idist, onembed, ostride, odist, type, batch, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftMakePlanMany cufftMakePlanMany


#undef cufftMakePlanMany64
cufftResult cufftMakePlanMany64(cufftHandle plan, int rank, long long int * n, long long int * inembed, long long int istride, long long int idist, long long int * onembed, long long int ostride, long long int odist, cufftType type, long long int batch, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftMakePlanMany64) (cufftHandle, int, long long int *, long long int *, long long int, long long int, long long int *, long long int, long long int, cufftType, long long int, size_t *) = (cufftResult (*)(cufftHandle, int, long long int *, long long int *, long long int, long long int, long long int *, long long int, long long int, cufftType, long long int, size_t *))dlsym(RTLD_NEXT, "cufftMakePlanMany64");
    
    /* pre exeuction logics */
    ac.add_counter("cufftMakePlanMany64", kApiTypeCuFFT);

    lretval = lcufftMakePlanMany64(plan, rank, n, inembed, istride, idist, onembed, ostride, odist, type, batch, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftMakePlanMany64 cufftMakePlanMany64


#undef cufftGetSizeMany64
cufftResult cufftGetSizeMany64(cufftHandle plan, int rank, long long int * n, long long int * inembed, long long int istride, long long int idist, long long int * onembed, long long int ostride, long long int odist, cufftType type, long long int batch, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftGetSizeMany64) (cufftHandle, int, long long int *, long long int *, long long int, long long int, long long int *, long long int, long long int, cufftType, long long int, size_t *) = (cufftResult (*)(cufftHandle, int, long long int *, long long int *, long long int, long long int, long long int *, long long int, long long int, cufftType, long long int, size_t *))dlsym(RTLD_NEXT, "cufftGetSizeMany64");
    
    /* pre exeuction logics */
    ac.add_counter("cufftGetSizeMany64", kApiTypeCuFFT);

    lretval = lcufftGetSizeMany64(plan, rank, n, inembed, istride, idist, onembed, ostride, odist, type, batch, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftGetSizeMany64 cufftGetSizeMany64


#undef cufftEstimate1d
cufftResult cufftEstimate1d(int nx, cufftType type, int batch, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftEstimate1d) (int, cufftType, int, size_t *) = (cufftResult (*)(int, cufftType, int, size_t *))dlsym(RTLD_NEXT, "cufftEstimate1d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftEstimate1d", kApiTypeCuFFT);

    lretval = lcufftEstimate1d(nx, type, batch, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftEstimate1d cufftEstimate1d


#undef cufftEstimate2d
cufftResult cufftEstimate2d(int nx, int ny, cufftType type, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftEstimate2d) (int, int, cufftType, size_t *) = (cufftResult (*)(int, int, cufftType, size_t *))dlsym(RTLD_NEXT, "cufftEstimate2d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftEstimate2d", kApiTypeCuFFT);

    lretval = lcufftEstimate2d(nx, ny, type, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftEstimate2d cufftEstimate2d


#undef cufftEstimate3d
cufftResult cufftEstimate3d(int nx, int ny, int nz, cufftType type, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftEstimate3d) (int, int, int, cufftType, size_t *) = (cufftResult (*)(int, int, int, cufftType, size_t *))dlsym(RTLD_NEXT, "cufftEstimate3d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftEstimate3d", kApiTypeCuFFT);

    lretval = lcufftEstimate3d(nx, ny, nz, type, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftEstimate3d cufftEstimate3d


#undef cufftEstimateMany
cufftResult cufftEstimateMany(int rank, int * n, int * inembed, int istride, int idist, int * onembed, int ostride, int odist, cufftType type, int batch, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftEstimateMany) (int, int *, int *, int, int, int *, int, int, cufftType, int, size_t *) = (cufftResult (*)(int, int *, int *, int, int, int *, int, int, cufftType, int, size_t *))dlsym(RTLD_NEXT, "cufftEstimateMany");
    
    /* pre exeuction logics */
    ac.add_counter("cufftEstimateMany", kApiTypeCuFFT);

    lretval = lcufftEstimateMany(rank, n, inembed, istride, idist, onembed, ostride, odist, type, batch, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftEstimateMany cufftEstimateMany


#undef cufftCreate
cufftResult cufftCreate(cufftHandle * handle){
    cufftResult lretval;
    cufftResult (*lcufftCreate) (cufftHandle *) = (cufftResult (*)(cufftHandle *))dlsym(RTLD_NEXT, "cufftCreate");
    
    /* pre exeuction logics */
    ac.add_counter("cufftCreate", kApiTypeCuFFT);

    lretval = lcufftCreate(handle);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftCreate cufftCreate


#undef cufftGetSize1d
cufftResult cufftGetSize1d(cufftHandle handle, int nx, cufftType type, int batch, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftGetSize1d) (cufftHandle, int, cufftType, int, size_t *) = (cufftResult (*)(cufftHandle, int, cufftType, int, size_t *))dlsym(RTLD_NEXT, "cufftGetSize1d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftGetSize1d", kApiTypeCuFFT);

    lretval = lcufftGetSize1d(handle, nx, type, batch, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftGetSize1d cufftGetSize1d


#undef cufftGetSize2d
cufftResult cufftGetSize2d(cufftHandle handle, int nx, int ny, cufftType type, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftGetSize2d) (cufftHandle, int, int, cufftType, size_t *) = (cufftResult (*)(cufftHandle, int, int, cufftType, size_t *))dlsym(RTLD_NEXT, "cufftGetSize2d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftGetSize2d", kApiTypeCuFFT);

    lretval = lcufftGetSize2d(handle, nx, ny, type, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftGetSize2d cufftGetSize2d


#undef cufftGetSize3d
cufftResult cufftGetSize3d(cufftHandle handle, int nx, int ny, int nz, cufftType type, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftGetSize3d) (cufftHandle, int, int, int, cufftType, size_t *) = (cufftResult (*)(cufftHandle, int, int, int, cufftType, size_t *))dlsym(RTLD_NEXT, "cufftGetSize3d");
    
    /* pre exeuction logics */
    ac.add_counter("cufftGetSize3d", kApiTypeCuFFT);

    lretval = lcufftGetSize3d(handle, nx, ny, nz, type, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftGetSize3d cufftGetSize3d


#undef cufftGetSizeMany
cufftResult cufftGetSizeMany(cufftHandle handle, int rank, int * n, int * inembed, int istride, int idist, int * onembed, int ostride, int odist, cufftType type, int batch, size_t * workArea){
    cufftResult lretval;
    cufftResult (*lcufftGetSizeMany) (cufftHandle, int, int *, int *, int, int, int *, int, int, cufftType, int, size_t *) = (cufftResult (*)(cufftHandle, int, int *, int *, int, int, int *, int, int, cufftType, int, size_t *))dlsym(RTLD_NEXT, "cufftGetSizeMany");
    
    /* pre exeuction logics */
    ac.add_counter("cufftGetSizeMany", kApiTypeCuFFT);

    lretval = lcufftGetSizeMany(handle, rank, n, inembed, istride, idist, onembed, ostride, odist, type, batch, workArea);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftGetSizeMany cufftGetSizeMany


#undef cufftGetSize
cufftResult cufftGetSize(cufftHandle handle, size_t * workSize){
    cufftResult lretval;
    cufftResult (*lcufftGetSize) (cufftHandle, size_t *) = (cufftResult (*)(cufftHandle, size_t *))dlsym(RTLD_NEXT, "cufftGetSize");
    
    /* pre exeuction logics */
    ac.add_counter("cufftGetSize", kApiTypeCuFFT);

    lretval = lcufftGetSize(handle, workSize);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftGetSize cufftGetSize


#undef cufftSetWorkArea
cufftResult cufftSetWorkArea(cufftHandle plan, void * workArea){
    cufftResult lretval;
    cufftResult (*lcufftSetWorkArea) (cufftHandle, void *) = (cufftResult (*)(cufftHandle, void *))dlsym(RTLD_NEXT, "cufftSetWorkArea");
    
    /* pre exeuction logics */
    ac.add_counter("cufftSetWorkArea", kApiTypeCuFFT);

    lretval = lcufftSetWorkArea(plan, workArea);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftSetWorkArea cufftSetWorkArea


#undef cufftSetAutoAllocation
cufftResult cufftSetAutoAllocation(cufftHandle plan, int autoAllocate){
    cufftResult lretval;
    cufftResult (*lcufftSetAutoAllocation) (cufftHandle, int) = (cufftResult (*)(cufftHandle, int))dlsym(RTLD_NEXT, "cufftSetAutoAllocation");
    
    /* pre exeuction logics */
    ac.add_counter("cufftSetAutoAllocation", kApiTypeCuFFT);

    lretval = lcufftSetAutoAllocation(plan, autoAllocate);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftSetAutoAllocation cufftSetAutoAllocation


#undef cufftExecC2C
cufftResult cufftExecC2C(cufftHandle plan, cufftComplex * idata, cufftComplex * odata, int direction){
    cufftResult lretval;
    cufftResult (*lcufftExecC2C) (cufftHandle, cufftComplex *, cufftComplex *, int) = (cufftResult (*)(cufftHandle, cufftComplex *, cufftComplex *, int))dlsym(RTLD_NEXT, "cufftExecC2C");
    
    /* pre exeuction logics */
    ac.add_counter("cufftExecC2C", kApiTypeCuFFT);

    lretval = lcufftExecC2C(plan, idata, odata, direction);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftExecC2C cufftExecC2C


#undef cufftExecR2C
cufftResult cufftExecR2C(cufftHandle plan, cufftReal * idata, cufftComplex * odata){
    cufftResult lretval;
    cufftResult (*lcufftExecR2C) (cufftHandle, cufftReal *, cufftComplex *) = (cufftResult (*)(cufftHandle, cufftReal *, cufftComplex *))dlsym(RTLD_NEXT, "cufftExecR2C");
    
    /* pre exeuction logics */
    ac.add_counter("cufftExecR2C", kApiTypeCuFFT);

    lretval = lcufftExecR2C(plan, idata, odata);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftExecR2C cufftExecR2C


#undef cufftExecC2R
cufftResult cufftExecC2R(cufftHandle plan, cufftComplex * idata, cufftReal * odata){
    cufftResult lretval;
    cufftResult (*lcufftExecC2R) (cufftHandle, cufftComplex *, cufftReal *) = (cufftResult (*)(cufftHandle, cufftComplex *, cufftReal *))dlsym(RTLD_NEXT, "cufftExecC2R");
    
    /* pre exeuction logics */
    ac.add_counter("cufftExecC2R", kApiTypeCuFFT);

    lretval = lcufftExecC2R(plan, idata, odata);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftExecC2R cufftExecC2R


#undef cufftExecZ2Z
cufftResult cufftExecZ2Z(cufftHandle plan, cufftDoubleComplex * idata, cufftDoubleComplex * odata, int direction){
    cufftResult lretval;
    cufftResult (*lcufftExecZ2Z) (cufftHandle, cufftDoubleComplex *, cufftDoubleComplex *, int) = (cufftResult (*)(cufftHandle, cufftDoubleComplex *, cufftDoubleComplex *, int))dlsym(RTLD_NEXT, "cufftExecZ2Z");
    
    /* pre exeuction logics */
    ac.add_counter("cufftExecZ2Z", kApiTypeCuFFT);

    lretval = lcufftExecZ2Z(plan, idata, odata, direction);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftExecZ2Z cufftExecZ2Z


#undef cufftExecD2Z
cufftResult cufftExecD2Z(cufftHandle plan, cufftDoubleReal * idata, cufftDoubleComplex * odata){
    cufftResult lretval;
    cufftResult (*lcufftExecD2Z) (cufftHandle, cufftDoubleReal *, cufftDoubleComplex *) = (cufftResult (*)(cufftHandle, cufftDoubleReal *, cufftDoubleComplex *))dlsym(RTLD_NEXT, "cufftExecD2Z");
    
    /* pre exeuction logics */
    ac.add_counter("cufftExecD2Z", kApiTypeCuFFT);

    lretval = lcufftExecD2Z(plan, idata, odata);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftExecD2Z cufftExecD2Z


#undef cufftExecZ2D
cufftResult cufftExecZ2D(cufftHandle plan, cufftDoubleComplex * idata, cufftDoubleReal * odata){
    cufftResult lretval;
    cufftResult (*lcufftExecZ2D) (cufftHandle, cufftDoubleComplex *, cufftDoubleReal *) = (cufftResult (*)(cufftHandle, cufftDoubleComplex *, cufftDoubleReal *))dlsym(RTLD_NEXT, "cufftExecZ2D");
    
    /* pre exeuction logics */
    ac.add_counter("cufftExecZ2D", kApiTypeCuFFT);

    lretval = lcufftExecZ2D(plan, idata, odata);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftExecZ2D cufftExecZ2D


#undef cufftSetStream
cufftResult cufftSetStream(cufftHandle plan, cudaStream_t stream){
    cufftResult lretval;
    cufftResult (*lcufftSetStream) (cufftHandle, cudaStream_t) = (cufftResult (*)(cufftHandle, cudaStream_t))dlsym(RTLD_NEXT, "cufftSetStream");
    
    /* pre exeuction logics */
    ac.add_counter("cufftSetStream", kApiTypeCuFFT);

    lretval = lcufftSetStream(plan, stream);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftSetStream cufftSetStream


#undef cufftDestroy
cufftResult cufftDestroy(cufftHandle plan){
    cufftResult lretval;
    cufftResult (*lcufftDestroy) (cufftHandle) = (cufftResult (*)(cufftHandle))dlsym(RTLD_NEXT, "cufftDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("cufftDestroy", kApiTypeCuFFT);

    lretval = lcufftDestroy(plan);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftDestroy cufftDestroy


#undef cufftGetVersion
cufftResult cufftGetVersion(int * version){
    cufftResult lretval;
    cufftResult (*lcufftGetVersion) (int *) = (cufftResult (*)(int *))dlsym(RTLD_NEXT, "cufftGetVersion");
    
    /* pre exeuction logics */
    ac.add_counter("cufftGetVersion", kApiTypeCuFFT);

    lretval = lcufftGetVersion(version);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftGetVersion cufftGetVersion


#undef cufftGetProperty
cufftResult cufftGetProperty(libraryPropertyType type, int * value){
    cufftResult lretval;
    cufftResult (*lcufftGetProperty) (libraryPropertyType, int *) = (cufftResult (*)(libraryPropertyType, int *))dlsym(RTLD_NEXT, "cufftGetProperty");
    
    /* pre exeuction logics */
    ac.add_counter("cufftGetProperty", kApiTypeCuFFT);

    lretval = lcufftGetProperty(type, value);
    
    /* post exeuction logics */

    return lretval;
}
#define cufftGetProperty cufftGetProperty

