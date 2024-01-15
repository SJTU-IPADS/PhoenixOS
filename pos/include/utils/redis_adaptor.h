#pragma once

#include <iostream>

#include <pthread.h>
#include <semaphore.h>

#include "hiredis/async.h"
#include "hiredis/adapters/libevent.h"

#include "pos/include/common.h"
#include "pos/include/log.h"


class POSUtil_RedisModule {
 public:
    POSUtil_RedisModule(){
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

    ~POSUtil_RedisModule(){
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
        ret = pthread_create(&_event_thread, 0, &POSUtil_RedisModule::__event_thread_wrapper, this);
        if(unlikely(ret != 0)){
            POS_WARN_C_DETAIL("failed to create event thread");
            goto redis_disconnect;
        }

        // setup callbacks
        redis_retval = redisAsyncSetConnectCallback(_redis_context, &POSUtil_RedisModule::__connect_callback);
        if(unlikely(redis_retval != REDIS_OK)){
            POS_WARN_C_DETAIL(
                "failed to setup the connection callback: err(%s)", _redis_context->errstr
            );
            goto redis_disconnect;
        }
        redis_retval = redisAsyncSetDisconnectCallback(_redis_context, &POSUtil_RedisModule::__disconnect_callback);
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
     *  \note   this function should be implemented by the publisher module
     *  \return POS_SUCCESS for succesfully publishment;
     *          POS_FAILED for failed publishment
     */
    virtual pos_retval_t publish(const std::string& channel_name, const std::string& message){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  subscribe a specified channel
     *  \param  channel_name    name of the channel to subscribe
     *  \note   this function should be implemented by the subscriber module
     *  \return POS_SUCCESS for succesfully subscribing;
     *          POS_FAILED for failed subscribing
     */
    virtual pos_retval_t subscribe(const std::string& channel_name){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  actual event thread procedure
     */
    void event_proc(){
        // waiting for the semaphore to start thread processing
        sem_wait(&_event_sem);

        // block here to process
        event_base_dispatch(_event_base);
    }

 protected:
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

 private:
};


/*!
 *  \brief  publisher module for redis db 
 */
class POSUtil_RedisPublisher : public POSUtil_RedisModule {
 public:
    POSUtil_RedisPublisher() : POSUtil_RedisModule() {};
    ~POSUtil_RedisPublisher() = default;

    /*!
     *  \brief  publish new message to specified channel
     *  \param  channel_name    name of the channel to publish new message
     *  \param  message         the new message
     *  \return POS_SUCCESS for succesfully publishment;
     *          POS_FAILED for failed publishment
     */
    pos_retval_t publish(const std::string& channel_name, const std::string& message) override {
        pos_retval_t retval = POS_SUCCESS;
        int redis_retval = REDIS_OK;

        redis_retval = redisAsyncCommand(
            /* ac */ this->_redis_context,
            /* fn */ POSUtil_RedisPublisher::__command_callback,
            /* privdata */ this,
            /* format */ "PUBLISH %s %s", channel_name.c_str(), message.c_str()
        );

        if(unlikely(redis_retval != REDIS_OK)){
            POS_WARN_C("failed to publish to Redis: channel_name(%s), message(%s)", channel_name.c_str(), message.c_str());
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        return retval;
    }

 private:
    /*!
     *  \brief  callback function after issuing command to the redis db
     *  \param  redis_context   the corresponding connection context
     *  \param  reply           the reply data
     *  \param  privdata        the private data
     *  \note   the publisher won't do anything inside this callback
     */
    static void __command_callback(redisAsyncContext* redis_context, void* reply, void* privdata){
        // do nothing in the publisher
    }
};


/*!
 *  \brief  callback function for receiving updating message of the subscribed channel
 */
using pos_redis_subscriber_cbfunc_t = pos_retval_t(*)(void*, redisReply*);


/*!
 *  \brief  subsriber module for redis db 
 */
class POSUtil_RedisSubscriber : public POSUtil_RedisModule {
 public:
    POSUtil_RedisSubscriber(pos_redis_subscriber_cbfunc_t cb_func_, void* cb_priv_data_) 
        : POSUtil_RedisModule(), cb_func(cb_func_), cb_priv_data(cb_priv_data_) {};

    ~POSUtil_RedisSubscriber() = default;
    
    /*!
     *  \brief  subscribe a specified channel
     *  \param  channel_name    name of the channel to subscribe
     *  \note   this function should be implemented by the subscriber module
     *  \return POS_SUCCESS for succesfully subscribing;
     *          POS_FAILED for failed subscribing
     */
    pos_retval_t subscribe(const std::string& channel_name) override {
        pos_retval_t retval = POS_SUCCESS;
        int redis_retval = REDIS_OK;

        redis_retval = redisAsyncCommand(
            /* ac */ this->_redis_context,
            /* fn */ POSUtil_RedisSubscriber::__command_callback,
            /* privdata */ this,
            /* format */ "SUBSCRIBE %s", channel_name.c_str()
        );

        if(unlikely(redis_retval != REDIS_OK)){
            POS_WARN_C("failed to subscribe from Redis: channel_name(%s)", channel_name.c_str());
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        return retval;
    }

    pos_redis_subscriber_cbfunc_t cb_func;
    void *cb_priv_data;

 private:
    /*!
     *  \brief  callback function after issuing command to the redis db
     *  \param  redis_context   the corresponding connection context
     *  \param  reply           the reply data
     *  \param  privdata        the private data
     */
    static void __command_callback(redisAsyncContext* redis_context, void* reply, void* privdata){
        POSUtil_RedisSubscriber *self;
        redisReply *redis_reply;

        POS_CHECK_POINTER(redis_context);
        POS_CHECK_POINTER(redis_reply = reinterpret_cast<redisReply*>(reply));
        POS_CHECK_POINTER(self = reinterpret_cast<POSUtil_RedisSubscriber*>(privdata));

        if(unlikely(POS_SUCCESS != self->cb_func(self->cb_priv_data, redis_reply))){
            POS_WARN_C("failed to execute redis subscribe callback");
        }
    }
};
