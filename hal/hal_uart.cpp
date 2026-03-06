#include "hal_uart.hpp"
extern "C" { #include "em_cmu.h" \n#include "em_eusart.h" \n#include "em_gpio.h" }
static constexpr GPIO_Port_TypeDef VCOM_PORT = gpioPortA;
static constexpr uint32_t VCOM_TX = 8u, VCOM_RX = 9u;
void hal_uart_init(uint32_t baud) {
    CMU_ClockEnable(cmuClock_EUSART1, true); CMU_ClockEnable(cmuClock_GPIO, true);
    GPIO_PinModeSet(VCOM_PORT, VCOM_TX, gpioModePushPull, 1);
    GPIO_PinModeSet(VCOM_PORT, VCOM_RX, gpioModeInput, 0);
    EUSART_UartInit_TypeDef init = EUSART_UART_INIT_DEFAULT_HF; init.baudrate = baud;
    EUSART_UartInitHf(EUSART1, &init);
    GPIO->EUSARTROUTE[1].TXROUTE = (VCOM_PORT << _GPIO_EUSART_TXROUTE_PORT_SHIFT) | (VCOM_TX << _GPIO_EUSART_TXROUTE_PIN_SHIFT);
    GPIO->EUSARTROUTE[1].RXROUTE = (VCOM_PORT << _GPIO_EUSART_RXROUTE_PORT_SHIFT) | (VCOM_RX << _GPIO_EUSART_RXROUTE_PIN_SHIFT);
    GPIO->EUSARTROUTE[1].ROUTEEN = GPIO_EUSART_ROUTEEN_TXPEN | GPIO_EUSART_ROUTEEN_RXPEN;
}
void hal_uart_putchar(char c) { EUSART_Tx(EUSART1, static_cast<uint8_t>(c)); }
void hal_uart_puts(const char* str) { while (*str) hal_uart_putchar(*str++); }