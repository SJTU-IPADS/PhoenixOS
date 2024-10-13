#include "autogen_cuda.h"


pos_retval_t POSAutogener::__collect_pos_support_yaml(
    const std::string& file_path,
    pos_support_header_file_meta_t *header_file_meta
){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t i, j, k;
    std::string api_type, param_type, handle_source;
    std::vector<std::string> dependent_headers;
    pos_support_api_meta_t *api_meta;
    pos_support_edge_meta_t *resource_meta;
    YAML::Node config, api, edges, related_edges;

    POS_CHECK_POINTER(header_file_meta);

    auto __parse_edges = [&](
        const char* edge_list_name,
        std::vector<pos_support_edge_meta_t*>* edge_list
    ) -> pos_retval_t {
        pos_retval_t retval = POS_SUCCESS;
        std::vector<pos_support_edge_meta_t*>* related_handles;

        for(j=0; j<api[edge_list_name].size(); j++){
            edges = api[edge_list_name][j];

            POS_CHECK_POINTER(edge_list);
            POS_CHECK_POINTER(resource_meta = new pos_support_edge_meta_t);
            edge_list->push_back(resource_meta);
            
            // [1] index of the handle in parameter list involved in this edge
            resource_meta->index = edges["param_index"].as<uint32_t>();

            // [2] type of the handle involved in this edge
            param_type = edges["resource_type"].as<std::string>();
            if(param_type == std::string("cuda_memory")){
                resource_meta->type = kPOS_ResourceTypeId_CUDA_Memory;
            } else if(param_type == std::string("cuda_stream")){
                resource_meta->type = kPOS_ResourceTypeId_CUDA_Stream;
            } else if(param_type == std::string("cuda_event")){
                resource_meta->type = kPOS_ResourceTypeId_CUDA_Event;
            } else if(param_type == std::string("cuda_module")){
                resource_meta->type = kPOS_ResourceTypeId_CUDA_Module;
            } else if(param_type == std::string("cuda_function")){
                resource_meta->type = kPOS_ResourceTypeId_CUDA_Function;
            } else {
                POS_ERROR_C_DETAIL(
                    "invalid parameter type detected: api_name(%s), given_type(%s)",
                    api_meta->name.c_str(), param_type.c_str()
                );
            }

            // [3] source of the handle value involved in this edge
            handle_source = edges["source"].as<std::string>();
            if(handle_source == std::string("from_param")){
                resource_meta->source = kPOS_HandleSource_FromParam;
            } else if(handle_source == std::string("to_param")){
                resource_meta->source = kPOS_HandleSource_ToParam;
            } else if(handle_source == std::string("from_last_used")){
                resource_meta->source = kPOS_HandleSource_FromLastUsed;
            } else {
                POS_ERROR_C_DETAIL(
                    "invalid handle source detected: api_name(%s), edge_list(%s), param_id(%u), given_handle_source(%s)",
                    api_meta->name.c_str(), edge_list_name, resource_meta->index, param_type.c_str()
                );
            }

            // [4] other related handles involved in this edge
            // this field is only for create edges
            if(std::string(edge_list_name) == std::string("create_edges") && edges["related_edges"]){
                for(k=0; k<edges["related_edges"].size(); k++){
                    // TODO: how to handle related?
                }
            }
        }
    exit:
        return retval;
    };

    try {
        config = YAML::LoadFile(file_path);
        header_file_meta->file_name = config["header_file_name"].as<std::string>();

        if(config["dependent_headers"]){
            for(j=0; j<config["dependent_headers"].size(); j++){
                dependent_headers.push_back(config["dependent_headers"][j].as<std::string>());
            }
        }

        for(i=0; i<config["apis"].size(); i++){
            api = config["apis"][i];

            POS_CHECK_POINTER(api_meta = new pos_support_api_meta_t);

            // name of the API
            api_meta->name = api["name"].as<std::string>();

            // whether to customize the parser and worker logic of API
            api_meta->customize = api["customize"].as<bool>();

            // dependent headers to support hijacking this API
            api_meta->dependent_headers = dependent_headers;

            // API type
            api_type = api["type"].as<std::string>();
            if(api_type == std::string("create_resource")){
                api_meta->api_type = kPOS_API_Type_Create_Resource;
            } else if(api_type == std::string("delete_resource")){
                api_meta->api_type = kPOS_API_Type_Delete_Resource;
            } else if(api_type == std::string("get_resource")){
                api_meta->api_type = kPOS_API_Type_Get_Resource;
            } else if(api_type == std::string("set_resource")){
                api_meta->api_type = kPOS_API_Type_Set_Resource;
            } else {
                POS_WARN_C(
                    "invalid api type detected: api_name(%s), given_type(%s)",
                    api_meta->name.c_str(), api_type.c_str()
                );
                retval = POS_FAILED_INVALID_INPUT;
                goto exit;
            }

            // edges to be created by this API
            if(unlikely(POS_SUCCESS != (
                retval = __parse_edges("create_edges", &api_meta->create_edges)
            ))){ goto exit; }
            if(unlikely(POS_SUCCESS != (
                retval = __parse_edges("delete_edges", &api_meta->delete_edges)
            ))){ goto exit; }
            if(unlikely(POS_SUCCESS != (
                retval = __parse_edges("in_edges", &api_meta->in_edges)
            ))){ goto exit; }
            if(unlikely(POS_SUCCESS != (
                retval = __parse_edges("out_edges", &api_meta->out_edges)
            ))){ goto exit; }
            if(unlikely(POS_SUCCESS != (
                retval = __parse_edges("inout_edges", &api_meta->inout_edges)
            ))){ goto exit; }

            header_file_meta->api_map.insert({ api_meta->name, api_meta });
        }
    } catch (const YAML::Exception& e) {
        POS_WARN_C("failed to parse yaml file: path(%s), error(%s)", file_path.c_str(), e.what());
        retval = POS_FAILED_INVALID_INPUT;
        goto exit;
    }

exit:
    return retval;
}


