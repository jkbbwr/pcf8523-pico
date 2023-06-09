#include <pcf8523.h>
#include <hardware/i2c.h>
#include "internal.h"

int pcf8523_reset() {
    uint8_t in[2] = {PCF8523_CONTROL_1, 0x58};
    try_return_error(i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, in, 2, false), PICO_ERROR_GENERIC);
    return 0;
}