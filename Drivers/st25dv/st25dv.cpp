/*
 * st25dv.cpp
 *
 *  Created on: Jan 14, 2026
 *      Author: William
 */

#include "../st25dv/st25dv.hpp"

//chip ST25DV64K
#define I2C1_ADDRESS_E2_0 0x53 //user memory, dynamic register, mailbox memory
#define I2C1_ADDRESS_E2_1 0x57 //static register

//user memory (E2=0)
#define USER_MEMORY		0x0000 //0x0000 - 0x1fff (8192 bytes)

//dynamic registers (E2=0)
#define EH_CTRL_Dyn		0x2002 //Energy Harvesting management & usage status
#define I2C_SSO_Dyn		0x2004 //I2C security session status
#define MB_CTRL_Dyn		0x2006 //Fast transfer mode control and status
#define MB_LEN_Dyn		0x2007 //length of fast transfer mode message

//FTM (Fast Trasfer Mode) buffer (E2=0)
#define MB_Dyn_Byte0	0x2008 //0x2008 - 0x2107

//static register (E2=1)
#define MB_MODE			0x000D
#define MB_WDG			0x000E //0 - 7 (dur=2^(MB_WDG-1)x30ms, MB_WDG=0 means infinite)
#define UID				0x0018
#define I2C_PASSWORD	0x0900 //0x900 - 0x907

st25dv::st25dv(I2C_HandleTypeDef* hi2c, uint16_t device_address)
: hi2c(hi2c), device_address(device_address)
{
}

void st25dv::enable_ftm()
{
	uint8_t wdata[1];
	wdata[0] = 0x01;
	hi2c.mem_write(I2C1_ADDRESS_E2_1 << 1, MB_MODE, 2, wdata, sizeof(wdata), 10);
}

void st25dv::disable_ftm()
{
	uint8_t wdata[1];
	wdata[0] = 0x00;
	hi2c.mem_write(I2C1_ADDRESS_E2_1 << 1, MB_MODE, 2, wdata, sizeof(wdata), 10);
}
void st25dv::ftm_write()
{

}
void st25dv::ftm_read()
{

}
void st25dv::read_unique_ID()
{

}
