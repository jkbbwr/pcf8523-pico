#pragma once
#include <stdint.h>

static uint8_t bcd_to_decimal(uint8_t bcd_value) {
    uint8_t high_nibble = (bcd_value >> 4) & 0x0F;
    uint8_t low_nibble = bcd_value & 0x0F;
    return (high_nibble * 10) + low_nibble;
}

static uint8_t decimal_to_bcd(uint8_t decimal_value) {
    uint8_t tens = decimal_value / 10;
    uint8_t ones = decimal_value % 10;
    return (tens << 4) | ones;
}