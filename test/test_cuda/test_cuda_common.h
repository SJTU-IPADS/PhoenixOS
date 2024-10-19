#pragma once

#include <iostream>
#include <vector>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "gtest/gtest.h"

#include "pos/include/common.h"
#include "pos/include/transport.h"
#include "pos/cuda_impl/workspace.h"
#include "pos/cuda_impl/api_index.h"


class PhOSCudaTest : public ::testing::Test {
 protected:
    void SetUp() override {
        if(unlikely(POS_SUCCESS !=
            this->__create_cuda_workspace_and_client()
        )){
            POS_ERROR_C("failed to create POS CUDA workspace and client");
        }
    }


    void TearDown() override {
        if(unlikely(POS_SUCCESS !=
            this->__destory_cuda_workspace()
        )){
            POS_ERROR_C("failed to destory POS CUDA workspace and client");
        }
    }

    // workspace and client to run test
    POSWorkspace_CUDA* _ws;
    POSClient* _clnt;

    /*!
     *  \brief  create new CUDA workspace and client for a unit test 
     *  \param  ws      pointer to the created CUDA workspace
     *  \param  clnt    pointer to the created CUDA client
     *  \return POS_SUCCESS for successfully creation
     */
    pos_retval_t __create_cuda_workspace_and_client();

    /*!
     *  \brief  destory CUDA workspace for a unit test 
     *  \return POS_SUCCESS for successfully destory
     */
    pos_retval_t __destory_cuda_workspace();
};
