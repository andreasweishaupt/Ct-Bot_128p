/*
 * Ct-Bot_128p.c
 *
 * Created: 19.01.2018 11:20:50
 * Author : Andreas
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "motor.h"
#include "led.h"
#include "display.h"
#include "sensoren.h"
#include "adc.h"
#include "maus.h"

volatile int adc_wert[8],channel;
int eins = 0;
int null1 = 0;

int index = 0;

//Linienverfolgung Variablen
int triggerR, triggerL = 0;
int speedR, speedL, speedT = -60;
int teiler = 20;


	
ISR(ADC_vect){
	adc_wert[channel] = ADCL + (ADCH << 8);
	channel++;
	if(channel>=8)
	channel=0;
	ADMUX = (1<<REFS0) | (channel & 0x07);         // interne Refernzspannung, rechts Ausrichtung
	ADCSRA |= (1 << ADSC);	
	
	distanceLeft[index]= adc_wert[0];
	index = (index + 1)%20;
}



int main(void)
{
	channel=0;
	
	ena_init();	
	adc_init();
	sensoren_isr();
	motor_init();
	

	
	display_init();
	led_init();
	encoder_isr();
	//maus_init();
	ena_ein(ENA_RADLED);
	sei();
	
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		/*
		_delay_ms(1000);
		befehl_schicken(CLEAR);
		display_ausgabe("%4d", adc_wert[6]);
		display_ausgabe("%4d", adc_wert[2]);
		display_ausgabe("%4d", adc_wert[3]);
		display_ausgabe("%4d", adc_wert[7]);
		*/
		
		/*
		_delay_ms(500);
		befehl_schicken(CLEAR);
		display_ausgabe("%4d", adc_wert[2]);
		display_ausgabe("%4d", adc_wert[3]);
		*/
		
		
		/*_delay_ms(500);
		befehl_schicken(CLEAR);
		display_ausgabe("%4d", triggerL);
		display_ausgabe("%4d", speedL);
		display_ausgabe("%4d", speedR);
		display_ausgabe("%4d", triggerR);
		*/
		
		//Git-Test-2
		
		if (adc_wert[6] > 400){
			led_ein(LED_LINKS);
		}else led_aus(LED_LINKS);
			
		if (adc_wert[7] > 400){
			led_ein(LED_RECHTS);
				
		}else led_aus(LED_RECHTS);
		
		
    }
}

