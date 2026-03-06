cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arm-none-eabi-gcc.cmake)

project(xg24_hello C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/efr32mg24.cmake)

set(GECKO_SDK ${CMAKE_SOURCE_DIR}/gecko_sdk)

set(EMLIB_SRC
    ${GECKO_SDK}/platform/emlib/src/em_cmu.c
    ${GECKO_SDK}/platform/emlib/src/em_emu.c
    ${GECKO_SDK}/platform/emlib/src/em_gpio.c
    ${GECKO_SDK}/platform/emlib/src/em_usart.c
    ${GECKO_SDK}/platform/emlib/src/em_eusart.c
    ${GECKO_SDK}/platform/emlib/src/em_core.c
    ${GECKO_SDK}/platform/emlib/src/em_system.c
)

set(DEVICE_SRC
    startup/startup_efr32mg24.c
    ${GECKO_SDK}/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.c
)

set(APP_SRC
    src/main.cpp
    src/app.cpp
    drivers/gpio/gpio_driver.cpp
    drivers/uart/uart_driver.cpp
    hal/hal_gpio.cpp
    hal/hal_uart.cpp
    bsp/bsp_init.cpp
)

set(INCLUDE_DIRS
    src
    drivers/gpio
    drivers/uart
    hal
    bsp
    ${GECKO_SDK}/platform/emlib/inc
    ${GECKO_SDK}/platform/Device/SiliconLabs/EFR32MG24/Include
    ${GECKO_SDK}/platform/common/inc
    ${GECKO_SDK}/platform/CMSIS/Core/Include
    ${GECKO_SDK}/hardware/board/inc
    ${GECKO_SDK}/hardware/kit/common/bsp
)

add_compile_options(${COMMON_FLAGS})

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/linker/efr32mg24b210f1536.ld)

set(LINK_FLAGS
    ${CPU_FLAGS}
    -T${LINKER_SCRIPT}
    -Wl,--gc-sections
    -Wl,-Map=${CMAKE_BINARY_DIR}/xg24_hello.map
    -specs=nosys.specs
    -specs=nano.specs
)

string(REPLACE ";" " " LINK_FLAGS_STR "${LINK_FLAGS}")

add_executable(xg24_hello.elf ${APP_SRC} ${EMLIB_SRC} ${DEVICE_SRC})
target_include_directories(xg24_hello.elf PRIVATE ${INCLUDE_DIRS})
target_compile_options(xg24_hello.elf PRIVATE ${COMMON_FLAGS})
set_target_properties(xg24_hello.elf PROPERTIES LINK_FLAGS "${LINK_FLAGS_STR}")

add_custom_command(TARGET xg24_hello.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:xg24_hello.elf> ${CMAKE_BINARY_DIR}/xg24_hello.bin
    COMMAND ${CMAKE_OBJCOPY} -O ihex   $<TARGET_FILE:xg24_hello.elf> ${CMAKE_BINARY_DIR}/xg24_hello.hex
    COMMAND ${CMAKE_SIZE}              $<TARGET_FILE:xg24_hello.elf>
    COMMENT "Generating xg24_hello.bin / xg24_hello.hex"
)