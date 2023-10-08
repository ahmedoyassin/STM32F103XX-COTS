/*
 * File        : GPIO_PROGRAM.C
 * Author      : Abdelrhman Rabie Embedded SW Engineer
 * Date        : 15/7/2023

 */
#ifndef UART_Config_h
#define UART_Config_h

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


#endif
