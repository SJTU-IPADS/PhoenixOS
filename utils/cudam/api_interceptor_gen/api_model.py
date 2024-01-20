class func_arg:
    def __init__(self, decl_type:str, name:str, order:int):
        self.decl_type = decl_type
        self.name = name
        self.order = order

def sort_func_arg(arg:func_arg):
    return arg.order

class api:
    def __init__(self, api_name:str):
        self.name = api_name
        self.nb_args = 0
        self.arg_list = list()

    def add_arg(self, decl_type:str, name:str, order:int):
        arg = func_arg(decl_type=decl_type, name=name, order=order)
        self.arg_list.append(arg)
        self.arg_list.sort(key=sort_func_arg)

    def add_retval(self, decl_type:str):
        self.retval_decl_type = decl_type

