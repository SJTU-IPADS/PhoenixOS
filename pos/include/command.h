#pragma once

#include <iostream>
#include <set>
#include "pos/include/common.h"
#include "pos/include/log.h"


// forward declaration
class POSHandle;


/*!
 *  \brief command type index
 */
enum pos_command_typeid_t : uint16_t {
    kPOS_Command_Nothing = 0,

    /* ========== Checkpoint Cmd ========== */
    kPOS_Command_Oob2Parser_PreDump,
    kPOS_Command_Oob2Parser_Dump,
    kPOS_Command_Parser2Worker_PreDump,
    kPOS_Command_Parser2Worker_Dump,
};


/*!
 *  \brief asynchronous command among different threads   
 */
typedef struct POSCommand_QE {
    // type of the command
    pos_command_typeid_t type;

    // client id
    pos_client_uuid_t client_id;

    // command execution result
    pos_retval_t retval;

    // ============================== payloads ==============================
    // for kPOS_Command_xxx_PreDump and kPOS_Command_xxx_Dump
    std::set<POSHandle*> checkpoint_handles;

    /*!
     *  \brief  record all handles that need to be checkpointed within this checkpoint op
     *  \param  id          resource type index
     *  \param  handle_set  sets of handles
     */
    inline void record_checkpoint_handles(std::set<POSHandle*>& handle_set){
        checkpoint_handles.insert(handle_set.begin(), handle_set.end());
    }

    /*!
     *  \brief  record all handles that need to be checkpointed within this checkpoint op
     *  \param  handle  the handle to be recorded
     */
    inline void record_checkpoint_handles(POSHandle *handle){
        checkpoint_handles.insert(handle);
    }
    // ============================== payloads ==============================

    POSCommand_QE()
        :   type(kPOS_Command_Nothing),
            retval(POS_SUCCESS) {}
} POSCommand_QE_t;
