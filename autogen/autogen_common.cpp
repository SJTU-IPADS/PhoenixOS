#include "autogen_common.h"


pos_retval_t POSAutogener::collect_pos_support_yamls(){
    pos_retval_t retval = POS_SUCCESS;
    pos_support_header_file_meta_t *header_file_meta;

    if(unlikely(this->support_directory.size() == 0)){
        POS_WARN_C("failed to do autogen, no path to support files provided")
        retval = POS_FAILED_INVALID_INPUT;
        goto exit;
    }

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

    if(unlikely(this->header_directory.size() == 0)){
        POS_WARN_C("failed to do autogen, no path to vender headers provided")
        retval = POS_FAILED_INVALID_INPUT;
        goto exit;
    }

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
                supported_file_name
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
                    api_name, supported_file_name
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

            // TODO: how to gen?
        }
    }

exit:
    return retval;
}
