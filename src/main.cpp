// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/core/Engine.hpp"

#include <QApplication>
#include <QtCore/qnamespace.h>

int main(int argc, char* argv[]) {
    QApplication::setHighDpiScaleFactorRoundingPolicy(
        Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

    const QApplication app(argc, argv);
    QApplication::setStyle("Fusion");
    QApplication::setApplicationName("Alcia");
    QApplication::setApplicationVersion("0.1.0");

    alcia::core::Engine engine;
    engine.run();

    return QApplication::exec();
}
