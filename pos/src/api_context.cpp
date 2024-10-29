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


pos_retval_t POSAPIContext_QE::persist_without_state_sync(std::string ckpt_dir){
    pos_retval_t retval = POS_SUCCESS;
    std::string ckpt_file_path;
    pos_protobuf::Bin_POSAPIContext apicxt_binary;
    pos_protobuf::Bin_POSHandleView *hv_binary;
    std::ofstream ckpt_file_stream;

    POS_ASSERT(std::filesystem::exists(ckpt_dir));

    apicxt_binary.set_id(this->id);
    apicxt_binary.set_api_id(this->api_cxt->api_id);

    for(POSHandleView_t &hv : this->input_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_input_handle_views());
        hv_binary->set_resource_type_id(hv.resource_type_id);
        hv_binary->set_id(hv.id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }

    for(POSHandleView_t &hv : this->output_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_output_handle_views());
        hv_binary->set_resource_type_id(hv.resource_type_id);
        hv_binary->set_id(hv.id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }

    for(POSHandleView_t &hv : this->create_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_create_handle_views());
        hv_binary->set_resource_type_id(hv.resource_type_id);
        hv_binary->set_id(hv.id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }

    for(POSHandleView_t &hv : this->delete_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_delete_handle_views());
        hv_binary->set_resource_type_id(hv.resource_type_id);
        hv_binary->set_id(hv.id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }

    for(POSHandleView_t &hv : this->inout_handle_views){
        POS_CHECK_POINTER(hv_binary = apicxt_binary.add_inout_handle_views());
        hv_binary->set_resource_type_id(hv.resource_type_id);
        hv_binary->set_id(hv.id);
        hv_binary->set_param_index(hv.param_index);
        hv_binary->set_offset(hv.offset);
    }
    apicxt_binary.set_create_tick(this->create_tick);
    apicxt_binary.set_return_tick(this->return_tick);
    apicxt_binary.set_parser_s_tick(this->parser_s_tick);
    apicxt_binary.set_parser_e_tick(this->parser_e_tick);
    apicxt_binary.set_worker_s_tick(this->worker_s_tick);
    apicxt_binary.set_worker_e_tick(this->worker_e_tick);

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


pos_retval_t POSAPIContext_QE::persist(std::string ckpt_dir){
    pos_retval_t retval = POS_SUCCESS;

    POS_ASSERT(std::filesystem::exists(ckpt_dir));

    // TODO:

exit:
    return retval;
}
