/// @file uart_driver.hpp
/// @brief High-level UART driver interface.

#pragma once

#include <cstdint>

/// @brief Abstracts a UART peripheral for simple text and byte output.
///
/// Wraps the HAL UART functions to provide an object-oriented interface.
/// Call init() before any write operations.
class UartDriver {
 public:
  /// @brief Constructs the driver with the desired baud rate.
  ///
  /// @param baud  Baud rate in bits per second. Defaults to 115200.
  explicit UartDriver(uint32_t baud = 115200u);

  /// @brief Initializes the UART peripheral.
  ///
  /// Configures clocks, GPIO routing, and the EUSART peripheral at the
  /// baud rate supplied to the constructor.
  void init();

  /// @brief Transmits a null-terminated string.
  ///
  /// @param str  Pointer to the null-terminated string to transmit.
  void write(const char* str);

  /// @brief Transmits a single byte.
  ///
  /// @param byte  The byte value to transmit.
  void write_byte(uint8_t byte);

 private:
  uint32_t baud_;  ///< Configured baud rate in bits per second.
};
