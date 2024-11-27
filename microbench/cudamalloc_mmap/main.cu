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
    uint64_t size = 64 * 2097152;

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
    req_ptr = 0x555000000000;
    CHECK_DRV(cuMemAddressReserve(&ptr, sz, 4*1024*1024, req_ptr, 0ULL));
        
    printf("cuda vm: %p, aligned_sz: %lu\n", ptr, aligned_sz);

    CHECK_DRV(cuMemCreate(&hdl, sz, &prop, 0));
    CHECK_DRV(cuMemMap(ptr+32*2097152, sz, 0ULL, hdl, 0ULL));
    CHECK_DRV(cuMemSetAccess(ptr+32*2097152, sz, &accessDesc, 1ULL));
    CHECK_DRV(cuMemUnmap(ptr+32*2097152, sz));
     CHECK_DRV(cuMemAddressFree(ptr+32*2097152, sz));
    CHECK_DRV(cuMemRelease(hdl));
}
