// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/Player.hpp"

#include <algorithm>

namespace alcia::game {

Player::Player(QString name) : name_(std::move(name)) {
}

const QString& Player::name() const {
    return name_;
}
int Player::health() const {
    return health_;
}
int Player::level() const {
    return level_;
}

void Player::takeDamage(int amount) {
    health_ = std::max(0, health_ - amount);
}

void Player::heal(int amount) {
    health_ = std::min(maxHealth_, health_ + amount);
}

void Player::gainExperience(int xp) {
    experience_ += xp;
    constexpr int xpPerLevel = 100;
    if (experience_ >= level_ * xpPerLevel) {
        ++level_;
        maxHealth_ += 10;
        health_ = maxHealth_;
    }
}

} // namespace alcia::game
