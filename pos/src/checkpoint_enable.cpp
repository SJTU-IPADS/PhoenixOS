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
#include "pos/include/utils/timer.h"


POSCheckpointBag::POSCheckpointBag(
    uint64_t fixed_state_size,
    pos_custom_ckpt_allocate_func_t allocator,
    pos_custom_ckpt_deallocate_func_t deallocator,
    pos_custom_ckpt_allocate_func_t dev_allocator,
    pos_custom_ckpt_deallocate_func_t dev_deallocator
) : is_latest_ckpt_finished(false) {
    pos_retval_t tmp_retval;
    uint64_t i=0;
    POSCheckpointSlot *tmp_ptr;

    this->_fixed_state_size = fixed_state_size;
    this->_allocate_func = allocator;
    this->_deallocate_func = deallocator;
    this->_dev_allocate_func = dev_allocator;
    this->_dev_deallocate_func = dev_deallocator;

    if(allocator != nullptr && deallocator != nullptr){
    #define __CKPT_PREFILL_SIZE 1
        for(i=0; i<__CKPT_PREFILL_SIZE; i++){
            tmp_retval = apply_checkpoint_slot<kPOS_CkptSlotPosition_Host>(i, &tmp_ptr, 0, /* force_overwrite */ false);
            POS_ASSERT(tmp_retval == POS_SUCCESS);
        }
        for(i=0; i<__CKPT_PREFILL_SIZE; i++){
            tmp_retval = invalidate_by_version<kPOS_CkptSlotPosition_Host>(i);
            POS_ASSERT(tmp_retval == POS_SUCCESS);
        }
    #undef __CKPT_PREFILL_SIZE
    }

    if(dev_allocator != nullptr && dev_deallocator != nullptr){
    #define __DEV_CKPT_PREFILL_SIZE 1
        for(i=0; i<__DEV_CKPT_PREFILL_SIZE; i++){
            tmp_retval = apply_checkpoint_slot<kPOS_CkptSlotPosition_Device>(i, &tmp_ptr, 0, /* force_overwrite */ false);
            POS_ASSERT(tmp_retval == POS_SUCCESS);
        }
        for(i=0; i<__DEV_CKPT_PREFILL_SIZE; i++){
            tmp_retval = invalidate_by_version<kPOS_CkptSlotPosition_Device>(i);
            POS_ASSERT(tmp_retval == POS_SUCCESS);
        }
    #undef __DEV_CKPT_PREFILL_SIZE
    }
}


/*!
 *  \brief  clear current checkpoint bag
 */
void POSCheckpointBag::clear(){
    typename std::unordered_map<uint64_t, POSCheckpointSlot*>::iterator map_iter;

    for(map_iter = _ckpt_map.begin(); map_iter != _ckpt_map.end(); map_iter++){
        if(likely(map_iter->second != nullptr)){
            delete map_iter->second;
        }
    }

    for(map_iter = _invalidate_ckpt_map.begin(); map_iter != _invalidate_ckpt_map.end(); map_iter++){
        if(likely(map_iter->second != nullptr)){
            delete map_iter->second;
        }
    }

    _ckpt_map.clear();
    _invalidate_ckpt_map.clear();
    _ckpt_version_set.clear();
}


/*!
 *  \brief  allocate a new checkpoint slot inside this bag
 *  \tparam ckpt_slot_pos       position of the applied checkpoint slot
 *  \param  version             version of this checkpoint
 *  \param  ptr                 pointer to the checkpoint slot
 *  \param  force_overwrite     force to overwrite the oldest checkpoint to save allocation time
 *                              (if no available slot exist)
 *  \return POS_SUCCESS for successfully allocation
 */
