#include "autogen_common.h"


pos_handle_source_typeid_t get_handle_source_by_name(std::string& handle_source){
    if(handle_source == std::string("from_param")){
        return kPOS_HandleSource_FromParam;
    } else if(handle_source == std::string("to_param")){
        return kPOS_HandleSource_ToParam;
    } else if(handle_source == std::string("from_last_used")){
        return kPOS_HandleSource_FromLastUsed;
    } else if(handle_source == std::string("from_default")){
        return kPOS_HandleSource_FromDefault;
    } else {
        POS_ERROR_DETAIL(
            "invalid handle source detected: given_handle_source(%s)", handle_source.c_str()
        );
    }
}


pos_retval_t POSAutogener::collect_pos_support_yamls(){
    pos_retval_t retval = POS_SUCCESS;
    pos_support_header_file_meta_t *header_file_meta;

    POS_ASSERT(this->support_directory.size() > 0);

    if(unlikely(
            !std::filesystem::exists(this->support_directory)
        ||  !std::filesystem::is_directory(this->support_directory)
    )){
        POS_WARN_C(
            "failed to do autogen, invalid support files path provided: path(%s)",
            this->support_directory.c_str()
        );
        retval = POS_FAILED_INVALID_INPUT;
        goto exit;
    }

    for (const auto& entry : std::filesystem::directory_iterator(this->support_directory)){
        if(entry.is_regular_file() &&  entry.path().extension() == ".yaml"){
            POS_LOG_C("parsing support file %s...", entry.path().c_str())

            POS_CHECK_POINTER(header_file_meta = new pos_support_header_file_meta_t);

            if(unlikely(POS_SUCCESS != (
                retval = this->__collect_pos_support_yaml(entry.path(), header_file_meta)
            ))){
                POS_ERROR_C("failed to parse file %s", entry.path().c_str())
            }

            /// !   \note   the file_name of header_file_meta should be updated in __collect_pos_support_yaml
            if(unlikely(header_file_meta->file_name.size() == 0)){
                POS_WARN_C("no name header file provided in yaml file: path(%s)", entry.path().c_str());
                retval = POS_FAILED_INVALID_INPUT;
                goto exit;
            }
            this->_supported_header_file_meta_map.insert({ header_file_meta->file_name , header_file_meta });
        }
    }

exit:
    return retval;
}


