// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#pragma once

#include <QString>

#include <optional>
#include <variant>

namespace alcia::game {

struct MoveCommand {
    QString direction;
};
struct LookCommand {};
struct QuitCommand {};
struct UnknownCommand {
    QString raw;
};

using Command = std::variant<MoveCommand, LookCommand, QuitCommand, UnknownCommand>;

/// Parses raw player input into a typed Command.
[[nodiscard]] Command parseCommand(const QString& input);

} // namespace alcia::game
