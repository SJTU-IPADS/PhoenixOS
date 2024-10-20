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
#include "pos/include/workspace.h"


POSWorkspaceConf::POSWorkspaceConf(POSWorkspace *root_ws){
    POS_CHECK_POINTER(this->_root_ws = root_ws);
    this->_runtime_daemon_log_path = POS_CONF_RUNTIME_DefaultDaemonLogPath;
    this->_runtime_client_log_path = POS_CONF_RUNTIME_DefaultClientLogPath;
    this->_eval_ckpt_interval_tick = this->_root_ws->tsc_timer.ms_to_tick(
        POS_CONF_EVAL_CkptDefaultIntervalMs
    );
}


pos_retval_t POSWorkspaceConf::set(ConfigType conf_type, std::string val){
    pos_retval_t retval = POS_SUCCESS;
    std::lock_guard<std::mutex> lock(this->_mutex);
    uint64_t _tmp;

    POS_ASSERT(conf_type < ConfigType::kUnknown);

    switch (conf_type)
    {
    case kRuntimeDaemonLogPath:
        // TODO:
        break;

    case kRuntimeClientLogPath:
        // TODO:
        break;
    
    case kEvalCkptIntervfalMs:
        try {
            _tmp = std::stoull(val);
        } catch (const std::invalid_argument& e) {
            POS_WARN_C("failed to set ckpt interval: %s", e.what());
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        } catch (const std::out_of_range& e) {
            POS_WARN_C("failed to set ckpt interval: %s", e.what());
            retval = POS_FAILED_INVALID_INPUT;
            goto exit;
        }
        this->_eval_ckpt_interval_tick = static_cast<uint64_t>(
            this->_root_ws->tsc_timer.ms_to_tick(_tmp)
        );
        break;

    default:
        break;
    }

exit:
    return retval;
}


POSWorkspace::POSWorkspace() : _current_max_uuid(0), ws_conf(this) {
    // create out-of-band server
    _oob_server = new POSOobServer(
        /* ws */ this,
        /* callback_handlers */ {
            {   kPOS_OOB_Msg_Agent_Register_Client,     oob_functions::agent_register_client::sv    },
            {   kPOS_OOB_Msg_Agent_Unregister_Client,   oob_functions::agent_unregister_client::sv  },
            {   kPOS_OOB_Msg_Utils_MockAPICall,         oob_functions::utils_mock_api_call::sv      },
            {   kPOS_OOB_Msg_CLI_Ckpt_PreDump,          oob_functions::cli_ckpt_predump::sv         },
            {   kPOS_OOB_Msg_CLI_Migration_Signal,      oob_functions::cli_migration_signal::sv     },
            {   kPOS_OOB_Msg_CLI_Restore_Signal,        oob_functions::cli_restore_signal::sv       },
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
        POS_CONF_EVAL_RstEnableContextPool == 1 ? "true" : "false",
        POS_CONF_EVAL_CkptOptLevel,
        POS_CONF_EVAL_CkptOptLevel == 0 ? "no ckpt" : POS_CONF_EVAL_CkptOptLevel == 1 ? "sync ckpt" : "async ckpt",
        POS_CONF_EVAL_CkptDefaultIntervalMs,
        POS_CONF_EVAL_CkptOptLevel == 0 ? "N/A" : POS_CONF_EVAL_CkptEnableIncremental == 1 ? "true" : "false",
        POS_CONF_EVAL_CkptOptLevel <= 1 ? "N/A" : POS_CONF_EVAL_CkptEnablePipeline == 1 ? "true" : "false",
        POS_CONF_EVAL_MigrOptLevel,
        POS_CONF_EVAL_MigrOptLevel == 0 ? "no migration" : POS_CONF_EVAL_MigrOptLevel == 1 ? "naive" : "pre-copy"
    );
}


POSWorkspace::~POSWorkspace() = default;


pos_retval_t POSWorkspace::init(){
    POS_DEBUG_C("initializing POS workspace...")
    return this->__init();
}


pos_retval_t POSWorkspace::deinit(){
    typename std::map<pos_client_uuid_t, POSClient*>::iterator clnt_iter;

    POS_DEBUG_C("deinitializing POS workspace...")

    if(likely(_oob_server != nullptr)){
        POS_DEBUG_C("shutdowning out-of-band server...");
        delete _oob_server;
    }

    POS_DEBUG_C("cleaning all clients...: #clients(%lu)", this->_client_map.size());
    for(clnt_iter = this->_client_map.begin(); clnt_iter != this->_client_map.end(); clnt_iter++){
        if(clnt_iter->second != nullptr){
            clnt_iter->second->deinit();
            delete clnt_iter->second;
        }
    }

    POS_DEBUG_C("deinit platform-specific context...");
    return this->__deinit();
}


pos_retval_t POSWorkspace::remove_client(pos_client_uuid_t uuid){
    pos_retval_t retval = POS_SUCCESS;
    void* clnt;
    typename std::map<__pid_t, POSClient*>::iterator pid_client_map_iter;

    if(unlikely(this->_client_map.count(uuid) == 0)){
        POS_WARN_C("try to remove an non-exist client: uuid(%lu)", uuid);
        retval = POS_FAILED_NOT_EXIST;
        goto exit;
    }
    POS_CHECK_POINTER(clnt = _client_map[uuid]);

    // remove queue pair first
    retval = this->__remove_qp(uuid);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to remove queue pair: uuid(%lu)", uuid);
        goto exit;
    }

    // delete from pid map
    for(pid_client_map_iter = this->_pid_client_map.begin();
        pid_client_map_iter != this->_pid_client_map.end();
        pid_client_map_iter ++
    ){
        if(pid_client_map_iter->second == clnt){
            this->_pid_client_map.erase(pid_client_map_iter);
            break;
        }
    }

    // delete client
    delete clnt;
    _client_map.erase(uuid);

    POS_DEBUG_C("removed client: uuid(%lu)", uuid);

exit:
    return retval;
}


