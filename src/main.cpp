#include "app.hpp"
#include "bsp_init.hpp"
int main() { bsp_init(); app_run(); while (true) {} }