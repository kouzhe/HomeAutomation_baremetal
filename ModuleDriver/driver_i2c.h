#ifndef __DRIVER_I2C_H
#define __DRIVER_I2C_H

#include "stm32f1xx_hal.h"

#define IO_DELAY_MS 100U

#define IO_SCL_H      HAL_GPIO_WritePin(IO_SCL_GPIO_Port, IO_SCL_Pin, GPIO_PIN_SET)
#define IO_SCL_L      HAL_GPIO_WritePin(IO_SCL_GPIO_Port, IO_SCL_Pin, GPIO_PIN_RESET)

#define IO_SDA_H      HAL_GPIO_WritePin(IO_SDA_GPIO_Port, IO_SDA_Pin, GPIO_PIN_SET)
#define IO_SDA_L      HAL_GPIO_WritePin(IO_SDA_GPIO_Port, IO_SDA_Pin, GPIO_PIN_RESET)

#define IO_SDA_IN      HAL_GPIO_ReadPin(IO_SDA_GPIO_Port, IO_SDA_Pin)

void vI2cDelay(uint32_t u8Count);
void vI2cStart(void);
void vI2cStop(void);
int8_t i8I2cGetAck(void);
void vI2cAck(void);
void vI2cNack(void);
void I2C_WriteByte(uint8_t u8Data);
int8_t I2C_ReadByte(uint8_t u8Ack);

#endif /* __DRIVER_LED_H */
