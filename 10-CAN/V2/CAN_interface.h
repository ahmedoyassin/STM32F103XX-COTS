/*
 * CAN_interface.h
 *
 *  Created on: Sep 21, 2023
 *      Author: Ahmed
 */

#ifndef CAN_INTERFACE_H_
#define CAN_INTERFACE_H_



#include "CAN_private.h"
#include "CAN_cfg.h"



/** @defgroupCAN CAN_Activation  CAN Activation **/
typedef enum
{
	CAN_DISABLE,
	CAN_ENABLE
}CAN_Activation;


/** @defgroup CAN_identifier_type CAN Identifier Type **/
typedef enum
{
	CAN_ID_STD = ((u32)(0x0)),
	CAN_ID_EXT = ((u32)(0x4))
}CAN_identifier_type;

/** @defgroup CAN_remote_transmission_request CAN Remote Transmission Request **/
typedef enum
{
	CAN_RTR_DATA = ((u32)(0x0)),
	CAN_RTR_REMOTEFLAG = ((u32)(0x1)),
	CAN_RTR_REMOTE = ((u32)(0x02))
}CAN_remote_transmission_request;


/** @defgroup CAN_receive_FIFO_number CAN Receive FIFO Number **/
typedef enum
{
	CAN_RX_FIFO0            =    ((u32)(0x0)),
	CAN_RX_FIFO1            =    ((u32)(0x1))
}CAN_receive_FIFO_number;

typedef enum
{
	CAN_FILTER_FIFO0        =    ((u32)(0x0)),
	CAN_FILTER_FIFO1        =    ((u32)(0x1))
}CAN_filter_FIFO;

typedef enum
{
	CAN_FILTERMODE_IDMASK   =    ((u32)(0x0)),
	CAN_FILTERMODE_IDLIST   =    ((u32)(0x1))
}CAN_filter_mode;

typedef enum
{
	CAN_FILTERSCALE_16BIT = ((u32)(0x0)),
	CAN_FILTERSCALE_32BIT = ((u32)(0x1))
}CAN_filter_scale;

typedef enum
{
	CAN_TX_IRQn = 19,
	CAN_RX0_IRQn,
	CAN_RX1_IRQn,
	CAN_SCE_IRQn
}CAN_IRQn;

/**
 * =============================================================================================
 *     					### CAN INE Bits definition
 *=============================================================================================
 **/
/** @defgroup CAN_Interrupts CAN Interrupts **/

/* Transmit Interrupt */
typedef enum
{
	CAN_IER_TX_MAILBOX_EMPTY = ((u32)(0x1))
}Transmit_Interrupt;

/* Receive Interrupts */
typedef enum
{
	CAN_IER_RX_FIFO0_MSG_PENDING	=	((u32)(0x2 )),
	CAN_IER_RX_FIFO0_FULL        	=	((u32)(0x4 )),
	CAN_IER_RX_FIFO0_OVERRUN     	=	((u32)(0x8 )),
	CAN_IER_RX_FIFO1_MSG_PENDING 	=	((u32)(0x10)),
	CAN_IER_RX_FIFO1_FULL        	=	((u32)(0x20)),
	CAN_IER_RX_FIFO1_OVERRUN    	=	((u32)(0x40))
}Receive_Interrupts;

/* Operating Mode Interrupts */
typedef enum
{
	CAN_IER_WAKEUP           =  	  ((u32)(1<<16)),
	CAN_IER_SLEEP_ACK        =    	((u32)(1<<17))
}Mode_Interrupts;

/*  */
typedef enum
{
	CAN_IER_ERROR_WARNING       = 	((u32)(1<<8 )),
	CAN_IER_ERROR_PASSIVE       = 	((u32)(1<<9 )),
	CAN_IER_BUSOFF              = 	((u32)(1<<10)),
	CAN_IER_LAST_ERROR_CODE     = 	((u32)(1<<11)),
	CAN_IER_ERROR               = 	((u32)(1<<15))
}Error_Interrupts;

/**
 * =============================================================================================
 *     					### CAN ERROR definition
 *=============================================================================================
 **/

