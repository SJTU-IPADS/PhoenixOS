#include <iostream>

#include "pos/include/common.h"
#include "pos/include/handle.h"
#include "pos/include/api_context.h"
#include "pos/include/dag.h"

#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/parser.h"
#include "pos/cuda_impl/client.h"
#include "pos/cuda_impl/api_context.h"

namespace ps_functions {

/*!
 *  \related    [Cricket Adapt] rpc_dinit
 *  \brief      disconnect of RPC connection
 */
namespace remoting_deinit {
    // parser function
    POS_RT_FUNC_PARSER(){
        pos_retval_t retval = POS_SUCCESS;
        POSClient_CUDA *client;
        POSAPIContext_QE *ckpt_wqe;

        POS_CHECK_POINTER(wqe);
        POS_CHECK_POINTER(ws);

    #if POS_CKPT_ENABLE_PREEMPT
        POS_LOG("RPC deinitialization signal received, start preemption checkpoint")
        client = (POSClient_CUDA*)(wqe->client);
        POS_CHECK_POINTER(client);
        ckpt_wqe = new POSAPIContext_QE_t(
            /* api_id*/ ws->checkpoint_api_id,
            /* client */ client
        );
        POS_CHECK_POINTER(ckpt_wqe);
        retval = client->dag.launch_op(ckpt_wqe);
    #endif

    exit:
        return retval;
    }
}; // namespace remoting_deinit

}; // namespace ps_functions
