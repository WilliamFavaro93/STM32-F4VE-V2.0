/*
 * i2c_handler.cpp
 *
 *  Created on: Jan 14, 2026
 *      Author: William
 */

#include <i2c_handler.hpp>

i2c_handler::i2c_handler(I2C_HandleTypeDef* hi2c)
: hi2c(hi2c)
{
}

int i2c_handler::mem_read(uint16_t device_address, uint16_t memory_address, uint16_t memory_address_size, uint8_t* rdata, uint32_t size, uint32_t timeout)
{
	return HAL_I2C_Mem_Read(hi2c, device_address, memory_address, memory_address_size, rdata, size, timeout);
}

int i2c_handler::mem_write(uint16_t device_address, uint16_t memory_address, uint16_t memory_address_size, uint8_t* wdata, uint32_t size, uint32_t timeout)
{
	return HAL_I2C_Mem_Write(hi2c, device_address, memory_address, memory_address_size, wdata, size, timeout);
}
