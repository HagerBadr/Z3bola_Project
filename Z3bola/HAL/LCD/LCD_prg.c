/*
 * LCD_prg.c
 *
 *  Created on: Mar 26, 2023
 *      Author: Delta Store
 */
/*******Library Includes********/
#include<util/delay.h>

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/********Lower Layer Inclusions********/
#include "../../MCAL/DIO/DIO_int.h"

/********Self Files Inclusions*********/
#include"LCD_int.h"
#include"LCD_priv.h"
#include"LCD_config.h"


void LCD_voidInit(void)
{
#if LCD_INIT_MODE == EIGHT_BIT_MODE
	/**intialize data port**/
	MDIO_voidSetPortSpecificDirection(LCD_DATA_PORT,LCD_ALL_OUTPUT);
	MDIO_voidSetPinDirection(LCD_CTRL_PORT , LCD_RS_PIN,OUTPUT);
	MDIO_voidSetPinDirection(LCD_CTRL_PORT , LCD_EN_PIN,OUTPUT);
	MDIO_voidSetPinDirection(LCD_CTRL_PORT , LCD_RW_PIN,OUTPUT);
	_delay_ms(40);
	LCD_voidSendCommand(FUNCTION_SET_CMD);
	LCD_voidSendCommand(DISPLAY_ON_OFF_CMD);
	LCD_voidSendCommand(DISPALY_CLEAR_CMD);
#elif LCD_INIT_MODE == FOUR_BIT_MODE
#endif
}

static void LCD_voidSendCommand(u8 Copy_u8Command)
{
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,LOW);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);

	MDIO_voidSetPortSpecificValue(LCD_DATA_PORT,Copy_u8Command);
	/****SEND  ENABLE PULSE *****/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);


}

void LCD_voidSendData(u8 Copy_u8Data)
{
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,HIGH);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
	MDIO_voidSetPortSpecificValue(LCD_DATA_PORT,Copy_u8Data);
	/****SEND  ENABLE PULSE *****/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);

}

void LCD_ClearDisplay(void)
{
	LCD_voidSendCommand(DISPALY_CLEAR_CMD);
}
void LCD_voidGoToXY(u8 Copy_u8XPos ,u8 Copy_u8YPos)
{
	/*******Calculate the address on LCD********/
	u8 Local_u8CharacterAddress = 0;
	if(Copy_u8XPos == LCD_ROW0)
	{
		//if x = 0 -> address = Y position
		Local_u8CharacterAddress = Copy_u8YPos;
	}
	else if(Copy_u8XPos == LCD_ROW1)
	{
		//if x = 1 -> address = Y position + 0x40
		Local_u8CharacterAddress = Copy_u8YPos + 0x40;
	}
	else
	{
		//Raise an Error
	}
	/**Set the 7th bit in the address variable**/
	SET_BIT(Local_u8CharacterAddress ,7);
	/**Send the address variable to commend**/
	LCD_voidSendCommand(Local_u8CharacterAddress);
}
void LCD_void_SendString(u8 *Copy_Pu8StringArray)
{
	u8 Copy_Pu8LoopCounter = 0;
	while(Copy_Pu8StringArray[Copy_Pu8LoopCounter] != '\0')	//NULL
	{
		LCD_voidSendData(Copy_Pu8StringArray[Copy_Pu8LoopCounter]);
		Copy_Pu8LoopCounter++;
	}
}

void LCD_void_SendNumber(u32 Copy_u32Number)
{
	u8 Local_u8ArrayNumber[10];
	s8 Local_s8LoopCounter = 0;
	while(Copy_u32Number != 0)
	{
		Local_u8ArrayNumber[Local_s8LoopCounter] = Copy_u32Number % 10;
		Copy_u32Number /=10;
		Local_s8LoopCounter++;
	}
	Local_s8LoopCounter--;
	while(Local_s8LoopCounter >= 0)
	{
		LCD_voidSendData(Local_u8ArrayNumber[Local_s8LoopCounter] + '0');
		Local_s8LoopCounter--;
	}
}

void LCD_voidSendCustomCharacter(u8 *Copy_pu8CharacterArray, u8 Copy_u8PatternNumber,  u8 Copy_u8Xposition,  u8 Copy_u8Yposition)
{
	u8 Local_u8LoopCounter;
	u8 Local_u8CGRAMAddress=0;
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
	SET_BIT(Local_u8CGRAMAddress ,6);
	LCD_voidSendCommand(Local_u8CGRAMAddress);
	for(Local_u8LoopCounter=0 ; Local_u8LoopCounter <8;Local_u8LoopCounter++)
	{
		LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
	}
	LCD_voidGoToXY(Copy_u8Xposition,Copy_u8Yposition);
	LCD_voidSendData(Copy_u8PatternNumber);
}
