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
#include "pos/include/dag.h"


bool POSClient::is_time_for_ckpt(){
    bool retval = false;
    uint64_t current_tick = POSUtilTimestamp::get_tsc();

    if(unlikely(
        current_tick - this->_last_ckpt_tick 
            >= this->_ws->tsc_timer.ms_to_tick(POS_CONF_EVAL_CkptDefaultIntervalMs)
    )){
        retval = true;
        this->_last_ckpt_tick = current_tick;
    }

    return retval;
}


void POSClient::init_restore_load_resources() {
    pos_retval_t temp_retval;
    uint64_t i, j;
    std::ifstream file;
    uint8_t *checkpoint_bin, *bin_ptr;
    uint64_t file_size;

    pos_resource_typeid_t resource_type_id;
    uint64_t nb_handles, nb_resource_types, serialize_area_size;

    uint64_t nb_api_cxt;
    POSAPIContext_QE_t *wqe;

    std::set<pos_resource_typeid_t> rid_set;
    typename std::set<pos_resource_typeid_t>::iterator rid_set_iter;

    pos_resource_typeid_t rid, parent_rid;
    pos_vertex_id_t parent_vid;
    POSHandleManager<POSHandle> *hm, *parent_hm;
    POSHandle *handle, *parent_handle;

    pos_vertex_id_t host_ckpt_wqe_vid;
    uint32_t host_ckpt_wqe_pid;
    uint64_t host_ckpt_offset, host_ckpt_size;

    auto __get_binary_file_size = [](std::ifstream& file) -> uint64_t {
        file.seekg(0, std::ios::end);
        return file.tellg();
    };

    auto __copy_binary_file_to_buffer = [](std::ifstream& file, uint64_t size, uint8_t *buffer) {
        file.seekg(0, std::ios::beg);
        file.read((char*)(buffer), size);
    };

    #define __READ_TYPED_BINARY_AND_FWD(var, type, pointer) \
                var = (*((type*)(pointer)));                \
                pointer += sizeof(type);

    // open checkpoint file
    file.open(this->_cxt.checkpoint_file_path.c_str(), std::ios::in|std::ios::binary);
    if(unlikely(!file.good())){
        POS_ERROR_C("failed to open checkpoint binary file from %s", this->_cxt.checkpoint_file_path.c_str());
    }

    POS_LOG("[Restore]: loading resource state from binary file...");

    // obtain its size
    file_size = __get_binary_file_size(file);
    POS_ASSERT(file_size > 0);

    // allocate buffer and readin data to the buffer
    POS_CHECK_POINTER(checkpoint_bin = (uint8_t*)malloc(file_size));
    __copy_binary_file_to_buffer(file, file_size, checkpoint_bin);
    bin_ptr = checkpoint_bin;

    /* --------- step 1: read handles --------- */
    // field: # resource type
    __READ_TYPED_BINARY_AND_FWD(nb_resource_types, uint64_t, bin_ptr);
    for(i=0; i<nb_resource_types; i++){
        // field: # resource type id
        __READ_TYPED_BINARY_AND_FWD(resource_type_id, pos_resource_typeid_t, bin_ptr);

        // field: # handles under this manager 
        __READ_TYPED_BINARY_AND_FWD(nb_handles, uint64_t, bin_ptr);

        for(j=0; j<nb_handles; j++){
            // field: size of the serialized area of this handle
            __READ_TYPED_BINARY_AND_FWD(serialize_area_size, uint64_t, bin_ptr);

            if(likely(serialize_area_size > 0)){
                temp_retval = this->__allocate_typed_resource_from_binary(resource_type_id, bin_ptr);
                POS_ASSERT(temp_retval == POS_SUCCESS);
                bin_ptr += serialize_area_size;
            }
        }
    }

    /* --------- step 2: read api context --------- */
    // field: # api context
    __READ_TYPED_BINARY_AND_FWD(nb_api_cxt, uint64_t, bin_ptr);

    for(i=0; i<nb_api_cxt; i++){
        // field: size of the serialized area of this api context
        __READ_TYPED_BINARY_AND_FWD(serialize_area_size, uint64_t, bin_ptr);
        
        if(serialize_area_size > 0){
            POS_CHECK_POINTER(wqe = new POSAPIContext_QE_t(/* pos_client */ this));
            wqe->deserialize(bin_ptr);
            this->dag.record_op(wqe);
        }
        
        bin_ptr += serialize_area_size;
    }

    auto __restore_handle_view_pointers = [&](std::vector<POSHandleView_t>& hv_vector){
        uint64_t i;
        POSHandleManager<POSHandle> *hm_target;
        POSHandle *handle_target;

        for(i=0; i<hv_vector.size(); i++){
            POSHandleView_t &hv = hv_vector[i];
            POS_CHECK_POINTER(hm_target = this->__get_handle_manager_by_resource_id(hv.resource_type_id));
            POS_CHECK_POINTER(handle_target = hm_target->get_handle_by_dag_id(hv.handle_dag_id));
            hv.handle = handle_target;
        }
    };

    // restore pointer within the handle views
    for(i=0; i<nb_api_cxt; i++){
        POS_CHECK_POINTER(wqe = this->dag.get_api_cxt_by_id(i));
        __restore_handle_view_pointers(wqe->input_handle_views);
        __restore_handle_view_pointers(wqe->inout_handle_views);
        __restore_handle_view_pointers(wqe->output_handle_views);
        __restore_handle_view_pointers(wqe->create_handle_views);
        __restore_handle_view_pointers(wqe->delete_handle_views);
    }

    /* --------- step 3: read DAG --------- */
    // field: size of the serialized area of this dag topo
    __READ_TYPED_BINARY_AND_FWD(serialize_area_size, uint64_t, bin_ptr);
    this->dag.deserialize(bin_ptr);
    bin_ptr += serialize_area_size;

    /* --------- step 4: restore handle tree --------- */
    rid_set = this->__get_resource_idx();
    for(rid_set_iter = rid_set.begin(); rid_set_iter != rid_set.end(); rid_set_iter++){
        rid = *rid_set_iter;

        POS_CHECK_POINTER(hm = this->__get_handle_manager_by_resource_id(rid));
        nb_handles = hm->get_nb_handles();

        for(i=0; i<nb_handles; i++){
            POS_CHECK_POINTER(handle = hm->get_handle_by_id(i));

            // restore parent handles
            for(j=0; j<handle->parent_handles_waitlist.size(); j++){
                parent_rid = handle->parent_handles_waitlist[j].first;
                parent_vid = handle->parent_handles_waitlist[j].second;

                POS_CHECK_POINTER(parent_hm = this->__get_handle_manager_by_resource_id(parent_rid));
                POS_CHECK_POINTER(parent_handle = parent_hm->get_handle_by_dag_id(parent_vid));

                handle->record_parent_handle(parent_handle);
            }

            // restore host-side checkpoint record
            if(handle->ckpt_bag != nullptr){
                for(j=0; j<handle->ckpt_bag->host_ckpt_waitlist.size(); j++){
                    host_ckpt_wqe_vid = std::get<0>(handle->ckpt_bag->host_ckpt_waitlist[j]);
                    host_ckpt_wqe_pid = std::get<1>(handle->ckpt_bag->host_ckpt_waitlist[j]);
                    host_ckpt_offset = std::get<2>(handle->ckpt_bag->host_ckpt_waitlist[j]);
                    host_ckpt_size = std::get<3>(handle->ckpt_bag->host_ckpt_waitlist[j]);

                    POS_CHECK_POINTER(wqe = this->dag.get_api_cxt_by_dag_id(host_ckpt_wqe_vid));
                    temp_retval = handle->ckpt_bag->set_host_checkpoint_record({
                        .wqe = wqe,
                        .param_index = host_ckpt_wqe_pid,
                        .offset = host_ckpt_offset,
                        .size = host_ckpt_size
                    });
                    POS_ASSERT(temp_retval == POS_SUCCESS);
                }
            }
        }

        POS_LOG("    => restored handle tree of %lu handles for resource type %u", nb_handles, rid);
    }
    
    /* --------- step 5: recompute missing checkpoints --------- */
    // check init_restore_generate_recompute_scheme
    
    /* --------- step 6: restore handles and their state (via reload / recomputes) --------- */
    // check init_restore_handles

    #undef  __READ_TYPED_BINARY_AND_FWD
}


