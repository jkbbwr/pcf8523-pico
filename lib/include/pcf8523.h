#pragma once

#include <stdint.h>
#include <stdbool.h>

#define PCF8523_I2C_ADDRESS 0x68
#define PCF8523_CONTROL_1 0x00
#define PCF8523_CONTROL_2 0x01
#define PCF8523_CONTROL_3 0x02
#define PCF8523_DATETIME_START 0x03

typedef struct {
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
    uint8_t day;
    uint8_t weekday;
    uint8_t month;
    uint16_t year;
    bool trusted;
} pcf8523_datetime;

int pcf8523_get_datetime(pcf8523_datetime *dt);

int pcf8523_set_datetime(pcf8523_datetime *dt);

int pcf8523_reset();

int pcf8523_rtc_start();

int pcf8523_enable_battery_switchover();