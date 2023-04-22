#include <pcf8523.h>
#include "pico/stdlib.h"
#include <stdio.h>
#include <hardware/i2c.h>

#define SDA 0
#define SCL 1

int main() {
    stdio_init_all();
    i2c_init(i2c_default, 100 * 1000);

    gpio_set_function(SDA, GPIO_FUNC_I2C);
    gpio_set_function(SCL, GPIO_FUNC_I2C);

    gpio_pull_up(SDA);
    gpio_pull_down(SCL);

    pcf8523_datetime dt;

    /*
    pcf8523_datetime dt = {
            .minute = 10,
            .hour = 21,
            .second = 0,
            .year = 2023,
            .month = 0,
            .day = 0,
            .trusted = false
    };

    pcf8523_reset();
    pcf8523_enable_battery_switchover();
    pcf8523_rtc_start();

    pcf8523_set_datetime(&dt);
    */

    while (1) {
        pcf8523_get_datetime(&dt);
        printf("Trust: %d\n\t%d:%d:%d\n", dt.trusted, dt.hour, dt.minute, dt.second);
        sleep_ms(1000);
    }
}