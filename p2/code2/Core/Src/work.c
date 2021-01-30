/*
 * work.c
 *
 *  Created on: Jan 30, 2021
 *      Author: 38164
 */

#include "work.h"

void init_Work() {
	init_MCU_two();
	init_LCD();
	init_KeyPad();
	xTaskCreate(work_task_function, "work_task_MCU2", 128, NULL, 6, NULL);
}

void work_task_function(void* params) {

	LCD_add_to_queue(LCD_INSTRUCTION, LCD_SET_CG_RAM_ADDRESS_INSTRUCTION | 0x08);

	LCD_add_to_queue(LCD_DATA, 0x1F);
	LCD_add_to_queue(LCD_DATA, 0x1F);
	LCD_add_to_queue(LCD_DATA, 0x1F);
	LCD_add_to_queue(LCD_DATA, 0x1F);
	LCD_add_to_queue(LCD_DATA, 0x1F);
	LCD_add_to_queue(LCD_DATA, 0x1F);
	LCD_add_to_queue(LCD_DATA, 0x1F);

	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);

	htim3.Instance->CCR1 = 0;
	htim3.Instance->CCR2 = 0;

	while(1) {
		MotorCommand m = receive_motor_command_from_MCU_one();

		if(m.motor == 1) {
			htim3.Instance->CCR1 = m.velocity;
			LCD_add_to_queue(LCD_INSTRUCTION, LCD_SET_DD_RAM_ADDRESS_INSTRUCTION | 0x00);
		}
		else if(m.motor == 2) {
			htim3.Instance->CCR2 = m.velocity;
			LCD_add_to_queue(LCD_INSTRUCTION, LCD_SET_DD_RAM_ADDRESS_INSTRUCTION | 0x40);
		}
		else {
			// NIKAD OVDE NE SME!
		}

		int i = 0;
		for(i=0; i<m.velocity; ++i) {
			LCD_add_to_queue(LCD_DATA, 0x01);
		}
		for(int j=i; j<16; ++j) {
			LCD_add_to_queue(LCD_DATA, ' ');
		}
	}
}
