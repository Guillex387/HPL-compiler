# Set the minimum version of CMake that can be used
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

project (hpl)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cc
)

# Add an executable with the above sources
add_executable(hpl ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(hpl_headers
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
