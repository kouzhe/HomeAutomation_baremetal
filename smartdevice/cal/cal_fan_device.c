/**
 * @file    cal_driver_led.c
 * @brief   fan cal
 * @author  Jerry Embedded
 */

#include <cal_fan_device.h>
#include <driver_fan.h>
#include <fan_device.h>

int8_t CAL_i8FanDeviceInit(Fan_Device* pstFanDevice)
{
	if (pstFanDevice)
		return HAL_i8FanDeviceInit(pstFanDevice);
}

int8_t CAL_i8FanDeviceControlSpeed (Fan_Device *pstFanDevice, Fan_tenMode enMode)
{
		if ((pstFanDevice) && (enMode < Fan_tenMode_Max))
			return HAL_i8FanDeviceControlSpeed(pstFanDevice, enMode);
}
