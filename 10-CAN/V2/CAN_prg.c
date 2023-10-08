/*
 * CAN_prg.c
 *
 *  Created on: Sep 21, 2023
 *      Author: Ahmed
 */

#include "CAN_interface.h"
#include "CAN_private.h"
#include "CAN_cfg.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "DMA_interface.h"


/*********************      ERROR FLAGS		*******************/
u32 CAN_ErrorCode = CAN_ERROR_NONE;
/** BoudRate value **/
extern CAN_BitTimingConfig CAN_bitRateConfig[7];
extern CAN_Interrupt_Callbacks CAN_TxMailboxAbortCallback[3];
extern CAN_Interrupt_Callbacks CAN_TxMailboxCompleteCallback[3];



void CAN_voidInit(const CAN_Configurations *CAN_CFG)
{
    /**  Enable the CAN clock **/
	RCC_voidEnablePeripheralClock(RCC_APB1, RCC_CAN);
    /** Configure CAN pins **/
	Port_SetPinDirection(A12,OUTPUT_2);
	Port_SetPinDirection(A11,INPUT);
	Port_SetPinMode(A12, A_PUSH_PULL);
	Port_SetPinMode(A11, FLOATING_INPUT);
	/**  exit CAN sleep mode **/
	    /* CLEAR SLEEP bit */
	CAN->MCR.B.SLEEP = CAN_DISABLE;
    /* wait to exit sleep mode */
	while(!(CAN->MSR.B.SLAK) == CAN_DISABLE);
    /**  Set CAN Initialization mode **/
   /* SET Initialization request BIT (INRQ) */
	CAN->MCR.B.INRQ = CAN_ENABLE;
    /* wait to enter in Initialization mode */
    while(!(CAN->MSR.B.INAK) == CAN_ENABLE);

    /**	Transmit FIFO **/
    /* SET FIFO priority */
    CAN->MCR.B.TXFP	= CAN_CFG ->TransmitFifoPriority;
    /** CHECK Receive FIFO locked mode **/
    CAN->MCR.B.RFLM = CAN_CFG-> ReceiveFifoLocked;
    /** CHECK automatic retransmission **/
    CAN->MCR.B.NART = CAN_CFG-> AutoRetransmission;
    /** CHECK automatic wakeup mode **/
    CAN->MCR.B.AWUM = CAN_CFG-> AutoBussOff;
    /** CHECK automatic bus-off management **/
    CAN->MCR.B.ABOM = CAN_CFG->	AutoBussOff;
    /** CHECK Time triggered communication mode **/
    CAN->MCR.B.TTCM = CAN_CFG->	TimeTriggeredMode;
    /** Set BoudRate register **/
    CAN->BTR.Reg = (u32)(CAN_CFG->MODE | ((CAN_bitRateConfig[CAN_CFG->BOUDRATE].TS2-1) << 20) | ((CAN_bitRateConfig[CAN_CFG->BOUDRATE].TS1-1) << 16) | (CAN_bitRateConfig[CAN_CFG->BOUDRATE].BRP-1));
}


void CAN_voidStart(void)
{
	/* CLEAR Initialization request BIT (INRQ) */
	CAN->MCR.B.INRQ = CAN_ENABLE;
	/* wait to enter in Initialization mode */
	while (!CAN->MCR.B.INRQ == 0);
}


