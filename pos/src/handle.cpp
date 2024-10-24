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
#include <algorithm>
#include <filesystem>
#include <string>
#include <map>
#include <type_traits>
#include <stdint.h>
#include <assert.h>
#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/serializer.h"
#include "pos/include/api_context.h"
#include "pos/include/checkpoint.h"
#include "pos/include/proto/handle.pb.h"

#include "google/protobuf/port_def.inc"

pos_retval_t POSHandle::set_passthrough_addr(void *addr, POSHandle* handle_ptr){ 
    using handle_type = typename std::decay<decltype(*this)>::type;

    pos_retval_t retval = POS_SUCCESS;
    client_addr = addr;
    server_addr = addr;
    POSHandleManager<handle_type> *hm_cast = (POSHandleManager<handle_type>*)_hm;

    POS_CHECK_POINTER(hm_cast);
    POS_ASSERT(handle_ptr == this);

    // record client-side address to the map
    retval = hm_cast->record_handle_address(addr, handle_ptr);

exit:
    return retval;
}


void POSHandle::mark_status(pos_handle_status_t status){
    using handle_type = typename std::decay<decltype(*this)>::type;
    POSHandleManager<handle_type> *hm_cast = (POSHandleManager<handle_type>*)this->_hm;
    POS_CHECK_POINTER(hm_cast);
    hm_cast->mark_handle_status(this, status);
}


void POSHandle::reset_preserve_counter(){ 
    this->_state_preserve_counter.store(0); 
}


bool POSHandle::is_client_addr_in_range(void *addr, uint64_t *offset){
    bool result;

    result = ((uint64_t)client_addr <= (uint64_t)addr) && ((uint64_t)addr < (uint64_t)(client_addr)+size);

    if(result && offset != nullptr){
        *offset = (uint64_t)addr - (uint64_t)client_addr;
    }

    return result;
}


pos_retval_t POSHandle::checkpoint_sync(uint64_t version_id, std::string ckpt_dir, uint64_t stream_id) {
    return this->__commit(version_id, stream_id, /* from_cache */ false, /* is_sync */ true, ckpt_dir);
}


pos_retval_t POSHandle::checkpoint_commit(uint64_t version_id, uint64_t stream_id){ 
    pos_retval_t retval = POS_SUCCESS;
    
    #if POS_CONF_EVAL_CkptEnablePipeline == 1
        //  if the on-device cache is enabled, the cache should be added previously by checkpoint_add,
        //  and this commit process doesn't need to be sync, as no ADD could corrupt this process
        retval = this->__commit(version_id, stream_id, /* from_cache */ true, /* is_sync */ false);
    #else
        uint8_t old_counter;
        old_counter = this->_state_preserve_counter.fetch_add(1, std::memory_order_relaxed);
        if (old_counter == 0) {
            /*!
                *  \brief  [case]  no CoW on this handle yet, we directly commit this buffer
                *  \note   the on-device cache is disabled, the commit should comes from the origin buffer, and this
                *          commit must be sync, as there could have CoW waiting on this commit to be finished
                */
            retval = this->__commit(version_id, stream_id, /* from_cache */ false, /* is_sync */ true);
            this->_state_preserve_counter.store(3, std::memory_order_relaxed);
        } else if (old_counter == 1) {
            /*!
                *  \brief  [case]  there's non-finished CoW on this handle, we need to wait until the CoW finished and
                *                  commit from the new buffer
                *  \note   we commit from the cache under this hood, and the commit process is async as there's no CoW 
                *          on this handle anymore
                */
            while(this->_state_preserve_counter < 3){}
            retval = this->__commit(version_id, stream_id, /* from_cache */ true, /* is_sync */ false);
        } else {
            /*!
                *  \brief  [case]  there's finished CoW on this handle, we can directly commit from the cache
                *  \note   same as the last case
                */
            retval = this->__commit(version_id, stream_id, /* from_cache */ true, /* is_sync */ false);
        }
    #endif  // POS_CONF_EVAL_CkptEnablePipeline        
    
    return retval;
}


