// SPDX-FileCopyrightText: 2026 Alcia Contributors
// SPDX-License-Identifier: MIT

#include "Alcia/core/Engine.hpp"

#include <QApplication>

#include <gtest/gtest.h>

class EngineTest : public ::testing::Test {
protected:
    void SetUp() override {
        static int argc    = 0;
        static char** argv = nullptr;
        if (QApplication::instance() == nullptr) {
            app_ = std::make_unique<QApplication>(argc, argv);
        }
    }

    std::unique_ptr<QApplication> app_;
};

TEST_F(EngineTest, EngineConstructsAndRuns) {
    alcia::core::Engine engine;
    EXPECT_NO_THROW(engine.run());
}
