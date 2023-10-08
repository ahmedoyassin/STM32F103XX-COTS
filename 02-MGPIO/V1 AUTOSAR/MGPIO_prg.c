/*
 * GPIO_prg.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */


#include "../Inc/MGPIO_interface.h"


void GPIO_VidInit(void)
 {

	 u8 PIN;
	for(u8 itr=0;itr<NUMBER_OF_USED_PINS;itr++)
	{

	PIN=arrOfPins[itr].PIN_ID;
	u8 u8BIT_0_L=PIN * 4;
	u8 u8BIT_1_L=(PIN * 4) + 1;
	u8 u8BIT_2_L=(PIN * 4) + 2;
	u8 u8BIT_3_L=(PIN * 4) + 3;
	u8 u8BIT_0_H=((PIN - 8) * 4) ;
	u8 u8BIT_1_H=((PIN - 8) * 4) + 1;
	u8 u8BIT_2_H=((PIN - 8) * 4) + 2;
	u8 u8BIT_3_H=((PIN - 8) * 4) + 3;

#if DET_ERROE_ENABLE == ENABLE
	if((arrOfPins[itr].PORT_ID) > 2)
	{
		 Det_ReportError (DET_GPIOModuleId,
				          GPIO_SetPinsMode,
						  GPIO_InvaildPortID);
	}
#endif

		switch(arrOfPins[itr].PORT_ID)
		{
		case PORTA:

                         #if DET_ERROE_ENABLE == ENABLE
	                         if((arrOfPins[itr].PORT_ID) > 15)
	                                 {
		                                 Det_ReportError (DET_GPIOModuleId,
				                                          GPIO_SetPinsMode,
														  GPIO_InvaildPinID);
	                                  }
                              #endif

			if(arrOfPins[itr].PIN_ID<8){

				if(arrOfPins[itr].MODE==OUTPUT)
				{
					CLR_BIT(GPIOA -> CRL,u8BIT_0_L);
					SET_BIT(GPIOA -> CRL,u8BIT_1_L);
					CLR_BIT(GPIOA -> CRL,u8BIT_2_L);
					CLR_BIT(GPIOA -> CRL,u8BIT_3_L);

				}
				else if(arrOfPins[itr].MODE==INPUT)
				{
					CLR_BIT(GPIOA -> CRL,u8BIT_0_L);
					CLR_BIT(GPIOA -> CRL,u8BIT_1_L);
					CLR_BIT(GPIOA -> CRL,u8BIT_2_L);
					SET_BIT(GPIOA -> CRL,u8BIT_3_L);
				}

			   }
			else if((7< arrOfPins[itr].PIN_ID)&& (arrOfPins[itr].PIN_ID<16)){
				if(arrOfPins[itr].MODE==OUTPUT)
				{
					CLR_BIT(GPIOA -> CRH,u8BIT_0_H);
					SET_BIT(GPIOA -> CRH,u8BIT_1_H);
					CLR_BIT(GPIOA -> CRH,u8BIT_2_H);
					CLR_BIT(GPIOA -> CRH,u8BIT_3_H);

				}
				else if(arrOfPins[itr].MODE==INPUT)
				{
					CLR_BIT(GPIOA -> CRH,u8BIT_0_H);
					CLR_BIT(GPIOA -> CRH,u8BIT_1_H);
					CLR_BIT(GPIOA -> CRH,u8BIT_2_H);
					SET_BIT(GPIOA -> CRH,u8BIT_3_H);


				}

			}

		break;
		case PORTB:

                       #if DET_ERROE_ENABLE == ENABLE
	                         if((arrOfPins[itr].PORT_ID) > 15)
	                                 {
		                                 Det_ReportError (DET_GPIOModuleId,
				                                          GPIO_SetPinsMode,
														  GPIO_InvaildPinID);
	                                  }
                       #endif


			if(arrOfPins[itr].PIN_ID<8){

				if(arrOfPins[itr].MODE==OUTPUT)
				{
				CLR_BIT(GPIOB -> CRL,u8BIT_0_L);
				SET_BIT(GPIOB -> CRL,u8BIT_1_L);
				CLR_BIT(GPIOB -> CRL,u8BIT_2_L);
				CLR_BIT(GPIOB -> CRL,u8BIT_3_L);

				}
				else if(arrOfPins[itr].MODE==INPUT)
				{
					CLR_BIT(GPIOB -> CRL,u8BIT_0_L);
					CLR_BIT(GPIOB -> CRL,u8BIT_1_L);
					CLR_BIT(GPIOB -> CRL,u8BIT_2_L);
					SET_BIT(GPIOB -> CRL,u8BIT_3_L);


				}

			}
			else if((7< arrOfPins[itr].PIN_ID) && (arrOfPins[itr].PIN_ID<16)){
				if(arrOfPins[itr].MODE==OUTPUT)
				{
					CLR_BIT(GPIOB -> CRH,u8BIT_0_H);
					SET_BIT(GPIOB -> CRH,u8BIT_1_H);
					CLR_BIT(GPIOB -> CRH,u8BIT_2_H);
					CLR_BIT(GPIOB -> CRH,u8BIT_3_H);

				}
				else if(arrOfPins[itr].MODE==INPUT)
				{
					CLR_BIT(GPIOB -> CRH,u8BIT_0_H);
					CLR_BIT(GPIOB -> CRH,u8BIT_1_H);
					CLR_BIT(GPIOB -> CRH,u8BIT_2_H);
					SET_BIT(GPIOB -> CRH,u8BIT_3_H);


				}

			}

		break;
		case PORTC:

                            #if DET_ERROE_ENABLE == ENABLE
	                           if((arrOfPins[itr].PORT_ID) > 15)
	                                 {
		                                 Det_ReportError (DET_GPIOModuleId,
				                                          GPIO_SetPinsMode,
														  GPIO_InvaildPinID);
	                                  }
                            #endif


			if(arrOfPins[itr].PIN_ID<8){

				if(arrOfPins[itr].MODE==OUTPUT)
				{
					CLR_BIT(GPIOC -> CRL,u8BIT_0_L);
					CLR_BIT(GPIOC -> CRL,u8BIT_1_L);
					CLR_BIT(GPIOC -> CRL,u8BIT_2_L);
					SET_BIT(GPIOC -> CRL,u8BIT_3_L);

				}
				else if(arrOfPins[itr].MODE==INPUT)
				{
					CLR_BIT(GPIOC -> CRL,u8BIT_0_L);
					SET_BIT(GPIOC -> CRL,u8BIT_1_L);
					CLR_BIT(GPIOC -> CRL,u8BIT_2_L);
					CLR_BIT(GPIOC -> CRL,u8BIT_3_L);


				}

			}
			else if((7< arrOfPins[itr].PIN_ID)&& (arrOfPins[itr].PIN_ID<16)){
				if(arrOfPins[itr].MODE==OUTPUT)
				{
					CLR_BIT(GPIOC -> CRH,u8BIT_0_H);
					CLR_BIT(GPIOC -> CRH,u8BIT_1_H);
					CLR_BIT(GPIOC -> CRH,u8BIT_2_H);
					SET_BIT(GPIOC -> CRH,u8BIT_3_H);

				}
				else if(arrOfPins[itr].MODE==INPUT)
				{
					CLR_BIT(GPIOC -> CRH,u8BIT_0_H);
					SET_BIT(GPIOC -> CRH,u8BIT_1_H);
					CLR_BIT(GPIOC -> CRH,u8BIT_2_H);
					CLR_BIT(GPIOC -> CRH,u8BIT_3_H);


				}

			}


		break;


	}
 }
 }

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	u8 U8copy_Get;

