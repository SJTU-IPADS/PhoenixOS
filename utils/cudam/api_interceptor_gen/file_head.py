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
