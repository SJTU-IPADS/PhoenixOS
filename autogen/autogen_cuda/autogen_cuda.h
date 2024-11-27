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

#include "autogen_common.h"
#include "pos/cuda_impl/handle.h"


/*!
 *  \brief  obtain handle type id according to given string from yaml file
 *  \param  handle_type   given string
 *  \return the corresponding handle type id
 */
uint32_t get_handle_type_by_name(std::string& handle_type);
