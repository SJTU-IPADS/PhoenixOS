/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <set>
#include <filesystem>

#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "pos/include/common.h"
#include "pos/include/utils/command_caller.h"
#include "pos/include/utils/string.h"
#include "pos/include/oob.h"
#include "pos/include/oob/ckpt_dump.h"
#include "pos/cli/cli.h"


#if defined(POS_CLI_RUNTIME_TARGET_CUDA)
    #include "pos/cuda_impl/handle.h"
#endif


pos_retval_t handle_dump(pos_cli_options_t &clio){
    pos_retval_t retval = POS_SUCCESS, criu_retval;
    oob_functions::cli_ckpt_dump::oob_call_data_t call_data;
    std::string criu_cmd, criu_result;
    std::thread criu_thread;
    std::promise<pos_retval_t> criu_thread_promise;
    std::future<pos_retval_t> criu_thread_future = criu_thread_promise.get_future();

    validate_and_cast_args(
        /* clio */ clio,
        /* rules */ {
            {
                /* meta_type */ kPOS_CliMeta_Pid,
                /* meta_name */ "pid",
                /* meta_desp */ "pid of the process to be migrated",
                /* cast_func */ [](pos_cli_options_t& clio, std::string& meta_val) -> pos_retval_t {
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
                    std::filesystem::path absolute_path;
                    std::string dump_dir;

                    absolute_path = std::filesystem::absolute(meta_val);

                    if(absolute_path.string().size() >= oob_functions::cli_ckpt_dump::kCkptFilePathMaxLen){
                        POS_WARN(
                            "ckpt file path too long: given(%lu), expected_max(%lu)",
                            absolute_path.string().size(),
                            oob_functions::cli_ckpt_dump::kCkptFilePathMaxLen
                        );
                        retval = POS_FAILED_INVALID_INPUT;
                        goto exit;
                    }

                    dump_dir = absolute_path.string() + std::string("/phos");
                    POS_ASSERT(dump_dir.size() < oob_functions::cli_ckpt_dump::kCkptFilePathMaxLen);

                    // make sure the directory exist and fresh
                    if (std::filesystem::exists(dump_dir)) {
                        std::filesystem::remove_all(dump_dir);
                    }
                    try {
                        std::filesystem::create_directories(dump_dir);
                    } catch (const std::filesystem::filesystem_error& e) {
                        POS_WARN(
                            "failed to create checkpoint directory: error(%s), dir(%s)",
                            e.what(), dump_dir.c_str()
                        );
                        retval = POS_FAILED;
                        goto exit;
                    }
                    POS_LOG("create ckpt dir: %s",  dump_dir.c_str());

                    memset(clio.metas.ckpt.ckpt_dir, 0, oob_functions::cli_ckpt_dump::kCkptFilePathMaxLen);
                    memcpy(clio.metas.ckpt.ckpt_dir, dump_dir.c_str(), dump_dir.size());

                exit:
                    return retval;
                },
                /* is_required */ true
            },
            {
                /* meta_type */ kPOS_CliMeta_SkipTarget,
                /* meta_name */ "skip-target",
                /* meta_desp */ "resource types to skip dumpping",
                /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                    pos_retval_t retval = POS_SUCCESS;
                    uint64_t i;
                    std::vector<std::string> substrings;
                    std::string substring;
                    typename std::map<pos_resource_typeid_t, std::string>::iterator map_iter;
                    bool found_resource = false;

                    substrings = POSUtil_String::split_string(meta_val, ',');

                    clio.metas.ckpt.nb_skip_targets = 0;
                    for(i=0; i<substrings.size(); i++){
                        substring = substrings[i];
                        found_resource = false;
                        for(map_iter = pos_resource_map.begin(); map_iter != pos_resource_map.end(); map_iter++){
                            if(map_iter->second == substring){
                                found_resource = true;
                                clio.metas.ckpt.skip_targets[clio.metas.ckpt.nb_skip_targets] = map_iter->first;
                                clio.metas.ckpt.nb_skip_targets += 1;
                                POS_ASSERT(clio.metas.ckpt.nb_skip_targets <= oob_functions::cli_ckpt_dump::kSkipTargetMaxNum);
                                break;
                            }
                        }
                        if(unlikely(found_resource == false)){
                            POS_WARN("unrecognized resource type %s", substring.c_str());
                            retval = POS_FAILED_INVALID_INPUT;
                            goto exit;
                        }
                    }

                exit:
                    return retval;
                },
                /* is_required */ false
            },
            {
                /* meta_type */ kPOS_CliMeta_Target,
                /* meta_name */ "target",
                /* meta_desp */ "resource types to do dumpping",
                /* cast_func */ [](pos_cli_options_t &clio, std::string& meta_val) -> pos_retval_t {
                    pos_retval_t retval = POS_SUCCESS;
                    uint64_t i;
                    std::vector<std::string> substrings;
                    std::string substring;
                    typename std::map<pos_resource_typeid_t, std::string>::iterator map_iter;
                    bool found_resource = false;

                    substrings = POSUtil_String::split_string(meta_val, ',');

                    clio.metas.ckpt.nb_targets = 0;
                    for(i=0; i<substrings.size(); i++){
                        substring = substrings[i];
                        found_resource = false;
                        for(map_iter = pos_resource_map.begin(); map_iter != pos_resource_map.end(); map_iter++){
                            if(map_iter->second == substring){
                                found_resource = true;
                                clio.metas.ckpt.targets[clio.metas.ckpt.nb_targets] = map_iter->first;
                                clio.metas.ckpt.nb_targets += 1;
                                POS_ASSERT(clio.metas.ckpt.nb_targets <= oob_functions::cli_ckpt_dump::kTargetMaxNum);
                                break;
                            }
                        }
                        if(unlikely(found_resource == false)){
                            POS_WARN("unrecognized resource type %s", substring.c_str());
                            retval = POS_FAILED_INVALID_INPUT;
                            goto exit;
                        }
                    }

                exit:
                    return retval;
                },
                /* is_required */ false
            },
        },
        /* collapse_rule */ [](pos_cli_options_t& clio) -> pos_retval_t {
            pos_retval_t retval = POS_SUCCESS;

            if(unlikely(clio.metas.ckpt.nb_targets > 0 && clio.metas.ckpt.nb_skip_targets > 0)){
                POS_WARN(
                    "you can't specified both the whitelist and blacklist of resource types to dump (use either '--target' or '--skip-target')"
                );
                retval = POS_FAILED_INVALID_INPUT;
                goto exit;
            }

            if(unlikely(clio.metas.ckpt.nb_targets == 0 && clio.metas.ckpt.nb_skip_targets == 0)){
                POS_WARN("no target and skip-target specified, default to dump all kinds of resource");
            }

        exit:
            return retval;
        }
    );

    // call criu
    criu_cmd = std::string("criu dump")
                +   std::string(" --images-dir ") + std::string(clio.metas.ckpt.ckpt_dir)
                +   std::string(" --shell-job --display-stats")
                +   std::string(" --tree ") + std::to_string(clio.metas.ckpt.pid);
    retval = POSUtil_Command_Caller::exec_sync(criu_cmd, criu_result, true, true);
    // retval = POSUtil_Command_Caller::exec_async(criu_cmd, criu_thread, criu_thread_promise, true, true);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN("cpu dump failed");
        // POS_WARN("failed to execute CRIU");
        goto exit;
    }

    // send dump request to posd
    call_data.pid = clio.metas.ckpt.pid;
    memcpy(
        call_data.ckpt_dir,
        clio.metas.ckpt.ckpt_dir,
        oob_functions::cli_ckpt_dump::kCkptFilePathMaxLen
    );

    // check gpu dump
    retval = clio.local_oob_client->call(kPOS_OOB_Msg_CLI_Ckpt_Dump, &call_data);
    if(POS_SUCCESS != call_data.retval){
        POS_WARN("gpu dump failed, %s", call_data.retmsg);
        goto exit;
    }

    // check cpu dump
    // if(criu_thread.joinable()){ criu_thread.join(); }
    // criu_retval = criu_thread_future.get();
    // if(POS_SUCCESS != call_data.retval){
    //     POS_WARN("cpu dump failed");
    //     goto exit;
    // }

    POS_LOG("dump done");

exit:
    return retval;
}
