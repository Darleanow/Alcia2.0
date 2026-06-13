// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/Player.hpp"

#include <gtest/gtest.h>

using namespace alcia::game;

TEST(Player, InitialState) {
    const Player p("Hero");
    EXPECT_EQ(p.name(), "Hero");
    EXPECT_EQ(p.health(), 100);
    EXPECT_EQ(p.level(), 1);
}

TEST(Player, TakeDamage) {
    Player p("Hero");
    p.takeDamage(30);
    EXPECT_EQ(p.health(), 70);
}

TEST(Player, HealthCannotGoBelowZero) {
    Player p("Hero");
    p.takeDamage(9999);
    EXPECT_EQ(p.health(), 0);
}

TEST(Player, Heal) {
    Player p("Hero");
    p.takeDamage(50);
    p.heal(20);
    EXPECT_EQ(p.health(), 70);
}

TEST(Player, HealCannotExceedMaxHealth) {
    Player p("Hero");
    p.heal(9999);
    EXPECT_EQ(p.health(), 100);
}

TEST(Player, LevelUp) {
    Player p("Hero");
    p.gainExperience(100);
    EXPECT_EQ(p.level(), 2);
    EXPECT_EQ(p.health(), 110);
}
