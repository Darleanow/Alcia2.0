// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/World.hpp"

#include <gtest/gtest.h>

using namespace alcia::game;

TEST(World, StartRoomExists) {
    const World w;
    ASSERT_NE(w.currentRoom(), nullptr);
    EXPECT_EQ(w.currentRoom()->m_id, "start");
}

TEST(World, MoveValidDirection) {
    const World w;
    EXPECT_TRUE(w.move("north"));
}

TEST(World, MoveInvalidDirection) {
    const World w;
    EXPECT_FALSE(w.move("west"));
}
