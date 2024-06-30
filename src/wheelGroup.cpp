/**
 * @file wheelGroup.cpp
 * @brief Implements the wheel group component.
 * @date 2024-06-30
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/************************* Standard Library Includes **************************/

#include <numeric>
#include <utility>
#include <vector>

/****************************** Project Includes ******************************/

#include "../include/wheel.hpp"
#include "../include/wheelGroup.hpp"

/*************************** Function Definitions  ****************************/

/**
 * @brief Construct a new Wheel Group object.
 *
 * This constructor initialises a new wheel group object with a specified
 * vector of wheels.
 *
 * @param wheels The wheels that form the wheel group.
 */
WheelGroup::WheelGroup(std::vector<Wheel> wheels) : wheels(std::move(wheels)) {}

/**
 * @brief Rotate the wheels.
 *
 * This function iterates through each wheel in the group and calls their
 * rotate method.
 *
 */
void WheelGroup::rotate() {
  for (auto& wheel : wheels) {
    wheel.rotate();
  }
}

/**
 * @brief Get the current pin configuration of all wheels in the group.
 *
 * This function gets the current pin value from each wheel, shifts it
 * into the correct position, and combines them into a single integer.
 *
 * @return int The combined pin values of the group's wheels.
 */
int WheelGroup::getCurrentPins() {
  int pins = 0;

  for (auto& wheel : wheels) {
    pins = (pins << 1) | wheel.getCurrentPin();
  }

  return pins;
}
