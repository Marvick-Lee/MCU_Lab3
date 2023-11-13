/*
 * global.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Le HUy
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "traffic.h"
#include "updateSEG.h"
#include "main.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"

#define INIT 		0
#define R1_G2 		1
#define R1_Y2 		2
#define G1_R2 		3
#define Y1_R2		4

#define MAN_RED			12
#define INIT_MAN_RED 	120
#define MAN_RED_ADD		121
#define MAN_GRN			13
#define INIT_MAN_GRN	130
#define MAN_GRN_ADD		131
#define MAN_YLW			14
#define INIT_MAN_YLW	140
#define MAN_YLW_ADD		141

extern int status;

#endif /* INC_GLOBAL_H_ */
