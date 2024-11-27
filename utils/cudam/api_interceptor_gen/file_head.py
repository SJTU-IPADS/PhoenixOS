# Copyright 2024 The PhoenixOS Authors. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

runtime = '''
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cuda_runtime.h>

#include "cudam.h"
#include "api_counter.h"

'''

driver = '''
#include <iostream>
#include <vector>
#include <cuda.h>
#include <dlfcn.h>

#include "cudam.h"
#include "api_counter.h"

'''

cublas_v2 = '''
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cublas_v2.h>

#include "cudam.h"
#include "api_counter.h"

'''

cusolver = '''
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cusolverDn.h>
#include <cusolverMg.h>
#include <cusolverRf.h>
#include <cusolverSp.h>

#include "cudam.h"
#include "api_counter.h"
'''

cudnn = '''
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cudnn.h>

#include "cudam.h"
#include "api_counter.h"
'''

curand = '''
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <curand.h>

#include "cudam.h"
#include "api_counter.h"
'''

cufft = '''
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cufft.h>
#include <cufftw.h>

#include "cudam.h"
#include "api_counter.h"
'''

nvml = '''
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <nvml.h>

#include "cudam.h"
#include "api_counter.h"
'''
