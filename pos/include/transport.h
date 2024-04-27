#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <endian.h>
#include <byteswap.h>
#include <getopt.h>

#include <sys/time.h>
#include <arpa/inet.h>
#include <infiniband/verbs.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timestamp.h"


/*!
 *  \brief  RDMA transport server
 */
class POSTransportServer_RDMA {
 public:
    POSTransportServer_RDMA(){}
    ~POSTransportServer_RDMA(){}

 private:
    
};


class POSTransportClient_RDMA {

};
