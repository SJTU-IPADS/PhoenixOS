#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <type_traits>

#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/bipartite_graph.h"
#include "pos/include/utils/serializer.h"
#include "pos/include/api_context.h"
#include "pos/include/checkpoint.h"

/*!
 *  \brief  setting both the client-side and server-side address of the handle 
 *          after finishing allocation
 *  \param  addr        the setting address of the handle
 *  \param  handle_ptr  pointer to current handle
 *  \return POS_SUCCESS for successfully setting
 *          POS_FAILED_ALREADY_EXIST for duplication failed;
 */
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


/*!
 *  \brief  mark the status of this handle
 *  \param  status the status to mark
 *  \note   this function would call the inner function within the corresponding handle manager
 */
void POSHandle::mark_status(pos_handle_status_t status){
    using handle_type = typename std::decay<decltype(*this)>::type;
    POSHandleManager<handle_type> *hm_cast = (POSHandleManager<handle_type>*)this->_hm;
    POS_CHECK_POINTER(hm_cast);
    hm_cast->mark_handle_status(this, status);
}


/*!
 *  \brief  collect all broken handles along the handle trees
 *  \note   this function will call recursively, aware of performance issue!
 *  \param  broken_handle_list  list of broken handles, 
 *  \param  layer_id            index of the layer at this call
 */
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


/*!
 *  \brief  serialize the state of current handle into the binary area
 *  \param  serialized_area  pointer to the binary area
 *  \return POS_SUCCESS for successfully serilization
 */
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


/*!
 *  \brief  deserialize the state of current handle from binary area
 *  \param  raw_area    raw data area
 *  \return POS_SUCCESS for successfully serialization
 */
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


/*!
 *  \brief  obtain the serilization size of basic fields of POSHandle
 *  \return the serilization size of basic fields of POSHandle
 */
uint64_t POSHandle::__get_basic_serialize_size(){
    pos_retval_t tmp_retval;
    void *ckpt_data;
    uint64_t ckpt_version, ckpt_size;

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
            /* parent_handle_indices */     + parent_handles.size() * (sizeof(pos_resource_typeid_t) + sizeof(pos_vertex_id_t))
            /* dag_vertex_id */             + sizeof(pos_vertex_id_t)
            /* size */                      + sizeof(uint64_t)
            /* state_size */                + sizeof(uint64_t)
            /* is_lastest_used_handle */    + sizeof(bool)
        );
    } else {
        /*!
            *  \note   for stateful handle, the size of the basic serialized fields is influenced by checkpoint
            */
        ckpt_version_set = this->ckpt_bag->get_checkpoint_version_set();
        ckpt_serialization_size = ckpt_version_set.size() * (sizeof(uint64_t) + state_size);

        host_ckpt_records = this->ckpt_bag->get_host_checkpoint_records();
        host_ckpt_serialization_size = host_ckpt_records.size() * (sizeof(pos_vertex_id_t) + sizeof(uint32_t));

        return (
            /* resource_type_id */          sizeof(pos_resource_typeid_t)
            /* client_addr */               + sizeof(uint64_t)
            /* server_addr */               + sizeof(uint64_t)
            /* nb_parent_handle */          + sizeof(uint64_t)
            /* parent_handle_indices */     + parent_handles.size() * (sizeof(pos_resource_typeid_t) + sizeof(pos_vertex_id_t))
            /* dag_vertex_id */             + sizeof(pos_vertex_id_t)
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


/*!
 *  \brief  serialize the basic state of current handle into the binary area
 *  \param  serialized_area  pointer to the binary area
 *  \return POS_SUCCESS for successfully serilization
 */
pos_retval_t POSHandle::__serialize_basic(void* serialized_area){
    pos_retval_t retval = POS_SUCCESS;
    void *ptr = serialized_area;

    uint64_t nb_parent_handles;

    POSCheckpointSlot *ckpt_slot;
    uint64_t ckpt_version, ckpt_size, nb_ckpt_version;
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
        POSUtil_Serializer::write_field(&ptr, &(parent_handle->dag_vertex_id), sizeof(pos_vertex_id_t));
    }
    POSUtil_Serializer::write_field(&ptr, &(this->dag_vertex_id), sizeof(pos_vertex_id_t));
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
        ckpt_version_set = this->ckpt_bag->get_checkpoint_version_set();
        nb_ckpt_version = ckpt_version_set.size();
        POSUtil_Serializer::write_field(&ptr, &nb_ckpt_version, sizeof(uint64_t));

        for(set_iter = ckpt_version_set.begin(); set_iter != ckpt_version_set.end(); set_iter++){
            ckpt_version = *set_iter;
            retval =  this->ckpt_bag->get_checkpoint_slot</* on_device */ false>(&ckpt_slot, ckpt_size, ckpt_version);
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
            POSUtil_Serializer::write_field(&ptr, &(host_ckpt_records[i].wqe->dag_vertex_id), sizeof(pos_vertex_id_t));
            POSUtil_Serializer::write_field(&ptr, &(host_ckpt_records[i].param_index), sizeof(uint32_t));
        }
    }

exit:
    return retval;
}


/*!
 *  \brief  deserialize basic field of this handle
 *  \param  raw_data    raw data area that store the serialized data
 *  \return POS_SUCCESS for successfully deserialize
 */
pos_retval_t POSHandle::__deserialize_basic(void* raw_data){
    pos_retval_t retval = POS_SUCCESS, tmp_retval;

    uint64_t i;
    uint64_t _nb_parent_handles;
    pos_resource_typeid_t parent_resource_id;
    pos_vertex_id_t parent_handle_dag_id;
    uint64_t nb_ckpt_version, ckpt_version;
    uint64_t nb_host_ckpt, param_id;
    pos_vertex_id_t wqe_dag_id;

    void *ptr = raw_data;
    POS_CHECK_POINTER(ptr);

    POSUtil_Deserializer::read_field(&(this->resource_type_id), &ptr, sizeof(pos_resource_typeid_t));

    POSUtil_Deserializer::read_field(&(this->client_addr), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&(this->server_addr), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&_nb_parent_handles, &ptr, sizeof(uint64_t));

    for(i=0; i<_nb_parent_handles; i++){
        POSUtil_Deserializer::read_field(&parent_resource_id, &ptr, sizeof(pos_resource_typeid_t));
        POSUtil_Deserializer::read_field(&parent_handle_dag_id, &ptr, sizeof(pos_vertex_id_t));
        this->parent_handles_waitlist.push_back(
            std::pair<pos_resource_typeid_t, pos_vertex_id_t>(parent_resource_id, parent_handle_dag_id)
        );
    }

    POSUtil_Deserializer::read_field(&(this->dag_vertex_id), &ptr, sizeof(pos_vertex_id_t));
    POSUtil_Deserializer::read_field(&(this->size), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&(this->state_size), &ptr, sizeof(uint64_t));
    POSUtil_Deserializer::read_field(&(this->is_lastest_used_handle), &ptr, sizeof(bool));

    if(this->state_size > 0){
        if(unlikely(POS_SUCCESS != this->init_ckpt_bag())){
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
            POSUtil_Deserializer::read_field(&wqe_dag_id, &ptr, sizeof(pos_vertex_id_t));
            POSUtil_Deserializer::read_field(&param_id, &ptr, sizeof(uint32_t));
            this->ckpt_bag->host_ckpt_waitlist.push_back(std::pair<pos_vertex_id_t, uint32_t>(wqe_dag_id, param_id));
        }
    }

exit:
    return retval;
}
