#include <iostream>

#include <cuda.h>
#include <cuda_runtime_api.h>

#define ROUND_UP(size, aligned_size)    ((size + aligned_size - 1) / aligned_size) * aligned_size;

static inline void
checkRtError(cudaError_t res, const char *tok, const char *file, unsigned line)
{
    if (res != cudaSuccess) {
        std::cerr << file << ':' << line << ' ' << tok
                  << "failed (" << (unsigned)res << "): " << cudaGetErrorString(res) << std::endl;
        abort();
    }
}

#define CHECK_RT(x) checkRtError(x, #x, __FILE__, __LINE__);

static inline void
checkDrvError(CUresult res, const char *tok, const char *file, unsigned line)
{
    if (res != CUDA_SUCCESS) {
        const char *errStr = NULL;
        (void)cuGetErrorString(res, &errStr);
        std::cerr << file << ':' << line << ' ' << tok
                  << "failed (" << (unsigned)res << "): " << errStr << std::endl;
        abort();
    }
}

#define CHECK_DRV(x) checkDrvError(x, #x, __FILE__, __LINE__);

int main(){
    CUmemAllocationProp prop = {};
    size_t sz, aligned_sz;
    CUmemGenericAllocationHandle hdl;
    CUmemAccessDesc accessDesc;
    CUdeviceptr ptr, req_ptr;
    int dev = 0;
    uint64_t size = 8192;

    // init runtime
    CHECK_RT(cudaSetDevice(dev));

    prop.type = CU_MEM_ALLOCATION_TYPE_PINNED;
    prop.location.type = CU_MEM_LOCATION_TYPE_DEVICE;
    prop.location.id = dev;
    accessDesc.location = prop.location;
    accessDesc.flags = CU_MEM_ACCESS_FLAGS_PROT_READWRITE;

    CHECK_DRV(cuMemGetAllocationGranularity(&aligned_sz, &prop, CU_MEM_ALLOC_GRANULARITY_MINIMUM));
    sz = ROUND_UP(size, aligned_sz);

    // give a hint (48-bit GPU memory address)
    req_ptr = 0x555500000000;
    CHECK_DRV(cuMemAddressReserve(&ptr, sz, 0ULL, req_ptr, 0ULL));
    CHECK_DRV(cuMemCreate(&hdl, sz, &prop, 0));
    CHECK_DRV(cuMemMap(ptr, sz, 0ULL, hdl, 0ULL));
    CHECK_DRV(cuMemSetAccess(ptr, sz, &accessDesc, 1ULL));

    printf("cuda vm: %p\n", ptr);

    CHECK_DRV(cuMemUnmap(ptr, sz));
    CHECK_DRV(cuMemAddressFree(ptr, sz));
    CHECK_DRV(cuMemRelease(hdl));
}
