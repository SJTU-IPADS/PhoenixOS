script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir

dir_path="./ckpt"
if [ ! -d "$dir_path" ]; then
    mkdir ckpt
fi

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
    else
        get_latest_ckpt_version
        prev_ckpt_version=$?
        prev_ckpt_dir="../$prev_ckpt_version"
        next_ckpt_version=$(($prev_ckpt_version + 1))
        next_ckpt_dir="$dir_path/$next_ckpt_version"
        mkdir $next_ckpt_dir
        if [ $prev_ckpt_version = 0 ]; then
            if [ $do_nvcr = true ]; then
                # stop gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi

            # criu dump
            criu pre-dump --tree $pid --images-dir $next_ckpt_dir --leave-running --track-mem --shell-job --display-stats

            if [ $do_nvcr = true ]; then
                # restore gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi
        else
            if [ $do_nvcr = true ]; then
                # stop gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi
            
            # criu dump
            criu pre-dump --tree $pid --images-dir $next_ckpt_dir --prev-images-dir $prev_ckpt_dir --leave-running --track-mem --shell-job --display-stats

            if [ $do_nvcr = true ]; then
                # restore gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi
        fi
        echo "ckpt to: $next_ckpt_dir"
    fi
}

ckpt_with_stop() {
    pid=$(ps -ef | grep python3 | grep -v grep | awk '{print $2}')

    if [ -z "$pid" ]
    then
        echo "No python3 process found."
    else
        get_latest_ckpt_version
        prev_ckpt_version=$?
        prev_ckpt_dir="../$prev_ckpt_version"
        next_ckpt_version=$(($prev_ckpt_version + 1))
        next_ckpt_dir="$dir_path/$next_ckpt_version"
        mkdir $next_ckpt_dir
        if [ $prev_ckpt_version = 0 ]; then
            if [ $do_nvcr = true ]; then
                # stop gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi

            # stop cpu
            criu dump --tree $pid --images-dir $next_ckpt_dir --shell-job --display-stats
        else
            if [ $do_nvcr = true ]; then
                # stop gpu
                /root/third_party/cuda-checkpoint/bin/x86_64_Linux/cuda-checkpoint --toggle --pid $pid
            fi

            # stop cpu
            criu dump --tree $pid --prev-images-dir $prev_ckpt_dir --images-dir $next_ckpt_dir --shell-job --display-stats
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

mount_mem_ckpt() {
    umount $dir_path
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

if [ $do_clear = true ]; then
    rm -rf $dir_path/*
    exit 0
fi

if [ $do_stop = true ]; then
    ckpt_with_stop
else
    ckpt_without_stop
fi
