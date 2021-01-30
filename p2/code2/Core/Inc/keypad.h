/*
 * keypad.h
 *
 *  Created on: Jan 30, 2021
 *      Author: 38164
 */

#ifndef CORE_INC_KEYPAD_H_
#define CORE_INC_KEYPAD_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "usart.h"
#include "gpio.h"
#include "timers.h"

#include "mcu_two.h"

#include <stdint.h>
#include <string.h>

extern void init_KeyPad();
extern void task_function_keypad(void* params);
extern void timer_function_keypad(TimerHandle_t handle);



#endif /* CORE_INC_KEYPAD_H_ */
