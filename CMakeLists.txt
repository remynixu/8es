cmake_minimum_required(VERSION 3.10)
project(8es C)

set(CMAKE_BINARY_DIR "./build")
set(CMAKE_SOURCE_DIR "./")
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic")

file(GLOB_RECURSE SOURCES "*.c")
add_executable(tty_game ${SOURCES})
