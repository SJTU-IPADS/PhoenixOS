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
#include "pos/include/utils/command_caller.h"
#include "pos/include/oob.h"
#include "pos/include/oob/ckpt_dump.h"

#include "pos/cli/cli.h"


pos_retval_t handle_dump(pos_cli_options_t &clio){
    pos_retval_t retval = POS_SUCCESS;
    oob_functions::cli_ckpt_dump::oob_call_data_t call_data;
    std::string criu_cmd, criu_output;

    validate_and_cast_args(clio, {
        {
            /* meta_type */ kPOS_CliMeta_Pid,
            /* meta_name */ "pid",
            /* meta_desp */ "pid of the process to be migrated",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                clio.metas.ckpt.pid = std::stoull(meta_val);
            exit:
                return retval;
            },
            /* is_required */ true
        },
        {
            /* meta_type */ kPOS_CliMeta_Dir,
            /* meta_name */ "dir",
            /* meta_desp */ "directory to store the checkpoint files",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                // TODO: should we cast the file path to absolute path?
                if(meta_val.size() >= oob_functions::cli_ckpt_dump::kCkptFilePathMaxLen){
                    POS_WARN(
                        "ckpt file path too long: given(%lu), expected_max(%lu)",
                        meta_val.size(),
                        oob_functions::cli_ckpt_dump::kCkptFilePathMaxLen
                    );
                    retval = POS_FAILED_INVALID_INPUT;
                    goto exit;
                }
                memset(clio.metas.ckpt.ckpt_dir, 0, oob_functions::cli_ckpt_dump::kCkptFilePathMaxLen);
                memcpy(clio.metas.ckpt.ckpt_dir, meta_val.c_str(), meta_val.size());
            exit:
                return retval;
            },
            /* is_required */ true
        }
    });

    // call criu
    criu_cmd = std::string("/root/bin/criu dump")
                +   std::string(" --images-dir ") + std::string(clio.metas.ckpt.ckpt_dir)
                +   std::string(" --shell-job --display-stats")
                +   std::string(" --tree ") + std::to_string(clio.metas.ckpt.pid);
    retval = POSUtil_Command_Caller::exec(criu_cmd, criu_output);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN(
            "failed to execute CRIU\n"
            "cmd: %s\n"
            "output: %s",
            criu_cmd.c_str(), criu_output.c_str()
        );
        goto exit;
    }

    // send dump request to posd
    call_data.pid = clio.metas.ckpt.pid;
    memcpy(
        call_data.ckpt_dir,
        clio.metas.ckpt.ckpt_dir,
        oob_functions::cli_ckpt_dump::kCkptFilePathMaxLen
    );

    retval = clio.local_oob_client->call(kPOS_OOB_Msg_CLI_Ckpt_Dump, &call_data);
    if(POS_SUCCESS != call_data.retval){
        POS_WARN("dump failed, %s", call_data.retmsg);
    } else {
        POS_LOG("dump done");
    }

exit:
    return retval;
}
