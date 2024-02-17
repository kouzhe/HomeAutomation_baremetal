/**
 * @file    kal_led_device.h
 * @brief   led kal
 * @author  Jerry Embedded
 */

#ifndef __KAL_LED_DEVICE_H
#define __KAL_LED_DEVICE_H

#include <stdbool.h>
#include <stdint.h>
#include <led_device.h>

int8_t KAL_i8LedDeviceInit (struct Led_Device *pstLEDDevice);
int8_t KAL_i8LedDeviceControl (struct Led_Device *pstLEDDevice, Led_tenStatus enStatus);

#endif /* __KAL_LED_DEVICE_H */
