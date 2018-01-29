/*
 * initall.c
 *
 * Created: 29.01.2018 12:06:22
 *  Author: JohnI
 */ 
#include "initall.h"


void intAllPeripherals(){
	
	initInterrupt();
	ena_init();
	adc_init();
	sensoren_isr();
	motor_init();
	display_init();
	led_init();
	
}
