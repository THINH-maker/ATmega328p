/*
 * main.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Tran Manh
 *      Description: Giao Tiep ATmega328p voi LCD 16x2 che do 4 bit
 *      Chu y chinh sua chan ket noi trong file LCD4.h sao cho phu hop voi ket noi tren proteus
 *      De su dung chi can tao project moi. Copy 4 file main.c, LCD4.c,LCD4.h,util.h vao thu muc Project vua tao roi build
 */
#include<avr/io.h>
#include <util/delay.h>
#include "util.h"
#include "LCD4.h"

int main()
{
	DDRD=0xFF;
	LCD_Init();
	LCD_Str_Cursor(1,1,"Thinh dz");
	_delay_ms(200);
	LCD_Str_Cursor(2,1,"thinh ok");
	_delay_ms(1000);
	while(1)
	{
		LCD_Left();
	}
}
