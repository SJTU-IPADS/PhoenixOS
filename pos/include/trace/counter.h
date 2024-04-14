#pragma once

#include <iostream>

#include "string.h"

#include "pos/include/common.h"

// define a new list of tracing couter
#define POS_TRACE_COUNTER_LIST_DEF(list_name, ...)                              \
    typedef struct __pos_counter_list_##list_name {                             \   
        struct __data_u64 {                                                     \
            uint64_t __VA_ARGS__;                                               \
        };                                                                      \
        __data_u64 counters;                                                    \
    } __pos_counter_list_##list_name##_t;

// declare a new list of tracing counters
#define POS_TRACE_COUNTER_LIST_DECLARE(list_name)                               \
    __pos_counter_list_##list_name##_t __pcl_##list_name;

// externally declare a new list of tracing counters
#define POS_TRACE_COUNTER_LIST_EXTERN_DECLARE(list_name)                        \
    extern __pos_counter_list_##list_name##_t __pcl_##list_name;

// reset all counters
#define POS_TRACE_COUNTER_LIST_RESET(list_name)                                                         \
    memset(&(__pcl_##list_name.counters), 0, sizeof(__pos_counter_list_##list_name##_t::__data_u64));

// add value to a counter
#define POS_TRACE_COUNTER_ADD(list_name, counter_name, value)   \
    __pcl_##list_name.counters.counter_name += value;

// obtain counter value
#define POS_TRACE_COUNTER_GET(list_name, counter_name)         \
    __pcl_##list_name.counters.counter_name
