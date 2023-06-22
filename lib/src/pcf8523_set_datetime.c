#include "pcf8523.h"
#include "hardware/i2c.h"
#include "internal.h"
#include "internal.h"

int pcf8523_set_datetime(datetime_t *dt) {
    uint8_t in[8] = {
            PCF8523_DATETIME_START,
            decimal_to_bcd(dt->sec),
            decimal_to_bcd(dt->min),
            decimal_to_bcd(dt->hour),
            decimal_to_bcd(dt->day),
            decimal_to_bcd(dt->dotw),
            decimal_to_bcd(dt->month),
            decimal_to_bcd(dt->year - 2000)
    };

    try_return_error(i2c_write_blocking(i2c_default, PCF8523_I2C_ADDRESS, in, 8, false), PICO_ERROR_GENERIC);
    return 0;
}