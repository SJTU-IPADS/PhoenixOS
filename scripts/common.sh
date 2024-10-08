#!/bin/bash

# >>>>>>>>>> global variables <<<<<<<<<<
git config --global --add safe.directory /root
DIR_ROOT=$(git rev-parse --show-toplevel)
DIR_ASSETS=$DIR_ROOT/assets
DIR_POS=$DIR_ROOT/pos
DIR_REMOTING=$DIR_ROOT/remoting
DIR_TEST=$DIR_ROOT/test
DIR_THIRD_PARTIES=$DIR_ROOT/third_party
DIR_SCRIPTS=$DIR_ROOT/scripts

# >>>>>>>>>> included utilities <<<<<<<<<<
source $DIR_SCRIPTS/utils/log.sh
source $DIR_SCRIPTS/utils/dependencies.sh
