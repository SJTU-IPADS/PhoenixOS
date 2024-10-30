import datetime
import os

YEAR = str(datetime.date.today().year)

# license text using /**/
slash_license_text = """/*
 * Copyright {} The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */""".format(YEAR)


# license text using #
sharp_license_text = """# Copyright {} The PhoenixOS Authors. All rights reserved.
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
# limitations under the License.""".format(YEAR)


def add_copyright(scan_dirs:list[str], file_suffixs:list[str], license_text:str):
    if license_text != slash_license_text and license_text != sharp_license_text:
        raise RuntimeError("unsupported license format")

    for scan_dir in scan_dirs:
        for root, dirs, files in os.walk(scan_dir):
            for file in files:
                # check whether suffix satisfy
                has_suffix = False
                for file_suffix in file_suffixs:
                    if file.endswith(file_suffix):
                        has_suffix = True
                        break
                if has_suffix == False:
                    continue
                
                file_path = os.path.join(root, file)

                # don't process file under 'build' directory
                directory_names = os.path.dirname(file_path).split('/')
                if "build" in directory_names:
                    continue

                with open(file_path, 'r+') as f:
                    content = f.read()
                    
                    # remove old copyright if exists
                    while True:
                        if license_text == slash_license_text:
                            start_index = content.find("/*\n * Copyright ")
                        elif license_text == sharp_license_text:
                            start_index = content.find("# Copyright ")

                        if start_index == -1:
                            break

                        if license_text == slash_license_text:
                            end_index = content.find(" * limitations under the License.\n */\n", start_index)   \
                                + len(" * limitations under the License.\n */\n")
                        elif license_text == sharp_license_text:
                            end_index = content.find("# limitations under the License.\n", start_index) \
                                + len("# limitations under the License.\n")                           
                        content = content[:start_index] + content[end_index:]

                    # add new copyright
                    f.seek(0, 0)
                    f.write(license_text + '\n' + content)

add_copyright(
    scan_dirs = ['./autogen', './microbench', './pos', './unittest', './utils', './scripts'],
    file_suffixs = [
        # c/cpp/cuda files
        '.cpp', '.hpp', '.c', '.h', 'cu', '.cuh', '.c.in', '.cpp.in', '.h.in', '.hpp.in',
        # other files
        'proto', 'go'
    ],
    license_text = slash_license_text
)

add_copyright(
    scan_dirs = ['./autogen', './microbench', './pos', './unittest', './utils', './scripts'],
    file_suffixs = ['.py', 'meson.build', '.sh'],
    license_text = sharp_license_text
)
