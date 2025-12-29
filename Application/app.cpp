/*
 * app.cpp
 *
 *  Created on: Dec 13, 2025
 *      Author: William
 */

#include "app.h"
#include "eeprom.hpp"
#include "main.h"
#include "stdio.h"

#include <array>
std::array<int, 20> buffer;

#include "platform.hpp"
#include "sw_timer.hpp"

sw_timer led1_timer;
sw_timer led2_timer;

void this_app()
{
	led1_timer.preset_time = 1 * seconds;
	led1_timer.start_counting();

	led2_timer.preset_time = 2 * seconds;
	led2_timer.start_counting();

	for(const auto& element: buffer)
		printf("%d", element);

	eeprom eeprom_1(1,2);
	eeprom_1.read(0, 0, 0);
	printf("Hello World");

	while(1)
	{
//		HAL_GPIO_TogglePin(USER_LED1_GPIO_Port, USER_LED1_Pin);
//		user_led1.toggle_pin();
//		if(k1_button.read_pin())
//			user_led2.toggle_pin();
//		HAL_Delay(1000);

		if(led1_timer.is_timeout())
		{
			user_led1.toggle_pin();
			led1_timer.restart_counting();
		}

		if(led2_timer.is_timeout())
		{
			user_led2.toggle_pin();
			led2_timer.restart_counting();
		}

		while(k1_button.read_pin());
	}
}


void generic_function(/*param*/)
{
	//creation of used variables
	//check parameters
	//do
	//return ret
}
