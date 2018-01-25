/*
 * shift.h
 *
 * Created: 19.01.2018 12:10:33
 *  Author: Andreas
 */ 


#ifndef SHIFT_H_
#define SHIFT_H_

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>

#define SCHIEBEREGISTER_DISPLAY	0x04  /* Port-Pin fuer SCHIEBEREGISTER_DISPLAY */
#define SCHIEBEREGISTER_LED	0x10	  /* Port-Pin fuer SCHIEBEREGISTER_DISPLAY */
#define SCHIEBEREGISTER_ENA	0x08	  /* Port-Pin fuer SCHIEBEREGISTER_DISPLAY */


/* Initialisert die Shift-Register*/
void schieberegister_init(void);

/* Schiebt Daten durch eines der drei 74HC595-Schieberegister und den Port danach noch zurücksetzen*/
void schieberegister_data_schicken(unsigned char data, unsigned char data_send, unsigned char data_schieben);



#endif /* SHIFT_H_ */