template<pos_ckptslot_position_t ckpt_slot_pos>
pos_retval_t POSCheckpointBag::apply_checkpoint_slot(
    uint64_t version, POSCheckpointSlot** ptr, uint64_t dynamic_state_size, bool force_overwrite
){
    pos_retval_t retval = POS_SUCCESS;
    typename std::unordered_map<uint64_t, POSCheckpointSlot*>::iterator map_iter;
    uint64_t old_version;

    uint64_t s_tick, e_tick;

    POS_CHECK_POINTER(ptr);

    if constexpr (ckpt_slot_pos == kPOS_CkptSlotPosition_Device){
        // TODO: we need to have a global pool of on_device cache, to save memory
        /*!
         *  \note   we might reuse the memory that has been invalidated previously
         */
        if(likely(this->_invalidate_dev_ckpt_map.size() > 0)){
            map_iter = this->_invalidate_dev_ckpt_map.begin();
            POS_CHECK_POINTER(*ptr = map_iter->second);

            //! \note: we skip to memset the on-device checkpoint here

            this->_invalidate_dev_ckpt_map.erase(map_iter);
        } else {
            if(unlikely(force_overwrite == false)){
                POS_CHECK_POINTER(*ptr = new POSCheckpointSlot(_fixed_state_size, _dev_allocate_func, _dev_deallocate_func));
            } else {
                map_iter = _dev_ckpt_map.begin();
                old_version = map_iter->first;
                POS_CHECK_POINTER(*ptr = map_iter->second);
                
                //! \note: we skip to memset the on-device checkpoint here

                this->_dev_ckpt_map.erase(map_iter);
                this->_dev_ckpt_version_set.erase(old_version);
            }
        }
        _dev_ckpt_map.insert(std::pair<uint64_t, POSCheckpointSlot*>(version, *ptr));
        _dev_ckpt_version_set.insert(version);
    } else { // ckpt_slot_pos == kPOS_CkptSlotPosition_Host
        /*!
         *  \note   we might reuse the memory that has been invalidated previously
         */
        if(likely(_invalidate_ckpt_map.size() > 0)){
            map_iter = _invalidate_ckpt_map.begin();

            POS_CHECK_POINTER(*ptr = map_iter->second);

            //! \note   this memset takes a long time, actually it's not necessary
            // memset((*ptr)->expose_pointer(), 0, _fixed_state_size);

            this->_invalidate_ckpt_map.erase(map_iter);
        } else {
            if(unlikely(force_overwrite == false)){
                POS_CHECK_POINTER(*ptr = new POSCheckpointSlot(_fixed_state_size, _allocate_func, _deallocate_func));
            } else {
                map_iter = this->_ckpt_map.begin();
                old_version = map_iter->first;
                POS_CHECK_POINTER(*ptr = map_iter->second);
                
                //! \note   this memset takes a long time, actually it's not necessary
                // memset((*ptr)->expose_pointer(), 0, _fixed_state_size);

                this->_ckpt_map.erase(map_iter);
                this->_ckpt_version_set.erase(old_version);
            }
        }
        this->_ckpt_map.insert(std::pair<uint64_t, POSCheckpointSlot*>(version, *ptr));
        this->_ckpt_version_set.insert(version);
    }
    
exit:
    return retval;
}
template pos_retval_t POSCheckpointBag::apply_checkpoint_slot<kPOS_CkptSlotPosition_Device>(
    uint64_t version, POSCheckpointSlot** ptr, uint64_t dynamic_state_size, bool force_overwrite
);
template pos_retval_t POSCheckpointBag::apply_checkpoint_slot<kPOS_CkptSlotPosition_Host>(
    uint64_t version, POSCheckpointSlot** ptr, uint64_t dynamic_state_size, bool force_overwrite
);


template<pos_ckptslot_position_t ckpt_slot_pos>
pos_retval_t POSCheckpointBag::get_checkpoint_slot(POSCheckpointSlot** ckpt_slot, uint64_t version){
    pos_retval_t retval = POS_SUCCESS;

    if constexpr (ckpt_slot_pos == kPOS_CkptSlotPosition_Device){
        if(unlikely(this->_dev_ckpt_version_set.size() == 0)){
            retval = POS_FAILED_NOT_READY;
            goto exit;
        }
        if(likely(this->_dev_ckpt_map.count(version) > 0)){
            *ckpt_slot = _dev_ckpt_map[version];
        } else {
            *ckpt_slot = nullptr;
            retval = POS_FAILED_NOT_EXIST;
        }
    } else { // ckpt_slot_pos == kPOS_CkptSlotPosition_Host
        if(unlikely(this->_ckpt_version_set.size() == 0)){
            retval = POS_FAILED_NOT_READY;
            goto exit;
        }
        if(likely(this->_ckpt_map.count(version) > 0)){
            *ckpt_slot = _ckpt_map[version];
        } else {
            *ckpt_slot = nullptr;
            retval = POS_FAILED_NOT_EXIST;
        }
    }

exit:
    return retval;
}
template pos_retval_t POSCheckpointBag::get_checkpoint_slot<kPOS_CkptSlotPosition_Device>(POSCheckpointSlot** ckpt_slot, uint64_t version);
template pos_retval_t POSCheckpointBag::get_checkpoint_slot<kPOS_CkptSlotPosition_Host>(POSCheckpointSlot** ckpt_slot, uint64_t version);


template<pos_ckptslot_position_t ckpt_slot_pos>
uint64_t POSCheckpointBag::get_nb_checkpoint_slots(){
    if constexpr (ckpt_slot_pos == kPOS_CkptSlotPosition_Device){
        return this->_dev_ckpt_map.size(); 
    } else { // ckpt_slot_pos == kPOS_CkptSlotPosition_Host
        return this->_ckpt_map.size();
    }
}
template uint64_t POSCheckpointBag::get_nb_checkpoint_slots<kPOS_CkptSlotPosition_Device>();
template uint64_t POSCheckpointBag::get_nb_checkpoint_slots<kPOS_CkptSlotPosition_Host>();


