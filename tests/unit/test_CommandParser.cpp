// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/game/CommandParser.hpp"

#include <gtest/gtest.h>
#include <variant>

using namespace alcia::game;

TEST(CommandParser, LookCommand) {
    EXPECT_TRUE(std::holds_alternative<LookCommand>(parseCommand("look")));
    EXPECT_TRUE(std::holds_alternative<LookCommand>(parseCommand("L")));
    EXPECT_TRUE(std::holds_alternative<LookCommand>(parseCommand("  LOOK  ")));
}

TEST(CommandParser, QuitCommand) {
    EXPECT_TRUE(std::holds_alternative<QuitCommand>(parseCommand("quit")));
    EXPECT_TRUE(std::holds_alternative<QuitCommand>(parseCommand("exit")));
    EXPECT_TRUE(std::holds_alternative<QuitCommand>(parseCommand("q")));
}

TEST(CommandParser, MoveCommandExplicit) {
    const auto cmd = parseCommand("go north");
    ASSERT_TRUE(std::holds_alternative<MoveCommand>(cmd));
    EXPECT_EQ(std::get<MoveCommand>(cmd).m_direction, "north");
}

TEST(CommandParser, MoveCommandShorthand) {
    const auto cmd = parseCommand("n");
    ASSERT_TRUE(std::holds_alternative<MoveCommand>(cmd));
    EXPECT_EQ(std::get<MoveCommand>(cmd).m_direction, "n");
}

TEST(CommandParser, UnknownCommand) {
    const auto cmd = parseCommand("dance");
    ASSERT_TRUE(std::holds_alternative<UnknownCommand>(cmd));
    EXPECT_EQ(std::get<UnknownCommand>(cmd).m_raw, "dance");
}

TEST(CommandParser, EmptyInput) {
    EXPECT_TRUE(std::holds_alternative<UnknownCommand>(parseCommand("")));
}
