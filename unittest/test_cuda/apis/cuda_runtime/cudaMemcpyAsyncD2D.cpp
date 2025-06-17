#include "test_cuda/test_cuda_common.h"

TEST_F(PhOSCudaTest, cudaMemcpyAsyncD2D) {
    uint64_t i;
    cudaError cuda_retval;
    void *src_mem_ptr = nullptr, *dst_mem_ptr = nullptr;
    void **src_mem_ptr_ = &src_mem_ptr;
    void **dst_mem_ptr_ = &dst_mem_ptr;
    std::vector<void*> src_allocated_mem_ptrs;
    std::vector<void*> dst_allocated_mem_ptrs;
    cudaMemcpyKind kind = cudaMemcpyDeviceToDevice;
    cudaStream_t stream = 0;
    std::vector<size_t> mem_sizes({ 
        1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 
        KB(1), KB(2), KB(4), KB(8), KB(16), KB(32), KB(64), KB(128), KB(256), KB(512),
        MB(1), MB(2), MB(4), MB(8), MB(16), MB(32), MB(64), MB(128), MB(256), MB(512)
    });

    // malloc GPU memory for source and destination
    for(uint64_t& mem_size : mem_sizes){
        // Allocate source memory
        cuda_retval = (cudaError)this->_ws->pos_process( 
            /* api_id */ PosApiIndex_cudaMalloc, 
            /* uuid */ this->_clnt->id,
            /* param_desps */ {
                { .value = &src_mem_ptr_, .size = sizeof(void**) },
                { .value = &mem_size, .size = sizeof(size_t) }
            }
        );
        EXPECT_EQ(cudaSuccess, cuda_retval);
        src_allocated_mem_ptrs.push_back(src_mem_ptr);

        // Allocate destination memory
        cuda_retval = (cudaError)this->_ws->pos_process( 
            /* api_id */ PosApiIndex_cudaMalloc, 
            /* uuid */ this->_clnt->id,
            /* param_desps */ {
                { .value = &dst_mem_ptr_, .size = sizeof(void**) },
                { .value = &mem_size, .size = sizeof(size_t) }
            }
        );
        EXPECT_EQ(cudaSuccess, cuda_retval);
        dst_allocated_mem_ptrs.push_back(dst_mem_ptr);
    }

    // copy data from source GPU memory to destination GPU memory
    for(i=0; i<mem_sizes.size(); i++){
        // async copy
        cuda_retval = (cudaError)this->_ws->pos_process( 
            /* api_id */ PosApiIndex_cudaMemcpyAsyncD2D, 
            /* uuid */ this->_clnt->id,
            /* param_desps */ {
                { .value = &(dst_allocated_mem_ptrs[i]), .size = sizeof(void*) },
                { .value = &(src_allocated_mem_ptrs[i]), .size = sizeof(const void*) },
                { .value = &(mem_sizes[i]), .size = sizeof(size_t) },
                { .value = &kind, .size = sizeof(cudaMemcpyKind) },
                { .value = &stream, .size = sizeof(cudaStream_t) }
            }
        );
        EXPECT_EQ(cudaSuccess, cuda_retval);

        // stream synchronize
        cuda_retval = (cudaError)this->_ws->pos_process( 
            /* api_id */ PosApiIndex_cudaStreamSynchronize, 
            /* uuid */ this->_clnt->id,
            /* param_desps */ {
                { .value = &stream, .size = sizeof(cudaStream_t) }
            }
        );
        EXPECT_EQ(cudaSuccess, cuda_retval);
    }
}
