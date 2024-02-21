cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(my_project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 17)

pico_sdk_init()

add_executable(example
    example/example.cpp
    src/Logger.h
    src/Logger.cpp
)

target_link_libraries(example pico_stdlib)

pico_add_extra_outputs(example)

pico_enable_stdio_usb(example 1)
pico_enable_stdio_uart(example 0)