POSClient* POSWorkspace::get_client_by_pid(__pid_t pid){
    POSClient *retval = nullptr;

    if(unlikely(this->_pid_client_map.count(pid) > 0)){
        retval = this->_pid_client_map[pid];
    }

    return retval;
}


POSClient* POSWorkspace::get_client_by_uuid(pos_client_uuid_t uuid){
    POSClient *retval = nullptr;

    if(unlikely(this->_client_map.count(uuid) > 0)){
        retval = this->_client_map[uuid];
    }

    return retval;
}


template<pos_queue_direction_t qdir, pos_queue_type_t qtype>
pos_retval_t POSWorkspace::push_q(void *qe){
    pos_retval_t retval = POS_SUCCESS;
    POSAPIContext_QE_t *apictx_qe;
    POSCommand_QE_t *cmd_qe;
    POSLockFreeQueue<POSAPIContext_QE_t*> *apictx_q;
    POSLockFreeQueue<POSCommand_QE_t*> *cmd_q;
    pos_client_uuid_t uuid;

    static_assert(
            qtype == kPOS_QueueType_ApiCxt_WQ || qtype == kPOS_QueueType_ApiCxt_CQ
        ||  qtype == kPOS_QueueType_Cmd_WQ || qtype == kPOS_QueueType_Cmd_CQ,
        "unknown queue type obtained"
    );

    // api context worker queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_WQ){
        POS_CHECK_POINTER(apictx_qe = reinterpret_cast<POSAPIContext_QE_t*>(qe));
        uuid = apictx_qe->client_id;
        
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Parser2Worker,
            "POSAPIContext_QE_t can only be passed within rpc2parser or parser2worker queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            if(unlikely(this->_apicxt_rpc2parser_wqs.count(uuid) == 0)){
                POS_WARN_C(
                    "failed to insert POSAPIContext_QE_t to rpc2parser queue, queue not exist: client_id(%lu)", uuid
                );
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            POS_CHECK_POINTER(apictx_q = this->_apicxt_rpc2parser_wqs[uuid]);
            apictx_q->push(apictx_qe);
        } else { // qdir == kPOS_QueueDirection_Parser2Worker
            if(unlikely(this->_apicxt_parser2worker_wqs.count(uuid) == 0)){
                POS_WARN_C(
                    "failed to insert POSAPIContext_QE_t to parser2worker queue, queue not exist: client_id(%lu)", uuid
                );
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            POS_CHECK_POINTER(apictx_q = this->_apicxt_parser2worker_wqs[uuid]);
            apictx_q->push(apictx_qe);
        }
    }

    // api context completion queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_CQ){
        POS_CHECK_POINTER(apictx_qe = reinterpret_cast<POSAPIContext_QE_t*>(qe));
        uuid = apictx_qe->client_id;
        
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Rpc2Worker,
            "POSAPIContext_QE_t can only be passed within rpc2parser or rpc2worker queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            if(unlikely(this->_apicxt_rpc2parser_cqs.count(uuid) == 0)){
                POS_WARN_C(
                    "failed to insert POSAPIContext_QE_t to rpc2parser queue, queue not exist: client_id(%lu)", uuid
                );
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            POS_CHECK_POINTER(apictx_q = this->_apicxt_rpc2parser_cqs[uuid]);
            apictx_q->push(apictx_qe);
        } else { // qdir == kPOS_QueueDirection_Rpc2Worker
            if(unlikely(this->_apicxt_rpc2worker_cqs.count(uuid) == 0)){
                POS_WARN_C(
                    "failed to insert POSAPIContext_QE_t to rpc2worker queue, queue not exist: client_id(%lu)", uuid
                );
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            POS_CHECK_POINTER(apictx_q = this->_apicxt_rpc2worker_cqs[uuid]);
            apictx_q->push(apictx_qe);
        }
    }

    // command work queue
    if constexpr (qtype == kPOS_QueueType_Cmd_WQ){
        POS_CHECK_POINTER(cmd_qe = reinterpret_cast<POSCommand_QE_t*>(qe));
        uuid = cmd_qe->client_id;
        
        static_assert(
            qdir == kPOS_QueueDirection_Worker2Parser || qdir == kPOS_QueueDirection_Oob2Parser,
            "POSCommand_QE_t can only be passed within worker2parser or oob2parser queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Worker2Parser){
            if(unlikely(this->_cmd_worker2parser_wqs.count(uuid) == 0)){
                POS_WARN_C(
                    "failed to insert POSCommand_QE_t to worker2parser work queue, queue not exist: client_id(%lu)", uuid
                );
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            POS_CHECK_POINTER(cmd_q = this->_cmd_worker2parser_wqs[uuid]);
            cmd_q->push(cmd_qe);
        } else { // qdir == kPOS_QueueDirection_Oob2Parser
            if(unlikely(this->_cmd_oob2parser_wqs.count(uuid) == 0)){
                POS_WARN_C(
                    "failed to insert POSCommand_QE_t to oob2parser work queue, queue not exist: client_id(%lu)", uuid
                );
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            POS_CHECK_POINTER(cmd_q = this->_cmd_oob2parser_wqs[uuid]);
            cmd_q->push(cmd_qe);
        }
    }

    // command completion queue
    if constexpr (qtype == kPOS_QueueType_Cmd_CQ){
        POS_CHECK_POINTER(cmd_qe = reinterpret_cast<POSCommand_QE_t*>(qe));
        uuid = cmd_qe->client_id;
        
        static_assert(
            qdir == kPOS_QueueDirection_Worker2Parser || qdir == kPOS_QueueDirection_Oob2Parser,
            "POSCommand_QE_t can only be passed within worker2parser or oob2parser queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Worker2Parser){
            if(unlikely(this->_cmd_worker2parser_cqs.count(uuid) == 0)){
                POS_WARN_C(
                    "failed to insert POSCommand_QE_t to worker2parser completion queue, queue not exist: client_id(%lu)", uuid
                );
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            POS_CHECK_POINTER(cmd_q = this->_cmd_worker2parser_cqs[uuid]);
            cmd_q->push(cmd_qe);
        } else { // qdir == kPOS_QueueDirection_Oob2Parser
            if(unlikely(this->_cmd_oob2parser_cqs.count(uuid) == 0)){
                POS_WARN_C(
                    "failed to insert POSCommand_QE_t to oob2parser completion queue, queue not exist: client_id(%lu)", uuid
                );
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            POS_CHECK_POINTER(cmd_q = this->_cmd_oob2parser_cqs[uuid]);
            cmd_q->push(cmd_qe);
        }
    }

exit:
    return retval;
}
template pos_retval_t POSWorkspace::push_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_WQ>(void *qe);
template pos_retval_t POSWorkspace::push_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_CQ>(void *qe);
template pos_retval_t POSWorkspace::push_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(void *qe);
template pos_retval_t POSWorkspace::push_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(void *qe);
template pos_retval_t POSWorkspace::push_q<kPOS_QueueDirection_Worker2Parser, kPOS_QueueType_Cmd_WQ>(void *qe);
template pos_retval_t POSWorkspace::push_q<kPOS_QueueDirection_Worker2Parser, kPOS_QueueType_Cmd_CQ>(void *qe);
template pos_retval_t POSWorkspace::push_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_WQ>(void *qe);
template pos_retval_t POSWorkspace::push_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_CQ>(void *qe);


pos_retval_t POSWorkspace::__create_qp(pos_client_uuid_t uuid){
    pos_retval_t retval = POS_SUCCESS;
    POSLockFreeQueue<POSAPIContext_QE_t*> *apicxt_rpc2parser_wq, *apicxt_rpc2parser_cq;
    POSLockFreeQueue<POSAPIContext_QE_t*> *apicxt_parser2worker_wq, *apicxt_rpc2worker_cq;
    POSLockFreeQueue<POSCommand_QE_t*> *cmd_worker2parser_wq, *cmd_worker2parser_cq;
    POSLockFreeQueue<POSCommand_QE_t*> *cmd_oob2parser_wq, *cmd_oob2parser_cq;

    if(unlikely(
            this->_apicxt_rpc2parser_wqs.count(uuid) > 0 
        ||  this->_apicxt_rpc2parser_cqs.count(uuid) > 0
        ||  this->_apicxt_parser2worker_wqs.count(uuid) > 0
        ||  this->_apicxt_rpc2worker_cqs.count(uuid) > 0
        ||  this->_cmd_worker2parser_wqs.count(uuid) > 0
        ||  this->_cmd_worker2parser_cqs.count(uuid) > 0
        ||  this->_cmd_oob2parser_wqs.count(uuid) > 0
        ||  this->_cmd_oob2parser_cqs.count(uuid) > 0
    )){
        POS_ERROR_C_DETAIL("try to create queue pairs with same client id, this is a bug: client_id(%lu)", uuid);
    }

    // rpc2parser apicxt work queue
    apicxt_rpc2parser_wq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
    POS_CHECK_POINTER(apicxt_rpc2parser_wq);
    this->_apicxt_rpc2parser_wqs[uuid] = apicxt_rpc2parser_wq;
    POS_DEBUG_C("create rpc2parser apicxt work queue: uuid(%lu)", uuid);

    // rpc2parser apicxt completion queue
    apicxt_rpc2parser_cq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
    POS_CHECK_POINTER(apicxt_rpc2parser_cq);
    this->_apicxt_rpc2parser_cqs[uuid] = apicxt_rpc2parser_cq;
    POS_DEBUG_C("create rpc2parser apicxt completion queue: uuid(%lu)", uuid);

    // parser2worker apicxt work queue
    apicxt_parser2worker_wq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
    POS_CHECK_POINTER(apicxt_parser2worker_wq);
    this->_apicxt_parser2worker_wqs[uuid] = apicxt_parser2worker_wq;
    POS_DEBUG_C("create parser2worker apicxt work queue: uuid(%lu)", uuid);

    // rpc2worker apicxt completion queue
    apicxt_rpc2worker_cq = new POSLockFreeQueue<POSAPIContext_QE_t*>();
    POS_CHECK_POINTER(apicxt_rpc2worker_cq);
    this->_apicxt_rpc2worker_cqs[uuid] = apicxt_rpc2worker_cq;
    POS_DEBUG_C("create rpc2worker apicxt completion queue: uuid(%lu)", uuid);

    // worker2parser cmd work queue
    cmd_worker2parser_wq = new POSLockFreeQueue<POSCommand_QE_t*>();
    POS_CHECK_POINTER(cmd_worker2parser_wq);
    this->_cmd_worker2parser_wqs[uuid] = cmd_worker2parser_wq;
    POS_DEBUG_C("create worker2parser cmd work queue: uuid(%lu)", uuid);

    // worker2parser cmd completion queue
    cmd_worker2parser_cq = new POSLockFreeQueue<POSCommand_QE_t*>();
    POS_CHECK_POINTER(cmd_worker2parser_cq);
    this->_cmd_worker2parser_cqs[uuid] = cmd_worker2parser_cq;
    POS_DEBUG_C("create worker2parser cmd completion queue: uuid(%lu)", uuid);

    // oob2parser cmd work queue
    cmd_oob2parser_wq = new POSLockFreeQueue<POSCommand_QE_t*>();
    POS_CHECK_POINTER(cmd_oob2parser_wq);
    this->_cmd_oob2parser_wqs[uuid] = cmd_oob2parser_wq;
    POS_DEBUG_C("create oob2parser cmd work queue: uuid(%lu)", uuid);

    // oob2parser cmd completion queue
    cmd_oob2parser_cq = new POSLockFreeQueue<POSCommand_QE_t*>();
    POS_CHECK_POINTER(cmd_oob2parser_cq);
    this->_cmd_oob2parser_cqs[uuid] = cmd_oob2parser_cq;
    POS_DEBUG_C("create oob2parser cmd completion queue: uuid(%lu)", uuid);

    return retval;
}


pos_retval_t POSWorkspace::__remove_qp(pos_client_uuid_t uuid){
    pos_retval_t retval = POS_SUCCESS;
    POSClient *clnt;

    if(unlikely(this->_client_map.count(uuid) == 0)){
        POS_WARN_C(
            "failed to remove qp, no client exist: uuid(%lu)", uuid
        );
        retval = POS_FAILED_NOT_EXIST;
        goto exit;
    }
    POS_CHECK_POINTER(clnt = this->_client_map[uuid]);
    clnt->status = kPOS_ClientStatus_Hang;
    
    // rpc2parser apicxt work queue
    if(this->_apicxt_rpc2parser_wqs[uuid] != nullptr){
        POS_DEBUG_C("removing apicxt rpc2parser work queue...: uuid(%lu)", uuid);
        /*!
         *  \note   this queue is polled by parser thread, so we wait until the queue is drain
         */
        this->_apicxt_rpc2parser_wqs[uuid]->lock_enqueue();
        while(this->_apicxt_rpc2parser_wqs[uuid]->len() > 0){}
        retval = this->__remove_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_WQ>(uuid);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to remove rpc2parser work queue: uuid(%lu)", uuid);
            goto exit;
        }
    }

    // rpc2parser apicxt completion queue
    if(this->_apicxt_rpc2parser_cqs[uuid] != nullptr){
        POS_DEBUG_C("removing apicxt rpc2parser completion queue...: uuid(%lu)", uuid);
        /*!
         *  \note   this queue is polled by unpredictable rpc thread, so we need to manully lock this queue
         */
        this->_apicxt_rpc2parser_cqs[uuid]->lock_enqueue();
        this->_apicxt_rpc2parser_cqs[uuid]->lock_dequeue();
        retval = this->__remove_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_CQ>(uuid);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to remove rpc2parser completion queue: uuid(%lu)", uuid);
            goto exit;
        }
    }

    // parser2worker apicxt work queue
    if(this->_apicxt_parser2worker_wqs[uuid] != nullptr){
        POS_DEBUG_C("removing apicxt parser2worker work queue...: uuid(%lu)", uuid);
        /*!
         *  \note   this queue is polled by worker thread, so we wait until the queue is drain
         */
        this->_apicxt_parser2worker_wqs[uuid]->lock_enqueue();
        while(this->_apicxt_parser2worker_wqs[uuid]->len() > 0){}
        retval = this->__remove_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(uuid);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to remove parser2worker work queue: uuid(%lu)", uuid);
            goto exit;
        }
    }

    // rpc2worker apicxt completion queue
    if(this->_apicxt_rpc2worker_cqs[uuid] != nullptr){
        POS_DEBUG_C("removing apicxt rpc2worker completion queue...: uuid(%lu)", uuid);
        /*!
         *  \note   this queue is polled by unpredictable rpc thread, so we need to manully lock this queue
         */
        this->_apicxt_rpc2worker_cqs[uuid]->lock_enqueue();
        this->_apicxt_rpc2worker_cqs[uuid]->lock_dequeue();
        retval = this->__remove_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(uuid);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to remove rpc2worker completion queue: uuid(%lu)", uuid);
            goto exit;
        }
    }

    // worker2parser cmd work queue
    if(this->_cmd_worker2parser_wqs[uuid] != nullptr){
        POS_DEBUG_C("removing cmd worker2parser work queue...: uuid(%lu)", uuid);
        this->_cmd_worker2parser_wqs[uuid]->lock_enqueue();
        this->_cmd_worker2parser_wqs[uuid]->lock_dequeue();
        while(this->_cmd_worker2parser_wqs[uuid]->len() > 0){}
        retval = this->__remove_q<kPOS_QueueDirection_Worker2Parser, kPOS_QueueType_Cmd_WQ>(uuid);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to remove cmd worker2parser work queue: uuid(%lu)", uuid);
            goto exit;
        }
    }

    // worker2parser cmd completion queue
    if(this->_cmd_worker2parser_cqs[uuid] != nullptr){
        POS_DEBUG_C("removing cmd worker2parser completion queue...: uuid(%lu)", uuid);
        this->_cmd_worker2parser_cqs[uuid]->lock_enqueue();
        this->_cmd_worker2parser_cqs[uuid]->lock_dequeue();
        retval = this->__remove_q<kPOS_QueueDirection_Worker2Parser, kPOS_QueueType_Cmd_CQ>(uuid);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to remove cmd worker2parser completion queue: uuid(%lu)", uuid);
            goto exit;
        }
    }

    // oob2parser cmd work queue
    if(this->_cmd_oob2parser_wqs[uuid] != nullptr){
        POS_DEBUG_C("removing cmd oob2parser work queue...: uuid(%lu)", uuid);
        this->_cmd_oob2parser_wqs[uuid]->lock_enqueue();
        this->_cmd_oob2parser_wqs[uuid]->lock_dequeue();
        while(this->_cmd_oob2parser_wqs[uuid]->len() > 0){}
        retval = this->__remove_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_WQ>(uuid);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to remove cmd oob2parser work queue: uuid(%lu)", uuid);
            goto exit;
        }
    }

    // oob2parser cmd completion queue
    if(this->_cmd_oob2parser_cqs[uuid] != nullptr){
        POS_DEBUG_C("removing cmd oob2parser completion queue...: uuid(%lu)", uuid);
        this->_cmd_oob2parser_cqs[uuid]->lock_enqueue();
        this->_cmd_oob2parser_cqs[uuid]->lock_dequeue();
        retval = this->__remove_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_CQ>(uuid);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to remove cmd oob2parser completion queue: uuid(%lu)", uuid);
            goto exit;
        }
    }

