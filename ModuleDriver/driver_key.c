
#include "driver_key.h"
#include "main.h"

uint8_t u8PollKey1GetState(void)
{
	if (KEY1_READ == 0U)
	{
		HAL_Delay(100U);
		if (KEY1_READ == 0U)
			return 0U; // key pressed
		else
		{
			return 1U; // key released
		}
	}
	else
	{
		return 1U; // not pressed
	}
}

uint8_t u8PollKey2GetState(void)
{
	if (KEY2_READ == 0U)
	{
		HAL_Delay(100U);
		if (KEY2_READ == 0U)
			return 0U; // key pressed
		else
		{
			return 1U; // key released
		}
	}
	else
	{
		return 1U; // not pressed
	}
}
