/*
 * File        : USART_config.h
 * Author      : Yassin
 * Date        : 06/08/2023

 */
#ifndef UART_Config_h
#define UART_Config_h

/**
 * \file UART_cfg.h
 * \section Brief
 * This is UART configuration
 * \section Details
 * The available configuration allowed in the UART
 * \section Scope
 * Private
 *
 *
 *
*/

#include "UART_Private.h"

typedef enum
{
	oversamplingby16,
	oversamplingby8
	
}OVER8;

typedef enum
{
	UE_DISEBLE,
	UE_ENABLE
	
}UE;
typedef enum
{
	 DATA_8_BIT,
	 DATA_9_BIT
	
}M;
typedef enum
{
	 IdleLine,
	 AddressMark
	
}WAKE;
typedef enum
{
	 Paritycontroldisabled,
	 ParitycontrolEnabled
	
}PCE;

typedef enum
{
	 Evenparity,
	 ODDparity

}PS;
typedef enum
{
	 PEIE_DISEBLE,
	 PEIE_ENABLE

}PEIE;
typedef enum
{
	TE_DISEBLE,
	TE_ENABLE

}TE;
typedef enum
{
	 RE_DISEBLE,
	 RE_ENABLE

}RE;
typedef enum
{
	  OneStopbit,
	  HalfStopbit,
	  towStopbit,
	  oneAndHalfStopbit

}STOP;

typedef enum
{
   USART_MODE_ONLY_TX,
   USART_MODE_ONLY_RX,
   USART_MODE_TXRX
}USART_MODE;

/* USART Number */
typedef enum
{
	UART1,
	UART2,
	UART3
}USART_ID;

/*USART Buad Rate */
typedef enum
{
   USART_STD_BAUD_2400    = 2400,
   USART_STD_BAUD_9600    = 9600,
   USART_STD_BAUD_19200   = 19200,
   USART_STD_BAUD_38400   = 38400,
   USART_STD_BAUD_57600   = 57600,
   USART_STD_BAUD_115200  = 115200,
   USART_STD_BAUD_230400  = 230400,
   USART_STD_BAUD_460800  = 460800,
   USART_STD_BAUD_921600  = 921600,
   USART_STD_BAUD_2250000 = 2250000,
   SUART_STD_BAUD_4500000 = 4500000
}USART_BAUD;

#endif
