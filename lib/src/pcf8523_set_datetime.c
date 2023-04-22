#include "pcf8523.h"
#include "hardware/i2c.h"
#include "internal.h"

int pcf8523_set_datetime(pcf8523_datetime *dt) {
    uint8_t in[8] = {
            PCF8523_DATETIME_START,
            decimal_to_bcd(dt->second),
            decimal_to_bcd(dt->minute),
            decimal_to_bcd(dt->hour),
            decimal_to_bcd(dt->day),
            decimal_to_bcd(0),
            decimal_to_bcd(0),
            decimal_to_bcd(dt->year - 2000),
    };

    i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, in, 8, false);
    return 0;
}