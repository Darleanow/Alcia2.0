// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/CommandParser.hpp"

#include <array>
#include <string_view>

namespace alcia::game {

Command parseCommand(const QString& input) {
    const QString TRIMMED = input.trimmed().toLower();

    if (TRIMMED == "look" || TRIMMED == "l") {
        return LookCommand{};
    }

    if (TRIMMED == "quit" || TRIMMED == "exit" || TRIMMED == "q") {
        return QuitCommand{};
    }

    constexpr std::array<std::string_view, 3> MOVE_PREFIXES = {"go ", "move ", "walk "};
    for (const auto& prefix : MOVE_PREFIXES) {
        if (TRIMMED.startsWith(QLatin1StringView(prefix))) {
            return MoveCommand{TRIMMED.sliced(static_cast<qsizetype>(prefix.size()))};
        }
    }

    constexpr std::array<std::string_view, 10> DIRECTIONS = {
        "north", "south", "east", "west", "up", "down", "n", "s", "e", "w"};
    for (const auto& dir : DIRECTIONS) {
        if (TRIMMED == QLatin1StringView(dir)) {
            return MoveCommand{TRIMMED};
        }
    }

    return UnknownCommand{input};
}

} // namespace alcia::game