pos_retval_t POSHandle::checkpoint_add(uint64_t version_id, uint64_t stream_id) { 
    pos_retval_t retval = POS_SUCCESS;
    uint8_t old_counter;

    /*!
        *  \brief  [case]  the adding has been finished, nothing need to do
        */
    if(this->_state_preserve_counter >= 2){
        retval = POS_FAILED_ALREADY_EXIST;
        goto exit;
    }

    old_counter = this->_state_preserve_counter.fetch_add(1, std::memory_order_relaxed);
    if (old_counter == 0) {
        /*!
            *  \brief  [case]  no adding on this handle yet, we conduct sync on-device copy from the origin buffer
            *  \note   this process must be sync, as there could have commit process waiting on this adding to be finished
            */
        retval = this->__add(version_id, stream_id);
        this->_state_preserve_counter.store(3, std::memory_order_relaxed);
    } else if (old_counter == 1) {
        /*!
            *  \brief  [case]  there's non-finished adding on this handle, we need to wait until the adding finished
            */
        retval = POS_WARN_ABANDONED;
        while(this->_state_preserve_counter < 3){}
    }

exit:
    return retval;
}


pos_retval_t POSHandle::__persist(POSCheckpointSlot* ckpt_slot, std::string ckpt_dir, uint64_t stream_id){
    pos_retval_t retval = POS_SUCCESS, prev_retval;
    std::future<pos_retval_t> persist_future;

    POS_CHECK_POINTER(ckpt_slot);

    // no directory specified, skip persisting
    if(ckpt_dir.size() == 0){ goto exit; }

    // verify the path exists
    if(unlikely(!std::filesystem::exists(ckpt_dir))){
        POS_WARN_C(
            "failed to persist checkpoint, no ckpt directory exists, this is a bug: ckpt_dir(%s)",
            ckpt_dir.c_str()
        );
        retval = POS_FAILED_NOT_EXIST;
        goto exit;
    }

    // collect previous persisting thread if any
    if(this->_persist_thread != nullptr){
        if(unlikely(POS_SUCCESS != (prev_retval = this->sync_persist()))){
            POS_WARN_C("pervious persisting is failed: retval(%u)", prev_retval);
        }
    }

    this->_persist_promise = new std::promise<pos_retval_t>;
    POS_CHECK_POINTER(this->_persist_promise);

    // persist asynchronously
    this->_persist_thread = new std::thread(
        [](POSHandle* handle, POSCheckpointSlot* ckpt_slot, std::string ckpt_dir, uint64_t stream_id){
            pos_retval_t retval = handle->__persist_async_thread(ckpt_slot, ckpt_dir, stream_id);
            handle->_persist_promise->set_value(retval);
        },
        this, ckpt_slot, ckpt_dir, stream_id
    );
    POS_CHECK_POINTER(this->_persist_thread);

exit:
    return retval;
}


pos_retval_t POSHandle::sync_persist(){
    pos_retval_t retval = POS_SUCCESS;
    std::future<pos_retval_t> persist_future;

    if(this->_persist_thread != nullptr){
        POS_ASSERT(this->_persist_promise != nullptr);
        persist_future = this->_persist_promise->get_future();
        persist_future.wait();
        retval = persist_future.get();

        // ref: https://en.cppreference.com/w/cpp/thread/thread/%7Ethread
        if(this->_persist_thread->joinable()){
            this->_persist_thread->join();
        }

        delete this->_persist_thread;
        this->_persist_thread = nullptr;
        delete this->_persist_promise;
        this->_persist_promise = nullptr;
    } else {
        retval = POS_FAILED_NOT_EXIST;
    }

exit:
    return retval;
}


