// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#pragma once

#include <QString>

#include <vector>

namespace alcia::game {

struct Room {
    QString m_id;
    QString m_description;
    std::vector<QString> m_exits;
};

class World {
public:
    World();

    [[nodiscard]] const Room* currentRoom() const;
    [[nodiscard]] bool move(const QString& direction) const;

private:
    std::vector<Room> m_rooms;
    std::size_t m_currentIndex{0};
};

} // namespace alcia::game
