/*
 * main.c
 *
 *  Created on: May 5, 2020
 *      Author: KyThuat88
 */
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<util.h>
volatile unsigned int ov_cnt=0;
int main()
{
	unsigned char nghin,tram,chuc,donvi;
	unsigned int t;
	DDRB=0x0F;
	DDRC=0x0F;
	TCCR0B=0x06;                  // chon External Clock falling edge
	TIMSK0|=(1<<TOIE0);
	sei();
	while(1)
	{                // TCNT0 ghi gia tri cua T/C0
	   t =TCNT0+ ov_cnt*256;
	   if(t==1000)
	   {
		   t=0;
		   TCNT0=0;
		   ov_cnt=0;
	   }

	   nghin=t/1000;
       tram=t%1000/100;
       chuc=t%100/10;
       donvi=t%10;

       PORTB=nghin;
       cbi(PORTC,PC0);
       _delay_ms(1);
       sbi(PORTC,PC0);

       PORTB=tram;
       cbi(PORTC,PC1);
       _delay_ms(1);
       sbi(PORTC,PC1);

       PORTB=chuc;
       cbi(PORTC,PC2);
       _delay_ms(1);
       sbi(PORTC,PC2);

       PORTB=donvi;
       cbi(PORTC,PC3);
       _delay_ms(1);
       sbi(PORTC,PC3);
	}
}
ISR(TIMER0_OVF_vect)
{
	ov_cnt++;
}

