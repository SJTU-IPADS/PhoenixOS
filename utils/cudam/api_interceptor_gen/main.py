import os
import sys
from pygccxml import utils
from pygccxml import declarations
from pygccxml import parser
from jinja2 import Template

from api_model import api
import global_config
import file_head
import function_template

# we record the parsed function to avoid duplication
parsed_function = []

# force cast map
redefine_map = {
    # nvml
    "nvmlInit_v2": "nvmlInit", 
    "nvmlDeviceGetPciInfo_v3": "nvmlDeviceGetPciInfo",
    "nvmlDeviceGetCount_v2": "nvmlDeviceGetCount",
    "nvmlDeviceGetHandleByIndex_v2": "nvmlDeviceGetHandleByIndex",
    "nvmlDeviceGetHandleByPciBusId_v2": "nvmlDeviceGetHandleByPciBusId",
    "nvmlDeviceGetNvLinkRemotePciInfo_v2": "nvmlDeviceGetNvLinkRemotePciInfo",
    "nvmlDeviceRemoveGpu_v2": "nvmlDeviceRemoveGpu",
    "nvmlDeviceGetGridLicensableFeatures_v3": "nvmlDeviceGetGridLicensableFeatures",
    "nvmlEventSetWait_v2": "nvmlEventSetWait",
    "nvmlDeviceGetAttributes_v2": "nvmlDeviceGetAttributes",
    "nvmlComputeInstanceGetInfo_v2": "nvmlComputeInstanceGetInfo",
    "nvmlDeviceGetComputeRunningProcesses_v2": "nvmlDeviceGetComputeRunningProcesses",
    "nvmlDeviceGetGraphicsRunningProcesses_v2": "nvmlDeviceGetGraphicsRunningProcesses",
    "nvmlGetExcludedDeviceCount": "nvmlGetBlacklistDeviceCount",
    "nvmlGetExcludedDeviceInfoByIndex": "nvmlGetBlacklistDeviceInfoByIndex"
}

def __parse_apis_from_header(header_file_path:str) -> list:
    # parse apis from header
    generator_path, generator_name = utils.find_xml_generator()
    xml_generator_config = parser.xml_generator_configuration_t(
        xml_generator_path=generator_path,
        xml_generator=generator_name,
        include_paths=[global_config.kCudaPath + "/include"]
    )
    decls = parser.parse([header_file_path], xml_generator_config)

    api_list = list()

    global_anonymous_ns = declarations.get_global_namespace(decls)
    
    for free_function in global_anonymous_ns.free_functions():
        parsed_function_signature = ""
        redefined_function_signature = ""

        if(
            free_function.name[0:2] != "cu" 
            and free_function.name[0:4] != "__cu" 
            and free_function.name[0:6] != "cublas"
            and free_function.name[0:5] != "cudnn"
            and free_function.name[0:5] != "cufft"
            and free_function.name[0:6] != "curand"
            and free_function.name[0:8] != "cusolver"
            and free_function.name[0:4] != "nvml"
        ):
            continue
        
        if(free_function.has_inline):
            continue
        
        is_redefined_function = False
        if free_function.name in redefine_map.keys():
            is_redefined_function = True

        parsed_function_signature += f"{free_function.name}"
        if is_redefined_function:
            redefined_function_signature += f"{redefine_map[free_function.name]}"

        new_api = api(api_name=free_function.name)
        if is_redefined_function:
            redefined_new_api = api(
                api_name=redefine_map[free_function.name],
                redefined_api_name=free_function.name
            )

        # parse arguments
        for index, arg in enumerate(free_function.arguments):
            new_api.add_arg(decl_type=str(arg.decl_type), name=arg.name, order=index)
            parsed_function_signature += f"_p{index}_{str(arg.decl_type)}_{arg.name}"
            if is_redefined_function:
                redefined_new_api.add_arg(decl_type=str(arg.decl_type), name=arg.name, order=index)
                redefined_function_signature += f"_p{index}_{str(arg.decl_type)}_{arg.name}"

        # parse return value
        new_api.add_retval(decl_type=str(free_function.return_type))
        parsed_function_signature += f"_r_{str(free_function.return_type)}"
        if is_redefined_function:
            redefined_new_api.add_retval(decl_type=str(free_function.return_type))
            redefined_function_signature += f"_r_{str(free_function.return_type)}"

        if parsed_function_signature not in parsed_function:
            api_list.append(new_api)
            parsed_function.append(parsed_function_signature)

        if is_redefined_function:
            if redefined_function_signature not in parsed_function:
                api_list.append(redefined_new_api)
                parsed_function.append(redefined_function_signature)
        


    return api_list


