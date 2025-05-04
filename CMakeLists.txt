cmake_minimum_required(VERSION 3.10)
project(LostFoundSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES
    "src/*.cpp"
)

# Executable
add_executable(LostFoundSystem ${SOURCES})

# Copy data directory to build directory
file(COPY data DESTINATION ${CMAKE_BINARY_DIR}) 