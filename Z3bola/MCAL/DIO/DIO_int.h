/*
 * DIO_Iint.h
 *
 *  Created on: Mar 25, 2023
 *      Author: Delta Store
 */
/*******Library Includes********/

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_
//#include"../../STD_TYPES.h"
//#include"../../BIT_MATH.h"
//#include"DIO_priv.h"


#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

#define OUTPUT		1
#define INPUT		0

#define HIGH		1
#define LOW			0

#define PULLUP		1		//with input only
#define NOTPULLUP	0

void MDIO_voidSetPinDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8Direction);
void MDIO_voidSetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8state);
u8 MDIO_void_getPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
void MDIO_voidSetPortSpecificDirection(u8 Copy_u8PortNumber,u8 Copy_u8SpecificDirection);	//
void MDIO_voidSetPortSpecificValue(u8 Copy_u8PortNumber,u8 Copy_u8state);

#endif /* MCAL_DIO_DIO_INT_H_ */
