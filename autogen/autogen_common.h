/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <format>

#include <unistd.h>

#include "utils.h"
#include "autogen_cpp.h"

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/api_context.h"

#include "clang-c/Index.h"
#include "yaml-cpp/yaml.h"


/*!
 *  \brief mark whether a handle's value come from
 */
enum pos_handle_source_typeid_t : uint8_t {
    kPOS_HandleSource_FromParam = 0,
    kPOS_HandleSource_ToParam,
    kPOS_HandleSource_FromLastUsed,
    kPOS_HandleSource_FromDefault
};


/*!
 *  \brief  obtain handle source type according to given string from yaml file
 *  \param  handle_source   given string
 *  \return the corresponding handle source type
 */
pos_handle_source_typeid_t get_handle_source_by_name(std::string& handle_source);


/*!
 *  \brief  metadata of a parameter of an supported API
 */
typedef struct pos_support_edge_meta {
    // index of the handle in parameter list involved in this edge
    uint16_t index;

    // type of the handle involved in this edge
    uint32_t handle_type;

    // source of the handle value involved in this edge
    pos_handle_source_typeid_t handle_source;

    // index of the parameter that indicate the expected handle address
    // this field is only used by create edge
    uint16_t expected_addr_param_index;

    // index of the parameter that indicate the resource state size behind this handle
    // this field is only used by create edge
    uint16_t state_size_param_index;
} pos_support_edge_meta_t;


/*!
 *  \brief  metadata of an supported API
 */
typedef struct pos_support_api_meta {
    // ========== common fields ==========
    // name of the API
    std::string name;

    // parent name of the API
    // e.g.,    API of cudaMemcpy would be cudaMemcpyH2D,
    //          cudaMemcpyD2H and cudaMemcpyD2D's parent
    std::string parent_name;

    // type of the API
    pos_api_type_t api_type;

    // TODO: move this out
    std::vector<std::string> dependent_headers;

    // whether this API is a synchronous API
    bool is_sync;

    // ========== fields for parser ==========
    bool customize_parser;
    std::vector<pos_support_edge_meta_t*> create_edges;
    std::vector<pos_support_edge_meta_t*> delete_edges;
    std::vector<pos_support_edge_meta_t*> in_edges;
    std::vector<pos_support_edge_meta_t*> out_edges;
    std::vector<pos_support_edge_meta_t*> inout_edges;

    // ========== fields for worker ==========
    // whether to customize worker function's logic
    bool customize_worker;

    // whether the worker function involves operation on memory bus
    bool involve_membus;

    // whether it needs to sync the stream after execute the worker function
    bool need_stream_sync;

    // map of parameters with constant values
    // index of the parameter -> constant value
    std::map<uint16_t, std::string> constant_params;

    ~pos_support_api_meta(){
        for(auto& ptr : create_edges){ delete ptr; }
        for(auto& ptr : delete_edges){ delete ptr; }
        for(auto& ptr : in_edges){ delete ptr; }
        for(auto& ptr : out_edges){ delete ptr; }
        for(auto& ptr : inout_edges){ delete ptr; }
    }
} pos_support_api_meta_t;


/*!
 *  \brief  metadata of an supported header file
 */
