# 1 "CMakeCUDACompilerId.cu"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
# 1
#pragma GCC diagnostic push
# 1
#pragma GCC diagnostic ignored "-Wunused-variable"
# 1
#pragma GCC diagnostic ignored "-Wunused-function"
# 1
static char __nv_inited_managed_rt = 0; static void **__nv_fatbinhandle_for_managed_rt; static void __nv_save_fatbinhandle_for_managed_rt(void **in){__nv_fatbinhandle_for_managed_rt = in;} static char __nv_init_managed_rt_with_module(void **); static inline void __nv_init_managed_rt(void) { __nv_inited_managed_rt = (__nv_inited_managed_rt ? __nv_inited_managed_rt                 : __nv_init_managed_rt_with_module(__nv_fatbinhandle_for_managed_rt));}
# 1
#pragma GCC diagnostic pop
# 1
#pragma GCC diagnostic ignored "-Wunused-variable"

# 1
#define __nv_is_extended_device_lambda_closure_type(X) false
#define __nv_is_extended_host_device_lambda_closure_type(X) false
#if defined(__nv_is_extended_device_lambda_closure_type) && defined(__nv_is_extended_host_device_lambda_closure_type)
#endif

# 1
# 61 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
#pragma GCC diagnostic push
# 64
#pragma GCC diagnostic ignored "-Wunused-function"
# 66 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_types.h"
#if 0
# 66
enum cudaRoundMode { 
# 68
cudaRoundNearest, 
# 69
cudaRoundZero, 
# 70
cudaRoundPosInf, 
# 71
cudaRoundMinInf
# 72
}; 
#endif
# 98 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 98
struct char1 { 
# 100
signed char x; 
# 101
}; 
#endif
# 103 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 103
struct uchar1 { 
# 105
unsigned char x; 
# 106
}; 
#endif
# 109 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 109
struct __attribute((aligned(2))) char2 { 
# 111
signed char x, y; 
# 112
}; 
#endif
# 114 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 114
struct __attribute((aligned(2))) uchar2 { 
# 116
unsigned char x, y; 
# 117
}; 
#endif
# 119 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 119
struct char3 { 
# 121
signed char x, y, z; 
# 122
}; 
#endif
# 124 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 124
struct uchar3 { 
# 126
unsigned char x, y, z; 
# 127
}; 
#endif
# 129 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 129
struct __attribute((aligned(4))) char4 { 
# 131
signed char x, y, z, w; 
# 132
}; 
#endif
# 134 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 134
struct __attribute((aligned(4))) uchar4 { 
# 136
unsigned char x, y, z, w; 
# 137
}; 
#endif
# 139 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 139
struct short1 { 
# 141
short x; 
# 142
}; 
#endif
# 144 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 144
struct ushort1 { 
# 146
unsigned short x; 
# 147
}; 
#endif
# 149 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 149
struct __attribute((aligned(4))) short2 { 
# 151
short x, y; 
# 152
}; 
#endif
# 154 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 154
struct __attribute((aligned(4))) ushort2 { 
# 156
unsigned short x, y; 
# 157
}; 
#endif
# 159 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 159
struct short3 { 
# 161
short x, y, z; 
# 162
}; 
#endif
# 164 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 164
struct ushort3 { 
# 166
unsigned short x, y, z; 
# 167
}; 
#endif
# 169 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 169
struct __attribute((aligned(8))) short4 { short x; short y; short z; short w; }; 
#endif
# 170 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 170
struct __attribute((aligned(8))) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; }; 
#endif
# 172 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 172
struct int1 { 
# 174
int x; 
# 175
}; 
#endif
# 177 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 177
struct uint1 { 
# 179
unsigned x; 
# 180
}; 
#endif
# 182 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 182
struct __attribute((aligned(8))) int2 { int x; int y; }; 
#endif
# 183 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 183
struct __attribute((aligned(8))) uint2 { unsigned x; unsigned y; }; 
#endif
# 185 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 185
struct int3 { 
# 187
int x, y, z; 
# 188
}; 
#endif
# 190 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 190
struct uint3 { 
# 192
unsigned x, y, z; 
# 193
}; 
#endif
# 195 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 195
struct __attribute((aligned(16))) int4 { 
# 197
int x, y, z, w; 
# 198
}; 
#endif
# 200 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 200
struct __attribute((aligned(16))) uint4 { 
# 202
unsigned x, y, z, w; 
# 203
}; 
#endif
# 205 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 205
struct long1 { 
# 207
long x; 
# 208
}; 
#endif
# 210 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 210
struct ulong1 { 
# 212
unsigned long x; 
# 213
}; 
#endif
# 220 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 220
struct __attribute((aligned((2) * sizeof(long)))) long2 { 
# 222
long x, y; 
# 223
}; 
#endif
# 225 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 225
struct __attribute((aligned((2) * sizeof(unsigned long)))) ulong2 { 
# 227
unsigned long x, y; 
# 228
}; 
#endif
# 232 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 232
struct long3 { 
# 234
long x, y, z; 
# 235
}; 
#endif
# 237 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 237
struct ulong3 { 
# 239
unsigned long x, y, z; 
# 240
}; 
#endif
# 242 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 242
struct __attribute((aligned(16))) long4 { 
# 244
long x, y, z, w; 
# 245
}; 
#endif
# 247 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 247
struct __attribute((aligned(16))) ulong4 { 
# 249
unsigned long x, y, z, w; 
# 250
}; 
#endif
# 252 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 252
struct float1 { 
# 254
float x; 
# 255
}; 
#endif
# 274 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 274
struct __attribute((aligned(8))) float2 { float x; float y; }; 
#endif
# 279 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 279
struct float3 { 
# 281
float x, y, z; 
# 282
}; 
#endif
# 284 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 284
struct __attribute((aligned(16))) float4 { 
# 286
float x, y, z, w; 
# 287
}; 
#endif
# 289 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 289
struct longlong1 { 
# 291
long long x; 
# 292
}; 
#endif
# 294 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 294
struct ulonglong1 { 
# 296
unsigned long long x; 
# 297
}; 
#endif
# 299 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 299
struct __attribute((aligned(16))) longlong2 { 
# 301
long long x, y; 
# 302
}; 
#endif
# 304 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 304
struct __attribute((aligned(16))) ulonglong2 { 
# 306
unsigned long long x, y; 
# 307
}; 
#endif
# 309 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 309
struct longlong3 { 
# 311
long long x, y, z; 
# 312
}; 
#endif
# 314 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 314
struct ulonglong3 { 
# 316
unsigned long long x, y, z; 
# 317
}; 
#endif
# 319 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 319
struct __attribute((aligned(16))) longlong4 { 
# 321
long long x, y, z, w; 
# 322
}; 
#endif
# 324 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 324
struct __attribute((aligned(16))) ulonglong4 { 
# 326
unsigned long long x, y, z, w; 
# 327
}; 
#endif
# 329 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 329
struct double1 { 
# 331
double x; 
# 332
}; 
#endif
# 334 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 334
struct __attribute((aligned(16))) double2 { 
# 336
double x, y; 
# 337
}; 
#endif
# 339 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 339
struct double3 { 
# 341
double x, y, z; 
# 342
}; 
#endif
# 344 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 344
struct __attribute((aligned(16))) double4 { 
# 346
double x, y, z, w; 
# 347
}; 
#endif
# 361 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef char1 
# 361
char1; 
#endif
# 362 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uchar1 
# 362
uchar1; 
#endif
# 363 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef char2 
# 363
char2; 
#endif
# 364 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uchar2 
# 364
uchar2; 
#endif
# 365 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef char3 
# 365
char3; 
#endif
# 366 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uchar3 
# 366
uchar3; 
#endif
# 367 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef char4 
# 367
char4; 
#endif
# 368 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uchar4 
# 368
uchar4; 
#endif
# 369 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef short1 
# 369
short1; 
#endif
# 370 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ushort1 
# 370
ushort1; 
#endif
# 371 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef short2 
# 371
short2; 
#endif
# 372 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ushort2 
# 372
ushort2; 
#endif
# 373 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef short3 
# 373
short3; 
#endif
# 374 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ushort3 
# 374
ushort3; 
#endif
# 375 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef short4 
# 375
short4; 
#endif
# 376 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ushort4 
# 376
ushort4; 
#endif
# 377 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef int1 
# 377
int1; 
#endif
# 378 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uint1 
# 378
uint1; 
#endif
# 379 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef int2 
# 379
int2; 
#endif
# 380 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uint2 
# 380
uint2; 
#endif
# 381 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef int3 
# 381
int3; 
#endif
# 382 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uint3 
# 382
uint3; 
#endif
# 383 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef int4 
# 383
int4; 
#endif
# 384 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uint4 
# 384
uint4; 
#endif
# 385 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef long1 
# 385
long1; 
#endif
# 386 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulong1 
# 386
ulong1; 
#endif
# 387 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef long2 
# 387
long2; 
#endif
# 388 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulong2 
# 388
ulong2; 
#endif
# 389 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef long3 
# 389
long3; 
#endif
# 390 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulong3 
# 390
ulong3; 
#endif
# 391 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef long4 
# 391
long4; 
#endif
# 392 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulong4 
# 392
ulong4; 
#endif
# 393 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef float1 
# 393
float1; 
#endif
# 394 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef float2 
# 394
float2; 
#endif
# 395 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef float3 
# 395
float3; 
#endif
# 396 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef float4 
# 396
float4; 
#endif
# 397 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef longlong1 
# 397
longlong1; 
#endif
# 398 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulonglong1 
# 398
ulonglong1; 
#endif
# 399 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef longlong2 
# 399
longlong2; 
#endif
# 400 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulonglong2 
# 400
ulonglong2; 
#endif
# 401 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef longlong3 
# 401
longlong3; 
#endif
# 402 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulonglong3 
# 402
ulonglong3; 
#endif
# 403 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef longlong4 
# 403
longlong4; 
#endif
# 404 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulonglong4 
# 404
ulonglong4; 
#endif
# 405 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef double1 
# 405
double1; 
#endif
# 406 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef double2 
# 406
double2; 
#endif
# 407 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef double3 
# 407
double3; 
#endif
# 408 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef double4 
# 408
double4; 
#endif
# 416 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 416
struct dim3 { 
# 418
unsigned x, y, z; 
# 430
}; 
#endif
# 432 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef dim3 
# 432
dim3; 
#endif
# 149 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3
typedef long ptrdiff_t; 
# 216 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3
typedef unsigned long size_t; 
#if !defined(__CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__)
#define __CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__
#endif
#include "crt/host_runtime.h"
# 437 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3
typedef 
# 426 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3
struct { 
# 427
long long __max_align_ll __attribute((__aligned__(__alignof__(long long)))); 
# 428
long double __max_align_ld __attribute((__aligned__(__alignof__(long double)))); 
# 437 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3
} max_align_t; 
# 444
typedef __decltype((nullptr)) nullptr_t; 
# 197 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 197
enum cudaError { 
# 204
cudaSuccess, 
# 210
cudaErrorInvalidValue, 
# 216
cudaErrorMemoryAllocation, 
# 222
cudaErrorInitializationError, 
# 229
cudaErrorCudartUnloading, 
# 236
cudaErrorProfilerDisabled, 
# 244
cudaErrorProfilerNotInitialized, 
# 251
cudaErrorProfilerAlreadyStarted, 
# 258
cudaErrorProfilerAlreadyStopped, 
# 267 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorInvalidConfiguration, 
# 273
cudaErrorInvalidPitchValue = 12, 
# 279
cudaErrorInvalidSymbol, 
# 287
cudaErrorInvalidHostPointer = 16, 
# 295
cudaErrorInvalidDevicePointer, 
# 301
cudaErrorInvalidTexture, 
# 307
cudaErrorInvalidTextureBinding, 
# 314
cudaErrorInvalidChannelDescriptor, 
# 320
cudaErrorInvalidMemcpyDirection, 
# 330 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorAddressOfConstant, 
# 339 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorTextureFetchFailed, 
# 348 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorTextureNotBound, 
# 357 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorSynchronizationError, 
# 363
cudaErrorInvalidFilterSetting, 
# 369
cudaErrorInvalidNormSetting, 
# 377
cudaErrorMixedDeviceExecution, 
# 385
cudaErrorNotYetImplemented = 31, 
# 394 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorMemoryValueTooLarge, 
# 401
cudaErrorStubLibrary = 34, 
# 408
cudaErrorInsufficientDriver, 
# 415
cudaErrorCallRequiresNewerDriver, 
# 421
cudaErrorInvalidSurface, 
# 427
cudaErrorDuplicateVariableName = 43, 
# 433
cudaErrorDuplicateTextureName, 
# 439
cudaErrorDuplicateSurfaceName, 
# 449 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorDevicesUnavailable, 
# 462 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorIncompatibleDriverContext = 49, 
# 468
cudaErrorMissingConfiguration = 52, 
# 477 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorPriorLaunchFailure, 
# 484
cudaErrorLaunchMaxDepthExceeded = 65, 
# 492
cudaErrorLaunchFileScopedTex, 
# 500
cudaErrorLaunchFileScopedSurf, 
# 515 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorSyncDepthExceeded, 
# 527 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorLaunchPendingCountExceeded, 
# 533
cudaErrorInvalidDeviceFunction = 98, 
# 539
cudaErrorNoDevice = 100, 
# 545
cudaErrorInvalidDevice, 
# 550
cudaErrorDeviceNotLicensed, 
# 559 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorSoftwareValidityNotEstablished, 
# 564
cudaErrorStartupFailure = 127, 
# 569
cudaErrorInvalidKernelImage = 200, 
# 579 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorDeviceUninitialized, 
# 584
cudaErrorMapBufferObjectFailed = 205, 
# 589
cudaErrorUnmapBufferObjectFailed, 
# 595
cudaErrorArrayIsMapped, 
# 600
cudaErrorAlreadyMapped, 
# 608
cudaErrorNoKernelImageForDevice, 
# 613
cudaErrorAlreadyAcquired, 
# 618
cudaErrorNotMapped, 
# 624
cudaErrorNotMappedAsArray, 
# 630
cudaErrorNotMappedAsPointer, 
# 636
cudaErrorECCUncorrectable, 
# 642
cudaErrorUnsupportedLimit, 
# 648
cudaErrorDeviceAlreadyInUse, 
# 654
cudaErrorPeerAccessUnsupported, 
# 660
cudaErrorInvalidPtx, 
# 665
cudaErrorInvalidGraphicsContext, 
# 671
cudaErrorNvlinkUncorrectable, 
# 678
cudaErrorJitCompilerNotFound, 
# 685
cudaErrorUnsupportedPtxVersion, 
# 692
cudaErrorJitCompilationDisabled, 
# 697
cudaErrorInvalidSource = 300, 
# 702
cudaErrorFileNotFound, 
# 707
cudaErrorSharedObjectSymbolNotFound, 
# 712
cudaErrorSharedObjectInitFailed, 
# 717
cudaErrorOperatingSystem, 
# 724
cudaErrorInvalidResourceHandle = 400, 
# 730
cudaErrorIllegalState, 
# 737
cudaErrorSymbolNotFound = 500, 
# 745
cudaErrorNotReady = 600, 
# 753
cudaErrorIllegalAddress = 700, 
# 762 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorLaunchOutOfResources, 
# 773 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorLaunchTimeout, 
# 779
cudaErrorLaunchIncompatibleTexturing, 
# 786
cudaErrorPeerAccessAlreadyEnabled, 
# 793
cudaErrorPeerAccessNotEnabled, 
# 806 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorSetOnActiveProcess = 708, 
# 813
cudaErrorContextIsDestroyed, 
# 820
cudaErrorAssert, 
# 827
cudaErrorTooManyPeers, 
# 833
cudaErrorHostMemoryAlreadyRegistered, 
# 839
cudaErrorHostMemoryNotRegistered, 
# 848 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorHardwareStackError, 
# 856
cudaErrorIllegalInstruction, 
# 865 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorMisalignedAddress, 
# 876 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorInvalidAddressSpace, 
# 884
cudaErrorInvalidPc, 
# 895 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorLaunchFailure, 
# 904 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorCooperativeLaunchTooLarge, 
# 909
cudaErrorNotPermitted = 800, 
# 915
cudaErrorNotSupported, 
# 924 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorSystemNotReady, 
# 931
cudaErrorSystemDriverMismatch, 
# 940 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaErrorCompatNotSupportedOnDevice, 
# 945
cudaErrorStreamCaptureUnsupported = 900, 
# 951
cudaErrorStreamCaptureInvalidated, 
# 957
cudaErrorStreamCaptureMerge, 
# 962
cudaErrorStreamCaptureUnmatched, 
# 968
cudaErrorStreamCaptureUnjoined, 
# 975
cudaErrorStreamCaptureIsolation, 
# 981
cudaErrorStreamCaptureImplicit, 
# 987
cudaErrorCapturedEvent, 
# 994
cudaErrorStreamCaptureWrongThread, 
# 999
cudaErrorTimeout, 
# 1005
cudaErrorGraphExecUpdateFailure, 
# 1010
cudaErrorUnknown = 999, 
# 1018
cudaErrorApiFailureBase = 10000
# 1019
}; 
#endif
# 1024 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1024
enum cudaChannelFormatKind { 
# 1026
cudaChannelFormatKindSigned, 
# 1027
cudaChannelFormatKindUnsigned, 
# 1028
cudaChannelFormatKindFloat, 
# 1029
cudaChannelFormatKindNone, 
# 1030
cudaChannelFormatKindNV12
# 1031
}; 
#endif
# 1036 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1036
struct cudaChannelFormatDesc { 
# 1038
int x; 
# 1039
int y; 
# 1040
int z; 
# 1041
int w; 
# 1042
cudaChannelFormatKind f; 
# 1043
}; 
#endif
# 1048 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
typedef struct cudaArray *cudaArray_t; 
# 1053
typedef const cudaArray *cudaArray_const_t; 
# 1055
struct cudaArray; 
# 1060
typedef struct cudaMipmappedArray *cudaMipmappedArray_t; 
# 1065
typedef const cudaMipmappedArray *cudaMipmappedArray_const_t; 
# 1067
struct cudaMipmappedArray; 
# 1077 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1077
struct cudaArraySparseProperties { 
# 1078
struct { 
# 1079
unsigned width; 
# 1080
unsigned height; 
# 1081
unsigned depth; 
# 1082
} tileExtent; 
# 1083
unsigned miptailFirstLevel; 
# 1084
unsigned long long miptailSize; 
# 1085
unsigned flags; 
# 1086
unsigned reserved[4]; 
# 1087
}; 
#endif
# 1092 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1092
enum cudaMemoryType { 
# 1094
cudaMemoryTypeUnregistered, 
# 1095
cudaMemoryTypeHost, 
# 1096
cudaMemoryTypeDevice, 
# 1097
cudaMemoryTypeManaged
# 1098
}; 
#endif
# 1103 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1103
enum cudaMemcpyKind { 
# 1105
cudaMemcpyHostToHost, 
# 1106
cudaMemcpyHostToDevice, 
# 1107
cudaMemcpyDeviceToHost, 
# 1108
cudaMemcpyDeviceToDevice, 
# 1109
cudaMemcpyDefault
# 1110
}; 
#endif
# 1117 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1117
struct cudaPitchedPtr { 
# 1119
void *ptr; 
# 1120
size_t pitch; 
# 1121
size_t xsize; 
# 1122
size_t ysize; 
# 1123
}; 
#endif
# 1130 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1130
struct cudaExtent { 
# 1132
size_t width; 
# 1133
size_t height; 
# 1134
size_t depth; 
# 1135
}; 
#endif
# 1142 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1142
struct cudaPos { 
# 1144
size_t x; 
# 1145
size_t y; 
# 1146
size_t z; 
# 1147
}; 
#endif
# 1152 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1152
struct cudaMemcpy3DParms { 
# 1154
cudaArray_t srcArray; 
# 1155
cudaPos srcPos; 
# 1156
cudaPitchedPtr srcPtr; 
# 1158
cudaArray_t dstArray; 
# 1159
cudaPos dstPos; 
# 1160
cudaPitchedPtr dstPtr; 
# 1162
cudaExtent extent; 
# 1163
cudaMemcpyKind kind; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
# 1164
}; 
#endif
# 1169 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1169
struct cudaMemcpy3DPeerParms { 
# 1171
cudaArray_t srcArray; 
# 1172
cudaPos srcPos; 
# 1173
cudaPitchedPtr srcPtr; 
# 1174
int srcDevice; 
# 1176
cudaArray_t dstArray; 
# 1177
cudaPos dstPos; 
# 1178
cudaPitchedPtr dstPtr; 
# 1179
int dstDevice; 
# 1181
cudaExtent extent; 
# 1182
}; 
#endif
# 1187 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1187
struct cudaMemsetParams { 
# 1188
void *dst; 
# 1189
size_t pitch; 
# 1190
unsigned value; 
# 1191
unsigned elementSize; 
# 1192
size_t width; 
# 1193
size_t height; 
# 1194
}; 
#endif
# 1199 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1199
enum cudaAccessProperty { 
# 1200
cudaAccessPropertyNormal, 
# 1201
cudaAccessPropertyStreaming, 
# 1202
cudaAccessPropertyPersisting
# 1203
}; 
#endif
# 1216 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1216
struct cudaAccessPolicyWindow { 
# 1217
void *base_ptr; 
# 1218
size_t num_bytes; 
# 1219
float hitRatio; 
# 1220
cudaAccessProperty hitProp; 
# 1221
cudaAccessProperty missProp; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
# 1222
}; 
#endif
# 1234 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
typedef void (*cudaHostFn_t)(void * userData); 
# 1239
#if 0
# 1239
struct cudaHostNodeParams { 
# 1240
cudaHostFn_t fn; 
# 1241
void *userData; 
# 1242
}; 
#endif
# 1247 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1247
enum cudaStreamCaptureStatus { 
# 1248
cudaStreamCaptureStatusNone, 
# 1249
cudaStreamCaptureStatusActive, 
# 1250
cudaStreamCaptureStatusInvalidated
# 1252
}; 
#endif
# 1258 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1258
enum cudaStreamCaptureMode { 
# 1259
cudaStreamCaptureModeGlobal, 
# 1260
cudaStreamCaptureModeThreadLocal, 
# 1261
cudaStreamCaptureModeRelaxed
# 1262
}; 
#endif
# 1264 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1264
enum cudaSynchronizationPolicy { 
# 1265
cudaSyncPolicyAuto = 1, 
# 1266
cudaSyncPolicySpin, 
# 1267
cudaSyncPolicyYield, 
# 1268
cudaSyncPolicyBlockingSync
# 1269
}; 
#endif
# 1274 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1274
enum cudaStreamAttrID { 
# 1275
cudaStreamAttributeAccessPolicyWindow = 1, 
# 1276
cudaStreamAttributeSynchronizationPolicy = 3
# 1277
}; 
#endif
# 1282 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1282
union cudaStreamAttrValue { 
# 1283
cudaAccessPolicyWindow accessPolicyWindow; 
# 1284
cudaSynchronizationPolicy syncPolicy; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
# 1285
}; 
#endif
# 1290 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1290
enum cudaStreamUpdateCaptureDependenciesFlags { 
# 1291
cudaStreamAddCaptureDependencies, 
# 1292
cudaStreamSetCaptureDependencies
# 1293
}; 
#endif
# 1298 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1298
enum cudaUserObjectFlags { 
# 1299
cudaUserObjectNoDestructorSync = 1
# 1300
}; 
#endif
# 1305 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1305
enum cudaUserObjectRetainFlags { 
# 1306
cudaGraphUserObjectMove = 1
# 1307
}; 
#endif
# 1312 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
struct cudaGraphicsResource; 
# 1317
#if 0
# 1317
enum cudaGraphicsRegisterFlags { 
# 1319
cudaGraphicsRegisterFlagsNone, 
# 1320
cudaGraphicsRegisterFlagsReadOnly, 
# 1321
cudaGraphicsRegisterFlagsWriteDiscard, 
# 1322
cudaGraphicsRegisterFlagsSurfaceLoadStore = 4, 
# 1323
cudaGraphicsRegisterFlagsTextureGather = 8
# 1324
}; 
#endif
# 1329 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1329
enum cudaGraphicsMapFlags { 
# 1331
cudaGraphicsMapFlagsNone, 
# 1332
cudaGraphicsMapFlagsReadOnly, 
# 1333
cudaGraphicsMapFlagsWriteDiscard
# 1334
}; 
#endif
# 1339 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1339
enum cudaGraphicsCubeFace { 
# 1341
cudaGraphicsCubeFacePositiveX, 
# 1342
cudaGraphicsCubeFaceNegativeX, 
# 1343
cudaGraphicsCubeFacePositiveY, 
# 1344
cudaGraphicsCubeFaceNegativeY, 
# 1345
cudaGraphicsCubeFacePositiveZ, 
# 1346
cudaGraphicsCubeFaceNegativeZ
# 1347
}; 
#endif
# 1352 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1352
enum cudaKernelNodeAttrID { 
# 1353
cudaKernelNodeAttributeAccessPolicyWindow = 1, 
# 1354
cudaKernelNodeAttributeCooperative
# 1355
}; 
#endif
# 1360 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1360
union cudaKernelNodeAttrValue { 
# 1361
cudaAccessPolicyWindow accessPolicyWindow; 
# 1362
int cooperative; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
# 1363
}; 
#endif
# 1368 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1368
enum cudaResourceType { 
# 1370
cudaResourceTypeArray, 
# 1371
cudaResourceTypeMipmappedArray, 
# 1372
cudaResourceTypeLinear, 
# 1373
cudaResourceTypePitch2D
# 1374
}; 
#endif
# 1379 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1379
enum cudaResourceViewFormat { 
# 1381
cudaResViewFormatNone, 
# 1382
cudaResViewFormatUnsignedChar1, 
# 1383
cudaResViewFormatUnsignedChar2, 
# 1384
cudaResViewFormatUnsignedChar4, 
# 1385
cudaResViewFormatSignedChar1, 
# 1386
cudaResViewFormatSignedChar2, 
# 1387
cudaResViewFormatSignedChar4, 
# 1388
cudaResViewFormatUnsignedShort1, 
# 1389
cudaResViewFormatUnsignedShort2, 
# 1390
cudaResViewFormatUnsignedShort4, 
# 1391
cudaResViewFormatSignedShort1, 
# 1392
cudaResViewFormatSignedShort2, 
# 1393
cudaResViewFormatSignedShort4, 
# 1394
cudaResViewFormatUnsignedInt1, 
# 1395
cudaResViewFormatUnsignedInt2, 
# 1396
cudaResViewFormatUnsignedInt4, 
# 1397
cudaResViewFormatSignedInt1, 
# 1398
cudaResViewFormatSignedInt2, 
# 1399
cudaResViewFormatSignedInt4, 
# 1400
cudaResViewFormatHalf1, 
# 1401
cudaResViewFormatHalf2, 
# 1402
cudaResViewFormatHalf4, 
# 1403
cudaResViewFormatFloat1, 
# 1404
cudaResViewFormatFloat2, 
# 1405
cudaResViewFormatFloat4, 
# 1406
cudaResViewFormatUnsignedBlockCompressed1, 
# 1407
cudaResViewFormatUnsignedBlockCompressed2, 
# 1408
cudaResViewFormatUnsignedBlockCompressed3, 
# 1409
cudaResViewFormatUnsignedBlockCompressed4, 
# 1410
cudaResViewFormatSignedBlockCompressed4, 
# 1411
cudaResViewFormatUnsignedBlockCompressed5, 
# 1412
cudaResViewFormatSignedBlockCompressed5, 
# 1413
cudaResViewFormatUnsignedBlockCompressed6H, 
# 1414
cudaResViewFormatSignedBlockCompressed6H, 
# 1415
cudaResViewFormatUnsignedBlockCompressed7
# 1416
}; 
#endif
# 1421 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1421
struct cudaResourceDesc { 
# 1422
cudaResourceType resType; 
# 1424
union { 
# 1425
struct { 
# 1426
cudaArray_t array; 
# 1427
} array; 
# 1428
struct { 
# 1429
cudaMipmappedArray_t mipmap; 
# 1430
} mipmap; 
# 1431
struct { 
# 1432
void *devPtr; 
# 1433
cudaChannelFormatDesc desc; 
# 1434
size_t sizeInBytes; 
# 1435
} linear; 
# 1436
struct { 
# 1437
void *devPtr; 
# 1438
cudaChannelFormatDesc desc; 
# 1439
size_t width; 
# 1440
size_t height; 
# 1441
size_t pitchInBytes; 
# 1442
} pitch2D; 
# 1443
} res; 
# 1444
}; 
#endif
# 1449 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1449
struct cudaResourceViewDesc { 
# 1451
cudaResourceViewFormat format; 
# 1452
size_t width; 
# 1453
size_t height; 
# 1454
size_t depth; 
# 1455
unsigned firstMipmapLevel; 
# 1456
unsigned lastMipmapLevel; 
# 1457
unsigned firstLayer; 
# 1458
unsigned lastLayer; 
# 1459
}; 
#endif
# 1464 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1464
struct cudaPointerAttributes { 
# 1470
cudaMemoryType type; 
# 1481 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
int device; 
# 1487
void *devicePointer; 
# 1496 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
void *hostPointer; 
# 1497
}; 
#endif
# 1502 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1502
struct cudaFuncAttributes { 
# 1509
size_t sharedSizeBytes; 
# 1515
size_t constSizeBytes; 
# 1520
size_t localSizeBytes; 
# 1527
int maxThreadsPerBlock; 
# 1532
int numRegs; 
# 1539
int ptxVersion; 
# 1546
int binaryVersion; 
# 1552
int cacheModeCA; 
# 1559
int maxDynamicSharedSizeBytes; 
# 1568 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
int preferredShmemCarveout; 
# 1569
}; 
#endif
# 1574 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1574
enum cudaFuncAttribute { 
# 1576
cudaFuncAttributeMaxDynamicSharedMemorySize = 8, 
# 1577
cudaFuncAttributePreferredSharedMemoryCarveout, 
# 1578
cudaFuncAttributeMax
# 1579
}; 
#endif
# 1584 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1584
enum cudaFuncCache { 
# 1586
cudaFuncCachePreferNone, 
# 1587
cudaFuncCachePreferShared, 
# 1588
cudaFuncCachePreferL1, 
# 1589
cudaFuncCachePreferEqual
# 1590
}; 
#endif
# 1596 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1596
enum cudaSharedMemConfig { 
# 1598
cudaSharedMemBankSizeDefault, 
# 1599
cudaSharedMemBankSizeFourByte, 
# 1600
cudaSharedMemBankSizeEightByte
# 1601
}; 
#endif
# 1606 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1606
enum cudaSharedCarveout { 
# 1607
cudaSharedmemCarveoutDefault = (-1), 
# 1608
cudaSharedmemCarveoutMaxShared = 100, 
# 1609
cudaSharedmemCarveoutMaxL1 = 0
# 1610
}; 
#endif
# 1615 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1615
enum cudaComputeMode { 
# 1617
cudaComputeModeDefault, 
# 1618
cudaComputeModeExclusive, 
# 1619
cudaComputeModeProhibited, 
# 1620
cudaComputeModeExclusiveProcess
# 1621
}; 
#endif
# 1626 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1626
enum cudaLimit { 
# 1628
cudaLimitStackSize, 
# 1629
cudaLimitPrintfFifoSize, 
# 1630
cudaLimitMallocHeapSize, 
# 1631
cudaLimitDevRuntimeSyncDepth, 
# 1632
cudaLimitDevRuntimePendingLaunchCount, 
# 1633
cudaLimitMaxL2FetchGranularity, 
# 1634
cudaLimitPersistingL2CacheSize
# 1635
}; 
#endif
# 1640 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1640
enum cudaMemoryAdvise { 
# 1642
cudaMemAdviseSetReadMostly = 1, 
# 1643
cudaMemAdviseUnsetReadMostly, 
# 1644
cudaMemAdviseSetPreferredLocation, 
# 1645
cudaMemAdviseUnsetPreferredLocation, 
# 1646
cudaMemAdviseSetAccessedBy, 
# 1647
cudaMemAdviseUnsetAccessedBy
# 1648
}; 
#endif
# 1653 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1653
enum cudaMemRangeAttribute { 
# 1655
cudaMemRangeAttributeReadMostly = 1, 
# 1656
cudaMemRangeAttributePreferredLocation, 
# 1657
cudaMemRangeAttributeAccessedBy, 
# 1658
cudaMemRangeAttributeLastPrefetchLocation
# 1659
}; 
#endif
# 1664 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1664
enum cudaOutputMode { 
# 1666
cudaKeyValuePair, 
# 1667
cudaCSV
# 1668
}; 
#endif
# 1673 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1673
enum cudaFlushGPUDirectRDMAWritesOptions { 
# 1674
cudaFlushGPUDirectRDMAWritesOptionHost = 1, 
# 1675
cudaFlushGPUDirectRDMAWritesOptionMemOps
# 1676
}; 
#endif
# 1681 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1681
enum cudaGPUDirectRDMAWritesOrdering { 
# 1682
cudaGPUDirectRDMAWritesOrderingNone, 
# 1683
cudaGPUDirectRDMAWritesOrderingOwner = 100, 
# 1684
cudaGPUDirectRDMAWritesOrderingAllDevices = 200
# 1685
}; 
#endif
# 1690 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1690
enum cudaFlushGPUDirectRDMAWritesScope { 
# 1691
cudaFlushGPUDirectRDMAWritesToOwner = 100, 
# 1692
cudaFlushGPUDirectRDMAWritesToAllDevices = 200
# 1693
}; 
#endif
# 1698 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1698
enum cudaFlushGPUDirectRDMAWritesTarget { 
# 1699
cudaFlushGPUDirectRDMAWritesTargetCurrentDevice
# 1700
}; 
#endif
# 1706 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1706
enum cudaDeviceAttr { 
# 1708
cudaDevAttrMaxThreadsPerBlock = 1, 
# 1709
cudaDevAttrMaxBlockDimX, 
# 1710
cudaDevAttrMaxBlockDimY, 
# 1711
cudaDevAttrMaxBlockDimZ, 
# 1712
cudaDevAttrMaxGridDimX, 
# 1713
cudaDevAttrMaxGridDimY, 
# 1714
cudaDevAttrMaxGridDimZ, 
# 1715
cudaDevAttrMaxSharedMemoryPerBlock, 
# 1716
cudaDevAttrTotalConstantMemory, 
# 1717
cudaDevAttrWarpSize, 
# 1718
cudaDevAttrMaxPitch, 
# 1719
cudaDevAttrMaxRegistersPerBlock, 
# 1720
cudaDevAttrClockRate, 
# 1721
cudaDevAttrTextureAlignment, 
# 1722
cudaDevAttrGpuOverlap, 
# 1723
cudaDevAttrMultiProcessorCount, 
# 1724
cudaDevAttrKernelExecTimeout, 
# 1725
cudaDevAttrIntegrated, 
# 1726
cudaDevAttrCanMapHostMemory, 
# 1727
cudaDevAttrComputeMode, 
# 1728
cudaDevAttrMaxTexture1DWidth, 
# 1729
cudaDevAttrMaxTexture2DWidth, 
# 1730
cudaDevAttrMaxTexture2DHeight, 
# 1731
cudaDevAttrMaxTexture3DWidth, 
# 1732
cudaDevAttrMaxTexture3DHeight, 
# 1733
cudaDevAttrMaxTexture3DDepth, 
# 1734
cudaDevAttrMaxTexture2DLayeredWidth, 
# 1735
cudaDevAttrMaxTexture2DLayeredHeight, 
# 1736
cudaDevAttrMaxTexture2DLayeredLayers, 
# 1737
cudaDevAttrSurfaceAlignment, 
# 1738
cudaDevAttrConcurrentKernels, 
# 1739
cudaDevAttrEccEnabled, 
# 1740
cudaDevAttrPciBusId, 
# 1741
cudaDevAttrPciDeviceId, 
# 1742
cudaDevAttrTccDriver, 
# 1743
cudaDevAttrMemoryClockRate, 
# 1744
cudaDevAttrGlobalMemoryBusWidth, 
# 1745
cudaDevAttrL2CacheSize, 
# 1746
cudaDevAttrMaxThreadsPerMultiProcessor, 
# 1747
cudaDevAttrAsyncEngineCount, 
# 1748
cudaDevAttrUnifiedAddressing, 
# 1749
cudaDevAttrMaxTexture1DLayeredWidth, 
# 1750
cudaDevAttrMaxTexture1DLayeredLayers, 
# 1751
cudaDevAttrMaxTexture2DGatherWidth = 45, 
# 1752
cudaDevAttrMaxTexture2DGatherHeight, 
# 1753
cudaDevAttrMaxTexture3DWidthAlt, 
# 1754
cudaDevAttrMaxTexture3DHeightAlt, 
# 1755
cudaDevAttrMaxTexture3DDepthAlt, 
# 1756
cudaDevAttrPciDomainId, 
# 1757
cudaDevAttrTexturePitchAlignment, 
# 1758
cudaDevAttrMaxTextureCubemapWidth, 
# 1759
cudaDevAttrMaxTextureCubemapLayeredWidth, 
# 1760
cudaDevAttrMaxTextureCubemapLayeredLayers, 
# 1761
cudaDevAttrMaxSurface1DWidth, 
# 1762
cudaDevAttrMaxSurface2DWidth, 
# 1763
cudaDevAttrMaxSurface2DHeight, 
# 1764
cudaDevAttrMaxSurface3DWidth, 
# 1765
cudaDevAttrMaxSurface3DHeight, 
# 1766
cudaDevAttrMaxSurface3DDepth, 
# 1767
cudaDevAttrMaxSurface1DLayeredWidth, 
# 1768
cudaDevAttrMaxSurface1DLayeredLayers, 
# 1769
cudaDevAttrMaxSurface2DLayeredWidth, 
# 1770
cudaDevAttrMaxSurface2DLayeredHeight, 
# 1771
cudaDevAttrMaxSurface2DLayeredLayers, 
# 1772
cudaDevAttrMaxSurfaceCubemapWidth, 
# 1773
cudaDevAttrMaxSurfaceCubemapLayeredWidth, 
# 1774
cudaDevAttrMaxSurfaceCubemapLayeredLayers, 
# 1775
cudaDevAttrMaxTexture1DLinearWidth, 
# 1776
cudaDevAttrMaxTexture2DLinearWidth, 
# 1777
cudaDevAttrMaxTexture2DLinearHeight, 
# 1778
cudaDevAttrMaxTexture2DLinearPitch, 
# 1779
cudaDevAttrMaxTexture2DMipmappedWidth, 
# 1780
cudaDevAttrMaxTexture2DMipmappedHeight, 
# 1781
cudaDevAttrComputeCapabilityMajor, 
# 1782
cudaDevAttrComputeCapabilityMinor, 
# 1783
cudaDevAttrMaxTexture1DMipmappedWidth, 
# 1784
cudaDevAttrStreamPrioritiesSupported, 
# 1785
cudaDevAttrGlobalL1CacheSupported, 
# 1786
cudaDevAttrLocalL1CacheSupported, 
# 1787
cudaDevAttrMaxSharedMemoryPerMultiprocessor, 
# 1788
cudaDevAttrMaxRegistersPerMultiprocessor, 
# 1789
cudaDevAttrManagedMemory, 
# 1790
cudaDevAttrIsMultiGpuBoard, 
# 1791
cudaDevAttrMultiGpuBoardGroupID, 
# 1792
cudaDevAttrHostNativeAtomicSupported, 
# 1793
cudaDevAttrSingleToDoublePrecisionPerfRatio, 
# 1794
cudaDevAttrPageableMemoryAccess, 
# 1795
cudaDevAttrConcurrentManagedAccess, 
# 1796
cudaDevAttrComputePreemptionSupported, 
# 1797
cudaDevAttrCanUseHostPointerForRegisteredMem, 
# 1798
cudaDevAttrReserved92, 
# 1799
cudaDevAttrReserved93, 
# 1800
cudaDevAttrReserved94, 
# 1801
cudaDevAttrCooperativeLaunch, 
# 1802
cudaDevAttrCooperativeMultiDeviceLaunch, 
# 1803
cudaDevAttrMaxSharedMemoryPerBlockOptin, 
# 1804
cudaDevAttrCanFlushRemoteWrites, 
# 1805
cudaDevAttrHostRegisterSupported, 
# 1806
cudaDevAttrPageableMemoryAccessUsesHostPageTables, 
# 1807
cudaDevAttrDirectManagedMemAccessFromHost, 
# 1808
cudaDevAttrMaxBlocksPerMultiprocessor = 106, 
# 1809
cudaDevAttrMaxPersistingL2CacheSize = 108, 
# 1810
cudaDevAttrMaxAccessPolicyWindowSize, 
# 1811
cudaDevAttrReservedSharedMemoryPerBlock = 111, 
# 1812
cudaDevAttrSparseCudaArraySupported, 
# 1813
cudaDevAttrHostRegisterReadOnlySupported, 
# 1814
cudaDevAttrMaxTimelineSemaphoreInteropSupported, 
# 1815
cudaDevAttrMemoryPoolsSupported, 
# 1816
cudaDevAttrGPUDirectRDMASupported, 
# 1817
cudaDevAttrGPUDirectRDMAFlushWritesOptions, 
# 1818
cudaDevAttrGPUDirectRDMAWritesOrdering, 
# 1819
cudaDevAttrMemoryPoolSupportedHandleTypes
# 1820
}; 
#endif
# 1825 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1825
enum cudaMemPoolAttr { 
# 1835 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaMemPoolReuseFollowEventDependencies = 1, 
# 1842
cudaMemPoolReuseAllowOpportunistic, 
# 1850
cudaMemPoolReuseAllowInternalDependencies, 
# 1861 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
cudaMemPoolAttrReleaseThreshold, 
# 1867
cudaMemPoolAttrReservedMemCurrent, 
# 1874
cudaMemPoolAttrReservedMemHigh, 
# 1880
cudaMemPoolAttrUsedMemCurrent, 
# 1887
cudaMemPoolAttrUsedMemHigh
# 1888
}; 
#endif
# 1893 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1893
enum cudaMemLocationType { 
# 1894
cudaMemLocationTypeInvalid, 
# 1895
cudaMemLocationTypeDevice
# 1896
}; 
#endif
# 1903 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1903
struct cudaMemLocation { 
# 1904
cudaMemLocationType type; 
# 1905
int id; 
# 1906
}; 
#endif
# 1911 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1911
enum cudaMemAccessFlags { 
# 1912
cudaMemAccessFlagsProtNone, 
# 1913
cudaMemAccessFlagsProtRead, 
# 1914
cudaMemAccessFlagsProtReadWrite = 3
# 1915
}; 
#endif
# 1920 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1920
struct cudaMemAccessDesc { 
# 1921
cudaMemLocation location; 
# 1922
cudaMemAccessFlags flags; 
# 1923
}; 
#endif
# 1928 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1928
enum cudaMemAllocationType { 
# 1929
cudaMemAllocationTypeInvalid, 
# 1933
cudaMemAllocationTypePinned, 
# 1934
cudaMemAllocationTypeMax = 2147483647
# 1935
}; 
#endif
# 1940 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1940
enum cudaMemAllocationHandleType { 
# 1941
cudaMemHandleTypeNone, 
# 1942
cudaMemHandleTypePosixFileDescriptor, 
# 1943
cudaMemHandleTypeWin32, 
# 1944
cudaMemHandleTypeWin32Kmt = 4
# 1945
}; 
#endif
# 1950 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1950
struct cudaMemPoolProps { 
# 1951
cudaMemAllocationType allocType; 
# 1952
cudaMemAllocationHandleType handleTypes; 
# 1953
cudaMemLocation location; 
# 1960
void *win32SecurityAttributes; 
# 1961
unsigned char reserved[64]; 
# 1962
}; 
#endif
# 1967 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1967
struct cudaMemPoolPtrExportData { 
# 1968
unsigned char reserved[64]; 
# 1969
}; 
#endif
# 1975 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1975
enum cudaDeviceP2PAttr { 
# 1976
cudaDevP2PAttrPerformanceRank = 1, 
# 1977
cudaDevP2PAttrAccessSupported, 
# 1978
cudaDevP2PAttrNativeAtomicSupported, 
# 1979
cudaDevP2PAttrCudaArrayAccessSupported
# 1980
}; 
#endif
# 1987 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1987
struct CUuuid_st { 
# 1988
char bytes[16]; 
# 1989
}; 
#endif
# 1990 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef CUuuid_st 
# 1990
CUuuid; 
#endif
# 1992 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef CUuuid_st 
# 1992
cudaUUID_t; 
#endif
# 1997 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1997
struct cudaDeviceProp { 
# 1999
char name[256]; 
# 2000
cudaUUID_t uuid; 
# 2001
char luid[8]; 
# 2002
unsigned luidDeviceNodeMask; 
# 2003
size_t totalGlobalMem; 
# 2004
size_t sharedMemPerBlock; 
# 2005
int regsPerBlock; 
# 2006
int warpSize; 
# 2007
size_t memPitch; 
# 2008
int maxThreadsPerBlock; 
# 2009
int maxThreadsDim[3]; 
# 2010
int maxGridSize[3]; 
# 2011
int clockRate; 
# 2012
size_t totalConstMem; 
# 2013
int major; 
# 2014
int minor; 
# 2015
size_t textureAlignment; 
# 2016
size_t texturePitchAlignment; 
# 2017
int deviceOverlap; 
# 2018
int multiProcessorCount; 
# 2019
int kernelExecTimeoutEnabled; 
# 2020
int integrated; 
# 2021
int canMapHostMemory; 
# 2022
int computeMode; 
# 2023
int maxTexture1D; 
# 2024
int maxTexture1DMipmap; 
# 2025
int maxTexture1DLinear; 
# 2026
int maxTexture2D[2]; 
# 2027
int maxTexture2DMipmap[2]; 
# 2028
int maxTexture2DLinear[3]; 
# 2029
int maxTexture2DGather[2]; 
# 2030
int maxTexture3D[3]; 
# 2031
int maxTexture3DAlt[3]; 
# 2032
int maxTextureCubemap; 
# 2033
int maxTexture1DLayered[2]; 
# 2034
int maxTexture2DLayered[3]; 
# 2035
int maxTextureCubemapLayered[2]; 
# 2036
int maxSurface1D; 
# 2037
int maxSurface2D[2]; 
# 2038
int maxSurface3D[3]; 
# 2039
int maxSurface1DLayered[2]; 
# 2040
int maxSurface2DLayered[3]; 
# 2041
int maxSurfaceCubemap; 
# 2042
int maxSurfaceCubemapLayered[2]; 
# 2043
size_t surfaceAlignment; 
# 2044
int concurrentKernels; 
# 2045
int ECCEnabled; 
# 2046
int pciBusID; 
# 2047
int pciDeviceID; 
# 2048
int pciDomainID; 
# 2049
int tccDriver; 
# 2050
int asyncEngineCount; 
# 2051
int unifiedAddressing; 
# 2052
int memoryClockRate; 
# 2053
int memoryBusWidth; 
# 2054
int l2CacheSize; 
# 2055
int persistingL2CacheMaxSize; 
# 2056
int maxThreadsPerMultiProcessor; 
# 2057
int streamPrioritiesSupported; 
# 2058
int globalL1CacheSupported; 
# 2059
int localL1CacheSupported; 
# 2060
size_t sharedMemPerMultiprocessor; 
# 2061
int regsPerMultiprocessor; 
# 2062
int managedMemory; 
# 2063
int isMultiGpuBoard; 
# 2064
int multiGpuBoardGroupID; 
# 2065
int hostNativeAtomicSupported; 
# 2066
int singleToDoublePrecisionPerfRatio; 
# 2067
int pageableMemoryAccess; 
# 2068
int concurrentManagedAccess; 
# 2069
int computePreemptionSupported; 
# 2070
int canUseHostPointerForRegisteredMem; 
# 2071
int cooperativeLaunch; 
# 2072
int cooperativeMultiDeviceLaunch; 
# 2073
size_t sharedMemPerBlockOptin; 
# 2074
int pageableMemoryAccessUsesHostPageTables; 
# 2075
int directManagedMemAccessFromHost; 
# 2076
int maxBlocksPerMultiProcessor; 
# 2077
int accessPolicyMaxWindowSize; 
# 2078
size_t reservedSharedMemPerBlock; 
# 2079
}; 
#endif
# 2175 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef 
# 2172
struct cudaIpcEventHandle_st { 
# 2174
char reserved[64]; 
# 2175
} cudaIpcEventHandle_t; 
#endif
# 2183 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef 
# 2180
struct cudaIpcMemHandle_st { 
# 2182
char reserved[64]; 
# 2183
} cudaIpcMemHandle_t; 
#endif
# 2188 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2188
enum cudaExternalMemoryHandleType { 
# 2192
cudaExternalMemoryHandleTypeOpaqueFd = 1, 
# 2196
cudaExternalMemoryHandleTypeOpaqueWin32, 
# 2200
cudaExternalMemoryHandleTypeOpaqueWin32Kmt, 
# 2204
cudaExternalMemoryHandleTypeD3D12Heap, 
# 2208
cudaExternalMemoryHandleTypeD3D12Resource, 
# 2212
cudaExternalMemoryHandleTypeD3D11Resource, 
# 2216
cudaExternalMemoryHandleTypeD3D11ResourceKmt, 
# 2220
cudaExternalMemoryHandleTypeNvSciBuf
# 2221
}; 
#endif
# 2263 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2263
struct cudaExternalMemoryHandleDesc { 
# 2267
cudaExternalMemoryHandleType type; 
# 2268
union { 
# 2274
int fd; 
# 2290 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
struct { 
# 2294
void *handle; 
# 2299
const void *name; 
# 2300
} win32; 
# 2305
const void *nvSciBufObject; 
# 2306
} handle; 
# 2310
unsigned long long size; 
# 2314
unsigned flags; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
# 2315
}; 
#endif
# 2320 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2320
struct cudaExternalMemoryBufferDesc { 
# 2324
unsigned long long offset; 
# 2328
unsigned long long size; 
# 2332
unsigned flags; 
# 2333
}; 
#endif
# 2338 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2338
struct cudaExternalMemoryMipmappedArrayDesc { 
# 2343
unsigned long long offset; 
# 2347
cudaChannelFormatDesc formatDesc; 
# 2351
cudaExtent extent; 
# 2356
unsigned flags; 
# 2360
unsigned numLevels; 
# 2361
}; 
#endif
# 2366 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2366
enum cudaExternalSemaphoreHandleType { 
# 2370
cudaExternalSemaphoreHandleTypeOpaqueFd = 1, 
# 2374
cudaExternalSemaphoreHandleTypeOpaqueWin32, 
# 2378
cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt, 
# 2382
cudaExternalSemaphoreHandleTypeD3D12Fence, 
# 2386
cudaExternalSemaphoreHandleTypeD3D11Fence, 
# 2390
cudaExternalSemaphoreHandleTypeNvSciSync, 
# 2394
cudaExternalSemaphoreHandleTypeKeyedMutex, 
# 2398
cudaExternalSemaphoreHandleTypeKeyedMutexKmt, 
# 2402
cudaExternalSemaphoreHandleTypeTimelineSemaphoreFd, 
# 2406
cudaExternalSemaphoreHandleTypeTimelineSemaphoreWin32
# 2407
}; 
#endif
# 2412 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2412
struct cudaExternalSemaphoreHandleDesc { 
# 2416
cudaExternalSemaphoreHandleType type; 
# 2417
union { 
# 2424
int fd; 
# 2440 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
struct { 
# 2444
void *handle; 
# 2449
const void *name; 
# 2450
} win32; 
# 2454
const void *nvSciSyncObj; 
# 2455
} handle; 
# 2459
unsigned flags; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
# 2460
}; 
#endif
# 2561 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2561
struct cudaExternalSemaphoreSignalParams { 
# 2562
struct { 
# 2566
struct { 
# 2570
unsigned long long value; 
# 2571
} fence; 
# 2572
union { 
# 2577
void *fence; 
# 2578
unsigned long long reserved; 
# 2579
} nvSciSync; 
# 2583
struct { 
# 2587
unsigned long long key; 
# 2588
} keyedMutex; 
# 2589
unsigned reserved[12]; 
# 2590
} params; 
# 2601 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
unsigned flags; 
# 2602
unsigned reserved[16]; 
# 2603
}; 
#endif
# 2608 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2608
struct cudaExternalSemaphoreWaitParams { 
# 2609
struct { 
# 2613
struct { 
# 2617
unsigned long long value; 
# 2618
} fence; 
# 2619
union { 
# 2624
void *fence; 
# 2625
unsigned long long reserved; 
# 2626
} nvSciSync; 
# 2630
struct { 
# 2634
unsigned long long key; 
# 2638
unsigned timeoutMs; 
# 2639
} keyedMutex; 
# 2640
unsigned reserved[10]; 
# 2641
} params; 
# 2652 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
unsigned flags; 
# 2653
unsigned reserved[16]; 
# 2654
}; 
#endif
# 2666 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef cudaError 
# 2666
cudaError_t; 
#endif
# 2671 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUstream_st *
# 2671
cudaStream_t; 
#endif
# 2676 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUevent_st *
# 2676
cudaEvent_t; 
#endif
# 2681 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef cudaGraphicsResource *
# 2681
cudaGraphicsResource_t; 
#endif
# 2686 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef cudaOutputMode 
# 2686
cudaOutputMode_t; 
#endif
# 2691 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUexternalMemory_st *
# 2691
cudaExternalMemory_t; 
#endif
# 2696 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUexternalSemaphore_st *
# 2696
cudaExternalSemaphore_t; 
#endif
# 2701 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUgraph_st *
# 2701
cudaGraph_t; 
#endif
# 2706 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUgraphNode_st *
# 2706
cudaGraphNode_t; 
#endif
# 2711 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUuserObject_st *
# 2711
cudaUserObject_t; 
#endif
# 2716 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUfunc_st *
# 2716
cudaFunction_t; 
#endif
# 2721 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUmemPoolHandle_st *
# 2721
cudaMemPool_t; 
#endif
# 2726 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2726
enum cudaCGScope { 
# 2727
cudaCGScopeInvalid, 
# 2728
cudaCGScopeGrid, 
# 2729
cudaCGScopeMultiGrid
# 2730
}; 
#endif
# 2735 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2735
struct cudaLaunchParams { 
# 2737
void *func; 
# 2738
dim3 gridDim; 
# 2739
dim3 blockDim; 
# 2740
void **args; 
# 2741
size_t sharedMem; 
# 2742
cudaStream_t stream; 
# 2743
}; 
#endif
# 2748 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2748
struct cudaKernelNodeParams { 
# 2749
void *func; 
# 2750
dim3 gridDim; 
# 2751
dim3 blockDim; 
# 2752
unsigned sharedMemBytes; 
# 2753
void **kernelParams; 
# 2754
void **extra; 
# 2755
}; 
#endif
# 2760 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2760
struct cudaExternalSemaphoreSignalNodeParams { 
# 2761
cudaExternalSemaphore_t *extSemArray; 
# 2762
const cudaExternalSemaphoreSignalParams *paramsArray; 
# 2763
unsigned numExtSems; 
# 2764
}; 
#endif
# 2769 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2769
struct cudaExternalSemaphoreWaitNodeParams { 
# 2770
cudaExternalSemaphore_t *extSemArray; 
# 2771
const cudaExternalSemaphoreWaitParams *paramsArray; 
# 2772
unsigned numExtSems; 
# 2773
}; 
#endif
# 2778 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2778
enum cudaGraphNodeType { 
# 2779
cudaGraphNodeTypeKernel, 
# 2780
cudaGraphNodeTypeMemcpy, 
# 2781
cudaGraphNodeTypeMemset, 
# 2782
cudaGraphNodeTypeHost, 
# 2783
cudaGraphNodeTypeGraph, 
# 2784
cudaGraphNodeTypeEmpty, 
# 2785
cudaGraphNodeTypeWaitEvent, 
# 2786
cudaGraphNodeTypeEventRecord, 
# 2787
cudaGraphNodeTypeCount
# 2788
}; 
#endif
# 2793 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
typedef struct CUgraphExec_st *cudaGraphExec_t; 
# 2798
#if 0
# 2798
enum cudaGraphExecUpdateResult { 
# 2799
cudaGraphExecUpdateSuccess, 
# 2800
cudaGraphExecUpdateError, 
# 2801
cudaGraphExecUpdateErrorTopologyChanged, 
# 2802
cudaGraphExecUpdateErrorNodeTypeChanged, 
# 2803
cudaGraphExecUpdateErrorFunctionChanged, 
# 2804
cudaGraphExecUpdateErrorParametersChanged, 
# 2805
cudaGraphExecUpdateErrorNotSupported, 
# 2806
cudaGraphExecUpdateErrorUnsupportedFunctionChange
# 2807
}; 
#endif
# 2813 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2813
enum cudaGetDriverEntryPointFlags { 
# 2814
cudaEnableDefault, 
# 2815
cudaEnableLegacyStream, 
# 2816
cudaEnablePerThreadDefaultStream
# 2817
}; 
#endif
# 2822 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 2822
enum cudaGraphDebugDotFlags { 
# 2823
cudaGraphDebugDotFlagsVerbose = 1, 
# 2824
cudaGraphDebugDotFlagsKernelNodeParams = 4, 
# 2825
cudaGraphDebugDotFlagsMemcpyNodeParams = 8, 
# 2826
cudaGraphDebugDotFlagsMemsetNodeParams = 16, 
# 2827
cudaGraphDebugDotFlagsHostNodeParams = 32, 
# 2828
cudaGraphDebugDotFlagsEventNodeParams = 64, 
# 2829
cudaGraphDebugDotFlagsExtSemasSignalNodeParams = 128, 
# 2830
cudaGraphDebugDotFlagsExtSemasWaitNodeParams = 256, 
# 2831
cudaGraphDebugDotFlagsKernelNodeAttributes = 512, 
# 2832
cudaGraphDebugDotFlagsHandles = 1024
# 2833
}; 
#endif
# 84 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_types.h"
#if 0
# 84
enum cudaSurfaceBoundaryMode { 
# 86
cudaBoundaryModeZero, 
# 87
cudaBoundaryModeClamp, 
# 88
cudaBoundaryModeTrap
# 89
}; 
#endif
# 94 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_types.h"
#if 0
# 94
enum cudaSurfaceFormatMode { 
# 96
cudaFormatModeForced, 
# 97
cudaFormatModeAuto
# 98
}; 
#endif
# 103 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_types.h"
#if 0
# 103
struct surfaceReference { 
# 108
cudaChannelFormatDesc channelDesc; 
# 109
}; 
#endif
# 114 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_types.h"
#if 0
typedef unsigned long long 
# 114
cudaSurfaceObject_t; 
#endif
# 84 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 84
enum cudaTextureAddressMode { 
# 86
cudaAddressModeWrap, 
# 87
cudaAddressModeClamp, 
# 88
cudaAddressModeMirror, 
# 89
cudaAddressModeBorder
# 90
}; 
#endif
# 95 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 95
enum cudaTextureFilterMode { 
# 97
cudaFilterModePoint, 
# 98
cudaFilterModeLinear
# 99
}; 
#endif
# 104 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 104
enum cudaTextureReadMode { 
# 106
cudaReadModeElementType, 
# 107
cudaReadModeNormalizedFloat
# 108
}; 
#endif
# 113 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 113
struct textureReference { 
# 118
int normalized; 
# 122
cudaTextureFilterMode filterMode; 
# 126
cudaTextureAddressMode addressMode[3]; 
# 130
cudaChannelFormatDesc channelDesc; 
# 134
int sRGB; 
# 138
unsigned maxAnisotropy; 
# 142
cudaTextureFilterMode mipmapFilterMode; 
# 146
float mipmapLevelBias; 
# 150
float minMipmapLevelClamp; 
# 154
float maxMipmapLevelClamp; 
# 158
int disableTrilinearOptimization; 
# 159
int __cudaReserved[14]; 
# 160
}; 
#endif
# 165 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 165
struct cudaTextureDesc { 
# 170
cudaTextureAddressMode addressMode[3]; 
# 174
cudaTextureFilterMode filterMode; 
# 178
cudaTextureReadMode readMode; 
# 182
int sRGB; 
# 186
float borderColor[4]; 
# 190
int normalizedCoords; 
# 194
unsigned maxAnisotropy; 
# 198
cudaTextureFilterMode mipmapFilterMode; 
# 202
float mipmapLevelBias; 
# 206
float minMipmapLevelClamp; 
# 210
float maxMipmapLevelClamp; 
# 214
int disableTrilinearOptimization; 
# 215
}; 
#endif
# 220 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
typedef unsigned long long 
# 220
cudaTextureObject_t; 
#endif
# 84 "/usr/local/cuda/bin/../targets/x86_64-linux/include/library_types.h"
typedef 
# 54
enum cudaDataType_t { 
# 56
CUDA_R_16F = 2, 
# 57
CUDA_C_16F = 6, 
# 58
CUDA_R_16BF = 14, 
# 59
CUDA_C_16BF, 
# 60
CUDA_R_32F = 0, 
# 61
CUDA_C_32F = 4, 
# 62
CUDA_R_64F = 1, 
# 63
CUDA_C_64F = 5, 
# 64
CUDA_R_4I = 16, 
# 65
CUDA_C_4I, 
# 66
CUDA_R_4U, 
# 67
CUDA_C_4U, 
# 68
CUDA_R_8I = 3, 
# 69
CUDA_C_8I = 7, 
# 70
CUDA_R_8U, 
# 71
CUDA_C_8U, 
# 72
CUDA_R_16I = 20, 
# 73
CUDA_C_16I, 
# 74
CUDA_R_16U, 
# 75
CUDA_C_16U, 
# 76
CUDA_R_32I = 10, 
# 77
CUDA_C_32I, 
# 78
CUDA_R_32U, 
# 79
CUDA_C_32U, 
# 80
CUDA_R_64I = 24, 
# 81
CUDA_C_64I, 
# 82
CUDA_R_64U, 
# 83
CUDA_C_64U
# 84
} cudaDataType; 
# 92
typedef 
# 87
enum libraryPropertyType_t { 
# 89
MAJOR_VERSION, 
# 90
MINOR_VERSION, 
# 91
PATCH_LEVEL
# 92
} libraryPropertyType; 
# 115 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_device_runtime_api.h"
extern "C" {
# 117
extern cudaError_t cudaDeviceGetAttribute(int * value, cudaDeviceAttr attr, int device); 
# 118
extern cudaError_t cudaDeviceGetLimit(size_t * pValue, cudaLimit limit); 
# 119
extern cudaError_t cudaDeviceGetCacheConfig(cudaFuncCache * pCacheConfig); 
# 120
extern cudaError_t cudaDeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig); 
# 121
extern cudaError_t cudaDeviceSynchronize(); 
# 122
extern cudaError_t cudaGetLastError(); 
# 123
extern cudaError_t cudaPeekAtLastError(); 
# 124
extern const char *cudaGetErrorString(cudaError_t error); 
# 125
extern const char *cudaGetErrorName(cudaError_t error); 
# 126
extern cudaError_t cudaGetDeviceCount(int * count); 
# 127
extern cudaError_t cudaGetDevice(int * device); 
# 128
extern cudaError_t cudaStreamCreateWithFlags(cudaStream_t * pStream, unsigned flags); 
# 129
extern cudaError_t cudaStreamDestroy(cudaStream_t stream); 
# 130
extern cudaError_t cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned flags); 
# 131
__attribute__((unused)) extern cudaError_t cudaStreamWaitEvent_ptsz(cudaStream_t stream, cudaEvent_t event, unsigned flags); 
# 132
extern cudaError_t cudaEventCreateWithFlags(cudaEvent_t * event, unsigned flags); 
# 133
extern cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream); 
# 134
__attribute__((unused)) extern cudaError_t cudaEventRecord_ptsz(cudaEvent_t event, cudaStream_t stream); 
# 135
extern cudaError_t cudaEventRecordWithFlags(cudaEvent_t event, cudaStream_t stream, unsigned flags); 
# 136
__attribute__((unused)) extern cudaError_t cudaEventRecordWithFlags_ptsz(cudaEvent_t event, cudaStream_t stream, unsigned flags); 
# 137
extern cudaError_t cudaEventDestroy(cudaEvent_t event); 
# 138
extern cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, const void * func); 
# 139
extern cudaError_t cudaFree(void * devPtr); 
# 140
extern cudaError_t cudaMalloc(void ** devPtr, size_t size); 
# 141
extern cudaError_t cudaMemcpyAsync(void * dst, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream); 
# 142
__attribute__((unused)) extern cudaError_t cudaMemcpyAsync_ptsz(void * dst, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream); 
# 143
extern cudaError_t cudaMemcpy2DAsync(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream); 
# 144
__attribute__((unused)) extern cudaError_t cudaMemcpy2DAsync_ptsz(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream); 
# 145
extern cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms * p, cudaStream_t stream); 
# 146
__attribute__((unused)) extern cudaError_t cudaMemcpy3DAsync_ptsz(const cudaMemcpy3DParms * p, cudaStream_t stream); 
# 147
extern cudaError_t cudaMemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream); 
# 148
__attribute__((unused)) extern cudaError_t cudaMemsetAsync_ptsz(void * devPtr, int value, size_t count, cudaStream_t stream); 
# 149
extern cudaError_t cudaMemset2DAsync(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream); 
# 150
__attribute__((unused)) extern cudaError_t cudaMemset2DAsync_ptsz(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream); 
# 151
extern cudaError_t cudaMemset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream); 
# 152
__attribute__((unused)) extern cudaError_t cudaMemset3DAsync_ptsz(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream); 
# 153
extern cudaError_t cudaRuntimeGetVersion(int * runtimeVersion); 
# 174 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_device_runtime_api.h"
__attribute__((unused)) extern void *cudaGetParameterBuffer(size_t alignment, size_t size); 
# 202 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_device_runtime_api.h"
__attribute__((unused)) extern void *cudaGetParameterBufferV2(void * func, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize); 
# 203
__attribute__((unused)) extern cudaError_t cudaLaunchDevice_ptsz(void * func, void * parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream); 
# 204
__attribute__((unused)) extern cudaError_t cudaLaunchDeviceV2_ptsz(void * parameterBuffer, cudaStream_t stream); 
# 222 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_device_runtime_api.h"
__attribute__((unused)) extern cudaError_t cudaLaunchDevice(void * func, void * parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream); 
# 223
__attribute__((unused)) extern cudaError_t cudaLaunchDeviceV2(void * parameterBuffer, cudaStream_t stream); 
# 226
extern cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, const void * func, int blockSize, size_t dynamicSmemSize); 
# 227
extern cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, const void * func, int blockSize, size_t dynamicSmemSize, unsigned flags); 
# 229
__attribute__((unused)) extern unsigned long long cudaCGGetIntrinsicHandle(cudaCGScope scope); 
# 230
__attribute__((unused)) extern cudaError_t cudaCGSynchronize(unsigned long long handle, unsigned flags); 
# 231
__attribute__((unused)) extern cudaError_t cudaCGSynchronizeGrid(unsigned long long handle, unsigned flags); 
# 232
__attribute__((unused)) extern cudaError_t cudaCGGetSize(unsigned * numThreads, unsigned * numGrids, unsigned long long handle); 
# 233
__attribute__((unused)) extern cudaError_t cudaCGGetRank(unsigned * threadRank, unsigned * gridRank, unsigned long long handle); 
# 234
}
# 236
template< class T> static inline cudaError_t cudaMalloc(T ** devPtr, size_t size); 
# 237
template< class T> static inline cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, T * entry); 
# 238
template< class T> static inline cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, T func, int blockSize, size_t dynamicSmemSize); 
# 239
template< class T> static inline cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, T func, int blockSize, size_t dynamicSmemSize, unsigned flags); 
# 264 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern "C" {
# 299 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceReset(); 
# 320 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceSynchronize(); 
# 407 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceSetLimit(cudaLimit limit, size_t value); 
# 442 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetLimit(size_t * pValue, cudaLimit limit); 
# 465 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetTexture1DLinearMaxWidth(size_t * maxWidthInElements, const cudaChannelFormatDesc * fmtDesc, int device); 
# 499 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetCacheConfig(cudaFuncCache * pCacheConfig); 
# 536 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetStreamPriorityRange(int * leastPriority, int * greatestPriority); 
# 580 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceSetCacheConfig(cudaFuncCache cacheConfig); 
# 611 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig); 
# 655 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceSetSharedMemConfig(cudaSharedMemConfig config); 
# 682 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetByPCIBusId(int * device, const char * pciBusId); 
# 712 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetPCIBusId(char * pciBusId, int len, int device); 
# 760 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaIpcGetEventHandle(cudaIpcEventHandle_t * handle, cudaEvent_t event); 
# 801 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaIpcOpenEventHandle(cudaEvent_t * event, cudaIpcEventHandle_t handle); 
# 844 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaIpcGetMemHandle(cudaIpcMemHandle_t * handle, void * devPtr); 
# 908 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaIpcOpenMemHandle(void ** devPtr, cudaIpcMemHandle_t handle, unsigned flags); 
# 944 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaIpcCloseMemHandle(void * devPtr); 
# 976 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceFlushGPUDirectRDMAWrites(cudaFlushGPUDirectRDMAWritesTarget target, cudaFlushGPUDirectRDMAWritesScope scope); 
# 1020 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaThreadExit(); 
# 1046 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaThreadSynchronize(); 
# 1095 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaThreadSetLimit(cudaLimit limit, size_t value); 
# 1128 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaThreadGetLimit(size_t * pValue, cudaLimit limit); 
# 1164 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaThreadGetCacheConfig(cudaFuncCache * pCacheConfig); 
# 1211 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaThreadSetCacheConfig(cudaFuncCache cacheConfig); 
# 1274 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetLastError(); 
# 1322 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaPeekAtLastError(); 
# 1338 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern const char *cudaGetErrorName(cudaError_t error); 
# 1354 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern const char *cudaGetErrorString(cudaError_t error); 
# 1382 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetDeviceCount(int * count); 
# 1660 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetDeviceProperties(cudaDeviceProp * prop, int device); 
# 1855 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetAttribute(int * value, cudaDeviceAttr attr, int device); 
# 1873 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetDefaultMemPool(cudaMemPool_t * memPool, int device); 
# 1897 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceSetMemPool(int device, cudaMemPool_t memPool); 
# 1917 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetMemPool(cudaMemPool_t * memPool, int device); 
# 1965 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetNvSciSyncAttributes(void * nvSciSyncAttrList, int device, int flags); 
# 2005 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceGetP2PAttribute(int * value, cudaDeviceP2PAttr attr, int srcDevice, int dstDevice); 
# 2026 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaChooseDevice(int * device, const cudaDeviceProp * prop); 
# 2063 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaSetDevice(int device); 
# 2084 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetDevice(int * device); 
# 2115 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaSetValidDevices(int * device_arr, int len); 
# 2184 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaSetDeviceFlags(unsigned flags); 
# 2230 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetDeviceFlags(unsigned * flags); 
# 2270 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamCreate(cudaStream_t * pStream); 
# 2302 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamCreateWithFlags(cudaStream_t * pStream, unsigned flags); 
# 2348 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamCreateWithPriority(cudaStream_t * pStream, unsigned flags, int priority); 
# 2375 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamGetPriority(cudaStream_t hStream, int * priority); 
# 2400 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamGetFlags(cudaStream_t hStream, unsigned * flags); 
# 2415 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaCtxResetPersistingL2Cache(); 
# 2435 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamCopyAttributes(cudaStream_t dst, cudaStream_t src); 
# 2456 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamGetAttribute(cudaStream_t hStream, cudaStreamAttrID attr, cudaStreamAttrValue * value_out); 
# 2480 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamSetAttribute(cudaStream_t hStream, cudaStreamAttrID attr, const cudaStreamAttrValue * value); 
# 2514 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamDestroy(cudaStream_t stream); 
# 2545 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned flags = 0); 
# 2553
typedef void (*cudaStreamCallback_t)(cudaStream_t stream, cudaError_t status, void * userData); 
# 2620 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamAddCallback(cudaStream_t stream, cudaStreamCallback_t callback, void * userData, unsigned flags); 
# 2644 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamSynchronize(cudaStream_t stream); 
# 2669 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamQuery(cudaStream_t stream); 
# 2753 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamAttachMemAsync(cudaStream_t stream, void * devPtr, size_t length = 0, unsigned flags = 4); 
# 2792 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamBeginCapture(cudaStream_t stream, cudaStreamCaptureMode mode); 
# 2843 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaThreadExchangeStreamCaptureMode(cudaStreamCaptureMode * mode); 
# 2871 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamEndCapture(cudaStream_t stream, cudaGraph_t * pGraph); 
# 2909 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamIsCapturing(cudaStream_t stream, cudaStreamCaptureStatus * pCaptureStatus); 
# 2941 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamGetCaptureInfo(cudaStream_t stream, cudaStreamCaptureStatus * pCaptureStatus, unsigned long long * pId); 
# 2996 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamGetCaptureInfo_v2(cudaStream_t stream, cudaStreamCaptureStatus * captureStatus_out, unsigned long long * id_out = 0, cudaGraph_t * graph_out = 0, const cudaGraphNode_t ** dependencies_out = 0, size_t * numDependencies_out = 0); 
# 3029 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaStreamUpdateCaptureDependencies(cudaStream_t stream, cudaGraphNode_t * dependencies, size_t numDependencies, unsigned flags = 0); 
# 3066 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaEventCreate(cudaEvent_t * event); 
# 3103 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaEventCreateWithFlags(cudaEvent_t * event, unsigned flags); 
# 3143 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream = 0); 
# 3190 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaEventRecordWithFlags(cudaEvent_t event, cudaStream_t stream = 0, unsigned flags = 0); 
# 3222 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaEventQuery(cudaEvent_t event); 
# 3252 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaEventSynchronize(cudaEvent_t event); 
# 3281 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaEventDestroy(cudaEvent_t event); 
# 3324 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaEventElapsedTime(float * ms, cudaEvent_t start, cudaEvent_t end); 
# 3501 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaImportExternalMemory(cudaExternalMemory_t * extMem_out, const cudaExternalMemoryHandleDesc * memHandleDesc); 
# 3555 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaExternalMemoryGetMappedBuffer(void ** devPtr, cudaExternalMemory_t extMem, const cudaExternalMemoryBufferDesc * bufferDesc); 
# 3614 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaExternalMemoryGetMappedMipmappedArray(cudaMipmappedArray_t * mipmap, cudaExternalMemory_t extMem, const cudaExternalMemoryMipmappedArrayDesc * mipmapDesc); 
# 3638 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDestroyExternalMemory(cudaExternalMemory_t extMem); 
# 3791 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaImportExternalSemaphore(cudaExternalSemaphore_t * extSem_out, const cudaExternalSemaphoreHandleDesc * semHandleDesc); 
# 3858 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaSignalExternalSemaphoresAsync_v2(const cudaExternalSemaphore_t * extSemArray, const cudaExternalSemaphoreSignalParams * paramsArray, unsigned numExtSems, cudaStream_t stream = 0); 
# 3934 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaWaitExternalSemaphoresAsync_v2(const cudaExternalSemaphore_t * extSemArray, const cudaExternalSemaphoreWaitParams * paramsArray, unsigned numExtSems, cudaStream_t stream = 0); 
# 3957 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDestroyExternalSemaphore(cudaExternalSemaphore_t extSem); 
# 4024 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaLaunchKernel(const void * func, dim3 gridDim, dim3 blockDim, void ** args, size_t sharedMem, cudaStream_t stream); 
# 4081 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaLaunchCooperativeKernel(const void * func, dim3 gridDim, dim3 blockDim, void ** args, size_t sharedMem, cudaStream_t stream); 
# 4182 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaLaunchCooperativeKernelMultiDevice(cudaLaunchParams * launchParamsList, unsigned numDevices, unsigned flags = 0); 
# 4229 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaFuncSetCacheConfig(const void * func, cudaFuncCache cacheConfig); 
# 4284 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaFuncSetSharedMemConfig(const void * func, cudaSharedMemConfig config); 
# 4317 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, const void * func); 
# 4354 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaFuncSetAttribute(const void * func, cudaFuncAttribute attr, int value); 
# 4380 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaSetDoubleForDevice(double * d); 
# 4404 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaSetDoubleForHost(double * d); 
# 4472 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaLaunchHostFunc(cudaStream_t stream, cudaHostFn_t fn, void * userData); 
# 4529 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, const void * func, int blockSize, size_t dynamicSMemSize); 
# 4558 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaOccupancyAvailableDynamicSMemPerBlock(size_t * dynamicSmemSize, const void * func, int numBlocks, int blockSize); 
# 4603 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, const void * func, int blockSize, size_t dynamicSMemSize, unsigned flags); 
# 4724 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMallocManaged(void ** devPtr, size_t size, unsigned flags = 1); 
# 4757 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMalloc(void ** devPtr, size_t size); 
# 4790 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMallocHost(void ** ptr, size_t size); 
# 4833 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMallocPitch(void ** devPtr, size_t * pitch, size_t width, size_t height); 
# 4882 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMallocArray(cudaArray_t * array, const cudaChannelFormatDesc * desc, size_t width, size_t height = 0, unsigned flags = 0); 
# 4911 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaFree(void * devPtr); 
# 4934 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaFreeHost(void * ptr); 
# 4957 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaFreeArray(cudaArray_t array); 
# 4980 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaFreeMipmappedArray(cudaMipmappedArray_t mipmappedArray); 
# 5046 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaHostAlloc(void ** pHost, size_t size, unsigned flags); 
# 5139 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaHostRegister(void * ptr, size_t size, unsigned flags); 
# 5162 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaHostUnregister(void * ptr); 
# 5207 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaHostGetDevicePointer(void ** pDevice, void * pHost, unsigned flags); 
# 5229 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaHostGetFlags(unsigned * pFlags, void * pHost); 
# 5268 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMalloc3D(cudaPitchedPtr * pitchedDevPtr, cudaExtent extent); 
# 5410 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMalloc3DArray(cudaArray_t * array, const cudaChannelFormatDesc * desc, cudaExtent extent, unsigned flags = 0); 
# 5552 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMallocMipmappedArray(cudaMipmappedArray_t * mipmappedArray, const cudaChannelFormatDesc * desc, cudaExtent extent, unsigned numLevels, unsigned flags = 0); 
# 5585 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetMipmappedArrayLevel(cudaArray_t * levelArray, cudaMipmappedArray_const_t mipmappedArray, unsigned level); 
# 5690 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms * p); 
# 5721 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy3DPeer(const cudaMemcpy3DPeerParms * p); 
# 5839 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms * p, cudaStream_t stream = 0); 
# 5865 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy3DPeerAsync(const cudaMemcpy3DPeerParms * p, cudaStream_t stream = 0); 
# 5887 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemGetInfo(size_t * free, size_t * total); 
# 5913 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaArrayGetInfo(cudaChannelFormatDesc * desc, cudaExtent * extent, unsigned * flags, cudaArray_t array); 
# 5942 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaArrayGetPlane(cudaArray_t * pPlaneArray, cudaArray_t hArray, unsigned planeIdx); 
# 5970 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaArray_t array); 
# 6000 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMipmappedArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaMipmappedArray_t mipmap); 
# 6045 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy(void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
# 6080 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpyPeer(void * dst, int dstDevice, const void * src, int srcDevice, size_t count); 
# 6129 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy2D(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind); 
# 6179 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy2DToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind); 
# 6229 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy2DFromArray(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind); 
# 6276 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy2DArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice); 
# 6319 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpyToSymbol(const void * symbol, const void * src, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyHostToDevice); 
# 6362 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpyFromSymbol(void * dst, const void * symbol, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyDeviceToHost); 
# 6419 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpyAsync(void * dst, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 6454 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpyPeerAsync(void * dst, int dstDevice, const void * src, int srcDevice, size_t count, cudaStream_t stream = 0); 
# 6517 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy2DAsync(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 6575 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy2DToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 6632 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpy2DFromArrayAsync(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 6683 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpyToSymbolAsync(const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 6734 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemcpyFromSymbolAsync(void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 6763 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemset(void * devPtr, int value, size_t count); 
# 6797 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemset2D(void * devPtr, size_t pitch, int value, size_t width, size_t height); 
# 6843 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemset3D(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent); 
# 6879 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream = 0); 
# 6920 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemset2DAsync(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream = 0); 
# 6973 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream = 0); 
# 7001 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetSymbolAddress(void ** devPtr, const void * symbol); 
# 7028 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetSymbolSize(size_t * size, const void * symbol); 
# 7098 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPrefetchAsync(const void * devPtr, size_t count, int dstDevice, cudaStream_t stream = 0); 
# 7214 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemAdvise(const void * devPtr, size_t count, cudaMemoryAdvise advice, int device); 
# 7273 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemRangeGetAttribute(void * data, size_t dataSize, cudaMemRangeAttribute attribute, const void * devPtr, size_t count); 
# 7312 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemRangeGetAttributes(void ** data, size_t * dataSizes, cudaMemRangeAttribute * attributes, size_t numAttributes, const void * devPtr, size_t count); 
# 7372 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaMemcpyToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t count, cudaMemcpyKind kind); 
# 7414 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaMemcpyFromArray(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind); 
# 7457 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaMemcpyArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice); 
# 7508 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaMemcpyToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 7558 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaMemcpyFromArrayAsync(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 7624 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMallocAsync(void ** devPtr, size_t size, cudaStream_t hStream); 
# 7647 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaFreeAsync(void * devPtr, cudaStream_t hStream); 
# 7672 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolTrimTo(cudaMemPool_t memPool, size_t minBytesToKeep); 
# 7710 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolSetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value); 
# 7748 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolGetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value); 
# 7763 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolSetAccess(cudaMemPool_t memPool, const cudaMemAccessDesc * descList, size_t count); 
# 7776 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolGetAccess(cudaMemAccessFlags * flags, cudaMemPool_t memPool, cudaMemLocation * location); 
# 7796 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolCreate(cudaMemPool_t * memPool, const cudaMemPoolProps * poolProps); 
# 7818 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolDestroy(cudaMemPool_t memPool); 
# 7850 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMallocFromPoolAsync(void ** ptr, size_t size, cudaMemPool_t memPool, cudaStream_t stream); 
# 7875 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolExportToShareableHandle(void * shareableHandle, cudaMemPool_t memPool, cudaMemAllocationHandleType handleType, unsigned flags); 
# 7902 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolImportFromShareableHandle(cudaMemPool_t * memPool, void * shareableHandle, cudaMemAllocationHandleType handleType, unsigned flags); 
# 7925 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolExportPointer(cudaMemPoolPtrExportData * exportData, void * ptr); 
# 7954 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaMemPoolImportPointer(void ** ptr, cudaMemPool_t memPool, cudaMemPoolPtrExportData * exportData); 
# 8106 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaPointerGetAttributes(cudaPointerAttributes * attributes, const void * ptr); 
# 8147 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceCanAccessPeer(int * canAccessPeer, int device, int peerDevice); 
# 8189 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceEnablePeerAccess(int peerDevice, unsigned flags); 
# 8211 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDeviceDisablePeerAccess(int peerDevice); 
# 8275 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource_t resource); 
# 8310 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t resource, unsigned flags); 
# 8349 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphicsMapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream = 0); 
# 8384 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphicsUnmapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream = 0); 
# 8416 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphicsResourceGetMappedPointer(void ** devPtr, size_t * size, cudaGraphicsResource_t resource); 
# 8454 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray_t * array, cudaGraphicsResource_t resource, unsigned arrayIndex, unsigned mipLevel); 
# 8483 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphicsResourceGetMappedMipmappedArray(cudaMipmappedArray_t * mipmappedArray, cudaGraphicsResource_t resource); 
# 8554 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaBindTexture(size_t * offset, const textureReference * texref, const void * devPtr, const cudaChannelFormatDesc * desc, size_t size = ((2147483647) * 2U) + 1U); 
# 8613 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaBindTexture2D(size_t * offset, const textureReference * texref, const void * devPtr, const cudaChannelFormatDesc * desc, size_t width, size_t height, size_t pitch); 
# 8651 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaBindTextureToArray(const textureReference * texref, cudaArray_const_t array, const cudaChannelFormatDesc * desc); 
# 8691 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaBindTextureToMipmappedArray(const textureReference * texref, cudaMipmappedArray_const_t mipmappedArray, const cudaChannelFormatDesc * desc); 
# 8717 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaUnbindTexture(const textureReference * texref); 
# 8746 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaGetTextureAlignmentOffset(size_t * offset, const textureReference * texref); 
# 8776 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaGetTextureReference(const textureReference ** texref, const void * symbol); 
# 8821 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaBindSurfaceToArray(const surfaceReference * surfref, cudaArray_const_t array, const cudaChannelFormatDesc * desc); 
# 8846 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
__attribute((deprecated)) extern cudaError_t cudaGetSurfaceReference(const surfaceReference ** surfref, const void * symbol); 
# 8881 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc * desc, cudaArray_const_t array); 
# 8911 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w, cudaChannelFormatKind f); 
# 9129 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaCreateTextureObject(cudaTextureObject_t * pTexObject, const cudaResourceDesc * pResDesc, const cudaTextureDesc * pTexDesc, const cudaResourceViewDesc * pResViewDesc); 
# 9149 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDestroyTextureObject(cudaTextureObject_t texObject); 
# 9169 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetTextureObjectResourceDesc(cudaResourceDesc * pResDesc, cudaTextureObject_t texObject); 
# 9189 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetTextureObjectTextureDesc(cudaTextureDesc * pTexDesc, cudaTextureObject_t texObject); 
# 9210 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetTextureObjectResourceViewDesc(cudaResourceViewDesc * pResViewDesc, cudaTextureObject_t texObject); 
# 9255 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaCreateSurfaceObject(cudaSurfaceObject_t * pSurfObject, const cudaResourceDesc * pResDesc); 
# 9275 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDestroySurfaceObject(cudaSurfaceObject_t surfObject); 
# 9294 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetSurfaceObjectResourceDesc(cudaResourceDesc * pResDesc, cudaSurfaceObject_t surfObject); 
# 9328 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaDriverGetVersion(int * driverVersion); 
# 9353 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaRuntimeGetVersion(int * runtimeVersion); 
# 9400 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphCreate(cudaGraph_t * pGraph, unsigned flags); 
# 9497 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddKernelNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaKernelNodeParams * pNodeParams); 
# 9530 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphKernelNodeGetParams(cudaGraphNode_t node, cudaKernelNodeParams * pNodeParams); 
# 9555 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphKernelNodeSetParams(cudaGraphNode_t node, const cudaKernelNodeParams * pNodeParams); 
# 9575 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphKernelNodeCopyAttributes(cudaGraphNode_t hSrc, cudaGraphNode_t hDst); 
# 9598 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphKernelNodeGetAttribute(cudaGraphNode_t hNode, cudaKernelNodeAttrID attr, cudaKernelNodeAttrValue * value_out); 
# 9622 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphKernelNodeSetAttribute(cudaGraphNode_t hNode, cudaKernelNodeAttrID attr, const cudaKernelNodeAttrValue * value); 
# 9672 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddMemcpyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaMemcpy3DParms * pCopyParams); 
# 9731 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddMemcpyNodeToSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind); 
# 9800 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddMemcpyNodeFromSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind); 
# 9868 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddMemcpyNode1D(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
# 9900 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphMemcpyNodeGetParams(cudaGraphNode_t node, cudaMemcpy3DParms * pNodeParams); 
# 9926 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphMemcpyNodeSetParams(cudaGraphNode_t node, const cudaMemcpy3DParms * pNodeParams); 
# 9965 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphMemcpyNodeSetParamsToSymbol(cudaGraphNode_t node, const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind); 
# 10011 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphMemcpyNodeSetParamsFromSymbol(cudaGraphNode_t node, void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind); 
# 10057 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphMemcpyNodeSetParams1D(cudaGraphNode_t node, void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
# 10104 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddMemsetNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaMemsetParams * pMemsetParams); 
# 10127 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphMemsetNodeGetParams(cudaGraphNode_t node, cudaMemsetParams * pNodeParams); 
# 10150 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphMemsetNodeSetParams(cudaGraphNode_t node, const cudaMemsetParams * pNodeParams); 
# 10191 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddHostNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaHostNodeParams * pNodeParams); 
# 10214 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphHostNodeGetParams(cudaGraphNode_t node, cudaHostNodeParams * pNodeParams); 
# 10237 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphHostNodeSetParams(cudaGraphNode_t node, const cudaHostNodeParams * pNodeParams); 
# 10275 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddChildGraphNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaGraph_t childGraph); 
# 10299 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphChildGraphNodeGetGraph(cudaGraphNode_t node, cudaGraph_t * pGraph); 
# 10336 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddEmptyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies); 
# 10380 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddEventRecordNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaEvent_t event); 
# 10407 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphEventRecordNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out); 
# 10434 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphEventRecordNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event); 
# 10481 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddEventWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaEvent_t event); 
# 10508 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphEventWaitNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out); 
# 10535 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphEventWaitNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event); 
# 10585 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddExternalSemaphoresSignalNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaExternalSemaphoreSignalNodeParams * nodeParams); 
# 10618 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExternalSemaphoresSignalNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreSignalNodeParams * params_out); 
# 10645 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExternalSemaphoresSignalNodeSetParams(cudaGraphNode_t hNode, const cudaExternalSemaphoreSignalNodeParams * nodeParams); 
# 10695 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddExternalSemaphoresWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaExternalSemaphoreWaitNodeParams * nodeParams); 
# 10728 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExternalSemaphoresWaitNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreWaitNodeParams * params_out); 
# 10755 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExternalSemaphoresWaitNodeSetParams(cudaGraphNode_t hNode, const cudaExternalSemaphoreWaitNodeParams * nodeParams); 
# 10783 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphClone(cudaGraph_t * pGraphClone, cudaGraph_t originalGraph); 
# 10811 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphNodeFindInClone(cudaGraphNode_t * pNode, cudaGraphNode_t originalNode, cudaGraph_t clonedGraph); 
# 10842 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphNodeGetType(cudaGraphNode_t node, cudaGraphNodeType * pType); 
# 10873 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphGetNodes(cudaGraph_t graph, cudaGraphNode_t * nodes, size_t * numNodes); 
# 10904 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphGetRootNodes(cudaGraph_t graph, cudaGraphNode_t * pRootNodes, size_t * pNumRootNodes); 
# 10938 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphGetEdges(cudaGraph_t graph, cudaGraphNode_t * from, cudaGraphNode_t * to, size_t * numEdges); 
# 10969 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphNodeGetDependencies(cudaGraphNode_t node, cudaGraphNode_t * pDependencies, size_t * pNumDependencies); 
# 11001 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphNodeGetDependentNodes(cudaGraphNode_t node, cudaGraphNode_t * pDependentNodes, size_t * pNumDependentNodes); 
# 11032 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphAddDependencies(cudaGraph_t graph, const cudaGraphNode_t * from, const cudaGraphNode_t * to, size_t numDependencies); 
# 11063 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphRemoveDependencies(cudaGraph_t graph, const cudaGraphNode_t * from, const cudaGraphNode_t * to, size_t numDependencies); 
# 11090 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphDestroyNode(cudaGraphNode_t node); 
# 11127 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphInstantiate(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, cudaGraphNode_t * pErrorNode, char * pLogBuffer, size_t bufferSize); 
# 11170 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecKernelNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaKernelNodeParams * pNodeParams); 
# 11220 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecMemcpyNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaMemcpy3DParms * pNodeParams); 
# 11275 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecMemcpyNodeSetParamsToSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind); 
# 11338 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecMemcpyNodeSetParamsFromSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind); 
# 11399 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecMemcpyNodeSetParams1D(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
# 11453 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecMemsetNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaMemsetParams * pNodeParams); 
# 11492 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecHostNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaHostNodeParams * pNodeParams); 
# 11538 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecChildGraphNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaGraph_t childGraph); 
# 11580 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecEventRecordNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event); 
# 11622 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecEventWaitNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event); 
# 11667 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecExternalSemaphoresSignalNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, const cudaExternalSemaphoreSignalNodeParams * nodeParams); 
# 11712 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecExternalSemaphoresWaitNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, const cudaExternalSemaphoreWaitNodeParams * nodeParams); 
# 11787 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecUpdate(cudaGraphExec_t hGraphExec, cudaGraph_t hGraph, cudaGraphNode_t * hErrorNode_out, cudaGraphExecUpdateResult * updateResult_out); 
# 11811 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphUpload(cudaGraphExec_t graphExec, cudaStream_t stream); 
# 11838 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphLaunch(cudaGraphExec_t graphExec, cudaStream_t stream); 
# 11861 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphExecDestroy(cudaGraphExec_t graphExec); 
# 11882 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphDestroy(cudaGraph_t graph); 
# 11901 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphDebugDotPrint(cudaGraph_t graph, const char * path, unsigned flags); 
# 11937 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaUserObjectCreate(cudaUserObject_t * object_out, void * ptr, cudaHostFn_t destroy, unsigned initialRefcount, unsigned flags); 
# 11961 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaUserObjectRetain(cudaUserObject_t object, unsigned count = 1); 
# 11989 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaUserObjectRelease(cudaUserObject_t object, unsigned count = 1); 
# 12017 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphRetainUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned count = 1, unsigned flags = 0); 
# 12042 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGraphReleaseUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned count = 1); 
# 12108 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetDriverEntryPoint(const char * symbol, void ** funcPtr, unsigned long long flags); 
# 12113
extern cudaError_t cudaGetExportTable(const void ** ppExportTable, const cudaUUID_t * pExportTableId); 
# 12289 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern cudaError_t cudaGetFuncBySymbol(cudaFunction_t * functionPtr, const void * symbolPtr); 
# 12431 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
}
# 104 "/usr/local/cuda/bin/../targets/x86_64-linux/include/channel_descriptor.h"
template< class T> inline cudaChannelFormatDesc cudaCreateChannelDesc() 
# 105
{ 
# 106
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone); 
# 107
} 
# 109
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf() 
# 110
{ 
# 111
int e = (((int)sizeof(unsigned short)) * 8); 
# 113
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 114
} 
# 116
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1() 
# 117
{ 
# 118
int e = (((int)sizeof(unsigned short)) * 8); 
# 120
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 121
} 
# 123
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2() 
# 124
{ 
# 125
int e = (((int)sizeof(unsigned short)) * 8); 
# 127
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
# 128
} 
# 130
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4() 
# 131
{ 
# 132
int e = (((int)sizeof(unsigned short)) * 8); 
# 134
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
# 135
} 
# 137
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> () 
# 138
{ 
# 139
int e = (((int)sizeof(char)) * 8); 
# 144
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 146
} 
# 148
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> () 
# 149
{ 
# 150
int e = (((int)sizeof(signed char)) * 8); 
# 152
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 153
} 
# 155
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> () 
# 156
{ 
# 157
int e = (((int)sizeof(unsigned char)) * 8); 
# 159
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 160
} 
# 162
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> () 
# 163
{ 
# 164
int e = (((int)sizeof(signed char)) * 8); 
# 166
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 167
} 
# 169
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> () 
# 170
{ 
# 171
int e = (((int)sizeof(unsigned char)) * 8); 
# 173
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 174
} 
# 176
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> () 
# 177
{ 
# 178
int e = (((int)sizeof(signed char)) * 8); 
# 180
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
# 181
} 
# 183
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> () 
# 184
{ 
# 185
int e = (((int)sizeof(unsigned char)) * 8); 
# 187
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
# 188
} 
# 190
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> () 
# 191
{ 
# 192
int e = (((int)sizeof(signed char)) * 8); 
# 194
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
# 195
} 
# 197
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> () 
# 198
{ 
# 199
int e = (((int)sizeof(unsigned char)) * 8); 
# 201
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
# 202
} 
# 204
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> () 
# 205
{ 
# 206
int e = (((int)sizeof(short)) * 8); 
# 208
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 209
} 
# 211
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> () 
# 212
{ 
# 213
int e = (((int)sizeof(unsigned short)) * 8); 
# 215
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 216
} 
# 218
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> () 
# 219
{ 
# 220
int e = (((int)sizeof(short)) * 8); 
# 222
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 223
} 
# 225
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> () 
# 226
{ 
# 227
int e = (((int)sizeof(unsigned short)) * 8); 
# 229
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 230
} 
# 232
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> () 
# 233
{ 
# 234
int e = (((int)sizeof(short)) * 8); 
# 236
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
# 237
} 
# 239
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> () 
# 240
{ 
# 241
int e = (((int)sizeof(unsigned short)) * 8); 
# 243
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
# 244
} 
# 246
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> () 
# 247
{ 
# 248
int e = (((int)sizeof(short)) * 8); 
# 250
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
# 251
} 
# 253
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> () 
# 254
{ 
# 255
int e = (((int)sizeof(unsigned short)) * 8); 
# 257
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
# 258
} 
# 260
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> () 
# 261
{ 
# 262
int e = (((int)sizeof(int)) * 8); 
# 264
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 265
} 
# 267
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> () 
# 268
{ 
# 269
int e = (((int)sizeof(unsigned)) * 8); 
# 271
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 272
} 
# 274
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> () 
# 275
{ 
# 276
int e = (((int)sizeof(int)) * 8); 
# 278
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 279
} 
# 281
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> () 
# 282
{ 
# 283
int e = (((int)sizeof(unsigned)) * 8); 
# 285
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 286
} 
# 288
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> () 
# 289
{ 
# 290
int e = (((int)sizeof(int)) * 8); 
# 292
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
# 293
} 
# 295
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> () 
# 296
{ 
# 297
int e = (((int)sizeof(unsigned)) * 8); 
# 299
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
# 300
} 
# 302
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> () 
# 303
{ 
# 304
int e = (((int)sizeof(int)) * 8); 
# 306
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
# 307
} 
# 309
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> () 
# 310
{ 
# 311
int e = (((int)sizeof(unsigned)) * 8); 
# 313
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
# 314
} 
# 376 "/usr/local/cuda/bin/../targets/x86_64-linux/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> () 
# 377
{ 
# 378
int e = (((int)sizeof(float)) * 8); 
# 380
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 381
} 
# 383
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> () 
# 384
{ 
# 385
int e = (((int)sizeof(float)) * 8); 
# 387
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 388
} 
# 390
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> () 
# 391
{ 
# 392
int e = (((int)sizeof(float)) * 8); 
# 394
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
# 395
} 
# 397
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> () 
# 398
{ 
# 399
int e = (((int)sizeof(float)) * 8); 
# 401
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
# 402
} 
# 404
static inline cudaChannelFormatDesc cudaCreateChannelDescNV12() 
# 405
{ 
# 406
int e = (((int)sizeof(char)) * 8); 
# 408
return cudaCreateChannelDesc(e, e, e, 0, cudaChannelFormatKindNV12); 
# 409
} 
# 79 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz) 
# 80
{ 
# 81
cudaPitchedPtr s; 
# 83
(s.ptr) = d; 
# 84
(s.pitch) = p; 
# 85
(s.xsize) = xsz; 
# 86
(s.ysize) = ysz; 
# 88
return s; 
# 89
} 
# 106 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z) 
# 107
{ 
# 108
cudaPos p; 
# 110
(p.x) = x; 
# 111
(p.y) = y; 
# 112
(p.z) = z; 
# 114
return p; 
# 115
} 
# 132 "/usr/local/cuda/bin/../targets/x86_64-linux/include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d) 
# 133
{ 
# 134
cudaExtent e; 
# 136
(e.width) = w; 
# 137
(e.height) = h; 
# 138
(e.depth) = d; 
# 140
return e; 
# 141
} 
# 73 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_functions.h"
static inline char1 make_char1(signed char x); 
# 75
static inline uchar1 make_uchar1(unsigned char x); 
# 77
static inline char2 make_char2(signed char x, signed char y); 
# 79
static inline uchar2 make_uchar2(unsigned char x, unsigned char y); 
# 81
static inline char3 make_char3(signed char x, signed char y, signed char z); 
# 83
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z); 
# 85
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w); 
# 87
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w); 
# 89
static inline short1 make_short1(short x); 
# 91
static inline ushort1 make_ushort1(unsigned short x); 
# 93
static inline short2 make_short2(short x, short y); 
# 95
static inline ushort2 make_ushort2(unsigned short x, unsigned short y); 
# 97
static inline short3 make_short3(short x, short y, short z); 
# 99
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z); 
# 101
static inline short4 make_short4(short x, short y, short z, short w); 
# 103
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w); 
# 105
static inline int1 make_int1(int x); 
# 107
static inline uint1 make_uint1(unsigned x); 
# 109
static inline int2 make_int2(int x, int y); 
# 111
static inline uint2 make_uint2(unsigned x, unsigned y); 
# 113
static inline int3 make_int3(int x, int y, int z); 
# 115
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z); 
# 117
static inline int4 make_int4(int x, int y, int z, int w); 
# 119
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w); 
# 121
static inline long1 make_long1(long x); 
# 123
static inline ulong1 make_ulong1(unsigned long x); 
# 125
static inline long2 make_long2(long x, long y); 
# 127
static inline ulong2 make_ulong2(unsigned long x, unsigned long y); 
# 129
static inline long3 make_long3(long x, long y, long z); 
# 131
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z); 
# 133
static inline long4 make_long4(long x, long y, long z, long w); 
# 135
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w); 
# 137
static inline float1 make_float1(float x); 
# 139
static inline float2 make_float2(float x, float y); 
# 141
static inline float3 make_float3(float x, float y, float z); 
# 143
static inline float4 make_float4(float x, float y, float z, float w); 
# 145
static inline longlong1 make_longlong1(long long x); 
# 147
static inline ulonglong1 make_ulonglong1(unsigned long long x); 
# 149
static inline longlong2 make_longlong2(long long x, long long y); 
# 151
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y); 
# 153
static inline longlong3 make_longlong3(long long x, long long y, long long z); 
# 155
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z); 
# 157
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w); 
# 159
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w); 
# 161
static inline double1 make_double1(double x); 
# 163
static inline double2 make_double2(double x, double y); 
# 165
static inline double3 make_double3(double x, double y, double z); 
# 167
static inline double4 make_double4(double x, double y, double z, double w); 
# 73 "/usr/local/cuda/bin/../targets/x86_64-linux/include/vector_functions.hpp"
static inline char1 make_char1(signed char x) 
# 74
{ 
# 75
char1 t; (t.x) = x; return t; 
# 76
} 
# 78
static inline uchar1 make_uchar1(unsigned char x) 
# 79
{ 
# 80
uchar1 t; (t.x) = x; return t; 
# 81
} 
# 83
static inline char2 make_char2(signed char x, signed char y) 
# 84
{ 
# 85
char2 t; (t.x) = x; (t.y) = y; return t; 
# 86
} 
# 88
static inline uchar2 make_uchar2(unsigned char x, unsigned char y) 
# 89
{ 
# 90
uchar2 t; (t.x) = x; (t.y) = y; return t; 
# 91
} 
# 93
static inline char3 make_char3(signed char x, signed char y, signed char z) 
# 94
{ 
# 95
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 96
} 
# 98
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z) 
# 99
{ 
# 100
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 101
} 
# 103
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w) 
# 104
{ 
# 105
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 106
} 
# 108
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w) 
# 109
{ 
# 110
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 111
} 
# 113
static inline short1 make_short1(short x) 
# 114
{ 
# 115
short1 t; (t.x) = x; return t; 
# 116
} 
# 118
static inline ushort1 make_ushort1(unsigned short x) 
# 119
{ 
# 120
ushort1 t; (t.x) = x; return t; 
# 121
} 
# 123
static inline short2 make_short2(short x, short y) 
# 124
{ 
# 125
short2 t; (t.x) = x; (t.y) = y; return t; 
# 126
} 
# 128
static inline ushort2 make_ushort2(unsigned short x, unsigned short y) 
# 129
{ 
# 130
ushort2 t; (t.x) = x; (t.y) = y; return t; 
# 131
} 
# 133
static inline short3 make_short3(short x, short y, short z) 
# 134
{ 
# 135
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 136
} 
# 138
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z) 
# 139
{ 
# 140
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 141
} 
# 143
static inline short4 make_short4(short x, short y, short z, short w) 
# 144
{ 
# 145
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 146
} 
# 148
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w) 
# 149
{ 
# 150
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 151
} 
# 153
static inline int1 make_int1(int x) 
# 154
{ 
# 155
int1 t; (t.x) = x; return t; 
# 156
} 
# 158
static inline uint1 make_uint1(unsigned x) 
# 159
{ 
# 160
uint1 t; (t.x) = x; return t; 
# 161
} 
# 163
static inline int2 make_int2(int x, int y) 
# 164
{ 
# 165
int2 t; (t.x) = x; (t.y) = y; return t; 
# 166
} 
# 168
static inline uint2 make_uint2(unsigned x, unsigned y) 
# 169
{ 
# 170
uint2 t; (t.x) = x; (t.y) = y; return t; 
# 171
} 
# 173
static inline int3 make_int3(int x, int y, int z) 
# 174
{ 
# 175
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 176
} 
# 178
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z) 
# 179
{ 
# 180
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 181
} 
# 183
static inline int4 make_int4(int x, int y, int z, int w) 
# 184
{ 
# 185
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 186
} 
# 188
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w) 
# 189
{ 
# 190
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 191
} 
# 193
static inline long1 make_long1(long x) 
# 194
{ 
# 195
long1 t; (t.x) = x; return t; 
# 196
} 
# 198
static inline ulong1 make_ulong1(unsigned long x) 
# 199
{ 
# 200
ulong1 t; (t.x) = x; return t; 
# 201
} 
# 203
static inline long2 make_long2(long x, long y) 
# 204
{ 
# 205
long2 t; (t.x) = x; (t.y) = y; return t; 
# 206
} 
# 208
static inline ulong2 make_ulong2(unsigned long x, unsigned long y) 
# 209
{ 
# 210
ulong2 t; (t.x) = x; (t.y) = y; return t; 
# 211
} 
# 213
static inline long3 make_long3(long x, long y, long z) 
# 214
{ 
# 215
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 216
} 
# 218
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z) 
# 219
{ 
# 220
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 221
} 
# 223
static inline long4 make_long4(long x, long y, long z, long w) 
# 224
{ 
# 225
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 226
} 
# 228
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w) 
# 229
{ 
# 230
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 231
} 
# 233
static inline float1 make_float1(float x) 
# 234
{ 
# 235
float1 t; (t.x) = x; return t; 
# 236
} 
# 238
static inline float2 make_float2(float x, float y) 
# 239
{ 
# 240
float2 t; (t.x) = x; (t.y) = y; return t; 
# 241
} 
# 243
static inline float3 make_float3(float x, float y, float z) 
# 244
{ 
# 245
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 246
} 
# 248
static inline float4 make_float4(float x, float y, float z, float w) 
# 249
{ 
# 250
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 251
} 
# 253
static inline longlong1 make_longlong1(long long x) 
# 254
{ 
# 255
longlong1 t; (t.x) = x; return t; 
# 256
} 
# 258
static inline ulonglong1 make_ulonglong1(unsigned long long x) 
# 259
{ 
# 260
ulonglong1 t; (t.x) = x; return t; 
# 261
} 
# 263
static inline longlong2 make_longlong2(long long x, long long y) 
# 264
{ 
# 265
longlong2 t; (t.x) = x; (t.y) = y; return t; 
# 266
} 
# 268
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y) 
# 269
{ 
# 270
ulonglong2 t; (t.x) = x; (t.y) = y; return t; 
# 271
} 
# 273
static inline longlong3 make_longlong3(long long x, long long y, long long z) 
# 274
{ 
# 275
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 276
} 
# 278
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z) 
# 279
{ 
# 280
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 281
} 
# 283
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w) 
# 284
{ 
# 285
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 286
} 
# 288
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w) 
# 289
{ 
# 290
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 291
} 
# 293
static inline double1 make_double1(double x) 
# 294
{ 
# 295
double1 t; (t.x) = x; return t; 
# 296
} 
# 298
static inline double2 make_double2(double x, double y) 
# 299
{ 
# 300
double2 t; (t.x) = x; (t.y) = y; return t; 
# 301
} 
# 303
static inline double3 make_double3(double x, double y, double z) 
# 304
{ 
# 305
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 306
} 
# 308
static inline double4 make_double4(double x, double y, double z, double w) 
# 309
{ 
# 310
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 311
} 
# 28 "/usr/include/string.h" 3
extern "C" {
# 42 "/usr/include/string.h" 3
extern void *memcpy(void *__restrict__ __dest, const void *__restrict__ __src, size_t __n) throw()
# 43
 __attribute((__nonnull__(1, 2))); 
# 46
extern void *memmove(void * __dest, const void * __src, size_t __n) throw()
# 47
 __attribute((__nonnull__(1, 2))); 
# 53
extern void *memccpy(void *__restrict__ __dest, const void *__restrict__ __src, int __c, size_t __n) throw()
# 55
 __attribute((__nonnull__(1, 2))); 
# 60
extern void *memset(void * __s, int __c, size_t __n) throw() __attribute((__nonnull__(1))); 
# 63
extern int memcmp(const void * __s1, const void * __s2, size_t __n) throw()
# 64
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 68
extern "C++" {
# 70
extern void *memchr(void * __s, int __c, size_t __n) throw() __asm__("memchr")
# 71
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 72
extern const void *memchr(const void * __s, int __c, size_t __n) throw() __asm__("memchr")
# 73
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 88 "/usr/include/string.h" 3
}
# 98 "/usr/include/string.h" 3
extern "C++" void *rawmemchr(void * __s, int __c) throw() __asm__("rawmemchr")
# 99
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 100
extern "C++" const void *rawmemchr(const void * __s, int __c) throw() __asm__("rawmemchr")
# 101
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 109
extern "C++" void *memrchr(void * __s, int __c, size_t __n) throw() __asm__("memrchr")
# 110
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 111
extern "C++" const void *memrchr(const void * __s, int __c, size_t __n) throw() __asm__("memrchr")
# 112
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 121 "/usr/include/string.h" 3
extern char *strcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 122
 __attribute((__nonnull__(1, 2))); 
# 124
extern char *strncpy(char *__restrict__ __dest, const char *__restrict__ __src, size_t __n) throw()
# 126
 __attribute((__nonnull__(1, 2))); 
# 129
extern char *strcat(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 130
 __attribute((__nonnull__(1, 2))); 
# 132
extern char *strncat(char *__restrict__ __dest, const char *__restrict__ __src, size_t __n) throw()
# 133
 __attribute((__nonnull__(1, 2))); 
# 136
extern int strcmp(const char * __s1, const char * __s2) throw()
# 137
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 139
extern int strncmp(const char * __s1, const char * __s2, size_t __n) throw()
# 140
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 143
extern int strcoll(const char * __s1, const char * __s2) throw()
# 144
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 146
extern size_t strxfrm(char *__restrict__ __dest, const char *__restrict__ __src, size_t __n) throw()
# 148
 __attribute((__nonnull__(2))); 
# 28 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3
struct __locale_struct { 
# 31
struct __locale_data *__locales[13]; 
# 34
const unsigned short *__ctype_b; 
# 35
const int *__ctype_tolower; 
# 36
const int *__ctype_toupper; 
# 39
const char *__names[13]; 
# 40
}; 
# 42
typedef __locale_struct *__locale_t; 
# 24 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3
typedef __locale_t locale_t; 
# 155 "/usr/include/string.h" 3
extern int strcoll_l(const char * __s1, const char * __s2, locale_t __l) throw()
# 156
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 3))); 
# 159
extern size_t strxfrm_l(char * __dest, const char * __src, size_t __n, locale_t __l) throw()
# 160
 __attribute((__nonnull__(2, 4))); 
# 166
extern char *strdup(const char * __s) throw()
# 167
 __attribute((__malloc__)) __attribute((__nonnull__(1))); 
# 174
extern char *strndup(const char * __string, size_t __n) throw()
# 175
 __attribute((__malloc__)) __attribute((__nonnull__(1))); 
# 203 "/usr/include/string.h" 3
extern "C++" {
# 205
extern char *strchr(char * __s, int __c) throw() __asm__("strchr")
# 206
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 207
extern const char *strchr(const char * __s, int __c) throw() __asm__("strchr")
# 208
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 223 "/usr/include/string.h" 3
}
# 230
extern "C++" {
# 232
extern char *strrchr(char * __s, int __c) throw() __asm__("strrchr")
# 233
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 234
extern const char *strrchr(const char * __s, int __c) throw() __asm__("strrchr")
# 235
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 250 "/usr/include/string.h" 3
}
# 260 "/usr/include/string.h" 3
extern "C++" char *strchrnul(char * __s, int __c) throw() __asm__("strchrnul")
# 261
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 262
extern "C++" const char *strchrnul(const char * __s, int __c) throw() __asm__("strchrnul")
# 263
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 272 "/usr/include/string.h" 3
extern size_t strcspn(const char * __s, const char * __reject) throw()
# 273
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 276
extern size_t strspn(const char * __s, const char * __accept) throw()
# 277
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 280
extern "C++" {
# 282
extern char *strpbrk(char * __s, const char * __accept) throw() __asm__("strpbrk")
# 283
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 284
extern const char *strpbrk(const char * __s, const char * __accept) throw() __asm__("strpbrk")
# 285
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 300 "/usr/include/string.h" 3
}
# 307
extern "C++" {
# 309
extern char *strstr(char * __haystack, const char * __needle) throw() __asm__("strstr")
# 310
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 311
extern const char *strstr(const char * __haystack, const char * __needle) throw() __asm__("strstr")
# 312
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 327 "/usr/include/string.h" 3
}
# 335
extern char *strtok(char *__restrict__ __s, const char *__restrict__ __delim) throw()
# 336
 __attribute((__nonnull__(2))); 
# 340
extern char *__strtok_r(char *__restrict__ __s, const char *__restrict__ __delim, char **__restrict__ __save_ptr) throw()
# 343
 __attribute((__nonnull__(2, 3))); 
# 345
extern char *strtok_r(char *__restrict__ __s, const char *__restrict__ __delim, char **__restrict__ __save_ptr) throw()
# 347
 __attribute((__nonnull__(2, 3))); 
# 353
extern "C++" char *strcasestr(char * __haystack, const char * __needle) throw() __asm__("strcasestr")
# 354
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 355
extern "C++" const char *strcasestr(const char * __haystack, const char * __needle) throw() __asm__("strcasestr")
# 357
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 368 "/usr/include/string.h" 3
extern void *memmem(const void * __haystack, size_t __haystacklen, const void * __needle, size_t __needlelen) throw()
# 370
 __attribute((__pure__)) __attribute((__nonnull__(1, 3))); 
# 374
extern void *__mempcpy(void *__restrict__ __dest, const void *__restrict__ __src, size_t __n) throw()
# 376
 __attribute((__nonnull__(1, 2))); 
# 377
extern void *mempcpy(void *__restrict__ __dest, const void *__restrict__ __src, size_t __n) throw()
# 379
 __attribute((__nonnull__(1, 2))); 
# 384
extern size_t strlen(const char * __s) throw()
# 385
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 390
extern size_t strnlen(const char * __string, size_t __maxlen) throw()
# 391
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 396
extern char *strerror(int __errnum) throw(); 
# 420 "/usr/include/string.h" 3
extern char *strerror_r(int __errnum, char * __buf, size_t __buflen) throw()
# 421
 __attribute((__nonnull__(2))); 
# 427
extern char *strerror_l(int __errnum, locale_t __l) throw(); 
# 30 "/usr/include/strings.h" 3
extern "C" {
# 34
extern int bcmp(const void * __s1, const void * __s2, size_t __n) throw()
# 35
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 38
extern void bcopy(const void * __src, void * __dest, size_t __n) throw()
# 39
 __attribute((__nonnull__(1, 2))); 
# 42
extern void bzero(void * __s, size_t __n) throw() __attribute((__nonnull__(1))); 
# 46
extern "C++" {
# 48
extern char *index(char * __s, int __c) throw() __asm__("index")
# 49
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 50
extern const char *index(const char * __s, int __c) throw() __asm__("index")
# 51
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 66 "/usr/include/strings.h" 3
}
# 74
extern "C++" {
# 76
extern char *rindex(char * __s, int __c) throw() __asm__("rindex")
# 77
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 78
extern const char *rindex(const char * __s, int __c) throw() __asm__("rindex")
# 79
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 94 "/usr/include/strings.h" 3
}
# 104 "/usr/include/strings.h" 3
extern int ffs(int __i) throw() __attribute((const)); 
# 110
extern int ffsl(long __l) throw() __attribute((const)); 
# 111
__extension__ extern int ffsll(long long __ll) throw()
# 112
 __attribute((const)); 
# 116
extern int strcasecmp(const char * __s1, const char * __s2) throw()
# 117
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 120
extern int strncasecmp(const char * __s1, const char * __s2, size_t __n) throw()
# 121
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 128
extern int strcasecmp_l(const char * __s1, const char * __s2, locale_t __loc) throw()
# 129
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 3))); 
# 133
extern int strncasecmp_l(const char * __s1, const char * __s2, size_t __n, locale_t __loc) throw()
# 135
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 4))); 
# 138
}
# 435 "/usr/include/string.h" 3
extern void explicit_bzero(void * __s, size_t __n) throw() __attribute((__nonnull__(1))); 
# 439
extern char *strsep(char **__restrict__ __stringp, const char *__restrict__ __delim) throw()
# 441
 __attribute((__nonnull__(1, 2))); 
# 446
extern char *strsignal(int __sig) throw(); 
# 449
extern char *__stpcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 450
 __attribute((__nonnull__(1, 2))); 
# 451
extern char *stpcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 452
 __attribute((__nonnull__(1, 2))); 
# 456
extern char *__stpncpy(char *__restrict__ __dest, const char *__restrict__ __src, size_t __n) throw()
# 458
 __attribute((__nonnull__(1, 2))); 
# 459
extern char *stpncpy(char *__restrict__ __dest, const char *__restrict__ __src, size_t __n) throw()
# 461
 __attribute((__nonnull__(1, 2))); 
# 466
extern int strverscmp(const char * __s1, const char * __s2) throw()
# 467
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 470
extern char *strfry(char * __string) throw() __attribute((__nonnull__(1))); 
# 473
extern void *memfrob(void * __s, size_t __n) throw() __attribute((__nonnull__(1))); 
# 481
extern "C++" char *basename(char * __filename) throw() __asm__("basename")
# 482
 __attribute((__nonnull__(1))); 
# 483
extern "C++" const char *basename(const char * __filename) throw() __asm__("basename")
# 484
 __attribute((__nonnull__(1))); 
# 498 "/usr/include/string.h" 3
}
# 30 "/usr/include/x86_64-linux-gnu/bits/types.h" 3
typedef unsigned char __u_char; 
# 31
typedef unsigned short __u_short; 
# 32
typedef unsigned __u_int; 
# 33
typedef unsigned long __u_long; 
# 36
typedef signed char __int8_t; 
# 37
typedef unsigned char __uint8_t; 
# 38
typedef signed short __int16_t; 
# 39
typedef unsigned short __uint16_t; 
# 40
typedef signed int __int32_t; 
# 41
typedef unsigned __uint32_t; 
# 43
typedef signed long __int64_t; 
# 44
typedef unsigned long __uint64_t; 
# 52
typedef long __quad_t; 
# 53
typedef unsigned long __u_quad_t; 
# 61
typedef long __intmax_t; 
# 62
typedef unsigned long __uintmax_t; 
# 133 "/usr/include/x86_64-linux-gnu/bits/types.h" 3
typedef unsigned long __dev_t; 
# 134
typedef unsigned __uid_t; 
# 135
typedef unsigned __gid_t; 
# 136
typedef unsigned long __ino_t; 
# 137
typedef unsigned long __ino64_t; 
# 138
typedef unsigned __mode_t; 
# 139
typedef unsigned long __nlink_t; 
# 140
typedef long __off_t; 
# 141
typedef long __off64_t; 
# 142
typedef int __pid_t; 
# 143
typedef struct { int __val[2]; } __fsid_t; 
# 144
typedef long __clock_t; 
# 145
typedef unsigned long __rlim_t; 
# 146
typedef unsigned long __rlim64_t; 
# 147
typedef unsigned __id_t; 
# 148
typedef long __time_t; 
# 149
typedef unsigned __useconds_t; 
# 150
typedef long __suseconds_t; 
# 152
typedef int __daddr_t; 
# 153
typedef int __key_t; 
# 156
typedef int __clockid_t; 
# 159
typedef void *__timer_t; 
# 162
typedef long __blksize_t; 
# 167
typedef long __blkcnt_t; 
# 168
typedef long __blkcnt64_t; 
# 171
typedef unsigned long __fsblkcnt_t; 
# 172
typedef unsigned long __fsblkcnt64_t; 
# 175
typedef unsigned long __fsfilcnt_t; 
# 176
typedef unsigned long __fsfilcnt64_t; 
# 179
typedef long __fsword_t; 
# 181
typedef long __ssize_t; 
# 184
typedef long __syscall_slong_t; 
# 186
typedef unsigned long __syscall_ulong_t; 
# 190
typedef __off64_t __loff_t; 
# 191
typedef char *__caddr_t; 
# 194
typedef long __intptr_t; 
# 197
typedef unsigned __socklen_t; 
# 202
typedef int __sig_atomic_t; 
# 8 "/usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h" 3
struct timeval { 
# 10
__time_t tv_sec; 
# 11
__suseconds_t tv_usec; 
# 12
}; 
# 26 "/usr/include/x86_64-linux-gnu/bits/timex.h" 3
struct timex { 
# 28
unsigned modes; 
# 29
__syscall_slong_t offset; 
# 30
__syscall_slong_t freq; 
# 31
__syscall_slong_t maxerror; 
# 32
__syscall_slong_t esterror; 
# 33
int status; 
# 34
__syscall_slong_t constant; 
# 35
__syscall_slong_t precision; 
# 36
__syscall_slong_t tolerance; 
# 37
timeval time; 
# 38
__syscall_slong_t tick; 
# 39
__syscall_slong_t ppsfreq; 
# 40
__syscall_slong_t jitter; 
# 41
int shift; 
# 42
__syscall_slong_t stabil; 
# 43
__syscall_slong_t jitcnt; 
# 44
__syscall_slong_t calcnt; 
# 45
__syscall_slong_t errcnt; 
# 46
__syscall_slong_t stbcnt; 
# 48
int tai; 
# 51
int:32; int:32; int:32; int:32; 
# 52
int:32; int:32; int:32; int:32; 
# 53
int:32; int:32; int:32; 
# 54
}; 
# 75 "/usr/include/x86_64-linux-gnu/bits/time.h" 3
extern "C" {
# 78
extern int clock_adjtime(__clockid_t __clock_id, timex * __utx) throw(); 
# 80
}
# 7 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h" 3
typedef __clock_t clock_t; 
# 7 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 3
typedef __time_t time_t; 
# 7 "/usr/include/x86_64-linux-gnu/bits/types/struct_tm.h" 3
struct tm { 
# 9
int tm_sec; 
# 10
int tm_min; 
# 11
int tm_hour; 
# 12
int tm_mday; 
# 13
int tm_mon; 
# 14
int tm_year; 
# 15
int tm_wday; 
# 16
int tm_yday; 
# 17
int tm_isdst; 
# 20
long tm_gmtoff; 
# 21
const char *tm_zone; 
# 26
}; 
# 9 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3
struct timespec { 
# 11
__time_t tv_sec; 
# 12
__syscall_slong_t tv_nsec; 
# 13
}; 
# 7 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h" 3
typedef __clockid_t clockid_t; 
# 7 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h" 3
typedef __timer_t timer_t; 
# 8 "/usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h" 3
struct itimerspec { 
# 10
timespec it_interval; 
# 11
timespec it_value; 
# 12
}; 
# 49 "/usr/include/time.h" 3
struct sigevent; 
# 54
typedef __pid_t pid_t; 
# 68 "/usr/include/time.h" 3
extern "C" {
# 72
extern clock_t clock() throw(); 
# 75
extern time_t time(time_t * __timer) throw(); 
# 78
extern double difftime(time_t __time1, time_t __time0) throw()
# 79
 __attribute((const)); 
# 82
extern time_t mktime(tm * __tp) throw(); 
# 88
extern size_t strftime(char *__restrict__ __s, size_t __maxsize, const char *__restrict__ __format, const tm *__restrict__ __tp) throw(); 
# 95
extern char *strptime(const char *__restrict__ __s, const char *__restrict__ __fmt, tm * __tp) throw(); 
# 104
extern size_t strftime_l(char *__restrict__ __s, size_t __maxsize, const char *__restrict__ __format, const tm *__restrict__ __tp, locale_t __loc) throw(); 
# 111
extern char *strptime_l(const char *__restrict__ __s, const char *__restrict__ __fmt, tm * __tp, locale_t __loc) throw(); 
# 119
extern tm *gmtime(const time_t * __timer) throw(); 
# 123
extern tm *localtime(const time_t * __timer) throw(); 
# 128
extern tm *gmtime_r(const time_t *__restrict__ __timer, tm *__restrict__ __tp) throw(); 
# 133
extern tm *localtime_r(const time_t *__restrict__ __timer, tm *__restrict__ __tp) throw(); 
# 139
extern char *asctime(const tm * __tp) throw(); 
# 142
extern char *ctime(const time_t * __timer) throw(); 
# 149
extern char *asctime_r(const tm *__restrict__ __tp, char *__restrict__ __buf) throw(); 
# 153
extern char *ctime_r(const time_t *__restrict__ __timer, char *__restrict__ __buf) throw(); 
# 159
extern char *__tzname[2]; 
# 160
extern int __daylight; 
# 161
extern long __timezone; 
# 166
extern char *tzname[2]; 
# 170
extern void tzset() throw(); 
# 174
extern int daylight; 
# 175
extern long timezone; 
# 181
extern int stime(const time_t * __when) throw(); 
# 196 "/usr/include/time.h" 3
extern time_t timegm(tm * __tp) throw(); 
# 199
extern time_t timelocal(tm * __tp) throw(); 
# 202
extern int dysize(int __year) throw() __attribute((const)); 
# 211 "/usr/include/time.h" 3
extern int nanosleep(const timespec * __requested_time, timespec * __remaining); 
# 216
extern int clock_getres(clockid_t __clock_id, timespec * __res) throw(); 
# 219
extern int clock_gettime(clockid_t __clock_id, timespec * __tp) throw(); 
# 222
extern int clock_settime(clockid_t __clock_id, const timespec * __tp) throw(); 
# 230
extern int clock_nanosleep(clockid_t __clock_id, int __flags, const timespec * __req, timespec * __rem); 
# 235
extern int clock_getcpuclockid(pid_t __pid, clockid_t * __clock_id) throw(); 
# 240
extern int timer_create(clockid_t __clock_id, sigevent *__restrict__ __evp, timer_t *__restrict__ __timerid) throw(); 
# 245
extern int timer_delete(timer_t __timerid) throw(); 
# 248
extern int timer_settime(timer_t __timerid, int __flags, const itimerspec *__restrict__ __value, itimerspec *__restrict__ __ovalue) throw(); 
# 253
extern int timer_gettime(timer_t __timerid, itimerspec * __value) throw(); 
# 257
extern int timer_getoverrun(timer_t __timerid) throw(); 
# 263
extern int timespec_get(timespec * __ts, int __base) throw()
# 264
 __attribute((__nonnull__(1))); 
# 280 "/usr/include/time.h" 3
extern int getdate_err; 
# 289 "/usr/include/time.h" 3
extern tm *getdate(const char * __string); 
# 303 "/usr/include/time.h" 3
extern int getdate_r(const char *__restrict__ __string, tm *__restrict__ __resbufp); 
# 307
}
# 88 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/common_functions.h"
extern "C" {
# 91
extern clock_t clock() throw(); 
# 96 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/common_functions.h"
extern void *memset(void *, int, size_t) throw(); 
# 97 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/common_functions.h"
extern void *memcpy(void *, const void *, size_t) throw(); 
# 99 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/common_functions.h"
}
# 115 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern "C" {
# 213 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int abs(int a) throw(); 
# 221 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long labs(long a) throw(); 
# 229 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long long llabs(long long a) throw(); 
# 279 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double fabs(double x) throw(); 
# 320 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float fabsf(float x) throw(); 
# 330 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern inline int min(int a, int b); 
# 337
extern inline unsigned umin(unsigned a, unsigned b); 
# 344
extern inline long long llmin(long long a, long long b); 
# 351
extern inline unsigned long long ullmin(unsigned long long a, unsigned long long b); 
# 372 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float fminf(float x, float y) throw(); 
# 392 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double fmin(double x, double y) throw(); 
# 405 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern inline int max(int a, int b); 
# 413
extern inline unsigned umax(unsigned a, unsigned b); 
# 420
extern inline long long llmax(long long a, long long b); 
# 427
extern inline unsigned long long ullmax(unsigned long long a, unsigned long long b); 
# 448 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float fmaxf(float x, float y) throw(); 
# 468 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double fmax(double, double) throw(); 
# 512 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double sin(double x) throw(); 
# 545 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double cos(double x) throw(); 
# 564 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern void sincos(double x, double * sptr, double * cptr) throw(); 
# 580 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern void sincosf(float x, float * sptr, float * cptr) throw(); 
# 625 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double tan(double x) throw(); 
# 694 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double sqrt(double x) throw(); 
# 766 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double rsqrt(double x); 
# 836 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float rsqrtf(float x); 
# 892 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double log2(double x) throw(); 
# 917 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double exp2(double x) throw(); 
# 942 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float exp2f(float x) throw(); 
# 969 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double exp10(double x) throw(); 
# 992 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float exp10f(float x) throw(); 
# 1038 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double expm1(double x) throw(); 
# 1083 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float expm1f(float x) throw(); 
# 1138 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float log2f(float x) throw(); 
# 1192 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double log10(double x) throw(); 
# 1263 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double log(double x) throw(); 
# 1366 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double log1p(double x) throw(); 
# 1472 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float log1pf(float x) throw(); 
# 1536 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double floor(double x) throw(); 
# 1575 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double exp(double x) throw(); 
# 1606 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double cosh(double x) throw(); 
# 1656 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double sinh(double x) throw(); 
# 1686 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double tanh(double x) throw(); 
# 1721 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double acosh(double x) throw(); 
# 1759 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float acoshf(float x) throw(); 
# 1775 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double asinh(double x) throw(); 
# 1791 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float asinhf(float x) throw(); 
# 1845 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double atanh(double x) throw(); 
# 1899 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float atanhf(float x) throw(); 
# 1958 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double ldexp(double x, int exp) throw(); 
# 2014 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float ldexpf(float x, int exp) throw(); 
# 2066 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double logb(double x) throw(); 
# 2121 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float logbf(float x) throw(); 
# 2152 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int ilogb(double x) throw(); 
# 2183 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int ilogbf(float x) throw(); 
# 2259 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double scalbn(double x, int n) throw(); 
# 2335 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float scalbnf(float x, int n) throw(); 
# 2411 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double scalbln(double x, long n) throw(); 
# 2487 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float scalblnf(float x, long n) throw(); 
# 2565 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double frexp(double x, int * nptr) throw(); 
# 2640 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float frexpf(float x, int * nptr) throw(); 
# 2654 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double round(double x) throw(); 
# 2671 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float roundf(float x) throw(); 
# 2689 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long lround(double x) throw(); 
# 2707 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long lroundf(float x) throw(); 
# 2725 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long long llround(double x) throw(); 
# 2743 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long long llroundf(float x) throw(); 
# 2795 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float rintf(float x) throw(); 
# 2812 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long lrint(double x) throw(); 
# 2829 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long lrintf(float x) throw(); 
# 2846 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long long llrint(double x) throw(); 
# 2863 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern long long llrintf(float x) throw(); 
# 2916 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double nearbyint(double x) throw(); 
# 2969 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float nearbyintf(float x) throw(); 
# 3031 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double ceil(double x) throw(); 
# 3043 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double trunc(double x) throw(); 
# 3058 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float truncf(float x) throw(); 
# 3084 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double fdim(double x, double y) throw(); 
# 3110 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float fdimf(float x, float y) throw(); 
# 3146 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double atan2(double y, double x) throw(); 
# 3177 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double atan(double x) throw(); 
# 3200 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double acos(double x) throw(); 
# 3232 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double asin(double x) throw(); 
# 3278 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double hypot(double x, double y) throw(); 
# 3376 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float hypotf(float x, float y) throw(); 
# 4108 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double cbrt(double x) throw(); 
# 4194 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float cbrtf(float x) throw(); 
# 4249 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double rcbrt(double x); 
# 4299 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float rcbrtf(float x); 
# 4359 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double sinpi(double x); 
# 4419 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float sinpif(float x); 
# 4471 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double cospi(double x); 
# 4523 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float cospif(float x); 
# 4553 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern void sincospi(double x, double * sptr, double * cptr); 
# 4583 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern void sincospif(float x, float * sptr, float * cptr); 
# 4895 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double pow(double x, double y) throw(); 
# 4951 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double modf(double x, double * iptr) throw(); 
# 5010 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double fmod(double x, double y) throw(); 
# 5096 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double remainder(double x, double y) throw(); 
# 5186 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float remainderf(float x, float y) throw(); 
# 5240 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double remquo(double x, double y, int * quo) throw(); 
# 5294 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float remquof(float x, float y, int * quo) throw(); 
# 5335 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double j0(double x) throw(); 
# 5377 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float j0f(float x) throw(); 
# 5446 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double j1(double x) throw(); 
# 5515 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float j1f(float x) throw(); 
# 5558 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double jn(int n, double x) throw(); 
# 5601 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float jnf(int n, float x) throw(); 
# 5653 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double y0(double x) throw(); 
# 5705 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float y0f(float x) throw(); 
# 5757 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double y1(double x) throw(); 
# 5809 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float y1f(float x) throw(); 
# 5862 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double yn(int n, double x) throw(); 
# 5915 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float ynf(int n, float x) throw(); 
# 6104 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double erf(double x) throw(); 
# 6186 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float erff(float x) throw(); 
# 6250 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double erfinv(double y); 
# 6307 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float erfinvf(float y); 
# 6346 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double erfc(double x) throw(); 
# 6384 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float erfcf(float x) throw(); 
# 6512 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double lgamma(double x) throw(); 
# 6575 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double erfcinv(double y); 
# 6631 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float erfcinvf(float y); 
# 6689 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double normcdfinv(double y); 
# 6747 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float normcdfinvf(float y); 
# 6790 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double normcdf(double y); 
# 6833 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float normcdff(float y); 
# 6908 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double erfcx(double x); 
# 6983 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float erfcxf(float x); 
# 7117 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float lgammaf(float x) throw(); 
# 7226 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double tgamma(double x) throw(); 
# 7335 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float tgammaf(float x) throw(); 
# 7348 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double copysign(double x, double y) throw(); 
# 7361 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float copysignf(float x, float y) throw(); 
# 7380 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double nextafter(double x, double y) throw(); 
# 7399 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float nextafterf(float x, float y) throw(); 
# 7415 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double nan(const char * tagp) throw(); 
# 7431 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float nanf(const char * tagp) throw(); 
# 7438 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __isinff(float) throw(); 
# 7439 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __isnanf(float) throw(); 
# 7449 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __finite(double) throw(); 
# 7450 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __finitef(float) throw(); 
# 7451 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __signbit(double) throw(); 
# 7452 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __isnan(double) throw(); 
# 7453 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __isinf(double) throw(); 
# 7456 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __signbitf(float) throw(); 
# 7615 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern double fma(double x, double y, double z) throw(); 
# 7773 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float fmaf(float x, float y, float z) throw(); 
# 7784 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __signbitl(long double) throw(); 
# 7790 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __finitel(long double) throw(); 
# 7791 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __isinfl(long double) throw(); 
# 7792 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern int __isnanl(long double) throw(); 
# 7842 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float acosf(float x) throw(); 
# 7882 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float asinf(float x) throw(); 
# 7922 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float atanf(float x) throw(); 
# 7955 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float atan2f(float y, float x) throw(); 
# 7979 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float cosf(float x) throw(); 
# 8021 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float sinf(float x) throw(); 
# 8063 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float tanf(float x) throw(); 
# 8094 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float coshf(float x) throw(); 
# 8144 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float sinhf(float x) throw(); 
# 8174 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float tanhf(float x) throw(); 
# 8225 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float logf(float x) throw(); 
# 8275 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float expf(float x) throw(); 
# 8326 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float log10f(float x) throw(); 
# 8381 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float modff(float x, float * iptr) throw(); 
# 8689 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float powf(float x, float y) throw(); 
# 8758 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float sqrtf(float x) throw(); 
# 8817 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float ceilf(float x) throw(); 
# 8878 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float floorf(float x) throw(); 
# 8936 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern float fmodf(float x, float y) throw(); 
# 8951 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
}
# 229 "/usr/include/x86_64-linux-gnu/c++/7/bits/c++config.h" 3
namespace std { 
# 231
typedef unsigned long size_t; 
# 232
typedef long ptrdiff_t; 
# 235
typedef __decltype((nullptr)) nullptr_t; 
# 237
}
# 251 "/usr/include/x86_64-linux-gnu/c++/7/bits/c++config.h" 3
namespace std { 
# 253
inline namespace __cxx11 __attribute((__abi_tag__("cxx11"))) { }
# 254
}
# 255
namespace __gnu_cxx { 
# 257
inline namespace __cxx11 __attribute((__abi_tag__("cxx11"))) { }
# 258
}
# 67 "/usr/include/c++/7/bits/cpp_type_traits.h" 3
extern "C++" {
# 69
namespace std __attribute((__visibility__("default"))) { 
# 73
struct __true_type { }; 
# 74
struct __false_type { }; 
# 76
template< bool > 
# 77
struct __truth_type { 
# 78
typedef __false_type __type; }; 
# 81
template<> struct __truth_type< true>  { 
# 82
typedef __true_type __type; }; 
# 86
template< class _Sp, class _Tp> 
# 87
struct __traitor { 
# 89
enum { __value = ((bool)_Sp::__value) || ((bool)_Tp::__value)}; 
# 90
typedef typename __truth_type< __value> ::__type __type; 
# 91
}; 
# 94
template< class , class > 
# 95
struct __are_same { 
# 97
enum { __value}; 
# 98
typedef __false_type __type; 
# 99
}; 
# 101
template< class _Tp> 
# 102
struct __are_same< _Tp, _Tp>  { 
# 104
enum { __value = 1}; 
# 105
typedef __true_type __type; 
# 106
}; 
# 109
template< class _Tp> 
# 110
struct __is_void { 
# 112
enum { __value}; 
# 113
typedef __false_type __type; 
# 114
}; 
# 117
template<> struct __is_void< void>  { 
# 119
enum { __value = 1}; 
# 120
typedef __true_type __type; 
# 121
}; 
# 126
template< class _Tp> 
# 127
struct __is_integer { 
# 129
enum { __value}; 
# 130
typedef __false_type __type; 
# 131
}; 
# 138
template<> struct __is_integer< bool>  { 
# 140
enum { __value = 1}; 
# 141
typedef __true_type __type; 
# 142
}; 
# 145
template<> struct __is_integer< char>  { 
# 147
enum { __value = 1}; 
# 148
typedef __true_type __type; 
# 149
}; 
# 152
template<> struct __is_integer< signed char>  { 
# 154
enum { __value = 1}; 
# 155
typedef __true_type __type; 
# 156
}; 
# 159
template<> struct __is_integer< unsigned char>  { 
# 161
enum { __value = 1}; 
# 162
typedef __true_type __type; 
# 163
}; 
# 167
template<> struct __is_integer< wchar_t>  { 
# 169
enum { __value = 1}; 
# 170
typedef __true_type __type; 
# 171
}; 
# 176
template<> struct __is_integer< char16_t>  { 
# 178
enum { __value = 1}; 
# 179
typedef __true_type __type; 
# 180
}; 
# 183
template<> struct __is_integer< char32_t>  { 
# 185
enum { __value = 1}; 
# 186
typedef __true_type __type; 
# 187
}; 
# 191
template<> struct __is_integer< short>  { 
# 193
enum { __value = 1}; 
# 194
typedef __true_type __type; 
# 195
}; 
# 198
template<> struct __is_integer< unsigned short>  { 
# 200
enum { __value = 1}; 
# 201
typedef __true_type __type; 
# 202
}; 
# 205
template<> struct __is_integer< int>  { 
# 207
enum { __value = 1}; 
# 208
typedef __true_type __type; 
# 209
}; 
# 212
template<> struct __is_integer< unsigned>  { 
# 214
enum { __value = 1}; 
# 215
typedef __true_type __type; 
# 216
}; 
# 219
template<> struct __is_integer< long>  { 
# 221
enum { __value = 1}; 
# 222
typedef __true_type __type; 
# 223
}; 
# 226
template<> struct __is_integer< unsigned long>  { 
# 228
enum { __value = 1}; 
# 229
typedef __true_type __type; 
# 230
}; 
# 233
template<> struct __is_integer< long long>  { 
# 235
enum { __value = 1}; 
# 236
typedef __true_type __type; 
# 237
}; 
# 240
template<> struct __is_integer< unsigned long long>  { 
# 242
enum { __value = 1}; 
# 243
typedef __true_type __type; 
# 244
}; 
# 261 "/usr/include/c++/7/bits/cpp_type_traits.h" 3
template<> struct __is_integer< __int128_t>  { enum { __value = 1}; typedef __true_type __type; }; template<> struct __is_integer< __uint128_t>  { enum { __value = 1}; typedef __true_type __type; }; 
# 278 "/usr/include/c++/7/bits/cpp_type_traits.h" 3
template< class _Tp> 
# 279
struct __is_floating { 
# 281
enum { __value}; 
# 282
typedef __false_type __type; 
# 283
}; 
# 287
template<> struct __is_floating< float>  { 
# 289
enum { __value = 1}; 
# 290
typedef __true_type __type; 
# 291
}; 
# 294
template<> struct __is_floating< double>  { 
# 296
enum { __value = 1}; 
# 297
typedef __true_type __type; 
# 298
}; 
# 301
template<> struct __is_floating< long double>  { 
# 303
enum { __value = 1}; 
# 304
typedef __true_type __type; 
# 305
}; 
# 310
template< class _Tp> 
# 311
struct __is_pointer { 
# 313
enum { __value}; 
# 314
typedef __false_type __type; 
# 315
}; 
# 317
template< class _Tp> 
# 318
struct __is_pointer< _Tp *>  { 
# 320
enum { __value = 1}; 
# 321
typedef __true_type __type; 
# 322
}; 
# 327
template< class _Tp> 
# 328
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> >  { 
# 330
}; 
# 335
template< class _Tp> 
# 336
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> >  { 
# 338
}; 
# 343
template< class _Tp> 
# 344
struct __is_char { 
# 346
enum { __value}; 
# 347
typedef __false_type __type; 
# 348
}; 
# 351
template<> struct __is_char< char>  { 
# 353
enum { __value = 1}; 
# 354
typedef __true_type __type; 
# 355
}; 
# 359
template<> struct __is_char< wchar_t>  { 
# 361
enum { __value = 1}; 
# 362
typedef __true_type __type; 
# 363
}; 
# 366
template< class _Tp> 
# 367
struct __is_byte { 
# 369
enum { __value}; 
# 370
typedef __false_type __type; 
# 371
}; 
# 374
template<> struct __is_byte< char>  { 
# 376
enum { __value = 1}; 
# 377
typedef __true_type __type; 
# 378
}; 
# 381
template<> struct __is_byte< signed char>  { 
# 383
enum { __value = 1}; 
# 384
typedef __true_type __type; 
# 385
}; 
# 388
template<> struct __is_byte< unsigned char>  { 
# 390
enum { __value = 1}; 
# 391
typedef __true_type __type; 
# 392
}; 
# 397
template< class _Tp> 
# 398
struct __is_move_iterator { 
# 400
enum { __value}; 
# 401
typedef __false_type __type; 
# 402
}; 
# 406
template< class _Iterator> inline _Iterator 
# 408
__miter_base(_Iterator __it) 
# 409
{ return __it; } 
# 412
}
# 413
}
# 37 "/usr/include/c++/7/ext/type_traits.h" 3
extern "C++" {
# 39
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 44
template< bool , class > 
# 45
struct __enable_if { 
# 46
}; 
# 48
template< class _Tp> 
# 49
struct __enable_if< true, _Tp>  { 
# 50
typedef _Tp __type; }; 
# 54
template< bool _Cond, class _Iftrue, class _Iffalse> 
# 55
struct __conditional_type { 
# 56
typedef _Iftrue __type; }; 
# 58
template< class _Iftrue, class _Iffalse> 
# 59
struct __conditional_type< false, _Iftrue, _Iffalse>  { 
# 60
typedef _Iffalse __type; }; 
# 64
template< class _Tp> 
# 65
struct __add_unsigned { 
# 68
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp>  __if_type; 
# 71
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type; 
# 72
}; 
# 75
template<> struct __add_unsigned< char>  { 
# 76
typedef unsigned char __type; }; 
# 79
template<> struct __add_unsigned< signed char>  { 
# 80
typedef unsigned char __type; }; 
# 83
template<> struct __add_unsigned< short>  { 
# 84
typedef unsigned short __type; }; 
# 87
template<> struct __add_unsigned< int>  { 
# 88
typedef unsigned __type; }; 
# 91
template<> struct __add_unsigned< long>  { 
# 92
typedef unsigned long __type; }; 
# 95
template<> struct __add_unsigned< long long>  { 
# 96
typedef unsigned long long __type; }; 
# 100
template<> struct __add_unsigned< bool> ; 
# 103
template<> struct __add_unsigned< wchar_t> ; 
# 107
template< class _Tp> 
# 108
struct __remove_unsigned { 
# 111
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp>  __if_type; 
# 114
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type; 
# 115
}; 
# 118
template<> struct __remove_unsigned< char>  { 
# 119
typedef signed char __type; }; 
# 122
template<> struct __remove_unsigned< unsigned char>  { 
# 123
typedef signed char __type; }; 
# 126
template<> struct __remove_unsigned< unsigned short>  { 
# 127
typedef short __type; }; 
# 130
template<> struct __remove_unsigned< unsigned>  { 
# 131
typedef int __type; }; 
# 134
template<> struct __remove_unsigned< unsigned long>  { 
# 135
typedef long __type; }; 
# 138
template<> struct __remove_unsigned< unsigned long long>  { 
# 139
typedef long long __type; }; 
# 143
template<> struct __remove_unsigned< bool> ; 
# 146
template<> struct __remove_unsigned< wchar_t> ; 
# 150
template< class _Type> inline bool 
# 152
__is_null_pointer(_Type *__ptr) 
# 153
{ return __ptr == 0; } 
# 155
template< class _Type> inline bool 
# 157
__is_null_pointer(_Type) 
# 158
{ return false; } 
# 162
inline bool __is_null_pointer(std::nullptr_t) 
# 163
{ return true; } 
# 167
template< class _Tp, bool  = std::__is_integer< _Tp> ::__value> 
# 168
struct __promote { 
# 169
typedef double __type; }; 
# 174
template< class _Tp> 
# 175
struct __promote< _Tp, false>  { 
# 176
}; 
# 179
template<> struct __promote< long double>  { 
# 180
typedef long double __type; }; 
# 183
template<> struct __promote< double>  { 
# 184
typedef double __type; }; 
# 187
template<> struct __promote< float>  { 
# 188
typedef float __type; }; 
# 190
template< class _Tp, class _Up, class 
# 191
_Tp2 = typename __promote< _Tp> ::__type, class 
# 192
_Up2 = typename __promote< _Up> ::__type> 
# 193
struct __promote_2 { 
# 195
typedef __typeof__(_Tp2() + _Up2()) __type; 
# 196
}; 
# 198
template< class _Tp, class _Up, class _Vp, class 
# 199
_Tp2 = typename __promote< _Tp> ::__type, class 
# 200
_Up2 = typename __promote< _Up> ::__type, class 
# 201
_Vp2 = typename __promote< _Vp> ::__type> 
# 202
struct __promote_3 { 
# 204
typedef __typeof__((_Tp2() + _Up2()) + _Vp2()) __type; 
# 205
}; 
# 207
template< class _Tp, class _Up, class _Vp, class _Wp, class 
# 208
_Tp2 = typename __promote< _Tp> ::__type, class 
# 209
_Up2 = typename __promote< _Up> ::__type, class 
# 210
_Vp2 = typename __promote< _Vp> ::__type, class 
# 211
_Wp2 = typename __promote< _Wp> ::__type> 
# 212
struct __promote_4 { 
# 214
typedef __typeof__(((_Tp2() + _Up2()) + _Vp2()) + _Wp2()) __type; 
# 215
}; 
# 218
}
# 219
}
# 34 "/usr/include/math.h" 3
extern "C" {
# 207 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3
typedef float _Float32; 
# 244 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3
typedef double _Float64; 
# 261 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3
typedef double _Float32x; 
# 278 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3
typedef long double _Float64x; 
# 149 "/usr/include/math.h" 3
typedef float float_t; 
# 150
typedef double double_t; 
# 238 "/usr/include/math.h" 3
enum { 
# 239
FP_INT_UPWARD, 
# 242
FP_INT_DOWNWARD, 
# 245
FP_INT_TOWARDZERO, 
# 248
FP_INT_TONEARESTFROMZERO, 
# 251
FP_INT_TONEAREST
# 254
}; 
# 21 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 3
extern int __fpclassify(double __value) throw()
# 22
 __attribute((const)); 
# 25
extern int __signbit(double __value) throw()
# 26
 __attribute((const)); 
# 30
extern int __isinf(double __value) throw() __attribute((const)); 
# 33
extern int __finite(double __value) throw() __attribute((const)); 
# 36
extern int __isnan(double __value) throw() __attribute((const)); 
# 39
extern int __iseqsig(double __x, double __y) throw(); 
# 42
extern int __issignaling(double __value) throw()
# 43
 __attribute((const)); 
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern double acos(double __x) throw(); extern double __acos(double __x) throw(); 
# 55
extern double asin(double __x) throw(); extern double __asin(double __x) throw(); 
# 57
extern double atan(double __x) throw(); extern double __atan(double __x) throw(); 
# 59
extern double atan2(double __y, double __x) throw(); extern double __atan2(double __y, double __x) throw(); 
# 62
extern double cos(double __x) throw(); extern double __cos(double __x) throw(); 
# 64
extern double sin(double __x) throw(); extern double __sin(double __x) throw(); 
# 66
extern double tan(double __x) throw(); extern double __tan(double __x) throw(); 
# 71
extern double cosh(double __x) throw(); extern double __cosh(double __x) throw(); 
# 73
extern double sinh(double __x) throw(); extern double __sinh(double __x) throw(); 
# 75
extern double tanh(double __x) throw(); extern double __tanh(double __x) throw(); 
# 79
extern void sincos(double __x, double * __sinx, double * __cosx) throw(); extern void __sincos(double __x, double * __sinx, double * __cosx) throw(); 
# 85
extern double acosh(double __x) throw(); extern double __acosh(double __x) throw(); 
# 87
extern double asinh(double __x) throw(); extern double __asinh(double __x) throw(); 
# 89
extern double atanh(double __x) throw(); extern double __atanh(double __x) throw(); 
# 95
extern double exp(double __x) throw(); extern double __exp(double __x) throw(); 
# 98
extern double frexp(double __x, int * __exponent) throw(); extern double __frexp(double __x, int * __exponent) throw(); 
# 101
extern double ldexp(double __x, int __exponent) throw(); extern double __ldexp(double __x, int __exponent) throw(); 
# 104
extern double log(double __x) throw(); extern double __log(double __x) throw(); 
# 107
extern double log10(double __x) throw(); extern double __log10(double __x) throw(); 
# 110
extern double modf(double __x, double * __iptr) throw(); extern double __modf(double __x, double * __iptr) throw() __attribute((__nonnull__(2))); 
# 114
extern double exp10(double __x) throw(); extern double __exp10(double __x) throw(); 
# 119
extern double expm1(double __x) throw(); extern double __expm1(double __x) throw(); 
# 122
extern double log1p(double __x) throw(); extern double __log1p(double __x) throw(); 
# 125
extern double logb(double __x) throw(); extern double __logb(double __x) throw(); 
# 130
extern double exp2(double __x) throw(); extern double __exp2(double __x) throw(); 
# 133
extern double log2(double __x) throw(); extern double __log2(double __x) throw(); 
# 140
extern double pow(double __x, double __y) throw(); extern double __pow(double __x, double __y) throw(); 
# 143
extern double sqrt(double __x) throw(); extern double __sqrt(double __x) throw(); 
# 147
extern double hypot(double __x, double __y) throw(); extern double __hypot(double __x, double __y) throw(); 
# 152
extern double cbrt(double __x) throw(); extern double __cbrt(double __x) throw(); 
# 159
extern double ceil(double __x) throw() __attribute((const)); extern double __ceil(double __x) throw() __attribute((const)); 
# 162
extern double fabs(double __x) throw() __attribute((const)); extern double __fabs(double __x) throw() __attribute((const)); 
# 165
extern double floor(double __x) throw() __attribute((const)); extern double __floor(double __x) throw() __attribute((const)); 
# 168
extern double fmod(double __x, double __y) throw(); extern double __fmod(double __x, double __y) throw(); 
# 182 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern int finite(double __value) throw() __attribute((const)); 
# 185
extern double drem(double __x, double __y) throw(); extern double __drem(double __x, double __y) throw(); 
# 189
extern double significand(double __x) throw(); extern double __significand(double __x) throw(); 
# 196
extern double copysign(double __x, double __y) throw() __attribute((const)); extern double __copysign(double __x, double __y) throw() __attribute((const)); 
# 201
extern double nan(const char * __tagb) throw() __attribute((const)); extern double __nan(const char * __tagb) throw() __attribute((const)); 
# 217 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern double j0(double) throw(); extern double __j0(double) throw(); 
# 218
extern double j1(double) throw(); extern double __j1(double) throw(); 
# 219
extern double jn(int, double) throw(); extern double __jn(int, double) throw(); 
# 220
extern double y0(double) throw(); extern double __y0(double) throw(); 
# 221
extern double y1(double) throw(); extern double __y1(double) throw(); 
# 222
extern double yn(int, double) throw(); extern double __yn(int, double) throw(); 
# 228
extern double erf(double) throw(); extern double __erf(double) throw(); 
# 229
extern double erfc(double) throw(); extern double __erfc(double) throw(); 
# 230
extern double lgamma(double) throw(); extern double __lgamma(double) throw(); 
# 235
extern double tgamma(double) throw(); extern double __tgamma(double) throw(); 
# 241
extern double gamma(double) throw(); extern double __gamma(double) throw(); 
# 249
extern double lgamma_r(double, int * __signgamp) throw(); extern double __lgamma_r(double, int * __signgamp) throw(); 
# 256
extern double rint(double __x) throw(); extern double __rint(double __x) throw(); 
# 259
extern double nextafter(double __x, double __y) throw(); extern double __nextafter(double __x, double __y) throw(); 
# 261
extern double nexttoward(double __x, long double __y) throw(); extern double __nexttoward(double __x, long double __y) throw(); 
# 266
extern double nextdown(double __x) throw(); extern double __nextdown(double __x) throw(); 
# 268
extern double nextup(double __x) throw(); extern double __nextup(double __x) throw(); 
# 272
extern double remainder(double __x, double __y) throw(); extern double __remainder(double __x, double __y) throw(); 
# 276
extern double scalbn(double __x, int __n) throw(); extern double __scalbn(double __x, int __n) throw(); 
# 280
extern int ilogb(double __x) throw(); extern int __ilogb(double __x) throw(); 
# 285
extern long llogb(double __x) throw(); extern long __llogb(double __x) throw(); 
# 290
extern double scalbln(double __x, long __n) throw(); extern double __scalbln(double __x, long __n) throw(); 
# 294
extern double nearbyint(double __x) throw(); extern double __nearbyint(double __x) throw(); 
# 298
extern double round(double __x) throw() __attribute((const)); extern double __round(double __x) throw() __attribute((const)); 
# 302
extern double trunc(double __x) throw() __attribute((const)); extern double __trunc(double __x) throw() __attribute((const)); 
# 307
extern double remquo(double __x, double __y, int * __quo) throw(); extern double __remquo(double __x, double __y, int * __quo) throw(); 
# 314
extern long lrint(double __x) throw(); extern long __lrint(double __x) throw(); 
# 316
__extension__ extern long long llrint(double __x) throw(); extern long long __llrint(double __x) throw(); 
# 320
extern long lround(double __x) throw(); extern long __lround(double __x) throw(); 
# 322
__extension__ extern long long llround(double __x) throw(); extern long long __llround(double __x) throw(); 
# 326
extern double fdim(double __x, double __y) throw(); extern double __fdim(double __x, double __y) throw(); 
# 329
extern double fmax(double __x, double __y) throw() __attribute((const)); extern double __fmax(double __x, double __y) throw() __attribute((const)); 
# 332
extern double fmin(double __x, double __y) throw() __attribute((const)); extern double __fmin(double __x, double __y) throw() __attribute((const)); 
# 335
extern double fma(double __x, double __y, double __z) throw(); extern double __fma(double __x, double __y, double __z) throw(); 
# 340
extern double roundeven(double __x) throw() __attribute((const)); extern double __roundeven(double __x) throw() __attribute((const)); 
# 344
extern __intmax_t fromfp(double __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfp(double __x, int __round, unsigned __width) throw(); 
# 349
extern __uintmax_t ufromfp(double __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfp(double __x, int __round, unsigned __width) throw(); 
# 355
extern __intmax_t fromfpx(double __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpx(double __x, int __round, unsigned __width) throw(); 
# 361
extern __uintmax_t ufromfpx(double __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpx(double __x, int __round, unsigned __width) throw(); 
# 365
extern double fmaxmag(double __x, double __y) throw() __attribute((const)); extern double __fmaxmag(double __x, double __y) throw() __attribute((const)); 
# 368
extern double fminmag(double __x, double __y) throw() __attribute((const)); extern double __fminmag(double __x, double __y) throw() __attribute((const)); 
# 371
extern int totalorder(double __x, double __y) throw()
# 372
 __attribute((const)); 
# 375
extern int totalordermag(double __x, double __y) throw()
# 376
 __attribute((const)); 
# 379
extern int canonicalize(double * __cx, const double * __x) throw(); 
# 382
extern double getpayload(const double * __x) throw(); extern double __getpayload(const double * __x) throw(); 
# 385
extern int setpayload(double * __x, double __payload) throw(); 
# 388
extern int setpayloadsig(double * __x, double __payload) throw(); 
# 396
extern double scalb(double __x, double __n) throw(); extern double __scalb(double __x, double __n) throw(); 
# 21 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 3
extern int __fpclassifyf(float __value) throw()
# 22
 __attribute((const)); 
# 25
extern int __signbitf(float __value) throw()
# 26
 __attribute((const)); 
# 30
extern int __isinff(float __value) throw() __attribute((const)); 
# 33
extern int __finitef(float __value) throw() __attribute((const)); 
# 36
extern int __isnanf(float __value) throw() __attribute((const)); 
# 39
extern int __iseqsigf(float __x, float __y) throw(); 
# 42
extern int __issignalingf(float __value) throw()
# 43
 __attribute((const)); 
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern float acosf(float __x) throw(); extern float __acosf(float __x) throw(); 
# 55
extern float asinf(float __x) throw(); extern float __asinf(float __x) throw(); 
# 57
extern float atanf(float __x) throw(); extern float __atanf(float __x) throw(); 
# 59
extern float atan2f(float __y, float __x) throw(); extern float __atan2f(float __y, float __x) throw(); 
# 62
extern float cosf(float __x) throw(); 
# 64
extern float sinf(float __x) throw(); 
# 66
extern float tanf(float __x) throw(); 
# 71
extern float coshf(float __x) throw(); extern float __coshf(float __x) throw(); 
# 73
extern float sinhf(float __x) throw(); extern float __sinhf(float __x) throw(); 
# 75
extern float tanhf(float __x) throw(); extern float __tanhf(float __x) throw(); 
# 79
extern void sincosf(float __x, float * __sinx, float * __cosx) throw(); 
# 85
extern float acoshf(float __x) throw(); extern float __acoshf(float __x) throw(); 
# 87
extern float asinhf(float __x) throw(); extern float __asinhf(float __x) throw(); 
# 89
extern float atanhf(float __x) throw(); extern float __atanhf(float __x) throw(); 
# 95
extern float expf(float __x) throw(); 
# 98
extern float frexpf(float __x, int * __exponent) throw(); extern float __frexpf(float __x, int * __exponent) throw(); 
# 101
extern float ldexpf(float __x, int __exponent) throw(); extern float __ldexpf(float __x, int __exponent) throw(); 
# 104
extern float logf(float __x) throw(); 
# 107
extern float log10f(float __x) throw(); 
# 110
extern float modff(float __x, float * __iptr) throw(); extern float __modff(float __x, float * __iptr) throw() __attribute((__nonnull__(2))); 
# 114
extern float exp10f(float __x) throw(); 
# 119
extern float expm1f(float __x) throw(); extern float __expm1f(float __x) throw(); 
# 122
extern float log1pf(float __x) throw(); extern float __log1pf(float __x) throw(); 
# 125
extern float logbf(float __x) throw(); extern float __logbf(float __x) throw(); 
# 130
extern float exp2f(float __x) throw(); extern float __exp2f(float __x) throw(); 
# 133
extern float log2f(float __x) throw(); 
# 140
extern float powf(float __x, float __y) throw(); 
# 143
extern float sqrtf(float __x) throw(); extern float __sqrtf(float __x) throw(); 
# 147
extern float hypotf(float __x, float __y) throw(); extern float __hypotf(float __x, float __y) throw(); 
# 152
extern float cbrtf(float __x) throw(); extern float __cbrtf(float __x) throw(); 
# 159
extern float ceilf(float __x) throw() __attribute((const)); extern float __ceilf(float __x) throw() __attribute((const)); 
# 162
extern float fabsf(float __x) throw() __attribute((const)); extern float __fabsf(float __x) throw() __attribute((const)); 
# 165
extern float floorf(float __x) throw() __attribute((const)); extern float __floorf(float __x) throw() __attribute((const)); 
# 168
extern float fmodf(float __x, float __y) throw(); extern float __fmodf(float __x, float __y) throw(); 
# 177 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern int isinff(float __value) throw() __attribute((const)); 
# 182
extern int finitef(float __value) throw() __attribute((const)); 
# 185
extern float dremf(float __x, float __y) throw(); extern float __dremf(float __x, float __y) throw(); 
# 189
extern float significandf(float __x) throw(); extern float __significandf(float __x) throw(); 
# 196
extern float copysignf(float __x, float __y) throw() __attribute((const)); extern float __copysignf(float __x, float __y) throw() __attribute((const)); 
# 201
extern float nanf(const char * __tagb) throw() __attribute((const)); extern float __nanf(const char * __tagb) throw() __attribute((const)); 
# 211 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern int isnanf(float __value) throw() __attribute((const)); 
# 217
extern float j0f(float) throw(); extern float __j0f(float) throw(); 
# 218
extern float j1f(float) throw(); extern float __j1f(float) throw(); 
# 219
extern float jnf(int, float) throw(); extern float __jnf(int, float) throw(); 
# 220
extern float y0f(float) throw(); extern float __y0f(float) throw(); 
# 221
extern float y1f(float) throw(); extern float __y1f(float) throw(); 
# 222
extern float ynf(int, float) throw(); extern float __ynf(int, float) throw(); 
# 228
extern float erff(float) throw(); extern float __erff(float) throw(); 
# 229
extern float erfcf(float) throw(); extern float __erfcf(float) throw(); 
# 230
extern float lgammaf(float) throw(); extern float __lgammaf(float) throw(); 
# 235
extern float tgammaf(float) throw(); extern float __tgammaf(float) throw(); 
# 241
extern float gammaf(float) throw(); extern float __gammaf(float) throw(); 
# 249
extern float lgammaf_r(float, int * __signgamp) throw(); extern float __lgammaf_r(float, int * __signgamp) throw(); 
# 256
extern float rintf(float __x) throw(); extern float __rintf(float __x) throw(); 
# 259
extern float nextafterf(float __x, float __y) throw(); extern float __nextafterf(float __x, float __y) throw(); 
# 261
extern float nexttowardf(float __x, long double __y) throw(); extern float __nexttowardf(float __x, long double __y) throw(); 
# 266
extern float nextdownf(float __x) throw(); extern float __nextdownf(float __x) throw(); 
# 268
extern float nextupf(float __x) throw(); extern float __nextupf(float __x) throw(); 
# 272
extern float remainderf(float __x, float __y) throw(); extern float __remainderf(float __x, float __y) throw(); 
# 276
extern float scalbnf(float __x, int __n) throw(); extern float __scalbnf(float __x, int __n) throw(); 
# 280
extern int ilogbf(float __x) throw(); extern int __ilogbf(float __x) throw(); 
# 285
extern long llogbf(float __x) throw(); extern long __llogbf(float __x) throw(); 
# 290
extern float scalblnf(float __x, long __n) throw(); extern float __scalblnf(float __x, long __n) throw(); 
# 294
extern float nearbyintf(float __x) throw(); extern float __nearbyintf(float __x) throw(); 
# 298
extern float roundf(float __x) throw() __attribute((const)); extern float __roundf(float __x) throw() __attribute((const)); 
# 302
extern float truncf(float __x) throw() __attribute((const)); extern float __truncf(float __x) throw() __attribute((const)); 
# 307
extern float remquof(float __x, float __y, int * __quo) throw(); extern float __remquof(float __x, float __y, int * __quo) throw(); 
# 314
extern long lrintf(float __x) throw(); extern long __lrintf(float __x) throw(); 
# 316
__extension__ extern long long llrintf(float __x) throw(); extern long long __llrintf(float __x) throw(); 
# 320
extern long lroundf(float __x) throw(); extern long __lroundf(float __x) throw(); 
# 322
__extension__ extern long long llroundf(float __x) throw(); extern long long __llroundf(float __x) throw(); 
# 326
extern float fdimf(float __x, float __y) throw(); extern float __fdimf(float __x, float __y) throw(); 
# 329
extern float fmaxf(float __x, float __y) throw() __attribute((const)); extern float __fmaxf(float __x, float __y) throw() __attribute((const)); 
# 332
extern float fminf(float __x, float __y) throw() __attribute((const)); extern float __fminf(float __x, float __y) throw() __attribute((const)); 
# 335
extern float fmaf(float __x, float __y, float __z) throw(); extern float __fmaf(float __x, float __y, float __z) throw(); 
# 340
extern float roundevenf(float __x) throw() __attribute((const)); extern float __roundevenf(float __x) throw() __attribute((const)); 
# 344
extern __intmax_t fromfpf(float __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpf(float __x, int __round, unsigned __width) throw(); 
# 349
extern __uintmax_t ufromfpf(float __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpf(float __x, int __round, unsigned __width) throw(); 
# 355
extern __intmax_t fromfpxf(float __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpxf(float __x, int __round, unsigned __width) throw(); 
# 361
extern __uintmax_t ufromfpxf(float __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpxf(float __x, int __round, unsigned __width) throw(); 
# 365
extern float fmaxmagf(float __x, float __y) throw() __attribute((const)); extern float __fmaxmagf(float __x, float __y) throw() __attribute((const)); 
# 368
extern float fminmagf(float __x, float __y) throw() __attribute((const)); extern float __fminmagf(float __x, float __y) throw() __attribute((const)); 
# 371
extern int totalorderf(float __x, float __y) throw()
# 372
 __attribute((const)); 
# 375
extern int totalordermagf(float __x, float __y) throw()
# 376
 __attribute((const)); 
# 379
extern int canonicalizef(float * __cx, const float * __x) throw(); 
# 382
extern float getpayloadf(const float * __x) throw(); extern float __getpayloadf(const float * __x) throw(); 
# 385
extern int setpayloadf(float * __x, float __payload) throw(); 
# 388
extern int setpayloadsigf(float * __x, float __payload) throw(); 
# 396
extern float scalbf(float __x, float __n) throw(); extern float __scalbf(float __x, float __n) throw(); 
# 21 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 3
extern int __fpclassifyl(long double __value) throw()
# 22
 __attribute((const)); 
# 25
extern int __signbitl(long double __value) throw()
# 26
 __attribute((const)); 
# 30
extern int __isinfl(long double __value) throw() __attribute((const)); 
# 33
extern int __finitel(long double __value) throw() __attribute((const)); 
# 36
extern int __isnanl(long double __value) throw() __attribute((const)); 
# 39
extern int __iseqsigl(long double __x, long double __y) throw(); 
# 42
extern int __issignalingl(long double __value) throw()
# 43
 __attribute((const)); 
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern long double acosl(long double __x) throw(); extern long double __acosl(long double __x) throw(); 
# 55
extern long double asinl(long double __x) throw(); extern long double __asinl(long double __x) throw(); 
# 57
extern long double atanl(long double __x) throw(); extern long double __atanl(long double __x) throw(); 
# 59
extern long double atan2l(long double __y, long double __x) throw(); extern long double __atan2l(long double __y, long double __x) throw(); 
# 62
extern long double cosl(long double __x) throw(); extern long double __cosl(long double __x) throw(); 
# 64
extern long double sinl(long double __x) throw(); extern long double __sinl(long double __x) throw(); 
# 66
extern long double tanl(long double __x) throw(); extern long double __tanl(long double __x) throw(); 
# 71
extern long double coshl(long double __x) throw(); extern long double __coshl(long double __x) throw(); 
# 73
extern long double sinhl(long double __x) throw(); extern long double __sinhl(long double __x) throw(); 
# 75
extern long double tanhl(long double __x) throw(); extern long double __tanhl(long double __x) throw(); 
# 79
extern void sincosl(long double __x, long double * __sinx, long double * __cosx) throw(); extern void __sincosl(long double __x, long double * __sinx, long double * __cosx) throw(); 
# 85
extern long double acoshl(long double __x) throw(); extern long double __acoshl(long double __x) throw(); 
# 87
extern long double asinhl(long double __x) throw(); extern long double __asinhl(long double __x) throw(); 
# 89
extern long double atanhl(long double __x) throw(); extern long double __atanhl(long double __x) throw(); 
# 95
extern long double expl(long double __x) throw(); extern long double __expl(long double __x) throw(); 
# 98
extern long double frexpl(long double __x, int * __exponent) throw(); extern long double __frexpl(long double __x, int * __exponent) throw(); 
# 101
extern long double ldexpl(long double __x, int __exponent) throw(); extern long double __ldexpl(long double __x, int __exponent) throw(); 
# 104
extern long double logl(long double __x) throw(); extern long double __logl(long double __x) throw(); 
# 107
extern long double log10l(long double __x) throw(); extern long double __log10l(long double __x) throw(); 
# 110
extern long double modfl(long double __x, long double * __iptr) throw(); extern long double __modfl(long double __x, long double * __iptr) throw() __attribute((__nonnull__(2))); 
# 114
extern long double exp10l(long double __x) throw(); extern long double __exp10l(long double __x) throw(); 
# 119
extern long double expm1l(long double __x) throw(); extern long double __expm1l(long double __x) throw(); 
# 122
extern long double log1pl(long double __x) throw(); extern long double __log1pl(long double __x) throw(); 
# 125
extern long double logbl(long double __x) throw(); extern long double __logbl(long double __x) throw(); 
# 130
extern long double exp2l(long double __x) throw(); extern long double __exp2l(long double __x) throw(); 
# 133
extern long double log2l(long double __x) throw(); extern long double __log2l(long double __x) throw(); 
# 140
extern long double powl(long double __x, long double __y) throw(); extern long double __powl(long double __x, long double __y) throw(); 
# 143
extern long double sqrtl(long double __x) throw(); extern long double __sqrtl(long double __x) throw(); 
# 147
extern long double hypotl(long double __x, long double __y) throw(); extern long double __hypotl(long double __x, long double __y) throw(); 
# 152
extern long double cbrtl(long double __x) throw(); extern long double __cbrtl(long double __x) throw(); 
# 159
extern long double ceill(long double __x) throw() __attribute((const)); extern long double __ceill(long double __x) throw() __attribute((const)); 
# 162
extern long double fabsl(long double __x) throw() __attribute((const)); extern long double __fabsl(long double __x) throw() __attribute((const)); 
# 165
extern long double floorl(long double __x) throw() __attribute((const)); extern long double __floorl(long double __x) throw() __attribute((const)); 
# 168
extern long double fmodl(long double __x, long double __y) throw(); extern long double __fmodl(long double __x, long double __y) throw(); 
# 177 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern int isinfl(long double __value) throw() __attribute((const)); 
# 182
extern int finitel(long double __value) throw() __attribute((const)); 
# 185
extern long double dreml(long double __x, long double __y) throw(); extern long double __dreml(long double __x, long double __y) throw(); 
# 189
extern long double significandl(long double __x) throw(); extern long double __significandl(long double __x) throw(); 
# 196
extern long double copysignl(long double __x, long double __y) throw() __attribute((const)); extern long double __copysignl(long double __x, long double __y) throw() __attribute((const)); 
# 201
extern long double nanl(const char * __tagb) throw() __attribute((const)); extern long double __nanl(const char * __tagb) throw() __attribute((const)); 
# 211 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern int isnanl(long double __value) throw() __attribute((const)); 
# 217
extern long double j0l(long double) throw(); extern long double __j0l(long double) throw(); 
# 218
extern long double j1l(long double) throw(); extern long double __j1l(long double) throw(); 
# 219
extern long double jnl(int, long double) throw(); extern long double __jnl(int, long double) throw(); 
# 220
extern long double y0l(long double) throw(); extern long double __y0l(long double) throw(); 
# 221
extern long double y1l(long double) throw(); extern long double __y1l(long double) throw(); 
# 222
extern long double ynl(int, long double) throw(); extern long double __ynl(int, long double) throw(); 
# 228
extern long double erfl(long double) throw(); extern long double __erfl(long double) throw(); 
# 229
extern long double erfcl(long double) throw(); extern long double __erfcl(long double) throw(); 
# 230
extern long double lgammal(long double) throw(); extern long double __lgammal(long double) throw(); 
# 235
extern long double tgammal(long double) throw(); extern long double __tgammal(long double) throw(); 
# 241
extern long double gammal(long double) throw(); extern long double __gammal(long double) throw(); 
# 249
extern long double lgammal_r(long double, int * __signgamp) throw(); extern long double __lgammal_r(long double, int * __signgamp) throw(); 
# 256
extern long double rintl(long double __x) throw(); extern long double __rintl(long double __x) throw(); 
# 259
extern long double nextafterl(long double __x, long double __y) throw(); extern long double __nextafterl(long double __x, long double __y) throw(); 
# 261
extern long double nexttowardl(long double __x, long double __y) throw(); extern long double __nexttowardl(long double __x, long double __y) throw(); 
# 266
extern long double nextdownl(long double __x) throw(); extern long double __nextdownl(long double __x) throw(); 
# 268
extern long double nextupl(long double __x) throw(); extern long double __nextupl(long double __x) throw(); 
# 272
extern long double remainderl(long double __x, long double __y) throw(); extern long double __remainderl(long double __x, long double __y) throw(); 
# 276
extern long double scalbnl(long double __x, int __n) throw(); extern long double __scalbnl(long double __x, int __n) throw(); 
# 280
extern int ilogbl(long double __x) throw(); extern int __ilogbl(long double __x) throw(); 
# 285
extern long llogbl(long double __x) throw(); extern long __llogbl(long double __x) throw(); 
# 290
extern long double scalblnl(long double __x, long __n) throw(); extern long double __scalblnl(long double __x, long __n) throw(); 
# 294
extern long double nearbyintl(long double __x) throw(); extern long double __nearbyintl(long double __x) throw(); 
# 298
extern long double roundl(long double __x) throw() __attribute((const)); extern long double __roundl(long double __x) throw() __attribute((const)); 
# 302
extern long double truncl(long double __x) throw() __attribute((const)); extern long double __truncl(long double __x) throw() __attribute((const)); 
# 307
extern long double remquol(long double __x, long double __y, int * __quo) throw(); extern long double __remquol(long double __x, long double __y, int * __quo) throw(); 
# 314
extern long lrintl(long double __x) throw(); extern long __lrintl(long double __x) throw(); 
# 316
__extension__ extern long long llrintl(long double __x) throw(); extern long long __llrintl(long double __x) throw(); 
# 320
extern long lroundl(long double __x) throw(); extern long __lroundl(long double __x) throw(); 
# 322
__extension__ extern long long llroundl(long double __x) throw(); extern long long __llroundl(long double __x) throw(); 
# 326
extern long double fdiml(long double __x, long double __y) throw(); extern long double __fdiml(long double __x, long double __y) throw(); 
# 329
extern long double fmaxl(long double __x, long double __y) throw() __attribute((const)); extern long double __fmaxl(long double __x, long double __y) throw() __attribute((const)); 
# 332
extern long double fminl(long double __x, long double __y) throw() __attribute((const)); extern long double __fminl(long double __x, long double __y) throw() __attribute((const)); 
# 335
extern long double fmal(long double __x, long double __y, long double __z) throw(); extern long double __fmal(long double __x, long double __y, long double __z) throw(); 
# 340
extern long double roundevenl(long double __x) throw() __attribute((const)); extern long double __roundevenl(long double __x) throw() __attribute((const)); 
# 344
extern __intmax_t fromfpl(long double __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpl(long double __x, int __round, unsigned __width) throw(); 
# 349
extern __uintmax_t ufromfpl(long double __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpl(long double __x, int __round, unsigned __width) throw(); 
# 355
extern __intmax_t fromfpxl(long double __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpxl(long double __x, int __round, unsigned __width) throw(); 
# 361
extern __uintmax_t ufromfpxl(long double __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpxl(long double __x, int __round, unsigned __width) throw(); 
# 365
extern long double fmaxmagl(long double __x, long double __y) throw() __attribute((const)); extern long double __fmaxmagl(long double __x, long double __y) throw() __attribute((const)); 
# 368
extern long double fminmagl(long double __x, long double __y) throw() __attribute((const)); extern long double __fminmagl(long double __x, long double __y) throw() __attribute((const)); 
# 371
extern int totalorderl(long double __x, long double __y) throw()
# 372
 __attribute((const)); 
# 375
extern int totalordermagl(long double __x, long double __y) throw()
# 376
 __attribute((const)); 
# 379
extern int canonicalizel(long double * __cx, const long double * __x) throw(); 
# 382
extern long double getpayloadl(const long double * __x) throw(); extern long double __getpayloadl(const long double * __x) throw(); 
# 385
extern int setpayloadl(long double * __x, long double __payload) throw(); 
# 388
extern int setpayloadsigl(long double * __x, long double __payload) throw(); 
# 396
extern long double scalbl(long double __x, long double __n) throw(); extern long double __scalbl(long double __x, long double __n) throw(); 
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float32 acosf32(_Float32 __x) throw(); extern _Float32 __acosf32(_Float32 __x) throw(); 
# 55
extern _Float32 asinf32(_Float32 __x) throw(); extern _Float32 __asinf32(_Float32 __x) throw(); 
# 57
extern _Float32 atanf32(_Float32 __x) throw(); extern _Float32 __atanf32(_Float32 __x) throw(); 
# 59
extern _Float32 atan2f32(_Float32 __y, _Float32 __x) throw(); extern _Float32 __atan2f32(_Float32 __y, _Float32 __x) throw(); 
# 62
extern _Float32 cosf32(_Float32 __x) throw(); extern _Float32 __cosf32(_Float32 __x) throw(); 
# 64
extern _Float32 sinf32(_Float32 __x) throw(); extern _Float32 __sinf32(_Float32 __x) throw(); 
# 66
extern _Float32 tanf32(_Float32 __x) throw(); extern _Float32 __tanf32(_Float32 __x) throw(); 
# 71
extern _Float32 coshf32(_Float32 __x) throw(); extern _Float32 __coshf32(_Float32 __x) throw(); 
# 73
extern _Float32 sinhf32(_Float32 __x) throw(); extern _Float32 __sinhf32(_Float32 __x) throw(); 
# 75
extern _Float32 tanhf32(_Float32 __x) throw(); extern _Float32 __tanhf32(_Float32 __x) throw(); 
# 79
extern void sincosf32(_Float32 __x, _Float32 * __sinx, _Float32 * __cosx) throw(); extern void __sincosf32(_Float32 __x, _Float32 * __sinx, _Float32 * __cosx) throw(); 
# 85
extern _Float32 acoshf32(_Float32 __x) throw(); extern _Float32 __acoshf32(_Float32 __x) throw(); 
# 87
extern _Float32 asinhf32(_Float32 __x) throw(); extern _Float32 __asinhf32(_Float32 __x) throw(); 
# 89
extern _Float32 atanhf32(_Float32 __x) throw(); extern _Float32 __atanhf32(_Float32 __x) throw(); 
# 95
extern _Float32 expf32(_Float32 __x) throw(); extern _Float32 __expf32(_Float32 __x) throw(); 
# 98
extern _Float32 frexpf32(_Float32 __x, int * __exponent) throw(); extern _Float32 __frexpf32(_Float32 __x, int * __exponent) throw(); 
# 101
extern _Float32 ldexpf32(_Float32 __x, int __exponent) throw(); extern _Float32 __ldexpf32(_Float32 __x, int __exponent) throw(); 
# 104
extern _Float32 logf32(_Float32 __x) throw(); extern _Float32 __logf32(_Float32 __x) throw(); 
# 107
extern _Float32 log10f32(_Float32 __x) throw(); extern _Float32 __log10f32(_Float32 __x) throw(); 
# 110
extern _Float32 modff32(_Float32 __x, _Float32 * __iptr) throw(); extern _Float32 __modff32(_Float32 __x, _Float32 * __iptr) throw() __attribute((__nonnull__(2))); 
# 114
extern _Float32 exp10f32(_Float32 __x) throw(); extern _Float32 __exp10f32(_Float32 __x) throw(); 
# 119
extern _Float32 expm1f32(_Float32 __x) throw(); extern _Float32 __expm1f32(_Float32 __x) throw(); 
# 122
extern _Float32 log1pf32(_Float32 __x) throw(); extern _Float32 __log1pf32(_Float32 __x) throw(); 
# 125
extern _Float32 logbf32(_Float32 __x) throw(); extern _Float32 __logbf32(_Float32 __x) throw(); 
# 130
extern _Float32 exp2f32(_Float32 __x) throw(); extern _Float32 __exp2f32(_Float32 __x) throw(); 
# 133
extern _Float32 log2f32(_Float32 __x) throw(); extern _Float32 __log2f32(_Float32 __x) throw(); 
# 140
extern _Float32 powf32(_Float32 __x, _Float32 __y) throw(); extern _Float32 __powf32(_Float32 __x, _Float32 __y) throw(); 
# 143
extern _Float32 sqrtf32(_Float32 __x) throw(); extern _Float32 __sqrtf32(_Float32 __x) throw(); 
# 147
extern _Float32 hypotf32(_Float32 __x, _Float32 __y) throw(); extern _Float32 __hypotf32(_Float32 __x, _Float32 __y) throw(); 
# 152
extern _Float32 cbrtf32(_Float32 __x) throw(); extern _Float32 __cbrtf32(_Float32 __x) throw(); 
# 159
extern _Float32 ceilf32(_Float32 __x) throw() __attribute((const)); extern _Float32 __ceilf32(_Float32 __x) throw() __attribute((const)); 
# 162
extern _Float32 fabsf32(_Float32 __x) throw() __attribute((const)); extern _Float32 __fabsf32(_Float32 __x) throw() __attribute((const)); 
# 165
extern _Float32 floorf32(_Float32 __x) throw() __attribute((const)); extern _Float32 __floorf32(_Float32 __x) throw() __attribute((const)); 
# 168
extern _Float32 fmodf32(_Float32 __x, _Float32 __y) throw(); extern _Float32 __fmodf32(_Float32 __x, _Float32 __y) throw(); 
# 196 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float32 copysignf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); extern _Float32 __copysignf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); 
# 201
extern _Float32 nanf32(const char * __tagb) throw() __attribute((const)); extern _Float32 __nanf32(const char * __tagb) throw() __attribute((const)); 
# 217 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float32 j0f32(_Float32) throw(); extern _Float32 __j0f32(_Float32) throw(); 
# 218
extern _Float32 j1f32(_Float32) throw(); extern _Float32 __j1f32(_Float32) throw(); 
# 219
extern _Float32 jnf32(int, _Float32) throw(); extern _Float32 __jnf32(int, _Float32) throw(); 
# 220
extern _Float32 y0f32(_Float32) throw(); extern _Float32 __y0f32(_Float32) throw(); 
# 221
extern _Float32 y1f32(_Float32) throw(); extern _Float32 __y1f32(_Float32) throw(); 
# 222
extern _Float32 ynf32(int, _Float32) throw(); extern _Float32 __ynf32(int, _Float32) throw(); 
# 228
extern _Float32 erff32(_Float32) throw(); extern _Float32 __erff32(_Float32) throw(); 
# 229
extern _Float32 erfcf32(_Float32) throw(); extern _Float32 __erfcf32(_Float32) throw(); 
# 230
extern _Float32 lgammaf32(_Float32) throw(); extern _Float32 __lgammaf32(_Float32) throw(); 
# 235
extern _Float32 tgammaf32(_Float32) throw(); extern _Float32 __tgammaf32(_Float32) throw(); 
# 249 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float32 lgammaf32_r(_Float32, int * __signgamp) throw(); extern _Float32 __lgammaf32_r(_Float32, int * __signgamp) throw(); 
# 256
extern _Float32 rintf32(_Float32 __x) throw(); extern _Float32 __rintf32(_Float32 __x) throw(); 
# 259
extern _Float32 nextafterf32(_Float32 __x, _Float32 __y) throw(); extern _Float32 __nextafterf32(_Float32 __x, _Float32 __y) throw(); 
# 266
extern _Float32 nextdownf32(_Float32 __x) throw(); extern _Float32 __nextdownf32(_Float32 __x) throw(); 
# 268
extern _Float32 nextupf32(_Float32 __x) throw(); extern _Float32 __nextupf32(_Float32 __x) throw(); 
# 272
extern _Float32 remainderf32(_Float32 __x, _Float32 __y) throw(); extern _Float32 __remainderf32(_Float32 __x, _Float32 __y) throw(); 
# 276
extern _Float32 scalbnf32(_Float32 __x, int __n) throw(); extern _Float32 __scalbnf32(_Float32 __x, int __n) throw(); 
# 280
extern int ilogbf32(_Float32 __x) throw(); extern int __ilogbf32(_Float32 __x) throw(); 
# 285
extern long llogbf32(_Float32 __x) throw(); extern long __llogbf32(_Float32 __x) throw(); 
# 290
extern _Float32 scalblnf32(_Float32 __x, long __n) throw(); extern _Float32 __scalblnf32(_Float32 __x, long __n) throw(); 
# 294
extern _Float32 nearbyintf32(_Float32 __x) throw(); extern _Float32 __nearbyintf32(_Float32 __x) throw(); 
# 298
extern _Float32 roundf32(_Float32 __x) throw() __attribute((const)); extern _Float32 __roundf32(_Float32 __x) throw() __attribute((const)); 
# 302
extern _Float32 truncf32(_Float32 __x) throw() __attribute((const)); extern _Float32 __truncf32(_Float32 __x) throw() __attribute((const)); 
# 307
extern _Float32 remquof32(_Float32 __x, _Float32 __y, int * __quo) throw(); extern _Float32 __remquof32(_Float32 __x, _Float32 __y, int * __quo) throw(); 
# 314
extern long lrintf32(_Float32 __x) throw(); extern long __lrintf32(_Float32 __x) throw(); 
# 316
__extension__ extern long long llrintf32(_Float32 __x) throw(); extern long long __llrintf32(_Float32 __x) throw(); 
# 320
extern long lroundf32(_Float32 __x) throw(); extern long __lroundf32(_Float32 __x) throw(); 
# 322
__extension__ extern long long llroundf32(_Float32 __x) throw(); extern long long __llroundf32(_Float32 __x) throw(); 
# 326
extern _Float32 fdimf32(_Float32 __x, _Float32 __y) throw(); extern _Float32 __fdimf32(_Float32 __x, _Float32 __y) throw(); 
# 329
extern _Float32 fmaxf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); extern _Float32 __fmaxf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); 
# 332
extern _Float32 fminf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); extern _Float32 __fminf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); 
# 335
extern _Float32 fmaf32(_Float32 __x, _Float32 __y, _Float32 __z) throw(); extern _Float32 __fmaf32(_Float32 __x, _Float32 __y, _Float32 __z) throw(); 
# 340
extern _Float32 roundevenf32(_Float32 __x) throw() __attribute((const)); extern _Float32 __roundevenf32(_Float32 __x) throw() __attribute((const)); 
# 344
extern __intmax_t fromfpf32(_Float32 __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpf32(_Float32 __x, int __round, unsigned __width) throw(); 
# 349
extern __uintmax_t ufromfpf32(_Float32 __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpf32(_Float32 __x, int __round, unsigned __width) throw(); 
# 355
extern __intmax_t fromfpxf32(_Float32 __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpxf32(_Float32 __x, int __round, unsigned __width) throw(); 
# 361
extern __uintmax_t ufromfpxf32(_Float32 __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpxf32(_Float32 __x, int __round, unsigned __width) throw(); 
# 365
extern _Float32 fmaxmagf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); extern _Float32 __fmaxmagf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); 
# 368
extern _Float32 fminmagf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); extern _Float32 __fminmagf32(_Float32 __x, _Float32 __y) throw() __attribute((const)); 
# 371
extern int totalorderf32(_Float32 __x, _Float32 __y) throw()
# 372
 __attribute((const)); 
# 375
extern int totalordermagf32(_Float32 __x, _Float32 __y) throw()
# 376
 __attribute((const)); 
# 379
extern int canonicalizef32(_Float32 * __cx, const _Float32 * __x) throw(); 
# 382
extern _Float32 getpayloadf32(const _Float32 * __x) throw(); extern _Float32 __getpayloadf32(const _Float32 * __x) throw(); 
# 385
extern int setpayloadf32(_Float32 * __x, _Float32 __payload) throw(); 
# 388
extern int setpayloadsigf32(_Float32 * __x, _Float32 __payload) throw(); 
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float64 acosf64(_Float64 __x) throw(); extern _Float64 __acosf64(_Float64 __x) throw(); 
# 55
extern _Float64 asinf64(_Float64 __x) throw(); extern _Float64 __asinf64(_Float64 __x) throw(); 
# 57
extern _Float64 atanf64(_Float64 __x) throw(); extern _Float64 __atanf64(_Float64 __x) throw(); 
# 59
extern _Float64 atan2f64(_Float64 __y, _Float64 __x) throw(); extern _Float64 __atan2f64(_Float64 __y, _Float64 __x) throw(); 
# 62
extern _Float64 cosf64(_Float64 __x) throw(); extern _Float64 __cosf64(_Float64 __x) throw(); 
# 64
extern _Float64 sinf64(_Float64 __x) throw(); extern _Float64 __sinf64(_Float64 __x) throw(); 
# 66
extern _Float64 tanf64(_Float64 __x) throw(); extern _Float64 __tanf64(_Float64 __x) throw(); 
# 71
extern _Float64 coshf64(_Float64 __x) throw(); extern _Float64 __coshf64(_Float64 __x) throw(); 
# 73
extern _Float64 sinhf64(_Float64 __x) throw(); extern _Float64 __sinhf64(_Float64 __x) throw(); 
# 75
extern _Float64 tanhf64(_Float64 __x) throw(); extern _Float64 __tanhf64(_Float64 __x) throw(); 
# 79
extern void sincosf64(_Float64 __x, _Float64 * __sinx, _Float64 * __cosx) throw(); extern void __sincosf64(_Float64 __x, _Float64 * __sinx, _Float64 * __cosx) throw(); 
# 85
extern _Float64 acoshf64(_Float64 __x) throw(); extern _Float64 __acoshf64(_Float64 __x) throw(); 
# 87
extern _Float64 asinhf64(_Float64 __x) throw(); extern _Float64 __asinhf64(_Float64 __x) throw(); 
# 89
extern _Float64 atanhf64(_Float64 __x) throw(); extern _Float64 __atanhf64(_Float64 __x) throw(); 
# 95
extern _Float64 expf64(_Float64 __x) throw(); extern _Float64 __expf64(_Float64 __x) throw(); 
# 98
extern _Float64 frexpf64(_Float64 __x, int * __exponent) throw(); extern _Float64 __frexpf64(_Float64 __x, int * __exponent) throw(); 
# 101
extern _Float64 ldexpf64(_Float64 __x, int __exponent) throw(); extern _Float64 __ldexpf64(_Float64 __x, int __exponent) throw(); 
# 104
extern _Float64 logf64(_Float64 __x) throw(); extern _Float64 __logf64(_Float64 __x) throw(); 
# 107
extern _Float64 log10f64(_Float64 __x) throw(); extern _Float64 __log10f64(_Float64 __x) throw(); 
# 110
extern _Float64 modff64(_Float64 __x, _Float64 * __iptr) throw(); extern _Float64 __modff64(_Float64 __x, _Float64 * __iptr) throw() __attribute((__nonnull__(2))); 
# 114
extern _Float64 exp10f64(_Float64 __x) throw(); extern _Float64 __exp10f64(_Float64 __x) throw(); 
# 119
extern _Float64 expm1f64(_Float64 __x) throw(); extern _Float64 __expm1f64(_Float64 __x) throw(); 
# 122
extern _Float64 log1pf64(_Float64 __x) throw(); extern _Float64 __log1pf64(_Float64 __x) throw(); 
# 125
extern _Float64 logbf64(_Float64 __x) throw(); extern _Float64 __logbf64(_Float64 __x) throw(); 
# 130
extern _Float64 exp2f64(_Float64 __x) throw(); extern _Float64 __exp2f64(_Float64 __x) throw(); 
# 133
extern _Float64 log2f64(_Float64 __x) throw(); extern _Float64 __log2f64(_Float64 __x) throw(); 
# 140
extern _Float64 powf64(_Float64 __x, _Float64 __y) throw(); extern _Float64 __powf64(_Float64 __x, _Float64 __y) throw(); 
# 143
extern _Float64 sqrtf64(_Float64 __x) throw(); extern _Float64 __sqrtf64(_Float64 __x) throw(); 
# 147
extern _Float64 hypotf64(_Float64 __x, _Float64 __y) throw(); extern _Float64 __hypotf64(_Float64 __x, _Float64 __y) throw(); 
# 152
extern _Float64 cbrtf64(_Float64 __x) throw(); extern _Float64 __cbrtf64(_Float64 __x) throw(); 
# 159
extern _Float64 ceilf64(_Float64 __x) throw() __attribute((const)); extern _Float64 __ceilf64(_Float64 __x) throw() __attribute((const)); 
# 162
extern _Float64 fabsf64(_Float64 __x) throw() __attribute((const)); extern _Float64 __fabsf64(_Float64 __x) throw() __attribute((const)); 
# 165
extern _Float64 floorf64(_Float64 __x) throw() __attribute((const)); extern _Float64 __floorf64(_Float64 __x) throw() __attribute((const)); 
# 168
extern _Float64 fmodf64(_Float64 __x, _Float64 __y) throw(); extern _Float64 __fmodf64(_Float64 __x, _Float64 __y) throw(); 
# 196 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float64 copysignf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); extern _Float64 __copysignf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); 
# 201
extern _Float64 nanf64(const char * __tagb) throw() __attribute((const)); extern _Float64 __nanf64(const char * __tagb) throw() __attribute((const)); 
# 217 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float64 j0f64(_Float64) throw(); extern _Float64 __j0f64(_Float64) throw(); 
# 218
extern _Float64 j1f64(_Float64) throw(); extern _Float64 __j1f64(_Float64) throw(); 
# 219
extern _Float64 jnf64(int, _Float64) throw(); extern _Float64 __jnf64(int, _Float64) throw(); 
# 220
extern _Float64 y0f64(_Float64) throw(); extern _Float64 __y0f64(_Float64) throw(); 
# 221
extern _Float64 y1f64(_Float64) throw(); extern _Float64 __y1f64(_Float64) throw(); 
# 222
extern _Float64 ynf64(int, _Float64) throw(); extern _Float64 __ynf64(int, _Float64) throw(); 
# 228
extern _Float64 erff64(_Float64) throw(); extern _Float64 __erff64(_Float64) throw(); 
# 229
extern _Float64 erfcf64(_Float64) throw(); extern _Float64 __erfcf64(_Float64) throw(); 
# 230
extern _Float64 lgammaf64(_Float64) throw(); extern _Float64 __lgammaf64(_Float64) throw(); 
# 235
extern _Float64 tgammaf64(_Float64) throw(); extern _Float64 __tgammaf64(_Float64) throw(); 
# 249 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float64 lgammaf64_r(_Float64, int * __signgamp) throw(); extern _Float64 __lgammaf64_r(_Float64, int * __signgamp) throw(); 
# 256
extern _Float64 rintf64(_Float64 __x) throw(); extern _Float64 __rintf64(_Float64 __x) throw(); 
# 259
extern _Float64 nextafterf64(_Float64 __x, _Float64 __y) throw(); extern _Float64 __nextafterf64(_Float64 __x, _Float64 __y) throw(); 
# 266
extern _Float64 nextdownf64(_Float64 __x) throw(); extern _Float64 __nextdownf64(_Float64 __x) throw(); 
# 268
extern _Float64 nextupf64(_Float64 __x) throw(); extern _Float64 __nextupf64(_Float64 __x) throw(); 
# 272
extern _Float64 remainderf64(_Float64 __x, _Float64 __y) throw(); extern _Float64 __remainderf64(_Float64 __x, _Float64 __y) throw(); 
# 276
extern _Float64 scalbnf64(_Float64 __x, int __n) throw(); extern _Float64 __scalbnf64(_Float64 __x, int __n) throw(); 
# 280
extern int ilogbf64(_Float64 __x) throw(); extern int __ilogbf64(_Float64 __x) throw(); 
# 285
extern long llogbf64(_Float64 __x) throw(); extern long __llogbf64(_Float64 __x) throw(); 
# 290
extern _Float64 scalblnf64(_Float64 __x, long __n) throw(); extern _Float64 __scalblnf64(_Float64 __x, long __n) throw(); 
# 294
extern _Float64 nearbyintf64(_Float64 __x) throw(); extern _Float64 __nearbyintf64(_Float64 __x) throw(); 
# 298
extern _Float64 roundf64(_Float64 __x) throw() __attribute((const)); extern _Float64 __roundf64(_Float64 __x) throw() __attribute((const)); 
# 302
extern _Float64 truncf64(_Float64 __x) throw() __attribute((const)); extern _Float64 __truncf64(_Float64 __x) throw() __attribute((const)); 
# 307
extern _Float64 remquof64(_Float64 __x, _Float64 __y, int * __quo) throw(); extern _Float64 __remquof64(_Float64 __x, _Float64 __y, int * __quo) throw(); 
# 314
extern long lrintf64(_Float64 __x) throw(); extern long __lrintf64(_Float64 __x) throw(); 
# 316
__extension__ extern long long llrintf64(_Float64 __x) throw(); extern long long __llrintf64(_Float64 __x) throw(); 
# 320
extern long lroundf64(_Float64 __x) throw(); extern long __lroundf64(_Float64 __x) throw(); 
# 322
__extension__ extern long long llroundf64(_Float64 __x) throw(); extern long long __llroundf64(_Float64 __x) throw(); 
# 326
extern _Float64 fdimf64(_Float64 __x, _Float64 __y) throw(); extern _Float64 __fdimf64(_Float64 __x, _Float64 __y) throw(); 
# 329
extern _Float64 fmaxf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); extern _Float64 __fmaxf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); 
# 332
extern _Float64 fminf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); extern _Float64 __fminf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); 
# 335
extern _Float64 fmaf64(_Float64 __x, _Float64 __y, _Float64 __z) throw(); extern _Float64 __fmaf64(_Float64 __x, _Float64 __y, _Float64 __z) throw(); 
# 340
extern _Float64 roundevenf64(_Float64 __x) throw() __attribute((const)); extern _Float64 __roundevenf64(_Float64 __x) throw() __attribute((const)); 
# 344
extern __intmax_t fromfpf64(_Float64 __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpf64(_Float64 __x, int __round, unsigned __width) throw(); 
# 349
extern __uintmax_t ufromfpf64(_Float64 __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpf64(_Float64 __x, int __round, unsigned __width) throw(); 
# 355
extern __intmax_t fromfpxf64(_Float64 __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpxf64(_Float64 __x, int __round, unsigned __width) throw(); 
# 361
extern __uintmax_t ufromfpxf64(_Float64 __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpxf64(_Float64 __x, int __round, unsigned __width) throw(); 
# 365
extern _Float64 fmaxmagf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); extern _Float64 __fmaxmagf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); 
# 368
extern _Float64 fminmagf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); extern _Float64 __fminmagf64(_Float64 __x, _Float64 __y) throw() __attribute((const)); 
# 371
extern int totalorderf64(_Float64 __x, _Float64 __y) throw()
# 372
 __attribute((const)); 
# 375
extern int totalordermagf64(_Float64 __x, _Float64 __y) throw()
# 376
 __attribute((const)); 
# 379
extern int canonicalizef64(_Float64 * __cx, const _Float64 * __x) throw(); 
# 382
extern _Float64 getpayloadf64(const _Float64 * __x) throw(); extern _Float64 __getpayloadf64(const _Float64 * __x) throw(); 
# 385
extern int setpayloadf64(_Float64 * __x, _Float64 __payload) throw(); 
# 388
extern int setpayloadsigf64(_Float64 * __x, _Float64 __payload) throw(); 
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float32x acosf32x(_Float32x __x) throw(); extern _Float32x __acosf32x(_Float32x __x) throw(); 
# 55
extern _Float32x asinf32x(_Float32x __x) throw(); extern _Float32x __asinf32x(_Float32x __x) throw(); 
# 57
extern _Float32x atanf32x(_Float32x __x) throw(); extern _Float32x __atanf32x(_Float32x __x) throw(); 
# 59
extern _Float32x atan2f32x(_Float32x __y, _Float32x __x) throw(); extern _Float32x __atan2f32x(_Float32x __y, _Float32x __x) throw(); 
# 62
extern _Float32x cosf32x(_Float32x __x) throw(); extern _Float32x __cosf32x(_Float32x __x) throw(); 
# 64
extern _Float32x sinf32x(_Float32x __x) throw(); extern _Float32x __sinf32x(_Float32x __x) throw(); 
# 66
extern _Float32x tanf32x(_Float32x __x) throw(); extern _Float32x __tanf32x(_Float32x __x) throw(); 
# 71
extern _Float32x coshf32x(_Float32x __x) throw(); extern _Float32x __coshf32x(_Float32x __x) throw(); 
# 73
extern _Float32x sinhf32x(_Float32x __x) throw(); extern _Float32x __sinhf32x(_Float32x __x) throw(); 
# 75
extern _Float32x tanhf32x(_Float32x __x) throw(); extern _Float32x __tanhf32x(_Float32x __x) throw(); 
# 79
extern void sincosf32x(_Float32x __x, _Float32x * __sinx, _Float32x * __cosx) throw(); extern void __sincosf32x(_Float32x __x, _Float32x * __sinx, _Float32x * __cosx) throw(); 
# 85
extern _Float32x acoshf32x(_Float32x __x) throw(); extern _Float32x __acoshf32x(_Float32x __x) throw(); 
# 87
extern _Float32x asinhf32x(_Float32x __x) throw(); extern _Float32x __asinhf32x(_Float32x __x) throw(); 
# 89
extern _Float32x atanhf32x(_Float32x __x) throw(); extern _Float32x __atanhf32x(_Float32x __x) throw(); 
# 95
extern _Float32x expf32x(_Float32x __x) throw(); extern _Float32x __expf32x(_Float32x __x) throw(); 
# 98
extern _Float32x frexpf32x(_Float32x __x, int * __exponent) throw(); extern _Float32x __frexpf32x(_Float32x __x, int * __exponent) throw(); 
# 101
extern _Float32x ldexpf32x(_Float32x __x, int __exponent) throw(); extern _Float32x __ldexpf32x(_Float32x __x, int __exponent) throw(); 
# 104
extern _Float32x logf32x(_Float32x __x) throw(); extern _Float32x __logf32x(_Float32x __x) throw(); 
# 107
extern _Float32x log10f32x(_Float32x __x) throw(); extern _Float32x __log10f32x(_Float32x __x) throw(); 
# 110
extern _Float32x modff32x(_Float32x __x, _Float32x * __iptr) throw(); extern _Float32x __modff32x(_Float32x __x, _Float32x * __iptr) throw() __attribute((__nonnull__(2))); 
# 114
extern _Float32x exp10f32x(_Float32x __x) throw(); extern _Float32x __exp10f32x(_Float32x __x) throw(); 
# 119
extern _Float32x expm1f32x(_Float32x __x) throw(); extern _Float32x __expm1f32x(_Float32x __x) throw(); 
# 122
extern _Float32x log1pf32x(_Float32x __x) throw(); extern _Float32x __log1pf32x(_Float32x __x) throw(); 
# 125
extern _Float32x logbf32x(_Float32x __x) throw(); extern _Float32x __logbf32x(_Float32x __x) throw(); 
# 130
extern _Float32x exp2f32x(_Float32x __x) throw(); extern _Float32x __exp2f32x(_Float32x __x) throw(); 
# 133
extern _Float32x log2f32x(_Float32x __x) throw(); extern _Float32x __log2f32x(_Float32x __x) throw(); 
# 140
extern _Float32x powf32x(_Float32x __x, _Float32x __y) throw(); extern _Float32x __powf32x(_Float32x __x, _Float32x __y) throw(); 
# 143
extern _Float32x sqrtf32x(_Float32x __x) throw(); extern _Float32x __sqrtf32x(_Float32x __x) throw(); 
# 147
extern _Float32x hypotf32x(_Float32x __x, _Float32x __y) throw(); extern _Float32x __hypotf32x(_Float32x __x, _Float32x __y) throw(); 
# 152
extern _Float32x cbrtf32x(_Float32x __x) throw(); extern _Float32x __cbrtf32x(_Float32x __x) throw(); 
# 159
extern _Float32x ceilf32x(_Float32x __x) throw() __attribute((const)); extern _Float32x __ceilf32x(_Float32x __x) throw() __attribute((const)); 
# 162
extern _Float32x fabsf32x(_Float32x __x) throw() __attribute((const)); extern _Float32x __fabsf32x(_Float32x __x) throw() __attribute((const)); 
# 165
extern _Float32x floorf32x(_Float32x __x) throw() __attribute((const)); extern _Float32x __floorf32x(_Float32x __x) throw() __attribute((const)); 
# 168
extern _Float32x fmodf32x(_Float32x __x, _Float32x __y) throw(); extern _Float32x __fmodf32x(_Float32x __x, _Float32x __y) throw(); 
# 196 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float32x copysignf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); extern _Float32x __copysignf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); 
# 201
extern _Float32x nanf32x(const char * __tagb) throw() __attribute((const)); extern _Float32x __nanf32x(const char * __tagb) throw() __attribute((const)); 
# 217 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float32x j0f32x(_Float32x) throw(); extern _Float32x __j0f32x(_Float32x) throw(); 
# 218
extern _Float32x j1f32x(_Float32x) throw(); extern _Float32x __j1f32x(_Float32x) throw(); 
# 219
extern _Float32x jnf32x(int, _Float32x) throw(); extern _Float32x __jnf32x(int, _Float32x) throw(); 
# 220
extern _Float32x y0f32x(_Float32x) throw(); extern _Float32x __y0f32x(_Float32x) throw(); 
# 221
extern _Float32x y1f32x(_Float32x) throw(); extern _Float32x __y1f32x(_Float32x) throw(); 
# 222
extern _Float32x ynf32x(int, _Float32x) throw(); extern _Float32x __ynf32x(int, _Float32x) throw(); 
# 228
extern _Float32x erff32x(_Float32x) throw(); extern _Float32x __erff32x(_Float32x) throw(); 
# 229
extern _Float32x erfcf32x(_Float32x) throw(); extern _Float32x __erfcf32x(_Float32x) throw(); 
# 230
extern _Float32x lgammaf32x(_Float32x) throw(); extern _Float32x __lgammaf32x(_Float32x) throw(); 
# 235
extern _Float32x tgammaf32x(_Float32x) throw(); extern _Float32x __tgammaf32x(_Float32x) throw(); 
# 249 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float32x lgammaf32x_r(_Float32x, int * __signgamp) throw(); extern _Float32x __lgammaf32x_r(_Float32x, int * __signgamp) throw(); 
# 256
extern _Float32x rintf32x(_Float32x __x) throw(); extern _Float32x __rintf32x(_Float32x __x) throw(); 
# 259
extern _Float32x nextafterf32x(_Float32x __x, _Float32x __y) throw(); extern _Float32x __nextafterf32x(_Float32x __x, _Float32x __y) throw(); 
# 266
extern _Float32x nextdownf32x(_Float32x __x) throw(); extern _Float32x __nextdownf32x(_Float32x __x) throw(); 
# 268
extern _Float32x nextupf32x(_Float32x __x) throw(); extern _Float32x __nextupf32x(_Float32x __x) throw(); 
# 272
extern _Float32x remainderf32x(_Float32x __x, _Float32x __y) throw(); extern _Float32x __remainderf32x(_Float32x __x, _Float32x __y) throw(); 
# 276
extern _Float32x scalbnf32x(_Float32x __x, int __n) throw(); extern _Float32x __scalbnf32x(_Float32x __x, int __n) throw(); 
# 280
extern int ilogbf32x(_Float32x __x) throw(); extern int __ilogbf32x(_Float32x __x) throw(); 
# 285
extern long llogbf32x(_Float32x __x) throw(); extern long __llogbf32x(_Float32x __x) throw(); 
# 290
extern _Float32x scalblnf32x(_Float32x __x, long __n) throw(); extern _Float32x __scalblnf32x(_Float32x __x, long __n) throw(); 
# 294
extern _Float32x nearbyintf32x(_Float32x __x) throw(); extern _Float32x __nearbyintf32x(_Float32x __x) throw(); 
# 298
extern _Float32x roundf32x(_Float32x __x) throw() __attribute((const)); extern _Float32x __roundf32x(_Float32x __x) throw() __attribute((const)); 
# 302
extern _Float32x truncf32x(_Float32x __x) throw() __attribute((const)); extern _Float32x __truncf32x(_Float32x __x) throw() __attribute((const)); 
# 307
extern _Float32x remquof32x(_Float32x __x, _Float32x __y, int * __quo) throw(); extern _Float32x __remquof32x(_Float32x __x, _Float32x __y, int * __quo) throw(); 
# 314
extern long lrintf32x(_Float32x __x) throw(); extern long __lrintf32x(_Float32x __x) throw(); 
# 316
__extension__ extern long long llrintf32x(_Float32x __x) throw(); extern long long __llrintf32x(_Float32x __x) throw(); 
# 320
extern long lroundf32x(_Float32x __x) throw(); extern long __lroundf32x(_Float32x __x) throw(); 
# 322
__extension__ extern long long llroundf32x(_Float32x __x) throw(); extern long long __llroundf32x(_Float32x __x) throw(); 
# 326
extern _Float32x fdimf32x(_Float32x __x, _Float32x __y) throw(); extern _Float32x __fdimf32x(_Float32x __x, _Float32x __y) throw(); 
# 329
extern _Float32x fmaxf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); extern _Float32x __fmaxf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); 
# 332
extern _Float32x fminf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); extern _Float32x __fminf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); 
# 335
extern _Float32x fmaf32x(_Float32x __x, _Float32x __y, _Float32x __z) throw(); extern _Float32x __fmaf32x(_Float32x __x, _Float32x __y, _Float32x __z) throw(); 
# 340
extern _Float32x roundevenf32x(_Float32x __x) throw() __attribute((const)); extern _Float32x __roundevenf32x(_Float32x __x) throw() __attribute((const)); 
# 344
extern __intmax_t fromfpf32x(_Float32x __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpf32x(_Float32x __x, int __round, unsigned __width) throw(); 
# 349
extern __uintmax_t ufromfpf32x(_Float32x __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpf32x(_Float32x __x, int __round, unsigned __width) throw(); 
# 355
extern __intmax_t fromfpxf32x(_Float32x __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpxf32x(_Float32x __x, int __round, unsigned __width) throw(); 
# 361
extern __uintmax_t ufromfpxf32x(_Float32x __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpxf32x(_Float32x __x, int __round, unsigned __width) throw(); 
# 365
extern _Float32x fmaxmagf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); extern _Float32x __fmaxmagf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); 
# 368
extern _Float32x fminmagf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); extern _Float32x __fminmagf32x(_Float32x __x, _Float32x __y) throw() __attribute((const)); 
# 371
extern int totalorderf32x(_Float32x __x, _Float32x __y) throw()
# 372
 __attribute((const)); 
# 375
extern int totalordermagf32x(_Float32x __x, _Float32x __y) throw()
# 376
 __attribute((const)); 
# 379
extern int canonicalizef32x(_Float32x * __cx, const _Float32x * __x) throw(); 
# 382
extern _Float32x getpayloadf32x(const _Float32x * __x) throw(); extern _Float32x __getpayloadf32x(const _Float32x * __x) throw(); 
# 385
extern int setpayloadf32x(_Float32x * __x, _Float32x __payload) throw(); 
# 388
extern int setpayloadsigf32x(_Float32x * __x, _Float32x __payload) throw(); 
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float64x acosf64x(_Float64x __x) throw(); extern _Float64x __acosf64x(_Float64x __x) throw(); 
# 55
extern _Float64x asinf64x(_Float64x __x) throw(); extern _Float64x __asinf64x(_Float64x __x) throw(); 
# 57
extern _Float64x atanf64x(_Float64x __x) throw(); extern _Float64x __atanf64x(_Float64x __x) throw(); 
# 59
extern _Float64x atan2f64x(_Float64x __y, _Float64x __x) throw(); extern _Float64x __atan2f64x(_Float64x __y, _Float64x __x) throw(); 
# 62
extern _Float64x cosf64x(_Float64x __x) throw(); extern _Float64x __cosf64x(_Float64x __x) throw(); 
# 64
extern _Float64x sinf64x(_Float64x __x) throw(); extern _Float64x __sinf64x(_Float64x __x) throw(); 
# 66
extern _Float64x tanf64x(_Float64x __x) throw(); extern _Float64x __tanf64x(_Float64x __x) throw(); 
# 71
extern _Float64x coshf64x(_Float64x __x) throw(); extern _Float64x __coshf64x(_Float64x __x) throw(); 
# 73
extern _Float64x sinhf64x(_Float64x __x) throw(); extern _Float64x __sinhf64x(_Float64x __x) throw(); 
# 75
extern _Float64x tanhf64x(_Float64x __x) throw(); extern _Float64x __tanhf64x(_Float64x __x) throw(); 
# 79
extern void sincosf64x(_Float64x __x, _Float64x * __sinx, _Float64x * __cosx) throw(); extern void __sincosf64x(_Float64x __x, _Float64x * __sinx, _Float64x * __cosx) throw(); 
# 85
extern _Float64x acoshf64x(_Float64x __x) throw(); extern _Float64x __acoshf64x(_Float64x __x) throw(); 
# 87
extern _Float64x asinhf64x(_Float64x __x) throw(); extern _Float64x __asinhf64x(_Float64x __x) throw(); 
# 89
extern _Float64x atanhf64x(_Float64x __x) throw(); extern _Float64x __atanhf64x(_Float64x __x) throw(); 
# 95
extern _Float64x expf64x(_Float64x __x) throw(); extern _Float64x __expf64x(_Float64x __x) throw(); 
# 98
extern _Float64x frexpf64x(_Float64x __x, int * __exponent) throw(); extern _Float64x __frexpf64x(_Float64x __x, int * __exponent) throw(); 
# 101
extern _Float64x ldexpf64x(_Float64x __x, int __exponent) throw(); extern _Float64x __ldexpf64x(_Float64x __x, int __exponent) throw(); 
# 104
extern _Float64x logf64x(_Float64x __x) throw(); extern _Float64x __logf64x(_Float64x __x) throw(); 
# 107
extern _Float64x log10f64x(_Float64x __x) throw(); extern _Float64x __log10f64x(_Float64x __x) throw(); 
# 110
extern _Float64x modff64x(_Float64x __x, _Float64x * __iptr) throw(); extern _Float64x __modff64x(_Float64x __x, _Float64x * __iptr) throw() __attribute((__nonnull__(2))); 
# 114
extern _Float64x exp10f64x(_Float64x __x) throw(); extern _Float64x __exp10f64x(_Float64x __x) throw(); 
# 119
extern _Float64x expm1f64x(_Float64x __x) throw(); extern _Float64x __expm1f64x(_Float64x __x) throw(); 
# 122
extern _Float64x log1pf64x(_Float64x __x) throw(); extern _Float64x __log1pf64x(_Float64x __x) throw(); 
# 125
extern _Float64x logbf64x(_Float64x __x) throw(); extern _Float64x __logbf64x(_Float64x __x) throw(); 
# 130
extern _Float64x exp2f64x(_Float64x __x) throw(); extern _Float64x __exp2f64x(_Float64x __x) throw(); 
# 133
extern _Float64x log2f64x(_Float64x __x) throw(); extern _Float64x __log2f64x(_Float64x __x) throw(); 
# 140
extern _Float64x powf64x(_Float64x __x, _Float64x __y) throw(); extern _Float64x __powf64x(_Float64x __x, _Float64x __y) throw(); 
# 143
extern _Float64x sqrtf64x(_Float64x __x) throw(); extern _Float64x __sqrtf64x(_Float64x __x) throw(); 
# 147
extern _Float64x hypotf64x(_Float64x __x, _Float64x __y) throw(); extern _Float64x __hypotf64x(_Float64x __x, _Float64x __y) throw(); 
# 152
extern _Float64x cbrtf64x(_Float64x __x) throw(); extern _Float64x __cbrtf64x(_Float64x __x) throw(); 
# 159
extern _Float64x ceilf64x(_Float64x __x) throw() __attribute((const)); extern _Float64x __ceilf64x(_Float64x __x) throw() __attribute((const)); 
# 162
extern _Float64x fabsf64x(_Float64x __x) throw() __attribute((const)); extern _Float64x __fabsf64x(_Float64x __x) throw() __attribute((const)); 
# 165
extern _Float64x floorf64x(_Float64x __x) throw() __attribute((const)); extern _Float64x __floorf64x(_Float64x __x) throw() __attribute((const)); 
# 168
extern _Float64x fmodf64x(_Float64x __x, _Float64x __y) throw(); extern _Float64x __fmodf64x(_Float64x __x, _Float64x __y) throw(); 
# 196 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float64x copysignf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); extern _Float64x __copysignf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); 
# 201
extern _Float64x nanf64x(const char * __tagb) throw() __attribute((const)); extern _Float64x __nanf64x(const char * __tagb) throw() __attribute((const)); 
# 217 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float64x j0f64x(_Float64x) throw(); extern _Float64x __j0f64x(_Float64x) throw(); 
# 218
extern _Float64x j1f64x(_Float64x) throw(); extern _Float64x __j1f64x(_Float64x) throw(); 
# 219
extern _Float64x jnf64x(int, _Float64x) throw(); extern _Float64x __jnf64x(int, _Float64x) throw(); 
# 220
extern _Float64x y0f64x(_Float64x) throw(); extern _Float64x __y0f64x(_Float64x) throw(); 
# 221
extern _Float64x y1f64x(_Float64x) throw(); extern _Float64x __y1f64x(_Float64x) throw(); 
# 222
extern _Float64x ynf64x(int, _Float64x) throw(); extern _Float64x __ynf64x(int, _Float64x) throw(); 
# 228
extern _Float64x erff64x(_Float64x) throw(); extern _Float64x __erff64x(_Float64x) throw(); 
# 229
extern _Float64x erfcf64x(_Float64x) throw(); extern _Float64x __erfcf64x(_Float64x) throw(); 
# 230
extern _Float64x lgammaf64x(_Float64x) throw(); extern _Float64x __lgammaf64x(_Float64x) throw(); 
# 235
extern _Float64x tgammaf64x(_Float64x) throw(); extern _Float64x __tgammaf64x(_Float64x) throw(); 
# 249 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3
extern _Float64x lgammaf64x_r(_Float64x, int * __signgamp) throw(); extern _Float64x __lgammaf64x_r(_Float64x, int * __signgamp) throw(); 
# 256
extern _Float64x rintf64x(_Float64x __x) throw(); extern _Float64x __rintf64x(_Float64x __x) throw(); 
# 259
extern _Float64x nextafterf64x(_Float64x __x, _Float64x __y) throw(); extern _Float64x __nextafterf64x(_Float64x __x, _Float64x __y) throw(); 
# 266
extern _Float64x nextdownf64x(_Float64x __x) throw(); extern _Float64x __nextdownf64x(_Float64x __x) throw(); 
# 268
extern _Float64x nextupf64x(_Float64x __x) throw(); extern _Float64x __nextupf64x(_Float64x __x) throw(); 
# 272
extern _Float64x remainderf64x(_Float64x __x, _Float64x __y) throw(); extern _Float64x __remainderf64x(_Float64x __x, _Float64x __y) throw(); 
# 276
extern _Float64x scalbnf64x(_Float64x __x, int __n) throw(); extern _Float64x __scalbnf64x(_Float64x __x, int __n) throw(); 
# 280
extern int ilogbf64x(_Float64x __x) throw(); extern int __ilogbf64x(_Float64x __x) throw(); 
# 285
extern long llogbf64x(_Float64x __x) throw(); extern long __llogbf64x(_Float64x __x) throw(); 
# 290
extern _Float64x scalblnf64x(_Float64x __x, long __n) throw(); extern _Float64x __scalblnf64x(_Float64x __x, long __n) throw(); 
# 294
extern _Float64x nearbyintf64x(_Float64x __x) throw(); extern _Float64x __nearbyintf64x(_Float64x __x) throw(); 
# 298
extern _Float64x roundf64x(_Float64x __x) throw() __attribute((const)); extern _Float64x __roundf64x(_Float64x __x) throw() __attribute((const)); 
# 302
extern _Float64x truncf64x(_Float64x __x) throw() __attribute((const)); extern _Float64x __truncf64x(_Float64x __x) throw() __attribute((const)); 
# 307
extern _Float64x remquof64x(_Float64x __x, _Float64x __y, int * __quo) throw(); extern _Float64x __remquof64x(_Float64x __x, _Float64x __y, int * __quo) throw(); 
# 314
extern long lrintf64x(_Float64x __x) throw(); extern long __lrintf64x(_Float64x __x) throw(); 
# 316
__extension__ extern long long llrintf64x(_Float64x __x) throw(); extern long long __llrintf64x(_Float64x __x) throw(); 
# 320
extern long lroundf64x(_Float64x __x) throw(); extern long __lroundf64x(_Float64x __x) throw(); 
# 322
__extension__ extern long long llroundf64x(_Float64x __x) throw(); extern long long __llroundf64x(_Float64x __x) throw(); 
# 326
extern _Float64x fdimf64x(_Float64x __x, _Float64x __y) throw(); extern _Float64x __fdimf64x(_Float64x __x, _Float64x __y) throw(); 
# 329
extern _Float64x fmaxf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); extern _Float64x __fmaxf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); 
# 332
extern _Float64x fminf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); extern _Float64x __fminf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); 
# 335
extern _Float64x fmaf64x(_Float64x __x, _Float64x __y, _Float64x __z) throw(); extern _Float64x __fmaf64x(_Float64x __x, _Float64x __y, _Float64x __z) throw(); 
# 340
extern _Float64x roundevenf64x(_Float64x __x) throw() __attribute((const)); extern _Float64x __roundevenf64x(_Float64x __x) throw() __attribute((const)); 
# 344
extern __intmax_t fromfpf64x(_Float64x __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpf64x(_Float64x __x, int __round, unsigned __width) throw(); 
# 349
extern __uintmax_t ufromfpf64x(_Float64x __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpf64x(_Float64x __x, int __round, unsigned __width) throw(); 
# 355
extern __intmax_t fromfpxf64x(_Float64x __x, int __round, unsigned __width) throw(); extern __intmax_t __fromfpxf64x(_Float64x __x, int __round, unsigned __width) throw(); 
# 361
extern __uintmax_t ufromfpxf64x(_Float64x __x, int __round, unsigned __width) throw(); extern __uintmax_t __ufromfpxf64x(_Float64x __x, int __round, unsigned __width) throw(); 
# 365
extern _Float64x fmaxmagf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); extern _Float64x __fmaxmagf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); 
# 368
extern _Float64x fminmagf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); extern _Float64x __fminmagf64x(_Float64x __x, _Float64x __y) throw() __attribute((const)); 
# 371
extern int totalorderf64x(_Float64x __x, _Float64x __y) throw()
# 372
 __attribute((const)); 
# 375
extern int totalordermagf64x(_Float64x __x, _Float64x __y) throw()
# 376
 __attribute((const)); 
# 379
extern int canonicalizef64x(_Float64x * __cx, const _Float64x * __x) throw(); 
# 382
extern _Float64x getpayloadf64x(const _Float64x * __x) throw(); extern _Float64x __getpayloadf64x(const _Float64x * __x) throw(); 
# 385
extern int setpayloadf64x(_Float64x * __x, _Float64x __payload) throw(); 
# 388
extern int setpayloadsigf64x(_Float64x * __x, _Float64x __payload) throw(); 
# 489 "/usr/include/math.h" 3
extern int signgam; 
# 570 "/usr/include/math.h" 3
enum { 
# 571
FP_NAN, 
# 574
FP_INFINITE, 
# 577
FP_ZERO, 
# 580
FP_SUBNORMAL, 
# 583
FP_NORMAL
# 586
}; 
# 23 "/usr/include/x86_64-linux-gnu/bits/iscanonical.h" 3
extern int __iscanonicall(long double __x) throw()
# 24
 __attribute((const)); 
# 46 "/usr/include/x86_64-linux-gnu/bits/iscanonical.h" 3
extern "C++" {
# 47
inline int iscanonical(float __val) { return (((void)((__typeof__(__val))__val)), 1); } 
# 48
inline int iscanonical(double __val) { return (((void)((__typeof__(__val))__val)), 1); } 
# 49
inline int iscanonical(long double __val) { return __iscanonicall(__val); } 
# 53
}
# 696 "/usr/include/math.h" 3
extern "C++" {
# 697
inline int issignaling(float __val) { return __issignalingf(__val); } 
# 698
inline int issignaling(double __val) { return __issignaling(__val); } 
# 700
inline int issignaling(long double __val) 
# 701
{ 
# 705
return __issignalingl(__val); 
# 707
} 
# 711
}
# 725 "/usr/include/math.h" 3
extern "C++" {
# 754 "/usr/include/math.h" 3
template< class __T> inline bool 
# 755
iszero(__T __val) 
# 756
{ 
# 757
return __val == 0; 
# 758
} 
# 760
}
# 1205 "/usr/include/math.h" 3
extern "C++" {
# 1206
template< class > struct __iseqsig_type; 
# 1208
template<> struct __iseqsig_type< float>  { 
# 1210
static int __call(float __x, float __y) throw() 
# 1211
{ 
# 1212
return __iseqsigf(__x, __y); 
# 1213
} 
# 1214
}; 
# 1216
template<> struct __iseqsig_type< double>  { 
# 1218
static int __call(double __x, double __y) throw() 
# 1219
{ 
# 1220
return __iseqsig(__x, __y); 
# 1221
} 
# 1222
}; 
# 1224
template<> struct __iseqsig_type< long double>  { 
# 1226
static int __call(long double __x, long double __y) throw() 
# 1227
{ 
# 1229
return __iseqsigl(__x, __y); 
# 1233
} 
# 1234
}; 
# 1246 "/usr/include/math.h" 3
template< class _T1, class _T2> inline int 
# 1248
iseqsig(_T1 __x, _T2 __y) throw() 
# 1249
{ 
# 1251
typedef __decltype(((__x + __y) + (0.0F))) _T3; 
# 1255
return __iseqsig_type< __decltype(((__x + __y) + (0.0F)))> ::__call(__x, __y); 
# 1256
} 
# 1258
}
# 1263
}
# 33 "/usr/include/stdlib.h" 3
extern "C" {
# 57 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 3
typedef 
# 53
enum { 
# 54
P_ALL, 
# 55
P_PID, 
# 56
P_PGID
# 57
} idtype_t; 
# 62 "/usr/include/stdlib.h" 3
typedef 
# 59
struct { 
# 60
int quot; 
# 61
int rem; 
# 62
} div_t; 
# 70
typedef 
# 67
struct { 
# 68
long quot; 
# 69
long rem; 
# 70
} ldiv_t; 
# 80
__extension__ typedef 
# 77
struct { 
# 78
long long quot; 
# 79
long long rem; 
# 80
} lldiv_t; 
# 97 "/usr/include/stdlib.h" 3
extern size_t __ctype_get_mb_cur_max() throw(); 
# 101
extern double atof(const char * __nptr) throw()
# 102
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 104
extern int atoi(const char * __nptr) throw()
# 105
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 107
extern long atol(const char * __nptr) throw()
# 108
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 112
__extension__ extern long long atoll(const char * __nptr) throw()
# 113
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 117
extern double strtod(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 119
 __attribute((__nonnull__(1))); 
# 123
extern float strtof(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 124
 __attribute((__nonnull__(1))); 
# 126
extern long double strtold(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 128
 __attribute((__nonnull__(1))); 
# 140 "/usr/include/stdlib.h" 3
extern _Float32 strtof32(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 142
 __attribute((__nonnull__(1))); 
# 146
extern _Float64 strtof64(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 148
 __attribute((__nonnull__(1))); 
# 158 "/usr/include/stdlib.h" 3
extern _Float32x strtof32x(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 160
 __attribute((__nonnull__(1))); 
# 164
extern _Float64x strtof64x(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 166
 __attribute((__nonnull__(1))); 
# 176 "/usr/include/stdlib.h" 3
extern long strtol(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 178
 __attribute((__nonnull__(1))); 
# 180
extern unsigned long strtoul(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 182
 __attribute((__nonnull__(1))); 
# 187
__extension__ extern long long strtoq(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 189
 __attribute((__nonnull__(1))); 
# 192
__extension__ extern unsigned long long strtouq(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 194
 __attribute((__nonnull__(1))); 
# 200
__extension__ extern long long strtoll(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 202
 __attribute((__nonnull__(1))); 
# 205
__extension__ extern unsigned long long strtoull(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 207
 __attribute((__nonnull__(1))); 
# 212
extern int strfromd(char * __dest, size_t __size, const char * __format, double __f) throw()
# 214
 __attribute((__nonnull__(3))); 
# 216
extern int strfromf(char * __dest, size_t __size, const char * __format, float __f) throw()
# 218
 __attribute((__nonnull__(3))); 
# 220
extern int strfroml(char * __dest, size_t __size, const char * __format, long double __f) throw()
# 222
 __attribute((__nonnull__(3))); 
# 232 "/usr/include/stdlib.h" 3
extern int strfromf32(char * __dest, size_t __size, const char * __format, _Float32 __f) throw()
# 234
 __attribute((__nonnull__(3))); 
# 238
extern int strfromf64(char * __dest, size_t __size, const char * __format, _Float64 __f) throw()
# 240
 __attribute((__nonnull__(3))); 
# 250 "/usr/include/stdlib.h" 3
extern int strfromf32x(char * __dest, size_t __size, const char * __format, _Float32x __f) throw()
# 252
 __attribute((__nonnull__(3))); 
# 256
extern int strfromf64x(char * __dest, size_t __size, const char * __format, _Float64x __f) throw()
# 258
 __attribute((__nonnull__(3))); 
# 274 "/usr/include/stdlib.h" 3
extern long strtol_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base, locale_t __loc) throw()
# 276
 __attribute((__nonnull__(1, 4))); 
# 278
extern unsigned long strtoul_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base, locale_t __loc) throw()
# 281
 __attribute((__nonnull__(1, 4))); 
# 284
__extension__ extern long long strtoll_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base, locale_t __loc) throw()
# 287
 __attribute((__nonnull__(1, 4))); 
# 290
__extension__ extern unsigned long long strtoull_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base, locale_t __loc) throw()
# 293
 __attribute((__nonnull__(1, 4))); 
# 295
extern double strtod_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, locale_t __loc) throw()
# 297
 __attribute((__nonnull__(1, 3))); 
# 299
extern float strtof_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, locale_t __loc) throw()
# 301
 __attribute((__nonnull__(1, 3))); 
# 303
extern long double strtold_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, locale_t __loc) throw()
# 306
 __attribute((__nonnull__(1, 3))); 
# 316 "/usr/include/stdlib.h" 3
extern _Float32 strtof32_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, locale_t __loc) throw()
# 319
 __attribute((__nonnull__(1, 3))); 
# 323
extern _Float64 strtof64_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, locale_t __loc) throw()
# 326
 __attribute((__nonnull__(1, 3))); 
# 337 "/usr/include/stdlib.h" 3
extern _Float32x strtof32x_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, locale_t __loc) throw()
# 340
 __attribute((__nonnull__(1, 3))); 
# 344
extern _Float64x strtof64x_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, locale_t __loc) throw()
# 347
 __attribute((__nonnull__(1, 3))); 
# 385 "/usr/include/stdlib.h" 3
extern char *l64a(long __n) throw(); 
# 388
extern long a64l(const char * __s) throw()
# 389
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 27 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
extern "C" {
# 33
typedef __u_char u_char; 
# 34
typedef __u_short u_short; 
# 35
typedef __u_int u_int; 
# 36
typedef __u_long u_long; 
# 37
typedef __quad_t quad_t; 
# 38
typedef __u_quad_t u_quad_t; 
# 39
typedef __fsid_t fsid_t; 
# 44
typedef __loff_t loff_t; 
# 48
typedef __ino_t ino_t; 
# 55
typedef __ino64_t ino64_t; 
# 60
typedef __dev_t dev_t; 
# 65
typedef __gid_t gid_t; 
# 70
typedef __mode_t mode_t; 
# 75
typedef __nlink_t nlink_t; 
# 80
typedef __uid_t uid_t; 
# 86
typedef __off_t off_t; 
# 93
typedef __off64_t off64_t; 
# 104 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
typedef __id_t id_t; 
# 109
typedef __ssize_t ssize_t; 
# 115
typedef __daddr_t daddr_t; 
# 116
typedef __caddr_t caddr_t; 
# 122
typedef __key_t key_t; 
# 135 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
typedef __useconds_t useconds_t; 
# 139
typedef __suseconds_t suseconds_t; 
# 149 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
typedef unsigned long ulong; 
# 150
typedef unsigned short ushort; 
# 151
typedef unsigned uint; 
# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3
typedef __int8_t int8_t; 
# 25
typedef __int16_t int16_t; 
# 26
typedef __int32_t int32_t; 
# 27
typedef __int64_t int64_t; 
# 178 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
typedef unsigned char u_int8_t __attribute((__mode__(__QI__))); 
# 179
typedef unsigned short u_int16_t __attribute((__mode__(__HI__))); 
# 180
typedef unsigned u_int32_t __attribute((__mode__(__SI__))); 
# 181
typedef unsigned long u_int64_t __attribute((__mode__(__DI__))); 
# 183
typedef long register_t __attribute((__mode__(__word__))); 
# 45 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3
static inline unsigned __bswap_32(unsigned __bsx) 
# 46
{ 
# 47
return __builtin_bswap32(__bsx); 
# 48
} 
# 109 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3
static inline __uint64_t __bswap_64(__uint64_t __bsx) 
# 110
{ 
# 111
return __builtin_bswap64(__bsx); 
# 112
} 
# 33 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 3
static inline __uint16_t __uint16_identity(__uint16_t __x) 
# 34
{ 
# 35
return __x; 
# 36
} 
# 39
static inline __uint32_t __uint32_identity(__uint32_t __x) 
# 40
{ 
# 41
return __x; 
# 42
} 
# 45
static inline __uint64_t __uint64_identity(__uint64_t __x) 
# 46
{ 
# 47
return __x; 
# 48
} 
# 8 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 3
typedef 
# 6
struct { 
# 7
unsigned long __val[(1024) / ((8) * sizeof(unsigned long))]; 
# 8
} __sigset_t; 
# 7 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 3
typedef __sigset_t sigset_t; 
# 49 "/usr/include/x86_64-linux-gnu/sys/select.h" 3
typedef long __fd_mask; 
# 70 "/usr/include/x86_64-linux-gnu/sys/select.h" 3
typedef 
# 60
struct { 
# 64
__fd_mask fds_bits[1024 / (8 * ((int)sizeof(__fd_mask)))]; 
# 70
} fd_set; 
# 77
typedef __fd_mask fd_mask; 
# 91 "/usr/include/x86_64-linux-gnu/sys/select.h" 3
extern "C" {
# 101 "/usr/include/x86_64-linux-gnu/sys/select.h" 3
extern int select(int __nfds, fd_set *__restrict__ __readfds, fd_set *__restrict__ __writefds, fd_set *__restrict__ __exceptfds, timeval *__restrict__ __timeout); 
# 113 "/usr/include/x86_64-linux-gnu/sys/select.h" 3
extern int pselect(int __nfds, fd_set *__restrict__ __readfds, fd_set *__restrict__ __writefds, fd_set *__restrict__ __exceptfds, const timespec *__restrict__ __timeout, const __sigset_t *__restrict__ __sigmask); 
# 126 "/usr/include/x86_64-linux-gnu/sys/select.h" 3
}
# 71 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3
extern "C" {
# 73
extern unsigned gnu_dev_major(__dev_t __dev) throw() __attribute((const)); 
# 74
extern unsigned gnu_dev_minor(__dev_t __dev) throw() __attribute((const)); 
# 75
extern __dev_t gnu_dev_makedev(unsigned __major, unsigned __minor) throw() __attribute((const)); 
# 85 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3
}
# 212 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
typedef __blksize_t blksize_t; 
# 219
typedef __blkcnt_t blkcnt_t; 
# 223
typedef __fsblkcnt_t fsblkcnt_t; 
# 227
typedef __fsfilcnt_t fsfilcnt_t; 
# 246 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
typedef __blkcnt64_t blkcnt64_t; 
# 247
typedef __fsblkcnt64_t fsblkcnt64_t; 
# 248
typedef __fsfilcnt64_t fsfilcnt64_t; 
# 65 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 3
struct __pthread_rwlock_arch_t { 
# 67
unsigned __readers; 
# 68
unsigned __writers; 
# 69
unsigned __wrphase_futex; 
# 70
unsigned __writers_futex; 
# 71
unsigned __pad3; 
# 72
unsigned __pad4; 
# 74
int __cur_writer; 
# 75
int __shared; 
# 76
signed char __rwelision; 
# 81
unsigned char __pad1[7]; 
# 84
unsigned long __pad2; 
# 87
unsigned __flags; 
# 99 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 3
}; 
# 86 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3
typedef 
# 82
struct __pthread_internal_list { 
# 84
__pthread_internal_list *__prev; 
# 85
__pthread_internal_list *__next; 
# 86
} __pthread_list_t; 
# 118 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3
struct __pthread_mutex_s { 
# 120
int __lock; 
# 121
unsigned __count; 
# 122
int __owner; 
# 124
unsigned __nusers; 
# 148 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3
int __kind; 
# 154
short __spins; short __elision; 
# 155
__pthread_list_t __list; 
# 166 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3
}; 
# 171
struct __pthread_cond_s { 
# 174
__extension__ union { 
# 175
__extension__ unsigned long long __wseq; 
# 177
struct { 
# 178
unsigned __low; 
# 179
unsigned __high; 
# 180
} __wseq32; 
# 181
}; 
# 183
__extension__ union { 
# 184
__extension__ unsigned long long __g1_start; 
# 186
struct { 
# 187
unsigned __low; 
# 188
unsigned __high; 
# 189
} __g1_start32; 
# 190
}; 
# 191
unsigned __g_refs[2]; 
# 192
unsigned __g_size[2]; 
# 193
unsigned __g1_orig_size; 
# 194
unsigned __wrefs; 
# 195
unsigned __g_signals[2]; 
# 196
}; 
# 27 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3
typedef unsigned long pthread_t; 
# 36
typedef 
# 33
union { 
# 34
char __size[4]; 
# 35
int __align; 
# 36
} pthread_mutexattr_t; 
# 45
typedef 
# 42
union { 
# 43
char __size[4]; 
# 44
int __align; 
# 45
} pthread_condattr_t; 
# 49
typedef unsigned pthread_key_t; 
# 53
typedef int pthread_once_t; 
# 56
union pthread_attr_t { 
# 58
char __size[56]; 
# 59
long __align; 
# 60
}; 
# 62
typedef pthread_attr_t pthread_attr_t; 
# 72
typedef 
# 68
union { 
# 69
__pthread_mutex_s __data; 
# 70
char __size[40]; 
# 71
long __align; 
# 72
} pthread_mutex_t; 
# 80
typedef 
# 76
union { 
# 77
__pthread_cond_s __data; 
# 78
char __size[48]; 
# 79
__extension__ long long __align; 
# 80
} pthread_cond_t; 
# 91
typedef 
# 87
union { 
# 88
__pthread_rwlock_arch_t __data; 
# 89
char __size[56]; 
# 90
long __align; 
# 91
} pthread_rwlock_t; 
# 97
typedef 
# 94
union { 
# 95
char __size[8]; 
# 96
long __align; 
# 97
} pthread_rwlockattr_t; 
# 103
typedef volatile int pthread_spinlock_t; 
# 112
typedef 
# 109
union { 
# 110
char __size[32]; 
# 111
long __align; 
# 112
} pthread_barrier_t; 
# 118
typedef 
# 115
union { 
# 116
char __size[4]; 
# 117
int __align; 
# 118
} pthread_barrierattr_t; 
# 257 "/usr/include/x86_64-linux-gnu/sys/types.h" 3
}
# 401 "/usr/include/stdlib.h" 3
extern long random() throw(); 
# 404
extern void srandom(unsigned __seed) throw(); 
# 410
extern char *initstate(unsigned __seed, char * __statebuf, size_t __statelen) throw()
# 411
 __attribute((__nonnull__(2))); 
# 415
extern char *setstate(char * __statebuf) throw() __attribute((__nonnull__(1))); 
# 423
struct random_data { 
# 425
int32_t *fptr; 
# 426
int32_t *rptr; 
# 427
int32_t *state; 
# 428
int rand_type; 
# 429
int rand_deg; 
# 430
int rand_sep; 
# 431
int32_t *end_ptr; 
# 432
}; 
# 434
extern int random_r(random_data *__restrict__ __buf, int32_t *__restrict__ __result) throw()
# 435
 __attribute((__nonnull__(1, 2))); 
# 437
extern int srandom_r(unsigned __seed, random_data * __buf) throw()
# 438
 __attribute((__nonnull__(2))); 
# 440
extern int initstate_r(unsigned __seed, char *__restrict__ __statebuf, size_t __statelen, random_data *__restrict__ __buf) throw()
# 443
 __attribute((__nonnull__(2, 4))); 
# 445
extern int setstate_r(char *__restrict__ __statebuf, random_data *__restrict__ __buf) throw()
# 447
 __attribute((__nonnull__(1, 2))); 
# 453
extern int rand() throw(); 
# 455
extern void srand(unsigned __seed) throw(); 
# 459
extern int rand_r(unsigned * __seed) throw(); 
# 467
extern double drand48() throw(); 
# 468
extern double erand48(unsigned short  __xsubi[3]) throw() __attribute((__nonnull__(1))); 
# 471
extern long lrand48() throw(); 
# 472
extern long nrand48(unsigned short  __xsubi[3]) throw()
# 473
 __attribute((__nonnull__(1))); 
# 476
extern long mrand48() throw(); 
# 477
extern long jrand48(unsigned short  __xsubi[3]) throw()
# 478
 __attribute((__nonnull__(1))); 
# 481
extern void srand48(long __seedval) throw(); 
# 482
extern unsigned short *seed48(unsigned short  __seed16v[3]) throw()
# 483
 __attribute((__nonnull__(1))); 
# 484
extern void lcong48(unsigned short  __param[7]) throw() __attribute((__nonnull__(1))); 
# 490
struct drand48_data { 
# 492
unsigned short __x[3]; 
# 493
unsigned short __old_x[3]; 
# 494
unsigned short __c; 
# 495
unsigned short __init; 
# 496
__extension__ unsigned long long __a; 
# 498
}; 
# 501
extern int drand48_r(drand48_data *__restrict__ __buffer, double *__restrict__ __result) throw()
# 502
 __attribute((__nonnull__(1, 2))); 
# 503
extern int erand48_r(unsigned short  __xsubi[3], drand48_data *__restrict__ __buffer, double *__restrict__ __result) throw()
# 505
 __attribute((__nonnull__(1, 2))); 
# 508
extern int lrand48_r(drand48_data *__restrict__ __buffer, long *__restrict__ __result) throw()
# 510
 __attribute((__nonnull__(1, 2))); 
# 511
extern int nrand48_r(unsigned short  __xsubi[3], drand48_data *__restrict__ __buffer, long *__restrict__ __result) throw()
# 514
 __attribute((__nonnull__(1, 2))); 
# 517
extern int mrand48_r(drand48_data *__restrict__ __buffer, long *__restrict__ __result) throw()
# 519
 __attribute((__nonnull__(1, 2))); 
# 520
extern int jrand48_r(unsigned short  __xsubi[3], drand48_data *__restrict__ __buffer, long *__restrict__ __result) throw()
# 523
 __attribute((__nonnull__(1, 2))); 
# 526
extern int srand48_r(long __seedval, drand48_data * __buffer) throw()
# 527
 __attribute((__nonnull__(2))); 
# 529
extern int seed48_r(unsigned short  __seed16v[3], drand48_data * __buffer) throw()
# 530
 __attribute((__nonnull__(1, 2))); 
# 532
extern int lcong48_r(unsigned short  __param[7], drand48_data * __buffer) throw()
# 534
 __attribute((__nonnull__(1, 2))); 
# 539
extern void *malloc(size_t __size) throw() __attribute((__malloc__)); 
# 541
extern void *calloc(size_t __nmemb, size_t __size) throw()
# 542
 __attribute((__malloc__)); 
# 549
extern void *realloc(void * __ptr, size_t __size) throw()
# 550
 __attribute((__warn_unused_result__)); 
# 558
extern void *reallocarray(void * __ptr, size_t __nmemb, size_t __size) throw()
# 559
 __attribute((__warn_unused_result__)); 
# 563
extern void free(void * __ptr) throw(); 
# 26 "/usr/include/alloca.h" 3
extern "C" {
# 32
extern void *alloca(size_t __size) throw(); 
# 38
}
# 572 "/usr/include/stdlib.h" 3
extern void *valloc(size_t __size) throw() __attribute((__malloc__)); 
# 577
extern int posix_memalign(void ** __memptr, size_t __alignment, size_t __size) throw()
# 578
 __attribute((__nonnull__(1))); 
# 583
extern void *aligned_alloc(size_t __alignment, size_t __size) throw()
# 584
 __attribute((__malloc__)) __attribute((__alloc_size__(2))); 
# 588
extern void abort() throw() __attribute((__noreturn__)); 
# 592
extern int atexit(void (* __func)(void)) throw() __attribute((__nonnull__(1))); 
# 597
extern "C++" int at_quick_exit(void (* __func)(void)) throw() __asm__("at_quick_exit")
# 598
 __attribute((__nonnull__(1))); 
# 607 "/usr/include/stdlib.h" 3
extern int on_exit(void (* __func)(int __status, void * __arg), void * __arg) throw()
# 608
 __attribute((__nonnull__(1))); 
# 614
extern void exit(int __status) throw() __attribute((__noreturn__)); 
# 620
extern void quick_exit(int __status) throw() __attribute((__noreturn__)); 
# 626
extern void _Exit(int __status) throw() __attribute((__noreturn__)); 
# 631
extern char *getenv(const char * __name) throw() __attribute((__nonnull__(1))); 
# 636
extern char *secure_getenv(const char * __name) throw()
# 637
 __attribute((__nonnull__(1))); 
# 644
extern int putenv(char * __string) throw() __attribute((__nonnull__(1))); 
# 650
extern int setenv(const char * __name, const char * __value, int __replace) throw()
# 651
 __attribute((__nonnull__(2))); 
# 654
extern int unsetenv(const char * __name) throw() __attribute((__nonnull__(1))); 
# 661
extern int clearenv() throw(); 
# 672 "/usr/include/stdlib.h" 3
extern char *mktemp(char * __template) throw() __attribute((__nonnull__(1))); 
# 685 "/usr/include/stdlib.h" 3
extern int mkstemp(char * __template) __attribute((__nonnull__(1))); 
# 695 "/usr/include/stdlib.h" 3
extern int mkstemp64(char * __template) __attribute((__nonnull__(1))); 
# 707 "/usr/include/stdlib.h" 3
extern int mkstemps(char * __template, int __suffixlen) __attribute((__nonnull__(1))); 
# 717 "/usr/include/stdlib.h" 3
extern int mkstemps64(char * __template, int __suffixlen)
# 718
 __attribute((__nonnull__(1))); 
# 728 "/usr/include/stdlib.h" 3
extern char *mkdtemp(char * __template) throw() __attribute((__nonnull__(1))); 
# 739 "/usr/include/stdlib.h" 3
extern int mkostemp(char * __template, int __flags) __attribute((__nonnull__(1))); 
# 749 "/usr/include/stdlib.h" 3
extern int mkostemp64(char * __template, int __flags) __attribute((__nonnull__(1))); 
# 759 "/usr/include/stdlib.h" 3
extern int mkostemps(char * __template, int __suffixlen, int __flags)
# 760
 __attribute((__nonnull__(1))); 
# 771 "/usr/include/stdlib.h" 3
extern int mkostemps64(char * __template, int __suffixlen, int __flags)
# 772
 __attribute((__nonnull__(1))); 
# 781 "/usr/include/stdlib.h" 3
extern int system(const char * __command); 
# 787
extern char *canonicalize_file_name(const char * __name) throw()
# 788
 __attribute((__nonnull__(1))); 
# 797 "/usr/include/stdlib.h" 3
extern char *realpath(const char *__restrict__ __name, char *__restrict__ __resolved) throw(); 
# 805
typedef int (*__compar_fn_t)(const void *, const void *); 
# 808
typedef __compar_fn_t comparison_fn_t; 
# 812
typedef int (*__compar_d_fn_t)(const void *, const void *, void *); 
# 817
extern void *bsearch(const void * __key, const void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar)
# 819
 __attribute((__nonnull__(1, 2, 5))); 
# 827
extern void qsort(void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar)
# 828
 __attribute((__nonnull__(1, 4))); 
# 830
extern void qsort_r(void * __base, size_t __nmemb, size_t __size, __compar_d_fn_t __compar, void * __arg)
# 832
 __attribute((__nonnull__(1, 4))); 
# 837
extern int abs(int __x) throw() __attribute((const)); 
# 838
extern long labs(long __x) throw() __attribute((const)); 
# 841
__extension__ extern long long llabs(long long __x) throw()
# 842
 __attribute((const)); 
# 849
extern div_t div(int __numer, int __denom) throw()
# 850
 __attribute((const)); 
# 851
extern ldiv_t ldiv(long __numer, long __denom) throw()
# 852
 __attribute((const)); 
# 855
__extension__ extern lldiv_t lldiv(long long __numer, long long __denom) throw()
# 857
 __attribute((const)); 
# 869 "/usr/include/stdlib.h" 3
extern char *ecvt(double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign) throw()
# 870
 __attribute((__nonnull__(3, 4))); 
# 875
extern char *fcvt(double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign) throw()
# 876
 __attribute((__nonnull__(3, 4))); 
# 881
extern char *gcvt(double __value, int __ndigit, char * __buf) throw()
# 882
 __attribute((__nonnull__(3))); 
# 887
extern char *qecvt(long double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign) throw()
# 889
 __attribute((__nonnull__(3, 4))); 
# 890
extern char *qfcvt(long double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign) throw()
# 892
 __attribute((__nonnull__(3, 4))); 
# 893
extern char *qgcvt(long double __value, int __ndigit, char * __buf) throw()
# 894
 __attribute((__nonnull__(3))); 
# 899
extern int ecvt_r(double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign, char *__restrict__ __buf, size_t __len) throw()
# 901
 __attribute((__nonnull__(3, 4, 5))); 
# 902
extern int fcvt_r(double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign, char *__restrict__ __buf, size_t __len) throw()
# 904
 __attribute((__nonnull__(3, 4, 5))); 
# 906
extern int qecvt_r(long double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign, char *__restrict__ __buf, size_t __len) throw()
# 909
 __attribute((__nonnull__(3, 4, 5))); 
# 910
extern int qfcvt_r(long double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign, char *__restrict__ __buf, size_t __len) throw()
# 913
 __attribute((__nonnull__(3, 4, 5))); 
# 919
extern int mblen(const char * __s, size_t __n) throw(); 
# 922
extern int mbtowc(wchar_t *__restrict__ __pwc, const char *__restrict__ __s, size_t __n) throw(); 
# 926
extern int wctomb(char * __s, wchar_t __wchar) throw(); 
# 930
extern size_t mbstowcs(wchar_t *__restrict__ __pwcs, const char *__restrict__ __s, size_t __n) throw(); 
# 933
extern size_t wcstombs(char *__restrict__ __s, const wchar_t *__restrict__ __pwcs, size_t __n) throw(); 
# 943
extern int rpmatch(const char * __response) throw() __attribute((__nonnull__(1))); 
# 954 "/usr/include/stdlib.h" 3
extern int getsubopt(char **__restrict__ __optionp, char *const *__restrict__ __tokens, char **__restrict__ __valuep) throw()
# 957
 __attribute((__nonnull__(1, 2, 3))); 
# 963
extern void setkey(const char * __key) throw() __attribute((__nonnull__(1))); 
# 971
extern int posix_openpt(int __oflag); 
# 979
extern int grantpt(int __fd) throw(); 
# 983
extern int unlockpt(int __fd) throw(); 
# 988
extern char *ptsname(int __fd) throw(); 
# 995
extern int ptsname_r(int __fd, char * __buf, size_t __buflen) throw()
# 996
 __attribute((__nonnull__(2))); 
# 999
extern int getpt(); 
# 1006
extern int getloadavg(double  __loadavg[], int __nelem) throw()
# 1007
 __attribute((__nonnull__(1))); 
# 1026 "/usr/include/stdlib.h" 3
}
# 46 "/usr/include/c++/7/bits/std_abs.h" 3
extern "C++" {
# 48
namespace std __attribute((__visibility__("default"))) { 
# 52
using ::abs;
# 56
inline long abs(long __i) { return __builtin_labs(__i); } 
# 61
inline long long abs(long long __x) { return __builtin_llabs(__x); } 
# 70
constexpr double abs(double __x) 
# 71
{ return __builtin_fabs(__x); } 
# 74
constexpr float abs(float __x) 
# 75
{ return __builtin_fabsf(__x); } 
# 78
constexpr long double abs(long double __x) 
# 79
{ return __builtin_fabsl(__x); } 
# 84
constexpr __int128_t abs(__int128_t __x) { return (__x >= (0)) ? __x : (-__x); } 
# 107 "/usr/include/c++/7/bits/std_abs.h" 3
}
# 108
}
# 77 "/usr/include/c++/7/cmath" 3
extern "C++" {
# 79
namespace std __attribute((__visibility__("default"))) { 
# 83
using ::acos;
# 87
constexpr float acos(float __x) 
# 88
{ return __builtin_acosf(__x); } 
# 91
constexpr long double acos(long double __x) 
# 92
{ return __builtin_acosl(__x); } 
# 95
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 99
acos(_Tp __x) 
# 100
{ return __builtin_acos(__x); } 
# 102
using ::asin;
# 106
constexpr float asin(float __x) 
# 107
{ return __builtin_asinf(__x); } 
# 110
constexpr long double asin(long double __x) 
# 111
{ return __builtin_asinl(__x); } 
# 114
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 118
asin(_Tp __x) 
# 119
{ return __builtin_asin(__x); } 
# 121
using ::atan;
# 125
constexpr float atan(float __x) 
# 126
{ return __builtin_atanf(__x); } 
# 129
constexpr long double atan(long double __x) 
# 130
{ return __builtin_atanl(__x); } 
# 133
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 137
atan(_Tp __x) 
# 138
{ return __builtin_atan(__x); } 
# 140
using ::atan2;
# 144
constexpr float atan2(float __y, float __x) 
# 145
{ return __builtin_atan2f(__y, __x); } 
# 148
constexpr long double atan2(long double __y, long double __x) 
# 149
{ return __builtin_atan2l(__y, __x); } 
# 152
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 155
atan2(_Tp __y, _Up __x) 
# 156
{ 
# 157
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 158
return atan2((__type)__y, (__type)__x); 
# 159
} 
# 161
using ::ceil;
# 165
constexpr float ceil(float __x) 
# 166
{ return __builtin_ceilf(__x); } 
# 169
constexpr long double ceil(long double __x) 
# 170
{ return __builtin_ceill(__x); } 
# 173
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 177
ceil(_Tp __x) 
# 178
{ return __builtin_ceil(__x); } 
# 180
using ::cos;
# 184
constexpr float cos(float __x) 
# 185
{ return __builtin_cosf(__x); } 
# 188
constexpr long double cos(long double __x) 
# 189
{ return __builtin_cosl(__x); } 
# 192
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 196
cos(_Tp __x) 
# 197
{ return __builtin_cos(__x); } 
# 199
using ::cosh;
# 203
constexpr float cosh(float __x) 
# 204
{ return __builtin_coshf(__x); } 
# 207
constexpr long double cosh(long double __x) 
# 208
{ return __builtin_coshl(__x); } 
# 211
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 215
cosh(_Tp __x) 
# 216
{ return __builtin_cosh(__x); } 
# 218
using ::exp;
# 222
constexpr float exp(float __x) 
# 223
{ return __builtin_expf(__x); } 
# 226
constexpr long double exp(long double __x) 
# 227
{ return __builtin_expl(__x); } 
# 230
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 234
exp(_Tp __x) 
# 235
{ return __builtin_exp(__x); } 
# 237
using ::fabs;
# 241
constexpr float fabs(float __x) 
# 242
{ return __builtin_fabsf(__x); } 
# 245
constexpr long double fabs(long double __x) 
# 246
{ return __builtin_fabsl(__x); } 
# 249
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 253
fabs(_Tp __x) 
# 254
{ return __builtin_fabs(__x); } 
# 256
using ::floor;
# 260
constexpr float floor(float __x) 
# 261
{ return __builtin_floorf(__x); } 
# 264
constexpr long double floor(long double __x) 
# 265
{ return __builtin_floorl(__x); } 
# 268
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 272
floor(_Tp __x) 
# 273
{ return __builtin_floor(__x); } 
# 275
using ::fmod;
# 279
constexpr float fmod(float __x, float __y) 
# 280
{ return __builtin_fmodf(__x, __y); } 
# 283
constexpr long double fmod(long double __x, long double __y) 
# 284
{ return __builtin_fmodl(__x, __y); } 
# 287
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 290
fmod(_Tp __x, _Up __y) 
# 291
{ 
# 292
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 293
return fmod((__type)__x, (__type)__y); 
# 294
} 
# 296
using ::frexp;
# 300
inline float frexp(float __x, int *__exp) 
# 301
{ return __builtin_frexpf(__x, __exp); } 
# 304
inline long double frexp(long double __x, int *__exp) 
# 305
{ return __builtin_frexpl(__x, __exp); } 
# 308
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 312
frexp(_Tp __x, int *__exp) 
# 313
{ return __builtin_frexp(__x, __exp); } 
# 315
using ::ldexp;
# 319
constexpr float ldexp(float __x, int __exp) 
# 320
{ return __builtin_ldexpf(__x, __exp); } 
# 323
constexpr long double ldexp(long double __x, int __exp) 
# 324
{ return __builtin_ldexpl(__x, __exp); } 
# 327
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 331
ldexp(_Tp __x, int __exp) 
# 332
{ return __builtin_ldexp(__x, __exp); } 
# 334
using ::log;
# 338
constexpr float log(float __x) 
# 339
{ return __builtin_logf(__x); } 
# 342
constexpr long double log(long double __x) 
# 343
{ return __builtin_logl(__x); } 
# 346
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 350
log(_Tp __x) 
# 351
{ return __builtin_log(__x); } 
# 353
using ::log10;
# 357
constexpr float log10(float __x) 
# 358
{ return __builtin_log10f(__x); } 
# 361
constexpr long double log10(long double __x) 
# 362
{ return __builtin_log10l(__x); } 
# 365
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 369
log10(_Tp __x) 
# 370
{ return __builtin_log10(__x); } 
# 372
using ::modf;
# 376
inline float modf(float __x, float *__iptr) 
# 377
{ return __builtin_modff(__x, __iptr); } 
# 380
inline long double modf(long double __x, long double *__iptr) 
# 381
{ return __builtin_modfl(__x, __iptr); } 
# 384
using ::pow;
# 388
constexpr float pow(float __x, float __y) 
# 389
{ return __builtin_powf(__x, __y); } 
# 392
constexpr long double pow(long double __x, long double __y) 
# 393
{ return __builtin_powl(__x, __y); } 
# 412 "/usr/include/c++/7/cmath" 3
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 415
pow(_Tp __x, _Up __y) 
# 416
{ 
# 417
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 418
return pow((__type)__x, (__type)__y); 
# 419
} 
# 421
using ::sin;
# 425
constexpr float sin(float __x) 
# 426
{ return __builtin_sinf(__x); } 
# 429
constexpr long double sin(long double __x) 
# 430
{ return __builtin_sinl(__x); } 
# 433
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 437
sin(_Tp __x) 
# 438
{ return __builtin_sin(__x); } 
# 440
using ::sinh;
# 444
constexpr float sinh(float __x) 
# 445
{ return __builtin_sinhf(__x); } 
# 448
constexpr long double sinh(long double __x) 
# 449
{ return __builtin_sinhl(__x); } 
# 452
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 456
sinh(_Tp __x) 
# 457
{ return __builtin_sinh(__x); } 
# 459
using ::sqrt;
# 463
constexpr float sqrt(float __x) 
# 464
{ return __builtin_sqrtf(__x); } 
# 467
constexpr long double sqrt(long double __x) 
# 468
{ return __builtin_sqrtl(__x); } 
# 471
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 475
sqrt(_Tp __x) 
# 476
{ return __builtin_sqrt(__x); } 
# 478
using ::tan;
# 482
constexpr float tan(float __x) 
# 483
{ return __builtin_tanf(__x); } 
# 486
constexpr long double tan(long double __x) 
# 487
{ return __builtin_tanl(__x); } 
# 490
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 494
tan(_Tp __x) 
# 495
{ return __builtin_tan(__x); } 
# 497
using ::tanh;
# 501
constexpr float tanh(float __x) 
# 502
{ return __builtin_tanhf(__x); } 
# 505
constexpr long double tanh(long double __x) 
# 506
{ return __builtin_tanhl(__x); } 
# 509
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 513
tanh(_Tp __x) 
# 514
{ return __builtin_tanh(__x); } 
# 517
}
# 536 "/usr/include/c++/7/cmath" 3
namespace std __attribute((__visibility__("default"))) { 
# 544
constexpr int fpclassify(float __x) 
# 545
{ return __builtin_fpclassify(0, 1, 4, 3, 2, __x); 
# 546
} 
# 549
constexpr int fpclassify(double __x) 
# 550
{ return __builtin_fpclassify(0, 1, 4, 3, 2, __x); 
# 551
} 
# 554
constexpr int fpclassify(long double __x) 
# 555
{ return __builtin_fpclassify(0, 1, 4, 3, 2, __x); 
# 556
} 
# 560
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, int> ::__type 
# 563
fpclassify(_Tp __x) 
# 564
{ return (__x != 0) ? 4 : 2; } 
# 569
constexpr bool isfinite(float __x) 
# 570
{ return __builtin_isfinite(__x); } 
# 573
constexpr bool isfinite(double __x) 
# 574
{ return __builtin_isfinite(__x); } 
# 577
constexpr bool isfinite(long double __x) 
# 578
{ return __builtin_isfinite(__x); } 
# 582
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, bool> ::__type 
# 585
isfinite(_Tp __x) 
# 586
{ return true; } 
# 591
constexpr bool isinf(float __x) 
# 592
{ return __builtin_isinf(__x); } 
# 599
constexpr bool isinf(double __x) 
# 600
{ return __builtin_isinf(__x); } 
# 604
constexpr bool isinf(long double __x) 
# 605
{ return __builtin_isinf(__x); } 
# 609
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, bool> ::__type 
# 612
isinf(_Tp __x) 
# 613
{ return false; } 
# 618
constexpr bool isnan(float __x) 
# 619
{ return __builtin_isnan(__x); } 
# 626
constexpr bool isnan(double __x) 
# 627
{ return __builtin_isnan(__x); } 
# 631
constexpr bool isnan(long double __x) 
# 632
{ return __builtin_isnan(__x); } 
# 636
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, bool> ::__type 
# 639
isnan(_Tp __x) 
# 640
{ return false; } 
# 645
constexpr bool isnormal(float __x) 
# 646
{ return __builtin_isnormal(__x); } 
# 649
constexpr bool isnormal(double __x) 
# 650
{ return __builtin_isnormal(__x); } 
# 653
constexpr bool isnormal(long double __x) 
# 654
{ return __builtin_isnormal(__x); } 
# 658
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, bool> ::__type 
# 661
isnormal(_Tp __x) 
# 662
{ return (__x != 0) ? true : false; } 
# 668
constexpr bool signbit(float __x) 
# 669
{ return __builtin_signbit(__x); } 
# 672
constexpr bool signbit(double __x) 
# 673
{ return __builtin_signbit(__x); } 
# 676
constexpr bool signbit(long double __x) 
# 677
{ return __builtin_signbit(__x); } 
# 681
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, bool> ::__type 
# 684
signbit(_Tp __x) 
# 685
{ return (__x < 0) ? true : false; } 
# 690
constexpr bool isgreater(float __x, float __y) 
# 691
{ return __builtin_isgreater(__x, __y); } 
# 694
constexpr bool isgreater(double __x, double __y) 
# 695
{ return __builtin_isgreater(__x, __y); } 
# 698
constexpr bool isgreater(long double __x, long double __y) 
# 699
{ return __builtin_isgreater(__x, __y); } 
# 703
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value && __is_arithmetic< _Up> ::__value, bool> ::__type 
# 707
isgreater(_Tp __x, _Up __y) 
# 708
{ 
# 709
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 710
return __builtin_isgreater((__type)__x, (__type)__y); 
# 711
} 
# 716
constexpr bool isgreaterequal(float __x, float __y) 
# 717
{ return __builtin_isgreaterequal(__x, __y); } 
# 720
constexpr bool isgreaterequal(double __x, double __y) 
# 721
{ return __builtin_isgreaterequal(__x, __y); } 
# 724
constexpr bool isgreaterequal(long double __x, long double __y) 
# 725
{ return __builtin_isgreaterequal(__x, __y); } 
# 729
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value && __is_arithmetic< _Up> ::__value, bool> ::__type 
# 733
isgreaterequal(_Tp __x, _Up __y) 
# 734
{ 
# 735
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 736
return __builtin_isgreaterequal((__type)__x, (__type)__y); 
# 737
} 
# 742
constexpr bool isless(float __x, float __y) 
# 743
{ return __builtin_isless(__x, __y); } 
# 746
constexpr bool isless(double __x, double __y) 
# 747
{ return __builtin_isless(__x, __y); } 
# 750
constexpr bool isless(long double __x, long double __y) 
# 751
{ return __builtin_isless(__x, __y); } 
# 755
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value && __is_arithmetic< _Up> ::__value, bool> ::__type 
# 759
isless(_Tp __x, _Up __y) 
# 760
{ 
# 761
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 762
return __builtin_isless((__type)__x, (__type)__y); 
# 763
} 
# 768
constexpr bool islessequal(float __x, float __y) 
# 769
{ return __builtin_islessequal(__x, __y); } 
# 772
constexpr bool islessequal(double __x, double __y) 
# 773
{ return __builtin_islessequal(__x, __y); } 
# 776
constexpr bool islessequal(long double __x, long double __y) 
# 777
{ return __builtin_islessequal(__x, __y); } 
# 781
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value && __is_arithmetic< _Up> ::__value, bool> ::__type 
# 785
islessequal(_Tp __x, _Up __y) 
# 786
{ 
# 787
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 788
return __builtin_islessequal((__type)__x, (__type)__y); 
# 789
} 
# 794
constexpr bool islessgreater(float __x, float __y) 
# 795
{ return __builtin_islessgreater(__x, __y); } 
# 798
constexpr bool islessgreater(double __x, double __y) 
# 799
{ return __builtin_islessgreater(__x, __y); } 
# 802
constexpr bool islessgreater(long double __x, long double __y) 
# 803
{ return __builtin_islessgreater(__x, __y); } 
# 807
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value && __is_arithmetic< _Up> ::__value, bool> ::__type 
# 811
islessgreater(_Tp __x, _Up __y) 
# 812
{ 
# 813
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 814
return __builtin_islessgreater((__type)__x, (__type)__y); 
# 815
} 
# 820
constexpr bool isunordered(float __x, float __y) 
# 821
{ return __builtin_isunordered(__x, __y); } 
# 824
constexpr bool isunordered(double __x, double __y) 
# 825
{ return __builtin_isunordered(__x, __y); } 
# 828
constexpr bool isunordered(long double __x, long double __y) 
# 829
{ return __builtin_isunordered(__x, __y); } 
# 833
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value && __is_arithmetic< _Up> ::__value, bool> ::__type 
# 837
isunordered(_Tp __x, _Up __y) 
# 838
{ 
# 839
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 840
return __builtin_isunordered((__type)__x, (__type)__y); 
# 841
} 
# 958 "/usr/include/c++/7/cmath" 3
}
# 1075 "/usr/include/c++/7/cmath" 3
namespace std __attribute((__visibility__("default"))) { 
# 1080
using ::double_t;
# 1081
using ::float_t;
# 1084
using ::acosh;
# 1085
using ::acoshf;
# 1086
using ::acoshl;
# 1088
using ::asinh;
# 1089
using ::asinhf;
# 1090
using ::asinhl;
# 1092
using ::atanh;
# 1093
using ::atanhf;
# 1094
using ::atanhl;
# 1096
using ::cbrt;
# 1097
using ::cbrtf;
# 1098
using ::cbrtl;
# 1100
using ::copysign;
# 1101
using ::copysignf;
# 1102
using ::copysignl;
# 1104
using ::erf;
# 1105
using ::erff;
# 1106
using ::erfl;
# 1108
using ::erfc;
# 1109
using ::erfcf;
# 1110
using ::erfcl;
# 1112
using ::exp2;
# 1113
using ::exp2f;
# 1114
using ::exp2l;
# 1116
using ::expm1;
# 1117
using ::expm1f;
# 1118
using ::expm1l;
# 1120
using ::fdim;
# 1121
using ::fdimf;
# 1122
using ::fdiml;
# 1124
using ::fma;
# 1125
using ::fmaf;
# 1126
using ::fmal;
# 1128
using ::fmax;
# 1129
using ::fmaxf;
# 1130
using ::fmaxl;
# 1132
using ::fmin;
# 1133
using ::fminf;
# 1134
using ::fminl;
# 1136
using ::hypot;
# 1137
using ::hypotf;
# 1138
using ::hypotl;
# 1140
using ::ilogb;
# 1141
using ::ilogbf;
# 1142
using ::ilogbl;
# 1144
using ::lgamma;
# 1145
using ::lgammaf;
# 1146
using ::lgammal;
# 1149
using ::llrint;
# 1150
using ::llrintf;
# 1151
using ::llrintl;
# 1153
using ::llround;
# 1154
using ::llroundf;
# 1155
using ::llroundl;
# 1158
using ::log1p;
# 1159
using ::log1pf;
# 1160
using ::log1pl;
# 1162
using ::log2;
# 1163
using ::log2f;
# 1164
using ::log2l;
# 1166
using ::logb;
# 1167
using ::logbf;
# 1168
using ::logbl;
# 1170
using ::lrint;
# 1171
using ::lrintf;
# 1172
using ::lrintl;
# 1174
using ::lround;
# 1175
using ::lroundf;
# 1176
using ::lroundl;
# 1178
using ::nan;
# 1179
using ::nanf;
# 1180
using ::nanl;
# 1182
using ::nearbyint;
# 1183
using ::nearbyintf;
# 1184
using ::nearbyintl;
# 1186
using ::nextafter;
# 1187
using ::nextafterf;
# 1188
using ::nextafterl;
# 1190
using ::nexttoward;
# 1191
using ::nexttowardf;
# 1192
using ::nexttowardl;
# 1194
using ::remainder;
# 1195
using ::remainderf;
# 1196
using ::remainderl;
# 1198
using ::remquo;
# 1199
using ::remquof;
# 1200
using ::remquol;
# 1202
using ::rint;
# 1203
using ::rintf;
# 1204
using ::rintl;
# 1206
using ::round;
# 1207
using ::roundf;
# 1208
using ::roundl;
# 1210
using ::scalbln;
# 1211
using ::scalblnf;
# 1212
using ::scalblnl;
# 1214
using ::scalbn;
# 1215
using ::scalbnf;
# 1216
using ::scalbnl;
# 1218
using ::tgamma;
# 1219
using ::tgammaf;
# 1220
using ::tgammal;
# 1222
using ::trunc;
# 1223
using ::truncf;
# 1224
using ::truncl;
# 1229
constexpr float acosh(float __x) 
# 1230
{ return __builtin_acoshf(__x); } 
# 1233
constexpr long double acosh(long double __x) 
# 1234
{ return __builtin_acoshl(__x); } 
# 1238
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1241
acosh(_Tp __x) 
# 1242
{ return __builtin_acosh(__x); } 
# 1247
constexpr float asinh(float __x) 
# 1248
{ return __builtin_asinhf(__x); } 
# 1251
constexpr long double asinh(long double __x) 
# 1252
{ return __builtin_asinhl(__x); } 
# 1256
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1259
asinh(_Tp __x) 
# 1260
{ return __builtin_asinh(__x); } 
# 1265
constexpr float atanh(float __x) 
# 1266
{ return __builtin_atanhf(__x); } 
# 1269
constexpr long double atanh(long double __x) 
# 1270
{ return __builtin_atanhl(__x); } 
# 1274
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1277
atanh(_Tp __x) 
# 1278
{ return __builtin_atanh(__x); } 
# 1283
constexpr float cbrt(float __x) 
# 1284
{ return __builtin_cbrtf(__x); } 
# 1287
constexpr long double cbrt(long double __x) 
# 1288
{ return __builtin_cbrtl(__x); } 
# 1292
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1295
cbrt(_Tp __x) 
# 1296
{ return __builtin_cbrt(__x); } 
# 1301
constexpr float copysign(float __x, float __y) 
# 1302
{ return __builtin_copysignf(__x, __y); } 
# 1305
constexpr long double copysign(long double __x, long double __y) 
# 1306
{ return __builtin_copysignl(__x, __y); } 
# 1310
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 1312
copysign(_Tp __x, _Up __y) 
# 1313
{ 
# 1314
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 1315
return copysign((__type)__x, (__type)__y); 
# 1316
} 
# 1321
constexpr float erf(float __x) 
# 1322
{ return __builtin_erff(__x); } 
# 1325
constexpr long double erf(long double __x) 
# 1326
{ return __builtin_erfl(__x); } 
# 1330
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1333
erf(_Tp __x) 
# 1334
{ return __builtin_erf(__x); } 
# 1339
constexpr float erfc(float __x) 
# 1340
{ return __builtin_erfcf(__x); } 
# 1343
constexpr long double erfc(long double __x) 
# 1344
{ return __builtin_erfcl(__x); } 
# 1348
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1351
erfc(_Tp __x) 
# 1352
{ return __builtin_erfc(__x); } 
# 1357
constexpr float exp2(float __x) 
# 1358
{ return __builtin_exp2f(__x); } 
# 1361
constexpr long double exp2(long double __x) 
# 1362
{ return __builtin_exp2l(__x); } 
# 1366
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1369
exp2(_Tp __x) 
# 1370
{ return __builtin_exp2(__x); } 
# 1375
constexpr float expm1(float __x) 
# 1376
{ return __builtin_expm1f(__x); } 
# 1379
constexpr long double expm1(long double __x) 
# 1380
{ return __builtin_expm1l(__x); } 
# 1384
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1387
expm1(_Tp __x) 
# 1388
{ return __builtin_expm1(__x); } 
# 1393
constexpr float fdim(float __x, float __y) 
# 1394
{ return __builtin_fdimf(__x, __y); } 
# 1397
constexpr long double fdim(long double __x, long double __y) 
# 1398
{ return __builtin_fdiml(__x, __y); } 
# 1402
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 1404
fdim(_Tp __x, _Up __y) 
# 1405
{ 
# 1406
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 1407
return fdim((__type)__x, (__type)__y); 
# 1408
} 
# 1413
constexpr float fma(float __x, float __y, float __z) 
# 1414
{ return __builtin_fmaf(__x, __y, __z); } 
# 1417
constexpr long double fma(long double __x, long double __y, long double __z) 
# 1418
{ return __builtin_fmal(__x, __y, __z); } 
# 1422
template< class _Tp, class _Up, class _Vp> constexpr typename __gnu_cxx::__promote_3< _Tp, _Up, _Vp> ::__type 
# 1424
fma(_Tp __x, _Up __y, _Vp __z) 
# 1425
{ 
# 1426
typedef typename __gnu_cxx::__promote_3< _Tp, _Up, _Vp> ::__type __type; 
# 1427
return fma((__type)__x, (__type)__y, (__type)__z); 
# 1428
} 
# 1433
constexpr float fmax(float __x, float __y) 
# 1434
{ return __builtin_fmaxf(__x, __y); } 
# 1437
constexpr long double fmax(long double __x, long double __y) 
# 1438
{ return __builtin_fmaxl(__x, __y); } 
# 1442
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 1444
fmax(_Tp __x, _Up __y) 
# 1445
{ 
# 1446
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 1447
return fmax((__type)__x, (__type)__y); 
# 1448
} 
# 1453
constexpr float fmin(float __x, float __y) 
# 1454
{ return __builtin_fminf(__x, __y); } 
# 1457
constexpr long double fmin(long double __x, long double __y) 
# 1458
{ return __builtin_fminl(__x, __y); } 
# 1462
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 1464
fmin(_Tp __x, _Up __y) 
# 1465
{ 
# 1466
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 1467
return fmin((__type)__x, (__type)__y); 
# 1468
} 
# 1473
constexpr float hypot(float __x, float __y) 
# 1474
{ return __builtin_hypotf(__x, __y); } 
# 1477
constexpr long double hypot(long double __x, long double __y) 
# 1478
{ return __builtin_hypotl(__x, __y); } 
# 1482
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 1484
hypot(_Tp __x, _Up __y) 
# 1485
{ 
# 1486
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 1487
return hypot((__type)__x, (__type)__y); 
# 1488
} 
# 1493
constexpr int ilogb(float __x) 
# 1494
{ return __builtin_ilogbf(__x); } 
# 1497
constexpr int ilogb(long double __x) 
# 1498
{ return __builtin_ilogbl(__x); } 
# 1502
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, int> ::__type 
# 1506
ilogb(_Tp __x) 
# 1507
{ return __builtin_ilogb(__x); } 
# 1512
constexpr float lgamma(float __x) 
# 1513
{ return __builtin_lgammaf(__x); } 
# 1516
constexpr long double lgamma(long double __x) 
# 1517
{ return __builtin_lgammal(__x); } 
# 1521
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1524
lgamma(_Tp __x) 
# 1525
{ return __builtin_lgamma(__x); } 
# 1530
constexpr long long llrint(float __x) 
# 1531
{ return __builtin_llrintf(__x); } 
# 1534
constexpr long long llrint(long double __x) 
# 1535
{ return __builtin_llrintl(__x); } 
# 1539
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, long long> ::__type 
# 1542
llrint(_Tp __x) 
# 1543
{ return __builtin_llrint(__x); } 
# 1548
constexpr long long llround(float __x) 
# 1549
{ return __builtin_llroundf(__x); } 
# 1552
constexpr long long llround(long double __x) 
# 1553
{ return __builtin_llroundl(__x); } 
# 1557
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, long long> ::__type 
# 1560
llround(_Tp __x) 
# 1561
{ return __builtin_llround(__x); } 
# 1566
constexpr float log1p(float __x) 
# 1567
{ return __builtin_log1pf(__x); } 
# 1570
constexpr long double log1p(long double __x) 
# 1571
{ return __builtin_log1pl(__x); } 
# 1575
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1578
log1p(_Tp __x) 
# 1579
{ return __builtin_log1p(__x); } 
# 1585
constexpr float log2(float __x) 
# 1586
{ return __builtin_log2f(__x); } 
# 1589
constexpr long double log2(long double __x) 
# 1590
{ return __builtin_log2l(__x); } 
# 1594
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1597
log2(_Tp __x) 
# 1598
{ return __builtin_log2(__x); } 
# 1603
constexpr float logb(float __x) 
# 1604
{ return __builtin_logbf(__x); } 
# 1607
constexpr long double logb(long double __x) 
# 1608
{ return __builtin_logbl(__x); } 
# 1612
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1615
logb(_Tp __x) 
# 1616
{ return __builtin_logb(__x); } 
# 1621
constexpr long lrint(float __x) 
# 1622
{ return __builtin_lrintf(__x); } 
# 1625
constexpr long lrint(long double __x) 
# 1626
{ return __builtin_lrintl(__x); } 
# 1630
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, long> ::__type 
# 1633
lrint(_Tp __x) 
# 1634
{ return __builtin_lrint(__x); } 
# 1639
constexpr long lround(float __x) 
# 1640
{ return __builtin_lroundf(__x); } 
# 1643
constexpr long lround(long double __x) 
# 1644
{ return __builtin_lroundl(__x); } 
# 1648
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, long> ::__type 
# 1651
lround(_Tp __x) 
# 1652
{ return __builtin_lround(__x); } 
# 1657
constexpr float nearbyint(float __x) 
# 1658
{ return __builtin_nearbyintf(__x); } 
# 1661
constexpr long double nearbyint(long double __x) 
# 1662
{ return __builtin_nearbyintl(__x); } 
# 1666
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1669
nearbyint(_Tp __x) 
# 1670
{ return __builtin_nearbyint(__x); } 
# 1675
constexpr float nextafter(float __x, float __y) 
# 1676
{ return __builtin_nextafterf(__x, __y); } 
# 1679
constexpr long double nextafter(long double __x, long double __y) 
# 1680
{ return __builtin_nextafterl(__x, __y); } 
# 1684
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 1686
nextafter(_Tp __x, _Up __y) 
# 1687
{ 
# 1688
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 1689
return nextafter((__type)__x, (__type)__y); 
# 1690
} 
# 1695
constexpr float nexttoward(float __x, long double __y) 
# 1696
{ return __builtin_nexttowardf(__x, __y); } 
# 1699
constexpr long double nexttoward(long double __x, long double __y) 
# 1700
{ return __builtin_nexttowardl(__x, __y); } 
# 1704
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1707
nexttoward(_Tp __x, long double __y) 
# 1708
{ return __builtin_nexttoward(__x, __y); } 
# 1713
constexpr float remainder(float __x, float __y) 
# 1714
{ return __builtin_remainderf(__x, __y); } 
# 1717
constexpr long double remainder(long double __x, long double __y) 
# 1718
{ return __builtin_remainderl(__x, __y); } 
# 1722
template< class _Tp, class _Up> constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 1724
remainder(_Tp __x, _Up __y) 
# 1725
{ 
# 1726
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 1727
return remainder((__type)__x, (__type)__y); 
# 1728
} 
# 1733
inline float remquo(float __x, float __y, int *__pquo) 
# 1734
{ return __builtin_remquof(__x, __y, __pquo); } 
# 1737
inline long double remquo(long double __x, long double __y, int *__pquo) 
# 1738
{ return __builtin_remquol(__x, __y, __pquo); } 
# 1742
template< class _Tp, class _Up> inline typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 1744
remquo(_Tp __x, _Up __y, int *__pquo) 
# 1745
{ 
# 1746
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 1747
return remquo((__type)__x, (__type)__y, __pquo); 
# 1748
} 
# 1753
constexpr float rint(float __x) 
# 1754
{ return __builtin_rintf(__x); } 
# 1757
constexpr long double rint(long double __x) 
# 1758
{ return __builtin_rintl(__x); } 
# 1762
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1765
rint(_Tp __x) 
# 1766
{ return __builtin_rint(__x); } 
# 1771
constexpr float round(float __x) 
# 1772
{ return __builtin_roundf(__x); } 
# 1775
constexpr long double round(long double __x) 
# 1776
{ return __builtin_roundl(__x); } 
# 1780
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1783
round(_Tp __x) 
# 1784
{ return __builtin_round(__x); } 
# 1789
constexpr float scalbln(float __x, long __ex) 
# 1790
{ return __builtin_scalblnf(__x, __ex); } 
# 1793
constexpr long double scalbln(long double __x, long __ex) 
# 1794
{ return __builtin_scalblnl(__x, __ex); } 
# 1798
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1801
scalbln(_Tp __x, long __ex) 
# 1802
{ return __builtin_scalbln(__x, __ex); } 
# 1807
constexpr float scalbn(float __x, int __ex) 
# 1808
{ return __builtin_scalbnf(__x, __ex); } 
# 1811
constexpr long double scalbn(long double __x, int __ex) 
# 1812
{ return __builtin_scalbnl(__x, __ex); } 
# 1816
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1819
scalbn(_Tp __x, int __ex) 
# 1820
{ return __builtin_scalbn(__x, __ex); } 
# 1825
constexpr float tgamma(float __x) 
# 1826
{ return __builtin_tgammaf(__x); } 
# 1829
constexpr long double tgamma(long double __x) 
# 1830
{ return __builtin_tgammal(__x); } 
# 1834
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1837
tgamma(_Tp __x) 
# 1838
{ return __builtin_tgamma(__x); } 
# 1843
constexpr float trunc(float __x) 
# 1844
{ return __builtin_truncf(__x); } 
# 1847
constexpr long double trunc(long double __x) 
# 1848
{ return __builtin_truncl(__x); } 
# 1852
template< class _Tp> constexpr typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 1855
trunc(_Tp __x) 
# 1856
{ return __builtin_trunc(__x); } 
# 1860
}
# 1917 "/usr/include/c++/7/cmath" 3
}
# 38 "/usr/include/c++/7/math.h" 3
using std::abs;
# 39
using std::acos;
# 40
using std::asin;
# 41
using std::atan;
# 42
using std::atan2;
# 43
using std::cos;
# 44
using std::sin;
# 45
using std::tan;
# 46
using std::cosh;
# 47
using std::sinh;
# 48
using std::tanh;
# 49
using std::exp;
# 50
using std::frexp;
# 51
using std::ldexp;
# 52
using std::log;
# 53
using std::log10;
# 54
using std::modf;
# 55
using std::pow;
# 56
using std::sqrt;
# 57
using std::ceil;
# 58
using std::fabs;
# 59
using std::floor;
# 60
using std::fmod;
# 63
using std::fpclassify;
# 64
using std::isfinite;
# 65
using std::isinf;
# 66
using std::isnan;
# 67
using std::isnormal;
# 68
using std::signbit;
# 69
using std::isgreater;
# 70
using std::isgreaterequal;
# 71
using std::isless;
# 72
using std::islessequal;
# 73
using std::islessgreater;
# 74
using std::isunordered;
# 78
using std::acosh;
# 79
using std::asinh;
# 80
using std::atanh;
# 81
using std::cbrt;
# 82
using std::copysign;
# 83
using std::erf;
# 84
using std::erfc;
# 85
using std::exp2;
# 86
using std::expm1;
# 87
using std::fdim;
# 88
using std::fma;
# 89
using std::fmax;
# 90
using std::fmin;
# 91
using std::hypot;
# 92
using std::ilogb;
# 93
using std::lgamma;
# 94
using std::llrint;
# 95
using std::llround;
# 96
using std::log1p;
# 97
using std::log2;
# 98
using std::logb;
# 99
using std::lrint;
# 100
using std::lround;
# 101
using std::nearbyint;
# 102
using std::nextafter;
# 103
using std::nexttoward;
# 104
using std::remainder;
# 105
using std::remquo;
# 106
using std::rint;
# 107
using std::round;
# 108
using std::scalbln;
# 109
using std::scalbn;
# 110
using std::tgamma;
# 111
using std::trunc;
# 121 "/usr/include/c++/7/cstdlib" 3
extern "C++" {
# 123
namespace std __attribute((__visibility__("default"))) { 
# 127
using ::div_t;
# 128
using ::ldiv_t;
# 130
using ::abort;
# 134
using ::atexit;
# 137
using ::at_quick_exit;
# 140
using ::atof;
# 141
using ::atoi;
# 142
using ::atol;
# 143
using ::bsearch;
# 144
using ::calloc;
# 145
using ::div;
# 146
using ::exit;
# 147
using ::free;
# 148
using ::getenv;
# 149
using ::labs;
# 150
using ::ldiv;
# 151
using ::malloc;
# 153
using ::mblen;
# 154
using ::mbstowcs;
# 155
using ::mbtowc;
# 157
using ::qsort;
# 160
using ::quick_exit;
# 163
using ::rand;
# 164
using ::realloc;
# 165
using ::srand;
# 166
using ::strtod;
# 167
using ::strtol;
# 168
using ::strtoul;
# 169
using ::system;
# 171
using ::wcstombs;
# 172
using ::wctomb;
# 177
inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); } 
# 182
}
# 195 "/usr/include/c++/7/cstdlib" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 200
using ::lldiv_t;
# 206
using ::_Exit;
# 210
using ::llabs;
# 213
inline lldiv_t div(long long __n, long long __d) 
# 214
{ lldiv_t __q; (__q.quot) = (__n / __d); (__q.rem) = (__n % __d); return __q; } 
# 216
using ::lldiv;
# 227 "/usr/include/c++/7/cstdlib" 3
using ::atoll;
# 228
using ::strtoll;
# 229
using ::strtoull;
# 231
using ::strtof;
# 232
using ::strtold;
# 235
}
# 237
namespace std { 
# 240
using __gnu_cxx::lldiv_t;
# 242
using __gnu_cxx::_Exit;
# 244
using __gnu_cxx::llabs;
# 245
using __gnu_cxx::div;
# 246
using __gnu_cxx::lldiv;
# 248
using __gnu_cxx::atoll;
# 249
using __gnu_cxx::strtof;
# 250
using __gnu_cxx::strtoll;
# 251
using __gnu_cxx::strtoull;
# 252
using __gnu_cxx::strtold;
# 253
}
# 257
}
# 38 "/usr/include/c++/7/stdlib.h" 3
using std::abort;
# 39
using std::atexit;
# 40
using std::exit;
# 43
using std::at_quick_exit;
# 46
using std::quick_exit;
# 54
using std::abs;
# 55
using std::atof;
# 56
using std::atoi;
# 57
using std::atol;
# 58
using std::bsearch;
# 59
using std::calloc;
# 60
using std::div;
# 61
using std::free;
# 62
using std::getenv;
# 63
using std::labs;
# 64
using std::ldiv;
# 65
using std::malloc;
# 67
using std::mblen;
# 68
using std::mbstowcs;
# 69
using std::mbtowc;
# 71
using std::qsort;
# 72
using std::rand;
# 73
using std::realloc;
# 74
using std::srand;
# 75
using std::strtod;
# 76
using std::strtol;
# 77
using std::strtoul;
# 78
using std::system;
# 80
using std::wcstombs;
# 81
using std::wctomb;
# 9029 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
namespace std { 
# 9030
constexpr bool signbit(float x); 
# 9031
constexpr bool signbit(double x); 
# 9032
constexpr bool signbit(long double x); 
# 9033
constexpr bool isfinite(float x); 
# 9034
constexpr bool isfinite(double x); 
# 9035
constexpr bool isfinite(long double x); 
# 9036
constexpr bool isnan(float x); 
# 9041
constexpr bool isnan(double x); 
# 9043
constexpr bool isnan(long double x); 
# 9044
constexpr bool isinf(float x); 
# 9049
constexpr bool isinf(double x); 
# 9051
constexpr bool isinf(long double x); 
# 9052
}
# 9205 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
namespace std { 
# 9207
template< class T> extern T __pow_helper(T, int); 
# 9208
template< class T> extern T __cmath_power(T, unsigned); 
# 9209
}
# 9211
using std::abs;
# 9212
using std::fabs;
# 9213
using std::ceil;
# 9214
using std::floor;
# 9215
using std::sqrt;
# 9217
using std::pow;
# 9219
using std::log;
# 9220
using std::log10;
# 9221
using std::fmod;
# 9222
using std::modf;
# 9223
using std::exp;
# 9224
using std::frexp;
# 9225
using std::ldexp;
# 9226
using std::asin;
# 9227
using std::sin;
# 9228
using std::sinh;
# 9229
using std::acos;
# 9230
using std::cos;
# 9231
using std::cosh;
# 9232
using std::atan;
# 9233
using std::atan2;
# 9234
using std::tan;
# 9235
using std::tanh;
# 9600 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
namespace std { 
# 9609 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern inline long long abs(long long); 
# 9619 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern inline long abs(long); 
# 9620
extern constexpr float abs(float); 
# 9621
extern constexpr double abs(double); 
# 9622
extern constexpr float fabs(float); 
# 9623
extern constexpr float ceil(float); 
# 9624
extern constexpr float floor(float); 
# 9625
extern constexpr float sqrt(float); 
# 9626
extern constexpr float pow(float, float); 
# 9631
template< class _Tp, class _Up> extern constexpr typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type pow(_Tp, _Up); 
# 9641
extern constexpr float log(float); 
# 9642
extern constexpr float log10(float); 
# 9643
extern constexpr float fmod(float, float); 
# 9644
extern inline float modf(float, float *); 
# 9645
extern constexpr float exp(float); 
# 9646
extern inline float frexp(float, int *); 
# 9647
extern constexpr float ldexp(float, int); 
# 9648
extern constexpr float asin(float); 
# 9649
extern constexpr float sin(float); 
# 9650
extern constexpr float sinh(float); 
# 9651
extern constexpr float acos(float); 
# 9652
extern constexpr float cos(float); 
# 9653
extern constexpr float cosh(float); 
# 9654
extern constexpr float atan(float); 
# 9655
extern constexpr float atan2(float, float); 
# 9656
extern constexpr float tan(float); 
# 9657
extern constexpr float tanh(float); 
# 9744 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
}
# 9847 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
namespace std { 
# 9848
constexpr float logb(float a); 
# 9849
constexpr int ilogb(float a); 
# 9850
constexpr float scalbn(float a, int b); 
# 9851
constexpr float scalbln(float a, long b); 
# 9852
constexpr float exp2(float a); 
# 9853
constexpr float expm1(float a); 
# 9854
constexpr float log2(float a); 
# 9855
constexpr float log1p(float a); 
# 9856
constexpr float acosh(float a); 
# 9857
constexpr float asinh(float a); 
# 9858
constexpr float atanh(float a); 
# 9859
constexpr float hypot(float a, float b); 
# 9860
constexpr float cbrt(float a); 
# 9861
constexpr float erf(float a); 
# 9862
constexpr float erfc(float a); 
# 9863
constexpr float lgamma(float a); 
# 9864
constexpr float tgamma(float a); 
# 9865
constexpr float copysign(float a, float b); 
# 9866
constexpr float nextafter(float a, float b); 
# 9867
constexpr float remainder(float a, float b); 
# 9868
inline float remquo(float a, float b, int * quo); 
# 9869
constexpr float round(float a); 
# 9870
constexpr long lround(float a); 
# 9871
constexpr long long llround(float a); 
# 9872
constexpr float trunc(float a); 
# 9873
constexpr float rint(float a); 
# 9874
constexpr long lrint(float a); 
# 9875
constexpr long long llrint(float a); 
# 9876
constexpr float nearbyint(float a); 
# 9877
constexpr float fdim(float a, float b); 
# 9878
constexpr float fma(float a, float b, float c); 
# 9879
constexpr float fmax(float a, float b); 
# 9880
constexpr float fmin(float a, float b); 
# 9881
}
# 9986 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline float exp10(float a); 
# 9988
static inline float rsqrt(float a); 
# 9990
static inline float rcbrt(float a); 
# 9992
static inline float sinpi(float a); 
# 9994
static inline float cospi(float a); 
# 9996
static inline void sincospi(float a, float * sptr, float * cptr); 
# 9998
static inline void sincos(float a, float * sptr, float * cptr); 
# 10000
static inline float j0(float a); 
# 10002
static inline float j1(float a); 
# 10004
static inline float jn(int n, float a); 
# 10006
static inline float y0(float a); 
# 10008
static inline float y1(float a); 
# 10010
static inline float yn(int n, float a); 
# 10012
__attribute__((unused)) static inline float cyl_bessel_i0(float a); 
# 10014
__attribute__((unused)) static inline float cyl_bessel_i1(float a); 
# 10016
static inline float erfinv(float a); 
# 10018
static inline float erfcinv(float a); 
# 10020
static inline float normcdfinv(float a); 
# 10022
static inline float normcdf(float a); 
# 10024
static inline float erfcx(float a); 
# 10026
static inline double copysign(double a, float b); 
# 10028
static inline double copysign(float a, double b); 
# 10036
static inline unsigned min(unsigned a, unsigned b); 
# 10044
static inline unsigned min(int a, unsigned b); 
# 10052
static inline unsigned min(unsigned a, int b); 
# 10060
static inline long min(long a, long b); 
# 10068
static inline unsigned long min(unsigned long a, unsigned long b); 
# 10076
static inline unsigned long min(long a, unsigned long b); 
# 10084
static inline unsigned long min(unsigned long a, long b); 
# 10092
static inline long long min(long long a, long long b); 
# 10100
static inline unsigned long long min(unsigned long long a, unsigned long long b); 
# 10108
static inline unsigned long long min(long long a, unsigned long long b); 
# 10116
static inline unsigned long long min(unsigned long long a, long long b); 
# 10127 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline float min(float a, float b); 
# 10138 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline double min(double a, double b); 
# 10148 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline double min(float a, double b); 
# 10158 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline double min(double a, float b); 
# 10169 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline unsigned max(unsigned a, unsigned b); 
# 10177
static inline unsigned max(int a, unsigned b); 
# 10185
static inline unsigned max(unsigned a, int b); 
# 10193
static inline long max(long a, long b); 
# 10201
static inline unsigned long max(unsigned long a, unsigned long b); 
# 10209
static inline unsigned long max(long a, unsigned long b); 
# 10217
static inline unsigned long max(unsigned long a, long b); 
# 10225
static inline long long max(long long a, long long b); 
# 10233
static inline unsigned long long max(unsigned long long a, unsigned long long b); 
# 10241
static inline unsigned long long max(long long a, unsigned long long b); 
# 10249
static inline unsigned long long max(unsigned long long a, long long b); 
# 10260 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline float max(float a, float b); 
# 10271 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline double max(double a, double b); 
# 10281 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline double max(float a, double b); 
# 10291 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
static inline double max(double a, float b); 
# 10302 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
extern "C" {
# 10303
__attribute__((unused)) inline void *__nv_aligned_device_malloc(size_t size, size_t align) 
# 10304
{int volatile ___ = 1;(void)size;(void)align;
# 10307
::exit(___);}
#if 0
# 10304
{ 
# 10305
__attribute__((unused)) void *__nv_aligned_device_malloc_impl(size_t, size_t); 
# 10306
return __nv_aligned_device_malloc_impl(size, align); 
# 10307
} 
#endif
# 10308 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.h"
}
# 758 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.hpp"
static inline float exp10(const float a) 
# 759
{ 
# 760
return exp10f(a); 
# 761
} 
# 763
static inline float rsqrt(const float a) 
# 764
{ 
# 765
return rsqrtf(a); 
# 766
} 
# 768
static inline float rcbrt(const float a) 
# 769
{ 
# 770
return rcbrtf(a); 
# 771
} 
# 773
static inline float sinpi(const float a) 
# 774
{ 
# 775
return sinpif(a); 
# 776
} 
# 778
static inline float cospi(const float a) 
# 779
{ 
# 780
return cospif(a); 
# 781
} 
# 783
static inline void sincospi(const float a, float *const sptr, float *const cptr) 
# 784
{ 
# 785
sincospif(a, sptr, cptr); 
# 786
} 
# 788
static inline void sincos(const float a, float *const sptr, float *const cptr) 
# 789
{ 
# 790
sincosf(a, sptr, cptr); 
# 791
} 
# 793
static inline float j0(const float a) 
# 794
{ 
# 795
return j0f(a); 
# 796
} 
# 798
static inline float j1(const float a) 
# 799
{ 
# 800
return j1f(a); 
# 801
} 
# 803
static inline float jn(const int n, const float a) 
# 804
{ 
# 805
return jnf(n, a); 
# 806
} 
# 808
static inline float y0(const float a) 
# 809
{ 
# 810
return y0f(a); 
# 811
} 
# 813
static inline float y1(const float a) 
# 814
{ 
# 815
return y1f(a); 
# 816
} 
# 818
static inline float yn(const int n, const float a) 
# 819
{ 
# 820
return ynf(n, a); 
# 821
} 
# 823
__attribute__((unused)) static inline float cyl_bessel_i0(const float a) 
# 824
{int volatile ___ = 1;(void)a;
# 826
::exit(___);}
#if 0
# 824
{ 
# 825
return cyl_bessel_i0f(a); 
# 826
} 
#endif
# 828 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.hpp"
__attribute__((unused)) static inline float cyl_bessel_i1(const float a) 
# 829
{int volatile ___ = 1;(void)a;
# 831
::exit(___);}
#if 0
# 829
{ 
# 830
return cyl_bessel_i1f(a); 
# 831
} 
#endif
# 833 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.hpp"
static inline float erfinv(const float a) 
# 834
{ 
# 835
return erfinvf(a); 
# 836
} 
# 838
static inline float erfcinv(const float a) 
# 839
{ 
# 840
return erfcinvf(a); 
# 841
} 
# 843
static inline float normcdfinv(const float a) 
# 844
{ 
# 845
return normcdfinvf(a); 
# 846
} 
# 848
static inline float normcdf(const float a) 
# 849
{ 
# 850
return normcdff(a); 
# 851
} 
# 853
static inline float erfcx(const float a) 
# 854
{ 
# 855
return erfcxf(a); 
# 856
} 
# 858
static inline double copysign(const double a, const float b) 
# 859
{ 
# 860
return copysign(a, static_cast< double>(b)); 
# 861
} 
# 863
static inline double copysign(const float a, const double b) 
# 864
{ 
# 865
return copysign(static_cast< double>(a), b); 
# 866
} 
# 868
static inline unsigned min(const unsigned a, const unsigned b) 
# 869
{ 
# 870
return umin(a, b); 
# 871
} 
# 873
static inline unsigned min(const int a, const unsigned b) 
# 874
{ 
# 875
return umin(static_cast< unsigned>(a), b); 
# 876
} 
# 878
static inline unsigned min(const unsigned a, const int b) 
# 879
{ 
# 880
return umin(a, static_cast< unsigned>(b)); 
# 881
} 
# 883
static inline long min(const long a, const long b) 
# 884
{ 
# 885
long retval; 
# 891
if (sizeof(long) == sizeof(int)) { 
# 895
retval = (static_cast< long>(min(static_cast< int>(a), static_cast< int>(b)))); 
# 896
} else { 
# 897
retval = (static_cast< long>(llmin(static_cast< long long>(a), static_cast< long long>(b)))); 
# 898
}  
# 899
return retval; 
# 900
} 
# 902
static inline unsigned long min(const unsigned long a, const unsigned long b) 
# 903
{ 
# 904
unsigned long retval; 
# 908
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 912
retval = (static_cast< unsigned long>(umin(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
# 913
} else { 
# 914
retval = (static_cast< unsigned long>(ullmin(static_cast< unsigned long long>(a), static_cast< unsigned long long>(b)))); 
# 915
}  
# 916
return retval; 
# 917
} 
# 919
static inline unsigned long min(const long a, const unsigned long b) 
# 920
{ 
# 921
unsigned long retval; 
# 925
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 929
retval = (static_cast< unsigned long>(umin(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
# 930
} else { 
# 931
retval = (static_cast< unsigned long>(ullmin(static_cast< unsigned long long>(a), static_cast< unsigned long long>(b)))); 
# 932
}  
# 933
return retval; 
# 934
} 
# 936
static inline unsigned long min(const unsigned long a, const long b) 
# 937
{ 
# 938
unsigned long retval; 
# 942
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 946
retval = (static_cast< unsigned long>(umin(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
# 947
} else { 
# 948
retval = (static_cast< unsigned long>(ullmin(static_cast< unsigned long long>(a), static_cast< unsigned long long>(b)))); 
# 949
}  
# 950
return retval; 
# 951
} 
# 953
static inline long long min(const long long a, const long long b) 
# 954
{ 
# 955
return llmin(a, b); 
# 956
} 
# 958
static inline unsigned long long min(const unsigned long long a, const unsigned long long b) 
# 959
{ 
# 960
return ullmin(a, b); 
# 961
} 
# 963
static inline unsigned long long min(const long long a, const unsigned long long b) 
# 964
{ 
# 965
return ullmin(static_cast< unsigned long long>(a), b); 
# 966
} 
# 968
static inline unsigned long long min(const unsigned long long a, const long long b) 
# 969
{ 
# 970
return ullmin(a, static_cast< unsigned long long>(b)); 
# 971
} 
# 973
static inline float min(const float a, const float b) 
# 974
{ 
# 975
return fminf(a, b); 
# 976
} 
# 978
static inline double min(const double a, const double b) 
# 979
{ 
# 980
return fmin(a, b); 
# 981
} 
# 983
static inline double min(const float a, const double b) 
# 984
{ 
# 985
return fmin(static_cast< double>(a), b); 
# 986
} 
# 988
static inline double min(const double a, const float b) 
# 989
{ 
# 990
return fmin(a, static_cast< double>(b)); 
# 991
} 
# 993
static inline unsigned max(const unsigned a, const unsigned b) 
# 994
{ 
# 995
return umax(a, b); 
# 996
} 
# 998
static inline unsigned max(const int a, const unsigned b) 
# 999
{ 
# 1000
return umax(static_cast< unsigned>(a), b); 
# 1001
} 
# 1003
static inline unsigned max(const unsigned a, const int b) 
# 1004
{ 
# 1005
return umax(a, static_cast< unsigned>(b)); 
# 1006
} 
# 1008
static inline long max(const long a, const long b) 
# 1009
{ 
# 1010
long retval; 
# 1015
if (sizeof(long) == sizeof(int)) { 
# 1019
retval = (static_cast< long>(max(static_cast< int>(a), static_cast< int>(b)))); 
# 1020
} else { 
# 1021
retval = (static_cast< long>(llmax(static_cast< long long>(a), static_cast< long long>(b)))); 
# 1022
}  
# 1023
return retval; 
# 1024
} 
# 1026
static inline unsigned long max(const unsigned long a, const unsigned long b) 
# 1027
{ 
# 1028
unsigned long retval; 
# 1032
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 1036
retval = (static_cast< unsigned long>(umax(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
# 1037
} else { 
# 1038
retval = (static_cast< unsigned long>(ullmax(static_cast< unsigned long long>(a), static_cast< unsigned long long>(b)))); 
# 1039
}  
# 1040
return retval; 
# 1041
} 
# 1043
static inline unsigned long max(const long a, const unsigned long b) 
# 1044
{ 
# 1045
unsigned long retval; 
# 1049
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 1053
retval = (static_cast< unsigned long>(umax(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
# 1054
} else { 
# 1055
retval = (static_cast< unsigned long>(ullmax(static_cast< unsigned long long>(a), static_cast< unsigned long long>(b)))); 
# 1056
}  
# 1057
return retval; 
# 1058
} 
# 1060
static inline unsigned long max(const unsigned long a, const long b) 
# 1061
{ 
# 1062
unsigned long retval; 
# 1066
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 1070
retval = (static_cast< unsigned long>(umax(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
# 1071
} else { 
# 1072
retval = (static_cast< unsigned long>(ullmax(static_cast< unsigned long long>(a), static_cast< unsigned long long>(b)))); 
# 1073
}  
# 1074
return retval; 
# 1075
} 
# 1077
static inline long long max(const long long a, const long long b) 
# 1078
{ 
# 1079
return llmax(a, b); 
# 1080
} 
# 1082
static inline unsigned long long max(const unsigned long long a, const unsigned long long b) 
# 1083
{ 
# 1084
return ullmax(a, b); 
# 1085
} 
# 1087
static inline unsigned long long max(const long long a, const unsigned long long b) 
# 1088
{ 
# 1089
return ullmax(static_cast< unsigned long long>(a), b); 
# 1090
} 
# 1092
static inline unsigned long long max(const unsigned long long a, const long long b) 
# 1093
{ 
# 1094
return ullmax(a, static_cast< unsigned long long>(b)); 
# 1095
} 
# 1097
static inline float max(const float a, const float b) 
# 1098
{ 
# 1099
return fmaxf(a, b); 
# 1100
} 
# 1102
static inline double max(const double a, const double b) 
# 1103
{ 
# 1104
return fmax(a, b); 
# 1105
} 
# 1107
static inline double max(const float a, const double b) 
# 1108
{ 
# 1109
return fmax(static_cast< double>(a), b); 
# 1110
} 
# 1112
static inline double max(const double a, const float b) 
# 1113
{ 
# 1114
return fmax(a, static_cast< double>(b)); 
# 1115
} 
# 1126 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/math_functions.hpp"
inline int min(const int a, const int b) 
# 1127
{ 
# 1128
return (a < b) ? a : b; 
# 1129
} 
# 1131
inline unsigned umin(const unsigned a, const unsigned b) 
# 1132
{ 
# 1133
return (a < b) ? a : b; 
# 1134
} 
# 1136
inline long long llmin(const long long a, const long long b) 
# 1137
{ 
# 1138
return (a < b) ? a : b; 
# 1139
} 
# 1141
inline unsigned long long ullmin(const unsigned long long a, const unsigned long long 
# 1142
b) 
# 1143
{ 
# 1144
return (a < b) ? a : b; 
# 1145
} 
# 1147
inline int max(const int a, const int b) 
# 1148
{ 
# 1149
return (a > b) ? a : b; 
# 1150
} 
# 1152
inline unsigned umax(const unsigned a, const unsigned b) 
# 1153
{ 
# 1154
return (a > b) ? a : b; 
# 1155
} 
# 1157
inline long long llmax(const long long a, const long long b) 
# 1158
{ 
# 1159
return (a > b) ? a : b; 
# 1160
} 
# 1162
inline unsigned long long ullmax(const unsigned long long a, const unsigned long long 
# 1163
b) 
# 1164
{ 
# 1165
return (a > b) ? a : b; 
# 1166
} 
# 74 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_surface_types.h"
template< class T, int dim = 1> 
# 75
struct surface : public surfaceReference { 
# 78
surface() 
# 79
{ 
# 80
(channelDesc) = cudaCreateChannelDesc< T> (); 
# 81
} 
# 83
surface(cudaChannelFormatDesc desc) 
# 84
{ 
# 85
(channelDesc) = desc; 
# 86
} 
# 88
}; 
# 90
template< int dim> 
# 91
struct surface< void, dim>  : public surfaceReference { 
# 94
surface() 
# 95
{ 
# 96
(channelDesc) = cudaCreateChannelDesc< void> (); 
# 97
} 
# 99
}; 
# 74 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_texture_types.h"
template< class T, int texType = 1, cudaTextureReadMode mode = cudaReadModeElementType> 
# 75
struct texture : public textureReference { 
# 78
texture(int norm = 0, cudaTextureFilterMode 
# 79
fMode = cudaFilterModePoint, cudaTextureAddressMode 
# 80
aMode = cudaAddressModeClamp) 
# 81
{ 
# 82
(normalized) = norm; 
# 83
(filterMode) = fMode; 
# 84
((addressMode)[0]) = aMode; 
# 85
((addressMode)[1]) = aMode; 
# 86
((addressMode)[2]) = aMode; 
# 87
(channelDesc) = cudaCreateChannelDesc< T> (); 
# 88
(sRGB) = 0; 
# 89
} 
# 91
texture(int norm, cudaTextureFilterMode 
# 92
fMode, cudaTextureAddressMode 
# 93
aMode, cudaChannelFormatDesc 
# 94
desc) 
# 95
{ 
# 96
(normalized) = norm; 
# 97
(filterMode) = fMode; 
# 98
((addressMode)[0]) = aMode; 
# 99
((addressMode)[1]) = aMode; 
# 100
((addressMode)[2]) = aMode; 
# 101
(channelDesc) = desc; 
# 102
(sRGB) = 0; 
# 103
} 
# 105
}; 
# 89 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.h"
extern "C" {
# 3217 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.h"
}
# 3225
__attribute__((unused)) static inline int mulhi(int a, int b); 
# 3227
__attribute__((unused)) static inline unsigned mulhi(unsigned a, unsigned b); 
# 3229
__attribute__((unused)) static inline unsigned mulhi(int a, unsigned b); 
# 3231
__attribute__((unused)) static inline unsigned mulhi(unsigned a, int b); 
# 3233
__attribute__((unused)) static inline long long mul64hi(long long a, long long b); 
# 3235
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b); 
# 3237
__attribute__((unused)) static inline unsigned long long mul64hi(long long a, unsigned long long b); 
# 3239
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, long long b); 
# 3241
__attribute__((unused)) static inline int float_as_int(float a); 
# 3243
__attribute__((unused)) static inline float int_as_float(int a); 
# 3245
__attribute__((unused)) static inline unsigned float_as_uint(float a); 
# 3247
__attribute__((unused)) static inline float uint_as_float(unsigned a); 
# 3249
__attribute__((unused)) static inline float saturate(float a); 
# 3251
__attribute__((unused)) static inline int mul24(int a, int b); 
# 3253
__attribute__((unused)) static inline unsigned umul24(unsigned a, unsigned b); 
# 3255
__attribute__((unused)) static inline int float2int(float a, cudaRoundMode mode = cudaRoundZero); 
# 3257
__attribute__((unused)) static inline unsigned float2uint(float a, cudaRoundMode mode = cudaRoundZero); 
# 3259
__attribute__((unused)) static inline float int2float(int a, cudaRoundMode mode = cudaRoundNearest); 
# 3261
__attribute__((unused)) static inline float uint2float(unsigned a, cudaRoundMode mode = cudaRoundNearest); 
# 90 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline int mulhi(const int a, const int b) 
# 91
{int volatile ___ = 1;(void)a;(void)b;
# 93
::exit(___);}
#if 0
# 91
{ 
# 92
return __mulhi(a, b); 
# 93
} 
#endif
# 95 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline unsigned mulhi(const unsigned a, const unsigned b) 
# 96
{int volatile ___ = 1;(void)a;(void)b;
# 98
::exit(___);}
#if 0
# 96
{ 
# 97
return __umulhi(a, b); 
# 98
} 
#endif
# 100 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline unsigned mulhi(const int a, const unsigned b) 
# 101
{int volatile ___ = 1;(void)a;(void)b;
# 103
::exit(___);}
#if 0
# 101
{ 
# 102
return __umulhi(static_cast< unsigned>(a), b); 
# 103
} 
#endif
# 105 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline unsigned mulhi(const unsigned a, const int b) 
# 106
{int volatile ___ = 1;(void)a;(void)b;
# 108
::exit(___);}
#if 0
# 106
{ 
# 107
return __umulhi(a, static_cast< unsigned>(b)); 
# 108
} 
#endif
# 110 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline long long mul64hi(const long long a, const long long b) 
# 111
{int volatile ___ = 1;(void)a;(void)b;
# 113
::exit(___);}
#if 0
# 111
{ 
# 112
return __mul64hi(a, b); 
# 113
} 
#endif
# 115 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline unsigned long long mul64hi(const unsigned long long a, const unsigned long long b) 
# 116
{int volatile ___ = 1;(void)a;(void)b;
# 118
::exit(___);}
#if 0
# 116
{ 
# 117
return __umul64hi(a, b); 
# 118
} 
#endif
# 120 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline unsigned long long mul64hi(const long long a, const unsigned long long b) 
# 121
{int volatile ___ = 1;(void)a;(void)b;
# 123
::exit(___);}
#if 0
# 121
{ 
# 122
return __umul64hi(static_cast< unsigned long long>(a), b); 
# 123
} 
#endif
# 125 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline unsigned long long mul64hi(const unsigned long long a, const long long b) 
# 126
{int volatile ___ = 1;(void)a;(void)b;
# 128
::exit(___);}
#if 0
# 126
{ 
# 127
return __umul64hi(a, static_cast< unsigned long long>(b)); 
# 128
} 
#endif
# 130 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline int float_as_int(const float a) 
# 131
{int volatile ___ = 1;(void)a;
# 133
::exit(___);}
#if 0
# 131
{ 
# 132
return __float_as_int(a); 
# 133
} 
#endif
# 135 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline float int_as_float(const int a) 
# 136
{int volatile ___ = 1;(void)a;
# 138
::exit(___);}
#if 0
# 136
{ 
# 137
return __int_as_float(a); 
# 138
} 
#endif
# 140 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline unsigned float_as_uint(const float a) 
# 141
{int volatile ___ = 1;(void)a;
# 143
::exit(___);}
#if 0
# 141
{ 
# 142
return __float_as_uint(a); 
# 143
} 
#endif
# 145 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline float uint_as_float(const unsigned a) 
# 146
{int volatile ___ = 1;(void)a;
# 148
::exit(___);}
#if 0
# 146
{ 
# 147
return __uint_as_float(a); 
# 148
} 
#endif
# 149 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline float saturate(const float a) 
# 150
{int volatile ___ = 1;(void)a;
# 152
::exit(___);}
#if 0
# 150
{ 
# 151
return __saturatef(a); 
# 152
} 
#endif
# 154 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline int mul24(const int a, const int b) 
# 155
{int volatile ___ = 1;(void)a;(void)b;
# 157
::exit(___);}
#if 0
# 155
{ 
# 156
return __mul24(a, b); 
# 157
} 
#endif
# 159 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline unsigned umul24(const unsigned a, const unsigned b) 
# 160
{int volatile ___ = 1;(void)a;(void)b;
# 162
::exit(___);}
#if 0
# 160
{ 
# 161
return __umul24(a, b); 
# 162
} 
#endif
# 164 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline int float2int(const float a, const cudaRoundMode mode) 
# 165
{int volatile ___ = 1;(void)a;(void)mode;
# 170
::exit(___);}
#if 0
# 165
{ 
# 166
return (mode == (cudaRoundNearest)) ? __float2int_rn(a) : ((mode == (cudaRoundPosInf)) ? __float2int_ru(a) : ((mode == (cudaRoundMinInf)) ? __float2int_rd(a) : __float2int_rz(a))); 
# 170
} 
#endif
# 172 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline unsigned float2uint(const float a, const cudaRoundMode mode) 
# 173
{int volatile ___ = 1;(void)a;(void)mode;
# 178
::exit(___);}
#if 0
# 173
{ 
# 174
return (mode == (cudaRoundNearest)) ? __float2uint_rn(a) : ((mode == (cudaRoundPosInf)) ? __float2uint_ru(a) : ((mode == (cudaRoundMinInf)) ? __float2uint_rd(a) : __float2uint_rz(a))); 
# 178
} 
#endif
# 180 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline float int2float(const int a, const cudaRoundMode mode) 
# 181
{int volatile ___ = 1;(void)a;(void)mode;
# 186
::exit(___);}
#if 0
# 181
{ 
# 182
return (mode == (cudaRoundZero)) ? __int2float_rz(a) : ((mode == (cudaRoundPosInf)) ? __int2float_ru(a) : ((mode == (cudaRoundMinInf)) ? __int2float_rd(a) : __int2float_rn(a))); 
# 186
} 
#endif
# 188 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.hpp"
__attribute__((unused)) static inline float uint2float(const unsigned a, const cudaRoundMode mode) 
# 189
{int volatile ___ = 1;(void)a;(void)mode;
# 194
::exit(___);}
#if 0
# 189
{ 
# 190
return (mode == (cudaRoundZero)) ? __uint2float_rz(a) : ((mode == (cudaRoundPosInf)) ? __uint2float_ru(a) : ((mode == (cudaRoundMinInf)) ? __uint2float_rd(a) : __uint2float_rn(a))); 
# 194
} 
#endif
# 106 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 106
{ } 
#endif
# 108 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 108
{ } 
#endif
# 110 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicSub(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 110
{ } 
#endif
# 112 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicSub(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 112
{ } 
#endif
# 114 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 114
{ } 
#endif
# 116 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 116
{ } 
#endif
# 118 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 118
{ } 
#endif
# 120 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 120
{ } 
#endif
# 122 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 122
{ } 
#endif
# 124 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 124
{ } 
#endif
# 126 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 126
{ } 
#endif
# 128 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 128
{ } 
#endif
# 130 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 130
{ } 
#endif
# 132 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 132
{ } 
#endif
# 134 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 134
{ } 
#endif
# 136 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 136
{ } 
#endif
# 138 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 138
{ } 
#endif
# 140 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 140
{ } 
#endif
# 142 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 142
{ } 
#endif
# 144 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 144
{ } 
#endif
# 146 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 146
{ } 
#endif
# 171 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
extern "C" {
# 180
}
# 189 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 189
{ } 
#endif
# 191 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 191
{ } 
#endif
# 193 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 193
{ } 
#endif
# 195 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute((deprecated("__any() is deprecated in favor of __any_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to suppr" "ess this warning)."))) __attribute__((unused)) static inline bool any(bool cond) {int volatile ___ = 1;(void)cond;::exit(___);}
#if 0
# 195
{ } 
#endif
# 197 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute((deprecated("__all() is deprecated in favor of __all_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to suppr" "ess this warning)."))) __attribute__((unused)) static inline bool all(bool cond) {int volatile ___ = 1;(void)cond;::exit(___);}
#if 0
# 197
{ } 
#endif
# 87 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.h"
extern "C" {
# 1139 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.h"
}
# 1147
__attribute__((unused)) static inline double fma(double a, double b, double c, cudaRoundMode mode); 
# 1149
__attribute__((unused)) static inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
# 1151
__attribute__((unused)) static inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
# 1153
__attribute__((unused)) static inline double dsub(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
# 1155
__attribute__((unused)) static inline int double2int(double a, cudaRoundMode mode = cudaRoundZero); 
# 1157
__attribute__((unused)) static inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero); 
# 1159
__attribute__((unused)) static inline long long double2ll(double a, cudaRoundMode mode = cudaRoundZero); 
# 1161
__attribute__((unused)) static inline unsigned long long double2ull(double a, cudaRoundMode mode = cudaRoundZero); 
# 1163
__attribute__((unused)) static inline double ll2double(long long a, cudaRoundMode mode = cudaRoundNearest); 
# 1165
__attribute__((unused)) static inline double ull2double(unsigned long long a, cudaRoundMode mode = cudaRoundNearest); 
# 1167
__attribute__((unused)) static inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest); 
# 1169
__attribute__((unused)) static inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest); 
# 1171
__attribute__((unused)) static inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest); 
# 93 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline double fma(double a, double b, double c, cudaRoundMode mode) 
# 94
{int volatile ___ = 1;(void)a;(void)b;(void)c;(void)mode;
# 99
::exit(___);}
#if 0
# 94
{ 
# 95
return (mode == (cudaRoundZero)) ? __fma_rz(a, b, c) : ((mode == (cudaRoundPosInf)) ? __fma_ru(a, b, c) : ((mode == (cudaRoundMinInf)) ? __fma_rd(a, b, c) : __fma_rn(a, b, c))); 
# 99
} 
#endif
# 101 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline double dmul(double a, double b, cudaRoundMode mode) 
# 102
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 107
::exit(___);}
#if 0
# 102
{ 
# 103
return (mode == (cudaRoundZero)) ? __dmul_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dmul_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dmul_rd(a, b) : __dmul_rn(a, b))); 
# 107
} 
#endif
# 109 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline double dadd(double a, double b, cudaRoundMode mode) 
# 110
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 115
::exit(___);}
#if 0
# 110
{ 
# 111
return (mode == (cudaRoundZero)) ? __dadd_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dadd_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dadd_rd(a, b) : __dadd_rn(a, b))); 
# 115
} 
#endif
# 117 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline double dsub(double a, double b, cudaRoundMode mode) 
# 118
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 123
::exit(___);}
#if 0
# 118
{ 
# 119
return (mode == (cudaRoundZero)) ? __dsub_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dsub_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dsub_rd(a, b) : __dsub_rn(a, b))); 
# 123
} 
#endif
# 125 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline int double2int(double a, cudaRoundMode mode) 
# 126
{int volatile ___ = 1;(void)a;(void)mode;
# 131
::exit(___);}
#if 0
# 126
{ 
# 127
return (mode == (cudaRoundNearest)) ? __double2int_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2int_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2int_rd(a) : __double2int_rz(a))); 
# 131
} 
#endif
# 133 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline unsigned double2uint(double a, cudaRoundMode mode) 
# 134
{int volatile ___ = 1;(void)a;(void)mode;
# 139
::exit(___);}
#if 0
# 134
{ 
# 135
return (mode == (cudaRoundNearest)) ? __double2uint_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2uint_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2uint_rd(a) : __double2uint_rz(a))); 
# 139
} 
#endif
# 141 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline long long double2ll(double a, cudaRoundMode mode) 
# 142
{int volatile ___ = 1;(void)a;(void)mode;
# 147
::exit(___);}
#if 0
# 142
{ 
# 143
return (mode == (cudaRoundNearest)) ? __double2ll_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ll_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ll_rd(a) : __double2ll_rz(a))); 
# 147
} 
#endif
# 149 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline unsigned long long double2ull(double a, cudaRoundMode mode) 
# 150
{int volatile ___ = 1;(void)a;(void)mode;
# 155
::exit(___);}
#if 0
# 150
{ 
# 151
return (mode == (cudaRoundNearest)) ? __double2ull_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ull_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ull_rd(a) : __double2ull_rz(a))); 
# 155
} 
#endif
# 157 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline double ll2double(long long a, cudaRoundMode mode) 
# 158
{int volatile ___ = 1;(void)a;(void)mode;
# 163
::exit(___);}
#if 0
# 158
{ 
# 159
return (mode == (cudaRoundZero)) ? __ll2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ll2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ll2double_rd(a) : __ll2double_rn(a))); 
# 163
} 
#endif
# 165 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline double ull2double(unsigned long long a, cudaRoundMode mode) 
# 166
{int volatile ___ = 1;(void)a;(void)mode;
# 171
::exit(___);}
#if 0
# 166
{ 
# 167
return (mode == (cudaRoundZero)) ? __ull2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ull2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ull2double_rd(a) : __ull2double_rn(a))); 
# 171
} 
#endif
# 173 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline double int2double(int a, cudaRoundMode mode) 
# 174
{int volatile ___ = 1;(void)a;(void)mode;
# 176
::exit(___);}
#if 0
# 174
{ 
# 175
return (double)a; 
# 176
} 
#endif
# 178 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline double uint2double(unsigned a, cudaRoundMode mode) 
# 179
{int volatile ___ = 1;(void)a;(void)mode;
# 181
::exit(___);}
#if 0
# 179
{ 
# 180
return (double)a; 
# 181
} 
#endif
# 183 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_double_functions.hpp"
__attribute__((unused)) static inline double float2double(float a, cudaRoundMode mode) 
# 184
{int volatile ___ = 1;(void)a;(void)mode;
# 186
::exit(___);}
#if 0
# 184
{ 
# 185
return (double)a; 
# 186
} 
#endif
# 89 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 89
{ } 
#endif
# 100 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMin(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 100
{ } 
#endif
# 102 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMax(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 102
{ } 
#endif
# 104 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline long long atomicAnd(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 104
{ } 
#endif
# 106 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline long long atomicOr(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 106
{ } 
#endif
# 108 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline long long atomicXor(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 108
{ } 
#endif
# 110 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMin(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 110
{ } 
#endif
# 112 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMax(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 112
{ } 
#endif
# 114 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAnd(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 114
{ } 
#endif
# 116 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicOr(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 116
{ } 
#endif
# 118 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicXor(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 118
{ } 
#endif
# 303 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline double atomicAdd(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 303
{ } 
#endif
# 306 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 306
{ } 
#endif
# 309 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 309
{ } 
#endif
# 312 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 312
{ } 
#endif
# 315 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 315
{ } 
#endif
# 318 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 318
{ } 
#endif
# 321 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 321
{ } 
#endif
# 324 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd_block(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 324
{ } 
#endif
# 327 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd_system(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 327
{ } 
#endif
# 330 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline double atomicAdd_block(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 330
{ } 
#endif
# 333 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline double atomicAdd_system(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 333
{ } 
#endif
# 336 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicSub_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 336
{ } 
#endif
# 339 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicSub_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 339
{ } 
#endif
# 342 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicSub_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 342
{ } 
#endif
# 345 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicSub_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 345
{ } 
#endif
# 348 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 348
{ } 
#endif
# 351 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 351
{ } 
#endif
# 354 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 354
{ } 
#endif
# 357 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 357
{ } 
#endif
# 360 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 360
{ } 
#endif
# 363 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 363
{ } 
#endif
# 366 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch_block(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 366
{ } 
#endif
# 369 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch_system(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 369
{ } 
#endif
# 372 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 372
{ } 
#endif
# 375 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 375
{ } 
#endif
# 378 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMin_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 378
{ } 
#endif
# 381 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMin_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 381
{ } 
#endif
# 384 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 384
{ } 
#endif
# 387 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 387
{ } 
#endif
# 390 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMin_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 390
{ } 
#endif
# 393 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMin_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 393
{ } 
#endif
# 396 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 396
{ } 
#endif
# 399 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 399
{ } 
#endif
# 402 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMax_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 402
{ } 
#endif
# 405 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMax_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 405
{ } 
#endif
# 408 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 408
{ } 
#endif
# 411 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 411
{ } 
#endif
# 414 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMax_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 414
{ } 
#endif
# 417 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMax_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 417
{ } 
#endif
# 420 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 420
{ } 
#endif
# 423 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 423
{ } 
#endif
# 426 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 426
{ } 
#endif
# 429 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 429
{ } 
#endif
# 432 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS_block(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 432
{ } 
#endif
# 435 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS_system(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 435
{ } 
#endif
# 438 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS_block(unsigned *address, unsigned compare, unsigned 
# 439
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 439
{ } 
#endif
# 442 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS_system(unsigned *address, unsigned compare, unsigned 
# 443
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 443
{ } 
#endif
# 446 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS_block(unsigned long long *address, unsigned long long 
# 447
compare, unsigned long long 
# 448
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 448
{ } 
#endif
# 451 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS_system(unsigned long long *address, unsigned long long 
# 452
compare, unsigned long long 
# 453
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 453
{ } 
#endif
# 456 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 456
{ } 
#endif
# 459 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 459
{ } 
#endif
# 462 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicAnd_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 462
{ } 
#endif
# 465 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicAnd_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 465
{ } 
#endif
# 468 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 468
{ } 
#endif
# 471 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 471
{ } 
#endif
# 474 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAnd_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 474
{ } 
#endif
# 477 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAnd_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 477
{ } 
#endif
# 480 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 480
{ } 
#endif
# 483 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 483
{ } 
#endif
# 486 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicOr_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 486
{ } 
#endif
# 489 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicOr_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 489
{ } 
#endif
# 492 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 492
{ } 
#endif
# 495 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 495
{ } 
#endif
# 498 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicOr_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 498
{ } 
#endif
# 501 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicOr_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 501
{ } 
#endif
# 504 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 504
{ } 
#endif
# 507 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 507
{ } 
#endif
# 510 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicXor_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 510
{ } 
#endif
# 513 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicXor_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 513
{ } 
#endif
# 516 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 516
{ } 
#endif
# 519 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 519
{ } 
#endif
# 522 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicXor_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 522
{ } 
#endif
# 525 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicXor_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 525
{ } 
#endif
# 90 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
extern "C" {
# 1503 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
}
# 1510
__attribute((deprecated("__ballot() is deprecated in favor of __ballot_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to" " suppress this warning)."))) __attribute__((unused)) static inline unsigned ballot(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
# 1510
{ } 
#endif
# 1512 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline int syncthreads_count(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
# 1512
{ } 
#endif
# 1514 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_and(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
# 1514
{ } 
#endif
# 1516 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_or(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
# 1516
{ } 
#endif
# 1521 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned __isGlobal(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 1521
{ } 
#endif
# 1522 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned __isShared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 1522
{ } 
#endif
# 1523 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned __isConstant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 1523
{ } 
#endif
# 1524 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned __isLocal(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 1524
{ } 
#endif
# 1526 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline size_t __cvta_generic_to_global(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 1526
{ } 
#endif
# 1527 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline size_t __cvta_generic_to_shared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 1527
{ } 
#endif
# 1528 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline size_t __cvta_generic_to_constant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 1528
{ } 
#endif
# 1529 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline size_t __cvta_generic_to_local(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 1529
{ } 
#endif
# 1531 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline void *__cvta_global_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
# 1531
{ } 
#endif
# 1532 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline void *__cvta_shared_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
# 1532
{ } 
#endif
# 1533 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline void *__cvta_constant_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
# 1533
{ } 
#endif
# 1534 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline void *__cvta_local_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
# 1534
{ } 
#endif
# 102 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __fns(unsigned mask, unsigned base, int offset) {int volatile ___ = 1;(void)mask;(void)base;(void)offset;::exit(___);}
#if 0
# 102
{ } 
#endif
# 103 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline void __barrier_sync(unsigned id) {int volatile ___ = 1;(void)id;::exit(___);}
#if 0
# 103
{ } 
#endif
# 104 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline void __barrier_sync_count(unsigned id, unsigned cnt) {int volatile ___ = 1;(void)id;(void)cnt;::exit(___);}
#if 0
# 104
{ } 
#endif
# 105 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline void __syncwarp(unsigned mask = 4294967295U) {int volatile ___ = 1;(void)mask;::exit(___);}
#if 0
# 105
{ } 
#endif
# 106 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __all_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
# 106
{ } 
#endif
# 107 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __any_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
# 107
{ } 
#endif
# 108 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __uni_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
# 108
{ } 
#endif
# 109 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __ballot_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
# 109
{ } 
#endif
# 110 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __activemask() {int volatile ___ = 1;::exit(___);}
#if 0
# 110
{ } 
#endif
# 119 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning)."))) __attribute__((unused)) static inline int __shfl(int var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 119
{ } 
#endif
# 120 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning)."))) __attribute__((unused)) static inline unsigned __shfl(unsigned var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 120
{ } 
#endif
# 121 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning)."))) __attribute__((unused)) static inline int __shfl_up(int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 121
{ } 
#endif
# 122 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning)."))) __attribute__((unused)) static inline unsigned __shfl_up(unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 122
{ } 
#endif
# 123 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning)."))) __attribute__((unused)) static inline int __shfl_down(int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 123
{ } 
#endif
# 124 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning)."))) __attribute__((unused)) static inline unsigned __shfl_down(unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 124
{ } 
#endif
# 125 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning)."))) __attribute__((unused)) static inline int __shfl_xor(int var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 125
{ } 
#endif
# 126 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning)."))) __attribute__((unused)) static inline unsigned __shfl_xor(unsigned var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 126
{ } 
#endif
# 127 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning)."))) __attribute__((unused)) static inline float __shfl(float var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 127
{ } 
#endif
# 128 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning)."))) __attribute__((unused)) static inline float __shfl_up(float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 128
{ } 
#endif
# 129 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning)."))) __attribute__((unused)) static inline float __shfl_down(float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 129
{ } 
#endif
# 130 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning)."))) __attribute__((unused)) static inline float __shfl_xor(float var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 130
{ } 
#endif
# 133 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __shfl_sync(unsigned mask, int var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 133
{ } 
#endif
# 134 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __shfl_sync(unsigned mask, unsigned var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 134
{ } 
#endif
# 135 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __shfl_up_sync(unsigned mask, int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 135
{ } 
#endif
# 136 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __shfl_up_sync(unsigned mask, unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 136
{ } 
#endif
# 137 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __shfl_down_sync(unsigned mask, int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 137
{ } 
#endif
# 138 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __shfl_down_sync(unsigned mask, unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 138
{ } 
#endif
# 139 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __shfl_xor_sync(unsigned mask, int var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 139
{ } 
#endif
# 140 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __shfl_xor_sync(unsigned mask, unsigned var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 140
{ } 
#endif
# 141 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline float __shfl_sync(unsigned mask, float var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 141
{ } 
#endif
# 142 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline float __shfl_up_sync(unsigned mask, float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 142
{ } 
#endif
# 143 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline float __shfl_down_sync(unsigned mask, float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 143
{ } 
#endif
# 144 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline float __shfl_xor_sync(unsigned mask, float var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 144
{ } 
#endif
# 148 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning)."))) __attribute__((unused)) static inline unsigned long long __shfl(unsigned long long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 148
{ } 
#endif
# 149 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning)."))) __attribute__((unused)) static inline long long __shfl(long long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 149
{ } 
#endif
# 150 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning)."))) __attribute__((unused)) static inline long long __shfl_up(long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 150
{ } 
#endif
# 151 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning)."))) __attribute__((unused)) static inline unsigned long long __shfl_up(unsigned long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 151
{ } 
#endif
# 152 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning)."))) __attribute__((unused)) static inline long long __shfl_down(long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 152
{ } 
#endif
# 153 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning)."))) __attribute__((unused)) static inline unsigned long long __shfl_down(unsigned long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 153
{ } 
#endif
# 154 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning)."))) __attribute__((unused)) static inline long long __shfl_xor(long long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 154
{ } 
#endif
# 155 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning)."))) __attribute__((unused)) static inline unsigned long long __shfl_xor(unsigned long long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 155
{ } 
#endif
# 156 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning)."))) __attribute__((unused)) static inline double __shfl(double var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 156
{ } 
#endif
# 157 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning)."))) __attribute__((unused)) static inline double __shfl_up(double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 157
{ } 
#endif
# 158 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning)."))) __attribute__((unused)) static inline double __shfl_down(double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 158
{ } 
#endif
# 159 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning)."))) __attribute__((unused)) static inline double __shfl_xor(double var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 159
{ } 
#endif
# 162 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long long __shfl_sync(unsigned mask, long long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 162
{ } 
#endif
# 163 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __shfl_sync(unsigned mask, unsigned long long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 163
{ } 
#endif
# 164 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long long __shfl_up_sync(unsigned mask, long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 164
{ } 
#endif
# 165 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __shfl_up_sync(unsigned mask, unsigned long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 165
{ } 
#endif
# 166 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long long __shfl_down_sync(unsigned mask, long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 166
{ } 
#endif
# 167 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __shfl_down_sync(unsigned mask, unsigned long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 167
{ } 
#endif
# 168 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long long __shfl_xor_sync(unsigned mask, long long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 168
{ } 
#endif
# 169 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __shfl_xor_sync(unsigned mask, unsigned long long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 169
{ } 
#endif
# 170 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline double __shfl_sync(unsigned mask, double var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 170
{ } 
#endif
# 171 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline double __shfl_up_sync(unsigned mask, double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 171
{ } 
#endif
# 172 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline double __shfl_down_sync(unsigned mask, double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 172
{ } 
#endif
# 173 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline double __shfl_xor_sync(unsigned mask, double var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 173
{ } 
#endif
# 177 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning)."))) __attribute__((unused)) static inline long __shfl(long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 177
{ } 
#endif
# 178 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning)."))) __attribute__((unused)) static inline unsigned long __shfl(unsigned long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 178
{ } 
#endif
# 179 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning)."))) __attribute__((unused)) static inline long __shfl_up(long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 179
{ } 
#endif
# 180 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning)."))) __attribute__((unused)) static inline unsigned long __shfl_up(unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 180
{ } 
#endif
# 181 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning)."))) __attribute__((unused)) static inline long __shfl_down(long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 181
{ } 
#endif
# 182 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning)."))) __attribute__((unused)) static inline unsigned long __shfl_down(unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 182
{ } 
#endif
# 183 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning)."))) __attribute__((unused)) static inline long __shfl_xor(long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 183
{ } 
#endif
# 184 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute((deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning)."))) __attribute__((unused)) static inline unsigned long __shfl_xor(unsigned long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 184
{ } 
#endif
# 187 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long __shfl_sync(unsigned mask, long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 187
{ } 
#endif
# 188 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long __shfl_sync(unsigned mask, unsigned long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 188
{ } 
#endif
# 189 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long __shfl_up_sync(unsigned mask, long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 189
{ } 
#endif
# 190 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long __shfl_up_sync(unsigned mask, unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 190
{ } 
#endif
# 191 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long __shfl_down_sync(unsigned mask, long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 191
{ } 
#endif
# 192 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long __shfl_down_sync(unsigned mask, unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 192
{ } 
#endif
# 193 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long __shfl_xor_sync(unsigned mask, long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 193
{ } 
#endif
# 194 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long __shfl_xor_sync(unsigned mask, unsigned long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 194
{ } 
#endif
# 87 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldg(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 87
{ } 
#endif
# 88 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldg(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 88
{ } 
#endif
# 90 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldg(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 90
{ } 
#endif
# 91 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldg(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 91
{ } 
#endif
# 92 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldg(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 92
{ } 
#endif
# 93 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldg(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 93
{ } 
#endif
# 94 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldg(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 94
{ } 
#endif
# 95 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldg(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 95
{ } 
#endif
# 96 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldg(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 96
{ } 
#endif
# 97 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldg(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 97
{ } 
#endif
# 98 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldg(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 98
{ } 
#endif
# 99 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldg(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 99
{ } 
#endif
# 100 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldg(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 100
{ } 
#endif
# 101 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldg(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 101
{ } 
#endif
# 103 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldg(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 103
{ } 
#endif
# 104 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldg(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 104
{ } 
#endif
# 105 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldg(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 105
{ } 
#endif
# 106 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldg(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 106
{ } 
#endif
# 107 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldg(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 107
{ } 
#endif
# 108 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldg(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 108
{ } 
#endif
# 109 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldg(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 109
{ } 
#endif
# 110 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldg(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 110
{ } 
#endif
# 111 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldg(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 111
{ } 
#endif
# 112 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldg(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 112
{ } 
#endif
# 113 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldg(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 113
{ } 
#endif
# 115 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldg(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 115
{ } 
#endif
# 116 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldg(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 116
{ } 
#endif
# 117 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldg(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 117
{ } 
#endif
# 118 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldg(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 118
{ } 
#endif
# 119 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldg(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 119
{ } 
#endif
# 123 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldcg(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 123
{ } 
#endif
# 124 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldcg(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 124
{ } 
#endif
# 126 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldcg(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 126
{ } 
#endif
# 127 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldcg(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 127
{ } 
#endif
# 128 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldcg(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 128
{ } 
#endif
# 129 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldcg(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 129
{ } 
#endif
# 130 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldcg(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 130
{ } 
#endif
# 131 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldcg(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 131
{ } 
#endif
# 132 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldcg(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 132
{ } 
#endif
# 133 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldcg(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 133
{ } 
#endif
# 134 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldcg(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 134
{ } 
#endif
# 135 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldcg(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 135
{ } 
#endif
# 136 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldcg(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 136
{ } 
#endif
# 137 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldcg(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 137
{ } 
#endif
# 139 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldcg(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 139
{ } 
#endif
# 140 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldcg(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 140
{ } 
#endif
# 141 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldcg(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 141
{ } 
#endif
# 142 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldcg(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 142
{ } 
#endif
# 143 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldcg(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 143
{ } 
#endif
# 144 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldcg(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 144
{ } 
#endif
# 145 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldcg(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 145
{ } 
#endif
# 146 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldcg(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 146
{ } 
#endif
# 147 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldcg(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 147
{ } 
#endif
# 148 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldcg(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 148
{ } 
#endif
# 149 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldcg(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 149
{ } 
#endif
# 151 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldcg(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 151
{ } 
#endif
# 152 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldcg(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 152
{ } 
#endif
# 153 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldcg(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 153
{ } 
#endif
# 154 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldcg(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 154
{ } 
#endif
# 155 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldcg(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 155
{ } 
#endif
# 159 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldca(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 159
{ } 
#endif
# 160 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldca(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 160
{ } 
#endif
# 162 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldca(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 162
{ } 
#endif
# 163 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldca(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 163
{ } 
#endif
# 164 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldca(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 164
{ } 
#endif
# 165 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldca(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 165
{ } 
#endif
# 166 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldca(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 166
{ } 
#endif
# 167 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldca(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 167
{ } 
#endif
# 168 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldca(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 168
{ } 
#endif
# 169 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldca(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 169
{ } 
#endif
# 170 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldca(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 170
{ } 
#endif
# 171 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldca(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 171
{ } 
#endif
# 172 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldca(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 172
{ } 
#endif
# 173 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldca(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 173
{ } 
#endif
# 175 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldca(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 175
{ } 
#endif
# 176 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldca(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 176
{ } 
#endif
# 177 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldca(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 177
{ } 
#endif
# 178 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldca(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 178
{ } 
#endif
# 179 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldca(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 179
{ } 
#endif
# 180 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldca(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 180
{ } 
#endif
# 181 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldca(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 181
{ } 
#endif
# 182 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldca(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 182
{ } 
#endif
# 183 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldca(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 183
{ } 
#endif
# 184 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldca(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 184
{ } 
#endif
# 185 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldca(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 185
{ } 
#endif
# 187 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldca(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 187
{ } 
#endif
# 188 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldca(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 188
{ } 
#endif
# 189 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldca(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 189
{ } 
#endif
# 190 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldca(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 190
{ } 
#endif
# 191 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldca(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 191
{ } 
#endif
# 195 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldcs(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 195
{ } 
#endif
# 196 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldcs(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 196
{ } 
#endif
# 198 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldcs(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 198
{ } 
#endif
# 199 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldcs(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 199
{ } 
#endif
# 200 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldcs(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 200
{ } 
#endif
# 201 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldcs(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 201
{ } 
#endif
# 202 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldcs(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 202
{ } 
#endif
# 203 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldcs(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 203
{ } 
#endif
# 204 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldcs(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 204
{ } 
#endif
# 205 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldcs(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 205
{ } 
#endif
# 206 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldcs(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 206
{ } 
#endif
# 207 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldcs(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 207
{ } 
#endif
# 208 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldcs(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 208
{ } 
#endif
# 209 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldcs(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 209
{ } 
#endif
# 211 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldcs(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 211
{ } 
#endif
# 212 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldcs(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 212
{ } 
#endif
# 213 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldcs(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 213
{ } 
#endif
# 214 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldcs(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 214
{ } 
#endif
# 215 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldcs(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 215
{ } 
#endif
# 216 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldcs(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 216
{ } 
#endif
# 217 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldcs(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 217
{ } 
#endif
# 218 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldcs(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 218
{ } 
#endif
# 219 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldcs(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 219
{ } 
#endif
# 220 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldcs(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 220
{ } 
#endif
# 221 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldcs(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 221
{ } 
#endif
# 223 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldcs(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 223
{ } 
#endif
# 224 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldcs(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 224
{ } 
#endif
# 225 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldcs(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 225
{ } 
#endif
# 226 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldcs(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 226
{ } 
#endif
# 227 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldcs(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 227
{ } 
#endif
# 231 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldlu(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 231
{ } 
#endif
# 232 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldlu(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 232
{ } 
#endif
# 234 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldlu(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 234
{ } 
#endif
# 235 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldlu(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 235
{ } 
#endif
# 236 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldlu(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 236
{ } 
#endif
# 237 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldlu(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 237
{ } 
#endif
# 238 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldlu(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 238
{ } 
#endif
# 239 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldlu(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 239
{ } 
#endif
# 240 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldlu(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 240
{ } 
#endif
# 241 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldlu(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 241
{ } 
#endif
# 242 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldlu(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 242
{ } 
#endif
# 243 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldlu(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 243
{ } 
#endif
# 244 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldlu(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 244
{ } 
#endif
# 245 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldlu(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 245
{ } 
#endif
# 247 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldlu(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 247
{ } 
#endif
# 248 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldlu(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 248
{ } 
#endif
# 249 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldlu(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 249
{ } 
#endif
# 250 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldlu(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 250
{ } 
#endif
# 251 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldlu(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 251
{ } 
#endif
# 252 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldlu(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 252
{ } 
#endif
# 253 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldlu(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 253
{ } 
#endif
# 254 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldlu(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 254
{ } 
#endif
# 255 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldlu(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 255
{ } 
#endif
# 256 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldlu(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 256
{ } 
#endif
# 257 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldlu(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 257
{ } 
#endif
# 259 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldlu(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 259
{ } 
#endif
# 260 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldlu(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 260
{ } 
#endif
# 261 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldlu(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 261
{ } 
#endif
# 262 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldlu(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 262
{ } 
#endif
# 263 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldlu(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 263
{ } 
#endif
# 267 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldcv(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 267
{ } 
#endif
# 268 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldcv(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 268
{ } 
#endif
# 270 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldcv(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 270
{ } 
#endif
# 271 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldcv(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 271
{ } 
#endif
# 272 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldcv(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 272
{ } 
#endif
# 273 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldcv(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 273
{ } 
#endif
# 274 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldcv(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 274
{ } 
#endif
# 275 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldcv(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 275
{ } 
#endif
# 276 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldcv(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 276
{ } 
#endif
# 277 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldcv(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 277
{ } 
#endif
# 278 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldcv(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 278
{ } 
#endif
# 279 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldcv(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 279
{ } 
#endif
# 280 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldcv(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 280
{ } 
#endif
# 281 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldcv(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 281
{ } 
#endif
# 283 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldcv(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 283
{ } 
#endif
# 284 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldcv(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 284
{ } 
#endif
# 285 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldcv(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 285
{ } 
#endif
# 286 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldcv(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 286
{ } 
#endif
# 287 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldcv(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 287
{ } 
#endif
# 288 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldcv(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 288
{ } 
#endif
# 289 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldcv(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 289
{ } 
#endif
# 290 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldcv(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 290
{ } 
#endif
# 291 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldcv(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 291
{ } 
#endif
# 292 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldcv(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 292
{ } 
#endif
# 293 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldcv(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 293
{ } 
#endif
# 295 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldcv(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 295
{ } 
#endif
# 296 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldcv(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 296
{ } 
#endif
# 297 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldcv(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 297
{ } 
#endif
# 298 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldcv(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 298
{ } 
#endif
# 299 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldcv(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 299
{ } 
#endif
# 303 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 303
{ } 
#endif
# 304 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 304
{ } 
#endif
# 306 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 306
{ } 
#endif
# 307 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 307
{ } 
#endif
# 308 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 308
{ } 
#endif
# 309 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 309
{ } 
#endif
# 310 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(long long *ptr, long long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 310
{ } 
#endif
# 311 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 311
{ } 
#endif
# 312 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 312
{ } 
#endif
# 313 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 313
{ } 
#endif
# 314 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 314
{ } 
#endif
# 315 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 315
{ } 
#endif
# 316 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 316
{ } 
#endif
# 317 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 317
{ } 
#endif
# 319 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 319
{ } 
#endif
# 320 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 320
{ } 
#endif
# 321 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 321
{ } 
#endif
# 322 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(unsigned long long *ptr, unsigned long long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 322
{ } 
#endif
# 323 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 323
{ } 
#endif
# 324 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 324
{ } 
#endif
# 325 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 325
{ } 
#endif
# 326 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 326
{ } 
#endif
# 327 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 327
{ } 
#endif
# 328 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 328
{ } 
#endif
# 329 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 329
{ } 
#endif
# 331 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 331
{ } 
#endif
# 332 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 332
{ } 
#endif
# 333 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 333
{ } 
#endif
# 334 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 334
{ } 
#endif
# 335 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwb(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 335
{ } 
#endif
# 339 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 339
{ } 
#endif
# 340 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 340
{ } 
#endif
# 342 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 342
{ } 
#endif
# 343 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 343
{ } 
#endif
# 344 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 344
{ } 
#endif
# 345 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 345
{ } 
#endif
# 346 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(long long *ptr, long long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 346
{ } 
#endif
# 347 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 347
{ } 
#endif
# 348 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 348
{ } 
#endif
# 349 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 349
{ } 
#endif
# 350 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 350
{ } 
#endif
# 351 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 351
{ } 
#endif
# 352 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 352
{ } 
#endif
# 353 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 353
{ } 
#endif
# 355 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 355
{ } 
#endif
# 356 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 356
{ } 
#endif
# 357 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 357
{ } 
#endif
# 358 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(unsigned long long *ptr, unsigned long long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 358
{ } 
#endif
# 359 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 359
{ } 
#endif
# 360 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 360
{ } 
#endif
# 361 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 361
{ } 
#endif
# 362 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 362
{ } 
#endif
# 363 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 363
{ } 
#endif
# 364 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 364
{ } 
#endif
# 365 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 365
{ } 
#endif
# 367 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 367
{ } 
#endif
# 368 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 368
{ } 
#endif
# 369 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 369
{ } 
#endif
# 370 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 370
{ } 
#endif
# 371 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcg(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 371
{ } 
#endif
# 375 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 375
{ } 
#endif
# 376 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 376
{ } 
#endif
# 378 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 378
{ } 
#endif
# 379 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 379
{ } 
#endif
# 380 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 380
{ } 
#endif
# 381 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 381
{ } 
#endif
# 382 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(long long *ptr, long long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 382
{ } 
#endif
# 383 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 383
{ } 
#endif
# 384 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 384
{ } 
#endif
# 385 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 385
{ } 
#endif
# 386 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 386
{ } 
#endif
# 387 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 387
{ } 
#endif
# 388 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 388
{ } 
#endif
# 389 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 389
{ } 
#endif
# 391 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 391
{ } 
#endif
# 392 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 392
{ } 
#endif
# 393 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 393
{ } 
#endif
# 394 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(unsigned long long *ptr, unsigned long long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 394
{ } 
#endif
# 395 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 395
{ } 
#endif
# 396 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 396
{ } 
#endif
# 397 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 397
{ } 
#endif
# 398 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 398
{ } 
#endif
# 399 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 399
{ } 
#endif
# 400 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 400
{ } 
#endif
# 401 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 401
{ } 
#endif
# 403 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 403
{ } 
#endif
# 404 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 404
{ } 
#endif
# 405 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 405
{ } 
#endif
# 406 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 406
{ } 
#endif
# 407 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stcs(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 407
{ } 
#endif
# 411 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 411
{ } 
#endif
# 412 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 412
{ } 
#endif
# 414 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 414
{ } 
#endif
# 415 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 415
{ } 
#endif
# 416 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 416
{ } 
#endif
# 417 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 417
{ } 
#endif
# 418 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(long long *ptr, long long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 418
{ } 
#endif
# 419 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 419
{ } 
#endif
# 420 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 420
{ } 
#endif
# 421 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 421
{ } 
#endif
# 422 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 422
{ } 
#endif
# 423 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 423
{ } 
#endif
# 424 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 424
{ } 
#endif
# 425 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 425
{ } 
#endif
# 427 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 427
{ } 
#endif
# 428 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 428
{ } 
#endif
# 429 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 429
{ } 
#endif
# 430 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(unsigned long long *ptr, unsigned long long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 430
{ } 
#endif
# 431 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 431
{ } 
#endif
# 432 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 432
{ } 
#endif
# 433 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 433
{ } 
#endif
# 434 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 434
{ } 
#endif
# 435 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 435
{ } 
#endif
# 436 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 436
{ } 
#endif
# 437 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 437
{ } 
#endif
# 439 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 439
{ } 
#endif
# 440 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 440
{ } 
#endif
# 441 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 441
{ } 
#endif
# 442 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 442
{ } 
#endif
# 443 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline void __stwt(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
# 443
{ } 
#endif
# 460 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __funnelshift_l(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
# 460
{ } 
#endif
# 472 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __funnelshift_lc(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
# 472
{ } 
#endif
# 485 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __funnelshift_r(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
# 485
{ } 
#endif
# 497 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __funnelshift_rc(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
# 497
{ } 
#endif
# 89 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp2a_lo(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 89
{ } 
#endif
# 90 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp2a_lo(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 90
{ } 
#endif
# 92 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp2a_lo(short2 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 92
{ } 
#endif
# 93 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp2a_lo(ushort2 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 93
{ } 
#endif
# 95 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp2a_hi(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 95
{ } 
#endif
# 96 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp2a_hi(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 96
{ } 
#endif
# 98 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp2a_hi(short2 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 98
{ } 
#endif
# 99 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp2a_hi(ushort2 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 99
{ } 
#endif
# 106 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp4a(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 106
{ } 
#endif
# 107 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp4a(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 107
{ } 
#endif
# 109 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp4a(char4 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 109
{ } 
#endif
# 110 "/usr/local/cuda/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp4a(uchar4 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 110
{ } 
#endif
# 93 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_any_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 93
{ } 
#endif
# 94 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_any_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 94
{ } 
#endif
# 95 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_any_sync(unsigned mask, unsigned long value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 95
{ } 
#endif
# 96 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_any_sync(unsigned mask, long value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 96
{ } 
#endif
# 97 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_any_sync(unsigned mask, unsigned long long value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 97
{ } 
#endif
# 98 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_any_sync(unsigned mask, long long value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 98
{ } 
#endif
# 99 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_any_sync(unsigned mask, float value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 99
{ } 
#endif
# 100 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_any_sync(unsigned mask, double value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 100
{ } 
#endif
# 102 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_all_sync(unsigned mask, unsigned value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
# 102
{ } 
#endif
# 103 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_all_sync(unsigned mask, int value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
# 103
{ } 
#endif
# 104 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_all_sync(unsigned mask, unsigned long value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
# 104
{ } 
#endif
# 105 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_all_sync(unsigned mask, long value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
# 105
{ } 
#endif
# 106 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_all_sync(unsigned mask, unsigned long long value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
# 106
{ } 
#endif
# 107 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_all_sync(unsigned mask, long long value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
# 107
{ } 
#endif
# 108 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_all_sync(unsigned mask, float value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
# 108
{ } 
#endif
# 109 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned __match_all_sync(unsigned mask, double value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
# 109
{ } 
#endif
# 111 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline void __nanosleep(unsigned ns) {int volatile ___ = 1;(void)ns;::exit(___);}
#if 0
# 111
{ } 
#endif
# 113 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_70_rt.h"
__attribute__((unused)) static inline unsigned short atomicCAS(unsigned short *address, unsigned short compare, unsigned short val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 113
{ } 
#endif
# 93 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_80_rt.h"
__attribute__((unused)) static inline unsigned __reduce_add_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 93
{ } 
#endif
# 94 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_80_rt.h"
__attribute__((unused)) static inline unsigned __reduce_min_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 94
{ } 
#endif
# 95 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_80_rt.h"
__attribute__((unused)) static inline unsigned __reduce_max_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 95
{ } 
#endif
# 97 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_80_rt.h"
__attribute__((unused)) static inline int __reduce_add_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 97
{ } 
#endif
# 98 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_80_rt.h"
__attribute__((unused)) static inline int __reduce_min_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 98
{ } 
#endif
# 99 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_80_rt.h"
__attribute__((unused)) static inline int __reduce_max_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 99
{ } 
#endif
# 101 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_80_rt.h"
__attribute__((unused)) static inline unsigned __reduce_and_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 101
{ } 
#endif
# 102 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_80_rt.h"
__attribute__((unused)) static inline unsigned __reduce_or_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 102
{ } 
#endif
# 103 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/sm_80_rt.h"
__attribute__((unused)) static inline unsigned __reduce_xor_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
# 103
{ } 
#endif
# 122 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 123
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf1Dread(T *res, surface< void, 1>  surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 124
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)s;(void)mode;
# 128
::exit(___);}
#if 0
# 124
{ 
# 128
} 
#endif
# 130 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 131
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline T surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 132
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 138
::exit(___);}
#if 0
# 132
{ 
# 138
} 
#endif
# 140 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 141
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf1Dread(T *res, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 142
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)mode;
# 146
::exit(___);}
#if 0
# 142
{ 
# 146
} 
#endif
# 149 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 150
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf2Dread(T *res, surface< void, 2>  surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 151
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)s;(void)mode;
# 155
::exit(___);}
#if 0
# 151
{ 
# 155
} 
#endif
# 157 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 158
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline T surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 159
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 165
::exit(___);}
#if 0
# 159
{ 
# 165
} 
#endif
# 167 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 168
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf2Dread(T *res, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 169
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)mode;
# 173
::exit(___);}
#if 0
# 169
{ 
# 173
} 
#endif
# 176 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 177
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf3Dread(T *res, surface< void, 3>  surf, int x, int y, int z, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 178
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)z;(void)s;(void)mode;
# 182
::exit(___);}
#if 0
# 178
{ 
# 182
} 
#endif
# 184 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 185
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline T surf3Dread(surface< void, 3>  surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 186
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 192
::exit(___);}
#if 0
# 186
{ 
# 192
} 
#endif
# 194 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 195
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf3Dread(T *res, surface< void, 3>  surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 196
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 200
::exit(___);}
#if 0
# 196
{ 
# 200
} 
#endif
# 204 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 205
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf1DLayeredread(T *res, surface< void, 241>  surf, int x, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 206
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)layer;(void)s;(void)mode;
# 210
::exit(___);}
#if 0
# 206
{ 
# 210
} 
#endif
# 212 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 213
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline T surf1DLayeredread(surface< void, 241>  surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 214
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 220
::exit(___);}
#if 0
# 214
{ 
# 220
} 
#endif
# 223 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 224
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf1DLayeredread(T *res, surface< void, 241>  surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 225
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)layer;(void)mode;
# 229
::exit(___);}
#if 0
# 225
{ 
# 229
} 
#endif
# 232 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 233
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf2DLayeredread(T *res, surface< void, 242>  surf, int x, int y, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 234
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layer;(void)s;(void)mode;
# 238
::exit(___);}
#if 0
# 234
{ 
# 238
} 
#endif
# 240 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 241
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline T surf2DLayeredread(surface< void, 242>  surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 242
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 248
::exit(___);}
#if 0
# 242
{ 
# 248
} 
#endif
# 251 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 252
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf2DLayeredread(T *res, surface< void, 242>  surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 253
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 257
::exit(___);}
#if 0
# 253
{ 
# 257
} 
#endif
# 260 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 261
__attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapread(T *res, surface< void, 12>  surf, int x, int y, int face, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 262
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)face;(void)s;(void)mode;
# 266
::exit(___);}
#if 0
# 262
{ 
# 266
} 
#endif
# 268 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 269
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline T surfCubemapread(surface< void, 12>  surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 270
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 277
::exit(___);}
#if 0
# 270
{ 
# 277
} 
#endif
# 279 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 280
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapread(T *res, surface< void, 12>  surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 281
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 285
::exit(___);}
#if 0
# 281
{ 
# 285
} 
#endif
# 288 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 289
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapLayeredread(T *res, surface< void, 252>  surf, int x, int y, int layerFace, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 290
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layerFace;(void)s;(void)mode;
# 294
::exit(___);}
#if 0
# 290
{ 
# 294
} 
#endif
# 296 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 297
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline T surfCubemapLayeredread(surface< void, 252>  surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 298
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 304
::exit(___);}
#if 0
# 298
{ 
# 304
} 
#endif
# 306 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 307
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapLayeredread(T *res, surface< void, 252>  surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 308
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 312
::exit(___);}
#if 0
# 308
{ 
# 312
} 
#endif
# 315 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 316
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf1Dwrite(T val, surface< void, 1>  surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 317
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)s;(void)mode;
# 321
::exit(___);}
#if 0
# 317
{ 
# 321
} 
#endif
# 323 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 324
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf1Dwrite(T val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 325
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 329
::exit(___);}
#if 0
# 325
{ 
# 329
} 
#endif
# 333 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 334
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf2Dwrite(T val, surface< void, 2>  surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 335
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)s;(void)mode;
# 339
::exit(___);}
#if 0
# 335
{ 
# 339
} 
#endif
# 341 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 342
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf2Dwrite(T val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 343
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 347
::exit(___);}
#if 0
# 343
{ 
# 347
} 
#endif
# 350 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 351
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf3Dwrite(T val, surface< void, 3>  surf, int x, int y, int z, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 352
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)s;(void)mode;
# 356
::exit(___);}
#if 0
# 352
{ 
# 356
} 
#endif
# 358 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 359
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf3Dwrite(T val, surface< void, 3>  surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 360
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 364
::exit(___);}
#if 0
# 360
{ 
# 364
} 
#endif
# 367 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 368
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf1DLayeredwrite(T val, surface< void, 241>  surf, int x, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 369
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)s;(void)mode;
# 373
::exit(___);}
#if 0
# 369
{ 
# 373
} 
#endif
# 375 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 376
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf1DLayeredwrite(T val, surface< void, 241>  surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 377
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 381
::exit(___);}
#if 0
# 377
{ 
# 381
} 
#endif
# 384 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 385
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf2DLayeredwrite(T val, surface< void, 242>  surf, int x, int y, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 386
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)s;(void)mode;
# 390
::exit(___);}
#if 0
# 386
{ 
# 390
} 
#endif
# 392 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 393
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surf2DLayeredwrite(T val, surface< void, 242>  surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 394
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 398
::exit(___);}
#if 0
# 394
{ 
# 398
} 
#endif
# 401 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 402
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapwrite(T val, surface< void, 12>  surf, int x, int y, int face, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 403
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)s;(void)mode;
# 407
::exit(___);}
#if 0
# 403
{ 
# 407
} 
#endif
# 409 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 410
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapwrite(T val, surface< void, 12>  surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 411
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 415
::exit(___);}
#if 0
# 411
{ 
# 415
} 
#endif
# 419 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 420
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapLayeredwrite(T val, surface< void, 252>  surf, int x, int y, int layerFace, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 421
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)s;(void)mode;
# 425
::exit(___);}
#if 0
# 421
{ 
# 425
} 
#endif
# 427 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 428
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapLayeredwrite(T val, surface< void, 252>  surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 429
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 433
::exit(___);}
#if 0
# 429
{ 
# 433
} 
#endif
# 72 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 73
struct __nv_tex_rmet_ret { }; 
# 75
template<> struct __nv_tex_rmet_ret< char>  { typedef char type; }; 
# 76
template<> struct __nv_tex_rmet_ret< signed char>  { typedef signed char type; }; 
# 77
template<> struct __nv_tex_rmet_ret< unsigned char>  { typedef unsigned char type; }; 
# 78
template<> struct __nv_tex_rmet_ret< char1>  { typedef char1 type; }; 
# 79
template<> struct __nv_tex_rmet_ret< uchar1>  { typedef uchar1 type; }; 
# 80
template<> struct __nv_tex_rmet_ret< char2>  { typedef char2 type; }; 
# 81
template<> struct __nv_tex_rmet_ret< uchar2>  { typedef uchar2 type; }; 
# 82
template<> struct __nv_tex_rmet_ret< char4>  { typedef char4 type; }; 
# 83
template<> struct __nv_tex_rmet_ret< uchar4>  { typedef uchar4 type; }; 
# 85
template<> struct __nv_tex_rmet_ret< short>  { typedef short type; }; 
# 86
template<> struct __nv_tex_rmet_ret< unsigned short>  { typedef unsigned short type; }; 
# 87
template<> struct __nv_tex_rmet_ret< short1>  { typedef short1 type; }; 
# 88
template<> struct __nv_tex_rmet_ret< ushort1>  { typedef ushort1 type; }; 
# 89
template<> struct __nv_tex_rmet_ret< short2>  { typedef short2 type; }; 
# 90
template<> struct __nv_tex_rmet_ret< ushort2>  { typedef ushort2 type; }; 
# 91
template<> struct __nv_tex_rmet_ret< short4>  { typedef short4 type; }; 
# 92
template<> struct __nv_tex_rmet_ret< ushort4>  { typedef ushort4 type; }; 
# 94
template<> struct __nv_tex_rmet_ret< int>  { typedef int type; }; 
# 95
template<> struct __nv_tex_rmet_ret< unsigned>  { typedef unsigned type; }; 
# 96
template<> struct __nv_tex_rmet_ret< int1>  { typedef int1 type; }; 
# 97
template<> struct __nv_tex_rmet_ret< uint1>  { typedef uint1 type; }; 
# 98
template<> struct __nv_tex_rmet_ret< int2>  { typedef int2 type; }; 
# 99
template<> struct __nv_tex_rmet_ret< uint2>  { typedef uint2 type; }; 
# 100
template<> struct __nv_tex_rmet_ret< int4>  { typedef int4 type; }; 
# 101
template<> struct __nv_tex_rmet_ret< uint4>  { typedef uint4 type; }; 
# 113 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template<> struct __nv_tex_rmet_ret< float>  { typedef float type; }; 
# 114
template<> struct __nv_tex_rmet_ret< float1>  { typedef float1 type; }; 
# 115
template<> struct __nv_tex_rmet_ret< float2>  { typedef float2 type; }; 
# 116
template<> struct __nv_tex_rmet_ret< float4>  { typedef float4 type; }; 
# 119
template< class T> struct __nv_tex_rmet_cast { typedef T *type; }; 
# 131 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 132
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex1Dfetch(texture< T, 1, cudaReadModeElementType>  t, int x) 
# 133
{int volatile ___ = 1;(void)t;(void)x;
# 139
::exit(___);}
#if 0
# 133
{ 
# 139
} 
#endif
# 141 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 142
struct __nv_tex_rmnf_ret { }; 
# 144
template<> struct __nv_tex_rmnf_ret< char>  { typedef float type; }; 
# 145
template<> struct __nv_tex_rmnf_ret< signed char>  { typedef float type; }; 
# 146
template<> struct __nv_tex_rmnf_ret< unsigned char>  { typedef float type; }; 
# 147
template<> struct __nv_tex_rmnf_ret< short>  { typedef float type; }; 
# 148
template<> struct __nv_tex_rmnf_ret< unsigned short>  { typedef float type; }; 
# 149
template<> struct __nv_tex_rmnf_ret< char1>  { typedef float1 type; }; 
# 150
template<> struct __nv_tex_rmnf_ret< uchar1>  { typedef float1 type; }; 
# 151
template<> struct __nv_tex_rmnf_ret< short1>  { typedef float1 type; }; 
# 152
template<> struct __nv_tex_rmnf_ret< ushort1>  { typedef float1 type; }; 
# 153
template<> struct __nv_tex_rmnf_ret< char2>  { typedef float2 type; }; 
# 154
template<> struct __nv_tex_rmnf_ret< uchar2>  { typedef float2 type; }; 
# 155
template<> struct __nv_tex_rmnf_ret< short2>  { typedef float2 type; }; 
# 156
template<> struct __nv_tex_rmnf_ret< ushort2>  { typedef float2 type; }; 
# 157
template<> struct __nv_tex_rmnf_ret< char4>  { typedef float4 type; }; 
# 158
template<> struct __nv_tex_rmnf_ret< uchar4>  { typedef float4 type; }; 
# 159
template<> struct __nv_tex_rmnf_ret< short4>  { typedef float4 type; }; 
# 160
template<> struct __nv_tex_rmnf_ret< ushort4>  { typedef float4 type; }; 
# 162
template< class T> 
# 163
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex1Dfetch(texture< T, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 164
{int volatile ___ = 1;(void)t;(void)x;
# 171
::exit(___);}
#if 0
# 164
{ 
# 171
} 
#endif
# 174 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 175
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex1D(texture< T, 1, cudaReadModeElementType>  t, float x) 
# 176
{int volatile ___ = 1;(void)t;(void)x;
# 182
::exit(___);}
#if 0
# 176
{ 
# 182
} 
#endif
# 184 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 185
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex1D(texture< T, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 186
{int volatile ___ = 1;(void)t;(void)x;
# 193
::exit(___);}
#if 0
# 186
{ 
# 193
} 
#endif
# 197 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 198
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex2D(texture< T, 2, cudaReadModeElementType>  t, float x, float y) 
# 199
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 206
::exit(___);}
#if 0
# 199
{ 
# 206
} 
#endif
# 208 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 209
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex2D(texture< T, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 210
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 217
::exit(___);}
#if 0
# 210
{ 
# 217
} 
#endif
# 221 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 222
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex1DLayered(texture< T, 241, cudaReadModeElementType>  t, float x, int layer) 
# 223
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 229
::exit(___);}
#if 0
# 223
{ 
# 229
} 
#endif
# 231 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 232
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex1DLayered(texture< T, 241, cudaReadModeNormalizedFloat>  t, float x, int layer) 
# 233
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 240
::exit(___);}
#if 0
# 233
{ 
# 240
} 
#endif
# 244 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 245
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex2DLayered(texture< T, 242, cudaReadModeElementType>  t, float x, float y, int layer) 
# 246
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 252
::exit(___);}
#if 0
# 246
{ 
# 252
} 
#endif
# 254 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 255
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex2DLayered(texture< T, 242, cudaReadModeNormalizedFloat>  t, float x, float y, int layer) 
# 256
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 263
::exit(___);}
#if 0
# 256
{ 
# 263
} 
#endif
# 266 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 267
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex3D(texture< T, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 268
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 274
::exit(___);}
#if 0
# 268
{ 
# 274
} 
#endif
# 276 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 277
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex3D(texture< T, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 278
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 285
::exit(___);}
#if 0
# 278
{ 
# 285
} 
#endif
# 288 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 289
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type texCubemap(texture< T, 12, cudaReadModeElementType>  t, float x, float y, float z) 
# 290
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 296
::exit(___);}
#if 0
# 290
{ 
# 296
} 
#endif
# 298 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 299
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type texCubemap(texture< T, 12, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 300
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 307
::exit(___);}
#if 0
# 300
{ 
# 307
} 
#endif
# 310 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 311
struct __nv_tex2dgather_ret { }; 
# 312
template<> struct __nv_tex2dgather_ret< char>  { typedef char4 type; }; 
# 313
template<> struct __nv_tex2dgather_ret< signed char>  { typedef char4 type; }; 
# 314
template<> struct __nv_tex2dgather_ret< char1>  { typedef char4 type; }; 
# 315
template<> struct __nv_tex2dgather_ret< char2>  { typedef char4 type; }; 
# 316
template<> struct __nv_tex2dgather_ret< char3>  { typedef char4 type; }; 
# 317
template<> struct __nv_tex2dgather_ret< char4>  { typedef char4 type; }; 
# 318
template<> struct __nv_tex2dgather_ret< unsigned char>  { typedef uchar4 type; }; 
# 319
template<> struct __nv_tex2dgather_ret< uchar1>  { typedef uchar4 type; }; 
# 320
template<> struct __nv_tex2dgather_ret< uchar2>  { typedef uchar4 type; }; 
# 321
template<> struct __nv_tex2dgather_ret< uchar3>  { typedef uchar4 type; }; 
# 322
template<> struct __nv_tex2dgather_ret< uchar4>  { typedef uchar4 type; }; 
# 324
template<> struct __nv_tex2dgather_ret< short>  { typedef short4 type; }; 
# 325
template<> struct __nv_tex2dgather_ret< short1>  { typedef short4 type; }; 
# 326
template<> struct __nv_tex2dgather_ret< short2>  { typedef short4 type; }; 
# 327
template<> struct __nv_tex2dgather_ret< short3>  { typedef short4 type; }; 
# 328
template<> struct __nv_tex2dgather_ret< short4>  { typedef short4 type; }; 
# 329
template<> struct __nv_tex2dgather_ret< unsigned short>  { typedef ushort4 type; }; 
# 330
template<> struct __nv_tex2dgather_ret< ushort1>  { typedef ushort4 type; }; 
# 331
template<> struct __nv_tex2dgather_ret< ushort2>  { typedef ushort4 type; }; 
# 332
template<> struct __nv_tex2dgather_ret< ushort3>  { typedef ushort4 type; }; 
# 333
template<> struct __nv_tex2dgather_ret< ushort4>  { typedef ushort4 type; }; 
# 335
template<> struct __nv_tex2dgather_ret< int>  { typedef int4 type; }; 
# 336
template<> struct __nv_tex2dgather_ret< int1>  { typedef int4 type; }; 
# 337
template<> struct __nv_tex2dgather_ret< int2>  { typedef int4 type; }; 
# 338
template<> struct __nv_tex2dgather_ret< int3>  { typedef int4 type; }; 
# 339
template<> struct __nv_tex2dgather_ret< int4>  { typedef int4 type; }; 
# 340
template<> struct __nv_tex2dgather_ret< unsigned>  { typedef uint4 type; }; 
# 341
template<> struct __nv_tex2dgather_ret< uint1>  { typedef uint4 type; }; 
# 342
template<> struct __nv_tex2dgather_ret< uint2>  { typedef uint4 type; }; 
# 343
template<> struct __nv_tex2dgather_ret< uint3>  { typedef uint4 type; }; 
# 344
template<> struct __nv_tex2dgather_ret< uint4>  { typedef uint4 type; }; 
# 346
template<> struct __nv_tex2dgather_ret< float>  { typedef float4 type; }; 
# 347
template<> struct __nv_tex2dgather_ret< float1>  { typedef float4 type; }; 
# 348
template<> struct __nv_tex2dgather_ret< float2>  { typedef float4 type; }; 
# 349
template<> struct __nv_tex2dgather_ret< float3>  { typedef float4 type; }; 
# 350
template<> struct __nv_tex2dgather_ret< float4>  { typedef float4 type; }; 
# 352
template< class T> 
# 353
__attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex2dgather_ret< T> ::type tex2Dgather(texture< T, 2, cudaReadModeElementType>  t, float x, float y, int comp = 0) 
# 354
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 361
::exit(___);}
#if 0
# 354
{ 
# 361
} 
#endif
# 364 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> struct __nv_tex2dgather_rmnf_ret { }; 
# 365
template<> struct __nv_tex2dgather_rmnf_ret< char>  { typedef float4 type; }; 
# 366
template<> struct __nv_tex2dgather_rmnf_ret< signed char>  { typedef float4 type; }; 
# 367
template<> struct __nv_tex2dgather_rmnf_ret< unsigned char>  { typedef float4 type; }; 
# 368
template<> struct __nv_tex2dgather_rmnf_ret< char1>  { typedef float4 type; }; 
# 369
template<> struct __nv_tex2dgather_rmnf_ret< uchar1>  { typedef float4 type; }; 
# 370
template<> struct __nv_tex2dgather_rmnf_ret< char2>  { typedef float4 type; }; 
# 371
template<> struct __nv_tex2dgather_rmnf_ret< uchar2>  { typedef float4 type; }; 
# 372
template<> struct __nv_tex2dgather_rmnf_ret< char3>  { typedef float4 type; }; 
# 373
template<> struct __nv_tex2dgather_rmnf_ret< uchar3>  { typedef float4 type; }; 
# 374
template<> struct __nv_tex2dgather_rmnf_ret< char4>  { typedef float4 type; }; 
# 375
template<> struct __nv_tex2dgather_rmnf_ret< uchar4>  { typedef float4 type; }; 
# 376
template<> struct __nv_tex2dgather_rmnf_ret< signed short>  { typedef float4 type; }; 
# 377
template<> struct __nv_tex2dgather_rmnf_ret< unsigned short>  { typedef float4 type; }; 
# 378
template<> struct __nv_tex2dgather_rmnf_ret< short1>  { typedef float4 type; }; 
# 379
template<> struct __nv_tex2dgather_rmnf_ret< ushort1>  { typedef float4 type; }; 
# 380
template<> struct __nv_tex2dgather_rmnf_ret< short2>  { typedef float4 type; }; 
# 381
template<> struct __nv_tex2dgather_rmnf_ret< ushort2>  { typedef float4 type; }; 
# 382
template<> struct __nv_tex2dgather_rmnf_ret< short3>  { typedef float4 type; }; 
# 383
template<> struct __nv_tex2dgather_rmnf_ret< ushort3>  { typedef float4 type; }; 
# 384
template<> struct __nv_tex2dgather_rmnf_ret< short4>  { typedef float4 type; }; 
# 385
template<> struct __nv_tex2dgather_rmnf_ret< ushort4>  { typedef float4 type; }; 
# 387
template< class T> 
# 388
__attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex2dgather_rmnf_ret< T> ::type tex2Dgather(texture< T, 2, cudaReadModeNormalizedFloat>  t, float x, float y, int comp = 0) 
# 389
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 396
::exit(___);}
#if 0
# 389
{ 
# 396
} 
#endif
# 400 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 401
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex1DLod(texture< T, 1, cudaReadModeElementType>  t, float x, float level) 
# 402
{int volatile ___ = 1;(void)t;(void)x;(void)level;
# 408
::exit(___);}
#if 0
# 402
{ 
# 408
} 
#endif
# 410 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 411
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex1DLod(texture< T, 1, cudaReadModeNormalizedFloat>  t, float x, float level) 
# 412
{int volatile ___ = 1;(void)t;(void)x;(void)level;
# 419
::exit(___);}
#if 0
# 412
{ 
# 419
} 
#endif
# 422 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 423
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex2DLod(texture< T, 2, cudaReadModeElementType>  t, float x, float y, float level) 
# 424
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)level;
# 430
::exit(___);}
#if 0
# 424
{ 
# 430
} 
#endif
# 432 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 433
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex2DLod(texture< T, 2, cudaReadModeNormalizedFloat>  t, float x, float y, float level) 
# 434
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)level;
# 441
::exit(___);}
#if 0
# 434
{ 
# 441
} 
#endif
# 444 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 445
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex1DLayeredLod(texture< T, 241, cudaReadModeElementType>  t, float x, int layer, float level) 
# 446
{int volatile ___ = 1;(void)t;(void)x;(void)layer;(void)level;
# 452
::exit(___);}
#if 0
# 446
{ 
# 452
} 
#endif
# 454 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 455
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex1DLayeredLod(texture< T, 241, cudaReadModeNormalizedFloat>  t, float x, int layer, float level) 
# 456
{int volatile ___ = 1;(void)t;(void)x;(void)layer;(void)level;
# 463
::exit(___);}
#if 0
# 456
{ 
# 463
} 
#endif
# 466 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 467
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex2DLayeredLod(texture< T, 242, cudaReadModeElementType>  t, float x, float y, int layer, float level) 
# 468
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;(void)level;
# 474
::exit(___);}
#if 0
# 468
{ 
# 474
} 
#endif
# 476 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 477
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex2DLayeredLod(texture< T, 242, cudaReadModeNormalizedFloat>  t, float x, float y, int layer, float level) 
# 478
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;(void)level;
# 485
::exit(___);}
#if 0
# 478
{ 
# 485
} 
#endif
# 488 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 489
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex3DLod(texture< T, 3, cudaReadModeElementType>  t, float x, float y, float z, float level) 
# 490
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)level;
# 496
::exit(___);}
#if 0
# 490
{ 
# 496
} 
#endif
# 498 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 499
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex3DLod(texture< T, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z, float level) 
# 500
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)level;
# 507
::exit(___);}
#if 0
# 500
{ 
# 507
} 
#endif
# 510 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 511
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type texCubemapLod(texture< T, 12, cudaReadModeElementType>  t, float x, float y, float z, float level) 
# 512
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)level;
# 518
::exit(___);}
#if 0
# 512
{ 
# 518
} 
#endif
# 520 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 521
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type texCubemapLod(texture< T, 12, cudaReadModeNormalizedFloat>  t, float x, float y, float z, float level) 
# 522
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)level;
# 529
::exit(___);}
#if 0
# 522
{ 
# 529
} 
#endif
# 533 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 534
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type texCubemapLayered(texture< T, 252, cudaReadModeElementType>  t, float x, float y, float z, int layer) 
# 535
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 541
::exit(___);}
#if 0
# 535
{ 
# 541
} 
#endif
# 543 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 544
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type texCubemapLayered(texture< T, 252, cudaReadModeNormalizedFloat>  t, float x, float y, float z, int layer) 
# 545
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 552
::exit(___);}
#if 0
# 545
{ 
# 552
} 
#endif
# 556 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 557
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type texCubemapLayeredLod(texture< T, 252, cudaReadModeElementType>  t, float x, float y, float z, int layer, float level) 
# 558
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;(void)level;
# 564
::exit(___);}
#if 0
# 558
{ 
# 564
} 
#endif
# 566 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 567
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type texCubemapLayeredLod(texture< T, 252, cudaReadModeNormalizedFloat>  t, float x, float y, float z, int layer, float level) 
# 568
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;(void)level;
# 575
::exit(___);}
#if 0
# 568
{ 
# 575
} 
#endif
# 579 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 580
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type texCubemapGrad(texture< T, 12, cudaReadModeElementType>  t, float x, float y, float z, float4 dPdx, float4 dPdy) 
# 581
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;
# 587
::exit(___);}
#if 0
# 581
{ 
# 587
} 
#endif
# 589 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 590
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type texCubemapGrad(texture< T, 12, cudaReadModeNormalizedFloat>  t, float x, float y, float z, float4 dPdx, float4 dPdy) 
# 591
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;
# 598
::exit(___);}
#if 0
# 591
{ 
# 598
} 
#endif
# 602 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 603
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type texCubemapLayeredGrad(texture< T, 252, cudaReadModeElementType>  t, float x, float y, float z, int layer, float4 dPdx, float4 dPdy) 
# 604
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;(void)dPdx;(void)dPdy;
# 610
::exit(___);}
#if 0
# 604
{ 
# 610
} 
#endif
# 612 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 613
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type texCubemapLayeredGrad(texture< T, 252, cudaReadModeNormalizedFloat>  t, float x, float y, float z, int layer, float4 dPdx, float4 dPdy) 
# 614
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;(void)dPdx;(void)dPdy;
# 621
::exit(___);}
#if 0
# 614
{ 
# 621
} 
#endif
# 625 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 626
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex1DGrad(texture< T, 1, cudaReadModeElementType>  t, float x, float dPdx, float dPdy) 
# 627
{int volatile ___ = 1;(void)t;(void)x;(void)dPdx;(void)dPdy;
# 633
::exit(___);}
#if 0
# 627
{ 
# 633
} 
#endif
# 635 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 636
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex1DGrad(texture< T, 1, cudaReadModeNormalizedFloat>  t, float x, float dPdx, float dPdy) 
# 637
{int volatile ___ = 1;(void)t;(void)x;(void)dPdx;(void)dPdy;
# 644
::exit(___);}
#if 0
# 637
{ 
# 644
} 
#endif
# 648 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 649
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex2DGrad(texture< T, 2, cudaReadModeElementType>  t, float x, float y, float2 dPdx, float2 dPdy) 
# 650
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)dPdx;(void)dPdy;
# 656
::exit(___);}
#if 0
# 650
{ 
# 656
} 
#endif
# 658 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 659
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex2DGrad(texture< T, 2, cudaReadModeNormalizedFloat>  t, float x, float y, float2 dPdx, float2 dPdy) 
# 660
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)dPdx;(void)dPdy;
# 667
::exit(___);}
#if 0
# 660
{ 
# 667
} 
#endif
# 670 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 671
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex1DLayeredGrad(texture< T, 241, cudaReadModeElementType>  t, float x, int layer, float dPdx, float dPdy) 
# 672
{int volatile ___ = 1;(void)t;(void)x;(void)layer;(void)dPdx;(void)dPdy;
# 678
::exit(___);}
#if 0
# 672
{ 
# 678
} 
#endif
# 680 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 681
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex1DLayeredGrad(texture< T, 241, cudaReadModeNormalizedFloat>  t, float x, int layer, float dPdx, float dPdy) 
# 682
{int volatile ___ = 1;(void)t;(void)x;(void)layer;(void)dPdx;(void)dPdy;
# 689
::exit(___);}
#if 0
# 682
{ 
# 689
} 
#endif
# 692 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 693
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex2DLayeredGrad(texture< T, 242, cudaReadModeElementType>  t, float x, float y, int layer, float2 dPdx, float2 dPdy) 
# 694
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;
# 700
::exit(___);}
#if 0
# 694
{ 
# 700
} 
#endif
# 702 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 703
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex2DLayeredGrad(texture< T, 242, cudaReadModeNormalizedFloat>  t, float x, float y, int layer, float2 dPdx, float2 dPdy) 
# 704
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;
# 711
::exit(___);}
#if 0
# 704
{ 
# 711
} 
#endif
# 714 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 715
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmet_ret< T> ::type tex3DGrad(texture< T, 3, cudaReadModeElementType>  t, float x, float y, float z, float4 dPdx, float4 dPdy) 
# 716
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;
# 722
::exit(___);}
#if 0
# 716
{ 
# 722
} 
#endif
# 724 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 725
__attribute((deprecated)) __attribute((always_inline)) __attribute__((unused)) static inline typename __nv_tex_rmnf_ret< T> ::type tex3DGrad(texture< T, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z, float4 dPdx, float4 dPdy) 
# 726
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;
# 733
::exit(___);}
#if 0
# 726
{ 
# 733
} 
#endif
# 64 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> struct __nv_itex_trait { }; 
# 65
template<> struct __nv_itex_trait< char>  { typedef void type; }; 
# 66
template<> struct __nv_itex_trait< signed char>  { typedef void type; }; 
# 67
template<> struct __nv_itex_trait< char1>  { typedef void type; }; 
# 68
template<> struct __nv_itex_trait< char2>  { typedef void type; }; 
# 69
template<> struct __nv_itex_trait< char4>  { typedef void type; }; 
# 70
template<> struct __nv_itex_trait< unsigned char>  { typedef void type; }; 
# 71
template<> struct __nv_itex_trait< uchar1>  { typedef void type; }; 
# 72
template<> struct __nv_itex_trait< uchar2>  { typedef void type; }; 
# 73
template<> struct __nv_itex_trait< uchar4>  { typedef void type; }; 
# 74
template<> struct __nv_itex_trait< short>  { typedef void type; }; 
# 75
template<> struct __nv_itex_trait< short1>  { typedef void type; }; 
# 76
template<> struct __nv_itex_trait< short2>  { typedef void type; }; 
# 77
template<> struct __nv_itex_trait< short4>  { typedef void type; }; 
# 78
template<> struct __nv_itex_trait< unsigned short>  { typedef void type; }; 
# 79
template<> struct __nv_itex_trait< ushort1>  { typedef void type; }; 
# 80
template<> struct __nv_itex_trait< ushort2>  { typedef void type; }; 
# 81
template<> struct __nv_itex_trait< ushort4>  { typedef void type; }; 
# 82
template<> struct __nv_itex_trait< int>  { typedef void type; }; 
# 83
template<> struct __nv_itex_trait< int1>  { typedef void type; }; 
# 84
template<> struct __nv_itex_trait< int2>  { typedef void type; }; 
# 85
template<> struct __nv_itex_trait< int4>  { typedef void type; }; 
# 86
template<> struct __nv_itex_trait< unsigned>  { typedef void type; }; 
# 87
template<> struct __nv_itex_trait< uint1>  { typedef void type; }; 
# 88
template<> struct __nv_itex_trait< uint2>  { typedef void type; }; 
# 89
template<> struct __nv_itex_trait< uint4>  { typedef void type; }; 
# 100 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template<> struct __nv_itex_trait< float>  { typedef void type; }; 
# 101
template<> struct __nv_itex_trait< float1>  { typedef void type; }; 
# 102
template<> struct __nv_itex_trait< float2>  { typedef void type; }; 
# 103
template<> struct __nv_itex_trait< float4>  { typedef void type; }; 
# 107
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 108
tex1Dfetch(T *ptr, cudaTextureObject_t obj, int x) 
# 109
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;
# 113
::exit(___);}
#if 0
# 109
{ 
# 113
} 
#endif
# 115 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 116
tex1Dfetch(cudaTextureObject_t texObject, int x) 
# 117
{int volatile ___ = 1;(void)texObject;(void)x;
# 123
::exit(___);}
#if 0
# 117
{ 
# 123
} 
#endif
# 125 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 126
tex1D(T *ptr, cudaTextureObject_t obj, float x) 
# 127
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;
# 131
::exit(___);}
#if 0
# 127
{ 
# 131
} 
#endif
# 134 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 135
tex1D(cudaTextureObject_t texObject, float x) 
# 136
{int volatile ___ = 1;(void)texObject;(void)x;
# 142
::exit(___);}
#if 0
# 136
{ 
# 142
} 
#endif
# 145 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 146
tex2D(T *ptr, cudaTextureObject_t obj, float x, float y) 
# 147
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;
# 151
::exit(___);}
#if 0
# 147
{ 
# 151
} 
#endif
# 153 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 154
tex2D(cudaTextureObject_t texObject, float x, float y) 
# 155
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;
# 161
::exit(___);}
#if 0
# 155
{ 
# 161
} 
#endif
# 164 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 165
tex2D(T *ptr, cudaTextureObject_t obj, float x, float y, bool *
# 166
isResident) 
# 167
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)isResident;
# 173
::exit(___);}
#if 0
# 167
{ 
# 173
} 
#endif
# 175 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 176
tex2D(cudaTextureObject_t texObject, float x, float y, bool *isResident) 
# 177
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)isResident;
# 183
::exit(___);}
#if 0
# 177
{ 
# 183
} 
#endif
# 188 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 189
tex3D(T *ptr, cudaTextureObject_t obj, float x, float y, float z) 
# 190
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;
# 194
::exit(___);}
#if 0
# 190
{ 
# 194
} 
#endif
# 196 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 197
tex3D(cudaTextureObject_t texObject, float x, float y, float z) 
# 198
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;
# 204
::exit(___);}
#if 0
# 198
{ 
# 204
} 
#endif
# 207 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 208
tex3D(T *ptr, cudaTextureObject_t obj, float x, float y, float z, bool *
# 209
isResident) 
# 210
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)isResident;
# 216
::exit(___);}
#if 0
# 210
{ 
# 216
} 
#endif
# 218 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 219
tex3D(cudaTextureObject_t texObject, float x, float y, float z, bool *isResident) 
# 220
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)isResident;
# 226
::exit(___);}
#if 0
# 220
{ 
# 226
} 
#endif
# 230 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 231
tex1DLayered(T *ptr, cudaTextureObject_t obj, float x, int layer) 
# 232
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;
# 236
::exit(___);}
#if 0
# 232
{ 
# 236
} 
#endif
# 238 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 239
tex1DLayered(cudaTextureObject_t texObject, float x, int layer) 
# 240
{int volatile ___ = 1;(void)texObject;(void)x;(void)layer;
# 246
::exit(___);}
#if 0
# 240
{ 
# 246
} 
#endif
# 248 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 249
tex2DLayered(T *ptr, cudaTextureObject_t obj, float x, float y, int layer) 
# 250
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;
# 254
::exit(___);}
#if 0
# 250
{ 
# 254
} 
#endif
# 256 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 257
tex2DLayered(cudaTextureObject_t texObject, float x, float y, int layer) 
# 258
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;
# 264
::exit(___);}
#if 0
# 258
{ 
# 264
} 
#endif
# 267 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 268
tex2DLayered(T *ptr, cudaTextureObject_t obj, float x, float y, int layer, bool *isResident) 
# 269
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)isResident;
# 275
::exit(___);}
#if 0
# 269
{ 
# 275
} 
#endif
# 277 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 278
tex2DLayered(cudaTextureObject_t texObject, float x, float y, int layer, bool *isResident) 
# 279
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)isResident;
# 285
::exit(___);}
#if 0
# 279
{ 
# 285
} 
#endif
# 289 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 290
texCubemap(T *ptr, cudaTextureObject_t obj, float x, float y, float z) 
# 291
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;
# 295
::exit(___);}
#if 0
# 291
{ 
# 295
} 
#endif
# 298 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 299
texCubemap(cudaTextureObject_t texObject, float x, float y, float z) 
# 300
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;
# 306
::exit(___);}
#if 0
# 300
{ 
# 306
} 
#endif
# 309 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 310
texCubemapLayered(T *ptr, cudaTextureObject_t obj, float x, float y, float z, int layer) 
# 311
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)layer;
# 315
::exit(___);}
#if 0
# 311
{ 
# 315
} 
#endif
# 317 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 318
texCubemapLayered(cudaTextureObject_t texObject, float x, float y, float z, int layer) 
# 319
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;
# 325
::exit(___);}
#if 0
# 319
{ 
# 325
} 
#endif
# 327 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 328
tex2Dgather(T *ptr, cudaTextureObject_t obj, float x, float y, int comp = 0) 
# 329
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)comp;
# 333
::exit(___);}
#if 0
# 329
{ 
# 333
} 
#endif
# 335 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 336
tex2Dgather(cudaTextureObject_t to, float x, float y, int comp = 0) 
# 337
{int volatile ___ = 1;(void)to;(void)x;(void)y;(void)comp;
# 343
::exit(___);}
#if 0
# 337
{ 
# 343
} 
#endif
# 346 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 347
tex2Dgather(T *ptr, cudaTextureObject_t obj, float x, float y, bool *isResident, int comp = 0) 
# 348
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)isResident;(void)comp;
# 354
::exit(___);}
#if 0
# 348
{ 
# 354
} 
#endif
# 356 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 357
tex2Dgather(cudaTextureObject_t to, float x, float y, bool *isResident, int comp = 0) 
# 358
{int volatile ___ = 1;(void)to;(void)x;(void)y;(void)isResident;(void)comp;
# 364
::exit(___);}
#if 0
# 358
{ 
# 364
} 
#endif
# 368 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 369
tex1DLod(T *ptr, cudaTextureObject_t obj, float x, float level) 
# 370
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)level;
# 374
::exit(___);}
#if 0
# 370
{ 
# 374
} 
#endif
# 376 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 377
tex1DLod(cudaTextureObject_t texObject, float x, float level) 
# 378
{int volatile ___ = 1;(void)texObject;(void)x;(void)level;
# 384
::exit(___);}
#if 0
# 378
{ 
# 384
} 
#endif
# 387 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 388
tex2DLod(T *ptr, cudaTextureObject_t obj, float x, float y, float level) 
# 389
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)level;
# 393
::exit(___);}
#if 0
# 389
{ 
# 393
} 
#endif
# 395 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 396
tex2DLod(cudaTextureObject_t texObject, float x, float y, float level) 
# 397
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)level;
# 403
::exit(___);}
#if 0
# 397
{ 
# 403
} 
#endif
# 407 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 408
tex2DLod(T *ptr, cudaTextureObject_t obj, float x, float y, float level, bool *isResident) 
# 409
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)level;(void)isResident;
# 415
::exit(___);}
#if 0
# 409
{ 
# 415
} 
#endif
# 417 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 418
tex2DLod(cudaTextureObject_t texObject, float x, float y, float level, bool *isResident) 
# 419
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)level;(void)isResident;
# 425
::exit(___);}
#if 0
# 419
{ 
# 425
} 
#endif
# 430 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 431
tex3DLod(T *ptr, cudaTextureObject_t obj, float x, float y, float z, float level) 
# 432
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)level;
# 436
::exit(___);}
#if 0
# 432
{ 
# 436
} 
#endif
# 438 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 439
tex3DLod(cudaTextureObject_t texObject, float x, float y, float z, float level) 
# 440
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;
# 446
::exit(___);}
#if 0
# 440
{ 
# 446
} 
#endif
# 449 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 450
tex3DLod(T *ptr, cudaTextureObject_t obj, float x, float y, float z, float level, bool *isResident) 
# 451
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)level;(void)isResident;
# 457
::exit(___);}
#if 0
# 451
{ 
# 457
} 
#endif
# 459 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 460
tex3DLod(cudaTextureObject_t texObject, float x, float y, float z, float level, bool *isResident) 
# 461
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;(void)isResident;
# 467
::exit(___);}
#if 0
# 461
{ 
# 467
} 
#endif
# 472 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 473
tex1DLayeredLod(T *ptr, cudaTextureObject_t obj, float x, int layer, float level) 
# 474
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;(void)level;
# 478
::exit(___);}
#if 0
# 474
{ 
# 478
} 
#endif
# 480 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 481
tex1DLayeredLod(cudaTextureObject_t texObject, float x, int layer, float level) 
# 482
{int volatile ___ = 1;(void)texObject;(void)x;(void)layer;(void)level;
# 488
::exit(___);}
#if 0
# 482
{ 
# 488
} 
#endif
# 491 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 492
tex2DLayeredLod(T *ptr, cudaTextureObject_t obj, float x, float y, int layer, float level) 
# 493
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)level;
# 497
::exit(___);}
#if 0
# 493
{ 
# 497
} 
#endif
# 499 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 500
tex2DLayeredLod(cudaTextureObject_t texObject, float x, float y, int layer, float level) 
# 501
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)level;
# 507
::exit(___);}
#if 0
# 501
{ 
# 507
} 
#endif
# 510 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 511
tex2DLayeredLod(T *ptr, cudaTextureObject_t obj, float x, float y, int layer, float level, bool *isResident) 
# 512
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)level;(void)isResident;
# 518
::exit(___);}
#if 0
# 512
{ 
# 518
} 
#endif
# 520 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 521
tex2DLayeredLod(cudaTextureObject_t texObject, float x, float y, int layer, float level, bool *isResident) 
# 522
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)level;(void)isResident;
# 528
::exit(___);}
#if 0
# 522
{ 
# 528
} 
#endif
# 531 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 532
texCubemapLod(T *ptr, cudaTextureObject_t obj, float x, float y, float z, float level) 
# 533
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)level;
# 537
::exit(___);}
#if 0
# 533
{ 
# 537
} 
#endif
# 539 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 540
texCubemapLod(cudaTextureObject_t texObject, float x, float y, float z, float level) 
# 541
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;
# 547
::exit(___);}
#if 0
# 541
{ 
# 547
} 
#endif
# 550 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 551
texCubemapGrad(T *ptr, cudaTextureObject_t obj, float x, float y, float z, float4 dPdx, float4 dPdy) 
# 552
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;
# 556
::exit(___);}
#if 0
# 552
{ 
# 556
} 
#endif
# 558 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 559
texCubemapGrad(cudaTextureObject_t texObject, float x, float y, float z, float4 dPdx, float4 dPdy) 
# 560
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;
# 566
::exit(___);}
#if 0
# 560
{ 
# 566
} 
#endif
# 568 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 569
texCubemapLayeredLod(T *ptr, cudaTextureObject_t obj, float x, float y, float z, int layer, float level) 
# 570
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)layer;(void)level;
# 574
::exit(___);}
#if 0
# 570
{ 
# 574
} 
#endif
# 576 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 577
texCubemapLayeredLod(cudaTextureObject_t texObject, float x, float y, float z, int layer, float level) 
# 578
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;(void)level;
# 584
::exit(___);}
#if 0
# 578
{ 
# 584
} 
#endif
# 586 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 587
tex1DGrad(T *ptr, cudaTextureObject_t obj, float x, float dPdx, float dPdy) 
# 588
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)dPdx;(void)dPdy;
# 592
::exit(___);}
#if 0
# 588
{ 
# 592
} 
#endif
# 594 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 595
tex1DGrad(cudaTextureObject_t texObject, float x, float dPdx, float dPdy) 
# 596
{int volatile ___ = 1;(void)texObject;(void)x;(void)dPdx;(void)dPdy;
# 602
::exit(___);}
#if 0
# 596
{ 
# 602
} 
#endif
# 605 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 606
tex2DGrad(T *ptr, cudaTextureObject_t obj, float x, float y, float2 dPdx, float2 dPdy) 
# 607
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)dPdx;(void)dPdy;
# 612
::exit(___);}
#if 0
# 607
{ 
# 612
} 
#endif
# 614 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 615
tex2DGrad(cudaTextureObject_t texObject, float x, float y, float2 dPdx, float2 dPdy) 
# 616
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)dPdx;(void)dPdy;
# 622
::exit(___);}
#if 0
# 616
{ 
# 622
} 
#endif
# 625 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 626
tex2DGrad(T *ptr, cudaTextureObject_t obj, float x, float y, float2 dPdx, float2 dPdy, bool *isResident) 
# 627
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)dPdx;(void)dPdy;(void)isResident;
# 634
::exit(___);}
#if 0
# 627
{ 
# 634
} 
#endif
# 636 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 637
tex2DGrad(cudaTextureObject_t texObject, float x, float y, float2 dPdx, float2 dPdy, bool *isResident) 
# 638
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)dPdx;(void)dPdy;(void)isResident;
# 644
::exit(___);}
#if 0
# 638
{ 
# 644
} 
#endif
# 648 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 649
tex3DGrad(T *ptr, cudaTextureObject_t obj, float x, float y, float z, float4 dPdx, float4 dPdy) 
# 650
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;
# 654
::exit(___);}
#if 0
# 650
{ 
# 654
} 
#endif
# 656 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 657
tex3DGrad(cudaTextureObject_t texObject, float x, float y, float z, float4 dPdx, float4 dPdy) 
# 658
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;
# 664
::exit(___);}
#if 0
# 658
{ 
# 664
} 
#endif
# 667 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 668
tex3DGrad(T *ptr, cudaTextureObject_t obj, float x, float y, float z, float4 dPdx, float4 dPdy, bool *isResident) 
# 669
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;(void)isResident;
# 675
::exit(___);}
#if 0
# 669
{ 
# 675
} 
#endif
# 677 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 678
tex3DGrad(cudaTextureObject_t texObject, float x, float y, float z, float4 dPdx, float4 dPdy, bool *isResident) 
# 679
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;(void)isResident;
# 685
::exit(___);}
#if 0
# 679
{ 
# 685
} 
#endif
# 690 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 691
tex1DLayeredGrad(T *ptr, cudaTextureObject_t obj, float x, int layer, float dPdx, float dPdy) 
# 692
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;(void)dPdx;(void)dPdy;
# 696
::exit(___);}
#if 0
# 692
{ 
# 696
} 
#endif
# 698 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 699
tex1DLayeredGrad(cudaTextureObject_t texObject, float x, int layer, float dPdx, float dPdy) 
# 700
{int volatile ___ = 1;(void)texObject;(void)x;(void)layer;(void)dPdx;(void)dPdy;
# 706
::exit(___);}
#if 0
# 700
{ 
# 706
} 
#endif
# 709 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 710
tex2DLayeredGrad(T *ptr, cudaTextureObject_t obj, float x, float y, int layer, float2 dPdx, float2 dPdy) 
# 711
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;
# 715
::exit(___);}
#if 0
# 711
{ 
# 715
} 
#endif
# 717 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 718
tex2DLayeredGrad(cudaTextureObject_t texObject, float x, float y, int layer, float2 dPdx, float2 dPdy) 
# 719
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;
# 725
::exit(___);}
#if 0
# 719
{ 
# 725
} 
#endif
# 728 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 729
tex2DLayeredGrad(T *ptr, cudaTextureObject_t obj, float x, float y, int layer, float2 dPdx, float2 dPdy, bool *isResident) 
# 730
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;(void)isResident;
# 736
::exit(___);}
#if 0
# 730
{ 
# 736
} 
#endif
# 738 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 739
tex2DLayeredGrad(cudaTextureObject_t texObject, float x, float y, int layer, float2 dPdx, float2 dPdy, bool *isResident) 
# 740
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;(void)isResident;
# 746
::exit(___);}
#if 0
# 740
{ 
# 746
} 
#endif
# 750 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_itex_trait< T> ::type 
# 751
texCubemapLayeredGrad(T *ptr, cudaTextureObject_t obj, float x, float y, float z, int layer, float4 dPdx, float4 dPdy) 
# 752
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)layer;(void)dPdx;(void)dPdy;
# 756
::exit(___);}
#if 0
# 752
{ 
# 756
} 
#endif
# 758 "/usr/local/cuda/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 759
texCubemapLayeredGrad(cudaTextureObject_t texObject, float x, float y, float z, int layer, float4 dPdx, float4 dPdy) 
# 760
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;(void)dPdx;(void)dPdy;
# 766
::exit(___);}
#if 0
# 760
{ 
# 766
} 
#endif
# 59 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> struct __nv_isurf_trait { }; 
# 60
template<> struct __nv_isurf_trait< char>  { typedef void type; }; 
# 61
template<> struct __nv_isurf_trait< signed char>  { typedef void type; }; 
# 62
template<> struct __nv_isurf_trait< char1>  { typedef void type; }; 
# 63
template<> struct __nv_isurf_trait< unsigned char>  { typedef void type; }; 
# 64
template<> struct __nv_isurf_trait< uchar1>  { typedef void type; }; 
# 65
template<> struct __nv_isurf_trait< short>  { typedef void type; }; 
# 66
template<> struct __nv_isurf_trait< short1>  { typedef void type; }; 
# 67
template<> struct __nv_isurf_trait< unsigned short>  { typedef void type; }; 
# 68
template<> struct __nv_isurf_trait< ushort1>  { typedef void type; }; 
# 69
template<> struct __nv_isurf_trait< int>  { typedef void type; }; 
# 70
template<> struct __nv_isurf_trait< int1>  { typedef void type; }; 
# 71
template<> struct __nv_isurf_trait< unsigned>  { typedef void type; }; 
# 72
template<> struct __nv_isurf_trait< uint1>  { typedef void type; }; 
# 73
template<> struct __nv_isurf_trait< long long>  { typedef void type; }; 
# 74
template<> struct __nv_isurf_trait< longlong1>  { typedef void type; }; 
# 75
template<> struct __nv_isurf_trait< unsigned long long>  { typedef void type; }; 
# 76
template<> struct __nv_isurf_trait< ulonglong1>  { typedef void type; }; 
# 77
template<> struct __nv_isurf_trait< float>  { typedef void type; }; 
# 78
template<> struct __nv_isurf_trait< float1>  { typedef void type; }; 
# 80
template<> struct __nv_isurf_trait< char2>  { typedef void type; }; 
# 81
template<> struct __nv_isurf_trait< uchar2>  { typedef void type; }; 
# 82
template<> struct __nv_isurf_trait< short2>  { typedef void type; }; 
# 83
template<> struct __nv_isurf_trait< ushort2>  { typedef void type; }; 
# 84
template<> struct __nv_isurf_trait< int2>  { typedef void type; }; 
# 85
template<> struct __nv_isurf_trait< uint2>  { typedef void type; }; 
# 86
template<> struct __nv_isurf_trait< longlong2>  { typedef void type; }; 
# 87
template<> struct __nv_isurf_trait< ulonglong2>  { typedef void type; }; 
# 88
template<> struct __nv_isurf_trait< float2>  { typedef void type; }; 
# 90
template<> struct __nv_isurf_trait< char4>  { typedef void type; }; 
# 91
template<> struct __nv_isurf_trait< uchar4>  { typedef void type; }; 
# 92
template<> struct __nv_isurf_trait< short4>  { typedef void type; }; 
# 93
template<> struct __nv_isurf_trait< ushort4>  { typedef void type; }; 
# 94
template<> struct __nv_isurf_trait< int4>  { typedef void type; }; 
# 95
template<> struct __nv_isurf_trait< uint4>  { typedef void type; }; 
# 96
template<> struct __nv_isurf_trait< float4>  { typedef void type; }; 
# 99
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 100
surf1Dread(T *ptr, cudaSurfaceObject_t obj, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 101
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)mode;
# 105
::exit(___);}
#if 0
# 101
{ 
# 105
} 
#endif
# 107 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 108
surf1Dread(cudaSurfaceObject_t surfObject, int x, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 109
{int volatile ___ = 1;(void)surfObject;(void)x;(void)boundaryMode;
# 115
::exit(___);}
#if 0
# 109
{ 
# 115
} 
#endif
# 117 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 118
surf2Dread(T *ptr, cudaSurfaceObject_t obj, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 119
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)mode;
# 123
::exit(___);}
#if 0
# 119
{ 
# 123
} 
#endif
# 125 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 126
surf2Dread(cudaSurfaceObject_t surfObject, int x, int y, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 127
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)boundaryMode;
# 133
::exit(___);}
#if 0
# 127
{ 
# 133
} 
#endif
# 136 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 137
surf3Dread(T *ptr, cudaSurfaceObject_t obj, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 138
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)mode;
# 142
::exit(___);}
#if 0
# 138
{ 
# 142
} 
#endif
# 144 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 145
surf3Dread(cudaSurfaceObject_t surfObject, int x, int y, int z, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 146
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)z;(void)boundaryMode;
# 152
::exit(___);}
#if 0
# 146
{ 
# 152
} 
#endif
# 154 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 155
surf1DLayeredread(T *ptr, cudaSurfaceObject_t obj, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 156
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;(void)mode;
# 160
::exit(___);}
#if 0
# 156
{ 
# 160
} 
#endif
# 162 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 163
surf1DLayeredread(cudaSurfaceObject_t surfObject, int x, int layer, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 164
{int volatile ___ = 1;(void)surfObject;(void)x;(void)layer;(void)boundaryMode;
# 170
::exit(___);}
#if 0
# 164
{ 
# 170
} 
#endif
# 172 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 173
surf2DLayeredread(T *ptr, cudaSurfaceObject_t obj, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 174
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)mode;
# 178
::exit(___);}
#if 0
# 174
{ 
# 178
} 
#endif
# 180 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 181
surf2DLayeredread(cudaSurfaceObject_t surfObject, int x, int y, int layer, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 182
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)layer;(void)boundaryMode;
# 188
::exit(___);}
#if 0
# 182
{ 
# 188
} 
#endif
# 190 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 191
surfCubemapread(T *ptr, cudaSurfaceObject_t obj, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 192
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)face;(void)mode;
# 196
::exit(___);}
#if 0
# 192
{ 
# 196
} 
#endif
# 198 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 199
surfCubemapread(cudaSurfaceObject_t surfObject, int x, int y, int face, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 200
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)face;(void)boundaryMode;
# 206
::exit(___);}
#if 0
# 200
{ 
# 206
} 
#endif
# 208 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 209
surfCubemapLayeredread(T *ptr, cudaSurfaceObject_t obj, int x, int y, int layerface, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 210
{int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layerface;(void)mode;
# 214
::exit(___);}
#if 0
# 210
{ 
# 214
} 
#endif
# 216 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 217
surfCubemapLayeredread(cudaSurfaceObject_t surfObject, int x, int y, int layerface, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 218
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)layerface;(void)boundaryMode;
# 224
::exit(___);}
#if 0
# 218
{ 
# 224
} 
#endif
# 226 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 227
surf1Dwrite(T val, cudaSurfaceObject_t obj, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 228
{int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)mode;
# 232
::exit(___);}
#if 0
# 228
{ 
# 232
} 
#endif
# 234 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 235
surf2Dwrite(T val, cudaSurfaceObject_t obj, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 236
{int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)mode;
# 240
::exit(___);}
#if 0
# 236
{ 
# 240
} 
#endif
# 242 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 243
surf3Dwrite(T val, cudaSurfaceObject_t obj, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 244
{int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)z;(void)mode;
# 248
::exit(___);}
#if 0
# 244
{ 
# 248
} 
#endif
# 250 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 251
surf1DLayeredwrite(T val, cudaSurfaceObject_t obj, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 252
{int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)layer;(void)mode;
# 256
::exit(___);}
#if 0
# 252
{ 
# 256
} 
#endif
# 258 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 259
surf2DLayeredwrite(T val, cudaSurfaceObject_t obj, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 260
{int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)layer;(void)mode;
# 264
::exit(___);}
#if 0
# 260
{ 
# 264
} 
#endif
# 266 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 267
surfCubemapwrite(T val, cudaSurfaceObject_t obj, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 268
{int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)face;(void)mode;
# 272
::exit(___);}
#if 0
# 268
{ 
# 272
} 
#endif
# 274 "/usr/local/cuda/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static typename __nv_isurf_trait< T> ::type 
# 275
surfCubemapLayeredwrite(T val, cudaSurfaceObject_t obj, int x, int y, int layerface, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 276
{int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)layerface;(void)mode;
# 280
::exit(___);}
#if 0
# 276
{ 
# 280
} 
#endif
# 3297 "/usr/local/cuda/bin/../targets/x86_64-linux/include/crt/device_functions.h"
extern "C" unsigned __cudaPushCallConfiguration(dim3 gridDim, dim3 blockDim, size_t sharedMem = 0, CUstream_st * stream = 0); 
# 68 "/usr/local/cuda/bin/../targets/x86_64-linux/include/device_launch_parameters.h"
extern "C" {
# 71
extern const uint3 __device_builtin_variable_threadIdx; 
# 72
extern const uint3 __device_builtin_variable_blockIdx; 
# 73
extern const dim3 __device_builtin_variable_blockDim; 
# 74
extern const dim3 __device_builtin_variable_gridDim; 
# 75
extern const int __device_builtin_variable_warpSize; 
# 80
}
# 201 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 202
cudaLaunchKernel(const T *
# 203
func, dim3 
# 204
gridDim, dim3 
# 205
blockDim, void **
# 206
args, size_t 
# 207
sharedMem = 0, cudaStream_t 
# 208
stream = 0) 
# 210
{ 
# 211
return ::cudaLaunchKernel((const void *)func, gridDim, blockDim, args, sharedMem, stream); 
# 212
} 
# 263 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 264
cudaLaunchCooperativeKernel(const T *
# 265
func, dim3 
# 266
gridDim, dim3 
# 267
blockDim, void **
# 268
args, size_t 
# 269
sharedMem = 0, cudaStream_t 
# 270
stream = 0) 
# 272
{ 
# 273
return ::cudaLaunchCooperativeKernel((const void *)func, gridDim, blockDim, args, sharedMem, stream); 
# 274
} 
# 307 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
static inline cudaError_t cudaEventCreate(cudaEvent_t *
# 308
event, unsigned 
# 309
flags) 
# 311
{ 
# 312
return ::cudaEventCreateWithFlags(event, flags); 
# 313
} 
# 372 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
static inline cudaError_t cudaMallocHost(void **
# 373
ptr, size_t 
# 374
size, unsigned 
# 375
flags) 
# 377
{ 
# 378
return ::cudaHostAlloc(ptr, size, flags); 
# 379
} 
# 381
template< class T> static inline cudaError_t 
# 382
cudaHostAlloc(T **
# 383
ptr, size_t 
# 384
size, unsigned 
# 385
flags) 
# 387
{ 
# 388
return ::cudaHostAlloc((void **)((void *)ptr), size, flags); 
# 389
} 
# 391
template< class T> static inline cudaError_t 
# 392
cudaHostGetDevicePointer(T **
# 393
pDevice, void *
# 394
pHost, unsigned 
# 395
flags) 
# 397
{ 
# 398
return ::cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags); 
# 399
} 
# 501 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 502
cudaMallocManaged(T **
# 503
devPtr, size_t 
# 504
size, unsigned 
# 505
flags = 1) 
# 507
{ 
# 508
return ::cudaMallocManaged((void **)((void *)devPtr), size, flags); 
# 509
} 
# 591 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 592
cudaStreamAttachMemAsync(cudaStream_t 
# 593
stream, T *
# 594
devPtr, size_t 
# 595
length = 0, unsigned 
# 596
flags = 4) 
# 598
{ 
# 599
return ::cudaStreamAttachMemAsync(stream, (void *)devPtr, length, flags); 
# 600
} 
# 602
template< class T> inline cudaError_t 
# 603
cudaMalloc(T **
# 604
devPtr, size_t 
# 605
size) 
# 607
{ 
# 608
return ::cudaMalloc((void **)((void *)devPtr), size); 
# 609
} 
# 611
template< class T> static inline cudaError_t 
# 612
cudaMallocHost(T **
# 613
ptr, size_t 
# 614
size, unsigned 
# 615
flags = 0) 
# 617
{ 
# 618
return cudaMallocHost((void **)((void *)ptr), size, flags); 
# 619
} 
# 621
template< class T> static inline cudaError_t 
# 622
cudaMallocPitch(T **
# 623
devPtr, size_t *
# 624
pitch, size_t 
# 625
width, size_t 
# 626
height) 
# 628
{ 
# 629
return ::cudaMallocPitch((void **)((void *)devPtr), pitch, width, height); 
# 630
} 
# 641 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
static inline cudaError_t cudaMallocAsync(void **
# 642
ptr, size_t 
# 643
size, cudaMemPool_t 
# 644
memPool, cudaStream_t 
# 645
stream) 
# 647
{ 
# 648
return ::cudaMallocFromPoolAsync(ptr, size, memPool, stream); 
# 649
} 
# 651
template< class T> static inline cudaError_t 
# 652
cudaMallocAsync(T **
# 653
ptr, size_t 
# 654
size, cudaMemPool_t 
# 655
memPool, cudaStream_t 
# 656
stream) 
# 658
{ 
# 659
return ::cudaMallocFromPoolAsync((void **)((void *)ptr), size, memPool, stream); 
# 660
} 
# 662
template< class T> static inline cudaError_t 
# 663
cudaMallocAsync(T **
# 664
ptr, size_t 
# 665
size, cudaStream_t 
# 666
stream) 
# 668
{ 
# 669
return ::cudaMallocAsync((void **)((void *)ptr), size, stream); 
# 670
} 
# 672
template< class T> static inline cudaError_t 
# 673
cudaMallocFromPoolAsync(T **
# 674
ptr, size_t 
# 675
size, cudaMemPool_t 
# 676
memPool, cudaStream_t 
# 677
stream) 
# 679
{ 
# 680
return ::cudaMallocFromPoolAsync((void **)((void *)ptr), size, memPool, stream); 
# 681
} 
# 720 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 721
cudaMemcpyToSymbol(const T &
# 722
symbol, const void *
# 723
src, size_t 
# 724
count, size_t 
# 725
offset = 0, cudaMemcpyKind 
# 726
kind = cudaMemcpyHostToDevice) 
# 728
{ 
# 729
return ::cudaMemcpyToSymbol((const void *)(&symbol), src, count, offset, kind); 
# 730
} 
# 774 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 775
cudaMemcpyToSymbolAsync(const T &
# 776
symbol, const void *
# 777
src, size_t 
# 778
count, size_t 
# 779
offset = 0, cudaMemcpyKind 
# 780
kind = cudaMemcpyHostToDevice, cudaStream_t 
# 781
stream = 0) 
# 783
{ 
# 784
return ::cudaMemcpyToSymbolAsync((const void *)(&symbol), src, count, offset, kind, stream); 
# 785
} 
# 822 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 823
cudaMemcpyFromSymbol(void *
# 824
dst, const T &
# 825
symbol, size_t 
# 826
count, size_t 
# 827
offset = 0, cudaMemcpyKind 
# 828
kind = cudaMemcpyDeviceToHost) 
# 830
{ 
# 831
return ::cudaMemcpyFromSymbol(dst, (const void *)(&symbol), count, offset, kind); 
# 832
} 
# 876 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 877
cudaMemcpyFromSymbolAsync(void *
# 878
dst, const T &
# 879
symbol, size_t 
# 880
count, size_t 
# 881
offset = 0, cudaMemcpyKind 
# 882
kind = cudaMemcpyDeviceToHost, cudaStream_t 
# 883
stream = 0) 
# 885
{ 
# 886
return ::cudaMemcpyFromSymbolAsync(dst, (const void *)(&symbol), count, offset, kind, stream); 
# 887
} 
# 945 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 946
cudaGraphAddMemcpyNodeToSymbol(cudaGraphNode_t *
# 947
pGraphNode, cudaGraph_t 
# 948
graph, const cudaGraphNode_t *
# 949
pDependencies, size_t 
# 950
numDependencies, const T &
# 951
symbol, const void *
# 952
src, size_t 
# 953
count, size_t 
# 954
offset, cudaMemcpyKind 
# 955
kind) 
# 956
{ 
# 957
return ::cudaGraphAddMemcpyNodeToSymbol(pGraphNode, graph, pDependencies, numDependencies, (const void *)(&symbol), src, count, offset, kind); 
# 958
} 
# 1016 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 1017
cudaGraphAddMemcpyNodeFromSymbol(cudaGraphNode_t *
# 1018
pGraphNode, cudaGraph_t 
# 1019
graph, const cudaGraphNode_t *
# 1020
pDependencies, size_t 
# 1021
numDependencies, void *
# 1022
dst, const T &
# 1023
symbol, size_t 
# 1024
count, size_t 
# 1025
offset, cudaMemcpyKind 
# 1026
kind) 
# 1027
{ 
# 1028
return ::cudaGraphAddMemcpyNodeFromSymbol(pGraphNode, graph, pDependencies, numDependencies, dst, (const void *)(&symbol), count, offset, kind); 
# 1029
} 
# 1067 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 1068
cudaGraphMemcpyNodeSetParamsToSymbol(cudaGraphNode_t 
# 1069
node, const T &
# 1070
symbol, const void *
# 1071
src, size_t 
# 1072
count, size_t 
# 1073
offset, cudaMemcpyKind 
# 1074
kind) 
# 1075
{ 
# 1076
return ::cudaGraphMemcpyNodeSetParamsToSymbol(node, (const void *)(&symbol), src, count, offset, kind); 
# 1077
} 
# 1115 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 1116
cudaGraphMemcpyNodeSetParamsFromSymbol(cudaGraphNode_t 
# 1117
node, void *
# 1118
dst, const T &
# 1119
symbol, size_t 
# 1120
count, size_t 
# 1121
offset, cudaMemcpyKind 
# 1122
kind) 
# 1123
{ 
# 1124
return ::cudaGraphMemcpyNodeSetParamsFromSymbol(node, dst, (const void *)(&symbol), count, offset, kind); 
# 1125
} 
# 1173 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 1174
cudaGraphExecMemcpyNodeSetParamsToSymbol(cudaGraphExec_t 
# 1175
hGraphExec, cudaGraphNode_t 
# 1176
node, const T &
# 1177
symbol, const void *
# 1178
src, size_t 
# 1179
count, size_t 
# 1180
offset, cudaMemcpyKind 
# 1181
kind) 
# 1182
{ 
# 1183
return ::cudaGraphExecMemcpyNodeSetParamsToSymbol(hGraphExec, node, (const void *)(&symbol), src, count, offset, kind); 
# 1184
} 
# 1232 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 1233
cudaGraphExecMemcpyNodeSetParamsFromSymbol(cudaGraphExec_t 
# 1234
hGraphExec, cudaGraphNode_t 
# 1235
node, void *
# 1236
dst, const T &
# 1237
symbol, size_t 
# 1238
count, size_t 
# 1239
offset, cudaMemcpyKind 
# 1240
kind) 
# 1241
{ 
# 1242
return ::cudaGraphExecMemcpyNodeSetParamsFromSymbol(hGraphExec, node, dst, (const void *)(&symbol), count, offset, kind); 
# 1243
} 
# 1271 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 1272
cudaUserObjectCreate(cudaUserObject_t *
# 1273
object_out, T *
# 1274
objectToWrap, unsigned 
# 1275
initialRefcount, unsigned 
# 1276
flags) 
# 1277
{ 
# 1278
return ::cudaUserObjectCreate(object_out, objectToWrap, [](void *
# 1281
vpObj) { delete (reinterpret_cast< T *>(vpObj)); } , initialRefcount, flags); 
# 1284
} 
# 1286
template< class T> static inline cudaError_t 
# 1287
cudaUserObjectCreate(cudaUserObject_t *
# 1288
object_out, T *
# 1289
objectToWrap, unsigned 
# 1290
initialRefcount, cudaUserObjectFlags 
# 1291
flags) 
# 1292
{ 
# 1293
return cudaUserObjectCreate(object_out, objectToWrap, initialRefcount, (unsigned)flags); 
# 1294
} 
# 1321 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 1322
cudaGetSymbolAddress(void **
# 1323
devPtr, const T &
# 1324
symbol) 
# 1326
{ 
# 1327
return ::cudaGetSymbolAddress(devPtr, (const void *)(&symbol)); 
# 1328
} 
# 1353 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 1354
cudaGetSymbolSize(size_t *
# 1355
size, const T &
# 1356
symbol) 
# 1358
{ 
# 1359
return ::cudaGetSymbolSize(size, (const void *)(&symbol)); 
# 1360
} 
# 1397 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1398
__attribute((deprecated)) static inline cudaError_t cudaBindTexture(size_t *
# 1399
offset, const texture< T, dim, readMode>  &
# 1400
tex, const void *
# 1401
devPtr, const cudaChannelFormatDesc &
# 1402
desc, size_t 
# 1403
size = ((2147483647) * 2U) + 1U) 
# 1405 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
{ 
# 1406
return ::cudaBindTexture(offset, &tex, devPtr, &desc, size); 
# 1407
} 
# 1443 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1444
__attribute((deprecated)) static inline cudaError_t cudaBindTexture(size_t *
# 1445
offset, const texture< T, dim, readMode>  &
# 1446
tex, const void *
# 1447
devPtr, size_t 
# 1448
size = ((2147483647) * 2U) + 1U) 
# 1450 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
{ 
# 1451
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size); 
# 1452
} 
# 1500 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1501
__attribute((deprecated)) static inline cudaError_t cudaBindTexture2D(size_t *
# 1502
offset, const texture< T, dim, readMode>  &
# 1503
tex, const void *
# 1504
devPtr, const cudaChannelFormatDesc &
# 1505
desc, size_t 
# 1506
width, size_t 
# 1507
height, size_t 
# 1508
pitch) 
# 1510
{ 
# 1511
return ::cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch); 
# 1512
} 
# 1559 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1560
__attribute((deprecated)) static inline cudaError_t cudaBindTexture2D(size_t *
# 1561
offset, const texture< T, dim, readMode>  &
# 1562
tex, const void *
# 1563
devPtr, size_t 
# 1564
width, size_t 
# 1565
height, size_t 
# 1566
pitch) 
# 1568
{ 
# 1569
return ::cudaBindTexture2D(offset, &tex, devPtr, &(tex.channelDesc), width, height, pitch); 
# 1570
} 
# 1602 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1603
__attribute((deprecated)) static inline cudaError_t cudaBindTextureToArray(const texture< T, dim, readMode>  &
# 1604
tex, cudaArray_const_t 
# 1605
array, const cudaChannelFormatDesc &
# 1606
desc) 
# 1608
{ 
# 1609
return ::cudaBindTextureToArray(&tex, array, &desc); 
# 1610
} 
# 1641 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1642
__attribute((deprecated)) static inline cudaError_t cudaBindTextureToArray(const texture< T, dim, readMode>  &
# 1643
tex, cudaArray_const_t 
# 1644
array) 
# 1646
{ 
# 1647
cudaChannelFormatDesc desc; 
# 1648
cudaError_t err = ::cudaGetChannelDesc(&desc, array); 
# 1650
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err; 
# 1651
} 
# 1683 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1684
__attribute((deprecated)) static inline cudaError_t cudaBindTextureToMipmappedArray(const texture< T, dim, readMode>  &
# 1685
tex, cudaMipmappedArray_const_t 
# 1686
mipmappedArray, const cudaChannelFormatDesc &
# 1687
desc) 
# 1689
{ 
# 1690
return ::cudaBindTextureToMipmappedArray(&tex, mipmappedArray, &desc); 
# 1691
} 
# 1722 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1723
__attribute((deprecated)) static inline cudaError_t cudaBindTextureToMipmappedArray(const texture< T, dim, readMode>  &
# 1724
tex, cudaMipmappedArray_const_t 
# 1725
mipmappedArray) 
# 1727
{ 
# 1728
cudaChannelFormatDesc desc; 
# 1729
cudaArray_t levelArray; 
# 1730
cudaError_t err = ::cudaGetMipmappedArrayLevel(&levelArray, mipmappedArray, 0); 
# 1732
if (err != (cudaSuccess)) { 
# 1733
return err; 
# 1734
}  
# 1735
err = ::cudaGetChannelDesc(&desc, levelArray); 
# 1737
return (err == (cudaSuccess)) ? cudaBindTextureToMipmappedArray(tex, mipmappedArray, desc) : err; 
# 1738
} 
# 1765 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1766
__attribute((deprecated)) static inline cudaError_t cudaUnbindTexture(const texture< T, dim, readMode>  &
# 1767
tex) 
# 1769
{ 
# 1770
return ::cudaUnbindTexture(&tex); 
# 1771
} 
# 1801 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> 
# 1802
__attribute((deprecated)) static inline cudaError_t cudaGetTextureAlignmentOffset(size_t *
# 1803
offset, const texture< T, dim, readMode>  &
# 1804
tex) 
# 1806
{ 
# 1807
return ::cudaGetTextureAlignmentOffset(offset, &tex); 
# 1808
} 
# 1853 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 1854
cudaFuncSetCacheConfig(T *
# 1855
func, cudaFuncCache 
# 1856
cacheConfig) 
# 1858
{ 
# 1859
return ::cudaFuncSetCacheConfig((const void *)func, cacheConfig); 
# 1860
} 
# 1862
template< class T> static inline cudaError_t 
# 1863
cudaFuncSetSharedMemConfig(T *
# 1864
func, cudaSharedMemConfig 
# 1865
config) 
# 1867
{ 
# 1868
return ::cudaFuncSetSharedMemConfig((const void *)func, config); 
# 1869
} 
# 1901 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> inline cudaError_t 
# 1902
cudaOccupancyMaxActiveBlocksPerMultiprocessor(int *
# 1903
numBlocks, T 
# 1904
func, int 
# 1905
blockSize, size_t 
# 1906
dynamicSMemSize) 
# 1907
{ 
# 1908
return ::cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, (const void *)func, blockSize, dynamicSMemSize, 0); 
# 1909
} 
# 1953 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> inline cudaError_t 
# 1954
cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *
# 1955
numBlocks, T 
# 1956
func, int 
# 1957
blockSize, size_t 
# 1958
dynamicSMemSize, unsigned 
# 1959
flags) 
# 1960
{ 
# 1961
return ::cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, (const void *)func, blockSize, dynamicSMemSize, flags); 
# 1962
} 
# 1967
class __cudaOccupancyB2DHelper { 
# 1968
size_t n; 
# 1970
public: __cudaOccupancyB2DHelper(size_t n_) : n(n_) { } 
# 1971
size_t operator()(int) 
# 1972
{ 
# 1973
return n; 
# 1974
} 
# 1975
}; 
# 2023 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class UnaryFunction, class T> static inline cudaError_t 
# 2024
cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(int *
# 2025
minGridSize, int *
# 2026
blockSize, T 
# 2027
func, UnaryFunction 
# 2028
blockSizeToDynamicSMemSize, int 
# 2029
blockSizeLimit = 0, unsigned 
# 2030
flags = 0) 
# 2031
{ 
# 2032
cudaError_t status; 
# 2035
int device; 
# 2036
cudaFuncAttributes attr; 
# 2039
int maxThreadsPerMultiProcessor; 
# 2040
int warpSize; 
# 2041
int devMaxThreadsPerBlock; 
# 2042
int multiProcessorCount; 
# 2043
int funcMaxThreadsPerBlock; 
# 2044
int occupancyLimit; 
# 2045
int granularity; 
# 2048
int maxBlockSize = 0; 
# 2049
int numBlocks = 0; 
# 2050
int maxOccupancy = 0; 
# 2053
int blockSizeToTryAligned; 
# 2054
int blockSizeToTry; 
# 2055
int blockSizeLimitAligned; 
# 2056
int occupancyInBlocks; 
# 2057
int occupancyInThreads; 
# 2058
size_t dynamicSMemSize; 
# 2064
if (((!minGridSize) || (!blockSize)) || (!func)) { 
# 2065
return cudaErrorInvalidValue; 
# 2066
}  
# 2072
status = ::cudaGetDevice(&device); 
# 2073
if (status != (cudaSuccess)) { 
# 2074
return status; 
# 2075
}  
# 2077
status = cudaDeviceGetAttribute(&maxThreadsPerMultiProcessor, cudaDevAttrMaxThreadsPerMultiProcessor, device); 
# 2081
if (status != (cudaSuccess)) { 
# 2082
return status; 
# 2083
}  
# 2085
status = cudaDeviceGetAttribute(&warpSize, cudaDevAttrWarpSize, device); 
# 2089
if (status != (cudaSuccess)) { 
# 2090
return status; 
# 2091
}  
# 2093
status = cudaDeviceGetAttribute(&devMaxThreadsPerBlock, cudaDevAttrMaxThreadsPerBlock, device); 
# 2097
if (status != (cudaSuccess)) { 
# 2098
return status; 
# 2099
}  
# 2101
status = cudaDeviceGetAttribute(&multiProcessorCount, cudaDevAttrMultiProcessorCount, device); 
# 2105
if (status != (cudaSuccess)) { 
# 2106
return status; 
# 2107
}  
# 2109
status = cudaFuncGetAttributes(&attr, func); 
# 2110
if (status != (cudaSuccess)) { 
# 2111
return status; 
# 2112
}  
# 2114
funcMaxThreadsPerBlock = (attr.maxThreadsPerBlock); 
# 2120
occupancyLimit = maxThreadsPerMultiProcessor; 
# 2121
granularity = warpSize; 
# 2123
if (blockSizeLimit == 0) { 
# 2124
blockSizeLimit = devMaxThreadsPerBlock; 
# 2125
}  
# 2127
if (devMaxThreadsPerBlock < blockSizeLimit) { 
# 2128
blockSizeLimit = devMaxThreadsPerBlock; 
# 2129
}  
# 2131
if (funcMaxThreadsPerBlock < blockSizeLimit) { 
# 2132
blockSizeLimit = funcMaxThreadsPerBlock; 
# 2133
}  
# 2135
blockSizeLimitAligned = (((blockSizeLimit + (granularity - 1)) / granularity) * granularity); 
# 2137
for (blockSizeToTryAligned = blockSizeLimitAligned; blockSizeToTryAligned > 0; blockSizeToTryAligned -= granularity) { 
# 2141
if (blockSizeLimit < blockSizeToTryAligned) { 
# 2142
blockSizeToTry = blockSizeLimit; 
# 2143
} else { 
# 2144
blockSizeToTry = blockSizeToTryAligned; 
# 2145
}  
# 2147
dynamicSMemSize = blockSizeToDynamicSMemSize(blockSizeToTry); 
# 2149
status = cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(&occupancyInBlocks, func, blockSizeToTry, dynamicSMemSize, flags); 
# 2156
if (status != (cudaSuccess)) { 
# 2157
return status; 
# 2158
}  
# 2160
occupancyInThreads = (blockSizeToTry * occupancyInBlocks); 
# 2162
if (occupancyInThreads > maxOccupancy) { 
# 2163
maxBlockSize = blockSizeToTry; 
# 2164
numBlocks = occupancyInBlocks; 
# 2165
maxOccupancy = occupancyInThreads; 
# 2166
}  
# 2170
if (occupancyLimit == maxOccupancy) { 
# 2171
break; 
# 2172
}  
# 2173
}  
# 2181
(*minGridSize) = (numBlocks * multiProcessorCount); 
# 2182
(*blockSize) = maxBlockSize; 
# 2184
return status; 
# 2185
} 
# 2219 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class UnaryFunction, class T> static inline cudaError_t 
# 2220
cudaOccupancyMaxPotentialBlockSizeVariableSMem(int *
# 2221
minGridSize, int *
# 2222
blockSize, T 
# 2223
func, UnaryFunction 
# 2224
blockSizeToDynamicSMemSize, int 
# 2225
blockSizeLimit = 0) 
# 2226
{ 
# 2227
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, blockSizeLimit, 0); 
# 2228
} 
# 2265 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 2266
cudaOccupancyMaxPotentialBlockSize(int *
# 2267
minGridSize, int *
# 2268
blockSize, T 
# 2269
func, size_t 
# 2270
dynamicSMemSize = 0, int 
# 2271
blockSizeLimit = 0) 
# 2272
{ 
# 2273
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, ((__cudaOccupancyB2DHelper)(dynamicSMemSize)), blockSizeLimit, 0); 
# 2274
} 
# 2303 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 2304
cudaOccupancyAvailableDynamicSMemPerBlock(size_t *
# 2305
dynamicSmemSize, T 
# 2306
func, int 
# 2307
numBlocks, int 
# 2308
blockSize) 
# 2309
{ 
# 2310
return ::cudaOccupancyAvailableDynamicSMemPerBlock(dynamicSmemSize, (const void *)func, numBlocks, blockSize); 
# 2311
} 
# 2362 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 2363
cudaOccupancyMaxPotentialBlockSizeWithFlags(int *
# 2364
minGridSize, int *
# 2365
blockSize, T 
# 2366
func, size_t 
# 2367
dynamicSMemSize = 0, int 
# 2368
blockSizeLimit = 0, unsigned 
# 2369
flags = 0) 
# 2370
{ 
# 2371
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, ((__cudaOccupancyB2DHelper)(dynamicSMemSize)), blockSizeLimit, flags); 
# 2372
} 
# 2405 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> inline cudaError_t 
# 2406
cudaFuncGetAttributes(cudaFuncAttributes *
# 2407
attr, T *
# 2408
entry) 
# 2410
{ 
# 2411
return ::cudaFuncGetAttributes(attr, (const void *)entry); 
# 2412
} 
# 2450 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 2451
cudaFuncSetAttribute(T *
# 2452
entry, cudaFuncAttribute 
# 2453
attr, int 
# 2454
value) 
# 2456
{ 
# 2457
return ::cudaFuncSetAttribute((const void *)entry, attr, value); 
# 2458
} 
# 2482 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim> 
# 2483
__attribute((deprecated)) static inline cudaError_t cudaBindSurfaceToArray(const surface< T, dim>  &
# 2484
surf, cudaArray_const_t 
# 2485
array, const cudaChannelFormatDesc &
# 2486
desc) 
# 2488
{ 
# 2489
return ::cudaBindSurfaceToArray(&surf, array, &desc); 
# 2490
} 
# 2513 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T, int dim> 
# 2514
__attribute((deprecated)) static inline cudaError_t cudaBindSurfaceToArray(const surface< T, dim>  &
# 2515
surf, cudaArray_const_t 
# 2516
array) 
# 2518
{ 
# 2519
cudaChannelFormatDesc desc; 
# 2520
cudaError_t err = ::cudaGetChannelDesc(&desc, array); 
# 2522
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err; 
# 2523
} 
# 2534 "/usr/local/cuda/bin/../targets/x86_64-linux/include/cuda_runtime.h"
#pragma GCC diagnostic pop
# 64 "CMakeCUDACompilerId.cu"
const char *info_compiler = ("INFO:compiler[NVIDIA]"); 
# 66
const char *info_simulate = ("INFO:simulate[GNU]"); 
# 336 "CMakeCUDACompilerId.cu"
const char info_version[] = {'I', 'N', 'F', 'O', ':', 'c', 'o', 'm', 'p', 'i', 'l', 'e', 'r', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n', '[', (('0') + ((11 / 10000000) % 10)), (('0') + ((11 / 1000000) % 10)), (('0') + ((11 / 100000) % 10)), (('0') + ((11 / 10000) % 10)), (('0') + ((11 / 1000) % 10)), (('0') + ((11 / 100) % 10)), (('0') + ((11 / 10) % 10)), (('0') + (11 % 10)), '.', (('0') + ((3 / 10000000) % 10)), (('0') + ((3 / 1000000) % 10)), (('0') + ((3 / 100000) % 10)), (('0') + ((3 / 10000) % 10)), (('0') + ((3 / 1000) % 10)), (('0') + ((3 / 100) % 10)), (('0') + ((3 / 10) % 10)), (('0') + (3 % 10)), '.', (('0') + ((109 / 10000000) % 10)), (('0') + ((109 / 1000000) % 10)), (('0') + ((109 / 100000) % 10)), (('0') + ((109 / 10000) % 10)), (('0') + ((109 / 1000) % 10)), (('0') + ((109 / 100) % 10)), (('0') + ((109 / 10) % 10)), (('0') + (109 % 10)), ']', '\000'}; 
# 365 "CMakeCUDACompilerId.cu"
const char info_simulate_version[] = {'I', 'N', 'F', 'O', ':', 's', 'i', 'm', 'u', 'l', 'a', 't', 'e', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n', '[', (('0') + ((7 / 10000000) % 10)), (('0') + ((7 / 1000000) % 10)), (('0') + ((7 / 100000) % 10)), (('0') + ((7 / 10000) % 10)), (('0') + ((7 / 1000) % 10)), (('0') + ((7 / 100) % 10)), (('0') + ((7 / 10) % 10)), (('0') + (7 % 10)), '.', (('0') + ((5 / 10000000) % 10)), (('0') + ((5 / 1000000) % 10)), (('0') + ((5 / 100000) % 10)), (('0') + ((5 / 10000) % 10)), (('0') + ((5 / 1000) % 10)), (('0') + ((5 / 100) % 10)), (('0') + ((5 / 10) % 10)), (('0') + (5 % 10)), ']', '\000'}; 
# 385
const char *info_platform = ("INFO:platform[Linux]"); 
# 386
const char *info_arch = ("INFO:arch[]"); 
# 390
const char *info_language_standard_default = ("INFO:standard_default[14]"); 
# 406
const char *info_language_extensions_default = ("INFO:extensions_default[ON]"); 
# 418
int main(int argc, char *argv[]) 
# 419
{ 
# 420
int require = 0; 
# 421
require += (info_compiler[argc]); 
# 422
require += (info_platform[argc]); 
# 424
require += (info_version[argc]); 
# 427
require += (info_simulate[argc]); 
# 430
require += (info_simulate_version[argc]); 
# 432
require += (info_language_standard_default[argc]); 
# 433
require += (info_language_extensions_default[argc]); 
# 434
(void)argv; 
# 435
return require; 
# 436
} 

# 1 "CMakeCUDACompilerId.cudafe1.stub.c"
#define _NV_ANON_NAMESPACE _GLOBAL__N__27_CMakeCUDACompilerId_cpp1_ii_bd57c623
#ifdef _NV_ANON_NAMESPACE
#endif
# 1 "CMakeCUDACompilerId.cudafe1.stub.c"
#include "CMakeCUDACompilerId.cudafe1.stub.c"
# 1 "CMakeCUDACompilerId.cudafe1.stub.c"
#undef _NV_ANON_NAMESPACE
