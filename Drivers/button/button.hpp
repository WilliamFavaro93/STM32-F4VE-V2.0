/*
 * button.hpp
 *
 *  Created on: Jan 12, 2026
 *      Author: William
 */

#ifndef BUTTON_BUTTON_HPP_
#define BUTTON_BUTTON_HPP_

#include "gpio.hpp"

class button
{
private:
	gpio* gpio_;
	bool is_active_low;
public:
	button(gpio* gpio_, bool is_active_low = true);
	bool is_pressed();
	bool is_released();
};


#endif /* BUTTON_BUTTON_HPP_ */
