#ifndef _CRC_H_
#define _CRC_H_

#include <iostream>
#include <stdint.h>

#include "cudam.h"

uint32_t utils_crc32b(const uint8_t *buffer, uint64_t size);
uint64_t utils_timestamp_ns();
uint8_t utils_delete_all_files_under_folder(const char *dir_path);

#endif