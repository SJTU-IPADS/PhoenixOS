#pragma once

#include <iostream>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timer.h"

typedef struct test_cxt_t {
    uint64_t duration_ticks;
    POSUtilTscTimer *tsc_timer;
} test_cxt;

pos_retval_t test_cuda_malloc(test_cxt* cxt);
pos_retval_t test_cuda_free(test_cxt* cxt);
pos_retval_t test_cuda_memcpy_h2d(test_cxt* cxt);
pos_retval_t test_cuda_memcpy_d2h(test_cxt* cxt);
pos_retval_t test_cuda_memcpy_d2d(test_cxt* cxt);
pos_retval_t test_cuda_memcpy_h2d_async(test_cxt* cxt);
pos_retval_t test_cuda_memcpy_d2h_async(test_cxt* cxt);
pos_retval_t test_cuda_memcpy_d2d_async(test_cxt* cxt);
pos_retval_t test_cuda_memset_async(test_cxt* cxt);

pos_retval_t test_cuda_set_device(test_cxt* cxt);
pos_retval_t test_cuda_get_device_count(test_cxt* cxt);
pos_retval_t test_cuda_get_device_properties(test_cxt* cxt);
pos_retval_t test_cuda_get_device(test_cxt* cxt);
pos_retval_t test_cuda_device_get_attribute(test_cxt* cxt);

pos_retval_t test_cu_ctx_get_current(test_cxt* cxt);
pos_retval_t test_cuda_get_last_error(test_cxt* cxt);
pos_retval_t test_cuda_get_error_string(test_cxt* cxt);
pos_retval_t test_cuda_peek_at_last_error(test_cxt* cxt);

pos_retval_t test_cuda_launch_kernel(test_cxt* cxt);
pos_retval_t test_cuda_stream_synchronize(test_cxt* cxt);
pos_retval_t test_cuda_stream_is_capturing(test_cxt* cxt);
pos_retval_t test_cuda_event_create_with_flags(test_cxt* cxt);
pos_retval_t test_cuda_event_record(test_cxt* cxt);
pos_retval_t test_cuda_event_destory(test_cxt* cxt);
pos_retval_t test_cuda_event_query(test_cxt* cxt);
pos_retval_t test_cuda_func_get_attributes(test_cxt* cxt);
pos_retval_t test_cuda_occupancy_max_active_bpm_with_flags(test_cxt* cxt);

pos_retval_t test_cublas_create(test_cxt* cxt);
pos_retval_t test_cublas_set_stream(test_cxt* cxt);
pos_retval_t test_cublas_set_mathmode(test_cxt* cxt);
pos_retval_t test_cublas_sgemm(test_cxt* cxt);
pos_retval_t test_cublas_sgemm_stride_batched(test_cxt* cxt);