typedef struct pos_support_header_file_meta {
    std::string file_name;
    std::map<std::string, pos_support_api_meta_t*> api_map;

    // retval value under current processed vendor header file
    std::string successful_retval;

    ~pos_support_header_file_meta(){
        std::map<std::string, pos_support_api_meta_t*>::iterator map_iter;
        for(map_iter=api_map.begin(); map_iter!=api_map.end(); map_iter++){
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
    bool is_pointer;

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
    std::map<std::string, pos_vendor_api_meta_t*> api_map;
    ~pos_vendor_header_file_meta(){
        typename std::map<std::string, pos_vendor_api_meta_t*>::iterator map_iter;
        for(map_iter = this->api_map.begin(); map_iter != this->api_map.end(); map_iter++){
            if(map_iter->second){ delete map_iter->second; }
        }
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

    // path to generate the source code
    std::string gen_directory;
    std::string parser_directory;
    std::string worker_directory;

    /*!
     *  \brief  collect PhOS supporting information
     *  \return POS_SUCCESS for succesfully collecting
     */
    pos_retval_t collect_pos_support_yamls();

    /*!
     *  \brief  parse vendor headers to generate IRs for autogen
     *  \return POS_SUCCESS for successfully generate
     */
    pos_retval_t collect_vendor_header_files();

    /*!
     *  \brief  generate source code of PhOS parser and worker for each APIs
     *  \return POS_SUCCESS for successfully generate
     */
    pos_retval_t generate_pos_src();

 private:
    // metadata of all vendor provided header files
    // file name -> metadata
    std::map<std::string, pos_vendor_header_file_meta_t*> _vendor_header_file_meta_map;

    // map of metadata of all pos supported header
    // file name -> metadata
    std::map<std::string, pos_support_header_file_meta_t*> _supported_header_file_meta_map;
    

    /*!
     *  \brief  collect all APIs from a yaml file that records pos-supported information
     *  \note   this function is implemeneted by each target
     *  \param  file_path           path to the yaml file to be parsed
     *  \param  header_file_meta    metadata of the parsed yaml file
     *  \return POS_SUCCESS for successfully parsed 
     */
    pos_retval_t __collect_pos_support_yaml(
        const std::string& file_path,
        pos_support_header_file_meta_t *header_file_meta
    );

    /*!
     *  \brief  collect all APIs from a single vendor header file
     *  \note   this function is implemeneted by each target
     *  \param  file_path                   path to the selected file to be parsed
     *  \param  vendor_header_file_meta     metadata of the parsed vendor header file
     *  \param  support_header_file_meta    metadata of the pos-supported header file
     *  \return POS_SUCCESS for successfully parsed 
     */
    pos_retval_t __collect_vendor_header_file(
        const std::string& file_path,
        pos_vendor_header_file_meta_t* vendor_header_file_meta,
        pos_support_header_file_meta_t* support_header_file_meta
    );

    /*!
     *  \brief  generate the parser logic of an API
     *  \param  vendor_api_meta     metadata of the parsed vendor API
     *  \param  support_api_meta    metadata of the pos-supported API
     *  \return POS_SUCCESS for successfully generated
     */
    pos_retval_t __generate_api_parser(
        pos_vendor_api_meta_t* vendor_api_meta,
        pos_support_api_meta_t* support_api_meta
    );

    /*!
     *  \brief  generate the worker logic of an API
     *  \param  vender_header_file_meta     metadata of the parsed vender header file
     *  \param  support_header_file_meta    metadata of the pos-supported header file
     *  \param  vendor_api_meta             metadata of the parsed vendor API
     *  \param  support_api_meta            metadata of the pos-supported API
     *  \return POS_SUCCESS for successfully generated
     */
    pos_retval_t __generate_api_worker(
        pos_vendor_header_file_meta_t* vender_header_file_meta,
        pos_support_header_file_meta_t* support_header_file_meta,
        pos_vendor_api_meta_t* vendor_api_meta,
        pos_support_api_meta_t* support_api_meta
    );

    /*!
     *  \brief  insert target-specific parser code of the API
     *  \note   this function is implemeneted by each target
     *  \param  vendor_api_meta         metadata of the parsed vendor API
     *  \param  support_api_meta        metadata of the pos-supported API
     *  \param  parser_file             source file
     *  \param  ps_function_namespace   code block of the outer namespace
     *  \param  api_namespace           code block of the API's namespace
     *  \param  parser_function         code block of the parser function
     *  \return POS_SUCCESS for successfully generated
     */
    pos_retval_t __insert_code_parser_for_target(
        pos_vendor_api_meta_t* vendor_api_meta,
        pos_support_api_meta_t* support_api_meta,
        POSCodeGen_CppSourceFile* parser_file,
        POSCodeGen_CppBlock *ps_function_namespace,
        POSCodeGen_CppBlock *api_namespace,
        POSCodeGen_CppBlock *parser_function
    );

    /*!
     *  \brief  insert target-specific worker code of the API
     *  \note   this function is implemeneted by each target
     *  \param  vender_header_file_meta     metadata of the parsed vender header file
     *  \param  support_header_file_meta    metadata of the pos-supported header file
     *  \param  vendor_api_meta             metadata of the parsed vendor API
     *  \param  support_api_meta            metadata of the pos-supported API
     *  \param  worker_file                 source file
     *  \param  wk_function_namespace       code block of the outer namespace
     *  \param  api_namespace               code block of the API's namespace
     *  \param  worker_function             code block of the worker function
     *  \return POS_SUCCESS for successfully generated
     */
    pos_retval_t __insert_code_worker_for_target(
        pos_vendor_header_file_meta_t* vender_header_file_meta,
        pos_support_header_file_meta_t* support_header_file_meta,
        pos_vendor_api_meta_t* vendor_api_meta,
        pos_support_api_meta_t* support_api_meta,
        POSCodeGen_CppSourceFile* worker_file,
        POSCodeGen_CppBlock *wk_function_namespace,
        POSCodeGen_CppBlock *api_namespace,
        POSCodeGen_CppBlock *worker_function
    );
};
