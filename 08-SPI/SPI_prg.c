/********************************************************************************************/
/********************************************************************************************/
/**************************		Authors:  Yassin - Rabie - Aliaa                *************/
/**************************		Date:    25 AUG 2023	    	        		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 SPI									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

void SPI_voidInit(void)
{
	
	
	
}
void SPI1_voidTransmitDataSync(u16 Copy_u16Data){
		CLR_BIT(SPI1_SLAVE1_PORT, SPI1_SLAVE1_PIN);
		SPI1->DR = Copy_u16Data;
		while( (!SPI1->SR.B.TXE));
		while( (!SPI1->SR.B.RXNE));
		while( (SPI1->SR.BSY) ) ;
	    DIO_voidSetPin(SPI1_SLAVE1_PORT, SPI1_SLAVE1_PIN);

}

void SPI1_voidReceiveDataSync(u16 *ptr_u16Data){
	
	while( (!SPI1->SR.B.RXNE));
    *ptr_u16Data = SPI1->DR;
    while( (SPI1->SR.BSY) ) ;
	
}

void SPI1_voidSetCallBackFunction(void (*SPI1_CallBackFunction)(u16)){
	 if( (NULL != SPI1_CallBackFunction) )
    {
        G_SPICallBackFunction[SPI1] = SPI1_CallBackFunction;
    }
	else;
	
}
