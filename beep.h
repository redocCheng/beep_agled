/*
 * Copyright (c) 2019-2020, redoc
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-08-14     redoc        the first version
 */

#ifndef __BEEP_H
#define __BEEP_H


#include "rtthread.h"

int beep_init(void);
int beep_stop(void);
int beep_show_err_low(void);
int beep_show_err_mid(void);
int beep_show_err_high(void);

#endif
