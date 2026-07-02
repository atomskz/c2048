cmake_minimum_required(VERSION 3.15)

project(c2048
    VERSION 0.1.0
    DESCRIPTION "Terminal-based 2048 game written in C"
    LANGUAGES C)

# Language standard: C11, required, no compiler-specific extensions.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Default to a Release build when the user did not specify one.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
endif()

add_executable(c2048
    src/main.c
    src/board.c
    src/game.c
    src/render.c
    src/utils.c)

target_include_directories(c2048 PRIVATE include)

# Enable common warnings on GCC/Clang; harmless if the flags are unsupported.
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(c2048 PRIVATE -Wall -Wextra -Wpedantic)
endif()