pos_retval_t POSAutogener::__collect_vendor_header_file(
    const std::string& file_path,
    pos_vendor_header_file_meta_t* vendor_header_file_meta,
    pos_support_header_file_meta_t* support_header_file_meta
){
    pos_retval_t retval = POS_SUCCESS;
    CXIndex index;
    CXTranslationUnit unit;
    CXCursor cursor;
    
    struct __clang_param_wrapper {
        pos_vendor_header_file_meta_t* vendor_header_file_meta;
        pos_support_header_file_meta_t* support_header_file_meta;
    };

    POS_CHECK_POINTER(vendor_header_file_meta);
    POS_CHECK_POINTER(support_header_file_meta);

    __clang_param_wrapper param {
        .vendor_header_file_meta = vendor_header_file_meta,
        .support_header_file_meta = support_header_file_meta
    };

    index = clang_createIndex(0, 0);
    unit = clang_parseTranslationUnit(
        index, file_path.c_str(), nullptr, 0, nullptr, 0, CXTranslationUnit_None
    );

    if(unlikely(unit == nullptr)){
        POS_WARN_C("failed to create CXTranslationUnit for file: path(%s)", file_path.c_str());
        retval = POS_FAILED;
        goto exit;
    }

    // scan across all function declarations
    cursor = clang_getTranslationUnitCursor(unit);
    clang_visitChildren(
        /* parent */ cursor,
        /* visitor */
        [](CXCursor cursor, CXCursor parent, CXClientData client_data) -> CXChildVisitResult {
            int i, num_args;
            std::string func_name_cppstr;
            CXString func_name;
            CXString func_ret_type;
            CXCursor arg_cursor;
            __clang_param_wrapper *param = nullptr;
            pos_vendor_header_file_meta_t *vendor_header_file_meta = nullptr;
            pos_support_header_file_meta_t *support_header_file_meta = nullptr;
            pos_vendor_api_meta_t *api_meta = nullptr;
            pos_vendor_param_meta_t *param_meta = nullptr;

            if (clang_getCursorKind(cursor) == CXCursor_FunctionDecl) {
                param = reinterpret_cast<__clang_param_wrapper*>(client_data);
                POS_CHECK_POINTER(param);
                vendor_header_file_meta = reinterpret_cast<pos_vendor_header_file_meta_t*>(param->vendor_header_file_meta);
                POS_CHECK_POINTER(vendor_header_file_meta);
                support_header_file_meta = reinterpret_cast<pos_support_header_file_meta_t*>(param->support_header_file_meta);
                POS_CHECK_POINTER(support_header_file_meta);

                func_name_cppstr = std::string(clang_getCString(clang_getCursorSpelling(cursor)));
                if(support_header_file_meta->api_map.count(func_name_cppstr) == 0){
                    goto cursor_traverse_exit;
                }

                POS_CHECK_POINTER(api_meta = new pos_vendor_api_meta_t);
                vendor_header_file_meta->api_map.insert({ func_name_cppstr, api_meta });
                api_meta->name = clang_getCursorSpelling(cursor);
                api_meta->return_type = clang_getCursorResultType(cursor);
                // returnType = clang_getTypeSpelling(clang_getCursorResultType(cursor));

                num_args = clang_Cursor_getNumArguments(cursor);
                for(i=0; i<num_args; i++){
                    POS_CHECK_POINTER(param_meta = new pos_vendor_param_meta_t);
                    api_meta->params.push_back(param_meta);
                    arg_cursor = clang_Cursor_getArgument(cursor, i);
                    param_meta->name = clang_getCursorSpelling(arg_cursor);
                    param_meta->type = clang_getCursorType(arg_cursor);
                }
            }
        
        cursor_traverse_exit:
            return CXChildVisit_Recurse;
        },
        /* client_data */ &param
    );
    clang_disposeTranslationUnit(unit);

exit:
    return retval;
}


