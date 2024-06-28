# Find all test source files
file(GLOB TEST_FILES "*.cpp")

# Create the test executable
add_executable(runTests ${TEST_FILES})

# Link GoogleTest and other needed libraries to the test executable
target_link_libraries(runTests gtest gtest_main)

# Include directories for the tests
target_include_directories(runTests PRIVATE ${INCLUDE_DIR})

# Find all source files in src and include directories (excluding main.cpp)
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp ${INCLUDE_DIR}/*.hpp)
list(REMOVE_ITEM SRC_FILES "${SRC_DIR}/main.cpp") # Exclude main.cpp from coverage

# Add compiler flags for coverage
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang")
    target_compile_options(runTests PRIVATE "-fprofile-instr-generate" "-fcoverage-mapping")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(runTests PRIVATE "--coverage")
endif()

# Add source files to the test executable
target_sources(runTests PRIVATE ${SRC_FILES})

# Add a test target for running the tests with CTest
enable_testing()
add_test(NAME UnitTests COMMAND runTests)

# Set output directories for the test executable
set_target_properties(runTests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)
