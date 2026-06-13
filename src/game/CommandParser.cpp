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
    const QString trimmed = input.trimmed().toLower();

    if (trimmed == "look" || trimmed == "l") {
        return LookCommand{};
    }

    if (trimmed == "quit" || trimmed == "exit" || trimmed == "q") {
        return QuitCommand{};
    }

    for (const auto& prefix : MOVE_PREFIXES) {
        const QString qtPrefix = QString::fromLatin1(prefix);
        if (trimmed.startsWith(qtPrefix)) {
            return MoveCommand{trimmed.sliced(qtPrefix.size())};
        }
    }

    for (const auto& dir : DIRECTIONS) {
        if (trimmed == QString::fromLatin1(dir)) {
            return MoveCommand{trimmed};
        }
    }

    return UnknownCommand{input};
}

} // namespace alcia::game
