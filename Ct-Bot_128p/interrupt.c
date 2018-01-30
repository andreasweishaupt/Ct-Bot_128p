/*
 * interrupt.c
 *
 * Created: 29.01.2018 12:17:20
 *  Author: JohnI
 */ 

#include "interrupt.h"

int index = 0;
int index1 = 0;
channel = 0;
ISR(ADC_vect){
	adc_value[channel] = ADCL + (ADCH << 8);
	channel++;
	if(channel>=8){
		channel=0;
	}	
	ADMUX = (1<<REFS0) | (channel & 0x07);       
	ADCSRA |= (1 << ADSC);
	leftDistance[index] = adc_value[0];
	rightDistance[index1] = adc_value[1];
	index =  (index + 1) %20;
	index1 = (index1 + 1) %20;
}

void initInterrupt(){
	channel=0;
	sei();	
}