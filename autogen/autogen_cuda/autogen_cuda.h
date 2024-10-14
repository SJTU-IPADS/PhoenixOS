#pragma once

#include "autogen_common.h"
#include "pos/cuda_impl/handle.h"

static uint32_t __get_handle_type_by_name(std::string& handle_type){
    if(handle_type == std::string("cuda_context")){
        return kPOS_ResourceTypeId_CUDA_Context;
    } else if(handle_type == std::string("cuda_module")){
        return kPOS_ResourceTypeId_CUDA_Module;
    } else if(handle_type == std::string("cuda_function")){
        return kPOS_ResourceTypeId_CUDA_Function;
    } else if(handle_type == std::string("cuda_var")){
        return kPOS_ResourceTypeId_CUDA_Var;
    } else if(handle_type == std::string("cuda_device")){
        return kPOS_ResourceTypeId_CUDA_Device;
    } else if(handle_type == std::string("cuda_memory")){
        return kPOS_ResourceTypeId_CUDA_Memory;
    } else if(handle_type == std::string("cuda_stream")){
        return kPOS_ResourceTypeId_CUDA_Stream;
    } else if(handle_type == std::string("cuda_event")){
        return kPOS_ResourceTypeId_CUDA_Event;
    } else {
        POS_ERROR_DETAIL(
            "invalid parameter type detected: given_type(%s)", handle_type.c_str()
        );
    }
}


static pos_handle_source_typeid_t __get_handle_source_by_name(std::string& handle_source){
    if(handle_source == std::string("from_param")){
        return kPOS_HandleSource_FromParam;
    } else if(handle_source == std::string("to_param")){
        return kPOS_HandleSource_ToParam;
    } else if(handle_source == std::string("from_last_used")){
        return kPOS_HandleSource_FromLastUsed;
    } else {
        POS_ERROR_DETAIL(
            "invalid handle source detected: given_handle_source(%s)", handle_source.c_str()
        );
    }
}
