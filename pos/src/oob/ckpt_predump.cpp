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
#include <vector>
#include <string>
#include <filesystem>

#include "pos/include/common.h"
#include "pos/include/oob.h"
#include "pos/include/oob/ckpt_predump.h"
#include "pos/include/log.h"
#include "pos/include/api_context.h"
#include "pos/include/workspace.h"
#include "pos/include/agent.h"
#include "pos/include/command.h"
#include "pos/cuda_impl/client.h"


namespace oob_functions {

/*!
 *  \related    kPOS_OOB_Msg_CLI_Ckpt_PreDump
 *  \brief      signal for predump the state of a specific client
 */
namespace cli_ckpt_predump {
    // server
    pos_retval_t sv(int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSWorkspace* ws, POSOobServer* oob_server){
        pos_retval_t retval = POS_SUCCESS;
        oob_payload_t *payload;
        POSClient *client;
        std::string retmsg;
        POSCommand_QE_t* cmd;
        std::vector<POSCommand_QE_t*> cmds;

        std::string predump_dir, mount_filepath;
        std::string mount_cmd;
        std::uintmax_t nb_removed_files;
        bool has_mount_before = false;

        payload = (oob_payload_t*)msg->payload;
        
        // obtain client with specified pid
        client = ws->get_client_by_pid(payload->pid);
        if(unlikely(client == nullptr)){
            retmsg = "no client with specified pid was found";
            payload->retval = POS_FAILED_NOT_EXIST;
            memcpy(payload->retmsg, retmsg.c_str(), retmsg.size());
            goto response;
        }

        // form cmd
        POS_CHECK_POINTER(cmd = new POSCommand_QE_t);
        cmd->client_id = client->id;
        cmd->type = kPOS_Command_Oob2Parser_PreDump;
        cmd->ckpt_dir = std::string(payload->ckpt_dir);

        // make sure the directory exist and fresh
        if (std::filesystem::exists(cmd->ckpt_dir)) {
            try {
                if(std::filesystem::exists(cmd->ckpt_dir + std::string("/tmpfs_mount.lock"))){
                    has_mount_before = true;
                }
                nb_removed_files = 0;
                for(auto& de : std::filesystem::directory_iterator(cmd->ckpt_dir)) {
                    // returns the number of deleted entities since c++17:
                    nb_removed_files += std::filesystem::remove_all(de.path());
                }
                POS_LOG(
                    "clean old assets under specified pre-dump dir: dir(%s), nb_removed_files(%lu)",
                    cmd->ckpt_dir.c_str(), nb_removed_files
                );
                POS_LOG("reuse pre-dump dir: %s",  cmd->ckpt_dir.c_str());
            } catch (const std::exception& e) {
                POS_WARN(
                    "failed to remove old assets under specified pre-dump dir: dir(%s), error(%s)",
                    cmd->ckpt_dir.c_str(), e.what()
                );
                retval = POS_FAILED;
                goto exit;
            }
        } else {
            try {
                std::filesystem::create_directories(cmd->ckpt_dir);
            } catch (const std::filesystem::filesystem_error& e) {
                POS_WARN(
                    "failed to create pre-dump directory: dir(%s), error(%s)",
                    cmd->ckpt_dir.c_str(), e.what()
                );
                retval = POS_FAILED;
                goto exit;
            }
            POS_LOG("create pre-dump dir: %s",  cmd->ckpt_dir.c_str());
        }

        // mount the memory to tmpfs
        if(has_mount_before == false){
            mount_cmd = std::string("mount -t tmpfs -o size=80g tmpfs ") + predump_dir;
            POS_LOG("mount pre-dump dir to tmpfs: size(%lu), dir(%s)",  cmd->ckpt_dir.c_str());
        }

        // send to parser
        retval = client->template push_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_WQ>(cmd);
        if(unlikely(retval != POS_SUCCESS)){
            retmsg = "see posd log for more details";
            payload->retval = POS_FAILED;
            memcpy(payload->retmsg, retmsg.c_str(), retmsg.size());
            goto response;
        }

        // wait parser reply
        cmds.clear();
        while(cmds.size() == 0){
            client->template poll_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_CQ>(&cmds);
        }
        POS_ASSERT(cmds.size() == 1);
        POS_ASSERT(cmds[0]->type == kPOS_Command_Oob2Parser_PreDump);

        // transfer error status
        if(unlikely(cmds[0]->retval != POS_SUCCESS)){
            if(cmds[0]->retval == POS_FAILED_NOT_ENABLED){
                retmsg = "posd doesn't enable ckpt support";
            } else if (cmds[0]->retval == POS_FAILED_ALREADY_EXIST){
                retmsg = "pre-dump too frequent, conflict";
            } else {
                retmsg = "see posd log for more details";
            }
            memcpy(payload->retmsg, retmsg.c_str(), retmsg.size());
        }
        payload->retval = cmds[0]->retval;

    response:
        POS_ASSERT(retmsg.size() < kServerRetMsgMaxLen);
        __POS_OOB_SEND();

        return retval;
    }

    // client
    pos_retval_t clnt(
        int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSAgent* agent, POSOobClient* oob_clnt, void* call_data
    ){
        pos_retval_t retval = POS_SUCCESS;
        oob_call_data_t *cm;
        oob_payload_t *payload;

        msg->msg_type = kPOS_OOB_Msg_CLI_Ckpt_PreDump;

        POS_CHECK_POINTER(call_data);
        cm = (oob_call_data_t*)call_data;

        // setup payload
        memset(msg->payload, 0, sizeof(msg->payload));
        payload = (oob_payload_t*)msg->payload;
        payload->pid = cm->pid;
        memcpy(payload->ckpt_dir, cm->ckpt_dir, kCkptFilePathMaxLen);

        __POS_OOB_SEND();

        // wait until the posd finished 
        __POS_OOB_RECV();
        cm->retval = payload->retval;
        memcpy(cm->retmsg, payload->retmsg, kServerRetMsgMaxLen);

    exit:
        return retval;
    }
} // namespace cli_ckpt_predump

} // namespace oob_functions
