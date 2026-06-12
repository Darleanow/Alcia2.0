// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/ui/ConsoleRenderer.hpp"

#include <QTextStream>

namespace alcia::ui {

namespace {
QTextStream& out() {
    static QTextStream s(stdout);
    return s;
}
} // namespace

void ConsoleRenderer::printRoom(const QString& description) {
    out() << "\n" << description << "\n";
}

void ConsoleRenderer::printMessage(const QString& message) {
    out() << message << "\n";
}

void ConsoleRenderer::printError(const QString& error) {
    QTextStream err(stderr);
    err << "[!] " << error << "\n";
}

void ConsoleRenderer::printPrompt() {
    out() << "> ";
    out().flush();
}

} // namespace alcia::ui
