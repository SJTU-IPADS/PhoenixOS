#!/bin/bash

check_requirement() {
    # $1 cmd line binary name
    if [[ ! -x "$(command -v $1)" ]]; then
        error "no $1 installed"
    fi
}

check_and_install_go() {
    if [[ ! -x "$(command -v go)" ]]; then
        warn "no go installed, installing from assets..."
        cd $DIR_ASSETS
        rm -rf /usr/local/go
        tar -C /usr/local -xzf go1.23.2.linux-amd64.tar.gz
        echo 'export PATH=$PATH:/usr/local/go/bin' >> $HOME/.bashrc
        source $HOME/.bashrc
        if [[ ! -x "$(command -v go)" ]]; then
            error "failed to install golang runtime"
        fi
        log "go1.23.2 installed"
        warn "please \"source $HOME/.bashrc\" for loading golang"
    fi
}
