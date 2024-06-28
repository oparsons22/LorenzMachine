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
 * @brief Testy fixture for a Wheel object.
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
   * four pins [1, 0, 1, 0].
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

  auto getWheel() -> std::unique_ptr<Wheel>& { return wheel; }
};

/******************************** Unit Tests **********************************/

/**
 * @brief Test the wheel's constructor.
 *
 * This function tests the wheel's constructor by asserting the current pin
 * value is 0. This indicates the object stores the provided pins and sets the
 * pinSetting to 0.
 *
 */
TEST_F(WheelTest, TestConstructor) {
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
