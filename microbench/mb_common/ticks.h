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

#define POS_TSC_FREQ    2200000000

static uint64_t get_tsc(){
    uint64_t a, d;
    __asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
    return (d << 32) | a;
}

#define POS_TSC_RANGE_TO_SEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ

#define POS_TSC_RANGE_TO_MSEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ * (double)1000.0f

#define POS_TSC_RANGE_TO_USEC(e_tick, s_tick) \
    (double)(e_tick - s_tick) / (double) POS_TSC_FREQ * (double)1000000.0f

#define POS_TSC_TO_USEC(tick) \
    (double)(tick) / (double) POS_TSC_FREQ * (double)1000000.0f
