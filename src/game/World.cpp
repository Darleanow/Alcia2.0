// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/World.hpp"

namespace alcia::game {

World::World() {
    rooms_.push_back({
        .id          = "start",
        .description = "You stand at the entrance of a dark forest. Paths lead north and east.",
        .exits       = {"north", "east"},
    });
}

const Room* World::currentRoom() const {
    if (currentIndex_ < rooms_.size())
        return &rooms_[currentIndex_];
    return nullptr;
}

bool World::move(const QString& direction) {
    const Room* room = currentRoom();
    if (!room)
        return false;

    auto it = std::ranges::find(room->exits, direction);
    if (it == room->exits.end())
        return false;

    return true;
}

} // namespace alcia::game
