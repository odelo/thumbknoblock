#pragma once
#include <cstdint>
void hal_gpio_init_output(uint8_t port, uint8_t pin);
void hal_gpio_set(uint8_t port, uint8_t pin, bool state);
void hal_gpio_toggle(uint8_t port, uint8_t pin);