/*
 * button.cpp
 *
 *  Created on: Jan 12, 2026
 *      Author: William
 */


#include "button.hpp"

button::button(gpio* gpio_, bool is_active_low)
: gpio_(gpio_), is_active_low(is_active_low)
{
}

bool button::is_pressed()
{
	if(is_active_low)
		return gpio_->read_pin();

	return not gpio_->read_pin();
}

bool button::is_released()
{
	if(is_active_low)
		return not gpio_->read_pin();

	return gpio_->read_pin();
}
