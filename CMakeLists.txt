# Specify the CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(monnidb VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(monnidb
    main.cpp
    database.cpp
    queryengine.cpp
    table.cpp
)

# Include directories
target_include_directories(monnidb PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
