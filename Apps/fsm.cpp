/*
 * fsm.cpp
 *
 *  Created on: Dec 28, 2025
 *      Author: William
 */

#include "fsm.hpp"
#include "assert.h"

motor::motor()
: current_state(state::IDLE)
{
}

state motor::get_state()
{
	return current_state;
}

void motor::handle_fault(fault fault)
{
	switch (fault)
	{
	case fault::OVERTEMPERATURE_FAULT:
		overtemperature_fault = true;
		break;
	case fault::OVERTEMPERATURE_OK:
		overtemperature_fault = false;
		break;
	}

	is_faulty = overtemperature_fault;//or di tutti i fault

	if(is_faulty)
		move_to(state::FAULT);
	else
		move_to(state::IDLE);
}

void motor::handle_event(event event)
{
	switch (current_state)
	{
	case state::IDLE:
		if(event == event::USER_ENABLE)
		{
			move_to(state::RUN);
		}
	case state::RUN:
		if(event == event::USER_DISABLE)
		{
			move_to(state::IDLE);
		}
		break;
	case state::FAULT:
		break;
	}
}

void motor::move_to(state state)
{
	current_state = state;

	switch (current_state)
	{
	case state::IDLE:
		deceleration_timer.set_preset_time(dutycycle * deceleration_time);
		deceleration_timer.restart_counting();
		is_running = false;
		is_faulty = false;
		break;
	case state::RUN:
		acceleration_timer.set_preset_time((1 - dutycycle) * acceleration_time);
		acceleration_timer.restart_counting();
		is_running = true;
		is_faulty = false;
		break;
	case state::FAULT:
		deceleration_timer.set_preset_time(dutycycle * deceleration_time);
		deceleration_timer.restart_counting();
		is_running = false;
		is_faulty = true;
		break;
	}
}

const bool ha[6] = {1,1,1,0,0,0};
const bool hb[6] = {0,0,1,1,1,0};
const bool hc[6] = {1,0,0,0,1,1};

const bool up[6] = {1,1,0,0,0,0};
const bool un[6] = {0,0,0,1,1,0};
const bool vp[6] = {0,0,1,1,0,0};
const bool vn[6] = {1,0,0,0,0,1};
const bool wp[6] = {0,0,0,0,1,1};
const bool wn[6] = {0,1,1,0,0,0};

void motor::handle_step(bool a, bool b, bool c)
{
	uint8_t step_ = -1;

	for(uint8_t i = 0; i < 6; i++)
		if((ha[i] == a) and (hb[i] == b) and (hc[i] == c))
			step_ = i;

	step = step_;

	if(up[step])

}

//timer dipendent
void motor::run()
{
	float elapsed_time;
	float preset_time;

	switch (current_state)
	{
		case state::IDLE:
		case state::FAULT:
			elapsed_time = deceleration_timer.get_elapsed_time();
			preset_time = deceleration_timer.get_preset_time();
			dutycycle = elapsed_time / preset_time;
			break;
		case state::RUN:
			elapsed_time = acceleration_timer.get_elapsed_time();
			preset_time = acceleration_timer.get_preset_time();
			dutycycle = elapsed_time / preset_time;
			break;
		default:
			break;
	}
}
