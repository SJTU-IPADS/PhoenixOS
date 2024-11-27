#!/bin/bash

if [ $# -ne 1 ]; then
    echo "usage: $0 <continuous ckpt interval (ms)>"
    exit 1
fi

interval=$(echo "$1 / 1000" | bc -l)

bash run_nvcr_ckpt.sh -c

while true; do
    if pgrep -x "python3" > /dev/null; then
        bash run_nvcr_ckpt.sh -s false -g
    else
        exit 0
    fi
    sleep $interval
done
