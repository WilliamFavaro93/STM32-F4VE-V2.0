/*
 * flash.hpp
 *
 *  Created on: Jan 5, 2026
 *      Author: William
 */

#ifndef FLASH_FLASH_HPP_
#define FLASH_FLASH_HPP_

#include <spi_handler.hpp>
#include "gpio.hpp"

//JEDEC standard

static const uint32_t page_size 		= 0x100;
static const uint32_t sector_size 		= 0x1000;
static const uint32_t half_block_size 	= 0x8000;
static const uint32_t block_size 		= 0x10000;

class JedecFlash {
public:
    enum Command {
        ReadData            = 0x03,
        FastRead            = 0x0B,
        PageProgram         = 0x02,

        SectorErase4K       = 0x20,
        BlockErase32K       = 0x52,
        BlockErase64K       = 0xD8,
        ChipErase           = 0xC7,

        WriteEnable         = 0x06,
        WriteDisable        = 0x04,

        ReadStatusReg1      = 0x05,
        ReadStatusReg2      = 0x35,
        WriteStatusReg      = 0x01,

        ReadJedecID         = 0x9F,
        ReadUniqueID        = 0x4B,

        EnableReset         = 0x66,
        ResetDevice         = 0x99
    };
    enum Vendor
	{
        Unknown         = 0x00,

        Winbond         = 0xEF,   // Winbond / NEX / W25 series
        Macronix        = 0xC2,   // MXIC
        Micron          = 0x20,   // Micron / Numonyx / ST
        GigaDevice      = 0xC8,   // GD25 series
        ISSI            = 0x9D,   // ISSI / PMC
        EON             = 0x1C,   // EON / ESMT
        Spansion        = 0x01,   // Spansion (now Cypress/Infineon)
        Cypress         = 0x34,   // Cypress (legacy parts)
        Atmel           = 0x1F,   // Atmel / Adesto / Dialog
        AMIC            = 0x37,   // AMIC Technology
        Fudan           = 0xA1,   // Fudan Microelectronics
        Zetta           = 0xBA,   // Zetta Semiconductor
        XMC             = 0x20,   // XMC (shares Micron’s ID range)
    };
    enum MemoryType
	{
        W25Q_Series = 0x40
    };
    enum Capacity
	{
        W25Q40  = 0x13,   // 4 Mbit  (512 KB)
        W25Q80  = 0x14,   // 8 Mbit  (1 MB)
        W25Q16  = 0x15,   // 16 Mbit (2 MB)
        W25Q32  = 0x16,   // 32 Mbit (4 MB)
        W25Q64  = 0x17,   // 64 Mbit (8 MB)
        W25Q128 = 0x18,   // 128 Mbit (16 MB)
        W25Q256 = 0x19    // 256 Mbit (32 MB)
    };
    enum StatusBit
	{
    	BUSY = 0x01,
		WE = 0x02
	};
};

//change into external_flash
class flash
{
private:
	//io interface
	spi_handler spi;
	gpio not_enable;
	gpio not_reset;

	uint8_t status_register_1;
	uint8_t status_register_2;
	uint8_t status_register_3;

	uint8_t vendor;
	uint8_t memory_type;
	uint8_t capacity;

	uint32_t get_memory();//ret 1<<capacity
public:
	flash(SPI_HandleTypeDef* hspi, GPIO_TypeDef* not_enable_port, uint16_t not_enable_pin, GPIO_TypeDef* not_reset_port, uint16_t not_reset_pin);
	//check status
	bool is_busy();
	bool is_write_enabled();
	bool is_enabled();
	bool is_resetting();
	//gpio control
	void start_reset();
	void end_reset();
	void enable();
	void disable();
	//spi control
	int map_err(uint8_t hal_error);
	int read_jedec_id();
	int read_status();
	int enable_write();
	int disable_write();
	int write_data(uint32_t address, uint8_t* tdata, uint16_t length);
	int read_data(uint32_t address, uint8_t* rdata, uint16_t length);
	int fast_read_data(uint32_t address, uint8_t* rdata, uint16_t length);
	int erase_sector(uint32_t sector);
	int erase_half_block(uint32_t half_block);
	int erase_block(uint32_t block);
	int erase_memory();
};

#endif /* FLASH_FLASH_HPP_ */
