#include "autogen_common.h"


pos_retval_t POSAutogener::collect_pos_support_header_files(){
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
            this->_supported_header_file_metas_map.insert({ entry.path().filename() , header_file_meta });

            if(unlikely(POS_SUCCESS != (
                retval = this->__collect_pos_support_header_files(entry.path(), header_file_meta)
            ))){
                POS_ERROR_C("failed to parse file %s", entry.path().c_str())
            }
        }
    }

exit:
    return retval;
}


pos_retval_t POSAutogener::collect_vendor_header_files(){
    pos_retval_t retval = POS_SUCCESS;
    pos_vendor_header_file_meta_t *header_file_meta;

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
            
            POS_CHECK_POINTER(header_file_meta = new pos_vendor_header_file_meta_t);
            this->_vendor_header_file_metas.push_back(header_file_meta);

            if(unlikely(POS_SUCCESS != (
                retval = this->__collect_vendor_header_file(entry.path(), header_file_meta)
            ))){
                POS_ERROR_C("failed to parse file %s", entry.path().c_str())
            }
        }
    }

exit:
    return retval;
}
