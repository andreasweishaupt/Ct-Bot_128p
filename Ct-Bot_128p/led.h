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

#define LED_RIGHT		0x01		/*!< LED right in driving direction (LED1) */
#define LED_LEFT		0x02		/*!< LED left in driving direction (LED2) */
#define LED_RED			0x04		/*!< LED red (LED3) */
#define LED_ORANGE		0x08		/*!< LED orange (LED4) */
#define LED_YELLOW		0x10		/*!< LED yellow (LED5) */
#define LED_GREEN		0x20		/*!< LED green (LED6) */
#define LED_TURQUOISE	0x40		/*!< LED turqouise (LED7) */
#define LED_WHITE		0x80		/*!< LED white (LED8) */
#define LED_ALL			0xFF		/*!< all LED's */



/* Turns on a single LED */
void led_on(unsigned LED);

/* initialize all LEDs */
void led_init(void);

/* A 8-bit variable is shown by the LED's*/
void led_set(unsigned int LED);

/* Turns off a single LED */
void led_off(unsigned LED);



#endif /* LED_H_ */