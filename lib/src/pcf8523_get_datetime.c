#include "pcf8523.h"
#include "hardware/i2c.h"
#include "internal.h"

int pcf8523_get_datetime(datetime_t *dt) {
    uint8_t in[1] = {PCF8523_DATETIME_START};
    uint8_t out[7] = {0};

    try_return_error(i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, in, 1, true), PICO_ERROR_GENERIC);
    try_return_error(i2c_read_blocking(i2c_default, PCF8523_I2C_ADDRESS, out, 7, false), PICO_ERROR_GENERIC);

    dt->sec = bcd_to_decimal(out[0] & 0x7F);
    dt->min = bcd_to_decimal(out[1]);
    dt->hour = bcd_to_decimal(out[2]);
    dt->day = bcd_to_decimal(out[3]);
    dt->dotw = bcd_to_decimal(out[4]);
    dt->month = bcd_to_decimal(out[5]);
    dt->year = (int16_t) (bcd_to_decimal(out[6]) + 2000);

    bool trusted = (out[0] & 0x80) >> 7 == 0;

    if (trusted) {
        return PCF8523_TRUSTED;
    }

    return PCF8523_NOT_TRUSTED;
}