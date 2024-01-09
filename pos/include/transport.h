#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <stdint.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timestamp.h"

enum pos_transport_roleid_t {
    kPOS_Transport_RoleId_Server=0,
    kPOS_Transport_RoleId_Client
};

/*!
 *  \brief  based class of transportation layer
 */
class POSTransport {
 public:
    /*!
     *  \brief  constructor
     *  \param  id  index for uniquely identifying a transport
     *  \param  non_blocking    indicate whether this is a blocking transportation
     *                          if it's, the recv procedure will block until new 
     *                          message coming, before reach the timeout bound
     *  \param  timeout         1. recv timeout upper bound, unit in milisecond;
     *                          2. could be set as 0 to block without timeout bound
     *  \param  role            indicate the role of the endpoint within the transport
     */
    POSTransport(pos_transport_id_t id, bool non_blocking, pos_transport_roleid_t role, uint64_t timeout) 
        : _id(id), _non_blocking(non_blocking), _role(role), _timeout(timeout){}
    ~POSTransport() = default;

    /*!
     *  \brief  initialization of the transport, top-half and bottom-half
     *  \return POS_SUCCESS for successfully initialized
     */
    virtual pos_retval_t init_th(){ return POS_FAILED; };
    virtual pos_retval_t init_bh(){ return POS_FAILED; };

    /*!
     *  \brief  clear all transportation resource
     *  \return POS_SUCCESS for successfully clearing
     */
    pos_retval_t clear(){ return POS_FAILED; }

    /*!
     *  \brief  receive a new batch of buffers from the transport endpoint
     *  \param  addrs    list of pointers that store the received data segments
     *  \param  sizes    list of sizes that store the size of each segments
     *  \note   1. for zero-copy implementation (e.g., POSTransport_SHM), the ownership
     *          of the received data is managed by the transport;
     *          2. the received data might stores across multiple underlying segments, so
     *          this interface would return LIST of addrs and sizes
     *  \return the received message
     */
    virtual pos_retval_t recv(std::vector<void*> *addrs, std::vector<uint64_t> *sizes){ return POS_FAILED; }

    /*!
     *  \brief  expire the lifecycle of the buffers according to its contained address
     *  \note   1. for zero-copy implementation (e.g., POSTransport_SHM), the ownership
     *          of the received data is managed by the transport, so one need to notify
     *          the transport to expire the data once the data is no longer needed
     *  \note   2. implementation of this function is optional
     *  \param  addrs   list of addresses that point to the buffers to be expired
     *  \return POS_SUCCESS for successfully expiring
     */
    virtual pos_retval_t expire_buffer(std::vector<void*> *addrs){ return POS_FAILED; }

    /*!
     *  \brief  send data to the other-side of transport endpoint
     *  \param  addr    base address of the data to be sent
     *  \param  size    number of bytes of the data to be sent
     *  \return POS_FAILED_INVALID_INPUT for too-large size;
     *          POS_FAILED_DRAIN for running out of mempool elements;
     *          POS_SUCCESS for successfully sending
     */
    virtual pos_retval_t send(void *addr, uint64_t size){ return POS_FAILED; }

    /*!
     *  \brief  put the data into the buffer, but don't send
     *  \param  addr    base address of the data
     *  \param  size    size of the data to put
     *  \return POS_SUCCESS for successfully putting
     */
    pos_retval_t put(void *addr, uint64_t size){ return POS_FAILED; }

    /*!
     *  \brief  flush all buffered data to the other end-point
     *  \return POS_SUCCESS for successfully flushing
     */
    pos_retval_t flush(){ return POS_FAILED; }

 protected:
    pos_transport_id_t _id;
    bool _non_blocking;
    pos_transport_roleid_t _role;
    uint64_t _timeout;
};

#include <fcntl.h>
#include <pthread.h>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/creation_tags.hpp>
#include <boost/date_time/microsec_time_clock.hpp>

#include "pos/include/utils/mempool.h"

#define POS_TRANSPORT_SHM_SEGMENT_SIZE                                                                  \
    2 * (                                                                                               \
        sizeof(pthread_mutex_t)                                                                         \
        + sizeof(POSMempool_t<POS_TRANSPORT_SHM_MEMPOOL_NB_ELT, POS_TRANSPORT_SHM_MEMPOOL_ELT_SIZE>)    \
    )
#define POS_TRANSPORT_SHM_MQ_LEN                128
#define POS_TRANSPORT_SHM_MEMPOOL_NB_ELT        1024*1024
#define POS_TRANSPORT_SHM_MEMPOOL_ELT_SIZE      1024
#define POS_TRANSPORT_SHM_MAX_NB_SEGMENTS       512
#define POS_SHM_SUFFIX_MAXLEN 128

using pos_transport_shm_id_mq_elt_t = std::pair<uint64_t, uint64_t>;
using pos_transport_shm_batch_mq_elt_t = uint64_t;

