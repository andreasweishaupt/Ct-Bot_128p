/*******************************************************************************
*
* File Name:   sensoren.c
* Project  :   c't Bot library
*
* Ver.     Date                 Author                    Comments
* -------  ----------   ---------------------   ------------------------------
* 2.00	   28.06.2006   Yang Li & Xingxing Hu   build
*                                               Initialisiere alle Sensore -> alle_sensoren_init(void);
*                                               geschwindigkeit-funktion -> speed_berechnung(void); 
*												positionsfunktion -> position_bestimmung(void);
*                                               berechnung der Entfernung -> speed_berechnung(void);
*                                               sensoren_isr(void) -> encoder_isr(void);
*                                               wert für encoder stetzen -> encoder_Set(int setl,int setr); 
*
*                                              
* 2006 Institut für Informatik, Tu-Clausthal
*****************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 ***************************************************************************/
 
#include "sensoren.h"



	
/* Interruptroutine für senoren (ohne radsensor)*/
void sensoren_isr(void){    
	   
	ena_ein(ENA_KANTLED|ENA_MAUS|ENA_SCHRANKE|ENA_KLAPPLED);
	ADCSRA |= (1 << ADSC);            //    A/D wandler einschalten
		
	//--------------------- klappesensor und transportfachsensor -----------------------
	Klappesensor_data[0] = ((PIND >> 6) & 0x01);
	Transportfachsensor_data[0] = ((PINB >> 0) & 0x01) & 0x01;			
		
	//--------------------- fehlerüberwachung -----------------
	SensError_data[0] = (PINB >> 2) & 0x01;
	tempoo = 0;
}

int getDistance(int sensor){
	int distance = 0;
	if (sensor = 0){
		for (int i = 0 ; i < 20 ; i++){
			distance += leftDistance[i];
		}
	}
	
	if (sensor = 1){
		for (int i = 0 ; i < 20 ; i++){
			distance += rightDistance[i];
		}
	}	
	return distance/20;
}

void encoder_isr(void)
{    unsigned int enc_l=0,enc_r=0;

	// --------------------- links ----------------------------
	//Rad-Encoder auswerten
	if ( ((PINB >> 4) & 0x01) != enc_l)				// uns interesieren nur Veraenderungen
	{
		//tempoo++;
		enc_l=((PINB >> 4) & 0x01);					// neuen wert sichern
		
		if (sl==1)	// Drehrichtung beachten
		sensEnc_data[0]++;	//vorwaerts
		if (sl==0)
		sensEnc_data[0]--;	//rueckwaerts
		if (sl==2)
		sensEnc_data[0]=sensEnc_data[0];	//stop
		
	}

	
	
	// --------------------- rechts ----------------------------
	if (((PIND >> 3) & 0x01) != enc_r)					// uns interesieren nur Veraenderungen
	{
		enc_r=((PIND >> 3) & 0x01);					// neuen wert sichern
		
		if (sr==1)									// Drehrichtung beachten
		sensEnc_data[1]++;							//vorwaerts
		if (sr==0)
		sensEnc_data[1]--;							//rueckwaerts
		if (sr==2)
		sensEnc_data[1]=sensEnc_data[1];	//stop
	}
}
	
int getAdcSensorValue(int sensor){
	
	switch(sensor) {
		case 0: 
			return getDistance(0);
		break;
		case 1: return getDistance(1); 
		break;
		case 2: return getDistance(2); 
		break;
		case 3: return adc_value[3];
		break;
		case 4: return adc_value[4];
		break;
		case 5: return adc_value[5];
		break;
		case 6: return adc_value[6];
		break;
		case 7: return adc_value[7];
		break;
		default:
		break;
	}
}

	