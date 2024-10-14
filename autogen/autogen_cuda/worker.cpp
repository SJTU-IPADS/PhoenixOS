#include "autogen_cuda.h"


pos_retval_t POSAutogener::__insert_code_worker_for_target(
    pos_vendor_api_meta_t* vendor_api_meta,
    pos_support_api_meta_t* support_api_meta,
    POSCodeGen_CppSourceFile* worker_file,
    POSCodeGen_CppBlock *wk_function_namespace,
    POSCodeGen_CppBlock *api_namespace,
    POSCodeGen_CppBlock *worker_function
){
    pos_retval_t retval = POS_SUCCESS;

    POS_CHECK_POINTER(vendor_api_meta);
    POS_CHECK_POINTER(support_api_meta);
    POS_CHECK_POINTER(worker_file);
    POS_CHECK_POINTER(wk_function_namespace);
    POS_CHECK_POINTER(api_namespace);
    POS_CHECK_POINTER(worker_function);

    // add POS CUDA headers
    parser_file->add_include("#include \"pos/cuda_impl/worker.h\"");

    // step 1: declare variables in the worker
    worker_function->declare_var("pos_retval_t retval = POS_SUCCESS;");

    // step 2: check input pointers for wqe and ws
    worker_function->append_content(
        "POS_CHECK_POINTER(wqe);\n"
        "POS_CHECK_POINTER(ws);"
    );

    // TODO: what to do next?

exit:
    return retval;
}
