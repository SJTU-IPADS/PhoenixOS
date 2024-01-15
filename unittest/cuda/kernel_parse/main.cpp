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
