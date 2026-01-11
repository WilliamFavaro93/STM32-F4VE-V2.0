/*
 * fsm.hpp
 *
 *  Created on: Dec 26, 2025
 *      Author: William
 */

#ifndef FSM_HPP_
#define FSM_HPP_

enum class state
{
	IDLE,
	BLINK,
	ERROR
};

enum class event
{
	START,
	STOP,
	FAULT,
	CLEAR
};

class fsm
{
private:
	state current_state;
public:
	fsm();
	state get_state();
	void handle_event(event event);
	void run();
};

#endif /* FSM_HPP_ */
