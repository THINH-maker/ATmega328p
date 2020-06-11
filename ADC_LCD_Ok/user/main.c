/*
 * main.c
 *
 *  Created on: May 17, 2020
 *      Author: KyThuat88
 */
#include <avr/io.h>
#include <util/delay.h>
#include "util.h"
#include "LCD4.h"
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
/*khai bao ket noi ADC*/
#define ADC_DDR		DDRC
#define ADC_CHANNEL	0
/*Dinh nghia cac che do hoat dong*/
#define AREF_MODE 	0	//Dien ap tham chieu ngoai VREF
#define AVCC_MODE	(1<<REFS0)//Dien ap tham chieu VCC
#define	INT_MODE	(1<<REFS0)|(1<<REFS1)//Dien ap tham chieu Internal 1.1V


void ADC_init(unsigned char mode)
{
	ADMUX = mode;
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);// Cho phep ADC hoat dong, Prescale 128
}
int ADC_read(char channel)
{
	int High, Low;
	cbi(ADC_DDR,channel); //Make ADC Port as Input
	ADMUX|=channel;	// Chon kenh
	ADCSRA |=(1<<ADSC);	//Bat dau chuyen doi
	while ((ADCSRA &(1<<ADIF))==0);// Cho chuyen doi hoan tat (Co ADIF = 1)
	_delay_us(20);
	Low =  (int)ADCL;
	High = (int)ADCH*256;
	return (Low+High);
}
int main()
{
	DDRD=0xFF;
	int ADC_val;
	int voltage;
	char buf[20];
	LCD_Init();
	LCD_Str_Cursor(1,1,"ADC Value:");
	LCD_Str_Cursor(2,1,"Voltage:");
	ADC_init(AVCC_MODE);
	while(1)
	{
		ADC_val = ADC_read(ADC_CHANNEL);
		sprintf(buf," %d",ADC_val);
		LCD_Str_Cursor(1,12,buf);
		voltage =(int)ADC_val*0.00488f; // 5:1024
		//itoa(voltage,buf,10); // ham chuyen tu int sang string
		sprintf(buf," %d",voltage);
		//ftoa(voltage,buf,2);
		LCD_Str_Cursor(2,10,buf);
		/*LCD_Char_Cursor(2,10,voltage/1000+0x30);
		LCD_Char('.');
		LCD_Char(voltage%1000/100+0x30);
		LCD_Char(voltage%100/10+0x30);*/
	}
}


