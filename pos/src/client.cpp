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
#include <map>
#include <algorithm>

#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/workspace.h"
#include "pos/include/handle.h"
#include "pos/include/client.h"
#include "pos/include/api_context.h"


void POSClient::init(){
    std::map<pos_u64id_t, POSAPIContext_QE_t*> apicxt_sequence_map;
    std::multimap<pos_u64id_t, POSHandle*> missing_handle_map;

    this->init_handle_managers();
}


void POSClient::deinit(){
    this->deinit_dump_handle_managers();
}