void CAN_voidTransmitMsg( CAN_TxHeaderTypeDef *pTxHeader, u8 Local_u8Data[])
{
	if ((CAN->TSR.B.TME0 != 0x0))  /* TME0 */
			{
		 /* Check transmit mailbox value */
				if((CAN->TSR.B.CODE) <= 2)
				{
					/* Set up the Id */
					if (CAN->TI0R.B.IDE == CAN_ID_STD)
					{
						CAN->TI0R.B.STID = pTxHeader -> StdId ;
						CAN->TI0R.B.RTR =  pTxHeader -> RTR;
					}
					else
					{
						CAN->TI0R.B.STID = pTxHeader -> StdId ;
						CAN->TI0R.B.EXID = pTxHeader -> ExtId ;
						CAN->TI0R.B.RTR =  pTxHeader -> RTR;

					}
					  /* Set up the DLC */
					CAN->TDT0R.B.DLC = pTxHeader->DLC;
					  /* Set up the Transmit Global Time mode */
					if (pTxHeader->TransmitGlobalTime == ENABLE)
						 {
							CAN->TDT0R.B.TGT = CAN_ENABLE;
						 }
					  /* Set up the Local_u8Data field */
					CAN->TDL0R.B.DATA0 = Local_u8Data[0];
					CAN->TDL0R.B.DATA1 = Local_u8Data[1];
					CAN->TDL0R.B.DATA2 = Local_u8Data[2];
					CAN->TDL0R.B.DATA3 = Local_u8Data[3];

					CAN->TDH0R.B.DATA4 = Local_u8Data[4];
					CAN->TDH0R.B.DATA5 = Local_u8Data[5];
					CAN->TDH0R.B.DATA6 = Local_u8Data[6];
					CAN->TDH0R.B.DATA7 = Local_u8Data[7];
					/* ENABLE CAN */
					CAN->TI0R.B.TXRQ = CAN_ENABLE;
				}
			}
	else if ((CAN->TSR.B.TME1 != 0x0)) /* TME1 */
	{
		 /* Check transmit mailbox value */
		if((CAN->TSR.B.CODE) <= 2)
			{
			/* Set up the Id */
			if (CAN->TI1R.B.IDE == CAN_ID_STD)
				{
					CAN->TI1R.B.STID = pTxHeader -> StdId ;
					CAN->TI1R.B.RTR =  pTxHeader -> RTR;
				}
			else
				{
					CAN->TI1R.B.STID = pTxHeader -> StdId ;
					CAN->TI1R.B.EXID = pTxHeader -> ExtId ;
					CAN->TI1R.B.RTR =  pTxHeader -> RTR;
				}
			  /* Set up the DLC */
					CAN->TDT1R.B.DLC = pTxHeader->DLC;
					  /* Set up the Transmit Global Time mode */
					if (pTxHeader->TransmitGlobalTime == ENABLE)
						 {
							CAN->TDT1R.B.TGT = CAN_ENABLE;
						 }
					  /* Set up the Local_u8Data field */
					CAN->TDL1R.B.DATA0 = Local_u8Data[0];
					CAN->TDL1R.B.DATA1 = Local_u8Data[1];
					CAN->TDL1R.B.DATA2 = Local_u8Data[2];
					CAN->TDL1R.B.DATA3 = Local_u8Data[3];

					CAN->TDH1R.B.DATA4 = Local_u8Data[4];
					CAN->TDH1R.B.DATA5 = Local_u8Data[5];
					CAN->TDH1R.B.DATA6 = Local_u8Data[6];
					CAN->TDH1R.B.DATA7 = Local_u8Data[7];
					/* ENABLE CAN */
					CAN->TI1R.B.TXRQ = CAN_ENABLE;
			}

	}

	else if ((CAN->TSR.B.TME2 != 0x0) ) /* TME2 */
	{
		 /* Check transmit mailbox value */
		if((CAN->TSR.B.CODE) <= 2)
			{
			/* Set up the Id */
				if (CAN->TI2R.B.IDE == CAN_ID_STD)
					{
						CAN->TI2R.B.STID = pTxHeader -> StdId ;
						CAN->TI2R.B.RTR =  pTxHeader -> RTR;
					}
				else
					{
						CAN->TI2R.B.STID = pTxHeader -> StdId ;
						CAN->TI2R.B.EXID = pTxHeader -> ExtId ;
						CAN->TI2R.B.RTR =  pTxHeader -> RTR;
					}
				  /* Set up the DLC */
						CAN->TDT2R.B.DLC = pTxHeader->DLC;
						  /* Set up the Transmit Global Time mode */
						if (pTxHeader->TransmitGlobalTime == ENABLE)
							 {
								CAN->TDT2R.B.TGT = CAN_ENABLE;
							 }
						  /* Set up the Local_u8Data field */
						CAN->TDL2R.B.DATA0 = Local_u8Data[0];
						CAN->TDL2R.B.DATA1 = Local_u8Data[1];
						CAN->TDL2R.B.DATA2 = Local_u8Data[2];
						CAN->TDL2R.B.DATA3 = Local_u8Data[3];

						CAN->TDH2R.B.DATA4 = Local_u8Data[4];
						CAN->TDH2R.B.DATA5 = Local_u8Data[5];
						CAN->TDH2R.B.DATA6 = Local_u8Data[6];
						CAN->TDH2R.B.DATA7 = Local_u8Data[7];
						/* ENABLE CAN */
						CAN->TI2R.B.TXRQ = CAN_ENABLE;
			}
	}
	else
	{

		// do nothing
	}
}
void CAN_voidRecieveMsg(u32 local_u8RxFifo, CAN_RxHeaderTypeDef *pRxHeader, u8 Local_u8Data[])
{
	if(local_u8RxFifo == 0)
	{
		/* GET Id */
	pRxHeader->IDE =  CAN->RI0R.B.IDE;
    if (pRxHeader->IDE == CAN_ID_STD)
    {
        pRxHeader->StdId = CAN->RI0R.B.STID;
    }
    else
    {
        pRxHeader->StdId = CAN->RI0R.B.STID;
        pRxHeader->ExtId = CAN->RI0R.B.EXID;
    }
    /* GET the RTR */
    pRxHeader->RTR = CAN->RI0R.B.RTR;
    /* GET the DLC */
    pRxHeader->DLC = CAN->RDT0R.B.DLC;
    /* GET the FMI */
    pRxHeader->FilterMatchIndex = CAN->RDT0R.B.FMI;
    /* GET the Time stamp */
    pRxHeader->TimeStamp = CAN->RDT0R.B.TIME;

    /* Transmit the data */

    	for(u8 i=0 ; i < 8 ; i++)
    		{/*clear buff*/
    			Local_u8Data[i] = 0;
    		}
		for(u8 i=0 ; i < pRxHeader->DLC ; i++)
		{
			if(i<4)
				Local_u8Data[i] = (u8)((CAN->RDL0R.B.DATA[i]));
			else
				Local_u8Data[i] = (u8)((CAN->RDH0R.B.DATA[i-4]));
		}
	}
	else
	{
		pRxHeader->IDE =  CAN->RI1R.B.IDE;
	    if (pRxHeader->IDE == CAN_ID_STD)
	    {
	        pRxHeader->StdId = CAN->RI1R.B.STID;
	    }
	    else
	    {
	        pRxHeader->StdId = CAN->RI1R.B.STID;
	        pRxHeader->ExtId = CAN->RI1R.B.EXID;
	    }
	    pRxHeader->RTR = CAN->RI1R.B.RTR;
	    pRxHeader->DLC = CAN->RDT1R.B.DLC;
	    pRxHeader->FilterMatchIndex = CAN->RDT1R.B.FMI;
	    pRxHeader->TimeStamp = CAN->RDT1R.B.TIME;

	    	for(u8 i=0 ; i < 8 ; i++)
	    		{/*clear buff*/
	    			Local_u8Data[i] = 0;
	    		}
			for(u8 i=0 ; i < pRxHeader->DLC ; i++)
			{
				if(i<4)
					Local_u8Data[i] = (u8)((CAN->RDL1R.B.DATA[i]));
				else
					Local_u8Data[i] = (u8)((CAN->RDH1R.B.DATA[i-4]));
			}

	}
    	/* Release the FIFO */
        if (local_u8RxFifo == CAN_RX_FIFO0)
        {
          /* Release RX FIFO 0 */
          CAN->RF0R.B.RFOM0 = CAN_ENABLE;
        }
        else
        {
          /* Release RX FIFO 1 */
            CAN->RF1R.B.RFOM1 = CAN_ENABLE;
        }
}
u8 CAN_voidRXPending(u8 local_u8RxFifo)
{
	/* return the Rx FIFO  message pending */
		if (local_u8RxFifo == CAN_RX_FIFO0) /* Rx element is assigned to Rx FIFO 0 */
		{
			/* return value of the Rx FIFO 0  */
		 return (CAN->RF0R.B.FMP0);

		}
		else /* Rx element is assigned to Rx FIFO 1 */
		{
			/* return value of the Rx FIFO 1  */
			 return (CAN->RF1R.B.FMP1);
		}

}
/*
void CAN_voidConfigFilter( CAN_FilterTypeDef *pFilterConfig)
{
	CAN->FMR.B.FINIT = CAN_ENABLE;







	CAN->FMR.B.FINIT = CAN_DISABLE;
}*/

