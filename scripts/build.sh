#!/usr/bin/env bash
set -euo pipefail

PRESET="${1:-debug}"
PROFILE="$(cd "$(dirname "$0")/.." && pwd)/.conan/profile"

case "$PRESET" in
    debug|tidy|asan|tsan|msan|fuzz|coverage|cppcheck|iwyu) BUILD_TYPE="Debug"          ;;
    release|ci|package|bench)                              BUILD_TYPE="Release"         ;;
    relwithdebinfo)                                        BUILD_TYPE="RelWithDebInfo"  ;;
    docs)                                                  BUILD_TYPE="Debug"           ;;
    *)
        echo "Unknown preset: $PRESET"
        echo "Available: debug | release | relwithdebinfo | asan | tsan | msan | coverage | tidy | cppcheck | iwyu | bench | fuzz | docs | package | ci"
        exit 1
        ;;
esac

CONAN_OPTS=()
[[ "$PRESET" == "bench" ]] && CONAN_OPTS+=("-o" "with_benchmarks=True" "-o" "with_tests=False")

rm -f CMakeUserPresets.json

conan install . \
    --profile:host="$PROFILE" \
    --profile:build="$PROFILE" \
    --output-folder="build/$PRESET" \
    --build=missing \
    -s "build_type=$BUILD_TYPE" \
    "${CONAN_OPTS[@]}"

rm -f CMakeUserPresets.json

cmake --preset "$PRESET"
cmake --build --preset "$PRESET" --parallel
