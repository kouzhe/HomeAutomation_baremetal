/**
 * @file    cal_led_device.h
 * @brief   led cal
 * @author  Jerry Embedded
 */

#ifndef __CAL_LED_DEVICE_H
#define __CAL_LED_DEVICE_H

#include <stdbool.h>
#include <stdint.h>
#include <led_device.h>

int8_t CAL_i8LedDeviceInit (struct Led_Device *pstLEDDevice);
int8_t CAL_i8LedDeviceControl (struct Led_Device *pstLEDDevice, Led_tenStatus enStatus);

#endif /* __CAL_LED_DEVICE_H */
