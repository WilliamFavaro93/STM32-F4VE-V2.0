/*
 * flash.cpp
 *
 *  Created on: Jan 5, 2026
 *      Author: William
 */


#include "flash.hpp"
#include "errno.h"
#include <stdio.h>

static bool flash_log_enable = false;
#define FLASH_LOG(...) 	if (flash_log_enable) { \
            				printf(__VA_ARGS__); \
        				} \

int flash::map_err(uint8_t hal_status)
{
	switch(hal_status)
	{
	case HAL_OK:
		return 0;
	case HAL_ERROR:
		return -EIO;
	case HAL_BUSY:
		return -EIO;
	case HAL_TIMEOUT:
		return -ETIMEDOUT;
	default:
		assert(0);
	}

	return 0;
}

flash::flash(SPI_HandleTypeDef* hspi,
		GPIO_TypeDef* not_enable_port, uint16_t not_enable_pin,
		GPIO_TypeDef* not_reset_port, uint16_t not_reset_pin)
: spi(hspi),
not_enable(not_enable_port, not_enable_pin),
not_reset(not_reset_port, not_reset_pin)
{
}

//check status
bool flash::is_busy()
{
	return status_register_1 & JedecFlash::StatusBit::BUSY;
}

bool flash::is_write_enabled()
{
	return status_register_1 & JedecFlash::StatusBit::WE;
}

bool flash::is_enabled()
{
	return not not_enable.read_pin();
}

bool flash::is_resetting()
{
	return not not_reset.read_pin();
}

uint32_t flash::get_memory()
{
	return 1U << capacity;
}

//gpio control
void flash::enable()
{
	not_enable.write_pin(gpio::pinstate::LOW);
}

void flash::disable()
{
	not_enable.write_pin(gpio::pinstate::HIGH);
}

void flash::start_reset()
{
	not_reset.write_pin(gpio::pinstate::LOW);
}

void flash::end_reset()
{
	not_reset.write_pin(gpio::pinstate::HIGH);
}

//spi control
int flash::read_status()
{
	uint8_t hal_status = 0;
	uint8_t tdata[2] = {0};
	uint8_t rdata[2] = {0};

	tdata[0] = (JedecFlash::Command::ReadStatusReg1);

	//send tdata
	enable();
	hal_status = spi.transmitreceive(tdata, rdata, sizeof(tdata), 100);
	disable();

	status_register_1 = rdata[1];

	return map_err(hal_status);
}

int flash::read_jedec_id()
{
	uint8_t hal_status = 0;
	uint8_t tdata[5] = {0};
	uint8_t rdata[5] = {0};

	tdata[0] = (JedecFlash::Command::ReadJedecID);

	//send txmsg
	enable();
	hal_status = spi.transmitreceive(tdata, rdata, sizeof(tdata), 10);
	disable();

	vendor = rdata[1];
	memory_type = rdata[2];
	capacity = rdata[3];

	return map_err(hal_status);
}

int flash::enable_write()
{
	uint8_t hal_status = 0;
	uint8_t tdata[1] = {0};

	tdata[0] = (JedecFlash::Command::WriteEnable);

	//send txmsg
	enable();
	hal_status = spi.transmit(tdata, sizeof(tdata), 10);
	disable();

	return map_err(hal_status);
}

int flash::disable_write()
{
	uint8_t hal_status = 0;
	uint8_t tdata[1] = {0};

	tdata[0] = (JedecFlash::Command::WriteDisable);

	//send txmsg
	enable();
	hal_status = spi.transmit(tdata, sizeof(tdata), 10);
	disable();

	return map_err(hal_status);
}

int flash::write_data(uint32_t address, uint8_t* data, uint16_t length)
{
	//create var
	uint32_t memory = get_memory();
	uint8_t hal_status = 0;
	uint8_t tdata[261] = {0};//1+4+256
	uint16_t size = (memory < 0xFFFFFF) ? 4+length : 5+length;

	//check param
	//page overflow
	if((address % page_size) + length > page_size)
		return -EINVAL;
	//memory overflow
	if(address + length > memory)
		return -EINVAL;

	//prepare txmsg
	tdata[0] = (JedecFlash::Command::PageProgram);
	if(memory < 0xFFFFFF)
	{
		tdata[1] = address >> 16;
		tdata[2] = address >> 8;
		tdata[3] = address >> 0;
	}
	else
	{
		tdata[1] = address >> 24;
		tdata[2] = address >> 16;
		tdata[3] = address >> 8;
		tdata[4] = address >> 0;
	}
	for(uint8_t i = 0; i < length; i++)
	{
		tdata[5+i] = data[i];
	}

	//send txmsg
	enable();
	hal_status = spi.transmit(tdata, size, 10);
	disable();

	return map_err(hal_status);
}

int flash::read_data(uint32_t address, uint8_t* data, uint16_t size)
{

}

int flash::fast_read_data(uint32_t address, uint8_t* data, uint16_t size)
{

}

int flash::erase_sector(uint32_t sector)
{

}

int flash::erase_half_block(uint32_t half_block)
{

}

int flash::erase_block(uint32_t block)
{

}

int flash::erase_memory()
{

}
