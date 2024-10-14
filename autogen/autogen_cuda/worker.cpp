#include "autogen_cuda.h"


pos_retval_t POSAutogener::__insert_code_worker_for_target(
    pos_vendor_header_file_meta_t* vendor_header_file_meta,
    pos_support_header_file_meta_t* support_header_file_meta,
    pos_vendor_api_meta_t* vendor_api_meta,
    pos_support_api_meta_t* support_api_meta,
    POSCodeGen_CppSourceFile* worker_file,
    POSCodeGen_CppBlock *wk_function_namespace,
    POSCodeGen_CppBlock *api_namespace,
    POSCodeGen_CppBlock *worker_function
){
    pos_retval_t retval = POS_SUCCESS;
    uint64_t k;
    pos_handle_source_typeid_t stream_source;
    uint16_t stream_param_index;
    std::string create_precheck, delete_precheck, in_precheck, out_precheck, inout_precheck;
    
    /*!
     *  \brief  form the parameter list to call the actual function
     *  \return the string of the parameter list
     */
    auto __form_parameter_list = [&]() -> std::string {
        uint64_t i, j;
        uint16_t create_handle_param_index;
        pos_vendor_param_meta_t *api_param;
        pos_support_edge_meta_t *other_edge;
        std::string param_list_str, param_str;
        bool is_var_duplicated, is_param_formed;
        
        // if this API is for creating new resource, we need to declare the corresponding
        // handle var at the begining
        if(support_api_meta->api_type == kPOS_API_Type_Create_Resource){
            POS_CHECK_POINTER(support_api_meta->create_edges[0]);
            POS_ASSERT(support_api_meta->create_edges[0]->index > 0);
            create_handle_param_index = support_api_meta->create_edges[0]->index - 1;
            POS_ASSERT(create_handle_param_index <= vendor_api_meta->params.size() - 1);
            POS_CHECK_POINTER(api_param = vendor_api_meta->params[create_handle_param_index]);

            is_var_duplicated = worker_function->declare_var(std::format(
                "{} __create_handle__ = NULL;",
                clang_getCString(clang_getTypeSpelling(api_param->type))
            ));
            POS_ASSERT(is_var_duplicated == false);
        }

        param_list_str.clear();
        for(i=0; i<vendor_api_meta->params.size(); i++){
            param_str.clear();
            POS_CHECK_POINTER(api_param = vendor_api_meta->params[i]);

            // find out what is the kind of current parameter
            if (support_api_meta->api_type == kPOS_API_Type_Create_Resource &&  i == create_handle_param_index){
                // this parameter is the handle to be created
                param_str = std::string("&__create_handle__");
            } else {
                // this parameter is other in/out/inout/delete handles / values / constant value
                is_param_formed = false;
                
                // try form as constant value
                if(support_api_meta->constant_params.count((uint16_t)(i)) == 1 && !is_param_formed){
                    param_str = support_api_meta->constant_params[(uint16_t)(i)];
                    is_param_formed = true;
                }

                // try form as other handles
                for(j=0; j<support_api_meta->in_edges.size() && !is_param_formed; j++){
                    POS_CHECK_POINTER(other_edge = support_api_meta->in_edges[j]);
                    if(other_edge->index - 1 == i){
                        param_str = std::format("pos_api_input_handle_offset_server_addr(wqe, {})", j);
                        is_param_formed = true;
                    }
                }
                for(j=0; j<support_api_meta->out_edges.size() && !is_param_formed; j++){
                    POS_CHECK_POINTER(other_edge = support_api_meta->out_edges[j]);
                    if(other_edge->index - 1 == i){
                        param_str = std::format("pos_api_output_handle_offset_server_addr(wqe, {})", j);
                        is_param_formed = true;
                    }
                }
                for(j=0; j<support_api_meta->inout_edges.size() && !is_param_formed; j++){
                    POS_CHECK_POINTER(other_edge = support_api_meta->inout_edges[j]);
                    if(other_edge->index - 1 == i){
                        param_str = std::format("pos_api_inout_handle_offset_server_addr(wqe, {})", j);
                        is_param_formed = true;
                    }
                }
                if (support_api_meta->api_type == kPOS_API_Type_Delete_Resource && !is_param_formed) {
                    POS_CHECK_POINTER(other_edge = support_api_meta->delete_edges[0]);
                    POS_ASSERT(other_edge->index > 0);
                    if(other_edge->index - 1 == i){
                        param_str = std::format("pos_api_delete_handle(wqe, 0)->server_addr");
                        is_param_formed = true;
                    }
                }

                // try form as values
                if (!is_param_formed){
                    param_str = std::format(
                        "pos_api_param_value(wqe, {}, {})",
                        i, clang_getCString(clang_getTypeSpelling(api_param->type))
                    );
                    is_param_formed = true;
                }

                // if(api_param->is_pointer && !is_param_formed){
                //     param_str = std::format("pos_api_param_addr(wqe, {})", i);
                //     is_param_formed = true;
                // }
                // if (!api_param->is_pointer && !is_param_formed){
                //     param_str = std::format(
                //         "pos_api_param_value(wqe, {}, {})",
                //         i, clang_getCString(clang_getTypeSpelling(api_param->type))
                //     );
                //     is_param_formed = true;
                // }
            }
            POS_ASSERT(param_str.size() > 0);

            param_list_str += std::format(
                "    /* {} */ ({})({})",
                clang_getCString(api_param->name),
                clang_getCString(clang_getTypeSpelling(api_param->type)),
                param_str
            );
            if(i != vendor_api_meta->params.size()-1){
                param_list_str += std::string(",\n");
            } else {
                param_list_str += std::string("\n");
            }
        }
        return param_list_str;
    };

    POS_CHECK_POINTER(vendor_header_file_meta);
    POS_CHECK_POINTER(support_header_file_meta);
    POS_CHECK_POINTER(vendor_api_meta);
    POS_CHECK_POINTER(support_api_meta);
    POS_CHECK_POINTER(worker_file);
    POS_CHECK_POINTER(wk_function_namespace);
    POS_CHECK_POINTER(api_namespace);
    POS_CHECK_POINTER(worker_function);

    // find out which stream this worker is using
    if(support_api_meta->involve_membus || support_api_meta->need_stream_sync){
        for(k=0; k<support_api_meta->in_edges.size(); k++){
            POS_CHECK_POINTER(support_api_meta->in_edges[k]);
            if(support_api_meta->in_edges[k]->handle_type == kPOS_ResourceTypeId_CUDA_Stream){
                stream_source = support_api_meta->in_edges[k]->handle_source;
                stream_param_index = k;
                break;
            }
            if(k == support_api_meta->in_edges.size()-1){
                POS_ERROR_C(
                    "failed to generate worker code, "
                    "no stream provided when the API need stream support: api(%s)",
                    support_api_meta->name.c_str()
                );
            }
        }
    }

    // add POS CUDA headers
    worker_file->add_include("#include \"pos/cuda_impl/worker.h\"");

    // step 1: declare variables in the worker
    worker_function->declare_var("pos_retval_t retval = POS_SUCCESS;");

    // step 2: check input pointers for wqe and ws
    worker_function->append_content(
        "POS_CHECK_POINTER(wqe);\n"
        "POS_CHECK_POINTER(ws);"
    );

    // step 3: runtime debug check of handles passed from parser
    if(support_api_meta->api_type == kPOS_API_Type_Create_Resource){
        create_precheck = std::string("    POS_CHECK_POINTER(pos_api_create_handle(wqe, 0));\n");
    }
    if(support_api_meta->api_type == kPOS_API_Type_Delete_Resource){
        delete_precheck = std::string("    POS_CHECK_POINTER(pos_api_delete_handle(wqe, 0));\n");
    }
    in_precheck = std::format(
        "    POS_ASSERT(wqe->input_handle_views.size() == {});\n",
        support_api_meta->in_edges.size()
    );
    out_precheck = std::format(
        "    POS_ASSERT(wqe->output_handle_views.size() == {});\n",
        support_api_meta->out_edges.size()
    );
    inout_precheck = std::format(
        "    POS_ASSERT(wqe->inout_handle_views.size() == {});\n",
        support_api_meta->inout_edges.size()
    );
    worker_function->append_content(std::format(
        "#if POS_ENABLE_DEBUG_CHECK\n"
        "{}"
        "{}"
        "{}"
        "{}"
        "{}"
        "#endif"
        ,
        create_precheck,
        delete_precheck,
        in_precheck,
        out_precheck,
        inout_precheck
    ));

    // step 4: membus lock if needed
    if(support_api_meta->involve_membus == true){
        worker_function->append_content(std::format(
            "#if POS_CKPT_OPT_LEVEL == 2\n"
            "   if( ((POSClient*)(wqe->client))->worker->async_ckpt_cxt.is_active == true ){{\n"
            "       wqe->api_cxt->return_code = cudaStreamSynchronize(\n"
            "           (cudaStream_t)({})\n"
            "       );\n"
            "       if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){{\n"
            "           POS_WARN_DETAIL(\"failed to sync stream to avoid ckpt conflict\");\n"
            "       }}\n"
            "       ((POSClient*)(wqe->client))->worker->async_ckpt_cxt.membus_lock = true;\n"
            "   }}\n"
            "#endif"
            ,
            stream_source == kPOS_HandleSource_FromParam 
                ? std::format("pos_api_input_handle_offset_server_addr(wqe, {})", stream_param_index) 
                : "0"
        ));
    }

    // step 5:
    worker_function->append_content(std::format(
        "wqe->api_cxt->return_code = {}(\n"
        "{}"
        ");"
        ,
        clang_getCString(vendor_api_meta->name),
        __form_parameter_list()
    ));

    // step 6: sync the stream if needed
    if(support_api_meta->need_stream_sync == true){
        worker_function->append_content(std::format(
            "wqe->api_cxt->return_code = cudaStreamSynchronize(\n"
            "   (cudaStream_t)({})\n"
            ");"
            ,
            stream_source == kPOS_HandleSource_FromParam 
                ? std::format("pos_api_input_handle_offset_server_addr(wqe, {})", stream_param_index) 
                : "0"
        ));
    }

    // step 7: membus unlock if needed
    if(support_api_meta->involve_membus == true){
        if(support_api_meta->need_stream_sync == true){
            worker_function->append_content(std::string(
                "#if POS_CKPT_OPT_LEVEL == 2\n"
                "   ((POSClient*)(wqe->client))->worker->async_ckpt_cxt.membus_lock = false;\n"
                "#endif"
            ));
        } else {
            worker_function->append_content(std::format(
                "#if POS_CKPT_OPT_LEVEL == 2\n"
                "   if( ((POSClient*)(wqe->client))->worker->async_ckpt_cxt.is_active == true ){{\n"
                "       wqe->api_cxt->return_code = cudaStreamSynchronize(\n"
                "           (cudaStream_t)({})\n"
                "       );\n"
                "       if(unlikely(cudaSuccess != wqe->api_cxt->return_code)){{\n"
                "           POS_WARN_DETAIL(\"failed to sync stream to avoid ckpt conflict\");\n"
                "       }}\n"
                "       ((POSClient*)(wqe->client))->worker->async_ckpt_cxt.membus_lock = false;\n"
                "   }}\n"
                "#endif"
                ,
                stream_source == kPOS_HandleSource_FromParam 
                    ? std::format("pos_api_input_handle_offset_server_addr(wqe, {})", stream_param_index) 
                    : "0"
            ));
        }
    }
    
    // step 8: change handle state for newly created handle / deleted handle
    if(support_api_meta->api_type == kPOS_API_Type_Create_Resource){
        worker_function->append_content(std::format(
            "if(likely({} == wqe->api_cxt->return_code)){{\n"
            "   pos_api_create_handle(wqe, 0)->set_server_addr(__create_handle__);\n"
            "   pos_api_create_handle(wqe, 0)->mark_status(kPOS_HandleStatus_Active);\n"
            "}}"
            ,
            support_header_file_meta->successful_retval
        ));
    }
    if(support_api_meta->api_type == kPOS_API_Type_Delete_Resource){
        worker_function->append_content(std::format(
            "if(likely({} == wqe->api_cxt->return_code)){{\n"
            "   pos_api_delete_handle(wqe, 0)->mark_status(kPOS_HandleStatus_Deleted);\n"
            "}}"
            ,
            support_header_file_meta->successful_retval
        ));
    }

    // step 9: check retval
    worker_function->append_content(std::format(
        "if(unlikely({} != wqe->api_cxt->return_code)){{\n"
        "   POSWorker::__restore(ws, wqe);\n"
        "}} else {{\n"
        "   POSWorker::__done(ws, wqe);\n"
        "}}"
        ,
        support_header_file_meta->successful_retval
    ));

    // step 10: exit pointer
    worker_function->append_content(
        "exit:\n"
        "return retval;"
    );

exit:
    return retval;
}
