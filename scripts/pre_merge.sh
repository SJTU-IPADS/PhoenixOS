script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir && cd ..

python3 ./scripts/add_copyright.py
