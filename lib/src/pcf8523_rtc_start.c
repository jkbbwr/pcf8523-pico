#include <pcf8523.h>
#include <hardware/i2c.h>
#include "internal.h"

int pcf8523_rtc_start() {
    uint8_t in[1] = {PCF8523_CONTROL_1};
    uint8_t out[1] = {0};
    try_return_error(i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, in, 1, true), PICO_ERROR_GENERIC);
    try_return_error(i2c_read_blocking(i2c_default, PCF8523_I2C_ADDRESS, out, 1, false), PICO_ERROR_GENERIC);
    uint8_t set[2] = {PCF8523_CONTROL_1, out[0] & 0xDF};
    try_return_error(i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, set, 2, false), PICO_ERROR_GENERIC);
    return 0;
}