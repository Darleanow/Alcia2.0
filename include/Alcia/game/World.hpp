// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#pragma once

#include <QString>

#include <vector>

namespace alcia::game {

struct Room {
    QString id;
    QString description;
    std::vector<QString> exits;
};

class World {
public:
    World();

    [[nodiscard]] const Room* currentRoom() const;
    bool move(const QString& direction);

private:
    std::vector<Room> rooms_;
    std::size_t currentIndex_{0};
};

} // namespace alcia::game
