// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/core/Engine.hpp"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication::setHighDpiScaleFactorRoundingPolicy(
        Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

    // QT_SCALE_FACTOR env var overrides this at runtime for per-machine tuning
    QApplication app(argc, argv);
    app.setStyle("Fusion");
    QApplication::setApplicationName("Alcia");
    QApplication::setApplicationVersion("0.1.0");

    alcia::core::Engine engine;
    engine.run();

    return QApplication::exec();
}
