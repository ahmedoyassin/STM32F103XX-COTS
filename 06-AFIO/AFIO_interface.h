
/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/********************************************************************************************/
/* Define function parameters  			 			                                        */
/********************************************************************************************/

/* Copy_u8Line (CHOOSE NUMBER OF PIN) */
/* notice:
LINE0 for A0 or B0 or C0
LINE1 for A1 or B1 or C1
etc...
*/
#define AFIO_LINE0      			0
#define AFIO_LINE1      			1
#define AFIO_LINE2      			2
#define AFIO_LINE3      			3
#define AFIO_LINE4      			4
#define AFIO_LINE5      			5
#define AFIO_LINE6      			6
#define AFIO_LINE7      			7
#define AFIO_LINE8      			8
#define AFIO_LINE9      			9
#define AFIO_LINE10     			10
#define AFIO_LINE11     			11
#define AFIO_LINE12     			12
#define AFIO_LINE13     			13
#define AFIO_LINE14     			14
#define AFIO_LINE15     			15

/* Copy_u8PortMap (CHOOSE PORT OF PIN) */
#define AFIO_PORTA					0
#define AFIO_PORTB					1
#define AFIO_PORTC					2



/********************************************************************************************/
/* Functions Prototype					 			                                        */
/********************************************************************************************/
u8 MAFIO_u8SetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap);

#endif
/********************************************************************************************/
/* END OF FILE: AFIO_interface.h                                                            */
/********************************************************************************************/
