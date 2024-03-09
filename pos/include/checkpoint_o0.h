#pragma once

#include <iostream>
#include <vector>
#include <set>

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
    ) {}
    ~POSCheckpointBag() = default;
    
    /*!
     *  \brief  clear current checkpoint bag
     */
    void clear(){}

    /*!
     *  \brief  allocate a new checkpoint slot inside this bag
     *  \param  version     version (i.e., dag index) of this checkpoint
     *  \param  ptr         pointer to the new checkpoint slot
     *  \return POS_SUCCESS for successfully allocation
     */
    pos_retval_t apply_checkpoint_slot(uint64_t version, POSCheckpointSlot** ptr){
        return POS_FAILED_NOT_IMPLEMENTED;
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
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  obtain the checkpoint version list
     *  \return the checkpoint version list
     */
    std::set<uint64_t> get_checkpoint_version_set(){
        return std::set<uint64_t>();
    }

    /*!
     *  \brief  invalidate the checkpoint from this bag
     *  \param  version version of the checkpoint to be removed
     *  \return POS_SUCCESS for successfully invalidate
     *          POS_NOT_READY for no checkpoint had been record
     */
    inline pos_retval_t invalidate_by_version(uint64_t version) {
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  obtain overall memory consumption of this checkpoint bag
     *  \return overall memory consumption of this checkpoint bag
     */
    inline uint64_t get_memory_consumption(){
        return 0;
    }

    /*!
     *  \brief  load checkpoint data into this bag
     *  \note   this function will be invoked during the restore process
     *  \param  version     version of this checkpoint
     *  \param  ckpt_data   pointer to the buffer that stores the checkpointed data
     *  \return POS_SUCCESS for successfully loading
     */
    inline pos_retval_t load(uint64_t version, void* ckpt_data){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

 private:
};
