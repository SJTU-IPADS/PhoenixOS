#include <iostream>
#include <vector>

#include <stdint.h>

#include <cuda.h>
#include <cuda_runtime.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "unittest/cuda/unittest.h"

int main(){
    std::map<uint64_t, pos_retval_t> result_map;
    bool has_error;

    POSUnitTest ut;

    has_error = ut.run_all();
    if(has_error){
        exit(1);
    }

    return 0;
}
