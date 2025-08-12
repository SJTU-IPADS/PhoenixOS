#include "test_cuda/test_cuda_common.h"

TEST_F(PhOSCudaTest, cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags) {
    CUresult cuda_retval;
    CUmodule module;
    CUmodule *module_ptr = &module;
    CUfunction function;
    CUfunction *function_ptr = &function;
    std::ifstream in;
    std::stringstream buffer;
    std::string function_name;
    const char* function_name_ptr;
    int numBlocks;
    int* numBlocks_ptr = &numBlocks;
    int blockSize = 256;  // 示例块大小
    size_t dynamicSMemSize = 0;  // 假设不使用动态共享内存
    unsigned int flags = 0;  // 默认标志

    // 获取测试文件路径
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

    // 打开并读取模块文件
    in.open(cubin_asb_path, std::ios::binary);
    EXPECT_EQ(true, in.is_open());
    buffer << in.rdbuf();

    // 加载模块
    cuda_retval = (CUresult)this->_ws->pos_process(
        /* api_id */ PosApiIndex_cuModuleLoadData,
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &module_ptr, .size = sizeof(CUmodule*) },
            { .value = buffer.str().data(), .size = buffer.str().size() }
        }
    );
    EXPECT_EQ(CUDA_SUCCESS, cuda_retval);

    // 获取函数
    function_name = "_Z15squareMatrixMulPKiS0_Pii";  // 示例函数名
    function_name_ptr = function_name.data();

    cuda_retval = (CUresult)this->_ws->pos_process(
        /* api_id */ PosApiIndex_cuModuleGetFunction,
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &function_ptr, .size = sizeof(CUfunction*) },
            { .value = &module, .size = sizeof(CUmodule) },
            { .value = &function_name_ptr, .size = sizeof(const char*) }
        }
    );
    EXPECT_EQ(CUDA_SUCCESS, cuda_retval);

    // 测试目标API - 计算占用率
    cuda_retval = (CUresult)this->_ws->pos_process(
        /* api_id */ PosApiIndex_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags,
        /* uuid */ this->_clnt->id,
        /* param_desps */ {
            { .value = &numBlocks_ptr, .size = sizeof(int*) },
            { .value = &function, .size = sizeof(CUfunction) },
            { .value = &blockSize, .size = sizeof(int) },
            { .value = &dynamicSMemSize, .size = sizeof(size_t) },
            { .value = &flags, .size = sizeof(unsigned int) }
        }
    );
    EXPECT_EQ(CUDA_SUCCESS, cuda_retval);
    EXPECT_GT(numBlocks, 0);  // 验证返回的块数是有效的

exit:
    if(in.is_open()){
        in.close();
    }
}
