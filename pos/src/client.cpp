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
#include <map>
#include <algorithm>

#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/workspace.h"
#include "pos/include/handle.h"
#include "pos/include/client.h"
#include "pos/include/api_context.h"


POSClient::POSClient(pos_client_uuid_t id, pos_client_cxt_t cxt, POSWorkspace *ws) 
    :   id(id),
        migration_ctx(this),
        status(kPOS_ClientStatus_CreatePending),
        _api_inst_pc(0), 
        _cxt(cxt),
        _last_ckpt_tick(0),
        _ws(ws)
{}


POSClient::POSClient() 
    :   id(0),
        migration_ctx(this),
        status(kPOS_ClientStatus_CreatePending),
        _last_ckpt_tick(0),
        _ws(nullptr)
{
    POS_ERROR_C("shouldn't call, just for passing compilation");
}


void POSClient::init(){
    pos_retval_t retval = POS_SUCCESS;
    std::map<pos_u64id_t, POSAPIContext_QE_t*> apicxt_sequence_map;
    std::multimap<pos_u64id_t, POSHandle*> missing_handle_map;

    if(unlikely(POS_SUCCESS != (
        retval = this->init_handle_managers()
    ))){
        POS_WARN_C("failed to initialize handle managers");
        goto exit;
    }
    
    if(unlikely(POS_SUCCESS != (
        retval = this->__create_qgroup()
    ))){
        POS_WARN_C("failed to initialize queue group");
        goto exit;
    }

exit:
    if(unlikely(retval != POS_SUCCESS)){
        this->status = kPOS_ClientStatus_Hang;
    } else {
        // enable parser and worker to poll
        this->status = kPOS_ClientStatus_Active;
    }
}


void POSClient::deinit(){
    this->deinit_dump_handle_managers();

    // stop parser and worker to poll
    this->status = kPOS_ClientStatus_Hang;

    this->__destory_qgroup();
}


template<pos_queue_direction_t qdir, pos_queue_type_t qtype>
pos_retval_t POSClient::push_q(void *qe){
    pos_retval_t retval = POS_SUCCESS;
    POSAPIContext_QE_t *apictx_qe;
    POSCommand_QE_t *cmd_qe;

    static_assert(
            qtype == kPOS_QueueType_ApiCxt_WQ || qtype == kPOS_QueueType_ApiCxt_CQ
        ||  qtype == kPOS_QueueType_ApiCxt_CkptDag_WQ
        ||  qtype == kPOS_QueueType_Cmd_WQ || qtype == kPOS_QueueType_Cmd_CQ,
        "unknown queue type obtained"
    );

    POS_CHECK_POINTER(qe);

    // api context worker queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_WQ){
        POS_CHECK_POINTER(apictx_qe = reinterpret_cast<POSAPIContext_QE_t*>(qe));
        
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Parser2Worker,
            "ApiCxt_WQE can only be pushed to rpc2parser or parser2worker queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            this->_apicxt_rpc2parser_wq->push(apictx_qe);
        } else { // qdir == kPOS_QueueDirection_Parser2Worker
            this->_apicxt_parser2worker_wq->push(apictx_qe);
        }
    }

    // api context completion queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_CQ){
        POS_CHECK_POINTER(apictx_qe = reinterpret_cast<POSAPIContext_QE_t*>(qe));
 
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Rpc2Worker,
            "ApiCxt_CQE can only be pushed to rpc2parser or rpc2worker queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            this->_apicxt_rpc2parser_cq->push(apictx_qe);
        } else { // qdir == kPOS_QueueDirection_Rpc2Worker
            this->_apicxt_rpc2worker_cq->push(apictx_qe);
        }
    }

    // api context ckptdag queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_CkptDag_WQ) {
        POS_CHECK_POINTER(apictx_qe = reinterpret_cast<POSAPIContext_QE_t*>(qe));

        static_assert(
            qdir == kPOS_QueueDirection_WorkerLocal,
            "ApiCxt_CkptDag_WQE can only be pushed to worker local queue"
        );

        this->_apicxt_workerlocal_ckptdag_wq->push(apictx_qe);
    }

    // command work queue
    if constexpr (qtype == kPOS_QueueType_Cmd_WQ){
        POS_CHECK_POINTER(cmd_qe = reinterpret_cast<POSCommand_QE_t*>(qe));
        
        static_assert(
            qdir == kPOS_QueueDirection_Parser2Worker || qdir == kPOS_QueueDirection_Oob2Parser,
            "Cmd_WQE can only be pushed to parser2worker or oob2parser queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Parser2Worker){
            this->_cmd_parser2worker_wq->push(cmd_qe);
        } else { // qdir == kPOS_QueueDirection_Oob2Parser
            this->_cmd_oob2parser_wq->push(cmd_qe);
        }
    }

    // command completion queue
    if constexpr (qtype == kPOS_QueueType_Cmd_CQ){
        POS_CHECK_POINTER(cmd_qe = reinterpret_cast<POSCommand_QE_t*>(qe));
        
        static_assert(
            qdir == kPOS_QueueDirection_Parser2Worker || qdir == kPOS_QueueDirection_Oob2Parser,
            "Cmd_CQE can only be pushed to parser2worker or oob2parser queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Parser2Worker){
            this->_cmd_parser2worker_cq->push(cmd_qe);
        } else { // qdir == kPOS_QueueDirection_Oob2Parser
            this->_cmd_oob2parser_cq->push(cmd_qe);
        }
    }

