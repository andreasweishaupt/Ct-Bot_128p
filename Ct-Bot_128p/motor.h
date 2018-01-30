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


//initialize motor
void motor_init(void);

/* sets every motor to the given pwm-value
 * input: left_speed - pwm-value for left motor, range 0-255
 * input: right_speed - pwm-value for right motor, range 0-255 */
void setMotorSpeed(int left_speed, int right_speed);



#endif /* MOTOR_H_ */