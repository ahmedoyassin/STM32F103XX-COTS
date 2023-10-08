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
	SPI_ID ID;
	SPI1_CLK_POLARITY CLK_POLARITY;
	SPI1_CLK_PHASE	CLK_PHASE;
	SPI_PRESCALER PRESCALER;
	SPI_MODE SPIMode;
	SPIDS SPIDATASIZE;
	SPIORDER SPIDATAORDER;
	SPI_STATE STATE;
    SPIE SPIEnableType;
}SPI_Configurations;


typedef struct
{
	SPI_Configurations SPI_Array[NUMBER_OF_USED_SPIS];
}SPI_ConfigType;
SPI_ConfigType arrOfSPI[NUMBER_OF_USED_SPIS];


void SPI_voidInit(void);


void SPI1_voidTransmitDataSync(u16 Copy_u16Data);
void SPI2_voidTransmitDataSync(u8 Copy_u8Data);


void SPI1_voidReceiveDataSync(u16 *Address_u16Data);
void SPI2_voidReceiveDataSync(u8 Copy_u8Data);

void SPI1_voidSetCallBackFunction(void (*SPI1_CallBackFunction)(u16));
void SPI2_voidSetCallBackFunction(void (*SPI2_CallBackFunction)(u16));