/*
 * NVIC_prg.c
 *
 *  Created on: Jul 29, 2023
 *      Author: Yassin
 */

#include "../Inc/MNVIC_interface.h"

void MNVIC_VidInit(void)
{
	SCB-> AIRCR = PRIGROUP;
}

void MNVIC_Piriorty_Set(s8 INT_ID, u8 Copy_U8Priority)
{
	NVIC -> IP[INT_ID]= Copy_U8Priority<<4;
}

u32 MNVIC_GetPriority (s8 INT_ID)
{
	return NVIC -> IP[INT_ID];
}

void MNVIC_VidPerhiralEnable(u8 Copy_U8ISER_ID)
{
	NVIC -> ISER[Copy_U8ISER_ID/32] = (1<<(Copy_U8ISER_ID % 32));
}
void MNVIC_VidPerhiralDisable(u8 Copy_U8ISER_ID)
{
	NVIC -> ICER[Copy_U8ISER_ID/32] = (1<<(Copy_U8ISER_ID % 32));
}
void MNVIC_VidSetPending(u8 Copy_U8ISER_ID)
{
	NVIC -> ISPR[Copy_U8ISER_ID/32] = (1<<(Copy_U8ISER_ID % 32));
}
void MNVIC_VidClearPending(u8 Copy_U8ISER_ID)
{
	NVIC -> ICPR[Copy_U8ISER_ID/32] = (1<<(Copy_U8ISER_ID % 32));
}
u8 MNVIC_U8ReadActiveBit(u8 Copy_U8ISER_ID)
{
	return (GET_BIT(NVIC -> IABR[Copy_U8ISER_ID/32],(Copy_U8ISER_ID % 32)));
}

void NVIC_SystemReset(void)
{
	SET_BIT(SCB_AIRCR,2);
}