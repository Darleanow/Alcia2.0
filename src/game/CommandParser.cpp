// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/CommandParser.hpp"

#include <array>
#include <string_view>

namespace alcia::game {

namespace {
constexpr std::array<std::string_view, 3> MOVE_PREFIXES = {"go ", "move ", "walk "};
constexpr std::array<std::string_view, 10> DIRECTIONS   = {
    "north", "south", "east", "west", "up", "down", "n", "s", "e", "w"};
} // namespace

Command parseCommand(const QString& input) {
    const QString TRIMMED = input.trimmed().toLower();

    if (TRIMMED == "look" || TRIMMED == "l") {
        return LookCommand{};
    }

    if (TRIMMED == "quit" || TRIMMED == "exit" || TRIMMED == "q") {
        return QuitCommand{};
    }

    for (const auto& prefix : MOVE_PREFIXES) {
        const QString QT_PREFIX = QString::fromLatin1(prefix);
        if (TRIMMED.startsWith(QT_PREFIX)) {
            return MoveCommand{TRIMMED.sliced(QT_PREFIX.size())};
        }
    }

    for (const auto& dir : DIRECTIONS) {
        if (TRIMMED == QString::fromLatin1(dir)) {
            return MoveCommand{TRIMMED};
        }
    }

    return UnknownCommand{input};
}

} // namespace alcia::game
