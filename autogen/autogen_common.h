#pragma once

#include <iostream>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#include <unistd.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/api_context.h"

#include "clang-c/Index.h"
#include "yaml-cpp/yaml.h"


/*!
 *  \brief  metadata of a parameter of an supported API
 */
typedef struct pos_support_resource_meta {
    uint16_t index;
    uint16_t type;
} pos_support_resource_meta_t;


/*!
 *  \brief  metadata of an supported API
 */
typedef struct pos_support_api_meta {
    std::string name;
    bool customize;
    pos_api_type_t api_type;
    std::vector<pos_support_resource_meta_t*> create_resources;
    std::vector<pos_support_resource_meta_t*> delete_resources;
    std::vector<pos_support_resource_meta_t*> set_resources;
    std::vector<pos_support_resource_meta_t*> get_resources;

    ~pos_support_api_meta(){
        for(auto& ptr : create_resources){ delete ptr; }
        for(auto& ptr : delete_resources){ delete ptr; }
        for(auto& ptr : set_resources){ delete ptr; }
        for(auto& ptr : get_resources){ delete ptr; }
    }
} pos_support_api_meta_t;


/*!
 *  \brief  metadata of an supported header file
 */
typedef struct pos_support_header_file_meta {
    std::string file_name;
    std::map<std::string, pos_support_api_meta_t*> api_maps;

    ~pos_support_header_file_meta(){
        std::map<std::string, pos_support_api_meta_t*>::iterator map_iter;
        for(map_iter=api_maps.begin(); map_iter!=api_maps.end(); map_iter++){
            delete map_iter->second;
        }
    }
} pos_support_header_file_meta_t;


/*!
 *  \brief  metadata of a parameter of an vendor API
 */
typedef struct pos_vendor_param_meta {
    CXString name;
    CXType type;

    ~pos_vendor_param_meta(){
        clang_disposeString(name);
    }
} pos_vendor_param_meta_t;


/*!
 *  \brief  metadata of an vendor API
 */
typedef struct pos_vendor_api_meta {
    CXString name;
    CXType return_type;
    std::vector<pos_vendor_param_meta_t*> params;
    ~pos_vendor_api_meta(){
        clang_disposeString(name);
        for(auto& param : params){ if(!param){ delete param; }}
    }
} pos_vendor_api_meta_t;


/*!
 *  \brief  metadata of an vendor header file
 */
typedef struct pos_vendor_header_file_meta {
    std::string file_name;
    std::vector<pos_vendor_api_meta_t*> apis;
    ~pos_vendor_header_file_meta(){
        for(auto& api : apis){ if(!api){ delete api; }}
    }
} pos_vendor_header_file_meta_t;


/*!
 *  \brief  context of auto-generation process
 */
class POSAutogener {
 public:
    POSAutogener(){}
    ~POSAutogener() = default;

    // path to all vendor headers to be parsed
    std::string header_directory;

    // path to supported file to be parsed
    std::string support_directory;

    /*!
     *  \brief  collect PhOS supporting information
     *  \return POS_SUCCESS for succesfully collecting
     */
    pos_retval_t collect_pos_support_header_files();

    /*!
     *  \brief  parse vendor headers to generate IRs for autogen
     *  \return POS_SUCCESS for successfully generate
     */
    pos_retval_t collect_vendor_header_files();

 private:
    // metadata of all vendor provided header files
    std::vector<pos_vendor_header_file_meta_t*> _vendor_header_file_metas;

    // map of metadata of all pos supported header
    // file name -> metadata
    std::map<std::string, pos_support_header_file_meta_t*> _supported_header_file_metas_map;

    /*!
     *  \brief  collect all APIs from a yaml file that records pos-supported information
     *  \note   this function is implemeneted by each target
     *  \param  file_path           path to the yaml file to be parsed
     *  \param  header_file_meta    metadata of the parsed yaml file
     *  \return POS_SUCCESS for successfully parsed 
     */
    pos_retval_t __collect_pos_support_header_files(
        const std::string& file_path,
        pos_support_header_file_meta_t *header_file_meta
    );


    /*!
     *  \brief  collect all APIs from a single vendor header file
     *  \note   this function is implemeneted by each target
     *  \param  file_path           path to the selected file to be parsed
     *  \param  header_file_meta    metadata of the parsed header file
     *  \return POS_SUCCESS for successfully parsed 
     */
    pos_retval_t __collect_vendor_header_file(
        const std::string& file_path,
        pos_vendor_header_file_meta_t *header_file_meta
    );
};
