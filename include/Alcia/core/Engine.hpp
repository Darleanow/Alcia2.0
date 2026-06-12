// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#pragma once

#include <QMainWindow>

namespace alcia::core {

class Engine : public QObject {
    Q_OBJECT

public:
    explicit Engine(QObject* parent = nullptr);
    ~Engine() override;

    Engine(const Engine&)            = delete;
    Engine& operator=(const Engine&) = delete;
    Engine(Engine&&)                 = delete;
    Engine& operator=(Engine&&)      = delete;

    void run();

signals:
    void quit();

private:
    QMainWindow* m_window;
};

} // namespace alcia::core
