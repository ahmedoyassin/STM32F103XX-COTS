/*
 * SYSICK_prg.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Yassin
 */

#include <../Inc/MSYSTICK_interface.h>
#include "../Inc/MSYSTICK_cfg.h"
#include "../Inc/MGPIO_interface.h"

u8 Copy_U8STKIntervalFlag =0;
void (*Copy_ptr_Callback_func) (void); //CallBack Function

void MSTK_voidInit(void)
{
#if MSYSTICK_CLK_SOURCE == MSYSTICK_SOURCE_AHB_by_8
	STK-> CTRL = MSTK_CTRL(CLK_SRC_OFF,INT_SRC_OFF,ENABLE_SRC_OFF);
#elif MSYSTICK_CLK_SOURCE == MSYSTICK_SOURCE_AHB
	STK-> CTRL = MSTK_CTRL(CLK_SRC_ON,INT_SRC_OFF,ENABLE_SRC_OFF);
#endif
}

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	STK->LOAD = (Copy_u32Ticks *1000);
	STK->CTRL = MSTK_CTRL(CLK_SRC_OFF,INT_SRC_OFF,ENABLE_SRC_ON);
	while(!GET_BIT(STK->CTRL,16));
	STK->CTRL = MSTK_CTRL(CLK_SRC_OFF,INT_SRC_OFF,ENABLE_SRC_OFF);
	STK->LOAD = 0x00000000U;
	STK -> VAL =0x00000000U;
}

void MSTK_voidSetSingleInterval  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	STK->VAL = 0x00000000;
	STK->LOAD = (Copy_u32Ticks *1000);
	Copy_ptr_Callback_func= Copy_ptr;
	Copy_U8STKIntervalFlag =1;
	STK->CTRL = MSTK_CTRL(CLK_SRC_OFF,INT_SRC_ON,ENABLE_SRC_ON);

}

void MSTK_voidSetPeriodicInterval( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	STK->LOAD = (Copy_u32Ticks -1) *1000;
	Copy_ptr_Callback_func= Copy_ptr;
	Copy_U8STKIntervalFlag =1;
	STK->CTRL = MSTK_CTRL(CLK_SRC_OFF,INT_SRC_ON,ENABLE_SRC_ON);
}

void MSTK_voidStopInterval(void)
{
	STK->CTRL = MSTK_CTRL(CLK_SRC_OFF,INT_SRC_OFF,ENABLE_SRC_OFF);
	STK-> LOAD = 0x00000000;
	STK -> VAL = 0x00000000;
}

u32  MSTK_u32GetElapsedTime(void)
{
	return ((STK->LOAD) - (STK->VAL));
}

u32  MSTK_U32GetCountedTicks(void) //Counts the function time
{
	return STK->VAL;
}

void SysTick_Handler(void)
{
	Copy_ptr_Callback_func();

		if(!Copy_U8STKIntervalFlag)
		{
			STK->CTRL = MSTK_CTRL(CLK_SRC_OFF,INT_SRC_OFF,ENABLE_SRC_OFF);
			STK->LOAD =0x00000000;
			STK->VAL = 0x00000000;
		}
		CLR_BIT(STK->CTRL,16);
}
