/*
 * spi.hpp
 *
 *  Created on: Jan 6, 2026
 *      Author: William
 */

#ifndef SPI_HANDLER_HPP_
#define SPI_HANDLER_HPP_

#ifdef __SPI_H__
	#include "spi.h"
#else
	#include "main.h"
#endif

class spi_handler
{
	SPI_HandleTypeDef* hspi;
public:
	spi_handler(SPI_HandleTypeDef* hspi);
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


#endif /* HSPI_SPI_HANDLER_HPP_ */
