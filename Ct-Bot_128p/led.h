/*
 * led.h
 *
 * Created: 19.01.2018 12:40:57
 *  Author: Andreas
 */ 


#ifndef LED_H_
#define LED_H_

#include <avr/io.h>
#include "shift.h"

#define LED_RECHTS	0x01		/*!< LED in Fahrichtung rechts*/
#define LED_LINKS	0x02		/*!< LED in Fahrichtung links*/
#define LED_ROT     0x04		/*!< LED Rot */
#define LED_ORANGE  0x08		/*!< LED Orange */
#define LED_GELB    0x10		/*!< LED Gelb */
#define LED_GRUEN   0x20		/*!< LED Gruen */
#define LED_TUERKIS 0x40		/*!< LED Tuerkis */
#define LED_WEISS   0x80		/*!< LED Weiss */
#define LED_ALL     0xFF		/*!< LED Alle */



/* Schaltet eine LED an */
void led_ein(unsigned LED);

/* Initialisiert die LEDs */
void led_init(void);

/* Zeigt eine 8-Bit Variable mit den LEDs an */
void led_set(unsigned int LED);

/* Schaltet eine LED aus */
void led_aus(unsigned LED);



#endif /* LED_H_ */