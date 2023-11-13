/*
 * button.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Le HUy
 */

#include "button.h"
#include "main.h"
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;
int KeyReg12 = NORMAL_STATE;
int KeyReg13 = NORMAL_STATE; // trạng thái ổn định trước đó
int TimerForKeyPress1 = 200;

int KeyReg20 = NORMAL_STATE;
int KeyReg21 = NORMAL_STATE;
int KeyReg22 = NORMAL_STATE;
int KeyReg23 = NORMAL_STATE;
int TimerForKeyPress2 = 200;

int KeyReg30 = NORMAL_STATE;
int KeyReg31 = NORMAL_STATE;
int KeyReg32 = NORMAL_STATE;
int KeyReg33 = NORMAL_STATE;
int TimerForKeyPress3 = 200;

int isButton1Pressed(){
	if (button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if (button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if (button3_flag == 1) {
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess1(){
	button1_flag = 1;
}

void subKeyProcess2(){
	button2_flag = 1;
}

void subKeyProcess3(){
	button3_flag = 1;
}

void getKeyInput1(){
	KeyReg10 = KeyReg11;
	KeyReg11 = KeyReg12;
	KeyReg12 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
	if ((KeyReg10 == KeyReg11) && (KeyReg11 == KeyReg12)){
		if(KeyReg13 != KeyReg12){ // nhấn thả
			KeyReg13 = KeyReg12;
			if (KeyReg12 == PRESSED_STATE){
				//TODO
				subKeyProcess1();
				TimerForKeyPress1 = 200;
			}
		} else{ //nhấn đè
			TimerForKeyPress1--;
			if (TimerForKeyPress1 == 0){
				//TODO
				KeyReg13 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInput2(){
	KeyReg20 = KeyReg21;
	KeyReg21 = KeyReg22;
	KeyReg22 = HAL_GPIO_ReadPin(button2_GPIO_Port,button2_Pin);
	if ( (KeyReg20 == KeyReg21) && (KeyReg21 == KeyReg22) ){
		if(KeyReg23 != KeyReg22){
			KeyReg23 = KeyReg22;
			if (KeyReg22 == PRESSED_STATE){
				//TODO
				subKeyProcess2();
				TimerForKeyPress2 = 200;
			}
		} else{
			TimerForKeyPress2--;
			if (TimerForKeyPress2 == 0){
				//TODO
				KeyReg23 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInput3(){
	KeyReg30 = KeyReg31;
	KeyReg31 = KeyReg32;
	KeyReg32 = HAL_GPIO_ReadPin(button3_GPIO_Port,button3_Pin);
	if ( (KeyReg30 == KeyReg31) && (KeyReg31 == KeyReg32) ){
		if(KeyReg33 != KeyReg32){
			KeyReg33 = KeyReg32;
			if (KeyReg32 == PRESSED_STATE){
				//TODO
				subKeyProcess3();
				TimerForKeyPress2 = 200;
			}
		} else{
			TimerForKeyPress3--;
			if (TimerForKeyPress3 == 0) {
				//TODO
				KeyReg33 = NORMAL_STATE;
			}
		}
	}
}

void buttonRun(){
	getKeyInput1();
	getKeyInput2();
	getKeyInput3();
}

