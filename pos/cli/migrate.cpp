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

#include "pos/cli/cli.h"

pos_retval_t handle_migrate(pos_cli_options_t &clio){
    pos_retval_t retval = POS_SUCCESS;

    validate_and_cast_args(clio, {
        {
            /* meta_type */ kPOS_CliMeta_Pid,
            /* meta_name */ "pid",
            /* meta_desp */ "pid of the process to be migrated",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                clio.metas.migrate.pid = std::stoull(meta_val);
            exit:
                return retval;
            },
            /* is_required */ true
        },
        {
            /* meta_type */ kPOS_CliMeta_OobIp,
            /* meta_name */ "oip",
            /* meta_desp */ "out-of-band ip of remote host",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                clio.metas.migrate.target_host_oob_ip = inet_addr(meta_val.c_str());
            exit:
                return retval;
            },
            /* is_required */ true
        },
        {
            /* meta_type */ kPOS_CliMeta_OobPort,
            /* meta_name */ "oport",
            /* meta_desp */ "out-of-band port of remote host",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                clio.metas.migrate.target_host_oob_port = std::stoul(meta_val);
            exit:
                return retval;
            },
            /* is_required */ true
        },
        {
            /* meta_type */ kPOS_CliMeta_DataplaneIp,
            /* meta_name */ "dip",
            /* meta_desp */ "dataplane ip of remote host",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                clio.metas.migrate.target_host_dp_ip = inet_addr(meta_val.c_str());
            exit:
                return retval;
            },
            /* is_required */ true
        },
        {
            /* meta_type */ kPOS_CliMeta_DataplanePort,
            /* meta_name */ "dport",
            /* meta_desp */ "dataplane port of remote host",
            /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                pos_retval_t retval = POS_SUCCESS;
                clio.metas.migrate.target_host_dp_port = std::stoul(meta_val);
            exit:
                return retval;
            },
            /* is_required */ true
        },
    });

    // step 1: create remote transport

    // step 2: connect 

exit:
    return retval;
}
