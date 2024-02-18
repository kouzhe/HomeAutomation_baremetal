/**
 * @file    fan_test.c
 * @brief   fan test
 * @author  Jerry Embedded
 */

#include <fan_device.h>
#include <kal_time.h>

#define FAN_INTERVAL_MS 3000U

void vFanTest(void)
{
	Fan_Device* pstFanDevice = pstGetFanDevice();

	pstFanDevice->Init(pstFanDevice);

	while(1U)
	{
		pstFanDevice->ControlSpeed(pstFanDevice, Fan_tenMode_Forward);
		KAL_vDelay(FAN_INTERVAL_MS);
		pstFanDevice->ControlSpeed(pstFanDevice, Fan_tenMode_Halt);
		KAL_vDelay(FAN_INTERVAL_MS);
		pstFanDevice->ControlSpeed(pstFanDevice, Fan_tenMode_Backward);
		KAL_vDelay(FAN_INTERVAL_MS);
		pstFanDevice->ControlSpeed(pstFanDevice, Fan_tenMode_Halt);
		KAL_vDelay(FAN_INTERVAL_MS);
	}
}
