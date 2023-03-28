/*
 * LCD_int.h
 *
 *  Created on: Mar 26, 2023
 *      Author: Delta Store
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

void LCD_ClearDisplay(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit(void);
void LCD_voidGoToXY(u8 Copy_u8XPos ,u8 Copy_u8YPos);
void LCD_void_SendString(u8 *Copy_Pu8StringArray);
void LCD_void_SendNumber(u32 Copy_u32Number);
void LCD_voidSendCustomCharacter(u8 *Copy_pu8CharacterArray, u8 Copy_u8PatternNumber,  u8 Copy_u8Xposition,  u8 Copy_u8Yposition);


#define LCD_ROW0				0
#define LCD_ROW1				1
//#define LCD_COL0
//#define LCD_COL1

#endif /* HAL_LCD_LCD_INT_H_ */
