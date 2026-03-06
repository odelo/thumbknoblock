#include "hal_gpio.hpp"
extern "C" { #include "em_gpio.h" }
static GPIO_Port_TypeDef to_port(uint8_t p) { return static_cast<GPIO_Port_TypeDef>(p); }
void hal_gpio_init_output(uint8_t port, uint8_t pin) { GPIO_PinModeSet(to_port(port), pin, gpioModePushPull, 0); }
void hal_gpio_set(uint8_t port, uint8_t pin, bool s) { s ? GPIO_PinOutSet(to_port(port), pin) : GPIO_PinOutClear(to_port(port), pin); }
void hal_gpio_toggle(uint8_t port, uint8_t pin) { GPIO_PinOutToggle(to_port(port), pin); }