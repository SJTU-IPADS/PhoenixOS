#include "test_cuda_common.h"

TEST(CUDA_PER_API_TEST, cudaMalloc) {
    uint64_t i;
    cudaError cuda_retval;
    void *mem_ptr;
    std::vector<void*> mem_ptrs;
    std::vector<int> mem_sizes({ 16, 512, KB(1), KB(2), KB(4), KB(8) });

    POS_CHECK_POINTER(pos_cuda_ws != nullptr);
    POS_CHECK_POINTER(clnt != nullptr);

    for(int mem_size : mem_sizes){
        cuda_retval = (cudaError)pos_cuda_ws->pos_process( 
            /* api_id */ CUDA_MALLOC, 
            /* uuid */ pos_client_uuid,
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