pos_retval_t POSAutogener::collect_vendor_header_files(){
    pos_retval_t retval = POS_SUCCESS;
    pos_vendor_header_file_meta_t *vendor_header_file_meta;
    pos_support_header_file_meta_t *supported_header_file_meta;
    typename std::map<std::string, pos_support_header_file_meta_t*>::iterator header_map_iter;
    typename std::map<std::string, pos_support_api_meta_t*>::iterator api_map_iter;

    POS_ASSERT(this->header_directory.size() > 0);

    if(unlikely(
            !std::filesystem::exists(this->header_directory)
        ||  !std::filesystem::is_directory(this->header_directory)
    )){
        POS_WARN_C(
            "failed to do autogen, invalid vender headers path provided: path(%s)",
            this->header_directory.c_str()
        );
        retval = POS_FAILED_INVALID_INPUT;
        goto exit;
    }

    for (const auto& entry : std::filesystem::directory_iterator(this->header_directory)){
        if(     entry.is_regular_file()
            &&  (entry.path().extension() == ".h" || entry.path().extension() == ".hpp")
        ){
            POS_LOG_C("parsing vendor header file %s...", entry.path().c_str())

            // if this header file isn't supported by PhOS, we just skip analyse it
            if( this->_supported_header_file_meta_map.count(entry.path().filename()) == 0 ){
                POS_BACK_LINE;
                POS_OLD_LOG_C("parsing vendor header file %s [skipped]", entry.path().c_str());
                continue;
            }
            POS_CHECK_POINTER( supported_header_file_meta 
                = this->_supported_header_file_meta_map[entry.path().filename()] );

            POS_CHECK_POINTER(vendor_header_file_meta = new pos_vendor_header_file_meta_t);
            vendor_header_file_meta->file_name = entry.path().filename();
            this->_vendor_header_file_meta_map.insert(
                { vendor_header_file_meta->file_name, vendor_header_file_meta }
            );

            if(unlikely(POS_SUCCESS != (
                retval = this->__collect_vendor_header_file(
                    entry.path(),
                    vendor_header_file_meta,
                    supported_header_file_meta
                )
            ))){
                POS_ERROR_C("failed to parse file %s", entry.path().c_str())
            }

            POS_BACK_LINE;
            POS_LOG_C(
                "parsing vendor header file %s [# hijacked apis: %lu]",
                entry.path().c_str(), vendor_header_file_meta->api_map.size()
            );
        }
    }

    // check
    for(header_map_iter = this->_supported_header_file_meta_map.begin();
        header_map_iter != this->_supported_header_file_meta_map.end();
        header_map_iter++
    ){
        // [1] whether all header files that registered as supported were founded
        const std::string &supported_file_name = header_map_iter->first;
        if(unlikely(this->_vendor_header_file_meta_map.count(supported_file_name) == 0)){
            POS_WARN_C(
                "PhOS registered to support header file %s, but no vendor header file was found",
                supported_file_name.c_str()
            );
            retval = POS_FAILED_NOT_EXIST;
            goto exit;
        }

        vendor_header_file_meta = this->_vendor_header_file_meta_map[supported_file_name];
        POS_CHECK_POINTER(vendor_header_file_meta);
        supported_header_file_meta = header_map_iter->second;
        POS_CHECK_POINTER(supported_header_file_meta);

        // [2] whether all apis that registered as supported were founded
        for(api_map_iter = supported_header_file_meta->api_map.begin();
            api_map_iter != supported_header_file_meta->api_map.end();
            api_map_iter++
        ){
            const std::string &api_name = api_map_iter->first;
            if(unlikely(vendor_header_file_meta->api_map.count(api_name) == 0)){
                POS_WARN_C(
                    "PhOS registered to support API %s in file %s, but no vendor API was found",
                    api_name.c_str(), supported_file_name.c_str()
                );
                retval = POS_FAILED_NOT_EXIST;
                goto exit;
            }
        }
    }

exit:
    return retval;
}

pos_retval_t POSAutogener::generate_pos_src(){
    pos_retval_t retval = POS_SUCCESS;
    pos_vendor_header_file_meta_t *vendor_header_file_meta = nullptr;
    pos_support_header_file_meta_t *supported_header_file_meta = nullptr;
    pos_vendor_api_meta_t *vendor_api_meta = nullptr;
    pos_support_api_meta_t *support_api_meta = nullptr;
    typename std::map<std::string, pos_support_header_file_meta_t*>::iterator header_map_iter;
    typename std::map<std::string, pos_support_api_meta_t*>::iterator api_map_iter;

    // recreate generate folders
    this->parser_directory = this->gen_directory + std::string("/parser");
    this->worker_directory = this->gen_directory + std::string("/worker");
    try {
        if (std::filesystem::exists(this->gen_directory)) { std::filesystem::remove_all(this->gen_directory); }
        std::filesystem::create_directory(this->gen_directory);
        std::filesystem::create_directory(this->parser_directory);
        std::filesystem::create_directory(this->worker_directory);
    } catch (const std::filesystem::filesystem_error& e) {
        POS_WARN_C(
            "failed to create new directory for the generated codes: parser_directory(%s), worker_directory(%s)",
            this->parser_directory.c_str(), this->worker_directory.c_str()
        );
        retval = POS_FAILED;
        goto exit;
    } catch (const std::exception& e) {
        POS_WARN_C(
            "failed to create new directory for the generated codes: parser_directory(%s), worker_directory(%s)",
            this->parser_directory.c_str(), this->worker_directory.c_str()
        );
        retval = POS_FAILED;
        goto exit;
    }

    // iterate through all APIs
    for(header_map_iter = this->_supported_header_file_meta_map.begin();
        header_map_iter != this->_supported_header_file_meta_map.end();
        header_map_iter++
    ){
        const std::string &supported_file_name = header_map_iter->first;
        vendor_header_file_meta = this->_vendor_header_file_meta_map[supported_file_name];
        POS_CHECK_POINTER(vendor_header_file_meta);
        supported_header_file_meta = header_map_iter->second;
        POS_CHECK_POINTER(supported_header_file_meta);

        for(api_map_iter = supported_header_file_meta->api_map.begin();
            api_map_iter != supported_header_file_meta->api_map.end();
            api_map_iter++
        ){
            const std::string &api_name = api_map_iter->first;

            vendor_api_meta = vendor_header_file_meta->api_map[api_name];
            POS_CHECK_POINTER(vendor_api_meta);
            support_api_meta = api_map_iter->second;
            POS_CHECK_POINTER(support_api_meta);

            // generate parser logic
            POS_LOG_C("generating parser logic for API %s...", api_name.c_str());
            if(unlikely(POS_SUCCESS != (
                retval = this->__generate_api_parser(vendor_api_meta, support_api_meta)
            ))){
                POS_ERROR_C("generating parser logic for API %s..., failed", api_name.c_str());
            }
            POS_BACK_LINE;
            POS_LOG_C("generating parser logic for API %s: [done]", api_name.c_str());

            // generate worker logic
            POS_LOG_C("generating worker logic for API %s...", api_name.c_str());
            if(unlikely(POS_SUCCESS != (
                retval = this->__generate_api_worker(
                    vendor_header_file_meta,
                    supported_header_file_meta,
                    vendor_api_meta,
                    support_api_meta
                )
            ))){
                POS_ERROR_C("generating worker logic for API %s..., failed", api_name.c_str());
            }
            POS_BACK_LINE;
            POS_LOG_C("generating worker logic for API %s: [done]", api_name.c_str());
        }
    }

exit:
    return retval;
}

