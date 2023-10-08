/*
 * File        : GPIO_PROGRAM.C
 * Author      : Abdelrhman Rabie Embedded SW Engineer
 * Date        : 15/7/2023

 */
#ifndef UART_Interface_h
#define UART_Interface_h




void UART_voidInit(void);

void UART_voidTRansimate(uint8 Copy_uint8Data[]);
uint8 UART_uint8RecivatdData(uint32 time);


#endif
