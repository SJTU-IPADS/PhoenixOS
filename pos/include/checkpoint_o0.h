#pragma once

#include <iostream>
#include <vector>

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
     *  \brief  allocate a new checkpoint slot inside this bag
     *  \param  version     version (i.e., dag index) of this checkpoint
     *  \param  ptr         pointer to the new checkpoint slot
     *  \return POS_SUCCESS for successfully allocation
     */
    pos_retval_t apply_new_checkpoint(uint64_t version, POSCheckpointSlot** ptr){
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
     *  \brief  obtain checkpointed data by given checkpoint version
     *  \param  data        pointer for obtaining data
     *  \param  size        size of the checkpoin data
     *  \param  version     the specified version
     *  \param  get_latest  whether to get the latest version of checkpoint,
     *                      if this field is true, the version field will be ignored
     *  \return POS_SUCCESS for successfully obtained
     */
    inline pos_retval_t get_checkpoint_data_by_version(void** data, uint64_t& size, uint64_t version=0, bool get_latest=true){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  obtain the latest checkpoint data with its checkpoint version
     *  \param  data        pointer for obtaining data
     *  \param  version     the resulted version
     *  \param  size        size of the checkpoin data
     *  \return POS_SUCCESS for successfully obtained
     */
    inline pos_retval_t get_latest_checkpoint(void **data, uint64_t& version, uint64_t& size){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

 private:
};
