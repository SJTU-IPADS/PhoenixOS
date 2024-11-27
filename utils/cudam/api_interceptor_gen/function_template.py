# Copyright 2024 The PhoenixOS Authors. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

general = '''
#undef {{ function_name }}
{{ function_rettype }} {{ function_name }}({{ function_parameters }}){
    {{ function_rettype }} lretval;
    {{ function_rettype }} (*l{{ function_name }}) ({{ function_parameter_type_list }}) = ({{ function_rettype }} (*)({{ function_parameter_type_list }}))dlsym(RTLD_NEXT, "{{ called_function_name }}");
    
    /* pre exeuction logics */
    ac.add_counter("{{ function_name }}", {{ function_library }});

    lretval = l{{ function_name }}({{ function_parameter_name_list }});
    
    /* post exeuction logics */

    return lretval;
}
#define {{ function_name }} {{ called_function_name }}\n\n
'''

general_void_retval = '''
{{ function_rettype }} {{ function_name }}({{ function_parameters }}){
    {{ function_rettype }} (*l{{ function_name }}) ({{ function_parameter_type_list }}) = ({{ function_rettype }} (*)({{ function_parameter_type_list }}))dlsym(RTLD_NEXT, "{{ called_function_name }}");

    /* pre exeuction logics */
    ac.add_counter("{{ function_name }}", {{ function_library }});

    /* post exeuction logics */

    l{{ function_name }}({{ function_parameter_name_list }});
}\n\n
'''
