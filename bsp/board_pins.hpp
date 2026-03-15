/// @file board_pins.hpp
/// @brief Board-level GPIO pin assignment table for BRD2703A (xG24 Explorer Kit).
///
/// Documents and initialises every GPIO pin on the EFR32MG24B210F1536IM48
/// (4 ports × up to 10 pins = 32 physical pins: PA0-PA9, PB0-PB5, PC0-PC9,
/// PD0-PD5).  The initialisation call configures each pin to a known,
/// safe state at startup.  Peripheral drivers that own a pin (EUSART, I2C,
/// …) will reconfigure it when they are initialised.

#pragma once

/// @brief Initialises every GPIO pin to a known startup state.
///
/// Must be called after the GPIO peripheral clock has been enabled
/// (i.e. after bsp_init() enables cmuClock_GPIO).  Pins managed by
/// hardware debug circuitry (SWCLK, SWDIO, SWO) are intentionally
/// skipped — reconfiguring them would break the debug interface.
void board_pins_init();
