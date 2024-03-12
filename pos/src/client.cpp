#pragma once

#include <iostream>
#include <map>
#include <algorithm>

#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/handle.h"
#include "pos/include/client.h"
#include "pos/include/api_context.h"
#include "pos/include/dag.h"


/*!
 *  \brief  restore resources from checkpointed file
 */
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

        POS_LOG("    => deserialized state of %lu handles for resource type %u", nb_handles, resource_type_id);
    }
    POS_LOG("[Restore]: step 1 finished");

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

    POS_LOG("    => deserialized %lu of api contexts", nb_api_cxt);
    POS_LOG("[Restore]: step 2 finished");

    /* --------- step 3: read DAG --------- */
    // field: size of the serialized area of this dag topo
    __READ_TYPED_BINARY_AND_FWD(serialize_area_size, uint64_t, bin_ptr);
    this->dag.deserialize(bin_ptr);
    bin_ptr += serialize_area_size;

    POS_LOG("    => deserialized DAG");
     POS_LOG("[Restore]: step 3 finished");

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
                    host_ckpt_wqe_vid = handle->ckpt_bag->host_ckpt_waitlist[j].first;
                    host_ckpt_wqe_pid = handle->ckpt_bag->host_ckpt_waitlist[j].second;

                    POS_CHECK_POINTER(wqe = this->dag.get_api_cxt_by_dag_id(host_ckpt_wqe_vid));
                    temp_retval = handle->ckpt_bag->set_host_checkpoint_record({.wqe = wqe, .param_index = host_ckpt_wqe_pid});
                    POS_ASSERT(temp_retval == POS_SUCCESS);
                }
            }
        }

        POS_LOG("    => restored handle tree of %lu handles for resource type %u", nb_handles, rid);
    }
    POS_LOG("[Restore]: step 4 finished");
    
    /* --------- step 5: recompute missing checkpoints --------- */
    // check init_restore_generate_recompute_scheme
    
    #undef  __READ_TYPED_BINARY_AND_FWD
}


/*!
 *  \brief  generate recompute wqe sequence
 */
void POSClient::init_restore_generate_recompute_scheme(){
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
    version_apicxt_map_t apicxt_sequence_map;

    version_handle_pair_t target_vp;
    pos_vertex_id_t vt;
    POSHandle *ht;
    POSAPIContext_QE_t *wqe_upstream;
    std::set<uint64_t> ckpt_version_set;

    auto __is_vh_map_contains = [](version_handle_map_t& vh_map, pos_vertex_id_t version, POSHandle* handle) -> bool {
        bool retval = false;
        auto nums = vh_map.count(version);
        auto iter = vh_map.find(version);
        while(nums--){
            if(iter->second == handle){
                retval = true;
                break;
            }
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

            ckpt_set = handle->ckpt_bag->get_checkpoint_version_set();
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
                POS_LOG("checkpoint ok: client_addr(%p), vo(%lu), vg(%lu), vh(%lu)", handle->client_addr, vo, vg, vh);
            }
        }
    }

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
        for(POSHandleView_t &hv : wqe_upstream->input_handle_views){
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
             *  \note   we will skip this upstream handle, if it's been or going to be traced
             */
            if( __is_vh_map_contains(missing_vh_map, vt-1, hv.handle) || __is_vh_map_contains(tracing_vh_map, vt-1, hv.handle)){
                continue;
            }

            /*!
             *  \note   we will continue to trace upstream of this upstream handle, if it's not yet checkpointed
             */
            POS_CHECK_POINTER(hv.handle->ckpt_bag);
            ckpt_version_set = hv.handle->ckpt_bag->get_checkpoint_version_set();
            if(ckpt_version_set.count(vt-1) == 0){
                missing_vh_map.insert(version_handle_pair_t(vt-1, hv.handle));
                tracing_vh_map.insert(version_handle_pair_t(vt-1, hv.handle));
            }
        }
        for(POSHandleView_t &hv : wqe_upstream->inout_handle_views){
            POS_CHECK_POINTER(hv.handle);
            if( __is_vh_map_contains(missing_vh_map, vt-1, hv.handle) || __is_vh_map_contains(tracing_vh_map, vt-1, hv.handle)){
                continue;
            }

            POS_CHECK_POINTER(hv.handle->ckpt_bag);
            ckpt_version_set = hv.handle->ckpt_bag->get_checkpoint_version_set();
            if(ckpt_version_set.count(vt-1) == 0){
                missing_vh_map.insert(version_handle_pair_t(vt-1, hv.handle));
                tracing_vh_map.insert(version_handle_pair_t(vt-1, hv.handle));
            }
        }

        tracing_vh_map.insert(version_handle_pair_t(vt, ht));
        apicxt_sequence_map.insert(version_apicxt_pair_t(vt, wqe_upstream));
    }

    // __print_apicxt_map(apicxt_sequence_map, std::string("final kernel sequence"));

    POS_LOG("[Restore]: step 5 finished, need to recompute %lu of APIs", apicxt_sequence_map.size());
}


