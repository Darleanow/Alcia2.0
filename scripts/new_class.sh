#!/usr/bin/env bash
set -euo pipefail

usage() {
    echo "Usage: $0 <ClassName> <module>"
    echo "       module: core | game | ui"
    exit 1
}

[[ $# -ne 2 ]] && usage

CLASS="$1"
MODULE="$2"
REPO_DIR="$(cd "$(dirname "$0")/.." && pwd)"
YEAR="$(date +%Y)"

HPP_DIR="$REPO_DIR/include/Alcia/$MODULE"
CPP_DIR="$REPO_DIR/src/$MODULE"

[[ -d "$HPP_DIR" ]] || { echo "Unknown module: $MODULE (expected core|game|ui)"; exit 1; }

GUARD="ALCIA_$( echo "${MODULE}_${CLASS}" | tr '[:lower:]' '[:upper:]' )_HPP"
HPP="$HPP_DIR/${CLASS}.hpp"
CPP="$CPP_DIR/${CLASS}.cpp"

[[ -f "$HPP" ]] && { echo "$HPP already exists"; exit 1; }
[[ -f "$CPP" ]] && { echo "$CPP already exists"; exit 1; }

cat > "$HPP" <<EOF
// Copyright (c) $YEAR Alcia contributors
// SPDX-License-Identifier: MIT

#pragma once

#include <QObject>

namespace alcia::$MODULE {

class ${CLASS} : public QObject {
    Q_OBJECT

public:
    explicit ${CLASS}(QObject* parent = nullptr);
    ~${CLASS}() override;

private:
};

}  // namespace alcia::$MODULE
EOF

cat > "$CPP" <<EOF
// Copyright (c) $YEAR Alcia contributors
// SPDX-License-Identifier: MIT

#include "Alcia/$MODULE/${CLASS}.hpp"

namespace alcia::$MODULE {

${CLASS}::${CLASS}(QObject* parent) : QObject(parent) {}

${CLASS}::~${CLASS}() = default;

}  // namespace alcia::$MODULE
EOF

echo "Created:"
echo "  $HPP"
echo "  $CPP"
