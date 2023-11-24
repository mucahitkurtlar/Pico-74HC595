cmake_minimum_required(VERSION 3.12)

# Pull in pico SDK (must before project)
include(pico_sdk_import.cmake)

project(sr_74hc595 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

add_executable(${PROJECT_NAME}
    main.c
    )

# Pull in our pico_stdib which pulls common
target_link_libraries(sr_74hc595 pico_stdlib)

# Create map/bin/hes file etc.
pico_add_extra_outputs(sr_74hc595)
