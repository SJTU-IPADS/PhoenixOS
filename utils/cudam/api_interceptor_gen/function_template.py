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