exit:
    return retval;
}


template<pos_queue_direction_t qdir, pos_queue_type_t qtype>
pos_retval_t POSWorkspace::poll_q(pos_client_uuid_t uuid, std::vector<POSAPIContext_QE*>* qes){
    pos_retval_t retval = POS_SUCCESS;
    POSAPIContext_QE *apicxt_qe;
    POSLockFreeQueue<POSAPIContext_QE_t*> *apicxt_q;

    static_assert(
        qtype == kPOS_QueueType_ApiCxt_WQ || qtype == kPOS_QueueType_ApiCxt_CQ,
        "invalid queue type obtained"
    );

    POS_CHECK_POINTER(qes);

    if(unlikely(this->_client_map.count(uuid) == 0)){
        POS_ERROR_C_DETAIL(
            "failed to poll q, no client exist, this is a bug: uuid(%lu), qir(%d), qtype(%d)",
            uuid, qdir, qtype
        );
    }

    // api context worker queue
    if constexpr (qtype == kPOS_QueueType_ApiCxt_WQ){
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Parser2Worker,
            "POSAPIContext_QE_t can only be passed within rpc2parser or parser2worker queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            if(unlikely(this->_apicxt_rpc2parser_wqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            apicxt_q = this->_apicxt_rpc2parser_wqs[uuid];
        } else { // kPOS_QueueDirection_Parser2Worker
            if(unlikely(this->_apicxt_parser2worker_wqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            apicxt_q = this->_apicxt_parser2worker_wqs[uuid];
        }
    }

    // api context completion queue
    if constexpr (qtype == kPOS_QueueType_ApiCxt_CQ){
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Rpc2Worker,
            "POSAPIContext_QE_t can only be passed within rpc2parser or parser2worker queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            if(unlikely(this->_apicxt_rpc2parser_cqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            apicxt_q = this->_apicxt_rpc2parser_cqs[uuid];
        } else { // kPOS_QueueDirection_Rpc2Worker
            if(unlikely(this->_apicxt_rpc2worker_cqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            apicxt_q = this->_apicxt_rpc2worker_cqs[uuid];
        }
    }

    POS_CHECK_POINTER(apicxt_q);
    while(POS_SUCCESS == apicxt_q->dequeue(apicxt_qe)){
        qes->push_back(apicxt_qe);
    }

exit:
    return retval;
}
template pos_retval_t POSWorkspace::poll_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_WQ>(pos_client_uuid_t uuid, std::vector<POSAPIContext_QE*>* qes);
template pos_retval_t POSWorkspace::poll_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(pos_client_uuid_t uuid, std::vector<POSAPIContext_QE*>* qes);
template pos_retval_t POSWorkspace::poll_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_CQ>(pos_client_uuid_t uuid, std::vector<POSAPIContext_QE*>* qes);
template pos_retval_t POSWorkspace::poll_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(pos_client_uuid_t uuid, std::vector<POSAPIContext_QE*>* qes);


template<pos_queue_direction_t qdir, pos_queue_type_t qtype>
pos_retval_t POSWorkspace::poll_q(pos_client_uuid_t uuid, std::vector<POSCommand_QE_t*>* qes){
    pos_retval_t retval = POS_SUCCESS;
    POSCommand_QE_t *cmd_qe;
    POSLockFreeQueue<POSCommand_QE_t*> *cmd_q;
    
    static_assert(
        qtype == kPOS_QueueType_Cmd_WQ || qtype == kPOS_QueueType_Cmd_CQ,
        "invalid queue type obtained"
    );

    POS_CHECK_POINTER(qes);

    if(unlikely(this->_client_map.count(uuid) == 0)){
        POS_ERROR_C_DETAIL(
            "failed to poll q, no client exist, this is a bug: uuid(%lu), qir(%d), qtype(%d)",
            uuid, qdir, qtype
        );
    }

    // command work queue
    if constexpr (qtype == kPOS_QueueType_Cmd_WQ){
        static_assert(
            qdir == kPOS_QueueDirection_Worker2Parser || qdir == kPOS_QueueDirection_Oob2Parser,
            "POSCommand_QE_t can only be passed within worker2parser or oob2parser queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Worker2Parser){
            if(unlikely(this->_cmd_worker2parser_wqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            cmd_q = this->_cmd_worker2parser_wqs[uuid];
        } else { // kPOS_QueueDirection_Oob2Parser
            if(unlikely(this->_cmd_oob2parser_wqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            cmd_q = this->_cmd_oob2parser_wqs[uuid];
        }
    }

    // command completion queue
    if constexpr (qtype == kPOS_QueueType_Cmd_CQ){
        static_assert(
            qdir == kPOS_QueueDirection_Worker2Parser || qdir == kPOS_QueueDirection_Oob2Parser,
            "POSCommand_QE_t can only be passed within worker2parser or oob2parser queue"
        );
        if constexpr (qdir == kPOS_QueueDirection_Worker2Parser){
            if(unlikely(this->_cmd_worker2parser_cqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            cmd_q = this->_cmd_worker2parser_cqs[uuid];
        } else { // kPOS_QueueDirection_Oob2Parser
            if(unlikely(this->_cmd_oob2parser_cqs.count(uuid) == 0)){
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
            cmd_q = this->_cmd_oob2parser_cqs[uuid];
        }
    }

    POS_CHECK_POINTER(cmd_q);
    while(POS_SUCCESS == cmd_q->dequeue(cmd_qe)){
        qes->push_back(cmd_qe);
    }

exit:
    return retval;
}
template pos_retval_t POSWorkspace::poll_q<kPOS_QueueDirection_Worker2Parser, kPOS_QueueType_Cmd_WQ>(pos_client_uuid_t uuid, std::vector<POSCommand_QE_t*>* qes);
template pos_retval_t POSWorkspace::poll_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_WQ>(pos_client_uuid_t uuid, std::vector<POSCommand_QE_t*>* qes);
template pos_retval_t POSWorkspace::poll_q<kPOS_QueueDirection_Worker2Parser, kPOS_QueueType_Cmd_CQ>(pos_client_uuid_t uuid, std::vector<POSCommand_QE_t*>* qes);
template pos_retval_t POSWorkspace::poll_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_CQ>(pos_client_uuid_t uuid, std::vector<POSCommand_QE_t*>* qes);


template<pos_queue_direction_t qdir, pos_queue_type_t qtype>
pos_retval_t POSWorkspace::__remove_q(pos_client_uuid_t uuid){
    pos_retval_t retval = POS_SUCCESS;
    POSLockFreeQueue<POSAPIContext_QE_t*> *apictx_q;
    POSLockFreeQueue<POSCommand_QE_t*> *cmd_q;

    static_assert(qtype == kPOS_QueueType_ApiCxt_WQ || qtype == kPOS_QueueType_ApiCxt_CQ
        ||  qtype == kPOS_QueueType_Cmd_WQ || qtype == kPOS_QueueType_Cmd_CQ,
        "unknown queue type obtained"
    );

    // api context worker queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_WQ){
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Parser2Worker,
            "POSAPIContext_QE_t can only be passed within rpc2parser or parser2worker queue"
        );
        
        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            apictx_q = this->_apicxt_rpc2parser_wqs[uuid];
            delete apictx_q;
            this->_apicxt_rpc2parser_wqs.erase(uuid);
            POS_DEBUG_C("remove apicxt rpc2parser work queue: uuid(%lu)", uuid);
        }

        if constexpr (qdir == kPOS_QueueDirection_Parser2Worker){
            apictx_q = this->_apicxt_parser2worker_wqs[uuid];
            delete apictx_q;
            this->_apicxt_parser2worker_wqs.erase(uuid);
            POS_DEBUG_C("remove apicxt parser2worker work queue: uuid(%lu)", uuid);
        }
    }

    // api context completion queue 
    if constexpr (qtype == kPOS_QueueType_ApiCxt_CQ){
        static_assert(
            qdir == kPOS_QueueDirection_Rpc2Parser || qdir == kPOS_QueueDirection_Rpc2Worker,
            "POSAPIContext_QE_t can only be passed within rpc2parser or rpc2worker queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Rpc2Parser){
            apictx_q = this->_apicxt_rpc2parser_cqs[uuid];
            delete apictx_q;
            this->_apicxt_rpc2parser_cqs.erase(uuid);
            POS_DEBUG_C("remove apicxt rpc2parser completion queue: uuid(%lu)", uuid);
        }

        if constexpr (qdir == kPOS_QueueDirection_Rpc2Worker){
            apictx_q = this->_apicxt_rpc2worker_cqs[uuid];
            delete apictx_q;
            this->_apicxt_rpc2worker_cqs.erase(uuid);
            POS_DEBUG_C("remove apicxt rpc2worker completion queue: uuid(%lu)", uuid);
        }
    }

    // command work queue
    if constexpr (qtype == kPOS_QueueType_Cmd_WQ){        
        static_assert(
            qdir == kPOS_QueueDirection_Worker2Parser || qdir == kPOS_QueueDirection_Oob2Parser,
            "POSCommand_QE_t can only be passed within worker2parser or oob2parser queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Worker2Parser){
            cmd_q = this->_cmd_worker2parser_wqs[uuid];
            delete cmd_q;
            this->_cmd_worker2parser_wqs.erase(uuid);
            POS_DEBUG_C("remove cmd worker2parser work queue: uuid(%lu)", uuid);
        }

        if constexpr (qdir == kPOS_QueueDirection_Oob2Parser){
            cmd_q = this->_cmd_oob2parser_wqs[uuid];
            delete cmd_q;
            this->_cmd_oob2parser_wqs.erase(uuid);
            POS_DEBUG_C("remove cmd oob2parser work queue: uuid(%lu)", uuid);
        }
    }

    // command completion queue
    if constexpr (qtype == kPOS_QueueType_Cmd_CQ){        
        static_assert(
            qdir == kPOS_QueueDirection_Worker2Parser || qdir == kPOS_QueueDirection_Oob2Parser,
            "POSCommand_QE_t can only be passed within worker2parser or oob2parser queue"
        );

        if constexpr (qdir == kPOS_QueueDirection_Worker2Parser){
            cmd_q = this->_cmd_worker2parser_cqs[uuid];
            delete cmd_q;
            this->_cmd_worker2parser_cqs.erase(uuid);
            POS_DEBUG_C("remove cmd worker2parser completion queue: uuid(%lu)", uuid);
        }

        if constexpr (qdir == kPOS_QueueDirection_Oob2Parser){
            cmd_q = this->_cmd_oob2parser_cqs[uuid];
            delete cmd_q;
            this->_cmd_oob2parser_cqs.erase(uuid);
            POS_DEBUG_C("remove cmd oob2parser completion queue: uuid(%lu)", uuid);
        }
    }

    return retval;
}
template pos_retval_t POSWorkspace::__remove_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_WQ>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::__remove_q<kPOS_QueueDirection_Rpc2Parser, kPOS_QueueType_ApiCxt_CQ>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::__remove_q<kPOS_QueueDirection_Parser2Worker, kPOS_QueueType_ApiCxt_WQ>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::__remove_q<kPOS_QueueDirection_Rpc2Worker, kPOS_QueueType_ApiCxt_CQ>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::__remove_q<kPOS_QueueDirection_Worker2Parser, kPOS_QueueType_Cmd_WQ>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::__remove_q<kPOS_QueueDirection_Worker2Parser, kPOS_QueueType_Cmd_CQ>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::__remove_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_WQ>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::__remove_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_CQ>(pos_client_uuid_t uuid);


void POSWorkspace::parse_command_line_options(int argc, char *argv[]){
    int opt;
    const char *op_string = "n:k:c:";

    while((opt = getopt(argc, argv, op_string)) != -1){
        switch (opt)
        {
        // client job names
        case 'n':
            _template_client_cxt.job_name = std::string(optarg);
            break;

        // client kernel meta file path
        case 'k':
            _template_client_cxt.kernel_meta_path = std::string(optarg);
            break;

        // client checkpoint file path
        case 'c':
            _template_client_cxt.checkpoint_file_path = std::string(optarg);
            break;

        default:
            POS_ERROR("unknown command line parameter: %c", op_string);
        }
    }

    if(unlikely(_template_client_cxt.job_name.size() == 0)){
        POS_ERROR_C("must assign a job name with -n option: -n resnet");
    }

    if(unlikely(
        _template_client_cxt.kernel_meta_path.size() > 0 
        && _template_client_cxt.checkpoint_file_path.size()) >0
    ){
        POS_ERROR_C("please either -c or -k, don't coexist!");
    }
}


int POSWorkspace::pos_process(
    uint64_t api_id, pos_client_uuid_t uuid, std::vector<POSAPIParamDesp_t> param_desps, void* ret_data, uint64_t ret_data_len
){
    uint64_t i;
    int retval, prev_error_code = 0;
    POSClient *client;
    POSAPIMeta_t api_meta;
    bool has_prev_error = false;
    POSAPIContext_QE* wqe;
    std::vector<POSAPIContext_QE*> cqes;
    POSAPIContext_QE* cqe;
    POSLockFreeQueue<POSAPIContext_QE_t*>* wq;
    
    // TODO: we assume always be client 0 here, for debugging under cricket
    uuid = 0;

#if POS_CONF_RUNTIME_EnableDebugCheck
    // check whether the client exists
    if(unlikely(_client_map.count(uuid) == 0)){
        POS_WARN_C_DETAIL("no client with uuid(%lu) was recorded", uuid);
        return POS_FAILED_NOT_EXIST;
    }
#endif // POS_CONF_RUNTIME_EnableDebugCheck

    POS_CHECK_POINTER(client = _client_map[uuid]);

    // check whether the work queue exists
#if POS_CONF_RUNTIME_EnableDebugCheck
    if(unlikely(_apicxt_rpc2parser_wqs.count(uuid) == 0)){
        POS_WARN_C_DETAIL("no work queue with client uuid(%lu) was created", uuid);
        return POS_FAILED_NOT_EXIST;
    }
#endif // POS_CONF_RUNTIME_EnableDebugCheck

    POS_CHECK_POINTER(wq = _apicxt_rpc2parser_wqs[uuid]);

    // check whether the metadata of the API was recorded
#if POS_CONF_RUNTIME_EnableDebugCheck
    if(unlikely(api_mgnr->api_metas.count(api_id) == 0)){
        POS_WARN_C_DETAIL(
            "no api metadata was recorded in the api manager: api_id(%lu)", api_id
        );
        return POS_FAILED_NOT_EXIST;
    }
#endif // POS_CONF_RUNTIME_EnableDebugCheck

    api_meta = api_mgnr->api_metas[api_id];

    // generate new work queue element
    wqe = new POSAPIContext_QE(
        /* api_id*/ api_id,
        /* uuid */ uuid,
        /* param_desps */ param_desps,
        /* api_inst_id */ client->get_and_move_api_inst_pc(),
        /* retval_data */ ret_data,
        /* retval_size */ ret_data_len,
        /* pos_client */ (void*)client
    );
    POS_CHECK_POINTER(wqe);

    // for profiling
    wqe->queue_len_before_parse = wq->len();

    // push to the work queue
    wq->push(wqe);
    
    /*!
     *  \note   if this is a sync call, we need to block until cqe is obtained
     */
    if(unlikely(api_meta.is_sync)){
        while(1){
            if(unlikely(
                POS_SUCCESS != (this->template poll_q<kPOS_QueueDirection_Rpc2Parser,kPOS_QueueType_ApiCxt_CQ>(uuid, &cqes))
            )){
                POS_ERROR_C_DETAIL("failed to poll runtime cq");
            }

            if(unlikely(
                POS_SUCCESS != (this->template poll_q<kPOS_QueueDirection_Rpc2Worker,kPOS_QueueType_ApiCxt_CQ>(uuid, &cqes))
            )){
                POS_ERROR_C_DETAIL("failed to poll worker cq");
            }

        #if POS_CONF_RUNTIME_EnableDebugCheck
            if(cqes.size() > 0){
                POS_DEBUG_C("polling completion queue, obtain %lu elements: uuid(%lu)", cqes.size(), uuid);
            }
        #endif

            for(i=0; i<cqes.size(); i++){
                POS_CHECK_POINTER(cqe = cqes[i]);

                // found the called sync api
                if(cqe->api_inst_id == wqe->api_inst_id){
                    // we should NOT do this assumtion here!
                    // POS_ASSERT(i == cqes.size() - 1);

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

                    goto exit;
                }

                // record previous async error
                if(unlikely(
                    cqe->status == kPOS_API_Execute_Status_Parser_Failed
                    || cqe->status == kPOS_API_Execute_Status_Worker_Failed
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

exit:
    return retval;
}
