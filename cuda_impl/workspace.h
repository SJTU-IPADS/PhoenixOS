#pragma once

#include <iostream>

#include "pos/common.h"
#include "pos/log.h"
#include "pos/workspace.h"
#include "pos/runtime.h"

#include "pos/cuda_impl/client.h"
#include "pos/cuda_impl/runtime.h"
#include "pos/cuda_impl/worker.h"
#include "pos/cuda_impl/api_context.h"

template<class T_POSTransport>
class POSWorkspace_CUDA : public POSWorkspace<T_POSTransport, POSClient_CUDA>{
 public:
    POSWorkspace_CUDA(){
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
        this->_runtime = new POSRuntime_CUDA<T_POSTransport>( 
            /* ws */ this,
            /* checkpoint_internal_ */ 10000
        );
        POS_CHECK_POINTER(this->_runtime);
        this->_runtime->init();

        // create worker
        this->_worker = new POSWorker_CUDA<T_POSTransport>( /* ws */ this );
        POS_CHECK_POINTER(this->_worker);
        this->_worker->init();

        // create the api manager
        this->api_mgnr = new POSApiManager_CUDA();
        POS_CHECK_POINTER(this->api_mgnr);
        this->api_mgnr->init();

        return POS_SUCCESS;
    }
};
