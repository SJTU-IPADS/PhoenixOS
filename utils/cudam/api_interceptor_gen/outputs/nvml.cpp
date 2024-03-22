
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <nvml.h>

#include "cudam.h"
#include "api_counter.h"

#undef nvmlInit_v2
nvmlReturn_t nvmlInit_v2(){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlInit_v2) () = (nvmlReturn_t (*)())dlsym(RTLD_NEXT, "nvmlInit_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlInit_v2", kApiTypeNvml);

    lretval = lnvmlInit_v2();
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlInit_v2 nvmlInit_v2


#undef nvmlInit
nvmlReturn_t nvmlInit(){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlInit) () = (nvmlReturn_t (*)())dlsym(RTLD_NEXT, "nvmlInit_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlInit", kApiTypeNvml);

    lretval = lnvmlInit();
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlInit nvmlInit_v2


#undef nvmlInitWithFlags
nvmlReturn_t nvmlInitWithFlags(unsigned int flags){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlInitWithFlags) (unsigned int) = (nvmlReturn_t (*)(unsigned int))dlsym(RTLD_NEXT, "nvmlInitWithFlags");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlInitWithFlags", kApiTypeNvml);

    lretval = lnvmlInitWithFlags(flags);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlInitWithFlags nvmlInitWithFlags


#undef nvmlShutdown
nvmlReturn_t nvmlShutdown(){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlShutdown) () = (nvmlReturn_t (*)())dlsym(RTLD_NEXT, "nvmlShutdown");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlShutdown", kApiTypeNvml);

    lretval = lnvmlShutdown();
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlShutdown nvmlShutdown


