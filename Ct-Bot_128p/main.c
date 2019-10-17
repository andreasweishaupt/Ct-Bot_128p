/*
 * Ct-Bot_128p.c
 *
 * Created: 19.01.2018 11:20:50
 * Author : Andreas,Michael
 */ 


#include "InitAll.h"
#include "followline.h"
#include "interrupt.h"
#include <avr/delay.h>
#include "stay_on_table.h"
#include "motor.h"

int main(void)
{
	
	intAllPeripherals();
	//init_photocoupler(400);

    while (1){
		/*
		display_write( "%4d ", getAdcSensorValue(4));
		display_write("          ");
		display_write( "%4d ", getAdcSensorValue(5));
		_delay_ms(500);
		send_command(CLEAR);
		*/
		//test_photocoupler();
		//move_cliff_detection();
		followLine();
    }
}
