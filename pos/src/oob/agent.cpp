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
#include <iostream>
#include <vector>

#include "pos/include/common.h"
#include "pos/include/oob.h"
#include "pos/include/log.h"
#include "pos/include/api_context.h"
#include "pos/include/workspace.h"
#include "pos/include/agent.h"

#include "pos/cuda_impl/client.h"

namespace oob_functions {

/*!
 *  \related    kPOS_OOB_Msg_Agent_Register_Client
 *  \brief      register a new client to the server
 */
namespace agent_register_client {
    // payload format
    typedef struct oob_payload {
        /* client */
        /* server */
        bool is_registered;
    } oob_payload_t;

    // server
    pos_retval_t sv(int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSWorkspace* ws, POSOobServer* oob_server){
        oob_payload_t *payload;

        POSClient *clnt;

        POS_CHECK_POINTER(remote);
        POS_CHECK_POINTER(msg);
        POS_CHECK_POINTER(ws);

        payload = (oob_payload_t*)msg->payload;
        
        // create client
        ws->create_client(&clnt, &(msg->client_meta.uuid));

        // create queue pair
        if(unlikely(POS_SUCCESS != ws->create_qp(msg->client_meta.uuid))){
            POS_ERROR_DETAIL("failed to create queue pair: uuid(%lu)", msg->client_meta.uuid);
        }
        POS_DEBUG("create queue pair: uuid(%lu)", msg->client_meta.uuid);

        clnt->status = kPOS_ClientStatus_Active;

        payload->is_registered = true;

        __POS_OOB_SEND();

        return POS_SUCCESS;
    }

    // client
    pos_retval_t clnt(
        int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSAgent* agent, POSOobClient* oob_clnt, void* call_data
    ){
        int retval = POS_SUCCESS;
        oob_payload_t *payload;

        msg->msg_type = kPOS_OOB_Msg_Agent_Register_Client;
        memset(msg->payload, 0, sizeof(msg->payload));
        __POS_OOB_SEND();

        __POS_OOB_RECV();
        payload = (oob_payload_t*)msg->payload;
        if(payload->is_registered == true){
            POS_DEBUG(
                "[OOB %u] successfully register client to the server: uuid(%lu)",
                kPOS_OOB_Msg_Agent_Register_Client, msg->client_meta.uuid
            );
        } else {
            POS_DEBUG("[OOB %u] failed to register client to the server", kPOS_OOB_Msg_Agent_Register_Client);
            retval = POS_FAILED;
        }

        oob_clnt->set_uuid(msg->client_meta.uuid);
        agent->set_uuid(msg->client_meta.uuid);

        return retval;
    }
} // namespace agent_register_client


namespace agent_unregister_client {
    // server
    pos_retval_t sv(int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSWorkspace* ws, POSOobServer* oob_server){
        POS_CHECK_POINTER(remote);
        POS_CHECK_POINTER(msg);
        POS_CHECK_POINTER(ws);

        // remove queue pair
        // ws->remove_qp(msg->client_meta.uuid);

        // remove client
        ws->remove_client(msg->client_meta.uuid);

        __POS_OOB_SEND();

        return POS_SUCCESS;
    }

    // client
    pos_retval_t clnt(
        int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSAgent* agent, POSOobClient* oob_clnt, void* call_data
    ){
        msg->msg_type = kPOS_OOB_Msg_Agent_Unregister_Client;
        __POS_OOB_SEND();
        __POS_OOB_RECV();
        return POS_SUCCESS;
    }
};

} // namespace oob_functions
