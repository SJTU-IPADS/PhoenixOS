#pragma once

#include <iostream>

#include "pos/include/command.h"
#include "pos/include/log.h"
#include "pos/include/workspace.h"
#include "pos/cuda_impl/workspace.h"


/*!
 *  \brief  create new workspace for CUDA platform
 *  \return pointer to the created CUDA workspace
 */
static POSWorkspace_CUDA* pos_create_workspace_cuda(){
    pos_retval_t retval = POS_SUCCESS;
    POSWorkspace_CUDA *pos_cuda_ws = nullptr;

    POS_CHECK_POINTER(pos_cuda_ws = new POSWorkspace_CUDA());
    if(unlikely(POS_SUCCESS != (retval = pos_cuda_ws->init()))){
        POS_WARN("failed to initialize PhOS CUDA Workspace: retval(%u)", retval);
        goto exit;
    }

exit:
    if(unlikely(retval != POS_SUCCESS)){
        if(pos_cuda_ws != nullptr){ delete pos_cuda_ws; }
        pos_cuda_ws = nullptr;
    }
    return pos_cuda_ws;
}


/*!
 *  \brief  destory workspace of CUDA platform
 *  \param  pos_cuda_ws pointer to the CUDA workspace to be destoried
 *  \return 0 for successfully destory
 *          1 for failed
 */
static int pos_destory_workspace_cuda(POSWorkspace_CUDA* pos_cuda_ws){
    int retval = 0;
    pos_retval_t pos_retval = POS_SUCCESS;

    POS_CHECK_POINTER(pos_cuda_ws);

    if(unlikely(POS_SUCCESS != (pos_retval = pos_cuda_ws->deinit()))){
        POS_WARN("failed to deinitialize PhOS CUDA Workspace: retval(%u)", pos_retval);
        retval = 1;
        goto exit;
    }
    delete pos_cuda_ws;

exit:
    return retval;
}
