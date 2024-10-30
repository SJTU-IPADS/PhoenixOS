#include <iostream>

#include <signal.h>

#include "pos/common.h"
#include "pos/transport.h"
#include "pos/cuda_impl/workspace.h"

POSWorkspace_CUDA<POSTransport_SHM> *pos_cuda_ws;
bool mock_stop = false;

void int_handler(int signal) {
    mock_stop = true;
}

int main(){
    struct sigaction act;
    act.sa_handler = int_handler;
    sigaction(SIGINT, &act, NULL);

    pos_cuda_ws = new POSWorkspace_CUDA<POSTransport_SHM>();
    POS_CHECK_POINTER(pos_cuda_ws);

    pos_cuda_ws->init();

    while(!mock_stop){}

    delete pos_cuda_ws;
}