/*
 * File        : USART_program.c
 * Author      : Yassin - RABIE - ALIAA 
 * Date        : 25/08/2023
 * Version     : 5

 */

/**
 * \file UART_Program.c
 * \section Brief
 * This is UART services Prg
 * \section Details
 * The module drives the UART functionality for SW
 * \section Scope
 * Public
 *
 *
 *
*/
#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Config.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"

/*
DIV BY 16
ENABLE USART
CHOICE 8 BIT Copy_U8Data
NO ADRESS AND NO LINE
ParitycontrolEnabled
CHOICE EVEN PARITY BIT
TRANSIMATE IS ENABLE
BOUD RATE 9600

 */
void (*USART1_CallBack)(void);
void (*USART2_CallBack)(void);
void (*USART3_CallBack)(void);
u8 received_string1[MAX_STRING_TO_BE_RECEIVED_USART1];
u8 received_string2[MAX_STRING_TO_BE_RECEIVED_USART2];
u8 received_string3[MAX_STRING_TO_BE_RECEIVED_USART3];


/***********************************[1]***********************************************
 * Service Name: UART_VidInit
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): Constant USART_ConfigType
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Set the configration of the given UART(s) to be enabled.
 ************************************************************************************/
 
 
 /**
 * \section Service_Name
 * UART_VidInit
 *
 * \section Service_ID_hex
 * 0x01
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Reentrant
 *
 * \section Parameters_in
 * \param[in] Constant USART_ConfigType(Pointer of Arrays)\PeripheralID--->Global Array to configrate the used UART(S).
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * None
 *
 * \section Description
 *  Set the configration of the given UART(s) to be enabled.
 * 
 * \section Activity_diagram
 *
 * \startuml 
 *   start
 *	repeat
 *  if (UART is enabled to Initalize) then (Yes)
 *  :Select UsART_ID;
 * 	else (no)
 *	end
  * endif
 *  :Enable the RCC for the UART;
 *  :Configrating the UART Pins;
 *  if(UART Word Size) then (8)
 *	:Set the UART WordSize = 8;
 *	else (9)
  *	:Set the UART WordSize = 9;
 *	endif
 *  switch (How many Stop-Bits are used?)
 *	case ( A)
 *	:OneStopbit;
 *	case ( B)
 *	:HalfStopbit;
 *	case ( C)
 *	:towStopbit;
 *	case ( D)
 *	:oneAndHalfStopbit;
 *	endswitch
 *  switch(UART Mode)
 *	case ( A)
 * 	:TX ONLY;
 *	case ( B)
 *	:RX ONLY;
 *	case ( C)
 *	: TX AND RX;
 *	endswitch
 *  switch (ParityControl Bit)
 *	case ( A)
 *	:ENABLED;
 *	switch (ParitySelection)
 *	case ( A)
 * 	:EVEN;
 *	case ( B)
 *	:ODD;
 *	endswitch
 *	case ( B)
 *	:DISABLED;
 *	endswitch
 *	:Select the buadrate;
 *	:ENABLE THE UART;
 *	repeat while (There's other UARTs left to Initalize?) is (Yes) not (no)
 * end
 * \enduml
 */

