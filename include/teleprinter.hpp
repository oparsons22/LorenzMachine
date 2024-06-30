/**
 * @file teleprinter.hpp
 * @brief Implement the teleprinter component.
 * @date 2024-06-30
 *
 * Copyright (c) 2024 Oliver Parsons
 */

#ifndef INCLUDE_TELEPRINTER_HPP_
#define INCLUDE_TELEPRINTER_HPP_

/************************* Standard Library Includes **************************/

#include <map>
#include <string>

/****************************** Project Includes ******************************/

#include "../include/lorenzMachine.hpp"

/****************************** Class Definitons ******************************/

/**
 * @brief Implementation of the Teleprinter.
 *
 * This class encapsulates the functionality of the teleprinter used to
 * interface with the Lorenz machine device. It provides functions to encrypt a
 * message via the Lorenz machine.
 *
 */
class Teleprinter {
 private:
  static const std::map<char, int> CHAR_TO_BAUDOT;  ///< Char to Baudot mapping.
  static const std::map<int, char> BAUDOT_TO_CHAR;  ///< Baudot to char mapping.

  LorenzMachine lorenzMachine;  ///< Lorenz machine to perform encryption.

  /**
   * @brief Get the Baudot code of a character.
   *
   * This function returns the Baudot value of a given character from the
   * teleprinter's mapping configuration.
   *
   * @param character The char value to get the Baudot of.
   * @return int The Baudot value of the given char.
   */
  static int getBaudotFromChar(char character);

  /**
   * @brief Get the character value of a Baudot code.
   *
   * This function returns the character of a given Baudot value from the
   * teleprinter's mapping configuration.
   *
   * @param baudot The Baudot value to get the char of.
   * @return char The char of the given Baudot value.
   */
  static char getCharFromBaudot(int baudot);

 public:
  /**
   * @brief Construct a new Teleprinter object.
   *
   * This constructor initialises a Teleprinter object with a provided Lorenz
   * machine.
   *
   * @param lorenzMachine The Lorenz machine device.
   */
  explicit Teleprinter(LorenzMachine lorenzMachine);

  /**
   * @brief Encrypts a message using the Lorenz machine device.
   *
   * This function encrypts a message using the Lorenz machine device. It gets
   * the Baudot code of each character in the message, encrypts it using the
   * Lorenz machine and then gets the new character using the encrypted Baudot
   * code.
   *
   * @param message The message to encrypt.
   * @return std::string The encrypted message.
   */
  std::string encryptMessage(const std::string& message);
};

#endif  // INCLUDE_TELEPRINTER_HPP_
