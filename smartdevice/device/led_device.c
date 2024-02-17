/**
 * @file    driver_led.c
 * @brief   led driver
 * @author  Jerry Embedded
 */

#include <kal_led_device.h>
#include <led_device.h>

int8_t i8LedDeviceInit (struct Led_Device *pstLEDDevice)
{
	if (!pstLEDDevice)
		return KAL_i8LedDeviceInit(pstLEDDevice);
}

int8_t i8LedDeviceControl (struct Led_Device *pstLEDDevice, Led_tenStatus enStatus)
{
		if ((!pstLEDDevice) && (enStatus >= Led_tenStatus_Off) && (enStatus < Led_tenStatus_Max))
			return KAL_i8LedDeviceControl(pstLEDDevice, enStatus);
}

static Led_Device stLed_Device[Led_tenStatus_Max] =
{
	{Led_tenColour_White, Led_tenStatus_Off, i8LedDeviceInit, i8LedDeviceControl},
	{Led_tenColour_Green, Led_tenStatus_Off, i8LedDeviceInit, i8LedDeviceControl},
	{Led_tenColour_Blue,  Led_tenStatus_Off, i8LedDeviceInit, i8LedDeviceControl},
};

PLEDDevice pstGetLedDevice(Led_tenColour enColour)
{
	PLEDDevice pstGetLedDevice = 0U;
	if ((enColour>= Led_tenColour_White) && (enColour < Led_tenColour_Max))
	{
		pstGetLedDevice = &(stLed_Device[enColour]);
		return pstGetLedDevice;
	}
}