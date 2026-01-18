/*
 * fsm.hpp
 *
 *  Created on: Dec 26, 2025
 *      Author: William
 */

#ifndef FSM_HPP_
#define FSM_HPP_

#include "sw_timer.hpp"

enum class state
{
	IDLE,//duty cycle -> 0%
	RUN,//duty cycle -> 100%
	FAULT,//duty cycle -> 0%
};

enum class event
{
	USER_ENABLE, //power_button_released
	USER_DISABLE,

	//hall sensor
	HALL_SENSOR_A_plus,
	HALL_SENSOR_A_minus,
	HALL_SENSOR_B_plus,
	HALL_SENSOR_B_minus,
	HALL_SENSOR_C_plus,
	HALL_SENSOR_C_minus,
};

enum class fault
{
	//fault
	OVERTEMPERATURE_FAULT,
	OVERTEMPERATURE_OK,

};

const float acceleration_time = 5 * seconds;
const float deceleration_time = 5 * seconds;

class motor
{
private:
	float dutycycle;
	sw_timer acceleration_timer;
	sw_timer deceleration_timer;
	bool overtemperature_fault;
	bool is_faulty;
	bool is_running;
	uint8_t step;
	state current_state;
	void move_to(state state);
public:
	motor();
	void update_step();
	state get_state();
	void handle_fault(fault fault);
	void handle_event(event event);
	void fsm();
};

#endif /* FSM_HPP_ */
