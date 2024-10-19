#include "test_cuda/test_cuda_common.h"

TEST_F(PhOSCudaTest, cudaMalloc) {
    uint64_t i;

    POSWorkspace_CUDA *ws;
    POSClient_CUDA *clnt;

    cudaError cuda_retval;
    void *mem_ptr;
    std::vector<void*> mem_ptrs;
    std::vector<int> mem_sizes({ 16, 512, KB(1), KB(2), KB(4), KB(8) });

    for(int mem_size : mem_sizes){
        cuda_retval = (cudaError)this->_ws->pos_process( 
            /* api_id */ CUDA_MALLOC, 
            /* uuid */ this->_clnt->id,
            /* param_desps */ {
                { .value = &mem_size, .size = sizeof(size_t) }
            },
            /* ret_data */ &(mem_ptr),
            /* ret_data_len */ sizeof(uint64_t)
        );
        EXPECT_EQ(cudaSuccess, cuda_retval);
        mem_ptrs.push_back(mem_ptr);
    }
}
