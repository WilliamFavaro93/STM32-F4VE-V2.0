/*
 * led.hpp
 *
 *  Created on: Jan 12, 2026
 *      Author: William
 */

#ifndef LED_LED_HPP_
#define LED_LED_HPP_


#include "gpio.hpp"

class led
{
private:
	gpio* gpio_;
	bool is_active_low;
public:
	led(gpio* gpio_, bool is_active_low = true);
	void on();
	void off();
	bool is_on();
	bool is_off();
};


#endif /* LED_LED_HPP_ */
