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

class func_arg:
    def __init__(self, decl_type:str, name:str, order:int):
        self.decl_type = decl_type
        self.name = name
        self.order = order

def sort_func_arg(arg:func_arg):
    return arg.order

class api:
    def __init__(self, api_name:str, redefined_api_name:str=""):
        self.name = api_name
        self.nb_args = 0
        self.arg_list = list()
        self.redefined_api_name = redefined_api_name

    def add_arg(self, decl_type:str, name:str, order:int):
        arg = func_arg(decl_type=decl_type, name=name, order=order)
        self.arg_list.append(arg)
        self.arg_list.sort(key=sort_func_arg)

    def add_retval(self, decl_type:str):
        self.retval_decl_type = decl_type
