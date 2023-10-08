/*
 * UART_prg.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Ahmed
 */


void (*USART1_CallBack)(void);
void (*USART2_CallBack)(void);
void (*USART3_CallBack)(void);

void MUSART1_voidInit(void)
{
	RCC_voidEnablePeripheralClock(RCC_APB2,RCC_USART1);
	/*  Select baudrate      */
	/* 9600   BRR = 0x341    */
	/* 115200 BRR = 0x45    */
	MUSART1 -> BRR = 0x341;
	SET_BIT(MUSART1 -> CR1 , 2);		// ENABLE RX
	SET_BIT(MUSART1 -> CR1 , 3);		// ENABLE TX
	SET_BIT(MUSART1 -> CR1 , 13);		// ENABLE USART
}

void MUSART1_voidTransmit(u8 *ptr)
{
		u8 Local_u8Counter = 0;
	while(ptr[Local_u8Counter] != '\0')
	{
		MUSART1 -> DR = ptr[Local_u8Counter];
		while((GET_BIT((MUSART1 -> SR), 6)) == 0);
		Local_u8Counter++;
	}
}

u8   MUSART1_u8Receive(void)
{
	u8 Local_s8ReceivedData = 0;
	while(((MUSART1 -> SR) & (1 << 5)) == 0);
	Local_s8ReceivedData = ((0xFF) & (MUSART1 -> DR)) ;

	return (Local_s8ReceivedData);
}

void MUSART2_voidInit(void)
{
	/*  Select baudrate      */
	/* 9600   BRR = 0x341    */
	/* 115200 BRR = 0x45    */
	MUSART2 -> BRR = 0x341;
	SET_BIT(MUSART2 -> CR1 , 2);
	SET_BIT(MUSART2 -> CR1 , 3);
	SET_BIT(MUSART2 -> CR1 , 13);
	MUSART2 -> SR = 0;
}

void MUSART2_voidTransmit(u8 *ptr)
{
	u8 Local_u8Counter = 0;
	while(ptr[Local_u8Counter] != '\0')
	{
		MUSART2 -> DR = ptr[Local_u8Counter];
		while((GET_BIT((MUSART2 -> SR), 6)) == 0);
		Local_u8Counter++;
	}
}

u8   MUSART2_u8Receive(void)
{
	RCC_voidEnablePeripheralClock(RCC_APB1,RCC_USART2);
	u8 Local_s8ReceivedData = 0;
	while(((MUSART2 -> SR) & (1 << 5)) == 0);
	Local_s8ReceivedData = ((0xFF) & (MUSART2 -> DR)) ;

	return (Local_s8ReceivedData);
}


void MUSART3_voidInit(void)
{
	RCC_voidEnablePeripheralClock(RCC_APB1,RCC_USART3);
	/*  Select baudrate      */
	/* 9600   BRR = 0x341    */
	/* 115200 BRR = 0x45    */
	MUSART3 -> BRR = 0x45;
	SET_BIT(MUSART3 -> CR1 , 2);
	SET_BIT(MUSART3 -> CR1 , 3);
	SET_BIT(MUSART3 -> CR1 , 13);
	MUSART3 -> SR = 0;

}

void MUSART3_voidTransmit(u8 *ptr)
{
	u8 Local_u8Counter = 0;
	while(ptr[Local_u8Counter] != '\0')
	{
		MUSART3 -> DR = ptr[Local_u8Counter];
		while((GET_BIT((MUSART3 -> SR), 6)) == 0);
		Local_u8Counter++;
	}
}
u8   MUSART3_u8Receive(void)
{
	u8 Local_s8ReceivedData = 0;
	while(((MUSART3 -> SR) & (1 << 5)) == 0);
	Local_s8ReceivedData = ((0xFF) & (MUSART3 -> DR)) ;

	return (Local_s8ReceivedData);
}





void USART1_VidSetCallBack( void (*ptr) (void) ){

	USART1_CallBack = ptr ;

}

void USART2_VidSetCallBack( void (*ptr) (void) ){

	USART2_CallBack = ptr ;

}

void USART3_VidSetCallBack( void (*ptr) (void) ){

	USART3_CallBack = ptr ;

}

void USART1_IRQHandler(void){

	MUART1->SR = 0 ;
	USART1_CallBack();

}

void USART2_IRQHandler(void){

	MUART2->SR = 0 ;
	USART1_CallBack();

}

void USART3_IRQHandler(void){

	MUART3->SR = 0 ;
	USART1_CallBack();

}