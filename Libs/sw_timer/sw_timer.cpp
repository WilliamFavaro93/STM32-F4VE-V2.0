/*
 * sw_timer.c
 *
 *  Created on: Dec 17, 2025
 *      Author: William
 */

#include "main.h"
#include "sw_timer.hpp"

sw_timer::sw_timer()
{
	is_counting = false;
	update_time = get_time();
	elapsed_time = 0;
}

__attribute__((__weak__))
uint32_t sw_timer::get_time()
{
	return HAL_GetTick();
}

/**/
void sw_timer::update()
{
	uint32_t dt = get_time() - update_time;

	if(is_counting)
	{
		if(elapsed_time > dt)
			elapsed_time -= dt;
		else
			elapsed_time = 0;
	}

	update_time = get_time();
}

/**/
void sw_timer::start_counting()
{
	update();
	is_counting = true;
}

/**/
void sw_timer::stop_counting()
{
	update();
	is_counting = false;
}

/**/
bool sw_timer::is_timeout()
{
	update();
	return elapsed_time == 0;
}

/**/
void sw_timer::restart_counting()
{
	update();
	elapsed_time = preset_time;
}

uint32_t sw_timer::get_elapsed_time()
{
	return elapsed_time;
}

uint32_t sw_timer::get_preset_time()
{
	return preset_time;
}


void sw_timer::set_preset_time(uint32_t preset_time)
{
	this->preset_time = preset_time;
}
