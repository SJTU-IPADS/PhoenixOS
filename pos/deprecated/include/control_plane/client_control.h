#pragma once

#include <iostream>

#include "pos/include/common.h"
#include "pos/include/log.h"

#include "pos/include/control_plane/controller.h"

enum pos_ctrl_client_pub_routine_t : pos_ctrlplane_routine_id_t {
    kPOS_Ctrl_Client_Routine_Register_Job = 0,
};

enum pos_ctrl_client_sub_routine_t : pos_ctrlplane_routine_id_t {
    kPOS_Ctrl_Client_Routine_Server_Notify = 0,
};

/*!
 *  \brief  route redis reply to corresponding routine
 *  \param  controller  controller instance that invoke this routine
 *  \param  reply       the raw redis reply
 *  \param  rid         the resulted routine index
 *  \return POS_SUCCESS for succesfully execution
 */
pos_retval_t pos_ctrl_client_sub_dispatcher(POSController* controller, redisReply* reply, pos_ctrlplane_routine_id_t& rid);

extern std::map<pos_ctrlplane_routine_id_t, pos_ctrlplane_pub_routine_t> client_pub_routine_map;
extern std::map<pos_ctrlplane_routine_id_t, pos_ctrlplane_sub_routine_t> client_sub_routine_map;
