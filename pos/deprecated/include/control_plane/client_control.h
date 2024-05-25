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
