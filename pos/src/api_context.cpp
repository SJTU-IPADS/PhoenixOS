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
#include <memory>
#include <filesystem>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/handle.h"
#include "pos/include/api_context.h"
#include "pos/include/utils/timer.h"
#include "pos/include/proto/apicxt.pb.h"


POSAPIContext_QE::POSAPIContext_QE(POSClient* client, const std::string& ckpt_file){
    pos_retval_t retval = POS_SUCCESS;
    pos_protobuf::Bin_POSAPIContext apicxt_binary;
    POSHandleView_t hv;
    std::ifstream input;
    uint64_t i, param_size;
    void *param_area;
    POSAPIParam_t *api_param;

    POS_CHECK_POINTER(client);

    input.open(ckpt_file, std::ios::in | std::ios::binary);
    if(!input){
        POS_WARN_C("failed to open apicxt ckpt file");
        retval = POS_FAILED;
        goto exit;
    }

    if (!apicxt_binary.ParseFromIstream(&input)) {
        POS_WARN_C("failed to deserialize apicxt ckpt file");
        retval = POS_FAILED;
        goto exit;
    }

    this->client = client;
    this->client_id = client->id;
    this->id = apicxt_binary.id();
    this->has_return = apicxt_binary.has_return();

    this->api_cxt = new POSAPIContext_t(apicxt_binary.api_id());
    POS_CHECK_POINTER(this->api_cxt);

    for(i=0; i<apicxt_binary.input_handle_views_size(); i++){
        hv.id = apicxt_binary.input_handle_views(i).id();
        hv.resource_type_id = apicxt_binary.input_handle_views(i).resource_type_id();
        hv.param_index = apicxt_binary.input_handle_views(i).param_index();
        hv.offset = apicxt_binary.input_handle_views(i).offset();
        hv.handle = nullptr;
        this->input_handle_views.push_back(hv);
    }

    for(i=0; i<apicxt_binary.output_handle_views_size(); i++){
        hv.id = apicxt_binary.output_handle_views(i).id();
        hv.resource_type_id = apicxt_binary.output_handle_views(i).resource_type_id();
        hv.param_index = apicxt_binary.output_handle_views(i).param_index();
        hv.offset = apicxt_binary.output_handle_views(i).offset();
        hv.handle = nullptr;
        this->output_handle_views.push_back(hv);
    }

    for(i=0; i<apicxt_binary.inout_handle_views_size(); i++){
        hv.id = apicxt_binary.inout_handle_views(i).id();
        hv.resource_type_id = apicxt_binary.inout_handle_views(i).resource_type_id();
        hv.param_index = apicxt_binary.inout_handle_views(i).param_index();
        hv.offset = apicxt_binary.inout_handle_views(i).offset();
        hv.handle = nullptr;
        this->inout_handle_views.push_back(hv);
    }

    for(i=0; i<apicxt_binary.create_handle_views_size(); i++){
        hv.id = apicxt_binary.create_handle_views(i).id();
        hv.resource_type_id = apicxt_binary.create_handle_views(i).resource_type_id();
        hv.param_index = apicxt_binary.create_handle_views(i).param_index();
        hv.offset = apicxt_binary.create_handle_views(i).offset();
        hv.handle = nullptr;
        this->create_handle_views.push_back(hv);
    }

    for(i=0; i<apicxt_binary.delete_handle_views_size(); i++){
        hv.id = apicxt_binary.delete_handle_views(i).id();
        hv.resource_type_id = apicxt_binary.delete_handle_views(i).resource_type_id();
        hv.param_index = apicxt_binary.delete_handle_views(i).param_index();
        hv.offset = apicxt_binary.delete_handle_views(i).offset();
        hv.handle = nullptr;
        this->delete_handle_views.push_back(hv);
    }

    this->create_tick = apicxt_binary.create_tick();
    this->return_tick = apicxt_binary.return_tick();
    this->parser_s_tick = apicxt_binary.parser_s_tick();
    this->parser_e_tick = apicxt_binary.parser_e_tick();
    this->worker_s_tick = apicxt_binary.worker_s_tick();
    this->worker_e_tick = apicxt_binary.worker_e_tick();

    for(i=0; i<apicxt_binary.params_size(); i++){
        POS_ASSERT((param_size = apicxt_binary.params(i).size()) > 0);
        POS_CHECK_POINTER(param_area = malloc(param_size));
        memcpy(
            param_area, 
            reinterpret_cast<const void*>(apicxt_binary.params(i).state().c_str()),
            param_size
        );

        POS_CHECK_POINTER(api_param = new POSAPIParam_t(param_area, param_size));
        this->api_cxt->params.push_back(api_param);
    }

exit:
    if(input.is_open()){ input.close(); }
    if(unlikely(retval = POS_SUCCESS)){
        // we mark client as nullptr to let outside know this APIcontext isn't
        // create successfully
        this->client = nullptr;
    }
}


