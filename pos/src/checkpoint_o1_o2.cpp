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
 *  \param  version     version (i.e., dag index) of this checkpoint
 *  \param  ptr         pointer to the checkpoint slot
 *  \return POS_SUCCESS for successfully allocation
 */
pos_retval_t POSCheckpointBag::apply_checkpoint_slot(uint64_t version, POSCheckpointSlot** ptr){
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
pos_retval_t POSCheckpointBag::get_checkpoint_slot(POSCheckpointSlot** ckpt_slot, uint64_t& size, uint64_t version){
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
 *  \brief  invalidate the checkpoint from this bag
 *  \param  version version of the checkpoint to be removed
 *  \return POS_SUCCESS for successfully invalidate
 *          POS_NOT_READY for no checkpoint had been record
 */
pos_retval_t POSCheckpointBag::invalidate_by_version(uint64_t version) {
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

    retval = apply_checkpoint_slot(version, &ckpt_slot);
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
