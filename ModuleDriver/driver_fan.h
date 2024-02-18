/**
 * @file    driver_fan.h
 * @brief   fan driver.
 * @author  Jerry Embedded
 */

#ifndef __DRIVER_FAN_H
#define __DRIVER_FAN_H

#include <stdbool.h>
#include <stdint.h>
#include <fan_device.h>

int8_t HAL_i8FanDeviceInit(Fan_Device* pstFanDevice);
int8_t HAL_i8FanDeviceControlSpeed (Fan_Device *pstFanDevice, Fan_tenMode enMode);

#endif /* __DRIVER_FAN_H */
