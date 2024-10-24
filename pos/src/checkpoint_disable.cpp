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


POSCheckpointBag::POSCheckpointBag(
    uint64_t state_size,
    pos_custom_ckpt_allocate_func_t allocator,
    pos_custom_ckpt_deallocate_func_t deallocator,
    pos_custom_ckpt_allocate_func_t dev_allocator,
    pos_custom_ckpt_deallocate_func_t dev_deallocator
) : is_latest_ckpt_finished(false) {
    this->_state_size = state_size;
    this->_allocate_func = allocator;
    this->_deallocate_func = deallocator;
    this->_dev_allocate_func = dev_allocator;
    this->_dev_deallocate_func = dev_deallocator;
}


void POSCheckpointBag::clear(){}


template<pos_ckptslot_position_t ckpt_slot_pos>
pos_retval_t POSCheckpointBag::apply_checkpoint_slot(
    uint64_t version, POSCheckpointSlot** ptr, uint64_t dynamic_state_size, bool force_overwrite
){
    return POS_FAILED_NOT_IMPLEMENTED;
}
template pos_retval_t POSCheckpointBag::apply_checkpoint_slot<kPOS_CkptSlotPosition_Device>(
    uint64_t version, POSCheckpointSlot** ptr, uint64_t dynamic_state_size, bool force_overwrite
);
template pos_retval_t POSCheckpointBag::apply_checkpoint_slot<kPOS_CkptSlotPosition_Host>(
    uint64_t version, POSCheckpointSlot** ptr, uint64_t dynamic_state_size, bool force_overwrite
);


template<pos_ckptslot_position_t ckpt_slot_pos>
pos_retval_t POSCheckpointBag::get_checkpoint_slot(POSCheckpointSlot** ckpt_slot, uint64_t version){
    return POS_FAILED_NOT_IMPLEMENTED;
}
template pos_retval_t POSCheckpointBag::get_checkpoint_slot<kPOS_CkptSlotPosition_Device>(POSCheckpointSlot** ckpt_slot, uint64_t version);
template pos_retval_t POSCheckpointBag::get_checkpoint_slot<kPOS_CkptSlotPosition_Host>(POSCheckpointSlot** ckpt_slot, uint64_t version);


template<pos_ckptslot_position_t ckpt_slot_pos>
std::set<uint64_t> POSCheckpointBag::get_checkpoint_version_set(){ return std::set<uint64_t>(); }
template std::set<uint64_t> POSCheckpointBag::get_checkpoint_version_set<kPOS_CkptSlotPosition_Device>();
template std::set<uint64_t> POSCheckpointBag::get_checkpoint_version_set<kPOS_CkptSlotPosition_Host>();


uint64_t POSCheckpointBag::get_memory_consumption(){ return 0; }


template<pos_ckptslot_position_t ckpt_slot_pos>
pos_retval_t POSCheckpointBag::invalidate_by_version(uint64_t version) {
   return POS_FAILED_NOT_IMPLEMENTED;
}
template pos_retval_t POSCheckpointBag::invalidate_by_version<kPOS_CkptSlotPosition_Device>(uint64_t version);
template pos_retval_t POSCheckpointBag::invalidate_by_version<kPOS_CkptSlotPosition_Host>(uint64_t version);


template<pos_ckptslot_position_t ckpt_slot_pos>
pos_retval_t POSCheckpointBag::invalidate_all_version(){
    return POS_FAILED_NOT_IMPLEMENTED;
}
template pos_retval_t POSCheckpointBag::invalidate_all_version<kPOS_CkptSlotPosition_Device>();
template pos_retval_t POSCheckpointBag::invalidate_all_version<kPOS_CkptSlotPosition_Host>();


pos_retval_t POSCheckpointBag::load(uint64_t version, void* ckpt_data){
    return POS_FAILED_NOT_IMPLEMENTED;
}


pos_retval_t POSCheckpointBag::set_host_checkpoint_record(pos_host_ckpt_t ckpt){
   return POS_FAILED_NOT_IMPLEMENTED;
}


std::vector<pos_host_ckpt_t> POSCheckpointBag::get_host_checkpoint_records(){
    return std::vector<pos_host_ckpt_t>();
}
