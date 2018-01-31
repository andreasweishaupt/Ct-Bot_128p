/*
 * stay_on_table.h
 *
 * Created: 29.01.2018 16:37:21
 *  Author: David
 */ 
#include <stdbool.h>
#include "sensoren.h"
#include "interrupt.h"

#ifndef STAY_ON_TABLE_H_
#define STAY_ON_TABLE_H_

int m_threshold;

/* initialize the photocoupler
 * input: treshold - all measured values above treshold will be detected as chasm */
void init_photocoupler(int threshold);

/* detects cliffs by measuring the front photocouplers
 * !!! note: init_photocoupler() has to be called before using this method
 * return: bool - true if an chasm is detected, false if no chasm is detected */
bool cliff_detection();

// shows the actual measured value of the photocouplers on the lcd
void test_photocoupler();

/* moves in straight direction, if detecting a cliff -> turns and moves back
 * !!! note: init_photocoupler() has to be called before using this method */
void move_cliff_detection();

#endif /* STAY_ON_TABLE_H_ */