pos_retval_t POSHandle::__persist_async_thread(POSCheckpointSlot* ckpt_slot, std::string ckpt_dir, uint64_t stream_id){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t i;
    std::string ckpt_file_path;
    std::ofstream ckpt_file_stream;
    google::protobuf::Message *handle_binary = nullptr, *_base_binary = nullptr;
    pos_protobuf::Bin_POSHanlde *base_binary = nullptr;

    // TODO: we must ensure the ckpt_slot won't be released until this ckpt ends!
    //      we haven't do that!
    POS_CHECK_POINTER(ckpt_slot);
    POS_ASSERT(std::filesystem::exists(ckpt_dir));

    if(unlikely(POS_SUCCESS != (
        retval = this->__sync_stream(stream_id)
    ))){
        POS_WARN_C(
            "failed to sync checkpoint commit stream before persisting: server_addr(%p), retval(%u)",
            this->server_addr, retval
        );
        goto exit;
    }

    if(unlikely(POS_SUCCESS != (
        retval = this->__generate_protobuf_binary(&handle_binary, &_base_binary)
    ))){
        POS_WARN_C("failed to generate protobuf binary: server_addr(%p), retval(%u)",
            this->server_addr, retval
        );
        goto exit;
    }
    POS_CHECK_POINTER(handle_binary);
    POS_CHECK_POINTER(base_binary = reinterpret_cast<pos_protobuf::Bin_POSHanlde*>(_base_binary));

    // base fields
    base_binary->set_id(this->id);
    base_binary->set_resource_type_id(this->resource_type_id);
    base_binary->set_client_addr((uint64_t)(this->client_addr));
    base_binary->set_server_addr((uint64_t)(this->server_addr));
    base_binary->set_size(this->size);

    // parent information
    base_binary->set_nb_parent_handles(parent_handles.size());
    for(i=0; i<parent_handles.size(); i++){
        POS_CHECK_POINTER(this->parent_handles[i]);
        base_binary->add_parent_handle_resource_type_idx(this->parent_handles[i]->resource_type_id);
        base_binary->add_parent_handle_idx(this->parent_handles[i]->id);
    }

    // state
    base_binary->set_state_size(this->state_size);
    if(unlikely(this->state_size > 0 && ckpt_slot == nullptr)){
        POS_WARN_C("serialize stateful handle without providing checkpoint slot");
        retval = POS_FAILED_INVALID_INPUT;
        goto exit;
    } else if(ckpt_slot != nullptr){
        base_binary->set_state(reinterpret_cast<const char*>(ckpt_slot->expose_pointer()), this->state_size);
    }

    // form the path to the checkpoint file of this handle
    ckpt_file_path = ckpt_dir 
                    + std::string("/h-")
                    + std::to_string(this->resource_type_id) 
                    + std::string("-")
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
    if(!handle_binary->SerializeToOstream(&ckpt_file_stream)){
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


pos_retval_t POSHandle::restore() {
    using handle_type = typename std::decay<decltype(*this)>::type;

    pos_retval_t retval;
    POSHandleManager<handle_type> *hm_cast = (POSHandleManager<handle_type>*)this->_hm;

    #if POS_CONF_EVAL_RstEnableContextPool == 1
        retval = hm_cast->try_restore_from_pool(this);
        if(likely(retval == POS_SUCCESS)){
            goto exit;
        }
    #endif // POS_CONF_EVAL_RstEnableContextPool

    retval = this->__restore(); 

exit:
    return retval;
}


pos_retval_t POSHandle::reload_state(uint64_t stream_id){
    pos_retval_t retval = POS_FAILED_NOT_EXIST;
    uint64_t on_device_dumped_version = 0, host_dumped_version = 0, final_dumped_version = 0;
    std::set<uint64_t> ckpt_set;
    POSCheckpointSlot *ckpt_slot = nullptr;

    uint64_t i;
    std::vector<pos_host_ckpt_t> records;
    void *data;

    POS_ASSERT(this->state_size > 0);
    POS_CHECK_POINTER(this->ckpt_bag);
    
    if(unlikely(this->status != kPOS_HandleStatus_Active)){
        POS_WARN(
            "failed to reload handle state as the handle isn't active yet: server_addr(%p), status(%d)",
            this->server_addr, this->status
        );
        retval = POS_FAILED;
        goto exit;
    }

    // compare on-device-dumped and host-dumped version
    ckpt_set = this->ckpt_bag->get_checkpoint_version_set<kPOS_CkptSlotPosition_Host>();
    if(ckpt_set.size() > 0){
        host_dumped_version = ( *(ckpt_set.rbegin()) );
    }
    ckpt_set = this->ckpt_bag->get_checkpoint_version_set<kPOS_CkptSlotPosition_Device>();
    if(ckpt_set.size() > 0){
        on_device_dumped_version = ( *(ckpt_set.rbegin()) );
    }
    
    if(host_dumped_version == 0 && on_device_dumped_version == 0){
        /*!
         *  \note   [option 1]  nothing have been dumped, reload from host origin,
                                try reload from origin host value in order
         */
        records = this->ckpt_bag->get_host_checkpoint_records();
        for(i=0; i<records.size(); i++){
            pos_host_ckpt_t &record = records[i];
            POS_CHECK_POINTER(record.wqe);
            if(unlikely(POS_SUCCESS != this->__reload_state(
                    /* data */ pos_api_param_addr(record.wqe, record.param_index),
                    /* offset */ record.offset,
                    /* size */ record.size,
                    /* stream_id */ stream_id,
                    /* on_device */ false
            ))){
                POS_WARN_DETAIL(
                    "failed to reload state from origin host value: "
                    "server_addr(%p), host_record_id(%lu), offset(%lu), size(%lu)",
                    this->server_addr, i, record.offset, record.size
                );
                retval = POS_FAILED;
            } else {
                retval = POS_SUCCESS;
            }
        }
    } else {
        /*!
         *  \note   [option 2]  reload from dumped result
         */
        final_dumped_version = host_dumped_version > on_device_dumped_version ? host_dumped_version : on_device_dumped_version;
        if(host_dumped_version > on_device_dumped_version){
            if(unlikely(POS_SUCCESS != this->ckpt_bag->get_checkpoint_slot<kPOS_CkptSlotPosition_Host>(&ckpt_slot, final_dumped_version))){
                POS_ERROR_C_DETAIL("failed to obtain ckpt slot during reload, this is a bug");
            }
            POS_CHECK_POINTER(ckpt_slot);
        } else {
            if(unlikely(POS_SUCCESS != this->ckpt_bag->get_checkpoint_slot<kPOS_CkptSlotPosition_Device>(&ckpt_slot, final_dumped_version))){
                POS_ERROR_C_DETAIL("failed to obtain ckpt slot during reload, this is a bug");
            }
            POS_CHECK_POINTER(ckpt_slot);
        }

        if(unlikely(POS_SUCCESS != this->__reload_state(
            /* data */ ckpt_slot->expose_pointer(),
            /* offset */ 0,
            /* size */ this->state_size,
            /* stream_id */ stream_id,
            /* on_device */ on_device_dumped_version >= host_dumped_version
        ))){
            POS_WARN_DETAIL(
                "failed to reload state from dumpped value: "
                "server_addr(%p), version_id(%lu)",
                this->server_addr, final_dumped_version
            );
            retval = POS_FAILED;
        } else {
            retval = POS_SUCCESS;
        }
    }

exit:
    return retval;
}


void POSHandle::collect_broken_handles(pos_broken_handle_list_t *broken_handle_list, uint16_t layer_id){
    uint64_t i;

    POS_CHECK_POINTER(broken_handle_list);

    // insert itself to the nonactive_handles map if itsn't active
    if(unlikely(status != kPOS_HandleStatus_Active && status != kPOS_HandleStatus_Delete_Pending)){
        broken_handle_list->add_handle(layer_id, this);
    }
    
    // iterate over its parent
    for(i=0; i<parent_handles.size(); i++){
        parent_handles[i]->collect_broken_handles(broken_handle_list, layer_id+1);
    }
}


pos_retval_t POSHandle::serialize(void** serialized_area){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t basic_field_size;
    void *ptr;

    POS_CHECK_POINTER(serialized_area);

    *serialized_area = malloc(this->get_serialize_size());
    POS_CHECK_POINTER(*serialized_area);
    ptr = *serialized_area;

    // part 1: size of the basic field
    basic_field_size = this->__get_basic_serialize_size();
    POSUtil_Serializer::write_field(&ptr, &(basic_field_size), sizeof(uint64_t));

    // part 2: basic field
    retval = this->__serialize_basic(ptr);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to serialize basic fields of handle");
        goto exit;
    }
    ptr += basic_field_size;

    // part 3: extra field
    retval = this->__serialize_extra(ptr);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to serialize extra fields of handle");
        goto exit;
    }
    
exit:
    return retval;
}


