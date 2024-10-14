#include "autogen_cuda.h"


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
    std::map<std::string, std::vector<std::string>> in_edge_map;
    
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
     *  \param  in_edge_map     all in edges invole by current API (resource type name -> handles)
     *                          this field is used by create edge to record all related
     *                          parent handles of the handle to be created
     */
    auto __insert_code_parse_handle = [&](
        std::string api_snake_name,
        pos_edge_direction_t edge_direction,
        pos_support_edge_meta_t* edge_meta,
        std::string hm_type,
        std::string hm_name,
        std::string handle_typeid,
        std::string handle_type,
        std::string handle_name,
        std::map<std::string, std::vector<std::string>>* in_edge_map = nullptr
    ){
        std::string edge_direction_str, related_handles_str;
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
        is_hm_duplicated = parser_function->declare_var(std::format("{} *{};", hm_type, hm_name));
        is_handle_duplicated = parser_function->declare_var(std::format("{} *{};", handle_type, handle_name));
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
            if(edge_meta->handle_source == kPOS_HandleSource_FromLastUsed){
                parser_function->append_content(std::format(
                    "// obtain handle from hm (use latest used handle)\n"
                    "POS_CHECK_POINTER({} = {}->latest_used_handle);",
                    handle_name, hm_name
                ));
            } else if(edge_meta->handle_source == kPOS_HandleSource_FromDefault){
                parser_function->append_content(std::format(
                    "// obtain handle from hm (use default handle)\n"
                    "retval = {}->get_handle_by_client_addr(\n"
                    "   /* client_addr */ 0,\n"
                    "   /* handle */ &{}\n"
                    ");\n"
                    "if(unlikely(retval != POS_SUCCESS)){{\n"
                    "   POS_WARN(\n"
                    "       \"parse({}): no {} was founded: client_addr(0)\"\n"
                    "   );\n"
                    "   goto exit;\n"
                    "}}\n"
                    "POS_CHECK_POINTER({});"
                    ,
                    hm_name,
                    handle_name,
                    api_snake_name,
                    hm_type,
                    handle_name
                ));
            } else {
                parser_function->append_content(std::format(
                    "// obtain handle from hm (use handle specified by parameter)\n"
                    "retval = {}->get_handle_by_client_addr(\n"
                    "   /* client_addr */ (void*)pos_api_param_value(wqe, {}, uint64_t),\n"
                    "   /* handle */ &{}\n"
                    ");\n"
                    "if(unlikely(retval != POS_SUCCESS)){{\n"
                    "   POS_WARN(\n"
                    "       \"parse({}): no {} was founded: client_addr(%p)\"\n"
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
                    hm_type,
                    edge_meta->index - 1,
                    handle_name
                ));
            }
        } else if (edge_direction == kPOS_Edge_Direction_Create){
            // case: for create edge, create handle from handle manager
            POS_CHECK_POINTER(in_edge_map);
            
            // the created handle must be returned to a parameter
            POS_ASSERT(edge_meta->index != 0);
            POS_ASSERT(edge_meta->handle_source == kPOS_HandleSource_ToParam);

            auto __cast_in_edges_to_related_handle_map = [&]() -> std::string {
                uint64_t i;
                std::string retstr, handle_type_name;
                typename std::map<std::string, std::vector<std::string>>::iterator map_iter;

                for(map_iter = in_edge_map->begin(); map_iter != in_edge_map->end(); map_iter++){
                    handle_type_name = map_iter->first;
                    std::vector<std::string> &handle_list = map_iter->second;
                    if(unlikely(handle_list.size() == 0)) continue;
                    
                    // begin of the pair
                    retstr += std::string("        {\n");
                    retstr += std::format("            /* id */ {},\n", handle_type_name);
                    
                    // begin of the handle list
                    retstr += std::string("            /* handles */ std::vector<POSHandle*>({\n");
                    for(i=0; i<handle_list.size(); i++){
                        retstr += std::format("                 {}", handle_list[i]);
                        if(i != handle_list.size() - 1){ 
                            retstr += std::string(", "); 
                        } else {
                            retstr += std::string("\n"); 
                        }
                    }

                    // end of the handle list
                    retstr += std::string("            })\n");

                    // end of the pair
                    if (std::next(map_iter) != in_edge_map->end()) { 
                        retstr += std::string("        },\n");
                    } else {
                        retstr += std::string("        }");
                    }
                }

                return retstr;
            };

            parser_function->append_content(std::format(
                "// create handle in the hm\n"
                "retval = {}->allocate_mocked_resource(\n"
                "   /* handle */ &{},\n"
                "   /* related_handles */ std::map<uint64_t, std::vector<POSHandle*>>({{\n"
                "{}\n"
                "   }}),\n" 
                "   /* size */ kPOS_HandleDefaultSize,\n"
                "   /* expected_addr */ {},\n"
                "   /* state_size */ {}\n"
                ");\n"
                "if(unlikely(retval != POS_SUCCESS)){{\n"
                "   POS_WARN(\"parse({}): failed to allocate mocked {} resource within the handler manager\");\n"
                "   memset(pos_api_param_addr(wqe, {}), 0, sizeof(uint64_t));\n"
                "   goto exit;\n"
                "}} else {{\n"
                "   memcpy(pos_api_param_addr(wqe, {}), &({}->client_addr), sizeof(uint64_t));\n"
                "}}"
                ,
                hm_name,
                handle_name,
                __cast_in_edges_to_related_handle_map(),
                edge_meta->expected_addr_param_index != 0
                    ? std::format("pos_api_param_value(wqe, {}, uint64_t)", edge_meta->expected_addr_param_index - 1)
                    : std::string("0"),
                edge_meta->state_size_param_index != 0
                    ? std::format("pos_api_param_value(wqe, {}, uint64_t)", edge_meta->state_size_param_index - 1)
                    : std::string("0"),
                api_snake_name,
                handle_type,
                edge_meta->index - 1,
                edge_meta->index - 1,
                handle_name
            ));
        } else if (edge_direction == kPOS_Edge_Direction_Delete){
            // case: for delete edge, create handle from handle manager
            // TODO
        } else {
            POS_ERROR_C_DETAIL("shouldn't be here, this is a bug");
        }

        // step 4: record edge info in the wqe
        if(edge_meta->index == 0){
            // the handle isn't occur in the parameter list,
            // hence no param_index and offset
            parser_function->append_content(std::format(
                "// record the related handle to QE\n"
                "wqe->record_handle<{}>({{\n"
                "   /* handle */ {}\n"
                "}});"
                ,
                edge_direction_str,
                handle_name
            ));
        } else {
            parser_function->append_content(std::format(
                "// record the related handle to QE\n"
                "wqe->record_handle<{}>({{\n"
                "   /* handle */ {},\n"
                "   /* param_index */ {},\n"
                "   /* offset */ pos_api_param_value(wqe, {}, uint64_t) - (uint64_t)({}->client_addr)\n"
                "}});"
                ,
                edge_direction_str,
                handle_name,
                edge_meta->index - 1,
                edge_meta->index - 1,
                handle_name
            ));
        }
        

        // step 5: allocate the handle in the dag
        if (edge_direction == kPOS_Edge_Direction_Create){
            parser_function->append_content(std::format(
                "retval = client->dag.allocate_handle({});\n"
                "if(unlikely(retval != POS_SUCCESS)){{ goto exit; }}\n",
                handle_name
            ));
        }
    };


    /*!
     *  \brief  insert parser code for a specific edge list
     *  \param  edge_direction  direction of the edge
     *  \param  edge_list       the edge list to be processed
     *  \param  in_edge_map     record all in/inout handles involved in this API
     *                          in order to record the related parent handle
     *                          of the created handle
     *                          this field is only enabled under API with create_resource type
     */
    auto __insert_code_parse_edge_list = [&](
        pos_edge_direction_t edge_direction,
        std::vector<pos_support_edge_meta_t*> *edge_list,
        std::map<std::string, std::vector<std::string>> *in_edge_map = nullptr
    ){
        POS_CHECK_POINTER(edge_list);
        std::string handle_name, handle_typeid;

        for(pos_support_edge_meta_t* edge_meta : *edge_list){
            //! \note   we maintain a handle variable map to
            //          avoid confliction of handle variable name
            if(handle_var_map.count(edge_meta->handle_type) == 0){
                handle_var_map[edge_meta->handle_type] = 0;
            } else {
                handle_var_map[edge_meta->handle_type] = 1;
            }

            switch(edge_meta->handle_type){
            case kPOS_ResourceTypeId_CUDA_Context:
                handle_name = std::string("context_handle_") + std::to_string(handle_var_map[edge_meta->handle_type]);
                handle_typeid = std::string("kPOS_ResourceTypeId_CUDA_Context");
                __insert_code_parse_handle(
                    /* api_snake_name */ api_snake_name,
                    /* edge_direction */ edge_direction,
                    /* edge_meta */ edge_meta,
                    /* hm_type */ "POSHandleManager_CUDA_Context",
                    /* hm_name */ "hm_context",
                    /* handle_typeid */ handle_typeid,
                    /* handle_type */ "POSHandle_CUDA_Context",
                    /* handle_name */ handle_name,
                    /* in_edge_map */ in_edge_map
                );
                break;
            case kPOS_ResourceTypeId_CUDA_Module:
                handle_name = std::string("module_handle_") + std::to_string(handle_var_map[edge_meta->handle_type]);
                handle_typeid = std::string("kPOS_ResourceTypeId_CUDA_Module");
                __insert_code_parse_handle(
                    /* api_snake_name */ api_snake_name,
                    /* edge_direction */ edge_direction,
                    /* edge_meta */ edge_meta,
                    /* hm_type */ "POSHandleManager_CUDA_Module",
                    /* hm_name */ "hm_module",
                    /* handle_typeid */ handle_typeid,
                    /* handle_type */ "POSHandle_CUDA_Module",
                    /* handle_name */ handle_name,
                    /* in_edge_map */ in_edge_map
                );
                break;
            case kPOS_ResourceTypeId_CUDA_Function:
                handle_name = std::string("function_handle_") + std::to_string(handle_var_map[edge_meta->handle_type]);
                handle_typeid = std::string("kPOS_ResourceTypeId_CUDA_Function");
                __insert_code_parse_handle(
                    /* api_snake_name */ api_snake_name,
                    /* edge_direction */ edge_direction,
                    /* edge_meta */ edge_meta,
                    /* hm_type */ "POSHandleManager_CUDA_Function",
                    /* hm_name */ "hm_function",
                    /* handle_typeid */ handle_typeid,
                    /* handle_type */ "POSHandle_CUDA_Function",
                    /* handle_name */ handle_name,
                    /* in_edge_map */ in_edge_map
                );
                break;
            case kPOS_ResourceTypeId_CUDA_Var:
                handle_name = std::string("var_handle_") + std::to_string(handle_var_map[edge_meta->handle_type]);
                handle_typeid = std::string("kPOS_ResourceTypeId_CUDA_Var");
                __insert_code_parse_handle(
                    /* api_snake_name */ api_snake_name,
                    /* edge_direction */ edge_direction,
                    /* edge_meta */ edge_meta,
                    /* hm_type */ "POSHandleManager_CUDA_Var",
                    /* hm_name */ "hm_var",
                    /* handle_typeid */ handle_typeid,
                    /* handle_type */ "POSHandle_CUDA_Var",
                    /* handle_name */ handle_name,
                    /* in_edge_map */ in_edge_map
                );
                break;
            case kPOS_ResourceTypeId_CUDA_Device:
                handle_name = std::string("device_handle_") + std::to_string(handle_var_map[edge_meta->handle_type]);
                handle_typeid = std::string("kPOS_ResourceTypeId_CUDA_Device");
                __insert_code_parse_handle(
                    /* api_snake_name */ api_snake_name,
                    /* edge_direction */ edge_direction,
                    /* edge_meta */ edge_meta,
                    /* hm_type */ "POSHandleManager_CUDA_Device",
                    /* hm_name */ "hm_device",
                    /* handle_typeid */ handle_typeid,
                    /* handle_type */ "POSHandle_CUDA_Device",
                    /* handle_name */ handle_name,
                    /* in_edge_map */ in_edge_map
                );
                break;
            case kPOS_ResourceTypeId_CUDA_Memory:
                handle_name = std::string("memory_handle_") + std::to_string(handle_var_map[edge_meta->handle_type]);
                handle_typeid = std::string("kPOS_ResourceTypeId_CUDA_Memory");
                __insert_code_parse_handle(
                    /* api_snake_name */ api_snake_name,
                    /* edge_direction */ edge_direction,
                    /* edge_meta */ edge_meta,
                    /* hm_type */ "POSHandleManager_CUDA_Memory",
                    /* hm_name */ "hm_memory",
                    /* handle_typeid */ handle_typeid,
                    /* handle_type */ "POSHandle_CUDA_Memory",
                    /* handle_name */ handle_name,
                    /* in_edge_map */ in_edge_map
                );
                break;
            case kPOS_ResourceTypeId_CUDA_Stream:
                handle_name = std::string("stream_handle_") + std::to_string(handle_var_map[edge_meta->handle_type]);
                handle_typeid = std::string("kPOS_ResourceTypeId_CUDA_Stream");
                __insert_code_parse_handle(
                    /* api_snake_name */ api_snake_name,
                    /* edge_direction */ edge_direction,
                    /* edge_meta */ edge_meta,
                    /* hm_type */ "POSHandleManager_CUDA_Stream",
                    /* hm_name */ "hm_stream",
                    /* handle_typeid */ handle_typeid,
                    /* handle_type */ "POSHandle_CUDA_Stream",
                    /* handle_name */ handle_name,
                    /* in_edge_map */ in_edge_map
                );
                break;
            case kPOS_ResourceTypeId_CUDA_Event:
                handle_name = std::string("event_handle_") + std::to_string(handle_var_map[edge_meta->handle_type]);
                handle_typeid = std::string("kPOS_ResourceTypeId_CUDA_Event");
                __insert_code_parse_handle(
                    /* api_snake_name */ api_snake_name,
                    /* edge_direction */ edge_direction,
                    /* edge_meta */ edge_meta,
                    /* hm_type */ "POSHandleManager_CUDA_Event",
                    /* hm_name */ "hm_event",
                    /* handle_typeid */ handle_typeid,
                    /* handle_type */ "POSHandle_CUDA_Event",
                    /* handle_name */ handle_name,
                    /* in_edge_map */ in_edge_map
                );
                break;
            default:
                POS_ERROR_C_DETAIL("shouldn't be here, this is a bug");
            }

            // record the related parent handle of the created handle
            if(edge_direction == kPOS_Edge_Direction_In || edge_direction == kPOS_Edge_Direction_InOut){
                if(in_edge_map != nullptr){ // in_edge_map should be provided when this API is of type create_resource
                    (*in_edge_map)[handle_typeid].push_back(handle_name);
                }
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
    __insert_code_parse_edge_list(
        /* edge_direction */ kPOS_Edge_Direction_In,
        /* edge_list */ &support_api_meta->in_edges,
        /* in_edge_map */ support_api_meta->api_type == kPOS_API_Type_Create_Resource ? &in_edge_map : nullptr
    );
    __insert_code_parse_edge_list(
        /* edge_direction */ kPOS_Edge_Direction_Out,
        /* edge_list */ &support_api_meta->out_edges,
        /* in_edge_map */ support_api_meta->api_type == kPOS_API_Type_Create_Resource ? &in_edge_map : nullptr
    );
    __insert_code_parse_edge_list(
        /* edge_direction */ kPOS_Edge_Direction_InOut,
        /* edge_list */ &support_api_meta->inout_edges,
        /* in_edge_map */ support_api_meta->api_type == kPOS_API_Type_Create_Resource ? &in_edge_map : nullptr
    );
    __insert_code_parse_edge_list(
        /* edge_direction */ kPOS_Edge_Direction_Delete,
        /* edge_list */ &support_api_meta->delete_edges,
        /* in_edge_map */ support_api_meta->api_type == kPOS_API_Type_Create_Resource ? &in_edge_map : nullptr
    );
    __insert_code_parse_edge_list(
        /* edge_direction */ kPOS_Edge_Direction_Create,
        /* edge_list */ &support_api_meta->create_edges,
        /* in_edge_map */ support_api_meta->api_type == kPOS_API_Type_Create_Resource ? &in_edge_map : nullptr
    );

    // step 6: launch the wqe to the queue to worker
    parser_function->append_content(std::string(
        "// launch the op to the dag\n"
        "retval = client->dag.launch_op(wqe);"
    ));

    // step 7: exit processing
    parser_function->append_content(
        "// parser exit\n"
        "exit:"
    );
    if(support_api_meta->api_type == kPOS_API_Type_Create_Resource){
        parser_function->append_content("wqe->status = kPOS_API_Execute_Status_Return_After_Parse;");
    }
    parser_function->append_content("return retval;");
    
exit:
    return retval;
}