void USART_VidInit(const USART_ConfigType *USART_CFG)
{
    if (USART_CFG == NULL)
    {
        return;
    }

    volatile USART_t *UART_PTR = NULL;

	for (int i = 0; i < NUMBER_OF_USED_UARTS; i++)
	    {
 if (USART_CFG->UART_Array[i].USARTEnableType == UE_DISEBLE)
 {
	continue;
 }

 switch (USART_CFG->UART_Array[i].USARTid)
 {
 case UART1:
	RCC_voidEnablePeripheralClock(RCC_APB2,RCC_USART1);
	Port_SetPinDirection(A9,0x2);
	Port_SetPinDirection(A10,0x0);
	Port_SetPinMode(A9, A_PUSH_PULL);
	Port_SetPinMode(A10, FLOATING_INPUT);
	UART_PTR = MUART1;
	break;

 case UART2:
	RCC_voidEnablePeripheralClock(RCC_APB1,RCC_USART2);
	Port_SetPinDirection(A2,0x2);
	//Port_SetPinDirection(A3,0x0);
	Port_SetPinMode(A2, A_PUSH_PULL);
	//Port_SetPinMode(A3, FLOATING_INPUT);
	UART_PTR = MUART2;
	break;

 case UART3:
	RCC_voidEnablePeripheralClock(RCC_APB1,RCC_USART3);
	Port_SetPinDirection(B10,0x2);
	Port_SetPinDirection(B11,0x0);
	Port_SetPinMode(B10, A_PUSH_PULL);
	Port_SetPinMode(B11, FLOATING_INPUT);
	UART_PTR = MUART3;
	break;
 }

UART_PTR->CR1.B.M= USART_CFG->UART_Array[i].USARTWordLength;
UART_PTR->CR2.B.STOP = USART_CFG->UART_Array[i].USARTStopBits;
UART_PTR->CR1.B.PCE = USART_CFG->UART_Array[i].USARTParityControl;
	   if(UART_PTR->CR1.B.PCE == 1)
	   {
    UART_PTR->CR1.B.PS = USART_CFG->UART_Array[i].USARTParitySelection;
	   }
	   
	   if (USART_CFG->UART_Array[i].USARTMode == USART_MODE_ONLY_TX)
	   {
UART_PTR->CR1.B.TE = 1;
UART_PTR->CR1.B.RE = 0;
	   }
	   if (USART_CFG->UART_Array[i].USARTMode == USART_MODE_ONLY_RX)
	   {
UART_PTR->CR1.B.TE = 0;
UART_PTR->CR1.B.RE = 1;
	   }
	   if (USART_CFG->UART_Array[i].USARTMode == USART_MODE_TXRX)
	   {
UART_PTR->CR1.B.TE = 1;
UART_PTR->CR1.B.RE = 1;
	   }
	   else
	   {
	   }
	   /*Put baud rate value in BRR Rister*/
	    u32 mantissa = (F_CPU) / (16 * USART_CFG->UART_Array[i].USARTBaud);
		u32 fraction = (((F_CPU * 100) / (16 * USART_CFG->UART_Array[i].USARTBaud)) % 100) * 16;
		if (fraction > 1500)
			{
				mantissa += 1;
				fraction = 0;
			}
		UART_PTR->BR.R = ( mantissa << 4  ) | ( fraction / 100 ) ;
					/*Start the USART*/
		UART_PTR->CR1.B.UE = UE_ENABLE;}
}
/***********************************[2]***********************************************
 * Service Name: USART1_ReceiveByte
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: Copy_U8Data
 * Description: Recieve the Sent Data by the user.
 ************************************************************************************/
 
/**
 * \section Service_Name
 * USART1_ReceiveByte
 *
 * \section Service_ID_hex
 * 0x02
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  None
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * Copy_U8Data
 *
 * \section Description
 *  Recieve the Sent Data by the user.
 * 
 * \section Activity_diagram
 *
 * \startuml 
 *   start
 *  :Initialize local variables;
 *  while (Data has been sent) is (No)
 *  if(Timeout is less than 5s) then (Yes)
 *  :Increment timeout;
 *	else (no)
 *  :Data equals rublish;
 *	end
  *	endif
 *  endwhile (Yes)
 *  :Data is received;
 *  :timeout equals 0;
 *	:return recievedData;
 * end
 * \enduml
*/
u8 USART1_ReceiveByte(void)
{
    u8 Copy_U8Data;
    u32 Copy_U32TimeOut=0;
    MUART1->SR.B.RXNE = 0;
    while((MUART1->SR.B.RXNE == 0) && (Copy_U32TimeOut < THRESHOLD_VALUE))
    {
           Copy_U32TimeOut++;
       }

       if(Copy_U32TimeOut == THRESHOLD_VALUE)
       {
           Copy_U8Data = 255;
       }
       else
       {
           Copy_U8Data = MUART1->DR.R;
           Copy_U32TimeOut=0;
       }
       return Copy_U8Data;
}
/***********************************[3]***********************************************
 * Service Name: USART2_ReceiveByte
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: Copy_U8Data
 * Description: Recieve the Sent Data by the user.
 ************************************************************************************/
 
