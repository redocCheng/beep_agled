/*
 * Copyright (c) 2019-2020, redoc
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-08-14     redoc        the first version
 */

#define LOG_TAG "beep"

#include "drv_gpio.h"
#include "beep.h"
#include "agile_led.h"
#include <rtdbg.h>


#define VALUE_BEEP_SHOW_ERR_LV_LOW       "125,60,125,15590"
#define VALUE_BEEP_SHOW_ERR_LV_MID       "125,60,125,60,125,4505"
#define VALUE_BEEP_SHOW_ERR_LV_HIGH      "125,60,125,60,125,60,125,60,125,60,125,60,125,60,125,60,125,60,125,1210"


static agile_led_t *led_beep;

int beep_stop(void)
{
    agile_led_stop(led_beep);
    agile_led_off(led_beep);
    return RT_EOK;
}

int beep_show_err_low(void)
{
    LOG_D("beep show error low.");
    beep_stop();
    agile_led_set_light_mode(led_beep, VALUE_BEEP_SHOW_ERR_LV_LOW, 1);
    return agile_led_start(led_beep);
}

int beep_show_err_mid(void)
{
    LOG_D("beep show error high.");
    beep_stop();
    agile_led_set_light_mode(led_beep, VALUE_BEEP_SHOW_ERR_LV_MID, -1);
    return agile_led_start(led_beep);
}

int beep_show_err_high(void)
{
    LOG_D("beep show error high.");
    beep_stop();
    agile_led_set_light_mode(led_beep, VALUE_BEEP_SHOW_ERR_LV_HIGH, -1);
    return agile_led_start(led_beep);
}

int beep_init(void)
{
    rt_pin_mode(PIN_BEEP_OUT, PIN_MODE_OUTPUT);
    rt_pin_write(PIN_BEEP_OUT, !ACTIVE_BEEP_OUT); 
    
    led_beep = agile_led_create(PIN_BEEP_OUT, ACTIVE_BEEP_OUT, VALUE_BEEP_SHOW_ERR_LV_LOW, -1);
    return RT_EOK;
}

