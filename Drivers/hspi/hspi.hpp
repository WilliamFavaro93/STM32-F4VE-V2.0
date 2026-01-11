/*
 * spi.hpp
 *
 *  Created on: Jan 6, 2026
 *      Author: William
 */

#ifndef HSPI_HSPI_HPP_
#define HSPI_HSPI_HPP_

#include "main.h"

class hspi
{
	SPI_HandleTypeDef* spi;
public:
	hspi(SPI_HandleTypeDef* hspi);
	void init();
	uint32_t get_state();//TODO
	bool is_not_init();//TODO
	bool is_ready();//TODO
	bool is_busy();//TODO
	bool is_transmitting();//TODO
	bool is_receiving();//TODO
	uint32_t get_error();
	int transmit(const uint8_t *tdata, uint16_t size, uint32_t timeout);
	int transmitreceive(const uint8_t *tdata, uint8_t *rdata, uint16_t size, uint32_t timeout);
	int transmit_IT();//TODO
	int transmitreceive_IT();//TODO
};


#endif /* HSPI_HSPI_HPP_ */
