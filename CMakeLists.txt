# Requirements.
cmake_minimum_required(VERSION 2.6)

set (PROJECT ege)

# Project.
project(${PROJECT})


# Set up the output path.
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

# Compiler flags.
set(CMAKE_C_FLAGS "-std=c11 ${CMAKE_C_FLAGS}")

if (UNIX)
  set(CMAKE_C_FLAGS "-g3 -Wall -Wextra -W  ${CMAKE_C_FLAGS}")
endif()

# Generate list of source files.
file (
  GLOB_RECURSE
  SRCS
  "${CMAKE_SOURCE_DIR}/src/*.c"
  )

# Headers directories.
set (HDRS "${CMAKE_SOURCE_DIR}/include/")

# Headers.
include_directories(${HDRS} ${SDL_INCLUDE_DIRS})

Find_Package ( SDL 1.2.15 )

# Executable.
add_executable(${PROJECT} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT} ${SDL_LIBRARY})
