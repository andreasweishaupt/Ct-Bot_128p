/*
 * shift.c
 *
 * Created: 19.01.2018 12:10:11
 *  Author: Andreas
 */ 

#include "shift.h"


/* Initialisert die schieberegister_init*/
void schieberegister_init(){
	DDRC |= 0x1F;		// Alle Pins die Ausgänge sind und Ausgänge Schalten
	PORTC &= ~0x1F; 	// Und auf Null
}


/* Schiebt Daten durch eines der drei 74HC595-Schieberegister und den Port danach noch zurücksetzen*/
void schieberegister_data_schicken(unsigned char data, unsigned char data_send, unsigned char data_schieben){
	int i=0;

	PORTC &= ~0x1F;		                   // und wieder clear
	while(i!=8){
		PORTC |= ((data >> 7)& 0x01);     // SDI=PORTC.0=BitWert (Datenleitung Schieberegister)
		PORTC |= data_send;	    	   // und ins jeweilige Storageregister senden(SRCLK)
		data= data << 1;		      	   // data links schieben
		PORTC &= ~0x1F;		               // und wieder clear
		i++;
	}
	
	PORTC |= data_schieben;			       // alles wird ins Output register geschoben -->(RCLK)
	PORTC &= ~0x1F;		                   // und wieder clear
}