/*
 * nrf.hpp
 *
 *  Created on: Jan 14, 2026
 *      Author: William
 */

#ifndef ST25DV_ST25DV_HPP_
#define ST25DV_ST25DV_HPP_

#include "i2c_handler.hpp"
#include "i2c_handler.hpp"

//ftm: fast transfer mode
class st25dv
{
	i2c_handler hi2c;
	uint16_t device_address;
//	bool ftm_enabled;
	uint16_t static_register;
	uint16_t dynamic_register;
public:
	st25dv(I2C_HandleTypeDef* hi2c, uint16_t device_address);

	bool is_ftm_enabled();
	bool is_data_memory_protection_enabled();

	void enable_ftm();
	void disable_ftm();
	void ftm_write();
	void ftm_read();
	void write();
	void read();

	void read_unique_ID();
	void insert_password();
};

#endif /* ST25DV_ST25DV_HPP_ */
