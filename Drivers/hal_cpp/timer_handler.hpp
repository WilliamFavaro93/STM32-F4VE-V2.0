/*
 * timer_handler.hpp
 *
 *  Created on: Jan 12, 2026
 *      Author: William
 */

#ifndef TIMER_HANDLER_HPP_
#define TIMER_HANDLER_HPP_

#ifdef __TIM_H__
	#include "tim.h"
#else
	#include "main.h"
#endif

class timer_handler
{
	TIM_HandleTypeDef* htim;
public:
	timer_handler(TIM_HandleTypeDef* htim);
	void enable();
	void disable();

	float get_frequency();
	void set_frequency(float frequency);

	float get_pwm1_dutycycle();
	float get_pwm2_dutycycle();
	float get_pwm3_dutycycle();
	float get_pwm4_dutycycle();
	//pwm 1
	void set_pwm1_dutycycle(float dutycycle);
	void set_pwm2_dutycycle(float dutycycle);
	void set_pwm3_dutycycle(float dutycycle);
	void set_pwm4_dutycycle(float dutycycle);
	//pwm 1
	void start_pwm1();
	void start_pwm2();
	void start_pwm3();
	void start_pwm4();

	void stop_pwm1();
	void stop_pwm2();
	void stop_pwm3();
	void stop_pwm4();
};


#endif /* HAL_CPP_TIMER_HANDLER_HPP_ */
