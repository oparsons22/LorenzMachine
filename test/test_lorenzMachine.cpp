/**
 * @file test_lorenzMachine.cpp
 * @brief Unit tests for lorenzMachine.cpp
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
#include "../include/wheel.hpp"
#include "../include/wheelGroup.hpp"

/******************************* Test Fixtures ********************************/

class LorenzMachineTest : public ::testing::Test {
 private:
  std::unique_ptr<LorenzMachine> lorenzMachine;

 protected:
  /**
   * @brief Setup the LorenzMachine fixture.
   *
   * This function is called before each test to create a new LorenzMachine
   * object with two wheels with two pins each.
   *
   */
  void SetUp() override {
    const Wheel m37({1, 1});
    const Wheel m61({1, 1});
    const WheelGroup chi({Wheel({1, 1}), Wheel({1, 1})});
    const WheelGroup psi({Wheel({1, 1}), Wheel({1, 1})});

    lorenzMachine = std::make_unique<LorenzMachine>(m61, m37, psi, chi);
  }

  /**
   * @brief Tear down the LorenzMachine fixture.
   *
   * This function is called after each test and deletes the LorenzMachine
   * object. This is done automatically as the wheel group object is managed by
   * a unique pointer.
   *
   */
  void TearDown() override {}

  /**
   * @brief Get the LorenzMachine object.
   *
   * @return std::unique_ptr<LorenzMachine>& The LorenzMachine object.
   */
  std::unique_ptr<LorenzMachine>& getLorenzMachine() { return lorenzMachine; }
};

/******************************** Unit Tests **********************************/

/**
 * @brief Test getting the current encryption key.
 *
 * This function tests getting the current encryption key of the machine. They
 * encryption key be 0b00 based on the PSI and CHI pins. Therefore, 0b11 should
 * encrypt to 0b01.
 *
 */
TEST_F(LorenzMachineTest, TestEncryptChar) {
  ASSERT_EQ(getLorenzMachine()->encryptChar(0b11), 0b01);
}
