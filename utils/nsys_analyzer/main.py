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

import sys
import json

import numpy as np

filename = sys.argv[1]

class Kernel():
    def __init__(self, demangled_name_id:int, start_ns:int, end_ns:int) -> None:
        self.demangled_name_id = demangled_name_id
        self.start_us = start_ns / 1000
        self.end_us = end_ns / 1000


class Statistics():
    def __init__(self) -> None:
        self.kernels = list()

    def add_kernel(self, kernel:Kernel):
        self.kernels.append(kernel)

    def compact(self):
        self._compact_kernel_stats()

    def _compact_kernel_stats(self):
        duration_ns_list = list()
        duration_ns_map = dict()

        for kernel in self.kernels:
            duration_ns_list.append(kernel.end_us - kernel.start_us)

            if duration_ns_map.get(kernel.demangled_name_id) == None:
                duration_ns_map[kernel.demangled_name_id] = list()
            duration_ns_map[kernel.demangled_name_id].append(kernel.end_us - kernel.start_us)

        array = np.array(duration_ns_list)

        print(
            f"Average Kernels Durations: p10: {np.percentile(array, 10):.2f} us, "
            f"p50: {np.percentile(array, 50):.2f} us, p99: {np.percentile(array, 99):.2f} us, "
            f"mean: {np.mean(array):.2f} us, min: {np.min(array):.2f} us, max: {np.max(array):.2f} us"
        )

        for demangled_name_id, duration_ns_list in duration_ns_map.items():
            array = np.array(duration_ns_list)
            print(
                f"Kernels {demangled_name_id} duration varience: {np.std(array):.2f}"
            )

def __process_cuda_event(stat:Statistics, event:dict):
    kernel_duration = list()

    def __process_memcpy():
        pass

    def __process_memset():
        pass

    def __process_kernel_launch():
        new_kernel = Kernel(
            demangled_name_id = int(event["kernel"]["demangledName"]),
            start_ns = int(event["startNs"]),
            end_ns = int(event["endNs"])
        )
        stat.add_kernel(kernel=new_kernel)

    eventClass = event["eventClass"]

    if eventClass == 1:
        __process_memcpy()
    elif eventClass == 2:
        __process_memset()
    elif eventClass == 3:
        __process_kernel_launch()
    else:
        raise RuntimeError(f"haven't support parsing of CudaEvent with eventClass {eventClass}")

def __process_trace_process_event(stat:Statistics, event:dict):
    pass


if __name__ == "__main__":

    stat = Statistics()

    with open(filename, 'r') as f:
        for line in f:
            data = json.loads(line)

            # we filter out those extra record
            record_type = -1
            for key, value in data.items():
                if key == "Type":
                    record_type = value
            if record_type < 0:
                continue
            
            if record_type == 48:   # TraceProcessEvent
                __process_trace_process_event(stat=stat, event=data["TraceProcessEvent"])
            elif record_type == 79:   # CudaEvent
                __process_cuda_event(stat=stat, event=data["CudaEvent"])
            else:
                continue

    stat.compact()
    

