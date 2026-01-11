/*
 * hal.hpp
 *
 *  Created on: Jan 9, 2026
 *      Author: William
 */

#ifndef HAL_HAL_HPP_
#define HAL_HAL_HPP_

#include "main.h"

namespace hal
{
	void delay(uint32_t delay);
	uint32_t get_tick();
	void suspend_tick();
	void resume_tick();
	uint32_t get_hal_version();
	uint32_t get_device_revision_id();
	uint32_t get_device_id();
	uint32_t get_unique_device_id_first_word();
	uint32_t get_unique_device_id_second_word();
	uint32_t get_unique_device_id_third_word();
};

#endif /* HAL_HAL_HPP_ */
