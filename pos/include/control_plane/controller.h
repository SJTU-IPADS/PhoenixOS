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
 *  \param  priv_data       private data to invoke this routine
 *  \param  channel_name    the resulted redis channel name to publish
 *  \param  msg             the resulted message to publish to the channel
 *  \return POS_SUCCESS for succesfully execution
 */
using pos_ctrlplane_pub_routine_t = pos_retval_t(*)(
    POSController* controller, void* priv_data, std::string& channel_name, std::string& msg
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

        POS_CHECK_POINTER(redis_pub = new POSUtil_RedisPublisher());
        POS_CHECK_POINTER(redis_sub = new POSUtil_RedisSubscriber(
            /* cb */ POSController::__subscribe_callback,
            /* priv_data */ this
        ));
    }

    ~POSController() = default;

    /*!
     *  \brief  start running controller
     *  \return POS_SUCCESS for successfully running;
     *          POS_FAILED for failed raising redis publisher/subscriber
     */
    inline pos_retval_t start(){
        pos_retval_t retval = POS_SUCCESS;

        retval = redis_pub->connect_and_run();
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to connect and run redis publisher");
            goto exit;
        }

        retval = redis_sub->connect_and_run();
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("failed to connect and run redis subscriber");
            goto exit;
        }

    exit:
        return retval;
    }


    /*!
     *  \brief  call control-plane routine to publish control-plane message
     *  \param  rid         corresponding routine index
     *  \param  priv_data   private data to call the publish routine (optional)
     *  \return POS_SUCCESS for successfully publishing, otherwise there's error occurs
     */
    inline pos_retval_t call(pos_ctrlplane_routine_id_t rid, void* priv_data=nullptr){
        pos_retval_t retval = POS_SUCCESS;
        std::string channel_name, msg; 

        if(unlikely(pub_routine_map.count(rid) == 0)){
            POS_WARN_C("failed to call non-exist publish routine: rid(%u)", rid);
            retval = POS_FAILED_NOT_EXIST;
            goto exit;
        }

        channel_name.clear();
        msg.clear();

        retval = (*(pub_routine_map[rid]))(this, priv_data, channel_name, msg);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C("publish routine execute failed: rid(%u), retval(%u)", rid, retval);
            goto exit;
        }

        retval = redis_pub->publish(channel_name, msg);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C(
                "failed to publish to redis db after successful routine execution: "
                "rid(%u), retval(%u), channel_name(%s), msg(%s)", 
                rid, retval, channel_name.c_str(), msg.c_str()
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
     *  \brief  redis subscriber/publisher group
     */
    POSUtil_RedisPublisher *redis_pub;
    POSUtil_RedisSubscriber *redis_sub;

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