/**
 * \section Service_Name
 * USART2_ReceiveByte
 *
 * \section Service_ID_hex
 * 0x03
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  None
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * Copy_U8Data
 *
 * \section Description
 *  Recieve the Sent Data by the user.
 * 
 * \section Activity_diagram
 *
 * \startuml 
 *   start
 *  :Initialize local variables;
 *  while (Data has been sent) is (No)
 *  if(Timeout is less than 5s) then (Yes)
 *  :Increment timeout;
 *	else (no)
 *  :Data equals rublish;
 *	end
  *	endif
 *  endwhile (Yes)
 *  :Data is received;
 *  :timeout equals 0;
 *	:return recievedData;
 * end
 * \enduml
*/
u8 USART2_ReceiveByte(void)
{
		u8 Copy_U8Data;
	    u32 Copy_U32TimeOut=0;
	    MUART2->SR.B.RXNE = 0;
	    while((MUART2->SR.B.RXNE == 0) && (Copy_U32TimeOut < THRESHOLD_VALUE))
	     Copy_U32TimeOut++;
	     if(Copy_U32TimeOut == THRESHOLD_VALUE)
	    	 	 Copy_U8Data = 255;
	     else
	     {
	    	 	 Copy_U8Data = MUART2->DR.R;
	    	 	 Copy_U32TimeOut=0;
	     }
	      return Copy_U8Data;
}
/***********************************[4]***********************************************
 * Service Name: USART3_ReceiveByte
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: Copy_U8Data
 * Description: Recieve the Sent Data by the user.
 ************************************************************************************/
 
/**
 * \section Service_Name
 * USART3_ReceiveByte
 *
 * \section Service_ID_hex
 * 0x04
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  None
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * Copy_U8Data
 *
 * \section Description
 *  Recieve the Sent Data by the user.
 * 
 * \section Activity_diagram
 *
 * \startuml 
 *   start
 *  :Initialize local variables;
 *  while (Data has been sent) is (No)
 *  if(Timeout is less than 5s) then (Yes)
 *  :Increment timeout;
 *	else (no)
 *  :Data equals rublish;
 *	end
  *	endif
 *  endwhile (Yes)
 *  :Data is received;
 *  :timeout equals 0;
 *	:return recievedData;
 * end
 * \enduml
*/
u8 USART3_ReceiveByte(void)
{
	u8 Copy_U8Data;
    u32 Copy_U32TimeOut=0;
    MUART3->SR.B.RXNE = 0;
    while((MUART3->SR.B.RXNE == 0) && (Copy_U32TimeOut < THRESHOLD_VALUE))
    {
     Copy_U32TimeOut++;
    }
     if(Copy_U32TimeOut == THRESHOLD_VALUE)
     {
    	 Copy_U8Data = 255;
     }
     else
     {
         Copy_U8Data = MUART3->DR.R;
         Copy_U32TimeOut=0;
     }
      return Copy_U8Data;
}
/***********************************[5]***********************************************
 * Service Name: USART1_VidSendChar
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): Copy_U8Data
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: void
 * Description: send char .
 ************************************************************************************/
 /**
 * \section Service_Name
 * USART1_VidSendChar
 *
 *
 * \section Service_ID_hex
 * 0x05
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  Copy_U8Data
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * Void
 *
 * \section Description
 *  send char.
 *
 * \section Sequence_diagram
 *
 * \startuml
 *  actor User
 *
 *	User -> Code: USART1_VidSendChar(Copy_U8Data)
 *	activate Code
 *
 *	Code -> MUART3: Set MUART3->SR.B.TC to 0
 *	activate MUART3
 *	MUART3 --> Code: MUART3->SR.B.TC set to 0
 *	deactivate MUART3
 *
 *	Code -> MUART1: Assign Copy_U8Data to MUART1->DR.R
 *	activate MUART1
 *	MUART1 --> Code: Copy_U8Data assigned to MUART1->DR.R
 *	deactivate MUART1
 *
 *	Code -> MUART1: Check if MUART1->SR.B.TC is false
 *	activate MUART1
 *	alt (Condition is true)
 *	  MUART1 --> Code: Condition is true
 *	  Code -> Code: Continue loop
 *	  loop
 *	else (Condition is false)
 *	  MUART1 --> Code: Condition is false
 *	  Code -> Code: Break loop
 *	end
 *	deactivate MUART1
 *
 *	Code -> MUART1: Set MUART1->SR.B.TC to 0
 *	activate MUART1
 *	MUART1 --> Code: MUART1->SR.B.TC set to 0
 *	deactivate MUART1
 *
 *	deactivate Code
 *
 * \enduml 
 *
 * \section Activity_diagram
 *
 * \startuml
 *  start
 *  :Initialize MUART3->SR.B.TC to 0;
 *  :MUART1->DR.R = Copy_U8Data;
 *	repeat
 *	  :Check if MUART1->SR.B.TC is false;
 *	  if (Condition)
 *		--> repeat
 *	  else
 *		break
 *   endif
 *	repeat while (Condition)
 *	:MUART1->SR.B.TC = 0;
 * end
 * \enduml
 */
