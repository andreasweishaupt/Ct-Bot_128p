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
			led_on(LED_LEFT);
		}else led_off(LED_LEFT);
			
		if (adc_wert[7] > 400){
			led_on(LED_RIGHT);
				
		}else led_off(LED_RIGHT);
		
		/*
		if(adc_wert[6] < 400 && adc_wert[7] < 400 && adc_wert[2] < 200 && adc_wert[3] < 200){
			setMotorSpeed(20,20);
		}else if(adc_wert[6] > 400 && adc_wert[7] > 400){
			
			setMotorSpeed(50,50);
			
		}else{
			
			if (adc_wert[6] > 400){
				setMotorSpeed(10,50);
			}else if (adc_wert[7] > 400){
				setMotorSpeed(50,10);
			}else if (adc_wert[2] < 200){
				setMotorSpeed(40,20);
			}else if (adc_wert[3] < 200){
				setMotorSpeed(20,40);
			}else setMotorSpeed(50,50);
		}
		*/
		if(speedR > 500) speedR = 500;
		if(speedL > 500) speedL = 500;
		
		
		
		if (!(triggerR || triggerL)){
			if(adc_wert[2] < 100) triggerL = 1;
			if(adc_wert[3] < 100) triggerR = 1;
			
			if(speedL != 0){
				/*
				if(speedL < 0){ speedL += 4;}
				if(speedL < 0){ speedL += 2;}
				if(speedL < 0){ speedL += 1;}
				if(speedL > 0){ speedL -= 4;}
				if(speedL > 0){ speedL -= 2;}
				if(speedL > 0){ speedL -= 1;}
				*/
				for(int z = 0; z < 5; z++){
					if(speedL == 0) break;
					if(speedL < 0) {
						speedL++;
						} else{
						speedL--;
					}
				}
			}
			if(speedR != 0){
				/*
				if(speedR < 0){ speedR += 4;}
				if(speedR < 0){ speedR += 2;}
				if(speedR < 0){ speedR += 1;}
				if(speedR > 0){ speedR -= 4;}
				if(speedR > 0){ speedR -= 2;}
				if(speedR > 0){ speedR -= 1;}
				*/
				for(int z = 0; z < 5; z++){
					if(speedR == 0) break;
					if(speedR < 0) {
						speedR++;
					} else{
						speedR--;
					}
				}
			}
			setMotorSpeed(20+speedL/teiler,20+speedR/teiler);
		}
		else if(triggerR && triggerL){
			setMotorSpeed(0,0);
			if(adc_wert[2] > 100){
				triggerL = 0;
				speedL += 200;
			}
			if(adc_wert[3] > 100){
				triggerR = 0;
				speedR += 200;
			}
		}
		else if (triggerL){
			if(adc_wert[2] > 100){
				triggerL = 0;
				speedT = speedL;
				speedL = speedR - 250;
				speedR = speedT + 450;
			}else{
				if(adc_wert[3] < 100){
					speedL += 1;
					//speedR -= 1;
				}
				 if(adc_wert[6] > 400){
					speedL += 100;
					speedR -= 100;
					//setMotorSpeed(-50,50);
					//_delay_ms(1);
				}
				speedL += 1;
				//speedR -= 1;
				setMotorSpeed(10+speedL/teiler, 10+speedR/teiler);
			}
		}
		else if(triggerR){
			if(adc_wert[3] > 100){
				triggerR = 0;
				speedT = speedR;
				speedR = speedL - 250;
				speedL = speedT + 450;
			}else{
				if(adc_wert[2] < 100){
					speedR += 1;
					//speedL -= 1;
				}
				if(adc_wert[7] > 400){
					speedR += 100;
					speedL -= 100;
					//setMotorSpeed(-50,50);
					//_delay_ms(1);
				}
				//speedL -= 1;
				speedR += 1;
				setMotorSpeed(10+speedL/teiler, 10+speedR/teiler);
			}
		}
		
		
		
		
		
		
    }
}
