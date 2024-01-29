cmake_minimum_required(VERSION 3.13)
# project(${PROJECT} C CXX ASM)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(my_project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 17)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project


add_executable(main
    main.cpp
    src/Logger.h
    src/Logger.cpp
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(main pico_stdlib)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(main)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)