exit:
    return retval;
}
template pos_retval_t POSClient::push_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_WQ>(void *qe);
template pos_retval_t POSClient::push_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_CQ>(void *qe);
template pos_retval_t POSClient::push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(void *qe);
template pos_retval_t POSClient::push_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(void *qe);
template pos_retval_t POSClient::push_q<kPOS_QueueDirection_WorkerLocal, kPOS_QueueType_ApiCxt_CkptDag_WQ>(void *qe);
template pos_retval_t POSClient::push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_WQ>(void *qe);
template pos_retval_t POSClient::push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(void *qe);
template pos_retval_t POSClient::push_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_WQ>(void *qe);
template pos_retval_t POSClient::push_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_CQ>(void *qe);


template<pos_queue_direction_t qdir, pos_queue_type_t qtype>
pos_retval_t POSClient::clear_q(){
    pos_retval_t retval = POS_SUCCESS;

    static_assert(
            qtype == kPOS_QueueType_ApiCxt_WQ || qtype == kPOS_QueueType_ApiCxt_CQ
        ||  qtype == kPOS_QueueType_ApiCxt_CkptDag_WQ
        ||  qtype == kPOS_QueueType_Cmd_WQ || qtype == kPOS_QueueType_Cmd_CQ,
        "unknown queue type obtained"
    );

    // api context worker queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_WQ){
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Parser2Worker,
            "ApiCxt_WQE can only be located within rpc2parser or parser2worker queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            this->_apicxt_rpc2parser_wq->drain();
        } else { // qdir == kPOS_QueueDirection_Parser2Worker
            this->_apicxt_parser2worker_wq->drain();
        }
    }

    // api context completion queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_CQ){
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Rpc2Worker,
            "ApiCxt_CQE can only be located within rpc2parser or rpc2worker queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            this->_apicxt_rpc2parser_cq->drain();
        } else { // qdir == kPOS_QueueDirection_Rpc2Worker
            this->_apicxt_rpc2worker_cq->drain();
        }
    }

    // api context ckptdag queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_CkptDag_WQ) {
        static_assert(
            qdir == kPOS_QueueDirection_WorkerLocal,
            "ApiCxt_CkptDag_WQE can only be located within worker local queue"
        );
        this->_apicxt_workerlocal_ckptdag_wq->drain();
    }

    // command work queue
    if constexpr (qtype == kPOS_QueueType_Cmd_WQ){
        static_assert(
            qdir == kPOS_QueueDirection_Parser2Worker || qdir == kPOS_QueueDirection_Oob2Parser,
            "Cmd_WQE can only be located within parser2worker or oob2parser queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Parser2Worker){
            this->_cmd_parser2worker_wq->drain();
        } else { // qdir == kPOS_QueueDirection_Oob2Parser
            this->_cmd_oob2parser_wq->drain();
        }
    }

    // command completion queue
    if constexpr (qtype == kPOS_QueueType_Cmd_CQ){
        static_assert(
            qdir == kPOS_QueueDirection_Parser2Worker || qdir == kPOS_QueueDirection_Oob2Parser,
            "Cmd_CQE can only be located within parser2worker or oob2parser queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Parser2Worker){
            this->_cmd_parser2worker_cq->drain();
        } else { // qdir == kPOS_QueueDirection_Oob2Parser
            this->_cmd_oob2parser_cq->drain();
        }
    }

