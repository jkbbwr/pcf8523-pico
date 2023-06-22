#include <pcf8523.h>
#include <hardware/i2c.h>
#include "internal.h"

int pcf8523_enable_battery_switchover() {
    uint8_t in[2] = {PCF8523_CONTROL_3, 0x00};
    try_return_error(i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, in, 2, false), PICO_ERROR_GENERIC);
    return 0;
}