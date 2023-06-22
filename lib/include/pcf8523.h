#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "pico/util/datetime.h"

#define PCF8523_I2C_ADDRESS 0x68
#define PCF8523_CONTROL_1 0x00
#define PCF8523_CONTROL_3 0x02
#define PCF8523_DATETIME_START 0x03

#define PCF8523_TRUSTED 0x00
#define PCF8523_NOT_TRUSTED 0x01

int pcf8523_get_datetime(datetime_t *dt);

int pcf8523_set_datetime(datetime_t *dt);

int pcf8523_reset();

int pcf8523_rtc_start();

int pcf8523_enable_battery_switchover();