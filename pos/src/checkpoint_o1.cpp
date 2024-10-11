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
#include <set>
#include <map>
#include <unordered_map>

#include <stdint.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/api_context.h"
#include "pos/include/checkpoint.h"
#include "pos/include/utils/timestamp.h"


POSCheckpointBag::POSCheckpointBag(
    uint64_t state_size,
    pos_custom_ckpt_allocate_func_t allocator,
    pos_custom_ckpt_deallocate_func_t deallocator,
    pos_custom_ckpt_allocate_func_t dev_allocator,
    pos_custom_ckpt_deallocate_func_t dev_deallocator
)  : is_latest_ckpt_finished(false) {
    this->_state_size = state_size;
    this->_allocate_func = allocator;
    this->_deallocate_func = deallocator;
    this->_dev_allocate_func = dev_allocator;
    this->_dev_deallocate_func = dev_deallocator;

    // apply font and back checkpoint slot
    if(allocator != nullptr && deallocator != nullptr){
        _ckpt_front = new POSCheckpointSlot(_state_size, allocator, deallocator);
        POS_CHECK_POINTER(_ckpt_front);
        _ckpt_back = new POSCheckpointSlot(_state_size, allocator, deallocator);
        POS_CHECK_POINTER(_ckpt_back);
    }

    _front_version = 0;
    _back_version = 0;
}


/*!
 *  \brief  clear current checkpoint bag
 */
void POSCheckpointBag::clear(){
    _use_front = true;
    _front_version = 0;
    _back_version = 0;
}

/*!
 *  \brief  allocate a new checkpoint slot inside this bag
 *  \tparam on_device           whether to apply the slot on the device
 *  \param  version             version (i.e., dag index) of this checkpoint
 *  \param  ptr                 pointer to the checkpoint slot
 *  \param  force_overwrite     force to overwrite the oldest checkpoint to save allocation time
 *                              (if no available slot exist)
 *  \return POS_SUCCESS for successfully allocation
 */
template<bool on_device>
pos_retval_t POSCheckpointBag::apply_checkpoint_slot(uint64_t version, POSCheckpointSlot** ptr, bool force_overwrite){
    pos_retval_t retval = POS_SUCCESS;

    POS_CHECK_POINTER(ptr);
    
    if(_use_front){
        _front_version = version;
        *ptr = _ckpt_front;
        _use_front = false;
    } else {
        _back_version = version;
        *ptr = _ckpt_back;
        _use_front = true;
    }

exit:
    return retval;
}
template pos_retval_t POSCheckpointBag::apply_checkpoint_slot<false>(uint64_t version, POSCheckpointSlot** ptr, bool force_overwrite);

/*!
 *  \brief  obtain checkpointed data by given checkpoint version
 *  \tparam on_device   whether to apply the slot on the device
 *  \param  ckpt_slot   pointer to the checkpoint slot if successfully obtained
 *  \param  version     the specified version
 *  \return POS_SUCCESS for successfully obtained
 *          POS_FAILED_NOT_EXIST for no checkpoint is found
 */
template<bool on_device>
pos_retval_t POSCheckpointBag::get_checkpoint_slot(POSCheckpointSlot** ckpt_slot, uint64_t version){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t version_to_check;
    bool _has_record;

    // check whether this bag has record
    _has_record = (_front_version != 0) || (_back_version != 0);
    if(unlikely(_has_record == false)){
        retval = POS_FAILED_NOT_READY;
        goto exit;
    }

    version_to_check = _use_front ? _back_version : _front_version;
    if(unlikely(version_to_check != version)){
        retval = POS_FAILED_NOT_READY;
        *ckpt_slot = nullptr;
    } else {
        *ckpt_slot = _use_front ? _ckpt_back : _ckpt_front;
    }
    
exit:
    return retval;
}
template pos_retval_t POSCheckpointBag::get_checkpoint_slot<true>(POSCheckpointSlot** ckpt_slot, uint64_t version); /* for migration */
template pos_retval_t POSCheckpointBag::get_checkpoint_slot<false>(POSCheckpointSlot** ckpt_slot, uint64_t version);


/*!
 *  \brief  obtain the number of recorded checkpoints inside this bag
 *  \tparam on_device   whether the slot to be applied is on the device
 *  \return number of recorded checkpoints
 */
template<bool on_device>
uint64_t POSCheckpointBag::get_nb_checkpoint_slots(){
    return 1;
}
template uint64_t POSCheckpointBag::get_nb_checkpoint_slots<false>();


/*!
 *  \brief  obtain the checkpoint version list
 *  \tparam on_device   whether the slot to be applied is on the device
 *  \return the checkpoint version list
 */
template<bool on_device>
std::set<uint64_t> POSCheckpointBag::get_checkpoint_version_set(){
     bool _has_record;

    // check whether this bag has record
    _has_record = (_front_version != 0) || (_back_version != 0);

    if(unlikely(_has_record == false)){
        return std::set<uint64_t>();
    } else {
        return _use_front ? std::set<uint64_t>({_back_version}) : std::set<uint64_t>({_front_version});
    }
}
template std::set<uint64_t> POSCheckpointBag::get_checkpoint_version_set<true>();   /* for migration */
template std::set<uint64_t> POSCheckpointBag::get_checkpoint_version_set<false>();

