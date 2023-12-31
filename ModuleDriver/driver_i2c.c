
#include "driver_i2c.h"
#include "main.h"

void vI2cDelay(uint32_t u8Count)
{
	volatile uint32_t u8Counter = u8Count;
	// while (u8Counter != 0U) // blocking
	// {
	// 	u8Counter --;
	// }
	while (u8Counter --); // blocking
}

// falling edge of SDA, SCL_H
void vI2cStart(void)
{
	IO_SDA_H; // can swap sequence
	IO_SCL_H;
	vI2cDelay(IO_DELAY_MS);
	IO_SDA_L;
	vI2cDelay(IO_DELAY_MS);
}

// rising edge of SDA, SCL_H
void vI2cStop(void)
{
	IO_SDA_L;
	IO_SCL_H;
	vI2cDelay(IO_DELAY_MS);
	IO_SDA_H;
	vI2cDelay(IO_DELAY_MS);
}

// get ack from slave
// SDA_IN = 0, get ack success
int8_t i8I2cGetAck(void)
{
	uint8_t u8Timer = 0U;
	IO_SCL_L; // bug fixed (sequence)
	IO_SDA_H; // free SDA
	vI2cDelay(IO_DELAY_MS);
	IO_SCL_H;
	while (IO_SDA_IN != 0U)
	{
		u8Timer++;
		if (u8Timer == 100U) // bug fixed 1000U, power cycle & hw reset issue
		{
			IO_SCL_L;
			return -1;
		}
		vI2cDelay(10); // bug fixed (issue)
	}
	IO_SCL_L;
	return 0;
}

// generate ack from master: ACK = 0 (1 clock cycle)
void vI2cAck(void)
{
	// IO_SDA_L; // ACK=0
	// IO_SCL_L;
	// vI2cDelay(IO_DELAY_MS);
	// IO_SCL_H;
	// vI2cDelay(IO_DELAY_MS);
	IO_SCL_L;
	IO_SDA_L; // ACK=0
	vI2cDelay(IO_DELAY_MS);
	IO_SCL_H;
	vI2cDelay(IO_DELAY_MS);
}

// generate ack from master: nACK = 1 (1 clock cycle)
void vI2cNack(void)
{
	// IO_SDA_H; // ACK=1
	// IO_SCL_L;
	// vI2cDelay(IO_DELAY_MS);
	// IO_SCL_H;
	// vI2cDelay(IO_DELAY_MS);
	IO_SCL_L;
	IO_SDA_H; // ACK=1
	vI2cDelay(IO_DELAY_MS);
	IO_SCL_H;
	vI2cDelay(IO_DELAY_MS);
}

// master: write byte (1st bit = MSB)
void I2C_WriteByte(uint8_t u8Data)
{
	for (uint8_t u8i = 0U; u8i < 8U; u8i++)
	{
			IO_SCL_L;
			// vI2cDelay(IO_DELAY_MS); // bug fix (add)
			if (u8Data & (1<<7)) // 0x80  (1<<7)
			{
				IO_SDA_H;
			}
			else
			{
				IO_SDA_L;
			}
			u8Data = u8Data<<1;
			vI2cDelay(IO_DELAY_MS); // bug fix (remove)
			IO_SCL_H;
			vI2cDelay(IO_DELAY_MS);
	}
	i8I2cGetAck();
}

// master: read byte (1st byte = MSB)
int8_t I2C_ReadByte(uint8_t u8Ack)
{
	// int8_t u8Data = 0U;
	// for (uint8_t u8i = 0U; u8i < 8U; u8i++)
	// {
	// 		IO_SCL_L;
	// 		vI2cDelay(IO_DELAY_MS);
	// 		IO_SCL_H;
	// 		if (IO_SDA_IN == 1U)
	// 		{
	// 			u8Data = (u8Data | 0x01)<<1;
	// 		}
	// 		else
	// 		{
	// 			u8Data = u8Data<<1;
	// 		}
	// 		vI2cDelay(IO_DELAY_MS);
	// }
	// if (u8Ack == 0U)
	// 	vI2cAck();
	// else if (u8Ack == 1U)
	// 	vI2cNack();

	// return u8Data;

	int8_t u8Data = 0U;
	IO_SDA_H;
	for (uint8_t u8i = 0U; u8i < 8U; u8i++)
	{
			IO_SCL_L;
			vI2cDelay(IO_DELAY_MS);
			IO_SCL_H;
			vI2cDelay(IO_DELAY_MS);
			u8Data = u8Data<<1;
			if (IO_SDA_IN == 1U)
			{
				u8Data++;
			}
			else
			{
				u8Data = u8Data;
			}
	}
	
	if (u8Ack == 0U)
		vI2cAck();
	else if (u8Ack == 1U)
		vI2cNack();

	return u8Data;
}

void I2C_GPIO_ReInit(void)
{
    /* 1. 使用结构体定义硬件GPIO对象 */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    /* 2. 将SCL和SDA的GPIO寄存器的值恢复为复位上电值 */
    HAL_GPIO_DeInit(IO_SCL_GPIO_Port, IO_SCL_Pin);
    HAL_GPIO_DeInit(IO_SDA_GPIO_Port, IO_SDA_Pin);
    
    /* 3. 使能SCL和SDA的GPIO的时钟，因为他们都是GPIOF组的，所以这里只使能GPIOF的时钟 */
    __HAL_RCC_GPIOF_CLK_ENABLE();
    
    /* 4. 设置GPIO的模式为开漏输出模式，响应速度设置为快速响应 */
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        
    /* 5. 选择要设置的GPIO引脚 */
    GPIO_InitStruct.Pin = IO_SCL_Pin;
    
    /* 6. 调用init函数初始化GPIO */
    HAL_GPIO_Init(IO_SCL_GPIO_Port, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = IO_SDA_Pin;
    HAL_GPIO_Init(IO_SDA_GPIO_Port, &GPIO_InitStruct);
}
