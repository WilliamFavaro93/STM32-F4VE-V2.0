/*
 * gpio.hpp
 *
 *  Created on: Dec 26, 2025
 *      Author: William
 */

#ifndef GPIO_GPIO_HPP_
#define GPIO_GPIO_HPP_

#include "main.h"

class gpio
{
private:
	GPIO_TypeDef* port_;
	uint16_t pin_;
public:
	gpio(GPIO_TypeDef* port, uint16_t pin);
	bool read_pin();
	void write_pin(bool pinstate);
	void toggle_pin();
};


#endif /* GPIO_GPIO_HPP_ */
