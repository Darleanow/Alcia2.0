// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#pragma once

#include <QString>

namespace alcia::ui {

/// Renders game state to stdout (terminal-based output).
class ConsoleRenderer {
public:
    static void printRoom(const QString& description);
    static void printMessage(const QString& message);
    static void printError(const QString& error);
    static void printPrompt();
};

} // namespace alcia::ui
