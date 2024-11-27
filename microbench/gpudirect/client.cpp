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

struct cm_con_data_t {
	uint64_t addr;          /* Buffer address */
	uint32_t rkey;          /* Remote key */
	uint32_t qp_num;        /* QP number */
	uint16_t lid;	          /* LID of the IB port */
	uint8_t gid[16];        /* gid */
} __attribute__((packed));

struct resources {
	struct ibv_device_attr device_attr; /* Device attributes */
	struct ibv_port_attr port_attr;	    /* IB port attributes */
	struct cm_con_data_t remote_props;  /* values to connect to remote side */
	struct ibv_context *ib_ctx;		      /* device handle */
	struct ibv_pd *pd;				          /* PD handle */
	struct ibv_cq *cq;				          /* CQ handle */
	struct ibv_qp *qp;				          /* QP handle */
	struct ibv_mr *mr;				          /* MR handle for buf */
	char *buf;						              /* memory buffer pointer, used for RDMA and send ops */
	int sock;						                /* TCP socket file descriptor */
};



static int resources_create(struct resources *res){
  struct ibv_device **dev_list = NULL;
  struct ibv_qp_init_attr qp_init_attr;
	struct ibv_device *ib_dev = NULL;

  
}


int main(int argc, char *argv[]){
  resources res = {0};



  return 0;
}
