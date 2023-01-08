cmake_minimum_required(VERSION 3.5)

project(monitor)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(inc)
file(GLOB SOURCES "src/*.c")

add_executable(monitor ${SOURCES})

target_link_libraries(monitor ${CURSES_LIBRARIES})

target_compile_options(monitor PRIVATE -Wall -Wextra)