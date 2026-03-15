/// @file bsp_init.cpp
/// @brief Board support package initialization implementation.

#include "bsp_init.hpp"

#include "board_pins.hpp"

extern "C" {
#include "em_chip.h"
#include "em_cmu.h"
}

void bsp_init() {
  CHIP_Init();
  CMU_ClockEnable(cmuClock_GPIO, true);
  board_pins_init();
}
