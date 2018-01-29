/*
 * followline.c
 *
 * Created: 29.01.2018 11:33:59
 *  Author: Andreas
 */ 

#include "followline.h"

int fl_triggerR, fl_triggerL = 0;
int fl_speedR, fl_speedL, fl_speedT = 0;
int fl_divide = 20;

void followLine(){
	if(fl_speedR > 400) fl_speedR = 400;
	if(fl_speedL > 400) fl_speedL = 400;
		
	if (!(fl_triggerR || fl_triggerL)){
		if(adc_value[2] < 100){
			fl_triggerL = 1;
			fl_speedL += 100;
			fl_speedR -= 200;
		}
		if(adc_value[3] < 100){
			fl_triggerR = 1;
			fl_speedR += 100;
			fl_speedL -= 200;
		}
			
		if(fl_speedL != 0){
			
			for(int z = 0; z < 3; z++){
				if(fl_speedL == 0) break;
				if(fl_speedL < 0) {
					fl_speedL++;
					} else{
					fl_speedL--;
				}
			}
		}
		if(fl_speedR != 0){
			
			for(int z = 0; z < 3; z++){
				if(fl_speedR == 0) break;
				if(fl_speedR < 0) {
					fl_speedR++;
				} else{
					fl_speedR--;
				}
			}
		}
		setMotorSpeed(20+fl_speedL/fl_divide,20+fl_speedR/fl_divide);
	}
	else if(fl_triggerR && fl_triggerL){
		setMotorSpeed(0,0);
		if(adc_value[2] > 100){
			fl_triggerL = 0;
		}
		if(adc_value[3] > 100){
			fl_triggerR = 0;
		}
	}
	else if (fl_triggerL){
		if(adc_value[2] > 100){
			fl_triggerL = 0;
			fl_speedT = fl_speedL;
			fl_speedL = fl_speedR - 400;
			fl_speedR = fl_speedT + 100;
		}else{
			if(adc_value[3] < 100){
				fl_speedL += 1;
				//speedR -= 1;
			}
			fl_speedL += 1;
			//speedR -= 1;
			setMotorSpeed(10+fl_speedL/fl_divide, 10+fl_speedR/fl_divide);
		}
	}
	else if(fl_triggerR){
		if(adc_value[3] > 100){
			fl_triggerR = 0;
			fl_speedT = fl_speedR;
			fl_speedR = fl_speedL - 400;
			fl_speedL = fl_speedT + 100;
		}else{
			if(adc_value[2] < 100){
				fl_speedR += 1;
				//speedL -= 1;
			}
			
			//speedL -= 1;
			fl_speedR += 1;
			setMotorSpeed(10+fl_speedL/fl_divide, 10+fl_speedR/fl_divide);
		}
	}
}