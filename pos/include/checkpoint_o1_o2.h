#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <stdint.h>

#include "pos/include/common.h"
#include "pos/include/log.h"

class POSCheckpointSlot;
using POSCheckpointSlot_ptr = std::shared_ptr<POSCheckpointSlot>;

using pos_custom_ckpt_allocate_func_t = void*(*)(uint64_t state_size);
using pos_custom_ckpt_deallocate_func_t = void(*)(void* ptr);

class POSCheckpointBag {
 public:
    POSCheckpointBag(
        uint64_t state_size,
        pos_custom_ckpt_allocate_func_t allocator,
        pos_custom_ckpt_deallocate_func_t deallocator
    )
        : _state_size(state_size), _use_front(true), _front_version(0), _back_version(0)
    {
        // apply font and back checkpoint slot
        _ckpt_front = std::make_shared<POSCheckpointSlot>(_state_size, allocator, deallocator);
        POS_CHECK_POINTER((_ckpt_front).get());
        _ckpt_back = std::make_shared<POSCheckpointSlot>(_state_size, allocator, deallocator);
        POS_CHECK_POINTER((_ckpt_back).get());
    }
    ~POSCheckpointBag() = default;
    
    /*!
     *  \brief  allocate a new checkpoint slot inside this bag
     *  \param  version     version (i.e., dag index) of this checkpoint
     *  \param  ptr         pointer to the checkpoint slot
     *  \return POS_SUCCESS for successfully allocation
     */
    pos_retval_t apply_new_checkpoint(uint64_t version, POSCheckpointSlot_ptr* ptr){
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

    /*!
     *  \brief  obtain overall memory consumption of this checkpoint bag
     *  \return overall memory consumption of this checkpoint bag
     */
    inline uint64_t get_memory_consumption(){
        return _state_size * 2;
    }

 private:    
    bool _use_front;

    uint64_t _front_version;
    POSCheckpointSlot_ptr _ckpt_front;

    uint64_t _back_version;
    POSCheckpointSlot_ptr _ckpt_back;

    uint64_t _state_size;
};
