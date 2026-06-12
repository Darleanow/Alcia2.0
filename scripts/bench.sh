#!/usr/bin/env bash
set -euo pipefail

REPO_DIR="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_DIR"

bash scripts/build.sh bench

./build/bench/tests/bench/AlciaBenchmarks \
    --benchmark_format=console \
    --benchmark_color=true \
    "$@"
