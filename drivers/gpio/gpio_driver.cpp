/// @file gpio_driver.cpp
/// @brief High-level GPIO driver implementation.

#include "gpio_driver.hpp"

#include "hal_gpio.hpp"

GpioDriver::GpioDriver(uint8_t port, uint8_t pin, GpioMode mode)
    : port_(port), pin_(pin) {
  switch (mode) {
    case GpioMode::Output:
    case GpioMode::PushPull:
      hal_gpio_init_output(port_, pin_);
      break;
    case GpioMode::Input:
      hal_gpio_init_input(port_, pin_);
      break;
    case GpioMode::InputPull:
      hal_gpio_init_input_pull(port_, pin_, /*pull_up=*/true);
      break;
  }
}

void GpioDriver::set(bool high) {
  hal_gpio_set(port_, pin_, high);
}

void GpioDriver::toggle() {
  hal_gpio_toggle(port_, pin_);
}

bool GpioDriver::read() const {
  return hal_gpio_read(port_, pin_);
}
