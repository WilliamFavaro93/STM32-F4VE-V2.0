/*
 * sw_timer.hpp
 *
 *  Created on: Dec 17, 2025
 *      Author: William
 */

#ifndef SW_TIMER_SW_TIMER_HPP_
#define SW_TIMER_SW_TIMER_HPP_

#include "sw_timer.hpp"
#include "stdint.h"

const uint32_t milliseconds = 1;
const uint32_t centiseconds = 10;
const uint32_t deciseconds  = 100;
const uint32_t seconds      = 1000;
const uint32_t minutes      = 60000;
const uint32_t hours        = 3600000;

class sw_timer
{
private:
	/** Indicates whether the timer is currently running */
	bool is_counting;

	/** Stores the last system time when the timer was updated */
	uint32_t update_time;

	/** Stores the elapsed time since the timer started */
	uint32_t elapsed_time;

	/** Preset timeout value for the timer (e.g., in milliseconds) */
	uint32_t preset_time;

	/** Returns the current system time (e.g., in milliseconds) */
	uint32_t get_time();

	/** Updates elapsed time based on current system time */
	void update();

public:
	/** Constructor: initializes timer state */
	sw_timer();

	/** Starts the timer counting from the current time */
	void start_counting();

	/** Stops the timer and freezes elapsed time */
	void stop_counting();

	uint32_t get_elapsed_time();
	uint32_t get_preset_time();
	void set_preset_time(uint32_t preset_time);
	/**
	 * Checks whether the elapsed time has reached or exceeded preset_time
	 * @return true if timeout occurred, false otherwise
	 */
	bool is_timeout();

	/** Restarts the timer by resetting elapsed time and starting again */
	void restart_counting();
};



#endif /* SW_TIMER_SW_TIMER_HPP_ */
