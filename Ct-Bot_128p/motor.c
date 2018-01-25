/*
 * motor.c
 *
 * Created: 19.01.2018 11:56:05
 *  Author: Andreas
 */ 

#include "motor.h"
void motor_init(void){
	DDRD |= 0x30;//Register D setze PD4,PD5 als Ausgang
	PORTD |= 0x30;//PortD PD4,PD5 auf HIGH setzen
	DDRC |= 0xC0;//Register C setze PD6,PD7 als Ausgang
	PORTC |= 0x40;//PortC PD6,PD7 auf HIGH setzen
	PORTC &= ~0x80;

	//TCCR1A = (1 << WGM10)|(1<<COM1A1)|(1 << COM1B1);
	//TCCR1B = 0b00100011;
	TCCR1A = (1<< WGM10) |(1<<COM1A1) |(1 << COM1B1) ;
	TCCR1B = (1<<CS11) | (1<<CS10);
	OCR1A = 0;                                //Vergleichswert festlegen
	OCR1B = 0;
}

void setMotorSpeed(int left_speed, int right_speed){
	OCR1A = abs(left_speed);                                //Vergleichswert festlegen
	OCR1B = abs(right_speed);
	
	if(left_speed > 0 )
	{PORTC |= 0x40;
	sl=1;}
	if(left_speed < 0 )
	{PORTC &= ~0x40;
	sl=0;}
	if(	left_speed == 0 )
	sl=2;
	
	
	if(right_speed < 0 )					// Einer der Motoren ist invertiert, da er ja in die andere Richtung schaut
	{PORTC |= 0x80;
	sr=0;}
	if(right_speed > 0 )
	{PORTC &= ~0x80;
	sr=1;}
	if(	right_speed == 0 )
	sr=2;
}