/*
 * LCD_priv.h
 *
 *  Created on: Mar 26, 2023
 *      Author: Delta Store
 */

#ifndef HAL_LCD_LCD_PRIV_H_
#define HAL_LCD_LCD_PRIV_H_


#define EIGHT_BIT_MODE			1
#define FOUR_BIT_MODE			0
#define FUNCTION_SET_CMD		0x3b
#define DISPLAY_ON_OFF_CMD		0x0f
#define DISPALY_CLEAR_CMD		0x01



static void LCD_voidSendCommand(u8 Copy_u8Command);


#endif /* HAL_LCD_LCD_PRIV_H_ */