void USART1_VidSendChar(u8 Copy_U8Data)
{
    MUART3->SR.B.TC = 0;
    MUART1->DR.R = Copy_U8Data;
    while (!MUART1->SR.B.TC);
    MUART1->SR.B.TC = 0;
}
/***********************************[6]***********************************************
 * Service Name: USART2_VidSendChar
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): Copy_U8Data
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: void
 * Description: send char .
 ************************************************************************************/
  /**
 * \section Service_Name
 * USART2_VidSendChar
 *
 *
 * \section Service_ID_hex
 * 0x06
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  Copy_U8Data
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * Void
 *
 * \section Description
 *  send char.
 *
 * \section Sequence_diagram
 *
 * \startuml
 *  actor User
 *
 *	User -> Code: USART2_VidSendChar(Copy_U8Data)
 *	activate Code
 *
 *	Code -> MUART2: Set MUART2->SR.B.TC to 0
 *	activate MUART2
 *	MUART2 --> Code: MUART2->SR.B.TC set to 0
 *	deactivate MUART2
 *
 *	Code -> MUART2: Assign Copy_U8Data to MUART2->DR.R
 *	activate MUART2
 *	MUART2 --> Code: Copy_U8Data assigned to MUART2->DR.R
 *	deactivate MUART2
 *
 *	Code -> MUART2: Check if MUART2->SR.B.TC is false
 *	activate MUART2
 *	alt (Condition is true)
 *	  MUART2 --> Code: Condition is true
 *	  Code -> Code: Continue loop
 *	  loop
 *	else (Condition is false)
 *	  MUART2 --> Code: Condition is false
 *	  Code -> Code: Break loop
 *	end
 *	deactivate MUART2
 *
 *	Code -> MUART2: Set MUART2->SR.B.TC to 0
 *	activate MUART2
 *	MUART2 --> Code: MUART2->SR.B.TC set to 0
 *	deactivate MUART2
 *
 *	deactivate Code
 *
 * \enduml 
 *
 * \section Activity_diagram
 *
 * \startuml
 *  start
 *  :Initialize MUART2->SR.B.TC to 0;
 *  :MUART2->DR.R = Copy_U8Data;
 *	repeat
 *	  :Check if MUART2->SR.B.TC is false;
 *	  if (Condition)
 *		--> repeat
 *	  else
 *		break
 *   endif
 *	repeat while (Condition)
 *	:MUART2->SR.B.TC = 0;
 * end
 * \enduml
 */
