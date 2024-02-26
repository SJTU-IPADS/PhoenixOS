#pragma once

#include <iostream>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/workspace.h"
#include "pos/include/parser.h"

#include "pos/cuda_impl/client.h"
#include "pos/cuda_impl/parser.h"
#include "pos/cuda_impl/worker.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/api_context.h"

class POSWorkspace_CUDA : public POSWorkspace{
 public:
    POSWorkspace_CUDA(int argc, char *argv[]) : POSWorkspace(argc, argv){
        this->checkpoint_api_id = 6666;
    }

    /*!
     *  \brief  initialize the workspace
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     *  \return POS_SUCCESS for successfully initialization
     */
    pos_retval_t init() override {
        // create runtime
        this->runtime = new POSParser_CUDA(/* ws */ this);
        POS_CHECK_POINTER(this->runtime);
        this->runtime->init();

        // create worker
        this->worker = new POSWorker_CUDA( /* ws */ this );
        POS_CHECK_POINTER(this->worker);
        this->worker->init();

        // create the api manager
        this->api_mgnr = new POSApiManager_CUDA();
        POS_CHECK_POINTER(this->api_mgnr);
        this->api_mgnr->init();

        // mark all stateful resources
        this->stateful_handle_type_idx.push_back({
            kPOS_ResourceTypeId_CUDA_Memory
        });

        return POS_SUCCESS;
    }
};
