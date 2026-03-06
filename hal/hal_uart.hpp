#pragma once
#include <cstdint>
void hal_uart_init(uint32_t baud);
void hal_uart_putchar(char c);
void hal_uart_puts(const char* str);