#pragma once

#include <iostream>

#include <pthread.h>
#include <semaphore.h>

#include "hiredis/async.h"
#include "hiredis/adapters/libevent.h"

#include "pos/include/common.h"
#include "pos/include/log.h"

/*!
 *  \brief  async callback function group
 */
using pos_redis_cb_sub = pos_retval_t(*)(void*, redisReply*); // subscribe callback


/*!
 *  \brief  callback functions for redis async adaptor
 */
typedef struct pos_redis_async_callbacks {
    pos_redis_cb_sub cb_sub;
    void *priv_data_sub;
} pos_redis_async_callbacks_t ;


/*!
 *  \brief  POS async adaptor, mainly for sub/pub
 */
class POSUtil_RedisAdaptor_Async {
 public:
    POSUtil_RedisAdaptor_Async(pos_redis_async_callbacks_t ops) : _ops(ops) {
        int ret;

        _event_base = event_base_new();
        if(unlikely(_event_base == nullptr)){
            POS_WARN_C("failed to create redis event");
            goto exit;
        }

        memset(&_event_sem, 0, sizeof(_event_sem));
        ret = sem_init(&_event_sem, 0, 0);
        if(unlikely(ret != 0)){
            POS_WARN_C("failed to initialize sem");
            goto exit;
        }

    exit:
        ;
    }

    ~POSUtil_RedisAdaptor_Async(){
        disconnect_and_stop();
        sem_destroy(_event_sem);
    }

    /*!
     *  \brief  connect to the redis db
     *  \param  ip_str  IPv4 address of the redis db to be connected
     *  \param  port    port of the redis db
     *  \return POS_SUCCESS for successfully connection;
     *          POS_FAILED for failed connection
     */
    pos_retval_t connect_and_run(const char *ip_str, uint16_t port){
        pos_retval_t retval = POS_SUCCESS;
        int redis_retval, ret;
        POS_CHECK_POINTER(ip_str);

        // connect to the redis server
        _redis_context = redisAsyncConnect(ip_str, port);
        if(unlikely(_redis_context == nullptr)){
            POS_WARN_C_DETAIL(
                "failed to connect to redis server: ip(%s), port(%u)",
                ip_str, port
            );
            retval = POS_FAILED;
            goto exit;
        }
        if(unlikely(_redis_context->err)){
            POS_WARN_C_DETAIL(
                "error occured when connect to redis server: err(%s), ip(%s), port(%u)",
                _redis_context->errstr, ip_str, port
            );
            retval = POS_FAILED;
            goto exit;
        }

        // attach the libevent base to the connection context
        redis_retval = redisLibeventAttach(_redis_context, _event_base);
        if(unlikely(redis_retval != REDIS_OK)){
            POS_WARN_C_DETAIL(
                "failed to attach libevent base to the connection context: err(%s)", _redis_context->errstr
            );
            goto redis_disconnect;
        }

        // start event processing thread
        ret = pthread_create(&_event_thread, 0, &POSUtil_RedisAdaptor_Async::__event_thread_wrapper, this);
        if(unlikely(ret != 0)){
            POS_WARN_C_DETAIL("failed to create event thread");
            goto redis_disconnect;
        }

        // setup callbacks
        redis_retval = redisAsyncSetConnectCallback(_redis_context, &POSUtil_RedisAdaptor_Async::__connect_callback);
        if(unlikely(redis_retval != REDIS_OK)){
            POS_WARN_C_DETAIL(
                "failed to setup the connection callback: err(%s)", _redis_context->errstr
            );
            goto redis_disconnect;
        }
        redis_retval = redisAsyncSetDisconnectCallback(_redis_context, &POSUtil_RedisAdaptor_Async::__disconnect_callback);
        if(unlikely(redis_retval != REDIS_OK)){
            POS_WARN_C_DETAIL(
                "failed to setup the disconnection callback: err(%s)", _redis_context->errstr
            );
            goto redis_disconnect;
        }

        // notify the event processing thread to start
        sem_post(&_event_sem);

        goto exit;

    redis_disconnect:
        retval = disconnect_and_stop();

    exit:
        return retval;
    }


    /*!
     *  \brief  disconnect from the redis server, and stop the event processing thread
     *  \return POS_SUCCESS for successfully disconnect from the redis db;
     *          POS_FAILED for failure during disconnection
     */
    pos_retval_t disconnect_and_stop(){
        pos_retval_t retval = POS_SUCCESS;
        int redis_retval = REDIS_OK;

        if(likely(_redis_context != nullptr)){
            redis_retval = redisAsyncDisconnect(_redis_context);
            if(unlikely(redis_retval != REDIS_OK)){
                POS_WARN_C_DETAIL(
                    "failed to disconnect from the redis server: err(%s)", _redis_context->errstr
                );
                retval = POS_FAILED;
                goto exit;
            }
            redisAsyncFree(_redis_context);
            _redis_context = nullptr;
        }

    exit:
        return retval;
    }


