#pragma once

#include <iostream>

#include "string.h"

#include "pos/include/common.h"
#include "pos/include/utils/timestamp.h"

#include "pos/include/trace/tick.h"

#if POS_ENABLE_TRACE

#define POS_TRACE(cond, trace_workload) if(cond){ {trace_workload} }

/* tick traces */
POS_TRACE_TICK_LIST_DEF(
    /* list_name */ worker,
    /* collect_interval_us */ 10000000, /* 10s */
    /* tick_list */
        /* ckpt */
        ckpt_drain,     // duration for draining out all old kernels before ckpt starts
        ckpt_cow,       // duration for CoW on non-ckpted buffers
        ckpt_add,       // duration for asyncly adding the buffer to another on-device buffer
        ckpt_commit     // duration for commit the on-device buffer to host-side buffer
);
POS_TRACE_TICK_LIST_EXTERN_DECLARE(worker);

#else

#define POS_TRACE(cond, trace_workload)

#endif // POS_ENABLE_TRACE


