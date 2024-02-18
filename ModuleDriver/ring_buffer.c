/**
 * @file    ring_buffer.c
 * @brief   ring_buffer (byte) driver
 * @author  Jerry Embedded
 */

#include <stdio.h>
#include <string.h>
#include "ring_buffer.h"
#include "main.h"

void vRingBufferInit(RingBuffer* pRingBuffer)
{
	if(pRingBuffer)
	{
		memset(pRingBuffer, 0U, sizeof(RingBuffer));
		// pRingBuffer->u16WIndex = 0U;
		// pRingBuffer->u16RIndex = 0U;
	}
}

void vRingBufferWriteByte(RingBuffer* pRingBuffer, unsigned char ucSrc)
{
	uint16_t u16WriteNext = (pRingBuffer->u16WIndex + 1) % RING_BUFFER_SIZE; // Note: RING_BUFFER_SIZE limited range
	if (u16WriteNext != pRingBuffer->u16RIndex) // cond: buffer is not full
	{
		pRingBuffer->ucBuffer[pRingBuffer->u16WIndex] = ucSrc;
		pRingBuffer->u16WIndex = u16WriteNext; // increment
	}
}

int8_t vRingBufferReadByte(RingBuffer* pRingBuffer, unsigned char* pcDstBuffer)
{
	if(pRingBuffer->u16RIndex == pRingBuffer->u16WIndex) // cond: buffer is empty
	{
		return -1U;
	}
	else
	{
		*pcDstBuffer = pRingBuffer->ucBuffer[pRingBuffer->u16RIndex];
		pRingBuffer->u16RIndex = (pRingBuffer->u16RIndex + 1U)%RING_BUFFER_SIZE; // increment (RING_BUFFER_SIZE)
		return 0U;
	}
}
