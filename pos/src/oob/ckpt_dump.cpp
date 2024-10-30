#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#include "pos/include/common.h"
#include "pos/include/oob.h"
#include "pos/include/oob/ckpt_dump.h"
#include "pos/include/log.h"
#include "pos/include/api_context.h"
#include "pos/include/workspace.h"
#include "pos/include/agent.h"
#include "pos/include/command.h"

#include "pos/cuda_impl/client.h"

namespace oob_functions {

/*!
 *  \related    kPOS_OOB_Msg_CLI_Ckpt_Dump
 *  \brief      signal for dump the state of a specific client
 */
namespace cli_ckpt_dump {
    // server
    pos_retval_t sv(int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSWorkspace* ws, POSOobServer* oob_server){
        pos_retval_t retval = POS_SUCCESS;
        oob_payload_t *payload;
        POSClient *client;
        std::string retmsg;
        POSCommand_QE_t* cmd;
        std::vector<POSCommand_QE_t*> cmds;

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
        cmd->type = kPOS_Command_Oob2Parser_Dump;
        cmd->ckpt_dir = std::string(payload->ckpt_dir) 
                        + std::string("/")
                        + std::to_string(payload->pid)
                        + std::string("-")
                        + std::to_string(ws->tsc_timer.get_tsc());

        // make sure the directory exist
        if (std::filesystem::exists(cmd->ckpt_dir)) {
            std::filesystem::remove_all(cmd->ckpt_dir);
        }
        try {
            std::filesystem::create_directories(cmd->ckpt_dir);
        } catch (const std::filesystem::filesystem_error& e) {
            retmsg = std::string("failed to create dir: ") + e.what();
            payload->retval = POS_FAILED;
            memcpy(payload->retmsg, retmsg.c_str(), retmsg.size());
            goto response;
        }
        POS_LOG("create ckpt dir: %s", cmd->ckpt_dir.c_str());

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
        POS_ASSERT(cmds[0]->type == kPOS_Command_Oob2Parser_Dump);

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

        // remove client
        if(likely(cmds[0]->retval == POS_SUCCESS)){
            ws->remove_client(cmd->client_id);
        }

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

        msg->msg_type = kPOS_OOB_Msg_CLI_Ckpt_Dump;

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

} // namespace cli_ckpt_dump
} // namespace oob_functions
