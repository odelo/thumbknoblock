/// @file bsp_init.hpp
/// @brief Board support package initialization interface.

#pragma once

/// @brief Initializes the board support package.
///
/// Applies chip errata workarounds and enables peripheral clocks required
/// by the hardware abstraction layer. Must be called once at startup before
/// any HAL or driver functions are used.
void bsp_init();
