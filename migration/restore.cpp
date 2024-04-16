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

#define SERVER_IP "10.66.10.1"
#define SERVER_UDP_PORT POS_OOB_SERVER_DEFAULT_PORT

void printf_error();

typedef struct POSOobMsg_RestoreSignal {
    // type of the message
    pos_oob_msg_typeid_t msg_type;

    // meta data of a out-of-band client
    POSOobClientMeta_t client_meta;
} POSOobMsg_RestoreSignal_t;

int main(){
    int retval;
    int s;
    int len;
    char recvbuf[128];
    char sendbuf[128];
    struct sockaddr_in local, remote;
    
    POSOobMsg_RestoreSignal_t restore_signal_msg;

    // create socket
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        printf_error();
        goto exit;
    }

    // set up server address
    remote.sin_family = AF_INET;
    //remote.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    remote.sin_addr.s_addr = inet_addr(SERVER_IP);
    remote.sin_port = htons(SERVER_UDP_PORT);
    
    // send
    memset(&restore_signal_msg, 0, sizeof(POSOobMsg_RestoreSignal_t));
    restore_signal_msg.msg_type = kPOS_Oob_Restore_Signal;

    len = sizeof(remote);
    retval = sendto(s, &restore_signal_msg, sizeof(POSOobMsg_RestoreSignal_t), 0, (struct sockaddr*)&remote, len);
    if(retval < 0){
        printf_error();
        goto exit;
    }
    fprintf(stdout, "[POS] successfully restore signal\n");
    
exit:       
    if(s > 0){
        close(s);
    }
}

void printf_error() {
    #ifdef _WIN32
        int retval = WSAGetLastError();
        fprintf(stderr, "socket error: %d\n", retval);
    #elif __linux__
        fprintf(stderr, "socket error: %s(errno: %d)\n",strerror(errno),errno);
    #endif
}
