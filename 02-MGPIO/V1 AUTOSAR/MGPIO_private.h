/*
 * GPIO_private.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDET.h"


#define GPIO_PORTA_BASE_ADDRESS 0x40010800
#define GPIO_PORTC_BASE_ADDRESS 0x40011000
#define GPIO_PORTB_BASE_ADDRESS 0x40010C00
#define GPIO_PORTD_BASE_ADDRESS 0x40011400
typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
}GPIO_TYPE;



#define GPIOA              ((GPIO_TYPE*)GPIO_PORTA_BASE_ADDRESS)
#define GPIOC              ((GPIO_TYPE*)GPIO_PORTC_BASE_ADDRESS)
#define GPIOB              ((GPIO_TYPE*)GPIO_PORTB_BASE_ADDRESS)
//#define GPIOD              ((GPIO_TYPE*)GPIO_PORTD_BASE_ADDRESS)

#define NOT_USED  255

typedef enum
{
	LOW,
	HIGH

}Dio_LevelType,Dio_PortLevelType, PIN_STATE_E ;


typedef enum
{
	A0=0,
	A1,
	A2,
	A3,
	A4,
	A5,
	A6,
	A7,
	A8,
	A9,
	A10,
	A11,
	A12,
	A13,
	A14,
	A15,
	B0,
	B1,
	B2,
	B3,
	B4,
	B5,
	B6,
	B7,
	B8,
	B9,
	B10,
	B11,
	B12,
	B13,
	B14,
	B15,
	C0,
	C1,
	C2,
	C3,
	C4,
	C5,
	C6,
	C7,
	C8,
	C9,
	C10,
	C11,
	C12,
	C13,
	C14,
	C15

}Dio_ChannelType;

typedef enum
{
	PORTA,
	PORTB,
	PORTC

}Dio_PortType, PORT_IDs_E;

/*Function id*/
typedef enum
{
	GPIO_VidInitId,
	GPIO_SET_PIN_VALUEId,
	GPIO_voidSetPinValueBSRRId,
	GPIO_GET_PIN_VALUEId
}GPIO_FunctionsIDs_E;

/*Errors id*/
typedef enum{
	GPIO_invalidPortId,
	GPIO_invalidPinId,
	GPIO_invalidModeId,
	GPIO_invalidValueHighLowId
}GPIO_ErrorsIDs_E;


typedef enum
{
	PIN0  ,
	PIN1  ,
	PIN2  ,
	PIN3  ,
	PIN4  ,
	PIN5  ,
	PIN6  ,
	PIN7  ,
	PIN8  ,
	PIN9  ,
	PIN10 ,
	PIN11 ,
	PIN12 ,
	PIN13 ,
	PIN14 ,
	PIN15
}PIN_IDs_E;


#define NUMBER_OF_USED_PINS_GROUP 4
#define SW_RELEASE_VERSION  1
#define SW_MAJOR_VERSION    0
#define SW_MINOR_VERSION    0

typedef struct {
u8 Major;
u8 Minor;

}Std_VersionInfoType;


typedef enum
{
	INPUT,
	OUTPUT

}MODE_IDs_E;


typedef enum
{
	PUSH_PULL,
	OPEN_DRAIN
}TYPE_IDs_E;

typedef enum
{
    LOW_SPEED,
    MEDIUM_SPEED,
    HIGH_SPEED

}SPEED_IDs_E;


typedef enum
{
	FLOATING,
	PULL_UP,
	PULL_DOWN
}INPUT_TYPE_IDs_E;


#endif /* MGPIO_PRIVATE_H_ */
