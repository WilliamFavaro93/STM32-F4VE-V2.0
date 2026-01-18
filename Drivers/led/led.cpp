/*
 * led.cpp
 *
 *  Created on: Jan 12, 2026
 *      Author: William
 */


#include "led.hpp"

led::led(gpio* gpio_, bool is_active_low)
    : gpio_(gpio_), is_active_low(is_active_low)
{
}


void led::on()
{
	gpio_->write_pin(1);
}

void led::off()
{
	gpio_->write_pin(0);
}

bool led::is_on()
{
	return gpio_->read_pin() == true;
}

bool led::is_off()
{
	return gpio_->read_pin() == false;
}
