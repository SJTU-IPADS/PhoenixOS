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

#include "string.h"

#include "pos/include/common.h"
#include "pos/include/utils/timestamp.h"

#include "pos/include/trace/tick.h"
#include "pos/include/trace/counter.h"

#if POS_ENABLE_TRACE

#define POS_TRACE(cond, trace_workload) if(cond){ {trace_workload} }

/* ========== tick traces ========== */
POS_TRACE_TICK_LIST_DEF(
    /* list_name */ worker,
    /* collect_interval_us */ 10000000, /* 10s */
    /* tick_list */
        /* ckpt */
        ckpt_drain,
        ckpt_cow_done,       
        ckpt_cow_wait,
        ckpt_add_done,
        ckpt_add_wait,
        ckpt_commit
);
POS_TRACE_TICK_LIST_EXTERN_DECLARE(worker);

/* ========== counter traces ========== */
POS_TRACE_COUNTER_LIST_DEF(
    /* list_name */ worker,
    /* counters */
        /* ckpt */
        ckpt_drain,
        ckpt_cow_done_size,       
        ckpt_cow_wait_size,
        ckpt_add_done_size,
        ckpt_add_wait_size,
        ckpt_commit_size
);
POS_TRACE_COUNTER_LIST_EXTERN_DECLARE(worker);

#else

#define POS_TRACE(cond, trace_workload)

#endif // POS_ENABLE_TRACE


