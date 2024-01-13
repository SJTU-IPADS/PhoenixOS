#pragma once

#include <iostream>

#include "pos/include/utils/readerwriterqueue/atomicops.h"
#include "pos/include/utils/readerwriterqueue/readerwriterqueue.h"

#define POS_LOCKLESS_QUEUE_LEN  8192

/*!
 *  \brief  lock-free queue
 *  \tparam T   elemenet type
 */
template<typename T>
class POSLockFreeQueue {
 public:
    POSLockFreeQueue(){
        _q = new moodycamel::ReaderWriterQueue<std::shared_ptr<T>, POS_LOCKLESS_QUEUE_LEN>();
        POS_CHECK_POINTER(_q);
    }
    ~POSLockFreeQueue() = default;

    /*!
     *  \brief  generate a new queue node and append to the tail of it
     *  \param  data    the payload that the newly added node points to
     */
    void push(std::shared_ptr<T> ptr){ _q->enqueue(ptr); }

    /*!
     *  \brief  obtain a shared-pointer which points to the payload that the 
     *          head element points to
     *  \return shared-pointer points to the first payload
     */
    std::shared_ptr<T> pop(){
        std::shared_ptr<T> ptr;
        if(_q->try_dequeue(ptr)){
            return ptr;
        } else {
            return nullptr;
        }
    }

 private:
    moodycamel::ReaderWriterQueue<std::shared_ptr<T>, POS_LOCKLESS_QUEUE_LEN> *_q;
};
