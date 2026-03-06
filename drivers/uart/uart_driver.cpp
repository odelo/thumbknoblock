#include "uart_driver.hpp"
#include "hal_uart.hpp"
UartDriver::UartDriver(uint32_t baud) : baud_(baud) {}
void UartDriver::init() { hal_uart_init(baud_); }
void UartDriver::write(const char* str) { hal_uart_puts(str); }
void UartDriver::write_byte(uint8_t byte) { hal_uart_putchar(static_cast<char>(byte)); }