/*!
 *  \brief  obtain the checkpoint version list
 *  \tparam ckpt_slot_pos   position of the checkpoint slot to be obtained
 *  \return the checkpoint version list
 */
template<pos_ckptslot_position_t ckpt_slot_pos>
std::set<uint64_t> POSCheckpointBag::get_checkpoint_version_set(){
    if constexpr (ckpt_slot_pos == kPOS_CkptSlotPosition_Device){
        return this->_dev_ckpt_version_set;
    } else { // ckpt_slot_pos == kPOS_CkptSlotPosition_Host
        return this->_ckpt_version_set;
    }
}
template std::set<uint64_t> POSCheckpointBag::get_checkpoint_version_set<kPOS_CkptSlotPosition_Device>();
template std::set<uint64_t> POSCheckpointBag::get_checkpoint_version_set<kPOS_CkptSlotPosition_Host>();


/*!
 *  \brief  obtain overall memory consumption of this checkpoint bag
 *  \return overall memory consumption of this checkpoint bag
 */
uint64_t POSCheckpointBag::get_memory_consumption(){
    return this->_ckpt_map.size() * this->_fixed_state_size;
}


/*!
 *  \brief  invalidate the checkpoint from this bag
 *  \tparam ckpt_slot_pos   position of the checkpoint slot to be invalidated
 *  \param  version version of the checkpoint to be removed
 *  \return POS_SUCCESS for successfully invalidate
 *          POS_NOT_READY for no checkpoint had been record
 */
template<pos_ckptslot_position_t ckpt_slot_pos>
pos_retval_t POSCheckpointBag::invalidate_by_version(uint64_t version) {
    pos_retval_t retval = POS_SUCCESS;
    POSCheckpointSlot *ckpt_slot;

    // check whether checkpoint exit
    retval = get_checkpoint_slot<ckpt_slot_pos>(&ckpt_slot, version);
    if(POS_SUCCESS != retval){
        goto exit;
    }
    POS_CHECK_POINTER(ckpt_slot);

    if constexpr (ckpt_slot_pos == kPOS_CkptSlotPosition_Device){
        this->_dev_ckpt_map.erase(version);
        this->_dev_ckpt_version_set.erase(version);
        this->_invalidate_dev_ckpt_map.insert(
            std::pair<uint64_t,POSCheckpointSlot*>(version, ckpt_slot)
        );
    } else { // ckpt_slot_pos == kPOS_CkptSlotPosition_Host
        this->_ckpt_map.erase(version);
        this->_ckpt_version_set.erase(version);
        this->_invalidate_ckpt_map.insert(
            std::pair<uint64_t,POSCheckpointSlot*>(version, ckpt_slot)
        );
    }

exit:
    return retval;
}
template pos_retval_t POSCheckpointBag::invalidate_by_version<kPOS_CkptSlotPosition_Device>(uint64_t version);
template pos_retval_t POSCheckpointBag::invalidate_by_version<kPOS_CkptSlotPosition_Host>(uint64_t version);


/*!
 *  \brief  invalidate all checkpoint from this bag
 *  \tparam ckpt_slot_pos   position of the checkpoint slots to be invalidated
 *  \return POS_SUCCESS for successfully invalidate
 *          POS_NOT_READY for no checkpoint had been record
 */
template<pos_ckptslot_position_t ckpt_slot_pos>
pos_retval_t POSCheckpointBag::invalidate_all_version(){
    pos_retval_t retval = POS_SUCCESS;
    std::set<uint64_t> version_set;
    typename std::set<uint64_t>::iterator version_set_iter;

    version_set = this->get_checkpoint_version_set<ckpt_slot_pos>();
    for(version_set_iter = version_set.begin(); version_set_iter != version_set.end(); version_set_iter++){
        retval = this->invalidate_by_version<ckpt_slot_pos>(*version_set_iter);
        if(unlikely(retval != POS_SUCCESS)){
            goto exit;
        }
    }
    
exit:
    return retval;
}
template pos_retval_t POSCheckpointBag::invalidate_all_version<kPOS_CkptSlotPosition_Device>();
template pos_retval_t POSCheckpointBag::invalidate_all_version<kPOS_CkptSlotPosition_Host>();


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

    retval = apply_checkpoint_slot<kPOS_CkptSlotPosition_Host>(version, &ckpt_slot, 0, /* force_overwrite */ false);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to apply new checkpoiont slot while loading in restore: version(%lu)", version);
        goto exit;
    }
    POS_CHECK_POINTER(ckpt_slot);

    memcpy(ckpt_slot->expose_pointer(), ckpt_data, this->_fixed_state_size);

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
    if(unlikely(this->_host_ckpt_map.count(ckpt.wqe->id) > 0)){
        retval = POS_FAILED_ALREADY_EXIST;
    } else {
        this->_host_ckpt_map.insert(
            std::pair<uint64_t, pos_host_ckpt_t>(ckpt.wqe->id, ckpt)
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
