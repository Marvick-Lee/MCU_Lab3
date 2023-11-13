/*
 * traffic.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Le HUy
 */

#include "global.h"
void initLED(){
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R2_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y2_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G2_Pin, RESET);
}
void onR1(){
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
}
void onY1(){
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
}
void onG1(){
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
}
void onR2(){
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, SET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
}
void onY2(){
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, SET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
}
void onG2(){
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
}
