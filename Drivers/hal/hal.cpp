/*
 * hal.cpp
 *
 *  Created on: Jan 9, 2026
 *      Author: William
 */

#include "hal.hpp"


void hal::delay(uint32_t delay)
{
	HAL_Delay(delay);
}
uint32_t hal::get_tick()
{
	return HAL_GetTick();
}
void hal::suspend_tick()
{
	HAL_SuspendTick();
}
void hal::resume_tick()
{
	HAL_ResumeTick();
}
uint32_t hal::get_hal_version()
{
	return HAL_GetHalVersion();
}
uint32_t hal::get_device_revision_id()
{
	return HAL_GetREVID();
}
uint32_t hal::get_device_id()
{
	return HAL_GetDEVID();
}
uint32_t hal::get_unique_device_id_first_word()
{
	return HAL_GetUIDw0();
}
uint32_t hal::get_unique_device_id_second_word()
{
	return HAL_GetUIDw1();
}
uint32_t hal::get_unique_device_id_third_word()
{
	return HAL_GetUIDw2();
}
