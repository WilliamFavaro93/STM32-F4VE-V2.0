/*
 * eeprom.cpp
 *
 *  Created on: Dec 13, 2025
 *      Author: William
 */


#include <eeprom.hpp>

eeprom::eeprom(uint8_t id_, uint32_t size_):
id(id_),
size(size_)
{
}

uint8_t eeprom::get_id()
{
	return 0;
}

uint32_t eeprom::get_size()
{
	return 0;
}

void eeprom::write(uint32_t address, void *data, uint32_t size)
{
	if(!size)
		return;

	return;
}

void eeprom::read(uint32_t address, void *data, uint32_t size)
{
	return;
}
