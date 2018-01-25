/*
 * display.h
 *
 * Created: 19.01.2018 12:08:06
 *  Author: Andreas
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "shift.h"
//#include "wait.h"

#define CLEAR 0x01		                  /* Kommando zum Löschen */
#define DISPLAY_CURSORHOME 0x02                	  /* Kommando für den Cursor */
#define ZEILE_LANGE	20	                      /* Wieviele Zeichen passen in eine Zeile */
#define PUFFER_GROESSE	(ZEILE_LANGE + 1)  /* Puffergroesse fuer eine Zeile in bytes */

/* Init Display */
void display_init(void);

void write_data(char data);

/* Cursorposition*/
void cursor_position(int zeile, int spalte);

/* Schreibt einen String auf das Display.*/
void display_ausgabe(char *format, ...);

/*ein befehl an das Display senden*/
void befehl_schicken(unsigned char befehl);



#endif /* DISPLAY_H_ */