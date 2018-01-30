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

#define CLEAR 0x01							/* clear/delete display */
#define DISPLAY_CURSORHOME 0x02             /* set cursor to homeposition */
#define ZEILE_LANGE	20	                    /* lenght of the display-line */
#define PUFFER_GROESSE	(ZEILE_LANGE + 1)	/* size of the display-puffer per line */

/* initialize display */
void display_init(void);

/* writes single bytes of data */
void write_data(char data);

/* sets the cursorposition to given values
 * input: row - row to set the cursor, allowed values 1-4
 * input: column - column to set the cursor, allowed values 1-20
*/
void cursor_position(int row, int column);

/* writes data to the lcd
 * if you want to write a sensorvalue (int/bool/etc...) to the display
 * use: "display_write( "%d", value);" */
void display_write(char *format, ...);

/* sends a command to the display
 * if you want to clear the display use: "send_command(CLEAR);"*/
void send_command(unsigned char command);



#endif /* DISPLAY_H_ */