# Specify the CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(monnidb VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define source files and header files
set(SOURCES
  src/database.cpp
  src/main.cpp
  src/queryengine.cpp
  src/table.cpp
)

set(HEADERS
  include/database.h
  include/queryengine.h
  include/table.h)

#Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Add a CMake option for building tests
option(BUILD_TESTS "Build and run tests" ON)

if(BUILD_TESTS)
    # Test executable
    add_executable(tests tests/queryengine_test.cpp src/queryengine.cpp src/database.cpp src/table.cpp)
    target_include_directories(tests PRIVATE include)

    # Enable testing and add test case
    enable_testing()
    add_test(NAME QueryEngineTests COMMAND tests)

    # Run tests after build
    add_custom_command(TARGET tests
                       POST_BUILD
                       COMMAND ctest --output-on-failure)
endif()
