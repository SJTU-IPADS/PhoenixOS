#include "test_cuda/test_cuda_common.h"


TEST_F(PhOSCudaTest, cuLaunchKernel) {
    cudaError cuda_rt_retval;
    CUresult cuda_dv_retval;
    CUmodule module;
    CUmodule *module_ptr = &module;
    CUfunction function;
    CUfunction *function_ptr = &function;
    CUstream stream;
    std::ifstream in;
    std::stringstream buffer;
    std::string function_name;
    const char* function_name_ptr;

    int *mem_A = nullptr, *mem_B = nullptr, *mem_C = nullptr;
    int **mem_A_ptr = &mem_A, **mem_B_ptr = &mem_B, **mem_C_ptr = &mem_C;
    int N = 8;
    uint64_t mem_size = N * N * sizeof(int);

    unsigned int gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes;
    void *list_params = nullptr, *list_extra = nullptr;
    uint64_t list_params_size = 0;

    std::filesystem::path current_path = __FILE__;
    std::filesystem::path current_abs_path = std::filesystem::absolute(current_path);
    std::filesystem::path current_dir_abs_path = current_abs_path.parent_path();
    std::filesystem::path current_dir_dir_abs_path = current_dir_abs_path.parent_path();

    #if CUDA_VERSION >= 9000 && CUDA_VERSION < 11040
        std::filesystem::path cubin_asb_path = std::filesystem::canonical(
            current_dir_dir_abs_path / "assets" / "sm70_72_75_80_86.fatbin"
        );
    #else
        POS_WARN("no test file for current cuda architecture: cuda_version(%d)", CUDA_VERSION);
        goto exit;
    #endif

    in.open(cubin_asb_path, std::ios::binary);
    EXPECT_EQ(true, in.is_open());
    buffer << in.rdbuf();

    // load module first
    cuda_rt_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cuModuleLoadData, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ { 
            { .value = &module_ptr, .size = sizeof(CUmodule*) },
            { .value = buffer.str().data(), .size = buffer.str().size() }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_rt_retval);

    function_name = "_Z15squareMatrixMulPKiS0_Pii";
    function_name_ptr = function_name.data();
    
    // get function
    cuda_rt_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cuModuleGetFunction, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ { 
            { .value = &function_ptr, .size = sizeof(CUfunction*) },
            { .value = &module, .size = sizeof(CUmodule) },
            { .value = &function_name_ptr, .size = sizeof(const char*) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_rt_retval);

    // allocate memory for computation
    cuda_rt_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaMalloc, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &mem_A_ptr, .size = sizeof(void**) },
            { .value = &mem_size, .size = sizeof(uint64_t) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_rt_retval);

    cuda_rt_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaMalloc, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &mem_B_ptr, .size = sizeof(void**) },
            { .value = &mem_size, .size = sizeof(uint64_t) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_rt_retval);

    cuda_rt_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaMalloc, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &mem_C_ptr, .size = sizeof(void**) },
            { .value = &mem_size, .size = sizeof(uint64_t) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_rt_retval);

    // formup parameters list of the kernel
    list_params_size = sizeof(mem_A) + sizeof(mem_B) + sizeof(mem_C) + sizeof(N);
    POS_CHECK_POINTER(list_params = malloc(list_params_size));
    memcpy(list_params, &mem_A, sizeof(mem_A));
    memcpy(list_params + sizeof(mem_A), &mem_B, sizeof(mem_B));
    memcpy(list_params + sizeof(mem_A) + sizeof(mem_B), &mem_C, sizeof(mem_C));
    memcpy(list_params + sizeof(mem_A) + sizeof(mem_B) + sizeof(mem_C), &N, sizeof(N));

    // formup launching parameters
    stream = 0;
    gridDimX = 1;
    gridDimY = 1;
    gridDimZ = 1;
    blockDimX = 32;
    blockDimY = 32;
    blockDimZ = 1;
    sharedMemBytes = 0;

    // launch kernel
    cuda_dv_retval = (CUresult)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cuLaunchKernel, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ { 
            { .value = &function, .size = sizeof(CUfunction) },
            { .value = &gridDimX, .size = sizeof(unsigned int) },
            { .value = &gridDimY, .size = sizeof(unsigned int) },
            { .value = &gridDimZ, .size = sizeof(unsigned int) },
            { .value = &blockDimX, .size = sizeof(unsigned int) },
            { .value = &blockDimY, .size = sizeof(unsigned int) },
            { .value = &blockDimZ, .size = sizeof(unsigned int) },
            { .value = &sharedMemBytes, .size = sizeof(unsigned int) },
            { .value = &stream, .size = sizeof(CUstream) },
            { .value = list_params, .size = list_params_size },
            { .value = list_extra, .size = 0 }
        }
    );
    EXPECT_EQ(CUDA_SUCCESS, cuda_dv_retval);

    // we can free list_params right after launch kernel
    free(list_params);

    // stream synchronize
    cuda_rt_retval = (cudaError)this->_ws->pos_process( 
        /* api_id */ PosApiIndex_cudaStreamSynchronize, 
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &stream, .size = sizeof(CUstream) }
        }
    );
    EXPECT_EQ(cudaSuccess, cuda_rt_retval);

exit:
    if(in.is_open()){
        in.close();
    }
}
