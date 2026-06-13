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
    QString m_name;
    int m_health     = 100;
    int m_maxHealth  = 100;
    int m_level      = 1;
    int m_experience = 0;
};

} // namespace alcia::game
