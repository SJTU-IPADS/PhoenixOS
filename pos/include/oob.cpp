#include <iostream>
#include <vector>

#include "pos/include/common.h"
#include "pos/include/oob.h"
#include "pos/include/log.h"
#include "pos/include/transport.h"
#include "pos/include/api_context.h"

namespace oob_functions {

/*!
 *  \related    kPOS_Oob_Register_Client
 *  \brief      register a new client to the server
 */
namespace register_client {
    // payload format
    typedef struct oob_payload {
        /* client */
        /* server */
        bool is_registered;
    } oob_payload_t;

    // server
    POS_OOB_FUNC_S(){
        oob_payload_t *payload;

        T_POSClient *clnt;
        T_POSTransport* trans;

        POS_CHECK_POINTER(remote);
        POS_CHECK_POINTER(msg);
        POS_CHECK_POINTER(ws);

        payload = (oob_payload_t*)msg->payload;
        
        // create client
        POS_CHECK_POINTER(clnt = new T_POSClient());
        clnt->init();
        ws->create_client(clnt, &(msg->client_meta.uuid));
        POS_DEBUG("create client: uuid(%lu)", msg->client_meta.uuid);

        // create queue pair
        if(unlikely(POS_SUCCESS != ws->create_qp(msg->client_meta.uuid))){
            POS_ERROR_DETAIL("failed to create queue pair: uuid(%lu)", msg->client_meta.uuid);
        }
        POS_DEBUG("create queue pair: uuid(%lu)", msg->client_meta.uuid);

        // create transport
        trans = new T_POSTransport( 
            /* id*/ msg->client_meta.uuid,
            /* non_blocking */ true,
            /* role */ kPOS_Transport_RoleId_Server,
            /* timeout */ 5000
        );
        POS_CHECK_POINTER(trans);
        ws->create_transport(trans, msg->client_meta.uuid);

        payload->is_registered = true;

        __POS_OOB_SEND();

        return POS_SUCCESS;
    }

    // client
    POS_OOB_FUNC_C(){
        int retval = POS_SUCCESS;
        oob_payload_t *payload;

        msg->msg_type = kPOS_Oob_Register_Client;
        memset(msg->payload, 0, sizeof(msg->payload));
        __POS_OOB_SEND();

        __POS_OOB_RECV();
        payload = (oob_payload_t*)msg->payload;
        if(payload->is_registered == true){
            POS_DEBUG(
                "[OOB %u] successfully register client to the server: uuid(%lu)",
                kPOS_Oob_Register_Client, msg->client_meta.uuid
            );
        } else {
            POS_DEBUG("[OOB %u] failed to register client to the server", kPOS_Oob_Register_Client);
            retval = POS_FAILED;
        }

        oob_clnt->set_uuid(msg->client_meta.uuid);
        agent->set_uuid(msg->client_meta.uuid);

        return retval;
    }
} // namespace register_client

namespace unregister_client {
    // server
    POS_OOB_FUNC_S(){
        POS_CHECK_POINTER(remote);
        POS_CHECK_POINTER(msg);
        POS_CHECK_POINTER(ws);

        // remove transport
        ws->remove_transport(msg->client_meta.uuid);

        // remove queue pair
        // ws->remove_qp(msg->client_meta.uuid);

        // remove client
        ws->remove_client(msg->client_meta.uuid);

        __POS_OOB_SEND();
    }

    // client
    POS_OOB_FUNC_C(){
        msg->msg_type = kPOS_Oob_Unregister_Client;
        __POS_OOB_SEND();
        __POS_OOB_RECV();
        return POS_SUCCESS;
    }
};

/*!
 *  \related    kPOS_Oob_Connect_Transport
 *  \brief      connect the transport between client and server
 */
namespace connect_transport {
    // payload format
    typedef struct oob_payload {
        /* client */
        /* server */
        bool transport_connected;
    } oob_payload_t;

    // server
    POS_OOB_FUNC_S(){
        oob_payload_t *payload;

        T_POSTransport *trpt;

        POS_CHECK_POINTER(remote);
        POS_CHECK_POINTER(msg);
        POS_CHECK_POINTER(ws);

        payload = (oob_payload_t*)msg->payload;

        trpt = ws->get_transport_by_uuid(msg->client_meta.uuid);
        if(trpt == nullptr){
            POS_WARN_DETAIL(
                "[OOB %u]failed to get transport: uuid(%lu), this might be a bug",
                kPOS_Oob_Connect_Transport,
                msg->client_meta.uuid
            );
            payload->transport_connected = false;
        } else {
            if(POS_SUCCESS != trpt->init_bh()){
                payload->transport_connected = false;
            } else {
                payload->transport_connected = true;
            }
        }

        __POS_OOB_SEND();
    }

