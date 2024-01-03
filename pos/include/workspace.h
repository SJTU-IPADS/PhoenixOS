#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <stdint.h>

template<class T_POSTransport, class T_POSClient>
class POSWorkspace;

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/client.h"
#include "pos/include/handle.h"
#include "pos/include/transport.h"
#include "pos/include/oob.h"
#include "pos/include/api_context.h"
#include "pos/include/utils/lockfree_queue.h"

enum pos_queue_position_t : uint8_t {
    kPOS_Queue_Position_Worker = 0,
    kPOS_Queue_Position_Runtime
};

enum pos_queue_type_t : uint8_t {
    kPOS_Queue_Type_WQ = 0,
    kPOS_Queue_Type_CQ
};

template<class T_POSTransport, class T_POSClient>
class POSWorker;

template<class T_POSTransport, class T_POSClient>
class POSRuntime;

/*!
 * \brief   base workspace of PhoenixOS
 */
template<class T_POSTransport, class T_POSClient>
class POSWorkspace {
 public:
    /*!
     *  \brief  constructor
     */
    POSWorkspace() : _current_max_uuid(0) { 
        // create out-of-band server
        _oob_server = new POSOobServer<T_POSTransport, T_POSClient>( /* ws */ this );
        POS_CHECK_POINTER(_oob_server);

        // TODO: create control-plane client here
    }
    
    /*!
     *  \brief  deconstructor
     */
    ~POSWorkspace(){ clear(); }

    /*!
     *  \brief  initialize the workspace, including raise the runtime and worker threads
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     *  \return POS_SUCCESS for successfully initialization
     */
    virtual pos_retval_t init();

    /*!
     *  \brief  shutdown the POS server
     */
    inline void clear(){
        typename std::map<pos_client_uuid_t, T_POSTransport*>::iterator trsp_iter;
        typename std::map<pos_client_uuid_t, T_POSClient*>::iterator client_iter;

        // shutdown out-of-band server
        delete _oob_server;

        // clear all transports
        for(trsp_iter = _transport_maps.begin(); trsp_iter != _transport_maps.end(); trsp_iter++){
            if(trsp_iter->second != nullptr){
                trsp_iter->second->clear();
                delete trsp_iter->second;
            }
        }

        // clear all clients
        for(client_iter = _client_map.begin(); client_iter != _client_map.end(); client_iter++){
            if(client_iter->second != nullptr){
                delete client_iter->second;
            }
        }

        // stop runtime
        if(_runtime != nullptr){ delete _runtime; }

        // stop worker
        if(_worker != nullptr){ delete _worker; }
    }

    /*!
     *  \brief  obtain POSClient according to given uuid
     *  \param  id  specified uuid
     *  \return nullptr for no client with specified uuid is founded;
     *          non-nullptr for pointer to founded client
     */
    inline T_POSClient* get_client_by_uuid(pos_client_uuid_t id){
        if(unlikely(_client_map.count(id) == 0)){
            return nullptr;
        } else {
            return _client_map[id];
        }
    }

    /*!
     *  \brief  obtain POSTransport according to given uuid
     *  \param  id  specified uuid
     *  \return nullptr for no transport with specified uuid is founded;
     *          non-nullptr for pointer to founded transport
     */
    inline T_POSTransport* get_transport_by_uuid(pos_client_uuid_t id){
        if(unlikely(_transport_maps.count(id) == 0)){
            return nullptr;
        } else {
            return _transport_maps[id];
        }
    }

    /*!
     *  \brief  add a new client to the workspace
     *  \param  clnt    pointer to the POSClient to be added
     *  \param  uuid    the result uuid of the added client
     *  \return POS_SUCCESS for successfully added
     */
    inline pos_retval_t create_client(T_POSClient* clnt, pos_client_uuid_t* uuid){
        *uuid = _current_max_uuid;
        _current_max_uuid += 1;
        _client_map[*uuid] = clnt;
        POS_DEBUG_C("add client: addr(%p), uuid(%lu)", clnt, *uuid);
        return POS_SUCCESS;
    }

