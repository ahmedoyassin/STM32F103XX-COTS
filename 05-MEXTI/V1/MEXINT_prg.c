/*
 * MEXINT_prg.c
 *
 *  Created on: Aug 4, 2023
 *      Author: Ahmed
 */
#include "../Inc/MNVIC_cfg.h"
#include "../Inc/MNVIC_private.h"
#include "../Inc/MNVIC_interface.h"
#include "../Inc/MEXINT_cfg.h"
#include "../Inc/MEXINT_private.h"
#include "../Inc/MEXINT_interface.h"

void MEXTI_VidInit(void)
{
	#if   EXTI_MODE == EXTI_RISING_EDGE
		SET_BIT( EXTI->RTSR , EXTI_LINE );
	#elif EXTI_MODE == EXTI_FALING_EDGE
		SET_BIT( EXTI->FTSR , EXTI_LINE );
	#elif EXTI_MODE == EXTI_ON_CHANGE
		SET_BIT( EXTI->RTSR , EXTI_LINE );
		SET_BIT( EXTI->FTSR , EXTI_LINE );
	#else 
		#error "WRONG!"
	#endif
	CLR_BIT(EXTI->IMR , EXTI_LINE);
}

void MEXTI_VidEnableEXTI(u8 Copy_U8Line)
{
		SET_BIT(EXTI->IMR , Copy_U8Line);
}

void MEXTI_VidDisableEXTI(u8 Copy_U8Line)
{
		CLR_BIT(EXTI->IMR , Copy_U8Line);
}


void MEXTI_VidSwTrigger(u8 Copy_U8Line)
{
		SET_BIT(EXTI->SWIER , Copy_U8Line);
}


void MEXTI_VidSetSignalLatch(u8 Copy_U8Line , u8 Copy_u8Mode )
{
	switch(Copy_u8Mode)
	{
		case EXTI_RISING_EDGE:   SET_BIT( EXTI->RTSR , Copy_U8Line ); break;
		case EXTI_FALING_EDGE: 	 SET_BIT( EXTI->FTSR , Copy_U8Line ); break;
		case EXTI_ON_CHANGE	 :   SET_BIT( EXTI->RTSR , Copy_U8Line );
		                         SET_BIT( EXTI->FTSR , Copy_U8Line ); break;
	}
}

void MEXTI_VidSetCallBack(void (*Copy_ptr) (void) , u8 Copy_U8Line)
{
	if(Copy_ptr != NULL)
		EXTI_CallBack[Copy_U8Line] = Copy_ptr;
}


void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE0]();
	SET_BIT(EXTI->PR , EXTI_LINE0);
}

void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE1]();
	SET_BIT(EXTI->PR , EXTI_LINE1);
}

void EXTI2_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE2]();
	SET_BIT(EXTI->PR , EXTI_LINE2);
}


void EXTI3_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE3]();
	SET_BIT(EXTI->PR , EXTI_LINE3);
}

void EXTI4_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE4]();
	SET_BIT(EXTI->PR , EXTI_LINE4);
}

void EXTI5_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE5]();
	SET_BIT(EXTI->PR , EXTI_LINE5);
}


void EXTI6_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE6]();
	SET_BIT(EXTI->PR , EXTI_LINE6);
}


void EXTI7_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE7]();
	SET_BIT(EXTI->PR , EXTI_LINE7);
}

void EXTI8_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE8]();
	SET_BIT(EXTI->PR , EXTI_LINE8);
}

void EXTI9_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE9]();
	SET_BIT(EXTI->PR , EXTI_LINE9);
}

void EXTI10_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE10]();
	SET_BIT(EXTI->PR , EXTI_LINE10);
}


void EXTI11_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE11]();
	SET_BIT(EXTI->PR , EXTI_LINE11);
}

void EXTI12_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE12]();
	SET_BIT(EXTI->PR , EXTI_LINE12);
}

void EXTI13_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE13]();
	SET_BIT(EXTI->PR , EXTI_LINE13);
}

void EXTI14_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE14]();
	SET_BIT(EXTI->PR , EXTI_LINE14);
}
void EXTI15_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE15]();
	SET_BIT(EXTI->PR , EXTI_LINE15);
}
