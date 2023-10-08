/*
 * SYSICK_interface.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Yassin
 */

#ifndef SYSICK_INTERFACE_H_
#define SYSICK_INTERFACE_H_

#include "MSYSTICK_private.h"


void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );
void MSTK_voidSetSingleInterval  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetPeriodicInterval( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_U32GetCountedTicks(void);
void SysTick_Handler(void);
void FUNC(void);

#endif /* SYSICK_INTERFACE_H_ */
