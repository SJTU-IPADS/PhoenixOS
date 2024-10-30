#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#include "pos/include/common.h"
#include "pos/include/oob.h"
#include "pos/include/oob/restore.h"
#include "pos/include/log.h"
#include "pos/include/api_context.h"
#include "pos/include/workspace.h"
#include "pos/include/agent.h"
#include "pos/include/command.h"
#include "pos/cuda_impl/client.h"


namespace oob_functions {

/*!
 *  \related    kPOS_OOB_Msg_CLI_Restore
 *  \brief      signal for restore the state of a specific client
 */
namespace cli_restore {
    // server
    pos_retval_t sv(int fd, struct sockaddr_in* remote, POSOobMsg_t* msg, POSWorkspace* ws, POSOobServer* oob_server){
        pos_retval_t retval = POS_SUCCESS;
        oob_payload_t *payload;
        std::string retmsg;
        POSClient *client;
        std::string ckpt_dir, client_ckpt_path;

        POS_CHECK_POINTER(ws);
        POS_CHECK_POINTER(oob_server);

        POS_CHECK_POINTER(payload = (oob_payload_t*)msg->payload);

        // make sure the directory exist
        ckpt_dir = std::string(payload->ckpt_dir);
        if (!std::filesystem::exists(ckpt_dir)) {
            payload->retval = POS_FAILED_NOT_EXIST;
            retmsg = std::string("no ckpt dir exist: ") + ckpt_dir.c_str();
            goto response;
        }

        // restore client in the workspace
        client_ckpt_path = ckpt_dir + std::string("/c.bin");
        if (!std::filesystem::exists(client_ckpt_path)) {
            payload->retval = POS_FAILED_NOT_EXIST;
            retmsg = std::string("ckpt corrupted: no client data");
            goto response;
        }
        if(unlikely(POS_SUCCESS != (
            payload->retval = ws->restore_client(client_ckpt_path, &client)
        ))){
            retmsg = std::string("see posd log for more details");
            goto response;
        }

        // restore handle in the client handle manager
        // if on-demand, we just record the file name (maybe some async thread to reload)
        // if not on-demand, we reload the handle immediately

        // reload unexecuted APIs in the client queue (async thread)

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

        msg->msg_type = kPOS_OOB_Msg_CLI_Restore;

        POS_CHECK_POINTER(call_data);
        cm = (oob_call_data_t*)call_data;

        // setup payload
        memset(msg->payload, 0, sizeof(msg->payload));
        payload = (oob_payload_t*)msg->payload;
        memcpy(payload->ckpt_dir, cm->ckpt_dir, kCkptFilePathMaxLen);

        __POS_OOB_SEND();

        // wait until the posd finished 
        __POS_OOB_RECV();
        cm->retval = payload->retval;
        memcpy(cm->retmsg, payload->retmsg, kServerRetMsgMaxLen);

    exit:
        return retval;
    }
} // namespace cli_restore

} // namespace oob_functions
