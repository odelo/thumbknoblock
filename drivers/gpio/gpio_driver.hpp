/// @file gpio_driver.hpp
/// @brief High-level GPIO driver interface.

#pragma once

#include <cstdint>

/// @brief GPIO pin operating mode.
enum class GpioMode {
  Input,      ///< High-impedance digital input.
  Output,     ///< General-purpose digital output.
  PushPull,   ///< Push-pull digital output (driven high and low).
  InputPull,  ///< Digital input with internal pull resistor enabled.
};

/// @brief Abstracts a single GPIO pin.
///
/// Wraps the HAL GPIO functions to provide an object-oriented interface for
/// configuring and manipulating a specific port/pin pair.
class GpioDriver {
 public:
  /// @brief Constructs and configures a GPIO pin.
  ///
  /// @param port  Zero-based GPIO port index.
  /// @param pin   Zero-based GPIO pin index within the port.
  /// @param mode  Desired operating mode for the pin.
  GpioDriver(uint8_t port, uint8_t pin, GpioMode mode);

  /// @brief Drives the pin to a logic level.
  ///
  /// @param high  `true` to drive the pin high; `false` to drive it low.
  void set(bool high);

  /// @brief Toggles the current output state of the pin.
  void toggle();

  /// @brief Reads the current logic level of the pin.
  ///
  /// @return `true` if the pin is high; `false` if it is low.
  bool read() const;

 private:
  uint8_t port_;  ///< GPIO port index.
  uint8_t pin_;   ///< GPIO pin index within the port.
};
