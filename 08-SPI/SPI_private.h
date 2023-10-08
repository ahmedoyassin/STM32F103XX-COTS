/********************************************************************************************/
/********************************************************************************************/
/**************************		Authors:  Yassin - Rabie - Aliaa                *************/
/**************************		Date:    25 AUG 2023	    	        		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 SPI									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


typedef struct
{
	union
	{
		u32 R;
		struct {
	u32 CPHA     :1;
    u32 CPOL     :1;
    u32 MSTR     :1;
    u32 BR		 :3;
    u32 SPE      :1;
    u32 LSBFIRST :1;
    u32 SSI      :1;
    u32 SSM      :1;
    u32 RXONLY   :1;
    u32 DFF      :1;
    u32 CRCNEXT  :1;
    u32 CRCEN    :1;
    u32 BIDIOE   :1;
    u32 BIDIMODE :1;
			
		}B;
	}CR1;
	union
	{
		u32 R;
		struct {
	RXDMAEN :1;
    TXDMAEN :1;
    SSOE    :1;
    ERRIE   :1;
    RXNEIE  :1;
    TXEIE   :1;
	RESERVED :26;	
		}B;
	}CR2;
    union
	{
		u32 R;
		struct {
	RXNE     :1;
    TXE      :1;
    CHSIDE   :1;
    UDR      :1;
    CRCERR   :1;
    MODF     :1;
    OVR      :1;
    BSY      :1;
	RESERVED :24;
			
			
		}B;
	}SR;
	
    u32 volatile DR;
    u32 volatile CRCPR;
	u32 volatile RXCRCR;
    u32 volatile TXCRCR;
	
    union
	{
		u32 R;
		struct {
	u32 CHLEN    :1;
    u32 DATLEN   :1;
    u32 CKPOL    :2;
    u32 I2SSTD   :2;
    u32 PCMSY    :1;
    u32 I2SCFG   :1;
    u32 I2SE     :1;
    u32 I2SMOD   :1;
	u32 RESERVED :22;
			
		}B;
	}I2SCFGR;
    union
	{
		u32 R;
		struct {
			u32 RESERVED :8;
			u32 ODD :1;
			u32 MCKOE :1;
			u32 RESERVED1 :22;
		}B;
	}I2SPR;
}ST_SPIRegisters_t;

#define SPI1 ( (ST_SPIRegisters_t volatile * const) (0x40013000) )
#define SPI2 ( (ST_SPIRegisters_t volatile * const) (0x40003800) )


#define NUMBER_OF_USED_SPIS 	(2)
