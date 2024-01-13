#include <iostream>
#include <string>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/cuda_impl/utils/fatbin.h"

int main(){
    pos_retval_t retval;
    uint64_t i;
    POSCudaFunctionDesp_ptr function_desp;
    std::vector<std::string> kernel_demangles_names({
        "_ZN14at_cuda_detail3cub30DeviceRadixSortDownsweepKernelINS0_21DeviceRadixSortPolicyIiN2at4cuda3cub6detail10OpaqueTypeILi1EEEiE9Policy800ELb0ELb0EiS8_iEEvPKT2_PSB_PKT3_PSF_PT4_SJ_iiNS0_13GridEvenShareISJ_EE",
        "_Z30_float_to_bfloat16_cuda_kernelPKfiiPt"
    });

    for(auto& name : kernel_demangles_names){
        function_desp = std::make_shared<POSCudaFunctionDesp_t>();
        POS_CHECK_POINTER(function_desp);
        retval = POSUtil_CUDA_Kernel_Parser::parse_by_prototype(name.c_str(), function_desp);
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_DETAIL("failed to extract parameter hints (pointer, direction): kernel_name(%s)", name.c_str());
        }
        
        POS_LOG("kernel: %s", name.c_str());
        POS_LOG("input pointers:");
        for(i=0; i<function_desp->input_pointer_params.size(); i++){ POS_LOG("    %lu", function_desp->input_pointer_params[i]); }
        POS_LOG("output pointers:");
        for(i=0; i<function_desp->output_pointer_params.size(); i++){ POS_LOG("    %lu", function_desp->output_pointer_params[i]); }
    }
}


// #include <iostream>
// #include <string>
// #include <algorithm>

// #include <string.h>
// #include <clang-c/Index.h>

// #include "pos/include/common.h"
// #include "pos/include/log.h"
// #include "pos/include/utils/string.h"

// int main(int argc, char** argv) {
//     CXIndex index;
//     CXUnsavedFile unsaved_file;
//     CXTranslationUnit translation_unit;
//     CXCursor root_cursor;
//     CXErrorCode cx_retval;
//     std::string kernel_prototype, processed_kernel_prototype;

//     index = clang_createIndex(0, 0);
//     // kernel_prototype = std::string("void kernel_1(const float *, float *, float *, float *, int);");
//     kernel_prototype = std::string("void at_cuda_detail::cub::DeviceRadixSortDownsweepKernel<at_cuda_detail::cub::DeviceRadixSortPolicy<int, at::cuda::cub::detail::OpaqueType<1>, int>::Policy800, false, false, int, at::cuda::cub::detail::OpaqueType<1>, int>(int const*, int*, at::cuda::cub::detail::OpaqueType<1> const*, at::cuda::cub::detail::OpaqueType<1>*, int*, int, int, int, at_cuda_detail::cub::GridEvenShare<int>)");

//     auto __find_field_range = [](char left_sign, char right_sign, const std::string& str, bool reverse_search=false) -> std::string {
//         int64_t i, nb_skip;
//         uint64_t left_sign_pos = std::string::npos, right_sign_pos = std::string::npos;

//         nb_skip = 0;

//         if(reverse_search){
//             right_sign_pos = str.find_last_of(right_sign, std::string::npos);
//             if (right_sign_pos == std::string::npos) 
//                 return std::string("");
        
//             for(i=right_sign_pos-1; i>=0; i--){
//                 if(unlikely(str[i] == right_sign)){
//                     nb_skip += 1;
//                 }
//                 if(unlikely(str[i] == left_sign)){
//                     if(nb_skip == 0){
//                         left_sign_pos = i;
//                         break;
//                     } else {
//                         nb_skip--;
//                     }
//                 }
//             }
//         } else {
//             left_sign_pos = str.find(left_sign);
//             if (left_sign_pos == std::string::npos) 
//                 return std::string("");
//             for(i=left_sign_pos+1; i<str.length(); i++){
//                 if(unlikely(str[i] == left_sign)){
//                     nb_skip += 1;
//                 }
//                 if(unlikely(str[i] == right_sign)){
//                     if(nb_skip == 0){
//                         right_sign_pos = i;
//                         break;
//                     } else {
//                         nb_skip--;
//                     }
//                 }
//             }
//         }
        
//         if(unlikely(
//             nb_skip > 0 || left_sign_pos == std::string::npos || right_sign_pos == std::string::npos 
//         )){
//             return std::string("");
//         } else {
//             return str.substr(left_sign_pos, right_sign_pos-left_sign_pos+1);
//         }
//     };

//     // POS_LOG(
//     //     "template_param_list: %s",
//     //     __find_field_range('<', '>', kernel_prototype).c_str()
//     // );

//     // POS_LOG(
//     //     "param_list: %s",
//     //     __find_field_range('(', ')', kernel_prototype, true).c_str()
//     // );

//     auto process_prototype = [&](std::string &prototype) -> std::string {
//         std::string mock_prototype, param_list;
//         pos_retval_t tmp_retval;
//         tmp_retval = POSUtil_String::extract_substring_from_field<true>('(', ')', prototype, param_list);
//         if(unlikely(tmp_retval != POS_SUCCESS)){
//             mock_prototype = std::string("void mocked_func();");
//         } else {
//             mock_prototype = std::string("void mocked_func") + param_list + std::string(";");
//         }
//         return mock_prototype;
//     };

//     processed_kernel_prototype = process_prototype(kernel_prototype);

//     unsaved_file.Filename = "temp.cpp";
//     unsaved_file.Contents = processed_kernel_prototype.c_str();
//     unsaved_file.Length = static_cast<unsigned long>(processed_kernel_prototype.length());

//     cx_retval = clang_parseTranslationUnit2(
//         /* CIdx */ index,
//         /* source_filename */ "temp.cpp",
//         /* command_line_args */ nullptr,
//         /* nb_command_line_args */ 0,
//         /* unsaved_files */ &unsaved_file,
//         /* nb_unsaved_file */ 1,
//         /* options */ CXTranslationUnit_None,
//         /* out_TU */ &translation_unit
//     );
//     if(unlikely(cx_retval != CXError_Success)){
//         POS_ERROR_DETAIL("failed to parse the function prototype from the memory buffer");
//     }
//     if(unlikely(translation_unit == nullptr)){
//         POS_ERROR_DETAIL("failed to create clang translation unit");
//     }

//     root_cursor = clang_getTranslationUnitCursor(translation_unit);

//     clang_visitChildren(
//         /* parent */ root_cursor,
//         /* visitor */ 
//         [](CXCursor cursor, CXCursor parent, CXClientData clientData) -> CXChildVisitResult {
//             CXType type = clang_getCursorType(cursor);
//             CXString typeName = clang_getTypeSpelling(type);
//             CXType pointeeType;

//             POS_LOG("children type: %d, typename: %s", cursor.kind, clang_getCString(typeName));

//             if(cursor.kind == CXCursor_ParmDecl) { // parameter 
//                 if (type.kind == CXType_Pointer) { // pointer type
//                     pointeeType = clang_getPointeeType(type);

//                     if(clang_isConstQualifiedType(pointeeType)){ // constant pointer type
//                         POS_LOG("    const pointer!")
//                     } else {
//                         POS_LOG("    isn't const pointer!")
//                     }
//                 }
//             }

//             return CXChildVisit_Recurse;
//         },
//         /* client_data */ nullptr
//     );

//     return 0;
// }