exit:
    return retval;
}
template pos_retval_t POSClient::clear_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_WQ>();
template pos_retval_t POSClient::clear_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_CQ>();
template pos_retval_t POSClient::clear_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>();
template pos_retval_t POSClient::clear_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>();
template pos_retval_t POSClient::clear_q<kPOS_QueueDirection_WorkerLocal, kPOS_QueueType_ApiCxt_CkptDag_WQ>();
template pos_retval_t POSClient::clear_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_WQ>();
template pos_retval_t POSClient::clear_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>();
template pos_retval_t POSClient::clear_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_WQ>();
template pos_retval_t POSClient::clear_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_CQ>();


template<pos_queue_direction_t qdir, pos_queue_type_t qtype>
pos_retval_t POSClient::poll_q(std::vector<POSAPIContext_QE*>* qes){
    pos_retval_t retval = POS_SUCCESS;
    POSAPIContext_QE *apicxt_qe;
    POSLockFreeQueue<POSAPIContext_QE_t*> *apicxt_q;

    static_assert(
            qtype == kPOS_QueueType_ApiCxt_WQ 
        ||  qtype == kPOS_QueueType_ApiCxt_CQ 
        ||  qtype == kPOS_QueueType_ApiCxt_CkptDag_WQ,
        "invalid queue type obtained"
    );

    POS_CHECK_POINTER(qes);

    // api context work queue
    if constexpr (qtype == kPOS_QueueType_ApiCxt_WQ){
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Parser2Worker,
            "POSAPIContext_WQE can only be poll from rpc2parser or parser2worker queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            apicxt_q = this->_apicxt_rpc2parser_wq;
        } else { // kPOS_QueueDirection_Parser2Worker
            apicxt_q = this->_apicxt_parser2worker_wq;
        }
    }

    // api context completion queue
    if constexpr (qtype == kPOS_QueueType_ApiCxt_CQ){
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Rpc2Worker,
            "POSAPIContext_CQE can only be poll from rpc2parser or parser2worker queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            apicxt_q = this->_apicxt_rpc2parser_cq;
        } else { // kPOS_QueueDirection_Rpc2Worker
            apicxt_q = this->_apicxt_rpc2worker_cq;
        }
    }

    // api context ckptdag work queue
    if constexpr (qtype == kPOS_QueueType_ApiCxt_CkptDag_WQ){
        static_assert(
            qdir == kPOS_QueueDirection_WorkerLocal,
            "ApiCxt_CkptDag_WQE can only be passed within worker local queue"
        );
        apicxt_q = this->_apicxt_workerlocal_ckptdag_wq;
    }

    POS_CHECK_POINTER(apicxt_q);
    while(POS_SUCCESS == apicxt_q->dequeue(apicxt_qe)){
        qes->push_back(apicxt_qe);
    }

exit:
    return retval;
}
template pos_retval_t POSClient::poll_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_WQ>(std::vector<POSAPIContext_QE*>* qes);
template pos_retval_t POSClient::poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(std::vector<POSAPIContext_QE*>* qes);
template pos_retval_t POSClient::poll_q<kPOS_QueueDirection_WorkerLocal, kPOS_QueueType_ApiCxt_CkptDag_WQ>(std::vector<POSAPIContext_QE*>* qes);
template pos_retval_t POSClient::poll_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_CQ>(std::vector<POSAPIContext_QE*>* qes);
template pos_retval_t POSClient::poll_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(std::vector<POSAPIContext_QE*>* qes);