#if DET_ERROE_ENABLE == ENABLE
	if(ChannelId > 47)
	{
		 Det_ReportError (DET_GPIOModuleId,
				          GPIO_GetPinValue,
						  GPIO_InvaildPinID);
	}
#endif


if (ChannelId== (A0|| A1 || A2|| A3 ||A4|| A5 || A6 || A7 ||A8 || A9 || A10|| A11 || A12 || A13 || A14|| A15))
{

	U8copy_Get =GET_BIT(GPIOA -> IDR,ChannelId);
		if(U8copy_Get == 1)
		{
			return HIGH;
		}
		else
		{
			return LOW;
		}
}
else if (ChannelId== (B0|| B1 || B2|| B3 || B4 || B5 || B6 || B7 ||B8 || B9 || B10|| B11 || B12 || B13 || B14|| B15))
{
		U8copy_Get =GET_BIT(GPIOB -> IDR,ChannelId);
		if(U8copy_Get == 1)
		{
			return HIGH;
		}
		else
		{
			return LOW;
		}
}
else if (ChannelId == (C0|| C1 || C2|| C3 || C4 || C5 || C6 || C7 ||C8 || C9 || C10|| C11 || C12 || C13 || C14|| C15))
		{
			 U8copy_Get =GET_BIT(GPIOC -> IDR,ChannelId);
			if(U8copy_Get == 1)
			{
				return HIGH;
			}
			else
			{
				return LOW;
			}
		}


}

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level)
{

#if DET_ERROE_ENABLE == ENABLE
	if(ChannelId > 47)
	{
		 Det_ReportError (DET_GPIOModuleId,
				          GPIO_SetPinValue,
						  GPIO_InvaildPinID);
	}
#endif


if (ChannelId== A0|| A1 || A2|| A3 ||A4|| A5 || A6 || A7 ||A8 || A9 || A10|| A11 || A12 || A13 || A14|| A15)
{	if(Level ==HIGH){
					SET_BIT(GPIOA ->BSRR, ChannelId);
				}
				else
				{
					SET_BIT(GPIOA->BRR,ChannelId);
					//SET_BIT(GPIOA ->BSRR,x);
				}
				}
else if (ChannelId== B0|| B1 || B2|| B3 || B4 || B5 || B6 || B7 ||B8 || B9 || B10|| B11 || B12 || B13 || B14|| B15)
{	if(Level ==HIGH)
				{
					SET_BIT(GPIOB ->BSRR, ChannelId);
				}
				else
				{
					SET_BIT(GPIOB->BRR,ChannelId);
					//SET_BIT(GPIOB ->BSRR, x);
				}}
else if (ChannelId== C0|| C1 || C2|| C3 || C4 || C5 || C6 || C7 ||C8 || C9 || C10|| C11 || C12 || C13 || C14|| C15)
{			if(Level ==HIGH)
				{
					SET_BIT(GPIOC ->BSRR, ChannelId);
				}
				else
				{
					SET_BIT(GPIOC->BRR,ChannelId);
					//SET_BIT(GPIOC ->BSRR, x);
				}				}

}


