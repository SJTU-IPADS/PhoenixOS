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
        _q = new moodycamel::ReaderWriterQueue<T, POS_LOCKLESS_QUEUE_LEN>();
        POS_CHECK_POINTER(_q);
    }
    ~POSLockFreeQueue() = default;

    /*!
     *  \brief  generate a new queue node and append to the tail of it
     *  \param  data    the payload that the newly added node points to
     */
    void push(T element){ _q->enqueue(element); }

    /*!
     *  \brief  obtain a pointer which points to the payload that the 
     *          head element points to
     *  \param  element reference to the variable to stored dequeued element (if any)
     *  \return POS_SUCCESS for successfully dequeued
     *          POS_FAILED_NOT_READY for empty queue
     */
    pos_retval_t dequeue(T& element){
        if(_q->try_dequeue(element)){
            return POS_SUCCESS;
        } else {
            return POS_FAILED_NOT_READY;
        }
    }

    /*!
     *  \brief  removes the front element from the queue, if any, without returning it
     *  \return true if an element is successfully removed, false if the queue is empty
     */
    inline bool pop(){ return _q->pop(); }

    /*!
     *  \brief  return the pointer to the front element of the queue
     *  \return pointer points to the front element
     *          nullptr if the queue is empty
     */
    T* peek(){
        return _q->peek();
    }

    inline uint64_t len(){ return _q->size_approx(); }

 private:
    moodycamel::ReaderWriterQueue<T, POS_LOCKLESS_QUEUE_LEN> *_q;
};
