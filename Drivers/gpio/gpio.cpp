/*
 * gpio.cpp
 *
 *  Created on: Dec 26, 2025
 *      Author: William
 */


#include "gpio.hpp"

gpio::gpio(GPIO_TypeDef* port, uint16_t pin)
{
	port_ = port;
	pin_ = pin;
}

bool gpio::read_pin()
{
	return HAL_GPIO_ReadPin(port_, pin_);
}

void gpio::write_pin(bool pinstate)
{
	GPIO_PinState pinstate_ = (pinstate) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(port_, pin_, pinstate_);
}

void gpio::toggle_pin()
{
	HAL_GPIO_TogglePin(port_, pin_);
}
