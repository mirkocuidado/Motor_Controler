/*
 * mcu_two.h
 *
 *  Created on: Jan 30, 2021
 *      Author: 38164
 */

#ifndef CORE_INC_MCU_TWO_H_
#define CORE_INC_MCU_TWO_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "usart.h"

#include <stdint.h>
#include <string.h>

typedef struct {
	uint8_t motor;
	uint8_t velocity;
} MotorCommand;

extern void init_MCU_two();
extern void task_receive_from_MCU_one(void* params);
extern MotorCommand receive_motor_command_from_MCU_one();

extern void add_to_queue_which_changes_the_speed_of_motors(uint8_t param);

extern void task_send_to_MCU_one(void* params);
extern void add_to_queue_to_send_to_MCU_one(uint8_t param);
#endif /* CORE_INC_MCU_TWO_H_ */
