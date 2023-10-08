/*
 * CAN_private.h
 *
 *  Created on: Sep 21, 2023
 *      Author: Ahmed
 */

#ifndef CAN_PRIVATE_H_
#define CAN_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"


typedef void (*CAN_Interrupt_Callbacks)(void);


typedef enum
{
	CAN_MODE_NORMAL = ((u32)(0x0)),
	CAN_MODE_LOOPBACK = ((u32)(0x1<<30)),
	CAN_MODE_SILENT = ((u32)(0x1<<31)),
	CAN_MODE_SILENT_LOOPBACK

}MODE_TYPE;


/*******************        BoudRate			**********************/

typedef enum
{
	CAN_50KBPS,
	CAN_100KBPS,
	CAN_125KBPS,
	CAN_250KBPS,
	CAN_500KBPS,
	CAN_800KBPS,
	CAN_1MBPS
}BOUDRATE_TYPE;

typedef const struct
{
	u8 TS2;
	u8 TS1;
	u8 BRP;
} CAN_BitTimingConfig;

/******** BoudRate value rating to table at web site {http://www.bittiming.can-wiki.info/}
 * 1. select ST Microelectronics bxCAN
 * 2. put freq with 36Mhz (APB1 freq)
 * 3. click Request Table						        ***********************************/

