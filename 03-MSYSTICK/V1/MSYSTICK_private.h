/*
 * SYSICK_private.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#ifndef SYSICK_PRIVATE_H_
#define SYSICK_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDET.h"

#define CLK_SRC 1
#define INT_SRC 1
#define ENABLE_SRC 1

#define CLK_SRC_ON 	1
#define CLK_SRC_OFF 0
#define INT_SRC_ON 	1
#define INT_SRC_OFF 0
#define ENABLE_SRC_ON 1
#define ENABLE_SRC_OFF 0


#define MSTK_CTRL(CLK_SRC,INT_SRC,ENBALE_SRC)		MSTK_CTRL_HELP(CLK_SRC,INT_SRC,ENBALE_SRC)
#define MSTK_CTRL_HELP(CLK_SRC,INT_SRC, ENBALE_SRC) 0b00000000000000000000000000000##CLK_SRC##INT_SRC##ENBALE_SRC


typedef struct
{
	u32 volatile CTRL  ;
	u32 volatile LOAD  ;
	u32 volatile VAL ;
	u32 volatile CALIB ;

}SYSTICK_REG;

#define STK  ((SYSTICK_REG*)(0xE000E010))

/************************SYSTICK CLOCK SOURCE******************/
#define        MSYSTICK_SOURCE_AHB                      0
#define        MSYSTICK_SOURCE_AHB_by_8                 1
/**************************************************************/


#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1


#endif /* SYSICK_PRIVATE_H_ */
