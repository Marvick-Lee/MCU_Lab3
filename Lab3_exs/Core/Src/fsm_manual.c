/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Le HUy
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch (status){
		case INIT_MAN_RED:
			//TODO
			// init
			led_index = 0;
			onR1();
			onR2();
			updateBufferMANRED();
			update7SEG(led_index);
			setTimer1(10);
			setTimer2(10);
			setTimer3(500); // 2Hz
			setTimer4(500);
			setTimer5(10);

			status = MAN_RED;
			break;

		case MAN_RED:
			//TODO
			if (timer3_flag == 1){ // update Mode
				updateBufferMANRED();
				setTimer3(500);
			}
			if (timer4_flag == 1){ //blinking
				HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
				HAL_GPIO_TogglePin(R2_GPIO_Port, R2_Pin);
				setTimer4(500);
			}
			if(timer5_flag == 1){ // buffer 4SEG
				update7SEG(led_index++);
				if (led_index > 3) led_index = 0;
				setTimer5(100);
			}

			if (isButton1Pressed() == 1) status = INIT_MAN_YLW;
			if (isButton2Pressed() == 1){
				if (RT >= 99) RT = GT + 1; else RT++;
				status = MAN_RED;
			}
			if (isButton3Pressed() == 1){
				YT = RT - YT;
				status = R1_G2;
			}
			break;

		case INIT_MAN_YLW:
			//TODO
			// init
			led_index = 0;
			onY1();
			onY2();
			updateBufferMANYLW();
			update7SEG(led_index);
			setTimer1(10);
			setTimer2(10);
			setTimer3(500); // 2Hz
			setTimer4(500);
			setTimer5(10);

			status = MAN_YLW;
			break;

		case MAN_YLW:
			//TODO
			if (timer3_flag == 1){ // update Mode
				updateBufferMANYLW();
				setTimer3(500);
			}
			if (timer4_flag == 1){ //blinking
				HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
				HAL_GPIO_TogglePin(Y2_GPIO_Port, Y2_Pin);
				setTimer4(500);
			}
			if(timer5_flag == 1){ // buffer 4SEG
				update7SEG(led_index++);
				if (led_index > 3) led_index = 0;
				setTimer5(100);
			}

			if (isButton1Pressed() == 1) status = INIT_MAN_GRN;
			if (isButton2Pressed() == 1){
				status = MAN_YLW;
				if (YT < RT) YT++;
			}
			if (isButton3Pressed() == 1){
				GT = RT - YT;
				status = R1_G2;
			}
			break;

		case INIT_MAN_GRN:
			//TODO
			// init
			led_index = 0;
			onG1();
			onG2();
			updateBufferMANGRN();
			update7SEG(led_index);
			setTimer1(10);
			setTimer2(10);
			setTimer3(500); // 2Hz
			setTimer4(500);
			setTimer5(10);

			status = MAN_GRN;
			break;

		case MAN_GRN:
			//TODO
			if (timer3_flag == 1){ // update Mode
				updateBufferMANGRN();
				setTimer3(500);
			}
			if (timer4_flag == 1){ //blinking
				HAL_GPIO_TogglePin(G1_GPIO_Port, G1_Pin);
				HAL_GPIO_TogglePin(G2_GPIO_Port, G2_Pin);
				setTimer4(500);
			}
			if(timer5_flag == 1){ // buffer 4SEG
				update7SEG(led_index++);
				if (led_index > 3) led_index = 0;
				setTimer5(100);
			}

			if (isButton1Pressed() == 1) status = INIT_MAN_RED;
			if (isButton2Pressed() == 1){
				if (GT < RT) GT++;
				status = MAN_GRN;
			}
			if (isButton3Pressed() == 1){
				YT = RT - GT;
				status = R1_G2;
			}
			break;

		default:
			break;
	}
}
