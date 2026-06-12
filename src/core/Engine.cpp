// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/core/Engine.hpp"

#include <QMainWindow>
#include <QObject>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

namespace alcia::core {

Engine::Engine(QObject* parent) : QObject(parent), m_window(new QMainWindow()) {
    auto* central = new QWidget(m_window);
    auto* layout  = new QVBoxLayout(central);
    auto* output  = new QTextEdit(central);

    output->setReadOnly(true);
    output->setPlainText("Welcome to Alcia.\n\nType a command to begin.");
    output->setObjectName("output");

    layout->addWidget(output);
    m_window->setCentralWidget(central);
    m_window->setWindowTitle("Alcia");
    m_window->resize(800, 600);
}

Engine::~Engine() {
    delete m_window;
}

void Engine::run() {
    m_window->show();
}

} // namespace alcia::core