pos_retval_t POSAutogener::__generate_api_parser(
    pos_vendor_api_meta_t* vendor_api_meta,
    pos_support_api_meta_t* support_api_meta
){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t i;
    POSCodeGen_CppSourceFile *parser_file;
    POSCodeGen_CppBlock *ps_function_namespace, *api_namespace, *parser_function;
    std::string api_snake_name;

    POS_CHECK_POINTER(vendor_api_meta);
    POS_CHECK_POINTER(support_api_meta);

    // for those APIs to be customized logic, we just omit
    if(support_api_meta->customize_parser == true){
        goto exit;
    }

    api_snake_name = posautogen_utils_camel2snake(support_api_meta->name);

    // create parser file
    parser_file = new POSCodeGen_CppSourceFile(
        this->parser_directory 
        + std::string("/")
        + support_api_meta->name
        + std::string(".cpp")
    );
    POS_CHECK_POINTER(parser_file);
    
    // add basic headers to the parser file
    parser_file->add_include("#include <iostream>");
    parser_file->add_include("#include \"pos/include/common.h\"");
    parser_file->add_include("#include \"pos/include/dag.h\"");
    for(i=0; i<support_api_meta->dependent_headers.size(); i++){
        parser_file->add_include(std::format("#include <{}>", support_api_meta->dependent_headers[i]));
    }

    // create ps_function namespace
    ps_function_namespace = new POSCodeGen_CppBlock(
        /* field name */ "namespace ps_functions",
        /* need_braces */ true,
        /* need_foot_comment */ true
    );
    POS_CHECK_POINTER(ps_function_namespace);
    parser_file->add_block(ps_function_namespace);

    // create api namespace
    retval = ps_function_namespace->allocate_block(
        /* field name */ std::string("namespace ") + api_snake_name,
        /* new_block */ &api_namespace,
        /* need_braces */ true,
        /* need_foot_comment */ true,
        /* level_offset */ 0
    );
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C(
            "failed to allocate cpp block for api namespace while generating parser function: "
            "api_name(%s)",
            api_snake_name
        );
    }
    POS_CHECK_POINTER(api_namespace);

    // create function POS_RT_FUNC_PARSER
    retval = api_namespace->allocate_block(
        /* field name */ std::string("POS_RT_FUNC_PARSER()"),
        /* new_block */ &parser_function,
        /* need_braces */ true,
        /* need_foot_comment */ false,
        /* level_offset */ 1
    );
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C(
            "failed to allocate cpp block for POS_RT_FUNC_PARSER while generating parser function: "
            "api_name(%s)",
            api_snake_name
        );
    }
    POS_CHECK_POINTER(parser_function);

    if(unlikely(POS_SUCCESS != (
        retval = this->__insert_code_parser_for_target(
            vendor_api_meta,
            support_api_meta,
            parser_file,
            ps_function_namespace,
            api_namespace,
            parser_function
        )
    ))){
        POS_WARN_C("failed to generate parser when inserted target-specific code");
        goto exit;
    }

    parser_file->archive();

