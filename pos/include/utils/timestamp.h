#pragma once

#include <algorithm>
#include <chrono>
#include <thread>

#include "pos/include/log.h"

#define POS_TSC_RANGE_TO_MSEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ * (double)1000.0f

#define POS_TSC_RANGE_TO_USEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ * (double)1000000.0f

#define POS_TSC_TO_USEC(tick) \
    (double)(tick) / (double) POS_TSC_FREQ * (double)1000000.0f

#define POS_USEC_TO_TSC(usec) \
    (double)(usec) / (double)1000000.0f * (double) POS_TSC_FREQ

#define POS_SEC_TO_TSC(sec) \
    sec * POS_TSC_FREQ

#define POS_TSC_TO_SEC(tsc) \
    (double)(tsc) / (double) POS_TSC_FREQ

class POSUtilTimestamp {
 public:
    /*!
     *  \brief  ontain TSC tick
     *  \return TSC tick
     */
    static inline uint64_t get_tsc(){
        uint64_t a, d;
        __asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
        return (d << 32) | a;
    }

    /*!
     *  \brief  delay specified microsecond
     *  \param  duration_us specified microsecond
     */
    static inline void delay_us(uint32_t microseconds){
        std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
    }
};
