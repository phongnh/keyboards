#!/usr/bin/env bash

function clone_repo() {
    local dir="$HOME/src/$1"
    local repo="$2"
    echo "==> Dir: $dir - Repo: $repo"
    if [ -d "$dir" ]; then
        cd "$dir" && git fetch -p && git rebase --autostash
    else
        git clone "$repo" "$dir"
    fi
}

function clone_qmk_repo() {
    local dir="$HOME/src/$1"
    clone_repo $@
    cd "$dir" && make git-submodule
}

mkdir -p ~/src

clone_qmk_repo 'qmk_firmware'     'https://github.com/qmk/qmk_firmware'
clone_qmk_repo 'qmk_firmware_spe' 'https://github.com/SouthPawEngineer/qmk_firmware_spe'
clone_qmk_repo 'qmk_firmware_ble' 'https://github.com/sekigon-gonnoc/qmk_firmware'

clone_repo 'BLE-Micro-Pro' 'https://github.com/sekigon-gonnoc/BLE-Micro-Pro'
clone_repo 'BlueMicro_BLE' 'https://github.com/jpconstantineau/BlueMicro_BLE'

# Linux
# sudo apt-get update -y
# sudo apt-get install gcc-avr avr-libc dfu-programmer dfu-util -y

# macOS
# brew tap osx-cross/avr
# brew install avr-libc
# brew install dfu-programmer
# brew install dfu-util
# brew install teensy_loader_cli
