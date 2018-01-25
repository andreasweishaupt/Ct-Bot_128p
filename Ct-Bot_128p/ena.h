/*******************************************************************************
*
* File Name:   ena.h
* Project  :   c't Bot library
*
*
* Ver.     Date                 Author                    Comments
* -------  ----------   ---------------------   ------------------------------
* 2.00	   28.06.2006   Yang Li & Xingxing Hu   build
*                                               Initialisiert die Enable-Leitungen -> ena_init();
*                                               Schaltet einzelne Enable-Leitungen an,andere werden nicht beeinflusst -> ena_ein(unsigned int ena);
*                                               Schaltet einzelne Enable-Leitungen aus,andere werden nicht beeinflusst -> ena_aus(unsigned int ena);
*                                               Schaltet die Enable-Leitungen -> ena_set(unsigned int ena);
*												                                              
* 2006 Institut für Informatik, Tu-Clausthal
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
 
#ifndef ENA_H_
#define ENA_H_

#include <avr/io.h>
#include "shift.h"

#define ENA_ABSTAND	    (1<<0)		/* Enable-Leitung Abstandssensoren */
#define ENA_RADLED		(1<<1)		/* Enable-Leitung Radencoder */
#define ENA_SCHRANKE	(1<<2)		/* Enable-Leitung Fachueberwachung */
#define ENA_KANTLED	    (1<<3)		/* Enable-Leitung Angrundsensor */
#define ENA_KLAPPLED	(1<<4)		/* Enable-Leitung Schieberueberwachung */
#define ENA_MAUS		(1<<5)		/* Enable-Leitung Liniensensor auf Mausplatine */


/* Schaltet die Enable-Leitungen*/
void ena_set(unsigned int ena_pin);

/* Initialisiert die Enable-Leitungen */
void ena_init(void);

/* Schaltet einzelne Enable-Leitungen an,andere werden nicht beeinflusst*/
void ena_ein(unsigned int ena_pin);

/* Schaltet einzelne Enable-Leitungen aus,andere werden nicht beeinflusst*/
void ena_aus(unsigned int ena_pin);

#endif



