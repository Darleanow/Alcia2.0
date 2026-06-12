#!/usr/bin/env bash
set -euo pipefail

PRESET="${1:-debug}"
REPO_DIR="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_DIR"

if command -v entr >/dev/null 2>&1; then
    echo "Watching src/ and include/ with entr (preset=$PRESET)..."
    find src include -name "*.cpp" -o -name "*.hpp" | \
        entr -c cmake --build --preset "$PRESET" --parallel
elif command -v inotifywait >/dev/null 2>&1; then
    echo "Watching src/ and include/ with inotifywait (preset=$PRESET)..."
    while inotifywait -r -e close_write src include 2>/dev/null; do
        cmake --build --preset "$PRESET" --parallel || true
    done
else
    echo "Install 'entr' (preferred) or 'inotify-tools' to use watch mode." >&2
    echo "  sudo apt-get install entr" >&2
    exit 1
fi
