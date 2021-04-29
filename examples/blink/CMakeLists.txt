cmake_minimum_required(VERSION 3.12)

#pull in pico SDK (must before project)
include(pico_sdk_import.cmake)

project(shift_register C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

#initialize the SDK
pico_sdk_init()

add_executable(${PROJECT_NAME}
    main.c
    ../../src/shift_register.c
    )

#pull in our pico_stdib which pulls common
target_link_libraries(shift_register pico_stdlib)

#create map/bin/hes file etc.
pico_add_extra_outputs(shift_register)
