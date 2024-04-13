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
    std::vector<POSAPIContext_QE*> wqes;
    POSAPIContext_QE* wqe;
    uint64_t last_ckpt_tick = 0, current_tick;

    if(unlikely(POS_SUCCESS != this->daemon_init())){
        POS_WARN_C("failed to init daemon, worker daemon exit");
        return;
    }
    
    while(!_stop_flag){
        _ws->poll_parser_wq(&wqes);

    #if POS_ENABLE_DEBUG_CHECK
        if(wqes.size() > 0){
            POS_DEBUG_C("polling runtime work queues, obtain %lu elements", wqes.size());
        }
    #endif

        for(i=0; i<wqes.size(); i++){
            POS_CHECK_POINTER(wqe = wqes[i]);

            api_id = wqe->api_cxt->api_id;
            api_meta = _ws->api_mgnr->api_metas[api_id];

        #if POS_ENABLE_DEBUG_CHECK
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

                goto checkpoint_entrance;
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

        checkpoint_entrance:
            /*!
             *  \brief  ================== phrase 2 - checkpoint insertion ==================
             */
            #if POS_CKPT_OPT_LEVEL > 0
                // TODO: this checkpoint tick should be modified as per-client
                current_tick = POSUtilTimestamp::get_tsc();
                if(unlikely(current_tick - last_ckpt_tick >= this->checkpoint_interval_tick)){
                    last_ckpt_tick = current_tick;
                    if(unlikely(POS_SUCCESS != this->__checkpoint_insertion(wqe))){
                        POS_WARN_C("failed to insert checkpointing op");
                    }
                }
            #else
                /* do nothing */ ;
            #endif
        }

        wqes.clear();
    }
}


/*!
 *  \brief  insert checkpoint op to the DAG based on certain conditions
 *  \note   aware of the macro POS_CKPT_ENABLE_INCREMENTAL
 *  \param  wqe the exact WQ element before inserting checkpoint op
 *  \return POS_SUCCESS for successfully checkpoint insertion
 */
pos_retval_t POSParser::__checkpoint_insertion(POSAPIContext_QE* wqe) {
    #if POS_CKPT_ENABLE_INCREMENTAL == 1
        return this->__checkpoint_insertion_incremental(wqe);
    #else
        return this->__checkpoint_insertion_naive(wqe);
    #endif
}


/*!
 *  \brief  naive implementation of checkpoint insertion procedure
 *  \note   this implementation naively insert a checkpoint op to the dag, 
 *          without any optimization hint
 *  \param  wqe the exact WQ element before inserting checkpoint op
 *  \return POS_SUCCESS for successfully checkpoint insertion
 */
pos_retval_t POSParser::__checkpoint_insertion_naive(POSAPIContext_QE* wqe) { 
    pos_retval_t retval = POS_SUCCESS;
    POSHandle *handle;
    POSHandleManager<POSHandle>* hm;
    POSAPIContext_QE *ckpt_wqe;
    uint64_t i, nb_handles;
    POSClient *client;

    ckpt_wqe = new POSAPIContext_QE_t(
        /* api_id*/ this->_ws->checkpoint_api_id,
        /* client */ wqe->client
    );
    POS_CHECK_POINTER(ckpt_wqe);

    client = (POSClient*)(wqe->client);

    for(auto &stateful_handle_id : this->_ws->stateful_handle_type_idx){
        hm = pos_get_client_typed_hm(client, stateful_handle_id, POSHandleManager<POSHandle>);
        POS_CHECK_POINTER(hm);
        nb_handles = hm->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            handle = hm->get_handle_by_id(i);
            POS_CHECK_POINTER(handle);
            ckpt_wqe->record_checkpoint_handles(handle);
        }
    }

    retval = ((POSClient*)wqe->client)->dag.launch_op(ckpt_wqe);

exit:
    return retval;
}


/*!
 *  \brief  level-1/2 optimization of checkpoint insertion procedure
 *  \note   this implementation give hints of those memory handles that
 *          been modified (INOUT/OUT) since last checkpoint
 *  \param  wqe the exact WQ element before inserting checkpoint op
 *  \return POS_SUCCESS for successfully checkpoint insertion
 */
pos_retval_t POSParser::__checkpoint_insertion_incremental(POSAPIContext_QE* wqe) {
    pos_retval_t retval = POS_SUCCESS;
    POSClient *client;
    POSHandleManager<POSHandle>* hm;
    POSAPIContext_QE *ckpt_wqe;
    uint64_t i;

    POS_CHECK_POINTER(wqe);

    client = (POSClient*)(wqe->client);
    
    ckpt_wqe = new POSAPIContext_QE_t(
        /* api_id*/ this->_ws->checkpoint_api_id,
        /* client */ wqe->client
    );
    POS_CHECK_POINTER(ckpt_wqe);

    /*!
        *  \note   we only checkpoint those resources that has been modified since last checkpoint
        */
    for(auto &stateful_handle_id : this->_ws->stateful_handle_type_idx){
        hm = pos_get_client_typed_hm(client, stateful_handle_id, POSHandleManager<POSHandle>);
        POS_CHECK_POINTER(hm);
        std::set<POSHandle*>& modified_handles = hm->get_modified_handles();
        if(likely(modified_handles.size() > 0)){
            ckpt_wqe->record_checkpoint_handles(modified_handles);
        }
        hm->clear_modified_handle();
    }

    retval = ((POSClient*)wqe->client)->dag.launch_op(ckpt_wqe);
    
exit:
    return retval;
}
