/*
 * gpio.hpp
 *
 *  Created on: Dec 26, 2025
 *      Author: William
 */

#ifndef GPIO_HPP_
#define GPIO_HPP_

#ifdef __GPIO_H__
	#include "gpio.h"
#else
	#include "main.h"
#endif

class gpio
{
private:
	GPIO_TypeDef* port;
	uint16_t pin;
public:
	enum pinstate
	{
		LOW = 0,
		HIGH = 1
	};
	gpio(GPIO_TypeDef* port, uint16_t pin);
	bool read_pin();
	void write_pin(bool pinstate);
	void toggle_pin();
};


#endif /* GPIO_HPP_ */