    /*!
     *  \brief  remove a client by given uuid
     *  \param  uuid    specified uuid of the client to be removed
     *  \return POS_FAILED_NOT_EXIST for no client with the given uuid exists;
     *          POS_SUCCESS for successfully removing
     */
    inline pos_retval_t remove_client(pos_client_uuid_t uuid){
        pos_retval_t retval = POS_SUCCESS;
        T_POSClient* clnt;

        /*!
         * \todo    we need to prevent other functions (e.g., poll_client_dag) would access
         *          those client to be removed, might need a mutex lock to manage the client
         *          map, to be added later
         */
        if(unlikely(_client_map.count(uuid) == 0)){
            retval = POS_FAILED_NOT_EXIST;
            POS_WARN_C("try to remove an non-exist client: uuid(%lu)", uuid);
        } else {
            // clnt = _client_map[uuid];
            // delete clnt;
            // _client_map.erase(uuid);
            // POS_DEBUG_C("remove client: uuid(%lu)", uuid);
        }

        return retval;
    }

    /*!
     *  \brief  create a new queue pair between frontend and runtime for the client specified with uuid
     *  \param  uuid    the uuid to identify a created client
     *  \return POS_FAILED_ALREADY_EXIST for duplicated queue pair;
     *          POS_SUCCESS for successfully created
     */
    inline pos_retval_t create_qp(pos_client_uuid_t uuid){
        if(unlikely(_runtime_wqs.count(uuid) > 0 || _runtime_cqs.count(uuid) > 0)){
            return POS_FAILED_ALREADY_EXIST;
        }

        // create queue pair between frontend and runtime
        POSLockFreeQueue<POSAPIContext_QE_t> *wq = new POSLockFreeQueue<POSAPIContext_QE_t>();
        POS_CHECK_POINTER(wq); _runtime_wqs[uuid] = wq;
        POSLockFreeQueue<POSAPIContext_QE_t> *cq = new POSLockFreeQueue<POSAPIContext_QE_t>();
        POS_CHECK_POINTER(cq); _runtime_cqs[uuid] = cq;

        // create completion queue between frontend and worker
        POSLockFreeQueue<POSAPIContext_QE_t> *cq2 = new POSLockFreeQueue<POSAPIContext_QE_t>();
        POS_CHECK_POINTER(cq2); _worker_cqs[uuid] = cq2;

        return POS_SUCCESS;
    }

    inline pos_retval_t poll_runtime_wq(std::vector<POSAPIContext_QE_ptr>* wqes){
        std::map<pos_client_uuid_t, POSLockFreeQueue<POSAPIContext_QE_t>*>::iterator wq_iter;
        pos_client_uuid_t uuid;
        POSLockFreeQueue<POSAPIContext_QE_t> *wq;
        POSAPIContext_QE_ptr wqe;

        POS_CHECK_POINTER(wqes);
        
        for(wq_iter=_runtime_wqs.begin(); wq_iter!=_runtime_wqs.end(); wq_iter++){
            uuid = wq_iter->first;
            wq = wq_iter->second;

            if(unlikely(_client_map.count(uuid) == 0)){
                /*!
                 *  \todo   try to lazyly delete the wq from the consumer-side here
                 *          but met some multi-thread bug; temp comment out here, which
                 *          will cause memory leak here
                 */
                // _remove_q<kPOS_Queue_Type_WQ, kPOS_Queue_Position_Runtime>(uuid);
                continue;
            }

            if((wqe = wq->pop()) != nullptr){ wqes->push_back(wqe); }
        }
        return POS_SUCCESS;
    }

    template<pos_queue_position_t qt>
    inline pos_retval_t poll_cq(
        std::vector<POSAPIContext_QE_ptr>* cqes, pos_client_uuid_t uuid
    ){
        POSAPIContext_QE_ptr cqe;
        POSLockFreeQueue<POSAPIContext_QE_t> *cq;

        POS_CHECK_POINTER(cqes);

        if constexpr (qt == kPOS_Queue_Position_Runtime){
            if(unlikely(_runtime_cqs.count(uuid) == 0)){ return POS_FAILED_NOT_EXIST; }
            cq = _runtime_cqs[uuid];
        } else if (qt == kPOS_Queue_Position_Worker){
            if(unlikely(_worker_cqs.count(uuid) == 0)){ return POS_FAILED_NOT_EXIST; }
            cq = _worker_cqs[uuid];
        }

        if(unlikely(_client_map.count(uuid) == 0)){
            /*!
             *  \todo   try to lazyly delete the cq from the consumer-side here
             *          but met some multi-thread bug; temp comment out here, which
             *          will cause memory leak here
             */
            if constexpr (qt == kPOS_Queue_Position_Runtime){
                // _remove_q<kPOS_Queue_Type_CQ, kPOS_Queue_Position_Runtime>(uuid);
            } else if (qt == kPOS_Queue_Position_Worker){
                // _remove_q<kPOS_Queue_Type_CQ, kPOS_Queue_Position_Worker>(uuid);
            }
        } else {
            while((cqe = cq->pop()) != nullptr){
                cqes->push_back(cqe);
            }
        }

        return POS_SUCCESS;
    }

