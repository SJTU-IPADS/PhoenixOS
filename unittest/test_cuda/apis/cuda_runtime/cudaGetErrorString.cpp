#include "test_cuda/test_cuda_common.h"

TEST_F(PhOSCudaTest, cudaGetErrorString) {
    cudaError cuda_retval;
    cudaError_t error_code = cudaSuccess;
    std::string error_string;

    error_string.resize(1024);
    cuda_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaGetErrorString, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ { 
            {.value = &error_code, .size = sizeof(cudaError_t) }
        },
        /* ret_data */ error_string.data(),
        /* ret_data_len */ error_string.size()
    );
    EXPECT_EQ(cudaSuccess, cuda_retval);
    POS_LOG("!!!! %s", error_string.c_str());
    // EXPECT_STREQ("no error", error_string);
}
