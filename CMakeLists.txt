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

