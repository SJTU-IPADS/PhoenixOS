#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <chrono>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <functional>

#include "cudam.h"
#include "utils.h"
#include "log.h"

/* 32-bits crc checksum */
uint32_t utils_crc32b(const uint8_t *buffer, uint64_t size) {
    uint64_t i;
    int64_t j;
    uint32_t byte, crc, mask;

    crc = 0xFFFFFFFF;
    
    for(i=0; i<size; i++){
        byte = buffer[i];            // get next byte.
        crc = crc ^ byte;
        for (j = 7; j >= 0; j--) {    // do eight times.
            mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
        i = i + 1;
    }

    return ~crc;
}

/* get nanosecond-scale timestamp */
uint64_t utils_timestamp_ns() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>
              (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

/* delete all files under specify directory */
uint8_t utils_delete_all_files_under_folder(const char *dir_path) {
    std::function<uint8_t(const char*)> delete_file;
    std::function<uint8_t(const char*, const char*, char*)> get_file_path;

    get_file_path = [&](const char *path, const char *filename,  char *filepath) -> uint8_t {
        strcpy(filepath, path);
        if(filepath[strlen(path) - 1] != '/')
            strcat(filepath, "/");
        strcat(filepath, filename);
        return RETVAL_SUCCESS;
    };

    delete_file = [&](const char *path) -> uint8_t {
        DIR *dir;
        struct dirent *dirinfo;
        struct stat statbuf;
        char filepath[1024] = {0};
        lstat(path, &statbuf);
        
        if (S_ISREG(statbuf.st_mode)){
            remove(path);
        } else if (S_ISDIR(statbuf.st_mode)){
            if ((dir = opendir(path)) == NULL)
                return   RETVAL_ERROR_INVALID;
            while ((dirinfo = readdir(dir)) != NULL){
                get_file_path(path, dirinfo->d_name, filepath);
                if (strcmp(dirinfo->d_name, ".") == 0 || strcmp(dirinfo->d_name, "..") == 0)
                    continue;
                delete_file(filepath);
                rmdir(filepath);
            }
            closedir(dir);
        }
        return RETVAL_SUCCESS;
    };

    return delete_file(dir_path);
}