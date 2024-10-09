#include "test_cuda_common.h"

POSWorkspace_CUDA *pos_cuda_ws = nullptr;
POSClient *clnt = nullptr;
uint64_t pos_client_uuid;

int main(int argc, char *argv[]){
    uint64_t i, api_id;

    ::testing::InitGoogleTest(&argc, argv);

    // initialize PhOS CUDA workspace
    // TODO: mock pos argc and argv
    POS_CHECK_POINTER( pos_cuda_ws = new POSWorkspace_CUDA(argc, argv) );
    pos_cuda_ws->init();

    // mock a fake client
    pos_cuda_ws->create_client(&clnt, &pos_client_uuid);
    pos_cuda_ws->create_qp(pos_client_uuid);

    return RUN_ALL_TESTS();
}
