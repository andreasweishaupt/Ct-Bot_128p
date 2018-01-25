/*******************************************************************************
*
* File Name:   adc.c
* Project  :   c't Bot library
*
*
* Ver.     Date                 Author                    Comments
* -------  ----------   ---------------------   ------------------------------
* 2.00	   28.06.2006   Yang Li & Xingxing Hu   build
*                                               adc_Initialisieren -> adc_init(); 
*												                                              
* Copyright (c) 2006 Institut für Informatik, Tu-Clausthal
*****************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 ***************************************************************************/
 
#include "adc.h"


// Initialisert den AD-Umsetzer mit Interrupt. 
void adc_init(){
    
    DDRA = 0x00;        // 8 Pins als input
    PORTA &= ~0xff;    //  alle input-pins aus
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0) | (1<<ADIF)|(1<<ADIE);    // prescale faktor= 128 ADC laeuft mit 16MHz/ 128 = 125kHz,ADC an
    
}
