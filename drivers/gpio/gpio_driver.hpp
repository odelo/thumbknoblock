#pragma once
#include <cstdint>
enum class GpioMode { Input, Output, PushPull, InputPull };
class GpioDriver {
public:
    GpioDriver(uint8_t port, uint8_t pin, GpioMode mode);
    void set(bool high); void toggle(); bool read() const;
private:
    uint8_t port_, pin_;
};