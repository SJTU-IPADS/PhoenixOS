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
