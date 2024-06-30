/**
 * @file wheel.hpp
 * @brief Implementation of the wheel component.
 * @date 2024-06-28
 *
 * Copyright (c) 2024 Oliver Parsons
 */

#ifndef INCLUDE_WHEEL_HPP_
#define INCLUDE_WHEEL_HPP_

/************************* Standard Library Includes **************************/

#include <cstddef>
#include <vector>

/****************************** Class Definitons ******************************/

/**
 * @brief Lorenz machine wheel component.
 *
 * This class represents an individual wheel in the Lorenz machine. It stores
 * the wheel's pin configuration as a vector on integers and contains methods to
 * rotate the wheel and get the value of the current pin.
 *
 */
class Wheel {
 private:
  std::vector<int> pins;  ///< The pin setting values (either 0s or 1s).
  size_t pinSetting = 0;  ///< The current pin index.

 public:
  /**
   * @brief Construct a new Wheel object.
   *
   * This constructor initialises a new wheel object with a vector of integers
   * (either 1s or 0s) that represent the wheel's pin configuration.
   *
   * @param pins The wheel's pin configuration (either 1s or 0s).
   */
  explicit Wheel(std::vector<int> pins);

  /**
   * @brief Get the Current Pin object.
   *
   * This function returns the value of the current pin at the index of the
   * current pin setting.
   *
   * @return int The current pin setting value (either 1 or 0).
   */
  [[nodiscard]] int getCurrentPin() const;

  /**
   * @brief Rotates the wheel.
   *
   * This function increments the current pin setting index to simulate rotating
   * the wheel. If incremented pin setting value exceeds the number of pins then
   * it wraps around to index 0.
   */
  void rotate();
};

#endif  // INCLUDE_WHEEL_HPP_
