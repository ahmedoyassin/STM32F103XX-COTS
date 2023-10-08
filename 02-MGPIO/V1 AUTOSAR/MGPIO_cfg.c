
/*
 * File        : GPIO_cfg.c
 * Author      : Abdelrhman Rabie, Aliaa & Ahemd Yassin
 * Date        : 15/7/2023

 */

#include "../Inc/MGPIO_interface.h"
#include "../Inc/MRCC_cfg.h"


void FUNC(void)
{
	Dio_WriteChannel( A9, LOW);

}


pinInfo arrOfPins[NUMBER_OF_USED_PINS]=
{{
		.PORT_ID      = PORTA,
		.PIN_ID       = PIN9,
		.MODE         = OUTPUT

},
	{
		.PORT_ID      = PORTA,
		.PIN_ID       = PIN8,
		.MODE         = OUTPUT
	},
	{
		.PORT_ID      = PORTA,
		.PIN_ID       = PIN10,
		.MODE         = OUTPUT

	}
};

/*
Dio_ChannelGroupType ArrOfGroup[NUMBER_OF_USED_PINS_GROUP]=
{
	{
		.PORT_ID = PORTA,
		.PIN_ID = PIN5,
	},
	{
		.PORT_ID = PORTA,
		.PIN_ID = PIN6,
	},
	{
		.PORT_ID = PORTA,
		.PIN_ID = PIN7,
	},
	{
		.PORT_ID = PORTA,
		.PIN_ID = PIN8,
	}
};*/
