# Set the minimum version of CMake that can be used
# $ cmake --version
cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 20)
# set_property(TARGET hpl PROPERTY CXX_STANDARD 17)

project (hpl)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cc
    src/lexer.cc
    src/chunk.cc
    src/compiler.cc
    src/tools.cc
    # Library to parse arguments C++17 https://github.com/p-ranav/argparse.git
    lib/argparse.hpp
)

# Add an executable with the above sources
add_executable(hpl ${SOURCES})
