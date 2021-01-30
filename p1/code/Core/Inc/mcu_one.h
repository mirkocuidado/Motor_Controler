/*
 * mcu_one.h
 *
 *  Created on: Jan 30, 2021
 *      Author: 38164
 */

#ifndef CORE_INC_MCU_ONE_H_
#define CORE_INC_MCU_ONE_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "usart.h"

#include <stdint.h>
#include <string.h>

extern void init_MCU_one();
extern void task_function_send_to_terminal(void* params);
extern void task_function_receive_from_terminal(void* params);
extern void send_string_to_terminal(char* string_to_send);
extern char* receive_string_from_terminal();

typedef struct {
	uint8_t motor;
	uint8_t velocity;
} MotorCommand;

extern void task_function_send_to_MCU_two(void* params);
extern void send_motor_command_to_MCU_two(MotorCommand m);

extern void send_integer_to_terminal(uint8_t number);

extern uint8_t velocities[2];

extern void task_function_receive_from_MCU_two(void* params);
extern void modify_velocities(MotorCommand m);

#endif /* CORE_INC_MCU_ONE_H_ */