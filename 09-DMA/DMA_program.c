#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"


void (*fptr_t)(void) = NULL;


fptr_t Global_pfArr[7] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};


void DMA_u8DMAChannelInit(DMA_configStruct_t* Copy_pstructDMAChannelConfig)
{
	switch(Copy_pstructDMAChannelConfig -> Copy_U8ChannelNumber)
	{
		case DMA_CHANNEL1:

			DMA -> CCR1 = 0;
			DMA -> CCR1.PL = Copy_U8ChannelPriority;
			DMA -> CCR1.PSIZE = Copy_U8DataSize;
			DMA -> CCR1.MSIZE = Copy_U8DataSize;
			DMA -> CCR1.MINC = Copy_U8IncrementMode;
			DMA -> CCR1.PINC = Copy_U8IncrementMode;
			DMA -> CCR1.EN = Copy_U8EnableTCInt;

			if( (Copy_pstructDMAChannelConfig -> Copy_U8ataTransferType) == DMA_MEM_TO_MEM)
			{
				DMA -> CCR1.MEM2MEM = 1;
			}
			else
			{
				DMA -> CCR1.DIR = Copy_U8DataTransferType;
			}
			break;

		case DMA_CHANNEL2:

			DMA -> CCR2 = 0;
			DMA -> CCR2.PL = Copy_U8ChannelPriority;
			DMA -> CCR2.PSIZE = Copy_U8DataSize;
			DMA -> CCR2.MSIZE = Copy_U8DataSize;
			DMA -> CCR2.MINC = Copy_U8IncrementMode;
			DMA -> CCR2.PINC = Copy_U8IncrementMode;
			DMA -> CCR2.EN = Copy_U8EnableTCInt;

			if( (Copy_pstructDMAChannelConfig -> Copy_U8ataTransferType) == DMA_MEM_TO_MEM)
			{
				DMA -> CCR2.MEM2MEM = 1;
			}
			else
			{
				DMA -> CCR2.DIR = Copy_U8DataTransferType;
			}
			break;

		case DMA_CHANNEL3:

			DMA -> CCR3 = 0;
			DMA -> CCR3.PL = Copy_U8ChannelPriority;
			DMA -> CCR3.PSIZE = Copy_U8DataSize;
			DMA -> CCR3.MSIZE = Copy_U8DataSize;
			DMA -> CCR3.MINC = Copy_U8IncrementMode;
			DMA -> CCR3.PINC = Copy_U8IncrementMode;
			DMA -> CCR3.EN = Copy_U8EnableTCInt;

			if( (Copy_pstructDMAChannelConfig -> Copy_U8ataTransferType) == DMA_MEM_TO_MEM)
			{
				DMA -> CCR3.MEM2MEM = 1;
			}
			else
			{
				DMA -> CCR3.DIR = Copy_U8DataTransferType;
			}
			break;

		case DMA_CHANNEL4:


			DMA -> CCR4 = 0;
			DMA -> CCR4.PL = Copy_U8ChannelPriority;
			DMA -> CCR4.PSIZE = Copy_U8DataSize;
			DMA -> CCR4.MSIZE = Copy_U8DataSize;
			DMA -> CCR4.MINC = Copy_U8IncrementMode;
			DMA -> CCR4.PINC = Copy_U8IncrementMode;
			DMA -> CCR4.EN = Copy_U8EnableTCInt;

			if( (Copy_pstructDMAChannelConfig -> Copy_U8ataTransferType) == DMA_MEM_TO_MEM)
			{
				DMA -> CCR4.MEM2MEM = 1;
			}
			else
			{
				DMA -> CCR4.DIR = Copy_U8DataTransferType;
			}
			break;

		case DMA_CHANNEL5:


			DMA -> CCR5 = 0;
			DMA -> CCR5.PL = Copy_U8ChannelPriority;
			DMA -> CCR5.PSIZE = Copy_U8DataSize;
			DMA -> CCR5.MSIZE = Copy_U8DataSize;
			DMA -> CCR5.MINC = Copy_U8IncrementMode;
			DMA -> CCR5.PINC = Copy_U8IncrementMode;
			DMA -> CCR5.EN = Copy_U8EnableTCInt;

			if( (Copy_pstructDMAChannelConfig -> Copy_U8ataTransferType) == DMA_MEM_TO_MEM)
			{
				DMA -> CCR5.MEM2MEM = 1;
			}
			else
			{
				DMA -> CCR5.DIR = Copy_U8DataTransferType;
			}
			break;

		case DMA_CHANNEL6:


			DMA -> CCR6 = 0;
			DMA -> CCR6.PL = Copy_U8ChannelPriority;
			DMA -> CCR6.PSIZE = Copy_U8DataSize;
			DMA -> CCR6.MSIZE = Copy_U8DataSize;
			DMA -> CCR6.MINC = Copy_U8IncrementMode;
			DMA -> CCR6.PINC = Copy_U8IncrementMode;
			DMA -> CCR6.EN = Copy_U8EnableTCInt;

			if( (Copy_pstructDMAChannelConfig -> Copy_U8ataTransferType) == DMA_MEM_TO_MEM)
			{
				DMA -> CCR6.MEM2MEM = 1;
			}
			else
			{
				DMA -> CCR6.DIR = Copy_U8DataTransferType;
			}
			break;

		case DMA_CHANNEL7:

			DMA -> CCR7 = 0;
			DMA -> CCR7.PL = Copy_U8ChannelPriority;
			DMA -> CCR7.PSIZE = Copy_U8DataSize;
			DMA -> CCR7.MSIZE = Copy_U8DataSize;
			DMA -> CCR7.MINC = Copy_U8IncrementMode;
			DMA -> CCR7.PINC = Copy_U8IncrementMode;
			DMA -> CCR7.EN = Copy_U8EnableTCInt;

			if( (Copy_pstructDMAChannelConfig -> Copy_U8ataTransferType) == DMA_MEM_TO_MEM)
			{
				DMA -> CCR7.MEM2MEM = 1;
			}
			else
			{
				DMA -> CCR7.DIR = Copy_U8DataTransferType;
			}
			break;
	}
}

