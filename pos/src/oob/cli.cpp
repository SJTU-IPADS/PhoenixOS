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
 *  \related    kPOS_OOB_Msg_CLI_Migration_Signal
 *  \brief      migration signal send from CRIU action script
 */
namespace cli_migration_signal {
    // payload format
    typedef struct oob_payload {
        /* client */
        uint64_t client_uuid;
        uint32_t remote_ipv4;
        uint32_t port;
        /* server */
    } oob_payload_t;

    typedef struct migration_cli_meta {
        uint64_t client_uuid;
    } migration_cli_meta_t;

    // server
    pos_retval_t sv(int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSWorkspace* ws, POSOobServer* oob_server){
        #if POS_MIGRATION_OPT_LEVEL > 0
            oob_payload_t *payload;
            POSClient *client;
            // pos_migration_job_t *mjob;

            payload = (oob_payload_t*)msg->payload;
            client = ws->get_client_by_uuid(payload->client_uuid);

            POS_LOG("received migration signal, notify POS worker: client_uuid(%lu)", payload->client_uuid);
            client->migration_ctx.start(payload->remote_ipv4, payload->port);

            // we block until the GPU conext is finished saved, then we notify the CPU-side
            while(client->migration_ctx.is_blocking() == false){}
            
            __POS_OOB_SEND();
        #else
            POS_WARN("received migration signal, but POS is compiled without migration support, omit");
        #endif
    }

    // client
    pos_retval_t clnt(
        int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSAgent* agent, POSOobClient* oob_clnt, void* call_data
    ){
        pos_retval_t retval = POS_SUCCESS;
        uint64_t i;
        migration_cli_meta_t *cli_meta;
        oob_payload_t *payload;

        msg->msg_type = kPOS_OOB_Msg_CLI_Migration_Signal;

        POS_CHECK_POINTER(call_data);
        cli_meta = (migration_cli_meta_t*)call_data;

        // setup payload
        memset(msg->payload, 0, sizeof(msg->payload));
        payload = (oob_payload_t*)msg->payload;
        payload->client_uuid = cli_meta->client_uuid;
        __POS_OOB_SEND();
        
        // wait until the GPU-side finished 
        __POS_OOB_RECV();

        return POS_SUCCESS;
    }
} // namespace cli_migration_signal


/*!
 *  \related    kPOS_OOB_Msg_CLI_Restore_Signal [MOCK]
 *  \brief      restore signal send from CRIU action script
 */
namespace cli_restore_signal {
    // payload format
    typedef struct oob_payload {
        /* client */
        uint64_t client_uuid;
        /* server */
    } oob_payload_t;

    typedef struct migration_cli_meta {
        uint64_t client_uuid;
    } migration_cli_meta_t;

    // server
    pos_retval_t sv(int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSWorkspace* ws, POSOobServer* oob_server){
        #if POS_MIGRATION_OPT_LEVEL > 0
            oob_payload_t *payload;
            POSClient *client;

            payload = (oob_payload_t*)msg->payload;
            client = ws->get_client_by_uuid(payload->client_uuid);

            POS_LOG("received restore signal, notify POS worker: client_uuid(%lu)", payload->client_uuid);
            client->migration_ctx.restore();
        #else
            POS_WARN("receive restore signal, but POS is compiled without migration support, omit");
        #endif

        return POS_SUCCESS;
    }

    // client
    pos_retval_t clnt(
        int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSAgent* agent, POSOobClient* oob_clnt, void* call_data
    ){
        pos_retval_t retval = POS_SUCCESS;
        uint64_t i;
        migration_cli_meta_t *cli_meta;
        oob_payload_t *payload;

        msg->msg_type = kPOS_OOB_Msg_CLI_Restore_Signal;

        POS_CHECK_POINTER(call_data);
        cli_meta = (migration_cli_meta_t*)call_data;

        // setup payload
        memset(msg->payload, 0, sizeof(msg->payload));
        payload = (oob_payload_t*)msg->payload;
        payload->client_uuid = cli_meta->client_uuid;
        __POS_OOB_SEND();

        return POS_SUCCESS;
    }
} // namespace cli_restore_signal


} // namespace oob_functions