void POSClient::init_restore_generate_recompute_scheme(
    std::map<pos_vertex_id_t, POSAPIContext_QE_t*>& apicxt_sequence_map,
    std::multimap<pos_vertex_id_t, POSHandle*>& missing_handle_map
){
    uint64_t i, nb_handles;
    bool is_missing;
    pos_vertex_id_t vg, vo, vh;
    POSHandle *handle;
    POSHandleManager<POSHandle> *hm;
    std::set<uint64_t> ckpt_set;

    using version_handle_map_t = std::multimap<pos_vertex_id_t, POSHandle*>;
    using version_handle_pair_t = std::pair<pos_vertex_id_t, POSHandle*>;
    using version_handle_vector_t = std::vector<version_handle_pair_t>;

    using version_apicxt_map_t = std::map<pos_vertex_id_t, POSAPIContext_QE_t*>;
    using version_apicxt_pair_t = std::pair<pos_vertex_id_t, POSAPIContext_QE_t*>;

    version_handle_map_t missing_vh_map;
    version_handle_map_t tracing_vh_map;

    version_handle_pair_t target_vp;
    pos_vertex_id_t vt;
    POSHandle *ht;
    POSAPIContext_QE_t *wqe_upstream, *wqe_upstream_of_inbuf;
    std::set<uint64_t> ckpt_version_set;
    pos_vertex_id_t vi;

    auto __is_vh_map_contains = [](version_handle_map_t& vh_map, pos_vertex_id_t version, POSHandle* handle) -> bool {
        bool retval = false;
        auto nums = vh_map.count(version);
        auto iter = vh_map.find(version);

        if(nums == 0){ goto exit; }

        POS_CHECK_POINTER(handle);

        while(nums--){
            if(iter->second == handle){
                retval = true;
                break;
            }
            iter++;
        }
        
    exit:
        return retval;
    };
    
    auto __pop_highest_version_vh_from_map = [](version_handle_map_t& vh_map) -> version_handle_pair_t {
        version_handle_pair_t retval;
        POS_ASSERT(vh_map.size() > 0);
        auto max_iter = vh_map.rbegin();
        retval.first = max_iter->first;
        retval.second = max_iter->second;
        vh_map.erase(std::next(max_iter).base());
        return retval;
    };

    auto __print_apicxt_map = [](version_apicxt_map_t& apicxt_map, std::string name) {
        typename version_apicxt_map_t::iterator map_iter;
        pos_vertex_id_t wqe_dag_id;
        POSAPIContext_QE_t *wqe;

        for(map_iter = apicxt_map.begin(); map_iter != apicxt_map.end(); map_iter++){
            wqe_dag_id = map_iter->first;
            POS_CHECK_POINTER(wqe = map_iter->second);
            POS_LOG("  => api_id(%lu), dag_id(%lu)", wqe->api_cxt->api_id, wqe_dag_id);
        }
        POS_LOG("%s contains %lu of API calls", name.c_str(), apicxt_map.size());
    };

    std::map<pos_vertex_id_t, POSAPIContext_QE_t*> kernel_sequence;

    vg = this->dag.latest_checkpoint_version;

    // step 1: generate missing list
    for(auto &stateful_type_id : this->_cxt.stateful_handle_type_idx){
        POS_CHECK_POINTER(hm = this->__get_handle_manager_by_resource_id(stateful_type_id));
        nb_handles = hm->get_nb_handles();

        for(i=0; i<nb_handles; i++){
            POS_CHECK_POINTER(handle = hm->get_handle_by_id(i));
            POS_CHECK_POINTER(handle->ckpt_bag);

            ckpt_set = handle->ckpt_bag->get_checkpoint_version_set</* on_deivce */false>();
            if(unlikely(ckpt_set.size() == 0)){
                // no checkpoint founded
                vh = 0;
            } else {
                vh = *(ckpt_set.rbegin());
            }

            this->dag.check_missing_ckpt(handle->dag_vertex_id, vh, vg, is_missing, vo);
            if(is_missing == true){
                missing_vh_map.insert(std::pair<pos_vertex_id_t,POSHandle*>(vo, handle));
                POS_LOG("checkpoint missing: client_addr(%p), vo(%lu), vg(%lu), vh(%lu)", handle->client_addr, vo, vg, vh);
            } else {
                POS_LOG("checkpoint ok: client_addr(%p), vg(%lu), vh(%lu)", handle->client_addr, vo, vg);
            }
        }
    }
    missing_handle_map = missing_vh_map;

    // step 2: generate recomputation sequence
    while(missing_vh_map.size() > 0){
        /*!
         *  \brief  pop one handle with missing checkpoint with highest version
         */
        target_vp = __pop_highest_version_vh_from_map(missing_vh_map);
        vt = target_vp.first;
        POS_CHECK_POINTER(ht = target_vp.second);
        POS_LOG("pop target vp: version(%lu), client_addr(%p)", vt, ht->client_addr);

        /*!
         *  \brief  obtain the upstream wqe of this handle, and add those input/inout
         *          handles of this wqe to the missing list, if they aren't under tracing
         *          or has exact checkpoint
         * \note    version of the handle is exactly the dag id of its upstream api context
         */
        POS_CHECK_POINTER(wqe_upstream = this->dag.get_api_cxt_by_dag_id(vt));

        auto __process_in_handles = [&](std::vector<POSHandleView_t> &hv_vec){
            for(POSHandleView_t &hv : hv_vec){
                POS_CHECK_POINTER(hv.handle);

                /*!
                *  \note   we only care about stateful handles
                */
                if(std::find(
                    this->_cxt.stateful_handle_type_idx.begin(), this->_cxt.stateful_handle_type_idx.end(), hv.resource_type_id
                ) == this->_cxt.stateful_handle_type_idx.end()){
                    continue;
                }

                /*!
                *  \brief  obtain the upstream api context that modified this input buffer, we need its version
                *  \note   we set the deadline version as vt-1, just the one before current upstream api context
                *          (i.e., wqe_upstream)
                */
                if(likely(vt > 0)){
                    wqe_upstream_of_inbuf = this->dag.get_handle_upstream_api_cxt_by_ddl(hv.handle_dag_id, vt-1);
                    if(wqe_upstream_of_inbuf == nullptr){
                        vi = 0;
                    } else {
                        vi = wqe_upstream_of_inbuf->dag_vertex_id;
                    }
                    POS_ASSERT(vi < vt);
                } else {
                    vi = 0;
                } 

                POS_LOG(
                    "    ==> upstream input buffer: client_addr(%p), vt(%lu), vi(%lu) | "
                    "missing_vh_map has vt(%d), vi(%d) | "
                    "tracing_vh_map has vt(%d), vi(%d) | "
                    "missing_vh_map len: %lu | "
                    "tracing_vh_map len: %lu ",
                    hv.handle->client_addr, vt, vi,
                    __is_vh_map_contains(missing_vh_map, vt, hv.handle),
                    __is_vh_map_contains(missing_vh_map, vi, hv.handle),
                    __is_vh_map_contains(tracing_vh_map, vt, hv.handle),
                    __is_vh_map_contains(tracing_vh_map, vi, hv.handle),
                    missing_vh_map.size(),
                    tracing_vh_map.size()
                );
                
                
                /*!
                 *  \note   if vi is 0, then we reach the initial state of this handle, there's no need to restore it via recompute
                 */
                if(unlikely(vi == 0)){
                    POS_LOG("trace till begining: client_addr(%p)", hv.handle->client_addr);
                    tracing_vh_map.insert(version_handle_pair_t(vi, hv.handle));
                    continue;
                }

                /*!
                *  \note   if this upstream handle has been or is going to be traced, we will skip it
                */
                if(__is_vh_map_contains(tracing_vh_map, vi, hv.handle) == true){
                    continue;
                } else if(__is_vh_map_contains(missing_vh_map, vi, hv.handle) == true){
                    continue;
                } else {
                    /*!
                     *  \note   we will continue to trace further upstream of this upstream input handle, if it's not yet checkpointed
                     */
                    POS_CHECK_POINTER(hv.handle->ckpt_bag);
                    ckpt_version_set = hv.handle->ckpt_bag->get_checkpoint_version_set</* on_deivce */false>();
                    if(ckpt_version_set.count(vi) == 0){
                        POS_LOG("    => insert: client_addr(%p), vi(%lu)", hv.handle->client_addr, vi);
                        missing_vh_map.insert(version_handle_pair_t(vi, hv.handle));
                        tracing_vh_map.insert(version_handle_pair_t(vi, hv.handle));
                    }
                }
            }
        };
        
        POS_LOG("  ==> input: %lu", wqe_upstream->input_handle_views.size());
        __process_in_handles(wqe_upstream->input_handle_views);

        POS_LOG("  ==> outin: %lu", wqe_upstream->inout_handle_views.size());
        __process_in_handles(wqe_upstream->inout_handle_views);

        tracing_vh_map.insert(version_handle_pair_t(vt, ht));
        apicxt_sequence_map.insert(version_apicxt_pair_t(vt, wqe_upstream));
    }

    // __print_apicxt_map(apicxt_sequence_map, std::string("final kernel sequence"));

    POS_LOG("[Restore]: (step 5) recompute scheme generation finished, need to recompute %lu of APIs", apicxt_sequence_map.size());
}


