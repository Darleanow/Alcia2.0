// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#pragma once

#include <QString>

namespace alcia::ui {

/// Renders game state to stdout (terminal-based output).
class ConsoleRenderer {
public:
    void printRoom(const QString& description);
    void printMessage(const QString& message);
    void printError(const QString& error);
    void printPrompt();
};

} // namespace alcia::ui
