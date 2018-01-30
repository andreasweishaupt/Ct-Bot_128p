/*
 * Ct-Bot_128p.c
 *
 * Created: 19.01.2018 11:20:50
 * Author : Andreas,Michael
 */ 


#include "InitAll.h"
#include "followline.h"
#include "interrupt.h"


int main(void)
{
	
	intAllPeripherals();	
	//display_ausgabe("Hallo");

    while (1){
		
		display_ausgabe( "%4d ", getAdcSensorValue(0));
		display_ausgabe( "%4d ", adcToDistance(getAdcSensorValue(0)));
		display_ausgabe("          ");
		display_ausgabe( "%4d ", getAdcSensorValue(1));
		display_ausgabe( "%4d ", adcToDistance(getAdcSensorValue(1)));
		_delay_ms(500);
		befehl_schicken(CLEAR);
    }

}
