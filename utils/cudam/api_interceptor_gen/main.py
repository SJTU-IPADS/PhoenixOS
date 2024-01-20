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
        # we only care about APIs start with 'cu' within driver / runtime 
        if(free_function.name[0:2] != "cu" and free_function.name[0:4] != "__cu" and free_function.name[0:6] != "cublas"):
            continue
        if(free_function.has_inline):
            continue
        new_api = api(api_name=free_function.name)

        # parse arguments
        for index, arg in enumerate(free_function.arguments):
            new_api.add_arg(decl_type=str(arg.decl_type), name=arg.name, order=index)

        # parse return value
        new_api.add_retval(decl_type=str(free_function.return_type))

        api_list.append(new_api)

    return api_list


def interceptors_render(header_file_path:str, output_path:str, function_library:str, function_template:str, function_void_retval_template:str, file_head:str):
    apis = __parse_apis_from_header(header_file_path)

    if os.path.isfile(output_path):
        os.remove(output_path)

    with open(output_path, 'a+') as f:
        t = Template(function_template)
        t_void = Template(function_void_retval_template)

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
            
            if api.retval_decl_type == "void":
                code = t_void.render(
                    function_rettype=api.retval_decl_type,
                    function_name=api.name,
                    function_parameters=function_parameters,
                    function_library=function_library,
                    function_parameter_type_list=function_parameter_type_list,
                    function_parameter_name_list=function_parameter_name_list
                )
            else:
                code = t.render(
                    function_rettype=api.retval_decl_type,
                    function_name=api.name,
                    function_parameters=function_parameters,
                    function_library=function_library,
                    function_parameter_type_list=function_parameter_type_list,
                    function_parameter_name_list=function_parameter_name_list
                )

            f.write(code)


if __name__ == '__main__':
    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cuda_runtime_api.h",
        output_path = "./outputs/runtime_api.cpp",
        function_library = "kApiTypeRuntime",
        function_template = function_template.general,
        function_void_retval_template = function_template.general_void_retval,
        file_head = file_head.runtime,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cuda.h",
        output_path = "./outputs/driver_api.cpp",
        function_library = "kApiTypeDriver",
        function_template = function_template.general,
        function_void_retval_template = function_template.general_void_retval,
        file_head = file_head.driver,
    )

    interceptors_render(
        header_file_path = f"./headers/{global_config.kCudaVersion}/cublas_v2.h",
        output_path = "./outputs/cublas_v2_api.cpp",
        function_library = "kApiTypeCublasV2",
        function_template = function_template.general,
        function_void_retval_template = function_template.general_void_retval,
        file_head = file_head.cublas_v2,
    )
