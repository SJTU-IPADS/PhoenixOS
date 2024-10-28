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
#include "pos/include/utils/serializer.h"
#include "pos/include/proto/apicxt.pb.h"


pos_retval_t POSAPIContext_QE::persist(std::string ckpt_dir){
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


/*!
 *  \brief  serialize the current current api context into the binary area
 *  \param  serialized_area  pointer to the binary area
 */
void POSAPIContext_t::serialize(void* serialized_area){
    void *ptr = serialized_area;
    uint64_t i, nb_params;
    POSAPIParam_t *param;

    POS_CHECK_POINTER(ptr);

    nb_params = params.size();

    POSUtil_Serializer::write_field(&ptr, &(api_id), sizeof(uint64_t));
    POSUtil_Serializer::write_field(&ptr, &(nb_params), sizeof(uint64_t));

    for(i=0; i<nb_params; i++){
        POS_CHECK_POINTER(param = params[i]);
        POSUtil_Serializer::write_field(&ptr, &(param->param_size), sizeof(uint64_t));
        POSUtil_Serializer::write_field(&ptr, param->param_value, param->param_size);
    }
}


/*!
 *  \brief  deserialize this api context
 *  \param  raw_data    raw data area that store the serialized data
 */
void POSAPIContext_t::deserialize(void* raw_data){
    void *ptr = raw_data;
    uint64_t i, nb_params, param_size;
    POSAPIParam_t *param;

    POS_CHECK_POINTER(ptr);

    POSUtil_Deserializer::read_field(&(this->api_id), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&(nb_params), &ptr, sizeof(uint64_t));
    
    for(i=0; i<nb_params; i++){
        POSUtil_Deserializer::read_field(&(param_size), &ptr, sizeof(uint64_t));
        POS_CHECK_POINTER(param = new POSAPIParam_t(ptr, param_size));
        ptr += param_size;

        params.push_back(param);
        overall_param_size += param_size;
    }
}


/*!
 *  \brief  serialize the current handle view into the binary area
 *  \param  serialized_area  pointer to the binary area
 */
void POSHandleView_t::serialize(void* serialized_area){
    void *ptr = serialized_area;
    POS_CHECK_POINTER(ptr);

    POS_CHECK_POINTER(handle);

    POSUtil_Serializer::write_field(&ptr, &(handle->id), sizeof(pos_u64id_t));
    POSUtil_Serializer::write_field(&ptr, &(handle->resource_type_id), sizeof(pos_resource_typeid_t));
    POSUtil_Serializer::write_field(&ptr, &(param_index), sizeof(uint64_t));
    POSUtil_Serializer::write_field(&ptr, &(offset), sizeof(uint64_t));
}


/*!
 *  \brief  deserialize this handle view
 *  \param  raw_data    raw data area that store the serialized data
 */
void POSHandleView_t::deserialize(void* raw_data){
    void *ptr = raw_data;

    POS_CHECK_POINTER(ptr);

    POSUtil_Deserializer::read_field(&(this->id), &ptr, sizeof(pos_u64id_t));
    POSUtil_Deserializer::read_field(&(this->resource_type_id), &ptr, sizeof(pos_resource_typeid_t));
    POSUtil_Deserializer::read_field(&(this->param_index), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&(this->offset), &ptr, sizeof(uint64_t));
}


/*!
 *  \brief  serialize this api context
 *  \param  serialized_area pointer to the area that stores the serialized data
 */
void POSAPIContext_QE_t::serialize(void** serialized_area){
    void *ptr;
    uint64_t api_cxt_serialize_size;

    // serialize one type of handle views
    auto __serialize_handle_views = [](void** ptr, std::vector<POSHandleView_t>& hv_vector){
        uint64_t nb_handle_views;
        nb_handle_views = hv_vector.size();

        POSUtil_Serializer::write_field(ptr, &(nb_handle_views), sizeof(uint64_t));
        for(auto &hv : hv_vector){
            hv.serialize(*ptr);
            (*ptr) += POSHandleView_t::get_serialize_size();
        }
    };

    POS_CHECK_POINTER(serialized_area);

    uint64_t allocate_size = get_serialize_size();
    
    *serialized_area = malloc(allocate_size);
    POS_CHECK_POINTER(*serialized_area);
    
    ptr = *serialized_area;

    // part 1: base fields
    POSUtil_Serializer::write_field(&ptr, &(this->id), sizeof(pos_u64id_t));

    // part 2: api context
    api_cxt_serialize_size = api_cxt->get_serialize_size();
    POSUtil_Serializer::write_field(&ptr, &(api_cxt_serialize_size), sizeof(uint64_t));

    api_cxt->serialize(ptr);
    ptr += api_cxt_serialize_size;

    // part 3: handle views
    __serialize_handle_views(&ptr, input_handle_views);
    __serialize_handle_views(&ptr, output_handle_views);
    __serialize_handle_views(&ptr, inout_handle_views);
    __serialize_handle_views(&ptr, create_handle_views);
    __serialize_handle_views(&ptr, delete_handle_views);
}


/*!
 *  \brief  deserialize this api context
 *  \param  raw_data    raw data area that store the serialized data
 */
void POSAPIContext_QE_t::deserialize(void* raw_data){
    void *ptr = raw_data;
    uint64_t api_cxt_serialize_size;

    auto __deserialize_handle_views = [](void** ptr, std::vector<POSHandleView_t>& hv_vector){
        uint64_t i, nb_handle_views;
        nb_handle_views = hv_vector.size();
        POSUtil_Deserializer::read_field(&(nb_handle_views), ptr, sizeof(uint64_t));

        for(i=0; i<nb_handle_views; i++){
            POSHandleView_t &hv = hv_vector.emplace_back();
            hv.deserialize(*ptr);
            (*ptr) += POSHandleView_t::get_serialize_size();
        }
    };

    POS_CHECK_POINTER(ptr);

    // part 1: base fields
    POSUtil_Deserializer::read_field(&(this->id), &ptr, sizeof(pos_u64id_t));

    // part 2: api context
    POSUtil_Deserializer::read_field(&(api_cxt_serialize_size), &ptr, sizeof(uint64_t));
    POS_CHECK_POINTER(api_cxt = new POSAPIContext_t());
    api_cxt->deserialize(ptr);
    ptr += api_cxt_serialize_size;

    // part 3: handle views
    __deserialize_handle_views(&ptr, input_handle_views);
    __deserialize_handle_views(&ptr, output_handle_views);
    __deserialize_handle_views(&ptr, inout_handle_views);
    __deserialize_handle_views(&ptr, create_handle_views);
    __deserialize_handle_views(&ptr, delete_handle_views);
}
