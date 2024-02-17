/**
 * @file    driver_led.h
 * @brief   led driver.
 * @author  Jerry Embedded
 */

#ifndef __DRIVER_LED_H
#define __DRIVER_LED_H

#include <stdbool.h>
#include <stdint.h>
#include <led_device.h>

int8_t HAL_i8LedDeviceInit (struct Led_Device *pstLEDDevice);
int8_t HAL_i8LedDeviceControl (struct Led_Device *pstLEDDevice, Led_tenStatus enStatus);

#endif /* __DRIVER_LED_H */
