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

int main(){
    int retval;

    migration_cli_meta_t cli_meta;
    cli_meta.client_uuid = 0;

    POSOobClient oob_client(
        /* local_port */ 10086,
        /* local_ip */ CLIENT_IP,
        /* server_port */ POS_OOB_SERVER_DEFAULT_PORT,
        /* server_ip */ SERVER_IP
    );

    oob_client.call(kPOS_Oob_Restore_Signal, &cli_meta);
    
exit:       
    return retval;
}
