import datetime
import os

YEAR = str(datetime.date.today().year)


c_cpp_cu_license_text = """/*
Copyright {} The PhoenixOS Authors. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/""".format(YEAR)


py_license_text = """'''
Copyright {} The PhoenixOS Authors. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
'''""".format(YEAR)


def process_c_cpp_cu():
    for root, dirs, files in os.walk('.'):
        for file in files:
            # modify this line to match the type of files you want to handle
            if file.endswith('.cpp') or file.endswith('.hpp')       \
                or file.endswith('.c') or file.endswith('.h')       \
                or file.endswith('.cu') or file.endswith('.cuh'):
                file_path = os.path.join(root, file)
                with open(file_path, 'r+') as f:
                    content = f.read()
                    
                    # remove old copyright if exists
                    while True:
                        start_index = content.find("/*\nCopyright ")
                        if start_index == -1:
                            break
                        end_index =                                                             \
                            content.find("limitations under the License.\n*/\n", start_index)   \
                            + len("limitations under the License.\n*/\n")
                        content = content[:start_index] + content[end_index:]
                    
                    # add new copyright
                    f.seek(0, 0)
                    f.write(c_cpp_cu_license_text + '\n' + content)
