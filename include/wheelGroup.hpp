/**
 * @file wheelGroup.hpp
 * @brief Implements the wheel group component.
 * @date 2024-06-30
 *
 * Copyright (c) 2024 Oliver Parsons
 */

#ifndef INCLUDE_WHEELGROUP_HPP_
#define INCLUDE_WHEELGROUP_HPP_

/************************* Standard Library Includes **************************/

#include <vector>

/************************* Standard Library Includes **************************/

#include "../include/wheel.hpp"

/****************************** Class Definitons ******************************/

/**
 * @brief Lorenz machine wheel component.
 *
 * This class represents a group of wheels in the Lorenz machine. It stores a
 * vector of wheels and contains methods to rotate the wheels and get the value
 * of their current pins.
 *
 */
class WheelGroup {
 private:
  std::vector<Wheel> wheels;  ///< The wheels that form the wheel group.

 public:
  /**
   * @brief Construct a new Wheel Group object.
   *
   * This constructor initialises a new wheel group object with a specified
   * vector of wheels.
   *
   * @param wheels The wheels that form the wheel group.
   */
  explicit WheelGroup(std::vector<Wheel> wheels);

  /**
   * @brief Rotate the wheels.
   *
   * This function iterates through each wheel in the group and calls their
   * rotate method.
   *
   */
  void rotate();

  /**
   * @brief Get the current pin configuration of all wheels in the group.
   *
   * This function gets the current pin value from each wheel, shifts it
   * into the correct position, and combines them into a single integer.
   *
   * @return int The combined pin values of the group's wheels.
   */
  [[nodiscard]] int getCurrentPins() const;
};

#endif  // INCLUDE_WHEELGROUP_HPP_