pos_retval_t POSHandle::deserialize(void* raw_area){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t basic_field_size;
    void *ptr = raw_area;

    POS_CHECK_POINTER(ptr);

    // part 1: size of the basic field
    POSUtil_Deserializer::read_field(&(basic_field_size), &ptr, sizeof(uint64_t));

    // part 2: basic field
    retval = this->__deserialize_basic(ptr);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to deserialize basic fields of handle");
        goto exit;
    }
    ptr += basic_field_size;

    // part 3: extra field
    retval = this->__deserialize_extra(ptr);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to deserialize extra fields of handle");
        goto exit;
    }

exit:
    return retval;
}


uint64_t POSHandle::__get_basic_serialize_size(){
    pos_retval_t tmp_retval;
    void *ckpt_data;
    uint64_t ckpt_version;

    std::set<uint64_t> ckpt_version_set;
    uint64_t ckpt_serialization_size;

    std::vector<pos_host_ckpt_t> host_ckpt_records;
    uint64_t host_ckpt_serialization_size;


    if(state_size == 0){
        /*!
            *  \note   for non-stateful handle, it's easy to determine the size of the basic serialized fields
            */
        return (
            /* resource_type_id */          sizeof(pos_resource_typeid_t)
            /* client_addr */               + sizeof(uint64_t)
            /* server_addr */               + sizeof(uint64_t)
            /* nb_parent_handle */          + sizeof(uint64_t)
            /* parent_handle_indices */     + parent_handles.size() * (sizeof(pos_resource_typeid_t) + sizeof(pos_u64id_t))
            /* id */                        + sizeof(pos_u64id_t)
            /* size */                      + sizeof(uint64_t)
            /* state_size */                + sizeof(uint64_t)
            /* is_lastest_used_handle */    + sizeof(bool)
        );
    } else {
        /*!
         *  \note   for stateful handle, the size of the basic serialized fields is influenced by checkpoint
         */
        ckpt_version_set = this->ckpt_bag->get_checkpoint_version_set<kPOS_CkptSlotPosition_Host>();
        ckpt_serialization_size = ckpt_version_set.size() * (sizeof(uint64_t) + state_size);

        host_ckpt_records = this->ckpt_bag->get_host_checkpoint_records();
        host_ckpt_serialization_size = host_ckpt_records.size() * (sizeof(pos_u64id_t) + sizeof(uint32_t) + sizeof(uint64_t) + sizeof(uint64_t));

        return (
            /* resource_type_id */          sizeof(pos_resource_typeid_t)
            /* client_addr */               + sizeof(uint64_t)
            /* server_addr */               + sizeof(uint64_t)
            /* nb_parent_handle */          + sizeof(uint64_t)
            /* parent_handle_indices */     + parent_handles.size() * (sizeof(pos_resource_typeid_t) + sizeof(pos_u64id_t))
            /* id */                        + sizeof(pos_u64id_t)
            /* size */                      + sizeof(uint64_t)
            /* state_size */                + sizeof(uint64_t)
            /* is_lastest_used_handle */    + sizeof(bool) 

            /* nb ckpt version */           + sizeof(uint64_t)
            /* ckpt_version + data */       + ckpt_serialization_size

            /* nb host-side ckpt */         + sizeof(uint64_t)
            /* host-side ckpt records */    + host_ckpt_serialization_size
        );
    }
}


