#pragma once

#include <iostream>
#include <memory>

#include <stdint.h>
#include <assert.h>

using pos_retval_t = uint8_t;

#ifdef __GNUC__
    #define likely(x)       __builtin_expect(!!(x), 1)
    #define unlikely(x)     __builtin_expect(!!(x), 0)
#else
    #define likely(x)       (x)
    #define unlikely(x)     (x)
#endif

enum pos_retval {
    POS_SUCCESS = 0,
    POS_WARN_DUPLICATED,
    POS_WARN_NOT_READY,
    POS_FAILED,
    POS_FAILED_NOT_EXIST,
    POS_FAILED_ALREADY_EXIST,
    POS_FAILED_INVALID_INPUT,
    POS_FAILED_DRAIN,
    POS_FAILED_NOT_READY,
    POS_FAILED_TIMEOUT,
    POS_FAILED_NOT_IMPLEMENTED,
    POS_FAILED_INCORRECT_OUTPUT
};

#define UINT_64_MAX (1<<64 -1)

#define POS_ASSERT(x)           assert(x);
#define POS_CHECK_POINTER(ptr)  assert((ptr) != nullptr);

/*!
 *  \brief  type for resource typeid
 */
using pos_resource_typeid_t = uint32_t;

/*!
 *  \brief  type for uniquely identify a client
 */
using pos_client_uuid_t = uint64_t;

/*!
 *  \brief  type for uniquely identify a transport
 */
using pos_transport_id_t = uint64_t;

/*!
 *  \brief  memory area which is dynamically allocated
 */
using POSMem_ptr = std::shared_ptr<uint8_t[]>;

/*!
 *  \brief  switch group
 */
#include "pos/include/switches.h"

/*!
 *  \brief  common configuration
 */
#include "pos/include/config.h"
