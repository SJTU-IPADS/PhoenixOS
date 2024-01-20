import numpy as np
import sys
from tabulate import tabulate

kIndex_Timestamp = 0
kIndex_Nb_Buffer = 1
kIndex_Nb_Active_Buffer = 2
kIndex_Nb_Duplicated_Buffer = 3
kIndex_Nb_Cpu_Buffer = 4
kIndex_Nb_Device_Buffer = 5
kIndex_Nb_Unified_Buffer = 6
kIndex_Overall_Buffer_Size = 7
kIndex_Overall_Active_Buffer_Size = 8
kIndex_Overall_Duplicated_Buffer_Size = 9
kIndex_Overall_Cpu_Buffer_Size = 10
kIndex_Overall_Device_Buffer_Size = 11
kIndex_Overall_Unified_Buffer_Size = 12

# timestamps = data[:,kIndex_Timestamp]
# nb_buffer = data[:,kIndex_Nb_Buffer]
# nb_active_buffer = data[:,kIndex_Nb_Active_Buffer]
# nb_duplicated_buffer = data[:,kIndex_Nb_Duplicated_Buffer]
# nb_cpu_buffer = data[:,kIndex_Nb_Cpu_Buffer]
# nb_device_buffer = data[:,kIndex_Nb_Device_Buffer]
# nb_unified_buffer = data[:,kIndex_Nb_Unified_Buffer]
# overall_buffer_size = data[:,kIndex_Overall_Buffer_Size]
# overall_active_buffer_size = data[:,kIndex_Overall_Active_Buffer_Size]
# overall_duplicated_buffer_size = data[:,kIndex_Overall_Duplicated_Buffer_Size]
# overall_cpu_buffer_size = data[:,kIndex_Overall_Cpu_Buffer_Size]
# overall_device_buffer_size = data[:,kIndex_Overall_Device_Buffer_Size]
# overall_unified_buffer_size = data[:,kIndex_Overall_Unified_Buffer_Size]

data = np.loadtxt(sys.argv[1])

# cast timestamp
timestamps = data[:,kIndex_Timestamp]
initial_timestamp = timestamps[0]
for i in range(0, len(data[:,kIndex_Timestamp])):
    data[:,kIndex_Timestamp][i] = (timestamps[i]-initial_timestamp)/1000000

# print
data_list = data.tolist()
data_list.insert(0, [
    "timestamp\n(ms)",
    "# buffers",
    "# active buffers",
    "# duplicated buffers",
    "# cpu buffers",
    "# device buffers",
    "# unified buffers",
    "buffer size\n(bytes)",
    "active buffer size\n(bytes)",
    "duplicated buffer size\n(bytes)",
    "cpu buffer size\n(bytes)",
    "device buffer size\n(bytes)",
    "unified buffer size\n(bytes)"
])
print(tabulate(data_list, headers='firstrow', tablefmt='fancy_grid'))





