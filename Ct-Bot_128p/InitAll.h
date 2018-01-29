/*
 * InitAll.h
 *
 * Created: 29.01.2018 12:05:28
 *  Author: JohnI
 */ 


#ifndef INITALL_H_
#define INITALL_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "motor.h"
#include "led.h"
#include "display.h"
#include "sensoren.h"
#include "adc.h"
#include "ena.h"
#include "interrupt.h"

void intAllPeripherals(void);

#endif /* INITALL_H_ */