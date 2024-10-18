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


POSWorkspace::POSWorkspace(int argc, char *argv[]) 
    : _current_max_uuid(0), ws_conf(this) 
{
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
    POS_DEBUG("initializing POS workspace...")
    POS_DEBUG("init platform-specific context...");
    return this->__init();
}


pos_retval_t POSWorkspace::deinit(){
    typename std::map<pos_client_uuid_t, POSClient*>::iterator clnt_iter;

    POS_DEBUG("deinitializing POS workspace...")

    if(likely(_oob_server != nullptr)){
        POS_DEBUG("shutdowning out-of-band server...");
        delete _oob_server;
    }

    POS_DEBUG("cleaning all clients...: #clients(%lu)", _client_map.size());
    for(clnt_iter = _client_map.begin(); clnt_iter != _client_map.end(); clnt_iter++){
        if(clnt_iter->second != nullptr){
            clnt_iter->second->deinit();
            delete clnt_iter->second;
        }
    }

    POS_DEBUG("deinit platform-specific context...");
    return this->__deinit();
}


pos_retval_t POSWorkspace::remove_client(pos_client_uuid_t uuid){
    pos_retval_t retval = POS_SUCCESS;
    void* clnt;

    /*!
     * \todo    we need to prevent other functions would access
     *          those client to be removed, might need a mutex lock to manage the client
     *          map, to be added later
     */
    if(unlikely(this->_client_map.count(uuid) == 0)){
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


POSClient* POSWorkspace::get_client_by_uuid(pos_client_uuid_t uuid){
    POSClient *retval = nullptr;

    if(unlikely(this->_client_map.count(uuid) > 0)){
        retval = this->_client_map[uuid];
    }

    return retval;
}


pos_retval_t POSWorkspace::create_qp(pos_client_uuid_t uuid){
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


POSAPIContext_QE* POSWorkspace::dequeue_parser_job(pos_client_uuid_t uuid){
    pos_retval_t tmp_retval;
    POSAPIContext_QE *wqe = nullptr;
    POSLockFreeQueue<POSAPIContext_QE_t*> *wq;

    if(unlikely(this->_parser_wqs.count(uuid) == 0)){
        POS_WARN("no parser wq with client uuid %lu registered", uuid);
        goto exit;
    }

    POS_CHECK_POINTER(wq = _parser_wqs[uuid]);
    wq->dequeue(wqe);

exit:
    return wqe;
}


template<pos_queue_position_t qt>
pos_retval_t POSWorkspace::poll_cq(pos_client_uuid_t uuid, std::vector<POSAPIContext_QE*>* cqes){
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
template pos_retval_t POSWorkspace::poll_cq<kPOS_Queue_Position_Worker>(pos_client_uuid_t uuid, std::vector<POSAPIContext_QE*>* cqes);
template pos_retval_t POSWorkspace::poll_cq<kPOS_Queue_Position_Parser>(pos_client_uuid_t uuid, std::vector<POSAPIContext_QE*>* cqes);


template<pos_queue_position_t qposition>
pos_retval_t POSWorkspace::push_cq(POSAPIContext_QE *cqe){
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
template pos_retval_t POSWorkspace::push_cq<kPOS_Queue_Position_Worker>(POSAPIContext_QE *cqe);
template pos_retval_t POSWorkspace::push_cq<kPOS_Queue_Position_Parser>(POSAPIContext_QE *cqe);


template<pos_queue_type_t qtype, pos_queue_position_t qposition>
pos_retval_t POSWorkspace::_remove_q(pos_client_uuid_t uuid){
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
template pos_retval_t POSWorkspace::_remove_q<kPOS_Queue_Type_WQ, kPOS_Queue_Position_Worker>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::_remove_q<kPOS_Queue_Type_CQ, kPOS_Queue_Position_Worker>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::_remove_q<kPOS_Queue_Type_WQ, kPOS_Queue_Position_Parser>(pos_client_uuid_t uuid);
template pos_retval_t POSWorkspace::_remove_q<kPOS_Queue_Type_CQ, kPOS_Queue_Position_Parser>(pos_client_uuid_t uuid);


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
    if(unlikely(_parser_wqs.count(uuid) == 0)){
        POS_WARN_C_DETAIL("no work queue with client uuid(%lu) was created", uuid);
        return POS_FAILED_NOT_EXIST;
    }
#endif // POS_CONF_RUNTIME_EnableDebugCheck

    POS_CHECK_POINTER(wq = _parser_wqs[uuid]);

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
    // this will introduce 25us overhead
    wq->push(wqe);
    
    /*!
     *  \note   if this is a sync call, we need to block until cqe is obtained
     */
    if(unlikely(api_meta.is_sync)){
        while(1){
            if(unlikely(POS_SUCCESS != poll_cq<kPOS_Queue_Position_Parser>(uuid, &cqes))){
                POS_ERROR_C_DETAIL("failed to poll runtime cq");
            }

            if(unlikely(POS_SUCCESS != poll_cq<kPOS_Queue_Position_Worker>(uuid, &cqes))){
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

exit:
    return retval;
}