template<pos_queue_direction_t qdir, pos_queue_type_t qtype>
pos_retval_t POSClient::poll_q(std::vector<POSCommand_QE_t*>* qes){
    pos_retval_t retval = POS_SUCCESS;
    POSCommand_QE_t *cmd_qe;
    POSLockFreeQueue<POSCommand_QE_t*> *cmd_q;
    
    static_assert(
        qtype == kPOS_QueueType_Cmd_WQ || qtype == kPOS_QueueType_Cmd_CQ,
        "invalid queue type obtained"
    );

    POS_CHECK_POINTER(qes);

    // command work queue
    if constexpr (qtype == kPOS_QueueType_Cmd_WQ){
        static_assert(
            qdir == kPOS_QueueDirection_Parser2Worker || qdir == kPOS_QueueDirection_Oob2Parser,
            "POSCommand_WQE can only be polled from parser2worker or oob2parser queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Parser2Worker){
            cmd_q = this->_cmd_parser2worker_wq;
        } else { // kPOS_QueueDirection_Oob2Parser
            cmd_q = this->_cmd_oob2parser_wq;
        }
    }

    // command completion queue
    if constexpr (qtype == kPOS_QueueType_Cmd_CQ){
        static_assert(
            qdir == kPOS_QueueDirection_Parser2Worker || qdir == kPOS_QueueDirection_Oob2Parser,
            "POSCommand_CQE can only be polled from parser2worker or oob2parser queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Parser2Worker){
            cmd_q = this->_cmd_parser2worker_cq;
        } else { // kPOS_QueueDirection_Oob2Parser
            cmd_q = this->_cmd_oob2parser_cq;
        }
    }

    POS_CHECK_POINTER(cmd_q);
    while(POS_SUCCESS == cmd_q->dequeue(cmd_qe)){
        qes->push_back(cmd_qe);
    }

exit:
    return retval;
}
template pos_retval_t POSClient::poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_WQ>(std::vector<POSCommand_QE_t*>* qes);
template pos_retval_t POSClient::poll_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_WQ>(std::vector<POSCommand_QE_t*>* qes);
template pos_retval_t POSClient::poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_Cmd_CQ>(std::vector<POSCommand_QE_t*>* qes);
template pos_retval_t POSClient::poll_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_CQ>(std::vector<POSCommand_QE_t*>* qes);


pos_retval_t POSClient::__create_qgroup(){
    pos_retval_t retval = POS_SUCCESS;

    // rpc2parser apicxt work queue
    this->_apicxt_rpc2parser_wq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
    POS_CHECK_POINTER(this->_apicxt_rpc2parser_wq);
    POS_DEBUG_C("created rpc2parser apicxt WQ: uuid(%lu)", this->id);

    // rpc2parser apicxt completion queue
    this->_apicxt_rpc2parser_cq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
    POS_CHECK_POINTER(this->_apicxt_rpc2parser_cq);
    POS_DEBUG_C("created rpc2parser apicxt CQ: uuid(%lu)", this->id);

    // parser2worker apicxt work queue
    this->_apicxt_parser2worker_wq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
    POS_CHECK_POINTER(this->_apicxt_parser2worker_wq);
    POS_DEBUG_C("created parser2worker apicxt WQ: uuid(%lu)", this->id);

    // rpc2worker apicxt completion queue
    this->_apicxt_rpc2worker_cq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
    POS_CHECK_POINTER(this->_apicxt_rpc2worker_cq);
    POS_DEBUG_C("created rpc2worker apicxt CQ: uuid(%lu)", this->id);

    // workerlocal apicxt ckptdag queue
    this->_apicxt_workerlocal_ckptdag_wq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
    POS_CHECK_POINTER(this->_apicxt_workerlocal_ckptdag_wq);
    POS_DEBUG_C("created workerlocal ckptdagapicxt WQ: uuid(%lu)", this->id);

    // parser2worker cmd work queue
    this->_cmd_parser2worker_wq = new POSLockFreeQueue<POSCommand_QE_t*>();
    POS_CHECK_POINTER(this->_cmd_parser2worker_wq);
    POS_DEBUG_C("created parser2worker cmd WQ: uuid(%lu)", this->id);

    // parser2worker cmd completion queue
    this->_cmd_parser2worker_cq = new POSLockFreeQueue<POSCommand_QE_t*>();
    POS_CHECK_POINTER(this->_cmd_parser2worker_cq);
    POS_DEBUG_C("created parser2worker cmd CQ: uuid(%lu)", this->id);

    // oob2parser cmd work queue
    this->_cmd_oob2parser_wq = new POSLockFreeQueue<POSCommand_QE_t*>();
    POS_CHECK_POINTER(this->_cmd_oob2parser_wq);
    POS_DEBUG_C("created oob2parser cmd WQ: uuid(%lu)", this->id);

    // oob2parser cmd completion queue
    this->_cmd_oob2parser_cq = new POSLockFreeQueue<POSCommand_QE_t*>();
    POS_CHECK_POINTER(this->_cmd_oob2parser_cq);
    POS_DEBUG_C("created oob2parser cmd CQ: uuid(%lu)", this->id);

    return retval;
}


