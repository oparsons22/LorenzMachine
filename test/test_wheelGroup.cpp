/**
 * @file test_wheelGroup.cpp
 * @brief Unit tests for wheelGroup.cpp
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

#include "../include/wheel.hpp"
#include "../include/wheelGroup.hpp"

/******************************* Test Fixtures ********************************/

class WheelGroupTest : public ::testing::Test {
 private:
  std::unique_ptr<WheelGroup> wheelGroup;

 protected:
  /**
   * @brief Setup the WheelGroup fixture.
   *
   * This function is called before each test to create a new WheelGroup object
   * with two wheels with two pins each.
   *
   */
  void SetUp() override {
    const std::vector<Wheel> wheels = {Wheel({0, 1}), Wheel({0, 0})};
    wheelGroup = std::make_unique<WheelGroup>(wheels);
  }

  /**
   * @brief Tear down the WheelGroup fixture.
   *
   * This function is called after each test and deletes the WheelGroup object.
   * This is done automatically as the wheel group object is managed by a unique
   * pointer.
   *
   */
  void TearDown() override {}

  /**
   * @brief Get the WheelGroup object.
   *
   * @return std::unique_ptr<WheelGroup>& The WheelGroup object.
   */
  auto getWheelGroup() -> std::unique_ptr<WheelGroup>& { return wheelGroup; }
};

/******************************** Unit Tests **********************************/

/**
 * @brief Test getting the current pin values.
 *
 * This function tests getting the current pin values of the wheels. Both wheels
 * first pins are 0, which should result in value of 0b00.
 *
 */
TEST_F(WheelGroupTest, TestGetCurrentPins) {
  ASSERT_EQ(getWheelGroup()->getCurrentPins(), 0);
}

/**
 * @brief Test rotating the wheels in the group.
 *
 * This function tests the rotate method by rotating the wheels and asserting
 * the pin values are 2. This indicates each wheel was rotated as the second
 * pin values should be 0b10.
 *
 */
TEST_F(WheelGroupTest, TestRotate) {
  getWheelGroup()->rotate();
  ASSERT_EQ(getWheelGroup()->getCurrentPins(), 2);
}
