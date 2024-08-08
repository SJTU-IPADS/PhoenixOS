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
#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
    kPOS_Queue_Position_Parser
};

enum pos_queue_type_t : uint8_t {
    kPOS_Queue_Type_WQ = 0,
    kPOS_Queue_Type_CQ
};

class POSWorker;
class POSParser;

/*!
 *  \brief  function prototypes for cli oob server
 */
namespace oob_functions {
    POS_OOB_DECLARE_SVR_FUNCTIONS(agent_register_client);
    POS_OOB_DECLARE_SVR_FUNCTIONS(agent_unregister_client);
    POS_OOB_DECLARE_SVR_FUNCTIONS(cli_migration_signal);
    POS_OOB_DECLARE_SVR_FUNCTIONS(cli_restore_signal);
    POS_OOB_DECLARE_SVR_FUNCTIONS(utils_mock_api_call);
}; // namespace oob_functions

/*!
 * \brief   base workspace of PhoenixOS
 */
class POSWorkspace {
 public:
    /*!
     *  \brief  constructor
     */
    POSWorkspace(int argc, char *argv[]) : _current_max_uuid(0) {
        // readin commandline options
        this->parse_command_line_options(argc, argv);

        // create out-of-band server
        _oob_server = new POSOobServer(
            /* ws */ this,
            /* callback_handlers */ {
                {   kPOS_OOB_Msg_Agent_Register_Client,   oob_functions::agent_register_client::sv      },
                {   kPOS_OOB_Msg_Agent_Unregister_Client, oob_functions::agent_unregister_client::sv    },
                {   kPOS_OOB_Msg_Utils_MockAPICall,     oob_functions::utils_mock_api_call::sv        },
                {   kPOS_OOB_Msg_CLI_Migration_Signal,  oob_functions::cli_migration_signal::sv     },
                {   kPOS_OOB_Msg_CLI_Restore_Signal,    oob_functions::cli_restore_signal::sv       },
            },
            /* ip_str */ POS_OOB_SERVER_DEFAULT_IP,
            /* port */ POS_OOB_SERVER_DEFAULT_PORT
        );
        POS_CHECK_POINTER(_oob_server);

        POS_LOG(
            "workspace created:                             \n"
            "   common configurations:                      \n"
            "       =>  enable_context_pool(%s)             \n"
            "   ckpt configirations:                        \n"
            "       =>  ckpt_opt_level(%d, %s)              \n"
            "       =>  ckpt_interval(%lu ms)               \n"
            "       =>  enable_ckpt_increamental(%s)        \n"
            "       =>  enable_ckpt_pipeline(%s)            \n"
            "   migration configurations:                   \n"
            "       =>  migration_opt_level(%d, %s)         \n"
            ,
            POS_ENABLE_CONTEXT_POOL == 1 ? "true" : "false",
            POS_CKPT_OPT_LEVEL,
            POS_CKPT_OPT_LEVEL == 0 ? "no ckpt" : POS_CKPT_OPT_LEVEL == 1 ? "sync ckpt" : "async ckpt",
            POS_CKPT_INTERVAL,
            POS_CKPT_OPT_LEVEL == 0 ? "N/A" : POS_CKPT_ENABLE_INCREMENTAL == 1 ? "true" : "false",
            POS_CKPT_OPT_LEVEL <= 1 ? "N/A" : POS_CKPT_ENABLE_PIPELINE == 1 ? "true" : "false",
            POS_MIGRATION_OPT_LEVEL,
            POS_MIGRATION_OPT_LEVEL == 0 ? "no migration" : POS_MIGRATION_OPT_LEVEL == 1 ? "naive" : "pre-copy"
        );
    }
    
    /*!
     *  \brief  deconstructor
     */
    ~POSWorkspace(){ 
        clear(); 
    }

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
    void clear();