pos_retval_t POSClient::__destory_qgroup(){
    pos_retval_t retval = POS_SUCCESS;
    
    // rpc2parser apicxt work queue
    POS_CHECK_POINTER(this->_apicxt_rpc2parser_wq);
    this->_apicxt_rpc2parser_wq->lock();
    delete this->_apicxt_rpc2parser_wq;
    POS_DEBUG_C("destoryed rpc2parser apicxt WQ: uuid(%lu)", this->id);

    // rpc2parser apicxt completion queue
    POS_CHECK_POINTER(this->_apicxt_rpc2parser_cq);
    this->_apicxt_rpc2parser_cq->lock();
    delete this->_apicxt_rpc2parser_cq;
    POS_DEBUG_C("destoryed rpc2parser apicxt CQ: uuid(%lu)", this->id);

    // parser2worker apicxt work queue
    POS_CHECK_POINTER(this->_apicxt_parser2worker_wq);
    this->_apicxt_parser2worker_wq->lock();
    delete this->_apicxt_parser2worker_wq;
    POS_DEBUG_C("destoryed parser2worker apicxt WQ: uuid(%lu)", this->id);

    // rpc2worker apicxt completion queue
    POS_CHECK_POINTER(this->_apicxt_rpc2worker_cq);
    this->_apicxt_rpc2worker_cq->lock();
    delete this->_apicxt_rpc2worker_cq;
    POS_DEBUG_C("destoryed rpc2worker apicxt CQ: uuid(%lu)", this->id);

    // workerlocal_ckptdag apicxt work queue
    POS_CHECK_POINTER(this->_apicxt_workerlocal_ckptdag_wq);
    this->_apicxt_workerlocal_ckptdag_wq->lock();
    delete this->_apicxt_workerlocal_ckptdag_wq;
    POS_DEBUG_C("destoryed workerlocal_ckptdag apicxt WQ: uuid(%lu)", this->id);

    // parser2worker cmd work queue
    POS_CHECK_POINTER(this->_cmd_parser2worker_wq);
    this->_cmd_parser2worker_wq->lock();
    delete this->_cmd_parser2worker_wq;
    POS_DEBUG_C("destoryed parser2worker apicxt WQ: uuid(%lu)", this->id);

    // parser2worker cmd completion queue
    POS_CHECK_POINTER(this->_cmd_parser2worker_cq);
    this->_cmd_parser2worker_cq->lock();
    delete this->_cmd_parser2worker_cq;
    POS_DEBUG_C("destoryed parser2worker cmd CQ: uuid(%lu)", this->id);

    // oob2parser cmd work queue
    POS_CHECK_POINTER(this->_cmd_oob2parser_wq);
    this->_cmd_oob2parser_wq->lock();
    delete this->_cmd_oob2parser_wq;
    POS_DEBUG_C("destoryed oob2parser cmd WQ: uuid(%lu)", this->id);

    // oob2parser cmd completion queue
    POS_CHECK_POINTER(this->_cmd_oob2parser_cq);
    this->_cmd_oob2parser_cq->lock();
    delete this->_cmd_oob2parser_cq;
    POS_DEBUG_C("destoryed oob2parser cmd CQ: uuid(%lu)", this->id);

exit:
    return retval;
}
