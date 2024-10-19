#include "pos/include/common.h"
#include "pos/include/log.h"
#include "test_cuda/test_cuda_common.h"


pos_retval_t PhOSCudaTest::__create_cuda_workspace_and_client(){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t pos_client_uuid;
    pos_create_client_param create_param;

    POS_CHECK_POINTER(this->_ws = new POSWorkspace_CUDA());
    this->_ws->init();

    create_param.job_name = "unit_test";
    retval = (this->_ws)->create_client(create_param, &this->_clnt);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN("failed to create client");
    }

exit:
    return retval;
}


pos_retval_t PhOSCudaTest::__destory_cuda_workspace(){
    pos_retval_t retval = POS_SUCCESS;
    POS_CHECK_POINTER(this->_ws);
    retval = this->_ws->deinit();
    delete this->_ws;
    return retval;
}
