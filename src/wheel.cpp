/**
 * @file wheel.cpp
 * @brief Implementation of the wheel component.
 * @date 2024-06-28
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/************************* Standard Library Includes **************************/

#include <utility>
#include <vector>

/****************************** Project Includes ******************************/

#include "../include/wheel.hpp"

/*************************** Function Definitions  ****************************/

/**
 * @brief Construct a new Wheel object.
 *
 * This constructor initialises a new wheel object with a vector of integers
 * (either 1s or 0s) that represent the wheel's pin configuration.
 *
 * @param pins The wheel's pin configuration (either 1s or 0s).
 */
Wheel::Wheel(std::vector<int> pins) : pins(std::move(pins)), pinSetting(0) {}

/**
 * @brief Get the Current Pin object.
 *
 * This function returns the value of the current pin at the index of the
 * current pin setting.
 *
 * @return int The current pin setting value (either 1 or 0).
 */
auto Wheel::getCurrentPin() const -> int { return pins[pinSetting]; }

/**
 * @brief Rotates the wheel.
 *
 * This function increments the current pin setting index to simulate rotating
 * the wheel. If incremented pin setting value exceeds the number of pins then
 * it wraps around to index 0.
 */
void Wheel::rotate() {
  if (++pinSetting >= pins.size()) {
    pinSetting = 0;
  }
}
