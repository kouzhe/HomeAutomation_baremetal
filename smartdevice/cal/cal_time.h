/**
 * @file    cal_time.h
 * @brief   led cal
 * @author  Jerry Embedded
 */

#ifndef __CAL_TIME_H
#define __CAL_TIME_H

#include <stdbool.h>
#include <stdint.h>

void CAL_vDelay(uint8_t u8Time_mS);
uint32_t CAL_u32GetTick(void);

#endif /* __CAL_TIME_H */