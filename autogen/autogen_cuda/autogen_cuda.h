#pragma once

#include "autogen_common.h"

enum pos_cuda_resource : uint16_t {
    kPOS_CUDAResource_Memory = 0,
    kPOS_CUDAResource_Stream,
    kPOS_CUDAResource_Event,
    kPOS_CUDAResource_Module,
    kPOS_CUDAResource_Function,
};
