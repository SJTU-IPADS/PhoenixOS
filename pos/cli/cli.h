#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "pos/include/common.h"
#include "pos/include/log.h"


/*!
 *  \brief  type of the command
 */
enum pos_cli_arg : int {
    kPOS_CliAction_Unknown = 0,
    /* ============ basic types ============ */
    // print help message
    kPOS_CliAction_Help,
    // migrate specified process
    kPOS_CliAction_Migrate,
    // preserve context resources
    kPOS_CliAction_Preserve,
    kPOS_CliAction_PLACEHOLDER,
    
    /* ============ metadatas ============ */
    // target process id
    kPOS_CliMeta_Pid,
    // oob ip
    kPOS_CliMeta_OobIp,
    // oob port
    kPOS_CliMeta_OobPort,
    // dataplane ip
    kPOS_CliMeta_DataplaneIp,
    // dataplane port
    kPOS_CliMeta_DataplanePort,
    kPOS_CliMeta_PLACEHOLDER,
};

typedef pos_cli_arg     pos_cli_action;
typedef pos_cli_arg     pos_cli_meta;

/*!
 *  \brief  convert action name from action type 
 */
static std::string pos_cli_action_name(pos_cli_arg action_type){
    switch (action_type)
    {
    case kPOS_CliAction_Help:
        return "help";

    case kPOS_CliAction_Migrate:
        return "migrate";

    case kPOS_CliAction_Preserve:
        return "preserve";
    
    default:
        return "unknown";
    }
}


typedef struct pos_cli_migrate_metas {
    uint64_t pid;
    in_addr_t target_host_oob_ip;
    uint32_t target_host_oob_port;
    in_addr_t target_host_dp_ip;
    uint32_t target_host_dp_port;
} pos_cli_migrate_metas_t;


/*!
 *  \brief  descriptor of command line options
 */
typedef struct pos_cli_options {
    // type of the command
    pos_cli_action action_type;

    // raw option map
    std::map<pos_cli_meta, std::string> _raw_metas;
    inline void record_raw(pos_cli_meta key, std::string value){
        _raw_metas[key] = value;
    }

    POSOobClient *local_oob_client;
    POSOobClient *remote_oob_client;

    // metadata of corresponding cli option
    union {
        pos_cli_migrate_metas migrate;
    } metas;

    pos_cli_options() : local_oob_client(nullptr), remote_oob_client(nullptr), action_type(kPOS_CliAction_Unknown) {}
} pos_cli_options_t;


/*!
 *  \brief  checking rule for verifying CLI argument
 */
typedef struct pos_cli_meta_check_rule {
    pos_cli_meta meta_type;
    std::string meta_name;
    std::string meta_desp;
    using cast_func_t = pos_retval_t(*)(pos_cli_options_t&, std::string&);
    cast_func_t cast_func;
    bool is_required;
} pos_arg_check_rule_t;

/*!
 *  \brief  validate correctness of arguments
 *  \param  clio    all cli infomations
 *  \param  rules   checking rules
 */
static void validate_and_cast_args(pos_cli_options_t &clio, std::vector<pos_arg_check_rule_t> &&rules){
    for(auto& rule : rules){
        if(clio._raw_metas.count(rule.meta_type) == 0){
            POS_ERROR(
                "%s action requires option '%s'(%s)",
                pos_cli_action_name(clio.action_type).c_str(),
                rule.meta_name.c_str(),
                rule.meta_desp.c_str()
            );
        }

        if(unlikely(POS_SUCCESS != rule.cast_func(clio, clio._raw_metas[rule.meta_type]))){
            POS_ERROR("invalid format for '%s' option", rule.meta_name.c_str());
        }
    }
}

pos_retval_t handle_migrate(pos_cli_options_t &clio);
