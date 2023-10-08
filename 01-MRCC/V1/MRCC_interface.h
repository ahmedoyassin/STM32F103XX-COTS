/*
 * MRCC_interface.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

#include "MRCC_private.h"

typedef enum
{
	RCC_AHB ,
	RCC_APB1,
	RCC_APB2
}busId_E;




void RCC_voidInitializeSystemClock(void);
void RCC_voidEnablePeripheralClock(busId_E local_busId, u8 local_peripheralId);
void RCC_voidDisablePeripheralClock(busId_E local_busId, u8 local_peripheralId);


#endif /* MRCC_INTERFACE_H_ */
