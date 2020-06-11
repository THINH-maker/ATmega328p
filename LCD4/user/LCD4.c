/*
 * LCD4.c
 *
 *  Created on: Sep 6, 2019
 *      Author: Tran Manh
 */
#include "LCD4.h"
#include <avr/io.h>
#include <util/delay.h>
#include "util.h"

void LCD_Enable()
{
	sbi(LCD_PORT,LCD_EN);
	cbi(LCD_PORT,LCD_EN);

}
void LCD_Send1Byte(unsigned char c)
{
	if(c & 0x80) sbi(LCD_PORT,LCD_D7); else cbi(LCD_PORT,LCD_D7);
	if(c & 0x40) sbi(LCD_PORT,LCD_D6); else cbi(LCD_PORT,LCD_D6);
	if(c & 0x20) sbi(LCD_PORT,LCD_D5); else cbi(LCD_PORT,LCD_D5);
	if(c & 0x10) sbi(LCD_PORT,LCD_D4); else cbi(LCD_PORT,LCD_D4);
	LCD_Enable();
	if(c & 0x08) sbi(LCD_PORT,LCD_D7); else cbi(LCD_PORT,LCD_D7);
	if(c & 0x04) sbi(LCD_PORT,LCD_D6); else cbi(LCD_PORT,LCD_D6);
	if(c & 0x02) sbi(LCD_PORT,LCD_D5); else cbi(LCD_PORT,LCD_D5);
	if(c & 0x01) sbi(LCD_PORT,LCD_D4); else cbi(LCD_PORT,LCD_D4);
	LCD_Enable();
	_delay_ms(1);
}

void LCD_Clear()
{
	cbi(LCD_PORT,LCD_RS);
	LCD_Send1Byte(_LCD_CLEAR);
	_delay_ms(2);
}
void LCD_Str(char *str)
{
	unsigned char i = 0;
	sbi(LCD_PORT,LCD_RS);
	while(str[i])
		{
			LCD_Char(str[i]);
			i++;
		}
}
void LCD_Str_Cursor(unsigned char row, unsigned char col, char *s)
{
	unsigned char add;
	//add = (row==1?0x80:0xC0);
	//add += (column - 1);
	if (row==1) add=0x7F;
		else if (row == 2) add = 0xbf;
		else if (row == 3) add = 0x8f;
		else if (row == 4) add = 0xcf;
	add += (col);
	cbi(LCD_PORT,LCD_RS);
	LCD_Send1Byte(add);
	sbi(LCD_PORT,LCD_RS);
	LCD_Str(s);
}
void LCD_Char(unsigned char chr)
{
	sbi(LCD_PORT,LCD_RS);
	LCD_Send1Byte(chr);
}
void LCD_Char_Cursor(unsigned char row,unsigned char col,unsigned char chr)
{
	unsigned char add;
	/*add = (row==1?0x80:0xC0);
	add += (column - 1);*/
	if (row==1) add=0x7F;
	else if (row == 2) add = 0xbf;
	else if (row == 3) add = 0x8f;
	else if (row == 4) add = 0xcf;
	add += (col);
	cbi(LCD_PORT,LCD_RS);
	LCD_Send1Byte(add);
	sbi(LCD_PORT,LCD_RS);
	LCD_Char(chr);
}
void LCD_Init()
{
	cbi(LCD_PORT,LCD_RS);
	_delay_ms(15);
	sbi(LCD_PORT,LCD_D4);
	sbi(LCD_PORT,LCD_D5);
	LCD_Enable();
	_delay_ms(5);
	LCD_Enable();
	_delay_us(100);
	LCD_Enable();
	_delay_ms(5);
	cbi(LCD_PORT,LCD_D4);
	LCD_Enable();
	_delay_us(40);
	LCD_Send1Byte(_LCD_4BIT_2LINE_5x7FONT);
	LCD_Send1Byte(_LCD_TURN_ON);
	LCD_Send1Byte(_LCD_CLEAR);
	LCD_Send1Byte(_LCD_ENTRY_MODE);
}
void LCD_SetCursor(unsigned char row, unsigned char col)
{
	{
		unsigned char address;
		if (row == 0) address = (0x80 + col);	 // row=0 - hang 1
	    else address = (0xC0 + col);			 // row=1 - hang 2
	    _delay_us(1000);
	    LCD_Send1Byte(address);
	    _delay_us(50);
	}
}
void LCD_Left()
{
	PORTD=0xFE;
	LCD_Send1Byte(0x18);
	_delay_ms(500);
}
void LCD_Right()
{
	PORTD &=0xFE;
	LCD_Send1Byte(0x1C);
	_delay_ms(500);
}
