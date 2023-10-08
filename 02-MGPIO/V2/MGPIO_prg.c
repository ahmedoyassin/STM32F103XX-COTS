/*
 * GPIO_prg.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#include "../Inc/MGPIO_interface.h"


u8 MGPIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
	case GPIOA :
		if(Copy_u8Pin <= GPIO_PIN7)
		{
			GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
			GPIOA_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}


		else if(Copy_u8Pin <= GPIO_PIN15)
		{
			Copy_u8Pin -= 8;
			GPIOA_CRH &= ~((0b1111) << (Copy_u8Pin * 4));
			GPIOA_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else
			Local_u8ErrorState = NOK;
		break;

	case GPIOB :
		if(Copy_u8Pin <= GPIO_PIN7)
		{
			GPIOB_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
			GPIOB_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= GPIO_PIN15)
		{
			Copy_u8Pin -= 8;
			GPIOB_CRH &= ~((0b1111) << (Copy_u8Pin * 4));
			GPIOB_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
		break;
	case GPIOC :
		if(Copy_u8Pin <= GPIO_PIN7)
		{
			GPIOC_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
			GPIOC_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= GPIO_PIN15)
		{

			Copy_u8Pin -= 8;
			GPIOC_CRH &= ~((0b1111) << (Copy_u8Pin * 4));
			GPIOC_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else
			Local_u8ErrorState = NOK;
		break;
	default :   Local_u8ErrorState = NOK;
		break;
	}

	return Local_u8ErrorState;
}

u8 MGPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{

	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
	case GPIOA :
		if(Copy_u8Value == GPIO_HIGH)
			GPIOA_BSRR = (1 <<  Copy_u8Pin);
		else if(Copy_u8Value == GPIO_LOW)
			GPIOA_BRR =	(1 <<  (Copy_u8Pin));
		else
			Local_u8ErrorState = NOK;
		break;

	case GPIOB :
		if(Copy_u8Value == GPIO_HIGH)
			GPIOB_BSRR = (1 <<  Copy_u8Pin);
		else if(Copy_u8Value == GPIO_LOW)
			GPIOB_BRR =	(1 <<  (Copy_u8Pin));
		else
			Local_u8ErrorState = NOK;
		break;
	case GPIOC :
		if(Copy_u8Value == GPIO_HIGH)
			GPIOC_BSRR = (1 <<  Copy_u8Pin);
		else if(Copy_u8Value == GPIO_LOW)
			GPIOC_BRR =	(1 <<  (Copy_u8Pin));
		else
			Local_u8ErrorState = NOK;
		break;
	default :  Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState = OK;

	if((Copy_pu8Value != NULL) && (Copy_u8Pin <= GPIO_PIN15))
	{
		switch(Copy_u8Port)
		{
		case GPIOA :	*Copy_pu8Value = GET_BIT(GPIOA_IDR , Copy_u8Pin);
		break;
		case GPIOB :	*Copy_pu8Value = GET_BIT(GPIOB_IDR , Copy_u8Pin);
		break;
		case GPIOC :	*Copy_pu8Value = GET_BIT(GPIOC_IDR , Copy_u8Pin);
		break;
		default    :    Local_u8ErrorState = NOK;   break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 MGPIO_u8SetLowPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode)
{

	u8 Local_u8ErrorState = OK;


	switch(Copy_u8Port)
	{
	case GPIOA	:	GPIOA_CRL = Copy_u32HalfPortMode;	break;
	case GPIOB	:	GPIOB_CRL = Copy_u32HalfPortMode;	break;
	default   	: 	Local_u8ErrorState = NOK;	break;
	}
	return Local_u8ErrorState;
}

u8 MGPIO_u8SetHighPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode)
{
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Port)
	{
	case GPIOA	:	GPIOA_CRH = Copy_u32HalfPortMode;	break;
	case GPIOB	:	GPIOB_CRH = Copy_u32HalfPortMode;	break;
	default   	: 	Local_u8ErrorState = NOK;	break;
	}
	return Local_u8ErrorState;
}

u8 MGPIO_u8SetHalfPortValue(u8 Copy_u8Port , u8 Copy_u8HalfPort , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_u8Port == GPIOA)
	{
		switch(Copy_u8HalfPort)
		{
		case GPIO_1ST_HALF_PORT:
			GPIOA_ODR &= GPIO_1ST_HALF_PORT_MASK;
			GPIOA_ODR |= Copy_u8Value;
			break;

		case GPIO_2ND_HALF_PORT:
			GPIOA_ODR &= GPIO_2ND_HALF_PORT_MASK;
			GPIOA_ODR |= Copy_u8Value << 8;
			break;

		default	:  Local_u8ErrorState = NOK;   break;
		}
	}
	else if(Copy_u8Port == GPIOB)
	{
		switch(Copy_u8HalfPort)
		{
		case GPIO_1ST_HALF_PORT:
			GPIOB_ODR &= GPIO_1ST_HALF_PORT_MASK;
			GPIOB_ODR |= Copy_u8Value;
			break;

		case GPIO_2ND_HALF_PORT:
			GPIOB_ODR &= GPIO_2ND_HALF_PORT_MASK;
			GPIOB_ODR |= Copy_u8Value << 8;
			break;

		default	:  Local_u8ErrorState = NOK;   break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

void MGPIO_voidSetPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode)
{
	MGPIO_u8SetLowPortDirection(Copy_u8Port , Copy_u32HalfPortMode);
	MGPIO_u8SetHighPortDirection(Copy_u8Port , Copy_u32HalfPortMode);
}

u8 MGPIO_u8SetPortValue(u8 Copy_u8Port , u16 Copy_u16Value)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
	case GPIOA	:	GPIOA_ODR = Copy_u16Value;	break;
	case GPIOB	:	GPIOB_ODR = Copy_u16Value;	break;
	default   	: 	Local_u8ErrorState = NOK;	break;
	}
	return Local_u8ErrorState;
}