u32 CAN_voidGetErrorCode(void)
{
	return CAN_ErrorCode;
}

void CAN_voidInitInterput(u8 IRQn)
{

	MNVIC_VidPerhiralEnable(IRQn);
	MNVIC_VidSetPending(IRQn);

}
void CAN_voidDeinterputInit(u8 IRQn)
{
	MNVIC_VidPerhiralDisable(IRQn);
	MNVIC_VidClearPending(IRQn);

}
void CAN_voidEnableInterrupt(u32 local_u32ActiveITs)
{
	CAN->IER.Reg |= local_u32ActiveITs;
}
void CAN_voidDisableInterrupt(u32 local_u32ActiveITs)
{
	CAN->IER.Reg &= ~ local_u32ActiveITs;
}

/*************************** 	CAN TX Interrupt Handler	 *********************/
void CAN_voidTX_Interrupt_Handler(void)
{
	 CAN_ErrorCode  = CAN_ERROR_NONE;

		/* Transmit Mailbox [0:2] management *****************************************/
	 for (u8 counter = 0 ; counter <= 16 ; counter += 8 )
	 {
		 switch(counter)
		 {
		 case 0:
		 if (CAN->TSR.B.RQCP0 != 0)/* RQCP: Request completed mailbox [0:2] */
		 {
			  /* Clear the Transmission Complete flag (and TXOK,ALST,TERR0 bits) */
			 CAN->TSR.B.RQCP0 = CAN_ENABLE;     /* RQCP: Request completed mailbox [0:2] */
			 if (CAN->TSR.B.TXOK0 != 0) /* TXOK: Transmission OK of mailbox [0:2] */

					/* Transmission Mailbox complete callback */
			 			CAN_TxMailboxCompleteCallback[counter/8]();
			 else
			 {
			 	if (CAN->TSR.B.ALST0 != 0) /* ALST: Arbitration lost for mailbox [0:2] */
					  /* Update error code */
			 		CAN_ErrorCode |= CAN_ERROR_TX_ALST0;
				else if (CAN->TSR.B.TERR0 != 0)/* TERR: Transmission error of mailbox [0:2] */
					  /* Update error code */
					CAN_ErrorCode |= CAN_ERROR_TX_TERR0;
			 	else
			 		CAN_TxMailboxAbortCallback[counter/8]();
			   }
		 }
			 break;
		 case 8:
			 if (CAN->TSR.B.RQCP1 != 0)
			 {
				 CAN->TSR.B.RQCP1 = CAN_ENABLE;
				 if (CAN->TSR.B.TXOK1 != 0)
				 			CAN_TxMailboxCompleteCallback[counter/8]();
				 else
				 {
				 	if (CAN->TSR.B.ALST1 != 0)
				 		CAN_ErrorCode |= CAN_ERROR_TX_ALST0;
					else if (CAN->TSR.B.TERR1 != 0)
						CAN_ErrorCode |= CAN_ERROR_TX_TERR0;
				 	else
				 		CAN_TxMailboxAbortCallback[counter/8]();
				 }
			 }
			 break;

		 case 16:
			 if (CAN->TSR.B.RQCP2 != 0)
			 {
				 CAN->TSR.B.RQCP2 = CAN_ENABLE;
				 if (CAN->TSR.B.TXOK2 != 0)
				 			CAN_TxMailboxCompleteCallback[counter/8]();
				 else
				 {
				 	if (CAN->TSR.B.ALST2 != 0)
				 		CAN_ErrorCode |= CAN_ERROR_TX_ALST0;
					else if (CAN->TSR.B.TERR2 != 0)
						CAN_ErrorCode |= CAN_ERROR_TX_TERR0;
				 	else
				 		CAN_TxMailboxAbortCallback[counter/8]();
				 }
			 }
			 break;
		 }}

	 /* Call the Error call Back in case of Errors */
	 	if (CAN_ErrorCode != CAN_ERROR_NONE)
	 	{
	 		/* Call Error callback function */
	 		CAN_ErrorCallback();
	 	}
}

