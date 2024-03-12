#include <iostream>

#include "cpu_rpc_prot.h"

#include "pos/common.h"
#include "pos/agent.h"
#include "pos/transport.h"
#include "pos/api_context.h"

POSAgent *pos_agent; 

typedef struct api_call_meta {
    uint64_t api_id;
    std::vector<POSAPIParamDesp_t> param_desps;
    int ret_code;
    uint8_t ret_data[512];
    uint64_t ret_data_size;
} api_call_meta_t;

int main(){
    api_call_meta_t call_meta;

    size_t mock_param_size_t_1;
    uint8_t mock_param_array_1[32] = {0};
    uint64_t mock_param_uint64_t_1;
    
    pos_agent = new POSAgent<POSTransport_SHM>();
    POS_CHECK_POINTER(pos_agent);
    
    // mock call cudaLoadModule
    // memset(&call_meta, 0, sizeof(api_call_meta_t));
    // call_meta.api_id = rpc_cuModuleLoad;
    // mock_param_size_t_1 = 64;
    // call_meta.param_desps.insert(call_meta.param_desps.begin(), {
    //     { .value = &mock_param_uint64_t_1, .size = sizeof(uint64_t) },
    //     { .value = mock_param_array_1, .size = sizeof(mock_param_array_1) }
    // });
    // call_meta.ret_data_size = 0;
    // pos_agent->oob_call(kPOS_Oob_Mock_Api_Call, &call_meta);
    // POS_DEBUG("cuModuleLoad: retcode(%d)", call_meta.ret_code);

    // mock call cudaMalloc
    memset(&call_meta, 0, sizeof(api_call_meta_t));
    call_meta.api_id = CUDA_MALLOC;
    mock_param_size_t_1 = 64;
    call_meta.param_desps.push_back({
        .value = &mock_param_size_t_1,
        .size = sizeof(size_t)
    });
    call_meta.ret_data_size = sizeof(uint64_t);
    pos_agent->oob_call(kPOS_Oob_Mock_Api_Call, &call_meta);
    POS_DEBUG("cuda_malloc: retcode(%d), addr(%p)", call_meta.ret_code, *((uint64_t*)(call_meta.ret_data)));

    delete pos_agent;
}
