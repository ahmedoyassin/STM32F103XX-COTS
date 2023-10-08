/*
 * MDET.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#ifndef MDET_H_
#define MDET_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"

typedef enum
{
	DET_RCCModuleId,
	DET_GPIOModuleId,
}DET_moduleId_E;

typedef enum
{
RCC_ResetPeripheral,
RCC_InitializeSystemClock,
RCC_EnablePeripheralClock,
RCC_DisablePeripheralClock,
GPIO_SetPinsMode,
EXTI_Config,
GPIO_GetPinValue = 0X00,
GPIO_SetPinValue =0X01



}DET_FunctionID_E;


typedef enum
{
RCC_InvaildBusID,
RCC_InvaildPeripheralID,
EXTI_InvaildModeID,
GPIO_InvaildPinID = 0x0A,
GPIO_InvaildPortID = 0x14



}DET_ERORID_E;


void Det_ReportError (DET_moduleId_E moduleId,
                            u32 functionId,
                            u32 errorId);

#endif /* MDET_H_ */
