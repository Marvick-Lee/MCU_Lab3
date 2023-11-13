/*
 * updateSEG.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Le HUy
 */

#ifndef INC_UPDATESEG_H_
#define INC_UPDATESEG_H_

#include "global.h"

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

extern int led_index;
extern int CT1;
extern int CT2;
extern int CT3;
extern int CT4;

void display7SEG(int num);
void update7SEG(int index);

void updateBufferNormal(int status);
void updateBufferMANRED();
void updateBufferMANYLW();
void updateBufferMANGRN();

#endif /* INC_UPDATESEG_H_ */
