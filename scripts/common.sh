#!/bin/bash

# >>>>>>>>>> global variables <<<<<<<<<<
DIR_ROOT=$(git rev-parse --show-toplevel)
DIR_POS=$DIR_ROOT/test
DIR_REMOTING=$DIR_ROOT/test
DIR_TEST=$DIR_ROOT/test
DIR_THIRD_PARTIES=$DIR_ROOT/third_party
DIR_SCRIPTS=$DIR_ROOT/scripts

# >>>>>>>>>> included utilities <<<<<<<<<<
source $DIR_SCRIPTS/utils/log.sh
source $DIR_SCRIPTS/utils/dependencies.sh
