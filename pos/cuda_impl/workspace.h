#pragma once

#include <iostream>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/workspace.h"
#include "pos/include/parser.h"

#include "pos/cuda_impl/client.h"
#include "pos/cuda_impl/parser.h"
#include "pos/cuda_impl/worker.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/api_context.h"


class POSWorkspace_CUDA : public POSWorkspace{
 public:
    POSWorkspace_CUDA(int argc, char *argv[]) : POSWorkspace(argc, argv){
        this->checkpoint_api_id = 6666;
    }

    /*!
     *  \brief  initialize the workspace
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     *  \return POS_SUCCESS for successfully initialization
     */
    pos_retval_t init() override {
        // create the api manager
        this->api_mgnr = new POSApiManager_CUDA();
        POS_CHECK_POINTER(this->api_mgnr);
        this->api_mgnr->init();

        // mark all stateful resources
        this->stateful_handle_type_idx.push_back({
            kPOS_ResourceTypeId_CUDA_Memory
        });

        return POS_SUCCESS;
    }

    /*!
     *  \brief  create and add a new client to the workspace
     *  \param  clnt    pointer to the POSClient to be added
     *  \param  uuid    the result uuid of the added client
     *  \return POS_SUCCESS for successfully added
     */
    pos_retval_t create_client(POSClient** clnt, pos_client_uuid_t* uuid) override {
        pos_client_cxt_CUDA_t client_cxt;
        client_cxt.cxt_base = this->_template_client_cxt;
        client_cxt.cxt_base.checkpoint_api_id = this->checkpoint_api_id;
        client_cxt.cxt_base.stateful_handle_type_idx = this->stateful_handle_type_idx;

        POS_CHECK_POINTER(*clnt = new POSClient_CUDA(/* ws */ this, /* id */ _current_max_uuid, /* cxt */ client_cxt));
        (*clnt)->init();
        
        *uuid = _current_max_uuid;
        _current_max_uuid += 1;
        _client_map[*uuid] = (*clnt);

        POS_DEBUG_C("add client: addr(%p), uuid(%lu)", (*clnt), *uuid);
        return POS_SUCCESS;
    }

 protected:
    /*!
     *  \brief  thread for ondemand reload stateful handles during restore
     */
    // void __ondemand_reload_thread() override {
    //     pos_ondemand_reload_job_t *plan;

    //     auto __process_one_plan = [&](pos_ondemand_reload_job_t *plan){
    //         POS_CHECK_POINTER(plan->handle);
    //         POS_CHECK_POINTER(plan->client);

    //         switch(handle->resource_type_id){
    //         case: kPOS_ResourceTypeId_CUDA_Memory:
    //             if(unlikely(POS_SUCCESS != plan->handle->reload_state())){
    //                 POS_WARN("failed to reload state of handle: server_addr(%p)", handle->server_addr);
    //             }
    //             break;
    //         case: kPOS_ResourceTypeId_CUDA_Module:
    //             // do nothing
    //             break;
    //         default:
    //             POS_WARN("unsupport CUDA resource for reloading state, this is a bug: resource_type_id(%u)", handle->resource_type_id);
    //         };
    //     };

    //     while(!this->ondemand_reload_cxt.stop_flag){
    //         if(POS_SUCCESS == this->ondemand_reload_cxt.wq_from_parser->dequeue(plan)){ 
    //             POS_CHECK_POINTER(plan);
    //             __process_one_plan(plan);
    //         }
            
    //         if(POS_SUCCESS == this->ondemand_reload_cxt.wq_from_worker->dequeue(plan)){ 
    //             POS_CHECK_POINTER(plan);
    //             __process_one_plan(plan);
    //         }
    //     }

    // exit:
    //     this->ondemand_reload_cxt.is_active = false;
    // }
};
