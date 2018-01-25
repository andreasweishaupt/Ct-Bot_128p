/*******************************************************************************
*
* File Name:   ena.c
* Project  :   c't Bot library
*
*
* Ver.     Date                 Author                    Comments
* -------  ----------   ---------------------   ------------------------------
* 2.00	   28.06.2006   Yang Li & Xingxing Hu   build
*                                               Initialisiert die Enable-Leitungen -> ena_init();
*                                               Schaltet einzelne Enable-Leitungen an,andere werden nicht beeinflusst -> ena_ein(unsigned int ena_pin);
*                                               Schaltet einzelne Enable-Leitungen aus,andere werden nicht beeinflusst -> ena_aus(unsigned int ena_pin);
*                                               Schaltet die Enable-Leitungen -> ena_set(unsigned int ena_pin);
*												                                              
* Copyright (c) 2006 Institut für Informatik, Tu-Clausthal
*****************************************************************************/
/***************************************************************************
*
*the ena source is based on ena.c ver 1.0 by Benjamin Benz 20.12.05 
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
 
#include "ena.h"

volatile int enable=0;	/*Sichert den Zustand der Enable-Leitungen */

/* Initialisiert die Enable-Leitungen */
void ena_init(){
	schieberegister_init();
	ena_set(0x00);
}

/* Schaltet einzelne Enable-Leitungen an,andere werden nicht beeinflusst*/
void ena_ein(unsigned int ena_pin){

	enable |= ena_pin;
	ena_set(enable);
}

/* Schaltet einzelne Enable-Leitungen aus,andere werden nicht beeinflusst*/
void ena_aus(unsigned int ena_pin){
	enable &= ~ena_pin;
	ena_set(enable);
}

/* Schaltet die Enable-Leitungen*/
void ena_set(unsigned int ena_pin){
	enable=ena_pin;
	schieberegister_data_schicken(~ena_pin,SCHIEBEREGISTER_ENA,(1<<1)); 
}


