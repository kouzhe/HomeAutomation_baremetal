/**
 * @file    kal_time.c
 * @brief   time kal
 * @author  Jerry Embedded
 */

#include "stm32f1xx_hal.h"
#include <kal_time.h>
#include <cal_time.h>

void KAL_vDelay(uint8_t u8Time_mS)
{
	CAL_vDelay(u8Time_mS);
}