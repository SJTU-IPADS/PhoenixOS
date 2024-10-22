#include <iostream>
#include <vector>
#include <string>

#include "pos/include/common.h"
#include "pos/include/oob.h"
#include "pos/include/oob/ckpt.h"
#include "pos/include/log.h"
#include "pos/include/api_context.h"
#include "pos/include/workspace.h"
#include "pos/include/agent.h"
#include "pos/include/command.h"

#include "pos/cuda_impl/client.h"

namespace oob_functions {

/*!
 *  \related    kPOS_OOB_Msg_CLI_Migration_RemotePrepare
 *  \brief      signal for prepare remote migration resources (e.g., create RC QP)
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
        cmd->type = kPOS_Command_OobToParser_PreDumpStart;

        // send to parser
        retval = ws->template push_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_WQ>(cmd);
        if(unlikely(retval != POS_SUCCESS)){
            retmsg = "see posd log for more details";
            payload->retval = POS_FAILED;
            memcpy(payload->retmsg, retmsg.c_str(), retmsg.size());
            goto response;
        }

        // wait parser reply
        cmds.clear();
        while(cmds.size() == 0){
            ws->template poll_q<kPOS_QueueDirection_Oob2Parser, kPOS_QueueType_Cmd_CQ>(client->id, &cmds);
        }
        POS_ASSERT(cmds.size() == 1);
        POS_ASSERT(cmds[0]->type == kPOS_Command_WorkerToParser_DumpEnd
                || cmds[0]->type == kPOS_Command_WorkerToParser_PreDumpEnd);

        // transfer error status
        if(unlikely(cmds[0]->retval != POS_SUCCESS)){
            if(cmds[0]->retval == POS_FAILED_NOT_ENABLED){
                retmsg = "posd doesn't enable ckpt support";
            } else {
                retmsg = "see posd log for more details";
            }
            memcpy(payload->retmsg, retmsg.c_str(), retmsg.size());
        }
        payload->retval = cmds[0]->retval;

    response:
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
        memcpy(payload->ckpt_file_path, cm->ckpt_file_path, kCkptFilePathMaxLen);

        __POS_OOB_SEND();

        // wait until the posd finished 
        __POS_OOB_RECV();
        cm->retval = payload->retval;
        memcpy(cm->retmsg, payload->retmsg, kServerRetMsgMaxLen);

    exit:
        return retval;
    }
}

} // namespace oob_functions
