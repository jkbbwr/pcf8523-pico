#include <pcf8523.h>
#include "pico/stdlib.h"
#include <stdio.h>
#include <hardware/i2c.h>
#include <string.h>

#define SDA 0
#define SCL 1

int main() {
    stdio_init_all();
    i2c_init(i2c_default, 100 * 1000);

    gpio_set_function(SDA, GPIO_FUNC_I2C);
    gpio_set_function(SCL, GPIO_FUNC_I2C);

    gpio_pull_up(SDA);
    gpio_pull_down(SCL);

    datetime_t datetime = {
            .year = 2023,
            .month = 6,
            .day = 22,
            .dotw = 4,
            .hour = 23,
            .min = 23,
            .sec = 25,
    };

    char dt[40];
    datetime_to_str(dt, 40, &datetime);
    printf("Setting date time to %s\n", dt);

    /*
    pcf8523_reset();
    pcf8523_rtc_start();
    pcf8523_enable_battery_switchover();
    pcf8523_set_datetime(&datetime);
    */

    while (true) {
        bool trusted = pcf8523_get_datetime(&datetime);
        memset(dt, 0, sizeof(dt));
        datetime_to_str(dt, 40, &datetime);
        printf("Fetched datetime (trusted? %s): %s\n", (trusted == PCF8523_TRUSTED ? "true" : "false"), dt);
        sleep_ms(1000);
    }
}