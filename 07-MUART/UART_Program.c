/*
 * File        : GPIO_PROGRAM.C
 * Author      : Abdelrhman Rabie Embedded SW Engineer
 * Date        : 15/7/2023

 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Config.h"
#include "MRCC_interface.h"  /*check if it's wrong*/


/*
DIV BY 16
ENABLE UART
CHOICE 8 BIT DATA
NO ADRESS AND NO LINE
ParitycontrolEnabled
CHOICE EVEN PARITY BIT
TRANSIMATE IS ENABLE
BOUD RATE 115200

 */
void UART_voidInit(void)
{
	
	RCC_voidEnablePeripheralClock(RCC_APB2,RCC_APB2RSTR_USART1RST);     /*ENABLE USART1 CLOCK(NOT AN ATOMIC FUNCTION)*/
	
	/*BIT 2 OF AFIO_MAPR_REG IS EQUAL ZERO BY DEFULT SO WE ARE NOT REMAPPING(USE TX:A9 , RX:A10)*/
	
	UART1->BRR.R=0xD9;                    /*BOUDE RATE 115200 FCPU=8000000*/
	UART1->CR1.B.OVER8=oversamplingby16;  /*MAKE UART SAMPLING 16 BIT */
	UART1->CR1.B.M=DATA_8_BIT;            /*SEND AND RECIVE 8 BIT DATA*/
	//UART1->CR1.B.PCE=ParitycontrolEnabled;
	//UART1->CR1.B.PS=Evenparity;
	UART1->CR1.B.TE=TE_ENABLE;
	UART1->CR1.B.RE=RE_ENABLE;
	UART1->CR2.B.STOP=OneStopbit;
   // UART1->SR.R=0;/*STUTUS REG =0 */
	UART1->CR1.B.UE=UE_ENABLE;            /*ENABLE UART*/

}

void UART_voidTRansimate(uint8 Copy_uint8Data[])
{

	uint32 local_UARTcounter=0;

	while(Copy_uint8Data[local_UARTcounter] != '\0')
		{
	UART1->DR.R=Copy_uint8Data[local_UARTcounter];
	while( UART1->SR.B.TXE == 0){}
	       ++local_UARTcounter;
	    }


}


uint8 UART_uint8RecivatdData(uint32 time)
{
	volatile uint32 timeout=0;
	volatile uint8 Local_u8DataReceived=0;

	{
	while( UART1->SR.B.RXNE==0)
	{
		++timeout;
		if(timeout==time)
		{
			Local_u8DataReceived=128;
		break;

		}


	}
	}
	if(Local_u8DataReceived==0)
		{
		Local_u8DataReceived=(uint8)(UART1->DR.R);
	    }

	UART1->SR.B.RXNE=0;
	return Local_u8DataReceived;
}

