from io import TextIOWrapper
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
from matplotlib.colors import ListedColormap

def _cast_duration_s_from_ticks(nb_ticks:int, tsc_freq:int) -> float:
    return nb_ticks / tsc_freq

def _cast_duration_us_from_ticks(nb_ticks:int, tsc_freq:int) -> float:
    return nb_ticks / tsc_freq * 1000000


class POSOp:
    """ Operator within the POS DAG

    Attribute:
        id:             index of the operator (order)
        api_id:         indicate which api this operator calls
        return_code:    the api return code
        handle_map:     map of indices of related handles of this call: handle id -> direction
    """

    def __init__(
            self, id:int, api_id:int, return_code:int, 
            c_tick:int, r_tick:int, runtime_s_tick:int, runtime_e_tick:int, worker_s_tick:int, worker_e_tick:int, tsc_freq:int,
            nb_ckpt_handles:int = 0, ckpt_size:int = 0, ckpt_memory_consumption:int = 0
    ) -> None:
        self.id = id
        self.api_id = api_id
        self.return_code = return_code
        self.handle_map : dict[int,int] = {}
        self.c_tick = c_tick
        self.r_tick = r_tick
        self.runtime_s_tick = runtime_s_tick
        self.runtime_e_tick = runtime_e_tick
        self.worker_s_tick = worker_s_tick
        self.worker_e_tick = worker_e_tick
        self.tsc_freq = tsc_freq
        self.runtime_duration:float = _cast_duration_us_from_ticks(self.runtime_e_tick-self.runtime_s_tick, tsc_freq)
        self.worker_duration:float = _cast_duration_us_from_ticks(self.worker_e_tick-self.worker_s_tick, tsc_freq)
        self.physical_duration:float = _cast_duration_us_from_ticks(self.r_tick-self.c_tick, tsc_freq)

        self.nb_ckpt_handles = nb_ckpt_handles
        self.ckpt_size = ckpt_size
        self.ckpt_memory_consumption = ckpt_memory_consumption

    def add_handle_id(self, hid:int, direction:int):
        if hid in self.handle_map.keys():
            raise Exception(f"try to add duplicate handle id{hid} for op{self.id}")
        self.handle_map[hid] = direction

class POSHandle:
    """ Handle within the POS DAG

    Attribute:
        id:                 index of the operator (order)
        resource_type_id:   type of the resource that this handle represents
        resource_name:      name of the resource
        client_addr:        client-side handle address
        server_addr:        server-side handle address
        state:              state of this handle in the final
        size:               resource size behind this handle
        op_map:             map of indices of related operators of this handle: op id -> direction
    """

    def __init__(self, id:int, resource_type_id:int, resource_name:str, client_addr:str, server_addr:str, state:int, size:int) -> None:
        self.id:int = id
        self.resource_type_id:int = resource_type_id
        self.resource_name:str = resource_name
        self.client_addr:str = client_addr
        self.server_addr:str = server_addr
        self.state:int = state
        self.size:int = size
        self.op_map : dict[int, int] = {}

    def add_op_id(self, opid:int, direction:int):
        if opid in self.op_map.keys():
            raise Exception(f"try to add duplicate op id{opid} for handle{self.id}")
        self.op_map[opid] = direction


