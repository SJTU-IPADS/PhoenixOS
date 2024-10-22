#pragma once

#include <iostream>

#include "pos/include/command.h"
#include "pos/include/log.h"
#include "pos/include/agent.h"

/*!
 *  \brief  create new agent
 *  \return pointer to the created agent
 */
static POSAgent* pos_create_agent(){
    POSAgent *pos_agent = nullptr;
    POS_CHECK_POINTER(pos_agent = new POSAgent());
    return pos_agent;
}


/*!
 *  \brief  destory agent
 *  \param  pos_cuda_ws pointer to the agent to be destoried
 *  \return 0 for successfully destory
 *          1 for failed
 */
static int pos_destory_agent(POSAgent* pos_agent){
    POS_CHECK_POINTER(pos_agent);
    delete pos_agent;
    return 0;
}
