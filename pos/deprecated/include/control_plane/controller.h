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
#include <vector>
#include <map>

#include <stdint.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/redis_adaptor.h"


/*!
 *  \brief  type for indexing routine of control plane
 */
using pos_ctrlplane_routine_id_t = uint32_t;


/*!
 *  \brief  function signature for routing redis reply to corresponding routine
 *  \param  controller  controller instance that invoke this routine
 *  \param  reply       the raw redis reply
 *  \param  rid         the resulted routine index
 *  \return POS_SUCCESS for succesfully execution
 */
using pos_ctrlplane_sub_dispatcher_t = pos_retval_t(*)(
    POSController* controller, redisReply* reply, pos_ctrlplane_routine_id_t& rid
);


/*!
 *  \brief  function signature of subscribe callback
 *  \param  controller  controller instance that invoke this routine
 *  \param  reply       the raw redis reply
 *  \return POS_SUCCESS for succesfully execution
 */
using pos_ctrlplane_sub_routine_t = pos_retval_t(*)(POSController* controller, redisReply* reply);


/*!
 *  \brief  function signature for publishing control-plane message
 *  \param  controller      controller instance that invoke this routine
 *  \param  attributes      attributes to be published
 *  \param  key             the resulted key to publish
 *  \param  value           the resulted value to publish
 *  \return POS_SUCCESS for succesfully execution
 */
using pos_ctrlplane_pub_routine_t = pos_retval_t(*)(
    POSController* controller, std::map<std::string,std::string>& attributes, std::string& key, std::string& value
);


/*!
 *  \brief  north controller
 */
class POSController {
 public:
    POSController(
        std::map<pos_ctrlplane_routine_id_t, pos_ctrlplane_pub_routine_t>& pub_rm,
        std::map<pos_ctrlplane_routine_id_t, pos_ctrlplane_sub_routine_t>& sub_rm,
        pos_ctrlplane_sub_dispatcher_t sub_dispatcher_, void* entrance_
    )
        : pub_routine_map(pub_rm), sub_routine_map(sub_rm), 
          sub_dispatcher(sub_dispatcher_), entrance(entrance_)
    {
        POS_CHECK_POINTER(sub_dispatcher);
        POS_CHECK_POINTER(redis_adaptor_async = new POSUtil_RedisAdaptor_Async({
            /* cb_sub */ POSController::__subscribe_callback,
            /* priv_data_sub */ this
        }));
        POS_CHECK_POINTER(redis_adaptor = new POSUtil_RedisAdaptor());
    }

    ~POSController(){
        redis_adaptor_async->disconnect_and_stop();
        redis_adaptor->disconnect();
    };

    /*!
     *  \brief  start running controller
     *  \return POS_SUCCESS for successfully running;
     *          POS_FAILED for failed raising redis adaptors
     */
    inline pos_retval_t start(std::string& redis_ip, uint16_t redis_port){
        pos_retval_t retval = POS_SUCCESS;

        retval = redis_adaptor_async->connect_and_run(redis_ip.c_str(), redis_port);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to connect and run redis async adaptor");
            goto exit;
        }

        retval = redis_adaptor->connect(redis_ip.c_str(), redis_port);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to connect redis adaptor");
            goto disconnect_async_adaptor;
        }

        goto exit;

    disconnect_async_adaptor:
        redis_adaptor_async->disconnect_and_stop();

    exit:
        return retval;
    }


    /*!
     *  \brief  call control-plane routine to publish control-plane message
     *  \param  rid         corresponding routine index
     *  \param  attributes      attributes to be published
     *  \return POS_SUCCESS for successfully publishing, otherwise there's error occurs
     */
    inline pos_retval_t publish(pos_ctrlplane_routine_id_t rid, std::map<std::string,std::string>& attributes){
        pos_retval_t retval = POS_SUCCESS;
        std::string key, value; 

        if(unlikely(pub_routine_map.count(rid) == 0)){
            POS_WARN_C("failed to call non-exist publish routine: rid(%u)", rid);
            retval = POS_FAILED_NOT_EXIST;
            goto exit;
        }

        key.clear();
        value.clear();

        retval = (*(pub_routine_map[rid]))(this, attributes, key, value);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("publish routine execute failed: rid(%u), retval(%u)", rid, retval);
            goto exit;
        }

        retval = redis_adaptor->set(key, value);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C(
                "failed to publish to redis db after successful routine execution: "
                "rid(%u), retval(%u), key(%s), value(%s)", 
                rid, retval, key.c_str(), value.c_str()
            );
            goto exit;
        }

    exit:
        return retval;
    }


    /*!
     *  \brief  map of controller routines (both publish and subscribe)
     */
    std::map<pos_ctrlplane_routine_id_t, pos_ctrlplane_pub_routine_t> pub_routine_map;
    std::map<pos_ctrlplane_routine_id_t, pos_ctrlplane_sub_routine_t> sub_routine_map;

    /*!
     *  \brief  dispatcher for subscribing msg routing
     */
    pos_ctrlplane_sub_dispatcher_t sub_dispatcher;

    /*!
     *  \brief  redis adaptors
     */
    POSUtil_RedisAdaptor_Async *redis_adaptor_async;
    POSUtil_RedisAdaptor *redis_adaptor;

    /*!
     *  \brief  entrance to control the system
     *  \note   [1] for POS-server, this pointer should point to POSWorkspace;
     *          [2] for POS-client, this pointer should point to POSAgent;
     *          [3] for POS-central_service, this pointer should point to ? 
     */
    void *entrance;

 private:
    /*!
     *  \brief  callback function when receive subscribe reply from redis db
     *  \param  priv_data   pointer to the current POSController instance
     *  \param  reply       the raw redis reply
     *  \return POS_SUCCESS for successfully subscribing callback execution
     */
    static pos_retval_t __subscribe_callback(void* priv_data, redisReply* reply){
        pos_retval_t retval = POS_SUCCESS;
        POSController *self;
        pos_ctrlplane_routine_id_t rid;

        POS_CHECK_POINTER(self = reinterpret_cast<POSController*>(priv_data));
        POS_CHECK_POINTER(reply);

        // parse reply
        retval = self->sub_dispatcher(self, reply, rid);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to dispatch subscrition reply to corresponding routine");
            goto exit;
        }

        // route to corresponding routine for further processing
        if(unlikely(sub_routine_map.count(rid) == 0)){
            POS_WARN_C("failed to call non-exist subscrition routine: rid(%u)", rid);
            retval = POS_FAILED_NOT_EXIST;
            goto exit;
        }

        retval = (*(sub_routine_map[rid]))(this, reply);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("subscrib routine execute failed: rid(%u), retval(%u)", rid, retval);
            goto exit;
        }

    exit:
        return retval;
    }
};

/*! 
 *  \brief  check necessary attributes to publish to the redis db (internal used)
 *  \param  attributes  given attributes
 *  \param  strs        necessary attribute keys
 *  \note   this function will fatal when miss necessary attribute
 */
static inline void __check_necessary_publish_attributes(std::vector<std::string,std::string>& attributes, std::vector<std::string> strs){
    for(auto &str : strs){
        if(unlikely(attributes.count(str) == 0)){
            POS_ERROR_C_DETAIL("non-comprehensive attributes provided to publish, this is a bug: attribute(%s)", str.c_str());
        }
    }
}