void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
{
#if Level == HIGH
	{
 	if (PortId == PORTA){
 		GPIOA ->ODR=0x0000FFFF;
 }
 else if (PortId == PORTB){
	 GPIOB ->ODR=0x0000FFFF;
 }
 else{
	 GPIOC ->ODR=0x0000FFFF;
 	 }
 }

#elif Level == LOW

 	if (PortId == PORTA){
 		GPIOA ->ODR=0x00000000;
 }
 else if (PortId == PORTB){
	 GPIOB ->ODR=0x00000000;
 }
 else{
	 GPIOC ->ODR=0x00000000;
 	 }


#endif
}

/*
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr ){

	for(u8 i = 0; i < NUMBER_OF_USED_PINS_GROUP; i++)
	{
		ChannelGroupIdPtr->PortId = ArrOfGroup[i].PORT_ID;
		ChannelGroupIdPtr->PinId = ArrOfGroup[i].PIN_ID;
		return GET_BIT(ChannelGroupIdPtr->PortId->IDR, ChannelGroupIdPtr->PinId);
	}
}

void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{

	for(u8 i = 0; i < NUMBER_OF_USED_PINS_GROUP; i++)
	{
		ChannelGroupIdPtr->PortId = ArrOfGroup[i].PORT_ID;
		ChannelGroupIdPtr->PinId = ArrOfGroup[i].PIN_ID;
		if(HIGH == Level)
		SET_BIT(ChannelGroupIdPtr->PortId->IDR, ChannelGroupIdPtr->PinId);
		else
		CLR_BIT((ChannelGroupIdPtr->PortId->IDR), ChannelGroupIdPtr->PinId);
	}
}
*/

void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo )
{
	VersionInfo->Major = SW_MAJOR_VERSION;
	VersionInfo->Minor = SW_MINOR_VERSION;
}

Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId)
{
	u8 U8copy_Get;
	if(ChannelId < 16)
	{
	U8copy_Get =GET_BIT(GPIOA -> IDR,ChannelId);
		if(U8copy_Get == 1)
		{
			return LOW;
		}
		else
		{
			return HIGH;
		}

	}
	else if((ChannelId >= 16) && (ChannelId < 32))
	{
		 U8copy_Get =GET_BIT(GPIOB -> IDR,(ChannelId - 16));
		if(U8copy_Get == 1)
		{
			return LOW;
		}
		else
		{
			return HIGH;
		}
	}
	else
		{
		if(U8copy_Get == 1)
		{
			return LOW;
		}
		else
		{
			return HIGH;
		}
	}
}

