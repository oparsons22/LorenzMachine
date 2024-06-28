# Define the minimum CMake version
cmake_minimum_required(VERSION 3.20)

# Define the project name and version
project(LorenzMachine VERSION 2.0.0
    DESCRIPTION "Template for C++ projects"
    LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define project directories
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(EXTERN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern)

# Define compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g --coverage")

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable target
add_executable(LorenzMachine)

# Find all source files (excluding tests)
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_DIR}/*.hpp)

# Add source files to executable target
target_sources(LorenzMachine PRIVATE ${SRC_FILES} ${INCLUDE_FILES})

# Include directories
target_include_directories(LorenzMachine PRIVATE ${INCLUDE_DIR})

# Output directories (optional, can be omitted if you want defaults)
set_target_properties(LorenzMachine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add GoogleTest
add_subdirectory(${EXTERN_DIR}/googletest)

# Add test subdirectory
add_subdirectory(test)
