/*
 * spi.cpp
 *
 *  Created on: Jan 6, 2026
 *      Author: William
 */

#include "hspi.hpp"

hspi::hspi(SPI_HandleTypeDef* spi)
:spi(spi)
{
}

void hspi::init()
{
	if (HAL_SPI_Init(spi) != HAL_OK)
	{
		Error_Handler();
	}
}

int hspi::transmit(const uint8_t *tdata, uint16_t size, uint32_t timeout)
{
	return HAL_SPI_Transmit(spi, tdata, size, timeout);
}

int hspi::transmitreceive(const uint8_t *tdata, uint8_t *rdata, uint16_t size, uint32_t timeout)
{
	return HAL_SPI_TransmitReceive(spi, tdata, rdata, size, timeout);
}
