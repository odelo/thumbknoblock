#include "bsp_init.hpp"
extern "C" { #include "em_chip.h" \n#include "em_cmu.h" }
void bsp_init() { CHIP_Init(); CMU_ClockEnable(cmuClock_GPIO, true); }