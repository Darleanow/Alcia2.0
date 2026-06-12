// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/core/Engine.hpp"

#include <QCoreApplication>

#include <gtest/gtest.h>

class EngineTest : public ::testing::Test {
protected:
    void SetUp() override {
        int argc    = 0;
        char** argv = nullptr;
        app_        = std::make_unique<QCoreApplication>(argc, argv);
    }

    std::unique_ptr<QCoreApplication> app_;
};

TEST_F(EngineTest, EngineConstructsAndRuns) {
    alcia::core::Engine engine;
    EXPECT_NO_THROW(engine.run());
}