pos_retval_t POSHandle::__serialize_basic(void* serialized_area){
    pos_retval_t retval = POS_SUCCESS;
    void *ptr = serialized_area;

    uint64_t nb_parent_handles;

    POSCheckpointSlot *ckpt_slot;
    uint64_t ckpt_version, nb_ckpt_version;
    std::set<uint64_t> ckpt_version_set;
    typename std::set<uint64_t>::iterator set_iter;

    std::vector<pos_host_ckpt_t> host_ckpt_records;
    uint64_t i, nb_host_ckpt, host_ckpt_serialization_size;

    POSHandle *latest_used_handle;

    POS_CHECK_POINTER(ptr);
    
    nb_parent_handles = this->parent_handles.size();

    POSUtil_Serializer::write_field(&ptr, &(this->resource_type_id), sizeof(pos_resource_typeid_t));
    POSUtil_Serializer::write_field(&ptr, &(this->client_addr), sizeof(uint64_t));
    POSUtil_Serializer::write_field(&ptr, &(this->server_addr), sizeof(uint64_t));
    POSUtil_Serializer::write_field(&ptr, &(nb_parent_handles), sizeof(uint64_t));
    for(auto& parent_handle : this->parent_handles){
        POSUtil_Serializer::write_field(&ptr, &(parent_handle->resource_type_id), sizeof(pos_resource_typeid_t));
        POSUtil_Serializer::write_field(&ptr, &(parent_handle->id), sizeof(pos_u64id_t));
    }
    POSUtil_Serializer::write_field(&ptr, &(this->id), sizeof(pos_u64id_t));
    POSUtil_Serializer::write_field(&ptr, &(this->size), sizeof(uint64_t));
    POSUtil_Serializer::write_field(&ptr, &(this->state_size), sizeof(uint64_t));

    latest_used_handle = ((POSHandleManager<POSHandle>*)(this->_hm))->latest_used_handle;
    if(latest_used_handle != nullptr){
        this->is_lastest_used_handle = latest_used_handle == this ? true : false;
    } else {
        this->is_lastest_used_handle = false;
    }
    POSUtil_Serializer::write_field(&ptr, &(this->is_lastest_used_handle), sizeof(bool));

    // we only serialize checkpoint for stateful resource
    if(state_size > 0){
        POS_CHECK_POINTER(this->ckpt_bag);

        // first part: XPU-side checkpoint
        ckpt_version_set = this->ckpt_bag->get_checkpoint_version_set<kPOS_CkptSlotPosition_Host>();
        nb_ckpt_version = ckpt_version_set.size();
        POSUtil_Serializer::write_field(&ptr, &nb_ckpt_version, sizeof(uint64_t));

        for(set_iter = ckpt_version_set.begin(); set_iter != ckpt_version_set.end(); set_iter++){
            ckpt_version = *set_iter;
            retval =  this->ckpt_bag->get_checkpoint_slot<kPOS_CkptSlotPosition_Host>(&ckpt_slot, ckpt_version);
            if(unlikely(retval != POS_SUCCESS)){
                POS_ERROR_C(
                    "failed to obtain checkpoint by version within the version set, this's a bug: client_addr(%p), version(%lu)",
                    this->client_addr, ckpt_version
                );
            }
            POS_CHECK_POINTER(ckpt_slot);
            POSUtil_Serializer::write_field(&ptr, &ckpt_version, sizeof(uint64_t));
            POSUtil_Serializer::write_field(&ptr, ckpt_slot->expose_pointer(), state_size);
        }

        // second part: host-side checkpoint record
        host_ckpt_records = this->ckpt_bag->get_host_checkpoint_records();
        nb_host_ckpt = host_ckpt_records.size();
        POSUtil_Serializer::write_field(&ptr, &(nb_host_ckpt), sizeof(uint64_t));
        for(i=0; i<nb_host_ckpt; i++){
            POSUtil_Serializer::write_field(&ptr, &(host_ckpt_records[i].wqe->id), sizeof(pos_u64id_t));
            POSUtil_Serializer::write_field(&ptr, &(host_ckpt_records[i].param_index), sizeof(uint32_t));
            POSUtil_Serializer::write_field(&ptr, &(host_ckpt_records[i].offset), sizeof(uint64_t));
            POSUtil_Serializer::write_field(&ptr, &(host_ckpt_records[i].size), sizeof(uint64_t));
        }
    }

exit:
    return retval;
}


