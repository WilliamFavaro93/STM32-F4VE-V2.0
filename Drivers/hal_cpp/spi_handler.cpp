/*
 * spi.cpp
 *
 *  Created on: Jan 6, 2026
 *      Author: William
 */

#include <spi_handler.hpp>

spi_handler::spi_handler(SPI_HandleTypeDef* hspi)
:hspi(hspi)
{
}

void spi_handler::init()
{
	if (HAL_SPI_Init(hspi) != HAL_OK)
	{
		Error_Handler();
	}
}

int spi_handler::transmit(const uint8_t *tdata, uint16_t size, uint32_t timeout)
{
	return HAL_SPI_Transmit(hspi, tdata, size, timeout);
}

int spi_handler::transmitreceive(const uint8_t *tdata, uint8_t *rdata, uint16_t size, uint32_t timeout)
{
	return HAL_SPI_TransmitReceive(hspi, tdata, rdata, size, timeout);
}
