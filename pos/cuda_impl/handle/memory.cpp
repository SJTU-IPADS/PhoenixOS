#include <iostream>
#include <map>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/memory.h"

std::map<int, CUdeviceptr>  POSHandleManager_CUDA_Memory::alloc_ptrs;
std::map<int, uint64_t>     POSHandleManager_CUDA_Memory::alloc_granularities;
bool                        POSHandleManager_CUDA_Memory::has_finshed_reserved;
const uint64_t              POSHandleManager_CUDA_Memory::reserved_vm_base = 0x7facd0000000;