void POSClient::init_restore_recreate_handles(
    std::map<pos_vertex_id_t, POSAPIContext_QE_t*>& apicxt_sequence_map,
    std::multimap<pos_vertex_id_t, POSHandle*>& missing_handle_map
){ 
    uint64_t i, nb_handles;
    std::set<pos_resource_typeid_t> rid_set;
    typename std::set<pos_resource_typeid_t>::iterator rid_set_iter;
    pos_resource_typeid_t rid;
    POSHandleManager<POSHandle> *hm, *parent_hm;
    POSHandle *handle, *parent_handle;

    typename std::multimap<pos_vertex_id_t, POSHandle*>::iterator mh_map_iter;
    pos_vertex_id_t handle_missing_version;
    POSHandle *missing_handle;
    std::set<POSHandle*> recomputed_handles;

    /*!
     *  \brief  recreate the handle with its parent handles if they are not ready
     *  \param  handle  the handle to be restored
     */
    auto __recreate_handle_with_dependency = [](POSHandle* handle){
        POSHandleManager<POSHandle> parent_hm;
        POSHandle *broken_handle;
        POSHandle::pos_broken_handle_list_t broken_handle_list;
        uint16_t nb_layers, layer_id_keeper;
        uint64_t handle_id_keeper;

        handle->collect_broken_handles(&broken_handle_list);
        nb_layers = broken_handle_list.get_nb_layers();
        if(likely(nb_layers == 0)){ goto exit; }

        layer_id_keeper = nb_layers - 1;
        handle_id_keeper = 0;

        while(1){
            broken_handle = broken_handle_list.reverse_get_handle(layer_id_keeper, handle_id_keeper);
            if(unlikely(broken_handle == nullptr)){ break; }
            if(unlikely(POS_SUCCESS != broken_handle->restore())){
                POS_ERROR_DETAIL(
                    "failed to restore broken handle: resource_type(%s), client_addr(%p), server_addr(%p), state(%u)",
                    broken_handle->get_resource_name().c_str(), broken_handle->client_addr, broken_handle->server_addr,
                    broken_handle->status
                );
            }
        }

    exit:
        ;
    };

    // step 1: recreate all handles on XPU driver / device
    rid_set = this->__get_resource_idx();
    for(rid_set_iter = rid_set.begin(); rid_set_iter != rid_set.end(); rid_set_iter++){
        rid = *rid_set_iter;
        POS_CHECK_POINTER(hm = this->__get_handle_manager_by_resource_id(rid));

        nb_handles = hm->get_nb_handles();
        for(i=0; i<nb_handles; i++){
            POS_CHECK_POINTER(handle = hm->get_handle_by_id(i));
            if(unlikely(handle->status == kPOS_HandleStatus_Active)){
                continue;
            }
            __recreate_handle_with_dependency(handle);
        }
    }

    // step 2: restore state of stateful resource via recomputation
    for(mh_map_iter=missing_handle_map.begin(); mh_map_iter!=missing_handle_map.end(); mh_map_iter++){
        handle_missing_version = mh_map_iter->first;
        POS_CHECK_POINTER(missing_handle = mh_map_iter->second);
        // TODO: recompute and restore their state
        POS_ERROR_C_DETAIL("haven't implement the recompute logic yet");
        recomputed_handles.insert(missing_handle);
    }


    // step 3: restore state of stateful resource via reload
    for(auto &stateful_type_id : this->_cxt.stateful_handle_type_idx){
        POS_CHECK_POINTER(hm = this->__get_handle_manager_by_resource_id(stateful_type_id));
        nb_handles = hm->get_nb_handles();

        for(i=0; i<nb_handles; i++){
            POS_CHECK_POINTER(handle = hm->get_handle_by_id(i));
            
            // this handle has already been recomputed and reloaded in step 2, no need to be reloaded again
            if(recomputed_handles.count(handle) > 0){ continue; }

            // reload the latest state back to device
            if(POS_SUCCESS != handle->reload_state_to_device(0, true)){
                POS_ERROR_C_DETAIL("failed to reload handle state to device: client_addr(%p)", handle->client_addr);
            }
        }
    }
}


