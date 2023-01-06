cmake_minimum_required(VERSION 3.5)

project(system_monitor)

set(SOURCES
    src/cpuusage.c
    src/main.c
)

add_executable(system_monitor ${SOURCES})

target_include_directories(system_monitor
    PRIVATE
        ${PROJECT_SOURCE_DIR}/inc
)