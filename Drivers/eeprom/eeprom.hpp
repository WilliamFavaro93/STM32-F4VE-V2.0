/*
 * eeprom.hpp
 *
 *  Created on: Dec 13, 2025
 *      Author: William
 */

#ifndef EEPROM_EEPROM_HPP_
#define EEPROM_EEPROM_HPP_

#include "stdint.h"

class eeprom
{
public:
	eeprom();
	eeprom(uint8_t id, uint32_t size);
	uint8_t get_id();
	uint32_t get_size();
	void write(uint32_t address, void *data, uint32_t size);
	void read(uint32_t address, void *data, uint32_t size);
private:
	uint8_t id;
	uint32_t size;
};

#endif /* EEPROM_EEPROM_HPP_ */
