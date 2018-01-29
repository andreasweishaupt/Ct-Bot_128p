/*
 * led.c
 *
 * Created: 19.01.2018 12:40:31
 *  Author: Andreas
 */ 

#include "led.h"

uint8_t LED_STATE;

/* Zeigt eine 8-Bit Variable mit den LEDs an */
void led_set(unsigned int LED){
	schieberegister_data_schicken(LED,SCHIEBEREGISTER_LED,1<<1);
}

/* Initialisiert die LEDs */
void led_init(void){
	schieberegister_init();
	LED_STATE = 0x00;
	led_off(0xFF);
}

/* Schaltet einzelne LEDs anandere werden nicht beeinflusst*/
void led_on(unsigned int LED){
	LED_STATE |= LED;
	led_set(LED_STATE);
}

/* Schaltet einzelne LEDs ausandere werden nicht beeinflusst*/
void led_off(unsigned int LED){
	LED_STATE &= ~LED;
	led_set(LED_STATE);
}