/*!
 *  \brief  shared-memory-based transport, enable zero-copy processing
 */
class POSTransport_SHM : public POSTransport {
 public:
    /*!
     *  \brief  constructor
     *  \param  id  index for uniquely identifying a transport
     *  \param  non_blocking    indicate whether this is a blocking transportation
     *                          if it's, the recv procedure will block until new 
     *                          message coming, before reach the timeout bound
     *  \param  timeout         1. recv timeout upper bound, unit in milisecond;
     *                          2. could be set as 0 to block without timeout bound
     *  \param  role            indicate the role of the endpoint within the transport
     */
    // POSTransport_SHM(){}
    POSTransport_SHM(pos_transport_id_t id, bool non_blocking, pos_transport_roleid_t role, uint64_t timeout)
        : POSTransport(id, non_blocking, role, timeout) 
    {
        // setup the shared memory segment name
        memset(_shm_prefix_name_send, 0, sizeof(_shm_prefix_name_send));
        memset(_shm_prefix_name_recv, 0, sizeof(_shm_prefix_name_recv));
        if (_role == kPOS_Transport_RoleId_Server){
            sprintf(_shm_prefix_name_send, "shm_s2c_%lu", id);
            sprintf(_shm_prefix_name_recv, "shm_c2s_%lu", id);
        } else {    // kPOS_Transport_RoleId_Client
            sprintf(_shm_prefix_name_send, "shm_c2s_%lu", id);
            sprintf(_shm_prefix_name_recv, "shm_s2c_%lu", id);
        }
        sprintf(_shm_prefix_name_common, "shm_%lu", id);
        
        if(POS_SUCCESS != init_th()){
            POS_ERROR_C("failure occured while initialializing top-half part of SHM-based Transport");
        }
    }

    /*!
     *  \brief  deconstructor
     */
    ~POSTransport_SHM(){ clear(); }

