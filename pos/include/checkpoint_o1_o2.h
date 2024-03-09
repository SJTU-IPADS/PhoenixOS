#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#include <stdint.h>

#include "pos/include/common.h"
#include "pos/include/log.h"

class POSCheckpointSlot;

using pos_custom_ckpt_allocate_func_t = void*(*)(uint64_t state_size);
using pos_custom_ckpt_deallocate_func_t = void(*)(void* ptr);

class POSCheckpointBag {
 public:
    POSCheckpointBag(
        uint64_t state_size,
        pos_custom_ckpt_allocate_func_t allocator,
        pos_custom_ckpt_deallocate_func_t deallocator
    )
        : _state_size(state_size), _allocate_func(allocator), _deallocate_func(deallocator)
    {
        // TODO: prefill
    }

    ~POSCheckpointBag() = default;
    
    /*!
     *  \brief  clear current checkpoint bag
     */
    void clear(){
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
     *  \param  version     version (i.e., dag index) of this checkpoint
     *  \param  ptr         pointer to the checkpoint slot
     *  \return POS_SUCCESS for successfully allocation
     */
    pos_retval_t apply_checkpoint_slot(uint64_t version, POSCheckpointSlot** ptr){
        pos_retval_t retval = POS_SUCCESS;
        typename std::unordered_map<uint64_t, POSCheckpointSlot*>::iterator map_iter;

        POS_CHECK_POINTER(ptr);

        /*!
         *  \note   we might reuse the memory that has been invalidated previously
         */
        if(likely(_invalidate_ckpt_map.size() > 0)){
            map_iter = _invalidate_ckpt_map.begin();
            
            POS_CHECK_POINTER(*ptr = map_iter->second);
            memset((*ptr)->expose_pointer(), 0, _state_size);

            _invalidate_ckpt_map.erase(map_iter);
        } else {
            POS_CHECK_POINTER(*ptr = new POSCheckpointSlot(_state_size, _allocate_func, _deallocate_func));
        }

        _ckpt_map.insert(std::pair<uint64_t, POSCheckpointSlot*>(version, *ptr));
        _ckpt_version_set.insert(version);

    exit:
        return retval;
    }


    /*!
     *  \brief  obtain checkpointed data by given checkpoint version
     *  \param  ckpt_slot   pointer to the checkpoint slot if successfully obtained
     *  \param  size        size of the checkpoin data
     *  \param  version     the specified version
     *  \return POS_SUCCESS for successfully obtained
     *          POS_FAILED_NOT_EXIST for no checkpoint is found
     */
    inline pos_retval_t get_checkpoint_slot(POSCheckpointSlot** ckpt_slot, uint64_t& size, uint64_t version){
        pos_retval_t retval = POS_SUCCESS;

        if(unlikely(_ckpt_version_set.size() == 0)){
            retval = POS_FAILED_NOT_READY;
            goto exit;
        }

        if(likely(_ckpt_map.count(version) > 0)){
            *ckpt_slot = _ckpt_map[version];
            size = _state_size;
        } else {
            *ckpt_slot = nullptr;
            size = 0;
            retval = POS_FAILED_NOT_EXIST;
        }
    
    exit:
        return retval;
    }


    /*!
     *  \brief  obtain the checkpoint version list
     *  \return the checkpoint version list
     */
    std::set<uint64_t> get_checkpoint_version_set(){
        return _ckpt_version_set;
    }


    /*!
     *  \brief  invalidate the checkpoint from this bag
     *  \param  version version of the checkpoint to be removed
     *  \return POS_SUCCESS for successfully invalidate
     *          POS_NOT_READY for no checkpoint had been record
     */
    inline pos_retval_t invalidate_by_version(uint64_t version) {
        pos_retval_t retval = POS_SUCCESS;
        POSCheckpointSlot *ckpt_slot;
        uint64_t ckpt_size;

        // check whether checkpoint exit
        retval = get_checkpoint_slot(&ckpt_slot, ckpt_size, version);
        if(POS_SUCCESS != retval){
            goto exit;
        }
        
        POS_CHECK_POINTER(ckpt_slot);

        _ckpt_map.erase(version);
        _ckpt_version_set.erase(version);

        _invalidate_ckpt_map.insert(
            std::pair<uint64_t,POSCheckpointSlot*>(version, ckpt_slot)
        );

    exit:
        return retval;
    }


    /*!
     *  \brief  obtain overall memory consumption of this checkpoint bag
     *  \return overall memory consumption of this checkpoint bag
     */
    inline uint64_t get_memory_consumption(){
        return _ckpt_map.size() * _state_size;
    }


    /*!
     *  \brief  load checkpoint data into this bag
     *  \note   this function will be invoked during the restore process
     *  \param  version     version of this checkpoint
     *  \param  size        size of the checkpoint data
     *  \param  ckpt_data   pointer to the buffer that stores the checkpointed data
     *  \return POS_SUCCESS for successfully loading
     */
    inline pos_retval_t load(uint64_t version, uint64_t size, void* ckpt_data){
        pos_retval_t retval = POS_SUCCESS;
        POSCheckpointSlot *ckpt_slot;

        POS_ASSERT(size == this->_state_size);
        POS_CHECK_POINTER(ckpt_data);

        retval = apply_checkpoint_slot(version, &ckpt_slot);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C(
                "failed to apply new checkpoiont slot while loading in restore: version(%lu), size(%lu)",
                version, size
            );
            goto exit;
        }
        POS_CHECK_POINTER(ckpt_slot);

        memcpy(ckpt_slot->expose_pointer(), ckpt_data, size);

    exit:
        return retval;
    }

 private:
    /*!
     *  \brief  checkpoint version map
     *  \note   key: version
     *  \note   value: checkpoint slot  
     */
    std::unordered_map<uint64_t, POSCheckpointSlot*> _ckpt_map;

    /*!
     *  \brief  checkpoint version that has been invalidated
     *  \note   we store thost invalidated version so that we can reuse their memory
     *          space in the next time we apply for a new checkpoint slot
     */
    std::unordered_map<uint64_t, POSCheckpointSlot*> _invalidate_ckpt_map;

    // all versions that this bag stored
    std::set<uint64_t> _ckpt_version_set;

    // state size of each checkpoint
    uint64_t _state_size;

    // allocator and deallocator of checkpoint memory
    pos_custom_ckpt_allocate_func_t _allocate_func;
    pos_custom_ckpt_deallocate_func_t _deallocate_func;
};
