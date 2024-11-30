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

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

dir_path="./ckpt"

# checkpoint to stop?
do_stop=true

# clear old checkpoint?
do_clear=false

# use cuda-checkpoint?
do_nvcr=false

function get_latest_ckpt_version(){
    if [ -d "$dir_path" ]; then
        largest_num=$(ls $dir_path | grep '^[0-9]*$' | sort -nr | head -1)
        if [ -z "$largest_num" ]; then
            # echo "No numeric subfolders found."
            return 0
        else
            # echo "The largest numeric subfolder is: $largest_num"
            return $largest_num
        fi
    else
        echo "Parent directory does not exist."
        exit 1
    fi
}

ckpt_without_stop() {
    pid=$(ps -ef | grep python3 | grep -v grep | awk '{print $2}')

    if [ -z "$pid" ]
    then
        echo "No python3 process found."
        exit 1
    else
        echo "ckpt pid $pid"
        get_latest_ckpt_version
        prev_ckpt_version=$?
        prev_ckpt_dir="../$prev_ckpt_version"
        next_ckpt_version=$(($prev_ckpt_version + 1))
        next_ckpt_dir="$dir_path/$next_ckpt_version"
        mkdir $next_ckpt_dir
        mount -t tmpfs -o size=80g tmpfs $next_ckpt_dir
        gpu_ckpt_time=0
        cpu_ckpt_time=0
        gpu_restore_time=0
        if [ $prev_ckpt_version = 0 ]; then
            start=$(date +%s.%3N)
            if [ $do_nvcr = true ]; then
                # stop gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi
            end=$(date +%s.%3N)
            gpu_ckpt_time=$(echo "$end - $start" | bc)
            echo "gpu stop: $gpu_ckpt_time s"

            # criu dump
            start=$(date +%s.%3N)
            criu pre-dump --tree $pid --images-dir $next_ckpt_dir --leave-running --track-mem --shell-job --display-stats
            end=$(date +%s.%3N)
            cpu_ckpt_time=$(echo "$end - $start" | bc)
            echo "pre-dump: $cpu_ckpt_time s"

            start=$(date +%s.%3N)
            if [ $do_nvcr = true ]; then
                # restore gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi
            end=$(date +%s.%3N)
            gpu_restore_time=$(echo "$end - $start" | bc)
            echo "gpu resume: $gpu_restore_time s"
        else
            start=$(date +%s.%3N)
            if [ $do_nvcr = true ]; then
                # stop gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi
            end=$(date +%s.%3N)
            gpu_ckpt_time=$(echo "$end - $start" | bc)
            echo "gpu stop: $gpu_ckpt_time s"

            # criu dump
            start=$(date +%s.%3N)
            criu pre-dump --tree $pid --images-dir $next_ckpt_dir --prev-images-dir $prev_ckpt_dir --leave-running --track-mem --shell-job --display-stats
            end=$(date +%s.%3N)
            cpu_ckpt_time=$(echo "$end - $start" | bc)
            echo "pre-dump: $cpu_ckpt_time s"

            start=$(date +%s.%3N)
            if [ $do_nvcr = true ]; then
                # restore gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi
            end=$(date +%s.%3N)
            gpu_restore_time=$(echo "$end - $start" | bc)
            echo "gpu resume: $gpu_restore_time s"
        fi
        echo "ckpt to: $next_ckpt_dir"
    fi
}

ckpt_with_stop() {
    pid=$(ps -ef | grep python3 | grep -v grep | awk '{print $2}')

    if [ -z "$pid" ]
    then
        echo "No python3 process found."
        exit 1
    else
        echo "ckpt pid $pid"
        get_latest_ckpt_version
        prev_ckpt_version=$?
        prev_ckpt_dir="../$prev_ckpt_version"
        next_ckpt_version=$(($prev_ckpt_version + 1))
        next_ckpt_dir="$dir_path/$next_ckpt_version"
        mkdir $next_ckpt_dir
        mount -t tmpfs -o size=80g tmpfs $next_ckpt_dir
        if [ $prev_ckpt_version = 0 ]; then
            start=$(date +%s.%3N)
            if [ $do_nvcr = true ]; then
                # stop gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi
            end=$(date +%s.%3N)
            echo $(echo "$end - $start" | bc)

            # stop cpu
            start=$(date +%s.%3N)
            criu dump --tree $pid --images-dir $next_ckpt_dir --shell-job --display-stats
            end=$(date +%s.%3N)
            echo $(echo "$end - $start" | bc)
        else
            start=$(date +%s.%3N)
            if [ $do_nvcr = true ]; then
                # stop gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi
            end=$(date +%s.%3N)
            echo $(echo "$end - $start" | bc)

            # stop cpu
            start=$(date +%s.%3N)
            criu dump --tree $pid --prev-images-dir $prev_ckpt_dir --images-dir $next_ckpt_dir --shell-job --display-stats
            end=$(date +%s.%3N)
            echo $(echo "$end - $start" | bc)
        fi
        echo "ckpt version: $next_ckpt_dir"
        # if [ "$?" = "0" ] ; then
        #     echo "Checkpoint of PID $p created successfully.";
        # else
        #     echo "Error creating checkpoint for PID $p";
        # fi
    fi
}

mount_mem_ckpt() {
    mount -t tmpfs -o size=80g tmpfs $dir_path
}

umount_mem_ckpt() {
    for dir in "$dir_path"/*/; do
        if [ -d "$dir" ]; then
            umount "$dir" 2>/dev/null
            if [ $? -eq 0 ]; then
                echo "umount: $dir"
            else
                echo "failed to umount: $dir"
            fi
        fi
    done
    umount $dir_path
    rm -rf $dir_path
    echo "umount and rm: $dir_path"
}

while getopts ":s:cg" opt; do
  case $opt in
    s)
        if [ "$OPTARG" = "true" ]; then
            do_stop=true
        elif [ "$OPTARG" = "false" ]; then
            do_stop=false
        else
            echo "invalid arguments of -s, should be \"true\" or \"false\""
            exit 1
        fi
        ;;
    c)
        do_clear=true
        ;;
    g)
        do_nvcr=true
        ;;
    \?)
        echo "invalid option: -$OPTARG" >&2
        exit 1
        ;;
  esac
done

cd $script_dir
if [ ! -d "$dir_path" ]; then
    mkdir ckpt
    mount_mem_ckpt
fi

if [ $do_clear = true ]; then
    umount_mem_ckpt
    rm -rf $dir_path
    exit 0
fi

if [ $do_stop = true ]; then
    ckpt_with_stop
else
    ckpt_without_stop
fi
