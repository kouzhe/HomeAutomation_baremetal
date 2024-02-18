/**
 * @file    ring_buffer.h
 * @brief   ring buffer (byte) driver.
 * @author  Jerry Embedded
 */

#ifndef __RING_BUFFER_H
#define __RING_BUFFER_H

#include <stdbool.h>
#include <stdint.h>

#define RING_BUFFER_SIZE 256U

typedef struct
{
  unsigned char ucBuffer[RING_BUFFER_SIZE];
  volatile uint16_t u16RIndex; // Read Index (volatile)
  volatile uint16_t u16WIndex; // Write Index (volatile)
} RingBuffer;

void vRingBufferInit(RingBuffer* pRingBuffer);
void vRingBufferWriteByte(RingBuffer* pRingBuffer, unsigned char ucSrc);
int8_t vRingBufferReadByte(RingBuffer* pRingBuffer, unsigned char* pcDstBuffer);

#endif /* __RING_BUFFER_H */
