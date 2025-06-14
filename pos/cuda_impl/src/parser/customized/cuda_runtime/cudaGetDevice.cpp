/*
 * Copyright 2025 The PhoenixOS Authors. All rights reserved.
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

#include <iostream>

#include "pos/include/common.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/parser.h"
#include "pos/cuda_impl/client.h"
#include "pos/cuda_impl/api_context.h"


namespace ps_functions {

namespace cuda_get_device {
    POS_RT_FUNC_PARSER(){
        pos_retval_t retval = POS_SUCCESS;
        POSClient_CUDA *client;
        POSHandleManager_CUDA_Device *hm_device;
        int latest_device_id;
        
        POS_CHECK_POINTER(wqe);
        POS_CHECK_POINTER(ws);

        client = (POSClient_CUDA*)(wqe->client);
        POS_CHECK_POINTER(client);

        // obtain handle managers of device
        hm_device = pos_get_client_typed_hm(
            client, kPOS_ResourceTypeId_CUDA_Device, POSHandleManager_CUDA_Device
        );
        POS_CHECK_POINTER(hm_device);
        POS_CHECK_POINTER(hm_device->latest_used_handle);

        POS_CHECK_POINTER(wqe->api_cxt->ret_data);

        latest_device_id = static_cast<int>((uint64_t)(hm_device->latest_used_handle->client_addr));
        memcpy(wqe->api_cxt->ret_data, &(latest_device_id), sizeof(int));

        // the api is finish, one can directly return
        wqe->status = kPOS_API_Execute_Status_Return_Without_Worker;

    exit:
        return retval;
    }
} // namespace cuda_get_device

} // namespace ps_functions
