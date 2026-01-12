/*
 * handle_adc.h
 *
 *  Created on: Jan 12, 2026
 *      Author: William
 */

#include "adc_handler.hpp"

adc_handler::adc_handler(ADC_HandleTypeDef* hadc)
: hadc(hadc)
{
}

int adc_handler::start()
{
	return HAL_ADC_Start(hadc);
}

int adc_handler::stop()
{
	return HAL_ADC_Stop(hadc);
}

int adc_handler::poll_for_conversion(uint32_t timeout)
{
	return HAL_ADC_PollForConversion(hadc, timeout);
}

uint32_t adc_handler::get_value()
{
	return HAL_ADC_GetValue(hadc);
}
