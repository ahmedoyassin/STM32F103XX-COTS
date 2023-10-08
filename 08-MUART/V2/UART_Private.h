/*
 * File        : USART_Private.h
 * Author      : Yassin
 * Date        : 06/08/2023

 */
#ifndef UART_Private_h
#define UART_Private_h

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**
 * \file UART_Private.h
 * \section Brief
 * This is USART Private.
 * \section Details
 * The definitions and typedefs for the UART needs
 * \section Scope
 * Private
 *
 *
 *
*/
#define NUMBER_OF_USED_UARTS 	3
#define F_CPU                                  8000000
#define MAX_STRING_TO_BE_RECEIVED_USART1 100
#define MAX_STRING_TO_BE_RECEIVED_USART2 100
#define MAX_STRING_TO_BE_RECEIVED_USART3 100
#define THRESHOLD_VALUE 10000000

typedef struct
{
	
	
	union
{
	u32 R;
    struct
	{
	u32 PE    :1;
	u32 FE    :1;
	u32 NF    :1;
	u32 ORE   :1;
	u32 IDLE  :1;
    u32 RXNE  :1;
    u32 TC    :1;
	u32 TXE   :1;
	u32 LBD   :1;
	u32 CTS   :1;
	u32 unsed :22;
	}B;	
}SR;
	
		union
{
	u32 R;
    	
}DR;
	
	union
{
	u32 R;
    struct
	{
	u32 DIV_Fraction :4;
	u32 DIV_Mantissa :12;
	u32 UNUSED       :16;
	}B;	
}BR;
	
	union
{
	u32 R;
    struct
	{
	u32 SBK   :1;
	u32 RWU   :1;
	u32 RE    :1;
	u32 TE    :1;
    u32 IDLEIE:1;
    u32 RXNEIE:1;
	u32 TCIE  :1;
	u32 TXEIE :1;
	u32 PEIE  :1;
	u32 PS    :1;
	u32 PCE   :1;
	u32 WAKE  :1;
	u32 M     :1;
	u32 UE    :1;
	u32 RES   :1;
	u32 OVER8 :1;
	u32 UNSED :16;
	
	}B;	
}CR1;	
	
union
{
	u32 R;
    struct
	{
	u32 ADD   :4;
	u32 RES   :1;
	u32 LBDL  :1;
	u32 LBDIE :1;
    u32 RES_1 :1;
    u32 LBCL  :1;
	u32 CPHA  :1;
	u32 CPOL  :1;
	u32 CLKEN :1;
	u32 STOP  :2;
	u32 LINE  :1;
	u32 RES_2 :1;
	u32 UNSED :16;
	}B;	
}CR2;	
	u32 CR3;
	u32 GTPR;
		
}USART_t;
/*
USART 1 IN APB2
USART 2&3 IN APB1
*/
#define                      BASE_ADRESS_USART1      0x40013800
#define                      BASE_ADRESS_USART2      0x40004400
#define                      BASE_ADRESS_USART3      0x40004800

#define MUART1 ((volatile USART_t *)BASE_ADRESS_USART1)
#define MUART2 ((volatile USART_t *)BASE_ADRESS_USART2)
#define MUART3 ((volatile USART_t *)BASE_ADRESS_USART3)


#endif
