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
 * \brief   RDMA resouce used by a connection
 */
typedef struct pos_rdma_resource {
   // device attributes
   struct ibv_device_attr device_attr;

   // IB port attributes
   struct ibv_port_attr port_attr;

   // values to connect to remote side
   struct cm_con_data_t remote_props;

   

   // PD handle
	struct ibv_pd *pd;

   // CQ handle
	struct ibv_cq *cq;

   // QP handle
	struct ibv_qp *qp;

   // MR handle for buf
	struct ibv_mr *mr;

   

   /*!
    * \brief   initailize all used resource before starting the connection
    */
   inline pos_retval_t init_client(){
      memset(this, 0, sizeof(struct pos_rdma_resource));

      // step 1: TCP connect to the server
      // step 2: 
   }

   /*!
    * \brief   initailize all used resource before starting the connection
    */
   inline pos_retval_t init_client(){
      memset(this, 0, sizeof(struct pos_rdma_resource));

      // step 1: TCP connect to the server
      // step 2: 
   }

} pos_rdma_resource_t;


class POSTransport_RDMA {
   /*!
    * \brief   constructor of RDMA transport end-point
    * \param   dev_name       name of the IB device to be used
    * \param   local_ib_port  local IB port to be used
    */
   POSTransport_RDMA(std::string dev_name, int local_ib_port){
      pos_retval_t tmp_retval;

      POS_ASSERT(POSTransport_RDMA::has_ib_device());

      tmp_retval = __open_and_init_ib_device(dev_name, local_ib_port);
      if(unlikely(POS_SUCCESS != tmp_retval)){
         goto exit;
      }

   exit:
      ;
   }
   ~POSTransport_RDMA() = default;

   /*!
    * \brief   [control-plane] listen to a TCP socket before starting connection,
    *          this function would be invoked on the server-side
    * \return  POS_SUCCESS for succesfully connected
    */
   pos_retval_t cp_listen_sock(){
      pos_retval_t retval = POS_SUCCESS;

      // todo

   exit:
      return retval;
   }

   /*!
    * \brief   query whether this host contains IB device
    */
   static inline bool has_ib_device(){
      int num_devices;
      ibv_get_device_list(&num_devices);
      return num_devices > 0;
   }

 private:
   /*!
    * \brief   open specific IB device
    * \param   dev_name       name of the IB device to be used
    * \param   local_ib_port  local IB port to be used
    * \return  POS_SUCCESS for successfully opened;
    *          others for any failure
    */
   pos_retval_t __open_and_init_ib_device(std::string& dev_name, int& local_ib_port){
      pos_retval_t retval = POS_SUCCESS;
      struct ibv_device **dev_list = nullptr;
      struct ibv_device *ib_dev = nullptr;
      struct ibv_qp_init_attr qp_init_attr;
      int i, rc, num_devices;
      char *tmp_dev_name;

      // obtain IB device list
      dev_list = ibv_get_device_list(&num_devices);
      if(unlikely(dev_list == nullptr)){
         POS_WARN_C("failed to obtain IB device list");
         retval = POS_FAILED_NOT_EXIST;
         goto exit;
      }
      if(unlikely(num_devices == 0)){
         POS_WARN_C("no IB device detected");
         retval = POS_FAILED_NOT_EXIST;
         goto exit;
      }
      POS_DEBUG_C("found %d of IB devices", num_devices);

      // decide the used device
      for(i=0; i<num_devices; i++){
         tmp_dev_name = strdup(ibv_get_device_name(dev_list[i]));
         if (!strcmp(tmp_dev_name, dev_name.c_str())){
            ib_dev = dev_list[i];
            break;
         }
      }
      if(dev_name.size() > 0 && ib_dev == nullptr){
         POS_WARN_C("no IB device named %s detected");
         retval = POS_FAILED_NOT_EXIST;
         goto exit;
      }
      if(unlikely(ib_dev == nullptr)){
         ib_dev = dev_list[0];
         POS_DEBUG_C(
            "no IB device specified, use first device by default: dev_name(%s)",
            strdup(ibv_get_device_name(ib_dev))
         );
      }
      POS_CHECK_POINTER(ib_dev);

      // obtain the handle of the IB device
      this->_ib_ctx = ibv_open_device(ib_dev);
      if(unlikely(this->_ib_ctx == nullptr)){
         POS_WARN_C(
            "failed to open IB device handle: device_name(%s)",
            ibv_get_device_name(ib_dev)
         );
         retval = POS_FAILED;
         goto exit;
      }

      // query port properties on the opened device
      if (ibv_query_port(this->_ib_ctx, this->local_ib_port, &res->port_attr)){
         fprintf(stderr, "ibv_query_port on port %u failed\n", config.ib_port);
         rc = 1;
         goto resources_create_exit;
      }
   
   exit:
      if(unlikely(retval != POS_SUCCESS)){
         if(dev_list){
            ibv_free_device_list(dev_list);
         }

         if(this->_ib_ctx){
            ibv_close_device(this->_ib_ctx);
            this->_ib_ctx = nullptr;
         }
      }

      return retval;
   }

   // IB device handle
	struct ibv_context *_ib_ctx;

   // TCP socket for building connection
	int sock;
};
