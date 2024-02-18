/**
 * @file    display_device.h
 * @brief   display device
 * @author  Jerry Embedded
 */

#ifndef __DISPLAY_DEVICE_H
#define __DISPLAY_DEVICE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct Display_Device
{
  unsigned char* ucName;
  unsigned char* ucFrameBuffer; // Framebuffer
  uint8_t u8XRes; // X Resolution
  uint8_t u8YRes; // Y Resolution
  uint8_t u8Bpp;  // bits per pixel
  uint16_t u16Size;
  int8_t (*Init)(Display_Device* pstDisplayDevice);
  void (*SetPixelColour)(Display_Device* pstDisplayDevice, uint16_t u16XPos, uint16_t u16YPos, uint16_t u16Colour); // Set "u16Colour" into ucFrameBuffer, u16Colour format: 0x00RRGGBB
  void (*FlushFrameBuffer)(Display_Device *pstDisplayDevice); // Flush "ucFrameBuffer" into HW
  Display_Device* pstNext;
}Display_Device;

void vDisplayDeviceRegister(Display_Device* pstDisplayDevice);

#endif /* __DISPLAY_DEVICE_H */
