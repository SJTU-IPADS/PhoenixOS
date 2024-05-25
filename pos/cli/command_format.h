#pragma once

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/oob.h"
#include "pos/include/migration.h"

/* ========= migration related commands ========= */
/*!
 *  \brief  command for initiating migration process
 *  \param  pid     [client] process id that to be migrated
 *  \param  d_ipv4  [client] IPv4 address of the host of the destination POS service
 *  \param  retval  [server] migration return value
 */
typedef struct pos_cli_migrate {
    // client
    uint64_t pid;
    uint32_t d_ipv4;
    // server
    pos_retval_t retval;
} pos_cli_migrate_t;

/*!
 *  \brief  command for preserving GPU resources (e.g., Context, Stream, etc.)
 *  \param  pid     [client] process id that to be migrated
 *  \param  d_ipv4  [client] IPv4 address of the host of the destination POS service
 *  \param  retval  [server] migration return value
 */
typedef struct pos_cli_preserve {
    // client

    // server
} pos_cli_preserve_t;

