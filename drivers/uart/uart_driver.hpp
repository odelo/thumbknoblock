#pragma once
#include <cstdint>
class UartDriver {
public:
    explicit UartDriver(uint32_t baud = 115200u);
    void init(); void write(const char* str); void write_byte(uint8_t byte);
private: uint32_t baud_;
};