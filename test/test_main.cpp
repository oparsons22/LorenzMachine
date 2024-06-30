/**
 * @file test_main.cpp
 * @brief Entry point for the Google Test framework.
 * @date 2024-06-25
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/****************************** Project Includes ******************************/

#include <gtest/gtest.h>

/*************************** Function Definitions  ****************************/

/**
 * @brief Runs all unit tests.
 *
 * @param argc Number of command line arguments.
 * @param argv Command line arguments.
 * @return int 0 if all tests are successful, or 1 otherwise.
 */
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
