/**
 * @file    led_device.h
 * @brief   led device
 * @author  Jerry Embedded
 */

#ifndef __LED_DEVICE_H
#define __LED_DEVICE_H

#include <stdbool.h>
#include <stdint.h>

typedef enum 
{
  Led_tenColour_White = 0U,
  Led_tenColour_Green,
  Led_tenColour_Blue,
  Led_tenColour_Max,
} Led_tenColour;

typedef enum 
{
  Led_tenStatus_Off = 0U,
  Led_tenStatus_On,
  Led_tenStatus_Toogle,
  Led_tenStatus_Max,
} Led_tenStatus;

typedef struct Led_Device
{
  Led_tenColour enColour;
  Led_tenStatus enStatus;
  int8_t (*Init)(struct Led_Device *pstLEDDevice);
  int8_t (*Control)(struct Led_Device *pstLEDDevice, Led_tenStatus enStatus);
}Led_Device, *PLEDDevice;

PLEDDevice pstGetLedDevice(Led_tenColour enColour);

#endif /* __LED_DEVICE_H */

