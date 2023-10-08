/*
 * MRCC_prg.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#include "../Inc/MRCC_interface.h"

void RCC_voidInitializeSystemClock(void)
{
	#if CLOCK_SELECTION == HSE
	RCC -> CR   = 0x00010000;
    //SET_BIT(RCC -> CR, HSE_ON);
	RCC -> CFGR = 0x00000001;

	   #elif CLOCK_SELECTION == HSI
	    RCC -> CR   = 0x00000081;
	    RCC -> CFGR = 0x00000000;



	#elif CLOCK_SELECTION == PLL

	#else

	#endif
}

void RCC_voidResetPeripheral(u8 local_busId, u8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case RCC_APB1 : SET_BIT(RCC -> APB1RSTR, local_peripheralId);break;
			case RCC_APB2 : SET_BIT(RCC -> APB2RSTR, local_peripheralId);break;
			default: Det_ReportError(DET_RCCModuleId,RCC_ResetPeripheral,RCC_InvaildPeripheralID);
			break;
		}
	}
	else{Det_ReportError(DET_RCCModuleId,RCC_ResetPeripheral,RCC_InvaildPeripheralID);
	}

}

void RCC_voidEnablePeripheralClock(busId_E local_busId, u8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case RCC_AHB  : SET_BIT(RCC -> AHBENR, local_peripheralId);break;
			case RCC_APB1 : SET_BIT(RCC -> APB1ENR, local_peripheralId);break;
			case RCC_APB2 : SET_BIT(RCC -> APB2ENR, local_peripheralId);break;
			default:   return 1; //error Undefined busId
			break;
		}
	}
	else{
		Det_ReportError(DET_RCCModuleId, RCC_EnablePeripheralClock,RCC_InvaildPeripheralID);
	}

}

void RCC_voidDisablePeripheralClock(busId_E local_busId, u8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case RCC_AHB  : CLEAR_BIT(RCC -> AHBENR, local_peripheralId);break;
			case RCC_APB1 : CLEAR_BIT(RCC -> APB1ENR, local_peripheralId);break;
			case RCC_APB2 : CLEAR_BIT(RCC -> APB2ENR, local_peripheralId);break;
			default: Det_ReportError(DET_RCCModuleId, RCC_EnablePeripheralClock,RCC_InvaildPeripheralID);
			break;
		}
	}
	else{
		Det_ReportError(DET_RCCModuleId, RCC_DisablePeripheralClock,RCC_InvaildPeripheralID);
	}


}
