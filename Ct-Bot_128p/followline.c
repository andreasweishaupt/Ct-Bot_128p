/*
 * followline.c
 *
 * Created: 29.01.2018 11:33:59
 *  Author: Andreas
 */ 


if(speedR > 400) speedR = 400;
		if(speedL > 400) speedL = 400;
		
		if (!(triggerR || triggerL)){
			if(adc_wert[2] < 100) triggerL = 1;
			if(adc_wert[3] < 100) triggerR = 1;
			
			if(speedL != 0){
				/*
				if(speedL < 0){ speedL += 4;}
				if(speedL < 0){ speedL += 2;}
				if(speedL < 0){ speedL += 1;}
				if(speedL > 0){ speedL -= 4;}
				if(speedL > 0){ speedL -= 2;}
				if(speedL > 0){ speedL -= 1;}
				*/
				for(int z = 0; z < 5; z++){
					if(speedL == 0) break;
					if(speedL < 0) {
						speedL++;
						} else{
						speedL--;
					}
				}
			}
			if(speedR != 0){
				/*
				if(speedR < 0){ speedR += 4;}
				if(speedR < 0){ speedR += 2;}
				if(speedR < 0){ speedR += 1;}
				if(speedR > 0){ speedR -= 4;}
				if(speedR > 0){ speedR -= 2;}
				if(speedR > 0){ speedR -= 1;}
				*/
				for(int z = 0; z < 5; z++){
					if(speedR == 0) break;
					if(speedR < 0) {
						speedR++;
					} else{
						speedR--;
					}
				}
			}
			setMotorSpeed(20+speedL/teiler,20+speedR/teiler);
		}
		else if(triggerR && triggerL){
			setMotorSpeed(0,0);
			if(adc_wert[2] > 100){
				triggerL = 0;
				speedL += 200;
			}
			if(adc_wert[3] > 100){
				triggerR = 0;
				speedR += 200;
			}
		}
		else if (triggerL){
			if(adc_wert[2] > 100){
				triggerL = 0;
				speedT = speedL;
				speedL = speedR - 250;
				speedR = speedT + 450;
			}else{
				if(adc_wert[3] < 100){
					speedL += 1;
					//speedR -= 1;
				}
				 if(adc_wert[6] > 400){
					speedL += 100;
					speedR -= 100;
					//setMotorSpeed(-50,50);
					//_delay_ms(1);
				}
				speedL += 1;
				//speedR -= 1;
				setMotorSpeed(10+speedL/teiler, 10+speedR/teiler);
			}
		}
		else if(triggerR){
			if(adc_wert[3] > 100){
				triggerR = 0;
				speedT = speedR;
				speedR = speedL - 250;
				speedL = speedT + 450;
			}else{
				if(adc_wert[2] < 100){
					speedR += 1;
					//speedL -= 1;
				}
				if(adc_wert[7] > 400){
					speedR += 100;
					speedL -= 100;
					//setMotorSpeed(-50,50);
					//_delay_ms(1);
				}
				//speedL -= 1;
				speedR += 1;
				setMotorSpeed(10+speedL/teiler, 10+speedR/teiler);
			}
		}