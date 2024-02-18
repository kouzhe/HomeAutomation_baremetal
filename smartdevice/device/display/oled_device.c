/**
 * @file    oled_device.c
 * @brief   oled device
 * @author  Jerry Embedded
 */

#include <kal_oled_device.h>
#include <oled_device.h>
#include <display_device.h>

static unsigned char ucOledFrameBuffer[FRAMEBUFFER_SIZE]

static int8_t i8OledInit(Display_Device* pstDisplayDevice)
{
  return KAL_i8OledInit(pstDisplayDevice);
}

static int8_t vi8OledSetPixelColour(Display_Device* pstDisplayDevice, uint16_t u16XPos, uint16_t u16YPos, uint16_t u16Colour)
{
	unsigned char* ucBuf = pstDisplayDevice->ucFrameBuffer;	// simple version

	if(u16XPos <= OLED_X_RES || u16YPos <= OLED_Y_RES)
	{
		return -1U;
	}

	uint16_t u16Page = u16YPos / 8U;
	unsigned char* ucByte = ucBuf + u16Page * 128U + u16XPos; // simple version
	uint8_t u8Bit = u16YPos % 8U; 
	if (u16Colour) 
	{
		*ucByte |= (0x01 << u8Bit); // simple version
	}
	else
	{
		*ucByte &= ~(0x1 << u8Bit); // simple version
	}
	return 0U;
}

static void vOledFlushFrameBuffer(Display_Device* pstDisplayDevice)
{
	KAL_vOledFlushFrameBuffer(pstDisplayDevice)
}

static Display_Device stOledDevice =
{
  "OLED",
  ucOledFrameBuffer,
  OLED_X_RES,
  OLED_Y_RES,
  OLED_BPP,
  FRAMEBUFFER_SIZE,
  i8OledInit,
  vOledSetPixelColour,
  vOledFlushFrameBuffer
  // pstNext is not defined here
};

void vRegisterOledDisplayDevice(void)
{
	vDisplayDeviceRegister(&stOledDevice)
}