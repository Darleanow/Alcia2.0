#!/usr/bin/env bash
set -euo pipefail

VERSION="v2.3.4"
BASE_URL="https://github.com/jothepro/doxygen-awesome-css/releases/download/${VERSION}"
DEST="docs/doxygen"

mkdir -p "$DEST"

FILES=(
  doxygen-awesome.css
  doxygen-awesome-sidebar-only.css
  doxygen-awesome-darkmode-toggle.js
  doxygen-awesome-fragment-copy-button.js
  doxygen-awesome-paragraph-link.js
  doxygen-awesome-interactive-toc.js
)

for f in "${FILES[@]}"; do
  curl -sSL "${BASE_URL}/${f}" -o "${DEST}/${f}"
done
