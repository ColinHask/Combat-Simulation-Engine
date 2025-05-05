cmake_minimum_required(VERSION 3.10)
project(combat-simulation-engine)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories for different configurations (important on Windows)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)

# Add include directories
include_directories(
    include
    external
)

# Gather all .cpp files in src/
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Create the executable
add_executable(simulator ${SOURCE_FILES})
