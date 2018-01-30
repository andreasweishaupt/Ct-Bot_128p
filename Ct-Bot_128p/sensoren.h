/*******************************************************************************
*
* File Name:   sensoren.h
* Project  :   c't Bot library
*
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
* 2006 Institut für Informatik, Tu-Clausthal
*****************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 ***************************************************************************/
 
#ifndef SENSOREN_H_
#define SENSOREN_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "adc.h" 
#include "ena.h"
#include "motor.h"
#include "interrupt.h"

#define SENS_DISTANCE_LEFT	0
#define SENS_DISTANCE_RIGHT	1
#define SENS_LINE_LEFT		2
#define SENS_LINE_RIGHT		3
#define SENS_LIGHT_LEFT		4
#define SENS_LIGHT_RIGHT	5
#define SENS_CLIFF_LEFT		6
#define SENS_CLIFF_RIGHT	7

volatile int Abstandsensor_data[2];
volatile int Speed_r;		                        /* Abrollgeschwindigkeit des linken Rades in [mm/s] [-128 bis 127] relaisitisch [-50 bis 50] */
volatile int Speed_l;			                    /* Abrollgeschwindigkeit des linken Rades in [mm/s] [-128 bis 127] relaisitisch [-50 bis 50] */
volatile int Lichtsensor_data[2];		                /* Lichtsensor */
volatile int Abstand_data[2];		                /* Distanz linker IR-Sensor in [mm], wenn korrekt umgerechnet wird */         
volatile int Kantensensor_data[2];	                    /* Abgrundsensor  */
volatile int Lininensensor_data[2];	                /* Lininensensor */
volatile unsigned int Transportfachsensor_data[1];		/* Sensor Ueberwachung Transportfach */
volatile unsigned int Klappesensor_data[1];		        /* Sensor Ueberwachung Klappe */
volatile unsigned int SensError_data[1];		        /* Ueberwachung Motor oder Batteriefehler */
volatile long int Maus_data[2];		            /* Maussensor Delta X, positive Werte zeigen querab der Fahrtrichtung nach rechts *//* Maussensor Delta Y, positive Werte zeigen in Fahrtrichtung */		            
volatile long int Maus_X;		                        /* Mausposition X, positive Werte zeigen querab der Fahrtrichtung nach rechts */
volatile long int Maus_Y;		                        /* Mausposition Y, positive Werte zeigen in Fahrtrichtung  */	                  
volatile long int sensEnc_data[2];                 /* Encoder der Motor */


int tempoo;

int distanceLeft[20];
	
/* Initialisiere alle Sensore */
void alle_sensoren_init(void);

/* geschwindigkeit-funktion*/
void speed_berechnung(void);

/* positionsfunktion*/
void position_bestimmung(void);


/* berechnung der Entfernung:D = a/(x-b)
 * D ist die Entfernung,X ist der Ausgabewert des Sensors
 * A ist die Steigung der Kurve A/X
 * B ist der Offset der Kurve
 */
int adcToDistance(int ausgabewert);

int getDistance();

/* Interruptroutine für senoren (ohne radsensor)*/
void sensoren_isr(void);

/* Interruptroutine für radsensor */
void encoder_isr(void);

/* returns last measured value of given sensor
 * input: sensor_typ - number of the sensor
 *	possible options:
 *	SENS_DISTANCE_LEFT
 *	SENS_DISTANCE_RIGHT
 *	SENS_LINE_LEFT
 *	SENS_LINE_RIGHT
 *	SENS_LIGHT_LEFT
 *	SENS_LIGHT_RIGHT
 *	SENS_CLIFF_LEFT
 *	SENS_CLIFF_RIGHT
 * return: measured value
 */
int getAdcSensorValue(int sensor_typ);

void encoder_Set(int setl,int setr);

#endif
