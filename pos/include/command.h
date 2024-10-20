#pragma once

#include <iostream>

#include "pos/include/command.h"
#include "pos/include/log.h"


/*!
 *  \brief command type index
 */
enum pos_command_typeid_t : uint16_t {
    kPOS_Command_OobToParser_Nothing = 0,

    /* ========== Cmd From OOB to Parser ========== */
    kPOS_Command_OobToParser_PreDumpStart,

    /* ========== Cmd From Worker to Parser ========== */
    kPOS_Command_OobToParser_PreDumpEnd
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

    POSCommand_QE()
        :   type(kPOS_Command_OobToParser_Nothing),
            retval(POS_SUCCESS) {}
} POSCommand_QE_t;