    /*!
     *  \brief  initialization of the transport (top-half)
     *  \note   the top-half is invoked by the constructor
     *  \ref    https://www.boost.org/doc/libs/1_37_0/doc/html/interprocess/quick_guide.html#interprocess.quick_guide.qg_named_interprocess
     *  \return POS_SUCCESS for successfully initialized
     */
    pos_retval_t init_th(){
        pos_retval_t retval = POS_SUCCESS;
        boost::interprocess::managed_shared_memory* segment;
        pthread_mutex_t *mempool_lock;
        POSMempoolWithSize_t *mempool;
        char name[POS_SHM_SUFFIX_MAXLEN+128] = {0};
        uint64_t segment_id;

        /*!
        *  \note   only server-side's top half would need to create the first segment and
        *          corresponding data structures (i.e., mempool_lock, mempool) in it, the
        *          client-side only need to open them in the bottom half
        */
        if(_role == kPOS_Transport_RoleId_Server){
            if(POS_SUCCESS != _create_shm_segment(&segment_id)){
                POS_WARN_C("failed to create the first segment")
                goto POSTransport_SHM_init_th_clean_resource;
            }
            POS_ASSERT(segment_id == 0);
        }

        /*!
        *  \note   bothh client and server need to create 2 types of message queues
        *          (i.e., step 4 & step 5)
        */

        // apply send message queue that stores mempool element index
        memset(name, 0, sizeof(name));
        sprintf(name, "%s_%s", _shm_prefix_name_send, "id_mq");
        try{
            boost::interprocess::message_queue::remove(name);
            _send_elt_id_mq = new boost::interprocess::message_queue(
                boost::interprocess::create_only,
                name,
                POS_TRANSPORT_SHM_MQ_LEN, sizeof(pos_transport_shm_id_mq_elt_t)
            );
            if(_send_elt_id_mq == nullptr){
                POS_WARN_C_DETAIL(
                    "failed to create boost-managed send_elt_id_mq: name(%s), len(%lu)",
                    name, POS_TRANSPORT_SHM_MQ_LEN
                );
                retval = POS_FAILED;
                goto POSTransport_SHM_init_th_clean_resource;
            }
        } catch(...) {
            POS_WARN_C_DETAIL(
                "failed to create boost-managed send_elt_id_mq: name(%s), len(%lu)",
                name, POS_TRANSPORT_SHM_MQ_LEN
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_init_th_clean_resource;
        }
        POS_DEBUG_C(
            "create boost-managed send_elt_id_mq: addr(%p), name(%s), len(%lu)",
            _send_elt_id_mq, name, POS_TRANSPORT_SHM_MQ_LEN
        );

        // apply send message queue that stores batch size
        memset(name, 0, sizeof(name));
        sprintf(name, "%s_%s", _shm_prefix_name_send, "batch_mq");
        try{
            boost::interprocess::message_queue::remove(name);
            _send_batch_size_mq = new boost::interprocess::message_queue(
                boost::interprocess::create_only,
                name,
                POS_TRANSPORT_SHM_MQ_LEN, sizeof(pos_transport_shm_batch_mq_elt_t)
            );
            if(_send_batch_size_mq == nullptr){
                POS_WARN_C_DETAIL(
                    "failed to create boost-managed send_batch_size_mq: name(%s), len(%lu)",
                    name, POS_TRANSPORT_SHM_MQ_LEN
                );
                retval = POS_FAILED;
                goto POSTransport_SHM_init_th_clean_resource;
            }
        } catch(...) {
            POS_WARN_C_DETAIL(
                "failed to create boost-managed send_batch_size_mq: name(%s), len(%lu)",
                name, POS_TRANSPORT_SHM_MQ_LEN
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_init_th_clean_resource;
        }
        POS_DEBUG_C(
            "create boost-managed send_batch_size_mq: addr(%p), name(%s), len(%lu)",
            _send_batch_size_mq, name, POS_TRANSPORT_SHM_MQ_LEN
        );

        POS_DEBUG_C(
            "successfully execute the top-half of the transport initialization"
        );

        goto exit_POSTransport_SHM_init_th;

    POSTransport_SHM_init_th_clean_resource:
        clear();

    exit_POSTransport_SHM_init_th:
        return retval;
    }

    /*!
     *  \brief  initialization of the transport (bottom-half)
     *  \note   the bottom-half is invoked manully in the create_client of POSWorkspace
     *  \ref    https://www.boost.org/doc/libs/1_37_0/doc/html/interprocess/quick_guide.html#interprocess.quick_guide.qg_named_interprocess
     *  \return POS_SUCCESS for successfully initialized
     */
    pos_retval_t init_bh(){
        pos_retval_t retval = POS_SUCCESS;
        boost::interprocess::managed_shared_memory* segment;
        pthread_mutex_t *mempool_lock;
        POSMempoolWithSize_t *mempool;
        char name[POS_SHM_SUFFIX_MAXLEN+128] = {0};

        /*!
        *  \note   only client-side's bottom half would need to open the first segment and
        *          corresponding data structures (i.e., mempool_lock, mempool) in it, the
        *          server-side should has already create them in the top half
        */
        if(_role == kPOS_Transport_RoleId_Client){
            if(POS_SUCCESS != _open_shm_segment(0)){
                POS_WARN_C("failed to open the first segment")
                goto POSTransport_SHM_init_bh_clean_resource;
            }
        }

        /*!
        *  \note   bothh client and server need to open 2 types of message queues
        *          (i.e., step 4 & step 5)
        */

        // step 4: open send message queue that stores mempool element index
        memset(name, 0, sizeof(name));
        sprintf(name, "%s_%s", _shm_prefix_name_recv, "id_mq");
        try{
            _recv_elt_id_mq = new boost::interprocess::message_queue(
                boost::interprocess::open_only, name
            );
            if(_recv_elt_id_mq == nullptr){
                POS_WARN_C_DETAIL(
                    "failed to open boost-managed recv_elt_id_mq: name(%s), len(%lu)",
                    name, POS_TRANSPORT_SHM_MQ_LEN
                );
                retval = POS_FAILED;
                goto POSTransport_SHM_init_bh_clean_resource;
            }
        } catch(...) {
            POS_WARN_C_DETAIL(
                "failed to open boost-managed recv_elt_id_mq: name(%s), len(%lu)",
                name, POS_TRANSPORT_SHM_MQ_LEN
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_init_bh_clean_resource;
        }
        POS_DEBUG_C(
            "open boost-managed recv_elt_id_mq: addr(%p), name(%s), len(%lu)",
            _recv_elt_id_mq, name, POS_TRANSPORT_SHM_MQ_LEN
        );

        // step 5: open send message queue that stores batch size
        memset(name, 0, sizeof(name));
        sprintf(name, "%s_%s", _shm_prefix_name_recv, "batch_mq");
        try{
            _recv_batch_size_mq = new boost::interprocess::message_queue(
                boost::interprocess::open_only, name
            );
            if(_recv_batch_size_mq == nullptr){
                POS_WARN_C_DETAIL(
                    "failed to open boost-managed recv_batch_size_mq: name(%s), len(%lu)",
                    name, POS_TRANSPORT_SHM_MQ_LEN
                );
                retval = POS_FAILED;
                goto POSTransport_SHM_init_bh_clean_resource;
            }
        } catch(...) {
            POS_WARN_C_DETAIL(
                "failed to open boost-managed recv_batch_size_mq: name(%s), len(%lu)",
                name, POS_TRANSPORT_SHM_MQ_LEN
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_init_bh_clean_resource;
        }
        POS_DEBUG_C(
            "open boost-managed recv_batch_size_mq: addr(%p), name(%s), len(%lu)",
            _recv_batch_size_mq, name, POS_TRANSPORT_SHM_MQ_LEN
        );

        POS_DEBUG_C(
            "successfully execute the bottom-half of the transport initialization"
        );

        goto exit_POSTransport_SHM_init_bh;

    POSTransport_SHM_init_bh_clean_resource:
        clear();

    exit_POSTransport_SHM_init_bh:
        return retval;
    }

    /*!
     *  \brief  clear all transportation resource
     *  \return POS_SUCCESS for successfully clearing
     */
    pos_retval_t clear(){
        char name[POS_SHM_SUFFIX_MAXLEN+128] = {0};
        std::map<uint64_t, boost::interprocess::managed_shared_memory*>::iterator seg_map_iter;
        uint64_t seg_id;
        boost::interprocess::managed_shared_memory *segment;
        pthread_mutex_t *mempool_lock;

        // step 1: clean segments
        for(seg_map_iter = _segments.begin(); seg_map_iter != _segments.end(); seg_map_iter++){
            seg_id = seg_map_iter->first;
            segment = seg_map_iter->second;

            if(segment == nullptr){ continue; }

            // free mempool lock
            POS_CHECK_POINTER(_mempool_lock_map[seg_id]);
            pthread_mutex_destroy(_mempool_lock_map[seg_id]);
            segment->destroy<pthread_mutex_t>("mempool_lock");
            POS_DEBUG_C("clean SHM resource: mempool_lock, seg_id(%lu)", seg_id);

            // free mempool
            POS_CHECK_POINTER(_mempools[seg_id]);
            segment->destroy<POSMempoolWithSize_t>("mempool");
            POS_DEBUG_C("clean SHM resource: mempool, seg_id(%lu)", seg_id);

            // free segment itself
            memset(name, 0, sizeof(name));
            sprintf(name, "%s_%s_%lu", _shm_prefix_name_common, "segment", seg_id);
            boost::interprocess::shared_memory_object::remove(name);
            POS_DEBUG_C("clean SHM resource: segment, seg_id(%lu)", seg_id);
        }
        pthread_mutexattr_destroy(&_lock_attr);
        
        // step 2: clean send id_mq
        if(_send_elt_id_mq){
            memset(name, 0, sizeof(name));
            sprintf(name, "%s_%s", _shm_prefix_name_send, "id_mq");
            boost::interprocess::message_queue::remove(name);
            POS_DEBUG_C("clean SHM resource: id_mq, name(%s)", name);
        }

        // step 3: clean send batch_mq
        if(_send_batch_size_mq){
            memset(name, 0, sizeof(name));
            sprintf(name, "%s_%s", _shm_prefix_name_send, "batch_mq");
            boost::interprocess::message_queue::remove(name);
            POS_DEBUG_C("clean SHM resource: batch_mq, name(%s)", name);
        }

        // step 4: clean recv id_mq
        if(_recv_elt_id_mq){
            memset(name, 0, sizeof(name));
            sprintf(name, "%s_%s", _shm_prefix_name_recv, "id_mq");
            boost::interprocess::message_queue::remove(name);
            POS_DEBUG_C("clean SHM resource: id_mq, name(%s)", name);
        }

        // step 5: clean recv batch_mq
        if(_recv_elt_id_mq){
            memset(name, 0, sizeof(name));
            sprintf(name, "%s_%s", _shm_prefix_name_recv, "batch_mq");
            boost::interprocess::message_queue::remove(name);
            POS_DEBUG_C("clean SHM resource: batch_mq, name(%s)", name);
        }

        return POS_SUCCESS;
    }

    /*!
     *  \brief  receive a new batch of buffers from the transport endpoint
     *  \param  addrs    list of pointers that store the received data segments
     *  \param  sizes    list of sizes that store the size of each segments
     *  \note   1. for zero-copy implementation (e.g., POSTransport_SHM), the ownership
     *          of the received data is managed by the transport;
     *          2. the received data might stores across multiple underlying segments, so
     *          this interface would return LIST of addrs and sizes
     *  \return the received message
     */
    pos_retval_t recv(std::vector<void*> *addrs, std::vector<uint64_t> *sizes){
        pos_retval_t retval = POS_SUCCESS;
        POSMempoolElt_t *elt;
        POSMempoolWithSize_t *mempool;
        pos_transport_shm_id_mq_elt_t id_mq_recv_payload;
        pos_transport_shm_batch_mq_elt_t batch_mq_recv_payload, i;
        uint64_t mq_recv_size;
        uint32_t mq_recv_priority;
        std::vector<pos_transport_shm_id_mq_elt_t> elt_idx;
        
        POS_CHECK_POINTER(addrs); POS_CHECK_POINTER(sizes);

        // step 1: receive batch size
        if (_non_blocking){
            if(_recv_batch_size_mq->try_receive(
                /* buffer */ &batch_mq_recv_payload,
                /* buffer_size */ sizeof(pos_transport_shm_batch_mq_elt_t),
                /* recvd_size */ mq_recv_size,
                /* priority */ mq_recv_priority
            ) == false){
                retval = POS_WARN_NOT_READY;
                goto exit_POSTransport_SHM_recv;
            }
        } else {
            if (_timeout != 0){
                namespace ns_ptime = boost::posix_time;
                namespace ns_dtime = boost::date_time;
                if(_recv_batch_size_mq->timed_receive(
                    /* buffer */ &batch_mq_recv_payload,
                    /* buffer_size */ sizeof(pos_transport_shm_batch_mq_elt_t),
                    /* recvd_size */ mq_recv_size,
                    /* priority */ mq_recv_priority,
                    /* abs_time */ ns_ptime::ptime(ns_dtime::microsec_clock<ns_ptime::ptime>::universal_time()) 
                                + ns_ptime::milliseconds(_timeout)
                ) == false){
                    retval = POS_WARN_NOT_READY;
                    goto exit_POSTransport_SHM_recv;
                }
            } else {
                _recv_batch_size_mq->receive(
                    /* buffer */ &batch_mq_recv_payload,
                    /* buffer_size */ sizeof(pos_transport_shm_batch_mq_elt_t),
                    /* recvd_size */ mq_recv_size,
                    /* priority */ mq_recv_priority
                );
            }
        }

        // step 2: receive element idx
        for(i=0; i<batch_mq_recv_payload; i++){
            // NOTE: this function shouldn't block too long
            _recv_elt_id_mq->receive(
                /* buffer */ &id_mq_recv_payload,
                /* buffer_size */ sizeof(pos_transport_shm_id_mq_elt_t),
                /* recvd_size */ mq_recv_size,
                /* priority */ mq_recv_priority
            );
            elt_idx.push_back(id_mq_recv_payload);
        }

        POS_DEBUG_C("transport recv new batch: batch_size(%lu)", batch_mq_recv_payload);

        /*!
        *  \note   check whether all segment exist, or it means the other side has created new
        *          segment(s), and we need to open it
        */
        for(i=0; i<batch_mq_recv_payload; i++){
            // lazyly detect newly added segmenets
            if(unlikely(_segments.count(elt_idx[i].first) == 0)){
                if(unlikely(POS_SUCCESS != _open_shm_segment(elt_idx[i].first))){
                    POS_ERROR_C_DETAIL("failed to open segment: segment_id(%lu)", elt_idx[i].first);
                }
            }

            POS_CHECK_POINTER(_mempool_lock_map[elt_idx[i].first]);

            // obtain corresponding mempool
            mempool = _mempools[elt_idx[i].first];
            POS_CHECK_POINTER(mempool);
            
            // extract mempool elements
            elt = mempool->get_elt_by_id((uint64_t)(elt_idx[i].second));
            if(elt != nullptr){
                addrs->push_back(elt->base_addr);
                sizes->push_back(elt->size);
            } else {
                POS_WARN_C_DETAIL("obtain empty pointer of mempool elements");
            }
        }

    exit_POSTransport_SHM_recv:
        return retval;
    }

    /*!
     *  \brief  expire the lifecycle of the buffers according to its contained address
     *  \note   1. for zero-copy implementation (e.g., POSTransport_SHM), the ownership
     *          of the received data is managed by the transport, so one need to notify
     *          the transport to expire the data once the data is no longer needed
     *  \note   2. implementation of this function is optional
     *  \param  addrs   list of addresses that point to the buffers to be expired
     *  \return POS_SUCCESS for successfully expiring
     */
    pos_retval_t expire_buffer(std::vector<void*> *addrs){
        std::map<uint64_t, POSMempoolWithSize_t*>::iterator mempool_iter;
        uint64_t segment_id;
        POSMempoolElt_t *elt;
        POSMempoolWithSize_t *mempool;
        void *addr;
        bool has_expired;
        std::vector<void*>::iterator addrs_iter;

        POS_CHECK_POINTER(addrs);

        for(addrs_iter=addrs->begin(); addrs_iter!=addrs->end(); addrs_iter++){
            addr = *addrs_iter;
            has_expired = false;
            for(mempool_iter=_mempools.begin(); mempool_iter != _mempools.end(); mempool_iter++){
                segment_id = (*mempool_iter).first;
                mempool = (*mempool_iter).second;
                POS_CHECK_POINTER(mempool);

                elt = mempool->get_elt_by_addr(addr);
                if(elt != nullptr){
                    has_expired = true;

                    pthread_mutex_lock(_mempool_lock_map[segment_id]);
                    mempool->return_elt(elt);
                    pthread_mutex_unlock(_mempool_lock_map[segment_id]);

                    break;
                }
            }
            if(unlikely(has_expired == false)){
                POS_WARN_C_DETAIL("failed to expire buffer: addr(%p)", addr);
            }
        }

        return POS_SUCCESS;
    }

    /*!
     *  \brief  send a new message to the transport endpoint
     *  \param  addr    base address of the data to be sent
     *  \param  size    number of bytes of the data to be sent
     *  \return POS_FAILED_INVALID_INPUT for too-large size;
     *          POS_FAILED_DRAIN for running out of mempool elements;
     *          POS_SUCCESS for successfully sending
     */
    pos_retval_t send(void *addr, uint64_t size){
        pos_retval_t retval;
        if(unlikely(retval = put(addr, size))){
            POS_WARN_C("failed to put data into the buffered area");
            return retval;
        }
        if(unlikely(retval = flush())){
            POS_WARN_C("failed to flush data to be sent");
            return retval;
        }
        return retval;
    }

    /*!
     *  \brief  put the data to send into the buffer
     *  \param  addr    base address of the data
     *  \param  size    size of the data to put
     *  \return POS_SUCCESS for successfully putting
     */
    pos_retval_t put(void *addr, uint64_t size){
        pos_retval_t retval = POS_SUCCESS;
        pos_transport_shm_batch_mq_elt_t nb_new_batch, remain_batch;
        pos_transport_shm_id_mq_elt_t last_elt_id;
        uint64_t new_segment_id, segment_id, copy_size, i, nb_last_buffered_elt;
        uint64_t last_elt_remain_size = 0;
        POSMempoolWithSize_t *mempool;
        POSMempoolElt_t *elt, *last_used_elt = nullptr;
        std::map<uint64_t, POSMempoolWithSize_t*>::iterator mempool_iter;
        std::vector<POSMempoolElt_t*> tmp_elts;
        
        POS_CHECK_POINTER(addr);
        if(unlikely(size == 0)){ goto exit_POSTransport_SHM_put; }

        // get the last buffered element
        if(_buffered_elt_idx.size() > 0){
            last_elt_id = _buffered_elt_idx[_buffered_elt_idx.size()-1];
            POS_CHECK_POINTER(mempool = _mempools[last_elt_id.first]);
            POS_CHECK_POINTER(last_used_elt = mempool->get_elt_by_id(last_elt_id.second));
            last_elt_remain_size = mempool->elt_size - last_used_elt->size;
        }

        if(unlikely((size-last_elt_remain_size) % POS_TRANSPORT_SHM_MEMPOOL_ELT_SIZE == 0)){
            nb_new_batch = (size-last_elt_remain_size) / POS_TRANSPORT_SHM_MEMPOOL_ELT_SIZE;
        } else {
            nb_new_batch = (size-last_elt_remain_size) / POS_TRANSPORT_SHM_MEMPOOL_ELT_SIZE + 1;
        }
        remain_batch = nb_new_batch;

        nb_last_buffered_elt = _buffered_elts.size();

        /*!
        *  \note   1. find enough mempool elements from all mempools;
        *          2. TODO: the following code might be slow, may need to be optimized
        */
        for(mempool_iter=_mempools.begin(); mempool_iter != _mempools.end(); mempool_iter++){
            segment_id = (*mempool_iter).first;
            mempool = (*mempool_iter).second;
            POS_CHECK_POINTER(mempool);

            // obtain free elements from the mempool
            pthread_mutex_lock(_mempool_lock_map[segment_id]);
            tmp_elts = mempool->get_free_elts(remain_batch);
            pthread_mutex_unlock(_mempool_lock_map[segment_id]);

            remain_batch -= tmp_elts.size();
            for(i=0; i<tmp_elts.size(); i++){
                _buffered_elt_idx.push_back(pos_transport_shm_id_mq_elt_t(
                    /* segment_id */ segment_id,
                    /* elt_id */ tmp_elts[i]->id
                ));
                _buffered_elts.push_back(tmp_elts[i]);
            }

            if(remain_batch == 0){ break; }
        }

        // not found enough batch, need to create new segment(s)
        while(remain_batch > 0){
            if(unlikely(POS_SUCCESS != _create_shm_segment(&new_segment_id))){
                POS_ERROR_C_DETAIL("failed to create new SHM segment");
            }

            mempool = _mempools[new_segment_id];
            POS_CHECK_POINTER(mempool);

            // obtain free elements from the mempool
            pthread_mutex_lock(_mempool_lock_map[new_segment_id]);
            tmp_elts = mempool->get_free_elts(remain_batch);
            pthread_mutex_unlock(_mempool_lock_map[new_segment_id]);

            remain_batch -= tmp_elts.size();
            for(i=0; i<tmp_elts.size(); i++){
                _buffered_elt_idx.push_back(pos_transport_shm_id_mq_elt_t(
                    /* segment_id */ new_segment_id,
                    /* elt_id */ tmp_elts[i]->id
                ));
                _buffered_elts.push_back(tmp_elts[i]);
            }
        }

        /*!
        *  \note   1. copy data into the mempool elements;
        *          2. NOTE: this is the only memory copy within the transport :-)
        */
        // part 1: copy the part of the data to the remain of last segment
        if(last_elt_remain_size != 0){
            POS_CHECK_POINTER(last_used_elt);
            copy_size = std::min<uint64_t>(last_elt_remain_size, size);

            memcpy(
                /* dst */ last_used_elt->base_addr+last_used_elt->size,
                /* src */ addr,
                /* size */ copy_size
            );
            last_used_elt->size += copy_size;

            size -= copy_size;
            addr = (void*)((uint64_t)addr + copy_size);
        }
        // part 2: copy the remain data to the new mempool elements
        for(i=nb_last_buffered_elt; i<_buffered_elts.size(); i++){
            POS_CHECK_POINTER(elt = _buffered_elts[i]);
            copy_size = std::min<uint64_t>(POS_TRANSPORT_SHM_MEMPOOL_ELT_SIZE, size);

            memcpy(elt->base_addr, addr, copy_size);
            elt->size = copy_size;

            addr = (void*)((uint64_t)addr + copy_size);
            size -= copy_size;
        }

    exit_POSTransport_SHM_put:
        return retval;
    }

    /*!
     *  \brief  flush all buffered data to the other end-point
     *  \return POS_SUCCESS for successfully flushing
     */
    pos_retval_t flush(){
        pos_transport_shm_batch_mq_elt_t nb_buffered_batch = _buffered_elt_idx.size();

        if(nb_buffered_batch > 0){
            // send the index of mempool elements
            for(pos_transport_shm_id_mq_elt_t id : _buffered_elt_idx){
                _send_elt_id_mq->send(
                    /* buffer */ &(id),
                    /* buffer_size */ sizeof(pos_transport_shm_id_mq_elt_t),
                    /* priority */ 0
                );
            }

            // send the batch number
            _send_batch_size_mq->send(
                /* buffer */ &(nb_buffered_batch),
                /* buffer_size */ sizeof(pos_transport_shm_batch_mq_elt_t),
                /* priority */ 0
            );
        }
        
        POS_DEBUG_C("transport sent message: nb_batch(%lu)", nb_buffered_batch);

        return POS_SUCCESS;
    }

 private:
    pos_retval_t _create_shm_segment(uint64_t *new_segment_id){
        pos_retval_t retval = POS_SUCCESS;
        boost::interprocess::managed_shared_memory* segment;
        char name[POS_SHM_SUFFIX_MAXLEN+128] = {0};
        pthread_mutex_t *mempool_lock;
        POSMempoolWithSize_t *mempool;

        POS_CHECK_POINTER(new_segment_id);
        *new_segment_id = _segments.size() > 0 
                                ? _segments.rbegin()->first + 1 : 0;
        POS_ASSERT(_segments.count(*new_segment_id) == 0);

        // step 1: create SHM segment
        memset(name, 0, sizeof(name));
        sprintf(name, "%s_%s_%lu", _shm_prefix_name_common, "segment", *new_segment_id);
        try{
            boost::interprocess::shared_memory_object::remove(name);
            segment = new boost::interprocess::managed_shared_memory(
                boost::interprocess::create_only, 
                name, 
                POS_TRANSPORT_SHM_SEGMENT_SIZE
            );
            if(segment == nullptr){
                POS_WARN_C_DETAIL(
                    "failed to create boost-managed SHM segments: name(%s), size(%lu)", 
                    name, POS_TRANSPORT_SHM_SEGMENT_SIZE
                );
                retval = POS_FAILED;
                goto POSTransport_SHM_create_shm_segment_clean_resource;
            }
        } catch(...) {
            POS_WARN_C_DETAIL(
                "failed to create boost-managed SHM segments: name(%s), size(%lu)", 
                name, POS_TRANSPORT_SHM_SEGMENT_SIZE
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_create_shm_segment_clean_resource;        
        }
        POS_DEBUG_C(
            "create boost-managed SHM segments: addr(%p), name(%s), size(%lu)", 
            segment, name, POS_TRANSPORT_SHM_SEGMENT_SIZE
        );
        _segments[*new_segment_id] = segment;

        // step 2: create mutex lock within SHM segments
        mempool_lock = segment->construct<pthread_mutex_t>("mempool_lock")();
        if(mempool_lock == nullptr){ 
            POS_WARN_C_DETAIL(
                "failed to construct mempool_lock within boost-managed SHM segments: segment_id(%lu)",
                *new_segment_id
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_create_shm_segment_clean_resource; 
        }
        pthread_mutexattr_init(&_lock_attr);
        pthread_mutexattr_setpshared(&_lock_attr, PTHREAD_PROCESS_SHARED);
        pthread_mutex_init(mempool_lock, &_lock_attr);
        POS_DEBUG_C(
            "initialize the mutex lock within SHM: addr(%p), segment_id(%lu)",
            mempool_lock, *new_segment_id
        );
        _mempool_lock_map[*new_segment_id] = mempool_lock;

        // step 3: allocate mempool within SHM segments
        mempool = segment->construct<POSMempoolWithSize_t>("mempool")();
        if(mempool == nullptr){ 
            POS_WARN_C_DETAIL(
                "failed to construct mempool within boost-managed SHM segments, segment_id(%lu)",
                *new_segment_id
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_create_shm_segment_clean_resource; 
        }
        _mempools[*new_segment_id] = mempool;

        goto exit_POSTransport_SHM_create_shm_segment;

    POSTransport_SHM_create_shm_segment_clean_resource:
        clear();

    exit_POSTransport_SHM_create_shm_segment:
        return retval;
    }

    pos_retval_t _open_shm_segment(uint64_t segment_id){
        pos_retval_t retval = POS_SUCCESS;
        boost::interprocess::managed_shared_memory* segment;
        pthread_mutex_t *mempool_lock;
        POSMempoolWithSize_t *mempool;
        char name[POS_SHM_SUFFIX_MAXLEN+128] = {0};

        if(_segments.count(segment_id) != 0){
            POS_WARN_C_DETAIL("try to open already-exist segment: segment_id(%lu)", segment_id);
            return POS_FAILED_ALREADY_EXIST;
        }

        // step 1: open SHM segment
        memset(name, 0, sizeof(name));
        sprintf(name, "%s_%s_%lu", _shm_prefix_name_common, "segment", segment_id);
        try{
            segment = new boost::interprocess::managed_shared_memory(
                boost::interprocess::open_only, name
            );
            if(segment == nullptr){
                POS_WARN_C_DETAIL(
                    "failed to open the boost-managed SHM segments: segment_id(%lu), name(%s), size(%lu)", 
                    segment_id, name, POS_TRANSPORT_SHM_SEGMENT_SIZE
                );
                retval = POS_FAILED;
                goto POSTransport_SHM_open_shm_segment_clean_resource;
            }
        } catch(...) {
            POS_WARN_C_DETAIL(
                "failed to open the boost-managed SHM segments: segment_id(%lu), name(%s), size(%lu)", 
                segment_id, name, POS_TRANSPORT_SHM_SEGMENT_SIZE
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_open_shm_segment_clean_resource;
        }
        POS_DEBUG_C(
            "open the boost-managed SHM segments: segment_id(%lu), addr(%p), name(%s), size(%lu)", 
            segment_id, segment, name, POS_TRANSPORT_SHM_SEGMENT_SIZE
        );
        _segments[segment_id] = segment;

        // step 2: obtain mempool lock within SHM segments
        mempool_lock = segment->find<pthread_mutex_t>("mempool_lock").first;
        if(mempool_lock == nullptr){
            POS_WARN_C_DETAIL(
                "failed to open the mempool_lock within boost-managed SHM segments: segment_id(%lu)",
                segment_id
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_open_shm_segment_clean_resource;
        }
        _mempool_lock_map[segment_id] = mempool_lock;

        // step 3: obtain mempool within SHM segments
        mempool = segment->find<POSMempoolWithSize_t>("mempool").first;
        if(mempool == nullptr){ 
            POS_WARN_C_DETAIL("failed to open mempool within boost-managed SHM segments: segment_id(%lu)",
                segment_id
            );
            retval = POS_FAILED;
            goto POSTransport_SHM_open_shm_segment_clean_resource; 
        }
        _mempools[segment_id] = mempool;

        goto exit_POSTransport_SHM_open_shm_segment;

    POSTransport_SHM_open_shm_segment_clean_resource:
        clear();

    exit_POSTransport_SHM_open_shm_segment:
        return retval;
    }

    // buffered indice of memory pool elements to be sent later
    std::vector<pos_transport_shm_id_mq_elt_t> _buffered_elt_idx;
    std::vector<POSMempoolElt_t*> _buffered_elts;

    // string as prefix to identify transport structures
    char _shm_prefix_name_send[POS_SHM_SUFFIX_MAXLEN];
    char _shm_prefix_name_recv[POS_SHM_SUFFIX_MAXLEN];
    char _shm_prefix_name_common[POS_SHM_SUFFIX_MAXLEN];

    // interprocess message queue that stores mempool element index
    boost::interprocess::message_queue *_recv_elt_id_mq, *_send_elt_id_mq;

    // interprocess message queue that stores batch size
    boost::interprocess::message_queue *_recv_batch_size_mq, *_send_batch_size_mq;

    // TODO: add an api call queue?

    // map of mutex lock to operate on each mempool
    // key: segment id; value: pointer to the mutex lock
    std::map<uint64_t, pthread_mutex_t*> _mempool_lock_map;
    pthread_mutexattr_t _lock_attr;

    // index of this transport
    pos_transport_id_t _id;

    using POSMempoolWithSize_t = POSMempool_t<
        /* nb_elts */ POS_TRANSPORT_SHM_MEMPOOL_NB_ELT,
        /* elt_size */ POS_TRANSPORT_SHM_MEMPOOL_ELT_SIZE
    >;

    // list of mempools
    // key: segment id; value: pointer to the segment
    std::map<uint64_t, POSMempoolWithSize_t*> _mempools;

    // map of boost-managed SHM segments
    // key: segment id; value: pointer to the segment
    std::map<uint64_t, boost::interprocess::managed_shared_memory*> _segments;
};
