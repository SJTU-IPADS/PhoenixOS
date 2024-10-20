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
#include "pos/include/oob/ckpt.h"

#include "pos/cli/cli.h"


pos_retval_t handle_predump(pos_cli_options_t &clio){
    pos_retval_t retval = POS_SUCCESS;
    oob_functions::cli_ckpt_predump::oob_call_data_t call_data;

    validate_and_cast_args(clio, {
        {
            /* meta_type */ kPOS_CliMeta_Pid,
            /* meta_name */ "pid",
            /* meta_desp */ "pid of the process to be migrated",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                clio.metas.pre_dump.pid = std::stoull(meta_val);
            exit:
                return retval;
            },
            /* is_required */ true
        },
        {
            /* meta_type */ kPOS_CliMeta_CkptFilePath,
            /* meta_name */ "file",
            /* meta_desp */ "path to the checkpoint file",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                // TODO: should we cast the file path to absolute path?
                if(meta_val.size() >= oob_functions::cli_ckpt_predump::kCkptFilePathMaxLen){
                    POS_WARN(
                        "ckpt file path too long: given(%lu), expected_max(%lu)",
                        meta_val.size(),
                        oob_functions::cli_ckpt_predump::kCkptFilePathMaxLen
                    );
                    retval = POS_FAILED_INVALID_INPUT;
                    goto exit;
                }
                memset(clio.metas.pre_dump.ckpt_file_path, 0, oob_functions::cli_ckpt_predump::kCkptFilePathMaxLen);
                memcpy(clio.metas.pre_dump.ckpt_file_path, meta_val.c_str(), meta_val.size());
            exit:
                return retval;
            },
            /* is_required */ true
        }
    });

    // send predump request
    call_data.pid = clio.metas.pre_dump.pid;
    memcpy(
        call_data.ckpt_file_path,
        clio.metas.pre_dump.ckpt_file_path,
        oob_functions::cli_ckpt_predump::kCkptFilePathMaxLen
    );

    retval = clio.local_oob_client->call(kPOS_OOB_Msg_CLI_Ckpt_PreDump, &call_data);
    if(POS_SUCCESS != retval){
        POS_WARN("predump failed, %s", call_data.retmsg);
    } else {
        POS_LOG("predump done");
    }

    return retval;
}
