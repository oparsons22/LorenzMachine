/**
 * @file test_wheel.cpp
 * @brief Unit tests for wheel.cpp.
 * @date 2024-06-28
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

/******************************* Test Fixtures ********************************/

/**
 * @brief Test fixture for a Wheel object.
 *
 */
class WheelTest : public ::testing::Test {
 private:
  std::unique_ptr<Wheel> wheel;

 protected:
  /**
   * @brief Setup the Wheel fixture.
   *
   * This function is called before each test to create a new Wheel object with
   * two pins [0, 1].
   *
   */
  void SetUp() override {
    const std::vector<int> pins = {0, 1};
    wheel = std::make_unique<Wheel>(pins);
  }

  /**
   * @brief Tear down the Wheel fixture.
   *
   * This function is called after each test and deletes the Wheel object. This
   * is done automatically as the wheel object is managed by a unique pointer.
   */
  void TearDown() override {}

  /**
   * @brief Get the Wheel object.
   *
   * @return std::unique_ptr<Wheel>& the Wheel object.
   */
  std::unique_ptr<Wheel>& getWheel() { return wheel; }
};

/******************************** Unit Tests **********************************/

/**
 * @brief Test the getting the wheel's current pin value.
 *
 * This function tests getting the value of the current pin.
 *
 */
TEST_F(WheelTest, TestGetCurrentPin) {
  ASSERT_EQ(getWheel()->getCurrentPin(), 0);
}

/**
 * @brief Test rotating the wheel.
 *
 * This function tests the wheel's rotate method by rotating the wheel and
 * asserting the current pin value is 1. This indicates the rotate method
 * incremented the pinSetting value.
 *
 */
TEST_F(WheelTest, TestRotate) {
  getWheel()->rotate();
  ASSERT_EQ(getWheel()->getCurrentPin(), 1);
}

/**
 * @brief Test the edge case of rotating the wheel.
 *
 * This function tests the edge case of the wheel rotation by asserting the
 * current pin value is 0. This indicates the pinSetting wraps back around to
 * index 0.
 *
 */
TEST_F(WheelTest, TestRotateEdgeCase) {
  getWheel()->rotate();
  getWheel()->rotate();
  ASSERT_EQ(getWheel()->getCurrentPin(), 0);
}
