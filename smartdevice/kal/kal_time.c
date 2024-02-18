/**
 * @file    kal_time.c
 * @brief   time kal
 * @author  Jerry Embedded
 */

#include "stm32f1xx_hal.h"
#include <kal_time.h>
#include <cal_time.h>

void KAL_vDelay(uint32_t u32Time_mS)
{
	CAL_vDelay(u32Time_mS);
}