/*
 * gpio.cpp
 *
 *  Created on: Dec 26, 2025
 *      Author: William
 */


#include "gpio.hpp"

gpio::gpio(GPIO_TypeDef* port, uint16_t pin)
: port(port), pin(pin)
{
}

bool gpio::read_pin()
{
	return HAL_GPIO_ReadPin(port, pin);
}

void gpio::write_pin(bool pinstate)
{
	HAL_GPIO_WritePin(port, pin, (pinstate) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void gpio::toggle_pin()
{
	HAL_GPIO_TogglePin(port, pin);
}
