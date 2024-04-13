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

get_latest_ckpt_version
latest_ckpt_version=$?
latest_ckpt_dir="ckpt/$latest_ckpt_version"

criu restore -D $latest_ckpt_dir -j --display-stats
