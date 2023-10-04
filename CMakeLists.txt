# Set the minimum version of CMake that can be used
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

project (hpl)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cc
    src/lexer.cc
    src/tools.cc
)

# Add an executable with the above sources
add_executable(hpl ${SOURCES})