/** @defgroup CAN_Error_Code CAN Error Code **/
typedef enum
{
	CAN_ERROR_NONE      =      (0x00000000U),
	CAN_ERROR_EWG       =      (0x00000001U),
	CAN_ERROR_EPV       =      (0x00000002U),
	CAN_ERROR_BOF       =      (0x00000004U),
	CAN_ERROR_STF       =      (0x00000008U),
	CAN_ERROR_FOR       =      (0x00000010U),
	CAN_ERROR_ACK       =      (0x00000020U),
	CAN_ERROR_BR        =      (0x00000040U),
	CAN_ERROR_BD        =      (0x00000080U),
	CAN_ERROR_CRC       =      (0x00000100U),
	CAN_ERROR_RX_FOV0   =      (0x00000200U),
	CAN_ERROR_RX_FOV1   =      (0x00000400U),
	CAN_ERROR_TX_ALST0  =      (0x00000800U),
	CAN_ERROR_TX_TERR0  =      (0x00001000U),
	CAN_ERROR_TX_ALST1  =      (0x00002000U),
	CAN_ERROR_TX_TERR1  =      (0x00004000U),
	CAN_ERROR_TX_ALST2  =      (0x00008000U),
	CAN_ERROR_TX_TERR2  =      (0x00010000U)
}CAN_Error_Code;


typedef struct
{
 u32 StdId : 11;
 u32 ExtId : 18;
 u32 IDE;
 u32 RTR;
 u32 DLC;
 u32 TimeStamp; // Only for RxHeader.
 u8 TransmitGlobalTime;
 u32 FilterMatchIndex;
} CAN_TxHeaderTypeDef, CAN_RxHeaderTypeDef;



/*************** 		CFG.C FILE 		***********************/

typedef struct
{
	CAN_Activation AutoRetransmission;
	CAN_Activation AutoBussOff;
	CAN_Activation AutoWakeUp;
	CAN_Activation TimeTriggeredMode;
	CAN_Activation ReceiveFifoLocked;
	CAN_Activation TransmitFifoPriority;
	MODE_TYPE MODE;
	BOUDRATE_TYPE BOUDRATE;
}CAN_Configurations;
CAN_Configurations CANOfUART;



/***************   Function definition    ******************/

void CAN_voidInit(const CAN_Configurations *CAN_CFG);
void CAN_voidStart(void);
void CAN_voidTransmitMsg( CAN_TxHeaderTypeDef *pTxHeader, u8 Local_u8Data[]);
void CAN_voidRecieveMsg(u32 local_u8RxFifo, CAN_RxHeaderTypeDef *pRxHeader, u8 Local_u8Data[]);
u8 CAN_voidRXPending(u8 local_u8RxFifo);
//void CAN_voidConfigFilter( CAN_FilterTypeDef *pFilterConfig);
u32 CAN_voidGetErrorCode(void);







/********************** Interrupt functions *******************/



void CAN_voidInitInterput(u8 IRQn);
void CAN_voidDeinterputInit(u8 IRQn);
void CAN_voidEnableInterrupt(u32 local_u32ActiveITs);
void CAN_voidDisableInterrupt(u32 local_u32ActiveITs);

void CAN_voidRX_FIFO0_Interrupt_Handler(void);
void CAN_voidRX_FIFO1_Interrupt_Handler(void);
void CAN_voidSCE_Interrupt_Handler(void); /* Status Change Error Interrupt Handler */









/*************	 Callbacks functions 	************************/



void CAN_TxMailbox0CompleteCallback();
void CAN_TxMailbox1CompleteCallback();
void CAN_TxMailbox2CompleteCallback();
void CAN_TxMailbox0AbortCallback();
void CAN_TxMailbox1AbortCallback();
void CAN_TxMailbox2AbortCallback();
void CAN_RxFifo0MsgPendingCallback();
void CAN_RxFifo0FullCallback();
void CAN_RxFifo1MsgPendingCallback();
void CAN_RxFifo1FullCallback();
void CAN_SleepCallback();
void CAN_WakeUpFromRxMsgCallback();
void CAN_ErrorCallback();







#endif /* CAN_INTERFACE_H_ */
