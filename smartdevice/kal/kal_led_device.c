/**
 * @file    kal_driver_led.c
 * @brief   led cal
 * @author  Jerry Embedded
 */

#include <cal_led_device.h>
#include <kal_led_device.h>
#include <led_device.h>
// #include <stdbool.h>
// #include <stdint.h>

int8_t KAL_i8LedDeviceInit (struct Led_Device *pstLEDDevice)
{
	if (pstLEDDevice)
		return CAL_i8LedDeviceInit(pstLEDDevice);
}

int8_t KAL_i8LedDeviceControl (struct Led_Device *pstLEDDevice, Led_tenStatus enStatus)
{
		if ((pstLEDDevice) && (enStatus >= Led_tenStatus_Off) && (enStatus < Led_tenStatus_Max))
			return CAL_i8LedDeviceControl(pstLEDDevice, enStatus);
}
