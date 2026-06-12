// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/CommandParser.hpp"

#include <QStringList>

namespace alcia::game {

Command parseCommand(const QString& input) {
    const QString TRIMMED = input.trimmed().toLower();

    if (TRIMMED == "look" || TRIMMED == "l") {
        return LookCommand{};
    }

    if (TRIMMED == "quit" || TRIMMED == "exit" || TRIMMED == "q") {
        return QuitCommand{};
    }

    const QStringList MOVE_PREFIXES = {"go ", "move ", "walk "};
    for (const auto& prefix : MOVE_PREFIXES) {
        if (TRIMMED.startsWith(prefix)) {
            return MoveCommand{TRIMMED.sliced(prefix.size())};
        }
    }

    const QStringList DIRECTIONS = {
        "north", "south", "east", "west", "up", "down", "n", "s", "e", "w"};
    if (DIRECTIONS.contains(TRIMMED)) {
        return MoveCommand{TRIMMED};
    }

    return UnknownCommand{input};
}

} // namespace alcia::game
