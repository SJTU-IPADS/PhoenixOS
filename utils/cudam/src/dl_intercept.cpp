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

#include <assert.h>
#include <dlfcn.h>
#include <string.h>

#include "cudam.h"

static void *(*dlopen_orig)(const char *, int) = NULL;
static int (*dlclose_orig)(void *) = NULL;
static void *dl_handle = NULL;

void *dlopen(const char *filename, int flag)
{
    void *ret = NULL;

    if (dlopen_orig == NULL) {
        if ((dlopen_orig = dlsym(RTLD_NEXT, "dlopen")) == NULL) {
            assert(0);
        }
    }

    if (filename == NULL) {
        assert(dlopen_orig != NULL);
        return dlopen_orig(filename, flag);
    }

    

    /*!
     *  \note   redirect the open of libcuda.so / libnvidia-ml.so to cudam
     *          see https://github.com/pytorch/pytorch/blob/main/c10/cuda/driver_api.cpp#L12
     */
    if (filename != NULL 
        && (
            // strcmp(filename, "libcuda.so.1") == 0
            // || strcmp(filename, "libcuda.so") == 0
            strcmp(filename, "libnvidia-ml.so.1") == 0
            || strcmp(filename, "libnvidia-ml.so") == 0
        )
    ){
        dl_handle = dlopen_orig("libcudam.so", flag);
        return dl_handle;
    } else {
        return dlopen_orig(filename, flag);
    }
}


int dlclose(void *handle)
{
    if (handle == NULL) {
        assert(0);
    } else if (dlclose_orig == NULL) {
        if ((dlclose_orig = dlsym(RTLD_NEXT, "dlclose")) == NULL) {
            assert(0);
        }
    }

    // Ignore dlclose call that would close this library
    if (dl_handle == handle) {
        return 0;
    } else {
        return dlclose_orig(handle);
    }
}