    template<pos_queue_position_t qposition>
    inline pos_retval_t push_cq(POSAPIContext_QE_ptr cqe){
        pos_client_uuid_t uuid;
        POSLockFreeQueue<POSAPIContext_QE_t> *cq;

        POS_CHECK_POINTER(cqe);
        uuid = cqe->client_id;

        if constexpr (qposition == kPOS_Queue_Position_Runtime){
            if(unlikely(_runtime_cqs.count(uuid) == 0)){ return POS_FAILED_NOT_EXIST; }
            cq = _runtime_cqs[uuid];
        } else if (qposition == kPOS_Queue_Position_Worker){
            if(unlikely(_worker_cqs.count(uuid) == 0)){ return POS_FAILED_NOT_EXIST; }
            cq = _worker_cqs[uuid];
        }

        cq->push(cqe);

        return POS_SUCCESS;
    }

    inline pos_retval_t poll_client_dag(std::vector<T_POSClient*> *clients){
        typename std::map<pos_client_uuid_t, T_POSClient*>::iterator iter;

        POS_CHECK_POINTER(clients);

        for(iter=_client_map.begin(); iter!=_client_map.end(); iter++){
            if(iter->second != nullptr){
                if(iter->second->dag.has_pending_op()){ clients->push_back(iter->second); }
            }
        }

        return POS_SUCCESS;
    }

