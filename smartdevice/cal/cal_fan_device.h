/**
 * @file    cal_fan_device.h
 * @brief   fan cal
 * @author  Jerry Embedded
 */

#ifndef __CAL_FAN_DEVICE_H
#define __CAL_FAN_DEVICE_H

#include <stdbool.h>
#include <stdint.h>
#include <fan_device.h>

int8_t CAL_i8FanDeviceInit(Fan_Device* pstFanDevice);
int8_t CAL_i8FanDeviceControlSpeed (Fan_Device *pstFanDevice, Fan_tenMode enMode);

#endif /* __CAL_FAN_DEVICE_H */
