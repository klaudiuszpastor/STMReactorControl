/*
 * lcd.h
 *
 *  Created on: Jan 3, 2025
 *      Author: User
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#pragma once

#include <stdint.h>

#define LCD_WIDTH	160
#define LCD_HEIGHT	128

#define BLACK			0x0000
#define RED			0x00f8
#define GREEN			0xe007
#define BLUE			0x1f00
#define YELLOW			0xe0ff
#define MAGENTA			0x1ff8
#define CYAN			0xff07
#define WHITE			0xffff

void lcd_init(void);
void lcd_put_pixel(int x, int y, uint16_t color);
void lcd_copy(void);

#endif /* INC_LCD_H_ */