/*!
 *  \brief  obtain overall memory consumption of this checkpoint bag
 *  \return overall memory consumption of this checkpoint bag
 */
uint64_t POSCheckpointBag::get_memory_consumption(){
    return 2 * _state_size;
}

/*!
 *  \brief  invalidate the checkpoint from this bag
 *  \tparam on_device   whether to apply the slot on the device
 *  \param  version version of the checkpoint to be removed
 *  \return POS_SUCCESS for successfully invalidate
 *          POS_NOT_READY for no checkpoint had been record
 */
template<bool on_device>
pos_retval_t POSCheckpointBag::invalidate_by_version(uint64_t version) {
    pos_retval_t retval = POS_SUCCESS;
    POSCheckpointSlot *slot;

    // check whether checkpoint exit
    retval = get_checkpoint_slot<on_device>(&slot, version);
    if(POS_SUCCESS != retval){
        goto exit;
    }

    // invalidate checkpoint by reset its version
    if(_use_front){
        POS_ASSERT(version == _back_version);
        _back_version = 0;
    } else { // _use_front == false
        POS_ASSERT(version == _front_version);
        _front_version = 0;
    }

exit:
    return retval;
}
template pos_retval_t POSCheckpointBag::invalidate_by_version<false>(uint64_t version);


/*!
 *  \brief  invalidate all checkpoint from this bag
 *  \tparam on_device   whether the checkpoints are on the device
 *  \return POS_SUCCESS for successfully invalidate
 *          POS_NOT_READY for no checkpoint had been record
 */
template<bool on_device>
pos_retval_t POSCheckpointBag::invalidate_all_version(){
    pos_retval_t retval = POS_SUCCESS;
    std::set<uint64_t> version_set;
    typename std::set<uint64_t>::iterator version_set_iter;

    version_set = this->get_checkpoint_version_set<on_device>();
    for(version_set_iter = version_set.begin(); version_set_iter != version_set.end(); version_set_iter++){
        retval = this->invalidate_by_version<on_device>(*version_set_iter);
        if(unlikely(retval != POS_SUCCESS)){
            goto exit;
        }
    }
    
exit:
    return retval;
}
template pos_retval_t POSCheckpointBag::invalidate_all_version<false>();


/*!
 *  \brief  load binary checkpoint data into this bag
 *  \note   this function will be invoked during the restore process
 *  \param  version     version of this checkpoint
 *  \param  ckpt_data   pointer to the buffer that stores the checkpointed data
 *  \return POS_SUCCESS for successfully loading
 */
pos_retval_t POSCheckpointBag::load(uint64_t version, void* ckpt_data){
    pos_retval_t retval = POS_SUCCESS;
    POSCheckpointSlot *ckpt_slot;

    POS_CHECK_POINTER(ckpt_data);

    retval = apply_checkpoint_slot</* on_device */false>(version, &ckpt_slot, /* force_overwrite */ false);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to apply new checkpoiont slot while loading in restore: version(%lu)", version);
        goto exit;
    }
    POS_CHECK_POINTER(ckpt_slot);

    memcpy(ckpt_slot->expose_pointer(), ckpt_data, this->_state_size);

exit:
    return retval;
}

/*!
 *  \brief  record a new host-side checkpoint of this bag
 *  \note   this function is invoked within parser thread
 *  \param  ckpt    host-side checkpoint record
 *  \return POS_SUCCESS for successfully recorded
 *          POS_FAILED_ALREADY_EXIST for duplicated version
 */
pos_retval_t POSCheckpointBag::set_host_checkpoint_record(pos_host_ckpt_t ckpt){
    pos_retval_t retval = POS_SUCCESS;

    POS_CHECK_POINTER(ckpt.wqe);
    if(unlikely(_host_ckpt_map.count(ckpt.wqe->dag_vertex_id) > 0)){
        retval = POS_FAILED_ALREADY_EXIST;
    } else {
        _host_ckpt_map.insert(
            std::pair<uint64_t, pos_host_ckpt_t>(ckpt.wqe->dag_vertex_id, ckpt)
        );
    }

    return retval;
}

/*!
 *  \brief  obtain all host-side checkpoint records
 *  \note   this function only return those api context that hasn't been pruned by checkpoint system
 *  \return all host-side checkpoint records
 */
std::vector<pos_host_ckpt_t> POSCheckpointBag::get_host_checkpoint_records(){
    std::vector<pos_host_ckpt_t> ret_list;
    typename std::unordered_map<uint64_t, pos_host_ckpt_t>::iterator map_iter;

    for(map_iter=this->_host_ckpt_map.begin(); map_iter!=this->_host_ckpt_map.end(); map_iter++){
        POS_CHECK_POINTER(map_iter->second.wqe)
        if(likely(map_iter->second.wqe->is_ckpt_pruned == false)){
            ret_list.push_back(map_iter->second);
        }
    }

    return ret_list;
}
