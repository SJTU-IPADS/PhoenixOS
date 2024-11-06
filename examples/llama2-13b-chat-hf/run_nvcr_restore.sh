script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

dir_path="./ckpt"

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


function restore(){
    cd $script_dir

    pid=$(ps -ef | grep python3 | grep -v grep | awk '{print $2}')
    
    get_latest_ckpt_version
    prev_ckpt_version=$?
    prev_ckpt_dir="$dir_path/$prev_ckpt_version"
    if [ $do_nvcr = true ]; then
        criu restore -D $prev_ckpt_dir -j --display-stats --restore-detached
        pid=$(ps -ef | grep python3 | grep -v grep | awk '{print $2}')
        if [ -z "$pid" ]; then
            echo "No python3 process restored."
            exit 1
        fi
        cuda-checkpoint --toggle --pid $pid
    else
        criu restore -D $prev_ckpt_dir -j --display-stats
    fi
}


while getopts ":s:cg" opt; do
  case $opt in
    g)
        do_nvcr=true
        ;;
    \?)
        echo "invalid option: -$OPTARG" >&2
        exit 1
        ;;
  esac
done

restore

