/**
 * @file    oled_device.h
 * @brief   oled device: instant of "display_device"
 * @author  Jerry Embedded
 */

#ifndef __OLED_DEVICE_H
#define __OLED_DEVICE_H

#include <stdbool.h>
#include <stdint.h>

#define OLED_X_RES 128U 
#define OLED_Y_RES 64U
#define OLED_BPP 1U
#define FRAMEBUFFER_SIZE (OLED_X_RES * OLED_Y_RES * OLED_BPP / 8U)

void vRegisterOledDisplayDevice(void);

#endif /* __OLED_DEVICE_H */

