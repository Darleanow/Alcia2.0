// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#pragma once

#include <QString>

namespace alcia::game {

class Player {
public:
    explicit Player(QString name);

    [[nodiscard]] const QString& name() const;
    [[nodiscard]] int health() const;
    [[nodiscard]] int level() const;

    void takeDamage(int amount);
    void heal(int amount);
    void gainExperience(int xp);

private:
    QString name_;
    int health_     = 100;
    int maxHealth_  = 100;
    int level_      = 1;
    int experience_ = 0;
};

} // namespace alcia::game
