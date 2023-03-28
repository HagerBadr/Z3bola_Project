/*
 * main2.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Delta Store
 */

//#include<avr/delay.h>
#include<util/delay.h>
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_int.h"
//#include"../MCAL/DIO/DIO_priv.h"

#include"../HAL/LCD/LCD_int.h"

void main(void)
{
	u8 customChar[] = {
			  0x00,
			  0x00,
			  0x0E,
			  0x0E,
			  0x04,
			  0x0E,
			  0x11,
			  0x00
			};
	u8 customChar2[] = { 0x0E, 0x0E,0x15, 0x0E, 0x04, 0x0E, 0x11, 0x00};
	u8 customChar3[] = {  0x07,
			  0x07,
			  0x02,
			  0x12,
			  0x07,
			  0x09,
			  0x00,
			  0x00};
	u8 customChar4[] = {  0x07,
			  0x07,
			  0x02,
			  0x02,
			  0x17,
			  0x09,
			  0x00,
			  0x00};
	u8 customChar5[] = { 0x1F, 0x14,0x1C,0x18,0x10, 0x10, 0x10, 0x10};
	u8 customChar6[] = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00};
	u8 customChar7[] = { 0x0E, 0x0E, 0x04, 0x0E, 0x15, 0x0E, 0x11, 0x00};
	u8 customChar8[] = {  0x00,
			  0x00,
			  0x00,
			  0x10,
			  0x08,
			  0x07,
			  0x08,
			  0x10};
	u8 customChar9[] = {    0x00,
			  0x00,
			  0x00,
			  0x07,
			  0x07,
			  0x1F,
			  0x00,
			  0x00};
	u8 customChar10[] = { 0x00, 0x0A, 0x00, 0x0E,0x11,0x11, 0x00, 0x00};
	u8 customChar11[] = {0x0A, 0x00, 0x11, 0x11, 0x0E, 0x00,  0x00,0x00};
	LCD_voidInit();

	while(1)
	{
		LCD_void_SendString("My Name is ");
		LCD_voidGoToXY(1,3);
		LCD_void_SendString("Z3bola");
		LCD_voidSendCustomCharacter(customChar7,3, 0, 14);
		LCD_voidSendCustomCharacter(customChar2,1, 0, 14);

		LCD_voidSendCustomCharacter(customChar7,3, 0, 14);
		LCD_voidSendCustomCharacter(customChar2,1, 0, 14);

		LCD_voidSendCustomCharacter(customChar7,3, 0, 14);
		LCD_voidSendCustomCharacter(customChar2,1, 0, 14);
		LCD_ClearDisplay();

		LCD_void_SendString("I Can Play");
		LCD_voidGoToXY(1,3);
		LCD_void_SendString("Football");
		LCD_voidSendCustomCharacter(customChar3,1, 0, 15);
		LCD_voidSendCustomCharacter(customChar4,1, 0, 15);

		LCD_voidSendCustomCharacter(customChar3,1, 0, 15);
		LCD_voidSendCustomCharacter(customChar4,1, 0, 15);

		LCD_voidSendCustomCharacter(customChar3,1, 0, 15);
		LCD_voidSendCustomCharacter(customChar4,1, 0, 15);
		LCD_ClearDisplay();

		LCD_void_SendString("Let's Play A");
		LCD_voidGoToXY(1,2);
		LCD_void_SendString("Game");
		LCD_voidSendCustomCharacter(customChar11,1, 1, 7);
		_delay_ms(200);
		LCD_ClearDisplay();

		LCD_voidGoToXY(0,4);
		LCD_void_SendString("Don't Kill");
		LCD_voidGoToXY(1,7);
		LCD_void_SendString("me");
		LCD_voidSendCustomCharacter(customChar5,2, 1, 1);
	//	LCD_voidSendCustomCharacter(customChar6,1, 1, 1);
		LCD_voidSendCustomCharacter(customChar7,3, 1, 14);
		LCD_voidSendCustomCharacter(customChar,3, 1, 14);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 2);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 4);
		LCD_voidSendCustomCharacter(customChar7,3, 1, 14);
		LCD_voidSendCustomCharacter(customChar,3, 1, 14);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 6);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 7);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 8);

		LCD_voidSendCustomCharacter(customChar7,3, 1, 14);
		LCD_voidSendCustomCharacter(customChar,3, 1, 14);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 9);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 10);
		LCD_voidSendCustomCharacter(customChar7,3, 1, 14);
		LCD_voidSendCustomCharacter(customChar,3, 1, 14);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 11);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 12);
		LCD_voidSendCustomCharacter(customChar6,1, 1, 13);

		LCD_voidSendCustomCharacter(customChar7,3, 1, 14);

		LCD_ClearDisplay();
		LCD_void_SendString("Z3bola is Dead");
		LCD_voidSendCustomCharacter(customChar10,1, 1, 7);

		LCD_voidSendCustomCharacter(customChar8,2, 1, 12);
		LCD_voidSendCustomCharacter(customChar9,3, 1, 13);
		_delay_ms(1000);
		LCD_ClearDisplay();

	}
}
