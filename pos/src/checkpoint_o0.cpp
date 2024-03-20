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
void POSCheckpointBag::clear(){}


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
    return POS_FAILED_NOT_IMPLEMENTED;
}
template pos_retval_t POSCheckpointBag::apply_checkpoint_slot<true>(uint64_t version, POSCheckpointSlot** ptr, bool force_overwrite);
template pos_retval_t POSCheckpointBag::apply_checkpoint_slot<false>(uint64_t version, POSCheckpointSlot** ptr, bool force_overwrite);


/*!
 *  \brief  obtain checkpointed data by given checkpoint version
 *  \tparam on_device   whether to apply the slot on the device
 *  \param  ckpt_slot   pointer to the checkpoint slot if successfully obtained
 *  \param  size        size of the checkpoin data
 *  \param  version     the specified version
 *  \return POS_SUCCESS for successfully obtained
 *          POS_FAILED_NOT_EXIST for no checkpoint is found
 */
template<bool on_device>
pos_retval_t POSCheckpointBag::get_checkpoint_slot(POSCheckpointSlot** ckpt_slot, uint64_t& size, uint64_t version){
    return POS_FAILED_NOT_IMPLEMENTED;
}
template pos_retval_t POSCheckpointBag::get_checkpoint_slot<true>(POSCheckpointSlot** ckpt_slot, uint64_t& size, uint64_t version);
template pos_retval_t POSCheckpointBag::get_checkpoint_slot<false>(POSCheckpointSlot** ckpt_slot, uint64_t& size, uint64_t version);


/*!
 *  \brief  invalidate the checkpoint from this bag
 *  \tparam on_device   whether to apply the slot on the device
 *  \param  version version of the checkpoint to be removed
 *  \return POS_SUCCESS for successfully invalidate
 *          POS_NOT_READY for no checkpoint had been record
 */
template<bool on_device>
pos_retval_t POSCheckpointBag::invalidate_by_version(uint64_t version) {
   return POS_FAILED_NOT_IMPLEMENTED;
}
template pos_retval_t POSCheckpointBag::invalidate_by_version<true>(uint64_t version);
template pos_retval_t POSCheckpointBag::invalidate_by_version<false>(uint64_t version);


/*!
 *  \brief  load binary checkpoint data into this bag
 *  \note   this function will be invoked during the restore process
 *  \param  version     version of this checkpoint
 *  \param  ckpt_data   pointer to the buffer that stores the checkpointed data
 *  \return POS_SUCCESS for successfully loading
 */
pos_retval_t POSCheckpointBag::load(uint64_t version, void* ckpt_data){
    return POS_FAILED_NOT_IMPLEMENTED;
}


/*!
 *  \brief  record a new host-side checkpoint of this bag
 *  \note   this function is invoked within parser thread
 *  \param  ckpt    host-side checkpoint record
 *  \return POS_SUCCESS for successfully recorded
 *          POS_FAILED_ALREADY_EXIST for duplicated version
 */
pos_retval_t POSCheckpointBag::set_host_checkpoint_record(pos_host_ckpt_t ckpt){
   return POS_FAILED_NOT_IMPLEMENTED;
}


/*!
 *  \brief  obtain all host-side checkpoint records
 *  \note   this function only return those api context that hasn't been pruned by checkpoint system
 *  \return all host-side checkpoint records
 */
std::vector<pos_host_ckpt_t> POSCheckpointBag::get_host_checkpoint_records(){
    return std::vector<pos_host_ckpt_t>();
}
