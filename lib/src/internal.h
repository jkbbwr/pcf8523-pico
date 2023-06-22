#pragma once

#include <stdint.h>

static int8_t bcd_to_decimal(uint8_t bcd_value) {
    int8_t high_nibble = (bcd_value >> 4) & 0x0F;
    int8_t low_nibble = bcd_value & 0x0F;
    return (high_nibble * 10) + low_nibble;
}

static int8_t decimal_to_bcd(uint8_t decimal_value) {
    int8_t tens = decimal_value / 10;
    int8_t ones = decimal_value % 10;
    return (tens << 4) | ones;
}

#define try_return_error(result, error) {\
    if (result == error) {  \
        return error;       \
    }                       \
}