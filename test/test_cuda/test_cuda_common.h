#pragma once

#include <iostream>
#include <vector>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "gtest/gtest.h"

#include "pos/include/common.h"
#include "pos/include/transport.h"
#include "pos/cuda_impl/workspace.h"
#include "pos/cuda_impl/api_index.h"

extern POSWorkspace_CUDA *pos_cuda_ws;
extern POSClient *clnt;
extern uint64_t pos_client_uuid;
