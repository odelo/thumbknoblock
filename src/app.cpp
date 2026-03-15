/// @file app.cpp
/// @brief Application logic implementation.

#include "app.hpp"

#include <cstdint>

extern "C" {
#include "em_gpio.h"
}

/// @brief GPIO port for LED0 (PA4 on BRD2703A).
static constexpr GPIO_Port_TypeDef LED0_PORT = gpioPortA;

/// @brief GPIO pin number for LED0.
static constexpr uint32_t LED0_PIN = 4u;

/// @brief Busy-waits for approximately @p n NOP cycles.
///
/// Used to produce a visible blink delay without a timer peripheral.
/// The actual duration is dependent on the CPU clock frequency and
/// compiler optimizations.
///
/// @param n  Number of NOP instructions to execute.
static void delay(volatile uint32_t n) {
  while (n--) {
    __asm volatile("nop");
  }
}

void app_run() {
  GPIO_PinModeSet(LED0_PORT, LED0_PIN, gpioModePushPull, 0);

  while (true) {
    GPIO_PinOutToggle(LED0_PORT, LED0_PIN);
    delay(500'000u);
  }
}
