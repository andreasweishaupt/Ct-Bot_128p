/*
 * stay_on_table.c
 *
 * Created: 29.01.2018 16:36:55
 *  Author: David
 */ 
#include "stay_on_table.h"
#include "display.h"

void init_photocoupler(int treshold)
{
	m_treshold = treshold;
}

bool cliff_detection()
{
	if(adc_value[6] > m_treshold || adc_value[7] > m_treshold)
	{
		return true;
	}
	return false;
}

void test_photocoupler()
{
	send_command(CLEAR);
	cursor_position(1,1);
	display_write("Left:");
	display_write("%d", adc_value[6]);
	cursor_position(2,1);
	display_write("Right:");
	display_write("%d", adc_value[7]);
	cursor_position(3,1);
	if (cliff_detection())
	{
		display_write("Cliff detected");
	}
	else
	{
		display_write("Cliff not detected");
	}
	_delay_ms(1000);
}

void move_cliff_detection()
{
	if (cliff_detection())
	{
		setMotorSpeed(-200,-200);
		_delay_ms(400);
		setMotorSpeed(0,0);
		_delay_ms(100);
		setMotorSpeed(255,-255);
		_delay_ms(700);
		setMotorSpeed(0,0);
	}
	else
	{
		setMotorSpeed(200,200);
		_delay_us(1);
		setMotorSpeed(0,0);
		_delay_us(10);
	}
}
