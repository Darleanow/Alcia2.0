// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/CommandParser.hpp"

#include <QCoreApplication>

#include <cstdint>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, std::size_t size) {
    static int argc = 0;
    static QCoreApplication app(argc, nullptr);

    const QString input =
        QString::fromUtf8(reinterpret_cast<const char*>(data), static_cast<qsizetype>(size));

    [[maybe_unused]] auto cmd = alcia::game::parseCommand(input);
    return 0;
}
