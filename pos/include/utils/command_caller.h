#pragma once

#include <iostream>
#include <cstdio>
#include <array>
#include <string>

#include "pos/include/common.h"
#include "pos/include/log.h"

class POSUtil_Command_Caller {
 public:
    /*!
     *  \brief  execute a specified command and obtain its result
     *  \param  cmd     the command to execute
     *  \param  result  the result of the executed command
     *  \todo   this function should support timeout option
     *  \return POS_SUCCESS once the command is successfully executed
     *          POS_FAILED if failed
     */
    static inline pos_retval_t exec(std::string& cmd, std::string& result){
        pos_retval_t retval = POS_SUCCESS;
        std::array<char, 8192> buffer;
        int exit_code = -1;

        FILE *pipe = popen(cmd.c_str(), "r");
        if (unlikely(pipe == nullptr)) {
            POS_WARN("failed to open pipe for executing command %s", cmd.c_str());
            retval = POS_FAILED;
            goto exit;
        }

        result.clear();
        while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
            result += buffer.data();
        }

        // remove \n and \r
        while (!result.empty() && (result.back() == '\n' || result.back() == '\r')) {
            result.pop_back();
        }

        exit_code = WEXITSTATUS(pclose(pipe));
        if(unlikely(exit_code != 0)){
            POS_WARN("failed execution of command %s: exit_code(%d)", cmd.c_str(), exit_code);
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        return retval;
    }
};
