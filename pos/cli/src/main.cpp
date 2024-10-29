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
#include <string>

#include <stdio.h>
#include <getopt.h>
#include <string.h>

#include "pos/include/common.h"
#include "pos/include/oob.h"
#include "pos/cli/cli.h"


#define CLIENT_IP "0.0.0.0"
#define SERVER_IP "10.66.10.1"
#define SERVER_UDP_PORT POS_OOB_SERVER_DEFAULT_PORT


typedef struct migration_cli_meta {
    uint64_t client_uuid;
} migration_cli_meta_t;


inline void __readin_raw_cli(int argc, char *argv[], pos_cli_options_t &clio){
    int opt;
    int option_index = 0;
    char short_opt[1024] = { 0 };

    sprintf(
        short_opt,
        /* action */    "%d%d%d%d%d%d%d"
        /* meta */      "%d:%d:%d:%d:%d:",
        kPOS_CliAction_Help,
        kPOS_CliAction_PreDump,
        kPOS_CliAction_Dump,
        kPOS_CliAction_Restore,
        kPOS_CliAction_TraceResource,
        kPOS_CliAction_Migrate,
        kPOS_CliAction_Preserve,
        kPOS_CliMeta_SubAction,
        kPOS_CliMeta_Pid,
        kPOS_CliMeta_Dir,
        kPOS_CliMeta_Dip,
        kPOS_CliMeta_Dport
    );

    struct option long_opt[] = {
        // action types
        {"help",            no_argument,        NULL,   kPOS_CliAction_Help},
        {"pre-dump",        no_argument,        NULL,   kPOS_CliAction_PreDump},
        {"dump",            no_argument,        NULL,   kPOS_CliAction_Dump},
        {"restore",         no_argument,        NULL,   kPOS_CliAction_Restore},
        {"migrate",         no_argument,        NULL,   kPOS_CliAction_Migrate},
        {"preserve",        no_argument,        NULL,   kPOS_CliAction_Preserve},
        {"trace-resource",  no_argument,        NULL,   kPOS_CliAction_TraceResource},

        // metadatas
        {"subaction",   required_argument,  NULL,   kPOS_CliMeta_SubAction},
        {"pid",         required_argument,  NULL,   kPOS_CliMeta_Pid},
        {"dir",         required_argument,  NULL,   kPOS_CliMeta_Dir},
        {"dip",         required_argument,  NULL,   kPOS_CliMeta_Dip},
        {"dport",       required_argument,  NULL,   kPOS_CliMeta_Dport},
        
        {NULL,          0,                  NULL,   0}
    };

    while ((opt = getopt_long(argc, argv, (const char*)(short_opt), long_opt, &option_index)) != -1) {
        if (opt < kPOS_CliAction_PLACEHOLDER) {
            clio.action_type = static_cast<pos_cli_action>(opt);
        } else if (opt < kPOS_CliMeta_PLACEHOLDER) {
            clio.record_raw(static_cast<pos_cli_meta>(opt), optarg);
        }
    }
}


inline pos_retval_t __dispatch(pos_cli_options_t &clio){
    switch (clio.action_type)
    {
    case kPOS_CliAction_PreDump:
        return handle_predump(clio);

    case kPOS_CliAction_Dump:
        return handle_dump(clio);

    case kPOS_CliAction_Migrate:
        return handle_migrate(clio);

    case kPOS_CliAction_TraceResource:
        return handle_trace(clio);
    
    default:
        return POS_FAILED_NOT_IMPLEMENTED;
    }
}


/*!
 *  \brief  function prototypes for cli oob client
 */
namespace oob_functions {
    // TODO: define other client-side functions here
    POS_OOB_DECLARE_CLNT_FUNCTIONS(cli_ckpt_predump);
    POS_OOB_DECLARE_CLNT_FUNCTIONS(cli_ckpt_dump);
    POS_OOB_DECLARE_CLNT_FUNCTIONS(cli_migration_signal);
    POS_OOB_DECLARE_CLNT_FUNCTIONS(cli_restore_signal);
    POS_OOB_DECLARE_CLNT_FUNCTIONS(cli_trace_resource);
}; // namespace oob_functions


int main(int argc, char *argv[]){
    pos_retval_t retval;
    pos_cli_options_t clio;

    __readin_raw_cli(argc, argv, clio);

    clio.local_oob_client = new POSOobClient(
        /* req_functions */ {
            {   kPOS_OOB_Msg_CLI_Ckpt_PreDump,      oob_functions::cli_ckpt_predump::clnt       },
            {   kPOS_OOB_Msg_CLI_Ckpt_Dump,         oob_functions::cli_ckpt_dump::clnt          },
            {   kPOS_OOB_Msg_CLI_Trace_Resource,    oob_functions::cli_trace_resource::clnt     },
            {   kPOS_OOB_Msg_CLI_Migration_Signal,  oob_functions::cli_migration_signal::clnt   },
            {   kPOS_OOB_Msg_CLI_Restore_Signal,    oob_functions::cli_restore_signal::clnt     },
        },
        /* local_port */ 10086,
        /* local_ip */ CLIENT_IP
    );
    POS_CHECK_POINTER(clio.local_oob_client);

    retval = __dispatch(clio);
    switch (retval)
    {
    case POS_SUCCESS:
        return 0;

    case POS_FAILED_NOT_IMPLEMENTED:
        POS_ERROR("unspecified action, use '-h' to check usage");

    default:
        POS_ERROR("CLI executed failed");
    }
}
