/**
 * @file teleprinter.cpp
 * @brief Implements the Teleprinter component.
 * @date 2024-06-30
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/************************* Standard Library Includes **************************/

#include <map>
#include <string>
#include <utility>

/****************************** Project Includes ******************************/

#include "../include/lorenzMachine.hpp"
#include "../include/teleprinter.hpp"

/********************************* Constants **********************************/

const std::map<char, int> Teleprinter::CHAR_TO_BAUDOT = {
    {'*', 0b00000}, {' ', 0b00100}, {'Q', 0b10111}, {'W', 0b10011},
    {'E', 0b00001}, {'R', 0b01010}, {'T', 0b10000}, {'Y', 0b10101},
    {'U', 0b00111}, {'I', 0b00110}, {'O', 0b11000}, {'P', 0b10110},
    {'A', 0b00011}, {'S', 0b00101}, {'D', 0b01001}, {'F', 0b01101},
    {'G', 0b11010}, {'H', 0b10100}, {'J', 0b01011}, {'K', 0b01111},
    {'L', 0b10010}, {'Z', 0b10001}, {'X', 0b11101}, {'C', 0b01110},
    {'V', 0b11110}, {'B', 0b11001}, {'N', 0b01100}, {'M', 0b11100},
    {',', 0b01000}, {'-', 0b00010}, {'!', 0b11011}, {'.', 0b11111}};

const std::map<int, char> Teleprinter::BAUDOT_TO_CHAR = {
    {0b00000, '*'}, {0b00100, ' '}, {0b10111, 'Q'}, {0b10011, 'W'},
    {0b00001, 'E'}, {0b01010, 'R'}, {0b10000, 'T'}, {0b10101, 'Y'},
    {0b00111, 'U'}, {0b00110, 'I'}, {0b11000, 'O'}, {0b10110, 'P'},
    {0b00011, 'A'}, {0b00101, 'S'}, {0b01001, 'D'}, {0b01101, 'F'},
    {0b11010, 'G'}, {0b10100, 'H'}, {0b01011, 'J'}, {0b01111, 'K'},
    {0b10010, 'L'}, {0b10001, 'Z'}, {0b11101, 'X'}, {0b01110, 'C'},
    {0b11110, 'V'}, {0b11001, 'B'}, {0b01100, 'N'}, {0b11100, 'M'},
    {0b01000, ','}, {0b00010, '-'}, {0b11011, '!'}, {0b11111, '.'},
};

/*************************** Function Definitions  ****************************/

/**
 * @brief Get the Baudot code of a character.
 *
 * This function returns the Baudot value of a given character from the
 * teleprinter's mapping configuration.
 *
 * @param character The char value to get the Baudot of.
 * @return int The Baudot value of the given char.
 */
int Teleprinter::getBaudotFromChar(const char character) {
  return CHAR_TO_BAUDOT.at(character);
}

/**
 * @brief Get the character value of a Baudot code.
 *
 * This function returns the character of a given Baudot value from the
 * teleprinter's mapping configuration.
 *
 * @param baudot The Baudot value to get the char of.
 * @return char The char of the given Baudot value.
 */
char Teleprinter::getCharFromBaudot(int baudot) {
  return BAUDOT_TO_CHAR.at(baudot);
}

/**
 * @brief Construct a new Teleprinter object.
 *
 * This constructor initialises a Teleprinter object with a provided Lorenz
 * machine.
 *
 * @param lorenzMachine The Lorenz machine device.
 */
Teleprinter::Teleprinter(LorenzMachine lorenzMachine)
    : lorenzMachine(std::move(lorenzMachine)) {}

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
std::string Teleprinter::encryptMessage(const std::string& message) {
  std::string encryptedMessage;
  for (const char character : message) {
    const int baudot = getBaudotFromChar(character);
    const char encryptedChar =
        getCharFromBaudot(lorenzMachine.encryptChar(baudot));
    encryptedMessage.push_back(encryptedChar);
  }

  return encryptedMessage;
}
