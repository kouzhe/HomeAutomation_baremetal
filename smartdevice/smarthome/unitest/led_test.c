/**
 * @file    led_test.c
 * @brief   led test
 * @author  Jerry Embedded
 */

#include <led_device.h>
#include <kal_time.h>

void vLedTest(void)
{
	PLEDDevice pstLedDeviceWhite = pstGetLedDevice(Led_tenColour_White);
	PLEDDevice pstLedDeviceGreen = pstGetLedDevice(Led_tenColour_Green);
	PLEDDevice pstLedDeviceBlue  = pstGetLedDevice(Led_tenColour_Blue);

	pstLedDeviceWhite->Init(pstLedDeviceWhite);
	pstLedDeviceGreen->Init(pstLedDeviceGreen);
	pstLedDeviceBlue->Init(pstLedDeviceBlue);

	while(1U)
	{
		pstLedDeviceWhite->Control(pstLedDeviceWhite,Led_tenStatus_On);
		pstLedDeviceGreen->Control(pstLedDeviceGreen,Led_tenStatus_On);
		pstLedDeviceBlue->Control(pstLedDeviceBlue,Led_tenStatus_On);
		KAL_vDelay(500U);
		pstLedDeviceWhite->Control(pstLedDeviceWhite,Led_tenStatus_Off);
		pstLedDeviceGreen->Control(pstLedDeviceGreen,Led_tenStatus_Off);
		pstLedDeviceBlue->Control(pstLedDeviceBlue,Led_tenStatus_Off);
		KAL_vDelay(500U);
	}
}
