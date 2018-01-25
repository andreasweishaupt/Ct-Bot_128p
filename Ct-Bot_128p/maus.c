/*******************************************************************************
*
* File Name:   maus.c
* Project  :   c't Bot library
*
*
* Ver.     Date                 Author                    Comments
* -------  ----------   ---------------------   ------------------------------
* 2.00	   28.06.2006   Yang Li & Xingxing Hu   build
*                                                Überträgt ein Byte an den Sensor -> maus_writeByte(int data);
*                                               Liest ein Byte vom Sensor -> maus_readByte(void);
*                                               Überträgt ein write-Kommando an den Sensor -> maus_write(int adr, int data);
*                                               Schickt ein Lesekommando an den Sensor und liest ein Byte zurück -> maus_read(unsigned int adr);
*                                               maus init -> maus_init(void);
*                                               
*												                                              
* 2006 Institut für Informatik, Tu-Clausthal
*****************************************************************************/
/***************************************************************************
*
*the maus source is based on mouse.c ver 1.0 by Benjamin Benz 20.12.05 
*Copyright (c) 2005, 59 Temple Place, Suite 330, Boston,MA 02111-1307, USA.
*
****************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 ***************************************************************************/
 
#include "maus.h"
#include <util/delay.h>

/* Überträgt ein Byte an den Sensor */
void maus_writeByte(int data)
{
	int i;
	DDRB  |= (1<<6); 			// SDA auf Output
	
	for (i=7; i>=0; i--)
	{
		PORTB &= ~(1<<7);		// SCK auf Low, vorbereiten
		
		//Daten rausschreiben
		PORTB = (PORTB & (~PINB)) |  ((data >> 1) & (1<<6));	
		data = data <<1;				// nächstes Bit vorbereiten
		
		PORTB |= (1<<7);		// SCK =1 Sensor uebernimmt auf steigender Flanke
	}
}

/* Liest ein Byte vom Sensor */
int maus_readByte(void)
{
	int i;
	char data=0;

	DDRB  &= ~(1<<6); 		// SDA auf Input

	for (i=7; i>-1; i--)
	{
		PORTB &= ~(1<<7);		// SCK =0 Sensor bereitet Daten auf fallender Flanke vor !
		data=data<<1;					// Platz schaffen
		PORTB |= (1<<7);		// SCK =1 Daten lesen  auf steigender Flanke
		
		data |= (PINB >> 6) & 0x01;			//Daten lesen
	}
	return data;
}

/* Überträgt ein write-Kommando an den Sensor */
void maus_write(int adr, int data)
{
	int i;
	maus_writeByte(adr);
	maus_writeByte(data);
	for (i=0; i<75; i++)
	{
		asm("nop");						// mindestens 100 Mikrosekunden Pause!!!
	}	
}

/* Schickt ein Lesekommando an den Sensor und liest ein Byte zurück */
int maus_read(unsigned int adr)
{
	int i;
	maus_writeByte(adr);
	for (i=0; i<75; i++)
	{	
		asm("nop");						// mindestens 100 Mikrosekunden Pause!!!
	}
	return maus_readByte();
}

void maus_init(void)
{
	DDRB  |= (1<<7); 			// SCK auf Output
	PORTB &= ~(1<<7);	
	_delay_ms(100);		// SCK auf 0
	ena_ein(ENA_MAUS);
	maus_write(0x00,MOUSE_CFG_RESET);	//Reset sensor
	maus_write(0x00,MOUSE_CFG_FORCEAWAKE);	//Always on
}
