/**
 * @file    driver_fan.c
 * @brief   fan driver
 * @author  Jerry Embedded
 */

#include "main.h"
#include "driver_fan.h"
#include <fan_device.h>

int8_t HAL_i8FanDeviceInit(Fan_Device* pstFanDevice)
{
	static uint8_t u8Flag = 0U; // allow to be init 1 time

	if(!pstFanDevice)
		return -1U;

	if (u8Flag == 0U)
	{
		GPIO_InitTypeDef GPIO_InitStruct = {0};

		/* GPIO Ports Clock Enable */
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOF_CLK_ENABLE();

		/*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);

		/*Configure GPIO pins : PFPin PFPin PFPin */
		GPIO_InitStruct.Pin = FAN_INA_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(FAN_INA_GPIO_Port, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = FAN_INB_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(FAN_INB_GPIO_Port, &GPIO_InitStruct);

		u8Flag = 1U;
		return 0U;
	}
	else
		return 1U; // not 1st time
}

int8_t HAL_i8FanDeviceControlSpeed (Fan_Device *pstFanDevice, Fan_tenMode enMode)
{
	if(!pstFanDevice)
		return -1U;

	pstFanDevice->enMode = enMode;

	switch (pstFanDevice->enMode)
	{
		case Fan_tenMode_Halt:
			HAL_GPIO_WritePin(FAN_INA_GPIO_Port, FAN_INA_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(FAN_INB_GPIO_Port, FAN_INB_Pin, GPIO_PIN_RESET);
			break;
		case Fan_tenMode_Forward:
			HAL_GPIO_WritePin(FAN_INA_GPIO_Port, FAN_INA_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(FAN_INB_GPIO_Port, FAN_INB_Pin, GPIO_PIN_SET);
			break;
		case Fan_tenMode_Backward:
			HAL_GPIO_WritePin(FAN_INA_GPIO_Port, FAN_INA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(FAN_INB_GPIO_Port, FAN_INB_Pin, GPIO_PIN_RESET);
			break;
		default:
			return -1U; // error mode
			break; 
	}
	return 0U;
}