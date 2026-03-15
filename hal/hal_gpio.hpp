/// @file hal_gpio.hpp
/// @brief GPIO hardware abstraction layer interface.
///
/// Provides a thin wrapper over the Silicon Labs emlib GPIO API, translating
/// between the driver layer's port/pin representation and the vendor types.

#pragma once

#include <cstdint>

/// @brief Configures a GPIO pin as a push-pull output.
///
/// @param port  Zero-based GPIO port index.
/// @param pin   Zero-based GPIO pin index within the port.
void hal_gpio_init_output(uint8_t port, uint8_t pin);

/// @brief Drives a GPIO output pin to a given logic level.
///
/// @param port   Zero-based GPIO port index.
/// @param pin    Zero-based GPIO pin index within the port.
/// @param state  `true` to drive the pin high; `false` to drive it low.
void hal_gpio_set(uint8_t port, uint8_t pin, bool state);

/// @brief Toggles the output state of a GPIO pin.
///
/// @param port  Zero-based GPIO port index.
/// @param pin   Zero-based GPIO pin index within the port.
void hal_gpio_toggle(uint8_t port, uint8_t pin);