/*************************  CAN RX FIFO 0 Interrupt Handler *****************************/
void CAN_voidRX_FIFO0_Interrupt_Handler(void)
{
	 CAN_ErrorCode  = CAN_ERROR_NONE;
	 if (CAN -> IER.B.FOVIE0 != CAN_DISABLE) /* FOVIE0: FIFO overrun interrupt enable */
	 	{
	 		if (CAN->RF0R.B.FOVR0 != CAN_DISABLE) /* FOVR0: FIFO 0 overrun */
	 		{
	 		  /* Set CAN error code to Rx Fifo 0 overrun error */
	 		  CAN_ErrorCode |= CAN_ERROR_RX_FOV0;

	 		  /* Clear FIFO0 Overrun Flag */
	 		 CAN->RF0R.B.FULL0 = CAN_ENABLE;
	 		}
	 	}
	 if (CAN -> IER.B.ERRIE != 0) /* FFIE0: FIFO full interrupt enable */
	 	{
	 		if (CAN->RF0R.B.FULL0 != 0) /* FULL0: FIFO 0 full */
	 		{
	 		  /* Clear FIFO 0 full Flag */
	 			CAN->RF0R.B.FULL0 = CAN_ENABLE;

	 		  /* Receive FIFO 0 full Callback */
	 		  /* Call weak (surcharged) callback */
	 		  CAN_RxFifo0FullCallback();
	 		}
	 	}
	 if (CAN -> IER.B.EPVIE != 0) /* FMPIE0: FIFO message pending interrupt enable */
	 	{
	 		/* Check if message is still pending */
	 		if (CAN->RF0R.B.FMP0 != 0) /* FMP0[1:0]: FIFO 0 message pending */
	 		{
	 		  /* Receive FIFO 0 mesage pending Callback */
	 		  /* Call weak (surcharged) callback */
	 		  CAN_RxFifo0MsgPendingCallback();
	 		}
	 	}
	 	/* Call the Error call Back in case of Errors */
	 	if (CAN_ErrorCode != CAN_ERROR_NONE)
	 	{
	 		/* Call Error callback function */
	 		CAN_ErrorCallback();
	 	}

}

