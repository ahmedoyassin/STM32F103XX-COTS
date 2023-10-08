/*
 * CAN_cfg.c
 *
 *  Created on: Sep 21, 2023
 *      Author: Ahmed Yassin
 */


#include "CAN_interface.h"
#include "CAN_private.h"

CAN_BitTimingConfig CAN_bitRateConfig[7] = {{2, 13, 45}, {2, 15, 20}, {2, 13, 18}, {2, 13, 9}, {2, 15, 4},{2, 12, 3}, {2, 15, 2}};
/*********************** CallBack array of function ***************************/
CAN_Interrupt_Callbacks CAN_TxMailboxCompleteCallback[3] = {&CAN_TxMailbox0CompleteCallback,
															&CAN_TxMailbox1CompleteCallback,
															&CAN_TxMailbox2CompleteCallback};

CAN_Interrupt_Callbacks CAN_TxMailboxAbortCallback[3] = {&CAN_TxMailbox0AbortCallback,
														&CAN_TxMailbox1AbortCallback,
														&CAN_TxMailbox2AbortCallback};



CAN_Configurations CANOfUART=
		{
				CAN_ENABLE,
				CAN_ENABLE,
				CAN_DISABLE,
				CAN_DISABLE,
				CAN_DISABLE,
				CAN_DISABLE,
				CAN_MODE_NORMAL,
				CAN_250KBPS
		};
