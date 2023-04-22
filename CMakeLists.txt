cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_SDK_PATH "/usr/share/pico-sdk")
set(PICO_BOARD pico CACHE STRING "Board type")

include(./cmake/pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif ()

project(pcf8523-test C ASM CXX)

pico_sdk_init()

add_subdirectory(./lib build)
add_executable(pcf8523-test test/main.c)
target_link_libraries(pcf8523-test pcf8523 hardware_i2c pico_stdlib)
pico_enable_stdio_uart(pcf8523-test 0)
pico_enable_stdio_usb(pcf8523-test 1)
pico_add_extra_outputs(pcf8523-test)