    /*!
     *  \brief  create and add a new client to the workspace
     *  \param  clnt    pointer to the POSClient to be added
     *  \param  uuid    the result uuid of the added client
     *  \return POS_SUCCESS for successfully added
     */
    virtual pos_retval_t create_client(POSClient** clnt, pos_client_uuid_t* uuid){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  remove a client by given uuid
     *  \param  uuid    specified uuid of the client to be removed
     *  \return POS_FAILED_NOT_EXIST for no client with the given uuid exists;
     *          POS_SUCCESS for successfully removing
     */
    inline pos_retval_t remove_client(pos_client_uuid_t uuid){
        pos_retval_t retval = POS_SUCCESS;
        void* clnt;

        /*!
         * \todo    we need to prevent other functions would access
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
     *  \brief  obtain client by given uuid
     *  \param  uuid    uuid of the client
     *  \return pointer to the corresponding POSClient
     */
    inline POSClient* get_client_by_uuid(pos_client_uuid_t uuid){
        POSClient *retval = nullptr;

        if(unlikely(_client_map.count(uuid) > 0)){
            retval = _client_map[uuid];
        }

        return retval;
    }

    /*!
     *  \brief  obtain client map
     *  \return client map
     */
    inline std::map<pos_client_uuid_t, POSClient*>& get_client_map(){
        return this->_client_map;
    }

    /*!
     *  \brief  create a new queue pair between frontend and runtime for the client specified with uuid
     *  \param  uuid    the uuid to identify a created client
     *  \return POS_FAILED_ALREADY_EXIST for duplicated queue pair;
     *          POS_SUCCESS for successfully created
     */
    inline pos_retval_t create_qp(pos_client_uuid_t uuid){
        if(unlikely(_parser_wqs.count(uuid) > 0 || _parser_cqs.count(uuid) > 0)){
            return POS_FAILED_ALREADY_EXIST;
        }

        // create queue pair between frontend and parser
        POSLockFreeQueue<POSAPIContext_QE_t*> *wq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
        POS_CHECK_POINTER(wq);
        _parser_wqs[uuid] = wq;

        POSLockFreeQueue<POSAPIContext_QE_t*> *cq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
        POS_CHECK_POINTER(cq);
        _parser_cqs[uuid] = cq;

        // create completion queue between frontend and worker
        POSLockFreeQueue<POSAPIContext_QE_t*> *cq2 = new POSLockFreeQueue<POSAPIContext_QE_t*>();
        POS_CHECK_POINTER(cq2);
        _worker_cqs[uuid] = cq2;

        return POS_SUCCESS;
    }

    inline POSAPIContext_QE* dequeue_parser_job(pos_client_uuid_t uuid){
        pos_retval_t tmp_retval;
        POSAPIContext_QE *wqe = nullptr;
        POSLockFreeQueue<POSAPIContext_QE_t*> *wq;

        if(unlikely(_parser_wqs.count(uuid) == 0)){
            POS_WARN("no parser wq with client uuid %lu registered", uuid);
            goto exit;
        }

        POS_CHECK_POINTER(wq = _parser_wqs[uuid]);
        wq->dequeue(wqe);

    exit:
        return wqe;
    }

    template<pos_queue_position_t qt>
    inline pos_retval_t poll_cq(
        std::vector<POSAPIContext_QE*>* cqes, pos_client_uuid_t uuid
    ){
        POSAPIContext_QE *cqe;
        POSLockFreeQueue<POSAPIContext_QE_t*> *cq;

        POS_CHECK_POINTER(cqes);

        if constexpr (qt == kPOS_Queue_Position_Parser){
            if(unlikely(_parser_cqs.count(uuid) == 0)){ return POS_FAILED_NOT_EXIST; }
            cq = _parser_cqs[uuid];
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
            if constexpr (qt == kPOS_Queue_Position_Parser){
                // _remove_q<kPOS_Queue_Type_CQ, kPOS_Queue_Position_Parser>(uuid);
            } else if (qt == kPOS_Queue_Position_Worker){
                // _remove_q<kPOS_Queue_Type_CQ, kPOS_Queue_Position_Worker>(uuid);
            }
        } else {
            while(POS_SUCCESS == cq->dequeue(cqe)){
                cqes->push_back(cqe);
            }
        }

        return POS_SUCCESS;
    }

    template<pos_queue_position_t qposition>
    inline pos_retval_t push_cq(POSAPIContext_QE *cqe){
        pos_client_uuid_t uuid;
        POSLockFreeQueue<POSAPIContext_QE_t*> *cq;

        POS_CHECK_POINTER(cqe);
        uuid = cqe->client_id;

        if constexpr (qposition == kPOS_Queue_Position_Parser){
            if(unlikely(_parser_cqs.count(uuid) == 0)){ return POS_FAILED_NOT_EXIST; }
            cq = _parser_cqs[uuid];
        } else if (qposition == kPOS_Queue_Position_Worker){
            if(unlikely(_worker_cqs.count(uuid) == 0)){ return POS_FAILED_NOT_EXIST; }
            cq = _worker_cqs[uuid];
        }

        cq->push(cqe);

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
        POSLockFreeQueue<POSAPIContext_QE_t*> *q;

        if constexpr (qtype == kPOS_Queue_Type_WQ){
            if(unlikely(_parser_wqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                POS_WARN_C("try to remove an non-exist work queue: uuid(%lu)", uuid);
            } else {
                q = _parser_wqs[uuid]; delete q; 
                _parser_wqs.erase(uuid);
                POS_DEBUG_C("remove work queue: uuid(%lu)", uuid);
            }
        } else if (qtype == kPOS_Queue_Type_CQ){
            if constexpr (qposition == kPOS_Queue_Position_Parser){
                if(unlikely(_parser_cqs.count(uuid) == 0)){
                    retval = POS_FAILED_NOT_EXIST;
                    POS_WARN_C("try to remove an non-exist runtime CQ: uuid(%lu)", uuid);
                } else {
                    q = _parser_cqs[uuid]; delete q; 
                    _parser_cqs.erase(uuid);
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
     *  \brief  entrance of POS processing
     *  \param  api_id          index of the called API
     *  \param  uuid            uuid of the remote client
     *  \param  is_sync         indicate whether the api is a sync one
     *  \param  param_desps     description of all parameters of the call
     *  \param  ret_data        pointer to the data to be returned
     *  \param  ret_data_len    length of the data to be returned
     *  \return return code on specific XPU platform
     */
    int pos_process(
        uint64_t api_id, pos_client_uuid_t uuid, std::vector<POSAPIParamDesp_t> param_desps,
        void* ret_data=nullptr, uint64_t ret_data_len=0
    );

    // api manager
    POSApiManager *api_mgnr;

    // api id to mark an checkpoint op (different by platforms)
    uint64_t checkpoint_api_id;

    // idx of all stateful resources (handles)
    std::vector<uint64_t> stateful_handle_type_idx;

 protected:
    /*!
     *  \brief  out-of-band server
     *  \note   use cases: intereact with CLI, and also agent-side
     */
    POSOobServer *_oob_server;

    // queue pairs between frontend and runtime (per client)
    std::map<pos_client_uuid_t, POSLockFreeQueue<POSAPIContext_QE_t*>*> _parser_wqs;
    std::map<pos_client_uuid_t, POSLockFreeQueue<POSAPIContext_QE_t*>*> _parser_cqs;

    // completion queue between frontend and worker (per client)
    std::map<pos_client_uuid_t, POSLockFreeQueue<POSAPIContext_QE_t*>*> _worker_cqs;

    // map of clients
    std::map<pos_client_uuid_t, POSClient*> _client_map;

    // the max uuid that has been recorded
    pos_client_uuid_t _current_max_uuid;

    // context for creating the client
    pos_client_cxt_t _template_client_cxt;

    /*!
     *  \brief  preserve resource on posd
     *  \param  rid     the resource type to preserve
     *  \param  data    source data for preserving
     *  \return POS_SUCCESS for successfully preserving
     */
    virtual pos_retval_t preserve_resource(pos_resource_typeid_t rid, void *data){
        return POS_FAILED_NOT_IMPLEMENTED;
    }
    
    void parse_command_line_options(int argc, char *argv[]);
};
