cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_COMPILER clang++)

project(lastcpp LANGUAGES CXX)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Tell CMake to scan for module dependencies
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Generate compile_commands.json for IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define executable
add_executable(lastcpp
    hello.cpp
    b.cpp
)

# Declare module interface files explicitly
target_sources(lastcpp
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES
        FILES a.cppm
              Vector.cppm
)
