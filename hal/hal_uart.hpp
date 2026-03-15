/// @file hal_uart.hpp
/// @brief UART hardware abstraction layer interface.
///
/// Provides a thin wrapper over the Silicon Labs emlib EUSART API for
/// basic UART transmit operations on the virtual COM port (VCOM).

#pragma once

#include <cstdint>

/// @brief Initializes the EUSART1 peripheral for UART communication.
///
/// Enables the EUSART1 and GPIO clocks, configures the TX and RX pins on
/// port A, and routes the peripheral signals through the GPIO EUSART router.
///
/// @param baud  Desired baud rate in bits per second.
void hal_uart_init(uint32_t baud);

/// @brief Transmits a single character over UART.
///
/// Blocks until the EUSART transmit buffer accepts the byte.
///
/// @param c  Character to transmit.
void hal_uart_putchar(char c);

/// @brief Transmits a null-terminated string over UART.
///
/// Calls hal_uart_putchar() for each character until the null terminator
/// is reached.
///
/// @param str  Pointer to the null-terminated string to transmit.
void hal_uart_puts(const char* str);
