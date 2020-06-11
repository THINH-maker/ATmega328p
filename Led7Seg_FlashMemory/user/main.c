/*
 * main.c
 *
 *  Created on: May 4, 2020
 *      Author: KyThuat88
 */
#include<avr/io.h>
#include<util/delay.h>
#include<avr/pgmspace.h>
unsigned char Led7Seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
int main()
{
	unsigned char i,j;
	DDRD=0xFF;
	DDRC=0xFF;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			PORTD=Led7Seg[i];
			for(j=0;j<10;j++)
			{
			PORTC=Led7Seg[j];
			_delay_ms(500);
			}
		}
	}
}


