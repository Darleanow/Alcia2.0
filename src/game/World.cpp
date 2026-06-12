// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/World.hpp"

#include <algorithm>

namespace alcia::game {

World::World() {
    m_rooms.push_back({
        .m_id          = "start",
        .m_description = "You stand at the entrance of a dark forest. Paths lead north and east.",
        .m_exits       = {"north", "east"},
    });
}

const Room* World::currentRoom() const {
    if (m_currentIndex < m_rooms.size()) {
        return &m_rooms[m_currentIndex];
    }
    return nullptr;
}

bool World::move(const QString& direction) const {
    const Room* room = currentRoom();
    if (room == nullptr) {
        return false;
    }

    auto it = std::ranges::find(room->m_exits, direction);
    if (it == room->m_exits.end()) {
        return false;
    }

    return true;
}

} // namespace alcia::game