void USART2_VidSendChar(u8 Copy_U8Data)
{
    MUART2->SR.B.TC = 0;
    MUART2->DR.R = Copy_U8Data;
    while (!MUART2->SR.B.TC);
    MUART2->SR.B.TC = 0;
}
/***********************************[7]***********************************************
 * Service Name: USART3_VidSendChar
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): Copy_U8Data
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: void
 * Description: send char .
 ************************************************************************************/
 /**
 * \section Service_Name
 * USART3_ReceiveString
 *
 *
 * \section Service_ID_hex
 * 0x07
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  None
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * pointer to string
 *
 * \section Description
 *  Recieve the Sent DataString by the user.
 *
 * \section Sequence_diagram
 *
 * \startuml
 *  actor User
 *
 *	User -> Code: USART3_VidSendChar(Copy_U8Data)
 *	activate Code
 *
 *	Code -> MUART3: Set MUART3->SR.B.TC to 0
 *	activate MUART3
 *	MUART3 --> Code: MUART3->SR.B.TC set to 0
 *	deactivate MUART3
 *
 *	Code -> MUART3: Assign Copy_U8Data to MUART3->DR.R
 *	activate MUART3
 *	MUART3 --> Code: Copy_U8Data assigned to MUART3->DR.R
 *	deactivate MUART3
 *
 *	Code -> MUART3: Check if MUART3->SR.B.TC is false
 *	activate MUART3
 *	alt (Condition is true)
 *	  MUART3 --> Code: Condition is true
 *	  Code -> Code: Continue loop
 *	  loop
 *	else (Condition is false)
 *	  MUART3 --> Code: Condition is false
 *	  Code -> Code: Break loop
 *	end
 *	deactivate MUART3
 *
 *	Code -> MUART3: Set MUART3->SR.B.TC to 0
 *	activate MUART3
 *	MUART3 --> Code: MUART3->SR.B.TC set to 0
 *	deactivate MUART3
 *
 *	deactivate Code
 *
 * \enduml 
 *
 * \section Activity_diagram
 *
 * \startuml
 *  start
 *  :Initialize MUART3->SR.B.TC to 0;
 *  :MUART3->DR.R = Copy_U8Data;
 *	repeat
 *	  :Check if MUART3->SR.B.TC is false;
 *	  if (Condition)
 *		--> repeat
 *	  else
 *		break
 *   endif
 *	repeat while (Condition)
 *	:MUART3->SR.B.TC = 0;
 * end
 * \enduml
 */
void USART3_VidSendChar(u8 Copy_U8Data)
{
    MUART3->SR.B.TC = 0;
    MUART3->DR.R = Copy_U8Data;
    while (!MUART3->SR.B.TC);
    MUART3->SR.B.TC = 0;
}
/***********************************[8]***********************************************
 * Service Name: USART1_TransmitSrring
 * Service ID[hex]: 0x08
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): pointer to string
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Transmit the  DataString .
 ************************************************************************************/
 /**
 * \section Service_Name
 * USART1_TransmitSrring
 *
 *
 * \section Service_ID_hex
 * 0x08
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  pointer to string
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * Void
 *
 * \section Description
 *  send a string of data.
 *
 * \section Sequence_diagram
 * \startuml
 *  actor User
 *
 * User -> Code: SendStringWithHash(string_Copy_U8Data)
 * activate Code
 *
 * Code -> Code: Initialize i to 0
 * Code -> Code: Check if string_Copy_U8Data[i] is not null
 * activate Code
 *
 * Code -> USART1: Send character string_Copy_U8Data[i]
 * activate USART1
 * USART1 --> Code: Character sent
 *
 * Code -> Code: Increment i
 * Code --> Code: Check if string_Copy_U8Data[i] is not null
 * deactivate Code
 *
 * Code -> Code: Check if string_Copy_U8Data[i] is not null
 * activate Code
 * Code -> USART1: Send character string_Copy_U8Data[i]
 * activate USART1
 * USART1 --> Code: Character sent
 *
  ... // Repeat the above steps until string_Copy_U8Data[i] is null
 
 * Code -> USART1: Send character '#'
 * activate USART1
 * USART1 --> Code: Character sent
 *
 * deactivate Code
 * \enduml 
 * \section Activity_diagram
 *
 * \startuml
 *  start
 * :Initialize i to 0;
 *  repeat
 * :Check if string_Copy_U8Data[i] is not null;
 * if (Condition)
 *  :Send string_Copy_U8Data[i] over USART1;
 *     --> Continue
 *    else
 *      break
 *    endif
 *     --> repeat
 *  repeat while (Condition)
 * :Send '#' over USART1;
 * stop
 * \enduml
 */

