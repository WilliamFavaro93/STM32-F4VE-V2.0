/*
 * i2c_handler.hpp
 *
 *  Created on: Jan 14, 2026
 *      Author: William
 */

#ifndef I2C_HANDLER_HPP_
#define I2C_HANDLER_HPP_

#ifdef __I2C_H__
	#include "i2c.h"
#else
	#include "main.h"
#endif

class i2c_handler
{
private:
	I2C_HandleTypeDef* hi2c;
public:
	i2c_handler(I2C_HandleTypeDef* hi2c);
	int mem_read(uint16_t device_address, uint16_t memory_address, uint16_t memory_address_size, uint8_t* rdata, uint32_t size, uint32_t timeout);
	int mem_write(uint16_t device_address, uint16_t memory_address, uint16_t memory_address_size, uint8_t* wdata, uint32_t size, uint32_t timeout);
};



#endif /* HAL_CPP_I2C_HANDLER_HPP_ */
