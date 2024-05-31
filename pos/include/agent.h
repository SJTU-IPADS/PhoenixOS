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

#include "pos/include/common.h"
#include "pos/include/oob.h"
#include "pos/include/api_context.h"

/*!
 *  \brief  function prototypes for cli oob client
 */
namespace oob_functions {
    POS_OOB_DECLARE_CLNT_FUNCTIONS(agent_register_client);
    POS_OOB_DECLARE_CLNT_FUNCTIONS(agent_unregister_client);
}; // namespace oob_functions

/*!
 *  \brief  client-side PhoenixOS agent, manages all POS resources
 */
class POSAgent {
 public:
    /*!
     *  \brief  constructor
     */
    POSAgent(){
        char remote_addr[256] = { 0 };

        // TODO: this address should be obtained from central service instead of environment variable
        char remote_addr_env[] = "REMOTE_GPU_ADDRESS";
        if (!getenv(remote_addr_env)) {
            POS_ERROR_C_DETAIL("failed to start POSAgent, no remote server address provided through \"REMOTE_GPU_ADDRESS\"");
        }
        if (strncpy(remote_addr, getenv(remote_addr_env), 256) == NULL) {
            POS_ERROR_C_DETAIL("failed to copy \"REMOTE_GPU_ADDRESS\" to buffer");
        }

        POS_LOG_C("try to connect to %s:%u", remote_addr, POS_OOB_SERVER_DEFAULT_PORT);

        _pos_oob_client = new POSOobClient(
            /* agent */ this,
            /* req_functions */ {
                {   kPOS_OOB_Msg_Agent_Register_Client,   oob_functions::agent_register_client::clnt    },
                {   kPOS_OOB_Msg_Agent_Unregister_Client, oob_functions::agent_unregister_client::clnt  },
            },
            /* local_port */ POS_OOB_CLIENT_DEFAULT_PORT,
            /* local_ip */ "0.0.0.0",
            /* server_port */ POS_OOB_SERVER_DEFAULT_PORT,
            /* server_ip */ remote_addr
        );
        POS_CHECK_POINTER(_pos_oob_client);

        // register client
        if(POS_SUCCESS != _pos_oob_client->call(kPOS_OOB_Msg_Agent_Register_Client, nullptr)){
            POS_ERROR_C_DETAIL("failed to register the client");
        }
        POS_DEBUG_C("successfully register client: uuid(%lu)", _uuid);
    }

    /*!
     *  \brief  deconstructor
     */
    ~POSAgent(){
        if(POS_SUCCESS != _pos_oob_client->call(kPOS_OOB_Msg_Agent_Unregister_Client, nullptr)){
            POS_ERROR_C_DETAIL("failed to unregister the client");
        }
        delete _pos_oob_client;
    }

    /*!
     *  \brief  call the out-of-band function
     *  \param  id      the out-of-band function id
     *  \param  data    payload to call the function
     *  \return according to different function definitions
     */
    inline pos_retval_t oob_call(pos_oob_msg_typeid_t id, void* data){
        POS_CHECK_POINTER(data);
        return _pos_oob_client->call(id, data);
    }

    /*!
     *  \brief  PhoenixOS API call proxy
     *  \param  api_id  index of the called API
     *  \param  params  list of parameters of the called API
     */
    pos_retval_t api_call(uint64_t api_id, std::vector<POSAPIParamDesp_t> params);

    /*!
     *  \brief  set the uuid of the client
     *  \note   this function is invoked during the registeration process 
     *          (i.e., agent_register_client oob type)
     */
    inline void set_uuid(pos_client_uuid_t id){ _uuid = id; }

 private:
    // pointer to the out-of-band client
    POSOobClient *_pos_oob_client;

    // uuid of the client
    pos_client_uuid_t _uuid;
};

extern POSAgent *pos_agent;
