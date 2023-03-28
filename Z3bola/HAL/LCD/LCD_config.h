/*
 * LCD_config.h
 *
 *  Created on: Mar 26, 2023
 *      Author: Delta Store
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
//*********PRE BUILD*******/
#define LCD_DATA_PORT		DIO_PORTA
#define LCD_INIT_MODE		EIGHT_BIT_MODE
#define LCD_ALL_OUTPUT		0XFF

#define LCD_RW_PIN		PIN0
#define LCD_RS_PIN		PIN1
#define	LCD_EN_PIN		PIN2
#define LCD_CTRL_PORT	DIO_PORTB

//#define LCD_ROW_POSITION
//#define LCD_COL_POSITION




#endif /* HAL_LCD_LCD_CONFIG_H_ */
