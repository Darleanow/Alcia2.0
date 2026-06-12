#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_DIR="$(dirname "$SCRIPT_DIR")"
cd "$REPO_DIR"

FAILED=0

run() {
    echo "── $1"
    shift
    "$@" || FAILED=1
}

run "clang-format" \
    find src include tests -name "*.cpp" -o -name "*.hpp" | \
    xargs clang-format --dry-run --Werror

run "clang-tidy" \
    bash scripts/build.sh tidy

run "cppcheck" \
    bash scripts/build.sh cppcheck

if [[ $FAILED -ne 0 ]]; then
    echo "Lint failed." >&2
    exit 1
fi
echo "All checks passed."
