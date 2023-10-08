/********************************************************************************************/
/********************************************************************************************/
/**************************		Authors:  Yassin - Rabie - Aliaa                *************/
/**************************		Date:    25 AUG 2023	    	        		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 SPI									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

#include "SPI_Private.h"


typedef enum
{
	SPI1,
	SPI2,
	SPI3
}SPI_ID;

typedef enum
{
	SPI_CLK_POLARITY_LOW,
	SPI_CLK_POLARITY_HIGH
}SPI_CLK_POLARITY;

typedef enum
{
	SPI_CLK_PHASE_FIRSTxCLK,
	SPI_CLK_PHASE_SECONDxCLK
}SPI_CLK_PHASE;

typedef enum
{
	SPI_MODE_SLAVE,
	SPI_MODE_MASTER
}SPI_MODE;

typedef enum
{
	SPI_DATA_SIZE_8,
	SPI_DATA_SIZE_16
}SPIDS;

typedef enum
{
	SPI_DATA_ORDER_MSB,
	SPI_DATA_ORDER_LSB
}SPIORDER;

typedef enum
{
	SPI_STATE_DISABLE,
	SPI_STATE_ENABLE
}SPI_STATE;

typedef enum
{
	SPI_DISABLE,
	SPI_ENABLE
}SPIE;