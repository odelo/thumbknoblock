/// @file board_pins.cpp
/// @brief Board-level GPIO pin assignment table for BRD2703A (xG24 Explorer Kit).
///
/// EFR32MG24B210F1536IM48 GPIO inventory
/// ───────────────────────────────────────
///  Port A  10 pins  PA0 – PA9
///  Port B   6 pins  PB0 – PB5
///  Port C  10 pins  PC0 – PC9
///  Port D   6 pins  PD0 – PD5
///  Total   32 pins
///
/// Column key
/// ──────────
///  Disabled    gpioModeDisabled – high-Z, no pull; safe default for NC pins.
///  Input       gpioModeInput    – digital input, no pull resistor.
///  InputPullUp gpioModeInputPull with OUT=1 – digital input, pull-up enabled.
///  Output      gpioModePushPull with OUT=0  – push-pull output, driven low.
///  [SKIP]      SWD / ETM pins managed by debug hardware; never reconfigure.

#include "board_pins.hpp"

#include "hal_gpio.hpp"

// Zero-based port indices that map directly to GPIO_Port_TypeDef enumerators.
static constexpr uint8_t kPortA = 0u;
static constexpr uint8_t kPortB = 1u;
static constexpr uint8_t kPortC = 2u;
static constexpr uint8_t kPortD = 3u;

void board_pins_init() {

  // ── Port A ──────────────────────────────────────────────────────────────────
  //  Pin   Mode          Assignment
  hal_gpio_init_disabled (kPortA, 0);  // PA0  NC
  /* PA1  [SKIP]          SWCLK – SWD debug clock; managed by debug hardware  */
  /* PA2  [SKIP]          SWDIO – SWD debug data;  managed by debug hardware  */
  /* PA3  [SKIP]          SWO   – serial wire output; managed by debug hardware*/
  hal_gpio_init_output   (kPortA, 4);  // PA4  LED0 – yellow status LED, active-high
  hal_gpio_init_disabled (kPortA, 5);  // PA5  NC
  hal_gpio_init_disabled (kPortA, 6);  // PA6  NC
  hal_gpio_init_disabled (kPortA, 7);  // PA7  NC
  hal_gpio_init_output   (kPortA, 8);  // PA8  EUSART1 TX (VCOM) – reconfigured by hal_uart_init
  hal_gpio_init_input    (kPortA, 9);  // PA9  EUSART1 RX (VCOM) – reconfigured by hal_uart_init

  // ── Port B ──────────────────────────────────────────────────────────────────
  //  Pin   Mode          Assignment
  hal_gpio_init_disabled (kPortB, 0);  // PB0  NC
  hal_gpio_init_disabled (kPortB, 1);  // PB1  NC  (EM4WU3 capable)
  hal_gpio_init_disabled (kPortB, 2);  // PB2  NC
  hal_gpio_init_disabled (kPortB, 3);  // PB3  NC
  hal_gpio_init_disabled (kPortB, 4);  // PB4  NC
  hal_gpio_init_disabled (kPortB, 5);  // PB5  NC

  // ── Port C ──────────────────────────────────────────────────────────────────
  //  Pin   Mode          Assignment
  hal_gpio_init_disabled (kPortC, 0);  // PC0  NC
  hal_gpio_init_disabled (kPortC, 1);  // PC1  EFP0 SDA – I2C data;  reconfigured by EFP driver
  hal_gpio_init_disabled (kPortC, 2);  // PC2  EFP0 SCL – I2C clock; reconfigured by EFP driver
  hal_gpio_init_disabled (kPortC, 3);  // PC3  NC
  hal_gpio_init_disabled (kPortC, 4);  // PC4  NC
  hal_gpio_init_input    (kPortC, 5);  // PC5  EFP0 INT – power-management interrupt, active-low
  hal_gpio_init_disabled (kPortC, 6);  // PC6  NC
  hal_gpio_init_disabled (kPortC, 7);  // PC7  NC
  hal_gpio_init_disabled (kPortC, 8);  // PC8  NC
  hal_gpio_init_disabled (kPortC, 9);  // PC9  NC

  // ── Port D ──────────────────────────────────────────────────────────────────
  //  Pin   Mode          Assignment
  hal_gpio_init_disabled (kPortD, 0);  // PD0  NC
  hal_gpio_init_disabled (kPortD, 1);  // PD1  NC
  hal_gpio_init_disabled (kPortD, 2);  // PD2  NC
  hal_gpio_init_disabled (kPortD, 3);  // PD3  NC
  hal_gpio_init_disabled (kPortD, 4);  // PD4  NC
  hal_gpio_init_disabled (kPortD, 5);  // PD5  NC  (EM4WU10 capable)
}
// clang-format on
