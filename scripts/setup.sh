#!/usr/bin/env bash
set -euo pipefail

QT_VERSION="6.11.0"
QT_DIR="$HOME/Qt"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_DIR="$(dirname "$SCRIPT_DIR")"

if command -v apt-get >/dev/null 2>&1; then
    sudo apt-get update -q
    sudo apt-get install -y \
        ninja-build ccache \
        clang clang-tidy clang-format \
        cppcheck doxygen graphviz lcov \
        libgl1-mesa-dev libglu1-mesa-dev libvulkan-dev \
        libxkbcommon-dev libfontconfig1-dev libfreetype-dev \
        python3-pip pre-commit
fi

command -v pip3 >/dev/null || { echo "pip3 required"; exit 1; }
command -v conan >/dev/null 2>&1 || pip3 install --break-system-packages "conan>=2.0"

if [[ ! -f "$QT_DIR/$QT_VERSION/gcc_64/bin/qmake" ]]; then
    pip3 install --break-system-packages aqtinstall
    aqt install-qt linux desktop "$QT_VERSION" linux_gcc_64 -O "$QT_DIR"
fi

if [[ ! -f "$REPO_DIR/.conan/profile" ]]; then
    echo ".conan/profile missing — creating it"
    conan profile detect --force
fi

if command -v pre-commit >/dev/null 2>&1; then
    pre-commit install
fi

bash "$SCRIPT_DIR/fetch_doxygen_awesome.sh"

echo "Setup done. Run: make"
