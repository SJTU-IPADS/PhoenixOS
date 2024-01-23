#pragma once

#include <iostream>
#include <vector>

#include <stdint.h>

#include "pos/include/common.h"
#include "pos/include/log.h"

using pos_custom_ckpt_allocate_func_t = void*(*)(uint64_t state_size);
using pos_custom_ckpt_deallocate_func_t = void(*)(void* ptr);

class POSCheckpointSlot {
 public:
    POSCheckpointSlot(uint64_t state_size) : _state_size(state_size), _custom_deallocator(nullptr) {
        if(likely(state_size > 0)){
            POS_CHECK_POINTER(_data = malloc(state_size));
        } else {
            POS_WARN_C("try to create checkpoint slot with state size 0, this is a bug");
            _data = nullptr;
        }
    }

    POSCheckpointSlot(
        uint64_t state_size,
        pos_custom_ckpt_allocate_func_t allocator,
        pos_custom_ckpt_deallocate_func_t deallocator
    ) : _state_size(state_size), _custom_deallocator(deallocator) {
        POS_CHECK_POINTER(allocator);
        if(likely(state_size > 0)){
            POS_CHECK_POINTER(_data = allocator(state_size));
        } else {
            POS_WARN_C("try to create checkpoint slot with state size 0, this is a bug");
            _data = nullptr;
        }
    }

    inline void* expose_pointer(){ return _data; }

    ~POSCheckpointSlot(){
        if(likely(_custom_deallocator != nullptr)){
            _custom_deallocator(_data);
        } else {
            // default deallocate using free
            if(unlikely(_data != nullptr && _state_size > 0)){
                free(_data);
            }
        }   
    }

 private:
    uint64_t _state_size;
    void *_data;
    pos_custom_ckpt_deallocate_func_t _custom_deallocator;
};


#if POS_CKPT_OPT_LEVAL == 1
    #include "pos/include/checkpoint_o1_o2.h"
#elif POS_CKPT_OPT_LEVAL == 2
    #include "pos/include/checkpoint_o1_o2.h"
#else // POS_CKPT_OPT_LEVAL == 0
    #include "pos/include/checkpoint_o0.h"
#endif
