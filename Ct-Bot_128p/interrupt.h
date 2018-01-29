/*
 * interrupt.h
 *
 * Created: 29.01.2018 12:17:02
 *  Author: JohnI
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "initall.h"

int adc_value[8],channel; //0:abstand links; 1:abstand rechts; 2:links linie; 3:linie rechts; 4:licht links; 5:licht rechts; 6:kantelinks; 7:kante rechts;

void initInterrupt(void);

int leftDistance[20];
int rightDistance[20];

#endif /* INTERRUPT_H_ */