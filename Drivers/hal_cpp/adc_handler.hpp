/*
 * handle_adc.h
 *
 *  Created on: Jan 12, 2026
 *      Author: William
 */

#ifndef ADC_HANDLER_ADC_HANDLER_HPP_
#define ADC_HANDLER_ADC_HANDLER_HPP_

#ifdef __ADC_H__
	#include "adc.h"
#else
	#include "main.h"
#endif

class adc_handler
{
	ADC_HandleTypeDef* hadc;
public:
	adc_handler(ADC_HandleTypeDef* hadc);
	int calibration_start();
	int start();
	int stop();
	int poll_for_conversion(uint32_t timeout);
	uint32_t get_value();
};

#endif /* ADC_HANDLER_ADC_HANDLER_HPP_ */
