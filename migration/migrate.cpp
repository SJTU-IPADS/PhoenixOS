//connectionless_oriented_client.c: Send Data to server, and receive an ACK from server
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h> //contains many function prototypes of system services: read(), write(), getpid(), close(), etc.

#include "pos/include/common.h"
#include "pos/include/oob.h"

#define CLIENT_IP "10.66.20.1"
#define SERVER_IP "10.66.10.1"
#define SERVER_UDP_PORT POS_OOB_SERVER_DEFAULT_PORT

typedef struct migration_cli_meta {
    uint64_t client_uuid;
} migration_cli_meta_t;

/*!
 *  \brief  function prototypes for cli oob client
 */
namespace oob_functions {
    POS_OOB_DECLARE_CLNT_FUNCTIONS(agent_register_client);
    POS_OOB_DECLARE_CLNT_FUNCTIONS(agent_unregister_client);
    POS_OOB_DECLARE_CLNT_FUNCTIONS(utils_mock_api_call);
    POS_OOB_DECLARE_CLNT_FUNCTIONS(cli_migration_signal);
    POS_OOB_DECLARE_CLNT_FUNCTIONS(cli_restore_signal);
}; // namespace oob_functions

int main(){
    int retval;

    migration_cli_meta_t cli_meta;
    cli_meta.client_uuid = 0;

    POSOobClient oob_client(
        /* req_functions */ {
            {   kPOS_OOB_Msg_CLI_Migration_Signal,  oob_functions::cli_migration_signal::clnt   },
        },
        /* local_port */ 10086,
        /* local_ip */ CLIENT_IP,
        /* server_port */ POS_OOB_SERVER_DEFAULT_PORT,
        /* server_ip */ SERVER_IP
    );

    oob_client.call(kPOS_OOB_Msg_CLI_Migration_Signal, &cli_meta);
    
exit:       
    return retval;
}
