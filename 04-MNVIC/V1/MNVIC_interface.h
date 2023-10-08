/*
 * NVIC_interface.h
 *
 *  Created on: Jul 29, 2023
 *      Author: Ahmed
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_

#include "MNVIC_private.h"


void MNVIC_VidInit(void);
void MNVIC_VidPerhiralEnable(u8 Copy_U8ISER_ID);
void MNVIC_VidPerhiralDisable(u8 Copy_U8ISER_ID);
void MNVIC_VidSetPending(u8 Copy_U8ISER_ID);
void MNVIC_VidClearPending(u8 Copy_U8ISER_ID);
u8 MNVIC_U8ReadActiveBit(u8 Copy_U8ISER_ID);
void MNVIC_Piriorty_Set(s8 INT_ID, u8 Copy_U8Group, u8 Copy_U8Priority);


// CFG.C

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);


#endif /* MNVIC_INTERFACE_H_ */