void USART1_TransmitSrring(u8 *string_Copy_U8Data)
{
    for (int i = 0 ; string_Copy_U8Data[i] != '\0' ; i++)
    	USART1_VidSendChar(string_Copy_U8Data[i]);
    USART1_VidSendChar('#');

}
/***********************************[9]***********************************************
 * Service Name: USART2_TransmitSrring
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): pointer to string
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Transmit the  DataString .
 ************************************************************************************/
 /**
 * \section Service_Name
 * USART2_TransmitSrring
 *
 *
 * \section Service_ID_hex
 * 0x09
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  pointer to string
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * Void
 *
 * \section Description
 *  send a string of data.
 *
 * \section Sequence_diagram
 * \startuml
 *  actor User
 *
 * User -> Code: SendStringWithHash(string_Copy_U8Data)
 * activate Code
 *
 * Code -> Code: Initialize i to 0
 * Code -> Code: Check if string_Copy_U8Data[i] is not null
 * activate Code
 *
 * Code -> USART2: Send character string_Copy_U8Data[i]
 * activate USART2
 * USART2 --> Code: Character sent
 *
 * Code -> Code: Increment i
 * Code --> Code: Check if string_Copy_U8Data[i] is not null
 * deactivate Code
 *
 * Code -> Code: Check if string_Copy_U8Data[i] is not null
 * activate Code
 * Code -> USART2: Send character string_Copy_U8Data[i]
 * activate USART2
 * USART2 --> Code: Character sent
 *
  ... // Repeat the above steps until string_Copy_U8Data[i] is null
 
 * Code -> USART2: Send character '#'
 * activate USART2
 * USART2 --> Code: Character sent
 *
 * deactivate Code
 * \enduml 
 *
 * \section Activity_diagram
 *
 * \startuml
 *  start
 * :Initialize i to 0;
 *  repeat
 * :Check if string_Copy_U8Data[i] is not null;
 * if (Condition)
 *  :Send string_Copy_U8Data[i] over USART2;
 *     --> Continue
 *    else
 *      break
 *    endif
 *     --> repeat
 *  repeat while (Condition)
 * :Send '#' over USART2;
 * stop
 * \enduml
 */

void USART2_TransmitSrring(u8 *string_Copy_U8Data)
{
    for (int i = 0 ; string_Copy_U8Data[i] != '\0' ; i++)
    	USART2_VidSendChar(string_Copy_U8Data[i]);
    USART2_VidSendChar('#');
}
/***********************************[10]***********************************************
 * Service Name: USART3_TransmitSrring
 * Service ID[hex]: 0x01A
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): pointer to string
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Transmit the  DataString .
 ************************************************************************************/
 /**
 * \section Service_Name
 * USART3_TransmitSrring
 *
 *
 * \section Service_ID_hex
 * 0x01A
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  pointer to string
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * Void
 *
 * \section Description
 *  send a string of data.
 *
 * \section Sequence_diagram
 * \startuml
 *  actor User
 *
 * User -> Code: SendStringWithHash(string_Copy_U8Data)
 * activate Code
 *
 * Code -> Code: Initialize i to 0
 * Code -> Code: Check if string_Copy_U8Data[i] is not null
 * activate Code
 *
 * Code -> USART3: Send character string_Copy_U8Data[i]
 * activate USART3
 * USART3 --> Code: Character sent
 *
 * Code -> Code: Increment i
 * Code --> Code: Check if string_Copy_U8Data[i] is not null
 * deactivate Code
 *
 * Code -> Code: Check if string_Copy_U8Data[i] is not null
 * activate Code
 * Code -> USART3: Send character string_Copy_U8Data[i]
 * activate USART3
 * USART3 --> Code: Character sent
 *
  ... // Repeat the above steps until string_Copy_U8Data[i] is null
 
 * Code -> USART3: Send character '#'
 * activate USART3
 * USART3 --> Code: Character sent
 *
 * deactivate Code
 * \enduml 
 *
 * \section Activity_diagram
 *
 * \startuml
 *  start
 * :Initialize i to 0;
 *  repeat
 * :Check if string_Copy_U8Data[i] is not null;
 * if (Condition)
 *  :Send string_Copy_U8Data[i] over USART3;
 *     --> Continue
 *    else
 *      break
 *    endif
 *     --> repeat
 *  repeat while (Condition)
 * :Send '#' over USART3;
 * stop
 * \enduml
 */

void USART3_TransmitSrring(u8 *string_Copy_U8Data)
{
    for (int i = 0 ; string_Copy_U8Data[i] != '\0' ; i++)
    	USART3_VidSendChar(string_Copy_U8Data[i]);
    USART3_VidSendChar('#');
}

/***********************************[11]***********************************************
 * Service Name: USART1_ReceiveString
 * Service ID[hex]: 0x0B
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: pointer to string
 * Description: Recieve the Sent DataString by the user.
 ************************************************************************************/
 