void POSClient::deinit_dump_checkpoints() {
    std::string file_path;
    
    typename std::map<pos_resource_typeid_t, void*>::iterator hm_map_iter;
    POSHandleManager<POSHandle> *hm;
    uint64_t nb_handles, nb_resource_types, i;
    POSHandle *handle;
    
    uint64_t nb_api_cxt;
    POSAPIContext_QE_t *api_cxt;

    void *serialize_area;
    uint64_t serialize_area_size;

    file_path = std::string("./") + this->_cxt.job_name + std::string("_checkpoints_") + std::to_string(this->id) + std::string(".bat");

    this->__ckpt_station.clear();

    POS_LOG("collecting checkpoints...");

    /* ------------------ step 1: dump handles ------------------ */
    // field: # resource type
    nb_resource_types = this->handle_managers.size();
    // output_file.write((const char*)(&(nb_resource_types)), sizeof(uint64_t));
    this->__ckpt_station.load_value<uint64_t>(nb_resource_types);

    for(hm_map_iter = this->handle_managers.begin(); hm_map_iter != handle_managers.end(); hm_map_iter++){
        POS_CHECK_POINTER(hm = (POSHandleManager<POSHandle>*)(hm_map_iter->second));
        nb_handles = hm->get_nb_handles();

        // field: resource type id
        // output_file.write((const char*)(&(hm_map_iter->first)), sizeof(pos_resource_typeid_t));
        this->__ckpt_station.load_value<pos_resource_typeid_t>(hm_map_iter->first);

        // field: # handles under this manager 
        // output_file.write((const char*)(&nb_handles), sizeof(uint64_t));
        this->__ckpt_station.load_value<uint64_t>(nb_handles);

        for(i=0; i<nb_handles; i++){
            POS_CHECK_POINTER(handle = hm->get_handle_by_id(i));

            if(unlikely(POS_SUCCESS != handle->serialize(&serialize_area))){
                POS_WARN_C("failed to serialize handle: client_addr(%p)", handle->client_addr);
                continue;
            }
            POS_CHECK_POINTER(serialize_area);

            serialize_area_size = handle->get_serialize_size();

            // field: size of the serialized area of this handle
            // output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));
            this->__ckpt_station.load_value<uint64_t>(serialize_area_size);

            if(likely(serialize_area_size > 0)){
                // field: serialized data
                // output_file.write((const char*)(serialize_area), serialize_area_size);
                this->__ckpt_station.load_mem_area(serialize_area, serialize_area_size);
            }
            // output_file.flush();
            // free(serialize_area);
        }
    }

    /* ------------------ step 2: dump api context ------------------ */
    // field: # api context
    nb_api_cxt = this->dag.get_nb_api_cxt();
    // output_file.write((const char*)(&(nb_api_cxt)), sizeof(uint64_t));
    this->__ckpt_station.load_value<uint64_t>(nb_api_cxt);

    for(i=0; i<nb_api_cxt; i++){
        POS_CHECK_POINTER(api_cxt = this->dag.get_api_cxt_by_id(i));

        /*!
         *  \note   we only dump those api context that hasn't been pruned
         */
        if(api_cxt->is_ckpt_pruned == true){
            // field: size of the serialized area of this api context
            serialize_area_size = 0;
            // output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));
            this->__ckpt_station.load_value<uint64_t>(serialize_area_size);
        } else {
            api_cxt->serialize(&serialize_area);
            POS_CHECK_POINTER(serialize_area);

            // field: size of the serialized area of this api context
            serialize_area_size = api_cxt->get_serialize_size();
            // output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));
            this->__ckpt_station.load_value<uint64_t>(serialize_area_size);
            
            // field: serialized data
            // output_file.write((const char*)(serialize_area), serialize_area_size);
            this->__ckpt_station.load_mem_area(serialize_area, serialize_area_size);
            
            // output_file.flush();
            // free(serialize_area);
        }
    }

    /* ------------------ step 3: dump dag ------------------ */
    /*!
     *  \note   actually, after dumping handle and api context, we already can construct DAG while restoring,
     *          as the api context contains information about which handles each API would operates on, we still
     *          dump the DAG here to accelerate the re-execute algorithm in restore
     */
    this->dag.serialize(&serialize_area);
    POS_CHECK_POINTER(serialize_area);

    // field: size of the serialized area of this dag topo
    serialize_area_size = this->dag.get_serialize_size();
    // output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));
    this->__ckpt_station.load_value<uint64_t>(serialize_area_size);

    // field: serialized data
    // output_file.write((const char*)(serialize_area), serialize_area_size);
    this->__ckpt_station.load_mem_area(serialize_area, serialize_area_size);
    
    // output_file.flush();
    // free(serialize_area);

    // output_file.close();
    // POS_LOG("finish dump checkpoints to %s", file_path.c_str());

    if(likely(POS_SUCCESS == this->__ckpt_station.collapse_to_image_file(file_path))){
        POS_LOG("dump checkpoints to images file: file_path(%s)", file_path.c_str());
    }
}
