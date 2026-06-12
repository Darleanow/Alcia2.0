// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/CommandParser.hpp"

#include <QStringList>

namespace alcia::game {

Command parseCommand(const QString& input) {
    const QString trimmed = input.trimmed().toLower();

    if (trimmed == "look" || trimmed == "l")
        return LookCommand{};

    if (trimmed == "quit" || trimmed == "exit" || trimmed == "q")
        return QuitCommand{};

    const QStringList movePrefixes = {"go ", "move ", "walk "};
    for (const auto& prefix : movePrefixes) {
        if (trimmed.startsWith(prefix))
            return MoveCommand{trimmed.sliced(prefix.size())};
    }

    const QStringList directions = {
        "north", "south", "east", "west", "up", "down", "n", "s", "e", "w"};
    if (directions.contains(trimmed))
        return MoveCommand{trimmed};

    return UnknownCommand{input};
}

} // namespace alcia::game
