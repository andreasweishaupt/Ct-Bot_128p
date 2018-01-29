/*
 * followline.c
 *
 * Created: 29.01.2018 11:33:59
 *  Author: Andreas
 */ 

#include "followline.h"
#include "motor.h"

//gehört hier nicht her
int adc_wert[8];

void followLine(){
	if(fl_speedR > 400) fl_speedR = 400;
	if(fl_speedL > 400) fl_speedL = 400;
		
	if (!(fl_triggerR || fl_triggerL)){
		if(adc_wert[2] < 100){
			fl_triggerL = 1;
			fl_speedL += 100;
			fl_speedR -= 100;
		}
		if(adc_wert[3] < 100){
			fl_triggerR = 1;
			fl_speedR += 100;
			fl_speedL -= 100;
		}
			
		if(fl_speedL != 0){
			
			for(int z = 0; z < 5; z++){
				if(fl_speedL == 0) break;
				if(fl_speedL < 0) {
					fl_speedL++;
					} else{
					fl_speedL--;
				}
			}
		}
		if(fl_speedR != 0){
			
			for(int z = 0; z < 5; z++){
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
		if(adc_wert[2] > 100){
			fl_triggerL = 0;
			fl_speedL += 200;
		}
		if(adc_wert[3] > 100){
			fl_triggerR = 0;
			fl_speedR += 200;
		}
	}
	else if (fl_triggerL){
		if(adc_wert[2] > 100){
			fl_triggerL = 0;
			speedT = fl_speedL;
			fl_speedL = fl_speedR - 250;
			fl_speedR = speedT + 450;
		}else{
			if(adc_wert[3] < 100){
				fl_speedL += 1;
				//speedR -= 1;
			}
			fl_speedL += 1;
			//speedR -= 1;
			setMotorSpeed(10+fl_speedL/fl_divide, 10+fl_speedR/fl_divide);
		}
	}
	else if(fl_triggerR){
		if(adc_wert[3] > 100){
			fl_triggerR = 0;
			speedT = fl_speedR;
			fl_speedR = fl_speedL - 250;
			fl_speedL = speedT + 450;
		}else{
			if(adc_wert[2] < 100){
				fl_speedR += 1;
				//speedL -= 1;
			}
			
			//speedL -= 1;
			fl_speedR += 1;
			setMotorSpeed(10+fl_speedL/fl_divide, 10+fl_speedR/fl_divide);
		}
	}
}