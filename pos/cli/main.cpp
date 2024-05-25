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
        /* action */    "%d%d%d"
        /* meta */      "%d:%d:%d:%d:%d:",
        kPOS_CliAction_Help,
        kPOS_CliAction_Migrate,
        kPOS_CliAction_Preserve,
        kPOS_CliMeta_Pid,
        kPOS_CliMeta_OobIp,
        kPOS_CliMeta_OobPort,
        kPOS_CliMeta_DataplaneIp,
        kPOS_CliMeta_DataplanePort
    );

    struct option long_opt[] = {
        // action types
        {"help",        no_argument,        NULL,   kPOS_CliAction_Help},
        {"migrate",     no_argument,        NULL,   kPOS_CliAction_Migrate},
        {"preserve",    no_argument,        NULL,   kPOS_CliAction_Preserve},
        
        // metadatas
        {"pid",         required_argument,  NULL,   kPOS_CliMeta_Pid},
        {"oip",         required_argument,  NULL,   kPOS_CliMeta_OobIp},
        {"oport",       required_argument,  NULL,   kPOS_CliMeta_OobPort},
        {"dip",         required_argument,  NULL,   kPOS_CliMeta_DataplaneIp},
        {"dport",       required_argument,  NULL,   kPOS_CliMeta_DataplanePort},
        
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
    case kPOS_CliAction_Migrate:
        return handle_migrate(clio);
    
    default:
        return POS_FAILED_NOT_IMPLEMENTED;
    }
}


int main(int argc, char *argv[]){
    pos_retval_t retval;
    pos_cli_options_t clio;

    __readin_raw_cli(argc, argv, clio);

    clio.local_oob_client = new POSOobClient(
        /* local_port */ 10086,
        /* local_ip */ CLIENT_IP,
        /* server_port */ POS_OOB_SERVER_DEFAULT_PORT,
        /* server_ip */ SERVER_IP
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
