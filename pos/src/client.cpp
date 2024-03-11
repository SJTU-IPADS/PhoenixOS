#pragma once

#include <iostream>
#include <map>

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
void POSClient::init_restore_resources() {
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

    POS_LOG("restoring from binary file...");

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

        POS_LOG("  => deserialized state of %lu handles for resource type %u", nb_handles, resource_type_id);
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

    POS_LOG("  => deserialized %lu of api contexts", nb_api_cxt);

    /* --------- step 3: read DAG --------- */
    // field: size of the serialized area of this dag topo
    __READ_TYPED_BINARY_AND_FWD(serialize_area_size, uint64_t, bin_ptr);
    this->dag.deserialize(bin_ptr);
    bin_ptr += serialize_area_size;

    POS_LOG("  => deserialized DAG");

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

        POS_LOG("  => restored handle tree of %lu handles for resource type %u", nb_handles, rid);
    }
    
    /* --------- step 5: recompute missing checkpoints --------- */
    // TODO:
    

    POS_LOG("restore finished");
    

    #undef  __READ_TYPED_BINARY_AND_FWD
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
