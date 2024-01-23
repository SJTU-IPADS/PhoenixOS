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
        _q = new moodycamel::ReaderWriterQueue<T*, POS_LOCKLESS_QUEUE_LEN>();
        POS_CHECK_POINTER(_q);
    }
    ~POSLockFreeQueue() = default;

    /*!
     *  \brief  generate a new queue node and append to the tail of it
     *  \param  data    the payload that the newly added node points to
     */
    void push(T* ptr){ _q->enqueue(ptr); }

    /*!
     *  \brief  obtain a pointer which points to the payload that the 
     *          head element points to
     *  \return pointer points to the first payload
     */
    T* pop(){
        T* ptr;
        if(_q->try_dequeue(ptr)){
            return ptr;
        } else {
            return nullptr;
        }
    }

    inline uint64_t len(){ return _q->size_approx(); }

 private:
    moodycamel::ReaderWriterQueue<T*, POS_LOCKLESS_QUEUE_LEN> *_q;
};
