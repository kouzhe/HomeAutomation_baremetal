#ifndef __DRIVER_KEY_H
#define __DRIVER_KEY_H

#include "stm32f1xx_hal.h"

#define KEY1_READ      HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define KEY2_READ      HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)

uint8_t u8PollKey1GetState(void);
uint8_t u8PollKey2GetState(void);

#endif /* __DRIVER_LED_H */
