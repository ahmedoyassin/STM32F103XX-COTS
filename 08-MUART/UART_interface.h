/*
 * UART_interface.h
 *
 *  Created on: Jul 30, 2023
 *      Author: Ahmed
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void MUSART1_voidInit(void);
void MUSART1_voidTransmit(u8 *ptr);
u8   MUSART1_u8Receive(void);


void MUSART2_voidInit(void);
void MUSART2_voidTransmit(u8 *ptr);
u8   MUSART2_u8Receive(void);


void MUSART3_voidInit(void);
void MUSART3_voidTransmit(u8 *ptr);
u8   MUSART3_u8Receive(void);


#endif /* UART_INTERFACE_H_ */
