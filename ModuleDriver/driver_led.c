/**
 * @file    driver_led.c
 * @brief   led driver
 * @author  Jerry Embedded
 */

#include "driver_led.h"
#include "main.h"
#include <led_device.h>

int8_t HAL_i8LedDeviceInit (struct Led_Device *pstLEDDevice)
{
	static uint8_t u8Flag = 0U; // allow to be init 1 time

	if (!pstLEDDevice)
	{
		GPIO_InitTypeDef GPIO_InitStruct = {0};

		/* GPIO Ports Clock Enable */
		__HAL_RCC_GPIOF_CLK_ENABLE();

		/*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(GPIOF, LED_WHITE_Pin|LED_BLUE_Pin|LED_GREEN_Pin, GPIO_PIN_SET);

		/*Configure GPIO pins : PFPin PFPin PFPin */
		GPIO_InitStruct.Pin = LED_WHITE_Pin|LED_BLUE_Pin|LED_GREEN_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

		u8Flag = 1U;
		return 0U;
	}
	else
		return -1U;
}

int8_t HAL_i8LedDeviceControl (struct Led_Device *pstLEDDevice, Led_tenStatus enStatus)
{
	  // avoid to use HAL_GPIO_TogglePin
		GPIO_PinState PinState;

		if(!pstLEDDevice)
			return -1U;

		if (enStatus == Led_tenStatus_Toogle)
		{
			enStatus = !(pstLEDDevice->enStatus);
		}

		PinState = enStatus ? GPIO_PIN_RESET : GPIO_PIN_SET;  
		pstLEDDevice->enStatus = enStatus; 

		switch (pstLEDDevice->enColour)
		{
			case Led_tenColour_White:
				HAL_GPIO_WritePin(LED_WHITE_GPIO_Port, LED_WHITE_Pin, PinState);
				break;
			case Led_tenColour_Green:
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, PinState);
				break;
			case Led_tenColour_Blue:
				HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, PinState);
				break;
			default:
				return -1U; // error colour
				break; 
		}
		return 0U;
}