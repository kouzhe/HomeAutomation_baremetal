/**
 * @file    driver_fan.c
 * @brief   fan driver
 * @author  Jerry Embedded
 */

#include <kal_fan_device.h>
#include <fan_device.h>

int8_t i8FanDeviceInit (struct Fan_Device *pstFanDevice)
{
	if (pstFanDevice)
		return KAL_i8FanDeviceInit(pstFanDevice);
}

int8_t i8FanDeviceControlSpeed (struct Fan_Device *pstFanDevice, Fan_tenMode enMode)
{
		if ((pstFanDevice) && (enMode < Fan_tenMode_Max))
			return KAL_i8FanDeviceControlSpeed(pstFanDevice, enMode);
}

static Fan_Device stFan_Device =
{
	Fan_tenMode_Halt, 
	i8FanDeviceInit, 
	i8FanDeviceControlSpeed
};

Fan_Device* pstGetFanDevice(void)
{
	return &stFan_Device;
}