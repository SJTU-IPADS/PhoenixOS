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
#pragma once

#include <iostream>
#include <vector>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/workspace.h"
#include "pos/include/parser.h"
#include "pos/cuda_impl/client.h"
#include "pos/cuda_impl/parser.h"
#include "pos/cuda_impl/worker.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/api_context.h"


class POSWorkspace_CUDA : public POSWorkspace {
 public:
    /*!
     *  \brief  constructor
     */
    POSWorkspace_CUDA(int argc, char *argv[]);

    /*!
     *  \brief  create and add a new client to the workspace
     *  \param  clnt    pointer to the POSClient to be added
     *  \param  uuid    the result uuid of the added client
     *  \return POS_SUCCESS for successfully added
     */
    pos_retval_t create_client(POSClient** clnt, pos_client_uuid_t* uuid) override;

    /*!
     *  \brief  preserve resource on posd
     *  \param  rid     the resource type to preserve
     *  \param  data    source data for preserving
     *  \return POS_SUCCESS for successfully preserving
     */
    pos_retval_t preserve_resource(pos_resource_typeid_t rid, void *data) override;

 private:
    // all CUDA context inside current workspace
    // one context per device
    std::vector<CUcontext> _cu_contexts;

    /*!
     *  \brief  initialize the workspace
     *  \note   create device context inside this function, implementation on specific platform
     *  \return POS_SUCCESS for successfully initialization
     */
    pos_retval_t __init() override;

    /*!
     *  \brief  deinitialize the workspace
     *  \note   destory device context inside this function, implementation on specific platform
     *  \return POS_SUCCESS for successfully deinitialization
     */
    pos_retval_t __deinit() override;
};
