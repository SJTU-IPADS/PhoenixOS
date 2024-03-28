#pragma once

#include <iostream>
#include <vector>

#include <stdint.h>

#include "pos/include/common.h"
#include "pos/include/log.h"

using pos_custom_ckpt_allocate_func_t = void*(*)(uint64_t state_size);
using pos_custom_ckpt_deallocate_func_t = void(*)(void* ptr);

class POSCheckpointSlot {
 public:
    POSCheckpointSlot(uint64_t state_size) : _state_size(state_size), _custom_deallocator(nullptr) {
        if(likely(state_size > 0)){
            POS_CHECK_POINTER(_data = malloc(state_size));
        } else {
            POS_WARN_C("try to create checkpoint slot with state size 0, this is a bug");
            _data = nullptr;
        }
    }

    POSCheckpointSlot(
        uint64_t state_size,
        pos_custom_ckpt_allocate_func_t allocator,
        pos_custom_ckpt_deallocate_func_t deallocator
    ) : _state_size(state_size), _custom_deallocator(deallocator) {
        POS_CHECK_POINTER(allocator);
        if(likely(state_size > 0)){
            POS_CHECK_POINTER(_data = allocator(state_size));
        } else {
            POS_WARN_C("try to create checkpoint slot with state size 0, this is a bug");
            _data = nullptr;
        }
    }

    inline void* expose_pointer(){ return _data; }

    ~POSCheckpointSlot(){
        if(likely(_custom_deallocator != nullptr)){
            _custom_deallocator(_data);
        } else {
            // default deallocate using free
            if(unlikely(_data != nullptr && _state_size > 0)){
                free(_data);
            }
        }   
    }

 private:
    uint64_t _state_size;
    void *_data;
    pos_custom_ckpt_deallocate_func_t _custom_deallocator;
};


// forward declaration
typedef struct POSAPIContext_QE POSAPIContext_QE_t;


/*!
 *  \brief  host-side value checkpoint record
 */
typedef struct pos_host_ckpt {
    // corresponding api context wqe that stores the host-side value
    POSAPIContext_QE_t *wqe;

    // index of the parameter that stores the host-side value
    uint32_t param_index;
} pos_host_ckpt_t;


class POSCheckpointBag {
 public:
    POSCheckpointBag(
        uint64_t state_size,
        pos_custom_ckpt_allocate_func_t allocator,
        pos_custom_ckpt_deallocate_func_t deallocator,
        pos_custom_ckpt_allocate_func_t dev_allocator,
        pos_custom_ckpt_deallocate_func_t dev_deallocator
    )
        : _state_size(state_size),
        _allocate_func(allocator), _deallocate_func(deallocator),
        _dev_allocate_func(dev_allocator), _dev_deallocate_func(dev_deallocator)
    {
        pos_retval_t tmp_retval;
        uint64_t i=0;
        POSCheckpointSlot *tmp_ptr;

        /*!
         *  \brief  prefill checkpoint area to avoid long allocation time
         *  \todo   this might slow down the creation of handle, and also
         *          the deletion of the handle, how to fix? maybe use a
         *          buffer pool?
         */
        if(allocator != nullptr && deallocator != nullptr){
        #define __CKPT_PREFILL_SIZE 48
            for(i=0; i<__CKPT_PREFILL_SIZE; i++){
                tmp_retval = apply_checkpoint_slot</* on_device */false>(i, &tmp_ptr, /* force_overwrite */ false);
                POS_ASSERT(tmp_retval == POS_SUCCESS);
            }
            for(i=0; i<__CKPT_PREFILL_SIZE; i++){
                tmp_retval = invalidate_by_version</* on_deivce */ false>(i);
                POS_ASSERT(tmp_retval == POS_SUCCESS);
            }
        #undef __CKPT_PREFILL_SIZE
        }

        if(dev_allocator != nullptr && dev_deallocator != nullptr){
        #define __DEV_CKPT_PREFILL_SIZE 4
            for(i=0; i<__DEV_CKPT_PREFILL_SIZE; i++){
                tmp_retval = apply_checkpoint_slot</* on_device */true>(i, &tmp_ptr, /* force_overwrite */ false);
                POS_ASSERT(tmp_retval == POS_SUCCESS);
            }
            for(i=0; i<__DEV_CKPT_PREFILL_SIZE; i++){
                tmp_retval = invalidate_by_version</* on_deivce */ true>(i);
                POS_ASSERT(tmp_retval == POS_SUCCESS);
            }
        #undef __DEV_CKPT_PREFILL_SIZE
        }
    }

    ~POSCheckpointBag() = default;
    
    /*!
     *  \brief  clear current checkpoint bag
     */
    void clear();