template<bool with_params>
pos_retval_t POSAPIContext_QE::persist(std::string ckpt_dir){
    pos_retval_t retval = POS_SUCCESS;
    std::string ckpt_file_path;
    pos_protobuf::Bin_POSAPIContext apicxt_binary;
    pos_protobuf::Bin_POSHandleView *hv_binary;
    pos_protobuf::Bin_POSAPIParam *param_binary;
    std::ofstream ckpt_file_stream;

    POS_ASSERT(std::filesystem::exists(ckpt_dir));

    apicxt_binary.set_id(this->id);
    apicxt_binary.set_has_return(this->has_return);
    apicxt_binary.set_api_id(this->api_cxt->api_id);

    for(POSHandleView_t &hv : this->input_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_input_handle_views());
        POS_CHECK_POINTER(hv.handle);
        hv_binary->set_resource_type_id(hv.handle->resource_type_id);
        hv_binary->set_id(hv.handle->id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }

    for(POSHandleView_t &hv : this->output_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_output_handle_views());
        POS_CHECK_POINTER(hv.handle);
        hv_binary->set_resource_type_id(hv.handle->resource_type_id);
        hv_binary->set_id(hv.handle->id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }

    for(POSHandleView_t &hv : this->create_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_create_handle_views());
        POS_CHECK_POINTER(hv.handle);
        hv_binary->set_resource_type_id(hv.handle->resource_type_id);
        hv_binary->set_id(hv.handle->id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }

    for(POSHandleView_t &hv : this->delete_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_delete_handle_views());
        POS_CHECK_POINTER(hv.handle);
        hv_binary->set_resource_type_id(hv.handle->resource_type_id);
        hv_binary->set_id(hv.handle->id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }

    for(POSHandleView_t &hv : this->inout_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_inout_handle_views());
        POS_CHECK_POINTER(hv.handle);
        hv_binary->set_resource_type_id(hv.handle->resource_type_id);
        hv_binary->set_id(hv.handle->id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }
    apicxt_binary.set_create_tick(this->create_tick);
    apicxt_binary.set_return_tick(this->return_tick);
    apicxt_binary.set_parser_s_tick(this->parser_s_tick);
    apicxt_binary.set_parser_e_tick(this->parser_e_tick);
    apicxt_binary.set_worker_s_tick(this->worker_s_tick);
    apicxt_binary.set_worker_e_tick(this->worker_e_tick);

    if constexpr (with_params) {
        for(POSAPIParam_t * &param : this->api_cxt->params){
            POS_CHECK_POINTER(param_binary = apicxt_binary.add_params());
            POS_ASSERT(param->param_size > 0);
            param_binary->set_size(param->param_size);
            param_binary->set_state(reinterpret_cast<const char*>(param->param_value), param->param_size);
        }
    }

    // form the path to the checkpoint file of this handle
    ckpt_file_path = ckpt_dir 
                    + std::string("/a-")
                    + std::to_string(this->id) 
                    + std::string(".bin");

    // write to file
    ckpt_file_stream.open(ckpt_file_path, std::ios::binary | std::ios::out);
    if(!ckpt_file_stream){
        POS_WARN_C(
            "failed to dump checkpoint to file, failed to open file: path(%s)",
            ckpt_file_path.c_str()
        );
        retval = POS_FAILED;
        goto exit;
    }
    if(!apicxt_binary.SerializeToOstream(&ckpt_file_stream)){
        POS_WARN_C(
            "failed to dump checkpoint to file, protobuf failed to dump: path(%s)",
            ckpt_file_path.c_str()
        );
        retval = POS_FAILED;
        goto exit;
    }

exit:
    if(ckpt_file_stream.is_open()){ ckpt_file_stream.close(); }
    return retval;
}
template pos_retval_t POSAPIContext_QE::persist<true>(std::string ckpt_dir);
template pos_retval_t POSAPIContext_QE::persist<false>(std::string ckpt_dir);
