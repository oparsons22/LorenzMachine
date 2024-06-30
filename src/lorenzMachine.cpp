/**
 * @file lorenzMachine.cpp
 * @brief Implements the Lorenz machine device.
 * @date 2024-06-30
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/************************* Standard Library Includes **************************/

#include <utility>

/****************************** Project Includes ******************************/

#include "../include/lorenzMachine.hpp"
#include "../include/wheel.hpp"
#include "../include/wheelGroup.hpp"

/*************************** Function Definitions  ****************************/

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
int LorenzMachine::makeKey() const {
  return psi.getCurrentPins() ^ chi.getCurrentPins();
}

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
void LorenzMachine::rotateWheels() {
  chi.rotate();

  if (m37.getCurrentPin() == 1) {
    psi.rotate();
  }

  if (m61.getCurrentPin() == 1) {
    m37.rotate();
  }

  m61.rotate();
}

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
LorenzMachine::LorenzMachine(Wheel m61, Wheel m37, WheelGroup psi,
                             WheelGroup chi)
    : m61(std::move(m61)),
      m37(std::move(m37)),
      psi(std::move(psi)),
      chi(std::move(chi)) {}

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
int LorenzMachine::encryptChar(int baudot) {
  const int encryptedChar = baudot ^ makeKey();
  rotateWheels();
  return encryptedChar;
}
