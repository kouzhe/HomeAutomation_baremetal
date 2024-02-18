/**
 * @file    kal_fan_device.h
 * @brief   fan kal
 * @author  Jerry Embedded
 */

#ifndef __KAL_FAN_DEVICE_H
#define __KAL_FAN_DEVICE_H

#include <stdbool.h>
#include <stdint.h>
#include <fan_device.h>

int8_t KAL_i8FanDeviceInit(Fan_Device* pstFanDevice);
int8_t KAL_i8FanDeviceControlSpeed (Fan_Device *pstFanDevice, Fan_tenMode enMode);

#endif /* __KAL_FAN_DEVICE_H */
