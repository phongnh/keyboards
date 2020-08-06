#!/usr/bin/env bash

DATE=`date +'%Y%m%d%H%M%S'`

QMK_FIRMWARE_DIR="$HOME/src/qmk_firmware"
QMK_FIRMWARE_SPE_DIR="$HOME/src/qmk_firmware_spe"
QMK_FIRMWARE_BLE_DIR="$HOME/src/qmk_firmware_ble"

READLINK=$(type -p greadlink readlink | head -1)

function resolve_link() {
    $READLINK "$1"
}

function abs_dirname() {
    local  cwd="$(pwd)"
    local path="$1"

    while [ -n "$path" ]; do
        cd "${path%/*}" 2>/dev/null 1>&2
        local name="${path##*/}"
        path="$(resolve_link "$name" || true)"
    done

    pwd
    cd "$cwd" || exit 1
}

function log_message() {
    if [ "$VERBOSE" = "yes" ]; then
        echo "$1"
    fi
}

function backup_file() {
    if [ -e "$1" ]; then
        log_message "   .. $1 existed!"
        if [ ! -L "$1" ]; then
            log_message "   .. mv \"$1\" \"$1.$DATE\""
            mv "$1" "$1.$DATE"
        fi
    fi
}

function link_keyboard() {
    local source="$1"
    local target="$2"
    if [ -e "$source" ]; then
        echo "-> Processing: $source"
        backup_file "$target"
        log_message "   .. ln -sf \"$source\" \"$target\""
        ln -sfn "$source" "$target"
    fi
}

function link_qmk_keyboard() {
    local name="$3"
    if [ -z "$name" ]; then
        name="phongnh"
    fi
    if [ -d "$QMK_FIRMWARE_DIR" ]; then
        link_keyboard "$1" "$QMK_FIRMWARE_DIR/keyboards/$2/keymaps/$name"
    fi
}

function link_qmk_spe_keyboard() {
    local name="$3"
    if [ -z "$name" ]; then
        name="phongnh"
    fi
    if [ -d "$QMK_FIRMWARE_SPE_DIR" ]; then
        link_keyboard "$1" "$QMK_FIRMWARE_SPE_DIR/keyboards/$2/keymaps/$name"
    fi
}

function link_keyboards() {
    local DIR="$(abs_dirname "${BASH_SOURCE-$0}")"
    echo "** DIR: $DIR"
    link_qmk_spe_keyboard "$DIR/centromere_plus" "centromere_plus"
    link_qmk_keyboard     "$DIR/crkbd"           "crkbd"
    link_qmk_keyboard     "$DIR/dichotomy"       "dichotomy"
    link_qmk_keyboard     "$DIR/ergodox_ez"      "ergodox_ez"
    link_qmk_keyboard     "$DIR/interdox"        "redox_w"         "interdox"
    link_qmk_keyboard     "$DIR/iris"            "keebio/iris"
    link_qmk_keyboard     "$DIR/katana60"        "katana60"
    link_qmk_keyboard     "$DIR/preonic"         "preonic"
    link_qmk_keyboard     "$DIR/redox"           "redox"
    link_qmk_keyboard     "$DIR/sol"             "rgbkb/sol"
    link_qmk_keyboard     "$DIR/unigo66"         "sirius/unigo66"
    link_qmk_keyboard     "$DIR/whitefox"        "whitefox"
}

link_keyboards "$@"
