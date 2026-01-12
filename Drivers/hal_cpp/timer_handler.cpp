/*
 * timer_handler.cpp
 *
 *  Created on: Jan 12, 2026
 *      Author: William
 */

#include <timer_handler.hpp>

timer_handler::timer_handler(TIM_HandleTypeDef* htim)
: htim(htim)
{
}

void timer_handler::enable()
{
	__HAL_TIM_ENABLE(htim);
}

void timer_handler::disable()
{
	__HAL_TIM_DISABLE(htim);
}

float timer_handler::get_frequency()
{
	return 0.0;
}

void timer_handler::set_frequency(float frequency)
{

}

float timer_handler::get_pwm1_dutycycle()
{
	float ARR = htim->Instance->ARR;
	float CCR = htim->Instance->CCR1;
	return CCR/ARR;
}

float timer_handler::get_pwm2_dutycycle()
{
	float ARR = htim->Instance->ARR;
	float CCR = htim->Instance->CCR2;
	return CCR/ARR;
}

float timer_handler::get_pwm3_dutycycle()
{
	float ARR = htim->Instance->ARR;
	float CCR = htim->Instance->CCR3;
	return CCR/ARR;
}

float timer_handler::get_pwm4_dutycycle()
{
	float ARR = htim->Instance->ARR;
	float CCR = htim->Instance->CCR4;
	return CCR/ARR;
}

//pwm 1
void set_pwm1_dutycycle(float dutycycle)
{
//	assert((dutycycle > 0.0f) and (dutycycle < 100.0f));
//	float ARR = htim.ARR;
//	float CCR = ARR;
//	return CCR/ARR;
}

void set_pwm2_dutycycle();

void set_pwm3_dutycycle();

void set_pwm4_dutycycle();

//pwm 1
void start_pwm1();
void start_pwm2();
void start_pwm3();
void start_pwm4();

void stop_pwm1();
void stop_pwm2();
void stop_pwm3();
void stop_pwm4();

