// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/Player.hpp"

#include <algorithm>
#include <utility>

namespace alcia::game {

Player::Player(QString name) : m_name(std::move(name)) {
}

const QString& Player::name() const {
    return m_name;
}
int Player::health() const {
    return m_health;
}
int Player::level() const {
    return m_level;
}

void Player::takeDamage(int amount) {
    m_health = std::max(0, m_health - amount);
}

void Player::heal(int amount) {
    m_health = std::min(m_maxHealth, m_health + amount);
}

void Player::gainExperience(int xp) {
    m_experience += xp;
    constexpr int XP_PER_LEVEL = 100;
    if (m_experience >= m_level * XP_PER_LEVEL) {
        ++m_level;
        m_maxHealth += 10;
        m_health = m_maxHealth;
    }
}

} // namespace alcia::game
