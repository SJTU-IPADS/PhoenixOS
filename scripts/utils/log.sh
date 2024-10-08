#!/bin/bash

log() {
  echo -e "\033[37m [POS Build Log] $1 \033[0m"
}

warn() {
  echo -e "\033[33m [POS Build Wrn] $1 \033[0m"
}

error() {
  echo -e "\033[31m [POS Build Err] $1 \033[0m"
  exit 1
}

error_f() {
    string_template="$1"
    shift
    params="$@"
    printf "\033[31m [POS Build Err] $string_template \033[0m" $params
    exit 1
}
