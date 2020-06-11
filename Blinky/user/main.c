#include<avr/io.h>
#include<util/delay.h>  //sfr Special function registers
#define sbi(sfr,bit)   (sfr |= (1<<bit))  // Set Bit In Registers
#define cbi(sfr,bit)   (sfr &= ~(1<<bit))  // Clear Bit In Registers
#define tbi(sfr,bit)   (sfr ^= (1<<bit))  // Toggle Bit In Registers
int main()
{
	DDRD=0xFF;
	PORTD=0x00;
	while(1)
	{
		_delay_ms(500);
		//PORTD=~PORTD; dao PORTD
		//PIND=0xFF; dao PORTD
		//PIND=0b00000001;// dao bit0 PORTD
		//PIND=(1<<PD0)|(1<<PD2); // PIND+0x01; dich PIND di PD0 lan (do PDx la const)
		tbi(PORTD,PD3);
	}
}
