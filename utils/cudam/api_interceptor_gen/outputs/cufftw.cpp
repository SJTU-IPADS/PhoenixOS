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


#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cufft.h>
#include <cufftw.h>

#include "cudam.h"
#include "api_counter.h"

#undef cuserid
char * cuserid(char * __s){
    char * lretval;
    char * (*lcuserid) (char *) = (char * (*)(char *))dlsym(RTLD_NEXT, "cuserid");
    
    /* pre exeuction logics */
    ac.add_counter("cuserid", kApiTypeCuFFT);

    lretval = lcuserid(__s);
    
    /* post exeuction logics */

    return lretval;
}
#define cuserid cuserid

