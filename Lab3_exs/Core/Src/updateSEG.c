/*
 * updateSEG.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Le HUy
 */

#include "global.h"
int led_index = 0;
int CT1 = 0;
int CT2 = 0;
int CT3 = 0;
int CT4 = 0;

const int NumCases[]={
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111,
		0b01100110,
		0b01101101,
		0b01111101,
		0b00000111,
		0b01111111,
		0b01101111
};

void display7SEG(int num){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_All, SET);
	HAL_GPIO_WritePin(GPIOB, NumCases[num], RESET);
}

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
void update7SEG(int index){
    switch (index){
        case 0:
            //Display the first 7SEG with led_buffer[0]
        	display7SEG(led_buffer[0]);
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
            break;
        case 1:
			//Display the second 7SEG with led_buffer[1]
        	display7SEG(led_buffer[1]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
            break;
        case 2:
			//Display the third 7SEG with led_buffer[2]
        	display7SEG(led_buffer[2]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
            break;
        case 3:
            //Display the forth 7SEG with led_buffer[3]
        	display7SEG(led_buffer[3]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
            break;
        default:
            break;
    }
}

void updateBufferNormal(int status){
	switch(status){
	case R1_G2:
		led_buffer[0] = (RT - CT1)/10;
		led_buffer[1] = (RT - CT1)%10;
		led_buffer[2] = (GT - CT1)/10;
		led_buffer[3] = (GT - CT1)%10;
		CT1++;
		break;

	case R1_Y2:
		led_buffer[0] = (RT - CT1)/10;
		led_buffer[1] = (RT - CT1)%10;
		led_buffer[2] = (YT - CT2)/10;
		led_buffer[3] = (YT - CT2)%10;
		CT1++; CT2 ++;
		break;

	case G1_R2:
		led_buffer[0] = (GT - CT3)/10;
		led_buffer[1] = (GT - CT3)%10;
		led_buffer[2] = (RT - CT3)/10;
		led_buffer[3] = (RT - CT3)%10;
		CT3 ++;
		break;

	case Y1_R2:
		led_buffer[0] = (YT - CT4)/10;
		led_buffer[1] = (YT - CT4)%10;
		led_buffer[2] = (RT - CT3)/10;
		led_buffer[3] = (RT - CT3)%10;
		CT3 ++; CT4 ++;

		if (led_buffer[1] <= 1) {
			CT1 = 0; CT2 = 0; CT3 = 0; CT4 = 0;
		}
		break;
	default:
		break;
	}
}

void updateBufferMANRED(){
	led_buffer[0] = 2;
	led_buffer[1] = 2;
	led_buffer[2] = RT /10;
	led_buffer[3] = RT % 10;
}

void updateBufferMANYLW(){
	led_buffer[0] = 3;
	led_buffer[1] = 3;
	led_buffer[2] = YT / 10;
	led_buffer[3] = YT % 10;
}

void updateBufferMANGRN(){
	led_buffer[0] = 4;
	led_buffer[1] = 4;
	led_buffer[2] = GT / 10;
	led_buffer[3] = GT % 10;
}
