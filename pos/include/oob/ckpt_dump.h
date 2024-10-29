#pragma once

#include <iostream>
#include <vector>
#include <unistd.h>

#include "pos/include/common.h"
#include "pos/include/oob.h"

namespace oob_functions {


namespace cli_ckpt_dump {
    static constexpr uint32_t kCkptFilePathMaxLen = 128;
    static constexpr uint32_t kServerRetMsgMaxLen = 128;

    // payload format
    typedef struct oob_payload {
        /* client */
        __pid_t pid;
        char ckpt_dir[kCkptFilePathMaxLen];
        /* server */
        pos_retval_t retval;
        char retmsg[kServerRetMsgMaxLen];
    } oob_payload_t;
    static_assert(sizeof(oob_payload_t) <= POS_OOB_MSG_MAXLEN);

    // metadata from CLI
    typedef struct oob_call_data {
        /* client */
        __pid_t pid;
        char ckpt_dir[kCkptFilePathMaxLen];
        /* server */
        pos_retval_t retval;
        char retmsg[kServerRetMsgMaxLen];
    } oob_call_data_t;
} // namespace cli_ckpt_dump


} // namespace oob_functions