    // client
    POS_OOB_FUNC_C(){
        int retval = POS_SUCCESS;
        oob_payload_t *payload;

        msg->msg_type = kPOS_Oob_Connect_Transport;
        memset(msg->payload, 0, sizeof(msg->payload));
        __POS_OOB_SEND();
        
        __POS_OOB_RECV();
        payload = (oob_payload_t*)msg->payload;
        if(payload->transport_connected == true){
            POS_DEBUG("[OOB %u] successfully connect transport", kPOS_Oob_Connect_Transport);
        } else {
            POS_DEBUG("[OOB %u] failed to connect transport", kPOS_Oob_Connect_Transport);
            retval = POS_FAILED;
        }

        return retval;
    }
} // namespace connect_transport

/*!
 *  \note   this is a special oob routine, client-side could call this routine
 *          to mock a API call; this routine would be used in the unit-test of
 *          POS, shouldn't be used in production
 */
namespace mock_api_call {
    // the metadata that need to be provided when the client want to mock the API
    typedef struct api_call_meta {
        uint64_t api_id;
        std::vector<POSAPIParamDesp_t> param_desps;
        int ret_code;
        uint8_t ret_data[512];
        uint64_t ret_data_size;
    } api_call_meta_t;

    // one parameter inside the API parameter list
    typedef struct api_param {
        uint8_t value[16];
        uint64_t size;
    } api_param_t;

    // payload format
    typedef struct oob_payload {
    /* client */
        // index of the called API
        uint64_t api_id;
    
        // parameters of the api calls
        api_param_t api_params[16];
        uint64_t nb_params;

    /* server */
        int ret_code;
        uint8_t ret_data[512];
    } oob_payload_t;

    // server
    POS_OOB_FUNC_S(){
        pos_retval_t retval = POS_SUCCESS;
        oob_payload_t *payload;
        uint64_t i;
        std::vector<POSAPIParamDesp_t> param_desps;

        POS_CHECK_POINTER(remote);
        POS_CHECK_POINTER(msg);
        POS_CHECK_POINTER(ws);

        // parse payload
        payload = (oob_payload_t*)msg->payload;
        for(i=0; i<payload->nb_params; i++){
            param_desps.push_back({ 
                .value = &(payload->api_params[i].value),
                .size = payload->api_params[i].size
            });
        }

        // call api
        payload->ret_code = ws->pos_process(
            /* api_id */ payload->api_id, 
            /* uuid */ msg->client_meta.uuid,
            /* param_desps */ param_desps,
            /* ret_data */ payload->ret_data
        );

        __POS_OOB_SEND();

        return POS_SUCCESS;
    }

    // client
    POS_OOB_FUNC_C(){
        pos_retval_t retval = POS_SUCCESS;
        uint64_t i;
        api_call_meta_t *api_call_meta;
        oob_payload_t *payload;

        msg->msg_type = kPOS_Oob_Mock_Api_Call;

        POS_CHECK_POINTER(call_data);
        api_call_meta = (api_call_meta_t*)call_data;

        // setup payload
        memset(msg->payload, 0, sizeof(msg->payload));
        payload = (oob_payload_t*)msg->payload;
        payload->api_id = api_call_meta->api_id;
        payload->nb_params = api_call_meta->param_desps.size();
        for(i=0; i<payload->nb_params; i++){
            POS_ASSERT(api_call_meta->param_desps[i].size <= 64);
            memcpy(
                payload->api_params[i].value,
                api_call_meta->param_desps[i].value,
                api_call_meta->param_desps[i].size
            );
            payload->api_params[i].size = api_call_meta->param_desps[i].size;
        }
        __POS_OOB_SEND();
        
        __POS_OOB_RECV();
        api_call_meta->ret_code = payload->ret_code;
        memcpy(api_call_meta->ret_data, payload->ret_data, api_call_meta->ret_data_size);

        return POS_SUCCESS;
    }
} // namespace mock_api_call

} // namespace oob_functions