/*!
 *  \brief  dump checkpoints to file
 */
void POSClient::deinit_dump_checkpoints() {
    std::string file_path;
    std::ofstream output_file;

    typename std::map<pos_resource_typeid_t, void*>::iterator hm_map_iter;
    POSHandleManager<POSHandle> *hm;
    uint64_t nb_handles, nb_resource_types, i;
    POSHandle *handle;
    
    uint64_t nb_api_cxt;
    POSAPIContext_QE_t *api_cxt;

    void *serialize_area;
    uint64_t serialize_area_size;

    file_path = std::string("./") + this->_cxt.job_name + std::string("_checkpoints_") + std::to_string(this->id) + std::string(".bat");
    output_file.open(file_path.c_str(), std::ios::binary);

    POS_LOG("dumping checkpoints...");

    /* ------------------ step 1: dump handles ------------------ */
    // field: # resource type
    nb_resource_types = this->handle_managers.size();
    output_file.write((const char*)(&(nb_resource_types)), sizeof(uint64_t));

    for(hm_map_iter = this->handle_managers.begin(); hm_map_iter != handle_managers.end(); hm_map_iter++){
        POS_CHECK_POINTER(hm = (POSHandleManager<POSHandle>*)(hm_map_iter->second));
        nb_handles = hm->get_nb_handles();

        // field: resource type id
        output_file.write((const char*)(&(hm_map_iter->first)), sizeof(pos_resource_typeid_t));

        // field: # handles under this manager 
        output_file.write((const char*)(&nb_handles), sizeof(uint64_t));

        for(i=0; i<nb_handles; i++){
            POS_CHECK_POINTER(handle = hm->get_handle_by_id(i));

            if(unlikely(POS_SUCCESS != handle->serialize(&serialize_area))){
                POS_WARN_C("failed to serialize handle: client_addr(%p)", handle->client_addr);
                continue;
            }
            POS_CHECK_POINTER(serialize_area);

            serialize_area_size = handle->get_serialize_size();

            // field: size of the serialized area of this handle
            output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));

            if(likely(serialize_area_size > 0)){
                // field: serialized data
                output_file.write((const char*)(serialize_area), serialize_area_size);
            }
            output_file.flush();
            free(serialize_area);
        }
    }

    POS_LOG("    => dumped checkpoints of handles");

    /* ------------------ step 2: dump api context ------------------ */
    // field: # api context
    nb_api_cxt = this->dag.get_nb_api_cxt();
    output_file.write((const char*)(&(nb_api_cxt)), sizeof(uint64_t));

    for(i=0; i<nb_api_cxt; i++){
        POS_CHECK_POINTER(api_cxt = this->dag.get_api_cxt_by_id(i));

        /*!
         *  \note   we only dump those api context that hasn't been pruned
         */
        if(api_cxt->is_ckpt_pruned == true){
            // field: size of the serialized area of this api context
            serialize_area_size = 0;
            output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));
        } else {
            api_cxt->serialize(&serialize_area);
            POS_CHECK_POINTER(serialize_area);

            // field: size of the serialized area of this api context
            serialize_area_size = api_cxt->get_serialize_size();
            output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));
            
            // field: serialized data
            output_file.write((const char*)(serialize_area), serialize_area_size);
            
            output_file.flush();
            free(serialize_area);
        }
    }

    POS_LOG("    => dumped checkpoints of api contexts");

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
    output_file.write((const char*)(&serialize_area_size), sizeof(uint64_t));

    // field: serialized data
    output_file.write((const char*)(serialize_area), serialize_area_size);
    
    output_file.flush();
    free(serialize_area);

    POS_LOG("    => dumped checkpoints of DAG");

    output_file.close();
    POS_LOG("finish dump checkpoints to %s", file_path.c_str());
}
