#!/bin/bash

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
root_dir=$(git rev-parse --show-toplevel)

cd $root_dir
python3 $script_dir/add_copyright.py
