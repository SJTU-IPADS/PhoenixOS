#ifndef _API_COUNTER_H_
#define _API_COUNTER_H_

#include <iostream>
#include <map>
#include <vector>

#include <stdint.h>
#include <assert.h>

enum api_type_t {
    kApiTypeRuntime = 0,
    kApiTypeDriver,
    kApiTypeCublasV2
};

class api_counter {
 public:
    api_counter(){}
    ~api_counter(){
        std::map<const char*, uint64_t>::iterator iter;

        fprintf(stdout, ">> Runtime API Count:\n");
        for(iter = _runtime_count_map.begin(); iter != _runtime_count_map.end(); iter++){
            fprintf(stdout, "  %s: %lu\n", iter->first, iter->second);
        }

        fprintf(stdout, ">> Driver API Count:\n");
        for(iter = _driver_count_map.begin(); iter != _driver_count_map.end(); iter++){
            fprintf(stdout, "  %s: %lu\n", iter->first, iter->second);
        }

        fprintf(stdout, ">> cuBLASv2 API Count:\n");
        for(iter = _cublas_v2_count_map.begin(); iter != _cublas_v2_count_map.end(); iter++){
            fprintf(stdout, "  %s: %lu\n", iter->first, iter->second);
        }
    }

    inline void add_counter(const char* api_name, api_type_t api_type){
        auto __get_dest_map = [&]() -> std::map<const char*, uint64_t>& {
            switch (api_type)
            {
            case kApiTypeRuntime:
                return this->_runtime_count_map;
            case kApiTypeDriver:
                return this->_driver_count_map;
            case kApiTypeCublasV2:
                return this->_cublas_v2_count_map;
            default:
                assert(0);
            }
        };
        
        std::map<const char*, uint64_t> &dest_map = __get_dest_map();

        if(dest_map.count(api_name) == 0){
            dest_map.insert(std::pair<const char*, uint64_t>(api_name, 1));
        } else {
            dest_map[api_name] += 1;
        }
    }

 private:
    std::map<const char*, uint64_t> _runtime_count_map;
    std::map<const char*, uint64_t> _driver_count_map;
    std::map<const char*, uint64_t> _cublas_v2_count_map;
};

extern api_counter ac;

#endif
