#!/bin/bash

check_requirement() {
  # $1 cmd line binary name
  if [[ ! -x "$(command -v $1)" ]]; then
    error "no $1 installed"
  fi
}
