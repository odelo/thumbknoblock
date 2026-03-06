#include "gpio_driver.hpp"
#include "hal_gpio.hpp"
GpioDriver::GpioDriver(uint8_t port, uint8_t pin, GpioMode mode) : port_(port), pin_(pin) {
    if (mode == GpioMode::Output || mode == GpioMode::PushPull) hal_gpio_init_output(port_, pin_);
}
void GpioDriver::set(bool high) { hal_gpio_set(port_, pin_, high); }
void GpioDriver::toggle() { hal_gpio_toggle(port_, pin_); }
bool GpioDriver::read() const { return false; }