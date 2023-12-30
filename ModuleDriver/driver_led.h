#ifndef __DRIVER_LED_H
#define __DRIVER_LED_H

#define LED_WHITE_ON()       HAL_GPIO_WritePin(LED_WHITE_GPIO_Port, LED_WHITE_Pin, 0)
#define LED_WHITE_OFF()      HAL_GPIO_WritePin(LED_WHITE_GPIO_Port, LED_WHITE_Pin, 1)
#define LED_BLUE_ON()        HAL_GPIO_WritePin(LED_BLUE_GPIO_Port,  LED_BLUE_Pin,  0)
#define LED_BLUE_OFF()       HAL_GPIO_WritePin(LED_BLUE_GPIO_Port,  LED_BLUE_Pin,  1)
#define LED_GREEN_ON()       HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0)
#define LED_GREEN_OFF()      HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1)

void vLedWhiteOn(void);
void vLedWhiteOff(void);
void vLedWhiteToggle(void);
void vLedBlueOn(void);
void vLedBlueOff(void);
void vLedBlueToggle(void);
void vLedGreenOn(void);
void vLedGreenOff(void);
void vLedGreenToggle(void);

#endif /* __DRIVER_LED_H */
