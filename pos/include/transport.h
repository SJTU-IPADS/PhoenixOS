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


#define POS_TRANSPORT_RDMA_MAX_WQE_PER_WQ    128
#define POS_TRANSPORT_RDMA_CQ_SIZE           128
#define POS_TRANSPORT_RDMA_MAX_SGE_PER_WQE   16

/*!
 * \brief   context for RDMA queues
 */
typedef struct pos_ib_queue_ctx {
   struct ibv_pd *pd = nullptr;
   struct ibv_qp *qp = nullptr;
   struct ibv_cq *cq = nullptr;
} pos_ib_queue_ctx_t;

/*!
 * \brief   represent a RDMA-based transport endpoint
 */
class POSTransport_RDMA {
   /*!
    * \brief   constructor of RDMA transport end-point
    * \param   dev_name       name of the IB device to be used
    * \param   local_ib_port  local IB port to be used
    */
   POSTransport_RDMA(std::string dev_name, int local_ib_port){
      pos_retval_t tmp_retval;
      pos_ib_queue_ctx_t qctx;

      POS_ASSERT(POSTransport_RDMA::has_ib_device());

      // open and init IB device
      tmp_retval = __open_and_init_ib_device(dev_name, local_ib_port);
      if(unlikely(POS_SUCCESS != tmp_retval)){
         goto exit;
      }

      // create the first Reliable & Connect-oriented (RC) QP and corresponding PD and CQ
      tmp_retval = this->__create_qctx(IBV_QPT_RC, qctx);
      if(unlikely(POS_SUCCESS != tmp_retval)){
         goto exit;
      }
      this->_qctxs.push_back(qctx);

   exit:
      ;
   }
   ~POSTransport_RDMA() = default;

   /*!
    * \brief   [control-plane] listen to a TCP socket before starting connection,
    *          this function would be invoked on the server-side
    * \return  POS_SUCCESS for succesfully connected
    */
   pos_retval_t oob_listen(){
      pos_retval_t retval = POS_SUCCESS;
      
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
    * \brief   [control-plane] open and initialize specific IB device
    * \param   dev_name       name of the IB device to be used
    * \param   local_ib_port  local IB port to be used
    * \return  POS_SUCCESS for successfully opened;
    *          others for any failure
    */
   pos_retval_t __open_and_init_ib_device(std::string& dev_name, int& local_ib_port){
      pos_retval_t retval = POS_SUCCESS;
      struct ibv_device **dev_list = nullptr;
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
            this->_ib_dev = dev_list[i];
            break;
         }
      }
      if(dev_name.size() > 0 && this->_ib_dev == nullptr){
         POS_WARN_C("no IB device named %s detected", dev_name.c_str());
         retval = POS_FAILED_NOT_EXIST;
         goto exit;
      }
      if(unlikely(this->_ib_dev == nullptr)){
         this->_ib_dev = dev_list[0];
         POS_DEBUG_C(
            "no IB device specified, use first device by default: dev_name(%s)",
            strdup(ibv_get_device_name(this->_ib_dev))
         );
      }
      POS_CHECK_POINTER(this->_ib_dev);

      // obtain the handle of the IB device
      this->_ib_ctx = ibv_open_device(this->_ib_dev);
      if(unlikely(this->_ib_ctx == nullptr)){
         POS_WARN_C(
            "failed to open IB device handle: device_name(%s)",
            ibv_get_device_name(this->_ib_dev)
         );
         retval = POS_FAILED;
         goto exit;
      }

      // query port properties on the opened device
      if (unlikely(
         0 != ibv_query_port(this->_ib_ctx, local_ib_port, &this->_port_attr)
      )){
         POS_WARN_C(
            "failed to ibv_query_port on port %u for device %s",
            local_ib_port, strdup(ibv_get_device_name(this->_ib_dev))
         );
         retval = POS_FAILED;
         goto exit;
      }

   exit:
      if(dev_list){
         ibv_free_device_list(dev_list);
      }

      if(unlikely(retval != POS_SUCCESS)){
         if(this->_ib_ctx){
            ibv_close_device(this->_ib_ctx);
            this->_ib_ctx = nullptr;
         }
      }