    /*!
     *  \brief  remove queue by given uuid
     *  \tparam qtype       type of the queue to be deleted: CQ/WQ
     *  \tparam qposition   position of the queue to be deleted: Runtime/Worker
     *  \param  uuid        specified uuid of the queue pair to be removed
     *  \note   work queue should be lazyly removed as they shared across theads
     *  \return POS_FAILED_NOT_EXIST for no work queue with the given uuid exists;
     *          POS_SUCCESS for successfully removing
     */
    template<pos_queue_type_t qtype, pos_queue_position_t qposition>
    inline pos_retval_t _remove_q(pos_client_uuid_t uuid){
        pos_retval_t retval = POS_SUCCESS;
        POSLockFreeQueue<POSAPIContext_QE_t> *q;

        if constexpr (qtype == kPOS_Queue_Type_WQ){
            if(unlikely(_runtime_wqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                POS_WARN_C("try to remove an non-exist work queue: uuid(%lu)", uuid);
            } else {
                q = _runtime_wqs[uuid]; delete q; 
                _runtime_wqs.erase(uuid);
                POS_DEBUG_C("remove work queue: uuid(%lu)", uuid);
            }
        } else if (qtype == kPOS_Queue_Type_CQ){
            if constexpr (qposition == kPOS_Queue_Position_Runtime){
                if(unlikely(_runtime_cqs.count(uuid) == 0)){
                    retval = POS_FAILED_NOT_EXIST;
                    POS_WARN_C("try to remove an non-exist runtime CQ: uuid(%lu)", uuid);
                } else {
                    q = _runtime_cqs[uuid]; delete q; 
                    _runtime_cqs.erase(uuid);
                    POS_DEBUG_C("remove runtime CQ: uuid(%lu)", uuid);
                }
            } else if (qposition == kPOS_Queue_Position_Worker){
                if(unlikely(_worker_cqs.count(uuid) == 0)){
                    retval = POS_FAILED_NOT_EXIST;
                    POS_WARN_C("try to remove an non-exist worker CQ: uuid(%lu)", uuid);
                } else {
                    q = _worker_cqs[uuid]; delete q; 
                    _worker_cqs.erase(uuid);
                    POS_DEBUG_C("remove worker CQ: uuid(%lu)", uuid);
                }
            }
        }

        return retval;
    }

    /*!
     *  \brief  add a new transport to the workspace
     *  \param  clnt    pointer to the POSTransport to be added
     *  \param  uuid    uuid of the transport to be added
     *  \return POS_SUCCESS for successfully added
     */
    inline pos_retval_t create_transport(T_POSTransport* trpt, pos_client_uuid_t uuid){
        POS_CHECK_POINTER(trpt);
        _transport_maps[uuid] = trpt;
        POS_DEBUG_C("add transport: addr(%p), uuid(%lu)", trpt, uuid);
        return POS_SUCCESS;
    }

    /*!
     *  \brief  remove a transport by given uuid
     *  \param  uuid    specified uuid of the transport to be removed
     *  \return POS_FAILED_NOT_EXIST for no transport with the given uuid exists;
     *          POS_SUCCESS for successfully removing
     */
    inline pos_retval_t remove_transport(pos_client_uuid_t uuid){
        pos_retval_t retval = POS_SUCCESS;
        T_POSTransport* trpt;

        if(unlikely(_transport_maps.count(uuid) == 0)){
            retval = POS_FAILED_NOT_EXIST;
            POS_WARN_C("try to remove an non-exist transport: uuid(%lu)", uuid);
        } else {
            trpt = _transport_maps[uuid];
            delete trpt;
            _transport_maps.erase(uuid);
            POS_DEBUG_C("remove transport: uuid(%lu)", uuid);
        }

        return retval;
    }

    /*!
     *  \brief  entrance of POS processing
     *  \param  api_id          index of the called API
     *  \param  uuid            uuid of the remote client
     *  \param  is_sync         indicate whether the api is a sync one
     *  \param  param_desps     description of all parameters of the call
     *  \param  ret_data        pointer to the data to be returned
     *  \param  ret_data_len    length of the data to be returned
     *  \return return code on specific XPU platform
     */
    inline int pos_process(
        uint64_t api_id, pos_client_uuid_t uuid, std::vector<POSAPIParamDesp_t> param_desps,
        void* ret_data=nullptr, uint64_t ret_data_len=0
    ){
        uint64_t i;
        int retval, prev_error_code = 0;
        T_POSClient *client;
        T_POSTransport *transport;
        POSAPIMeta_t api_meta;
        bool has_prev_error = false;
        POSAPIContext_QE_ptr wqe;
        std::vector<POSAPIContext_QE_ptr> cqes;
        POSLockFreeQueue<POSAPIContext_QE_t>* wq;
        
        // TODO: we assume always be client 0 here, for debugging under cricket
        uuid = 0;

    #if POS_ENABLE_DEBUG_CHECK
        // check whether the client exists
        if(unlikely(_client_map.count(uuid) == 0)){
            POS_WARN_C_DETAIL("no client with uuid(%lu) was recorded", uuid);
            return POS_FAILED_NOT_EXIST;
        }
    #endif // POS_ENABLE_DEBUG_CHECK

        POS_CHECK_POINTER(client = _client_map[uuid]);

    #if POS_ENABLE_DEBUG_CHECK
        // check whether the transport exists
        /*! \note   for debuging without transport, we temp comment out this check */
        // if(unlikely(_transport_maps.count(uuid) == 0)){
        //     POS_WARN_C_DETAIL("no transport with uuid(%lu) was recorded", uuid);
        //     return POS_FAILED_NOT_EXIST;
        // }
    #endif // POS_ENABLE_DEBUG_CHECK

        // POS_CHECK_POINTER(transport = _transport_maps[uuid]);

        // check whether the work queue exists
    #if POS_ENABLE_DEBUG_CHECK
        if(unlikely(_runtime_wqs.count(uuid) == 0)){
            POS_WARN_C_DETAIL("no work queue with client uuid(%lu) was created", uuid);
            return POS_FAILED_NOT_EXIST;
        }
    #endif // POS_ENABLE_DEBUG_CHECK

        POS_CHECK_POINTER(wq = _runtime_wqs[uuid]);

        // check whether the metadata of the API was recorded
    #if POS_ENABLE_DEBUG_CHECK
        if(unlikely(api_mgnr->api_metas.count(api_id) == 0)){
            POS_WARN_C_DETAIL(
                "no api metadata was recorded in the api manager: api_id(%lu)", api_id
            );
            return POS_FAILED_NOT_EXIST;
        }
    #endif // POS_ENABLE_DEBUG_CHECK
    
        api_meta = api_mgnr->api_metas[api_id];

        // generate new work queue element
        wqe = std::make_shared<POSAPIContext_QE>(
            /* api_id*/ api_id,
            /* uuid */ uuid,
            /* param_desps */ param_desps,
            /* api_inst_id */ client->get_and_move_api_inst_pc(),
            /* retval_data */ ret_data,
            /* retval_size */ ret_data_len,
            /* pos_client */ (void*)client,
            /* pos_transport */ (void*)transport
        );
        POS_CHECK_POINTER(wqe);

        // push to the work queue
        wq->push(wqe);
        
        /*!
         *  \note   if this is a sync call, we need to block until cqe is obtained
         */
        if(unlikely(api_meta.is_sync)){
            while(1){
                // we declare the pointer here so every iteration ends the shared_ptr would be released
                POSAPIContext_QE_ptr cqe;

                if(unlikely(POS_SUCCESS != poll_cq<kPOS_Queue_Position_Runtime>(&cqes, uuid))){
                    POS_ERROR_C_DETAIL("failed to poll runtime cq");
                }

                if(unlikely(POS_SUCCESS != poll_cq<kPOS_Queue_Position_Worker>(&cqes, uuid))){
                    POS_ERROR_C_DETAIL("failed to poll worker cq");
                }

            #if POS_ENABLE_DEBUG_CHECK
                if(cqes.size() > 0){
                    POS_DEBUG_C("polling completion queue, obtain %lu elements: uuid(%lu)", cqes.size(), uuid);
                }
            #endif

                for(i=0; i<cqes.size(); i++){
                    POS_CHECK_POINTER(cqe = cqes[i]);

                    // found the called sync api
                    if(cqe->api_inst_id == wqe->api_inst_id){
                        // we should NOT do this assumtion here!
                        // assert(i == cqes.size() - 1);

                        // setup return code
                        retval = has_prev_error ? prev_error_code : cqe->api_cxt->return_code;

                        /*!
                         *  \brief  setup return data
                         *  \note   avoid this copy!
                         *          then we assume only sync call would have return data
                         */
                        // if(unlikely(ret_data_len > 0 && ret_data != nullptr)){
                        //     memcpy(ret_data, cqe->api_cxt->ret_data, ret_data_len);
                        // }

                        goto exit_POSWorkspace_pos_process;
                    }

                    // record previous async error
                    if(unlikely(
                        cqe->status == kPOS_API_Execute_Status_Parse_Failed
                        || cqe->status == kPOS_API_Execute_Status_Launch_Failed
                    )){
                        has_prev_error = true;
                        prev_error_code = cqe->api_cxt->return_code;
                    }
                }

                cqes.clear();
            }
        } else {
            // if this is a async call, we directly return success
            retval = api_mgnr->cast_pos_retval(POS_SUCCESS, api_meta.library_id);
        }

    exit_POSWorkspace_pos_process:
        return retval;
    }

    // api manager
    POSApiManager *api_mgnr;

    // api id to mark an checkpoint op (different by platforms)
    uint64_t checkpoint_api_id;

    // idx of all stateful resources (handles)
    std::vector<uint64_t> stateful_handle_type_idx;

 protected:
    // pos runtime
    POSRuntime<T_POSTransport, T_POSClient> *_runtime;

    // pos worker
    POSWorker<T_POSTransport, T_POSClient> *_worker;

    // the out-of-band server
    POSOobServer<T_POSTransport, T_POSClient> *_oob_server;

    // queue pairs between frontend and runtime (per client)
    std::map<pos_client_uuid_t, POSLockFreeQueue<POSAPIContext_QE_t>*> _runtime_wqs;
    std::map<pos_client_uuid_t, POSLockFreeQueue<POSAPIContext_QE_t>*> _runtime_cqs;

    // completion queue between frontend and worker (per client)
    std::map<pos_client_uuid_t, POSLockFreeQueue<POSAPIContext_QE_t>*> _worker_cqs;

    // map of clients
    std::map<pos_client_uuid_t, T_POSClient*> _client_map;

    // map of transports
    std::map<pos_client_uuid_t, T_POSTransport*> _transport_maps;

    // the max uuid that has been recorded
    pos_client_uuid_t _current_max_uuid;
};
