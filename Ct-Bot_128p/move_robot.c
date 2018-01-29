/*
 * move_robot.c
 *
 * Created: 29.01.2018 13:25:28
 *  Author: David
 */ 
#include "move_robot.h"
#include "motor.h"
#include "display.h"

//drives with Speed speed in Direction direction
void move(int speed, int direction)
{
	int right_speed = (speed % 1000);
	right_speed = right_speed %100;
	int left_speed = (speed - right_speed)/100;
	cursor_position(1,1);
	display_ausgabe("%d", left_speed);
	cursor_position(1,8);
	display_ausgabe("%d", right_speed);
	cursor_position(3,1);
	display_ausgabe("%d", speed);
	setMotorSpeed(direction * left_speed, direction * right_speed);
}