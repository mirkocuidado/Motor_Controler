/*
 * work.h
 *
 *  Created on: Jan 30, 2021
 *      Author: 38164
 */

#ifndef CORE_INC_WORK_H_
#define CORE_INC_WORK_H_

#include "mcu_two.h"
#include "lcd.h"
#include "keypad.h"

#include "tim.h"

extern void init_Work();
extern void work_task_function(void* params);

#endif /* CORE_INC_WORK_H_ */
