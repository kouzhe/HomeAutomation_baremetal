/**
 * @file    driver_led.c
 * @brief   led driver
 * @author  Jerry Embedded
 */

#include <kal_display_device.h>
#include <display_device.h>

static Display_Device* pstDisplayDeviceList; // Display Device List

// Register multiple display device
void vDisplayDeviceRegister(Display_Device* pstDisplayDevice)
{
	pstDisplayDevice->pstNext = pstDisplayDeviceList;
	pstDisplayDeviceList = pstDisplayDevice;
}

Display_Device* pstGetDisplayDevice(unsigned char* ucName)
{
	Display_Device* pstList = pstDisplayDeviceList; // Note: have to add "pstList", not affect original "pstDisplayDeviceList" 
	while(pstList)
	{
		if(strstr(pstDisplayDeviceList->ucName, ucName) == 0U)
		{
			return pstList;
		}
		else
		{
			pstList = pstList->pstNext;
		}
	}

	return NULL; // "not found"
}