#undef nvmlErrorString
char const * nvmlErrorString(nvmlReturn_t result){
    char const * lretval;
    char const * (*lnvmlErrorString) (nvmlReturn_t) = (char const * (*)(nvmlReturn_t))dlsym(RTLD_NEXT, "nvmlErrorString");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlErrorString", kApiTypeNvml);

    lretval = lnvmlErrorString(result);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlErrorString nvmlErrorString


#undef nvmlSystemGetDriverVersion
nvmlReturn_t nvmlSystemGetDriverVersion(char * version, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlSystemGetDriverVersion) (char *, unsigned int) = (nvmlReturn_t (*)(char *, unsigned int))dlsym(RTLD_NEXT, "nvmlSystemGetDriverVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlSystemGetDriverVersion", kApiTypeNvml);

    lretval = lnvmlSystemGetDriverVersion(version, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlSystemGetDriverVersion nvmlSystemGetDriverVersion


#undef nvmlSystemGetNVMLVersion
nvmlReturn_t nvmlSystemGetNVMLVersion(char * version, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlSystemGetNVMLVersion) (char *, unsigned int) = (nvmlReturn_t (*)(char *, unsigned int))dlsym(RTLD_NEXT, "nvmlSystemGetNVMLVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlSystemGetNVMLVersion", kApiTypeNvml);

    lretval = lnvmlSystemGetNVMLVersion(version, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlSystemGetNVMLVersion nvmlSystemGetNVMLVersion


#undef nvmlSystemGetCudaDriverVersion
nvmlReturn_t nvmlSystemGetCudaDriverVersion(int * cudaDriverVersion){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlSystemGetCudaDriverVersion) (int *) = (nvmlReturn_t (*)(int *))dlsym(RTLD_NEXT, "nvmlSystemGetCudaDriverVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlSystemGetCudaDriverVersion", kApiTypeNvml);

    lretval = lnvmlSystemGetCudaDriverVersion(cudaDriverVersion);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlSystemGetCudaDriverVersion nvmlSystemGetCudaDriverVersion


#undef nvmlSystemGetCudaDriverVersion_v2
nvmlReturn_t nvmlSystemGetCudaDriverVersion_v2(int * cudaDriverVersion){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlSystemGetCudaDriverVersion_v2) (int *) = (nvmlReturn_t (*)(int *))dlsym(RTLD_NEXT, "nvmlSystemGetCudaDriverVersion_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlSystemGetCudaDriverVersion_v2", kApiTypeNvml);

    lretval = lnvmlSystemGetCudaDriverVersion_v2(cudaDriverVersion);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlSystemGetCudaDriverVersion_v2 nvmlSystemGetCudaDriverVersion_v2


#undef nvmlSystemGetProcessName
nvmlReturn_t nvmlSystemGetProcessName(unsigned int pid, char * name, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlSystemGetProcessName) (unsigned int, char *, unsigned int) = (nvmlReturn_t (*)(unsigned int, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlSystemGetProcessName");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlSystemGetProcessName", kApiTypeNvml);

    lretval = lnvmlSystemGetProcessName(pid, name, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlSystemGetProcessName nvmlSystemGetProcessName


#undef nvmlUnitGetCount
nvmlReturn_t nvmlUnitGetCount(unsigned int * unitCount){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlUnitGetCount) (unsigned int *) = (nvmlReturn_t (*)(unsigned int *))dlsym(RTLD_NEXT, "nvmlUnitGetCount");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlUnitGetCount", kApiTypeNvml);

    lretval = lnvmlUnitGetCount(unitCount);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlUnitGetCount nvmlUnitGetCount


#undef nvmlUnitGetHandleByIndex
nvmlReturn_t nvmlUnitGetHandleByIndex(unsigned int index, nvmlUnit_t * unit){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlUnitGetHandleByIndex) (unsigned int, nvmlUnit_t *) = (nvmlReturn_t (*)(unsigned int, nvmlUnit_t *))dlsym(RTLD_NEXT, "nvmlUnitGetHandleByIndex");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlUnitGetHandleByIndex", kApiTypeNvml);

    lretval = lnvmlUnitGetHandleByIndex(index, unit);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlUnitGetHandleByIndex nvmlUnitGetHandleByIndex


#undef nvmlUnitGetUnitInfo
nvmlReturn_t nvmlUnitGetUnitInfo(nvmlUnit_t unit, nvmlUnitInfo_t * info){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlUnitGetUnitInfo) (nvmlUnit_t, nvmlUnitInfo_t *) = (nvmlReturn_t (*)(nvmlUnit_t, nvmlUnitInfo_t *))dlsym(RTLD_NEXT, "nvmlUnitGetUnitInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlUnitGetUnitInfo", kApiTypeNvml);

    lretval = lnvmlUnitGetUnitInfo(unit, info);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlUnitGetUnitInfo nvmlUnitGetUnitInfo


#undef nvmlUnitGetLedState
nvmlReturn_t nvmlUnitGetLedState(nvmlUnit_t unit, nvmlLedState_t * state){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlUnitGetLedState) (nvmlUnit_t, nvmlLedState_t *) = (nvmlReturn_t (*)(nvmlUnit_t, nvmlLedState_t *))dlsym(RTLD_NEXT, "nvmlUnitGetLedState");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlUnitGetLedState", kApiTypeNvml);

    lretval = lnvmlUnitGetLedState(unit, state);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlUnitGetLedState nvmlUnitGetLedState


#undef nvmlUnitGetPsuInfo
nvmlReturn_t nvmlUnitGetPsuInfo(nvmlUnit_t unit, nvmlPSUInfo_t * psu){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlUnitGetPsuInfo) (nvmlUnit_t, nvmlPSUInfo_t *) = (nvmlReturn_t (*)(nvmlUnit_t, nvmlPSUInfo_t *))dlsym(RTLD_NEXT, "nvmlUnitGetPsuInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlUnitGetPsuInfo", kApiTypeNvml);

    lretval = lnvmlUnitGetPsuInfo(unit, psu);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlUnitGetPsuInfo nvmlUnitGetPsuInfo


#undef nvmlUnitGetTemperature
nvmlReturn_t nvmlUnitGetTemperature(nvmlUnit_t unit, unsigned int type, unsigned int * temp){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlUnitGetTemperature) (nvmlUnit_t, unsigned int, unsigned int *) = (nvmlReturn_t (*)(nvmlUnit_t, unsigned int, unsigned int *))dlsym(RTLD_NEXT, "nvmlUnitGetTemperature");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlUnitGetTemperature", kApiTypeNvml);

    lretval = lnvmlUnitGetTemperature(unit, type, temp);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlUnitGetTemperature nvmlUnitGetTemperature


#undef nvmlUnitGetFanSpeedInfo
nvmlReturn_t nvmlUnitGetFanSpeedInfo(nvmlUnit_t unit, nvmlUnitFanSpeeds_t * fanSpeeds){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlUnitGetFanSpeedInfo) (nvmlUnit_t, nvmlUnitFanSpeeds_t *) = (nvmlReturn_t (*)(nvmlUnit_t, nvmlUnitFanSpeeds_t *))dlsym(RTLD_NEXT, "nvmlUnitGetFanSpeedInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlUnitGetFanSpeedInfo", kApiTypeNvml);

    lretval = lnvmlUnitGetFanSpeedInfo(unit, fanSpeeds);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlUnitGetFanSpeedInfo nvmlUnitGetFanSpeedInfo


#undef nvmlUnitGetDevices
nvmlReturn_t nvmlUnitGetDevices(nvmlUnit_t unit, unsigned int * deviceCount, nvmlDevice_t * devices){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlUnitGetDevices) (nvmlUnit_t, unsigned int *, nvmlDevice_t *) = (nvmlReturn_t (*)(nvmlUnit_t, unsigned int *, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlUnitGetDevices");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlUnitGetDevices", kApiTypeNvml);

    lretval = lnvmlUnitGetDevices(unit, deviceCount, devices);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlUnitGetDevices nvmlUnitGetDevices


#undef nvmlSystemGetHicVersion
nvmlReturn_t nvmlSystemGetHicVersion(unsigned int * hwbcCount, nvmlHwbcEntry_t * hwbcEntries){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlSystemGetHicVersion) (unsigned int *, nvmlHwbcEntry_t *) = (nvmlReturn_t (*)(unsigned int *, nvmlHwbcEntry_t *))dlsym(RTLD_NEXT, "nvmlSystemGetHicVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlSystemGetHicVersion", kApiTypeNvml);

    lretval = lnvmlSystemGetHicVersion(hwbcCount, hwbcEntries);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlSystemGetHicVersion nvmlSystemGetHicVersion


#undef nvmlDeviceGetCount_v2
nvmlReturn_t nvmlDeviceGetCount_v2(unsigned int * deviceCount){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetCount_v2) (unsigned int *) = (nvmlReturn_t (*)(unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetCount_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetCount_v2", kApiTypeNvml);

    lretval = lnvmlDeviceGetCount_v2(deviceCount);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetCount_v2 nvmlDeviceGetCount_v2


#undef nvmlDeviceGetCount
nvmlReturn_t nvmlDeviceGetCount(unsigned int * deviceCount){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetCount) (unsigned int *) = (nvmlReturn_t (*)(unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetCount_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetCount", kApiTypeNvml);

    lretval = lnvmlDeviceGetCount(deviceCount);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetCount nvmlDeviceGetCount_v2


#undef nvmlDeviceGetAttributes_v2
nvmlReturn_t nvmlDeviceGetAttributes_v2(nvmlDevice_t device, nvmlDeviceAttributes_t * attributes){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetAttributes_v2) (nvmlDevice_t, nvmlDeviceAttributes_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlDeviceAttributes_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetAttributes_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetAttributes_v2", kApiTypeNvml);

    lretval = lnvmlDeviceGetAttributes_v2(device, attributes);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetAttributes_v2 nvmlDeviceGetAttributes_v2


#undef nvmlDeviceGetAttributes
nvmlReturn_t nvmlDeviceGetAttributes(nvmlDevice_t device, nvmlDeviceAttributes_t * attributes){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetAttributes) (nvmlDevice_t, nvmlDeviceAttributes_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlDeviceAttributes_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetAttributes_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetAttributes", kApiTypeNvml);

    lretval = lnvmlDeviceGetAttributes(device, attributes);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetAttributes nvmlDeviceGetAttributes_v2


#undef nvmlDeviceGetHandleByIndex_v2
nvmlReturn_t nvmlDeviceGetHandleByIndex_v2(unsigned int index, nvmlDevice_t * device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetHandleByIndex_v2) (unsigned int, nvmlDevice_t *) = (nvmlReturn_t (*)(unsigned int, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetHandleByIndex_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetHandleByIndex_v2", kApiTypeNvml);

    lretval = lnvmlDeviceGetHandleByIndex_v2(index, device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetHandleByIndex_v2 nvmlDeviceGetHandleByIndex_v2


#undef nvmlDeviceGetHandleByIndex
nvmlReturn_t nvmlDeviceGetHandleByIndex(unsigned int index, nvmlDevice_t * device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetHandleByIndex) (unsigned int, nvmlDevice_t *) = (nvmlReturn_t (*)(unsigned int, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetHandleByIndex_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetHandleByIndex", kApiTypeNvml);

    lretval = lnvmlDeviceGetHandleByIndex(index, device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetHandleByIndex nvmlDeviceGetHandleByIndex_v2


#undef nvmlDeviceGetHandleBySerial
nvmlReturn_t nvmlDeviceGetHandleBySerial(char const * serial, nvmlDevice_t * device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetHandleBySerial) (char const *, nvmlDevice_t *) = (nvmlReturn_t (*)(char const *, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetHandleBySerial");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetHandleBySerial", kApiTypeNvml);

    lretval = lnvmlDeviceGetHandleBySerial(serial, device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetHandleBySerial nvmlDeviceGetHandleBySerial


#undef nvmlDeviceGetHandleByUUID
nvmlReturn_t nvmlDeviceGetHandleByUUID(char const * uuid, nvmlDevice_t * device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetHandleByUUID) (char const *, nvmlDevice_t *) = (nvmlReturn_t (*)(char const *, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetHandleByUUID");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetHandleByUUID", kApiTypeNvml);

    lretval = lnvmlDeviceGetHandleByUUID(uuid, device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetHandleByUUID nvmlDeviceGetHandleByUUID


#undef nvmlDeviceGetHandleByPciBusId_v2
nvmlReturn_t nvmlDeviceGetHandleByPciBusId_v2(char const * pciBusId, nvmlDevice_t * device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetHandleByPciBusId_v2) (char const *, nvmlDevice_t *) = (nvmlReturn_t (*)(char const *, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetHandleByPciBusId_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetHandleByPciBusId_v2", kApiTypeNvml);

    lretval = lnvmlDeviceGetHandleByPciBusId_v2(pciBusId, device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetHandleByPciBusId_v2 nvmlDeviceGetHandleByPciBusId_v2


#undef nvmlDeviceGetHandleByPciBusId
nvmlReturn_t nvmlDeviceGetHandleByPciBusId(char const * pciBusId, nvmlDevice_t * device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetHandleByPciBusId) (char const *, nvmlDevice_t *) = (nvmlReturn_t (*)(char const *, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetHandleByPciBusId_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetHandleByPciBusId", kApiTypeNvml);

    lretval = lnvmlDeviceGetHandleByPciBusId(pciBusId, device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetHandleByPciBusId nvmlDeviceGetHandleByPciBusId_v2


#undef nvmlDeviceGetName
nvmlReturn_t nvmlDeviceGetName(nvmlDevice_t device, char * name, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetName) (nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceGetName");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetName", kApiTypeNvml);

    lretval = lnvmlDeviceGetName(device, name, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetName nvmlDeviceGetName


#undef nvmlDeviceGetBrand
nvmlReturn_t nvmlDeviceGetBrand(nvmlDevice_t device, nvmlBrandType_t * type){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetBrand) (nvmlDevice_t, nvmlBrandType_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlBrandType_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetBrand");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetBrand", kApiTypeNvml);

    lretval = lnvmlDeviceGetBrand(device, type);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetBrand nvmlDeviceGetBrand


#undef nvmlDeviceGetIndex
nvmlReturn_t nvmlDeviceGetIndex(nvmlDevice_t device, unsigned int * index){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetIndex) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetIndex");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetIndex", kApiTypeNvml);

    lretval = lnvmlDeviceGetIndex(device, index);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetIndex nvmlDeviceGetIndex


#undef nvmlDeviceGetSerial
nvmlReturn_t nvmlDeviceGetSerial(nvmlDevice_t device, char * serial, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetSerial) (nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceGetSerial");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetSerial", kApiTypeNvml);

    lretval = lnvmlDeviceGetSerial(device, serial, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetSerial nvmlDeviceGetSerial


#undef nvmlDeviceGetMemoryAffinity
nvmlReturn_t nvmlDeviceGetMemoryAffinity(nvmlDevice_t device, unsigned int nodeSetSize, long unsigned int * nodeSet, nvmlAffinityScope_t scope){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMemoryAffinity) (nvmlDevice_t, unsigned int, long unsigned int *, nvmlAffinityScope_t) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, long unsigned int *, nvmlAffinityScope_t))dlsym(RTLD_NEXT, "nvmlDeviceGetMemoryAffinity");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMemoryAffinity", kApiTypeNvml);

    lretval = lnvmlDeviceGetMemoryAffinity(device, nodeSetSize, nodeSet, scope);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMemoryAffinity nvmlDeviceGetMemoryAffinity


#undef nvmlDeviceGetCpuAffinityWithinScope
nvmlReturn_t nvmlDeviceGetCpuAffinityWithinScope(nvmlDevice_t device, unsigned int cpuSetSize, long unsigned int * cpuSet, nvmlAffinityScope_t scope){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetCpuAffinityWithinScope) (nvmlDevice_t, unsigned int, long unsigned int *, nvmlAffinityScope_t) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, long unsigned int *, nvmlAffinityScope_t))dlsym(RTLD_NEXT, "nvmlDeviceGetCpuAffinityWithinScope");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetCpuAffinityWithinScope", kApiTypeNvml);

    lretval = lnvmlDeviceGetCpuAffinityWithinScope(device, cpuSetSize, cpuSet, scope);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetCpuAffinityWithinScope nvmlDeviceGetCpuAffinityWithinScope


#undef nvmlDeviceGetCpuAffinity
nvmlReturn_t nvmlDeviceGetCpuAffinity(nvmlDevice_t device, unsigned int cpuSetSize, long unsigned int * cpuSet){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetCpuAffinity) (nvmlDevice_t, unsigned int, long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetCpuAffinity");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetCpuAffinity", kApiTypeNvml);

    lretval = lnvmlDeviceGetCpuAffinity(device, cpuSetSize, cpuSet);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetCpuAffinity nvmlDeviceGetCpuAffinity


#undef nvmlDeviceSetCpuAffinity
nvmlReturn_t nvmlDeviceSetCpuAffinity(nvmlDevice_t device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetCpuAffinity) (nvmlDevice_t) = (nvmlReturn_t (*)(nvmlDevice_t))dlsym(RTLD_NEXT, "nvmlDeviceSetCpuAffinity");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetCpuAffinity", kApiTypeNvml);

    lretval = lnvmlDeviceSetCpuAffinity(device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetCpuAffinity nvmlDeviceSetCpuAffinity


#undef nvmlDeviceClearCpuAffinity
nvmlReturn_t nvmlDeviceClearCpuAffinity(nvmlDevice_t device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceClearCpuAffinity) (nvmlDevice_t) = (nvmlReturn_t (*)(nvmlDevice_t))dlsym(RTLD_NEXT, "nvmlDeviceClearCpuAffinity");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceClearCpuAffinity", kApiTypeNvml);

    lretval = lnvmlDeviceClearCpuAffinity(device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceClearCpuAffinity nvmlDeviceClearCpuAffinity


#undef nvmlDeviceGetTopologyCommonAncestor
nvmlReturn_t nvmlDeviceGetTopologyCommonAncestor(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuTopologyLevel_t * pathInfo){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetTopologyCommonAncestor) (nvmlDevice_t, nvmlDevice_t, nvmlGpuTopologyLevel_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlDevice_t, nvmlGpuTopologyLevel_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetTopologyCommonAncestor");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetTopologyCommonAncestor", kApiTypeNvml);

    lretval = lnvmlDeviceGetTopologyCommonAncestor(device1, device2, pathInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetTopologyCommonAncestor nvmlDeviceGetTopologyCommonAncestor


#undef nvmlDeviceGetTopologyNearestGpus
nvmlReturn_t nvmlDeviceGetTopologyNearestGpus(nvmlDevice_t device, nvmlGpuTopologyLevel_t level, unsigned int * count, nvmlDevice_t * deviceArray){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetTopologyNearestGpus) (nvmlDevice_t, nvmlGpuTopologyLevel_t, unsigned int *, nvmlDevice_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlGpuTopologyLevel_t, unsigned int *, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetTopologyNearestGpus");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetTopologyNearestGpus", kApiTypeNvml);

    lretval = lnvmlDeviceGetTopologyNearestGpus(device, level, count, deviceArray);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetTopologyNearestGpus nvmlDeviceGetTopologyNearestGpus


#undef nvmlSystemGetTopologyGpuSet
nvmlReturn_t nvmlSystemGetTopologyGpuSet(unsigned int cpuNumber, unsigned int * count, nvmlDevice_t * deviceArray){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlSystemGetTopologyGpuSet) (unsigned int, unsigned int *, nvmlDevice_t *) = (nvmlReturn_t (*)(unsigned int, unsigned int *, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlSystemGetTopologyGpuSet");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlSystemGetTopologyGpuSet", kApiTypeNvml);

    lretval = lnvmlSystemGetTopologyGpuSet(cpuNumber, count, deviceArray);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlSystemGetTopologyGpuSet nvmlSystemGetTopologyGpuSet


#undef nvmlDeviceGetP2PStatus
nvmlReturn_t nvmlDeviceGetP2PStatus(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuP2PCapsIndex_t p2pIndex, nvmlGpuP2PStatus_t * p2pStatus){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetP2PStatus) (nvmlDevice_t, nvmlDevice_t, nvmlGpuP2PCapsIndex_t, nvmlGpuP2PStatus_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlDevice_t, nvmlGpuP2PCapsIndex_t, nvmlGpuP2PStatus_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetP2PStatus");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetP2PStatus", kApiTypeNvml);

    lretval = lnvmlDeviceGetP2PStatus(device1, device2, p2pIndex, p2pStatus);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetP2PStatus nvmlDeviceGetP2PStatus


#undef nvmlDeviceGetUUID
nvmlReturn_t nvmlDeviceGetUUID(nvmlDevice_t device, char * uuid, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetUUID) (nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceGetUUID");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetUUID", kApiTypeNvml);

    lretval = lnvmlDeviceGetUUID(device, uuid, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetUUID nvmlDeviceGetUUID


#undef nvmlVgpuInstanceGetMdevUUID
nvmlReturn_t nvmlVgpuInstanceGetMdevUUID(nvmlVgpuInstance_t vgpuInstance, char * mdevUuid, unsigned int size){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetMdevUUID) (nvmlVgpuInstance_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetMdevUUID");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetMdevUUID", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetMdevUUID(vgpuInstance, mdevUuid, size);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetMdevUUID nvmlVgpuInstanceGetMdevUUID


#undef nvmlDeviceGetMinorNumber
nvmlReturn_t nvmlDeviceGetMinorNumber(nvmlDevice_t device, unsigned int * minorNumber){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMinorNumber) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetMinorNumber");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMinorNumber", kApiTypeNvml);

    lretval = lnvmlDeviceGetMinorNumber(device, minorNumber);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMinorNumber nvmlDeviceGetMinorNumber


#undef nvmlDeviceGetBoardPartNumber
nvmlReturn_t nvmlDeviceGetBoardPartNumber(nvmlDevice_t device, char * partNumber, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetBoardPartNumber) (nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceGetBoardPartNumber");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetBoardPartNumber", kApiTypeNvml);

    lretval = lnvmlDeviceGetBoardPartNumber(device, partNumber, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetBoardPartNumber nvmlDeviceGetBoardPartNumber


#undef nvmlDeviceGetInforomVersion
nvmlReturn_t nvmlDeviceGetInforomVersion(nvmlDevice_t device, nvmlInforomObject_t object, char * version, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetInforomVersion) (nvmlDevice_t, nvmlInforomObject_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlInforomObject_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceGetInforomVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetInforomVersion", kApiTypeNvml);

    lretval = lnvmlDeviceGetInforomVersion(device, object, version, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetInforomVersion nvmlDeviceGetInforomVersion


#undef nvmlDeviceGetInforomImageVersion
nvmlReturn_t nvmlDeviceGetInforomImageVersion(nvmlDevice_t device, char * version, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetInforomImageVersion) (nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceGetInforomImageVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetInforomImageVersion", kApiTypeNvml);

    lretval = lnvmlDeviceGetInforomImageVersion(device, version, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetInforomImageVersion nvmlDeviceGetInforomImageVersion


#undef nvmlDeviceGetInforomConfigurationChecksum
nvmlReturn_t nvmlDeviceGetInforomConfigurationChecksum(nvmlDevice_t device, unsigned int * checksum){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetInforomConfigurationChecksum) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetInforomConfigurationChecksum");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetInforomConfigurationChecksum", kApiTypeNvml);

    lretval = lnvmlDeviceGetInforomConfigurationChecksum(device, checksum);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetInforomConfigurationChecksum nvmlDeviceGetInforomConfigurationChecksum


#undef nvmlDeviceValidateInforom
nvmlReturn_t nvmlDeviceValidateInforom(nvmlDevice_t device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceValidateInforom) (nvmlDevice_t) = (nvmlReturn_t (*)(nvmlDevice_t))dlsym(RTLD_NEXT, "nvmlDeviceValidateInforom");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceValidateInforom", kApiTypeNvml);

    lretval = lnvmlDeviceValidateInforom(device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceValidateInforom nvmlDeviceValidateInforom


#undef nvmlDeviceGetDisplayMode
nvmlReturn_t nvmlDeviceGetDisplayMode(nvmlDevice_t device, nvmlEnableState_t * display){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetDisplayMode) (nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetDisplayMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetDisplayMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetDisplayMode(device, display);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetDisplayMode nvmlDeviceGetDisplayMode


#undef nvmlDeviceGetDisplayActive
nvmlReturn_t nvmlDeviceGetDisplayActive(nvmlDevice_t device, nvmlEnableState_t * isActive){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetDisplayActive) (nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetDisplayActive");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetDisplayActive", kApiTypeNvml);

    lretval = lnvmlDeviceGetDisplayActive(device, isActive);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetDisplayActive nvmlDeviceGetDisplayActive


#undef nvmlDeviceGetPersistenceMode
nvmlReturn_t nvmlDeviceGetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t * mode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPersistenceMode) (nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetPersistenceMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPersistenceMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetPersistenceMode(device, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPersistenceMode nvmlDeviceGetPersistenceMode


#undef nvmlDeviceGetPciInfo_v3
nvmlReturn_t nvmlDeviceGetPciInfo_v3(nvmlDevice_t device, nvmlPciInfo_t * pci){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPciInfo_v3) (nvmlDevice_t, nvmlPciInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlPciInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetPciInfo_v3");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPciInfo_v3", kApiTypeNvml);

    lretval = lnvmlDeviceGetPciInfo_v3(device, pci);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPciInfo_v3 nvmlDeviceGetPciInfo_v3


#undef nvmlDeviceGetPciInfo
nvmlReturn_t nvmlDeviceGetPciInfo(nvmlDevice_t device, nvmlPciInfo_t * pci){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPciInfo) (nvmlDevice_t, nvmlPciInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlPciInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetPciInfo_v3");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPciInfo", kApiTypeNvml);

    lretval = lnvmlDeviceGetPciInfo(device, pci);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPciInfo nvmlDeviceGetPciInfo_v3


#undef nvmlDeviceGetMaxPcieLinkGeneration
nvmlReturn_t nvmlDeviceGetMaxPcieLinkGeneration(nvmlDevice_t device, unsigned int * maxLinkGen){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMaxPcieLinkGeneration) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetMaxPcieLinkGeneration");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMaxPcieLinkGeneration", kApiTypeNvml);

    lretval = lnvmlDeviceGetMaxPcieLinkGeneration(device, maxLinkGen);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMaxPcieLinkGeneration nvmlDeviceGetMaxPcieLinkGeneration


#undef nvmlDeviceGetMaxPcieLinkWidth
nvmlReturn_t nvmlDeviceGetMaxPcieLinkWidth(nvmlDevice_t device, unsigned int * maxLinkWidth){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMaxPcieLinkWidth) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetMaxPcieLinkWidth");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMaxPcieLinkWidth", kApiTypeNvml);

    lretval = lnvmlDeviceGetMaxPcieLinkWidth(device, maxLinkWidth);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMaxPcieLinkWidth nvmlDeviceGetMaxPcieLinkWidth


#undef nvmlDeviceGetCurrPcieLinkGeneration
nvmlReturn_t nvmlDeviceGetCurrPcieLinkGeneration(nvmlDevice_t device, unsigned int * currLinkGen){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetCurrPcieLinkGeneration) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetCurrPcieLinkGeneration");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetCurrPcieLinkGeneration", kApiTypeNvml);

    lretval = lnvmlDeviceGetCurrPcieLinkGeneration(device, currLinkGen);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetCurrPcieLinkGeneration nvmlDeviceGetCurrPcieLinkGeneration


#undef nvmlDeviceGetCurrPcieLinkWidth
nvmlReturn_t nvmlDeviceGetCurrPcieLinkWidth(nvmlDevice_t device, unsigned int * currLinkWidth){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetCurrPcieLinkWidth) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetCurrPcieLinkWidth");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetCurrPcieLinkWidth", kApiTypeNvml);

    lretval = lnvmlDeviceGetCurrPcieLinkWidth(device, currLinkWidth);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetCurrPcieLinkWidth nvmlDeviceGetCurrPcieLinkWidth


#undef nvmlDeviceGetPcieThroughput
nvmlReturn_t nvmlDeviceGetPcieThroughput(nvmlDevice_t device, nvmlPcieUtilCounter_t counter, unsigned int * value){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPcieThroughput) (nvmlDevice_t, nvmlPcieUtilCounter_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlPcieUtilCounter_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetPcieThroughput");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPcieThroughput", kApiTypeNvml);

    lretval = lnvmlDeviceGetPcieThroughput(device, counter, value);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPcieThroughput nvmlDeviceGetPcieThroughput


#undef nvmlDeviceGetPcieReplayCounter
nvmlReturn_t nvmlDeviceGetPcieReplayCounter(nvmlDevice_t device, unsigned int * value){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPcieReplayCounter) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetPcieReplayCounter");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPcieReplayCounter", kApiTypeNvml);

    lretval = lnvmlDeviceGetPcieReplayCounter(device, value);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPcieReplayCounter nvmlDeviceGetPcieReplayCounter


#undef nvmlDeviceGetClockInfo
nvmlReturn_t nvmlDeviceGetClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int * clock){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetClockInfo) (nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlClockType_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetClockInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetClockInfo", kApiTypeNvml);

    lretval = lnvmlDeviceGetClockInfo(device, type, clock);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetClockInfo nvmlDeviceGetClockInfo


#undef nvmlDeviceGetMaxClockInfo
nvmlReturn_t nvmlDeviceGetMaxClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int * clock){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMaxClockInfo) (nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlClockType_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetMaxClockInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMaxClockInfo", kApiTypeNvml);

    lretval = lnvmlDeviceGetMaxClockInfo(device, type, clock);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMaxClockInfo nvmlDeviceGetMaxClockInfo


#undef nvmlDeviceGetApplicationsClock
nvmlReturn_t nvmlDeviceGetApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int * clockMHz){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetApplicationsClock) (nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlClockType_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetApplicationsClock");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetApplicationsClock", kApiTypeNvml);

    lretval = lnvmlDeviceGetApplicationsClock(device, clockType, clockMHz);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetApplicationsClock nvmlDeviceGetApplicationsClock


#undef nvmlDeviceGetDefaultApplicationsClock
nvmlReturn_t nvmlDeviceGetDefaultApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int * clockMHz){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetDefaultApplicationsClock) (nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlClockType_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetDefaultApplicationsClock");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetDefaultApplicationsClock", kApiTypeNvml);

    lretval = lnvmlDeviceGetDefaultApplicationsClock(device, clockType, clockMHz);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetDefaultApplicationsClock nvmlDeviceGetDefaultApplicationsClock


#undef nvmlDeviceResetApplicationsClocks
nvmlReturn_t nvmlDeviceResetApplicationsClocks(nvmlDevice_t device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceResetApplicationsClocks) (nvmlDevice_t) = (nvmlReturn_t (*)(nvmlDevice_t))dlsym(RTLD_NEXT, "nvmlDeviceResetApplicationsClocks");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceResetApplicationsClocks", kApiTypeNvml);

    lretval = lnvmlDeviceResetApplicationsClocks(device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceResetApplicationsClocks nvmlDeviceResetApplicationsClocks


#undef nvmlDeviceGetClock
nvmlReturn_t nvmlDeviceGetClock(nvmlDevice_t device, nvmlClockType_t clockType, nvmlClockId_t clockId, unsigned int * clockMHz){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetClock) (nvmlDevice_t, nvmlClockType_t, nvmlClockId_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlClockType_t, nvmlClockId_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetClock");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetClock", kApiTypeNvml);

    lretval = lnvmlDeviceGetClock(device, clockType, clockId, clockMHz);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetClock nvmlDeviceGetClock


#undef nvmlDeviceGetMaxCustomerBoostClock
nvmlReturn_t nvmlDeviceGetMaxCustomerBoostClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int * clockMHz){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMaxCustomerBoostClock) (nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlClockType_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetMaxCustomerBoostClock");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMaxCustomerBoostClock", kApiTypeNvml);

    lretval = lnvmlDeviceGetMaxCustomerBoostClock(device, clockType, clockMHz);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMaxCustomerBoostClock nvmlDeviceGetMaxCustomerBoostClock


#undef nvmlDeviceGetSupportedMemoryClocks
nvmlReturn_t nvmlDeviceGetSupportedMemoryClocks(nvmlDevice_t device, unsigned int * count, unsigned int * clocksMHz){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetSupportedMemoryClocks) (nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetSupportedMemoryClocks");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetSupportedMemoryClocks", kApiTypeNvml);

    lretval = lnvmlDeviceGetSupportedMemoryClocks(device, count, clocksMHz);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetSupportedMemoryClocks nvmlDeviceGetSupportedMemoryClocks


#undef nvmlDeviceGetSupportedGraphicsClocks
nvmlReturn_t nvmlDeviceGetSupportedGraphicsClocks(nvmlDevice_t device, unsigned int memoryClockMHz, unsigned int * count, unsigned int * clocksMHz){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetSupportedGraphicsClocks) (nvmlDevice_t, unsigned int, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetSupportedGraphicsClocks");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetSupportedGraphicsClocks", kApiTypeNvml);

    lretval = lnvmlDeviceGetSupportedGraphicsClocks(device, memoryClockMHz, count, clocksMHz);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetSupportedGraphicsClocks nvmlDeviceGetSupportedGraphicsClocks


#undef nvmlDeviceGetAutoBoostedClocksEnabled
nvmlReturn_t nvmlDeviceGetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t * isEnabled, nvmlEnableState_t * defaultIsEnabled){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetAutoBoostedClocksEnabled) (nvmlDevice_t, nvmlEnableState_t *, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t *, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetAutoBoostedClocksEnabled");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetAutoBoostedClocksEnabled", kApiTypeNvml);

    lretval = lnvmlDeviceGetAutoBoostedClocksEnabled(device, isEnabled, defaultIsEnabled);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetAutoBoostedClocksEnabled nvmlDeviceGetAutoBoostedClocksEnabled


#undef nvmlDeviceSetAutoBoostedClocksEnabled
nvmlReturn_t nvmlDeviceSetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetAutoBoostedClocksEnabled) (nvmlDevice_t, nvmlEnableState_t) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t))dlsym(RTLD_NEXT, "nvmlDeviceSetAutoBoostedClocksEnabled");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetAutoBoostedClocksEnabled", kApiTypeNvml);

    lretval = lnvmlDeviceSetAutoBoostedClocksEnabled(device, enabled);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetAutoBoostedClocksEnabled nvmlDeviceSetAutoBoostedClocksEnabled


#undef nvmlDeviceSetDefaultAutoBoostedClocksEnabled
nvmlReturn_t nvmlDeviceSetDefaultAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled, unsigned int flags){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetDefaultAutoBoostedClocksEnabled) (nvmlDevice_t, nvmlEnableState_t, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceSetDefaultAutoBoostedClocksEnabled");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetDefaultAutoBoostedClocksEnabled", kApiTypeNvml);

    lretval = lnvmlDeviceSetDefaultAutoBoostedClocksEnabled(device, enabled, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetDefaultAutoBoostedClocksEnabled nvmlDeviceSetDefaultAutoBoostedClocksEnabled


#undef nvmlDeviceGetFanSpeed
nvmlReturn_t nvmlDeviceGetFanSpeed(nvmlDevice_t device, unsigned int * speed){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetFanSpeed) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetFanSpeed");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetFanSpeed", kApiTypeNvml);

    lretval = lnvmlDeviceGetFanSpeed(device, speed);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetFanSpeed nvmlDeviceGetFanSpeed


#undef nvmlDeviceGetFanSpeed_v2
nvmlReturn_t nvmlDeviceGetFanSpeed_v2(nvmlDevice_t device, unsigned int fan, unsigned int * speed){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetFanSpeed_v2) (nvmlDevice_t, unsigned int, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetFanSpeed_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetFanSpeed_v2", kApiTypeNvml);

    lretval = lnvmlDeviceGetFanSpeed_v2(device, fan, speed);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetFanSpeed_v2 nvmlDeviceGetFanSpeed_v2


#undef nvmlDeviceGetTemperature
nvmlReturn_t nvmlDeviceGetTemperature(nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int * temp){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetTemperature) (nvmlDevice_t, nvmlTemperatureSensors_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlTemperatureSensors_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetTemperature");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetTemperature", kApiTypeNvml);

    lretval = lnvmlDeviceGetTemperature(device, sensorType, temp);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetTemperature nvmlDeviceGetTemperature


#undef nvmlDeviceGetTemperatureThreshold
nvmlReturn_t nvmlDeviceGetTemperatureThreshold(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, unsigned int * temp){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetTemperatureThreshold) (nvmlDevice_t, nvmlTemperatureThresholds_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlTemperatureThresholds_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetTemperatureThreshold");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetTemperatureThreshold", kApiTypeNvml);

    lretval = lnvmlDeviceGetTemperatureThreshold(device, thresholdType, temp);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetTemperatureThreshold nvmlDeviceGetTemperatureThreshold


#undef nvmlDeviceSetTemperatureThreshold
nvmlReturn_t nvmlDeviceSetTemperatureThreshold(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, int * temp){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetTemperatureThreshold) (nvmlDevice_t, nvmlTemperatureThresholds_t, int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlTemperatureThresholds_t, int *))dlsym(RTLD_NEXT, "nvmlDeviceSetTemperatureThreshold");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetTemperatureThreshold", kApiTypeNvml);

    lretval = lnvmlDeviceSetTemperatureThreshold(device, thresholdType, temp);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetTemperatureThreshold nvmlDeviceSetTemperatureThreshold


#undef nvmlDeviceGetPerformanceState
nvmlReturn_t nvmlDeviceGetPerformanceState(nvmlDevice_t device, nvmlPstates_t * pState){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPerformanceState) (nvmlDevice_t, nvmlPstates_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlPstates_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetPerformanceState");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPerformanceState", kApiTypeNvml);

    lretval = lnvmlDeviceGetPerformanceState(device, pState);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPerformanceState nvmlDeviceGetPerformanceState


#undef nvmlDeviceGetCurrentClocksThrottleReasons
nvmlReturn_t nvmlDeviceGetCurrentClocksThrottleReasons(nvmlDevice_t device, long long unsigned int * clocksThrottleReasons){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetCurrentClocksThrottleReasons) (nvmlDevice_t, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetCurrentClocksThrottleReasons");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetCurrentClocksThrottleReasons", kApiTypeNvml);

    lretval = lnvmlDeviceGetCurrentClocksThrottleReasons(device, clocksThrottleReasons);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetCurrentClocksThrottleReasons nvmlDeviceGetCurrentClocksThrottleReasons


#undef nvmlDeviceGetSupportedClocksThrottleReasons
nvmlReturn_t nvmlDeviceGetSupportedClocksThrottleReasons(nvmlDevice_t device, long long unsigned int * supportedClocksThrottleReasons){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetSupportedClocksThrottleReasons) (nvmlDevice_t, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetSupportedClocksThrottleReasons");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetSupportedClocksThrottleReasons", kApiTypeNvml);

    lretval = lnvmlDeviceGetSupportedClocksThrottleReasons(device, supportedClocksThrottleReasons);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetSupportedClocksThrottleReasons nvmlDeviceGetSupportedClocksThrottleReasons


#undef nvmlDeviceGetPowerState
nvmlReturn_t nvmlDeviceGetPowerState(nvmlDevice_t device, nvmlPstates_t * pState){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPowerState) (nvmlDevice_t, nvmlPstates_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlPstates_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetPowerState");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPowerState", kApiTypeNvml);

    lretval = lnvmlDeviceGetPowerState(device, pState);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPowerState nvmlDeviceGetPowerState


#undef nvmlDeviceGetPowerManagementMode
nvmlReturn_t nvmlDeviceGetPowerManagementMode(nvmlDevice_t device, nvmlEnableState_t * mode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPowerManagementMode) (nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetPowerManagementMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPowerManagementMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetPowerManagementMode(device, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPowerManagementMode nvmlDeviceGetPowerManagementMode


#undef nvmlDeviceGetPowerManagementLimit
nvmlReturn_t nvmlDeviceGetPowerManagementLimit(nvmlDevice_t device, unsigned int * limit){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPowerManagementLimit) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetPowerManagementLimit");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPowerManagementLimit", kApiTypeNvml);

    lretval = lnvmlDeviceGetPowerManagementLimit(device, limit);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPowerManagementLimit nvmlDeviceGetPowerManagementLimit


#undef nvmlDeviceGetPowerManagementLimitConstraints
nvmlReturn_t nvmlDeviceGetPowerManagementLimitConstraints(nvmlDevice_t device, unsigned int * minLimit, unsigned int * maxLimit){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPowerManagementLimitConstraints) (nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetPowerManagementLimitConstraints");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPowerManagementLimitConstraints", kApiTypeNvml);

    lretval = lnvmlDeviceGetPowerManagementLimitConstraints(device, minLimit, maxLimit);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPowerManagementLimitConstraints nvmlDeviceGetPowerManagementLimitConstraints


#undef nvmlDeviceGetPowerManagementDefaultLimit
nvmlReturn_t nvmlDeviceGetPowerManagementDefaultLimit(nvmlDevice_t device, unsigned int * defaultLimit){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPowerManagementDefaultLimit) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetPowerManagementDefaultLimit");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPowerManagementDefaultLimit", kApiTypeNvml);

    lretval = lnvmlDeviceGetPowerManagementDefaultLimit(device, defaultLimit);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPowerManagementDefaultLimit nvmlDeviceGetPowerManagementDefaultLimit


#undef nvmlDeviceGetPowerUsage
nvmlReturn_t nvmlDeviceGetPowerUsage(nvmlDevice_t device, unsigned int * power){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPowerUsage) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetPowerUsage");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPowerUsage", kApiTypeNvml);

    lretval = lnvmlDeviceGetPowerUsage(device, power);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPowerUsage nvmlDeviceGetPowerUsage


#undef nvmlDeviceGetTotalEnergyConsumption
nvmlReturn_t nvmlDeviceGetTotalEnergyConsumption(nvmlDevice_t device, long long unsigned int * energy){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetTotalEnergyConsumption) (nvmlDevice_t, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetTotalEnergyConsumption");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetTotalEnergyConsumption", kApiTypeNvml);

    lretval = lnvmlDeviceGetTotalEnergyConsumption(device, energy);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetTotalEnergyConsumption nvmlDeviceGetTotalEnergyConsumption


#undef nvmlDeviceGetEnforcedPowerLimit
nvmlReturn_t nvmlDeviceGetEnforcedPowerLimit(nvmlDevice_t device, unsigned int * limit){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetEnforcedPowerLimit) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetEnforcedPowerLimit");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetEnforcedPowerLimit", kApiTypeNvml);

    lretval = lnvmlDeviceGetEnforcedPowerLimit(device, limit);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetEnforcedPowerLimit nvmlDeviceGetEnforcedPowerLimit


#undef nvmlDeviceGetGpuOperationMode
nvmlReturn_t nvmlDeviceGetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t * current, nvmlGpuOperationMode_t * pending){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGpuOperationMode) (nvmlDevice_t, nvmlGpuOperationMode_t *, nvmlGpuOperationMode_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlGpuOperationMode_t *, nvmlGpuOperationMode_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetGpuOperationMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGpuOperationMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetGpuOperationMode(device, current, pending);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGpuOperationMode nvmlDeviceGetGpuOperationMode


#undef nvmlDeviceGetMemoryInfo
nvmlReturn_t nvmlDeviceGetMemoryInfo(nvmlDevice_t device, nvmlMemory_t * memory){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMemoryInfo) (nvmlDevice_t, nvmlMemory_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlMemory_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetMemoryInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMemoryInfo", kApiTypeNvml);

    lretval = lnvmlDeviceGetMemoryInfo(device, memory);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMemoryInfo nvmlDeviceGetMemoryInfo


#undef nvmlDeviceGetComputeMode
nvmlReturn_t nvmlDeviceGetComputeMode(nvmlDevice_t device, nvmlComputeMode_t * mode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetComputeMode) (nvmlDevice_t, nvmlComputeMode_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlComputeMode_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetComputeMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetComputeMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetComputeMode(device, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetComputeMode nvmlDeviceGetComputeMode


#undef nvmlDeviceGetCudaComputeCapability
nvmlReturn_t nvmlDeviceGetCudaComputeCapability(nvmlDevice_t device, int * major, int * minor){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetCudaComputeCapability) (nvmlDevice_t, int *, int *) = (nvmlReturn_t (*)(nvmlDevice_t, int *, int *))dlsym(RTLD_NEXT, "nvmlDeviceGetCudaComputeCapability");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetCudaComputeCapability", kApiTypeNvml);

    lretval = lnvmlDeviceGetCudaComputeCapability(device, major, minor);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetCudaComputeCapability nvmlDeviceGetCudaComputeCapability


#undef nvmlDeviceGetEccMode
nvmlReturn_t nvmlDeviceGetEccMode(nvmlDevice_t device, nvmlEnableState_t * current, nvmlEnableState_t * pending){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetEccMode) (nvmlDevice_t, nvmlEnableState_t *, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t *, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetEccMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetEccMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetEccMode(device, current, pending);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetEccMode nvmlDeviceGetEccMode


#undef nvmlDeviceGetBoardId
nvmlReturn_t nvmlDeviceGetBoardId(nvmlDevice_t device, unsigned int * boardId){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetBoardId) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetBoardId");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetBoardId", kApiTypeNvml);

    lretval = lnvmlDeviceGetBoardId(device, boardId);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetBoardId nvmlDeviceGetBoardId


#undef nvmlDeviceGetMultiGpuBoard
nvmlReturn_t nvmlDeviceGetMultiGpuBoard(nvmlDevice_t device, unsigned int * multiGpuBool){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMultiGpuBoard) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetMultiGpuBoard");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMultiGpuBoard", kApiTypeNvml);

    lretval = lnvmlDeviceGetMultiGpuBoard(device, multiGpuBool);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMultiGpuBoard nvmlDeviceGetMultiGpuBoard


#undef nvmlDeviceGetTotalEccErrors
nvmlReturn_t nvmlDeviceGetTotalEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, long long unsigned int * eccCounts){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetTotalEccErrors) (nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetTotalEccErrors");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetTotalEccErrors", kApiTypeNvml);

    lretval = lnvmlDeviceGetTotalEccErrors(device, errorType, counterType, eccCounts);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetTotalEccErrors nvmlDeviceGetTotalEccErrors


#undef nvmlDeviceGetDetailedEccErrors
nvmlReturn_t nvmlDeviceGetDetailedEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlEccErrorCounts_t * eccCounts){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetDetailedEccErrors) (nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlEccErrorCounts_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlEccErrorCounts_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetDetailedEccErrors");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetDetailedEccErrors", kApiTypeNvml);

    lretval = lnvmlDeviceGetDetailedEccErrors(device, errorType, counterType, eccCounts);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetDetailedEccErrors nvmlDeviceGetDetailedEccErrors


#undef nvmlDeviceGetMemoryErrorCounter
nvmlReturn_t nvmlDeviceGetMemoryErrorCounter(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlMemoryLocation_t locationType, long long unsigned int * count){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMemoryErrorCounter) (nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlMemoryLocation_t, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlMemoryLocation_t, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetMemoryErrorCounter");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMemoryErrorCounter", kApiTypeNvml);

    lretval = lnvmlDeviceGetMemoryErrorCounter(device, errorType, counterType, locationType, count);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMemoryErrorCounter nvmlDeviceGetMemoryErrorCounter


#undef nvmlDeviceGetUtilizationRates
nvmlReturn_t nvmlDeviceGetUtilizationRates(nvmlDevice_t device, nvmlUtilization_t * utilization){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetUtilizationRates) (nvmlDevice_t, nvmlUtilization_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlUtilization_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetUtilizationRates");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetUtilizationRates", kApiTypeNvml);

    lretval = lnvmlDeviceGetUtilizationRates(device, utilization);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetUtilizationRates nvmlDeviceGetUtilizationRates


#undef nvmlDeviceGetEncoderUtilization
nvmlReturn_t nvmlDeviceGetEncoderUtilization(nvmlDevice_t device, unsigned int * utilization, unsigned int * samplingPeriodUs){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetEncoderUtilization) (nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetEncoderUtilization");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetEncoderUtilization", kApiTypeNvml);

    lretval = lnvmlDeviceGetEncoderUtilization(device, utilization, samplingPeriodUs);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetEncoderUtilization nvmlDeviceGetEncoderUtilization


#undef nvmlDeviceGetEncoderCapacity
nvmlReturn_t nvmlDeviceGetEncoderCapacity(nvmlDevice_t device, nvmlEncoderType_t encoderQueryType, unsigned int * encoderCapacity){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetEncoderCapacity) (nvmlDevice_t, nvmlEncoderType_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEncoderType_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetEncoderCapacity");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetEncoderCapacity", kApiTypeNvml);

    lretval = lnvmlDeviceGetEncoderCapacity(device, encoderQueryType, encoderCapacity);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetEncoderCapacity nvmlDeviceGetEncoderCapacity


#undef nvmlDeviceGetEncoderStats
nvmlReturn_t nvmlDeviceGetEncoderStats(nvmlDevice_t device, unsigned int * sessionCount, unsigned int * averageFps, unsigned int * averageLatency){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetEncoderStats) (nvmlDevice_t, unsigned int *, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetEncoderStats");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetEncoderStats", kApiTypeNvml);

    lretval = lnvmlDeviceGetEncoderStats(device, sessionCount, averageFps, averageLatency);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetEncoderStats nvmlDeviceGetEncoderStats


#undef nvmlDeviceGetEncoderSessions
nvmlReturn_t nvmlDeviceGetEncoderSessions(nvmlDevice_t device, unsigned int * sessionCount, nvmlEncoderSessionInfo_t * sessionInfos){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetEncoderSessions) (nvmlDevice_t, unsigned int *, nvmlEncoderSessionInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, nvmlEncoderSessionInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetEncoderSessions");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetEncoderSessions", kApiTypeNvml);

    lretval = lnvmlDeviceGetEncoderSessions(device, sessionCount, sessionInfos);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetEncoderSessions nvmlDeviceGetEncoderSessions


#undef nvmlDeviceGetDecoderUtilization
nvmlReturn_t nvmlDeviceGetDecoderUtilization(nvmlDevice_t device, unsigned int * utilization, unsigned int * samplingPeriodUs){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetDecoderUtilization) (nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetDecoderUtilization");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetDecoderUtilization", kApiTypeNvml);

    lretval = lnvmlDeviceGetDecoderUtilization(device, utilization, samplingPeriodUs);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetDecoderUtilization nvmlDeviceGetDecoderUtilization


#undef nvmlDeviceGetFBCStats
nvmlReturn_t nvmlDeviceGetFBCStats(nvmlDevice_t device, nvmlFBCStats_t * fbcStats){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetFBCStats) (nvmlDevice_t, nvmlFBCStats_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlFBCStats_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetFBCStats");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetFBCStats", kApiTypeNvml);

    lretval = lnvmlDeviceGetFBCStats(device, fbcStats);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetFBCStats nvmlDeviceGetFBCStats


#undef nvmlDeviceGetFBCSessions
nvmlReturn_t nvmlDeviceGetFBCSessions(nvmlDevice_t device, unsigned int * sessionCount, nvmlFBCSessionInfo_t * sessionInfo){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetFBCSessions) (nvmlDevice_t, unsigned int *, nvmlFBCSessionInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, nvmlFBCSessionInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetFBCSessions");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetFBCSessions", kApiTypeNvml);

    lretval = lnvmlDeviceGetFBCSessions(device, sessionCount, sessionInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetFBCSessions nvmlDeviceGetFBCSessions


#undef nvmlDeviceGetDriverModel
nvmlReturn_t nvmlDeviceGetDriverModel(nvmlDevice_t device, nvmlDriverModel_t * current, nvmlDriverModel_t * pending){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetDriverModel) (nvmlDevice_t, nvmlDriverModel_t *, nvmlDriverModel_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlDriverModel_t *, nvmlDriverModel_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetDriverModel");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetDriverModel", kApiTypeNvml);

    lretval = lnvmlDeviceGetDriverModel(device, current, pending);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetDriverModel nvmlDeviceGetDriverModel


#undef nvmlDeviceGetVbiosVersion
nvmlReturn_t nvmlDeviceGetVbiosVersion(nvmlDevice_t device, char * version, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetVbiosVersion) (nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceGetVbiosVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetVbiosVersion", kApiTypeNvml);

    lretval = lnvmlDeviceGetVbiosVersion(device, version, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetVbiosVersion nvmlDeviceGetVbiosVersion


#undef nvmlDeviceGetBridgeChipInfo
nvmlReturn_t nvmlDeviceGetBridgeChipInfo(nvmlDevice_t device, nvmlBridgeChipHierarchy_t * bridgeHierarchy){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetBridgeChipInfo) (nvmlDevice_t, nvmlBridgeChipHierarchy_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlBridgeChipHierarchy_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetBridgeChipInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetBridgeChipInfo", kApiTypeNvml);

    lretval = lnvmlDeviceGetBridgeChipInfo(device, bridgeHierarchy);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetBridgeChipInfo nvmlDeviceGetBridgeChipInfo


#undef nvmlDeviceGetComputeRunningProcesses_v2
nvmlReturn_t nvmlDeviceGetComputeRunningProcesses_v2(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_t * infos){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetComputeRunningProcesses_v2) (nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetComputeRunningProcesses_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetComputeRunningProcesses_v2", kApiTypeNvml);

    lretval = lnvmlDeviceGetComputeRunningProcesses_v2(device, infoCount, infos);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetComputeRunningProcesses_v2 nvmlDeviceGetComputeRunningProcesses_v2


#undef nvmlDeviceGetComputeRunningProcesses
nvmlReturn_t nvmlDeviceGetComputeRunningProcesses(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_t * infos){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetComputeRunningProcesses) (nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetComputeRunningProcesses_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetComputeRunningProcesses", kApiTypeNvml);

    lretval = lnvmlDeviceGetComputeRunningProcesses(device, infoCount, infos);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetComputeRunningProcesses nvmlDeviceGetComputeRunningProcesses_v2


#undef nvmlDeviceGetGraphicsRunningProcesses_v2
nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses_v2(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_t * infos){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGraphicsRunningProcesses_v2) (nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetGraphicsRunningProcesses_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGraphicsRunningProcesses_v2", kApiTypeNvml);

    lretval = lnvmlDeviceGetGraphicsRunningProcesses_v2(device, infoCount, infos);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGraphicsRunningProcesses_v2 nvmlDeviceGetGraphicsRunningProcesses_v2


#undef nvmlDeviceGetGraphicsRunningProcesses
nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_t * infos){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGraphicsRunningProcesses) (nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetGraphicsRunningProcesses_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGraphicsRunningProcesses", kApiTypeNvml);

    lretval = lnvmlDeviceGetGraphicsRunningProcesses(device, infoCount, infos);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGraphicsRunningProcesses nvmlDeviceGetGraphicsRunningProcesses_v2


#undef nvmlDeviceOnSameBoard
nvmlReturn_t nvmlDeviceOnSameBoard(nvmlDevice_t device1, nvmlDevice_t device2, int * onSameBoard){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceOnSameBoard) (nvmlDevice_t, nvmlDevice_t, int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlDevice_t, int *))dlsym(RTLD_NEXT, "nvmlDeviceOnSameBoard");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceOnSameBoard", kApiTypeNvml);

    lretval = lnvmlDeviceOnSameBoard(device1, device2, onSameBoard);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceOnSameBoard nvmlDeviceOnSameBoard


#undef nvmlDeviceGetAPIRestriction
nvmlReturn_t nvmlDeviceGetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t * isRestricted){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetAPIRestriction) (nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetAPIRestriction");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetAPIRestriction", kApiTypeNvml);

    lretval = lnvmlDeviceGetAPIRestriction(device, apiType, isRestricted);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetAPIRestriction nvmlDeviceGetAPIRestriction


#undef nvmlDeviceGetSamples
nvmlReturn_t nvmlDeviceGetSamples(nvmlDevice_t device, nvmlSamplingType_t type, long long unsigned int lastSeenTimeStamp, nvmlValueType_t * sampleValType, unsigned int * sampleCount, nvmlSample_t * samples){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetSamples) (nvmlDevice_t, nvmlSamplingType_t, long long unsigned int, nvmlValueType_t *, unsigned int *, nvmlSample_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlSamplingType_t, long long unsigned int, nvmlValueType_t *, unsigned int *, nvmlSample_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetSamples");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetSamples", kApiTypeNvml);

    lretval = lnvmlDeviceGetSamples(device, type, lastSeenTimeStamp, sampleValType, sampleCount, samples);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetSamples nvmlDeviceGetSamples


#undef nvmlDeviceGetBAR1MemoryInfo
nvmlReturn_t nvmlDeviceGetBAR1MemoryInfo(nvmlDevice_t device, nvmlBAR1Memory_t * bar1Memory){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetBAR1MemoryInfo) (nvmlDevice_t, nvmlBAR1Memory_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlBAR1Memory_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetBAR1MemoryInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetBAR1MemoryInfo", kApiTypeNvml);

    lretval = lnvmlDeviceGetBAR1MemoryInfo(device, bar1Memory);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetBAR1MemoryInfo nvmlDeviceGetBAR1MemoryInfo


#undef nvmlDeviceGetViolationStatus
nvmlReturn_t nvmlDeviceGetViolationStatus(nvmlDevice_t device, nvmlPerfPolicyType_t perfPolicyType, nvmlViolationTime_t * violTime){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetViolationStatus) (nvmlDevice_t, nvmlPerfPolicyType_t, nvmlViolationTime_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlPerfPolicyType_t, nvmlViolationTime_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetViolationStatus");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetViolationStatus", kApiTypeNvml);

    lretval = lnvmlDeviceGetViolationStatus(device, perfPolicyType, violTime);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetViolationStatus nvmlDeviceGetViolationStatus


#undef nvmlDeviceGetAccountingMode
nvmlReturn_t nvmlDeviceGetAccountingMode(nvmlDevice_t device, nvmlEnableState_t * mode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetAccountingMode) (nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetAccountingMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetAccountingMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetAccountingMode(device, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetAccountingMode nvmlDeviceGetAccountingMode


#undef nvmlDeviceGetAccountingStats
nvmlReturn_t nvmlDeviceGetAccountingStats(nvmlDevice_t device, unsigned int pid, nvmlAccountingStats_t * stats){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetAccountingStats) (nvmlDevice_t, unsigned int, nvmlAccountingStats_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlAccountingStats_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetAccountingStats");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetAccountingStats", kApiTypeNvml);

    lretval = lnvmlDeviceGetAccountingStats(device, pid, stats);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetAccountingStats nvmlDeviceGetAccountingStats


#undef nvmlDeviceGetAccountingPids
nvmlReturn_t nvmlDeviceGetAccountingPids(nvmlDevice_t device, unsigned int * count, unsigned int * pids){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetAccountingPids) (nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetAccountingPids");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetAccountingPids", kApiTypeNvml);

    lretval = lnvmlDeviceGetAccountingPids(device, count, pids);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetAccountingPids nvmlDeviceGetAccountingPids


#undef nvmlDeviceGetAccountingBufferSize
nvmlReturn_t nvmlDeviceGetAccountingBufferSize(nvmlDevice_t device, unsigned int * bufferSize){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetAccountingBufferSize) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetAccountingBufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetAccountingBufferSize", kApiTypeNvml);

    lretval = lnvmlDeviceGetAccountingBufferSize(device, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetAccountingBufferSize nvmlDeviceGetAccountingBufferSize


#undef nvmlDeviceGetRetiredPages
nvmlReturn_t nvmlDeviceGetRetiredPages(nvmlDevice_t device, nvmlPageRetirementCause_t cause, unsigned int * pageCount, long long unsigned int * addresses){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetRetiredPages) (nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int *, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int *, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetRetiredPages");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetRetiredPages", kApiTypeNvml);

    lretval = lnvmlDeviceGetRetiredPages(device, cause, pageCount, addresses);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetRetiredPages nvmlDeviceGetRetiredPages


#undef nvmlDeviceGetRetiredPages_v2
nvmlReturn_t nvmlDeviceGetRetiredPages_v2(nvmlDevice_t device, nvmlPageRetirementCause_t cause, unsigned int * pageCount, long long unsigned int * addresses, long long unsigned int * timestamps){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetRetiredPages_v2) (nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int *, long long unsigned int *, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int *, long long unsigned int *, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetRetiredPages_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetRetiredPages_v2", kApiTypeNvml);

    lretval = lnvmlDeviceGetRetiredPages_v2(device, cause, pageCount, addresses, timestamps);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetRetiredPages_v2 nvmlDeviceGetRetiredPages_v2


#undef nvmlDeviceGetRetiredPagesPendingStatus
nvmlReturn_t nvmlDeviceGetRetiredPagesPendingStatus(nvmlDevice_t device, nvmlEnableState_t * isPending){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetRetiredPagesPendingStatus) (nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetRetiredPagesPendingStatus");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetRetiredPagesPendingStatus", kApiTypeNvml);

    lretval = lnvmlDeviceGetRetiredPagesPendingStatus(device, isPending);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetRetiredPagesPendingStatus nvmlDeviceGetRetiredPagesPendingStatus


#undef nvmlDeviceGetRemappedRows
nvmlReturn_t nvmlDeviceGetRemappedRows(nvmlDevice_t device, unsigned int * corrRows, unsigned int * uncRows, unsigned int * isPending, unsigned int * failureOccurred){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetRemappedRows) (nvmlDevice_t, unsigned int *, unsigned int *, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, unsigned int *, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetRemappedRows");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetRemappedRows", kApiTypeNvml);

    lretval = lnvmlDeviceGetRemappedRows(device, corrRows, uncRows, isPending, failureOccurred);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetRemappedRows nvmlDeviceGetRemappedRows


#undef nvmlDeviceGetRowRemapperHistogram
nvmlReturn_t nvmlDeviceGetRowRemapperHistogram(nvmlDevice_t device, nvmlRowRemapperHistogramValues_t * values){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetRowRemapperHistogram) (nvmlDevice_t, nvmlRowRemapperHistogramValues_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlRowRemapperHistogramValues_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetRowRemapperHistogram");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetRowRemapperHistogram", kApiTypeNvml);

    lretval = lnvmlDeviceGetRowRemapperHistogram(device, values);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetRowRemapperHistogram nvmlDeviceGetRowRemapperHistogram


#undef nvmlDeviceGetArchitecture
nvmlReturn_t nvmlDeviceGetArchitecture(nvmlDevice_t device, nvmlDeviceArchitecture_t * arch){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetArchitecture) (nvmlDevice_t, nvmlDeviceArchitecture_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlDeviceArchitecture_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetArchitecture");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetArchitecture", kApiTypeNvml);

    lretval = lnvmlDeviceGetArchitecture(device, arch);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetArchitecture nvmlDeviceGetArchitecture


#undef nvmlUnitSetLedState
nvmlReturn_t nvmlUnitSetLedState(nvmlUnit_t unit, nvmlLedColor_t color){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlUnitSetLedState) (nvmlUnit_t, nvmlLedColor_t) = (nvmlReturn_t (*)(nvmlUnit_t, nvmlLedColor_t))dlsym(RTLD_NEXT, "nvmlUnitSetLedState");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlUnitSetLedState", kApiTypeNvml);

    lretval = lnvmlUnitSetLedState(unit, color);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlUnitSetLedState nvmlUnitSetLedState


#undef nvmlDeviceSetPersistenceMode
nvmlReturn_t nvmlDeviceSetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t mode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetPersistenceMode) (nvmlDevice_t, nvmlEnableState_t) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t))dlsym(RTLD_NEXT, "nvmlDeviceSetPersistenceMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetPersistenceMode", kApiTypeNvml);

    lretval = lnvmlDeviceSetPersistenceMode(device, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetPersistenceMode nvmlDeviceSetPersistenceMode


#undef nvmlDeviceSetComputeMode
nvmlReturn_t nvmlDeviceSetComputeMode(nvmlDevice_t device, nvmlComputeMode_t mode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetComputeMode) (nvmlDevice_t, nvmlComputeMode_t) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlComputeMode_t))dlsym(RTLD_NEXT, "nvmlDeviceSetComputeMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetComputeMode", kApiTypeNvml);

    lretval = lnvmlDeviceSetComputeMode(device, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetComputeMode nvmlDeviceSetComputeMode


#undef nvmlDeviceSetEccMode
nvmlReturn_t nvmlDeviceSetEccMode(nvmlDevice_t device, nvmlEnableState_t ecc){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetEccMode) (nvmlDevice_t, nvmlEnableState_t) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t))dlsym(RTLD_NEXT, "nvmlDeviceSetEccMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetEccMode", kApiTypeNvml);

    lretval = lnvmlDeviceSetEccMode(device, ecc);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetEccMode nvmlDeviceSetEccMode


#undef nvmlDeviceClearEccErrorCounts
nvmlReturn_t nvmlDeviceClearEccErrorCounts(nvmlDevice_t device, nvmlEccCounterType_t counterType){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceClearEccErrorCounts) (nvmlDevice_t, nvmlEccCounterType_t) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEccCounterType_t))dlsym(RTLD_NEXT, "nvmlDeviceClearEccErrorCounts");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceClearEccErrorCounts", kApiTypeNvml);

    lretval = lnvmlDeviceClearEccErrorCounts(device, counterType);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceClearEccErrorCounts nvmlDeviceClearEccErrorCounts


#undef nvmlDeviceSetDriverModel
nvmlReturn_t nvmlDeviceSetDriverModel(nvmlDevice_t device, nvmlDriverModel_t driverModel, unsigned int flags){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetDriverModel) (nvmlDevice_t, nvmlDriverModel_t, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlDriverModel_t, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceSetDriverModel");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetDriverModel", kApiTypeNvml);

    lretval = lnvmlDeviceSetDriverModel(device, driverModel, flags);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetDriverModel nvmlDeviceSetDriverModel


#undef nvmlDeviceSetGpuLockedClocks
nvmlReturn_t nvmlDeviceSetGpuLockedClocks(nvmlDevice_t device, unsigned int minGpuClockMHz, unsigned int maxGpuClockMHz){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetGpuLockedClocks) (nvmlDevice_t, unsigned int, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceSetGpuLockedClocks");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetGpuLockedClocks", kApiTypeNvml);

    lretval = lnvmlDeviceSetGpuLockedClocks(device, minGpuClockMHz, maxGpuClockMHz);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetGpuLockedClocks nvmlDeviceSetGpuLockedClocks


#undef nvmlDeviceResetGpuLockedClocks
nvmlReturn_t nvmlDeviceResetGpuLockedClocks(nvmlDevice_t device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceResetGpuLockedClocks) (nvmlDevice_t) = (nvmlReturn_t (*)(nvmlDevice_t))dlsym(RTLD_NEXT, "nvmlDeviceResetGpuLockedClocks");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceResetGpuLockedClocks", kApiTypeNvml);

    lretval = lnvmlDeviceResetGpuLockedClocks(device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceResetGpuLockedClocks nvmlDeviceResetGpuLockedClocks


#undef nvmlDeviceSetMemoryLockedClocks
nvmlReturn_t nvmlDeviceSetMemoryLockedClocks(nvmlDevice_t device, unsigned int minMemClockMHz, unsigned int maxMemClockMHz){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetMemoryLockedClocks) (nvmlDevice_t, unsigned int, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceSetMemoryLockedClocks");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetMemoryLockedClocks", kApiTypeNvml);

    lretval = lnvmlDeviceSetMemoryLockedClocks(device, minMemClockMHz, maxMemClockMHz);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetMemoryLockedClocks nvmlDeviceSetMemoryLockedClocks


#undef nvmlDeviceResetMemoryLockedClocks
nvmlReturn_t nvmlDeviceResetMemoryLockedClocks(nvmlDevice_t device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceResetMemoryLockedClocks) (nvmlDevice_t) = (nvmlReturn_t (*)(nvmlDevice_t))dlsym(RTLD_NEXT, "nvmlDeviceResetMemoryLockedClocks");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceResetMemoryLockedClocks", kApiTypeNvml);

    lretval = lnvmlDeviceResetMemoryLockedClocks(device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceResetMemoryLockedClocks nvmlDeviceResetMemoryLockedClocks


#undef nvmlDeviceSetApplicationsClocks
nvmlReturn_t nvmlDeviceSetApplicationsClocks(nvmlDevice_t device, unsigned int memClockMHz, unsigned int graphicsClockMHz){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetApplicationsClocks) (nvmlDevice_t, unsigned int, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceSetApplicationsClocks");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetApplicationsClocks", kApiTypeNvml);

    lretval = lnvmlDeviceSetApplicationsClocks(device, memClockMHz, graphicsClockMHz);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetApplicationsClocks nvmlDeviceSetApplicationsClocks


#undef nvmlDeviceSetPowerManagementLimit
nvmlReturn_t nvmlDeviceSetPowerManagementLimit(nvmlDevice_t device, unsigned int limit){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetPowerManagementLimit) (nvmlDevice_t, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceSetPowerManagementLimit");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetPowerManagementLimit", kApiTypeNvml);

    lretval = lnvmlDeviceSetPowerManagementLimit(device, limit);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetPowerManagementLimit nvmlDeviceSetPowerManagementLimit


#undef nvmlDeviceSetGpuOperationMode
nvmlReturn_t nvmlDeviceSetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t mode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetGpuOperationMode) (nvmlDevice_t, nvmlGpuOperationMode_t) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlGpuOperationMode_t))dlsym(RTLD_NEXT, "nvmlDeviceSetGpuOperationMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetGpuOperationMode", kApiTypeNvml);

    lretval = lnvmlDeviceSetGpuOperationMode(device, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetGpuOperationMode nvmlDeviceSetGpuOperationMode


#undef nvmlDeviceSetAPIRestriction
nvmlReturn_t nvmlDeviceSetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t isRestricted){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetAPIRestriction) (nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t))dlsym(RTLD_NEXT, "nvmlDeviceSetAPIRestriction");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetAPIRestriction", kApiTypeNvml);

    lretval = lnvmlDeviceSetAPIRestriction(device, apiType, isRestricted);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetAPIRestriction nvmlDeviceSetAPIRestriction


#undef nvmlDeviceSetAccountingMode
nvmlReturn_t nvmlDeviceSetAccountingMode(nvmlDevice_t device, nvmlEnableState_t mode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetAccountingMode) (nvmlDevice_t, nvmlEnableState_t) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlEnableState_t))dlsym(RTLD_NEXT, "nvmlDeviceSetAccountingMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetAccountingMode", kApiTypeNvml);

    lretval = lnvmlDeviceSetAccountingMode(device, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetAccountingMode nvmlDeviceSetAccountingMode


#undef nvmlDeviceClearAccountingPids
nvmlReturn_t nvmlDeviceClearAccountingPids(nvmlDevice_t device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceClearAccountingPids) (nvmlDevice_t) = (nvmlReturn_t (*)(nvmlDevice_t))dlsym(RTLD_NEXT, "nvmlDeviceClearAccountingPids");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceClearAccountingPids", kApiTypeNvml);

    lretval = lnvmlDeviceClearAccountingPids(device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceClearAccountingPids nvmlDeviceClearAccountingPids


#undef nvmlDeviceGetNvLinkState
nvmlReturn_t nvmlDeviceGetNvLinkState(nvmlDevice_t device, unsigned int link, nvmlEnableState_t * isActive){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetNvLinkState) (nvmlDevice_t, unsigned int, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetNvLinkState");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetNvLinkState", kApiTypeNvml);

    lretval = lnvmlDeviceGetNvLinkState(device, link, isActive);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetNvLinkState nvmlDeviceGetNvLinkState


#undef nvmlDeviceGetNvLinkVersion
nvmlReturn_t nvmlDeviceGetNvLinkVersion(nvmlDevice_t device, unsigned int link, unsigned int * version){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetNvLinkVersion) (nvmlDevice_t, unsigned int, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetNvLinkVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetNvLinkVersion", kApiTypeNvml);

    lretval = lnvmlDeviceGetNvLinkVersion(device, link, version);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetNvLinkVersion nvmlDeviceGetNvLinkVersion


#undef nvmlDeviceGetNvLinkCapability
nvmlReturn_t nvmlDeviceGetNvLinkCapability(nvmlDevice_t device, unsigned int link, nvmlNvLinkCapability_t capability, unsigned int * capResult){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetNvLinkCapability) (nvmlDevice_t, unsigned int, nvmlNvLinkCapability_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlNvLinkCapability_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetNvLinkCapability");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetNvLinkCapability", kApiTypeNvml);

    lretval = lnvmlDeviceGetNvLinkCapability(device, link, capability, capResult);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetNvLinkCapability nvmlDeviceGetNvLinkCapability


#undef nvmlDeviceGetNvLinkRemotePciInfo_v2
nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo_v2(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t * pci){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetNvLinkRemotePciInfo_v2) (nvmlDevice_t, unsigned int, nvmlPciInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlPciInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetNvLinkRemotePciInfo_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetNvLinkRemotePciInfo_v2", kApiTypeNvml);

    lretval = lnvmlDeviceGetNvLinkRemotePciInfo_v2(device, link, pci);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetNvLinkRemotePciInfo_v2 nvmlDeviceGetNvLinkRemotePciInfo_v2


#undef nvmlDeviceGetNvLinkRemotePciInfo
nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t * pci){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetNvLinkRemotePciInfo) (nvmlDevice_t, unsigned int, nvmlPciInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlPciInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetNvLinkRemotePciInfo_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetNvLinkRemotePciInfo", kApiTypeNvml);

    lretval = lnvmlDeviceGetNvLinkRemotePciInfo(device, link, pci);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetNvLinkRemotePciInfo nvmlDeviceGetNvLinkRemotePciInfo_v2


#undef nvmlDeviceGetNvLinkErrorCounter
nvmlReturn_t nvmlDeviceGetNvLinkErrorCounter(nvmlDevice_t device, unsigned int link, nvmlNvLinkErrorCounter_t counter, long long unsigned int * counterValue){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetNvLinkErrorCounter) (nvmlDevice_t, unsigned int, nvmlNvLinkErrorCounter_t, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlNvLinkErrorCounter_t, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetNvLinkErrorCounter");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetNvLinkErrorCounter", kApiTypeNvml);

    lretval = lnvmlDeviceGetNvLinkErrorCounter(device, link, counter, counterValue);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetNvLinkErrorCounter nvmlDeviceGetNvLinkErrorCounter


#undef nvmlDeviceResetNvLinkErrorCounters
nvmlReturn_t nvmlDeviceResetNvLinkErrorCounters(nvmlDevice_t device, unsigned int link){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceResetNvLinkErrorCounters) (nvmlDevice_t, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceResetNvLinkErrorCounters");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceResetNvLinkErrorCounters", kApiTypeNvml);

    lretval = lnvmlDeviceResetNvLinkErrorCounters(device, link);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceResetNvLinkErrorCounters nvmlDeviceResetNvLinkErrorCounters


#undef nvmlDeviceSetNvLinkUtilizationControl
nvmlReturn_t nvmlDeviceSetNvLinkUtilizationControl(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t * control, unsigned int reset){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetNvLinkUtilizationControl) (nvmlDevice_t, unsigned int, unsigned int, nvmlNvLinkUtilizationControl_t *, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int, nvmlNvLinkUtilizationControl_t *, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceSetNvLinkUtilizationControl");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetNvLinkUtilizationControl", kApiTypeNvml);

    lretval = lnvmlDeviceSetNvLinkUtilizationControl(device, link, counter, control, reset);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetNvLinkUtilizationControl nvmlDeviceSetNvLinkUtilizationControl


#undef nvmlDeviceGetNvLinkUtilizationControl
nvmlReturn_t nvmlDeviceGetNvLinkUtilizationControl(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t * control){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetNvLinkUtilizationControl) (nvmlDevice_t, unsigned int, unsigned int, nvmlNvLinkUtilizationControl_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int, nvmlNvLinkUtilizationControl_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetNvLinkUtilizationControl");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetNvLinkUtilizationControl", kApiTypeNvml);

    lretval = lnvmlDeviceGetNvLinkUtilizationControl(device, link, counter, control);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetNvLinkUtilizationControl nvmlDeviceGetNvLinkUtilizationControl


#undef nvmlDeviceGetNvLinkUtilizationCounter
nvmlReturn_t nvmlDeviceGetNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter, long long unsigned int * rxcounter, long long unsigned int * txcounter){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetNvLinkUtilizationCounter) (nvmlDevice_t, unsigned int, unsigned int, long long unsigned int *, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int, long long unsigned int *, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetNvLinkUtilizationCounter");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetNvLinkUtilizationCounter", kApiTypeNvml);

    lretval = lnvmlDeviceGetNvLinkUtilizationCounter(device, link, counter, rxcounter, txcounter);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetNvLinkUtilizationCounter nvmlDeviceGetNvLinkUtilizationCounter


#undef nvmlDeviceFreezeNvLinkUtilizationCounter
nvmlReturn_t nvmlDeviceFreezeNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlEnableState_t freeze){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceFreezeNvLinkUtilizationCounter) (nvmlDevice_t, unsigned int, unsigned int, nvmlEnableState_t) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int, nvmlEnableState_t))dlsym(RTLD_NEXT, "nvmlDeviceFreezeNvLinkUtilizationCounter");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceFreezeNvLinkUtilizationCounter", kApiTypeNvml);

    lretval = lnvmlDeviceFreezeNvLinkUtilizationCounter(device, link, counter, freeze);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceFreezeNvLinkUtilizationCounter nvmlDeviceFreezeNvLinkUtilizationCounter


#undef nvmlDeviceResetNvLinkUtilizationCounter
nvmlReturn_t nvmlDeviceResetNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceResetNvLinkUtilizationCounter) (nvmlDevice_t, unsigned int, unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceResetNvLinkUtilizationCounter");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceResetNvLinkUtilizationCounter", kApiTypeNvml);

    lretval = lnvmlDeviceResetNvLinkUtilizationCounter(device, link, counter);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceResetNvLinkUtilizationCounter nvmlDeviceResetNvLinkUtilizationCounter


#undef nvmlEventSetCreate
nvmlReturn_t nvmlEventSetCreate(nvmlEventSet_t * set){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlEventSetCreate) (nvmlEventSet_t *) = (nvmlReturn_t (*)(nvmlEventSet_t *))dlsym(RTLD_NEXT, "nvmlEventSetCreate");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlEventSetCreate", kApiTypeNvml);

    lretval = lnvmlEventSetCreate(set);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlEventSetCreate nvmlEventSetCreate


#undef nvmlDeviceRegisterEvents
nvmlReturn_t nvmlDeviceRegisterEvents(nvmlDevice_t device, long long unsigned int eventTypes, nvmlEventSet_t set){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceRegisterEvents) (nvmlDevice_t, long long unsigned int, nvmlEventSet_t) = (nvmlReturn_t (*)(nvmlDevice_t, long long unsigned int, nvmlEventSet_t))dlsym(RTLD_NEXT, "nvmlDeviceRegisterEvents");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceRegisterEvents", kApiTypeNvml);

    lretval = lnvmlDeviceRegisterEvents(device, eventTypes, set);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceRegisterEvents nvmlDeviceRegisterEvents


#undef nvmlDeviceGetSupportedEventTypes
nvmlReturn_t nvmlDeviceGetSupportedEventTypes(nvmlDevice_t device, long long unsigned int * eventTypes){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetSupportedEventTypes) (nvmlDevice_t, long long unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetSupportedEventTypes");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetSupportedEventTypes", kApiTypeNvml);

    lretval = lnvmlDeviceGetSupportedEventTypes(device, eventTypes);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetSupportedEventTypes nvmlDeviceGetSupportedEventTypes


#undef nvmlEventSetWait_v2
nvmlReturn_t nvmlEventSetWait_v2(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlEventSetWait_v2) (nvmlEventSet_t, nvmlEventData_t *, unsigned int) = (nvmlReturn_t (*)(nvmlEventSet_t, nvmlEventData_t *, unsigned int))dlsym(RTLD_NEXT, "nvmlEventSetWait_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlEventSetWait_v2", kApiTypeNvml);

    lretval = lnvmlEventSetWait_v2(set, data, timeoutms);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlEventSetWait_v2 nvmlEventSetWait_v2


#undef nvmlEventSetWait
nvmlReturn_t nvmlEventSetWait(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlEventSetWait) (nvmlEventSet_t, nvmlEventData_t *, unsigned int) = (nvmlReturn_t (*)(nvmlEventSet_t, nvmlEventData_t *, unsigned int))dlsym(RTLD_NEXT, "nvmlEventSetWait_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlEventSetWait", kApiTypeNvml);

    lretval = lnvmlEventSetWait(set, data, timeoutms);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlEventSetWait nvmlEventSetWait_v2


#undef nvmlEventSetFree
nvmlReturn_t nvmlEventSetFree(nvmlEventSet_t set){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlEventSetFree) (nvmlEventSet_t) = (nvmlReturn_t (*)(nvmlEventSet_t))dlsym(RTLD_NEXT, "nvmlEventSetFree");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlEventSetFree", kApiTypeNvml);

    lretval = lnvmlEventSetFree(set);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlEventSetFree nvmlEventSetFree


#undef nvmlDeviceModifyDrainState
nvmlReturn_t nvmlDeviceModifyDrainState(nvmlPciInfo_t * pciInfo, nvmlEnableState_t newState){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceModifyDrainState) (nvmlPciInfo_t *, nvmlEnableState_t) = (nvmlReturn_t (*)(nvmlPciInfo_t *, nvmlEnableState_t))dlsym(RTLD_NEXT, "nvmlDeviceModifyDrainState");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceModifyDrainState", kApiTypeNvml);

    lretval = lnvmlDeviceModifyDrainState(pciInfo, newState);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceModifyDrainState nvmlDeviceModifyDrainState


#undef nvmlDeviceQueryDrainState
nvmlReturn_t nvmlDeviceQueryDrainState(nvmlPciInfo_t * pciInfo, nvmlEnableState_t * currentState){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceQueryDrainState) (nvmlPciInfo_t *, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlPciInfo_t *, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlDeviceQueryDrainState");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceQueryDrainState", kApiTypeNvml);

    lretval = lnvmlDeviceQueryDrainState(pciInfo, currentState);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceQueryDrainState nvmlDeviceQueryDrainState


#undef nvmlDeviceRemoveGpu_v2
nvmlReturn_t nvmlDeviceRemoveGpu_v2(nvmlPciInfo_t * pciInfo, nvmlDetachGpuState_t gpuState, nvmlPcieLinkState_t linkState){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceRemoveGpu_v2) (nvmlPciInfo_t *, nvmlDetachGpuState_t, nvmlPcieLinkState_t) = (nvmlReturn_t (*)(nvmlPciInfo_t *, nvmlDetachGpuState_t, nvmlPcieLinkState_t))dlsym(RTLD_NEXT, "nvmlDeviceRemoveGpu_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceRemoveGpu_v2", kApiTypeNvml);

    lretval = lnvmlDeviceRemoveGpu_v2(pciInfo, gpuState, linkState);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceRemoveGpu_v2 nvmlDeviceRemoveGpu_v2


#undef nvmlDeviceRemoveGpu
nvmlReturn_t nvmlDeviceRemoveGpu(nvmlPciInfo_t * pciInfo, nvmlDetachGpuState_t gpuState, nvmlPcieLinkState_t linkState){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceRemoveGpu) (nvmlPciInfo_t *, nvmlDetachGpuState_t, nvmlPcieLinkState_t) = (nvmlReturn_t (*)(nvmlPciInfo_t *, nvmlDetachGpuState_t, nvmlPcieLinkState_t))dlsym(RTLD_NEXT, "nvmlDeviceRemoveGpu_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceRemoveGpu", kApiTypeNvml);

    lretval = lnvmlDeviceRemoveGpu(pciInfo, gpuState, linkState);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceRemoveGpu nvmlDeviceRemoveGpu_v2


#undef nvmlDeviceDiscoverGpus
nvmlReturn_t nvmlDeviceDiscoverGpus(nvmlPciInfo_t * pciInfo){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceDiscoverGpus) (nvmlPciInfo_t *) = (nvmlReturn_t (*)(nvmlPciInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceDiscoverGpus");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceDiscoverGpus", kApiTypeNvml);

    lretval = lnvmlDeviceDiscoverGpus(pciInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceDiscoverGpus nvmlDeviceDiscoverGpus


#undef nvmlDeviceGetFieldValues
nvmlReturn_t nvmlDeviceGetFieldValues(nvmlDevice_t device, int valuesCount, nvmlFieldValue_t * values){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetFieldValues) (nvmlDevice_t, int, nvmlFieldValue_t *) = (nvmlReturn_t (*)(nvmlDevice_t, int, nvmlFieldValue_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetFieldValues");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetFieldValues", kApiTypeNvml);

    lretval = lnvmlDeviceGetFieldValues(device, valuesCount, values);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetFieldValues nvmlDeviceGetFieldValues


#undef nvmlDeviceGetVirtualizationMode
nvmlReturn_t nvmlDeviceGetVirtualizationMode(nvmlDevice_t device, nvmlGpuVirtualizationMode_t * pVirtualMode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetVirtualizationMode) (nvmlDevice_t, nvmlGpuVirtualizationMode_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlGpuVirtualizationMode_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetVirtualizationMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetVirtualizationMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetVirtualizationMode(device, pVirtualMode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetVirtualizationMode nvmlDeviceGetVirtualizationMode


#undef nvmlDeviceGetHostVgpuMode
nvmlReturn_t nvmlDeviceGetHostVgpuMode(nvmlDevice_t device, nvmlHostVgpuMode_t * pHostVgpuMode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetHostVgpuMode) (nvmlDevice_t, nvmlHostVgpuMode_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlHostVgpuMode_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetHostVgpuMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetHostVgpuMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetHostVgpuMode(device, pHostVgpuMode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetHostVgpuMode nvmlDeviceGetHostVgpuMode


#undef nvmlDeviceSetVirtualizationMode
nvmlReturn_t nvmlDeviceSetVirtualizationMode(nvmlDevice_t device, nvmlGpuVirtualizationMode_t virtualMode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetVirtualizationMode) (nvmlDevice_t, nvmlGpuVirtualizationMode_t) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlGpuVirtualizationMode_t))dlsym(RTLD_NEXT, "nvmlDeviceSetVirtualizationMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetVirtualizationMode", kApiTypeNvml);

    lretval = lnvmlDeviceSetVirtualizationMode(device, virtualMode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetVirtualizationMode nvmlDeviceSetVirtualizationMode


#undef nvmlDeviceGetGridLicensableFeatures_v3
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v3(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGridLicensableFeatures_v3) (nvmlDevice_t, nvmlGridLicensableFeatures_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlGridLicensableFeatures_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetGridLicensableFeatures_v3");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGridLicensableFeatures_v3", kApiTypeNvml);

    lretval = lnvmlDeviceGetGridLicensableFeatures_v3(device, pGridLicensableFeatures);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGridLicensableFeatures_v3 nvmlDeviceGetGridLicensableFeatures_v3


#undef nvmlDeviceGetGridLicensableFeatures
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGridLicensableFeatures) (nvmlDevice_t, nvmlGridLicensableFeatures_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlGridLicensableFeatures_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetGridLicensableFeatures_v3");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGridLicensableFeatures", kApiTypeNvml);

    lretval = lnvmlDeviceGetGridLicensableFeatures(device, pGridLicensableFeatures);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGridLicensableFeatures nvmlDeviceGetGridLicensableFeatures_v3


#undef nvmlDeviceGetProcessUtilization
nvmlReturn_t nvmlDeviceGetProcessUtilization(nvmlDevice_t device, nvmlProcessUtilizationSample_t * utilization, unsigned int * processSamplesCount, long long unsigned int lastSeenTimeStamp){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetProcessUtilization) (nvmlDevice_t, nvmlProcessUtilizationSample_t *, unsigned int *, long long unsigned int) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlProcessUtilizationSample_t *, unsigned int *, long long unsigned int))dlsym(RTLD_NEXT, "nvmlDeviceGetProcessUtilization");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetProcessUtilization", kApiTypeNvml);

    lretval = lnvmlDeviceGetProcessUtilization(device, utilization, processSamplesCount, lastSeenTimeStamp);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetProcessUtilization nvmlDeviceGetProcessUtilization


#undef nvmlDeviceGetSupportedVgpus
nvmlReturn_t nvmlDeviceGetSupportedVgpus(nvmlDevice_t device, unsigned int * vgpuCount, nvmlVgpuTypeId_t * vgpuTypeIds){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetSupportedVgpus) (nvmlDevice_t, unsigned int *, nvmlVgpuTypeId_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, nvmlVgpuTypeId_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetSupportedVgpus");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetSupportedVgpus", kApiTypeNvml);

    lretval = lnvmlDeviceGetSupportedVgpus(device, vgpuCount, vgpuTypeIds);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetSupportedVgpus nvmlDeviceGetSupportedVgpus


#undef nvmlDeviceGetCreatableVgpus
nvmlReturn_t nvmlDeviceGetCreatableVgpus(nvmlDevice_t device, unsigned int * vgpuCount, nvmlVgpuTypeId_t * vgpuTypeIds){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetCreatableVgpus) (nvmlDevice_t, unsigned int *, nvmlVgpuTypeId_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, nvmlVgpuTypeId_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetCreatableVgpus");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetCreatableVgpus", kApiTypeNvml);

    lretval = lnvmlDeviceGetCreatableVgpus(device, vgpuCount, vgpuTypeIds);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetCreatableVgpus nvmlDeviceGetCreatableVgpus


#undef nvmlVgpuTypeGetClass
nvmlReturn_t nvmlVgpuTypeGetClass(nvmlVgpuTypeId_t vgpuTypeId, char * vgpuTypeClass, unsigned int * size){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetClass) (nvmlVgpuTypeId_t, char *, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, char *, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetClass");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetClass", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetClass(vgpuTypeId, vgpuTypeClass, size);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetClass nvmlVgpuTypeGetClass


#undef nvmlVgpuTypeGetName
nvmlReturn_t nvmlVgpuTypeGetName(nvmlVgpuTypeId_t vgpuTypeId, char * vgpuTypeName, unsigned int * size){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetName) (nvmlVgpuTypeId_t, char *, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, char *, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetName");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetName", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetName(vgpuTypeId, vgpuTypeName, size);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetName nvmlVgpuTypeGetName


#undef nvmlVgpuTypeGetGpuInstanceProfileId
nvmlReturn_t nvmlVgpuTypeGetGpuInstanceProfileId(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * gpuInstanceProfileId){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetGpuInstanceProfileId) (nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetGpuInstanceProfileId");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetGpuInstanceProfileId", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetGpuInstanceProfileId(vgpuTypeId, gpuInstanceProfileId);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetGpuInstanceProfileId nvmlVgpuTypeGetGpuInstanceProfileId


#undef nvmlVgpuTypeGetDeviceID
nvmlReturn_t nvmlVgpuTypeGetDeviceID(nvmlVgpuTypeId_t vgpuTypeId, long long unsigned int * deviceID, long long unsigned int * subsystemID){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetDeviceID) (nvmlVgpuTypeId_t, long long unsigned int *, long long unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, long long unsigned int *, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetDeviceID");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetDeviceID", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetDeviceID(vgpuTypeId, deviceID, subsystemID);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetDeviceID nvmlVgpuTypeGetDeviceID


#undef nvmlVgpuTypeGetFramebufferSize
nvmlReturn_t nvmlVgpuTypeGetFramebufferSize(nvmlVgpuTypeId_t vgpuTypeId, long long unsigned int * fbSize){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetFramebufferSize) (nvmlVgpuTypeId_t, long long unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetFramebufferSize");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetFramebufferSize", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetFramebufferSize(vgpuTypeId, fbSize);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetFramebufferSize nvmlVgpuTypeGetFramebufferSize


#undef nvmlVgpuTypeGetNumDisplayHeads
nvmlReturn_t nvmlVgpuTypeGetNumDisplayHeads(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * numDisplayHeads){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetNumDisplayHeads) (nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetNumDisplayHeads");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetNumDisplayHeads", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetNumDisplayHeads(vgpuTypeId, numDisplayHeads);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetNumDisplayHeads nvmlVgpuTypeGetNumDisplayHeads


#undef nvmlVgpuTypeGetResolution
nvmlReturn_t nvmlVgpuTypeGetResolution(nvmlVgpuTypeId_t vgpuTypeId, unsigned int displayIndex, unsigned int * xdim, unsigned int * ydim){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetResolution) (nvmlVgpuTypeId_t, unsigned int, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, unsigned int, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetResolution");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetResolution", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetResolution(vgpuTypeId, displayIndex, xdim, ydim);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetResolution nvmlVgpuTypeGetResolution


#undef nvmlVgpuTypeGetLicense
nvmlReturn_t nvmlVgpuTypeGetLicense(nvmlVgpuTypeId_t vgpuTypeId, char * vgpuTypeLicenseString, unsigned int size){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetLicense) (nvmlVgpuTypeId_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetLicense");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetLicense", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetLicense(vgpuTypeId, vgpuTypeLicenseString, size);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetLicense nvmlVgpuTypeGetLicense


#undef nvmlVgpuTypeGetFrameRateLimit
nvmlReturn_t nvmlVgpuTypeGetFrameRateLimit(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * frameRateLimit){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetFrameRateLimit) (nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetFrameRateLimit");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetFrameRateLimit", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetFrameRateLimit(vgpuTypeId, frameRateLimit);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetFrameRateLimit nvmlVgpuTypeGetFrameRateLimit


#undef nvmlVgpuTypeGetMaxInstances
nvmlReturn_t nvmlVgpuTypeGetMaxInstances(nvmlDevice_t device, nvmlVgpuTypeId_t vgpuTypeId, unsigned int * vgpuInstanceCount){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetMaxInstances) (nvmlDevice_t, nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlVgpuTypeId_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetMaxInstances");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetMaxInstances", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetMaxInstances(device, vgpuTypeId, vgpuInstanceCount);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetMaxInstances nvmlVgpuTypeGetMaxInstances


#undef nvmlVgpuTypeGetMaxInstancesPerVm
nvmlReturn_t nvmlVgpuTypeGetMaxInstancesPerVm(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * vgpuInstanceCountPerVm){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuTypeGetMaxInstancesPerVm) (nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuTypeId_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuTypeGetMaxInstancesPerVm");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuTypeGetMaxInstancesPerVm", kApiTypeNvml);

    lretval = lnvmlVgpuTypeGetMaxInstancesPerVm(vgpuTypeId, vgpuInstanceCountPerVm);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuTypeGetMaxInstancesPerVm nvmlVgpuTypeGetMaxInstancesPerVm


#undef nvmlDeviceGetActiveVgpus
nvmlReturn_t nvmlDeviceGetActiveVgpus(nvmlDevice_t device, unsigned int * vgpuCount, nvmlVgpuInstance_t * vgpuInstances){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetActiveVgpus) (nvmlDevice_t, unsigned int *, nvmlVgpuInstance_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, nvmlVgpuInstance_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetActiveVgpus");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetActiveVgpus", kApiTypeNvml);

    lretval = lnvmlDeviceGetActiveVgpus(device, vgpuCount, vgpuInstances);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetActiveVgpus nvmlDeviceGetActiveVgpus


#undef nvmlVgpuInstanceGetVmID
nvmlReturn_t nvmlVgpuInstanceGetVmID(nvmlVgpuInstance_t vgpuInstance, char * vmId, unsigned int size, nvmlVgpuVmIdType_t * vmIdType){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetVmID) (nvmlVgpuInstance_t, char *, unsigned int, nvmlVgpuVmIdType_t *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, char *, unsigned int, nvmlVgpuVmIdType_t *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetVmID");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetVmID", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetVmID(vgpuInstance, vmId, size, vmIdType);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetVmID nvmlVgpuInstanceGetVmID


#undef nvmlVgpuInstanceGetUUID
nvmlReturn_t nvmlVgpuInstanceGetUUID(nvmlVgpuInstance_t vgpuInstance, char * uuid, unsigned int size){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetUUID) (nvmlVgpuInstance_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetUUID");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetUUID", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetUUID(vgpuInstance, uuid, size);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetUUID nvmlVgpuInstanceGetUUID


#undef nvmlVgpuInstanceGetVmDriverVersion
nvmlReturn_t nvmlVgpuInstanceGetVmDriverVersion(nvmlVgpuInstance_t vgpuInstance, char * version, unsigned int length){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetVmDriverVersion) (nvmlVgpuInstance_t, char *, unsigned int) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, char *, unsigned int))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetVmDriverVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetVmDriverVersion", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetVmDriverVersion(vgpuInstance, version, length);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetVmDriverVersion nvmlVgpuInstanceGetVmDriverVersion


#undef nvmlVgpuInstanceGetFbUsage
nvmlReturn_t nvmlVgpuInstanceGetFbUsage(nvmlVgpuInstance_t vgpuInstance, long long unsigned int * fbUsage){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetFbUsage) (nvmlVgpuInstance_t, long long unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, long long unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetFbUsage");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetFbUsage", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetFbUsage(vgpuInstance, fbUsage);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetFbUsage nvmlVgpuInstanceGetFbUsage


#undef nvmlVgpuInstanceGetLicenseStatus
nvmlReturn_t nvmlVgpuInstanceGetLicenseStatus(nvmlVgpuInstance_t vgpuInstance, unsigned int * licensed){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetLicenseStatus) (nvmlVgpuInstance_t, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetLicenseStatus");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetLicenseStatus", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetLicenseStatus(vgpuInstance, licensed);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetLicenseStatus nvmlVgpuInstanceGetLicenseStatus


#undef nvmlVgpuInstanceGetType
nvmlReturn_t nvmlVgpuInstanceGetType(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuTypeId_t * vgpuTypeId){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetType) (nvmlVgpuInstance_t, nvmlVgpuTypeId_t *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, nvmlVgpuTypeId_t *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetType");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetType", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetType(vgpuInstance, vgpuTypeId);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetType nvmlVgpuInstanceGetType


#undef nvmlVgpuInstanceGetFrameRateLimit
nvmlReturn_t nvmlVgpuInstanceGetFrameRateLimit(nvmlVgpuInstance_t vgpuInstance, unsigned int * frameRateLimit){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetFrameRateLimit) (nvmlVgpuInstance_t, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetFrameRateLimit");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetFrameRateLimit", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetFrameRateLimit(vgpuInstance, frameRateLimit);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetFrameRateLimit nvmlVgpuInstanceGetFrameRateLimit


#undef nvmlVgpuInstanceGetEccMode
nvmlReturn_t nvmlVgpuInstanceGetEccMode(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t * eccMode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetEccMode) (nvmlVgpuInstance_t, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetEccMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetEccMode", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetEccMode(vgpuInstance, eccMode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetEccMode nvmlVgpuInstanceGetEccMode


#undef nvmlVgpuInstanceGetEncoderCapacity
nvmlReturn_t nvmlVgpuInstanceGetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance, unsigned int * encoderCapacity){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetEncoderCapacity) (nvmlVgpuInstance_t, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetEncoderCapacity");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetEncoderCapacity", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetEncoderCapacity(vgpuInstance, encoderCapacity);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetEncoderCapacity nvmlVgpuInstanceGetEncoderCapacity


#undef nvmlVgpuInstanceSetEncoderCapacity
nvmlReturn_t nvmlVgpuInstanceSetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance, unsigned int encoderCapacity){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceSetEncoderCapacity) (nvmlVgpuInstance_t, unsigned int) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int))dlsym(RTLD_NEXT, "nvmlVgpuInstanceSetEncoderCapacity");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceSetEncoderCapacity", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceSetEncoderCapacity(vgpuInstance, encoderCapacity);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceSetEncoderCapacity nvmlVgpuInstanceSetEncoderCapacity


#undef nvmlVgpuInstanceGetEncoderStats
nvmlReturn_t nvmlVgpuInstanceGetEncoderStats(nvmlVgpuInstance_t vgpuInstance, unsigned int * sessionCount, unsigned int * averageFps, unsigned int * averageLatency){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetEncoderStats) (nvmlVgpuInstance_t, unsigned int *, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int *, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetEncoderStats");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetEncoderStats", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetEncoderStats(vgpuInstance, sessionCount, averageFps, averageLatency);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetEncoderStats nvmlVgpuInstanceGetEncoderStats


#undef nvmlVgpuInstanceGetEncoderSessions
nvmlReturn_t nvmlVgpuInstanceGetEncoderSessions(nvmlVgpuInstance_t vgpuInstance, unsigned int * sessionCount, nvmlEncoderSessionInfo_t * sessionInfo){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetEncoderSessions) (nvmlVgpuInstance_t, unsigned int *, nvmlEncoderSessionInfo_t *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int *, nvmlEncoderSessionInfo_t *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetEncoderSessions");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetEncoderSessions", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetEncoderSessions(vgpuInstance, sessionCount, sessionInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetEncoderSessions nvmlVgpuInstanceGetEncoderSessions


#undef nvmlVgpuInstanceGetFBCStats
nvmlReturn_t nvmlVgpuInstanceGetFBCStats(nvmlVgpuInstance_t vgpuInstance, nvmlFBCStats_t * fbcStats){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetFBCStats) (nvmlVgpuInstance_t, nvmlFBCStats_t *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, nvmlFBCStats_t *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetFBCStats");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetFBCStats", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetFBCStats(vgpuInstance, fbcStats);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetFBCStats nvmlVgpuInstanceGetFBCStats


#undef nvmlVgpuInstanceGetFBCSessions
nvmlReturn_t nvmlVgpuInstanceGetFBCSessions(nvmlVgpuInstance_t vgpuInstance, unsigned int * sessionCount, nvmlFBCSessionInfo_t * sessionInfo){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetFBCSessions) (nvmlVgpuInstance_t, unsigned int *, nvmlFBCSessionInfo_t *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int *, nvmlFBCSessionInfo_t *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetFBCSessions");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetFBCSessions", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetFBCSessions(vgpuInstance, sessionCount, sessionInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetFBCSessions nvmlVgpuInstanceGetFBCSessions


#undef nvmlVgpuInstanceGetGpuInstanceId
nvmlReturn_t nvmlVgpuInstanceGetGpuInstanceId(nvmlVgpuInstance_t vgpuInstance, unsigned int * gpuInstanceId){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetGpuInstanceId) (nvmlVgpuInstance_t, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetGpuInstanceId");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetGpuInstanceId", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetGpuInstanceId(vgpuInstance, gpuInstanceId);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetGpuInstanceId nvmlVgpuInstanceGetGpuInstanceId


#undef nvmlVgpuInstanceGetMetadata
nvmlReturn_t nvmlVgpuInstanceGetMetadata(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuMetadata_t * vgpuMetadata, unsigned int * bufferSize){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetMetadata) (nvmlVgpuInstance_t, nvmlVgpuMetadata_t *, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, nvmlVgpuMetadata_t *, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetMetadata");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetMetadata", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetMetadata(vgpuInstance, vgpuMetadata, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetMetadata nvmlVgpuInstanceGetMetadata


#undef nvmlDeviceGetVgpuMetadata
nvmlReturn_t nvmlDeviceGetVgpuMetadata(nvmlDevice_t device, nvmlVgpuPgpuMetadata_t * pgpuMetadata, unsigned int * bufferSize){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetVgpuMetadata) (nvmlDevice_t, nvmlVgpuPgpuMetadata_t *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlVgpuPgpuMetadata_t *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetVgpuMetadata");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetVgpuMetadata", kApiTypeNvml);

    lretval = lnvmlDeviceGetVgpuMetadata(device, pgpuMetadata, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetVgpuMetadata nvmlDeviceGetVgpuMetadata


#undef nvmlGetVgpuCompatibility
nvmlReturn_t nvmlGetVgpuCompatibility(nvmlVgpuMetadata_t * vgpuMetadata, nvmlVgpuPgpuMetadata_t * pgpuMetadata, nvmlVgpuPgpuCompatibility_t * compatibilityInfo){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGetVgpuCompatibility) (nvmlVgpuMetadata_t *, nvmlVgpuPgpuMetadata_t *, nvmlVgpuPgpuCompatibility_t *) = (nvmlReturn_t (*)(nvmlVgpuMetadata_t *, nvmlVgpuPgpuMetadata_t *, nvmlVgpuPgpuCompatibility_t *))dlsym(RTLD_NEXT, "nvmlGetVgpuCompatibility");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGetVgpuCompatibility", kApiTypeNvml);

    lretval = lnvmlGetVgpuCompatibility(vgpuMetadata, pgpuMetadata, compatibilityInfo);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGetVgpuCompatibility nvmlGetVgpuCompatibility


#undef nvmlDeviceGetPgpuMetadataString
nvmlReturn_t nvmlDeviceGetPgpuMetadataString(nvmlDevice_t device, char * pgpuMetadata, unsigned int * bufferSize){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetPgpuMetadataString) (nvmlDevice_t, char *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, char *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetPgpuMetadataString");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetPgpuMetadataString", kApiTypeNvml);

    lretval = lnvmlDeviceGetPgpuMetadataString(device, pgpuMetadata, bufferSize);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetPgpuMetadataString nvmlDeviceGetPgpuMetadataString


#undef nvmlGetVgpuVersion
nvmlReturn_t nvmlGetVgpuVersion(nvmlVgpuVersion_t * supported, nvmlVgpuVersion_t * current){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGetVgpuVersion) (nvmlVgpuVersion_t *, nvmlVgpuVersion_t *) = (nvmlReturn_t (*)(nvmlVgpuVersion_t *, nvmlVgpuVersion_t *))dlsym(RTLD_NEXT, "nvmlGetVgpuVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGetVgpuVersion", kApiTypeNvml);

    lretval = lnvmlGetVgpuVersion(supported, current);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGetVgpuVersion nvmlGetVgpuVersion


#undef nvmlSetVgpuVersion
nvmlReturn_t nvmlSetVgpuVersion(nvmlVgpuVersion_t * vgpuVersion){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlSetVgpuVersion) (nvmlVgpuVersion_t *) = (nvmlReturn_t (*)(nvmlVgpuVersion_t *))dlsym(RTLD_NEXT, "nvmlSetVgpuVersion");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlSetVgpuVersion", kApiTypeNvml);

    lretval = lnvmlSetVgpuVersion(vgpuVersion);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlSetVgpuVersion nvmlSetVgpuVersion


#undef nvmlDeviceGetVgpuUtilization
nvmlReturn_t nvmlDeviceGetVgpuUtilization(nvmlDevice_t device, long long unsigned int lastSeenTimeStamp, nvmlValueType_t * sampleValType, unsigned int * vgpuInstanceSamplesCount, nvmlVgpuInstanceUtilizationSample_t * utilizationSamples){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetVgpuUtilization) (nvmlDevice_t, long long unsigned int, nvmlValueType_t *, unsigned int *, nvmlVgpuInstanceUtilizationSample_t *) = (nvmlReturn_t (*)(nvmlDevice_t, long long unsigned int, nvmlValueType_t *, unsigned int *, nvmlVgpuInstanceUtilizationSample_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetVgpuUtilization");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetVgpuUtilization", kApiTypeNvml);

    lretval = lnvmlDeviceGetVgpuUtilization(device, lastSeenTimeStamp, sampleValType, vgpuInstanceSamplesCount, utilizationSamples);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetVgpuUtilization nvmlDeviceGetVgpuUtilization


#undef nvmlDeviceGetVgpuProcessUtilization
nvmlReturn_t nvmlDeviceGetVgpuProcessUtilization(nvmlDevice_t device, long long unsigned int lastSeenTimeStamp, unsigned int * vgpuProcessSamplesCount, nvmlVgpuProcessUtilizationSample_t * utilizationSamples){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetVgpuProcessUtilization) (nvmlDevice_t, long long unsigned int, unsigned int *, nvmlVgpuProcessUtilizationSample_t *) = (nvmlReturn_t (*)(nvmlDevice_t, long long unsigned int, unsigned int *, nvmlVgpuProcessUtilizationSample_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetVgpuProcessUtilization");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetVgpuProcessUtilization", kApiTypeNvml);

    lretval = lnvmlDeviceGetVgpuProcessUtilization(device, lastSeenTimeStamp, vgpuProcessSamplesCount, utilizationSamples);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetVgpuProcessUtilization nvmlDeviceGetVgpuProcessUtilization


#undef nvmlVgpuInstanceGetAccountingMode
nvmlReturn_t nvmlVgpuInstanceGetAccountingMode(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t * mode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetAccountingMode) (nvmlVgpuInstance_t, nvmlEnableState_t *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, nvmlEnableState_t *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetAccountingMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetAccountingMode", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetAccountingMode(vgpuInstance, mode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetAccountingMode nvmlVgpuInstanceGetAccountingMode


#undef nvmlVgpuInstanceGetAccountingPids
nvmlReturn_t nvmlVgpuInstanceGetAccountingPids(nvmlVgpuInstance_t vgpuInstance, unsigned int * count, unsigned int * pids){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetAccountingPids) (nvmlVgpuInstance_t, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetAccountingPids");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetAccountingPids", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetAccountingPids(vgpuInstance, count, pids);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetAccountingPids nvmlVgpuInstanceGetAccountingPids


#undef nvmlVgpuInstanceGetAccountingStats
nvmlReturn_t nvmlVgpuInstanceGetAccountingStats(nvmlVgpuInstance_t vgpuInstance, unsigned int pid, nvmlAccountingStats_t * stats){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceGetAccountingStats) (nvmlVgpuInstance_t, unsigned int, nvmlAccountingStats_t *) = (nvmlReturn_t (*)(nvmlVgpuInstance_t, unsigned int, nvmlAccountingStats_t *))dlsym(RTLD_NEXT, "nvmlVgpuInstanceGetAccountingStats");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceGetAccountingStats", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceGetAccountingStats(vgpuInstance, pid, stats);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceGetAccountingStats nvmlVgpuInstanceGetAccountingStats


#undef nvmlVgpuInstanceClearAccountingPids
nvmlReturn_t nvmlVgpuInstanceClearAccountingPids(nvmlVgpuInstance_t vgpuInstance){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlVgpuInstanceClearAccountingPids) (nvmlVgpuInstance_t) = (nvmlReturn_t (*)(nvmlVgpuInstance_t))dlsym(RTLD_NEXT, "nvmlVgpuInstanceClearAccountingPids");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlVgpuInstanceClearAccountingPids", kApiTypeNvml);

    lretval = lnvmlVgpuInstanceClearAccountingPids(vgpuInstance);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlVgpuInstanceClearAccountingPids nvmlVgpuInstanceClearAccountingPids


#undef nvmlGetExcludedDeviceCount
nvmlReturn_t nvmlGetExcludedDeviceCount(unsigned int * deviceCount){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGetExcludedDeviceCount) (unsigned int *) = (nvmlReturn_t (*)(unsigned int *))dlsym(RTLD_NEXT, "nvmlGetExcludedDeviceCount");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGetExcludedDeviceCount", kApiTypeNvml);

    lretval = lnvmlGetExcludedDeviceCount(deviceCount);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGetExcludedDeviceCount nvmlGetExcludedDeviceCount


#undef nvmlGetBlacklistDeviceCount
nvmlReturn_t nvmlGetBlacklistDeviceCount(unsigned int * deviceCount){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGetBlacklistDeviceCount) (unsigned int *) = (nvmlReturn_t (*)(unsigned int *))dlsym(RTLD_NEXT, "nvmlGetExcludedDeviceCount");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGetBlacklistDeviceCount", kApiTypeNvml);

    lretval = lnvmlGetBlacklistDeviceCount(deviceCount);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGetBlacklistDeviceCount nvmlGetExcludedDeviceCount


#undef nvmlGetExcludedDeviceInfoByIndex
nvmlReturn_t nvmlGetExcludedDeviceInfoByIndex(unsigned int index, nvmlExcludedDeviceInfo_t * info){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGetExcludedDeviceInfoByIndex) (unsigned int, nvmlExcludedDeviceInfo_t *) = (nvmlReturn_t (*)(unsigned int, nvmlExcludedDeviceInfo_t *))dlsym(RTLD_NEXT, "nvmlGetExcludedDeviceInfoByIndex");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGetExcludedDeviceInfoByIndex", kApiTypeNvml);

    lretval = lnvmlGetExcludedDeviceInfoByIndex(index, info);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGetExcludedDeviceInfoByIndex nvmlGetExcludedDeviceInfoByIndex


#undef nvmlGetBlacklistDeviceInfoByIndex
nvmlReturn_t nvmlGetBlacklistDeviceInfoByIndex(unsigned int index, nvmlExcludedDeviceInfo_t * info){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGetBlacklistDeviceInfoByIndex) (unsigned int, nvmlExcludedDeviceInfo_t *) = (nvmlReturn_t (*)(unsigned int, nvmlExcludedDeviceInfo_t *))dlsym(RTLD_NEXT, "nvmlGetExcludedDeviceInfoByIndex");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGetBlacklistDeviceInfoByIndex", kApiTypeNvml);

    lretval = lnvmlGetBlacklistDeviceInfoByIndex(index, info);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGetBlacklistDeviceInfoByIndex nvmlGetExcludedDeviceInfoByIndex


#undef nvmlDeviceSetMigMode
nvmlReturn_t nvmlDeviceSetMigMode(nvmlDevice_t device, unsigned int mode, nvmlReturn_t * activationStatus){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceSetMigMode) (nvmlDevice_t, unsigned int, nvmlReturn_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlReturn_t *))dlsym(RTLD_NEXT, "nvmlDeviceSetMigMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceSetMigMode", kApiTypeNvml);

    lretval = lnvmlDeviceSetMigMode(device, mode, activationStatus);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceSetMigMode nvmlDeviceSetMigMode


#undef nvmlDeviceGetMigMode
nvmlReturn_t nvmlDeviceGetMigMode(nvmlDevice_t device, unsigned int * currentMode, unsigned int * pendingMode){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMigMode) (nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetMigMode");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMigMode", kApiTypeNvml);

    lretval = lnvmlDeviceGetMigMode(device, currentMode, pendingMode);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMigMode nvmlDeviceGetMigMode


#undef nvmlDeviceGetGpuInstanceProfileInfo
nvmlReturn_t nvmlDeviceGetGpuInstanceProfileInfo(nvmlDevice_t device, unsigned int profile, nvmlGpuInstanceProfileInfo_t * info){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGpuInstanceProfileInfo) (nvmlDevice_t, unsigned int, nvmlGpuInstanceProfileInfo_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlGpuInstanceProfileInfo_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetGpuInstanceProfileInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGpuInstanceProfileInfo", kApiTypeNvml);

    lretval = lnvmlDeviceGetGpuInstanceProfileInfo(device, profile, info);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGpuInstanceProfileInfo nvmlDeviceGetGpuInstanceProfileInfo


#undef nvmlDeviceGetGpuInstancePossiblePlacements
nvmlReturn_t nvmlDeviceGetGpuInstancePossiblePlacements(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t * placements, unsigned int * count){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGpuInstancePossiblePlacements) (nvmlDevice_t, unsigned int, nvmlGpuInstancePlacement_t *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlGpuInstancePlacement_t *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetGpuInstancePossiblePlacements");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGpuInstancePossiblePlacements", kApiTypeNvml);

    lretval = lnvmlDeviceGetGpuInstancePossiblePlacements(device, profileId, placements, count);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGpuInstancePossiblePlacements nvmlDeviceGetGpuInstancePossiblePlacements


#undef nvmlDeviceGetGpuInstanceRemainingCapacity
nvmlReturn_t nvmlDeviceGetGpuInstanceRemainingCapacity(nvmlDevice_t device, unsigned int profileId, unsigned int * count){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGpuInstanceRemainingCapacity) (nvmlDevice_t, unsigned int, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetGpuInstanceRemainingCapacity");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGpuInstanceRemainingCapacity", kApiTypeNvml);

    lretval = lnvmlDeviceGetGpuInstanceRemainingCapacity(device, profileId, count);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGpuInstanceRemainingCapacity nvmlDeviceGetGpuInstanceRemainingCapacity


#undef nvmlDeviceCreateGpuInstance
nvmlReturn_t nvmlDeviceCreateGpuInstance(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t * gpuInstance){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceCreateGpuInstance) (nvmlDevice_t, unsigned int, nvmlGpuInstance_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlGpuInstance_t *))dlsym(RTLD_NEXT, "nvmlDeviceCreateGpuInstance");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceCreateGpuInstance", kApiTypeNvml);

    lretval = lnvmlDeviceCreateGpuInstance(device, profileId, gpuInstance);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceCreateGpuInstance nvmlDeviceCreateGpuInstance


#undef nvmlDeviceCreateGpuInstanceWithPlacement
nvmlReturn_t nvmlDeviceCreateGpuInstanceWithPlacement(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t const * placement, nvmlGpuInstance_t * gpuInstance){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceCreateGpuInstanceWithPlacement) (nvmlDevice_t, unsigned int, nvmlGpuInstancePlacement_t const *, nvmlGpuInstance_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlGpuInstancePlacement_t const *, nvmlGpuInstance_t *))dlsym(RTLD_NEXT, "nvmlDeviceCreateGpuInstanceWithPlacement");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceCreateGpuInstanceWithPlacement", kApiTypeNvml);

    lretval = lnvmlDeviceCreateGpuInstanceWithPlacement(device, profileId, placement, gpuInstance);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceCreateGpuInstanceWithPlacement nvmlDeviceCreateGpuInstanceWithPlacement


#undef nvmlGpuInstanceDestroy
nvmlReturn_t nvmlGpuInstanceDestroy(nvmlGpuInstance_t gpuInstance){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGpuInstanceDestroy) (nvmlGpuInstance_t) = (nvmlReturn_t (*)(nvmlGpuInstance_t))dlsym(RTLD_NEXT, "nvmlGpuInstanceDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGpuInstanceDestroy", kApiTypeNvml);

    lretval = lnvmlGpuInstanceDestroy(gpuInstance);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGpuInstanceDestroy nvmlGpuInstanceDestroy


#undef nvmlDeviceGetGpuInstances
nvmlReturn_t nvmlDeviceGetGpuInstances(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t * gpuInstances, unsigned int * count){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGpuInstances) (nvmlDevice_t, unsigned int, nvmlGpuInstance_t *, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlGpuInstance_t *, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetGpuInstances");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGpuInstances", kApiTypeNvml);

    lretval = lnvmlDeviceGetGpuInstances(device, profileId, gpuInstances, count);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGpuInstances nvmlDeviceGetGpuInstances


#undef nvmlDeviceGetGpuInstanceById
nvmlReturn_t nvmlDeviceGetGpuInstanceById(nvmlDevice_t device, unsigned int id, nvmlGpuInstance_t * gpuInstance){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGpuInstanceById) (nvmlDevice_t, unsigned int, nvmlGpuInstance_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlGpuInstance_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetGpuInstanceById");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGpuInstanceById", kApiTypeNvml);

    lretval = lnvmlDeviceGetGpuInstanceById(device, id, gpuInstance);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGpuInstanceById nvmlDeviceGetGpuInstanceById


#undef nvmlGpuInstanceGetInfo
nvmlReturn_t nvmlGpuInstanceGetInfo(nvmlGpuInstance_t gpuInstance, nvmlGpuInstanceInfo_t * info){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGpuInstanceGetInfo) (nvmlGpuInstance_t, nvmlGpuInstanceInfo_t *) = (nvmlReturn_t (*)(nvmlGpuInstance_t, nvmlGpuInstanceInfo_t *))dlsym(RTLD_NEXT, "nvmlGpuInstanceGetInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGpuInstanceGetInfo", kApiTypeNvml);

    lretval = lnvmlGpuInstanceGetInfo(gpuInstance, info);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGpuInstanceGetInfo nvmlGpuInstanceGetInfo


#undef nvmlGpuInstanceGetComputeInstanceProfileInfo
nvmlReturn_t nvmlGpuInstanceGetComputeInstanceProfileInfo(nvmlGpuInstance_t gpuInstance, unsigned int profile, unsigned int engProfile, nvmlComputeInstanceProfileInfo_t * info){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGpuInstanceGetComputeInstanceProfileInfo) (nvmlGpuInstance_t, unsigned int, unsigned int, nvmlComputeInstanceProfileInfo_t *) = (nvmlReturn_t (*)(nvmlGpuInstance_t, unsigned int, unsigned int, nvmlComputeInstanceProfileInfo_t *))dlsym(RTLD_NEXT, "nvmlGpuInstanceGetComputeInstanceProfileInfo");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGpuInstanceGetComputeInstanceProfileInfo", kApiTypeNvml);

    lretval = lnvmlGpuInstanceGetComputeInstanceProfileInfo(gpuInstance, profile, engProfile, info);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGpuInstanceGetComputeInstanceProfileInfo nvmlGpuInstanceGetComputeInstanceProfileInfo


#undef nvmlGpuInstanceGetComputeInstanceRemainingCapacity
nvmlReturn_t nvmlGpuInstanceGetComputeInstanceRemainingCapacity(nvmlGpuInstance_t gpuInstance, unsigned int profileId, unsigned int * count){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGpuInstanceGetComputeInstanceRemainingCapacity) (nvmlGpuInstance_t, unsigned int, unsigned int *) = (nvmlReturn_t (*)(nvmlGpuInstance_t, unsigned int, unsigned int *))dlsym(RTLD_NEXT, "nvmlGpuInstanceGetComputeInstanceRemainingCapacity");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGpuInstanceGetComputeInstanceRemainingCapacity", kApiTypeNvml);

    lretval = lnvmlGpuInstanceGetComputeInstanceRemainingCapacity(gpuInstance, profileId, count);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGpuInstanceGetComputeInstanceRemainingCapacity nvmlGpuInstanceGetComputeInstanceRemainingCapacity


#undef nvmlGpuInstanceCreateComputeInstance
nvmlReturn_t nvmlGpuInstanceCreateComputeInstance(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t * computeInstance){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGpuInstanceCreateComputeInstance) (nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *) = (nvmlReturn_t (*)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *))dlsym(RTLD_NEXT, "nvmlGpuInstanceCreateComputeInstance");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGpuInstanceCreateComputeInstance", kApiTypeNvml);

    lretval = lnvmlGpuInstanceCreateComputeInstance(gpuInstance, profileId, computeInstance);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGpuInstanceCreateComputeInstance nvmlGpuInstanceCreateComputeInstance


#undef nvmlComputeInstanceDestroy
nvmlReturn_t nvmlComputeInstanceDestroy(nvmlComputeInstance_t computeInstance){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlComputeInstanceDestroy) (nvmlComputeInstance_t) = (nvmlReturn_t (*)(nvmlComputeInstance_t))dlsym(RTLD_NEXT, "nvmlComputeInstanceDestroy");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlComputeInstanceDestroy", kApiTypeNvml);

    lretval = lnvmlComputeInstanceDestroy(computeInstance);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlComputeInstanceDestroy nvmlComputeInstanceDestroy


#undef nvmlGpuInstanceGetComputeInstances
nvmlReturn_t nvmlGpuInstanceGetComputeInstances(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t * computeInstances, unsigned int * count){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGpuInstanceGetComputeInstances) (nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *, unsigned int *) = (nvmlReturn_t (*)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *, unsigned int *))dlsym(RTLD_NEXT, "nvmlGpuInstanceGetComputeInstances");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGpuInstanceGetComputeInstances", kApiTypeNvml);

    lretval = lnvmlGpuInstanceGetComputeInstances(gpuInstance, profileId, computeInstances, count);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGpuInstanceGetComputeInstances nvmlGpuInstanceGetComputeInstances


#undef nvmlGpuInstanceGetComputeInstanceById
nvmlReturn_t nvmlGpuInstanceGetComputeInstanceById(nvmlGpuInstance_t gpuInstance, unsigned int id, nvmlComputeInstance_t * computeInstance){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlGpuInstanceGetComputeInstanceById) (nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *) = (nvmlReturn_t (*)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *))dlsym(RTLD_NEXT, "nvmlGpuInstanceGetComputeInstanceById");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlGpuInstanceGetComputeInstanceById", kApiTypeNvml);

    lretval = lnvmlGpuInstanceGetComputeInstanceById(gpuInstance, id, computeInstance);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlGpuInstanceGetComputeInstanceById nvmlGpuInstanceGetComputeInstanceById


#undef nvmlComputeInstanceGetInfo_v2
nvmlReturn_t nvmlComputeInstanceGetInfo_v2(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t * info){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlComputeInstanceGetInfo_v2) (nvmlComputeInstance_t, nvmlComputeInstanceInfo_t *) = (nvmlReturn_t (*)(nvmlComputeInstance_t, nvmlComputeInstanceInfo_t *))dlsym(RTLD_NEXT, "nvmlComputeInstanceGetInfo_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlComputeInstanceGetInfo_v2", kApiTypeNvml);

    lretval = lnvmlComputeInstanceGetInfo_v2(computeInstance, info);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlComputeInstanceGetInfo_v2 nvmlComputeInstanceGetInfo_v2


#undef nvmlComputeInstanceGetInfo
nvmlReturn_t nvmlComputeInstanceGetInfo(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t * info){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlComputeInstanceGetInfo) (nvmlComputeInstance_t, nvmlComputeInstanceInfo_t *) = (nvmlReturn_t (*)(nvmlComputeInstance_t, nvmlComputeInstanceInfo_t *))dlsym(RTLD_NEXT, "nvmlComputeInstanceGetInfo_v2");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlComputeInstanceGetInfo", kApiTypeNvml);

    lretval = lnvmlComputeInstanceGetInfo(computeInstance, info);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlComputeInstanceGetInfo nvmlComputeInstanceGetInfo_v2


#undef nvmlDeviceIsMigDeviceHandle
nvmlReturn_t nvmlDeviceIsMigDeviceHandle(nvmlDevice_t device, unsigned int * isMigDevice){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceIsMigDeviceHandle) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceIsMigDeviceHandle");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceIsMigDeviceHandle", kApiTypeNvml);

    lretval = lnvmlDeviceIsMigDeviceHandle(device, isMigDevice);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceIsMigDeviceHandle nvmlDeviceIsMigDeviceHandle


#undef nvmlDeviceGetGpuInstanceId
nvmlReturn_t nvmlDeviceGetGpuInstanceId(nvmlDevice_t device, unsigned int * id){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetGpuInstanceId) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetGpuInstanceId");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetGpuInstanceId", kApiTypeNvml);

    lretval = lnvmlDeviceGetGpuInstanceId(device, id);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetGpuInstanceId nvmlDeviceGetGpuInstanceId


#undef nvmlDeviceGetComputeInstanceId
nvmlReturn_t nvmlDeviceGetComputeInstanceId(nvmlDevice_t device, unsigned int * id){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetComputeInstanceId) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetComputeInstanceId");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetComputeInstanceId", kApiTypeNvml);

    lretval = lnvmlDeviceGetComputeInstanceId(device, id);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetComputeInstanceId nvmlDeviceGetComputeInstanceId


#undef nvmlDeviceGetMaxMigDeviceCount
nvmlReturn_t nvmlDeviceGetMaxMigDeviceCount(nvmlDevice_t device, unsigned int * count){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMaxMigDeviceCount) (nvmlDevice_t, unsigned int *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int *))dlsym(RTLD_NEXT, "nvmlDeviceGetMaxMigDeviceCount");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMaxMigDeviceCount", kApiTypeNvml);

    lretval = lnvmlDeviceGetMaxMigDeviceCount(device, count);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMaxMigDeviceCount nvmlDeviceGetMaxMigDeviceCount


#undef nvmlDeviceGetMigDeviceHandleByIndex
nvmlReturn_t nvmlDeviceGetMigDeviceHandleByIndex(nvmlDevice_t device, unsigned int index, nvmlDevice_t * migDevice){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetMigDeviceHandleByIndex) (nvmlDevice_t, unsigned int, nvmlDevice_t *) = (nvmlReturn_t (*)(nvmlDevice_t, unsigned int, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetMigDeviceHandleByIndex");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetMigDeviceHandleByIndex", kApiTypeNvml);

    lretval = lnvmlDeviceGetMigDeviceHandleByIndex(device, index, migDevice);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetMigDeviceHandleByIndex nvmlDeviceGetMigDeviceHandleByIndex


#undef nvmlDeviceGetDeviceHandleFromMigDeviceHandle
nvmlReturn_t nvmlDeviceGetDeviceHandleFromMigDeviceHandle(nvmlDevice_t migDevice, nvmlDevice_t * device){
    nvmlReturn_t lretval;
    nvmlReturn_t (*lnvmlDeviceGetDeviceHandleFromMigDeviceHandle) (nvmlDevice_t, nvmlDevice_t *) = (nvmlReturn_t (*)(nvmlDevice_t, nvmlDevice_t *))dlsym(RTLD_NEXT, "nvmlDeviceGetDeviceHandleFromMigDeviceHandle");
    
    /* pre exeuction logics */
    ac.add_counter("nvmlDeviceGetDeviceHandleFromMigDeviceHandle", kApiTypeNvml);

    lretval = lnvmlDeviceGetDeviceHandleFromMigDeviceHandle(migDevice, device);
    
    /* post exeuction logics */

    return lretval;
}
#define nvmlDeviceGetDeviceHandleFromMigDeviceHandle nvmlDeviceGetDeviceHandleFromMigDeviceHandle

