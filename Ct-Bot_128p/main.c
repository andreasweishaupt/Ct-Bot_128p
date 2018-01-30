/*
 * Ct-Bot_128p.c
 *
 * Created: 19.01.2018 11:20:50
 * Author : Andreas,Michael
 */ 


#include "InitAll.h"
#include "followline.h"
#include <avr/delay.h>

int main(void)
{
	
	intAllPeripherals();	
	//display_ausgabe("Hallo");
	
    /* Replace with your application code */
    while (1) {
		_delay_ms(100);
		display_ausgabe("%d", getDistance(0));
		_delay_ms(500);
		befehl_schicken(CLEAR);
	};
}
