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
#include "pos/include/control_plane/client_control.h"

/*!
 *  \brief  route redis reply to corresponding routine
 *  \param  controller  controller instance that invoke this routine
 *  \param  reply       the raw redis reply
 *  \param  rid         the resulted routine index
 *  \return POS_SUCCESS for succesfully execution
 */
pos_retval_t pos_ctrl_client_sub_dispatcher(POSController* controller, redisReply* reply, pos_ctrlplane_routine_id_t& rid){
    pos_retval_t retval = POS_SUCCESS;

exit:
    return retval;
}


/*!
 *  \brief  register a new job to the world
 *  \param  controller      controller instance that invoke this routine
 *  \param  attributes      attributes to be published
 *  \param  key             the resulted key to publish
 *  \param  value           the resulted value to publish
 *  \return POS_SUCCESS for succesfully execution
 */
pos_retval_t pos_ctrl_client_register_job(POSController* controller, std::map<std::string,std::string>& attributes, std::string& key, std::string& value){
    pos_retval_t retval = POS_SUCCESS;
    register_context_t *reg_cxt;

    POS_CHECK_POINTER(controller);
    POS_CHECK_POINTER(reg_cxt = reinterpret_cast<register_context_t*>(priv_data));
    POS_CHECK_POINTER(reg_cxt->ip_addr);

    __check_necessary_publish_attributes(attributes, {"job_id", "client_ip", "transport"});

    // SET /JOB/[job id]/CLIENT/[client ip] "state=applying;transport=[transport type];"
    key = std::string("/JOB/") + attributes["job_id"] + std::string("/CLIENT/") + attributes["client_ip"];
    value = std::string("state=applying;transport=") + attributes["transport"] + std::string(";");

exit:
    return retval;
}


std::map<pos_ctrlplane_routine_id_t, pos_ctrlplane_pub_routine_t> client_pub_routine_map(
    {   kPOS_Ctrl_Client_Routine_Register_Job, pos_ctrl_client_register_job }
);

std::map<pos_ctrlplane_routine_id_t, pos_ctrlplane_sub_routine_t> client_sub_routine_map();
