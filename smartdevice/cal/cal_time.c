/**
 * @file    cal_time.c
 * @brief   time cal
 * @author  Jerry Embedded
 */

#include "stm32f1xx_hal.h"
#include <kal_time.h>

void CAL_vDelay(uint8_t u8Time_mS)
{
	HAL_Delay(u8Time_mS); 	// 1ms per interrupt
}

uint32_t CAL_u32GetTick(void)
{
	return HAL_GetTick(); // Provides a tick value in millisecond
}