/*************************  CAN RX FIFO 1 Interrupt Handler *****************************/
void CAN_voidRX_FIFO1_Interrupt_Handler(void)
{
	 CAN_ErrorCode  = CAN_ERROR_NONE;
	 /* Receive FIFO 1 overrun interrupt management *****************************/
	 	  if (CAN->IER.B.FOVIE1 != CAN_DISABLE) /* FOVIE1: FIFO overrun interrupt enable */
	 	  {
	 		if (CAN -> RF1R.B.FOVR1 != CAN_DISABLE) /* FOVR1: FIFO 1 overrun */
	 		{
	 		  /* Set CAN error code to Rx Fifo 1 overrun error */
	 		  CAN_ErrorCode |= CAN_ERROR_RX_FOV1;

	 		  /* Clear FIFO1 Overrun Flag */
	 		  CAN->RF1R.B.FOVR1 = CAN_ENABLE;
	 		}
	 	  }

	 	  /* Receive FIFO 1 full interrupt management ********************************/
	 	  if (CAN->IER.B.FFIE1 != 0) /* FFIE1: FIFO full interrupt enable */
	 	  {
	 		if (CAN -> RF1R.B.FULL1 != 0) /* FULL1: FIFO 1 full */
	 		{
	 		  /* Clear FIFO 1 full Flag */
	 			CAN->RF1R.B.FULL1 = CAN_ENABLE;

	 		  /* Receive FIFO 1 full Callback */
	 		  /* Call weak (surcharged) callback */
	 		  CAN_RxFifo1FullCallback();
	 		}
	 	  }

	 	  /* Receive FIFO 1 message pending interrupt management *********************/
	 	if (CAN->IER.B.FMPIE1 != 0) /* FMPIE1: FIFO message pending interrupt enable */
	 	{
	 		/* Check if message is still pending */
	 		if (CAN -> RF1R.B.FMP1 != 0) /* FMP1[1:0]: FIFO 0 message pending */
	 		{
	 		  /* Receive FIFO 1 mesage pending Callback */
	 		  /* Call weak (surcharged) callback */
	 		  CAN_RxFifo1MsgPendingCallback();
	 		}
	 	}
	 	  /* Call the Error call Back in case of Errors */
	 	if (CAN_ErrorCode != CAN_ERROR_NONE)
	 	{
	 		/* Call Error callback function */
	 		CAN_ErrorCallback();
	 	}
}