      return retval;
   }

   /*!
    * \brief   [control-plane] create new queue context (i.e., PD, QP, CQ)
    * \param   qp_type  type of the QP to be created
    * \param   qctx     queue context
    * \return  POS_SUCCESS for successfully creation
    */
   pos_retval_t __create_qctx(ibv_qp_type qp_type, pos_ib_queue_ctx_t &qctx){
      pos_retval_t retval = POS_SUCCESS;
      struct ibv_pd *pd = nullptr;
      struct ibv_qp *qp = nullptr;
      struct ibv_cq *cq = nullptr;
      struct ibv_qp_init_attr qp_init_attr;

      POS_CHECK_POINTER(this->_ib_dev);
      POS_CHECK_POINTER(this->_ib_ctx);

      cq = ibv_create_cq(this->_ib_ctx, POS_TRANSPORT_RDMA_CQ_SIZE, NULL, NULL, 0);
      if (unlikely(cq == nullptr)){
         POS_WARN_C(
            "failed to create CQ: device(%s), size(%u)",
            strdup(ibv_get_device_name(this->_ib_dev)), POS_TRANSPORT_RDMA_CQ_SIZE
         );
         retval = POS_FAILED;
         goto exit;
	   }

      // allocate protection domain for the QP to be created
      pd = ibv_alloc_pd(this->_ib_ctx);
      if (unlikely(pd == nullptr)){
         POS_WARN_C(
            "failed to allocate protection domain on device %s",
            strdup(ibv_get_device_name(this->_ib_dev))
         );
         retval = POS_FAILED;
         goto exit;
      }

      memset(&qp_init_attr, 0, sizeof(struct ibv_qp_init_attr));
      qp_init_attr.qp_type = qp_type;
      // if set, each Work Request (WR) submitted to the SQ generates a completion entry
      qp_init_attr.sq_sig_all = 1;
      qp_init_attr.send_cq = cq;
      qp_init_attr.recv_cq = cq;
      // requested max number of outstanding WRs in the SQ/RQ
      qp_init_attr.cap.max_send_wr = POS_TRANSPORT_RDMA_MAX_WQE_PER_WQ;
      qp_init_attr.cap.max_recv_wr = POS_TRANSPORT_RDMA_MAX_WQE_PER_WQ;
      // requested max number of scatter/gather (s/g) elements in a WR in the SQ/RQ
      qp_init_attr.cap.max_send_sge = POS_TRANSPORT_RDMA_MAX_SGE_PER_WQE;
      qp_init_attr.cap.max_recv_sge = POS_TRANSPORT_RDMA_MAX_SGE_PER_WQE;

      qp = ibv_create_qp(pd, &qp_init_attr);
      if (unlikely(qp == nullptr)){
         POS_WARN_C("failed to create qp on IB device %s", strdup(ibv_get_device_name(this->_ib_dev)));
         retval = POS_FAILED;
         goto exit;
      }

      POS_DEBUG_C(
         "create queue context: device(%s), max_send/recv_wr(%u), max_send/recv_sge(%u), cq_size(%u) ",
         strdup(ibv_get_device_name(this->_ib_dev)),
         POS_TRANSPORT_RDMA_MAX_WQE_PER_WQ,
         POS_TRANSPORT_RDMA_MAX_SGE_PER_WQE,
         POS_TRANSPORT_RDMA_CQ_SIZE
      );
      qctx.pd = pd;
      qctx.qp = qp;
      qctx.cq = cq;

   exit:
      if(unlikely(retval != POS_SUCCESS)){
         if(cq != nullptr){
            ibv_destroy_cq(cq);
         }

         if(pd != nullptr){
            ibv_dealloc_pd(pd);
         }

         if(qp != nullptr){
            ibv_destroy_qp(qp);
         }
      }

      return retval;
   }

   // IB device handle
   struct ibv_device *_ib_dev;

   // IB context of current process
	struct ibv_context *_ib_ctx;

   // IB port attributes
   struct ibv_port_attr _port_attr;
   
   // map of handles of the protection domain, and corresponding QP and CQ
   std::vector<pos_ib_queue_ctx_t> _qctxs;

   // TCP socket for building connection
	int sock;
};
