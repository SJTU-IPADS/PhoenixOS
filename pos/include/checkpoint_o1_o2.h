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

    /*!
     *  \brief  obtain checkpointed data by given checkpoint version
     *  \param  data        pointer for obtaining data
     *  \param  size        size of the checkpoin data
     *  \param  version     the specified version
     *  \param  get_latest  whether to get the latest version of checkpoint,
     *                      if this field is true, the version field will be ignored
     *  \return POS_SUCCESS for successfully obtained
     */
    inline pos_retval_t get_checkpoint_data_by_version(void** data, uint64_t& size, uint64_t version=0, bool get_latest=true){
        pos_retval_t retval = POS_SUCCESS;
        uint64_t version_to_check;
        bool _has_record;

        // check whether this bag has record
        _has_record = (_front_version != 0) || (_back_version != 0);
        if(unlikely(_has_record == false)){
            retval = POS_FAILED_NOT_READY;
            goto exit;
        }

        *data = _use_front ? _ckpt_back->expose_pointer() : _ckpt_front->expose_pointer();
        size = _state_size;

        if(unlikely(get_latest == false)){
            version_to_check = _use_front ? _back_version : _front_version;

            // no match version
            if(unlikely(version_to_check != version)){
                retval = POS_FAILED_NOT_READY;
            }
        }

    exit:
        return retval;
    }

    /*!
     *  \brief  obtain the latest checkpoint data with its checkpoint version
     *  \param  data        pointer for obtaining data
     *  \param  version     the resulted version
     *  \param  size        size of the checkpoin data
     *  \return POS_SUCCESS for successfully obtained
     */
    inline pos_retval_t get_latest_checkpoint(void **data, uint64_t& version, uint64_t& size){
        pos_retval_t retval = POS_SUCCESS;
        bool _has_record;

        // check whether this bag has record
        _has_record = (_front_version != 0) || (_back_version != 0);
        if(unlikely(_has_record == false)){
            retval = POS_FAILED_NOT_READY;
            goto exit;
        }

        *data = _use_front ? _ckpt_back->expose_pointer() : _ckpt_front->expose_pointer();
        version = _use_front ? _back_version : _front_version;
        size = _state_size;

    exit:
        return retval;
    }

 private:
    // indicate which checkpoint slot to use (front / back)
    bool _use_front;

    // front checkpoint slot
    uint64_t _front_version;
    POSCheckpointSlot_ptr _ckpt_front;

    // back checkpoint slot
    uint64_t _back_version;
    POSCheckpointSlot_ptr _ckpt_back;

    // state size of each checkpoint
    uint64_t _state_size;
};