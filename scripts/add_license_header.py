#!/usr/bin/env python3
"""Add or check SPDX license headers in C++ source files."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

HEADER = """\
// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT
"""

EXTENSIONS = {".cpp", ".hpp", ".h", ".hxx", ".cxx"}


def needs_header(path: Path) -> bool:
    content = path.read_text(encoding="utf-8", errors="replace")
    return "SPDX-FileCopyrightText" not in content


def add_header(path: Path) -> None:
    content = path.read_text(encoding="utf-8", errors="replace")
    path.write_text(HEADER + "\n" + content, encoding="utf-8")
    print(f"  [added]   {path}")


def main() -> int:
    parser = argparse.ArgumentParser(description="Manage SPDX license headers.")
    parser.add_argument("dirs", nargs="+", type=Path, help="Source directories to scan")
    parser.add_argument("--check", action="store_true", help="Check only, exit 1 if missing")
    args = parser.parse_args()

    missing: list[Path] = []

    for d in args.dirs:
        for ext in EXTENSIONS:
            for path in d.rglob(f"*{ext}"):
                if needs_header(path):
                    missing.append(path)

    if not missing:
        print("All files have license headers.")
        return 0

    if args.check:
        print("Missing license headers in:")
        for p in missing:
            print(f"  {p}")
        print(f"\nRun: python3 scripts/add_license_header.py src include tests")
        return 1

    print(f"Adding headers to {len(missing)} file(s)...")
    for p in missing:
        add_header(p)
    return 0


if __name__ == "__main__":
    sys.exit(main())