    /*!
     *  \brief  allocate a new checkpoint slot inside this bag
     *  \tparam on_device           whether to apply the slot on the device
     *  \param  version             version (i.e., dag index) of this checkpoint
     *  \param  ptr                 pointer to the checkpoint slot
     *  \param  force_overwrite     force to overwrite the oldest checkpoint to save allocation time
     *                              (if no available slot exit)
     *  \return POS_SUCCESS for successfully allocation
     */
    template<bool on_device>
    pos_retval_t apply_checkpoint_slot(uint64_t version, POSCheckpointSlot** ptr, bool force_overwrite);

    /*!
     *  \brief  obtain checkpointed data by given checkpoint version
     *  \tparam on_device   whether the slot to be applied is on the device
     *  \param  ckpt_slot   pointer to the checkpoint slot if successfully obtained
     *  \param  size        size of the checkpoin data
     *  \param  version     the specified version
     *  \return POS_SUCCESS for successfully obtained
     *          POS_FAILED_NOT_EXIST for no checkpoint is found
     */
    template<bool on_device>
    pos_retval_t get_checkpoint_slot(POSCheckpointSlot** ckpt_slot, uint64_t& size, uint64_t version);

    /*!
     *  \brief  obtain the checkpoint version list
     *  \return the checkpoint version list
     */
    inline std::set<uint64_t> get_checkpoint_version_set(){
        return _ckpt_version_set;
    }


    /*!
     *  \brief  invalidate the checkpoint from this bag
     *  \tparam on_device   whether to apply the slot on the device
     *  \param  version version of the checkpoint to be removed
     *  \return POS_SUCCESS for successfully invalidate
     *          POS_NOT_READY for no checkpoint had been record
     */
    template<bool on_device>
    pos_retval_t invalidate_by_version(uint64_t version);


    /*!
     *  \brief  obtain overall memory consumption of this checkpoint bag
     *  \return overall memory consumption of this checkpoint bag
     */
    inline uint64_t get_memory_consumption(){
        return _ckpt_map.size() * _state_size;
    }


    /*!
     *  \brief  load binary checkpoint data into this bag
     *  \note   this function will be invoked during the restore process
     *  \param  version     version of this checkpoint
     *  \param  ckpt_data   pointer to the buffer that stores the checkpointed data
     *  \return POS_SUCCESS for successfully loading
     */
    pos_retval_t load(uint64_t version, void* ckpt_data);

    /*!
     *  \brief  record a new host-side checkpoint of this bag
     *  \note   this function is invoked within parser thread
     *  \param  ckpt    host-side checkpoint record
     *  \return POS_SUCCESS for successfully recorded
     *          POS_FAILED_ALREADY_EXIST for duplicated version
     */
    pos_retval_t set_host_checkpoint_record(pos_host_ckpt_t ckpt);

    /*!
     *  \brief  obtain all host-side checkpoint records
     *  \note   this function only return those api context that hasn't been pruned by checkpoint system
     *  \return all host-side checkpoint records
     */
    std::vector<pos_host_ckpt_t> get_host_checkpoint_records();

    // waitlist of the host-side checkpoint record, populated during restore phrase
    std::vector<std::pair<pos_vertex_id_t, uint32_t>> host_ckpt_waitlist;

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

    /*!
     *  \brief  on-device checkpoint version map
     *  \note   key: version
     *  \note   value: checkpoint slot  
     */
    std::unordered_map<uint64_t, POSCheckpointSlot*> _dev_ckpt_map;

    /*!
     *  \brief  device-side checkpoint version that has been invalidated
     *  \note   we store thost invalidated version so that we can reuse their memory
     *          space in the next time we apply for a new checkpoint slot
     */
    std::unordered_map<uint64_t, POSCheckpointSlot*> _invalidate_dev_ckpt_map;

    /*!
     *  \brief  list of host-side checkpoint
     */
    std::unordered_map<uint64_t, pos_host_ckpt_t> _host_ckpt_map;
    
    // all versions that this bag stored
    std::set<uint64_t> _ckpt_version_set;

    // all on-device versions that this bag stored
    std::set<uint64_t> _dev_ckpt_version_set;

    // state size of each checkpoint
    uint64_t _state_size;

    // allocator and deallocator of checkpoint memory
    pos_custom_ckpt_allocate_func_t _allocate_func;
    pos_custom_ckpt_deallocate_func_t _deallocate_func;

    // allocator and deallocator of on-device checkpoint memory
    pos_custom_ckpt_allocate_func_t _dev_allocate_func;
    pos_custom_ckpt_deallocate_func_t _dev_deallocate_func;
};
