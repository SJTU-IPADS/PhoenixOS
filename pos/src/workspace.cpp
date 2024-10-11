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
#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/workspace.h"

/*!
 *  \brief  shutdown the POS server
 */
void POSWorkspace::clear(){
    typename std::map<pos_client_uuid_t, POSClient*>::iterator clnt_iter;

    POS_LOG("clearing POS Workspace...")

    if(likely(_oob_server != nullptr)){
        delete _oob_server;
        POS_LOG("shutdowned out-of-band server");
    }
    
    POS_LOG("cleaning all clients...");
    for(clnt_iter = _client_map.begin(); clnt_iter != _client_map.end(); clnt_iter++){
        if(clnt_iter->second != nullptr){
            clnt_iter->second->deinit();
            delete clnt_iter->second;
        }
    }
}

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

#if POS_ENABLE_DEBUG_CHECK
    // check whether the client exists
    if(unlikely(_client_map.count(uuid) == 0)){
        POS_WARN_C_DETAIL("no client with uuid(%lu) was recorded", uuid);
        return POS_FAILED_NOT_EXIST;
    }
#endif // POS_ENABLE_DEBUG_CHECK

    POS_CHECK_POINTER(client = _client_map[uuid]);

    // check whether the work queue exists
#if POS_ENABLE_DEBUG_CHECK
    if(unlikely(_parser_wqs.count(uuid) == 0)){
        POS_WARN_C_DETAIL("no work queue with client uuid(%lu) was created", uuid);
        return POS_FAILED_NOT_EXIST;
    }
#endif // POS_ENABLE_DEBUG_CHECK

    POS_CHECK_POINTER(wq = _parser_wqs[uuid]);

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
            if(unlikely(POS_SUCCESS != poll_cq<kPOS_Queue_Position_Parser>(&cqes, uuid))){
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
