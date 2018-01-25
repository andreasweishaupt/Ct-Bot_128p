/*
 * motor.h
 *
 * Created: 19.01.2018 11:57:04
 *  Author: Andreas
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>

int sl,sr;


//Initialisiert die Motoren
void motor_init(void);

//Setzen Motor speed
void setMotorSpeed(int left_speed, int right_speed);



#endif /* MOTOR_H_ */