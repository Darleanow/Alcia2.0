#!/usr/bin/env bash
set -euo pipefail

PRESET="${1:-debug}"
SCALE="${QT_SCALE_FACTOR:-2}"
EXE="build/$PRESET/src/Alcia"

if [[ ! -f "$EXE" ]]; then
    echo "Binary not found: $EXE — run: bash scripts/build.sh $PRESET"
    exit 1
fi

QT_SCALE_FACTOR="$SCALE" \
QT_ENABLE_HIGHDPI_SCALING=1 \
exec "$EXE"
