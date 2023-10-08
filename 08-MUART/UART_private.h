/*
 * UART.private.h
 *
 *  Created on: Jul 30, 2023
 *      Author: Ahmed
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

typedef struct
{
	volatile u32	SR;
	volatile u32	DR;
	volatile u32	BRR;
	volatile u32	CR1;
	volatile u32	CR2;
	volatile u32	CR3;
	volatile u32	GRPR;
}MUART_t;

#define MUSART1 ((volatile MUART_t *) 0x40013800)
#define MUSART2 ((volatile MUART_t *) 0x40004400)
#define MUSART3 ((volatile MUART_t *) 0x40004800)


#endif /* UART_PRIVATE_H_ */
