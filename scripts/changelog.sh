#!/usr/bin/env bash
set -euo pipefail

REPO_DIR="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_DIR"

FROM="${1:-$(git describe --tags --abbrev=0 2>/dev/null || git rev-list --max-parents=0 HEAD)}"
TO="${2:-HEAD}"

declare -A SECTIONS=(
    [feat]="Features"
    [fix]="Bug Fixes"
    [perf]="Performance"
    [refactor]="Refactoring"
    [docs]="Documentation"
    [build]="Build"
    [ci]="CI"
    [chore]="Chores"
)

echo "## Changelog ($FROM → $TO)"
echo ""

for type in feat fix perf refactor docs build ci chore; do
    lines=$(git log "$FROM..$TO" --oneline --no-merges \
        --grep="^${type}" --format="- %s (%h)" 2>/dev/null || true)
    if [[ -n "$lines" ]]; then
        echo "### ${SECTIONS[$type]}"
        echo "$lines"
        echo ""
    fi
done
