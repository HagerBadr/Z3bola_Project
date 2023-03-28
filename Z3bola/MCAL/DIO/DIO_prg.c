/*
 * DIO_prg.c
 *
 *  Created on: Mar 25, 2023
 *      Author: Delta Store
 */

/*******Library Includes********/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/********Lower Layer Inclusions********/
/********Self Files Inclusions*********/
#include"DIO_int.h"
#include"DIO_priv.h"
#include"DIO_config.h"

void MDIO_voidSetPinDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8Direction)
{
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRA_REG, Copy_u8PinNumber);
		}
		else if(Copy_u8Direction == INPUT)
		{
			CLR_BIT(DDRA_REG, Copy_u8PinNumber);
		}
		else
		{

		}
		break;
	case DIO_PORTB:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRB_REG, Copy_u8PinNumber);
		}
		else if(Copy_u8Direction == INPUT)
		{
			CLR_BIT(DDRB_REG, Copy_u8PinNumber);
		}
		else
		{

		}
		break;
	case DIO_PORTC:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRC_REG, Copy_u8PinNumber);
		}
		else if(Copy_u8Direction == INPUT)
		{
			CLR_BIT(DDRC_REG, Copy_u8PinNumber);
		}
		else
		{

		}
		break;
	case DIO_PORTD:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRD_REG, Copy_u8PinNumber);
		}
		else if(Copy_u8Direction == INPUT)
		{
			CLR_BIT(DDRD_REG, Copy_u8PinNumber);
		}
		else
		{

		}
		break;
	}
}

void MDIO_voidSetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8state)
{
	switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			switch(Copy_u8state)
			{
			case HIGH:
				SET_BIT(PORTA_REG,Copy_u8PinNumber);
				break;
			case LOW:
				CLR_BIT(PORTA_REG,Copy_u8PinNumber);
				break;
			}
			break;
		case DIO_PORTB:
			switch(Copy_u8state)
			{
			case HIGH:
				SET_BIT(PORTB_REG,Copy_u8PinNumber);
				break;
			case LOW:
				CLR_BIT(PORTB_REG,Copy_u8PinNumber);
				break;
			}
				break;
		case DIO_PORTC:
			switch(Copy_u8state)
			{
			case HIGH:
				SET_BIT(PORTC_REG,Copy_u8PinNumber);
				break;
			case LOW:
				CLR_BIT(PORTC_REG,Copy_u8PinNumber);
				break;
			}
				break;
		case DIO_PORTD:
			switch(Copy_u8state)
			{
			case HIGH:
				SET_BIT(PORTD_REG,Copy_u8PinNumber);
				break;
			case LOW:
				CLR_BIT(PORTD_REG,Copy_u8PinNumber);
				break;
			}
				break;
		}
}

u8 MDIO_void_getPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber)
{
	u8 Local_u8PinValue;

	switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			Local_u8PinValue = GET_BIT(PINA_REG,Copy_u8PinNumber);
			break;
		case DIO_PORTB:
			Local_u8PinValue = GET_BIT(PINB_REG,Copy_u8PinNumber);
				break;
		case DIO_PORTC:
			Local_u8PinValue = GET_BIT(PINC_REG,Copy_u8PinNumber);
				break;
		case DIO_PORTD:
			Local_u8PinValue = GET_BIT(PIND_REG,Copy_u8PinNumber);
				break;
		}
	return Local_u8PinValue;
}

void MDIO_voidSetPortSpecificDirection(u8 Copy_u8PortNumber,u8 Copy_u8SpecificDirection)
{
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		//DDRA_REG == Copy_u8SpecificDirection;
		SET_REG(DDRA_REG,Copy_u8SpecificDirection);
		break;
	case DIO_PORTB:
		SET_REG(DDRB_REG,Copy_u8SpecificDirection);
		break;
	case DIO_PORTC:
		SET_REG(DDRC_REG,Copy_u8SpecificDirection);
		break;
	case DIO_PORTD:
		SET_REG(DDRD_REG,Copy_u8SpecificDirection);
		break;
	default :
		break;
	}
}
void MDIO_voidSetPortSpecificValue(u8 Copy_u8PortNumber,u8 Copy_u8state)
{
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		SET_REG(PORTA_REG,Copy_u8state);
		break;
	case DIO_PORTB:
		SET_REG(PORTB_REG,Copy_u8state);
		break;
	case DIO_PORTC:
		SET_REG(PORTC_REG,Copy_u8state);
		break;
	case DIO_PORTD:
		SET_REG(PORTD_REG,Copy_u8state);
		break;
	}
}
