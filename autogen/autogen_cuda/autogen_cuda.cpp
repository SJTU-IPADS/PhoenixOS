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

#include "autogen_cuda.h"


uint32_t get_handle_type_by_name(std::string& handle_type){
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