    /*!
     *  \brief  publish new message to specified channel
     *  \param  channel_name    name of the channel to publish new message
     *  \param  message         the new message
     *  \return POS_SUCCESS for succesfully execution;
     *          POS_FAILED for failed execution
     */
    pos_retval_t publish(const std::string& channel_name, const std::string& message) {
        auto __empty_callback = [](redisAsyncContext* redis_context, void* reply, void* privdata){
            // do nothing
        };
        
        return POSUtil_RedisAdaptor_Async::__exeucte_command_async(
            /* redis_context */ this->_redis_context,
            /* cb */ __empty_callback,
            /* privdata */ this,
            /* command */ std::string("PUBLISH ") + channel_name + std::string(" ") + message
        );
    }

    /*!
     *  \brief  subscribe a specified channel
     *  \param  channel_name    name of the channel to subscribe
     *  \return POS_SUCCESS for succesfully execution;
     *          POS_FAILED for failed execution
     */
    pos_retval_t subscribe(const std::string& channel_name, void* priv_data) {
        /*!
         *  \brief  callback function after receiving subscribtion message
         *  \param  redis_context   the corresponding connection context
         *  \param  reply           the reply data
         *  \param  privdata        the private data
         */
        auto __subscribe_callback = [](redisAsyncContext* redis_context, void* reply, void* priv_data){
            pos_retval_t retval;
            redisReply *redis_reply;
            POSUtil_RedisAdaptor_Async *self;
            void *priv_data;

            POS_CHECK_POINTER(redis_context);
            POS_CHECK_POINTER(redis_reply = reinterpret_cast<redisReply*>(reply));
            POS_CHECK_POINTER(self = reinterpret_cast<POSUtil_RedisAdaptor_Async*>(priv_data));

            if(likely(self->_ops.cb_sub != nullptr)){
                retval = (*(self->_ops.cb_sub))(self->_ops.priv_data_sub, redis_reply);
                if(unlikely(retval != POS_SUCCESS)){
                    POS_WARN_C("failed to execute redis subscribe callback");
                }
            }
        };

        return POSUtil_RedisAdaptor_Async::__exeucte_command_async(
            /* redis_context */ this->_redis_context,
            /* cb */ __subscribe_callback,
            /* privdata */ this,
            /* command */ std::string("SUBSCRIBE ") + channel_name
        );
    }


    /*!
     *  \brief  actual event thread procedure
     */
    void event_proc(){
        // waiting for the semaphore to start thread processing
        sem_wait(&_event_sem);

        // block here to process async event
        event_base_dispatch(_event_base);
    }

    // callback group
    pos_redis_async_callbacks_t _ops;

 private:
    // libevent base for asyncly process redis connection event
    event_base *_event_base;

    // thread for processing redis connection event
    pthread_t _event_thread;

    // semaphore for notifying the event_thread to start
    sem_t _event_sem;

    // redis connection context
    redisAsyncContext *_redis_context;

    /*!
     *  \brief  wrapper of the thread procedure
     *  \param  data    pointer to the current POSUtil_RedisPublisher instance
     */
    static void __event_thread_wrapper(void* data){
        POSUtil_RedisPublisher *self;
        POS_CHECK_POINTER(data);
        self = reinterpret_cast<POSUtil_RedisPublisher*>(data);
        return self->event_proc();
    }

    /*!
     *  \brief  callback function after attempting connect to redis db
     *  \param  redis_context   the corresponding connection context
     *  \param  status          status code of the connection
     */
    static void __connect_callback(redisAsyncContext* redis_context, int status){
        if(likely(status == REDIS_OK)){
            POS_LOG_C("publisher connect to redis server");
        } else {
            POS_WARN_C_DETAIL("publisher failed to connect the redis server: err(%s)",
                _redis_context->errstr
            );
        }
    }

    /*!
     *  \brief  callback function after attempting disconnect to redis db
     *  \param  redis_context   the corresponding connection context
     *  \param  status          status code of the disconnection
     */
    static void __disconnect_callback(redisAsyncContext* redis_context, int status){
        if(likely(status == REDIS_OK)){
            POS_LOG_C("publisher disconnect from the redis server");
        } else {
            // TODO: should we try reconnect here?
            POS_WARN_C_DETAIL("publisher failed to disconnect from the redis server: err(%s)",
                _redis_context->errstr
            );
        }
    }

    using pos_redis_command_callback_func_t 
        = void(*)(redisAsyncContext* redis_context, void* reply, void* privdata);