/**
 * \section Service_Name
 * USART1_ReceiveString
 *
 *
 * \section Service_ID_hex
 * 0x0B
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  None
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * pointer to string
 *
 * \section Description
 *  Recieve the Sent DataString by the user.
 * 
 * \section Sequence_diagram
 *
 * \startuml
 *  USART1ReceiveString -> USART1ReceiveByte: USART1_ReceiveByte()
 * \enduml
 *
 * \section Activity_diagram
 *
 * \startuml
 *  start
 *  :Initialize local variables;
 *  while (Reach end of the string) is (NO)
 *  :store the received data in the string;
 *  endwhile (YES)
 *  :put null terminator at the end of the string;
 *  :return recievedDataString;
 * end
 * \enduml
 */

u8* USART1_ReceiveString(void)
{
    u8 Copy_U8Data;
    int i;
    for (i = 0; (Copy_U8Data = USART1_ReceiveByte()) != '#'; i++)
    received_string1[i] = Copy_U8Data;
    received_string1[i] = '\0';
    return (received_string1) ;
}

/***********************************[12]***********************************************
 * Service Name: USART2_ReceiveString
 * Service ID[hex]: 0x0C
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: pointer to string
 * Description: Recieve the Sent DataString by the user.
 ************************************************************************************/
 
/**
 * \section Service_Name
 * USART2_ReceiveString
 *
 *
 * \section Service_ID_hex
 * 0x0C
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  None
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * pointer to string
 *
 * \section Description
 *  Recieve the Sent DataString by the user.
 *
 * \section Sequence_diagram
 *
 * \startuml
 *  USART2ReceiveString -> USART2ReceiveByte: USART2_ReceiveByte()
 * \enduml 
 *
 * \section Activity_diagram
 *
 * \startuml
 *  start
 *  :Initialize local variables;
 *  while (Reach end of the string) is (NO)
 *  :store the received data in the string;
 *  endwhile (YES)
 *  :put null terminator at the end of the string;
 *  :return recievedDataString;
 * end
 * \enduml
 */

u8* USART2_ReceiveString(void)
{
    u8 Copy_U8Data;
    int i;
    for (i = 0; (Copy_U8Data = USART2_ReceiveByte()) != '#'; i++)
    received_string2[i] = Copy_U8Data;
    received_string2[i] = '\0';
    return (received_string2) ;
}

/***********************************[13]***********************************************
 * Service Name: USART3_ReceiveString
 * Service ID[hex]: 0x0D
 * Sync/Async: Synchronous
 * Renterancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: pointer to string
 * Description: Recieve the Sent DataString by the user.
 ************************************************************************************/
 
/**
 * \section Service_Name
 * USART3_ReceiveString
 *
 *
 * \section Service_ID_hex
 * 0x0D
 *
 * \section Sync_Async
 * Synchronous
 *
 * \section Renterancy
 * Non-Reentrant
 *
 * \section Parameters_in
 *  None
 *
 * \section Parameters_InOut
 * None
 *
 * \section Parameters_Out
 * None
 *
 * \section Return_value
 * pointer to string
 *
 * \section Description
 *  Recieve the Sent DataString by the user.
 * 
 * \section Sequence_diagram
 *
 * \startuml
 *  USART3ReceiveString -> USART3ReceiveByte: USART3_ReceiveByte()
 * \enduml
 *
 * \section Activity_diagram
 *
 * \startuml
 *  start
 *  :Initialize local variables;
 *  while (Reach end of the string) is (NO)
 *  :store the received data in the string;
 *  endwhile (YES)
 *  :put null terminator at the end of the string;
 *  :return recievedDataString;
 * end
 * \enduml
 */

u8* USART3_ReceiveString(void)
{
    u8 Copy_U8Data;
    int i;
    for (i = 0; (Copy_U8Data = USART3_ReceiveByte()) != '#'; i++)
    received_string3[i] = Copy_U8Data;
    received_string3[i] = '\0';
    return (received_string3) ;
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

	MUART1->SR.R = 0 ;
	USART1_CallBack();
}

void USART2_IRQHandler(void){

	MUART2->SR.R = 0 ;
	USART1_CallBack();
}

void USART3_IRQHandler(void){

	MUART3->SR.R = 0 ;
	USART1_CallBack();
}
