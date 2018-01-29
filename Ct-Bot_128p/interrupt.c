/*
 * interrupt.c
 *
 * Created: 29.01.2018 12:17:20
 *  Author: JohnI
 */ 

#include "interrupt.h"


ISR(ADC_vect){
	adc_value[channel] = ADCL + (ADCH << 8);
	channel++;
	if(channel>=8)
	channel=0;
	ADMUX = (1<<REFS0) | (channel & 0x07);       
	ADCSRA |= (1 << ADSC);
}

void initInterrupt(){
	channel=0;
	sei();	
}