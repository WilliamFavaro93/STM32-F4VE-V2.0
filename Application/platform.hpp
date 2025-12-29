/*
 * platform.hpp
 *
 *  Created on: Dec 26, 2025
 *      Author: William
 */

#ifndef PLATFORM_HPP_
#define PLATFORM_HPP_

#include "gpio.hpp"
//definizione di tutti i componenti della scheda
//gpio
gpio user_led1(USER_LED1_GPIO_Port, USER_LED1_Pin);
gpio user_led2(USER_LED2_GPIO_Port, USER_LED2_Pin);
gpio k0_button(USER_BUTTON2_GPIO_Port, USER_BUTTON2_Pin);
gpio k1_button(USER_BUTTON3_GPIO_Port, USER_BUTTON3_Pin);
//spi


#endif /* PLATFORM_HPP_ */