/*CAN_BitTimingConfig CAN_bitRateConfig[7] = {	{2, 13, 45},
												{2, 15, 20},
												{2, 13, 18},
												{2, 13, 9},
												{2, 15, 4},
												{2, 12, 3},
												{2, 15, 2}
															};
*/
/*******************   Register Definition     ***********************/
/** Controller Area Network  **/
typedef struct
{
	union
	{
		volatile u32 Reg;
	    struct
		{
		volatile u32 INRQ : 1;
		volatile u32 SLEEP :1;
		volatile u32 TXFP : 1;
		volatile u32 RFLM : 1;
		volatile u32 NART : 1;
		volatile u32 AWUM : 1;
		volatile u32 ABOM : 1;
		volatile u32 TTCM : 1;
		volatile u32 RESERVED1 : 7;
		volatile u32 RESET : 1;
		volatile u32 DBF : 1;
		volatile u32 RESERVED2 : 15;
		}B;
	}MCR;
	union
		{
			volatile u32 Reg;
		    struct
			{
			volatile u32 INAK : 1;
			volatile u32 SLAK :1;
			volatile u32 ERRI : 1;
			volatile u32 WKUI : 1;
			volatile u32 SLAKI : 1;
			volatile u32 RESERVED1 : 3;
			volatile u32 TXM : 1;
			volatile u32 RXM : 1;
			volatile u32 SAMP : 1;
			volatile u32 RX : 1;
			volatile u32 RESERVED2 : 20;
			}B;
		}MSR;
	union
		{
			volatile u32 Reg;
			struct
			{
			volatile u32 RQCP0 : 1;
			volatile u32 TXOK0 :1;
			volatile u32 ALST0 : 1;
			volatile u32 TERR0 : 1;
			volatile u32 RESERVED1 : 3;
			volatile u32 ABRQ0 : 1;
			volatile u32 RQCP1 : 1;
			volatile u32 TXOK1 : 1;
			volatile u32 ALST1 : 1;
			volatile u32 TERR1 : 1;
			volatile u32 RESERVED2 : 3;
			volatile u32 ABRQ1 : 1;
			volatile u32 RQCP2 : 1;
			volatile u32 TXOK2 : 1;
			volatile u32 ALST2 : 1;
			volatile u32 TERR2 : 1;
			volatile u32 RESERVED3 : 3;
			volatile u32 ABRQ2 : 1;
			volatile u32 CODE : 2;
			volatile u32 TME0 : 1;
			volatile u32 TME1 : 1;
			volatile u32 TME2 : 1;
			volatile u32 LOW0 : 1;
			volatile u32 LOW1 : 1;
			volatile u32 LOW2 : 1;
			}B;
		}TSR;
	union
		{
			volatile u32 Reg;
			 struct
			{
			volatile u32 FMP0 : 2;
			volatile u32 RESERVED1 : 1;
			volatile u32 FULL0 :1;
			volatile u32 FOVR0 : 1;
			volatile u32 RFOM0 : 1;
			volatile u32 RESERVED2 : 26;
			}B;
		}RF0R;
	union
		{
			volatile u32 Reg;
			 struct
			{
			volatile u32 FMP1 : 2;
			volatile u32 RESERVED1 : 1;
			volatile u32 FULL1 :1;
			volatile u32 FOVR1 : 1;
			volatile u32 RFOM1 : 1;
			volatile u32 RESERVED2 : 26;
			}B;
		}RF1R;
	union
	{
			volatile u32 Reg;
			struct
			{
				volatile u32 TMEIE : 1;
				volatile u32 FMPIE0: 1;
				volatile u32 FFIE0: 1;
				volatile u32 FOVIE0: 1;
				volatile u32 FMPIE1: 1;
				volatile u32 FFIE1: 1;
				volatile u32 FOVIE1: 1;
				volatile u32 RESERVED1 :1;
				volatile u32 EWGIE: 1;
				volatile u32 EPVIE: 1;
				volatile u32 BOFIE: 1;
				volatile u32 LECIE: 1;
				volatile u32 RESERVED2 : 3;
				volatile u32 ERRIE: 1;
				volatile u32 WKUIE: 1;
				volatile u32 SLKIE: 1;
				volatile u32 RESERVED3 : 14;
			}B;
		}IER;
		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 EWGF :1;
				volatile u32 EPVF :1;
				volatile u32 BOFF :1;
				volatile u32 RESERVED1 :1;
				volatile u32 LEC :3;
				volatile u32 RESERVED2 :9;
				volatile u32 TEC : 8;
				volatile u32 REC :8;
			}B;
		}ESR;
	union
	{
			volatile u32 Reg;
			struct
			{
				volatile u32 BRP :10;
				volatile u32 RESERVED1 :6;
				volatile u32 TS1 : 4;
				volatile u32 TS3 : 3;
				volatile u32 RESERVED2 : 1;
				volatile u32 SJW :2;
				volatile u32 RESERVED3 :4;
				volatile u32 LBKM :1;
				volatile u32 SILM :1;
			}B;
	}BTR;

	volatile u32 RESERVED0[88];

	union
	{
		volatile u32 Reg;
		struct
		{
			volatile u32 TXRQ : 1;
			volatile u32 RTR : 1;
			volatile u32 IDE : 1;
			volatile u32 EXID :18;
			volatile u32 STID : 11;

		}B;

	}TI0R;

	union
	{
		volatile u32 Reg;
		struct
		{
			volatile u32 DLC : 4;
			volatile u32 RESERVED1 : 4;
			volatile u32 TGT : 1;
			volatile u32 RESERVED2 : 7;
			volatile u32 TIME : 16;
		}B;

	}TDT0R;


	union
	{
		volatile u32 Reg;
		struct
		{
			volatile u32 DATA0 : 8;
			volatile u32 DATA1 : 8;
			volatile u32 DATA2 : 8;
			volatile u32 DATA3 : 8;
		}B;
	}TDL0R;

	union
	{
		volatile u32 Reg;
		struct
		{
			volatile u32 DATA4 : 8;
			volatile u32 DATA5 : 8;
			volatile u32 DATA6 : 8;
			volatile u32 DATA7 : 8;
		}B;

	}TDH0R;

	union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 TXRQ : 1;
				volatile u32 RTR : 1;
				volatile u32 IDE : 1;
				volatile u32 EXID :18;
				volatile u32 STID : 11;
			}B;

		}TI1R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 DLC : 4;
				volatile u32 RESERVED1 : 4;
				volatile u32 TGT : 1;
				volatile u32 RESERVED2 : 7;
				volatile u32 TIME : 16;
			}B;
		}TDT1R;


		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 DATA0 : 8;
				volatile u32 DATA1 : 8;
				volatile u32 DATA2 : 8;
				volatile u32 DATA3 : 8;

			}B;
		}TDL1R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 DATA4 : 8;
				volatile u32 DATA5 : 8;
				volatile u32 DATA6 : 8;
				volatile u32 DATA7 : 8;
			}B;

		}TDH1R;


		union
			{
			volatile u32 Reg;
			struct
			{
				volatile u32 TXRQ : 1;
				volatile u32 RTR : 1;
				volatile u32 IDE : 1;
				volatile u32 EXID :18;
				volatile u32 STID : 11;
			}B;

		}TI2R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 DLC : 4;
				volatile u32 RESERVED1 : 4;
				volatile u32 TGT : 1;
				volatile u32 RESERVED2 : 7;
				volatile u32 TIME : 16;
			}B;
		}TDT2R;


		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 DATA0 : 8;
				volatile u32 DATA1 : 8;
				volatile u32 DATA2 : 8;
				volatile u32 DATA3 : 8;
			}B;
		}TDL2R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 DATA4 : 8;
				volatile u32 DATA5 : 8;
				volatile u32 DATA6 : 8;
				volatile u32 DATA7 : 8;
			}B;

		}TDH2R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 RESERVED1 : 1;
				volatile u32 RTR : 1;
				volatile u32 IDE : 1;
				volatile u32 EXID :18;
				volatile u32 STID : 11;
			}B;
		}RI0R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 DLC : 4;
				volatile u32 RESERVED : 4;
				volatile u32 FMI : 8;
				volatile u32 TIME : 16;

			}B;
		}RDT0R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u8 DATA[4];
			}B;
		}RDL0R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u8 DATA[4];
			}B;
		}RDH0R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 RESERVED1 : 1;
				volatile u32 RTR : 1;
				volatile u32 IDE : 1;
				volatile u32 EXID :18;
				volatile u32 STID : 11;
			}B;
		}RI1R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u32 DLC : 4;
				volatile u32 RESERVED : 4;
				volatile u32 FMI : 8;
				volatile u32 TIME : 16;

			}B;
		}RDT1R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u8 DATA[4];
			}B;
		}RDL1R;

		union
		{
			volatile u32 Reg;
			struct
			{
				volatile u8 DATA[4];
			}B;
		}RDH1R;

    volatile u32  RESERVED1[12];

    union
	{
    	volatile u32 Reg;
    	struct
		{
    		volatile u32 FINIT : 1;
    		volatile u32 RESERVED1 : 7;
    		volatile u32 CAN2SB :6;
    		volatile u32 RESERVED2 : 18;
		}B;

	}FMR;
    union
	{
    	volatile u32 Reg;
    	struct
		{
    		volatile u32 FBM0 :1;
    		volatile u32 FBM1 :1;
    		volatile u32 FBM2 :1;
    		volatile u32 FBM3 :1;
    		volatile u32 FBM4 :1;
    		volatile u32 FBM5 :1;
    		volatile u32 FBM6 :1;
    		volatile u32 FBM7 :1;
    		volatile u32 FBM8 :1;
    		volatile u32 FBM9 :1;
    		volatile u32 FBM10 :1;
    		volatile u32 FBM11 :1;
    		volatile u32 FBM12 :1;
    		volatile u32 FBM13 :1;
    		volatile u32 FBM14 :1;
    		volatile u32 FBM15 :1;
    		volatile u32 FBM16 :1;
    		volatile u32 FBM17 :1;
    		volatile u32 FBM18 :1;
    		volatile u32 FBM19 :1;
    		volatile u32 FBM20 :1;
    		volatile u32 FBM21 :1;
    		volatile u32 FBM22 :1;
    		volatile u32 FBM23 :1;
    		volatile u32 FBM24 :1;
    		volatile u32 FBM25 :1;
    		volatile u32 FBM26 :1;
    		volatile u32 FBM27 :1;
    		volatile u32 RESERVED : 4;
		}B;

	}FM1R;
    volatile u32  RESERVED2;
    union
	{
    	volatile u32 Reg;
    	struct
		{
    		volatile u32 FSC0 :1;
    		volatile u32 FSC1 :1;
    		volatile u32 FSC2 :1;
    		volatile u32 FSC3 :1;
    		volatile u32 FSC4 :1;
    		volatile u32 FSC5 :1;
    		volatile u32 FSC6 :1;
    		volatile u32 FSC7 :1;
    		volatile u32 FSC8 :1;
    		volatile u32 FSC9 :1;
    		volatile u32 FSC10 :1;
    		volatile u32 FSC11 :1;
    		volatile u32 FSC12 :1;
    		volatile u32 FSC13 :1;
    		volatile u32 FSC14 :1;
    		volatile u32 FSC15 :1;
    		volatile u32 FSC16 :1;
    		volatile u32 FSC17 :1;
    		volatile u32 FSC18 :1;
    		volatile u32 FSC19 :1;
    		volatile u32 FSC20 :1;
    		volatile u32 FSC21 :1;
    		volatile u32 FSC22 :1;
    		volatile u32 FSC23 :1;
    		volatile u32 FSC24 :1;
    		volatile u32 FSC25 :1;
    		volatile u32 FSC26 :1;
    		volatile u32 FSC27 :1;
    		volatile u32 RESERVED : 4;
		}B;

	}FS1R;
    volatile u32  RESERVED3;
    union
	{
    	volatile u32 Reg;
    	struct
		{
    		volatile u32 FFA0 :1;
    		volatile u32 FFA1 :1;
    		volatile u32 FFA2 :1;
    		volatile u32 FFA3 :1;
    		volatile u32 FFA4 :1;
    		volatile u32 FFA5 :1;
    		volatile u32 FFA6 :1;
    		volatile u32 FFA7 :1;
    		volatile u32 FFA8 :1;
    		volatile u32 FFA9 :1;
    		volatile u32 FFA10 :1;
    		volatile u32 FFA11 :1;
    		volatile u32 FFA12 :1;
    		volatile u32 FFA13 :1;
    		volatile u32 FFA14 :1;
    		volatile u32 FFA15 :1;
    		volatile u32 FFA16 :1;
    		volatile u32 FFA17 :1;
    		volatile u32 FFA18 :1;
    		volatile u32 FFA19 :1;
    		volatile u32 FFA20 :1;
    		volatile u32 FFA21 :1;
    		volatile u32 FFA22 :1;
    		volatile u32 FFA23 :1;
    		volatile u32 FFA24 :1;
    		volatile u32 FFA25 :1;
    		volatile u32 FFA26 :1;
    		volatile u32 FFA27 :1;
    		volatile u32 RESERVED : 4;
		}B;

	}FFA1R;
    volatile u32  RESERVED4;
    union
	{
    	volatile u32 Reg;
    	struct
		{
    		volatile u32 FACT0 :1;
    		volatile u32 FACT1 :1;
    		volatile u32 FACT2 :1;
    		volatile u32 FACT3 :1;
    		volatile u32 FACT4 :1;
    		volatile u32 FACT5 :1;
    		volatile u32 FACT6 :1;
    		volatile u32 FACT7 :1;
    		volatile u32 FACT8 :1;
    		volatile u32 FACT9 :1;
    		volatile u32 FACT10 :1;
    		volatile u32 FACT11 :1;
    		volatile u32 FACT12 :1;
    		volatile u32 FACT13 :1;
    		volatile u32 FACT14 :1;
    		volatile u32 FACT15 :1;
    		volatile u32 FACT16 :1;
    		volatile u32 FACT17 :1;
    		volatile u32 FACT18 :1;
    		volatile u32 FACT19 :1;
    		volatile u32 FACT20 :1;
    		volatile u32 FACT21 :1;
    		volatile u32 FACT22 :1;
    		volatile u32 FACT23 :1;
    		volatile u32 FACT24 :1;
    		volatile u32 FACT25 :1;
    		volatile u32 FACT26 :1;
    		volatile u32 FACT27 :1;
    		volatile u32 RESERVED : 4;
		}B;

	}FA1R;
    volatile u32  RESERVED5[8];

    union
	{
    	volatile u32 Reg;
    	struct
		{
    		volatile u32 FB0 : 1;
    		volatile u32 FB1 : 1;
    		volatile u32 FB2 : 1;
    		volatile u32 FB3 : 1;
    		volatile u32 FB4 : 1;
    		volatile u32 FB5 : 1;
    		volatile u32 FB6 : 1;
    		volatile u32 FB7 : 1;
    		volatile u32 FB8 : 1;
    		volatile u32 FB9 : 1;
    		volatile u32 FB10 : 1;
    		volatile u32 FB11 : 1;
    		volatile u32 FB12 : 1;
    		volatile u32 FB13 : 1;
    		volatile u32 FB14 : 1;
    		volatile u32 FB15 : 1;
    		volatile u32 FB16 : 1;
    		volatile u32 FB17 : 1;
    		volatile u32 FB18 : 1;
    		volatile u32 FB19 : 1;
    		volatile u32 FB20 : 1;
    		volatile u32 FB21 : 1;
    		volatile u32 FB22 : 1;
    		volatile u32 FB23 : 1;
    		volatile u32 FB24 : 1;
    		volatile u32 FB25 : 1;
    		volatile u32 FB26 : 1;
    		volatile u32 FB27 : 1;
    		volatile u32 FB28 : 1;
    		volatile u32 FB29 : 1;
    		volatile u32 FB30 : 1;
    		volatile u32 FB31 : 1;

		}B;
	}F0R1;

    union
	{
    	volatile u32 Reg;
    	struct
		{
    		volatile u32 FB0 : 1;
    		volatile u32 FB1 : 1;
    		volatile u32 FB2 : 1;
    		volatile u32 FB3 : 1;
    		volatile u32 FB4 : 1;
    		volatile u32 FB5 : 1;
    		volatile u32 FB6 : 1;
    		volatile u32 FB7 : 1;
    		volatile u32 FB8 : 1;
    		volatile u32 FB9 : 1;
    		volatile u32 FB10 : 1;
    		volatile u32 FB11 : 1;
    		volatile u32 FB12 : 1;
    		volatile u32 FB13 : 1;
    		volatile u32 FB14 : 1;
    		volatile u32 FB15 : 1;
    		volatile u32 FB16 : 1;
    		volatile u32 FB17 : 1;
    		volatile u32 FB18 : 1;
    		volatile u32 FB19 : 1;
    		volatile u32 FB20 : 1;
    		volatile u32 FB21 : 1;
    		volatile u32 FB22 : 1;
    		volatile u32 FB23 : 1;
    		volatile u32 FB24 : 1;
    		volatile u32 FB25 : 1;
    		volatile u32 FB26 : 1;
    		volatile u32 FB27 : 1;
    		volatile u32 FB28 : 1;
    		volatile u32 FB29 : 1;
    		volatile u32 FB30 : 1;
    		volatile u32 FB31 : 1;
		}B;
	}F0R2;

    union
	{
    	volatile u32 Reg;
    	struct
		{
    		volatile u32 FB0 : 1;
    		volatile u32 FB1 : 1;
    		volatile u32 FB2 : 1;
    		volatile u32 FB3 : 1;
    		volatile u32 FB4 : 1;
    		volatile u32 FB5 : 1;
    		volatile u32 FB6 : 1;
    		volatile u32 FB7 : 1;
    		volatile u32 FB8 : 1;
    		volatile u32 FB9 : 1;
    		volatile u32 FB10 : 1;
    		volatile u32 FB11 : 1;
    		volatile u32 FB12 : 1;
    		volatile u32 FB13 : 1;
    		volatile u32 FB14 : 1;
    		volatile u32 FB15 : 1;
    		volatile u32 FB16 : 1;
    		volatile u32 FB17 : 1;
    		volatile u32 FB18 : 1;
    		volatile u32 FB19 : 1;
    		volatile u32 FB20 : 1;
    		volatile u32 FB21 : 1;
    		volatile u32 FB22 : 1;
    		volatile u32 FB23 : 1;
    		volatile u32 FB24 : 1;
    		volatile u32 FB25 : 1;
    		volatile u32 FB26 : 1;
    		volatile u32 FB27 : 1;
    		volatile u32 FB28 : 1;
    		volatile u32 FB29 : 1;
    		volatile u32 FB30 : 1;
    		volatile u32 FB31 : 1;
		}B;
	}F1R1;
	union
	{
		volatile u32 Reg;
		struct
		{
    		volatile u32 FB0 : 1;
    		volatile u32 FB1 : 1;
    		volatile u32 FB2 : 1;
    		volatile u32 FB3 : 1;
    		volatile u32 FB4 : 1;
    		volatile u32 FB5 : 1;
    		volatile u32 FB6 : 1;
    		volatile u32 FB7 : 1;
    		volatile u32 FB8 : 1;
    		volatile u32 FB9 : 1;
    		volatile u32 FB10 : 1;
    		volatile u32 FB11 : 1;
    		volatile u32 FB12 : 1;
    		volatile u32 FB13 : 1;
    		volatile u32 FB14 : 1;
    		volatile u32 FB15 : 1;
    		volatile u32 FB16 : 1;
    		volatile u32 FB17 : 1;
    		volatile u32 FB18 : 1;
    		volatile u32 FB19 : 1;
    		volatile u32 FB20 : 1;
    		volatile u32 FB21 : 1;
    		volatile u32 FB22 : 1;
    		volatile u32 FB23 : 1;
    		volatile u32 FB24 : 1;
    		volatile u32 FB25 : 1;
    		volatile u32 FB26 : 1;
    		volatile u32 FB27 : 1;
    		volatile u32 FB28 : 1;
    		volatile u32 FB29 : 1;
    		volatile u32 FB30 : 1;
    		volatile u32 FB31 : 1;
		}B;
	}F1R2;


}CAN_t;

/*******************   BASE Address Definition    *********************/
#define CAN_BASE_ADDRESS	0x40006400 		//define the boundary address of CAN
#define CAN	((volatile CAN_t *) CAN_BASE_ADDRESS)



#endif /* CAN_PRIVATE_H_ */
