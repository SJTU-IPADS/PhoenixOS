#include <iostream>
#include <string>

#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "pos/include/common.h"
#include "pos/include/oob.h"
#include "pos/include/oob/restore.h"

#include "pos/cli/cli.h"


pos_retval_t handle_restore(pos_cli_options_t &clio){
    pos_retval_t retval = POS_SUCCESS;
    oob_functions::cli_restore::oob_call_data_t call_data;

    validate_and_cast_args(clio, {
        {
            /* meta_type */ kPOS_CliMeta_Dir,
            /* meta_name */ "dir",
            /* meta_desp */ "directory that stores the checkpoint files",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                // TODO: should we cast the file path to absolute path?
                if(meta_val.size() >= oob_functions::cli_restore::kCkptFilePathMaxLen){
                    POS_WARN(
                        "ckpt file path too long: given(%lu), expected_max(%lu)",
                        meta_val.size(),
                        oob_functions::cli_restore::kCkptFilePathMaxLen
                    );
                    retval = POS_FAILED_INVALID_INPUT;
                    goto exit;
                }
                memset(clio.metas.ckpt.ckpt_dir, 0, oob_functions::cli_restore::kCkptFilePathMaxLen);
                memcpy(clio.metas.ckpt.ckpt_dir, meta_val.c_str(), meta_val.size());
            exit:
                return retval;
            },
            /* is_required */ true
        }
    });

    // send dump request
    memcpy(
        call_data.ckpt_dir,
        clio.metas.ckpt.ckpt_dir,
        oob_functions::cli_restore::kCkptFilePathMaxLen
    );

    retval = clio.local_oob_client->call(kPOS_OOB_Msg_CLI_Restore, &call_data);
    if(POS_SUCCESS != call_data.retval){
        POS_WARN("restore failed, %s", call_data.retmsg);
    } else {
        POS_LOG("restore done");
    }

    return retval;
}