exit:
    return retval;
}


pos_retval_t POSAutogener::__generate_api_worker(
    pos_vendor_header_file_meta_t* vender_header_file_meta,
    pos_support_header_file_meta_t* support_header_file_meta,
    pos_vendor_api_meta_t* vendor_api_meta,
    pos_support_api_meta_t* support_api_meta
){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t i;
    std::string api_snake_name;
    POSCodeGen_CppSourceFile *worker_file;
    POSCodeGen_CppBlock *wk_function_namespace, *api_namespace, *worker_function;

    POS_CHECK_POINTER(vendor_api_meta);
    POS_CHECK_POINTER(support_api_meta);

    // for those APIs to be customized logic, we just omit
    if(support_api_meta->customize_worker == true){
        goto exit;
    }

    api_snake_name = posautogen_utils_camel2snake(support_api_meta->name);

    // create worker file
    worker_file = new POSCodeGen_CppSourceFile(
        this->worker_directory 
        + std::string("/")
        + support_api_meta->name
        + std::string(".cpp")
    );
    POS_CHECK_POINTER(worker_file);
    
    // add basic headers to the worker file
    worker_file->add_include("#include <iostream>");
    worker_file->add_include("#include \"pos/include/common.h\"");
    worker_file->add_include("#include \"pos/include/client.h\"");
    for(i=0; i<support_api_meta->dependent_headers.size(); i++){
        worker_file->add_include(std::format("#include <{}>", support_api_meta->dependent_headers[i]));
    }

    // create wk_function namespace
    wk_function_namespace = new POSCodeGen_CppBlock(
        /* field name */ "namespace wk_functions",
        /* need_braces */ true,
        /* need_foot_comment */ true
    );
    POS_CHECK_POINTER(wk_function_namespace);
    worker_file->add_block(wk_function_namespace);

    // create api namespace
    retval = wk_function_namespace->allocate_block(
        /* field name */ std::string("namespace ") + api_snake_name,
        /* new_block */ &api_namespace,
        /* need_braces */ true,
        /* need_foot_comment */ true,
        /* level_offset */ 0
    );
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C(
            "failed to allocate cpp block for api namespace while generating worker function: "
            "api_name(%s)",
            api_snake_name
        );
    }
    POS_CHECK_POINTER(api_namespace);

    // create function POS_RT_FUNC_PARSER
    retval = api_namespace->allocate_block(
        /* field name */ std::string("POS_WK_FUNC_LAUNCH()"),
        /* new_block */ &worker_function,
        /* need_braces */ true,
        /* need_foot_comment */ false,
        /* level_offset */ 1
    );
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C(
            "failed to allocate cpp block for POS_WK_FUNC_LAUNCH while generating worker function: "
            "api_name(%s)",
            api_snake_name
        );
    }
    POS_CHECK_POINTER(worker_function);

    if(unlikely(POS_SUCCESS != (
        retval = this->__insert_code_worker_for_target(
            vender_header_file_meta,
            support_header_file_meta,
            vendor_api_meta,
            support_api_meta,
            worker_file,
            wk_function_namespace,
            api_namespace,
            worker_function
        )
    ))){
        POS_WARN_C("failed to generate worker when inserted target-specific code");
        goto exit;
    }

    worker_file->archive();

exit:
    return retval;
}
