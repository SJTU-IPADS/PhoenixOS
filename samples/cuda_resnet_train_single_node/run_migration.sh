script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir

process_name=train.py


dir_path="./ckpt"
if [ ! -d "$dir_path" ]; then
    echo "no ckpt exist"
    exit 1
fi
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

# do ckpt
pid=$(ps -ef | grep $process_name | grep -v grep | awk '{print $2}')
if [ -z "$pid" ]; then
    echo "No python3 process found."
    exit 1
fi

get_latest_ckpt_version
prev_ckpt_version=$?
prev_ckpt_dir="../$prev_ckpt_version"
next_ckpt_version=$(($prev_ckpt_version + 1))
next_ckpt_dir="$dir_path/$next_ckpt_version"
mkdir $next_ckpt_dir
   
criu dump --tree $pid --images-dir $next_ckpt_dir --shell-job --display-stats --action-script $script_dir/../migrate_action_script.sh
echo "ckpt to: $next_ckpt_dir"

sleep 2

# do restore
get_latest_ckpt_version
latest_ckpt_version=$?
latest_ckpt_dir="ckpt/$latest_ckpt_version"
criu restore -D $latest_ckpt_dir -j --display-stats --action-script $script_dir/../restore_action_script.sh
