/// @file hal_gpio.cpp
/// @brief GPIO hardware abstraction layer implementation.

#include "hal_gpio.hpp"

extern "C" {
#include "em_gpio.h"
}

/// @brief Converts a zero-based port index to the vendor GPIO_Port_TypeDef.
///
/// @param p  Zero-based port index.
/// @return   Corresponding GPIO_Port_TypeDef enumeration value.
static GPIO_Port_TypeDef to_port(uint8_t p) {
  return static_cast<GPIO_Port_TypeDef>(p);
}

void hal_gpio_init_output(uint8_t port, uint8_t pin) {
  GPIO_PinModeSet(to_port(port), pin, gpioModePushPull, 0);
}

void hal_gpio_init_input(uint8_t port, uint8_t pin) {
  GPIO_PinModeSet(to_port(port), pin, gpioModeInput, 0);
}

void hal_gpio_init_input_pull(uint8_t port, uint8_t pin, bool pull_up) {
  GPIO_PinModeSet(to_port(port), pin, gpioModeInputPull, pull_up ? 1u : 0u);
}

void hal_gpio_init_disabled(uint8_t port, uint8_t pin) {
  GPIO_PinModeSet(to_port(port), pin, gpioModeDisabled, 0);
}

void hal_gpio_set(uint8_t port, uint8_t pin, bool s) {
  if (s) {
    GPIO_PinOutSet(to_port(port), pin);
  } else {
    GPIO_PinOutClear(to_port(port), pin);
  }
}

void hal_gpio_toggle(uint8_t port, uint8_t pin) {
  GPIO_PinOutToggle(to_port(port), pin);
}

bool hal_gpio_read(uint8_t port, uint8_t pin) {
  return GPIO_PinInGet(to_port(port), pin) != 0u;
}
