/**
 * @file lorenzMachine.hpp
 * @brief Implements the Lorenz machine device.
 * @date 2024-06-30
 *
 * Copyright (c) 2024 Oliver Parsons
 */

#ifndef INCLUDE_LORENZMACHINE_HPP_
#define INCLUDE_LORENZMACHINE_HPP_

/****************************** Project Includes ******************************/

#include "../include/wheel.hpp"
#include "../include/wheelGroup.hpp"

/****************************** Class Definitons ******************************/

/**
 * @brief Implementation of the Lorenz machine device.
 *
 * This class encapsulates the functionality of the Lorenz machine device. It
 * stores its wheel components and provides methods to encrypt a character, and
 * rotate the device's wheels.
 *
 */
class LorenzMachine {
 private:
  Wheel m61;       ///< The M61 wheel component.
  Wheel m37;       ///< The M37 wheel component.
  WheelGroup psi;  ///< the PSI wheel group component.
  WheelGroup chi;  ///< The CHI wheel group component.

  /**
   * @brief Get the current encryption key.
   *
   * This function generates the 5-bit key used for encryption based on the
   * current state of the machine. The current pin value (0 or 1) of each
   * corresponding wheel in the Chi and Psi group are XOR together to create the
   * 5-bit key.
   *
   * @return int The 5-bit encryption key.
   */
  [[nodiscard]] int makeKey() const;

  /**
   * @brief Rotate the wheels.
   *
   * This function rotates each wheel in the machine. Firstly, all 5 Chi wheels
   * rotate every time. Secondly, if the current setting of M37 is 1 then all 5
   * Psi wheels are rotated. Thirdly, if the current setting of M61 is 1 then
   * M37 is rotated. Finally, M61 is rotated every time. The wheel rotations
   * must be applied in this order.
   *
   */
  void rotateWheels();

 public:
  /**
   * @brief Construct a new Lorenz machine object.
   *
   * This constructor initialises a new Lorenz machine object with the required
   * wheel components.
   *
   * @param m61 The M61 wheel component.
   * @param m37 The M37 wheel component.
   * @param psi The PSI wheel group component.
   * @param chi The CHI wheel group component.
   */
  LorenzMachine(Wheel m61, Wheel m37, WheelGroup psi, WheelGroup chi);

  /**
   * @brief Encrypt a character's Baudot code.
   *
   * This function encrypts a Baudot code character by performing an XOR
   * operation on the Baudot code and the machine's key. It also rotates the
   * machine's wheels to ensure the next character is encrypted using a new
   * encryption key.
   *
   * @param baudot The character Baudot code to encrypt.
   * @return int The encrypted Baudot code.
   */
  int encryptChar(int baudot);
};

#endif  // INCLUDE_LORENZMACHINE_HPP_