void DMA_u8DMAChannelTransfer(u8 Copy_u8ChannelNumber, u32 Copy_u32SrcAddress, u32 Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers)
{
	switch(Copy_u8ChannelNumber)
	{
		case DMA_CHANNEL1:

			/*Setting the number of transfers*/
			DMA -> CNDTR1.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(DMA -> CCR1.MEM2MEM)
			{
				DMA -> CPAR1.R = Copy_u32SrcAddress;
				DMA -> CMAR1.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(DMA -> CCR1.DIR)
				{
					DMA -> CMAR1.R = Copy_u32SrcAddress;
					DMA -> CPAR1.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR1.R = Copy_u32SrcAddress;
					DMA -> CMAR1.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			DMA -> CCR1.EN = 1;

			break;

		case DMA_CHANNEL2:

			/*Setting the number of transfers*/
			DMA -> CNDTR2.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(DMA -> CCR2.MEM2MEM)
			{
				DMA -> CPAR2.R = Copy_u32SrcAddress;
				DMA -> CMAR2.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(DMA -> CCR2.DIR)
				{
					DMA -> CMAR2.R = Copy_u32SrcAddress;
					DMA -> CPAR2.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR2.R = Copy_u32SrcAddress;
					DMA -> CMAR2.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			DMA -> CCR2.EN = 1;

			break;

		case DMA_CHANNEL3:

			/*Setting the number of transfers*/
			DMA -> CNDTR3.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(DMA -> CCR3.MEM2MEM)
			{
				DMA -> CPAR3.R = Copy_u32SrcAddress;
				DMA -> CMAR3.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(DMA -> CCR3.DIR)
				{
					DMA -> CMAR3.R = Copy_u32SrcAddress;
					DMA -> CPAR3.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR3.R = Copy_u32SrcAddress;
					DMA -> CMAR3.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			DMA -> CCR3.EN = 1;

			break;

		case DMA_CHANNEL4:

			/*Setting the number of transfers*/
			DMA -> CNDTR4.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(DMA -> CCR4.MEM2MEM)
			{
				DMA -> CPAR4.R = Copy_u32SrcAddress;
				DMA -> CMAR4.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(DMA -> CCR4.DIR)
				{
					DMA -> CMAR4.R = Copy_u32SrcAddress;
					DMA -> CPAR4.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR4.R = Copy_u32SrcAddress;
					DMA -> CMAR4.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			DMA -> CCR4.EN = 1;

			break;

		case DMA_CHANNEL5:

			/*Setting the number of transfers*/
			DMA -> CNDTR5.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(DMA -> CCR5.MEM2MEM)
			{
				DMA -> CPAR5.R = Copy_u32SrcAddress;
				DMA -> CMAR5.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(DMA -> CCR5.DIR)
				{
					DMA -> CMAR5.R = Copy_u32SrcAddress;
					DMA -> CPAR5.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR5.R = Copy_u32SrcAddress;
					DMA -> CMAR5.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			DMA -> CCR5.EN = 1;

			break;

		case DMA_CHANNEL6:

			/*Setting the number of transfers*/
			DMA -> CNDTR6.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
				if(DMA -> CCR6.MEM2MEM)
			{
				DMA -> CPAR6 = Copy_u32SrcAddress;
				DMA -> CMAR6.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(DMA -> CCR6.DIR)
				{
					DMA -> CMAR6.R = Copy_u32SrcAddress;
					DMA -> CPAR6 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR6 = Copy_u32SrcAddress;
					DMA -> CMAR6.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			DMA -> CCR6.EN = 1;

			break;

		case DMA_CHANNEL7:

			/*Setting the number of transfers*/
			DMA -> CNDTR7.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
				if(DMA -> CCR7.MEM2MEM)
			{
				DMA -> CPAR7.R = Copy_u32SrcAddress;
				DMA -> CMAR7.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(DMA -> CCR7.DIR)
				{
					DMA -> CMAR7.R = Copy_u32SrcAddress;
					DMA -> CPAR7.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR7.R = Copy_u32SrcAddress;
					DMA -> CMAR7.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			DMA -> CCR7.EN = 1;

			break;
	}
}

void DMA_u8DMAChannelTransfer_busyWait(u8 Copy_u8ChannelNumber, u32 Copy_u32SrcAddress, u32 Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers)
{
	switch(Copy_u8ChannelNumber)
	{
		case DMA_CHANNEL1:

			/*Setting the number of transfers*/
			DMA -> CNDTR1.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR1, 14))
			{
				DMA -> CPAR1.R = Copy_u32SrcAddress;
				DMA -> CMAR1.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR1, 4))
				{
					DMA -> CMAR1.R = Copy_u32SrcAddress;
					DMA -> CPAR1.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR1.R = Copy_u32SrcAddress;
					DMA -> CMAR1.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR1, 0);

			break;

		case DMA_CHANNEL2:

			/*Setting the number of transfers*/
			DMA -> CNDTR2.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR2, 14))
			{
				DMA -> CPAR2.R = Copy_u32SrcAddress;
				DMA -> CMAR2.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR2, 4))
				{
					DMA -> CMAR2.R = Copy_u32SrcAddress;
					DMA -> CPAR2.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR2.R = Copy_u32SrcAddress;
					DMA -> CMAR2.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR2, 0);

			break;

		case DMA_CHANNEL3:

			/*Setting the number of transfers*/
			DMA -> CNDTR3.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR3, 14))
			{
				DMA -> CPAR3.R = Copy_u32SrcAddress;
				DMA -> CMAR3.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR3, 4))
				{
					DMA -> CMAR3.R = Copy_u32SrcAddress;
					DMA -> CPAR3.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR3.R = Copy_u32SrcAddress;
					DMA -> CMAR3.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR3, 0);

			break;

		case DMA_CHANNEL4:

			/*Setting the number of transfers*/
			DMA -> CNDTR4.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR4, 14))
			{
				DMA -> CPAR4.R = Copy_u32SrcAddress;
				DMA -> CMAR4.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR4, 4))
				{
					DMA -> CMAR4.R = Copy_u32SrcAddress;
					DMA -> CPAR4.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR4.R = Copy_u32SrcAddress;
					DMA -> CMAR4.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR4, 0);

			break;

		case DMA_CHANNEL5:

			/*Setting the number of transfers*/
			DMA -> CNDTR5.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR5, 14))
			{
				DMA -> CPAR5.R = Copy_u32SrcAddress;
				DMA -> CMAR5.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR5, 4))
				{
					DMA -> CMAR5.R = Copy_u32SrcAddress;
					DMA -> CPAR5.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR5.R = Copy_u32SrcAddress;
					DMA -> CMAR5.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR5, 0);

			break;

		case DMA_CHANNEL6:

			/*Setting the number of transfers*/
			DMA -> CNDTR6.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR6, 14))
			{
				DMA -> CPAR6 = Copy_u32SrcAddress;
				DMA -> CMAR6.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR6, 4))
				{
					DMA -> CMAR6.R = Copy_u32SrcAddress;
					DMA -> CPAR6 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR6 = Copy_u32SrcAddress;
					DMA -> CMAR6.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR6, 0);

			break;

		case DMA_CHANNEL7:

			/*Setting the number of transfers*/
			DMA -> CNDTR7.R = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR7, 14))
			{
				DMA -> CPAR7.R = Copy_u32SrcAddress;
				DMA -> CMAR7.R = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR7, 4))
				{
					DMA -> CMAR7.R = Copy_u32SrcAddress;
					DMA -> CPAR7.R = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR7.R = Copy_u32SrcAddress;
					DMA -> CMAR7.R = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR7, 0);

			break;
	}

	/*Polling over TC flag*/
	while(! (GET_BIT(DMA -> ISR.R, (1 + (4*(Copy_u8ChannelNumber - 1))) )));

	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, (1 + (4*(Copy_u8ChannelNumber - 1))) );
}

u8 DMA_u8DMASetCallBack(u8 Copy_u8ChannelNumber, void (*pf) (void))
{
	Global_pfArr[Copy_u8ChannelNumber - 1] = pf;
}


void DMA1_Channel1_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR.R, 1);

	if(Global_pfArr[0] != NULL)
	{
		Global_pfArr[0]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel2_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR.R, 5);

	if(Global_pfArr[1] != NULL)
	{
		Global_pfArr[1]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel3_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR.R, 9);

	if(Global_pfArr[2] != NULL)
	{
		Global_pfArr[2]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel4_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR.R, 13);

	if(Global_pfArr[3] != NULL)
	{
		Global_pfArr[3]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel5_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR.R, 17);

	if(Global_pfArr[4] != NULL)
	{
		Global_pfArr[4]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel6_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR.R, 21);

	if(Global_pfArr[5] != NULL)
	{
		Global_pfArr[5]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel7_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR.R, 25);

	if(Global_pfArr[6] != NULL)
	{
		Global_pfArr[6]();
	}
	else
	{
		/*Do nothing*/
	}
}
