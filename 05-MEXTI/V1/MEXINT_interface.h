/*
 * MEXINT_interface.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Ahmed
 */

#ifndef EXINT_MEXINT_INTERFACE_H_
#define EXINT_MEXINT_INTERFACE_H_


/* Line is a standered for Ports
 * Example LINE0 --> A0 & B0 & C0
 *  */
#define EXTI_LINE0      			0
#define EXTI_LINE1      			1
#define EXTI_LINE2      			2
#define EXTI_LINE3      			3
#define EXTI_LINE4      			4
#define EXTI_LINE5      			5
#define EXTI_LINE6      			6
#define EXTI_LINE7      			7
#define EXTI_LINE8      			8
#define EXTI_LINE9      			9
#define EXTI_LINE10     			10
#define EXTI_LINE11     			11
#define EXTI_LINE12     			12
#define EXTI_LINE13     			13
#define EXTI_LINE14     			14
#define EXTI_LINE15     			15


/* EXTI Mode */
#define EXTI_RISING_EDGE   			1
#define EXTI_FALING_EDGE   			2
#define EXTI_ON_CHANGE    			3


void MEXTI_VidInit(void);

void MEXTI_VidEnableEXTI(u8 Copy_U8Line) ;

void MEXTI_VidDisableEXTI(u8 Copy_U8Line);

void MEXTI_VidSwTrigger(u8 Copy_U8Line)  ;

void MEXTI_VidSetSignalLatch(u8 Copy_U8Line , u8 Copy_VidMode );

void MEXTI_VidSetCallBack(void (*Copy_ptr) (void) , u8 Copy_U8Line);

#endif
