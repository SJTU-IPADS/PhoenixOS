#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "pos/include/common.h"
#include "pos/include/log.h"

#include "pos/cuda_impl/api_index.h"

#include "unittest/cuda/apis/base.h"
#include "unittest/cuda/include/utils.h"



using pos_unittest_func_t = pos_retval_t(*)(test_cxt*);

class POSUnitTest {
 public:
    POSUnitTest(){
        insert_unittest_funcs();
    }
    ~POSUnitTest() = default;

    void insert_unittest_funcs(){
        func_map.insert({
            /* memory related apis */
            {   CUDA_MALLOC, test_cuda_malloc },
            {   CUDA_FREE, test_cuda_free },
            {   CUDA_MEMCPY_HTOD, test_cuda_memcpy_h2d },
            {   CUDA_MEMCPY_DTOH, test_cuda_memcpy_d2h },
            {   CUDA_MEMCPY_DTOD, test_cuda_memcpy_d2d },
            {   CUDA_MEMCPY_HTOD_ASYNC, test_cuda_memcpy_h2d_async },
            {   CUDA_MEMCPY_DTOH_ASYNC, test_cuda_memcpy_d2h_async },
            {   CUDA_MEMCPY_DTOD_ASYNC, test_cuda_memcpy_d2d_async },

            /* device related apis */
            {   CUDA_SET_DEVICE, test_cuda_set_device },
            {   CUDA_GET_DEVICE_COUNT, test_cuda_get_device_count },
            {   CUDA_GET_DEVICE_PROPERTIES, test_cuda_get_device_properties },
            {   CUDA_GET_DEVICE, test_cuda_get_device },

            /* context related apis */
            {   CUDA_GET_LAST_ERROR, test_cuda_get_last_error },
            {   CUDA_GET_ERROR_STRING, test_cuda_get_error_string },

            /* kernel related apis */
            {   CUDA_LAUNCH_KERNEL, test_cuda_launch_kernel },
            {   CUDA_STREAM_SYNCHRONIZE, test_cuda_stream_synchronize },
            {   CUDA_STREAM_IS_CAPTURING, test_cuda_stream_is_capturing },
            {   CUDA_EVENT_CREATE, test_cuda_event_create_record_destory },
            
            /* cublas apis */
            {   rpc_cublasCreate, test_cublas_create },
            {   rpc_cublasSetStream, test_cublas_set_stream },
            {   rpc_cublasSetMathMode, test_cublas_set_mathmode },
        });
    }

    bool run_all(){
        pos_retval_t retval;
        bool has_error = false;
        std::map<uint64_t, pos_unittest_func_t>::iterator iter;

        for(iter=func_map.begin(); iter!=func_map.end(); iter++){
            test_cxt cxt = {0};
            retval = run_one(iter->first, &cxt);
            POS_LOG(
                "API(%lu): status = %s(%d), duration = %lf us",
                iter->first,
                retval == POS_SUCCESS ? "success" : "failed",
                retval,
                POS_TSC_TO_USEC(cxt.duration_ticks)
            );
            if(unlikely(retval != POS_SUCCESS)){
                has_error = true;
            }
        }

        return has_error;
    }

    pos_retval_t run_one(uint64_t api_id, test_cxt* cxt){
        
        if(unlikely(func_map.count(api_id) == 0)){
            POS_ERROR_C("no unit test function registered: api_id(%lu)", api_id);
        }

        return (*func_map[api_id])(cxt);
    }

 private:
    std::map<uint64_t, pos_unittest_func_t> func_map;
};