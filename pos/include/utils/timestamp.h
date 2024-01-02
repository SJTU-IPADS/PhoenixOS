#pragma once

#include <algorithm>
#include <chrono>

class POSUtilTimestamp {
 public:
    /*!
     * \brief   obtain nanosecond timestamp
     * \return  nanosecond timestamp
     */
    static inline uint64_t get_timestamp_ns() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>
                (std::chrono::steady_clock::now().time_since_epoch()).count();
    }

    /*!
     * \brief   obtain microsecond timestamp
     * \return  microsecond timestamp
     */
    static inline uint64_t get_timestamp_us() {
        return std::chrono::duration_cast<std::chrono::microseconds>
                (std::chrono::steady_clock::now().time_since_epoch()).count();
    }

    /*!
     * \brief   obtain milliseconds timestamp
     * \return  milliseconds timestamp
     */
    static inline uint64_t get_timestamp_ms() {
        return std::chrono::duration_cast<std::chrono::milliseconds>
                (std::chrono::steady_clock::now().time_since_epoch()).count();
    }

    /*!
     *  \brief  ontain TSC tick
     *  \return TSC tick
     */
    static inline uint64_t get_tsc(){
        uint64_t a, d;
        __asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
        return (d << 32) | a;
    }
};

#define POS_TSC_RANGE_TO_SEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ

#define POS_TSC_RANGE_TO_MSEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ * (double)1000.0f

#define POS_TSC_RANGE_TO_USEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ * (double)1000000.0f

#define POS_TSC_TO_USEC(tick) \
    (double)(tick) / (double) POS_TSC_FREQ * (double)1000000.0f
