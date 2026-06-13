// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/CommandParser.hpp"

#include <benchmark/benchmark.h>

static void BM_ParseCommand(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(alcia::game::parseCommand("go north"));
    }
}
BENCHMARK(BM_ParseCommand);
