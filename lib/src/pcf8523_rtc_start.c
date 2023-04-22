#include <pcf8523.h>
#include <hardware/i2c.h>

int pcf8523_rtc_start() {
    uint8_t in[1] = {PCF8523_CONTROL_1};
    uint8_t out[1] = {0};
    i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, in, 1, true);
    i2c_read_blocking(i2c_default, PCF8523_I2C_ADDRESS, out, 1, false);
    uint8_t set[2] = {PCF8523_CONTROL_1, out[0] & 0xDF};
    i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, set, 2, false);
    return 0;
}