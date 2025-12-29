/*
 * fsm.cpp
 *
 *  Created on: Dec 28, 2025
 *      Author: William
 */

#include "fsm.hpp"

fsm::fsm()
: current_state(state::IDLE)
{
}


state fsm::get_state()
{
	return current_state;
}

void fsm::handle_event(event event)
{
	switch (current_state)
	{
		case state::IDLE:
			if (event == event::START)
			{
				current_state = state::BLINK;
			}
			break;

		case state::BLINK:
			if (event == event::STOP)
			{
				current_state = state::IDLE;
//				led_off();
			}
			else if (event == event::FAULT)
			{
				current_state = state::ERROR;
//				led_on();
			}
			break;

		case state::ERROR:
			if (event == event::CLEAR)
			{
				current_state = state::IDLE;
//				led_off();
			}
			break;

		default:
			/* Should never happen */
//			assert(0);
			break;
	}
}


void fsm::run()
{
//	if (start_button_pressed())
//	{
//		led_fsm.handle_event(event::START);
//	}
//
//	if (fault_detected())
//	{
//		led_fsm.handle_event(event::FAULT);
//	}

	switch (current_state)
	{
		case state::IDLE:
//			led_off();
			break;

		case state::BLINK:
//			led_toggle();
			break;

		case state::ERROR:
//			led_on();
			break;
	}
}
