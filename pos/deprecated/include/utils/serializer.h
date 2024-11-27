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
#include <string>

#include <string.h>

#include "pos/include/common.h"
#include "pos/include/log.h"

class POSUtil_Serializer {
 public:
    /*!
     *  \brief  serialize spefic field of the handle to the serilization area
     *  \param  dptr    pointer of pointer to the serilization memory for storing the field
     *  \param  sptr    address of the field to be serialized
     *  \param  size    size of the field to be serialized
     */
    static void write_field(void** dptr, const void* sptr, uint64_t size){
        POS_CHECK_POINTER(*dptr);
        POS_CHECK_POINTER(sptr);
        if(likely(size > 0)){
            memcpy(*dptr, sptr, size);
        }
        (*dptr) += size;
    }
};

class POSUtil_Deserializer {
 public:
    /*!
     *  \brief  deserialize spefic field of the handle to variable
     *  \param  var     the area to store the deserialized data
     *  \param  sptr    pointer to the pointer of the field to be read
     *  \param  size    size of the data to be deserialized
     */
    static void read_field(void* dptr, void** sptr, uint64_t size){
        POS_CHECK_POINTER(dptr);
        POS_CHECK_POINTER(*sptr);
        memcpy(dptr, *sptr, size);
        (*sptr) += size;
    }
};