class POSDag:
    """ POS DAG, generate through trace file

    Attributes:
        trace_file: opened trace file
        nb_handles: number of handles within the DAG
        nb_ops:     number of ops within the DAG
        ops:        dict of POSOp: vertex id -> POSOp
        handles:    dict of POSHandle: vertex id -> POSHandle
        dat_mat:    matric representation of the DAG
    """

    def __init__(self, file_path:str) -> None:
        self.trace_file:TextIOWrapper = open(file_path, 'r')
        self.nb_handles:int = 0
        self.nb_ops:int = 0
        self.ops : dict[int, POSOp] = {}
        self.tsc_freq:int = 0
        self.handles : dict[int, POSHandle] = {}
        self.dag_mat : list = []

        print(f">>> parsing trace file {file_path}...")
        self._parse_trace_file()

    def __del__(self):
        self.trace_file.close()

    def _parse_trace_file(self):
        lines = self.trace_file.readlines()
        for id, line in enumerate(lines):
            # first line: #ops, #handles
            if(id == 0):
                self.nb_ops, self.nb_handles, self.tsc_freq = [int(x.strip()) for x in line.split(',')]
                continue
            
            # next self.nb_ops lines: info of ops
            if(id <= self.nb_ops):
                vid, api_id, return_code,                                                       \
                c_tick, r_tick, runtime_s_tick, runtime_e_tick, worker_s_tick, worker_e_tick,   \
                nb_ckpt_handles, ckpt_size, ckpt_memory_consumption                             \
                    = [int(x.strip()) for x in line.split(',')]
                op = POSOp(
                    vid, api_id, return_code,
                    c_tick, r_tick, runtime_s_tick, runtime_e_tick, worker_s_tick, worker_e_tick, self.tsc_freq, 
                    nb_ckpt_handles, ckpt_size, ckpt_memory_consumption
                )
                self.ops[vid] = op
                continue
            
            # next self.nb_handles lines: info of handles
            if(id <= self.nb_ops + self.nb_handles):
                vid, resource_type_id, resource_name, client_addr, server_addr, state, size, parent_idx_remain \
                    = [x.strip() for x in line.split(',', 7)]
                vid = int(vid)
                resource_type_id = int(resource_type_id)

                if client_addr.isdigit():
                    client_addr = hex(int(client_addr, 16))
                else:
                    client_addr = 0
                
                if server_addr.isdigit():
                    server_addr = hex(int(server_addr, 16))
                else:
                    server_addr = 0
                
                state = int(state)
                size = int(size)

                # process depdendent parents
                # print(parent_idx_remain)
                # TODO: 

                handle = POSHandle(vid, resource_type_id, resource_name, client_addr, server_addr, state, size)
                self.handles[vid] = handle
                continue
            
            # next self.nb_handles line: topology between ops and handles
            if id <= self.nb_ops + 2*self.nb_handles:
                if line.count(',') == 1:
                    """this handle has no op to use"""
                    continue
                
                vid, nb_neighbor, remain = [x.strip() for x in line.split(',', 2)]
                vid = int(vid)
                nb_neighbor = int(nb_neighbor)

                handle = self.handles[vid]

                for i in range(0, nb_neighbor):
                    if i != nb_neighbor-1:
                        nid, direction, remain = [x.strip() for x in remain.split(',', 2)]
                        nid = int(nid)
                        direction = int(direction)
                    else:
                        nid, direction = [x.strip() for x in remain.split(',')]
                        nid = int(nid)
                        direction = int(direction)

                    op = self.ops[nid]

                    op.add_handle_id(handle.id, direction)
                    handle.add_op_id(op.id, direction)

    def collapse_matrix(self):
        print(f">>> collapsing DAG to matrix...")
        for id, op in self.ops.items():
            handle_vector = list(4 for _ in range(self.nb_handles))
            for hid, direction in op.handle_map.items():
                handle_vector[hid] = direction
            self.dag_mat.append(handle_vector)

    def analyse_dag(self, figure_dir_path:str):
        self._analyse_ckpt(figure_dir_path)
        self._analyse_ops()

    def _analyse_ops(self):
        print(">>> analysing ops...")
        api_call_times : dict[int, int] = {}
        runtime_duration_dict : dict[int,list[float]] = {}
        worker_duration_dict : dict[int,list[float]] = {}
        physical_duration_dict : dict[int,list[float]] = {}

        for id, op in self.ops.items():
            if op.api_id not in api_call_times.keys():
                api_call_times[op.api_id] = 1
            else:
                api_call_times[op.api_id] += 1

            if op.api_id not in runtime_duration_dict.keys():
                runtime_duration_dict[op.api_id] = list()
            runtime_duration_dict[op.api_id].append(op.runtime_duration)

            if op.api_id not in worker_duration_dict.keys():
                worker_duration_dict[op.api_id] = list()
            worker_duration_dict[op.api_id].append(op.worker_duration)

            if op.api_id not in physical_duration_dict.keys():
                physical_duration_dict[op.api_id] = list()
            physical_duration_dict[op.api_id].append(op.physical_duration)

        for api_id, call_time in api_call_times.items():
            print(f"\napi: {api_id}, call_times: {call_time}")

            def _analyse_duration(duration_list:list):
                np_array = np.array(duration_list)
                return  np.percentile(np_array, 10), np.percentile(np_array, 50), np.percentile(np_array, 99),\
                        np.mean(np_array), np.min(np_array), np.max(np_array)

            def _print_statistics(duration_list:list, name:str):
                p10, p50, p99, mean, min, max = _analyse_duration(duration_list)
                print(f"{name}: p10({p10:.2f} us), p50({p50:.2f} us), p99({p99:.2f} us), mean({mean:.2f} us), min({min:.2f} us), max({max:.2f} us)")

            _print_statistics(runtime_duration_dict[api_id], "runtime")
            _print_statistics(worker_duration_dict[api_id], "worker")
            _print_statistics(physical_duration_dict[api_id], "physical")

    def _analyse_ckpt(self, figure_dir_path:str):
        print(">>> analysing checkpoint...")
        normal_ops : list[POSOp] = []
        checkpoint_ops : list[POSOp] = []
        normal_ops_duration : int = 0
        checkpoint_ops_duration : int = 0
        checkpoint_size : int = 0

        for id, op in self.ops.items():
            if op.api_id == 6666:
                checkpoint_ops.append(op)
                checkpoint_ops_duration += op.worker_duration
                checkpoint_size += op.ckpt_size
            else:
                normal_ops.append(op)
                # normal_ops_duration += op.runtime_duration + op.worker_duration
                normal_ops_duration += op.worker_duration

        print(
            f"normal ops duration: {normal_ops_duration} us, ckpt ops duration: {checkpoint_ops_duration} us, times of ckpt: {len(checkpoint_ops)}"
        )

        print(f"ckpt size: {checkpoint_size / 1024 / 1024 / 1024} GB")

        # draw figure
        # >>>>>>>>>> Draw checkpoint op series figure <<<<<<<<<<
        ckpt_op_series : list[tuple] = []
        # print(">>>>>> ckpt statistics")
        # print(f"    nb_ops({len(self.ops)}), nb_ckpt_ops({len(checkpoint_ops)}, %{len(checkpoint_ops)/len(self.ops)})")
        # print("     details:")
        for id, ckpt_op in enumerate(checkpoint_ops):
            # print(
            #     f"        {id}: duration = {ckpt_op.worker_duration}s, nb_ckpt_handles = {ckpt_op.nb_ckpt_handles}, ckpt_size = {ckpt_op.ckpt_size}"
            # )
            ckpt_op_series.append((id, ckpt_op.worker_duration, ckpt_op.nb_ckpt_handles, ckpt_op.ckpt_size, ckpt_op.ckpt_memory_consumption))
        
        ckpt_dataframe:pd.DataFrame = pd.DataFrame(
            data = {
                'idx': [x[0] for x in ckpt_op_series],
                'durations': [x[1] for x in ckpt_op_series],
                'nb_ckpt_handles': [x[2] for x in ckpt_op_series],
                'ckpt_sizes': [x[3] / 1024 / 1024 for x in ckpt_op_series],
                'ckpt_memory_consumption': [x[4] / 1024 / 1024 for x in ckpt_op_series],
            }
        )
        
        plt.figure(figsize=(9, 6), dpi=200)
        plt.title("Checkpoint Process")
        plt.xlabel("Checkpoint Op Id", fontsize=10)
        plt.xticks(size=6)
        plt.grid(True, linestyle='dashed', alpha=0.5)
    
        ax1 = sns.barplot(data=ckpt_dataframe, x='idx', y='durations')
        ax1.set_ylabel("Duration / us")

        ax2 = ax1.twinx()
        # sns.lineplot(data=ckpt_dataframe, x='idx', y='ckpt_sizes', marker='o', ax=ax2, color = 'r')
        sns.lineplot(data=ckpt_dataframe, x='idx', y='ckpt_sizes', ax=ax2, color = 'r')
        ax2.set_ylabel("# Checkpointed Size / MB")

        plt.savefig(f"{figure_dir_path}/ckpt_series.png")

        # >>>>>>>>>> Draw memory consumption figure <<<<<<<<<<
        plt.clf()
        plt.figure(figsize=(9, 6), dpi=200)
        plt.title("Memory Consumption")
        plt.xlabel("Checkpoint Op Id", fontsize=10)
        plt.xticks(size=6)
        plt.grid(True, linestyle='dashed', alpha=0.5)

        ax3 = sns.lineplot(data=ckpt_dataframe, x='idx', y='ckpt_memory_consumption', color = 'r')
        ax3.set_ylabel("Memory Consumption / MB")
        plt.savefig(f"{figure_dir_path}/memory_consumption.png")

    def dump_matrix(self, file_path:str):
        print(f">>> dumping matrix to figure...")
        plt.figure(figsize=(self.nb_ops * 0.3, self.nb_handles * 0.3),dpi=100)

        """colors for 4 types of opearation direction
            0: kPOS_Edge_Direction_In
            1: kPOS_Edge_Direction_Out
            2: kPOS_Edge_Direction_InOut
            3: kPOS_Edge_Direction_Create
            4: no relation ship
        """ 
        cmap_dict = {0: '#0065ff', 1: '#fb0202', 2: '#7e0000', 3: '#9b9b9b', 4: '#ffffff'}
        cmap = ListedColormap([cmap_dict[i] for i in range(5)])

        """set labels
        """
        y_axis_labels = [handle.resource_name for handle in self.handles.values()]

        """create heat map
        """
        array = np.array(self.dag_mat).transpose()
        hm = sns.heatmap(
            data=array,
            vmax=5,
            cmap=cmap,
            linewidths=0.3,
            linecolor='#eaeaea',
            yticklabels=y_axis_labels
        )

        """setting up colorbar
        """
        colorbar = hm.collections[0].colorbar
        # show the border of the colorbar
        for spine in colorbar.ax.spines.values():
            spine.set_visible(True)
        # set legend
        colorbar.set_ticks([0.5, 1.5, 2.5, 3.5, 4.5])
        colorbar.set_ticklabels(['In', 'Out', 'In & Out', 'Create', 'N/A'])
        colorbar.ax.tick_params(labelsize=15)

        """set axis
        """
        hm.set_xlabel("Operators",fontsize=15)
        hm.set_ylabel("Resources",fontsize=15)

        hm.get_figure().savefig(file_path)

if __name__ == "__main__":
    dag = POSDag(file_path="/root/dag.pos")

    
    dag.analyse_dag(figure_dir_path="/root")

    # dag.collapse_matrix()
    # dag.dump_matrix(file_path="/root/dag_matrix.png")