    /*!
     *  \brief  asyncly execute redis command
     *  \param  redis_context   the corresponding connection context
     *  \param  cb              callback function after the execution of redis command
     *  \param  privdata        private data passed into the callback function
     *  \param  command         command to be executed
     *  \return POS_SUSSCESS for successfully execution, POS_FAILED for failure
     */
    static pos_retval_t __exeucte_command_async(
        redisAsyncContext* redis_context, pos_redis_command_callback_func_t cb,
        void* privdata, std::string& command
    ){
        pos_retval_t retval = POS_SUCCESS;
        int redis_retval = REDIS_OK;

        redis_retval = redisAsyncCommand(
            /* ac */ redis_context,
            /* fn */ cb,
            /* privdata */ privdata,
            /* format */ command.c_str()
        );

        if(unlikely(redis_retval != REDIS_OK)){
            POS_WARN_C("failed to execute redis command (%s)", command.c_str());
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        return retval;
    }
};


/*!
 *  \brief  POS sync adaptor, mainly for set/get/pub
 */
class POSUtil_RedisAdaptor {
 public:
    POSUtil_RedisAdaptor(){}
    ~POSUtil_RedisAdaptor(){
        disconnect();
    }

    /*!
     *  \brief  connect to the redis db
     *  \param  ip_str  IPv4 address of the redis db to be connected
     *  \param  port    port of the redis db
     *  \return POS_SUCCESS for successfully connection;
     *          POS_FAILED for failed connection
     */
    pos_retval_t connect(const char *ip_str, uint16_t port){
        pos_retval_t retval = POS_SUCCESS;
        int redis_retval, ret;
        POS_CHECK_POINTER(ip_str);

        _redis_context = redisConnect(ip_str, port);
        if(unlikely(_redis_context == nullptr)){
            POS_WARN_C_DETAIL(
                "failed to connect to redis server: ip(%s), port(%u)",
                ip_str, port
            );
            retval = POS_FAILED;
            goto exit;
        }
        if(unlikely(_redis_context->err)){
            POS_WARN_C_DETAIL(
                "error occured when connect to redis server: err(%s), ip(%s), port(%u)",
                _redis_context->errstr, ip_str, port
            );
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        return retval;
    }

    /*!
     *  \brief  disconnect from the redis server
     *  \return always POS_SUCCESS
     */
    pos_retval_t disconnect(){
        pos_retval_t retval = POS_SUCCESS;

        if(likely(_redis_context != nullptr)){
            redisFree(_redis_context);
            _redis_context = nullptr;
        }

    exit:
        return retval;
    }

    /*!
     *  \brief  publish new message to specified channel
     *  \param  channel_name    name of the channel to publish new message
     *  \param  message         the new message
     *  \return POS_SUCCESS for succesfully execution;
     *          POS_FAILED for failed execution
     */
    pos_retval_t publish(const std::string& channel_name, const std::string& message) {
        return POSUtil_RedisAdaptor::__exeucte_command(
            /* redis_context */ _redis_context,
            /* command */ std::string("PUBLISH ") + channel_name + std::string(" ") + message
        );
    }

    /*!
     *  \brief  asyncly set a new value to the key
     *  \param  key     the key to be configured
     *  \param  value   the new value to be set
     *  \ref    to set with expire: http://doc.redisfans.com/string/set.html
     *  \return POS_SUCCESS for succesfully execution;
     *          POS_FAILED for failed execution
     */
    pos_retval_t set(const std::string& key, const std::string& value){
        return POSUtil_RedisAdaptor::__exeucte_command(
            /* redis_context */ _redis_context,
            /* command */ std::string("SET ") + key + std::string(" ") + value
        );
    }

    /*!
     *  \brief  get the value of a key
     *  \param  key     the key to be queried
     *  \param  value   obtained value
     *  \return POS_SUCCESS for succesfully execution;
     *          POS_FAILED for failed execution
     */
    pos_retval_t get(const std::string& key, const std::string& value){
        pos_retval_t retval;
        redisReply reply;

        retval = POSUtil_RedisAdaptor::__exeucte_command(
            /* redis_context */ _redis_context,
            /* command */ std::string("GET ") + key,
            /* reply */ &reply
        );

        if(likely(retval == POS_SUCCESS)){
            POS_CHECK_POINTER(reply);
            value = std::string(reply->str);
            freeReplyObject(reply);
        }
    
        return retval;
    }

 private:
    // redis connection context
    redisContext *_redis_context;

    /*!
     *  \brief  execute redis command
     *  \param  redis_context   the corresponding connection context
     *  \param  command         command to be executed
     *  \param  reply           pointer to receive the redis reply
     *  \return POS_SUSSCESS for successfully execution, POS_FAILED for failure
     */
    static pos_retval_t __exeucte_command(
        redisAsyncContext* redis_context, std::string& command, redisReply **reply=nullptr;
    ){
        pos_retval_t retval = POS_SUCCESS;
        redisReply __reply;

        __reply = redisCommand(
            /* ac */ redis_context,
            /* format */ command.c_str()
        );

        if(unlikely(__reply == nullptr)){
            POS_WARN_C(
                "failed to execute redis command: command(%s), error(%s)",
                command.c_str(), redis_context->errstr
            );
            retval = POS_FAILED;
            goto exit;
        }

        if(likely(reply != nullptr)){
            *reply = __reply;
        }

    exit:
        return retval;
    }
};
