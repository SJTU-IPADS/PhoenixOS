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

#include "pos/include/common.h"
#include "pos/include/workspace.h"
#include "pos/include/client.h"
#include "pos/include/transport.h"
#include "pos/include/parser.h"

/*!
 *  \brief  processing daemon of the runtime
 */
void POSParser::__daemon(){
    uint64_t i, api_id;
    pos_retval_t parser_retval, dag_retval;
    POSAPIMeta_t api_meta;
    POSAPIContext_QE* wqe;
    uint64_t last_ckpt_tick = 0, current_tick;

    if(unlikely(POS_SUCCESS != this->daemon_init())){
        POS_WARN_C("failed to init daemon, worker daemon exit");
        return;
    }
    
    while(!_stop_flag){

        while(this->_client->status != kPOS_ClientStatus_Active){}

        if((wqe = _ws->dequeue_parser_job(this->_client->id)) != nullptr){
            api_id = wqe->api_cxt->api_id;
            api_meta = _ws->api_mgnr->api_metas[api_id];

        #if POS_CONF_RUNTIME_EnableDebugCheck
            if(unlikely(_parser_functions.count(api_id) == 0)){
                POS_ERROR_C_DETAIL(
                    "runtime has no parser function for api %lu, need to implement", api_id
                );
            }
        #endif

            /*!
            *  \brief  ================== phrase 1 - parse API semantics ==================
            */
            wqe->runtime_s_tick = POSUtilTimestamp::get_tsc();
            parser_retval = (*(this->_parser_functions[api_id]))(this->_ws, wqe);
            wqe->runtime_e_tick = POSUtilTimestamp::get_tsc();

            // set the return code
            wqe->api_cxt->return_code = this->_ws->api_mgnr->cast_pos_retval(
                /* pos_retval */ parser_retval, 
                /* library_id */ api_meta.library_id
            );

            if(unlikely(POS_SUCCESS != parser_retval)){
                POS_WARN_C(
                    "failed to execute parser function: client_id(%lu), api_id(%lu)",
                    wqe->client_id, api_id
                );
                wqe->status = kPOS_API_Execute_Status_Parse_Failed;
                wqe->return_tick = POSUtilTimestamp::get_tsc();                    
                this->_ws->template push_cq<kPOS_Queue_Position_Parser>(wqe);

                continue;
            }
            
            /*!
                *  \note       for api in type of Delete_Resource, one can directly send
                *              response to the client right after operating on mocked resources
                *  \warning    we can't apply this rule for Create_Resource, consider the memory situation, which is passthrough addressed
                */
            if(unlikely(api_meta.api_type == kPOS_API_Type_Delete_Resource)){
                POS_DEBUG_C("api(%lu) is type of Delete_Resource, set as \"Return_After_Parse\"", api_id);
                wqe->status = kPOS_API_Execute_Status_Return_After_Parse;
            }

            /*!
                *  \note       for sync api that mark as kPOS_API_Execute_Status_Return_After_Parse,
                *              we directly return the result back to the frontend side
                */
            if(wqe->status == kPOS_API_Execute_Status_Return_After_Parse){
                wqe->return_tick = POSUtilTimestamp::get_tsc();
                this->_ws->template push_cq<kPOS_Queue_Position_Parser>(wqe);
            }
        }

        /*!
        *  \brief  ================== phrase 2 - checkpoint insertion ==================
        *  \note   we need to do again as there might no wqe polled
        */
        #if POS_CONF_EVAL_CkptOptLevel > 0
            if(this->_client->is_time_for_ckpt()){
                if(unlikely(POS_SUCCESS != this->__checkpoint_insertion())){
                    POS_WARN_C("failed to insert checkpointing op");
                }
            }
        #else
            /* do nothing */ ;
        #endif
    }
}


/*!
 *  \brief  insert checkpoint op to the DAG based on certain conditions
 *  \note   aware of the macro POS_CONF_EVAL_CkptEnableIncremental
 *  \return POS_SUCCESS for successfully checkpoint insertion
 */
pos_retval_t POSParser::__checkpoint_insertion() {
    #if POS_CONF_EVAL_CkptEnableIncremental == 1
        return this->__checkpoint_insertion_incremental();
    #else
        return this->__checkpoint_insertion_naive();
    #endif
}


/*!
 *  \brief  naive implementation of checkpoint insertion procedure
 *  \note   this implementation naively insert a checkpoint op to the dag, 
 *          without any optimization hint
 *  \return POS_SUCCESS for successfully checkpoint insertion
 */
pos_retval_t POSParser::__checkpoint_insertion_naive() { 
    pos_retval_t retval = POS_SUCCESS;
    POSHandle *handle;
    POSHandleManager<POSHandle>* hm;
    POSAPIContext_QE *ckpt_wqe;
    uint64_t i, nb_handles;

    ckpt_wqe = new POSAPIContext_QE_t(
        /* api_id*/ this->_ws->checkpoint_api_id,
        /* client */ this->_client
    );
    POS_CHECK_POINTER(ckpt_wqe);

    for(auto &stateful_handle_id : this->_ws->stateful_handle_type_idx){
        hm = pos_get_client_typed_hm(this->_client, stateful_handle_id, POSHandleManager<POSHandle>);
        POS_CHECK_POINTER(hm);
        nb_handles = hm->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            handle = hm->get_handle_by_id(i);
            POS_CHECK_POINTER(handle);
            ckpt_wqe->record_checkpoint_handles(handle);
        }
    }

    retval = this->_client->dag.launch_op(ckpt_wqe);

exit:
    return retval;
}


/*!
 *  \brief  level-1/2 optimization of checkpoint insertion procedure
 *  \note   this implementation give hints of those memory handles that
 *          been modified (INOUT/OUT) since last checkpoint
 *  \return POS_SUCCESS for successfully checkpoint insertion
 */
pos_retval_t POSParser::__checkpoint_insertion_incremental() {
    pos_retval_t retval = POS_SUCCESS;
    POSHandleManager<POSHandle>* hm;
    POSAPIContext_QE *ckpt_wqe;
    uint64_t i;

    ckpt_wqe = new POSAPIContext_QE_t(
        /* api_id*/ this->_ws->checkpoint_api_id,
        /* client */ this->_client
    );
    POS_CHECK_POINTER(ckpt_wqe);

    /*!
        *  \note   we only checkpoint those resources that has been modified since last checkpoint
        */
    for(auto &stateful_handle_id : this->_ws->stateful_handle_type_idx){
        hm = pos_get_client_typed_hm(this->_client, stateful_handle_id, POSHandleManager<POSHandle>);
        POS_CHECK_POINTER(hm);
        std::set<POSHandle*>& modified_handles = hm->get_modified_handles();
        if(likely(modified_handles.size() > 0)){
            ckpt_wqe->record_checkpoint_handles(modified_handles);
        }
        hm->clear_modified_handle();
    }

    retval = this->_client->dag.launch_op(ckpt_wqe);
    
exit:
    return retval;
}
