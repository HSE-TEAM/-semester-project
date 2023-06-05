cmake_minimum_required(VERSION 3.25)
project(
        Calculator
        VERSION 1.0
        DESCRIPTION "A calculator that can be used to calculate the cost of a balcony"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src/calculator)
add_subdirectory(src/database)
add_subdirectory(src/common)
add_subdirectory(src/utils)

add_subdirectory(apps)