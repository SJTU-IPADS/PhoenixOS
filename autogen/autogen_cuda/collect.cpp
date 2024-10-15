#include "autogen_cuda.h"


pos_retval_t POSAutogener::__collect_pos_support_yaml(
    const std::string& file_path,
    pos_support_header_file_meta_t *header_file_meta
){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t i, k;
    std::string api_type;
    std::vector<std::string> dependent_headers;
    pos_support_api_meta_t *api_meta;
    YAML::Node config, api, edge, related_edge, constant_param;

    POS_CHECK_POINTER(header_file_meta);

    auto __parse_edges = [&](
        pos_support_api_meta_t* api_meta,
        const char* edge_list_name,
        std::vector<pos_support_edge_meta_t*>* edge_list
    ) -> pos_retval_t {
        pos_retval_t retval = POS_SUCCESS;
        uint64_t j, k;
        pos_support_edge_meta_t *edge_meta, *related_edge_meta;
        std::string handle_type, handle_source, related_handle_type, related_handle_source;
        std::vector<pos_support_edge_meta_t*>* related_handles;

        POS_CHECK_POINTER(api_meta);
        POS_CHECK_POINTER(edge_list);

        // one API should only create/delete at most one handle at most
        if(std::string(edge_list_name) == std::string("create_edges")){
            POS_ASSERT(api[edge_list_name].size() <= 1);
        }
        if(std::string(edge_list_name) == std::string("delete_edges")){
            POS_ASSERT(api[edge_list_name].size() <= 1);
        }

        for(j=0; j<api[edge_list_name].size(); j++){
            edge = api[edge_list_name][j];

            POS_CHECK_POINTER(edge_meta = new pos_support_edge_meta_t);
            edge_list->push_back(edge_meta);
            
            // [1] index of the handle in parameter list involved in this edge
            edge_meta->index = edge["param_index"].as<uint32_t>();

            // [2] type of the handle involved in this edge
            handle_type = edge["handle_type"].as<std::string>();
            edge_meta->handle_type = get_handle_type_by_name(handle_type);

            // [3] source of the handle value involved in this edge
            handle_source = edge["handle_source"].as<std::string>();
            edge_meta->handle_source = get_handle_source_by_name(handle_source);

            // [4] state_size and expected_addr involved in this edge
            // this field is only for create edge
            if(std::string(edge_list_name) == std::string("create_edges")){
                if(edge["state_size_param_index"]){
                    edge_meta->state_size_param_index = edge["state_size_param_index"].as<uint16_t>();
                } else {
                    POS_WARN_C(
                        "api %s's create edge is provided without state_size_param_index",
                        api_meta->name.c_str()
                    );
                }

                if(edge["expected_addr_param_index"]){
                    edge_meta->expected_addr_param_index = edge["expected_addr_param_index"].as<uint16_t>();
                }
            }
        }

    exit:
        return retval;
    };

    try {
        config = YAML::LoadFile(file_path);
        header_file_meta->file_name = config["header_file_name"].as<std::string>();
        header_file_meta->successful_retval = config["successful_retval"].as<std::string>();

        if(config["dependent_headers"]){
            for(i=0; i<config["dependent_headers"].size(); i++){
                dependent_headers.push_back(config["dependent_headers"][i].as<std::string>());
            }
        }

        for(i=0; i<config["apis"].size(); i++){
            api = config["apis"][i];

            POS_CHECK_POINTER(api_meta = new pos_support_api_meta_t);

            // name of the API
            api_meta->name = api["name"].as<std::string>();

            // parent name of the API
            api_meta->parent_name = api["parent_name"].as<std::string>();

            // whether the API is synchronous
            api_meta->is_sync = api["is_sync"].as<bool>();

            // whether to customize the parser and worker logic of API
            api_meta->customize_parser = api["customize_parser"].as<bool>();
            api_meta->customize_worker = api["customize_worker"].as<bool>();

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
                retval = __parse_edges(api_meta, "create_edges", &api_meta->create_edges)
            ))){ goto exit; }
            if(unlikely(POS_SUCCESS != (
                retval = __parse_edges(api_meta, "delete_edges", &api_meta->delete_edges)
            ))){ goto exit; }
            if(unlikely(POS_SUCCESS != (
                retval = __parse_edges(api_meta, "in_edges", &api_meta->in_edges)
            ))){ goto exit; }
            if(unlikely(POS_SUCCESS != (
                retval = __parse_edges(api_meta, "out_edges", &api_meta->out_edges)
            ))){ goto exit; }
            if(unlikely(POS_SUCCESS != (
                retval = __parse_edges(api_meta, "inout_edges", &api_meta->inout_edges)
            ))){ goto exit; }

            // whether this API involve operating on memory bus
            api_meta->involve_membus = api["involve_membus"].as<bool>();

            // whether it needs to sync the stream after the worker is executed
            api_meta->need_stream_sync = api["need_stream_sync"].as<bool>();

            // record all constant parameter values of this API
            for(k=0; k<api["constant_params"].size(); k++){
                constant_param = api["constant_params"][k];
                if(unlikely(api_meta->constant_params.count(constant_param["index"].as<uint16_t>()-1) > 0)){
                    POS_WARN_C(
                        "duplicated constant parameter value detected, overwrite: api_name(%s), param_index(%u)",
                        api_meta->name.c_str(), constant_param["index"].as<uint16_t>()
                    );
                }
                api_meta->constant_params.insert(
                    { constant_param["index"].as<uint16_t>()-1, constant_param["value"].as<std::string>() }
                );
            }

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
                // if(support_header_file_meta->api_map.count(func_name_cppstr) == 0){
                //     goto cursor_traverse_exit;
                // }

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
                    param_meta->is_pointer = param_meta->type.kind == CXType_Pointer;
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
