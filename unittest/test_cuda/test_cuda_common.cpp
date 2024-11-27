/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
