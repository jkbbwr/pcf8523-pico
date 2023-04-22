#include "pcf8523.h"
#include "hardware/i2c.h"
#include "internal.h"

int pcf8523_get_datetime(pcf8523_datetime *dt) {
    uint8_t in[1] = {PCF8523_DATETIME_START};
    uint8_t out[7] = {0};

    i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, in, 1, true);
    i2c_read_blocking(i2c_default, PCF8523_I2C_ADDRESS, out, 7, false);

    // Grab the 7th bit of `seconds` to extract integrity.
    dt->trusted = (out[0] & 0x80) >> 7 == 0;
    dt->second = bcd_to_decimal(out[0] & 0x7F);
    dt->minute = bcd_to_decimal(out[1]);
    dt->hour = bcd_to_decimal(out[2]);
    dt->day = bcd_to_decimal(out[3]);
    dt->weekday = 0;
    dt->month = 0;
    dt->year = bcd_to_decimal(out[6]);

    return 0;
}