pos_retval_t POSHandle::__deserialize_basic(void* raw_data){
    pos_retval_t retval = POS_SUCCESS, tmp_retval;

    uint64_t i;
    uint64_t _nb_parent_handles;
    pos_resource_typeid_t parent_resource_id;
    pos_u64id_t parent_handle_id;
    uint64_t nb_ckpt_version, ckpt_version;
    uint64_t nb_host_ckpt, host_ckpt_offset, host_ckpt_size;
    uint32_t param_id;
    pos_u64id_t wqe_apicxt_id;

    void *ptr = raw_data;
    POS_CHECK_POINTER(ptr);

    POSUtil_Deserializer::read_field(&(this->resource_type_id), &ptr, sizeof(pos_resource_typeid_t));

    POSUtil_Deserializer::read_field(&(this->client_addr), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&(this->server_addr), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&_nb_parent_handles, &ptr, sizeof(uint64_t));

    for(i=0; i<_nb_parent_handles; i++){
        POSUtil_Deserializer::read_field(&parent_resource_id, &ptr, sizeof(pos_resource_typeid_t));
        POSUtil_Deserializer::read_field(&parent_handle_id, &ptr, sizeof(pos_u64id_t));
        this->parent_handles_waitlist.push_back(
            std::pair<pos_resource_typeid_t, pos_u64id_t>(parent_resource_id, parent_handle_id)
        );
    }

    POSUtil_Deserializer::read_field(&(this->id), &ptr, sizeof(pos_u64id_t));
    POSUtil_Deserializer::read_field(&(this->size), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&(this->state_size), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&(this->is_lastest_used_handle), &ptr, sizeof(bool));

    if(this->state_size > 0){
        if(unlikely(POS_SUCCESS != this->__init_ckpt_bag())){
            POS_ERROR_C_DETAIL("failed to inilialize checkpoint bag");
        }
        POS_CHECK_POINTER(this->ckpt_bag);

        // first part: XPU-side checkpoint
        POSUtil_Deserializer::read_field(&nb_ckpt_version, &ptr, sizeof(uint64_t));
        for(i=0; i<nb_ckpt_version; i++){
            POSUtil_Deserializer::read_field(&ckpt_version, &ptr, sizeof(uint64_t));
            tmp_retval = this->ckpt_bag->load(ckpt_version, ptr);
            if(unlikely(tmp_retval != POS_SUCCESS)){
                POS_ERROR_C(
                    "failed to load checkpoint while restoring: client_addr(%p), version(%lu)",
                    this->client_addr, ckpt_version
                );
            }

            ptr += this->state_size;
        }

        // second part: host-side checkpoint record
        POSUtil_Deserializer::read_field(&nb_host_ckpt, &ptr, sizeof(uint64_t));
        for(i=0; i<nb_host_ckpt; i++){
            POSUtil_Deserializer::read_field(&wqe_apicxt_id, &ptr, sizeof(pos_u64id_t));
            POSUtil_Deserializer::read_field(&param_id, &ptr, sizeof(uint32_t));
            POSUtil_Deserializer::read_field(&host_ckpt_offset, &ptr, sizeof(uint64_t));
            POSUtil_Deserializer::read_field(&host_ckpt_size, &ptr, sizeof(uint64_t));
            this->ckpt_bag->host_ckpt_waitlist.push_back(
                std::tuple<pos_u64id_t, uint32_t, uint64_t, uint64_t>(wqe_apicxt_id, param_id, host_ckpt_offset, host_ckpt_size)
            );
        }
    }

exit:
    return retval;
}
