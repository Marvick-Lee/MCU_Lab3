/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Le HUy
 */

#include "fsm_automatic.h"

//Normal mode
//Predefine time
int RT = 5;
int YT = 2;
int GT = 3;

void fsm_automatic_run(){
	switch (status){
		case INIT:
			//TODO
			initLED();
			led_index = 0;
			CT1 = 0;
			CT2 = 0;
			CT3 = 0;
			CT4 = 0;
			status = R1_G2;
			setTimer1(1000*GT);
			setTimer2(10);
			setTimer3(10);
			break;

		case INIT_AUTO:
			status = R1_G2;
			setTimer1(1000 * GT);
			setTimer2(10);
			setTimer3(10);
			break;
		case R1_G2:
			//TODO
			onR1(); onG2();
			if (timer1_flag == 1){
				status = R1_Y2;
				setTimer1(1000*YT);
			}
			if(timer2_flag == 1){
				update7SEG(led_index++);
				if (led_index > 3) led_index = 0;
				setTimer2(100);
			}
			if(timer3_flag == 1){
				updateBufferNormal(status);
				setTimer3(1000);
			}

			if (isButton1Pressed() == 1) status = INIT_MAN_RED;
			break;

		case R1_Y2:
			//TODO
			onR1(); onY2();
			if (timer1_flag == 1){
				status = G1_R2;
				setTimer1(1000*GT);
			}
			if(timer2_flag == 1){
				update7SEG(led_index++);
				if (led_index > 3) led_index = 0;
				setTimer2(100);
			}
			if(timer3_flag == 1){
				updateBufferNormal(status);
				setTimer3(1000);
			}
			if (isButton1Pressed() == 1) status = INIT_MAN_RED;
			break;

		case G1_R2:
			//TODO
			onG1(); onR2();
			if (timer1_flag == 1){
				status = Y1_R2;
				setTimer1(1000*YT);
			}
			if(timer2_flag == 1){
				update7SEG(led_index++);
				if (led_index > 3) led_index = 0;
				setTimer2(100);
			}
			if(timer3_flag == 1){
				updateBufferNormal(status);
				setTimer3(1000);
			}
			if (isButton1Pressed() == 1) status = INIT_MAN_RED;
			break;

		case Y1_R2:
			//TODO
			onY1(); onR2();
			if (timer1_flag == 1){
				status = R1_G2;
				setTimer1(1000*GT);
			}
			if(timer2_flag == 1){
				update7SEG(led_index++);
				if (led_index > 3) led_index = 0;
				setTimer2(100);
			}
			if(timer3_flag == 1){
				updateBufferNormal(status);
				setTimer3(1000);
			}
			if (isButton1Pressed() == 1) status = INIT_MAN_RED;
			break;

		default:
			break;
	}
}
