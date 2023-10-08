/*
 * MEXINT_private.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Ahmed
 */

/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/

#ifndef MEXINT_PRIVATE_H_
#define MEXINT_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDET.h"


typedef struct
{
	volatile u32 IMR   ;
	volatile u32 EMR   ;
	volatile u32 RTSR  ;
	volatile u32 FTSR  ;
	volatile u32 SWIER ;
	volatile u32 PR    ;
	
}EXTI_t;

#define EXTI 							((volatile EXTI_t *)0x40010400)

#define EXTI_NUBER_OF_LINES			16


static void (*EXTI_CallBack[EXTI_NUBER_OF_LINES])  (void) = {NULL};

#endif