/*************************** CAN SCE (Status Change Error) Interrupt Handler *********************/
void CAN_voidSCE_Interrupt_Handler(void)
{
	 CAN_ErrorCode  = CAN_ERROR_NONE;
	 /* Sleep interrupt management *********************************************/
		  if (CAN->IER.B.SLKIE != CAN_DISABLE) /* SLKIE: Sleep interrupt enable */
		  {
		    if (CAN->MSR.B.SLAKI != CAN_DISABLE) /* SLAKI: Sleep acknowledge interrupt */
		    {
		      /* Clear Sleep interrupt Flag */
		    	CAN->MSR.B.SLAKI = CAN_ENABLE; /* SLAKI: Sleep acknowledge interrupt */

		      /* Sleep Callback */
		      CAN_SleepCallback();
		    }
		  }

		  /* WakeUp interrupt management *********************************************/
		  if (CAN->IER.B.WKUIE != CAN_DISABLE) /* WKUIE: Wakeup interrupt enable */
		  {
		    if (CAN->MSR.B.WKUI != CAN_DISABLE) /* WKUI: Wakeup interrupt */
		    {
		      /* Clear WakeUp Flag */
		    	CAN->MSR.B.WKUI = CAN_ENABLE; /* WKUI: Wakeup interrupt */

		      /* WakeUp Callback */
		      CAN_WakeUpFromRxMsgCallback();
		    }
		  }

		  /* Error interrupts management *********************************************/
		  if (CAN->IER.B.ERRIE != CAN_DISABLE) /* ERRIE: Error interrupt enable */
		  {
			 if (CAN->MSR.B.ERRI != CAN_DISABLE) /* ERRI: Error interrupt */
		    {
		      /* Check Error Warning Flag */
		      if ((CAN->IER.B.EWGIE != CAN_DISABLE) && /* EWGIE: Error warning interrupt enable*/
		          (CAN->ESR.B.EWGF != CAN_DISABLE)) /* EWGF: Error warning flag */
		      {
		        /* Set CAN error code to Error Warning */
		        CAN_ErrorCode |= CAN_ERROR_EWG;

		        /* No need for clear of Error Warning Flag as read-only */
		      }

		      /* Check Error Passive Flag */
		      if ((CAN->IER.B.EPVIE != CAN_DISABLE) && /* EPVIE: Error passive interrupt enable*/
		    		  (CAN->ESR.B.EPVF != CAN_DISABLE)) /* EPVF: Error passive flag */
		      {
		        /* Set CAN error code to Error Passive */
		        CAN_ErrorCode |= CAN_ERROR_EPV;

		        /* No need for clear of Error Passive Flag as read-only */
		      }

		      /* Check Bus-off Flag */
		      if ((CAN->IER.B.BOFIE != CAN_DISABLE) && /* BOFIE: Bus-off interrupt enable */
		    		  (CAN->ESR.B.BOFF != CAN_DISABLE)) /* BOFF: Bus-off flag */
		      {
		        /* Set CAN error code to Bus-Off */
		        CAN_ErrorCode |= CAN_ERROR_BOF;

		        /* No need for clear of Error Bus-Off as read-only */
		      }
		      /* Check Last Error Code Flag */
		      if ((CAN->IER.B.LECIE != CAN_DISABLE) && /* LECIE: Last error code interrupt enable */
		          (CAN->ESR.B.LEC != CAN_DISABLE)) /* LEC[2:0]: Last error code */
		      {
		        switch (CAN->ESR.B.LEC)  // 7=0b111 /* LEC[2:0]: Last error code */
		        {
		          case (0x1):
		            /* Set CAN error code to Stuff error */
		            CAN_ErrorCode |= CAN_ERROR_STF;
		            break;
		          case (0x2):
		            /* Set CAN error code to Form error */
		            CAN_ErrorCode |= CAN_ERROR_FOR;
		            break;
		          case (0x3):
		            /* Set CAN error code to Acknowledgement error */
		            CAN_ErrorCode |= CAN_ERROR_ACK;
		            break;
		          case (0x4):
		            /* Set CAN error code to Bit recessive error */
		            CAN_ErrorCode |= CAN_ERROR_BR;
		            break;
		          case (0x5):
		            /* Set CAN error code to Bit Dominant error */
		            CAN_ErrorCode |= CAN_ERROR_BD;
		            break;
		          case (0x6):
		            /* Set CAN error code to CRC error */
		            CAN_ErrorCode |= CAN_ERROR_CRC;
		            break;
		          default:
		            break;
		        }

		        /* Clear Last error code Flag */
		        CAN->ESR.B.LEC = CAN_DISABLE; /* ERRI: Error interrupt */
		      }
		    }

		    /* Clear ERRI Flag */
		    CAN->MSR.B.ERRI = CAN_ENABLE; /* ERRI: Error interrupt */
		  }
	  /* Call the Error call Back in case of Errors */
	  if (CAN_ErrorCode != CAN_ERROR_NONE)
	  {
	    /* Call Error callback function */
	    CAN_ErrorCallback();
	  }

}

/*
 * #######################################################################
 * 						CAN_Interrupt_IRQHandler
 * #######################################################################
 */
void USB_HP_CAN1_TX_IRQHandler(void) /* USB High Priority or CAN1 TX */
{
	CAN_voidTX_Interrupt_Handler();
}
void USB_LP_CAN1_RX0_IRQHandler(void) /* USB Low  Priority or CAN1 RX0 */
{
	CAN_voidRX_FIFO0_Interrupt_Handler();
}
void CAN1_RX1_IRQHandler(void) /* CAN1 RX1 */
{
	CAN_voidRX_FIFO1_Interrupt_Handler();
}
void CAN1_SCE_IRQHandler(void) /* CAN1 SCE */
{
	CAN_voidSCE_Interrupt_Handler();
}


