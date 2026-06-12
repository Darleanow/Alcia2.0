# Alcia

> A text-based RPG built with Qt 6.11 and modern C++23.

[![CI](https://github.com/your-org/alcia/actions/workflows/ci.yml/badge.svg)](https://github.com/your-org/alcia/actions/workflows/ci.yml)
[![CodeQL](https://github.com/your-org/alcia/actions/workflows/codeql.yml/badge.svg)](https://github.com/your-org/alcia/actions/workflows/codeql.yml)
[![codecov](https://codecov.io/gh/your-org/alcia/branch/main/graph/badge.svg)](https://codecov.io/gh/your-org/alcia)
[![Docs](https://img.shields.io/badge/docs-GitHub%20Pages-blue)](https://your-org.github.io/alcia)

## Prerequisites

| Tool       | Version  |
|------------|----------|
| CMake      | ≥ 3.28   |
| Qt         | 6.11     |
| Conan      | ≥ 2.0    |
| Ninja      | any      |
| Clang/GCC  | C++23    |
| Python     | ≥ 3.10   |

## Quick start

```bash
# 1. Clone
git clone https://github.com/your-org/alcia && cd alcia

# 2. Fetch Doxygen Awesome theme assets
bash scripts/fetch_doxygen_awesome.sh

# 3. Install pre-commit hooks
pip install pre-commit && pre-commit install

# 4. Install dependencies (Conan)
conan profile detect --force
conan install . --output-folder=build/debug --build=missing -s build_type=Debug

# 5. Configure & build (Debug)
cmake --preset debug
cmake --build --preset debug

# 6. Run tests
ctest --preset debug --output-on-failure
```

## CMake presets

| Preset        | Description                          |
|---------------|--------------------------------------|
| `debug`       | Debug build with tests               |
| `release`     | Optimised release build              |
| `asan`        | AddressSanitizer + UBSan             |
| `tsan`        | ThreadSanitizer                      |
| `coverage`    | GCC coverage (lcov)                  |
| `tidy`        | clang-tidy enabled                   |
| `fuzz`        | libFuzzer targets                    |
| `docs`        | Doxygen documentation                |
| `ci`          | Used by GitHub Actions               |

## Project structure

```
Alcia/
├── include/Alcia/        # Public headers
│   ├── core/             # Engine
│   ├── game/             # World, Player, CommandParser
│   └── ui/               # ConsoleRenderer
├── src/                  # Implementation
│   ├── core/
│   ├── game/
│   └── ui/
├── tests/
│   ├── unit/             # GTest unit tests
│   ├── integration/      # GTest integration tests
│   └── fuzz/             # libFuzzer targets (optional)
├── docs/doxygen/         # Doxygen Awesome config & templates
├── cmake/                # CMake helper modules
├── scripts/              # Utility scripts
└── .github/workflows/    # CI, CodeQL, Coverage, CDash, Docs
```

## Workflows

| Workflow         | Trigger                    | Purpose                        |
|------------------|----------------------------|--------------------------------|
| `ci.yml`         | push/PR                    | Build, test, format check      |
| `coverage.yml`   | push main / PR             | lcov → Codecov upload          |
| `codeql.yml`     | push/PR + weekly           | GitHub Advanced Security       |
| `codequality.yml`| push/PR                    | clang-tidy report on PRs       |
| `cdash.yml`      | push main + nightly cron   | CTest dashboard submission     |
| `docs.yml`       | push main                  | Doxygen → GitHub Pages         |

## License

MIT — see [LICENSE](LICENSE).
