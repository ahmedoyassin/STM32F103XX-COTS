/*
 * MRCC_prg.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#include "../Inc/MRCC_interface.h"
#include "../Inc/MRCC_cfg.h"

void RCC_voidInitializeSystemClock(void)
{
	/* Configure Enable Clock source */
	#if RCC_CLOCK_SOURCE == RCC_HSI
		SET_BIT(RCC_CR ,RCC_HSI_ON);
		CLR_BIT(RCC_CR ,RCC_HSE_ON);
		CLR_BIT(RCC_CR ,RCC_PLL_ON);

	#elif RCC_CLOCK_SOURCE == RCC_HSE
		CLR_BIT(RCC_CR ,RCC_HSI_ON);
		SET_BIT(RCC_CR ,RCC_HSE_ON);
		CLR_BIT(RCC_CR ,RCC_PLL_ON);

		/* Configure HSE type */
	#if RCC_HSE_TYPE == RCC_RC
		SET_BIT(RCC_CR , RCC_HSE_BYP);

	#elif RCC_HSE_TYPE == RCC_CRYSTAL
		CLR_BIT(RCC_CR , RCC_HSE_BYP);
	#else
		#error("You Choose Wrong HSE type")
	#endif

	#elif RCC_CLOCK_SOURCE == RCC_PLL
	#if RCC_PLL_ENTRY_CLOCK_SOURCE == RCC_HSI_DIV_BY_2
		CLR_BIT(RCC_CFGR , RCC_PLLSRC);

	#elif RCC_PLL_ENTRY_CLOCK_SOURCE == RCC_HSE
		SET_BIT(RCC_CFGR , RCC_PLLSRC);

	#if RCC_HSE_DIV_FOR_PLL_ENTRY == RCC_HSE_NOT_DIV
		CLR_BIT(RCC_CFGR , RCC_PLLXTPRE);
	#elif RCC_HSE_DIV_FOR_PLL_ENTRY == RCC_HSE_DIV_BY_2
		SET_BIT(RCC_CFGR , RCC_PLLXTPRE);
	#else
		#error("You Choose Wrong HSE divider for PLL entry")
	#endif
	#else
		#error("You Choose Wrong PLL entry clock source")
	#endif

		RCC_CFGR &= RCC_PLL_MUL_MASK;
		RCC_CFGR |= RCC_PLL_MUL_FACTOR;
		CLR_BIT(RCC_CR ,RCC_HSI_ON);
		CLR_BIT(RCC_CR ,RCC_HSE_ON);
		SET_BIT(RCC_CR ,RCC_PLL_ON);
	#else
		#error("You Choose Wrong Enable Clock source type")
	#endif

		/* Configure Clock security system */
	#if CLOCK_SECURITY_SYSTEM == RCC_CSS_ENABLE
		SET_BIT(RCC_CR , RCC_CSS_ON);

	#elif CLOCK_SECURITY_SYSTEM == RCC_CSS_DISABLE
		CLR_BIT(RCC_CR , RCC_CSS_ON);
	#else
		#error("You Choose Wrong Clock security system")
	#endif

		RCC_CR &= RCC_HSITRIM_MASK;
		RCC_CR |= RCC_HSI_CLOCK_TRIMMING;

		RCC_CFGR &= RCC_HCLK_APB2_PRESCALER_MASK;
	    RCC_CFGR |= RCC_APB_HIGH_SPEED_PRESCALER;

		RCC_CFGR &= RCC_HCLK_APB1_PRESCALER_MASK;
	    RCC_CFGR |= RCC_APB_LOW_SPEED_PRESCALER;

		RCC_CFGR &= RCC_AHB_PRESCALER_MASK;
	    RCC_CFGR |= RCC_AHP_PRESCALER;

		RCC_CFGR &= RCC_SW_MASK;
	    RCC_CFGR |= RCC_SYSTEM_CLOCK;
}

void RCC_voidResetPeripheral(u8 local_busId, u8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case RCC_APB1 : SET_BIT(RCC_APB1RSTR, local_peripheralId);break;
			case RCC_APB2 : SET_BIT(RCC_APB2RSTR, local_peripheralId);break;
		}}}

void RCC_voidEnablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR, Copy_u8PerId);break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR, Copy_u8PerId);break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR, Copy_u8PerId);break;
		}}}
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  : CLEAR_BIT(RCC_AHBENR, Copy_u8PerId);break;
			case RCC_APB1 : CLEAR_BIT(RCC_APB1ENR, Copy_u8PerId);break;
			case RCC_APB2 : CLEAR_BIT(RCC_APB2ENR, Copy_u8PerId);break;
		}}}