def interceptors_render(header_file_path:str, output_path:str, function_library:str, file_head:str):
    apis = __parse_apis_from_header(header_file_path)

    if os.path.isfile(output_path):
        os.remove(output_path)

    with open(output_path, 'a+') as f:
        t = Template(function_template.general)
        t_void = Template(function_template.general_void_retval)

        # write file head
        f.write(file_head)
        
        # write each api
        for api in apis:
            function_parameters = ""
            function_parameter_type_list = ""
            function_parameter_name_list = ""
            for index, arg in enumerate(api.arg_list):
                if index != len(api.arg_list)-1:
                    function_parameters += f"{arg.decl_type} {arg.name}, "
                    function_parameter_type_list += f"{arg.decl_type}, "
                    function_parameter_name_list += f"{arg.name}, "
                else:
                    function_parameters += f"{arg.decl_type} {arg.name}"
                    function_parameter_type_list += f"{arg.decl_type}"
                    function_parameter_name_list += f"{arg.name}"

            def render_dispatching(
                __api, __template, __function_parameters, __function_library,
                __function_parameter_type_list, __function_parameter_name_list
            ) -> str:
                if __api.redefined_api_name == "":
                    __code = __template.render(
                        function_rettype=__api.retval_decl_type,
                        function_name=__api.name,
                        called_function_name=__api.name,
                        function_parameters=__function_parameters,
                        function_library=__function_library,
                        function_parameter_type_list=__function_parameter_type_list,
                        function_parameter_name_list=__function_parameter_name_list
                    )
                else:
                    __code = __template.render(
                        function_rettype=__api.retval_decl_type,
                        function_name=__api.name,
                        called_function_name=__api.redefined_api_name,
                        function_parameters=__function_parameters,
                        function_library=__function_library,
                        function_parameter_type_list=__function_parameter_type_list,
                        function_parameter_name_list=__function_parameter_name_list
                    )
                return __code

            template = None
            if api.retval_decl_type == "void":
                template = t_void
            else:
                template = t
                
            code = render_dispatching(
                __api = api,
                __template = template,
                __function_parameters = function_parameters,
                __function_library = function_library,
                __function_parameter_type_list = function_parameter_type_list,
                __function_parameter_name_list = function_parameter_name_list
            )
            
            f.write(code)

if __name__ == '__main__':
    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cuda_runtime_api.h",
        output_path = "./outputs/runtime_api.cpp",
        function_library = "kApiTypeRuntime",
        file_head = file_head.runtime
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cuda.h",
        output_path = "./outputs/driver_api.cpp",
        function_library = "kApiTypeDriver",
        file_head = file_head.driver
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cublas_v2.h",
        output_path = "./outputs/cublas_v2_api.cpp",
        function_library = "kApiTypeCublasV2",
        file_head = file_head.cublas_v2,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cudnn.h",
        output_path = "./outputs/cudnn.cpp",
        function_library = "kApiTypeCuDNN",
        file_head = file_head.cudnn,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cusolverDn.h",
        output_path = "./outputs/cusolver_dn.cpp",
        function_library = "kApiTypeCuSolver",
        file_head = file_head.cusolver,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cusolverMg.h",
        output_path = "./outputs/cusolver_mg.cpp",
        function_library = "kApiTypeCuSolver",
        file_head = file_head.cusolver,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cusolverRf.h",
        output_path = "./outputs/cusolver_rf.cpp",
        function_library = "kApiTypeCuSolver",
        file_head = file_head.cusolver,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cusolverSp.h",
        output_path = "./outputs/cusolver_sp.cpp",
        function_library = "kApiTypeCuSolver",
        file_head = file_head.cusolver,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/nvml.h",
        output_path = "./outputs/nvml.cpp",
        function_library = "kApiTypeNvml",
        file_head = file_head.nvml,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/curand.h",
        output_path = "./outputs/curand.cpp",
        function_library = "kApiTypeCuRand",
        file_head = file_head.curand,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cufft.h",
        output_path = "./outputs/cufft.cpp",
        function_library = "kApiTypeCuFFT",
        file_head = file_head.cufft,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cufftw.h",
        output_path = "./outputs/cufftw.cpp",
        function_library = "kApiTypeCuFFT",
        file_head = file_head.cufft,
    )