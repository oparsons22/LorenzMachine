/**
 * @file test_teleprinter.cpp
 * @brief Unit tests for teleprinter.cpp
 * @date 2024-06-30
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/************************* External Library Includes **************************/

#include <gtest/gtest.h>

/************************* Standard Library Includes **************************/

#include <memory>
#include <vector>

/****************************** Project Includes ******************************/

#include "../include/lorenzMachine.hpp"
#include "../include/teleprinter.hpp"
#include "../include/wheel.hpp"
#include "../include/wheelGroup.hpp"

/******************************* Test Fixtures ********************************/

class TeleprinterTest : public ::testing::Test {
 private:
  std::unique_ptr<Teleprinter> teleprinter;

 protected:
  /**
   * @brief Setup the Teleprinter fixture.
   *
   * This function is called before each test to create a new Teleprinter.
   *
   */
  void SetUp() override {
    const Wheel m37({1});
    const Wheel m61({1});
    const WheelGroup chi(
        {Wheel({0}), Wheel({0}), Wheel({1}), Wheel({1}), Wheel({0})});
    const WheelGroup psi(
        {Wheel({0}), Wheel({1}), Wheel({1}), Wheel({0}), Wheel({0})});

    teleprinter =
        std::make_unique<Teleprinter>(LorenzMachine(m61, m37, psi, chi));
  }

  /**
   * @brief Tear down the Teleprinter fixture.
   *
   * This function is called after each test and deletes the Teleprinter
   * object. This is done automatically as the wheel group object is managed by
   * a unique pointer.
   *
   */
  void TearDown() override {}

  /**
   * @brief Get the Teleprinter object.
   *
   * @return std::unique_ptr<Teleprinter>& The Teleprinter object.
   */
  std::unique_ptr<Teleprinter>& getTeleprinter() { return teleprinter; }
};

/******************************** Unit Tests **********************************/

TEST_F(TeleprinterTest, TestEncryptMessage) {
  ASSERT_EQ(getTeleprinter()->encryptMessage("H"), "V");
}
