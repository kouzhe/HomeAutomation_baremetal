/**
 * @file    cal_driver_led.c
 * @brief   led cal
 * @author  Jerry Embedded
 */

#include <driver_led.h>
#include <cal_led_device.h>
#include <led_device.h>

int8_t CAL_i8LedDeviceInit (struct Led_Device *pstLEDDevice)
{
	if (!pstLEDDevice)
		return HAL_i8LedDeviceInit(pstLEDDevice);
}

int8_t CAL_i8LedDeviceControl (struct Led_Device *pstLEDDevice, Led_tenStatus enStatus)
{
		if ((!pstLEDDevice) && (enStatus > Led_tenStatus_Off) && (enStatus < Led_tenStatus_Max))
			return HAL_i8LedDeviceControl(pstLEDDevice, enStatus);
}