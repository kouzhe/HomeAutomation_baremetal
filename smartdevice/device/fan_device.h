/**
 * @file    fan_device.h
 * @brief   fan device
 * @author  Jerry Embedded
 */

#ifndef __FAN_DEVICE_H
#define __FAN_DEVICE_H

#include <stdbool.h>
#include <stdint.h>

typedef enum 
{
  Fan_tenMode_Halt = 0U,
  Fan_tenMode_Forward,
  Fan_tenMode_Backward,
  Fan_tenMode_Max,
} Fan_tenMode;

typedef struct Fan_Device
{
  Fan_tenMode enMode;
  int8_t (*Init)(struct Fan_Device *pstFanDevice);
  int8_t (*ControlSpeed)(struct Fan_Device *pstFanDevice, Fan_tenMode enMode);
}Fan_Device;

Fan_Device* pstGetFanDevice(void);

#endif /* __FAN_DEVICE_H */

