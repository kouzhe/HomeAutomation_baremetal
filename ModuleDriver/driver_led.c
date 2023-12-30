
#include "driver_led.h"
#include "main.h"


void vLedWhiteOn(void)
{
	HAL_GPIO_WritePin(LED_WHITE_GPIO_Port, LED_WHITE_Pin, GPIO_PIN_RESET);
}

void vLedWhiteOff(void)
{
	HAL_GPIO_WritePin(LED_WHITE_GPIO_Port, LED_WHITE_Pin, GPIO_PIN_SET);
}

void vLedWhiteToggle(void)
{
	HAL_GPIO_TogglePin(LED_WHITE_GPIO_Port, LED_WHITE_Pin);
}

void vLedBlueOn(void)
{
	HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_RESET);
}

void vLedBlueOff(void)
{
	HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET);
}

void vLedBlueToggle(void)
{
	HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
}

void vLedGreenOn(void)
{
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
}

void vLedGreenOff(void)
{
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
}

void vLedGreenToggle(void)
{
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}