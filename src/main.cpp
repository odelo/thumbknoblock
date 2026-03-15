/// @file main.cpp
/// @brief Firmware entry point.

#include "app.hpp"
#include "bsp_init.hpp"

/// @brief C runtime entry point.
///
/// Initializes the board support package and then transfers control to the
/// application. A spin loop after app_run() satisfies the compiler's
/// requirement for a return value while keeping the CPU active if
/// app_run() were to return unexpectedly.
///
/// @return Never returns under normal operation.
int main() {
  bsp_init();
  app_run();
  while (true) {}
}