pos_retval_t POSAutogener::__insert_code_parser_for_target(
    pos_vendor_api_meta_t* vendor_api_meta,
    pos_support_api_meta_t* support_api_meta,
    POSCodeGen_CppSourceFile* parser_file,
    POSCodeGen_CppBlock *ps_function_namespace,
    POSCodeGen_CppBlock *api_namespace,
    POSCodeGen_CppBlock *parser_function
){
    uint64_t i;
    pos_retval_t retval = POS_SUCCESS;
    std::string api_snake_name;
    std::map<uint32_t, uint32_t> handle_var_map;
    
    api_snake_name = posautogen_utils_camel2snake(support_api_meta->name);


    /*!
     *  \brief  insert parser code for processing a single handle involved in the API
     *  \note   this function is invoked by __insert_code_parse_edge_list
     *  \param  api_snake_name  snake name of the API
     *  \param  edge_direction  direction of this edge that involve current handle
     *  \param  edge_meta       metadata of this edge, extract from yaml file
     *  \param  hm_type         string of the handle manager type
     *  \param  hm_name         string of the handle maneger variable name
     *  \param  handle_typeid   string of the handle type id of the processing handle
     *  \param  handle_type     string of the handle type of the processing handle
     *  \param  handle_name     string of the handle variable name
     */
    auto __insert_code_parse_handle = [&](
        std::string api_snake_name,
        pos_edge_direction_t edge_direction,
        pos_support_edge_meta_t* edge_meta,
        std::string&& hm_type,
        std::string&& hm_name,
        std::string&& handle_typeid,
        std::string&& handle_type,
        std::string&& handle_name
    ){
        std::string edge_direction_str;
        bool is_hm_duplicated, is_handle_duplicated;
        POS_CHECK_POINTER(edge_meta);

        edge_direction_str = 
                edge_direction == kPOS_Edge_Direction_In        ? std::string("kPOS_Edge_Direction_In")     :
                edge_direction == kPOS_Edge_Direction_Out       ? std::string("kPOS_Edge_Direction_Out")    :
                edge_direction == kPOS_Edge_Direction_InOut     ? std::string("kPOS_Edge_Direction_InOut")  :
                edge_direction == kPOS_Edge_Direction_Create    ? std::string("kPOS_Edge_Direction_Create") :
                edge_direction == kPOS_Edge_Direction_Delete    ? std::string("kPOS_Edge_Direction_Delete") :
                                                                  std::string("__WRONG__");
        if(unlikely(edge_direction_str == std::string("__WRONG__"))){
            POS_ERROR_C_DETAIL("shouldn't be here, this is a bug");
        }

        // step 1: declare pointers of handle manager and handle
        is_hm_duplicated = parser_function->declare_var(std::format("{} *{}", hm_type, hm_name));
        is_handle_duplicated = parser_function->declare_var(std::format("{} *{}", handle_type, handle_name));
        POS_ASSERT(is_handle_duplicated == false);

        // step 2: obtain handle manager
        if(is_hm_duplicated == false){
            parser_function->append_content(std::format(
                "// obtain handle manager of {}\n"
                "{} = pos_get_client_typed_hm(\n"
                "   client, {}, {}\n"
                ");\n"
                "POS_CHECK_POINTER({});"
                ,
                handle_typeid,
                hm_name, 
                handle_typeid, hm_type,
                hm_name
            ));
        }

        // step 3: operate in the handle manager
        if(     edge_direction == kPOS_Edge_Direction_In
            ||  edge_direction == kPOS_Edge_Direction_Out
            ||  edge_direction == kPOS_Edge_Direction_InOut
        ){
            // case: for in/out/inout edge, obtain handle from handle manager
            if(edge_meta->source == kPOS_HandleSource_FromLastUsed){
                parser_function->append_content(std::format(
                    "// obtain handle from hm\n"
                    "POS_CHECK_POINTER({} = {}->latest_used_handle);",
                    handle_name, hm_name
                ));
            } else {
                parser_function->append_content(std::format(
                    "// obtain handle from hm\n"
                    "retval = {}->get_handle_by_client_addr(\n"
                    "   /* client_addr */ (void*)pos_api_param_value(wqe, {}, uint64_t),"
                    "   /* handle */ &{}\n"
                    ");"
                    "if(unlikely(retval != POS_SUCCESS)){{\n"
                    "   POS_WARN(\n"
                    "       \"parse({}): no memory was founded: client_addr(%p)\"\n",
                    "       (void*)pos_api_param_value(wqe, {}, uint64_t)\n"
                    "   );\n"
                    "   goto exit;\n"
                    "}}\n"
                    "POS_CHECK_POINTER({});"
                    ,
                    hm_name,
                    edge_meta->index - 1,
                    handle_name,
                    api_snake_name,
                    edge_meta->index - 1,
                    handle_name
                ));
            }
        } else if (edge_direction == kPOS_Edge_Direction_Create){
            // case: for create edge, create handle from handle manager
            parser_function->append_content(std::format(
                "// create handle in the hm\n"
                "retval = hm_memory->allocate_mocked_resource(\n"
                "   /* handle */ &{},\n"
                "   /* related_handles */"
                "   /* size */ pos_api_param_value(wqe, {}, size_t)\n",
                "   /* expected_addr */ 0\n",
                "   /* state_size */ (uint64_t)pos_api_param_value(wqe, 0, size_t)\n"
                ,
                
            ));
        } else if (edge_direction == kPOS_Edge_Direction_Delete){
            // case: for delete edge, create handle from handle manager
        } else {
            POS_ERROR_C_DETAIL("shouldn't be here, this is a bug");
        }


        // step 4: record edge info in the wqe
        if(edge_meta->source == kPOS_HandleSource_FromLastUsed){
            //! \note   if the value of the handle comes from latest used
            //          we need to check the latest used handle recorded 
            //          in the handle manager
            parser_function->append_content(std::format(
                "POS_CHECK_POINTER({}->latest_used_handle);",
                hm_name
            ));

            parser_function->append_content(std::format(
                "// record the related handle to QE\n"
                "wqe->record_handle<{}>({{\n"
                "   /* handle */ {}->latest_used_handle\n"
                "}});"
                ,
                edge_direction_str,
                hm_name
            ));
        } else if(edge_meta->source == kPOS_HandleSource_FromParam){
            parser_function->append_content(std::format(
                "// record the related handle to QE\n"
                "wqe->record_handle<{}>({{\n"
                "   /* handle */ {},\n",
                "   /* param_index */ {},\n",
                "   /* offset */ pos_api_param_value(wqe, {}, uint64_t) - (uint64_t)({}->client_addr)\n",
                "}});"
                ,
                handle_name,
                edge_meta->index - 1,
                edge_meta->index - 1,
                handle_name
            ));
        }
    };

    /*!
     *  \brief  insert parser code for a specific edge list
     *  \param  edge_list   the edge list to be processed
     */
    auto __insert_code_parse_edge_list = [&](
        std::vector<pos_support_edge_meta_t*> *edge_list,
    ){
        POS_CHECK_POINTER(edge_list);
        for(pos_support_edge_meta_t* edge_meta : edge_list){
            //! \note   we maintain a handle variable map to
            //          avoid confliction of handle variable name
            if(handle_var_map.count(edge_meta->type) == 0){
                handle_var_map[edge_meta->type] = 0;
            } else {
                handle_var_map[edge_meta->type] = 1;
            }

            switch(edge_meta->type){
            case kPOS_ResourceTypeId_CUDA_Memory:
                __insert_code_parse_handle(
                    /* api_snake_name */ api_snake_name,
                    /* edge_direction */ kPOS_Edge_Direction_Create,
                    /* edge_meta */ edge_meta,
                    /* hm_type */ "POSHandleManager_CUDA_Memory",
                    /* hm_name */ "hm_memory",
                    /* handle_typeid */ "kPOS_ResourceTypeId_CUDA_Memory",
                    /* handle_type */ "POSHandle_CUDA_Memory",
                    /* handle_name */ std::string("memory_handle_") 
                        + std::to_string(handle_var_map[edge_meta->type])
                );
                break;
            
            default:
                POS_ERROR_C_DETAIL("shouldn't be here, this is a bug");
            }
        }
    };

    POS_CHECK_POINTER(vendor_api_meta);
    POS_CHECK_POINTER(support_api_meta);
    POS_CHECK_POINTER(parser_file);
    POS_CHECK_POINTER(ps_function_namespace);
    POS_CHECK_POINTER(api_namespace);
    POS_CHECK_POINTER(parser_function);

    // add POS CUDA headers
    parser_file->add_include("#include \"pos/cuda_impl/handle.h\"");
    parser_file->add_include("#include \"pos/cuda_impl/parser.h\"");
    parser_file->add_include("#include \"pos/cuda_impl/client.h\"");
    parser_file->add_include("#include \"pos/cuda_impl/api_context.h\"");

    // step 1: declare variables in the parser
    parser_function->declare_var("pos_retval_t retval = POS_SUCCESS;");
    parser_function->declare_var("POSClient_CUDA *client;");

    // step 2: check input pointers for wqe and ws
    parser_function->append_content(
        "POS_CHECK_POINTER(wqe);\n"
        "POS_CHECK_POINTER(ws);"
    );

    // step 3: obtain client
    parser_function->append_content(
        "client = (POSClient_CUDA*)(wqe->client);\n"
        "POS_CHECK_POINTER(client);"
    );

    // step 4: do runtime debug check
    parser_function->append_content(std::format(
        "#if POS_ENABLE_DEBUG_CHECK\n"
        "    // check whether given parameter is valid\n"
        "   if(unlikely(wqe->api_cxt->params.size() != {})) {{\n"
        "       POS_WARN(\n"
        "           \"parse({}): failed to parse, given %lu params, {} expected\",\n"
        "           wqe->api_cxt->params.size()\n"
        "       );\n"
        "       retval = POS_FAILED_INVALID_INPUT;\n"
        "       goto exit;\n"
        "   }}\n"
        "#endif\n"
        ,
        vendor_api_meta->params.size(), 
        api_snake_name,
        vendor_api_meta->params.size()
    ));

    // step 5: processing handles
    for(pos_support_edge_meta_t* edge_meta : support_api_meta->create_edges){
        switch(edge_meta->type){
        case kPOS_ResourceTypeId_CUDA_Memory:
            __insert_code_parse_handle(
                /* api_snake_name */ api_snake_name,
                /* edge_direction */ kPOS_Edge_Direction_Create,
                /* edge_meta */ edge_meta,
                /* hm_type */ "POSHandleManager_CUDA_Memory",
                /* hm_name */ "hm_memory",
                /* handle_typeid */ "kPOS_ResourceTypeId_CUDA_Memory",
                /* handle_type */ "POSHandle_CUDA_Memory",
                /* handle_name */ "memory_handle"
            );
            break;
        default:
            POS_ERROR_C_DETAIL("shouldn't be here, this is a bug");
        }
    }

    // step 5: launch the wqe to the queue to worker
    parser_function->append_content(std::string("retval = client->dag.launch_op(wqe);"));

exit:
    return retval;
}
