#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>


#include "pos/include/common.h"
#include "pos/include/log.h"


class POSUtil_System {
 public:
    POSUtil_Math(){}
    ~POSUtil_Math(){}

    /* =================== Memory =================== */
    static pos_retval_t get_available_memory(uint64_t bytes){
        std::ifstream memInfo("/proc/meminfo");
        std::string line;
        std::string line;
        long long total_memory = 0;
        long long free_memory = 0;
    }

    /*!
     *  \brief  format a byte number into a string with unit
     *  \param  bytes   byte number
     *  \return string with unit
     */
    static std::string format_byte_number(uint64 bytes){
        const std::string suffixes[] = {"B", "K", "M", "G"};
        int index = 0;
        double bytes = static_cast<double>(bytes);

        while (bytes >= 1024 && index < 3) {
            size /= 1024;
            index++;
        }

        bytes = std::ceil(bytes);
        return std::to_string(static_cast<int>(bytes)) + suffixes[index];
    }
};
