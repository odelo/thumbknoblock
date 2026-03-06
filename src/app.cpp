#include "app.hpp"
extern "C" { #include "em_gpio.h" }
#include <cstdint>
static constexpr GPIO_Port_TypeDef LED0_PORT = gpioPortA;
static constexpr uint32_t LED0_PIN = 4u;
static void delay(volatile uint32_t n) { while (n--) __asm volatile("nop"); }
void app_run() {
    GPIO_PinModeSet(LED0_PORT, LED0_PIN, gpioModePushPull, 0);
    while (true) { GPIO_PinOutToggle(LED0_PORT, LED0_PIN); delay(500'000u); }
}